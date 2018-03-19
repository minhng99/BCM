/*
* <:copyright-BRCM:2016:proprietary:standard
* 
*    Copyright (c) 2016 Broadcom 
*    All Rights Reserved
* 
*  This program is the proprietary software of Broadcom and/or its
*  licensors, and may only be used, duplicated, modified or distributed pursuant
*  to the terms and conditions of a separate, written license agreement executed
*  between you and Broadcom (an "Authorized License").  Except as set forth in
*  an Authorized License, Broadcom grants no license (express or implied), right
*  to use, or waiver of any kind with respect to the Software, and Broadcom
*  expressly reserves all rights in and to the Software and all intellectual
*  property rights therein.  IF YOU HAVE NO AUTHORIZED LICENSE, THEN YOU HAVE
*  NO RIGHT TO USE THIS SOFTWARE IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY
*  BROADCOM AND DISCONTINUE ALL USE OF THE SOFTWARE.
* 
*  Except as expressly set forth in the Authorized License,
* 
*  1. This program, including its structure, sequence and organization,
*     constitutes the valuable trade secrets of Broadcom, and you shall use
*     all reasonable efforts to protect the confidentiality thereof, and to
*     use this information only in connection with your use of Broadcom
*     integrated circuit products.
* 
*  2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
*     AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
*     WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
*     RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND
*     ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT,
*     FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR
*     COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE
*     TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR
*     PERFORMANCE OF THE SOFTWARE.
* 
*  3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR
*     ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL,
*     INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY
*     WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
*     IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES;
*     OR (ii) ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE
*     SOFTWARE ITSELF OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS
*     SHALL APPLY NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY
*     LIMITED REMEDY.
* :> 
*/

#include "bdmf_dev.h"
#include "rdpa_api.h"
#include "rdpa_int.h"
#include "rdpa_common.h"
#include "rdd.h"
#include "rdd_dhd_helper.h"
#include "rdpa_platform.h"
#include "rdpa_dhd_helper_basic.h"
#include "rdpa_dhd_helper_ex.h"
#include "rdp_drv_dhd.h"


static void dhd_init_cfg_dump(rdpa_dhd_init_cfg_t *init_cfg)
{
    bdmf_trace("Initial configuration\n");
    bdmf_trace("=================================\n");
    bdmf_trace("\trx_post_flow_ring_base_addr : %p\n", init_cfg->rx_post_flow_ring_base_addr);
    bdmf_trace("\ttx_post_flow_ring_base_addr : %p\n", init_cfg->tx_post_flow_ring_base_addr);
    bdmf_trace("\trx_complete_flow_ring_base_addr : %p\n", init_cfg->rx_complete_flow_ring_base_addr);
    bdmf_trace("\ttx_complete_flow_ring_base_addr : %p\n", init_cfg->tx_complete_flow_ring_base_addr);
    bdmf_trace("\n");
    bdmf_trace("\tr2d_wr_arr_base_addr : %p, phys_addr : %p\n", init_cfg->r2d_wr_arr_base_addr, (void *)(uintptr_t)init_cfg->r2d_wr_arr_base_phys_addr);
    bdmf_trace("\td2r_rd_arr_base_addr : %p, phys_addr : %p\n", init_cfg->d2r_rd_arr_base_addr, (void *)(uintptr_t)init_cfg->d2r_rd_arr_base_phys_addr);
    bdmf_trace("\tr2d_rd_arr_base_addr : %p, phys_addr : %p\n", init_cfg->r2d_rd_arr_base_addr, (void *)(uintptr_t)init_cfg->r2d_rd_arr_base_phys_addr);
    bdmf_trace("\td2r_wr_arr_base_addr : %p, phys_addr : %p\n", init_cfg->d2r_wr_arr_base_addr, (void *)(uintptr_t)init_cfg->d2r_wr_arr_base_phys_addr);
    bdmf_trace("\ttx_post_mgmt_arr_base_addr : %p, phys_addr : %p\n", init_cfg->tx_post_mgmt_arr_base_addr, (void *)(uintptr_t)init_cfg->tx_post_mgmt_arr_base_phys_addr);
    bdmf_trace("\n");
    
    bdmf_trace("\tDoorbell Wakeup register : 0x%x\n", init_cfg->dongle_wakeup_register);
    bdmf_trace("\tDoorbell ISR : %p\n", init_cfg->doorbell_isr);
    bdmf_trace("\tDoorbell CTX : %p\n", init_cfg->doorbell_ctx);
    
    bdmf_trace("\tadd_llcsnap_header : %d\n", init_cfg->add_llcsnap_header);
    bdmf_trace("\tflow_ring_format : %d\n", init_cfg->flow_ring_format);
}

