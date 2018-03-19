/*
   Copyright (c) 2015 Broadcom
   All Rights Reserved

    <:label-BRCM:2015:DUAL/GPL:standard

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



/* This is an automated file. Do not edit its contents. */


#include "rdd.h"
#include "ru_types.h"

#include "rdd_data_structures_auto.h"

/* >>>RDD_DS_TM_PD_FIFO_TABLE_ADDRESS_ARR */
uint32_t RDD_DS_TM_PD_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x0,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_PD_FIFO_TABLE_ADDRESS_ARR */


/* >>>RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR */
uint32_t RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x1400,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR */


/* >>>RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR */
uint32_t RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x1800,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR */


/* >>>RDD_DS_TM_TM_FLOW_CNTR_TABLE_ADDRESS_ARR */
uint32_t RDD_DS_TM_TM_FLOW_CNTR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x1d00,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_TM_FLOW_CNTR_TABLE_ADDRESS_ARR */


/* >>>RDD_DS_TM_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS_ARR */
uint32_t RDD_DS_TM_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x1d40,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS_ARR */


/* >>>RDD_REGISTERS_BUFFER_ADDRESS_ARR */
uint32_t RDD_REGISTERS_BUFFER_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x1d80,
	0xa80,
	0x1500,
};
/* <<<RDD_REGISTERS_BUFFER_ADDRESS_ARR */


/* >>>RDD_BASIC_SCHEDULER_TABLE_DS_ADDRESS_ARR */
uint32_t RDD_BASIC_SCHEDULER_TABLE_DS_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x1e00,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_BASIC_SCHEDULER_TABLE_DS_ADDRESS_ARR */


/* >>>RDD_BASIC_RATE_LIMITER_TABLE_DS_ADDRESS_ARR */
uint32_t RDD_BASIC_RATE_LIMITER_TABLE_DS_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2000,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_BASIC_RATE_LIMITER_TABLE_DS_ADDRESS_ARR */


/* >>>RDD_RUNNER_PROFILING_TRACE_BUFFER_ADDRESS_ARR */
uint32_t RDD_RUNNER_PROFILING_TRACE_BUFFER_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2800,
	0x800,
	0x1000,
};
/* <<<RDD_RUNNER_PROFILING_TRACE_BUFFER_ADDRESS_ARR */


/* >>>RDD_DS_TM_TM_ACTION_PTR_TABLE_ADDRESS_ARR */
uint32_t RDD_DS_TM_TM_ACTION_PTR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2a00,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_TM_ACTION_PTR_TABLE_ADDRESS_ARR */


/* >>>RDD_BUDGET_ALLOCATION_TIMER_VALUE_ADDRESS_ARR */
uint32_t RDD_BUDGET_ALLOCATION_TIMER_VALUE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2a22,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_BUDGET_ALLOCATION_TIMER_VALUE_ADDRESS_ARR */


/* >>>RDD_DS_TM_BB_DESTINATION_TABLE_ADDRESS_ARR */
uint32_t RDD_DS_TM_BB_DESTINATION_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2a24,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_BB_DESTINATION_TABLE_ADDRESS_ARR */


/* >>>RDD_DS_TM_SCHEDULING_GLOBAL_FLUSH_CFG_ADDRESS_ARR */
uint32_t RDD_DS_TM_SCHEDULING_GLOBAL_FLUSH_CFG_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2a26,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_SCHEDULING_GLOBAL_FLUSH_CFG_ADDRESS_ARR */


/* >>>RDD_SCHEDULING_FLUSH_GLOBAL_CFG_ADDRESS_ARR */
uint32_t RDD_SCHEDULING_FLUSH_GLOBAL_CFG_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2a27,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_SCHEDULING_FLUSH_GLOBAL_CFG_ADDRESS_ARR */


/* >>>RDD_DS_TM_BBH_TX_QUEUE_ID_TABLE_ADDRESS_ARR */
uint32_t RDD_DS_TM_BBH_TX_QUEUE_ID_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2a28,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_BBH_TX_QUEUE_ID_TABLE_ADDRESS_ARR */


/* >>>RDD_DS_TM_FLUSH_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR */
uint32_t RDD_DS_TM_FLUSH_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2a30,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_FLUSH_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR */


/* >>>RDD_TASK_IDX_ADDRESS_ARR */
uint32_t RDD_TASK_IDX_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2a3c,
	0xd3c,
	0x1364,
};
/* <<<RDD_TASK_IDX_ADDRESS_ARR */


