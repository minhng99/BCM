/*
    <:copyright-BRCM:2015-2016:DUAL/GPL:standard
    
       Copyright (c) 2015-2016 Broadcom 
       All Rights Reserved
    
    Unless you and Broadcom execute a separate written software license
    agreement governing use of this software, this software is licensed
    to you under the terms of the GNU General Public License version 2
    (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
    with the following added to such license:
    
       As a special exception, the copyright holders of this software give
       you permission to link this software with independent modules, and
       to copy and distribute the resulting executable under terms of your
       choice, provided that you also meet, for each linked independent
       module, the terms and conditions of the license of that module.
       An independent module is a module which is not derived from this
       software.  The special exception does not apply to any modifications
       of the software.
    
    Not withstanding the above, under no circumstances may you combine
    this software in any way with any other Broadcom software provided
    under a license other than the GPL, without Broadcom's express prior
    written consent.
    
    :>
*/

#include "bdmf_dev.h"
#include "rdp_drv_shell.h"
#include "rdp_drv_dis_reor.h"
#include "rdp_drv_bbh_rx.h"
#include "rdp_drv_cntr.h"
#include "rdp_drv_proj_cntr.h"
#include "rdp_drv_rnr.h"
#include "rdd_runner_proj_defs.h"
#include "access_macros.h"
#include "rdd_data_structures_auto.h"
#include "xrdp_drv_rnr_quad_ag.h"
#include "xrdp_drv_rnr_regs_ag.h"
#include "xrdp_drv_ubus_slv_ag.h"
#include "rdd_runner_tasks_auto.h"
#include "rdd_map_auto.h"
#include "rdd_scheduling.h"
#include "rdp_drv_qm.h"

#ifdef USE_BDMF_SHELL

extern void rdpa_cpu_tx_disable(bdmf_boolean en);

static int rdp_drv_shell_bbh_rx_global_enable_set(bdmf_boolean enable)
{
    int i, rc = BDMF_ERR_OK;

    for (i = BBH_ID_FIRST; i < BBH_ID_NUM; ++i)
        rc = rc ? rc : ag_drv_bbh_rx_general_configuration_enable_set(i, enable, enable);

    return rc;
}

static int rdp_drv_shell_cpu_tx_disable(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    bdmf_boolean disable = parm[0].value.unumber;
    rdpa_cpu_tx_disable(disable);

    return BDMF_ERR_OK;
}

static int rdp_drv_shell_isolate_set(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    uint8_t core_idx = parm[0].value.unumber;
    uint8_t task_idx = parm[1].value.unumber;
    uint8_t rnr_grp_idx = parm[2].value.unumber;
    int rc;

    /* stop all traffic */
    rc = rdp_drv_shell_bbh_rx_global_enable_set(BBH_RX_DISABLE);
    rdpa_cpu_tx_disable(CPU_TRAFFIC_DISABLE);

    WMB();

    /* configure dispatcher */
    rc = rc ? rc : drv_dis_reor_isolate_set(core_idx, task_idx, rnr_grp_idx);

    /* resume traffic */
    rc = rc ? rc : rdp_drv_shell_bbh_rx_global_enable_set(BBH_RX_ENABLE);
    rdpa_cpu_tx_disable(CPU_TRAFFIC_ENABLE);

    return rc;
}

static int rdp_drv_shell_isolate_restore(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    uint8_t rnr_grp_idx = parm[0].value.unumber;
    int rc;

    /* stop all traffic */
    rc = rdp_drv_shell_bbh_rx_global_enable_set(BBH_RX_DISABLE);
    rdpa_cpu_tx_disable(CPU_TRAFFIC_DISABLE);

    WMB();

    /* restore dispatcher configurations */
    rc = rc ? rc : drv_dis_reor_restore_isolate_set(rnr_grp_idx);

    /* resume traffic */
    rc = rc ? rc : rdp_drv_shell_bbh_rx_global_enable_set(BBH_RX_ENABLE);
    rdpa_cpu_tx_disable(CPU_TRAFFIC_ENABLE);

    return rc;
}

static inline void print_scheduler_event(char *trace_buf, uint8_t log_to_file, RDD_TRACE_EVENT_DTS *entry, uint32_t timestamp, uint8_t core_id)
{
    uint8_t bbhrx_addr, acc;
    uint16_t sheduler_acc;
    static char *events[] = {
            "Sheduler: Timer", "Sheduler: FW", "Sheduler: FW wakeup", "Sheduler: CPU", "Sheduler: BBRX sync ", "Sheduler: BBRX async ",
            "Sheduler: BBTX ", "Sheduler: Parser", "Sheduler: RAM RD", "Sheduler: DMA WR reply", "Sheduler: DMA RD", "Sheduler: DMA WR"
    };
    char one_acc_event[256], bbhrx_addr_str[64], *p;

    RDD_TRACE_EVENT_INCOMING_BBHRX_SRC_ADDR_READ(bbhrx_addr, entry);
    RDD_TRACE_EVENT_ACC_TYPE_READ(sheduler_acc, entry);

    strcpy(trace_buf, "\0");

    while ((sheduler_acc) && (sheduler_acc != 0xaed))
    {
        /* read and clear each set bit in sheduler_acc */
        acc = ffs(sheduler_acc) - 1;
        sheduler_acc &= ~(1LL << acc);

        if (BBRX_EVENT(acc))
        {
            sprintf(bbhrx_addr_str, "%s0x%2x", events[acc], bbhrx_addr);
            p = bbhrx_addr_str;
        }
        else
            p = events[acc];
        
        if (log_to_file)
        {
            sprintf(one_acc_event, "%u,%u,%s\n", core_id, timestamp, p);
            strcat(trace_buf, one_acc_event);
        }
        else
        {
            sprintf(one_acc_event, "%-20u %-20s\n", timestamp, p);
            strcat(trace_buf, one_acc_event);
        }
    }
}

