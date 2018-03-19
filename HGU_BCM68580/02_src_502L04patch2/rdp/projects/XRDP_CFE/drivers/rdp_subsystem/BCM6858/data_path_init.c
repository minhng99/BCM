/*
   <:copyright-BRCM:2015:DUAL/GPL:standard

      Copyright (c) 2015 Broadcom
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

#ifdef _CFE_
#include "lib_types.h"
#include "lib_malloc.h"
#include "lib_printf.h"
#include "lib_string.h"
#define xrdp_memset lib_memset
#define xrdp_memcpy lib_memcpy
extern void cfe_usleep(int);
#define xrdp_alloc(_a) KMALLOC(_a, 32)
#define xrdp_usleep(_a) cfe_usleep(_a)
#define BDMF_TRACE_ERR xprintf
#define bdmf_ioremap(_a, _b) _a
#else
#define xrdp_memset memset
#define xrdp_memcpy memcpy
#define xrdp_usleep(_a) bdmf_usleep(_a)
#define xrdp_alloc(_a) bdmf_alloc(_a)
#endif

#include "rdd.h"
#include "rdd_defs.h"
#include "data_path_init.h"
#ifdef RDP_SIM
#include "rdd_ip_class.h"
#endif
#include "rdd_init.h"
#include "rdd_cpu_rx.h"
#ifndef _CFE_
#include "rdd_tcam_ic.h"
#endif
#include "rdp_platform.h"
#include "rdd_basic_scheduler.h"
#include "rdp_drv_sbpm.h"
#include "rdp_drv_cnpl.h"
#include "rdp_drv_cntr.h"
#include "xrdp_drv_psram_ag.h"
#include "xrdp_drv_fpm_ag.h"
#include "rdp_common.h"
#include "rdp_drv_dma.h"
#include "rdp_drv_rnr.h"
#include "rdp_drv_dqm.h"
#include "rdp_drv_dis_reor.h"
#ifndef _CFE_
#include "rdp_drv_natc.h"
#endif
#include "rdp_drv_tcam.h"
#include "rdp_drv_fpm.h"
#ifndef _CFE_
#include "rdp_drv_hash.h"
#include "rdd_tuple_lkp.h"
#endif
#include "xrdp_drv_drivers_common_ag.h"
#include "xrdp_drv_xlif_rx_if_ag.h"
#include "xrdp_drv_xlif_tx_if_ag.h"
#include "xrdp_drv_ubus_mstr_ag.h"
#include "xrdp_drv_ubus_slv_ag.h"
#include "rdp_drv_qm.h"
#include "bdmf_data_types.h"
#include "rdd_scheduling.h"
#ifdef EPON
#include "rdd_ghost_reporting.h"
#endif
#ifdef CONFIG_DHD_RUNNER
#include "dhd_defs.h"
#ifndef _CFE_
#include "rdd_dhd_helper.h"
#endif
#endif
#include "rdpa_config.h"

#undef RNR_LAST
#define RNR_LAST 2

#if defined(CONFIG_BCM_GLB_COHERENCY) && !defined(RDP_SIM)
#include <board.h>
#include "bcm_misc_hw_init.h"
#include "bcm_map_part.h"
#define DECODE_WIN0 0
#define DECODE_WIN1 1
#define CACHE_BIT_OFF 0
#define CACHE_BIT_ON 1
#endif

extern rdpa_speed_type rdpa_wan_speed_get(rdpa_if if_);
extern bdmf_boolean rdpa_is_epon_ae_mode(void);
dpi_params_t *p_dpi_cfg;

extern uint32_t total_length_bytes[];
extern rdpa_emac bbh_id_to_rdpa_emac[BBH_ID_NUM];
extern rdd_bb_id rdpa_emac_to_bb_id_tx[rdpa_emac__num_of];

RDD_FPM_GLOBAL_CFG_DTS g_fpm_hw_cfg;
bbh_rx_sdma_profile_t *g_bbh_rx_sdma_profile;
bbh_tx_dma_profile_t *g_bbh_tx_dma_profile;
bbh_tx_sdma_profile_t *g_bbh_tx_sdma_profile;
bbh_tx_ddr_profile_t *g_bbh_tx_ddr_profile;
queue_to_rnr_t g_lan_queue_to_rnr[1] = { {RNR0, RNR0} };
pd_fifo_size_t g_lan_pd_fifo_size[1] = { {BBH_TX_DS_PD_FIFO_SIZE_0, BBH_TX_DS_PD_FIFO_SIZE_1} };
pd_wkup_threshold_t g_lan_pd_wkup_threshold[2] = { {0, 0}, {0, 0} };
pd_bytes_threshold_t g_lan_pd_bytes_threshold[1] = { {0, 0} };
dma_id_e g_dma_source[] = {BB_ID_DMA0, BB_ID_DMA1, BB_ID_SDMA0, BB_ID_SDMA1};

#ifdef BCM6858
#define XFI_EMAC_PORT 0
#endif

queue_to_rnr_t g_wan_queue_to_rnr[TX_QEUEU_PAIRS] = {
          {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0},
          {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0}, {RNR0, RNR0} };

bbh_to_dma_x_t  g_bbh_to_dma_x[BBH_ID_NUM] = {
          {BBH_ID_XLMAC0_0_10G, DMA1_ID},
          {BBH_ID_XLMAC0_1_2p5G, DMA1_ID},
          {BBH_ID_XLMAC0_2_1G, DMA1_ID},
          {BBH_ID_XLMAC0_3_1G, DMA0_ID},
          {BBH_ID_XLMAC1_0_RGMII, DMA1_ID},
          {BBH_ID_XLMAC1_1_RGMII, DMA0_ID},
          {BBH_ID_XLMAC1_2_RGMII, DMA0_ID},
#ifdef BCM6858
          {BBH_ID_XLMAC1_3_RGMII, DMA0_ID},
#endif
          {BBH_ID_PON, DMA0_ID} };

bbh_id_e g_dma_to_bbh_x[profiles_num][NUM_OF_DMA][NUM_OF_PERIPHERALS_PER_DMA] = {
#ifdef BCM6858
         {{BBH_ID_XLMAC0_3_1G, BBH_ID_XLMAC1_1_RGMII, BBH_ID_XLMAC1_2_RGMII, BBH_ID_XLMAC1_3_RGMII, BBH_ID_PON, BBH_ID_NULL},
          {BBH_ID_XLMAC0_0_10G, BBH_ID_XLMAC0_1_2p5G, BBH_ID_XLMAC0_2_1G, BBH_ID_XLMAC1_0_RGMII, BBH_ID_NULL, BBH_ID_NULL}},
         {{BBH_ID_XLMAC0_3_1G, BBH_ID_XLMAC1_1_RGMII, BBH_ID_XLMAC1_2_RGMII, BBH_ID_XLMAC1_3_RGMII, BBH_ID_PON, BBH_ID_NULL},
          {BBH_ID_XLMAC0_0_10G, BBH_ID_XLMAC0_1_2p5G, BBH_ID_XLMAC0_2_1G, BBH_ID_XLMAC1_0_RGMII, BBH_ID_NULL, BBH_ID_NULL}},
         {{BBH_ID_XLMAC0_3_1G, BBH_ID_XLMAC1_1_RGMII, BBH_ID_XLMAC1_2_RGMII, BBH_ID_XLMAC1_3_RGMII, BBH_ID_PON, BBH_ID_NULL},
#else
         {{BBH_ID_XLMAC0_3_1G, BBH_ID_XLMAC1_1_RGMII, BBH_ID_XLMAC1_2_RGMII, BBH_ID_PON, BBH_ID_NULL, BBH_ID_NULL},
          {BBH_ID_XLMAC0_0_10G, BBH_ID_XLMAC0_1_2p5G, BBH_ID_XLMAC0_2_1G, BBH_ID_XLMAC1_0_RGMII, BBH_ID_NULL, BBH_ID_NULL}},
         {{BBH_ID_XLMAC0_3_1G, BBH_ID_XLMAC1_1_RGMII, BBH_ID_XLMAC1_2_RGMII, BBH_ID_PON, BBH_ID_NULL, BBH_ID_NULL},
          {BBH_ID_XLMAC0_0_10G, BBH_ID_XLMAC0_1_2p5G, BBH_ID_XLMAC0_2_1G, BBH_ID_XLMAC1_0_RGMII, BBH_ID_NULL, BBH_ID_NULL}},
         {{BBH_ID_XLMAC0_3_1G, BBH_ID_XLMAC1_1_RGMII, BBH_ID_XLMAC1_2_RGMII, BBH_ID_PON, BBH_ID_NULL, BBH_ID_NULL},
#endif
          {BBH_ID_XLMAC0_0_10G, BBH_ID_XLMAC0_1_2p5G, BBH_ID_XLMAC0_2_1G, BBH_ID_XLMAC1_0_RGMII, BBH_ID_NULL, BBH_ID_NULL}} };

/* array description:
      - this array describe the buffers weight according to g_dma_to_bbh_X array.
      - total weight is 32 for each DMA (four BBH IDs) */
uint8_t g_bbh_buff_num[profiles_num][NUM_OF_DMA][NUM_OF_PERIPHERALS_PER_DMA] = {
#ifdef BCM6858
         /* PON + No XFI port */ {{5, 5, 5, 5, 12}, {8, 8, 8, 8}},
         /* PON + XFI port0   */ {{5, 5, 5, 5, 12}, {6, 6, 6, 14}},
         /* PON + XFI port4   */ {{5, 5, 5, 5, 12}, {14, 6, 6, 6}} };
#else
         /* PON + No XFI port */ {{6, 6, 6, 14}, {8, 8, 8, 8}},
         /* PON + XFI port0   */ {{6, 6, 6, 14}, {14, 6, 6, 6}},
         /* PON + XFI port4   */ {{6, 6, 6, 14}, {6, 6, 6, 14}} };
#endif

bb_source_t g_dma_bb_source[BBH_ID_NUM] = {
         {BB_ID_RX_XLMAC0_0_10G, BB_ID_TX_XLMAC0_0_10G},
         {BB_ID_RX_XLMAC0_1_2P5G, BB_ID_TX_XLMAC0_1_2P5G},
         {BB_ID_RX_XLMAC0_2_1G, BB_ID_TX_XLMAC0_2_1G},
         {BB_ID_RX_XLMAC0_3_1G, BB_ID_TX_XLMAC0_3_1G},
         {BB_ID_RX_XLMAC1_0_RGMII, BB_ID_TX_XLMAC1_0_RGMII},
         {BB_ID_RX_XLMAC1_1_RGMII, BB_ID_TX_XLMAC1_1_RGMII},
         {BB_ID_RX_XLMAC1_2_RGMII, BB_ID_TX_XLMAC1_2_RGMII},
#ifdef BCM6858
         {BB_ID_RX_XLMAC1_3_RGMII, BB_ID_TX_XLMAC1_3_RGMII},
#endif
         {BB_ID_RX_PON_ETH, BB_ID_TX_PON_ETH_PD} };

uint8_t g_max_otf_reads[BBH_ID_NUM] =
         {MAX_OTF_READ_REQUEST_DEFAULT_DMA1, MAX_OTF_READ_REQUEST_DEFAULT_DMA1,
          MAX_OTF_READ_REQUEST_DEFAULT_DMA1, MAX_OTF_READ_REQUEST_DEFAULT_DMA1,
          MAX_OTF_READ_REQUEST_DEFAULT_DMA1, MAX_OTF_READ_REQUEST_DEFAULT_DMA0,
#ifdef BCM6858
          MAX_OTF_READ_REQUEST_DEFAULT_DMA0, MAX_OTF_READ_REQUEST_DEFAULT_DMA0,
          MAX_OTF_READ_REQUEST_DEFAULT_DMA0};
#else
          MAX_OTF_READ_REQUEST_DEFAULT_DMA0, MAX_OTF_READ_REQUEST_DEFAULT_DMA0};
#endif

urgent_threhold_t g_dma_urgent_threshold[BBH_ID_NUM][2] = {
         { {DMA1_U_THRESH_IN_BBH_ID_XLMAC0_0_10G_VALUE, DMA1_U_THRESH_OUT_BBH_ID_XLMAC0_0_10G_VALUE},
           {SDMA1_U_THRESH_IN_BBH_ID_XLMAC0_0_10G_VALUE, SDMA1_U_THRESH_OUT_BBH_ID_XLMAC0_0_10G_VALUE} },
         { {DMA1_U_THRESH_IN_BBH_ID_XLMAC0_1_2p5G_VALUE, DMA1_U_THRESH_OUT_BBH_ID_XLMAC0_1_2p5G_VALUE},
           {SDMA1_U_THRESH_IN_BBH_ID_XLMAC0_1_2p5G_VALUE, SDMA1_U_THRESH_OUT_BBH_ID_XLMAC0_1_2p5G_VALUE} },
         { {DMA1_U_THRESH_IN_BBH_ID_XLMAC0_2_1G_VALUE, DMA1_U_THRESH_OUT_BBH_ID_XLMAC0_2_1G_VALUE},
           {SDMA1_U_THRESH_IN_BBH_ID_XLMAC0_2_1G_VALUE, SDMA1_U_THRESH_OUT_BBH_ID_XLMAC0_2_1G_VALUE} },
         { {DMA0_U_THRESH_IN_BBH_ID_XLMAC0_3_1G_VALUE, DMA0_U_THRESH_OUT_BBH_ID_XLMAC0_3_1G_VALUE},
           {SDMA0_U_THRESH_IN_BBH_ID_XLMAC0_3_1G_VALUE, SDMA0_U_THRESH_OUT_BBH_ID_XLMAC0_3_1G_VALUE} },
         { {DMA1_U_THRESH_IN_BBH_ID_XLMAC1_0_RGMII_VALUE, DMA1_U_THRESH_OUT_BBH_ID_XLMAC1_0_RGMII_VALUE},
           {SDMA1_U_THRESH_IN_BBH_ID_XLMAC1_0_RGMII_VALUE, SDMA1_U_THRESH_OUT_BBH_ID_XLMAC1_0_RGMII_VALUE} },
         { {DMA0_U_THRESH_IN_BBH_ID_XLMAC1_1_RGMII_VALUE, DMA0_U_THRESH_OUT_BBH_ID_XLMAC1_1_RGMII_VALUE},
           {SDMA0_U_THRESH_IN_BBH_ID_XLMAC1_1_RGMII_VALUE, SDMA0_U_THRESH_OUT_BBH_ID_XLMAC1_1_RGMII_VALUE} },
         { {DMA0_U_THRESH_IN_BBH_ID_XLMAC1_2_RGMII_VALUE, DMA0_U_THRESH_OUT_BBH_ID_XLMAC1_2_RGMII_VALUE},
           {SDMA0_U_THRESH_IN_BBH_ID_XLMAC1_2_RGMII_VALUE, SDMA0_U_THRESH_OUT_BBH_ID_XLMAC1_2_RGMII_VALUE} },
#ifdef BCM6858
         { {DMA0_U_THRESH_IN_BBH_ID_XLMAC1_2_RGMII_VALUE, DMA0_U_THRESH_OUT_BBH_ID_XLMAC1_2_RGMII_VALUE},
           {SDMA0_U_THRESH_IN_BBH_ID_XLMAC1_2_RGMII_VALUE, SDMA0_U_THRESH_OUT_BBH_ID_XLMAC1_2_RGMII_VALUE} },
#endif
         { {DMA0_U_THRESH_IN_BBH_ID_PON_VALUE, DMA0_U_THRESH_OUT_BBH_ID_PON_VALUE},
           {SDMA0_U_THRESH_IN_BBH_ID_PON_VALUE, SDMA0_U_THRESH_OUT_BBH_ID_PON_VALUE} } };