/* >>>RDD_UPDATE_FIFO_TABLE_ADDRESS_ARR */
uint32_t RDD_UPDATE_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2a40,
	0xb80,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_UPDATE_FIFO_TABLE_ADDRESS_ARR */


/* >>>RDD_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS_ARR */
uint32_t RDD_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2a60,
	0xb40,
	0x1580,
};
/* <<<RDD_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS_ARR */


/* >>>RDD_DS_TM_SCHEDULING_FLUSH_VECTOR_ADDRESS_ARR */
uint32_t RDD_DS_TM_SCHEDULING_FLUSH_VECTOR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2a80,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_SCHEDULING_FLUSH_VECTOR_ADDRESS_ARR */


/* >>>RDD_SRAM_DUMMY_STORE_ADDRESS_ARR */
uint32_t RDD_SRAM_DUMMY_STORE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2a94,
	0xd49,
	0x15ec,
};
/* <<<RDD_SRAM_DUMMY_STORE_ADDRESS_ARR */


/* >>>RDD_DS_TM_FIRST_QUEUE_MAPPING_ADDRESS_ARR */
uint32_t RDD_DS_TM_FIRST_QUEUE_MAPPING_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2a95,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_FIRST_QUEUE_MAPPING_ADDRESS_ARR */


/* >>>RDD_DS_TM_SCHEDULING_QUEUE_AGING_VECTOR_ADDRESS_ARR */
uint32_t RDD_DS_TM_SCHEDULING_QUEUE_AGING_VECTOR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2aa0,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_SCHEDULING_QUEUE_AGING_VECTOR_ADDRESS_ARR */


/* >>>RDD_DS_TM_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_ADDRESS_ARR */
uint32_t RDD_DS_TM_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2ac0,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_ADDRESS_ARR */


/* >>>RDD_RATE_LIMITER_VALID_TABLE_DS_ADDRESS_ARR */
uint32_t RDD_RATE_LIMITER_VALID_TABLE_DS_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2ae0,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_RATE_LIMITER_VALID_TABLE_DS_ADDRESS_ARR */


/* >>>RDD_FPM_GLOBAL_CFG_ADDRESS_ARR */
uint32_t RDD_FPM_GLOBAL_CFG_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2af0,
	0xd30,
	0x1670,
};
/* <<<RDD_FPM_GLOBAL_CFG_ADDRESS_ARR */


/* >>>RDD_DS_TM_BBH_QUEUE_TABLE_ADDRESS_ARR */
uint32_t RDD_DS_TM_BBH_QUEUE_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	0x2c00,
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_TM_BBH_QUEUE_TABLE_ADDRESS_ARR */


/* >>>RDD_RX_FLOW_TABLE_ADDRESS_ARR */
uint32_t RDD_RX_FLOW_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0x0,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_RX_FLOW_TABLE_ADDRESS_ARR */


/* >>>RDD_DS_CPU_RX_METER_TABLE_ADDRESS_ARR */
uint32_t RDD_DS_CPU_RX_METER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0x280,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_CPU_RX_METER_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_RING_INTERRUPT_COUNTER_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_RING_INTERRUPT_COUNTER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0x300,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_RING_INTERRUPT_COUNTER_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0x390,
	0x15b0,
};
/* <<<RDD_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_ADDRESS_ARR */


/* >>>RDD_DIRECT_PROCESSING_PD_TABLE_ADDRESS_ARR */
uint32_t RDD_DIRECT_PROCESSING_PD_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0x3a0,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DIRECT_PROCESSING_PD_TABLE_ADDRESS_ARR */


/* >>>RDD_DS_CPU_REASON_TO_METER_TABLE_ADDRESS_ARR */
uint32_t RDD_DS_CPU_REASON_TO_METER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0x3c0,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DS_CPU_REASON_TO_METER_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_RX_SCRATCHPAD_ADDRESS_ARR */
uint32_t RDD_CPU_RX_SCRATCHPAD_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0x400,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_RX_SCRATCHPAD_ADDRESS_ARR */


/* >>>RDD_CPU_RECYCLE_SRAM_PD_FIFO_ADDRESS_ARR */
uint32_t RDD_CPU_RECYCLE_SRAM_PD_FIFO_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0x600,
	0x1400,
};
/* <<<RDD_CPU_RECYCLE_SRAM_PD_FIFO_ADDRESS_ARR */