static inline void print_cs_event(char *trace_buf, uint8_t log_to_file, RDD_TRACE_EVENT_DTS *entry,
        uint32_t timestamp, trace_event_type_t event_type, uint8_t core_id, uint8_t *prev_task)
{
    uint16_t pc;
    uint8_t incoming_task;
    char *events[] = {"CS active->active", "CS idle->active", "CS active->idle"};

    if (event_type == TRACE_EVENT_CS_ACTIVE_IDLE)
    {
        incoming_task = *prev_task;
        pc = INVALID_PC;
    }

    else
    {
        RDD_TRACE_EVENT_INCOMING_TASK_NUM_READ(incoming_task, entry);
        *prev_task = incoming_task;
        RDD_TRACE_EVENT_TASK_PC_READ(pc, entry);
        pc <<= 2;
    }

    if (TASK_INVALID(incoming_task)){
        if (log_to_file)
            sprintf(trace_buf, "%u,%u,%s,%s,%u,0x%04x\n",
                    core_id, timestamp, events[event_type], "N/A", incoming_task, pc);
        else
            sprintf(trace_buf, "%-20u %-20s %-20s 0x%04x\n",
                    timestamp, events[event_type], "N/A", pc);
    }
    else
    {
        if (log_to_file)
            sprintf(trace_buf, "%u,%u,%s,%s,%u,0x%04x\n",
                    core_id, timestamp, events[event_type],
                    image_task_names[rdp_core_to_image_map[core_id]][incoming_task], incoming_task, pc);
        else
            sprintf(trace_buf, "%-20u %-20s %-20s 0x%04x\n",
                    timestamp, events[event_type],
                    image_task_names[rdp_core_to_image_map[core_id]][incoming_task], pc);
    }
}

static int rdp_drv_profiling_trace_dump(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    trace_event_type_t event_type;
    RDD_TRACE_EVENT_DTS entry, *p;
    bdmf_file trace_log = 0;
    uint8_t prev_task = RUNNER_MAX_TASKS_NUM;
    char trace_buf[400] = {0};
    char default_fname[] = "/var/log/trace_log.csv";
    char *filename;
    uint8_t core_id = parm[0].value.unumber, log_to_file = parm[1].value.unumber;
    uint16_t prev_timestamp = 0, timestamp = 0, event_count = 0;
    uint32_t edited_timestamp, timestamp_wraparound_counter = 0, event_info = 0;
    bdmf_boolean profiling_on = 0;
    bdmf_error_t rc = BDMF_ERR_OK;
    uint32_t num_cycles = 0;


    if (log_to_file)
    {
        if (n_parms > 2)
            filename = parm[2].value.string;
        else
            filename = default_fname;
#ifndef _CFE_
        /* open trace log file */
        trace_log = bdmf_file_open(filename, BDMF_FMODE_CREATE | BDMF_FMODE_APPEND | BDMF_FMODE_RDWR);
        if (!trace_log)
        {
            bdmf_trace("trace log creation failed!\n");
            return BDMF_ERR_INTERNAL;
        }
#endif
    }
    /* verify that profiling is not running right now */
    rc = ag_drv_ubus_slv_profiling_status_get(&profiling_on, &num_cycles);
    if (!rc && !profiling_on)
    {
        if (!log_to_file)
            bdmf_session_print(session, "%-20s %-20s %-20s %-10s\n", "Timestamp [32ns]", "Event", "Incoming Task", "PC addr");
        p = ((RDD_TRACE_EVENT_DTS *)RDD_RUNNER_PROFILING_TRACE_BUFFER_PTR(core_id));
        entry = *p;
        RDD_TRACE_EVENT_TRACE_EVENT_INFO_READ(event_info, &entry);
        RDD_TRACE_EVENT_TIMESTAMP_READ(timestamp, &entry);
        while ((event_info != 0x3FFFF || timestamp != 0xFFF) && event_count < RDD_RUNNER_PROFILING_TRACE_BUFFER_SIZE)
        {
            if (prev_timestamp > timestamp)
                timestamp_wraparound_counter += (1L << TRACE_TIMESTAMP_BIT_LEN);
            edited_timestamp = timestamp + timestamp_wraparound_counter;
            RDD_TRACE_EVENT_EVENT_ID_READ(event_type, &entry);
            if (event_type == TRACE_EVENT_SCHEDULER)
                print_scheduler_event(trace_buf, log_to_file, &entry, edited_timestamp, core_id);
            else
                print_cs_event(trace_buf, log_to_file, &entry, edited_timestamp, event_type, core_id, &prev_task);
#ifndef _CFE_
            if (log_to_file)
                bdmf_file_write(trace_log, trace_buf, strlen(trace_buf));
            else
                bdmf_session_print(session, "%s", trace_buf);
#else
            bdmf_session_print(session, trace_buf);
#endif
            p++;
            event_count++;
            entry = *p;
            prev_timestamp = timestamp;
            RDD_TRACE_EVENT_TIMESTAMP_READ(timestamp, &entry);
            RDD_TRACE_EVENT_TRACE_EVENT_INFO_READ(event_info, &entry);
        }
    }
    else if (profiling_on)
        bdmf_session_print(session, "\nProfiling is still running. Please try again later.\n");
#ifndef _CFE_
    if (log_to_file)
    {
        bdmf_session_print(session, "Trace dumped to %s\n", filename);
        /* close trace log file */
        bdmf_file_close(trace_log);
    }
#endif

    return rc;
}