strict_priority_t g_dma_strict_priority[BBH_ID_NUM][2] = {
         { {DMA1_STRICT_PRI_RX_BBH_ID_XLMAC0_0_10G_VALUE, DMA1_STRICT_PRI_TX_BBH_ID_XLMAC0_0_10G_VALUE},
           {SDMA1_STRICT_PRI_RX_BBH_ID_XLMAC0_0_10G_VALUE, SDMA1_STRICT_PRI_TX_BBH_ID_XLMAC0_0_10G_VALUE} },
         { {DMA0_STRICT_PRI_RX_BBH_ID_XLMAC0_1_2p5G_VALUE, DMA0_STRICT_PRI_TX_BBH_ID_XLMAC0_1_2p5G_VALUE},
           {SDMA0_STRICT_PRI_RX_BBH_ID_XLMAC0_1_2p5G_VALUE, SDMA0_STRICT_PRI_TX_BBH_ID_XLMAC0_1_2p5G_VALUE} },
         { {DMA1_STRICT_PRI_RX_BBH_ID_XLMAC0_2_1G_VALUE, DMA1_STRICT_PRI_TX_BBH_ID_XLMAC0_2_1G_VALUE},
           {SDMA1_STRICT_PRI_RX_BBH_ID_XLMAC0_2_1G_VALUE, SDMA1_STRICT_PRI_TX_BBH_ID_XLMAC0_2_1G_VALUE} },
         { {DMA1_STRICT_PRI_RX_BBH_ID_XLMAC0_3_1G_VALUE, DMA1_STRICT_PRI_TX_BBH_ID_XLMAC0_3_1G_VALUE},
           {SDMA1_STRICT_PRI_RX_BBH_ID_XLMAC0_3_1G_VALUE, SDMA1_STRICT_PRI_TX_BBH_ID_XLMAC0_3_1G_VALUE} },
         { {DMA1_STRICT_PRI_RX_BBH_ID_XLMAC1_0_RGMII_VALUE, DMA1_STRICT_PRI_TX_BBH_ID_XLMAC1_0_RGMII_VALUE},
           {SDMA1_STRICT_PRI_RX_BBH_ID_XLMAC1_0_RGMII_VALUE, SDMA1_STRICT_PRI_TX_BBH_ID_XLMAC1_0_RGMII_VALUE} },
         { {DMA0_STRICT_PRI_RX_BBH_ID_XLMAC1_1_RGMII_VALUE, DMA0_STRICT_PRI_TX_BBH_ID_XLMAC1_1_RGMII_VALUE},
           {SDMA0_STRICT_PRI_RX_BBH_ID_XLMAC1_1_RGMII_VALUE, SDMA0_STRICT_PRI_TX_BBH_ID_XLMAC1_1_RGMII_VALUE} },
         { {DMA0_STRICT_PRI_RX_BBH_ID_XLMAC1_2_RGMII_VALUE, DMA0_STRICT_PRI_TX_BBH_ID_XLMAC1_2_RGMII_VALUE},
           {SDMA0_STRICT_PRI_RX_BBH_ID_XLMAC1_2_RGMII_VALUE, SDMA0_STRICT_PRI_TX_BBH_ID_XLMAC1_2_RGMII_VALUE} },
#ifdef BCM6858
         { {DMA0_STRICT_PRI_RX_BBH_ID_XLMAC1_2_RGMII_VALUE, DMA0_STRICT_PRI_TX_BBH_ID_XLMAC1_2_RGMII_VALUE},
           {SDMA0_STRICT_PRI_RX_BBH_ID_XLMAC1_2_RGMII_VALUE, SDMA0_STRICT_PRI_TX_BBH_ID_XLMAC1_2_RGMII_VALUE} },
#endif
         { {DMA0_STRICT_PRI_RX_BBH_ID_PON_VALUE, DMA0_STRICT_PRI_TX_BBH_ID_PON_VALUE},
           {SDMA0_STRICT_PRI_RX_BBH_ID_PON_VALUE, SDMA0_STRICT_PRI_TX_BBH_ID_PON_VALUE} } };

rr_weight_t g_dma_rr_weight[BBH_ID_NUM][2] = {
         { {DMA1_RR_WEIGHT_RX_BBH_ID_XLMAC0_0_10G_VALUE, DMA1_RR_WEIGHT_TX_BBH_ID_XLMAC0_0_10G_VALUE},
           {SDMA1_RR_WEIGHT_RX_BBH_ID_XLMAC0_0_10G_VALUE, SDMA1_RR_WEIGHT_TX_BBH_ID_XLMAC0_0_10G_VALUE} },
         { {DMA0_RR_WEIGHT_RX_BBH_ID_XLMAC0_1_2p5G_VALUE, DMA0_RR_WEIGHT_TX_BBH_ID_XLMAC0_1_2p5G_VALUE},
           {SDMA0_RR_WEIGHT_RX_BBH_ID_XLMAC0_1_2p5G_VALUE, SDMA0_RR_WEIGHT_TX_BBH_ID_XLMAC0_1_2p5G_VALUE} },
         { {DMA1_RR_WEIGHT_RX_BBH_ID_XLMAC0_2_1G_VALUE, DMA1_RR_WEIGHT_TX_BBH_ID_XLMAC0_2_1G_VALUE},
           {SDMA1_RR_WEIGHT_RX_BBH_ID_XLMAC0_2_1G_VALUE, SDMA1_RR_WEIGHT_TX_BBH_ID_XLMAC0_2_1G_VALUE} },
         { {DMA1_RR_WEIGHT_RX_BBH_ID_XLMAC0_3_1G_VALUE, DMA1_RR_WEIGHT_TX_BBH_ID_XLMAC0_3_1G_VALUE},
           {SDMA1_RR_WEIGHT_RX_BBH_ID_XLMAC0_3_1G_VALUE, SDMA1_RR_WEIGHT_TX_BBH_ID_XLMAC0_3_1G_VALUE} },
         { {DMA1_RR_WEIGHT_RX_BBH_ID_XLMAC1_0_RGMII_VALUE, DMA1_RR_WEIGHT_TX_BBH_ID_XLMAC1_0_RGMII_VALUE},
           {SDMA1_RR_WEIGHT_RX_BBH_ID_XLMAC1_0_RGMII_VALUE, SDMA1_RR_WEIGHT_TX_BBH_ID_XLMAC1_0_RGMII_VALUE} },
         { {DMA0_RR_WEIGHT_RX_BBH_ID_XLMAC1_1_RGMII_VALUE, DMA0_RR_WEIGHT_TX_BBH_ID_XLMAC1_1_RGMII_VALUE},
           {SDMA0_RR_WEIGHT_RX_BBH_ID_XLMAC1_1_RGMII_VALUE, SDMA0_RR_WEIGHT_TX_BBH_ID_XLMAC1_1_RGMII_VALUE} },
         { {DMA0_RR_WEIGHT_RX_BBH_ID_XLMAC1_2_RGMII_VALUE, DMA0_RR_WEIGHT_TX_BBH_ID_XLMAC1_2_RGMII_VALUE},
           {SDMA0_RR_WEIGHT_RX_BBH_ID_XLMAC1_2_RGMII_VALUE, SDMA0_RR_WEIGHT_TX_BBH_ID_XLMAC1_2_RGMII_VALUE} },
#ifdef BCM6858
         { {DMA0_RR_WEIGHT_RX_BBH_ID_XLMAC1_2_RGMII_VALUE, DMA0_RR_WEIGHT_TX_BBH_ID_XLMAC1_2_RGMII_VALUE},
           {SDMA0_RR_WEIGHT_RX_BBH_ID_XLMAC1_2_RGMII_VALUE, SDMA0_RR_WEIGHT_TX_BBH_ID_XLMAC1_2_RGMII_VALUE} },
#endif
         { {DMA0_RR_WEIGHT_RX_BBH_ID_PON_VALUE, DMA0_RR_WEIGHT_TX_BBH_ID_PON_VALUE},
           {SDMA0_RR_WEIGHT_RX_BBH_ID_PON_VALUE, SDMA0_RR_WEIGHT_TX_BBH_ID_PON_VALUE} } };

static uint8_t calculate_buffers_offset(uint8_t profile_id, uint8_t dma_num, uint8_t periphreal_num)
{
    uint8_t j, offset = 0;

    for (j = 0; j < periphreal_num; j++)
    {
        offset = offset + g_bbh_buff_num[profile_id][dma_num][j];
    }
    return offset;
}

static int bbh_profiles_init(void)
{
    uint8_t i, j, bbh_id, profile_id;
    bbh_rx_sdma_chunks_cfg_t *bbh_rx_sdma_cfg;
    bbh_tx_bbh_dma_cfg *bbh_tx_dma_cfg;
    bbh_tx_bbh_sdma_cfg *bbh_tx_sdma_cfg;
    bbh_tx_bbh_ddr_cfg *bbh_tx_ddr_cfg;

    g_bbh_rx_sdma_profile = (bbh_rx_sdma_profile_t *)xrdp_alloc(sizeof(bbh_rx_sdma_profile_t));
    g_bbh_tx_dma_profile = (bbh_tx_dma_profile_t *)xrdp_alloc(sizeof(bbh_tx_dma_profile_t));
    g_bbh_tx_sdma_profile = (bbh_tx_sdma_profile_t *)xrdp_alloc(sizeof(bbh_tx_sdma_profile_t));
    g_bbh_tx_ddr_profile = (bbh_tx_ddr_profile_t *)xrdp_alloc(sizeof(bbh_tx_ddr_profile_t));

    /* TODO: check profile ID according to active_ports and board_configuration */
    switch (p_dpi_cfg->xfi_port)
    {
        case rdpa_emac0:
            profile_id = wan_pon_xfi0_profile_id;
            break;
        case rdpa_emac4:
            profile_id = wan_pon_xfi4_profile_id;
            break;
        case rdpa_emac_none:
            profile_id = wan_pon_no_xfi_profile_id;
            break;
        default:
            return BDMF_ERR_PARM;
    }

    for (bbh_id = 0; bbh_id < BBH_ID_NUM; bbh_id++)
    {
        int found = 0;

        /* serach BBH_ID in DMA/SDMA array */
        for (i = 0; i < NUM_OF_DMA; i++)
        {
            for (j = 0; j < NUM_OF_PERIPHERALS_PER_DMA; j++)
            {
                if (g_bbh_to_dma_x[bbh_id].bbh_id == g_dma_to_bbh_x[profile_id][i][j])
                {
                    found = 1;
                    break;
                }
            }
            if (found)
                break;
        }
        if (!found)
            return BDMF_ERR_INTERNAL;

        bbh_rx_sdma_cfg = &(g_bbh_rx_sdma_profile->bbh_rx_sdma_chunks_config[bbh_id]);
        bbh_rx_sdma_cfg->sdma_bb_id = i ? BB_ID_SDMA1 : BB_ID_SDMA0;
        bbh_rx_sdma_cfg->first_chunk_idx =
            calculate_buffers_offset(profile_id, i, j) * BBH_RX_TOTAL_BUFFER_NUM / TOTAL_BUFFERS_WEIGHT;
        bbh_rx_sdma_cfg->sdma_chunks =
            g_bbh_buff_num[profile_id][i][j] * BBH_RX_TOTAL_BUFFER_NUM / TOTAL_BUFFERS_WEIGHT;

        bbh_tx_dma_cfg = &(g_bbh_tx_dma_profile->bbh_tx_dma_cfg[bbh_id]);
        bbh_tx_dma_cfg->dmasrc = i ? BB_ID_DMA1 : BB_ID_DMA0;
        bbh_tx_dma_cfg->descbase =
            calculate_buffers_offset(profile_id, i, j) * BBH_TX_TOTAL_BUFFER_NUM / TOTAL_BUFFERS_WEIGHT;
        bbh_tx_dma_cfg->descsize = g_bbh_buff_num[profile_id][i][j] * BBH_TX_TOTAL_BUFFER_NUM / TOTAL_BUFFERS_WEIGHT;

        bbh_tx_sdma_cfg = &(g_bbh_tx_sdma_profile->bbh_tx_sdma_cfg[bbh_id]);
        bbh_tx_sdma_cfg->sdmasrc = i ? BB_ID_SDMA1 : BB_ID_SDMA0;
        bbh_tx_sdma_cfg->descbase =
            calculate_buffers_offset(profile_id, i, j) * BBH_TX_TOTAL_BUFFER_NUM / TOTAL_BUFFERS_WEIGHT;
        bbh_tx_sdma_cfg->descsize = g_bbh_buff_num[profile_id][i][j] * BBH_TX_TOTAL_BUFFER_NUM / TOTAL_BUFFERS_WEIGHT;

        bbh_tx_ddr_cfg = &(g_bbh_tx_ddr_profile->bbh_tx_ddr_cfg[bbh_id]);

        lookup_bbh_tx_bufsz_by_fpm_bufsz(&p_dpi_cfg->fpm_buf_size, &bbh_tx_ddr_cfg->bufsize);

        bbh_tx_ddr_cfg->byteresul = RES_1B;
        bbh_tx_ddr_cfg->ddrtxoffset = 0;
        /* MIN size = 0x4 - MAX size = 0x40  where to check values?*/
        /*hnsize0 must be equal to hnsize1 because the per packet header size selection is not implemented yet*/
        bbh_tx_ddr_cfg->hnsize0 = 0x20;
        bbh_tx_ddr_cfg->hnsize1 = 0x20;
    }
    return 0;
}

static int bbh_rx_cfg(bbh_id_e bbh_id)
{
    uint8_t i;
    bdmf_error_t rc = BDMF_ERR_OK;
    bbh_rx_config cfg;

    xrdp_memset(&cfg, 0, sizeof(bbh_rx_config));

    cfg.sdma_chunks_cfg = &(g_bbh_rx_sdma_profile->bbh_rx_sdma_chunks_config[bbh_id]);
    cfg.disp_bb_id = BB_ID_DISPATCHER_REORDER;
    cfg.sbpm_bb_id = BB_ID_SBPM;

    /* TODO: should match other blocks configurations (runner) */
    /* TODO: should it be a profile as well ? */
#ifdef BCM6858
    if ((bbh_id == 0) || (bbh_id == 4))
        cfg.normal_viq = 4 - bbh_id;
    else
#endif
        cfg.normal_viq = bbh_id;

#ifdef G9991
    cfg.excl_cfg.exc_en = 1;
#ifdef BCM6858
    if ((bbh_id == 0) || (bbh_id == 4))
        cfg.excl_viq = (BBH_ID_NUM + (4 - bbh_id));
    else
#endif
        cfg.excl_viq = BBH_ID_NUM + bbh_id;
#else
    /* In non G9991, there's no exclusive viqs for non PON BBHs, therefore, excl viq configuration of BBH RX is the same as normal VIQ*/
    cfg.excl_viq = (bbh_id == BBH_ID_PON) ? (BBH_ID_NUM + bbh_id) : bbh_id;
    cfg.excl_cfg.exc_en = (bbh_id == BBH_ID_PON);
#endif
    for (i = 0; i < 4; i++)
    {
        if (IS_WAN_RX_PORT(bbh_id))
            cfg.min_pkt_size[i] = MIN_WAN_PKT_SIZE;
        else
            cfg.min_pkt_size[i] = MIN_ETH_PKT_SIZE;
        cfg.max_pkt_size[i] = p_dpi_cfg->mtu_size;
    }

    if (IS_WAN_RX_PORT(bbh_id))
        cfg.min_pkt_size[1] = MIN_OMCI_PKT_SIZE;

#ifdef G9991
    if ((!IS_WAN_RX_PORT(bbh_id)) && ((1 << bbh_id_to_rdpa_emac[bbh_id]) & p_dpi_cfg->g9991_port_vec))
    {
        cfg.pattern_recog.patterndatamsb = G9991_DFC_PATTERN_MSB;
        cfg.pattern_recog.patterndatalsb = G9991_DFC_PATTERN_LSB;
        cfg.pattern_recog.patternmaskmsb = G9991_DFC_MASK_MSB;
        cfg.pattern_recog.patternmasklsb = G9991_DFC_MASK_LSB;
        cfg.excl_cfg.pattern_en = 1;
        cfg.gint_en = 1;
        cfg.sop_offset = G9991_US_SOP_OFFSET;
#ifdef RDP_SIM
    }
    else
        cfg.sop_offset = SOP_OFFSET;
    cfg.crc_omit_dis = 1;
#else
    }
    else if ((int)p_dpi_cfg->system_port == (int)bbh_id)
        cfg.crc_omit_dis = 1;
    else
    {
        cfg.crc_omit_dis = 0;
        cfg.sop_offset = SOP_OFFSET;
    }
#endif
#else
    cfg.crc_omit_dis = 0;
    cfg.sop_offset = SOP_OFFSET;
#endif
    cfg.per_flow_th = BBH_RX_FLOWS_32_255_GROUP_DIVIDER;

    cfg.max_otf_sbpm = DRV_BBH_RX_MAXIMUM_OTF_SBPM_REQUESTS_DEFAULT_VAL;

    /* TODO: taken from 6838 : By default, the triggers for FC will be disabled and the triggers for drop enabled.
       If the user configures flow control for the port, the triggers for drop will be
       disabled and triggers for FC (including Runner request) will be enabled */
    /*config.flow_ctrl_cfg.drops = ?*/
    /*config.flow_ctrl_cfg.timer = ?*/

    rc = rc ? rc : drv_bbh_rx_configuration_set(bbh_id, &cfg);