/** This optional callback is called at object init time
 * after initial attributes are set.
 * Its work is:
 * - make sure that all necessary attributes are set and make sense
 * - allocate dynamic resources if any
 * - assign object name if not done in pre_init
 * - finalise object creation
 * If function returns error code !=0, object creation is aborted
 */
int dhd_helper_post_init_ex(struct bdmf_object *mo)
{
    int rc;
    
    dhd_helper_drv_priv_t *dhd_helper = (dhd_helper_drv_priv_t *)bdmf_obj_data(mo);    
 
    dhd_init_cfg_dump(&dhd_helper->init_cfg);
    rc = rdd_dhd_hlp_cfg(dhd_helper->radio_idx, &dhd_helper->init_cfg, 1);

    if (rc)
        BDMF_TRACE_RET(BDMF_ERR_INTERNAL, "Failed to initialize Flow Rings, rc %d\n", rc);

    return rc;
}

/**  dhd helper destroy callback
 *
 */
void dhd_helper_destroy_ex(struct bdmf_object *mo)
{
}

/**  dhd helper for sending packet to dongle
 *
 */
int rdpa_dhd_helper_send_packet_to_dongle_ex(void *data, uint32_t length, const rdpa_dhd_tx_post_info_t *info)
{    
   rdd_dhd_helper_packet_dump(data, length, info);

   return rdp_drv_dhd_cpu_tx(info, data, length);    
}


/* "flush" attribute "write" callback */
int dhd_helper_attr_flush_write_ex(struct bdmf_object *mo, struct bdmf_attr *ad,
    bdmf_index index, const void *val, uint32_t size)
{
    dhd_helper_drv_priv_t *dhd_helper = (dhd_helper_drv_priv_t *)bdmf_obj_data(mo);
    uint32_t flow_ring_id = *(uint32_t *)val;
    
    return rdp_drv_dhd_helper_flow_ring_flush(dhd_helper->radio_idx, flow_ring_id);
}


/* "flow_ring_enable" attribute "write" callback */
int dhd_helper_attr_flow_ring_enable_write_ex(struct bdmf_object *mo, struct bdmf_attr *ad,
    bdmf_index index, const void *val, uint32_t size)
{
    dhd_helper_drv_priv_t *dhd_helper = (dhd_helper_drv_priv_t *)bdmf_obj_data(mo);
    uint32_t flow_ring_id = (uint32_t)index;
   
    return rdp_drv_dhd_helper_flow_ring_disable(dhd_helper->radio_idx, flow_ring_id);
}


/* "tx_complete_send2host" attribute "write" callback */
int dhd_helper_tx_complete_host_send2dhd_write_ex(struct bdmf_object *mo, struct bdmf_attr *ad,
    bdmf_index index, const void *val, uint32_t size)
{          
    /* not supported in XRDP -return 0 in order not to fail upper driver*/
    return 0;
}

/* "tx_complete_send2host" attribute "read" callback */
int dhd_helper_tx_complete_host_send2dhd_read_ex(struct bdmf_object *mo,
     struct bdmf_attr *ad, bdmf_index index, void *val, uint32_t size)
{
    /* not supported in XRDP -return 0 in order not to fail upper driver*/
    return 0;
}


#if 0
/* FIXME!! TODO!! implement per access category timeout value rather than global timer */
/* "aggregation_timer" attribute "write" callback */
int dhd_helper_aggregation_timer_write_ex(struct bdmf_object *mo,
    struct bdmf_attr *ad, bdmf_index index, const void *val, uint32_t size)
{   
    dhd_helper_drv_priv_t *dhd_helper = (dhd_helper_drv_priv_t *)bdmf_obj_data(mo);
    
    if (dhd_helper->aggregation_timer)
        return 0;
        
    dhd_helper->aggregation_timer = *(uint8_t *)val;    