static int rdp_drv_profiling_get_idle(bdmf_session_handle session)
{
    int core, rc = BDMF_ERR_OK;
    uint32_t idle_prmille;
    struct xrdp_rnr_profiling_res res = {};
#if defined(XRDP)
    uint32_t accamulative_idle = 0, average_idle = 0, num_of_processing_cores = 0;
    uint16_t procesing_cores_bit_mask = 0;
#endif

    rc = xrdp_rnr_profiling_get_result(&res);
    if (rc)
    {
        bdmf_session_print(session, "\nFailed to get profiling result, err=%d.\n", rc);
        return rc;
    }


    if (!res.profiling_on && res.total_cnt)
    {
        for (core = 0; core < NUM_OF_RUNNER_CORES; core += (NUM_OF_RUNNER_CORES / NUM_OF_RNR_WITH_PROFILING))
        {
        	idle_prmille = (1000 * res.idle_cnts[core] + res.total_cnt / 2) / res.total_cnt; /*to increase precision xx.x% */
            bdmf_session_print(session, "\ncore %2u was idle for %u cycles out of %u total cycles:         %3u.%u %% idle time\n",
                core, res.idle_cnts[core], res.total_cnt, (idle_prmille / 10), (idle_prmille % 10));
#if defined(XRDP)
            if ( IS_PROCESSING_RUNNER_IMAGE( core ) )
            {
            	MS_SET_BIT_I(procesing_cores_bit_mask, core, 1);
            	num_of_processing_cores++;
            	accamulative_idle += idle_prmille;
            }
        }
        if (num_of_processing_cores)
        {
            average_idle =  (accamulative_idle + num_of_processing_cores / 2) / num_of_processing_cores;
            bdmf_session_print(session, "\nprocessing cores [");
            for (core = 0; core < NUM_OF_RUNNER_CORES; core += (NUM_OF_RUNNER_CORES / NUM_OF_RNR_WITH_PROFILING))
            {
                if (MS_GET_BIT_I(procesing_cores_bit_mask, core))
                	bdmf_session_print(session, "%u, ", core);
            }
            bdmf_session_print(session, "] were idle by average:         %3u.%u %% idle time\n", (average_idle / 10), (average_idle % 10));
#endif
        }
    }
    else if (res.profiling_on)
        bdmf_session_print(session, "\nProfiling is still running. Please try again later.\n");
    return rc;
}

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))
#endif
static int rdp_drv_profiling_enable(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    struct xrdp_rnr_profiling_cfg cfg = {};
    int i;

#if defined(BCM6858)
    for (i = 0; i < ARRAY_SIZE(cfg.enable_quads) && i < n_parms; i++)
        cfg.enable_quads[i] = parm[i].value.unumber;
    if (i < n_parms)
        cfg.num_cycles = parm[i].value.unumber;
#else
    if (n_parms) {
        for (i = 0; i < ARRAY_SIZE(cfg.enable_quads); i++)
            cfg.enable_quads[i] = 1;
        cfg.num_cycles = parm[0].value.unumber;
    }
#endif

    return xrdp_rnr_profiling_set_config(&cfg);
}

static inline bdmf_boolean is_task_defined_anywhere(uint8_t task_num)
{
    uint8_t core;
    for (core = 0; core < NUM_OF_RUNNER_CORES; core += 4)
        if (TASK_EXISTS(image_task_names, core, task_num))
            return 1;
    return 0;
}

static int rdp_drv_profiling_collect_trace_data(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    int rc = BDMF_ERR_OK;
    uint8_t core, i, tsk;
    char trace_filename[] = "/var/log/trace_quad_0_single_task_15.csv";
    bdmfmon_cmd_parm_t pe_parm[] = {
#if defined(BCM6858)
        {.value.unumber = 1 /* enable quad 0 */}, {.value.unumber = 1 /* enable quad 1 */},
        {.value.unumber = 1 /* enable quad 2 */}, {.value.unumber = 1 /* enable quad 3 */},
#endif
        {.value.unumber = 0xFFFF /* 64k cycles */}
    },
                       ct_parm[] = {{.value.unumber = 0 /* RNR_0 */}, {.value.unumber = 0 /* enable scheduler events */},
                       {.value.unumber = 1 /* single task mode */}, {.value.unumber = 0 /* task id = 0 */}},
                       dt_parm[] = {{.value.unumber = 0 /* RNR_QUAD_0 */}, {.value.unumber = 1 /* log to file */ }, {.value.string = trace_filename}};
    /* go through task nums while not ALL task names are "" */
    for (tsk = 0; (tsk < RUNNER_MAX_TASKS_NUM) && (is_task_defined_anywhere(tsk)) && (!rc); tsk++)
    {
        /* create params and fill them accordingly */
        ct_parm[3].value.unumber = tsk;
        for (core = 0; !rc && core < NUM_OF_RUNNER_CORES; core += (NUM_OF_RUNNER_CORES / NUM_OF_RNR_WITH_PROFILING))
        {
            ct_parm[0].value.unumber = core;
            drv_rnr_cli_config_trace(session, ct_parm, ARRAY_LENGTH(ct_parm));
        }
        /* for given number of periods: run pe and then dt */
        for (i = 0; i < parm[0].value.unumber; i++)
        {
            rc = rc ? rc : rdp_drv_profiling_enable(session, pe_parm, ARRAY_LENGTH(pe_parm));
            bdmf_usleep(PROFILING_CYCLES_US_DEF);
            for (core = 0; !rc && core < NUM_OF_RUNNER_CORES; core += (NUM_OF_RUNNER_CORES / NUM_OF_RNR_WITH_PROFILING))
            {
                if (TASK_EXISTS(image_task_names, core, tsk))
                {
                    dt_parm[0].value.unumber = core;
                    sprintf(trace_filename, "/var/log/trace_core_%u_single_task_%u.csv", core, tsk);
                    dt_parm[2].value.string = trace_filename;
                    rc = rc ? rc : rdp_drv_profiling_trace_dump(session, dt_parm, ARRAY_LENGTH(dt_parm));
                }
            }
        }
    }

    return rc;
}