#ifndef RDP_SIM
    /* initialize all flows (including the 2 groups) */
    for (i = 0; i < DRV_BBH_RX_FLOW_INDEX_FOR_PER_FLOW_CONFIGURATION_GROUP_0 / 2; i++)
    {
        rc = rc ? rc : ag_drv_bbh_rx_min_pkt_sel_flows_0_15_set(bbh_id, i, 0);
        rc = rc ? rc : ag_drv_bbh_rx_max_pkt_sel_flows_0_15_set(bbh_id, i, 0);
        rc = rc ? rc : ag_drv_bbh_rx_min_pkt_sel_flows_16_31_set(bbh_id, i, 0);
        rc = rc ? rc : ag_drv_bbh_rx_max_pkt_sel_flows_16_31_set(bbh_id, i, 0);
    }

    rc = rc ? rc : ag_drv_bbh_rx_pkt_sel_group_0_set(bbh_id, 0, 0);
    rc = rc ? rc : ag_drv_bbh_rx_pkt_sel_group_1_set(bbh_id, 0, 0);
#endif

    return rc;
}


static int bbh_rx_init(void)
{
    bdmf_error_t rc = BDMF_ERR_OK;
    bbh_id_e bbh_id;

    for (bbh_id = BBH_ID_FIRST; bbh_id <= BBH_ID_LAST_XLMAC; bbh_id++)
    {
        rc = rc ? rc : bbh_rx_cfg(bbh_id);

        if (rc)
        {
            BDMF_TRACE_ERR("Error whlie configuring bbh_rx %d\n", bbh_id);
            return rc;
        }
    }
    return rc;
}

static void ubus_bridge_init(void)
{
    ag_drv_ubus_slv_vpb_base_set(UBUS_SLV_VPB_BASE_ADDR);
    ag_drv_ubus_slv_vpb_mask_set(UBUS_SLV_MASK);
    ag_drv_ubus_slv_apb_base_set(UBUS_SLV_APB_BASE_ADDR);
    ag_drv_ubus_slv_apb_mask_set(UBUS_SLV_MASK);

    ag_drv_ubus_mstr_hyst_ctrl_set(UBUS_MSTR_ID_0, UBUS_MSTR_CMD_SPCAE, UBUS_MSTR_DATA_SPCAE);
    ag_drv_ubus_mstr_hyst_ctrl_set(UBUS_MSTR_ID_1, UBUS_MSTR_CMD_SPCAE, UBUS_MSTR_DATA_SPCAE);
}

static int fpm_init(void)
{
    bdmf_error_t rc = BDMF_ERR_OK;
    bdmf_boolean reset_req = 1;
    fpm_pool2_intr_sts interrupt_status = FPM_INTERRUPT_STATUS;
    fpm_pool2_intr_msk interrupt_mask = FPM_INTERRUPT_MASK;
    uint16_t timeout = 0;

    drv_fpm_init(p_dpi_cfg->rdp_ddr_pkt_base_virt, p_dpi_cfg->fpm_buf_size);

    rc = rc ? rc : ag_drv_fpm_pool1_xon_xoff_cfg_set(FPM_XON_THRESHOLD, FPM_XOFF_THRESHOLD);
    rc = rc ? rc : ag_drv_fpm_init_mem_set(1);

    /* polling until reset is finished */
    while (!rc && reset_req && timeout <= FPM_INIT_TIMEOUT)
    {
        rc = rc ? rc : ag_drv_fpm_init_mem_get(&reset_req);
        xrdp_usleep(FPM_POLL_SLEEP_TIME);
        timeout++;
    }
    if (timeout == FPM_INIT_TIMEOUT)
        rc = BDMF_ERR_INTERNAL;

    /* enable the fpm pool */
    rc = rc ? rc : ag_drv_fpm_pool1_en_set(1);

    /* fpm configurations */
#ifndef XRDP_EMULATION
    /* fpm interrupts */
    rc = rc ? rc : ag_drv_fpm_pool1_intr_sts_set(&interrupt_status);
    rc = rc ? rc : ag_drv_fpm_pool1_intr_msk_set(&interrupt_mask);
#endif

    if (rc)
        BDMF_TRACE_ERR("Failed to initialize fpm driver\n");

    return rc;
}

static int cnpl_init(void)
{
    int rc;

    /* reset counters-policers memory */
    rc = drv_cnpl_memory_data_init();
    /* init counter groups according to project */
    rc = rc ? rc : drv_cntr_group_init();
    return rc;
}

static int parser_init(void)
{
    int rc = BDMF_ERR_OK;
    uint8_t i;

    /* configure runner quads */
    for (i = 0; !rc && i < NUM_OF_RNR_QUAD; i++)
    {
        /* parser configuration */
        rc = rc ? rc : ag_drv_rnr_quad_tcp_flags_set(i, PARSER_TCP_CTL_FLAGS);
        rc = rc ? rc : ag_drv_rnr_quad_profile_us_set(i, PARSER_PROFILE_US);
        rc = rc ? rc : ag_drv_rnr_quad_exception_bits_set(i, PARSER_EXCP_STATUS_BITS);
        rc = rc ? rc : ag_drv_rnr_quad_parser_core_configuration_ppp_ip_prot_code_set(i,
            PARSER_PPP_PROTOCOL_CODE_0_IPV4, PARSER_PPP_PROTOCOL_CODE_1_IPV6);
        rc = rc ? rc : ag_drv_rnr_quad_parser_core_configuration_eng_set(i, PARSER_AH_DETECTION);
    }

    if (rc)
        BDMF_TRACE_ERR("Failed to initialize parser driver\n");

    return rc;
}

#ifndef _CFE_
static int hash_init(void)
{
    hash_config_t hash_cfg = {};

    hash_cfg.tbl_num = 3;

    /* IPTV table configuration */
    /**/
    hash_cfg.tbl_cfg[GET_SW_TABLE_ID(HASH_TABLE_IPTV)].tbl_size = HASH_TABLE_IPTV_SIZE_PER_ENGINE;
    hash_cfg.tbl_cfg[GET_SW_TABLE_ID(HASH_TABLE_IPTV)].cam_en = 0;
    hash_cfg.tbl_init[GET_SW_TABLE_ID(HASH_TABLE_IPTV)].int_ctx_size = 3;
    hash_cfg.tbl_init[GET_SW_TABLE_ID(HASH_TABLE_IPTV)].ext_ctx_size = 0;
    hash_cfg.tbl_init[GET_SW_TABLE_ID(HASH_TABLE_IPTV)].search_depth_per_engine = 4;

    /* 32 bit key */
    hash_cfg.mask[GET_SW_TABLE_ID(HASH_TABLE_IPTV)].maskl = HASH_TABLE_IPTV_KEY_MASK_LO;
    /* Only 12 bits of internal context are used*/
    hash_cfg.mask[GET_SW_TABLE_ID(HASH_TABLE_IPTV)].maskh = HASH_TABLE_IPTV_KEY_MASK_HI;


    /* MAC (ARL) table configuration */
    hash_cfg.tbl_cfg[GET_SW_TABLE_ID(HASH_TABLE_ARL)].tbl_size = HASH_TABLE_ARL_SIZE_PER_ENGINE;
    hash_cfg.tbl_cfg[GET_SW_TABLE_ID(HASH_TABLE_ARL)].cam_en = 0;
    hash_cfg.tbl_init[GET_SW_TABLE_ID(HASH_TABLE_ARL)].int_ctx_size = 0;
    hash_cfg.tbl_init[GET_SW_TABLE_ID(HASH_TABLE_ARL)].ext_ctx_size = 3;
    hash_cfg.tbl_init[GET_SW_TABLE_ID(HASH_TABLE_ARL)].search_depth_per_engine = 4;

    /* 60 bit key */
    hash_cfg.mask[GET_SW_TABLE_ID(HASH_TABLE_ARL)].maskl = HASH_TABLE_ARL_KEY_MASK_LO;
    hash_cfg.mask[GET_SW_TABLE_ID(HASH_TABLE_ARL)].maskh = HASH_TABLE_ARL_KEY_MASK_HI;


    /* VLAN lookup table configuration */
    hash_cfg.tbl_cfg[GET_SW_TABLE_ID(HASH_TABLE_BRIDGE_AND_VLAN_LKP)].tbl_size = HASH_TABLE_BRIDGE_AND_VLAN_LKP_SIZE_PER_ENGINE;
    hash_cfg.tbl_cfg[GET_SW_TABLE_ID(HASH_TABLE_BRIDGE_AND_VLAN_LKP)].cam_en = 0;
    hash_cfg.tbl_init[GET_SW_TABLE_ID(HASH_TABLE_BRIDGE_AND_VLAN_LKP)].int_ctx_size = 3;
    hash_cfg.tbl_init[GET_SW_TABLE_ID(HASH_TABLE_BRIDGE_AND_VLAN_LKP)].ext_ctx_size = 6;
    hash_cfg.tbl_init[GET_SW_TABLE_ID(HASH_TABLE_BRIDGE_AND_VLAN_LKP)].search_depth_per_engine = 4;

    /* 20 bit key */
    hash_cfg.mask[GET_SW_TABLE_ID(HASH_TABLE_BRIDGE_AND_VLAN_LKP)].maskl = HASH_TABLE_BRIDGE_AND_VLAN_LKP_MASK_LO;
    hash_cfg.mask[GET_SW_TABLE_ID(HASH_TABLE_BRIDGE_AND_VLAN_LKP)].maskh = HASH_TABLE_BRIDGE_AND_VLAN_LKP_MASK_HI;

    /* reset hash memory */
    return drv_hash_init(&hash_cfg);
}
#endif /*_CFE_*/

static int sbpm_init(void)
{
    bdmf_error_t rc = BDMF_ERR_OK;
    uint16_t base_addr;
    uint16_t init_offset;
    sbpm_thr_ug thr_ug = {};

    /* base address and offset */
    base_addr = SBPM_BASE_ADDRESS;
    init_offset = SBPM_INIT_OFFSET;

    rc = rc ? rc : ag_drv_sbpm_regs_init_free_list_set(base_addr, init_offset, 0, 0);
	/* TODO : temporary : for primitive Ingress Qos implementation in FW */
    rc = rc ? rc : drv_sbpm_thr_ug0_get(&thr_ug);
    thr_ug.excl_low_thr = 900;
    rc = rc ? rc : drv_sbpm_thr_ug0_set(&thr_ug);

    ag_drv_sbpm_regs_sbpm_ug0_excl_low_trsh_set(SBPM_UG0_EXCL_LOW_THRESHOLD, SBPM_UG0_EXCL_LOW_HIST);

#ifndef _CFE_
    rc = rc ? rc : drv_sbpm_thr_ug1_get(&thr_ug);
    thr_ug.excl_low_thr = SBPM_UG1_EXCL_LOW_THRESHOLD;
    thr_ug.excl_low_hyst = SBPM_UG1_EXCL_LOW_HIST;
    rc = rc ? rc : drv_sbpm_thr_ug1_set(&thr_ug);
#endif

#ifdef RDP_SIM
    drv_sbpm_default_val_init();
#endif
    if (rc)
        BDMF_TRACE_ERR("Failed to initialize sbpm driver\n");

    return rc;
}


static int get_ds_tm_rnr_id(bbh_id_e bbh_id)
{
#ifdef G9991
    if ((p_dpi_cfg->dpu_split_scheduling_mode) && (bbh_id >= BBH_ID_XLMAC1_2_RGMII))
        return  DS_TM_CORE_BBH_2_3;
    else
        return  DS_TM_CORE_BBH_0_1;
#else
    return  get_runner_idx(ds_tm_runner_image);
#endif
}

static int bbh_tx_init(void)
{
    bbh_id_e bbh_id;
    bbh_tx_config config;
    uint8_t max_on_the_fly_reads;
    bdmf_phys_addr_t fpm_base_phys_addr;
    bdmf_error_t rc = BDMF_ERR_OK;
    pd_fifo_base_t lan_pd_fifo_base[1] = {};

    /* init fifo base arrays */
    lan_pd_fifo_base[0].base0 = 0;
    lan_pd_fifo_base[0].base1 = lan_pd_fifo_base[0].base0 + g_lan_pd_fifo_size[0].size0 + 1;

    for (bbh_id = BBH_ID_FIRST; bbh_id <= BBH_ID_LAST_XLMAC; bbh_id++)
    {
        xrdp_memset(&config, 0, sizeof(bbh_tx_config));

        /* cores which sending PDs */
        config.mac_type = MAC_TYPE_EMAC;
        config.rnr_cfg[0].skb_addr = 0;


        if (p_dpi_cfg->bbh_id_gbe_wan != bbh_id)
        {
            config.rnr_cfg[0].rnr_src_id = get_ds_tm_rnr_id(bbh_id);
            config.rnr_cfg[0].tcont_addr = IMAGE_0_DS_TM_BBH_TX_QUEUE_ID_TABLE_ADDRESS >> 3;
#ifdef BCM6858
            if ((bbh_id == 0) || (bbh_id == 4))
                config.rnr_cfg[0].ptr_addr = (IMAGE_0_DS_TM_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS +
                    ((4 - bbh_id) * sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS))) >> 3;
            else
#endif
                config.rnr_cfg[0].ptr_addr = (IMAGE_0_DS_TM_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS + (bbh_id * sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS))) >> 3;
#ifndef G9991
#ifdef BCM6858
            if ((bbh_id == 0) || (bbh_id == 4))
                config.rnr_cfg[0].task_number = (IMAGE_0_DS_TM_LAN0_THREAD_NUMBER + (4 - bbh_id));
            else
#endif
                config.rnr_cfg[0].task_number = (IMAGE_0_DS_TM_LAN0_THREAD_NUMBER + bbh_id);
#else
                /* system port */
                if (bbh_id == BBH_ID_XLMAC1_1_RGMII)
                    config.rnr_cfg[0].task_number = IMAGE_0_DS_TM_SYSTEM_PORT_THREAD_NUMBER;
                else
                    config.rnr_cfg[0].task_number = rdd_g9991_thread_number_get(bbh_id_to_rdpa_emac[bbh_id], p_dpi_cfg->g9991_port_vec);
#endif
        }

        /* CHECK : how many queues to set (q2rnr)?*/
        config.lan_queue_cfg.queue_to_rnr = g_lan_queue_to_rnr;
        /* For Ethernet port working in MDU mode, PD FIFO size should be configured to 4 (and not 8). */
        config.lan_queue_cfg.pd_fifo_base = lan_pd_fifo_base;
        config.lan_queue_cfg.pd_fifo_size = g_lan_pd_fifo_size;
        /* why it says in the regge it is used for epon */
        config.lan_queue_cfg.pd_wkup_threshold = g_lan_pd_wkup_threshold;
        config.lan_queue_cfg.pd_bytes_threshold = g_lan_pd_bytes_threshold;
        /* pd_prefetch_byte_threshold feature is irrelevant in EMAC (since there is only one FIFO) */
        config.lan_queue_cfg.pd_bytes_threshold_en = 0;
        config.lan_queue_cfg.pd_empty_threshold = 1;

        config.src_id.fpmsrc = BB_ID_FPM;
        config.src_id.sbpmsrc = BB_ID_SBPM;
        /* Missing: MSG_RNR_SRC_ID */

        config.dma_cfg = &(g_bbh_tx_dma_profile->bbh_tx_dma_cfg[bbh_id]);
        config.sdma_cfg = &(g_bbh_tx_sdma_profile->bbh_tx_sdma_cfg[bbh_id]);
        config.ddr_cfg = &(g_bbh_tx_ddr_profile->bbh_tx_ddr_cfg[bbh_id]);

        fpm_base_phys_addr = RDD_RSV_VIRT_TO_PHYS(p_dpi_cfg->rdp_ddr_pkt_base_virt);
        GET_ADDR_HIGH_LOW(config.base_addr_high.addr[0], config.base_addr_low.addr[0], fpm_base_phys_addr);

        config.base_addr_low.addr[1] = 0;
        config.base_addr_high.addr[1] = 0;

        rc = rc ? rc : drv_bbh_tx_configuration_set(bbh_id, &config);
        rc = rc ? rc : ag_drv_bbh_tx_lan_configurations_eee_set(bbh_id, 1);

        max_on_the_fly_reads = (g_max_otf_reads[bbh_id] > config.dma_cfg->descsize) ? config.dma_cfg->descsize : g_max_otf_reads[bbh_id];
        rc = rc ? rc : ag_drv_bbh_tx_dma_max_otf_read_request_set(bbh_id, max_on_the_fly_reads);
        max_on_the_fly_reads = (g_max_otf_reads[bbh_id] > config.sdma_cfg->descsize) ? config.sdma_cfg->descsize : g_max_otf_reads[bbh_id];
        rc = rc ? rc : ag_drv_bbh_tx_sdma_max_otf_read_request_set(bbh_id, max_on_the_fly_reads);

        /* only bbh_id 0 has extra long fifos for xfi */
        if (bbh_id == XFI_EMAC_PORT)
        {
            rc = rc ? rc : ag_drv_bbh_tx_common_configurations_dfifoctrl_set(bbh_id, BBH_TX_DATA_XFI_FIFO_SRAM_SIZE, BBH_TX_DATA_XFI_FIFO_DDR_SIZE, BBH_TX_XFI_DATA_FIFO_SRAM_BASE);
            rc = rc ? rc : ag_drv_bbh_tx_lan_configurations_txthresh_set(bbh_id, BBH_TX_XFI_LAN_DDR_THRESHOLD, BBH_TX_XFI_LAN_SRAM_THRESHOLD);
        }
        else
        {
            rc = rc ? rc : ag_drv_bbh_tx_common_configurations_dfifoctrl_set(bbh_id, BBH_TX_DATA_FIFO_SRAM_SIZE, BBH_TX_DATA_FIFO_DDR_SIZE, BBH_TX_DATA_FIFO_SRAM_BASE);
            rc = rc ? rc : ag_drv_bbh_tx_lan_configurations_txthresh_set(bbh_id, BBH_TX_LAN_DDR_THRESHOLD, BBH_TX_LAN_SRAM_THRESHOLD);
        }

        rc = rc ? rc : ag_drv_bbh_tx_lan_configurations_ts_set(bbh_id, 1);
        if (rc)
            break;
    }

    if (rc)
        BDMF_TRACE_ERR("Failed to initialize bbh_tx driver");

    return rc;
}