    return rdd_dhd_helper_aggregation_timer_set(dhd_helper->aggregation_timer);
}
#endif


/* "int_connect" attribute "write" callback */
int dhd_helper_int_connect_write_ex(struct bdmf_object *mo,
    struct bdmf_attr *ad, bdmf_index index, const void *val, uint32_t size)
{
    /* This callback not required anymore, as we are awaking dongle directly */
    
    return 0;
}

void rdpa_dhd_helper_doorbell_interrupt_clear_ex(uint32_t radio_idx)
{
}

void dhd_helper_cpu_exception_rxq_set_ex(dhd_helper_drv_priv_t *dhd_helper, uint8_t rdd_cpu_rxq)
{
    int tc;
    
    bdmf_trace("dhd_helper_cpu_exception_rxq_set_ex: cpu_port = %d, hw_queue = %d\n", (int)dhd_helper->cpu_data.cpu_port, rdd_cpu_rxq);
    RDD_CPU_RING_DESCRIPTOR_INTERRUPT_ID_WRITE_G(rdd_cpu_rxq, RDD_DHD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_ADDRESS_ARR,
        dhd_helper->radio_idx);
    
    /* set allocated dhd queue in exception mapping */
    for (tc = 0; tc < RDPA_CPU_TC_NUM; tc++)
    {        
        rdd_cpu_exc_tc_to_rxq_set(dhd_helper->cpu_data.cpu_port, tc, rdd_cpu_rxq);
    }
}

/* creates DHD Tx complete Ring with given size */
int rdpa_dhd_helper_dhd_complete_ring_create_ex(uint32_t ring_idx, uint32_t ring_size)
{
    return rdp_drv_dhd_helper_dhd_complete_ring_create(ring_idx, ring_size);
}

/* destroys DHD Tx complete Ring with given size */
int rdpa_dhd_helper_dhd_complete_ring_destroy_ex(uint32_t ring_idx, uint32_t ring_size)
{
    return rdp_drv_dhd_helper_dhd_complete_ring_destroy(ring_idx, ring_size);
}

/* gets next entry from DHD Tx complete Ring  */
int rdpa_dhd_helper_dhd_complete_message_get_ex(rdpa_dhd_complete_data_t *dhd_complete_info)
{
    return rdp_drv_dhd_helper_dhd_complete_message_get(dhd_complete_info);
}

/* "rx_post_init" attribute "write" callback */
int dhd_helper_attr_rx_post_init_write_ex(struct bdmf_object *mo, struct bdmf_attr *ad,
    bdmf_index index, const void *val, uint32_t size)
{    
    dhd_helper_drv_priv_t *dhd_helper = (dhd_helper_drv_priv_t *)bdmf_obj_data(mo);

    return rdp_drv_rx_post_init(dhd_helper->radio_idx, &dhd_helper->init_cfg) ? BDMF_ERR_NOMEM : 0;
}


/* "rx_post_uninit" attribute "write" callback */
int dhd_helper_attr_rx_post_uninit_write_ex(struct bdmf_object *mo, struct bdmf_attr *ad,
    bdmf_index index, const void *val, uint32_t size)
{
    dhd_helper_drv_priv_t *dhd_helper = (dhd_helper_drv_priv_t *)bdmf_obj_data(mo);

    return rdp_drv_dhd_rx_post_uninit(dhd_helper->radio_idx, &dhd_helper->init_cfg) ? BDMF_ERR_NOMEM : 0;
}

/* "ssid_tx_dropped_packets" attribute "read" callback */
int dhd_helper_ssid_tx_dropped_packets_read_ex(struct bdmf_object *mo, struct bdmf_attr *ad,
    bdmf_index index, void *val, uint32_t size)
{    
    dhd_helper_drv_priv_t *dhd_helper = (dhd_helper_drv_priv_t *)bdmf_obj_data(mo);
    uint32_t *drops = (uint32_t *)val;
    uint16_t rdd_drops = rdp_drv_dhd_helper_ssid_tx_dropped_packets_get(dhd_helper->radio_idx, index);
    *drops = rdd_drops;

    return 0;
}

void rdpa_dhd_helper_wakeup_information_get_ex(rdpa_dhd_wakeup_info_t *wakeup_info)
{
    rdp_drv_dhd_helper_wakeup_information_get(wakeup_info);
}