static int rdp_drv_print_tm_bs_info(bdmf_session_handle session, rdpa_traffic_dir dir, uint8_t bbh_queue, uint8_t sub_tm)
{
    rdd_tm_info tm_info = {};
    qm_wred_profile_cfg wred_profile = {};
    uint8_t i;
    qm_q_context q_context = {};
    char **line;

    line=(char **)bdmf_alloc(16*sizeof(char *));
    for(i = 0; i < 16; i++)
        line[i]=(char *)bdmf_alloc(256*sizeof(char));

    if (sub_tm)
        rdd_tm_debug_bs_get(dir, bbh_queue, &tm_info);
    else
        rdd_tm_debug_get(dir, bbh_queue, &tm_info);
    if (tm_info.enable)
    {
        bdmf_session_print(session, "________________\n");
        bdmf_session_print(session, "|basic sched     |\n");
        if (sub_tm)
            bdmf_session_print(session, "|slot_idx=%02d   |\n", (sub_tm - 1));
        else
            bdmf_session_print(session, "|bbh_queue=%02d  |\n", bbh_queue);
        bdmf_session_print(session, "|sched_idx=%02d  |\n", tm_info.sched_index);
        bdmf_session_print(session, "|wrr_offset=%02d |\n", tm_info.dwrr_offset);
        if (tm_info.sched_rl.rl_en)
            bdmf_session_print(session, "|rl_index=%03d  |\n|rate=0x%07x|\n", tm_info.sched_rl.rl_index, tm_info.sched_rl.rl_rate);
        bdmf_session_print(session, "________________\n\n");
        for (i = 0; i < BASIC_SCHEDULER_NUM_OF_QUEUES; ++i)
        {
            if (tm_info.queue_info[i].queue_bit_mask)
            {
                drv_qm_queue_get_config(tm_info.queue_info[i].queue_index, &q_context);
                ag_drv_qm_wred_profile_cfg_get(q_context.wred_profile, &wred_profile);
                sprintf(line[0] + i*16, "________________ ");
                sprintf(line[1] + i*16, "|slot_idx=%d     | ", i);
                sprintf(line[2] + i*16, "|qm_queue=%03d   | ", tm_info.queue_info[i].queue_index);
                sprintf(line[3] + i*16, "|weight=%03d     | ", tm_info.queue_info[i].queue_weight);
                sprintf(line[4] + i*16, "|force_copy=%03d | ", q_context.copy_to_ddr);
                sprintf(line[5] + i*16, "|not_copy=%03d   | ", q_context.ddr_copy_disable);
                sprintf(line[6] + i*16, "|agg_dis=%03d    | ", q_context.aggregation_disable);
                sprintf(line[7] + i*16, "|fpm_ug=%03d     | ", q_context.fpm_ug);
                sprintf(line[8] + i*16, "|q_802_1ae=%03d  | ", q_context.q_802_1ae);
                sprintf(line[9] + i*16, "|sci=%03d        | ", q_context.sci);
                sprintf(line[10] + i*16, "|fec_enable=%03d | ", q_context.fec_enable);
                sprintf(line[11] + i*16, "|min_thr=%05d  | ", wred_profile.min_thr0);
                sprintf(line[12] + i*16, "|max_thr=%05d  | ", wred_profile.max_thr0);
                if (tm_info.queue_info[i].queue_rl.rl_en)
                {
                    sprintf(line[13] + i*16, "|rl_index=%03d   | ", tm_info.queue_info[i].queue_rl.rl_index);
                    sprintf(line[14] + i*16, "|rate=0x%07x | ", tm_info.queue_info[i].queue_rl.rl_rate);
                }
                else
                {
                    sprintf(line[13] + i*16, "|               | ");
                    sprintf(line[14] + i*16, "|               | ");
                }
                sprintf(line[15] + i*16, "________________ ");
            }
        }
        for (i = 0; i < 16; i++)
            bdmf_session_print(session, "%s\n", line[i]);
    }

    if (line)
    {
        for (i = 0; i < 16; i++)
            bdmf_free(line[i]);
        bdmf_free(line);
    }
    return 0;
}