/* >>>RDD_US_CPU_RX_METER_TABLE_ADDRESS_ARR */
uint32_t RDD_US_CPU_RX_METER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0x700,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_US_CPU_RX_METER_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_REASON_AND_VPORT_TO_METER_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_REASON_AND_VPORT_TO_METER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0x780,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_REASON_AND_VPORT_TO_METER_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_ADDRESS_ARR */
uint32_t RDD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0x7f8,
	0x1368,
};
/* <<<RDD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_ADDRESS_ARR */


/* >>>RDD_CPU_RX_COPY_PD_FIFO_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_RX_COPY_PD_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xa00,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_RX_COPY_PD_FIFO_TABLE_ADDRESS_ARR */


/* >>>RDD_US_CPU_REASON_TO_METER_TABLE_ADDRESS_ARR */
uint32_t RDD_US_CPU_REASON_TO_METER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xa40,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_US_CPU_REASON_TO_METER_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_VPORT_TO_METER_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_VPORT_TO_METER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xb00,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_VPORT_TO_METER_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_RX_INTERRUPT_ID_DDR_ADDR_ADDRESS_ARR */
uint32_t RDD_CPU_RX_INTERRUPT_ID_DDR_ADDR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xb28,
	0x1660,
};
/* <<<RDD_CPU_RX_INTERRUPT_ID_DDR_ADDR_ADDRESS_ARR */


/* >>>RDD_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_ADDRESS_ARR */
uint32_t RDD_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xb30,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_ADDRESS_ARR */


/* >>>RDD_SCRATCH_ADDRESS_ARR */
uint32_t RDD_SCRATCH_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xb60,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_SCRATCH_ADDRESS_ARR */


/* >>>RDD_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xba0,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_RX_INTERRUPT_SCRATCH_ADDRESS_ARR */
uint32_t RDD_CPU_RX_INTERRUPT_SCRATCH_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xbac,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_RX_INTERRUPT_SCRATCH_ADDRESS_ARR */


/* >>>RDD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xbb0,
	0x1620,
};
/* <<<RDD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_RX_COPY_UPDATE_FIFO_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_RX_COPY_UPDATE_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xbc0,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_RX_COPY_UPDATE_FIFO_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xbe0,
	0x1630,
};
/* <<<RDD_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_INTERRUPT_COALESCING_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_INTERRUPT_COALESCING_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xbf0,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_INTERRUPT_COALESCING_TABLE_ADDRESS_ARR */


/* >>>RDD_PD_FIFO_TABLE_ADDRESS_ARR */
uint32_t RDD_PD_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xc00,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_PD_FIFO_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_REASON_TO_TC_ADDRESS_ARR */
uint32_t RDD_CPU_REASON_TO_TC_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xc20,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_REASON_TO_TC_ADDRESS_ARR */


/* >>>RDD_TC_TO_CPU_RXQ_ADDRESS_ARR */
uint32_t RDD_TC_TO_CPU_RXQ_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xc60,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_TC_TO_CPU_RXQ_ADDRESS_ARR */


/* >>>RDD_EXC_TC_TO_CPU_RXQ_ADDRESS_ARR */
uint32_t RDD_EXC_TC_TO_CPU_RXQ_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xca0,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_EXC_TC_TO_CPU_RXQ_ADDRESS_ARR */


/* >>>RDD_CPU_FEED_RING_DESCRIPTOR_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_FEED_RING_DESCRIPTOR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xce0,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_FEED_RING_DESCRIPTOR_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_RX_LOCAL_SCRATCH_ADDRESS_ARR */
uint32_t RDD_CPU_RX_LOCAL_SCRATCH_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xcf0,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_RX_LOCAL_SCRATCH_ADDRESS_ARR */


/* >>>RDD_VPORT_TO_CPU_OBJ_ADDRESS_ARR */
uint32_t RDD_VPORT_TO_CPU_OBJ_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xd00,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_VPORT_TO_CPU_OBJ_ADDRESS_ARR */


/* >>>RDD_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xd28,
	0x1668,
};
/* <<<RDD_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_RX_COPY_LOCAL_SCRATCH_ADDRESS_ARR */
uint32_t RDD_CPU_RX_COPY_LOCAL_SCRATCH_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xd40,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_RX_COPY_LOCAL_SCRATCH_ADDRESS_ARR */