static int dma_sdma_init(void)
{
    bdmf_error_t rc = BDMF_ERR_OK;
    uint8_t dma_id, peripheral_id, bbh_id, max_read_on_the_fly;

    for (dma_id = DMA_ID_FIRST; dma_id < DMA_NUM; dma_id++)
    {
        max_read_on_the_fly = IS_SDMA(dma_id) ? SDMA_MAX_READ_ON_THE_FLY : DMA_MAX_READ_ON_THE_FLY;
        rc = rc ? rc : ag_drv_dma_config_max_otf_set(dma_id, max_read_on_the_fly);
        peripheral_id = 0;
        for (bbh_id = BBH_ID_FIRST; bbh_id < BBH_ID_NUM; bbh_id++)
        {
            /* check if peripherial correspond to the right DMA */
            if (g_bbh_to_dma_x[bbh_id].dma_id != dma_id%2)
                continue;

            if (IS_SDMA(dma_id))
                rc = rc ? rc : ag_drv_dma_config_num_of_writes_set(dma_id, peripheral_id, g_bbh_rx_sdma_profile->bbh_rx_sdma_chunks_config[bbh_id].sdma_chunks);

            if (IS_DMA(dma_id))
                rc = rc ? rc : ag_drv_dma_config_num_of_reads_set(dma_id, peripheral_id, g_bbh_tx_dma_profile->bbh_tx_dma_cfg[bbh_id].descsize);
            else
                rc = rc ? rc : ag_drv_dma_config_num_of_reads_set(dma_id, peripheral_id, g_bbh_tx_sdma_profile->bbh_tx_sdma_cfg[bbh_id].descsize);

            rc = rc ? rc : ag_drv_dma_config_u_thresh_set(dma_id, peripheral_id, g_dma_urgent_threshold[bbh_id][dma_id%2].into_urgent_threshold,
                g_dma_urgent_threshold[bbh_id][dma_id%2].out_of_urgent_threshold);
            rc = rc ? rc : ag_drv_dma_config_pri_set(dma_id, peripheral_id, g_dma_strict_priority[bbh_id][dma_id%2].rx_side,
                g_dma_strict_priority[bbh_id][dma_id%2].tx_side);
            rc = rc ? rc : ag_drv_dma_config_weight_set(dma_id, peripheral_id, g_dma_rr_weight[bbh_id][dma_id%2].rx_side, g_dma_rr_weight[bbh_id][dma_id%2].tx_side);
            rc = rc ? rc : ag_drv_dma_config_periph_source_set(dma_id, peripheral_id, g_dma_bb_source[bbh_id].rx_side, g_dma_bb_source[bbh_id].tx_side);

            peripheral_id++;

            if (rc)
                break;
        }
        if (rc)
            break;
    }

    if (rc)
        BDMF_TRACE_ERR("Failed to initialize dma_sdma driver\n");

    return rc;
}

static int rnr_frequency_set(uint16_t freq)
{
    uint8_t rnr_idx;
    int rc = BDMF_ERR_OK;

    for (rnr_idx = 0; rnr_idx <= RNR_LAST; rnr_idx++)
    {
        rc = rc ? rc : ag_drv_rnr_regs_rnr_freq_set(rnr_idx, (freq-1));
    }
    return rc;
}

extern uintptr_t xrdp_virt2phys(const ru_block_rec *ru_block, uint8_t addr_idx);

static int runner_init(int is_basic)
{
    bdmf_error_t rc = BDMF_ERR_OK;
    rnr_dma_regs_cfg_t rnr_dma_cfg;
    rnr_quad_general_config_powersave_config powersave_cfg;
    uint8_t quad_idx, ubus_slave_idx;
    uint32_t addr_hi, addr_lo;
    bdmf_phys_addr_t fpm_base_phys_addr;
#if !defined(_CFE_) && !defined(RDP_SIM)
    bdmf_phys_addr_t psram_dma_base_phys_addr;
#endif
    rdd_init_params_t rdd_init_params = {0};
#ifdef G9991
    uint8_t i;
#endif
    uint32_t  core_index;

    drv_rnr_cores_addr_init();
    drv_rnr_mem_init();
    drv_rnr_load_microcode();
    drv_rnr_load_prediction();

    /* scheduler configuration */
    drv_rnr_set_sch_cfg();
    for (core_index = 0; core_index < GROUPED_EN_SEGMENTS_NUM; core_index++)
        if (IS_DS_TM_RUNNER_IMAGE(core_index))
            ag_drv_rnr_regs_cfg_sch_cfg_set(core_index, DRV_RNR_4SP_12RR);

    fpm_base_phys_addr = RDD_RSV_VIRT_TO_PHYS(p_dpi_cfg->rdp_ddr_pkt_base_virt);
    GET_ADDR_HIGH_LOW(addr_hi, addr_lo, fpm_base_phys_addr);

    g_fpm_hw_cfg.fpm_base_low = addr_lo;
    g_fpm_hw_cfg.fpm_base_high = addr_hi;

    rnr_dma_cfg.ddr.dma_base = (addr_hi << 12) | (addr_lo >> 20);

    lookup_dma_bufsz_by_fpm_bufsz(&p_dpi_cfg->fpm_buf_size, &rnr_dma_cfg.ddr.dma_buf_size);

    rnr_dma_cfg.ddr.dma_static_offset = 0;
#if defined(_CFE_) || defined(RDP_SIM)
    rnr_dma_cfg.psram.dma_base = ((RU_BLK(PSRAM).addr[0] + RU_REG_OFFSET(PSRAM, MEMORY_DATA)) >> 20);
#else
    psram_dma_base_phys_addr = xrdp_virt2phys(&RU_BLK(PSRAM), 0) + RU_REG_OFFSET(PSRAM, MEMORY_DATA);
    rnr_dma_cfg.psram.dma_base = psram_dma_base_phys_addr >> 20;
#endif
    rnr_dma_cfg.psram.dma_buf_size = DMA_BUFSIZE_128;
    rnr_dma_cfg.psram.dma_static_offset = 0;

    rc = drv_rnr_dma_cfg(&rnr_dma_cfg);

    /* ToDo: fill rdd_init_params */

    rdd_init_params.is_basic = is_basic;
    g_fpm_hw_cfg.fpm_token_size_asr_8 = p_dpi_cfg->fpm_buf_size >> 8;

#ifdef G9991
    /* init g9991 ports */
    for (i = 0; i < RDD_G9991_SID_TO_PHYSICAL_PORT_MASK_SIZE; i++)
        rdd_init_params.g9991_port[i] = get_location_of_bit_in_mask(i + 1, p_dpi_cfg->g9991_port_vec);
#endif

#ifdef CONFIG_DHD_RUNNER
    /* offset should be int muber of words */
    rdd_init_params.dhd_hw_config.ddr_sop_offset = ((ddr_sop_offset0 + DHD_DATA_OFFSET + 7) >> 3) << 3;
#endif

    rc = rc ? rc : rdd_data_structures_init(&rdd_init_params);
    rc = rc ? rc : rnr_frequency_set(p_dpi_cfg->runner_freq);
    rc = rc ? rc : parser_init();
    if (rc)
        return rc;
    powersave_cfg.time_counter = 0x20; /* cycles to wait before power save */
    powersave_cfg.enable_powersave_core_0 = 1;
    powersave_cfg.enable_powersave_core_1 = 1;
    powersave_cfg.enable_powersave_core_2 = 1;
    powersave_cfg.enable_powersave_core_3 = 1;

    for (quad_idx = 0; quad_idx < NUM_OF_RNR_QUAD; quad_idx++)
    {
        rc = rc ? rc : ag_drv_rnr_quad_general_config_powersave_config_set(quad_idx, &powersave_cfg);

        /* change dynamic clock threshold in each quad */
        rc = rc ? rc : ag_drv_rnr_quad_general_config_dma_arb_cfg_set(quad_idx, 0, 0, 0, RNR_QUAD_DMA_ARB_CONJEST_THRESHOLD);
        rc = rc ? rc : ag_drv_rnr_quad_ext_flowctrl_config_token_val_set(quad_idx, XRDP_UBUS_SLAVE_IDX, 1);

        /* extend PSRAM slave tokens to 8 */
	    for (ubus_slave_idx = 16; ubus_slave_idx < 20; ubus_slave_idx++)
	        rc = rc ? rc : ag_drv_rnr_quad_ext_flowctrl_config_token_val_set(quad_idx, ubus_slave_idx, 8);

        if (rc)
            return rc;
    }

    return rc;
}


static inline void dispatcher_reorder_viq_init(dsptchr_config *cfg, dsptchr_cngs_params *congs_init, uint8_t bb_id, uint32_t target_address,
    bdmf_boolean dest, bdmf_boolean delayed, uint8_t viq_num, uint8_t guaranteed_limit, uint16_t common_max_limit, bdmf_boolean is_bbh_queue)
{
    cfg->dsptchr_viq_list[viq_num].wakeup_thrs = DSPTCHR_WAKEUP_THRS;
    cfg->dsptchr_viq_list[viq_num].bb_id = bb_id;
    cfg->dsptchr_viq_list[viq_num].bbh_target_address = target_address; /* for BBH - 2 is normal, 3 is exclusive */
    cfg->dsptchr_viq_list[viq_num].queue_dest = dest; /* 0-disp, 1-reor */
    cfg->dsptchr_viq_list[viq_num].delayed_queue = delayed; /* 0-non delayed, 1-delayed */
    cfg->dsptchr_viq_list[viq_num].common_max_limit = common_max_limit;
    cfg->dsptchr_viq_list[viq_num].guaranteed_max_limit = guaranteed_limit;
    cfg->dsptchr_viq_list[viq_num].coherency_en = is_bbh_queue;
    cfg->dsptchr_viq_list[viq_num].coherency_ctr = 0;
    xrdp_memcpy(&(cfg->dsptchr_viq_list[viq_num].ingress_cngs), congs_init, sizeof(dsptchr_cngs_params));
    xrdp_memcpy(&(cfg->dsptchr_viq_list[viq_num].egress_cngs), congs_init, sizeof(dsptchr_cngs_params));
    if (cfg->viq_num <= viq_num)
        cfg->viq_num = viq_num + 1;
}

static inline void dispatcher_reorder_rnr_group_init(dsptchr_config *cfg, uint8_t grp_idx, uint8_t core_index, uint32_t task_mask, uint32_t base_addr, uint32_t offset)
{
    cfg->dsptchr_rnr_group_list[grp_idx].tasks_mask.task_mask[core_index/2] |= (task_mask << ((core_index & 1) << 4));
    cfg->rg_available_tasks[grp_idx] += asserted_bits_count_get(task_mask);
    cfg->dsptchr_rnr_cfg[core_index].rnr_num = core_index;
    cfg->dsptchr_rnr_cfg[core_index].rnr_addr_cfg.base_add = base_addr;
    cfg->dsptchr_rnr_cfg[core_index].rnr_addr_cfg.offset_add = offset;
    cfg->rnr_disp_en_vector |= (1 << core_index);
}


static uint32_t disp_reor_enable_vec(const dsptchr_config *cfg)
{
    uint8_t viq;
    uint32_t enable_vec = 0;

    for (viq = 0; viq < cfg->viq_num; viq++)
    {
        if (cfg->dsptchr_viq_list[viq].wakeup_thrs)
            enable_vec |= (1 << viq);
    }
    enable_vec &= ~(1 << BBH_ID_PON);
    enable_vec &= ~(1 << (BBH_ID_PON + BBH_ID_NUM));
    return enable_vec;
}