static int rdp_drv_print_tm_cs_info(bdmf_session_handle session, rdpa_traffic_dir dir, uint8_t bbh_queue)
{
    rdd_tm_info tm_info = {};
    qm_wred_profile_cfg wred_profile = {};
    uint8_t i;
    qm_q_context q_context = {};
    bdmf_boolean zero_idx_printed = 0;
    char **line;

    line=(char **)bdmf_alloc(16*sizeof(char *));
    for(i = 0; i < 16; i++)
        line[i]=(char *)bdmf_alloc(1024*sizeof(char));

    rdd_tm_debug_get(dir, bbh_queue, &tm_info);

    if (tm_info.enable)
    {
        bdmf_session_print(session, "________________\n");
        bdmf_session_print(session, "|complex sched   |\n");
        bdmf_session_print(session, "|bbh_queue=%02d  |\n", bbh_queue);
        bdmf_session_print(session, "|sched_idx=%02d  |\n", tm_info.sched_index);
        bdmf_session_print(session, "|wrr_offset=%02d |\n", tm_info.dwrr_offset);
        if (tm_info.sched_rl.rl_en)
            bdmf_session_print(session, "|rl_index=%03d  |\n|rate=0x%07x|\n", tm_info.sched_rl.rl_index, tm_info.sched_rl.rl_rate);
        bdmf_session_print(session, "________________\n\n");
        for (i = 0; i < RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BLOCK_INDEX_NUMBER; ++i)
        {
            if ((tm_info.queue_info[i].queue_bit_mask) || (!zero_idx_printed))
            {
                if (!tm_info.queue_info[i].queue_bit_mask)
                    zero_idx_printed = 1;
                if (tm_info.bs_exist)
                    rdp_drv_print_tm_bs_info(session, dir, tm_info.queue_info[i].queue_index, i + 1);
                else
                {
                    drv_qm_queue_get_config(tm_info.queue_info[i].queue_index, &q_context);
                    ag_drv_qm_wred_profile_cfg_get(q_context.wred_profile, &wred_profile);
                    sprintf(line[0] + i*16, "________________ ");
                    sprintf(line[1] + i*16, "|slot_idx=%d     | ", i);
                    sprintf(line[2] + i*16, "|qm_queue=%03d   | ", tm_info.queue_info[i].queue_index);
                    sprintf(line[3] + i*16, "|weight=%03d     | ", tm_info.queue_info[i].queue_weight);
                    sprintf(line[4] + i*16, "|force_copy=%03d | ", q_context.copy_to_ddr);
                    sprintf(line[5] + i*16, "|not_copy=%03d   | ", q_context.ddr_copy_disable);
                    sprintf(line[6] + i*16, "|agg_dis=%03d    | ", q_context.aggregation_disable);
                    sprintf(line[7] + i*16, "|fpm_ug=%03d     | ", q_context.fpm_ug);
                    sprintf(line[8] + i*16, "|q_802_1ae=%03d  | ", q_context.q_802_1ae);
                    sprintf(line[9] + i*16, "|sci=%03d        | ", q_context.sci);
                    sprintf(line[10] + i*16, "|fec_enable=%03d | ", q_context.fec_enable);
                    sprintf(line[11] + i*16, "|min_thr=%05d  | ", wred_profile.min_thr0);
                    sprintf(line[12] + i*16, "|max_thr=%05d  | ", wred_profile.max_thr0);
                    if (tm_info.queue_info[i].queue_rl.rl_en)
                    {
                        sprintf(line[13] + i*16, "|rl_index=%03d   | ", tm_info.queue_info[i].queue_rl.rl_index);
                        sprintf(line[14] + i*16, "|rate=0x%07x | ", tm_info.queue_info[i].queue_rl.rl_rate);
                    }
                    else
                    {
                        sprintf(line[13] + i*16, "|               | ");
                        sprintf(line[14] + i*16, "|               | ");
                    }
                    sprintf(line[15] + i*16, "________________ ");
                }
            }
        }
        if (!tm_info.bs_exist)
            for (i = 0; i < 16; i++)
                bdmf_session_print(session, "%s\n", line[i]);
    }

    if (line)
    {
        for (i = 0; i < 16; i++)
            bdmf_free(line[i]);
        bdmf_free(line);
    }
    return 0;
}

static int rdp_drv_print_tm_info(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    uint8_t dir = parm[0].value.number, bbh_queue = parm[1].value.number;
    int rc;

    if (dir == rdpa_dir_ds)
        rc = rdp_drv_print_tm_bs_info(session, dir, bbh_queue, 0);
    else
    {
        if (rdd_tm_is_cs_exist(dir, bbh_queue))
            rc = rdp_drv_print_tm_cs_info(session, dir, bbh_queue);
        else
            rc = rdp_drv_print_tm_bs_info(session, dir, bbh_queue, 0);
    }

    return rc;
}

#ifdef G9991
static int rdp_drv_shell_get_flow_control_rx_count(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    dsptchr_qdes_bfout bfout = {};
    int rc;

    rc = ag_drv_dsptchr_qdes_bfout_get(0, &bfout);

    if (rc)
        bdmf_session_print(session, "Error: while trying read flow control rx count\n");
    else
        bdmf_session_print(session, "Number of rx flow control is: %d\n", bfout.qdes_bfout[DISP_REOR_VIQ_BBH_RX7_EXCL]);

    bdmf_session_print(session, "\n");
    return rc;
}
#endif

