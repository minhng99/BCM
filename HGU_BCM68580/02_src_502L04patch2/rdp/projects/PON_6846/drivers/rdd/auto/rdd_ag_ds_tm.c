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


#include "rdd_ag_ds_tm.h"

int rdd_ag_ds_tm_scheduling_queue_descriptor_get(uint32_t _entry, rdd_scheduling_queue_descriptor_t *scheduling_queue_descriptor)
{
    if(!scheduling_queue_descriptor || _entry >= RDD_DS_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_BLOCK_TYPE_READ_G(scheduling_queue_descriptor->block_type, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_BBH_QUEUE_INDEX_READ_G(scheduling_queue_descriptor->bbh_queue_index, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_READ_G(scheduling_queue_descriptor->scheduler_index, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUEUE_BIT_MASK_READ_G(scheduling_queue_descriptor->queue_bit_mask, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_queue_descriptor_set(uint32_t _entry, rdd_scheduling_queue_descriptor_t *scheduling_queue_descriptor)
{
    if(!scheduling_queue_descriptor || _entry >= RDD_DS_TM_SCHEDULING_QUEUE_TABLE_SIZE || scheduling_queue_descriptor->bbh_queue_index >= 64 || scheduling_queue_descriptor->scheduler_index >= 128)
          return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_BLOCK_TYPE_WRITE_G(scheduling_queue_descriptor->block_type, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_BBH_QUEUE_INDEX_WRITE_G(scheduling_queue_descriptor->bbh_queue_index, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_WRITE_G(scheduling_queue_descriptor->scheduler_index, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUEUE_BIT_MASK_WRITE_G(scheduling_queue_descriptor->queue_bit_mask, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_bbh_queue_descriptor_get(uint32_t _entry, rdd_bbh_queue_descriptor_t *bbh_queue_descriptor)
{
    if(!bbh_queue_descriptor || _entry >= RDD_DS_TM_BBH_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_READ_G(bbh_queue_descriptor->scheduler_index, RDD_DS_TM_BBH_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_TYPE_READ_G(bbh_queue_descriptor->scheduler_type, RDD_DS_TM_BBH_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_bbh_queue_descriptor_set(uint32_t _entry, rdd_bbh_queue_descriptor_t *bbh_queue_descriptor)
{
    if(!bbh_queue_descriptor || _entry >= RDD_DS_TM_BBH_QUEUE_TABLE_SIZE || bbh_queue_descriptor->scheduler_index >= 128)
          return BDMF_ERR_PARM;

    RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_WRITE_G(bbh_queue_descriptor->scheduler_index, RDD_DS_TM_BBH_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_TYPE_WRITE_G(bbh_queue_descriptor->scheduler_type, RDD_DS_TM_BBH_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_queue_table_enable_set(uint32_t _entry, bdmf_boolean enable)
{
    if(_entry >= RDD_DS_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_ENABLE_WRITE_G(enable, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_queue_table_enable_get(uint32_t _entry, bdmf_boolean *enable)
{
    if(_entry >= RDD_DS_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_ENABLE_READ_G(*enable, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_queue_table_rate_limit_enable_set(uint32_t _entry, bdmf_boolean rate_limit_enable)
{
    if(_entry >= RDD_DS_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMIT_ENABLE_WRITE_G(rate_limit_enable, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_queue_table_rate_limit_enable_get(uint32_t _entry, bdmf_boolean *rate_limit_enable)
{
    if(_entry >= RDD_DS_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMIT_ENABLE_READ_G(*rate_limit_enable, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_queue_table_rate_limiter_index_set(uint32_t _entry, uint8_t rate_limiter_index)
{
    if(_entry >= RDD_DS_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMITER_INDEX_WRITE_G(rate_limiter_index, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_queue_table_rate_limiter_index_get(uint32_t _entry, uint8_t *rate_limiter_index)
{
    if(_entry >= RDD_DS_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMITER_INDEX_READ_G(*rate_limiter_index, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_queue_table_quantum_number_set(uint32_t _entry, uint8_t quantum_number)
{
    if(_entry >= RDD_DS_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUANTUM_NUMBER_WRITE_G(quantum_number, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_queue_table_quantum_number_get(uint32_t _entry, uint8_t *quantum_number)
{
    if(_entry >= RDD_DS_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUANTUM_NUMBER_READ_G(*quantum_number, RDD_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_flush_vector_set(uint32_t _entry, uint32_t bits)
{
    if(_entry >= RDD_DS_TM_SCHEDULING_FLUSH_VECTOR_SIZE)
          return BDMF_ERR_PARM;

    RDD_BYTES_4_BITS_WRITE_G(bits, RDD_DS_TM_SCHEDULING_FLUSH_VECTOR_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_flush_vector_get(uint32_t _entry, uint32_t *bits)
{
    if(_entry >= RDD_DS_TM_SCHEDULING_FLUSH_VECTOR_SIZE)
          return BDMF_ERR_PARM;

    RDD_BYTES_4_BITS_READ_G(*bits, RDD_DS_TM_SCHEDULING_FLUSH_VECTOR_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_bb_destination_table_set(uint16_t bits)
{
    RDD_BYTES_2_BITS_WRITE_G(bits, RDD_DS_TM_BB_DESTINATION_TABLE_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_bb_destination_table_get(uint16_t *bits)
{
    RDD_BYTES_2_BITS_READ_G(*bits, RDD_DS_TM_BB_DESTINATION_TABLE_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_global_flush_cfg_set(uint8_t bits)
{
    RDD_BYTE_1_BITS_WRITE_G(bits, RDD_DS_TM_SCHEDULING_GLOBAL_FLUSH_CFG_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_global_flush_cfg_get(uint8_t *bits)
{
    RDD_BYTE_1_BITS_READ_G(*bits, RDD_DS_TM_SCHEDULING_GLOBAL_FLUSH_CFG_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_first_queue_mapping_set(uint8_t bits)
{
    RDD_BYTE_1_BITS_WRITE_G(bits, RDD_DS_TM_FIRST_QUEUE_MAPPING_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_first_queue_mapping_get(uint8_t *bits)
{
    RDD_BYTE_1_BITS_READ_G(*bits, RDD_DS_TM_FIRST_QUEUE_MAPPING_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_tm_flow_cntr_table_set(uint32_t _entry, uint8_t cntr_id)
{
    if(_entry >= RDD_DS_TM_TM_FLOW_CNTR_TABLE_SIZE)
          return BDMF_ERR_PARM;

    RDD_TM_FLOW_CNTR_ENTRY_CNTR_ID_WRITE_G(cntr_id, RDD_DS_TM_TM_FLOW_CNTR_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_tm_flow_cntr_table_get(uint32_t _entry, uint8_t *cntr_id)
{
    if(_entry >= RDD_DS_TM_TM_FLOW_CNTR_TABLE_SIZE)
          return BDMF_ERR_PARM;

    RDD_TM_FLOW_CNTR_ENTRY_CNTR_ID_READ_G(*cntr_id, RDD_DS_TM_TM_FLOW_CNTR_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_basic_scheduler_table_ds_quantum_number_set(uint32_t _entry, uint8_t quantum_number)
{
    if(_entry >= RDD_BASIC_SCHEDULER_TABLE_DS_SIZE)
         return BDMF_ERR_PARM;

    RDD_BASIC_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_WRITE_G(quantum_number, RDD_BASIC_SCHEDULER_TABLE_DS_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_basic_scheduler_table_ds_quantum_number_get(uint32_t _entry, uint8_t *quantum_number)
{
    if(_entry >= RDD_BASIC_SCHEDULER_TABLE_DS_SIZE)
         return BDMF_ERR_PARM;

    RDD_BASIC_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_READ_G(*quantum_number, RDD_BASIC_SCHEDULER_TABLE_DS_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