static int dispatcher_reorder_init(void)
{
    dsptchr_config cfg;
    dsptchr_cngs_params congs_init;
    bdmf_error_t rc = BDMF_ERR_OK;
    uint8_t bbh_id, core_index, i;
#ifdef G9991
    int g9991_bbh;
    uint32_t system_port_mask = 0;
    uint16_t common_max_limit = DIS_REOR_LINKED_LIST_BUFFER_NUM
        - (DSPTCHR_NORMAL_GUARANTEED_BUFFERS * (DISP_REOR_VIQ_LAST + 1))
        + (DSPTCHR_NORMAL_GUARANTEED_BUFFERS - DSPTCHR_EXCLUSIVE_WAN_GUARANTEED_BUFFERS) * BBH_ID_NUM /*Guaranteed for exclusive VIQs*/
        - DISP_REOR_VIQ_LAST; /* Guaranteed for dummy buffers*/
#else
    /* Dispatcher queues for reassembly are not present in this case*/
    uint16_t common_max_limit = DIS_REOR_LINKED_LIST_BUFFER_NUM
       - (DSPTCHR_NORMAL_GUARANTEED_BUFFERS * (DISP_REOR_VIQ_LAST + 1 - 2)) /* TODO: will change when increasing number of G9991 VIQs */
       + DSPTCHR_NORMAL_GUARANTEED_BUFFERS * (BBH_ID_NUM - 1) /*Guaranteed for PON exclusive VIQ*/
       + (DSPTCHR_NORMAL_GUARANTEED_BUFFERS - DSPTCHR_EXCLUSIVE_WAN_GUARANTEED_BUFFERS)
       - DISP_REOR_VIQ_LAST + 2; /* Guaranteed for dummy buffers*/
#endif

    xrdp_memset(&cfg, 0, sizeof(dsptchr_config));
    xrdp_memset(&congs_init, 0, sizeof(dsptchr_cngs_params));
    congs_init.frst_lvl = DIS_REOR_LINKED_LIST_BUFFER_NUM - 1;
    congs_init.scnd_lvl = DIS_REOR_LINKED_LIST_BUFFER_NUM - 1;
    congs_init.hyst_thrs = (DIS_REOR_LINKED_LIST_BUFFER_NUM / 4) - 1;

    /* reset dispatcher credit for all queues */
    for (i = 0; i < DSPTCHR_VIRTUAL_QUEUE_NUM; ++i)
        rc = rc ? rc : ag_drv_dsptchr_credit_cnt_set(i, 0);

    /* configure all viq 0-15 are for bbh-rx */
    for (bbh_id = BBH_ID_FIRST; bbh_id < BBH_ID_NUM; bbh_id++)
    {
#ifdef BCM6858
        if ((bbh_id == 0) || (bbh_id == 4))
            /* normal viq for bbh-rx */
            dispatcher_reorder_viq_init(&cfg, &congs_init, (BB_ID_RX_XLMAC1_0_RGMII - (2 * (4 - bbh_id))), dsptchr_viq_bbh_target_addr_normal, dsptchr_viq_dest_disp,
                dsptchr_viq_delayed, (4 - bbh_id), DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 1);
        else if (bbh_id == BBH_ID_PON)
            /* normal viq for bbh-rx */
            dispatcher_reorder_viq_init(&cfg, &congs_init, BB_ID_RX_PON_ETH, dsptchr_viq_bbh_target_addr_normal, dsptchr_viq_dest_disp,
                dsptchr_viq_delayed, bbh_id, DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 1);
        else if (bbh_id == (BBH_ID_PON - 1))
            /* normal viq for bbh-rx */
            dispatcher_reorder_viq_init(&cfg, &congs_init, BB_ID_RX_XLMAC1_3_RGMII, dsptchr_viq_bbh_target_addr_normal, dsptchr_viq_dest_disp,
                dsptchr_viq_delayed, bbh_id, DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 1);
        else
#endif
            /* normal viq for bbh-rx */
            dispatcher_reorder_viq_init(&cfg, &congs_init, BB_ID_RX_XLMAC0_0_10G + (2 * bbh_id), dsptchr_viq_bbh_target_addr_normal, dsptchr_viq_dest_disp,
                dsptchr_viq_delayed, bbh_id, DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 1);

#ifndef G9991
#ifdef BCM6858
        if (bbh_id == BBH_ID_PON)
            /* TODO: actually all queues besides PON exclusive can be ommited for non G9991*/
            dispatcher_reorder_viq_init(&cfg, &congs_init, BB_ID_RX_PON_ETH, dsptchr_viq_bbh_target_addr_excl, dsptchr_viq_dest_disp,
                dsptchr_viq_delayed, bbh_id + BBH_ID_NUM, DSPTCHR_EXCLUSIVE_WAN_GUARANTEED_BUFFERS * (bbh_id == BBH_ID_PON), common_max_limit, 1);
        else if (bbh_id == (BBH_ID_PON - 1))
            dispatcher_reorder_viq_init(&cfg, &congs_init, BB_ID_RX_XLMAC1_3_RGMII, dsptchr_viq_bbh_target_addr_excl, dsptchr_viq_dest_disp,
                dsptchr_viq_delayed, bbh_id + BBH_ID_NUM, DSPTCHR_EXCLUSIVE_WAN_GUARANTEED_BUFFERS * (bbh_id == BBH_ID_PON), common_max_limit, 1);
        else
#endif
            /* TODO: actually all queues besides PON exclusive can be ommited for non G9991*/
            dispatcher_reorder_viq_init(&cfg, &congs_init, BB_ID_RX_XLMAC0_0_10G + (2 * bbh_id), dsptchr_viq_bbh_target_addr_excl, dsptchr_viq_dest_disp,
                dsptchr_viq_delayed, bbh_id + BBH_ID_NUM, DSPTCHR_EXCLUSIVE_WAN_GUARANTEED_BUFFERS * (bbh_id == BBH_ID_PON), common_max_limit, 1);
#else
#ifdef BCM6858
        if (bbh_id == BBH_ID_PON)
            /* TODO: actually all queues besides PON exclusive can be ommited for non G9991*/
            dispatcher_reorder_viq_init(&cfg, &congs_init, BB_ID_RX_PON_ETH, dsptchr_viq_bbh_target_addr_excl, dsptchr_viq_dest_disp,
                dsptchr_viq_delayed, bbh_id + BBH_ID_NUM, DSPTCHR_EXCLUSIVE_WAN_GUARANTEED_BUFFERS, common_max_limit, 1);
        else if (bbh_id == (BBH_ID_PON - 1))
            dispatcher_reorder_viq_init(&cfg, &congs_init, BB_ID_RX_XLMAC1_3_RGMII, dsptchr_viq_bbh_target_addr_excl, dsptchr_viq_dest_disp,
                dsptchr_viq_delayed, bbh_id + BBH_ID_NUM, DSPTCHR_EXCLUSIVE_WAN_GUARANTEED_BUFFERS, common_max_limit, 1);
        else if ((bbh_id == 0) || (bbh_id == 4))
            dispatcher_reorder_viq_init(&cfg, &congs_init, (BB_ID_RX_XLMAC1_0_RGMII - (2 * (4 - bbh_id))), dsptchr_viq_bbh_target_addr_excl, dsptchr_viq_dest_disp,
                dsptchr_viq_delayed, (4 - bbh_id) + BBH_ID_NUM, DSPTCHR_EXCLUSIVE_WAN_GUARANTEED_BUFFERS, common_max_limit, 1);
        else
#endif
            dispatcher_reorder_viq_init(&cfg, &congs_init, BB_ID_RX_XLMAC0_0_10G + (2 * bbh_id), dsptchr_viq_bbh_target_addr_excl, dsptchr_viq_dest_disp,
                dsptchr_viq_delayed, bbh_id + BBH_ID_NUM, DSPTCHR_EXCLUSIVE_WAN_GUARANTEED_BUFFERS, common_max_limit, 1);
#endif
    }

#ifdef EPON
    /* VIQ for epon tm - 16 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(us_tm_runner_image), ((IMAGE_3_DISPATCHER_CREDIT_TABLE_ADDRESS >> 3) |
        (IMAGE_3_US_TM_WAN_THREAD_NUMBER << 12)), dsptchr_viq_dest_reor, dsptchr_viq_non_delayed,
        DISP_REOR_VIQ_EPON_TM, DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);
#endif

    /* VIQ for CPU_TX egress - 17 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(cpu_tx_runner_image), (IMAGE_2_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS >> 3 |
        IMAGE_2_CPU_IF_2_CPU_TX_EGRESS_THREAD_NUMBER << 12), dsptchr_viq_dest_reor, dsptchr_viq_delayed, DISP_REOR_VIQ_CPU_TX_EGRESS,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);

#ifndef CPU_TX_RING
    /* VIQ for CPU_TX forward - 18 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(cpu_tx_runner_image), (IMAGE_2_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS >> 3 |
        IMAGE_2_CPU_IF_2_CPU_TX_INGRESS_THREAD_NUMBER << 12), dsptchr_viq_dest_disp, dsptchr_viq_delayed, DISP_REOR_VIQ_CPU_TX_FORWARD,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);
#endif

    /* VIQ for flush DS - 20 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_ds_tm_rnr_id(BBH_ID_XLMAC1_0_RGMII), (IMAGE_0_DS_TM_FLUSH_DISPATCHER_CREDIT_TABLE_ADDRESS >> 3) |
        (IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER << 12), dsptchr_viq_dest_reor, dsptchr_viq_delayed, DISP_REOR_VIQ_DS_TM_FLUSH,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);

#ifdef G9991
    /* VIQ for flush DS - 30 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_ds_tm_rnr_id(BBH_ID_XLMAC1_2_RGMII), (IMAGE_0_DS_TM_FLUSH_DISPATCHER_CREDIT_TABLE_ADDRESS >> 3) |
        (IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER << 12), dsptchr_viq_dest_reor, dsptchr_viq_delayed, DISP_REOR_VIQ_DS_TM_FLUSH_BBH_2_3,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);
#endif

#ifdef G9991
    /* VIQ for g9991 reassembly0 - 24 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(reassembly_runner_image), (IMAGE_1_REASSEMBLY_DISPATCHER_CREDIT_TABLE_ADDRESS >> 3) |
        (IMAGE_1_REASSEMBLY_G9991_0_THREAD_NUMBER << 12), dsptchr_viq_dest_disp, dsptchr_viq_delayed, DISP_REOR_VIQ_G9991_REASS0,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);

    /* VIQ for g9991 reassembly1 - 25 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(reassembly_runner_image), ((IMAGE_1_REASSEMBLY_DISPATCHER_CREDIT_TABLE_ADDRESS + 16) >> 3) |
        (IMAGE_1_REASSEMBLY_G9991_1_THREAD_NUMBER << 12), dsptchr_viq_dest_disp, dsptchr_viq_delayed, DISP_REOR_VIQ_G9991_REASS1,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);

    /* VIQ for g9991 reassembly2 - 26 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(reassembly_runner_image), ((IMAGE_1_REASSEMBLY_DISPATCHER_CREDIT_TABLE_ADDRESS + 32) >> 3) |
        (IMAGE_1_REASSEMBLY_G9991_2_THREAD_NUMBER << 12), dsptchr_viq_dest_disp, dsptchr_viq_delayed, DISP_REOR_VIQ_G9991_REASS2,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);

    /* VIQ for g9991 reassembly3 - 27 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(reassembly_runner_image), ((IMAGE_1_REASSEMBLY_DISPATCHER_CREDIT_TABLE_ADDRESS + 48) >> 3) |
        (IMAGE_1_REASSEMBLY_G9991_3_THREAD_NUMBER << 12), dsptchr_viq_dest_disp, dsptchr_viq_delayed, DISP_REOR_VIQ_G9991_REASS3,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);

    /* VIQ for CPU_RX_copy - 28 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(cpu_rx_runner_image), (IMAGE_2_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_ADDRESS >> 3 |
        IMAGE_2_CPU_IF_2_CPU_RX_COPY_THREAD_NUMBER << 12), dsptchr_viq_dest_reor, dsptchr_viq_delayed, DISP_REOR_VIQ_CPU_RX_COPY,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);
#endif

#ifdef CONFIG_DHD_RUNNER
    /* VIQ for DHD_RX_COMPLETE_0 - 22 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(dhd_complete_runner_image), (IMAGE_2_DHD_RX_COMPLETE_0_DISPATCHER_CREDIT_TABLE_ADDRESS >> 3 |
        IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_0_THREAD_NUMBER << 12), dsptchr_viq_dest_disp, dsptchr_viq_delayed, DISP_REOR_VIQ_DHD_RX_COMPLETE_0,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);

    /* VIQ for DHD_RX_COMPLETE_1 - 23 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(dhd_complete_runner_image), (IMAGE_2_DHD_RX_COMPLETE_1_DISPATCHER_CREDIT_TABLE_ADDRESS >> 3 |
        IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_1_THREAD_NUMBER << 12), dsptchr_viq_dest_disp, dsptchr_viq_delayed, DISP_REOR_VIQ_DHD_RX_COMPLETE_1,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);

    /* VIQ for DHD_RX_COMPLETE_2 - 24 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(dhd_complete_runner_image), (IMAGE_2_DHD_RX_COMPLETE_2_DISPATCHER_CREDIT_TABLE_ADDRESS >> 3 |
        IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_2_THREAD_NUMBER << 12), dsptchr_viq_dest_disp, dsptchr_viq_delayed, DISP_REOR_VIQ_DHD_RX_COMPLETE_2,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);

    /* VIQ for DHD Mcast - 27 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(dhd_tx_post_runner_image), (IMAGE_1_DHD_MCAST_DISPATCHER_CREDIT_TABLE_ADDRESS >> 3 |
        IMAGE_1_CPU_IF_1_DHD_MCAST_THREAD_NUMBER << 12), dsptchr_viq_dest_reor, dsptchr_viq_delayed, DISP_REOR_VIQ_DHD_MCAST,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);

#endif

#ifndef G9991
    /* VIQ for CPU_RX_copy - 28 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(cpu_rx_runner_image), (IMAGE_1_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_ADDRESS >> 3 |
        IMAGE_1_CPU_IF_1_CPU_RX_COPY_THREAD_NUMBER << 12), dsptchr_viq_dest_reor, dsptchr_viq_delayed, DISP_REOR_VIQ_CPU_RX_COPY,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);
#endif

#if defined(CONFIG_BCM_SPDSVC_SUPPORT)
    /* VIQ for SPDSVC - 29 */
    dispatcher_reorder_viq_init(&cfg, &congs_init, get_runner_idx(spdsvc_gen_runner_image), (IMAGE_2_SPDSVC_GEN_DISPATCHER_CREDIT_TABLE_ADDRESS >> 3 |
        IMAGE_2_CPU_IF_2_SPDSVC_GEN_THREAD_NUMBER << 12), dsptchr_viq_dest_reor, dsptchr_viq_delayed, DISP_REOR_VIQ_SPDSVC,
        DSPTCHR_NORMAL_GUARANTEED_BUFFERS, common_max_limit, 0);
#endif

    /* configure all rnr groups */
    for (core_index = 0; core_index < GROUPED_EN_SEGMENTS_NUM; core_index++)
    {
#ifndef G9991
        /* setting group 1 - wan direct */
        if (rdp_core_to_image_map[core_index] == wan_direct_runner_image)
        {
            dispatcher_reorder_rnr_group_init(&cfg, 1, core_index, (1<< IMAGE_1_CPU_IF_1_WAN_DIRECT_THREAD_NUMBER), (IMAGE_1_DIRECT_PROCESSING_PD_TABLE_ADDRESS >> 3), 0);
        }
#else
        /* setting group 1 - wan direct */
        /* setting group 7 - system port */
        if (rdp_core_to_image_map[core_index] == wan_direct_runner_image)
        {
            dispatcher_reorder_rnr_group_init(&cfg, 1, core_index, (1<< IMAGE_2_CPU_IF_2_WAN_DIRECT_THREAD_NUMBER),
                                              ((IMAGE_2_WAN_DIRECT_PROCESSING_PD_TABLE_ADDRESS - IMAGE_2_CPU_IF_2_WAN_DIRECT_THREAD_NUMBER * sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS)) >> 3),
                                              (sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) >> 3));

            dispatcher_reorder_rnr_group_init(&cfg, 7, core_index, (1<< IMAGE_2_CPU_IF_2_DIRECT_SYSTEM_PORT_THREAD_NUMBER),
                                              ((IMAGE_2_SYSTEM_PORT_DIRECT_PROCESSING_PD_TABLE_ADDRESS - IMAGE_2_CPU_IF_2_DIRECT_SYSTEM_PORT_THREAD_NUMBER * sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS)) >> 3),
                                              (sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) >> 3));
        }
        /* setting group 2-5 - reassembly */
        if (rdp_core_to_image_map[core_index] == reassembly_runner_image)
        {
            dispatcher_reorder_rnr_group_init(&cfg, 2, core_index, (1<< IMAGE_1_REASSEMBLY_G9991_0_THREAD_NUMBER), (IMAGE_1_G9991_PD_TABLE_ADDRESS >> 3), 4);
            dispatcher_reorder_rnr_group_init(&cfg, 3, core_index, (1<< IMAGE_1_REASSEMBLY_G9991_1_THREAD_NUMBER), (IMAGE_1_G9991_PD_TABLE_ADDRESS >> 3), 4);
            dispatcher_reorder_rnr_group_init(&cfg, 4, core_index, (1<< IMAGE_1_REASSEMBLY_G9991_2_THREAD_NUMBER), (IMAGE_1_G9991_PD_TABLE_ADDRESS >> 3), 4);
            dispatcher_reorder_rnr_group_init(&cfg, 5, core_index, (1<< IMAGE_1_REASSEMBLY_G9991_3_THREAD_NUMBER), (IMAGE_1_G9991_PD_TABLE_ADDRESS >> 3), 4);
        }

        /* setting group 6 - g9991 flow control */
        if ((( p_dpi_cfg->dpu_split_scheduling_mode) && (rdp_core_to_image_map[core_index] == flow_control_runner_image)) || (core_index == DS_TM_CORE_BBH_0_1))
        {
            dispatcher_reorder_rnr_group_init(&cfg, 6, core_index, (1<< IMAGE_0_DS_TM_FLOW_CONTROL_THREAD_NUMBER), (IMAGE_0_G9991_FLOW_CONTROL_PD_ADDRESS >> 3), 0);
        }
#endif
    }

    /* mapping viq to rnr group */
#ifndef G9991
#ifndef _CFE_
    cfg.rnr_grp_num = 2;
    cfg.dsptchr_rnr_group_list[0].queues_mask = ((1 << BBH_ID_NUM) - 1) | /* all bbh viq except wan-bbh exclusive viq */
        (1 << DISP_REOR_VIQ_CPU_TX_FORWARD);
#ifdef CONFIG_DHD_RUNNER
    cfg.dsptchr_rnr_group_list[0].queues_mask |=  (1 << DISP_REOR_VIQ_DHD_RX_COMPLETE_0) | (1 << DISP_REOR_VIQ_DHD_RX_COMPLETE_1) | (1 << DISP_REOR_VIQ_DHD_RX_COMPLETE_2) ;
#endif
    cfg.dsptchr_rnr_group_list[1].queues_mask = (1 << (BBH_ID_NUM + BBH_ID_PON)); /* wan-bbh exclusive viq */
#else
    /* send all traffic via "direct flow" */
    cfg.rnr_grp_num = 2;
    cfg.dsptchr_rnr_group_list[0].queues_mask = 0x0000;
    cfg.dsptchr_rnr_group_list[1].queues_mask = ((1 << BBH_ID_NUM) - 1) | (1 << (BBH_ID_NUM + BBH_ID_PON));;