static char *pvdc_str[] =
{
    [COUNTER_TM_PD_NOT_VALID_ID]                      = "TM PD not valid",
    [COUNTER_TM_ACTION_NOT_VALID_ID]                  = "TM action not valid",
    [COUNTER_EPON_TM_PD_NOT_VALID_ID]                 = "EPON TM PD not valid",
#ifdef G9991
    [COUNTER_G9991_TM_PD_NOT_VALID_ID]                = "G9991 TM PD not valid",
#endif
    [COUNTER_PROCESSING_ACTION_NOT_VALID_ID]          = "Processing action not valid ID",
    [COUNTER_CPU_RECYCLE_RING_CONGESTION]             = "CPU Recycle Ring congestion",
    [COUNTER_CPU_RX_FEED_RING_CONGESTION]             = "CPU RX Feed Ring Congestion",
    [COUNTER_CPU_RX_PSRAM_DROP]                       = "CPU RX PSRAM drop",
    [COUNTER_IPTV_HASH_LKP_MISS_DROP]                 = "IPTV hash lkp miss drop",
    [COUNTER_IPTV_SIP_VID_LKP_MISS_DROP]              = "IPTV SIP VID lkp miss drop",
    [COUNTER_IPTV_INVALID_CTX_ENTRY_DROP]             = "IPTV invalid ctx entry drop",
    [COUNTER_IPTV_FPM_ALLOC_NACK_DROP]                = "IPTV FPM alloc NACK drop",
    [COUNTER_IPTV_FIRST_REPL_DISP_ALLOC_NACK_DROP]    = "IPTV first repl disp alloc NACK drop",
    [COUNTER_IPTV_EXCEPTION_DROP]                     = "IPTV_exception_drop",
    [COUNTER_IPTV_OTHER_REPL_DISP_ALLOC_NACK_DROP]    = "IPTV other repl disp alloc NACK drop",
    [COUNTER_CPU_TX_COPY_NO_FPM]                      = "CPU TX copy no FPM",
    [COUNTER_CPU_TX_COPY_NO_SBPM]                     = "CPU TX copy no SBPM",
    [COUNTER_CPU_RX_TC_TO_RXQ_MAP_DROP]               = "CPU RX TC to RXQ map drop",
    [COUNTER_CPU_RX_VPORT_TO_CPU_OBJ_MAP_DROP]        = "CPU RX Vport TO CPU Object map drop",
    [COUNTER_ETHERNET_FLOW_DROP_ACTION]               = "Ethernet Flow drop action",
    [COUNTER_SBPM_ALLOC_EXCEPTION_DROP]               = "SBPM Alloc Exception drop",
    [COUNTER_DROP_CONNECTION_ACTION_DROP_ID]          = "Drop Connection Action drop ID",
    [COUNTER_DROP_RESOURCE_CONGESTION_INGRESS]        = "Drop ingress Resource Connection",
    [COUNTER_DROP_RESOURCE_CONGESTION_EGRESS]         = "Drop egress Resource Connection",   
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_DHCP] = "DS Ingress filter DHCP",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_ETYPE_PPPOE_D] = "DS Ingress filter PPPOE_D",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_ETYPE_PPPOE_S] = "DS Ingress filter PPPOE_S",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_IGMP] = "DS Ingress filter IGMP",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_MLD] = "DS Ingress filter MLD",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_ICMPV6] = "DS Ingress filter ICMPV6",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_HDR_ERR] = "DS Ingress filter HDR_ERR",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_IP_FRAGMENT] = "DS Ingress filter IP_FRAGMENT",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_ETYPE_UDEF_0] = "DS Ingress filter ETYPE_UDEF_0",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_ETYPE_UDEF_1] = "DS Ingress filter ETYPE_UDEF_1",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_ETYPE_UDEF_2] = "DS Ingress filter ETYPE_UDEF_2",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_ETYPE_UDEF_3] = "DS Ingress filter ETYPE_UDEF_3",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_ETYPE_ARP] = "DS Ingress filter ETYPE_ARP",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_ETYPE_PTP_1588] = "DS Ingress filter ETYPE_PTP_1588",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_ETYPE_802_1X] = "DS Ingress filter ETYPE_802_1X",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_ETYPE_802_1AG_CFM] = "DS Ingress filter ETYPE_802_1AG_CFM",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_MAC_SPOOFING] = "DS Ingress filter MAC_SPOOFING",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_IP_MCAST_CONTROL] = "DS Ingress filter IP_MCAST_CONTROL",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_MCAST] = "DS Ingress filter MCAST",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_BCAST] = "DS Ingress filter BCAST",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_DS + INGRESS_FILTER_L4_PTP_1588] = "DS Ingress filter L4_PTP_1588",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_DHCP] = "US Ingress filter DHCP",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_ETYPE_PPPOE_D] = "US Ingress filter PPPOE_D",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_ETYPE_PPPOE_S] = "US Ingress filter PPPOE_S",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_IGMP] = "US Ingress filter IGMP",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_MLD] = "US Ingress filter MLD",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_ICMPV6] = "US Ingress filter ICMPV6",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_HDR_ERR] = "US Ingress filter HDR_ERR",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_IP_FRAGMENT] = "US Ingress filter IP_FRAGMENT",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_ETYPE_UDEF_0] = "US Ingress filter ETYPE_UDEF_0",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_ETYPE_UDEF_1] = "US Ingress filter ETYPE_UDEF_1",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_ETYPE_UDEF_2] = "US Ingress filter ETYPE_UDEF_2",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_ETYPE_UDEF_3] = "US Ingress filter ETYPE_UDEF_3",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_ETYPE_ARP] = "US Ingress filter ETYPE_ARP",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_ETYPE_PTP_1588] = "US Ingress filter ETYPE_PTP_1588",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_ETYPE_802_1X] = "US Ingress filter ETYPE_802_1X",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_ETYPE_802_1AG_CFM] = "US Ingress filter ETYPE_802_1AG_CFM",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_MAC_SPOOFING] = "US Ingress filter MAC_SPOOFING",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_IP_MCAST_CONTROL] = "US Ingress filter IP_MCAST_CONTROL",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_MCAST] = "US Ingress filter MCAST",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_BCAST] = "US Ingress filter BCAST",
    [COUNTER_INGRESS_FILTER_DROP_FIRST_US + INGRESS_FILTER_L4_PTP_1588] = "US Ingress filter L4_PTP_1588",
    [COUNTER_CPU_RX_METER_DROP] = "CPU RX Meter drop",
    [COUNTER_INGRESS_ISOLATION_DROP] = "Ingress VLAN Isolation",
    [COUNTER_EGRESS_ISOLATION_DROP] = "Egress VLAN Isolation",
    [COUNTER_DA_LKP_MISS_DROP] = "Bridge ARL miss on DA MAC lookup",
    [COUNTER_SA_LKP_MISS_DROP] = "Bridge ARL miss on SA MAC lookup",
    [COUNTER_BRIDGE_FW_ELIGABILITY_DROP] = 
        "Bridge forwarding eligability drop - ingress and egress ports don't belong to the same bridge",
    [COUNTER_DA_LKP_MATCH_DROP] = "DA lookup drop on matched entry",
    [COUNTER_SA_LKP_MATCH_DROP] = "SA lookup drop on matched entry",
 
    [COUNTER_DROP_DISABLED_QUEUE] = "Drop queue disabled",
    [COUNTER_DROP_DISABLED_TX_FLOW] = "TX flow disabled",
    [COUNTER_SBPM_LIB_DISP_CONG] = "SBPM LIB Dispatcher Congestion",
    [COUNTER_CPU_FEED_RING_DISP_CONGESTION] = "CPU_RX Feed MGMT Dispatcher Congestion",
    [COUNTER_BRIDGE_FLOODING] = "Flooded by bridge",

    /* Protocol filters */
    [COUNTER_DIS_PROTO_DS_IPV4] = "Drop by DS Protocol Filter IPv4",
    [COUNTER_DIS_PROTO_DS_IPV6] = "Drop by DS Protocol Filter IPv6",
    [COUNTER_DIS_PROTO_DS_PPPOE] = "Drop by DS Protocol Filter PPPoE",
    [COUNTER_DIS_PROTO_DS_NON_IP] = "Drop by DS Protocol Filter Non-IP",
    [COUNTER_DIS_PROTO_US_IPV4] = "Drop by US Protocol Filter IPv4",
    [COUNTER_DIS_PROTO_US_IPV6] = "Drop by US Protocol Filter IPv6",
    [COUNTER_DIS_PROTO_US_PPPOE] = "Drop by US Protocol Filter PPPoE",
    [COUNTER_DIS_PROTO_US_NON_IP] = "Drop by US Protocol Filter Non-IP",

