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

#ifndef RDP_PLATFORM_H_INCLUDED
#define RDP_PLATFORM_H_INCLUDED

#ifdef __cplusplus
extern "C"
{
#endif

#define RNR_FREQ_IN_MHZ 1400
#define UBUS_SLV_FREQ_IN_MHZ 500

/* TODO: implement */
#define IS_WAN_TX_PORT(bbh_id) (bbh_id == BBH_TX_WAN_ID)
#define IS_WAN_RX_PORT(bbh_id) (bbh_id == BBH_ID_PON)
#define IS_SDMA(dma_id)  (dma_id > DMA0_ID)
#define IS_DMA(dma_id)   (dma_id <= DMA0_ID)
#define IS_PROCESSING_RUNNER_IMAGE(i)  ((rdp_core_to_image_map[i] == processing0_runner_image) || (rdp_core_to_image_map[i] == processing1_runner_image) || (rdp_core_to_image_map[i] == processing2_runner_image) || (rdp_core_to_image_map[i] == processing3_runner_image))
#define IS_DS_TM_RUNNER_IMAGE(i)  (rdp_core_to_image_map[i] == ds_tm_runner_image)
#define IS_US_TM_RUNNER_IMAGE(i)  (rdp_core_to_image_map[i] == us_tm_runner_image)

#define MAX_NUM_OF_LLID 32
#define MAX_NUM_OF_QUEUES_IN_SCHED 32

/* NATC */
#define NATC_CACHE_ENTRIES_NUM   512

/* DISP CONGESTION */
#define DIS_REOR_CONGESTION_THRESHOLD    200
#define DIS_REOR_LINKED_LIST_BUFFER_NUM  1024
#define NUM_OF_PROCESSING_TASKS          32

/* SBPM */
#define SBPM_BASE_ADDRESS                   0
#define SBPM_INIT_OFFSET                    0x000007ff
#define SBPM_UG0_BN_THRESHOLD               0x3FF
#define SBPM_UG0_EXCL_LOW_THRESHOLD         0x384
#define SBPM_UG0_EXCL_LOW_HIST              0x14
#define SBPM_UG1_BN_THRESHOLD               0x400
#define SBPM_UG1_EXCL_LOW_THRESHOLD         0x100
#define SBPM_UG1_EXCL_LOW_HIST              0x14

/* BBH_RX */
#define DRV_BBH_RX_MAXIMAL_PACKET_HEADER_OFFSET 63
#define BBH_FREQUENCY (500*1000000) /* 500 MHz */

/* BBH_TX */
#define BBH_TX_DS_PD_FIFO_SIZE_0 7
#define BBH_TX_DS_PD_FIFO_SIZE_1 7

/* HASH */
#define HASH_NUM_OF_ENGINES           4
#define HASH_NUM_OF_ENGINES_LOG2      2
#define HASH_NUM_OF_EFFECTIVE_ENGINES 4

/* Bridge and VLAN */
#define HASH_TABLE_BRIDGE_AND_VLAN_LKP_SIZE_PER_ENGINE  hash_max_32_entries_per_engine

/* TCAM table size (entries) */
#define RDP_TCAM_TABLE_SIZE     256
/* Number of TCAM engines */
#define RDP_TCAM_NUM_ENGINES    2

/* Max number of queues supported by QM */
#define QM_NUM_QUEUES           160
/* Max number of EPON queues supported by QM */
#define QM_NUM_EPON_QUEUES      96
/* Max number of reported queues supported by QM */
#define QM_NUM_REPORTED_QUEUES  128

/*XGPON DEFS*/
/* size of each one of FIFOs 0-7 - value is size + 1*/
#define BBH_TX_XGPON_PD_FIFO_SIZE_0_7 11
#define BBH_TX_XGPON_PD_FIFO_SIZE_8_15 11
#define BBH_TX_XGPON_PD_FIFO_SIZE_16_23 11
#define BBH_TX_XGPON_PD_FIFO_SIZE_24_31 11
#define BBH_TX_XGPON_PD_FIFO_SIZE_32_39 11

#define BBH_TX_GPON_PD_FIFO_SIZE_0_7 5
#define BBH_TX_GPON_PD_FIFO_SIZE_8_15 5
#define BBH_TX_GPON_PD_FIFO_SIZE_16_23 5
#define BBH_TX_GPON_PD_FIFO_SIZE_24_31 5
#define BBH_TX_GPON_PD_FIFO_SIZE_32_39 5

/*EPON DEFS*/
#define BBH_TX_XEPON_PD_FIFO_SIZE_0_7 19
#define BBH_TX_XEPON_PD_FIFO_SIZE_8_15 19
#define BBH_TX_XEPON_PD_FIFO_SIZE_16_23 0
#define BBH_TX_XEPON_PD_FIFO_SIZE_24_31 0
#define BBH_TX_XEPON_PD_FIFO_SIZE_32_39 0

#define BBH_TX_EPON_PD_FIFO_SIZE_0_7 5
#define BBH_TX_EPON_PD_FIFO_SIZE_8_15 5
#define BBH_TX_EPON_PD_FIFO_SIZE_16_23 0
#define BBH_TX_EPON_PD_FIFO_SIZE_24_31 0
#define BBH_TX_EPON_PD_FIFO_SIZE_32_39 0

typedef enum dma_id_e
{
    DMA0_ID = 0,
    DMA1_ID,
    SDMA0_ID,
    SDMA1_ID,
    DMA_NUM,
    DMA_ID_FIRST = DMA0_ID,
} dma_id_e;

typedef enum bbh_id_e
{
    BBH_ID_0 = 0,
    BBH_ID_1,
    BBH_ID_2,
    BBH_ID_3,
    BBH_ID_4,
    BBH_ID_5,
    BBH_ID_PON,
    BBH_ID_NUM,
    BBH_ID_FIRST = BBH_ID_0,
    BBH_ID_LAST = BBH_ID_PON,
    BBH_ID_NULL = BBH_ID_NUM
} bbh_id_e;

typedef enum bbh_tx_id_e
{
    BBH_TX_ID_LAN = 0,
    BBH_TX_ID_PON,
    BBH_TX_ID_NUM,
    BBH_TX_ID_FIRST = BBH_TX_ID_LAN,
    BBH_TX_ID_LAST = BBH_TX_ID_PON,
    BBH_TX_ID_NULL = BBH_TX_ID_NUM
} bbh_tx_id_e;

typedef enum rnr_quad_id_e
{
    RNR_QUAD0_ID = 0,
    RNR_QUAD1_ID,
    RNR_QUAD_ID_LAST = RNR_QUAD1_ID,
    NUM_OF_RNR_QUADS = RNR_QUAD_ID_LAST + 1,
} rnr_quad_id_e;

#define NUM_OF_CORES_IN_QUAD                        4
#define DRV_PARSER_DA_FILTER_NUM                    8
#define NUM_OF_RNR_WITH_PROFILING                   8


#define DMA_U_THRESH_IN_BBH_LAN_VALUE     ( 0x3 )
#define DMA_U_THRESH_OUT_BBH_LAN_VALUE    ( 0x2 )
#define SDMA_U_THRESH_IN_BBH_LAN_VALUE    ( 0x3 )
#define SDMA_U_THRESH_OUT_BBH_LAN_VALUE   ( 0x2 )

#define DMA_U_THRESH_IN_BBH_PON_VALUE     ( 0x8 )
#define DMA_U_THRESH_OUT_BBH_PON_VALUE    ( 0x6 )
#define SDMA_U_THRESH_IN_BBH_PON_VALUE    ( 0x8 )
#define SDMA_U_THRESH_OUT_BBH_PON_VALUE   ( 0x6 )

#define DMA_STRICT_PRI_RX_BBH_LAN_VALUE   ( 0x4 )
#define DMA_STRICT_PRI_TX_BBH_LAN_VALUE   ( 0x8 )
#define SDMA_STRICT_PRI_RX_BBH_LAN_VALUE  ( 0x4 )
#define SDMA_STRICT_PRI_TX_BBH_LAN_VALUE  ( 0x8 )

#define DMA_STRICT_PRI_RX_BBH_PON_VALUE   ( 0x4 )
#define DMA_STRICT_PRI_TX_BBH_PON_VALUE   ( 0x8 )
#define SDMA_STRICT_PRI_RX_BBH_PON_VALUE  ( 0x4 )
#define SDMA_STRICT_PRI_TX_BBH_PON_VALUE  ( 0x8 )

#define DMA_RR_WEIGHT_RX_BBH_LAN_VALUE    ( 0x0 )
#define DMA_RR_WEIGHT_TX_BBH_LAN_VALUE    ( 0x0 )

#define SDMA_RR_WEIGHT_RX_BBH_LAN_VALUE   ( 0x0 )
#define SDMA_RR_WEIGHT_TX_BBH_LAN_VALUE   ( 0x0 )

#define DMA_RR_WEIGHT_RX_BBH_PON_VALUE    ( 0x0 )
#define DMA_RR_WEIGHT_TX_BBH_PON_VALUE    ( 0x0 )
#define SDMA_RR_WEIGHT_RX_BBH_PON_VALUE   ( 0x0 )
#define SDMA_RR_WEIGHT_TX_BBH_PON_VALUE   ( 0x0 )

#endif