/* >>>RDD_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_ADDRESS_ARR */
uint32_t RDD_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xd48,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_ADDRESS_ARR */


/* >>>RDD_CPU_FEED_RING_INTERRUPT_THRESHOLD_ADDRESS_ARR */
uint32_t RDD_CPU_FEED_RING_INTERRUPT_THRESHOLD_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xd4a,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_FEED_RING_INTERRUPT_THRESHOLD_ADDRESS_ARR */


/* >>>RDD_CPU_FEED_RING_INTERRUPT_COUNTER_ADDRESS_ARR */
uint32_t RDD_CPU_FEED_RING_INTERRUPT_COUNTER_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xd4c,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_FEED_RING_INTERRUPT_COUNTER_ADDRESS_ARR */


/* >>>RDD_MAC_TYPE_ADDRESS_ARR */
uint32_t RDD_MAC_TYPE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xd4e,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_MAC_TYPE_ADDRESS_ARR */


/* >>>RDD_CPU_RECYCLE_INTERRUPT_SCRATCH_ADDRESS_ARR */
uint32_t RDD_CPU_RECYCLE_INTERRUPT_SCRATCH_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xd80,
	0x1700,
};
/* <<<RDD_CPU_RECYCLE_INTERRUPT_SCRATCH_ADDRESS_ARR */


/* >>>RDD_CPU_RECYCLE_SHADOW_RD_IDX_ADDRESS_ARR */
uint32_t RDD_CPU_RECYCLE_SHADOW_RD_IDX_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xe00,
	0x1780,
};
/* <<<RDD_CPU_RECYCLE_SHADOW_RD_IDX_ADDRESS_ARR */


/* >>>RDD_CPU_RECYCLE_SHADOW_WR_IDX_ADDRESS_ARR */
uint32_t RDD_CPU_RECYCLE_SHADOW_WR_IDX_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0xe80,
	0x1800,
};
/* <<<RDD_CPU_RECYCLE_SHADOW_WR_IDX_ADDRESS_ARR */


/* >>>RDD_CPU_RING_DESCRIPTORS_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_RING_DESCRIPTORS_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	0x3000,
	INVALID_TABLE_ADDRESS,
};
/* <<<RDD_CPU_RING_DESCRIPTORS_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_TX_SCRATCHPAD_ADDRESS_ARR */
uint32_t RDD_CPU_TX_SCRATCHPAD_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
	0x0,
};
/* <<<RDD_CPU_TX_SCRATCHPAD_ADDRESS_ARR */


/* >>>RDD_TX_FLOW_TABLE_ADDRESS_ARR */
uint32_t RDD_TX_FLOW_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
	0x1200,
};
/* <<<RDD_TX_FLOW_TABLE_ADDRESS_ARR */


/* >>>RDD_QUEUE_THRESHOLD_VECTOR_ADDRESS_ARR */
uint32_t RDD_QUEUE_THRESHOLD_VECTOR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
	0x1340,
};
/* <<<RDD_QUEUE_THRESHOLD_VECTOR_ADDRESS_ARR */


/* >>>RDD_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
	0x1370,
};
/* <<<RDD_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_TX_RING_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_TX_RING_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
	0x1380,
};
/* <<<RDD_CPU_TX_RING_TABLE_ADDRESS_ARR */


/* >>>RDD_FPM_REPLY_ADDRESS_ARR */
uint32_t RDD_FPM_REPLY_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
	0x15a0,
};
/* <<<RDD_FPM_REPLY_ADDRESS_ARR */


/* >>>RDD_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
	0x15c0,
};
/* <<<RDD_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
	0x15e0,
};
/* <<<RDD_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
	0x15f0,
};
/* <<<RDD_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
	0x1600,
};
/* <<<RDD_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_TX_EGRESS_PD_FIFO_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_TX_EGRESS_PD_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
	0x1640,
};
/* <<<RDD_CPU_TX_EGRESS_PD_FIFO_TABLE_ADDRESS_ARR */


/* >>>RDD_CPU_TX_INGRESS_PD_FIFO_TABLE_ADDRESS_ARR */
uint32_t RDD_CPU_TX_INGRESS_PD_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM] = {
	INVALID_TABLE_ADDRESS,
	INVALID_TABLE_ADDRESS,
	0x1680,
};
/* <<<RDD_CPU_TX_INGRESS_PD_FIFO_TABLE_ADDRESS_ARR */