#ifdef G9991
    /* G9991 reassembly */
    [COUNTER_G9991_SOF_AFTER_SOF] = "G9991 SOF after SOF",
    [COUNTER_G9991_MOF_EOF_WITHOUT_SOF] = "G9991 MOF/EOF without SOF",
    [COUNTER_G9991_REASSEMBLY_ERROR] = "G9991 reassembly error"
#endif
};

static int rdp_drv_shell_print_various_counters(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    int rc = 0, i;
    uint16_t cntr = 0;

    bdmf_session_print(session, "Various Counters:\n\r");
    bdmf_session_print(session, "=================\n\r");

    for (i = COUNTER_FIRST; i <= COUNTER_LAST; i++)
    {
        if (i > COUNTER_LAST_NON_DHD)
            break;
        rc = drv_cntr_varios_counter_get(i, &cntr);
        if (!rc && cntr != 0)
            bdmf_session_print(session, "%s: %d\n\r", pvdc_str[i], cntr);
    }

    return rc;
}

static int rdp_drv_shell_print_counters_mapping(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    int rc = 0, i;
    uint32_t cntr_id;
    RDD_RX_FLOW_ENTRY_DTS rx_flow_entry = {};

    bdmf_session_print(session, "RX Counters:\n\r");
    bdmf_session_print(session, "============\n\r");

    bdmf_session_print(session, "Flow   |   vport   |  cntr_id\n\r");
    bdmf_session_print(session, "-----------------------------\n\r");

    for (i = 0; i < RDD_RX_FLOW_TABLE_SIZE; i++)
    {
        rc = rdd_rx_flow_params_get(i, &rx_flow_entry);
        if (rc)
            continue;
        if (rx_flow_entry.cntr_id != RX_FLOW_CNTR_GROUP_INVLID_CNTR)
            bdmf_session_print(session, "%4d   |   %4d   |   %4d\n\r", i, rx_flow_entry.virtual_port, rx_flow_entry.cntr_id);
    }
    bdmf_session_print(session, "TX Counters:\n\r");
    bdmf_session_print(session, "============\n\r");

    bdmf_session_print(session, "Flow   |  cntr_id\n\r");
    bdmf_session_print(session, "-----------------\n\r");


    for (i = 0; i < RDD_TM_FLOW_CNTR_TABLE_SIZE * 2; i++)
    {
        cntr_id = rdd_tm_flow_cntr_id_get(i);
        if (cntr_id != TX_FLOW_CNTR_GROUP_INVLID_CNTR)
            bdmf_session_print(session, "%4d   |   %4d\n\r", i, cntr_id);
    }

    return rc;
}