#endif
#else /* G9991 */
    if (p_dpi_cfg->system_port != rdpa_emac_none)
        system_port_mask = (1 << p_dpi_cfg->system_port);
    cfg.rnr_grp_num = 8;
    cfg.dsptchr_rnr_group_list[0].queues_mask = (((1 << BBH_ID_NUM) - 1) & (~(p_dpi_cfg->g9991_port_vec)) & ~system_port_mask) |
        (1 << DISP_REOR_VIQ_G9991_REASS0) | (1 << DISP_REOR_VIQ_G9991_REASS1) |
        (1 << DISP_REOR_VIQ_G9991_REASS2) | (1 << DISP_REOR_VIQ_G9991_REASS3) |
        (1 << DISP_REOR_VIQ_CPU_TX_FORWARD);
    cfg.dsptchr_rnr_group_list[1].queues_mask = (1 << (BBH_ID_NUM + BBH_ID_PON));                                       /* wan-bbh exclusive viq */
    for (i = 0; i < RDD_G9991_SID_TO_PHYSICAL_PORT_MASK_SIZE; i++)
    {
        g9991_bbh = get_location_of_bit_in_mask(i+1, p_dpi_cfg->g9991_port_vec);
        if (g9991_bbh >= 0)
            cfg.dsptchr_rnr_group_list[i+2].queues_mask = (1 << g9991_bbh);                                             /* reassembly */
    }
    cfg.dsptchr_rnr_group_list[6].queues_mask = ((1 << (BBH_ID_NUM + BBH_ID_PON)) - 1) & (~((1 << BBH_ID_NUM) - 1));    /* lan-bbh exclusive viq (flow control) */
    cfg.dsptchr_rnr_group_list[7].queues_mask = system_port_mask;                                                       /* system port */
#endif

    /* set up pools limits */
    cfg.pools_limits.grnted_pool_lmt = cfg.viq_num
        +  cfg.viq_num * DSPTCHR_NORMAL_GUARANTEED_BUFFERS  /* should be equal to sum of grntd credits in all active queues */
        - (DSPTCHR_NORMAL_GUARANTEED_BUFFERS * (BBH_ID_NUM - 1)  /*No Guaranteed for exclusive VIQs besides PON*/
        + (DSPTCHR_NORMAL_GUARANTEED_BUFFERS - DSPTCHR_EXCLUSIVE_WAN_GUARANTEED_BUFFERS)); /*Guaranteed for PON exclusive VIQ*/
    cfg.pools_limits.grnted_pool_size = cfg.pools_limits.grnted_pool_lmt;
    cfg.pools_limits.mcast_pool_lmt = 0;
    cfg.pools_limits.mcast_pool_size = cfg.pools_limits.mcast_pool_lmt;
    cfg.pools_limits.cmn_pool_lmt = DIS_REOR_LINKED_LIST_BUFFER_NUM
        - (cfg.pools_limits.grnted_pool_lmt + cfg.pools_limits.mcast_pool_lmt);
    cfg.pools_limits.cmn_pool_size = cfg.pools_limits.cmn_pool_lmt;
    cfg.pools_limits.rnr_pool_lmt = 0; /* runners multicast prefetch limit */
    cfg.pools_limits.rnr_pool_size = 0; /* current in processing for multicast */
    cfg.pools_limits.processing_pool_size = 0; /* current in processing */

    /* enable all viq except wan-bbh */
    cfg.queue_en_vec = disp_reor_enable_vec(&cfg);

    rc = drv_dis_reor_queues_init();
    rc = rc ? rc : drv_dis_reor_tasks_to_rg_init();
    rc = rc ? rc : drv_dis_reor_free_linked_list_init();
    rc = rc ? rc : drv_dis_reor_cfg(&cfg);
    rc = rc ? rc : ag_drv_dsptchr_load_balancing_lb_cfg_set(1, 2); /*set strict task priority mode in dispatcher*/
    return rc;
}

#ifndef _CFE_
static int natc_init(void)
{
    int rc = BDMF_ERR_OK;
    natc_ddr_cfg_natc_ddr_size ddr_size = {ddr_size_32k, ddr_size_32k, ddr_size_32k, ddr_size_32k, ddr_size_32k, ddr_size_32k, ddr_size_32k, ddr_size_32k};
    natc_ddr_cfg_total_len total_len = {total_len_80B, total_len_80B, total_len_80B, total_len_80B, total_len_80B, total_len_80B, total_len_80B, total_len_80B};
    natc_config_t cfg;

    xrdp_memset(&cfg, 0, sizeof(natc_config_t));
    cfg.ctrl_status.nat_hash_mode = hash_mode_crc32_low;
    cfg.ctrl_status.ddr_hash_mode = hash_mode_crc32_low;
    cfg.ctrl_status.multi_hash_limit = multi_hash_limit_def;

    cfg.ctrl_status.age_timer_tick = timer_tick_packet;
    cfg.ctrl_status.age_timer = age_timer_32_ticks;

    cfg.ctrl_status.cache_update_on_reg_ddr_lookup = 1;
    cfg.ctrl_status.ddr_enable = 1;
    cfg.ctrl_status.natc_enable = 1;

    cfg.tbl_num = 2;

    /* DS table */
    cfg.tbl_cntrl[tuple_lkp_ds_tbl].key_len = key_len_16B;
    cfg.tbl_cfg[tuple_lkp_ds_tbl].mask = NATC_16BYTE_KEY_MASK;
    cfg.tbl_cfg[tuple_lkp_ds_tbl].key_len = NATC_TABLE_KEY_16B + (NATC_TABLE_KEY_16B * cfg.tbl_cntrl[tuple_lkp_ds_tbl].key_len);
    cfg.tbl_cfg[tuple_lkp_ds_tbl].key_tbl_size = ((((NATC_TABLE_BASE_SIZE_SIZE << ddr_size.ddr_size_tbl0) + ddr_8_bins_per_bucket) * cfg.tbl_cfg[tuple_lkp_ds_tbl].key_len) + 0x1f) & ~0x1f;
    cfg.tbl_cfg[tuple_lkp_ds_tbl].res_len = total_length_bytes[total_len_80B] - cfg.tbl_cfg[tuple_lkp_ds_tbl].key_len;
    cfg.tbl_cfg[tuple_lkp_ds_tbl].res_tbl_size = ((((NATC_TABLE_BASE_SIZE_SIZE << ddr_size.ddr_size_tbl0) + ddr_8_bins_per_bucket) * cfg.tbl_cfg[tuple_lkp_ds_tbl].res_len) + 0x1f) & ~0x1f;
#ifndef XRDP_EMULATION
    cfg.tbl_cfg[tuple_lkp_ds_tbl].vir_addr.key = p_dpi_cfg->rdp_ddr_rnr_tables_base_virt;
    cfg.tbl_cfg[tuple_lkp_ds_tbl].vir_addr.res = (void *)((uint8_t *)cfg.tbl_cfg[tuple_lkp_ds_tbl].vir_addr.key +
        cfg.tbl_cfg[tuple_lkp_ds_tbl].key_tbl_size);

    cfg.tbl_cfg[tuple_lkp_ds_tbl].phy_addr.key = RDD_RSV_VIRT_TO_PHYS(cfg.tbl_cfg[tuple_lkp_ds_tbl].vir_addr.key);
    cfg.tbl_cfg[tuple_lkp_ds_tbl].phy_addr.res = RDD_RSV_VIRT_TO_PHYS(cfg.tbl_cfg[tuple_lkp_ds_tbl].vir_addr.res);
#else
    cfg.tbl_cfg[tuple_lkp_ds_tbl].vir_addr.key = (uint32_t)bdmf_ioremap(cfg.tbl_cfg[tuple_lkp_ds_tbl].phy_addr.key,
        cfg.tbl_cfg[tuple_lkp_ds_tbl].key_tbl_size + cfg.tbl_cfg[tuple_lkp_ds_tbl].res_tbl_size);
    cfg.tbl_cfg[tuple_lkp_ds_tbl].vir_addr.res = cfg.tbl_cfg[tuple_lkp_ds_tbl].vir_addr.key +
        cfg.tbl_cfg[tuple_lkp_ds_tbl].key_tbl_size;

    cfg.tbl_cfg[tuple_lkp_ds_tbl].phy_addr.key = cfg.tbl_cfg[tuple_lkp_ds_tbl].vir_addr.key;
    cfg.tbl_cfg[tuple_lkp_ds_tbl].phy_addr.res = cfg.tbl_cfg[tuple_lkp_ds_tbl].vir_addr.res;
#endif

    /* US table */
    cfg.tbl_cntrl[tuple_lkp_us_tbl].key_len = key_len_16B;
    cfg.tbl_cfg[tuple_lkp_us_tbl].mask = NATC_16BYTE_KEY_MASK;
    cfg.tbl_cfg[tuple_lkp_us_tbl].key_len = NATC_TABLE_KEY_16B + (NATC_TABLE_KEY_16B * cfg.tbl_cntrl[tuple_lkp_us_tbl].key_len);

    /* To compute the actual size of the table, add DDR_BINS_PER_BUCKET field to the table size selection;
       For instance, if DDR_BINS_PER_BUCKET is 7 (8 bins per bucket) and DDR_size is 2 (32k entries), the actual size of the table in DDR is
      (32*1024+7) multiply by total length (TOTAL_LEN) of key and context in bytes
       Extra 7 entries are used to store collided entries of the last entry  
       Align to 32b key and res sizes to optimal performance */

    cfg.tbl_cfg[tuple_lkp_us_tbl].key_tbl_size = ((((NATC_TABLE_BASE_SIZE_SIZE << ddr_size.ddr_size_tbl1) + ddr_8_bins_per_bucket) * cfg.tbl_cfg[tuple_lkp_us_tbl].key_len) + 0x1f) & ~0x1f;
    cfg.tbl_cfg[tuple_lkp_us_tbl].res_len = total_length_bytes[total_len_80B] - cfg.tbl_cfg[tuple_lkp_us_tbl].key_len;
    cfg.tbl_cfg[tuple_lkp_us_tbl].res_tbl_size = ((((NATC_TABLE_BASE_SIZE_SIZE << ddr_size.ddr_size_tbl1) + ddr_8_bins_per_bucket) * cfg.tbl_cfg[tuple_lkp_us_tbl].res_len) + 0x1f) & ~0x1f;

#ifndef XRDP_EMULATION
    cfg.tbl_cfg[tuple_lkp_us_tbl].vir_addr.key = (void *)((uint8_t *)cfg.tbl_cfg[tuple_lkp_ds_tbl].vir_addr.res +
                                                          cfg.tbl_cfg[tuple_lkp_ds_tbl].res_tbl_size);
    cfg.tbl_cfg[tuple_lkp_us_tbl].vir_addr.res = (void *)((uint8_t *)cfg.tbl_cfg[tuple_lkp_us_tbl].vir_addr.key +
        cfg.tbl_cfg[tuple_lkp_us_tbl].key_tbl_size);

    cfg.tbl_cfg[tuple_lkp_us_tbl].phy_addr.key = RDD_RSV_VIRT_TO_PHYS(cfg.tbl_cfg[tuple_lkp_us_tbl].vir_addr.key);
    cfg.tbl_cfg[tuple_lkp_us_tbl].phy_addr.res = RDD_RSV_VIRT_TO_PHYS(cfg.tbl_cfg[tuple_lkp_us_tbl].vir_addr.res);
#else
    cfg.tbl_cfg[tuple_lkp_us_tbl].vir_addr.key = (uint32_t)bdmf_ioremap(cfg.tbl_cfg[tuple_lkp_us_tbl].phy_addr.key,
        cfg.tbl_cfg[tuple_lkp_us_tbl].key_tbl_size + cfg.tbl_cfg[tuple_lkp_us_tbl].res_tbl_size);
    cfg.tbl_cfg[tuple_lkp_us_tbl].vir_addr.res = cfg.tbl_cfg[tuple_lkp_us_tbl].vir_addr.key +
        cfg.tbl_cfg[tuple_lkp_us_tbl].key_tbl_size;

    cfg.tbl_cfg[tuple_lkp_us_tbl].phy_addr.key = cfg.tbl_cfg[tuple_lkp_us_tbl].vir_addr.key;
    cfg.tbl_cfg[tuple_lkp_us_tbl].phy_addr.res = cfg.tbl_cfg[tuple_lkp_us_tbl].vir_addr.res;
#endif

    rc = rc ? rc : ag_drv_natc_ddr_cfg_ddr_bins_per_bucket_0_set(ddr_8_bins_per_bucket, ddr_8_bins_per_bucket, ddr_8_bins_per_bucket, ddr_8_bins_per_bucket);
    rc = rc ? rc : ag_drv_natc_ddr_cfg_ddr_bins_per_bucket_1_set(ddr_8_bins_per_bucket, ddr_8_bins_per_bucket, ddr_8_bins_per_bucket, ddr_8_bins_per_bucket);
    rc = rc ? rc : ag_drv_natc_ddr_cfg_natc_ddr_size_set(&ddr_size);
    rc = rc ? rc : ag_drv_natc_ddr_cfg_total_len_set(&total_len);
    rc = rc ? rc : ag_drv_natc_key_mask_tbl_key_mask_set(tuple_lkp_ds_tbl, NATC_16BYTE_KEY_MASK);
    rc = rc ? rc : ag_drv_natc_key_mask_tbl_key_mask_set(tuple_lkp_us_tbl, NATC_16BYTE_KEY_MASK);


    return (rc ? rc : drv_natc_init(&cfg));
}
#endif /* _CFE_ */


static int dqm_init(void)
{
    bdmf_error_t rc;
    bdmf_phys_addr_t fpm_base_phys_addr;
    uint32_t buf_size;

    fpm_base_phys_addr = RDD_RSV_VIRT_TO_PHYS(p_dpi_cfg->rdp_ddr_pkt_base_virt);
    buf_size = g_bbh_tx_ddr_profile->bbh_tx_ddr_cfg[BBH_ID_FIRST].bufsize;
    fpm_base_phys_addr = (fpm_base_phys_addr >> 8);
    rc = ag_drv_dqm_fpm_addr_set(xrdp_virt2phys(&RU_BLK(FPM), 0) + RU_REG_OFFSET(FPM, POOL1_ALLOC_DEALLOC));
    rc = rc ? rc : ag_drv_dqm_buf_base_set(fpm_base_phys_addr);
    rc = rc ? rc : ag_drv_dqm_buf_size_set(buf_size);

    return rc;
}