static bdmfmon_handle_t drv_shell_dir;

void rdp_drv_shell_init(bdmfmon_handle_t driver_dir)
{
    drv_shell_dir = bdmfmon_dir_add(driver_dir, "drv_shell", "shell", BDMF_ACCESS_ADMIN, NULL);

    BDMFMON_MAKE_CMD(drv_shell_dir, "cpu_tx", "stop cpu_tx traffic", rdp_drv_shell_cpu_tx_disable,
                    BDMFMON_MAKE_PARM_RANGE("disable", "disable cpu_tx traffic", BDMFMON_PARM_UNUMBER, 0, 0, 1));

    BDMFMON_MAKE_CMD(drv_shell_dir, "iso", "isolate dispatch configuration", rdp_drv_shell_isolate_set,
                     BDMFMON_MAKE_PARM_RANGE("core", "core index", BDMFMON_PARM_NUMBER, 0, 0, RNR_LAST),
                     BDMFMON_MAKE_PARM_RANGE("task", "task index", BDMFMON_PARM_NUMBER, 0, 0, (RUNNER_MAX_TASKS_NUM - 1)),
                     BDMFMON_MAKE_PARM_RANGE("rnr_grp", "runner_group", BDMFMON_PARM_NUMBER, 0, 0, (RUNNER_GROUP_MAX_NUM - 1)));

    BDMFMON_MAKE_CMD(drv_shell_dir, "riso", "restore configurations after isolate dispatch", rdp_drv_shell_isolate_restore,
                     BDMFMON_MAKE_PARM_RANGE("rnr_grp", "runner_group", BDMFMON_PARM_NUMBER, 0, 0, (RUNNER_GROUP_MAX_NUM - 1)));

    BDMFMON_MAKE_CMD_NOPARM(drv_shell_dir, "pvc", "print various counters", rdp_drv_shell_print_various_counters);
                     
    BDMFMON_MAKE_CMD_NOPARM(drv_shell_dir, "pcm", "print counters mapping", rdp_drv_shell_print_counters_mapping);

#if !defined(BCM6858)
    BDMFMON_MAKE_CMD(drv_shell_dir, "pe", "profiling enable", rdp_drv_profiling_enable,
         BDMFMON_MAKE_PARM_RANGE_DEFVAL("num_cycles", "profiling cycles", BDMFMON_PARM_UNUMBER, 0, 0, 0xFFFF, 0xFFFF));
#else
    BDMFMON_MAKE_CMD(drv_shell_dir, "pe", "profiling enable", rdp_drv_profiling_enable,
         BDMFMON_MAKE_PARM_RANGE("quad_0_en", "enable trace for quad 0", BDMFMON_PARM_UNUMBER, 0, 0, 1),
         BDMFMON_MAKE_PARM_RANGE("quad_1_en", "enable trace for quad 1", BDMFMON_PARM_UNUMBER, 0, 0, 1),
         BDMFMON_MAKE_PARM_RANGE("quad_2_en", "enable trace for quad 2", BDMFMON_PARM_UNUMBER, 0, 0, 1),
         BDMFMON_MAKE_PARM_RANGE("quad_3_en", "enable trace for quad 3", BDMFMON_PARM_UNUMBER, 0, 0, 1),
         BDMFMON_MAKE_PARM_RANGE_DEFVAL("num_cycles", "profiling cycles", BDMFMON_PARM_UNUMBER, 0, 0, 0xFFFF, 0xFFFF));
#endif
    BDMFMON_MAKE_CMD(drv_shell_dir, "ptm", "print tm information", rdp_drv_print_tm_info,
        BDMFMON_MAKE_PARM_RANGE("direction", "0 - ds, 1 - us", BDMFMON_PARM_NUMBER, 0, 0, 1),
        BDMFMON_MAKE_PARM_RANGE("bbh_queue", "BBH QUEUE ID", BDMFMON_PARM_NUMBER, 0, 0, 31));

    BDMFMON_MAKE_CMD(drv_shell_dir, "dt", "dump trace buffer", rdp_drv_profiling_trace_dump,
         BDMFMON_MAKE_PARM_ENUM("core_id", "core_id", rnr_id_enum_table, 0),
         BDMFMON_MAKE_PARM_RANGE("log_to_file", "0 - to screen, 1 - to file", BDMFMON_PARM_UNUMBER, 0, 0, 1));

    BDMFMON_MAKE_CMD_NOPARM(drv_shell_dir, "rut", "runner utilization", (bdmfmon_cmd_cb_t)rdp_drv_profiling_get_idle);

    BDMFMON_MAKE_CMD(drv_shell_dir, "ctd", "collect trace data", rdp_drv_profiling_collect_trace_data,
             BDMFMON_MAKE_PARM_RANGE("num_periods", "number of profiling periods to run", BDMFMON_PARM_UNUMBER, 0, 1, 100));

#ifdef G9991
    BDMFMON_MAKE_CMD_NOPARM(drv_shell_dir, "pfc",   "print flow control rx count", rdp_drv_shell_get_flow_control_rx_count);
#endif
}

void rdp_drv_shell_exit(bdmfmon_handle_t driver_dir)
{
    if (drv_shell_dir)
    {
        bdmfmon_token_destroy(drv_shell_dir);
        drv_shell_dir = NULL;
    }
}
#endif