static int qm_init(void)
{
    uint32_t addr_hi, addr_lo;
    bdmf_phys_addr_t fpm_base_phys_addr;
    bdmf_error_t rc = BDMF_ERR_OK;
    qm_rnr_group_cfg rnr_group_cfg = {};
    qm_q_context queue_cfg = {};
    qm_wred_profile_cfg wred_cfg = {};
    uint32_t idx = 0;

    qm_init_cfg init_cfg =
    {
        .is_counters_read_clear = 0,   /* TRUE=read-clear counter access mode */
        .is_drop_counters_enable = 1,  /* TRUE=drop counters enable. FALSE=max occupancy holder */
#ifndef _CFE_
        .is_close_agg_disable = 1,     /* TRUE=aggregations are not closed automatically */
#else
        .is_close_agg_disable = 0,
#endif
        .ddr_sop_offset = {0, 18}     /* DDR SoP offsets profile0 - everythig except multicast , profile1 - for multicast, */
    };

    fpm_base_phys_addr = RDD_RSV_VIRT_TO_PHYS(p_dpi_cfg->rdp_ddr_pkt_base_virt);
    GET_ADDR_HIGH_LOW(addr_hi, addr_lo, fpm_base_phys_addr);

    init_cfg.fpm_base = (addr_hi << 24) | (addr_lo >> 8); /* in 256B resolution */
    init_cfg.fpm_buf_size = g_bbh_tx_ddr_profile->bbh_tx_ddr_cfg[BBH_ID_FIRST].bufsize;

    init_cfg.num_fpm_ug = NUM_OF_FPM_UG;          /* Number of valid elements in fpm_ug_thr array */

    /* Default configuration - no WLAN */

    init_cfg.fpm_ug_thr[0].higher_thr = DS_FPM_UG_DEFAULT;  /* DS */
    init_cfg.fpm_ug_thr[0].lower_thr = init_cfg.fpm_ug_thr[0].mid_thr = init_cfg.fpm_ug_thr[0].higher_thr;

    init_cfg.fpm_ug_thr[1].higher_thr = US_FPM_UG_DEFAULT;  /* US */
    init_cfg.fpm_ug_thr[1].lower_thr = init_cfg.fpm_ug_thr[1].mid_thr = init_cfg.fpm_ug_thr[1].higher_thr;

    /* WLAN group in future solution*/
    init_cfg.fpm_ug_thr[2].higher_thr = WLAN_FPM_UG_DEFAULT;  /* WLAN */
    init_cfg.fpm_ug_thr[2].lower_thr = init_cfg.fpm_ug_thr[2].mid_thr = init_cfg.fpm_ug_thr[2].higher_thr;

    /* All pass group - for CPU and WLAN in short term solution */
    init_cfg.fpm_ug_thr[3].higher_thr = TOTAL_FPM_TOKENS;
    init_cfg.fpm_ug_thr[3].lower_thr = init_cfg.fpm_ug_thr[3].mid_thr = init_cfg.fpm_ug_thr[3].higher_thr;

    rc = rc ? rc : drv_qm_init(&init_cfg);

	/* Init spedific WRED profiles*/

    /* CPU_RX WRED profile */
    wred_cfg.min_thr0 = 8000;
    wred_cfg.min_thr1 = 24000;
    wred_cfg.max_thr0 = 8000;
    wred_cfg.max_thr1 = 24000;
    rc = rc ? rc :ag_drv_qm_wred_profile_cfg_set(QM_WRED_PROFILE_CPU_RX, &wred_cfg);

    if (!rc)
        ag_drv_qm_qm_pd_cong_ctrl_set(DEF_QM_PD_CONGESTION_CONTROL_THRESHOLD);


    ag_drv_qm_copy_decision_profile_set(QM_COPY_DEC_PROFILE_LOW, QM_COPY_DEC_MAX_QUEUE_OCCUPANCY , 0);
    ag_drv_qm_copy_decision_profile_set(QM_COPY_DEC_PROFILE_HIGH, QM_COPY_DEC_MAX_QUEUE_OCCUPANCY , 1);


    /* Initializing DQM before any of QM's queues */
    rc = rc ? rc : dqm_init();

    /* setup 1 queue */
    queue_cfg.wred_profile = 0;                            /* WRED profile */
    queue_cfg.copy_dec_profile = QM_COPY_DEC_PROFILE_LOW;  /* Copy decision profile */
    queue_cfg.fpm_ug = FPM_US_UG;                          /* FPM UG */
    queue_cfg.ddr_copy_disable = 0;                        /* TRUE=never copy to DDR */
    queue_cfg.copy_to_ddr = US_DDR_COPY_ENABLE;            /* TRUE=Force copy to DDR */
#ifndef _CFE_
    queue_cfg.aggregation_disable = 0;          /* TRUE=Disable aggregation */
#else
    queue_cfg.aggregation_disable = 1;
#endif
    queue_cfg.exclusive_priority = 0;           /* TRUE=exclusive priority */
    queue_cfg.q_802_1ae = 0;                    /* TRUE=802.1AE */
    queue_cfg.sci = 0;                          /* TRUE=SCI */
    queue_cfg.fec_enable = 0;                   /* TRUE=enable FEC */

    /* Init ALL queues */
    for (idx = QM_QUEUE_US_START; idx <= QM_QUEUE_US_END; idx++)
    {
        rc = rc ? rc : drv_qm_queue_config(idx, &queue_cfg);
        rc = rc ? rc : drv_qm_queue_enable(idx);
    }
    queue_cfg.fpm_ug = FPM_DS_UG;                       /* FPM UG */
    queue_cfg.copy_to_ddr = DS_DDR_COPY_ENABLE;         /* TRUE=Force copy to DDR */
    queue_cfg.aggregation_disable = DS_AGG_DISABLE;     /* TRUE=Disable aggregation */

    for (idx = QM_QUEUE_DS_START; idx <= QM_QUEUE_DS_END; idx++)
    {
        rc = rc ? rc : drv_qm_queue_config(idx, &queue_cfg);
        rc = rc ? rc : drv_qm_queue_enable(idx);
    }

    /* Init DS drop queue */
    queue_cfg.wred_profile = QM_WRED_PROFILE_DROP_ALL;
    queue_cfg.aggregation_disable = 1;   /* TRUE=Disable aggregation */
    rc = rc ? rc : drv_qm_queue_config(QM_QUEUE_DROP, &queue_cfg);
    rc = rc ? rc : drv_qm_queue_enable(QM_QUEUE_DROP);

    queue_cfg.fpm_ug = FPM_ALL_PASS_UG;       /* FPM UG */

    queue_cfg.wred_profile = 0;
    queue_cfg.copy_to_ddr = 0;           /* TRUE=Force copy to DDR */
    queue_cfg.aggregation_disable = 1;   /* TRUE=Disable aggregation */

    for (idx = QM_QUEUE_DS_END + 1; idx < QM_NUM_QUEUES; idx++)
    {
    if ((idx == QM_QUEUE_DROP) || (idx == QM_QUEUE_CPU_RX) || (idx == QM_QUEUE_CPU_RX_COPY_NORMAL) || (idx == QM_QUEUE_CPU_RX_COPY_EXCLUSIVE))
            continue;

#ifdef CONFIG_DHD_RUNNER
       if ((idx == QM_QUEUE_DHD_TX_POST_0)  || (idx == QM_QUEUE_DHD_TX_POST_1)  || (idx == QM_QUEUE_DHD_TX_POST_2))
	        continue;
#endif
        rc = rc ? rc : drv_qm_queue_config(idx, &queue_cfg);
        rc = rc ? rc : drv_qm_queue_enable(idx);
    }

#ifdef CONFIG_DHD_RUNNER
    /* configure params for DHD_TX_POST queue - DHD CPU queues are standard and configured above*/
    queue_cfg.copy_to_ddr = 1;
    queue_cfg.fpm_ug = FPM_WLAN_UG;
    queue_cfg.exclusive_priority = 1;

    for (idx = 0; idx < 3; idx++)
    {
        rc = rc ? rc : drv_qm_queue_config(QM_QUEUE_DHD_TX_POST_0 + idx*2, &queue_cfg);
        rc = rc ? rc : drv_qm_queue_enable(QM_QUEUE_DHD_TX_POST_0  + idx*2);
    }

    /* configure params for DHD_MCAST queue */
    queue_cfg.copy_to_ddr = 0;
    queue_cfg.exclusive_priority = 0;
    queue_cfg.ddr_copy_disable = 1;
    rc = rc ? rc : drv_qm_queue_config(QM_QUEUE_DHD_MCAST, &queue_cfg);
    rc = rc ? rc : drv_qm_queue_enable(QM_QUEUE_DHD_MCAST);

    queue_cfg.fpm_ug = FPM_ALL_PASS_UG;       /* FPM UG */
    queue_cfg.copy_to_ddr = 0;           /* TRUE=Force copy to DDR */
    queue_cfg.ddr_copy_disable = 0;
    /* -------------------------------- */
#endif

    /* configure WRED profile for CPU_RX queue */
    queue_cfg.wred_profile = QM_WRED_PROFILE_CPU_RX;

    rc = rc ? rc : drv_qm_queue_config(QM_QUEUE_CPU_RX, &queue_cfg);
    rc = rc ? rc : drv_qm_queue_enable(QM_QUEUE_CPU_RX);

    queue_cfg.copy_dec_profile = QM_COPY_DEC_PROFILE_HIGH;             /* Copy decision profile */
    queue_cfg.wred_profile = QM_WRED_PROFILE_CPU_RX;
    queue_cfg.ddr_copy_disable = QM_COPY_DEC_PROFILE_HIGH;

    rc = rc ? rc : drv_qm_queue_config(QM_QUEUE_CPU_RX_COPY_NORMAL, &queue_cfg);
    rc = rc ? rc : drv_qm_queue_enable(QM_QUEUE_CPU_RX_COPY_NORMAL);

    queue_cfg.wred_profile = QM_WRED_PROFILE_CPU_RX;
    queue_cfg.ddr_copy_disable = 0;

    rc = rc ? rc : drv_qm_queue_config(QM_QUEUE_CPU_RX_COPY_EXCLUSIVE, &queue_cfg);
    rc = rc ? rc : drv_qm_queue_enable(QM_QUEUE_CPU_RX_COPY_EXCLUSIVE);

    if (p_dpi_cfg->dpu_split_scheduling_mode)
    {
        /* ds group 0 */
        rnr_group_cfg.start_queue = QM_QUEUE_DS_START; /* should be from dpi params */
        rnr_group_cfg.end_queue = QM_QUEUE_DS_START + ( QM_QUEUE_DS_END - QM_QUEUE_DS_START ) / 2; /* should be from dpi params */
        rnr_group_cfg.pd_fifo_base = (IMAGE_0_DS_TM_PD_FIFO_TABLE_ADDRESS >> 3);
        rnr_group_cfg.pd_fifo_size = qm_pd_fifo_size_2;
        rnr_group_cfg.upd_fifo_base = (IMAGE_0_UPDATE_FIFO_TABLE_ADDRESS >> 3);
        rnr_group_cfg.upd_fifo_size = qm_update_fifo_size_8;
        rnr_group_cfg.rnr_bb_id = get_ds_tm_rnr_id(BBH_ID_XLMAC1_0_RGMII);
        rnr_group_cfg.rnr_task = IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER;
        rnr_group_cfg.rnr_enable = 1;
        rc = rc ? rc : ag_drv_qm_rnr_group_cfg_set(qm_rnr_group_0, &rnr_group_cfg);

        /* ds group 10 */
        rnr_group_cfg.start_queue = QM_QUEUE_DS_START + (QM_QUEUE_DS_END - QM_QUEUE_DS_START) / 2 + 1; /* should be from dpi params */
        rnr_group_cfg.end_queue = QM_QUEUE_DS_END; /* should be from dpi params */
        rnr_group_cfg.pd_fifo_base = (IMAGE_0_DS_TM_PD_FIFO_TABLE_ADDRESS >> 3);
        rnr_group_cfg.pd_fifo_size = qm_pd_fifo_size_2;
        rnr_group_cfg.upd_fifo_base = (IMAGE_0_UPDATE_FIFO_TABLE_ADDRESS >> 3);
        rnr_group_cfg.upd_fifo_size = qm_update_fifo_size_8;
        rnr_group_cfg.rnr_bb_id = get_ds_tm_rnr_id(BBH_ID_XLMAC1_2_RGMII);
        rnr_group_cfg.rnr_task = IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER;
        rnr_group_cfg.rnr_enable = 1;
        rc = rc ? rc : ag_drv_qm_rnr_group_cfg_set(qm_rnr_group_10, &rnr_group_cfg);
    }
    else
    {
        /* ds group 0 */
        rnr_group_cfg.start_queue = QM_QUEUE_DS_START; /* should be from dpi params */
        rnr_group_cfg.end_queue = QM_QUEUE_DS_END; /* should be from dpi params */
        rnr_group_cfg.start_queue = QM_QUEUE_DS_START; /* should be from dpi params */
        rnr_group_cfg.end_queue = QM_QUEUE_DS_END; /* should be from dpi params */
        rnr_group_cfg.pd_fifo_base = (IMAGE_0_DS_TM_PD_FIFO_TABLE_ADDRESS >> 3);
        rnr_group_cfg.pd_fifo_size = qm_pd_fifo_size_2;
        rnr_group_cfg.upd_fifo_base = (IMAGE_0_UPDATE_FIFO_TABLE_ADDRESS >> 3);
        rnr_group_cfg.upd_fifo_size = qm_update_fifo_size_8;
        rnr_group_cfg.rnr_bb_id = get_ds_tm_rnr_id(BBH_ID_XLMAC1_0_RGMII);
        rnr_group_cfg.rnr_task = IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER;
        rnr_group_cfg.rnr_enable = 1;
        rc = rc ? rc : ag_drv_qm_rnr_group_cfg_set(qm_rnr_group_0, &rnr_group_cfg);
    }

#ifdef G9991
    /* cpu - group 3 (cpu_rx fifo task) */
    rnr_group_cfg.start_queue = QM_QUEUE_CPU_RX; /* single queue for CPU RX */
    rnr_group_cfg.end_queue = QM_QUEUE_CPU_RX;
    rnr_group_cfg.pd_fifo_base = (IMAGE_2_PD_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.rnr_task = IMAGE_2_CPU_IF_2_CPU_RX_UPDATE_FIFO_THREAD_NUMBER;
    rnr_group_cfg.upd_fifo_base = (IMAGE_2_UPDATE_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.pd_fifo_size = qm_pd_fifo_size_2;
    rnr_group_cfg.upd_fifo_size = qm_update_fifo_size_8;
    rnr_group_cfg.rnr_bb_id = get_runner_idx(cpu_rx_runner_image);
    rnr_group_cfg.rnr_enable = 1;
    rc = rc ? rc : ag_drv_qm_rnr_group_cfg_set(qm_rnr_group_3, &rnr_group_cfg);
#else
    /* cpu - group 3 (cpu_rx fifo task) */
    rnr_group_cfg.start_queue = QM_QUEUE_CPU_RX; /* single queue for CPU RX */
    rnr_group_cfg.end_queue = QM_QUEUE_CPU_RX;
    rnr_group_cfg.pd_fifo_base = (IMAGE_1_PD_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.rnr_task = IMAGE_1_CPU_IF_1_CPU_RX_UPDATE_FIFO_THREAD_NUMBER;
    rnr_group_cfg.upd_fifo_base = (IMAGE_1_UPDATE_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.pd_fifo_size = qm_pd_fifo_size_2;
    rnr_group_cfg.upd_fifo_size = qm_update_fifo_size_8;
    rnr_group_cfg.rnr_bb_id = get_runner_idx(cpu_rx_runner_image);
    rnr_group_cfg.rnr_enable = 1;
    rc = rc ? rc : ag_drv_qm_rnr_group_cfg_set(qm_rnr_group_3, &rnr_group_cfg);
#endif

#ifndef CPU_TX_RING
    /* cpu - group 4 (cpu_tx egress fifo task) */
    rnr_group_cfg.start_queue = QM_QUEUE_CPU_TX_EGRESS; /* single queue for CPU TX egress*/
    rnr_group_cfg.end_queue = QM_QUEUE_CPU_TX_EGRESS;
    rnr_group_cfg.pd_fifo_base = (IMAGE_2_CPU_TX_EGRESS_PD_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.rnr_task = IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_EGRESS_THREAD_NUMBER;
    rnr_group_cfg.upd_fifo_base = (IMAGE_2_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.pd_fifo_size = qm_pd_fifo_size_2;
    rnr_group_cfg.upd_fifo_size = qm_update_fifo_size_8;
    rnr_group_cfg.rnr_bb_id = get_runner_idx(cpu_tx_runner_image);
    rnr_group_cfg.rnr_enable = 1;
    rc = rc ? rc : ag_drv_qm_rnr_group_cfg_set(qm_rnr_group_4, &rnr_group_cfg);

    /* cpu - group 5 (cpu_tx forward fifo task) */
    rnr_group_cfg.start_queue = QM_QUEUE_CPU_TX_INGRESS; /* single queue for CPU TX ingress */
    rnr_group_cfg.end_queue = QM_QUEUE_CPU_TX_INGRESS;
    rnr_group_cfg.pd_fifo_base = (IMAGE_2_CPU_TX_INGRESS_PD_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.rnr_task = IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_INGRESS_THREAD_NUMBER;
    rnr_group_cfg.upd_fifo_base = (IMAGE_2_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.pd_fifo_size = qm_pd_fifo_size_2;
    rnr_group_cfg.upd_fifo_size = qm_update_fifo_size_8;
    rnr_group_cfg.rnr_bb_id = get_runner_idx(cpu_tx_runner_image);
    rnr_group_cfg.rnr_enable = 1;
    rc = rc ? rc : ag_drv_qm_rnr_group_cfg_set(qm_rnr_group_5, &rnr_group_cfg);
#endif

#ifdef CONFIG_DHD_RUNNER
    /* dhd tx post - group 6 (dhd tx post and cpu tx post fifo task) */
    rnr_group_cfg.start_queue = QM_QUEUE_DHD_CPU_TX_POST_0; /* DHD CPU and TX group */
    rnr_group_cfg.end_queue = QM_QUEUE_DHD_TX_POST_2;
    rnr_group_cfg.pd_fifo_base = (IMAGE_1_DHD_TX_POST_PD_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.rnr_task = IMAGE_1_CPU_IF_1_DHD_TX_POST_UPDATE_FIFO_THREAD_NUMBER;
    rnr_group_cfg.upd_fifo_base = (IMAGE_1_DHD_TX_POST_UPDATE_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.pd_fifo_size = qm_pd_fifo_size_2;
    rnr_group_cfg.upd_fifo_size = qm_update_fifo_size_8;
    rnr_group_cfg.rnr_bb_id = get_runner_idx(dhd_tx_post_runner_image);
    rnr_group_cfg.rnr_enable = 1;
    rc = rc ? rc : ag_drv_qm_rnr_group_cfg_set(qm_rnr_group_6, &rnr_group_cfg);

    /* dhd mcast - group 7 (dhd mcast fifo task) */
    rnr_group_cfg.start_queue = QM_QUEUE_DHD_MCAST; /* single queue for DHD Mcast for all 3 radios */
    rnr_group_cfg.end_queue = QM_QUEUE_DHD_MCAST;
    rnr_group_cfg.pd_fifo_base = (IMAGE_1_DHD_MCAST_PD_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.upd_fifo_base = (IMAGE_1_DHD_MCAST_UPDATE_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.pd_fifo_size = qm_pd_fifo_size_2;
    rnr_group_cfg.upd_fifo_size = qm_update_fifo_size_8;

    rnr_group_cfg.rnr_task = IMAGE_1_CPU_IF_1_DHD_MCAST_UPDATE_FIFO_THREAD_NUMBER;

    rnr_group_cfg.rnr_bb_id = get_runner_idx(dhd_tx_post_runner_image);
    rnr_group_cfg.rnr_enable = 1;
    rc = rc ? rc : ag_drv_qm_rnr_group_cfg_set(qm_rnr_group_7, &rnr_group_cfg);
#endif

#ifdef G9991
    /* cpu - group 8 (cpu_rx_copy fifo task) */
    rnr_group_cfg.start_queue = QM_QUEUE_CPU_RX_COPY_EXCLUSIVE; /* 2 queues for CPU RX COPY*/
    rnr_group_cfg.end_queue = QM_QUEUE_CPU_RX_COPY_NORMAL;
    rnr_group_cfg.pd_fifo_base = (IMAGE_2_CPU_RX_COPY_PD_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.rnr_task = IMAGE_2_CPU_IF_2_CPU_RX_COPY_UPDATE_FIFO_THREAD_NUMBER;
    rnr_group_cfg.upd_fifo_base = (IMAGE_2_CPU_RX_COPY_UPDATE_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.pd_fifo_size = qm_pd_fifo_size_2;
    rnr_group_cfg.upd_fifo_size = qm_update_fifo_size_8;
    rnr_group_cfg.rnr_bb_id = get_runner_idx(cpu_rx_runner_image);
    rnr_group_cfg.rnr_enable = 1;
    rc = rc ? rc : ag_drv_qm_rnr_group_cfg_set(qm_rnr_group_8, &rnr_group_cfg);
#else
    /* cpu - group 8 (cpu_rx_copy fifo task) */
    rnr_group_cfg.start_queue = QM_QUEUE_CPU_RX_COPY_EXCLUSIVE; /* 2 queues for CPU RX COPY*/
    rnr_group_cfg.end_queue = QM_QUEUE_CPU_RX_COPY_NORMAL;
    rnr_group_cfg.pd_fifo_base = (IMAGE_1_CPU_RX_COPY_PD_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.rnr_task = IMAGE_1_CPU_IF_1_CPU_RX_COPY_UPDATE_FIFO_THREAD_NUMBER;
    rnr_group_cfg.upd_fifo_base = (IMAGE_1_CPU_RX_COPY_UPDATE_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.pd_fifo_size = qm_pd_fifo_size_2;
    rnr_group_cfg.upd_fifo_size = qm_update_fifo_size_8;
    rnr_group_cfg.rnr_bb_id = get_runner_idx(cpu_rx_runner_image);
    rnr_group_cfg.rnr_enable = 1;
    rc = rc ? rc : ag_drv_qm_rnr_group_cfg_set(qm_rnr_group_8, &rnr_group_cfg);
#endif  // G9991

#if defined(CONFIG_BCM_SPDSVC_SUPPORT)
    /* Recycle buffers transmitted from ABS address and discarded by QM.
     * For now this feature is only supported for speed service. It will need
     * to be re-evaluated when CPU TX from ABS address is implemented
     */
    rnr_group_cfg.start_queue = QM_QUEUE_TX_ABS_RECYCLE;
    rnr_group_cfg.end_queue = QM_QUEUE_TX_ABS_RECYCLE;
    rnr_group_cfg.pd_fifo_base = (IMAGE_2_TX_ABS_RECYCLE_PD_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.rnr_task = IMAGE_2_CPU_IF_2_TX_ABS_RECYCLE_THREAD_NUMBER;
    rnr_group_cfg.upd_fifo_base = (IMAGE_2_TX_ABS_RECYCLE_UPDATE_FIFO_TABLE_ADDRESS >> 3);
    rnr_group_cfg.pd_fifo_size = qm_pd_fifo_size_2;
    rnr_group_cfg.upd_fifo_size = qm_update_fifo_size_8;
    rnr_group_cfg.rnr_bb_id = get_runner_idx(tx_abs_recycle_runner_image);
    rnr_group_cfg.rnr_enable = 1;
    rc = rc ? rc : ag_drv_qm_rnr_group_cfg_set(qm_rnr_group_9, &rnr_group_cfg);

    /* Provision QM to re-queue discarded ABS PDs to QM_QUEUE_TX_ABS_RECYCLE queue */
    rc = rc ? rc : ag_drv_qm_global_cfg_abs_drop_queue_set(QM_QUEUE_TX_ABS_RECYCLE, 1);
#endif

    return rc;
}

static void rdp_block_enable(void)
{
    uint8_t idx;
    qm_enable_ctrl qm_enable = {
        .fpm_prefetch_enable = 1,
        .reorder_credit_enable = 1,
        .dqm_pop_enable = 1,
        .rmt_fixed_arb_enable = 1,
        .dqm_push_fixed_arb_enable = 1
    };

    bdmf_error_t rc = BDMF_ERR_OK;
#ifndef RDP_SIM
    bdmf_boolean rdy = 0;
    bdmf_boolean bsy = 0;
    uint16_t init_offset = 0;
    uint16_t base_addr = 0;

    /* enable BBH_RX */
    while ((rc == BDMF_ERR_OK) && (rdy == 0))
    {
        rc = ag_drv_sbpm_regs_init_free_list_get(&base_addr, &init_offset, &bsy, &rdy);
        xrdp_usleep(FPM_POLL_SLEEP_TIME);
    }
#endif
    for (idx = BBH_ID_FIRST; idx <= BBH_ID_LAST_XLMAC; idx++)
    {
        rc = rc ? rc : ag_drv_xlif_rx_if_if_dis_set(idx, 0);
        rc = rc ? rc : ag_drv_xlif_tx_if_if_enable_set(idx, 0, 0);
        rc = rc ? rc : ag_drv_xlif_tx_if_urun_port_enable_set(idx, 0);
        rc = rc ? rc : ag_drv_xlif_tx_if_tx_threshold_set(idx, 12);
    }
    for (idx = BBH_ID_FIRST; idx < BBH_ID_PON; idx++)
    {
        rc = rc ? rc : ag_drv_bbh_rx_general_configuration_enable_set(idx, 1, 1);
    }

    /* enable DISP_REOR */
    rc = rc ? rc : ag_drv_dsptchr_reorder_cfg_dsptchr_reordr_cfg_set(1, 1);

    /* enable QM */
    rc = rc ? rc : ag_drv_qm_enable_ctrl_set(&qm_enable);
    rc = rc ? rc : ag_drv_ubus_mstr_en_set(0, 1);
    rc = rc ? rc : ag_drv_ubus_mstr_en_set(1, 1);

    /* enable RNR */
    for (idx = 0; idx <= RNR_LAST; idx++)
        rc = rc ? rc : ag_drv_rnr_regs_rnr_enable_set(idx, 1);

    if (rc)
        BDMF_TRACE_ERR("Failed to enable rdp blocks\n");
}


#ifdef G9991
static void g9991_gbe_cfg(rdpa_emac wan_emac)
{
#ifdef BCM6858
    if (wan_emac == 0 || wan_emac == 4)
    {
        ag_drv_bbh_rx_general_configuration_crcomitdis_set(4 - wan_emac, 0);
        ag_drv_bbh_rx_general_configuration_sopoffset_set(4 - wan_emac, SOP_OFFSET);
        ag_drv_bbh_rx_general_configuration_g9991en_set(4 - wan_emac, 0, 0);
    }
    else
    {
        ag_drv_bbh_rx_general_configuration_crcomitdis_set(wan_emac, 0);
        ag_drv_bbh_rx_general_configuration_sopoffset_set(wan_emac, SOP_OFFSET);
        ag_drv_bbh_rx_general_configuration_g9991en_set(wan_emac, 0, 0);
    }
#else
    ag_drv_bbh_rx_general_configuration_crcomitdis_set(wan_emac, 0);
    ag_drv_bbh_rx_general_configuration_sopoffset_set(wan_emac, SOP_OFFSET);
    ag_drv_bbh_rx_general_configuration_g9991en_set(wan_emac, 0);
#endif
}
#endif


static int _data_path_init(dpi_params_t *dpi_params, int is_basic)
{
    bdmf_error_t rc;
    p_dpi_cfg = dpi_params;

    bdmf_trace("INFO: %s#%d: Start.\n", __FUNCTION__, __LINE__);
#if defined(RDP_SIM) && !defined(XRDP_EMULATION)
    if (rdd_sim_alloc_segments())
        return BDMF_ERR_INTERNAL;
#endif
    ubus_bridge_init();

    rc = bbh_profiles_init();
    if (rc)
    {
        bdmf_trace("Error: %s#%d: Failed to init BBH profiles.\n", __FUNCTION__, __LINE__);
        return rc;
    }

    bdmf_trace("INFO: %s#%d: Driver init.\n", __FUNCTION__, __LINE__);

    rc = fpm_init();
    rc = rc ? rc : qm_init();
    rc = rc ? rc : runner_init(is_basic);
    rc = rc ? rc : bbh_rx_init();
    rc = rc ? rc : bbh_tx_init();
    rc = rc ? rc : sbpm_init();
    rc = rc ? rc : cnpl_init();
    rc = rc ? rc : dma_sdma_init();
    rc = rc ? rc : dispatcher_reorder_init();
#ifndef _CFE_
    rc = rc ? rc : natc_init();
    rc = rc ? rc : hash_init();
#endif
    if (rc)
    {
        bdmf_trace("Error: %s#%d: rc = %d, End.\n", __FUNCTION__, __LINE__, rc);
        return rc;
    }

    bdmf_trace("INFO: %s#%d: Enable Accelerators.\n", __FUNCTION__, __LINE__);
    rdp_block_enable();
    bdmf_trace("INFO: %s#%d: End.\n", __FUNCTION__, __LINE__);
    return rc;
}

#ifdef CONFIG_BCM_UBUS_DECODE_REMAP
extern unsigned int g_board_size_power_of_2;
#endif

int data_path_init(dpi_params_t *dpi_params)
{
#ifdef CONFIG_BCM_UBUS_DECODE_REMAP
	void *fpm_pool_addr;
	uint32_t fpm_pool_size;
	int rc;

	if ((rc = drv_rnr_quad_ubus_decode_wnd_cfg(DECODE_WIN0, 0, g_board_size_power_of_2, DECODE_CFG_PID_B53, IS_DDR_COHERENT)))
	{
		printk("Error %s line[%d] size[%d]: \n",__FILE__, __LINE__,
				g_board_size_power_of_2);
		return rc;
	}

#ifdef CONFIG_BCM_FPM_COHERENCY_EXCLUDE
	/* FPM pool memory must not be cache coherent since CCI-400 can't handle 10Gig bandwidth */
	if (BcmMemReserveGetByName(FPMPOOL_BASE_ADDR_STR, &fpm_pool_addr, &fpm_pool_size))
	{
		printk("misc_hw_init: failed to get fpm_pool base address\n");
		return -1;
	}
	if ((rc = drv_rnr_quad_ubus_decode_wnd_cfg(DECODE_WIN1, virt_to_phys(fpm_pool_addr), log2_32(fpm_pool_size), DECODE_CFG_PID_B53, CACHE_BIT_OFF)))
	{
		printk("%s:%d: failed to configure ubus decode window: \n",__FILE__, __LINE__);
		return rc;
	}
#endif /* CONFIG_BCM_FPM_COHERENCY_EXCLUDE */
#endif /* CONFIG_BCM_GLB_COHERENCY */

    return _data_path_init(dpi_params, 0);
}

int data_path_init_basic(dpi_params_t *dpi_params)
{
    int rc;

    /* Basic data path */
    rc = _data_path_init(dpi_params, 1);

    if (rc)
        bdmf_trace("%s failed, error %d\n", __FUNCTION__, rc);
    return rc;
}


#if defined(CONFIG_DHD_RUNNER) && !defined(_CFE_)

int set_fpm_budget(int resource_num, int add)
{
    static int xepon_port_on = 0;
    static int num_of_wlan_radios = 0;
    int rc, i;
    int dhd_rx_post_fpm, fpm_exclusive_thresh;
    int fpm_thr[NUM_OF_FPM_UG];
    qm_fpm_ug_thr fpm_ug_thr;

    if (resource_num == FPM_RES_XEPON)
    {
        if (add)
          xepon_port_on = 1;
        else
          xepon_port_on = 0;
    }

    if (resource_num == FPM_RES_WLAN)
    {
        if (add)
          num_of_wlan_radios++;
        else
          num_of_wlan_radios--;
    }

    /* in case no WLAN default configuration will apply */
    if (!num_of_wlan_radios)
    {
        dhd_rx_post_fpm = 0;
        fpm_thr[FPM_DS_UG] = DS_FPM_UG_DEFAULT;
        fpm_thr[FPM_US_UG] = US_FPM_UG_DEFAULT;
        fpm_thr[FPM_WLAN_UG] = WLAN_FPM_UG_DEFAULT;  
    }
    else
    {
        /* number of 256 byte fpm = 8*(DHD_RX_POST_FLOW_RING_SIZE-1), fpm_token_size_asr_8 is a multiples of 256 */
        dhd_rx_post_fpm = num_of_wlan_radios*8*(DHD_RX_POST_FLOW_RING_SIZE-1)/g_fpm_hw_cfg.fpm_token_size_asr_8;
    
        if (xepon_port_on)
        {
            fpm_thr[FPM_DS_UG] = DS_FPM_UG_XEPON;
            fpm_thr[FPM_US_UG] = US_FPM_UG_XEPON;
            fpm_thr[FPM_WLAN_UG] = WLAN_FPM_UG_XEPON - dhd_rx_post_fpm;
        }
        else
        {
            fpm_thr[FPM_DS_UG] = DS_FPM_UG_NO_XEPON;
            fpm_thr[FPM_US_UG] = US_FPM_UG_NO_XEPON;
            fpm_thr[FPM_WLAN_UG] = WLAN_FPM_UG_NO_XEPON - dhd_rx_post_fpm;
        }
    }
    
    fpm_exclusive_thresh = TOTAL_FPM_TOKENS - fpm_thr[FPM_DS_UG] - fpm_thr[FPM_US_UG] - (fpm_thr[FPM_WLAN_UG] + dhd_rx_post_fpm);

    BUG_ON(fpm_exclusive_thresh < 0);
    BUG_ON(fpm_thr[FPM_WLAN_UG] < 0);

    /* last group is all pass - does not change*/
    for (i = 0; i < NUM_OF_FPM_UG - 1; i++)
    {
        fpm_ug_thr.lower_thr = fpm_ug_thr.mid_thr = fpm_ug_thr.higher_thr = fpm_thr[i];
        rc = ag_drv_qm_fpm_ug_thr_set(i, &fpm_ug_thr);
    }

    /* reduce from total budget consumed fpm */
    rdd_dhd_helper_fpm_thresholds_set(fpm_thr[FPM_WLAN_UG] - DHD_FPM_HIGH_PRIO_RESERVED, fpm_thr[FPM_WLAN_UG]);

    rc = rc ? rc : ag_drv_fpm_pool1_xon_xoff_cfg_set(fpm_exclusive_thresh, fpm_exclusive_thresh + 64);

    bdmf_trace("FPM group configuration set:  DS = %d, US = %d, WLAN_Tx = %d for %d radios, Exclusive threshold = %d \n", fpm_thr[FPM_DS_UG], fpm_thr[FPM_US_UG], fpm_thr[FPM_WLAN_UG], num_of_wlan_radios, fpm_exclusive_thresh);

    return rc;
}

#endif
