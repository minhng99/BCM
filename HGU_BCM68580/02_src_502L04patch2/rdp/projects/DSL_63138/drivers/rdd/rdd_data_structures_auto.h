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


#ifndef _RDD_DATA_STRUCTURES_AUTO_H
#define _RDD_DATA_STRUCTURES_AUTO_H

/* PRIVATE_A */
#define RDD_IH_BUFFER_RESERVED_FW_ONLY_NUMBER	64

typedef struct
{
	uint32_t	reserved_fw_only[RDD_IH_BUFFER_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IH_BUFFER_DTS;

#if defined DSL_63138

#define RDD_INGRESS_HANDLER_BUFFER_SIZE     32
typedef struct
{
	RDD_IH_BUFFER_DTS	entry[ RDD_INGRESS_HANDLER_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_HANDLER_BUFFER_DTS;

#define RDD_INGRESS_HANDLER_BUFFER_PTR()	( RDD_INGRESS_HANDLER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + INGRESS_HANDLER_BUFFER_ADDRESS )

#endif

typedef struct
{
	uint32_t	reserved0                     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	next_packet_descriptor_pointer	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PACKET_DESCRIPTOR_DTS;

#define RDD_PACKET_DESCRIPTOR_NEXT_PACKET_DESCRIPTOR_POINTER_READ(r, p)                 MREAD_16((uint8_t *)p + 6, r)
#define RDD_PACKET_DESCRIPTOR_NEXT_PACKET_DESCRIPTOR_POINTER_WRITE(v, p)                MWRITE_16((uint8_t *)p + 6, v)
#if defined DSL_63138

typedef struct
{
	uint32_t	crc_calc          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wan_port_or_fstat 	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_bridge_port	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length     	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	absolute_normal   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	last_indication   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pti               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	_1588             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	add_indication    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	header_number     	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_offset    	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_memory     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_location   	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = packet_location, size = 15 bits
	uint32_t	buffer_number     	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs_address_index 	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_DESCRIPTOR_DTS;

#define RDD_BBH_TX_DESCRIPTOR_CRC_CALC_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_CRC_CALC_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_WAN_PORT_OR_FSTAT_READ(r, p)                  FIELD_MREAD_16((uint8_t *)p, 3, 12, r)
#define RDD_BBH_TX_DESCRIPTOR_WAN_PORT_OR_FSTAT_WRITE(v, p)                 FIELD_MWRITE_16((uint8_t *)p, 3, 12, v)
#define RDD_BBH_TX_DESCRIPTOR_SOURCE_BRIDGE_PORT_READ(r, p)                 FIELD_MREAD_32((uint8_t *)p + 0, 14, 5, r)
#define RDD_BBH_TX_DESCRIPTOR_SOURCE_BRIDGE_PORT_WRITE(v, p)                FIELD_MWRITE_32((uint8_t *)p + 0, 14, 5, v)
#define RDD_BBH_TX_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 2, 0, 14, r)
#define RDD_BBH_TX_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 2, 0, 14, v)
#define RDD_BBH_TX_DESCRIPTOR_ABSOLUTE_NORMAL_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_ABSOLUTE_NORMAL_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_LAST_INDICATION_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_LAST_INDICATION_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_PTI_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 4, 4, 2, r)
#define RDD_BBH_TX_DESCRIPTOR_PTI_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 4, 4, 2, v)
#define RDD_BBH_TX_DESCRIPTOR__1588_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 4, 3, 1, r)
#define RDD_BBH_TX_DESCRIPTOR__1588_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 4, 3, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_ADD_INDICATION_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 4, 2, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_ADD_INDICATION_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 4, 2, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_HEADER_NUMBER_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 4, 7, 3, r)
#define RDD_BBH_TX_DESCRIPTOR_HEADER_NUMBER_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 4, 7, 3, v)
#define RDD_BBH_TX_DESCRIPTOR_PAYLOAD_OFFSET_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 5, 0, 7, r)
#define RDD_BBH_TX_DESCRIPTOR_PAYLOAD_OFFSET_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 5, 0, 7, v)
#define RDD_BBH_TX_DESCRIPTOR_TARGET_MEMORY_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 6, 7, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_TARGET_MEMORY_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 6, 7, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_PACKET_LOCATION_READ(r, p)                    FIELD_MREAD_16((uint8_t *)p + 6, 0, 15, r)
#define RDD_BBH_TX_DESCRIPTOR_PACKET_LOCATION_WRITE(v, p)                   FIELD_MWRITE_16((uint8_t *)p + 6, 0, 15, v)
#define RDD_BBH_TX_DESCRIPTOR_BUFFER_NUMBER_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 6, 0, 15, r)
#define RDD_BBH_TX_DESCRIPTOR_BUFFER_NUMBER_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 6, 0, 15, v)
#define RDD_BBH_TX_DESCRIPTOR_ABS_ADDRESS_INDEX_READ(r, p)                  FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_BBH_TX_DESCRIPTOR_ABS_ADDRESS_INDEX_WRITE(v, p)                 FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#endif

typedef struct
{
	uint32_t	union_field1          	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = union_field1, size = 15 bits
	uint32_t	next_packet_descriptor	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0             	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1             	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	egress_port           	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length         	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	absolute_normal       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	multicast_ssid        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wred_bit              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_queue              	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	header_number         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_offset        	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_memory         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	buffer_number         	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUE_DESCRIPTOR_DTS;

#define RDD_SERVICE_QUEUE_DESCRIPTOR_UNION_FIELD1_READ(r, p)                           FIELD_MREAD_16((uint8_t *)p, 1, 15, r)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_UNION_FIELD1_WRITE(v, p)                          FIELD_MWRITE_16((uint8_t *)p, 1, 15, v)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_NEXT_PACKET_DESCRIPTOR_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 3, 13, r)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_NEXT_PACKET_DESCRIPTOR_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 3, 13, v)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_SERVICE_QUEUE_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 1, 1, 3, r)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_SERVICE_QUEUE_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 1, 1, 3, v)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_EGRESS_PORT_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p + 0, 14, 3, r)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_EGRESS_PORT_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p + 0, 14, 3, v)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                          FIELD_MREAD_16((uint8_t *)p + 2, 0, 14, r)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                         FIELD_MWRITE_16((uint8_t *)p + 2, 0, 14, v)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_ABSOLUTE_NORMAL_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_ABSOLUTE_NORMAL_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_MULTICAST_SSID_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_MULTICAST_SSID_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_WRED_BIT_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 4, 5, 1, r)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_WRED_BIT_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 4, 5, 1, v)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_TX_QUEUE_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 4, 2, 3, r)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_TX_QUEUE_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 4, 2, 3, v)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_HEADER_NUMBER_READ(r, p)                          FIELD_MREAD_16((uint8_t *)p + 4, 7, 3, r)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_HEADER_NUMBER_WRITE(v, p)                         FIELD_MWRITE_16((uint8_t *)p + 4, 7, 3, v)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_PAYLOAD_OFFSET_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 5, 0, 7, r)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_PAYLOAD_OFFSET_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 5, 0, 7, v)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_TARGET_MEMORY_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 6, 7, 1, r)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_TARGET_MEMORY_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 6, 7, 1, v)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_BUFFER_NUMBER_READ(r, p)                          FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_SERVICE_QUEUE_DESCRIPTOR_BUFFER_NUMBER_WRITE(v, p)                         FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#define RDD_CONNECTION_CONTEXT_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER	32

typedef struct
{
	uint32_t	reserved_fw_only[RDD_CONNECTION_CONTEXT_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CONNECTION_CONTEXT_BUFFER_ENTRY_DTS;

#if defined DSL_63138

#define RDD_DS_CONNECTION_CONTEXT_BUFFER_SIZE     8
typedef struct
{
	RDD_CONNECTION_CONTEXT_BUFFER_ENTRY_DTS	entry[ RDD_DS_CONNECTION_CONTEXT_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CONNECTION_CONTEXT_BUFFER_DTS;

#define RDD_DS_CONNECTION_CONTEXT_BUFFER_PTR()	( RDD_DS_CONNECTION_CONTEXT_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CONNECTION_CONTEXT_BUFFER_ADDRESS )

#endif
#define RDD_GSO_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER	32

typedef struct
{
	uint32_t	reserved_fw_only[RDD_GSO_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_BUFFER_ENTRY_DTS;

#define RDD_GSO_PSEUDO_HEADER_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER	10

typedef struct
{
	uint32_t	reserved_fw_only[RDD_GSO_PSEUDO_HEADER_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_PSEUDO_HEADER_BUFFER_ENTRY_DTS;


typedef struct
{
	uint32_t	ssid_vector    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	chain_id       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wifi_queue     	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	headroom_size  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_bridge_port	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dma_sync       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	type           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_PARAMETERS_BLOCK_ENTRY_DTS;

#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_SSID_VECTOR_READ(r, p)                     MREAD_16((uint8_t *)p, r)
#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_SSID_VECTOR_WRITE(v, p)                    MWRITE_16((uint8_t *)p, v)
#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_CHAIN_ID_READ(r, p)                        MREAD_8((uint8_t *)p + 2, r)
#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_CHAIN_ID_WRITE(v, p)                       MWRITE_8((uint8_t *)p + 2, v)
#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_WIFI_QUEUE_READ(r, p)                      MREAD_8((uint8_t *)p + 3, r)
#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_WIFI_QUEUE_WRITE(v, p)                     MWRITE_8((uint8_t *)p + 3, v)
#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_HEADROOM_SIZE_READ(r, p)                   MREAD_8((uint8_t *)p + 4, r)
#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_HEADROOM_SIZE_WRITE(v, p)                  MWRITE_8((uint8_t *)p + 4, v)
#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_SRC_BRIDGE_PORT_READ(r, p)                 MREAD_8((uint8_t *)p + 5, r)
#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_SRC_BRIDGE_PORT_WRITE(v, p)                MWRITE_8((uint8_t *)p + 5, v)
#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_DMA_SYNC_READ(r, p)                        MREAD_8((uint8_t *)p + 6, r)
#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_DMA_SYNC_WRITE(v, p)                       MWRITE_8((uint8_t *)p + 6, v)
#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_TYPE_READ(r, p)                            MREAD_8((uint8_t *)p + 7, r)
#define RDD_CPU_PARAMETERS_BLOCK_ENTRY_TYPE_WRITE(v, p)                           MWRITE_8((uint8_t *)p + 7, v)

typedef struct
{
	uint16_t	active_rate_controllers	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BUDGET_ALLOCATOR_ENTRY_DTS;

#define RDD_BUDGET_ALLOCATOR_ENTRY_ACTIVE_RATE_CONTROLLERS_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_BUDGET_ALLOCATOR_ENTRY_ACTIVE_RATE_CONTROLLERS_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)

#define RDD_BUDGET_ALLOCATOR_TABLE_SIZE     8
typedef struct
{
	RDD_BUDGET_ALLOCATOR_ENTRY_DTS	entry[ RDD_BUDGET_ALLOCATOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BUDGET_ALLOCATOR_TABLE_DTS;

#define RDD_DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE_PTR()	( RDD_DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE_ADDRESS )


typedef struct
{
	uint8_t	cpu_meter 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_REASON_TO_METER_ENTRY_DTS;

#define RDD_CPU_REASON_TO_METER_ENTRY_CPU_METER_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_CPU_REASON_TO_METER_ENTRY_CPU_METER_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#if defined DSL_63138

#define RDD_DS_CPU_REASON_TO_METER_TABLE_SIZE     64
typedef struct
{
	RDD_CPU_REASON_TO_METER_ENTRY_DTS	entry[ RDD_DS_CPU_REASON_TO_METER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_REASON_TO_METER_TABLE_DTS;

#define RDD_DS_CPU_REASON_TO_METER_TABLE_PTR()	( RDD_DS_CPU_REASON_TO_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_REASON_TO_METER_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	head_ptr        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tail_ptr        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_counter  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_threshold	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	profile_ptr     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	queue_mask      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_id 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_SERVICE_QUEUE_DESCRIPTOR_DTS;

#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_HEAD_PTR_READ(r, p)                         MREAD_16((uint8_t *)p, r)
#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_HEAD_PTR_WRITE(v, p)                        MWRITE_16((uint8_t *)p, v)
#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_TAIL_PTR_READ(r, p)                         MREAD_16((uint8_t *)p + 2, r)
#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_TAIL_PTR_WRITE(v, p)                        MWRITE_16((uint8_t *)p + 2, v)
#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_PACKET_COUNTER_READ(r, p)                   MREAD_16((uint8_t *)p + 4, r)
#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_PACKET_COUNTER_WRITE(v, p)                  MWRITE_16((uint8_t *)p + 4, v)
#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_PACKET_THRESHOLD_READ(r, p)                 MREAD_16((uint8_t *)p + 8, r)
#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_PACKET_THRESHOLD_WRITE(v, p)                MWRITE_16((uint8_t *)p + 8, v)
#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_PROFILE_PTR_READ(r, p)                      MREAD_16((uint8_t *)p + 10, r)
#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_PROFILE_PTR_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 10, v)
#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_QUEUE_MASK_READ(r, p)                       MREAD_8((uint8_t *)p + 12, r)
#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_QUEUE_MASK_WRITE(v, p)                      MWRITE_8((uint8_t *)p + 12, v)
#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_RATE_LIMITER_ID_READ(r, p)                  MREAD_8((uint8_t *)p + 13, r)
#define RDD_DS_SERVICE_QUEUE_DESCRIPTOR_RATE_LIMITER_ID_WRITE(v, p)                 MWRITE_8((uint8_t *)p + 13, v)
#if defined DSL_63138

#define RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_SIZE     8
typedef struct
{
	RDD_DS_SERVICE_QUEUE_DESCRIPTOR_DTS	entry[ RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_DTS;

#define RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_PTR()	( RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	current_budget	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	exponent      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	commited_rate 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bucket_size   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	commited_burst	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop_counter  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_POLICER_ENTRY_DTS;

#define RDD_POLICER_ENTRY_CURRENT_BUDGET_READ(r, p)                 MREAD_32((uint8_t *)p, r)
#define RDD_POLICER_ENTRY_CURRENT_BUDGET_WRITE(v, p)                MWRITE_32((uint8_t *)p, v)
#define RDD_POLICER_ENTRY_EXPONENT_READ(r, p)                       MREAD_16((uint8_t *)p + 4, r)
#define RDD_POLICER_ENTRY_EXPONENT_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 4, v)
#define RDD_POLICER_ENTRY_COMMITED_RATE_READ(r, p)                  MREAD_16((uint8_t *)p + 6, r)
#define RDD_POLICER_ENTRY_COMMITED_RATE_WRITE(v, p)                 MWRITE_16((uint8_t *)p + 6, v)
#define RDD_POLICER_ENTRY_BUCKET_SIZE_READ(r, p)                    MREAD_16((uint8_t *)p + 10, r)
#define RDD_POLICER_ENTRY_BUCKET_SIZE_WRITE(v, p)                   MWRITE_16((uint8_t *)p + 10, v)
#define RDD_POLICER_ENTRY_COMMITED_BURST_READ(r, p)                 MREAD_16((uint8_t *)p + 12, r)
#define RDD_POLICER_ENTRY_COMMITED_BURST_WRITE(v, p)                MWRITE_16((uint8_t *)p + 12, v)
#define RDD_POLICER_ENTRY_DROP_COUNTER_READ(r, p)                   MREAD_16((uint8_t *)p + 14, r)
#define RDD_POLICER_ENTRY_DROP_COUNTER_WRITE(v, p)                  MWRITE_16((uint8_t *)p + 14, v)

#define RDD_POLICER_TABLE_SIZE     16
typedef struct
{
	RDD_POLICER_ENTRY_DTS	entry[ RDD_POLICER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_POLICER_TABLE_DTS;

#define RDD_DS_POLICER_TABLE_PTR()	( RDD_DS_POLICER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_POLICER_TABLE_ADDRESS )

#define RDD_IPSEC_DS_BUFFER_RESERVED_NUMBER	176

typedef struct
{
	uint8_t	reserved[RDD_IPSEC_DS_BUFFER_RESERVED_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_BUFFER_DTS;

#if defined DSL_63138

#define RDD_IPSEC_DS_BUFFER_POOL_SIZE     2
typedef struct
{
	RDD_IPSEC_DS_BUFFER_DTS	entry[ RDD_IPSEC_DS_BUFFER_POOL_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_BUFFER_POOL_DTS;

#define RDD_IPSEC_DS_BUFFER_POOL_PTR()	( RDD_IPSEC_DS_BUFFER_POOL_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_DS_BUFFER_POOL_ADDRESS )

#endif
#define RDD_IPSEC_SA_DESC_AUTH_KEY_NUMBER	32
#define RDD_IPSEC_SA_DESC_CRYPT_KEY_NUMBER	32

typedef struct
{
	uint32_t	spi                                              	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	eng_cfg                                          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hmac_dis                                         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	auth_key_fetch_dis                               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                                        	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	auth_alg                                         	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	nxt_hdr                                          	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	aes_key_size                                     	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	des_dec_vec                                      	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	des_iters                                        	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rng_clk_en                                       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                                        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rng_seed                                         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rng_sample_num                                   	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4                                        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	crypt_key_fetch_dis                              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	write_dis                                        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mech                                             	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	decrypt                                          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	crypt_alg                                        	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved5                                        	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	clustr_ovrrd                                     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	read_clustr_sel                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	write_clustr_sel                                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	add                                              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	auth_key[RDD_IPSEC_SA_DESC_AUTH_KEY_NUMBER];
	uint8_t	crypt_key[RDD_IPSEC_SA_DESC_CRYPT_KEY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_SA_DESC_DTS;

#define RDD_IPSEC_SA_DESC_SPI_READ(r, p)                                 MREAD_32((uint8_t *)p, r)
#define RDD_IPSEC_SA_DESC_SPI_WRITE(v, p)                                MWRITE_32((uint8_t *)p, v)
#define RDD_IPSEC_SA_DESC_SPI_L_READ( wv )                               FIELD_GET( wv, 0, 32 )
#define RDD_IPSEC_SA_DESC_SPI_L_WRITE( v, wv )                           FIELD_SET( v, 0, 32, wv )
#define RDD_IPSEC_SA_DESC_ENG_CFG_READ(r, p)                             MREAD_16((uint8_t *)p + 4, r)
#define RDD_IPSEC_SA_DESC_ENG_CFG_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 4, v)
#define RDD_IPSEC_SA_DESC_ENG_CFG_L_READ( wv )                           FIELD_GET( wv, 16, 16 )
#define RDD_IPSEC_SA_DESC_ENG_CFG_L_WRITE( v, wv )                       FIELD_SET( v, 16, 16, wv )
#define RDD_IPSEC_SA_DESC_HMAC_DIS_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 7, 7, 1, r)
#define RDD_IPSEC_SA_DESC_HMAC_DIS_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 7, 7, 1, v)
#define RDD_IPSEC_SA_DESC_HMAC_DIS_L_READ( wv )                          FIELD_GET( wv, 7, 1 )
#define RDD_IPSEC_SA_DESC_HMAC_DIS_L_WRITE( v, wv )                      FIELD_SET( v, 7, 1, wv )
#define RDD_IPSEC_SA_DESC_AUTH_KEY_FETCH_DIS_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 7, 6, 1, r)
#define RDD_IPSEC_SA_DESC_AUTH_KEY_FETCH_DIS_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 7, 6, 1, v)
#define RDD_IPSEC_SA_DESC_AUTH_KEY_FETCH_DIS_L_READ( wv )                FIELD_GET( wv, 6, 1 )
#define RDD_IPSEC_SA_DESC_AUTH_KEY_FETCH_DIS_L_WRITE( v, wv )            FIELD_SET( v, 6, 1, wv )
#define RDD_IPSEC_SA_DESC_AUTH_ALG_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 7, 0, 2, r)
#define RDD_IPSEC_SA_DESC_AUTH_ALG_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 7, 0, 2, v)
#define RDD_IPSEC_SA_DESC_AUTH_ALG_L_READ( wv )                          FIELD_GET( wv, 0, 2 )
#define RDD_IPSEC_SA_DESC_AUTH_ALG_L_WRITE( v, wv )                      FIELD_SET( v, 0, 2, wv )
#define RDD_IPSEC_SA_DESC_NXT_HDR_READ(r, p)                             MREAD_8((uint8_t *)p + 8, r)
#define RDD_IPSEC_SA_DESC_NXT_HDR_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 8, v)
#define RDD_IPSEC_SA_DESC_NXT_HDR_L_READ( wv )                           FIELD_GET( wv, 24, 8 )
#define RDD_IPSEC_SA_DESC_NXT_HDR_L_WRITE( v, wv )                       FIELD_SET( v, 24, 8, wv )
#define RDD_IPSEC_SA_DESC_AES_KEY_SIZE_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 9, 5, 3, r)
#define RDD_IPSEC_SA_DESC_AES_KEY_SIZE_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 9, 5, 3, v)
#define RDD_IPSEC_SA_DESC_AES_KEY_SIZE_L_READ( wv )                      FIELD_GET( wv, 21, 3 )
#define RDD_IPSEC_SA_DESC_AES_KEY_SIZE_L_WRITE( v, wv )                  FIELD_SET( v, 21, 3, wv )
#define RDD_IPSEC_SA_DESC_DES_DEC_VEC_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 9, 2, 3, r)
#define RDD_IPSEC_SA_DESC_DES_DEC_VEC_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 9, 2, 3, v)
#define RDD_IPSEC_SA_DESC_DES_DEC_VEC_L_READ( wv )                       FIELD_GET( wv, 18, 3 )
#define RDD_IPSEC_SA_DESC_DES_DEC_VEC_L_WRITE( v, wv )                   FIELD_SET( v, 18, 3, wv )
#define RDD_IPSEC_SA_DESC_DES_ITERS_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 9, 0, 2, r)
#define RDD_IPSEC_SA_DESC_DES_ITERS_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 9, 0, 2, v)
#define RDD_IPSEC_SA_DESC_DES_ITERS_L_READ( wv )                         FIELD_GET( wv, 16, 2 )
#define RDD_IPSEC_SA_DESC_DES_ITERS_L_WRITE( v, wv )                     FIELD_SET( v, 16, 2, wv )
#define RDD_IPSEC_SA_DESC_RNG_CLK_EN_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 10, 7, 1, r)
#define RDD_IPSEC_SA_DESC_RNG_CLK_EN_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 10, 7, 1, v)
#define RDD_IPSEC_SA_DESC_RNG_CLK_EN_L_READ( wv )                        FIELD_GET( wv, 15, 1 )
#define RDD_IPSEC_SA_DESC_RNG_CLK_EN_L_WRITE( v, wv )                    FIELD_SET( v, 15, 1, wv )
#define RDD_IPSEC_SA_DESC_RNG_SEED_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 10, 5, 1, r)
#define RDD_IPSEC_SA_DESC_RNG_SEED_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 10, 5, 1, v)
#define RDD_IPSEC_SA_DESC_RNG_SEED_L_READ( wv )                          FIELD_GET( wv, 13, 1 )
#define RDD_IPSEC_SA_DESC_RNG_SEED_L_WRITE( v, wv )                      FIELD_SET( v, 13, 1, wv )
#define RDD_IPSEC_SA_DESC_RNG_SAMPLE_NUM_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 10, 0, 5, r)
#define RDD_IPSEC_SA_DESC_RNG_SAMPLE_NUM_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 10, 0, 5, v)
#define RDD_IPSEC_SA_DESC_RNG_SAMPLE_NUM_L_READ( wv )                    FIELD_GET( wv, 8, 5 )
#define RDD_IPSEC_SA_DESC_RNG_SAMPLE_NUM_L_WRITE( v, wv )                FIELD_SET( v, 8, 5, wv )
#define RDD_IPSEC_SA_DESC_CRYPT_KEY_FETCH_DIS_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 11, 6, 1, r)
#define RDD_IPSEC_SA_DESC_CRYPT_KEY_FETCH_DIS_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 11, 6, 1, v)
#define RDD_IPSEC_SA_DESC_CRYPT_KEY_FETCH_DIS_L_READ( wv )               FIELD_GET( wv, 6, 1 )
#define RDD_IPSEC_SA_DESC_CRYPT_KEY_FETCH_DIS_L_WRITE( v, wv )           FIELD_SET( v, 6, 1, wv )
#define RDD_IPSEC_SA_DESC_WRITE_DIS_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 11, 5, 1, r)
#define RDD_IPSEC_SA_DESC_WRITE_DIS_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 11, 5, 1, v)
#define RDD_IPSEC_SA_DESC_WRITE_DIS_L_READ( wv )                         FIELD_GET( wv, 5, 1 )
#define RDD_IPSEC_SA_DESC_WRITE_DIS_L_WRITE( v, wv )                     FIELD_SET( v, 5, 1, wv )
#define RDD_IPSEC_SA_DESC_MECH_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 11, 3, 2, r)
#define RDD_IPSEC_SA_DESC_MECH_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 11, 3, 2, v)
#define RDD_IPSEC_SA_DESC_MECH_L_READ( wv )                              FIELD_GET( wv, 3, 2 )
#define RDD_IPSEC_SA_DESC_MECH_L_WRITE( v, wv )                          FIELD_SET( v, 3, 2, wv )
#define RDD_IPSEC_SA_DESC_DECRYPT_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 11, 2, 1, r)
#define RDD_IPSEC_SA_DESC_DECRYPT_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 11, 2, 1, v)
#define RDD_IPSEC_SA_DESC_DECRYPT_L_READ( wv )                           FIELD_GET( wv, 2, 1 )
#define RDD_IPSEC_SA_DESC_DECRYPT_L_WRITE( v, wv )                       FIELD_SET( v, 2, 1, wv )
#define RDD_IPSEC_SA_DESC_CRYPT_ALG_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 11, 0, 2, r)
#define RDD_IPSEC_SA_DESC_CRYPT_ALG_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 11, 0, 2, v)
#define RDD_IPSEC_SA_DESC_CRYPT_ALG_L_READ( wv )                         FIELD_GET( wv, 0, 2 )
#define RDD_IPSEC_SA_DESC_CRYPT_ALG_L_WRITE( v, wv )                     FIELD_SET( v, 0, 2, wv )
#define RDD_IPSEC_SA_DESC_CLUSTR_OVRRD_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 13, 2, 1, r)
#define RDD_IPSEC_SA_DESC_CLUSTR_OVRRD_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 13, 2, 1, v)
#define RDD_IPSEC_SA_DESC_CLUSTR_OVRRD_L_READ( wv )                      FIELD_GET( wv, 18, 1 )
#define RDD_IPSEC_SA_DESC_CLUSTR_OVRRD_L_WRITE( v, wv )                  FIELD_SET( v, 18, 1, wv )
#define RDD_IPSEC_SA_DESC_READ_CLUSTR_SEL_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 13, 1, 1, r)
#define RDD_IPSEC_SA_DESC_READ_CLUSTR_SEL_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 13, 1, 1, v)
#define RDD_IPSEC_SA_DESC_READ_CLUSTR_SEL_L_READ( wv )                   FIELD_GET( wv, 17, 1 )
#define RDD_IPSEC_SA_DESC_READ_CLUSTR_SEL_L_WRITE( v, wv )               FIELD_SET( v, 17, 1, wv )
#define RDD_IPSEC_SA_DESC_WRITE_CLUSTR_SEL_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 13, 0, 1, r)
#define RDD_IPSEC_SA_DESC_WRITE_CLUSTR_SEL_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 13, 0, 1, v)
#define RDD_IPSEC_SA_DESC_WRITE_CLUSTR_SEL_L_READ( wv )                  FIELD_GET( wv, 16, 1 )
#define RDD_IPSEC_SA_DESC_WRITE_CLUSTR_SEL_L_WRITE( v, wv )              FIELD_SET( v, 16, 1, wv )
#define RDD_IPSEC_SA_DESC_ADD_READ(r, p)                                 MREAD_16((uint8_t *)p + 14, r)
#define RDD_IPSEC_SA_DESC_ADD_WRITE(v, p)                                MWRITE_16((uint8_t *)p + 14, v)
#define RDD_IPSEC_SA_DESC_ADD_L_READ( wv )                               FIELD_GET( wv, 0, 16 )
#define RDD_IPSEC_SA_DESC_ADD_L_WRITE( v, wv )                           FIELD_SET( v, 0, 16, wv )
#define RDD_IPSEC_SA_DESC_AUTH_KEY_READ(r, p, i)                         MREAD_I_8((uint8_t *)p + 16, i, r)
#define RDD_IPSEC_SA_DESC_AUTH_KEY_WRITE(v, p, i)                        MWRITE_I_8((uint8_t *)p + 16, i, v)
#define RDD_IPSEC_SA_DESC_CRYPT_KEY_READ(r, p, i)                        MREAD_I_8((uint8_t *)p + 48, i, r)
#define RDD_IPSEC_SA_DESC_CRYPT_KEY_WRITE(v, p, i)                       MWRITE_I_8((uint8_t *)p + 48, i, v)
#if defined DSL_63138

#define RDD_IPSEC_DS_SA_DESC_TABLE_SIZE     16
typedef struct
{
	RDD_IPSEC_SA_DESC_DTS	entry[ RDD_IPSEC_DS_SA_DESC_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_SA_DESC_TABLE_DTS;

#define RDD_IPSEC_DS_SA_DESC_TABLE_PTR()	( RDD_IPSEC_DS_SA_DESC_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_DS_SA_DESC_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_IPSEC_US_SA_DESC_TABLE_SIZE     16
typedef struct
{
	RDD_IPSEC_SA_DESC_DTS	entry[ RDD_IPSEC_US_SA_DESC_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_US_SA_DESC_TABLE_DTS;

#define RDD_IPSEC_US_SA_DESC_TABLE_PTR()	( RDD_IPSEC_US_SA_DESC_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_US_SA_DESC_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	current_peak_budget           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocated_peak_budget_exponent	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocated_peak_budget         	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_budget_limit_exponent    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_budget_limit             	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	current_sustain_budget        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocated_sustain_budget      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_mask             	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_burst_counter            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_weight                   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0                     	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_burst_flag               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_DTS;

#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_CURRENT_PEAK_BUDGET_READ(r, p)                            MREAD_32((uint8_t *)p, r)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_CURRENT_PEAK_BUDGET_WRITE(v, p)                           MWRITE_32((uint8_t *)p, v)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_ALLOCATED_PEAK_BUDGET_EXPONENT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 4, 6, 2, r)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_ALLOCATED_PEAK_BUDGET_EXPONENT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 4, 6, 2, v)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_ALLOCATED_PEAK_BUDGET_READ(r, p)                          FIELD_MREAD_16((uint8_t *)p + 4, 0, 14, r)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_ALLOCATED_PEAK_BUDGET_WRITE(v, p)                         FIELD_MWRITE_16((uint8_t *)p + 4, 0, 14, v)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_BUDGET_LIMIT_EXPONENT_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 6, 6, 2, r)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_BUDGET_LIMIT_EXPONENT_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 6, 6, 2, v)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_BUDGET_LIMIT_READ(r, p)                              FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_BUDGET_LIMIT_WRITE(v, p)                             FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_CURRENT_SUSTAIN_BUDGET_READ(r, p)                         MREAD_32((uint8_t *)p + 8, r)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_CURRENT_SUSTAIN_BUDGET_WRITE(v, p)                        MWRITE_32((uint8_t *)p + 8, v)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_ALLOCATED_SUSTAIN_BUDGET_READ(r, p)                       MREAD_32((uint8_t *)p + 12, r)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_ALLOCATED_SUSTAIN_BUDGET_WRITE(v, p)                      MWRITE_32((uint8_t *)p + 12, v)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_RATE_LIMITER_MASK_READ(r, p)                              MREAD_32((uint8_t *)p + 16, r)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_RATE_LIMITER_MASK_WRITE(v, p)                             MWRITE_32((uint8_t *)p + 16, v)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_BURST_COUNTER_READ(r, p)                             MREAD_16((uint8_t *)p + 20, r)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_BURST_COUNTER_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 20, v)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_WEIGHT_READ(r, p)                                    MREAD_8((uint8_t *)p + 22, r)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_WEIGHT_WRITE(v, p)                                   MWRITE_8((uint8_t *)p + 22, v)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_BURST_FLAG_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 23, 0, 1, r)
#define RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_BURST_FLAG_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 23, 0, 1, v)
#if defined DSL_63138

#define RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_SIZE     32
typedef struct
{
	RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_DTS	entry[ RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_DTS;

#define RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_PTR()	( RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + SERVICE_QUEUES_RATE_LIMITER_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	period        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	counter_reload	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	firmware_ptr  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TIMER_TASK_DESCRIPTOR_ENTRY_DTS;

#define RDD_TIMER_TASK_DESCRIPTOR_ENTRY_PERIOD_READ(r, p)                         MREAD_8((uint8_t *)p, r)
#define RDD_TIMER_TASK_DESCRIPTOR_ENTRY_PERIOD_WRITE(v, p)                        MWRITE_8((uint8_t *)p, v)
#define RDD_TIMER_TASK_DESCRIPTOR_ENTRY_COUNTER_RELOAD_READ(r, p)                 MREAD_8((uint8_t *)p + 1, r)
#define RDD_TIMER_TASK_DESCRIPTOR_ENTRY_COUNTER_RELOAD_WRITE(v, p)                MWRITE_8((uint8_t *)p + 1, v)
#define RDD_TIMER_TASK_DESCRIPTOR_ENTRY_FIRMWARE_PTR_READ(r, p)                   MREAD_16((uint8_t *)p + 2, r)
#define RDD_TIMER_TASK_DESCRIPTOR_ENTRY_FIRMWARE_PTR_WRITE(v, p)                  MWRITE_16((uint8_t *)p + 2, v)

#define RDD_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_SIZE     4
typedef struct
{
	RDD_TIMER_TASK_DESCRIPTOR_ENTRY_DTS	entry[ RDD_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_DTS;

#define RDD_DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_PTR()	( RDD_DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS )


typedef struct
{
	uint32_t	union_field1                    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = union_field1, size = 32 bits
	uint32_t	register_r9                     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	emac_descriptor_ptr             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0                       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	union_field2                    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = union_field2, size = 32 bits
	uint32_t	register_r11                    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	eth_tx_queues_pointers_table_ptr	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_destination                 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_DTS;

#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_UNION_FIELD1_READ(r, p)                                     MREAD_32((uint8_t *)p, r)
#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_UNION_FIELD1_WRITE(v, p)                                    MWRITE_32((uint8_t *)p, v)
#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_REGISTER_R9_READ(r, p)                                      MREAD_32((uint8_t *)p, r)
#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_REGISTER_R9_WRITE(v, p)                                     MWRITE_32((uint8_t *)p, v)
#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_EMAC_DESCRIPTOR_PTR_READ(r, p)                              MREAD_16((uint8_t *)p, r)
#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_EMAC_DESCRIPTOR_PTR_WRITE(v, p)                             MWRITE_16((uint8_t *)p, v)
#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_UNION_FIELD2_READ(r, p)                                     MREAD_32((uint8_t *)p + 4, r)
#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_UNION_FIELD2_WRITE(v, p)                                    MWRITE_32((uint8_t *)p + 4, v)
#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_REGISTER_R11_READ(r, p)                                     MREAD_32((uint8_t *)p + 4, r)
#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_REGISTER_R11_WRITE(v, p)                                    MWRITE_32((uint8_t *)p + 4, v)
#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_ETH_TX_QUEUES_POINTERS_TABLE_PTR_READ(r, p)                 MREAD_16((uint8_t *)p + 4, r)
#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_ETH_TX_QUEUES_POINTERS_TABLE_PTR_WRITE(v, p)                MWRITE_16((uint8_t *)p + 4, v)
#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_BBH_DESTINATION_READ(r, p)                                  MREAD_16((uint8_t *)p + 6, r)
#define RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_BBH_DESTINATION_WRITE(v, p)                                 MWRITE_16((uint8_t *)p + 6, v)
#if defined DSL_63138

#define RDD_ETH_TX_LOCAL_REGISTERS_SIZE     9
typedef struct
{
	RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_DTS	entry[ RDD_ETH_TX_LOCAL_REGISTERS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_LOCAL_REGISTERS_DTS;

#define RDD_ETH_TX_LOCAL_REGISTERS_PTR()	( RDD_ETH_TX_LOCAL_REGISTERS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_LOCAL_REGISTERS_ADDRESS )

#endif
#define RDD_RUNNER_FLOW_HEADER_DESCRIPTOR_RESERVED_FW_ONLY_NUMBER	2

typedef struct
{
	uint32_t	reserved_fw_only[RDD_RUNNER_FLOW_HEADER_DESCRIPTOR_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FLOW_HEADER_DESCRIPTOR_DTS;


typedef struct
{
	uint16_t	primitive_address	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY_DTS;

#define RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY_PRIMITIVE_ADDRESS_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY_PRIMITIVE_ADDRESS_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)
#if defined DSL_63138

#define RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_SIZE     8
typedef struct
{
	RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY_DTS	entry[ RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_DTS;

#define RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_PTR()	( RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_ADDRESS )

#endif
#define RDD_EIGHT_BYTES_RESERVED_FW_ONLY_NUMBER	2

typedef struct
{
	uint32_t	reserved_fw_only[RDD_EIGHT_BYTES_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EIGHT_BYTES_DTS;

#if defined DSL_63138

#define RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_SIZE     32
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_DTS;

#define RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_PTR()	( RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_MAIN_PROFILING_BUFFER_RUNNER_ADDRESS )

#endif

#define RDD_PICO_TIMER_TASK_DESCRIPTOR_TABLE_SIZE     4
typedef struct
{
	RDD_TIMER_TASK_DESCRIPTOR_ENTRY_DTS	entry[ RDD_PICO_TIMER_TASK_DESCRIPTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PICO_TIMER_TASK_DESCRIPTOR_TABLE_DTS;

#define RDD_DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE_PTR()	( RDD_DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS )

#define RDD_WLAN_MCAST_CONTROL_ENTRY_DHD_LIST_TABLE_NUMBER	64

typedef struct
{
	uint32_t	bbh_descriptor_0                                                      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_descriptor_1                                                      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_buffer_0                                                           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_buffer_1                                                           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_buffer_2                                                           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_buffer_3                                                           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_buffer_4                                                           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_buffer_5                                                           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ingress_queue_write_ptr                                               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bpm_buffer_number_0                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bpm_buffer_number_1                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bpm_buffer_number_2                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bpm_buffer_number_3                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bpm_buffer_address_0                                                  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bpm_buffer_address_1                                                  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bpm_buffer_address_2                                                  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bpm_buffer_address_3                                                  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	request_id                                                            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_buf_ptr                                                          	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dhd_list_base_address                                                 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ingress_queue_pd_write_ptr                                            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ingress_queue_pd_read_ptr                                             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_proxy_enabled                                                      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dhd_list_size                                                         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dhd_list_ptr                                                          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	dhd_list_table[RDD_WLAN_MCAST_CONTROL_ENTRY_DHD_LIST_TABLE_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_CONTROL_ENTRY_DTS;

#define RDD_WLAN_MCAST_CONTROL_ENTRY_BBH_DESCRIPTOR_0_READ(r, p)                           MREAD_32((uint8_t *)p, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BBH_DESCRIPTOR_0_WRITE(v, p)                          MWRITE_32((uint8_t *)p, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BBH_DESCRIPTOR_1_READ(r, p)                           MREAD_32((uint8_t *)p + 4, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BBH_DESCRIPTOR_1_WRITE(v, p)                          MWRITE_32((uint8_t *)p + 4, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_L2_BUFFER_0_READ(r, p)                                MREAD_32((uint8_t *)p + 8, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_L2_BUFFER_0_WRITE(v, p)                               MWRITE_32((uint8_t *)p + 8, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_L2_BUFFER_1_READ(r, p)                                MREAD_32((uint8_t *)p + 12, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_L2_BUFFER_1_WRITE(v, p)                               MWRITE_32((uint8_t *)p + 12, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_L2_BUFFER_2_READ(r, p)                                MREAD_32((uint8_t *)p + 16, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_L2_BUFFER_2_WRITE(v, p)                               MWRITE_32((uint8_t *)p + 16, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_L2_BUFFER_3_READ(r, p)                                MREAD_32((uint8_t *)p + 20, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_L2_BUFFER_3_WRITE(v, p)                               MWRITE_32((uint8_t *)p + 20, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_L2_BUFFER_4_READ(r, p)                                MREAD_32((uint8_t *)p + 24, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_L2_BUFFER_4_WRITE(v, p)                               MWRITE_32((uint8_t *)p + 24, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_L2_BUFFER_5_READ(r, p)                                MREAD_16((uint8_t *)p + 28, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_L2_BUFFER_5_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 28, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_INGRESS_QUEUE_WRITE_PTR_READ(r, p)                    MREAD_16((uint8_t *)p + 30, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_INGRESS_QUEUE_WRITE_PTR_WRITE(v, p)                   MWRITE_16((uint8_t *)p + 30, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_NUMBER_0_READ(r, p)                        MREAD_32((uint8_t *)p + 32, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_NUMBER_0_WRITE(v, p)                       MWRITE_32((uint8_t *)p + 32, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_NUMBER_1_READ(r, p)                        MREAD_32((uint8_t *)p + 36, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_NUMBER_1_WRITE(v, p)                       MWRITE_32((uint8_t *)p + 36, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_NUMBER_2_READ(r, p)                        MREAD_32((uint8_t *)p + 40, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_NUMBER_2_WRITE(v, p)                       MWRITE_32((uint8_t *)p + 40, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_NUMBER_3_READ(r, p)                        MREAD_32((uint8_t *)p + 44, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_NUMBER_3_WRITE(v, p)                       MWRITE_32((uint8_t *)p + 44, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_ADDRESS_0_READ(r, p)                       MREAD_32((uint8_t *)p + 48, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_ADDRESS_0_WRITE(v, p)                      MWRITE_32((uint8_t *)p + 48, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_ADDRESS_1_READ(r, p)                       MREAD_32((uint8_t *)p + 52, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_ADDRESS_1_WRITE(v, p)                      MWRITE_32((uint8_t *)p + 52, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_ADDRESS_2_READ(r, p)                       MREAD_32((uint8_t *)p + 56, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_ADDRESS_2_WRITE(v, p)                      MWRITE_32((uint8_t *)p + 56, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_ADDRESS_3_READ(r, p)                       MREAD_32((uint8_t *)p + 60, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_BPM_BUFFER_ADDRESS_3_WRITE(v, p)                      MWRITE_32((uint8_t *)p + 60, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_REQUEST_ID_READ(r, p)                                 MREAD_32((uint8_t *)p + 64, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_REQUEST_ID_WRITE(v, p)                                MWRITE_32((uint8_t *)p + 64, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_DATA_BUF_PTR_READ(r, p)                               MREAD_32((uint8_t *)p + 68, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_DATA_BUF_PTR_WRITE(v, p)                              MWRITE_32((uint8_t *)p + 68, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_DHD_LIST_BASE_ADDRESS_READ(r, p)                      MREAD_32((uint8_t *)p + 72, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_DHD_LIST_BASE_ADDRESS_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 72, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_INGRESS_QUEUE_PD_WRITE_PTR_READ(r, p)                 MREAD_16((uint8_t *)p + 76, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_INGRESS_QUEUE_PD_WRITE_PTR_WRITE(v, p)                MWRITE_16((uint8_t *)p + 76, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_INGRESS_QUEUE_PD_READ_PTR_READ(r, p)                  MREAD_16((uint8_t *)p + 78, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_INGRESS_QUEUE_PD_READ_PTR_WRITE(v, p)                 MWRITE_16((uint8_t *)p + 78, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_IS_PROXY_ENABLED_READ(r, p)                           MREAD_8((uint8_t *)p + 80, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_IS_PROXY_ENABLED_WRITE(v, p)                          MWRITE_8((uint8_t *)p + 80, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_DHD_LIST_SIZE_READ(r, p)                              MREAD_8((uint8_t *)p + 81, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_DHD_LIST_SIZE_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 81, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_DHD_LIST_PTR_READ(r, p)                               MREAD_16((uint8_t *)p + 82, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_DHD_LIST_PTR_WRITE(v, p)                              MWRITE_16((uint8_t *)p + 82, v)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_DHD_LIST_TABLE_READ(r, p, i)                          MREAD_I_8((uint8_t *)p + 84, i, r)
#define RDD_WLAN_MCAST_CONTROL_ENTRY_DHD_LIST_TABLE_WRITE(v, p, i)                         MWRITE_I_8((uint8_t *)p + 84, i, v)

typedef struct
{
	uint32_t	valid_mask	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_WAN_UDP_FILTER_CONTROL_ENTRY_DTS;

#define RDD_DS_WAN_UDP_FILTER_CONTROL_ENTRY_VALID_MASK_READ(r, p)                 MREAD_32((uint8_t *)p, r)
#define RDD_DS_WAN_UDP_FILTER_CONTROL_ENTRY_VALID_MASK_WRITE(v, p)                MWRITE_32((uint8_t *)p, v)

typedef struct
{
	uint32_t	reserved_0  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_mac     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_mac_lsw 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_1  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_2  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vtag0_tpid  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vtag0_tci   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vtag1_tpid  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vtag1_tci   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_mac     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_mac_lshw	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	eth_type    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_L2_UCAST_TUPLE_ENTRY_DTS;

#define RDD_FC_L2_UCAST_TUPLE_ENTRY_DST_MAC_READ(r, p)                      MREAD_16((uint8_t *)p + 2, r)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_DST_MAC_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 2, v)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_DST_MAC_LSW_READ(r, p)                  MREAD_32((uint8_t *)p + 4, r)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_DST_MAC_LSW_WRITE(v, p)                 MWRITE_32((uint8_t *)p + 4, v)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_VTAG0_TPID_READ(r, p)                   MREAD_16((uint8_t *)p + 16, r)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_VTAG0_TPID_WRITE(v, p)                  MWRITE_16((uint8_t *)p + 16, v)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_VTAG0_TCI_READ(r, p)                    MREAD_16((uint8_t *)p + 18, r)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_VTAG0_TCI_WRITE(v, p)                   MWRITE_16((uint8_t *)p + 18, v)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_VTAG1_TPID_READ(r, p)                   MREAD_16((uint8_t *)p + 20, r)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_VTAG1_TPID_WRITE(v, p)                  MWRITE_16((uint8_t *)p + 20, v)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_VTAG1_TCI_READ(r, p)                    MREAD_16((uint8_t *)p + 22, r)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_VTAG1_TCI_WRITE(v, p)                   MWRITE_16((uint8_t *)p + 22, v)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_SRC_MAC_READ(r, p)                      MREAD_32((uint8_t *)p + 24, r)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_SRC_MAC_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 24, v)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_SRC_MAC_LSHW_READ(r, p)                 MREAD_16((uint8_t *)p + 28, r)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_SRC_MAC_LSHW_WRITE(v, p)                MWRITE_16((uint8_t *)p + 28, v)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_ETH_TYPE_READ(r, p)                     MREAD_16((uint8_t *)p + 30, r)
#define RDD_FC_L2_UCAST_TUPLE_ENTRY_ETH_TYPE_WRITE(v, p)                    MWRITE_16((uint8_t *)p + 30, v)

typedef struct
{
	uint16_t	allocated_budget	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	current_budget  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RATE_LIMITER_REMAINDER_ENTRY_DTS;

#define RDD_RATE_LIMITER_REMAINDER_ENTRY_ALLOCATED_BUDGET_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_RATE_LIMITER_REMAINDER_ENTRY_ALLOCATED_BUDGET_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#define RDD_RATE_LIMITER_REMAINDER_ENTRY_CURRENT_BUDGET_READ(r, p)                   MREAD_8((uint8_t *)p + 1, r)
#define RDD_RATE_LIMITER_REMAINDER_ENTRY_CURRENT_BUDGET_WRITE(v, p)                  MWRITE_8((uint8_t *)p + 1, v)
#if defined DSL_63138

#define RDD_RATE_LIMITER_REMAINDER_TABLE_SIZE     32
typedef struct
{
	RDD_RATE_LIMITER_REMAINDER_ENTRY_DTS	entry[ RDD_RATE_LIMITER_REMAINDER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RATE_LIMITER_REMAINDER_TABLE_DTS;

#define RDD_RATE_LIMITER_REMAINDER_TABLE_PTR()	( RDD_RATE_LIMITER_REMAINDER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + RATE_LIMITER_REMAINDER_TABLE_ADDRESS )

#endif
#if defined DSL_63138

typedef struct
{
	uint32_t	vlan_index_table_ptr	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	opbit_remark_mode   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipbit_remark_mode   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wifi_ssid           	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dei_remark_enable   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dei_value           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue_mode  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	forward_mode        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_port         	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	qos_mapping_mode    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	traffic_class       	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_mode        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_id          	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_shaping_mode   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	union_field1        	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = union_field1, size = 7 bits
	uint32_t	rate_shaper_id      	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1           	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue       	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	subnet_id           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_pbit          	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inner_pbit          	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp_remarking_mode 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp                	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ecn                 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_VLAN_INDEX_TABLE_PTR_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 3, 13, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_VLAN_INDEX_TABLE_PTR_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 3, 13, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OPBIT_REMARK_MODE_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 1, 2, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OPBIT_REMARK_MODE_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 1, 2, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_IPBIT_REMARK_MODE_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 1, 1, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_IPBIT_REMARK_MODE_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 1, 1, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_WIFI_SSID_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p + 0, 13, 4, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_WIFI_SSID_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p + 0, 13, 4, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_REMARK_ENABLE_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 2, 4, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_REMARK_ENABLE_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 2, 4, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_VALUE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 2, 3, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_VALUE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 2, 3, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 2, 2, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 2, 2, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_FORWARD_MODE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 2, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_FORWARD_MODE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 2, 0, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_EGRESS_PORT_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 3, 4, 4, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_EGRESS_PORT_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 3, 4, 4, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_QOS_MAPPING_MODE_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 3, 3, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_QOS_MAPPING_MODE_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 3, 3, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_TRAFFIC_CLASS_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 3, 0, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_TRAFFIC_CLASS_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 3, 0, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DROP_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DROP_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_CPU_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_CPU_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_MODE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 4, 5, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_MODE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 4, 5, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_ID_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 4, 1, 4, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_ID_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 4, 1, 4, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_SHAPING_MODE_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 4, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_SHAPING_MODE_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 4, 0, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_UNION_FIELD1_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 5, 1, 7, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_UNION_FIELD1_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 5, 1, 7, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_SHAPER_ID_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 5, 1, 7, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_SHAPER_ID_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 5, 1, 7, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SERVICE_QUEUE_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 5, 1, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SERVICE_QUEUE_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 5, 1, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SUBNET_ID_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p + 4, 15, 2, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SUBNET_ID_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p + 4, 15, 2, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OUTER_PBIT_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 6, 4, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OUTER_PBIT_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 6, 4, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_INNER_PBIT_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 6, 1, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_INNER_PBIT_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 6, 1, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_REMARKING_MODE_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 6, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_REMARKING_MODE_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 6, 0, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 7, 2, 6, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 7, 2, 6, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_ECN_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 7, 0, 2, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_ECN_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 7, 0, 2, v)
#endif
#if defined DSL_63138

#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_SIZE     256
typedef struct
{
	RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	reserved1    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid0         	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid1         	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	valid        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context_index	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4    	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	next_entry   	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_sa        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_CONNECTION2_ENTRY_DTS;

#define RDD_FC_MCAST_CONNECTION2_ENTRY_VID0_READ(r, p)                          FIELD_MREAD_16((uint8_t *)p, 0, 12, r)
#define RDD_FC_MCAST_CONNECTION2_ENTRY_VID0_WRITE(v, p)                         FIELD_MWRITE_16((uint8_t *)p, 0, 12, v)
#define RDD_FC_MCAST_CONNECTION2_ENTRY_VID1_READ(r, p)                          FIELD_MREAD_16((uint8_t *)p + 2, 0, 12, r)
#define RDD_FC_MCAST_CONNECTION2_ENTRY_VID1_WRITE(v, p)                         FIELD_MWRITE_16((uint8_t *)p + 2, 0, 12, v)
#define RDD_FC_MCAST_CONNECTION2_ENTRY_VALID_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_FC_MCAST_CONNECTION2_ENTRY_VALID_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_FC_MCAST_CONNECTION2_ENTRY_CONTEXT_INDEX_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 4, 0, 15, r)
#define RDD_FC_MCAST_CONNECTION2_ENTRY_CONTEXT_INDEX_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 4, 0, 15, v)
#define RDD_FC_MCAST_CONNECTION2_ENTRY_NEXT_ENTRY_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 7, 0, 7, r)
#define RDD_FC_MCAST_CONNECTION2_ENTRY_NEXT_ENTRY_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 7, 0, 7, v)
#define RDD_FC_MCAST_CONNECTION2_ENTRY_IP_SA_READ(r, p)                         MREAD_32((uint8_t *)p + 8, r)
#define RDD_FC_MCAST_CONNECTION2_ENTRY_IP_SA_WRITE(v, p)                        MWRITE_32((uint8_t *)p + 8, v)
#if defined DSL_63138

#define RDD_FC_MCAST_CONNECTION2_TABLE_SIZE     128
typedef struct
{
	RDD_FC_MCAST_CONNECTION2_ENTRY_DTS	entry[ RDD_FC_MCAST_CONNECTION2_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_CONNECTION2_TABLE_DTS;

#define RDD_FC_MCAST_CONNECTION2_TABLE_PTR()	( RDD_FC_MCAST_CONNECTION2_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + FC_MCAST_CONNECTION2_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	eth_mac_pointer 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_queue_pointer	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_QUEUE_POINTERS_ENTRY_DTS;

#define RDD_ETH_TX_QUEUE_POINTERS_ENTRY_ETH_MAC_POINTER_READ(r, p)                  MREAD_16((uint8_t *)p, r)
#define RDD_ETH_TX_QUEUE_POINTERS_ENTRY_ETH_MAC_POINTER_WRITE(v, p)                 MWRITE_16((uint8_t *)p, v)
#define RDD_ETH_TX_QUEUE_POINTERS_ENTRY_TX_QUEUE_POINTER_READ(r, p)                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_ETH_TX_QUEUE_POINTERS_ENTRY_TX_QUEUE_POINTER_WRITE(v, p)                MWRITE_16((uint8_t *)p + 2, v)
#if defined DSL_63138

#define RDD_ETH_TX_QUEUES_POINTERS_TABLE_SIZE     72
typedef struct
{
	RDD_ETH_TX_QUEUE_POINTERS_ENTRY_DTS	entry[ RDD_ETH_TX_QUEUES_POINTERS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_QUEUES_POINTERS_TABLE_DTS;

#define RDD_ETH_TX_QUEUES_POINTERS_TABLE_PTR()	( RDD_ETH_TX_QUEUES_POINTERS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_QUEUES_POINTERS_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	reserved_fw_only	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS;

#if defined DSL_63138

#define RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
typedef struct
{
	RDD_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS	entry[ RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_DTS;

#define RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_PTR()	( RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS )

#endif

typedef struct
{
	uint32_t	bbh_descriptor_0 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_descriptor_1 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timer_period     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	skb_free_index   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	copies_in_transit	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	total_copies     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	total_length     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tokens           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bucket_size      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bucket           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_queue_discards	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_queue_writes  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_queue_reads   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_buf_ptr     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	eth_header_0     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	eth_header_1     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	eth_header_2     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	eth_header_3     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SPDSVC_CONTEXT_ENTRY_DTS;

#define RDD_SPDSVC_CONTEXT_ENTRY_BBH_DESCRIPTOR_0_READ(r, p)                  MREAD_32((uint8_t *)p, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_BBH_DESCRIPTOR_0_WRITE(v, p)                 MWRITE_32((uint8_t *)p, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_BBH_DESCRIPTOR_1_READ(r, p)                  MREAD_32((uint8_t *)p + 4, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_BBH_DESCRIPTOR_1_WRITE(v, p)                 MWRITE_32((uint8_t *)p + 4, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_TIMER_PERIOD_READ(r, p)                      MREAD_16((uint8_t *)p + 8, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_TIMER_PERIOD_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 8, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_SKB_FREE_INDEX_READ(r, p)                    MREAD_16((uint8_t *)p + 10, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_SKB_FREE_INDEX_WRITE(v, p)                   MWRITE_16((uint8_t *)p + 10, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_COPIES_IN_TRANSIT_READ(r, p)                 MREAD_32((uint8_t *)p + 12, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_COPIES_IN_TRANSIT_WRITE(v, p)                MWRITE_32((uint8_t *)p + 12, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_TOTAL_COPIES_READ(r, p)                      MREAD_32((uint8_t *)p + 16, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_TOTAL_COPIES_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 16, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_TOTAL_LENGTH_READ(r, p)                      MREAD_16((uint8_t *)p + 22, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_TOTAL_LENGTH_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 22, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_TOKENS_READ(r, p)                            MREAD_16((uint8_t *)p + 24, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_TOKENS_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 24, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_BUCKET_SIZE_READ(r, p)                       MREAD_16((uint8_t *)p + 26, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_BUCKET_SIZE_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 26, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_BUCKET_READ(r, p)                            MREAD_32((uint8_t *)p + 28, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_BUCKET_WRITE(v, p)                           MWRITE_32((uint8_t *)p + 28, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_TX_QUEUE_DISCARDS_READ(r, p)                 MREAD_32((uint8_t *)p + 32, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_TX_QUEUE_DISCARDS_WRITE(v, p)                MWRITE_32((uint8_t *)p + 32, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_TX_QUEUE_WRITES_READ(r, p)                   MREAD_32((uint8_t *)p + 36, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_TX_QUEUE_WRITES_WRITE(v, p)                  MWRITE_32((uint8_t *)p + 36, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_TX_QUEUE_READS_READ(r, p)                    MREAD_32((uint8_t *)p + 40, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_TX_QUEUE_READS_WRITE(v, p)                   MWRITE_32((uint8_t *)p + 40, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_DATA_BUF_PTR_READ(r, p)                      MREAD_32((uint8_t *)p + 44, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_DATA_BUF_PTR_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 44, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_ETH_HEADER_0_READ(r, p)                      MREAD_32((uint8_t *)p + 48, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_ETH_HEADER_0_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 48, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_ETH_HEADER_1_READ(r, p)                      MREAD_32((uint8_t *)p + 52, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_ETH_HEADER_1_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 52, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_ETH_HEADER_2_READ(r, p)                      MREAD_32((uint8_t *)p + 56, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_ETH_HEADER_2_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 56, v)
#define RDD_SPDSVC_CONTEXT_ENTRY_ETH_HEADER_3_READ(r, p)                      MREAD_16((uint8_t *)p + 60, r)
#define RDD_SPDSVC_CONTEXT_ENTRY_ETH_HEADER_3_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 60, v)
#define RDD_SBPM_REPLY_ENTRY_RESERVED_FW_ONLY_NUMBER	32

typedef struct
{
	uint32_t	reserved_fw_only[RDD_SBPM_REPLY_ENTRY_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SBPM_REPLY_ENTRY_DTS;


typedef struct
{
	uint32_t	head_ptr              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tail_ptr              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ingress_packet_counter	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_packet_counter 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_threshold      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	profile_ptr           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rs_status_offset      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rs_group_status_offset	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	queue_mask            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	index                 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_QUEUE_DESCRIPTOR_DTS;

#define RDD_ETH_TX_QUEUE_DESCRIPTOR_HEAD_PTR_READ(r, p)                               MREAD_16((uint8_t *)p, r)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_HEAD_PTR_WRITE(v, p)                              MWRITE_16((uint8_t *)p, v)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_TAIL_PTR_READ(r, p)                               MREAD_16((uint8_t *)p + 2, r)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_TAIL_PTR_WRITE(v, p)                              MWRITE_16((uint8_t *)p + 2, v)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_INGRESS_PACKET_COUNTER_READ(r, p)                 MREAD_16((uint8_t *)p + 4, r)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_INGRESS_PACKET_COUNTER_WRITE(v, p)                MWRITE_16((uint8_t *)p + 4, v)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_EGRESS_PACKET_COUNTER_READ(r, p)                  MREAD_16((uint8_t *)p + 6, r)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_EGRESS_PACKET_COUNTER_WRITE(v, p)                 MWRITE_16((uint8_t *)p + 6, v)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_PACKET_THRESHOLD_READ(r, p)                       MREAD_16((uint8_t *)p + 8, r)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_PACKET_THRESHOLD_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 8, v)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_PROFILE_PTR_READ(r, p)                            MREAD_16((uint8_t *)p + 10, r)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_PROFILE_PTR_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 10, v)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_RS_STATUS_OFFSET_READ(r, p)                       MREAD_8((uint8_t *)p + 12, r)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_RS_STATUS_OFFSET_WRITE(v, p)                      MWRITE_8((uint8_t *)p + 12, v)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_RS_GROUP_STATUS_OFFSET_READ(r, p)                 MREAD_8((uint8_t *)p + 13, r)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_RS_GROUP_STATUS_OFFSET_WRITE(v, p)                MWRITE_8((uint8_t *)p + 13, v)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_QUEUE_MASK_READ(r, p)                             MREAD_8((uint8_t *)p + 14, r)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_QUEUE_MASK_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 14, v)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_INDEX_READ(r, p)                                  MREAD_8((uint8_t *)p + 15, r)
#define RDD_ETH_TX_QUEUE_DESCRIPTOR_INDEX_WRITE(v, p)                                 MWRITE_8((uint8_t *)p + 15, v)
#if defined DSL_63138

#define RDD_ETH_TX_QUEUES_TABLE_SIZE     72
typedef struct
{
	RDD_ETH_TX_QUEUE_DESCRIPTOR_DTS	entry[ RDD_ETH_TX_QUEUES_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_QUEUES_TABLE_DTS;

#define RDD_ETH_TX_QUEUES_TABLE_PTR()	( RDD_ETH_TX_QUEUES_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_QUEUES_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	current_budget  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	budget_limit    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocated_budget	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_METER_ENTRY_DTS;

#define RDD_CPU_RX_METER_ENTRY_CURRENT_BUDGET_READ(r, p)                   MREAD_16((uint8_t *)p, r)
#define RDD_CPU_RX_METER_ENTRY_CURRENT_BUDGET_WRITE(v, p)                  MWRITE_16((uint8_t *)p, v)
#define RDD_CPU_RX_METER_ENTRY_BUDGET_LIMIT_READ(r, p)                     MREAD_16((uint8_t *)p + 2, r)
#define RDD_CPU_RX_METER_ENTRY_BUDGET_LIMIT_WRITE(v, p)                    MWRITE_16((uint8_t *)p + 2, v)
#define RDD_CPU_RX_METER_ENTRY_ALLOCATED_BUDGET_READ(r, p)                 MREAD_16((uint8_t *)p + 4, r)
#define RDD_CPU_RX_METER_ENTRY_ALLOCATED_BUDGET_WRITE(v, p)                MWRITE_16((uint8_t *)p + 4, v)

#define RDD_CPU_RX_METER_TABLE_SIZE     16
typedef struct
{
	RDD_CPU_RX_METER_ENTRY_DTS	entry[ RDD_CPU_RX_METER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_METER_TABLE_DTS;

#define RDD_DS_CPU_RX_METER_TABLE_PTR()	( RDD_DS_CPU_RX_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_RX_METER_TABLE_ADDRESS )


typedef struct
{
	uint8_t	enable    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FORWARDING_MATRIX_ENTRY_DTS;

#define RDD_FORWARDING_MATRIX_ENTRY_ENABLE_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_FORWARDING_MATRIX_ENTRY_ENABLE_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#if defined DSL_63138

#define RDD_DS_FORWARDING_MATRIX_TABLE_SIZE     9
#define RDD_DS_FORWARDING_MATRIX_TABLE_SIZE2    16
typedef struct
{
	RDD_FORWARDING_MATRIX_ENTRY_DTS	entry[ RDD_DS_FORWARDING_MATRIX_TABLE_SIZE ][ RDD_DS_FORWARDING_MATRIX_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FORWARDING_MATRIX_TABLE_DTS;

#define RDD_DS_FORWARDING_MATRIX_TABLE_PTR()	( RDD_DS_FORWARDING_MATRIX_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FORWARDING_MATRIX_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	valid                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context_index          	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bucket_overflow_counter	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	command_list_length_64 	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_extend             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_multicast           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	protocol               	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved               	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tos                    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_mac_crc            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_mac_crc            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_L2_UCAST_CONNECTION_ENTRY_DTS;

#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_VALID_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_VALID_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_CONTEXT_INDEX_READ(r, p)                           FIELD_MREAD_16((uint8_t *)p, 0, 15, r)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_CONTEXT_INDEX_WRITE(v, p)                          FIELD_MWRITE_16((uint8_t *)p, 0, 15, v)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_BUCKET_OVERFLOW_COUNTER_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 2, 5, 3, r)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_BUCKET_OVERFLOW_COUNTER_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 2, 5, 3, v)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_COMMAND_LIST_LENGTH_64_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 2, 1, 4, r)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_COMMAND_LIST_LENGTH_64_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 2, 1, 4, v)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_KEY_EXTEND_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 2, 0, 1, r)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_KEY_EXTEND_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 2, 0, 1, v)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_IS_MULTICAST_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 3, 7, 1, r)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_IS_MULTICAST_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 3, 7, 1, v)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_PROTOCOL_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 3, 0, 7, r)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_PROTOCOL_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 3, 0, 7, v)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_TOS_READ(r, p)                                     MREAD_8((uint8_t *)p + 7, r)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_TOS_WRITE(v, p)                                    MWRITE_8((uint8_t *)p + 7, v)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_SRC_MAC_CRC_READ(r, p)                             MREAD_32((uint8_t *)p + 8, r)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_SRC_MAC_CRC_WRITE(v, p)                            MWRITE_32((uint8_t *)p + 8, v)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_DST_MAC_CRC_READ(r, p)                             MREAD_32((uint8_t *)p + 12, r)
#define RDD_FC_L2_UCAST_CONNECTION_ENTRY_DST_MAC_CRC_WRITE(v, p)                            MWRITE_32((uint8_t *)p + 12, v)

typedef struct
{
	uint32_t	reserved_fw_only	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS;

#if defined DSL_63138

#define RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
typedef struct
{
	RDD_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS	entry[ RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_DTS;

#define RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_PTR()	( RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS )

#endif

typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TWO_BYTES_DTS;

#if defined DSL_63138

#define RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_SIZE     32
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	egress_counter              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0                   	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ingress_counter             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_id             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_task_number              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	emac_mask                   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_queues_status            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	gpio_flow_control_vector_ptr	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_counters_ptr_0       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_destination_0           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_counters_ptr_1       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_destination_1           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_counters_ptr_2       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4                   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_destination_2           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_port                 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved5                   	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved6                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_MAC_DESCRIPTOR_DTS;

#define RDD_ETH_TX_MAC_DESCRIPTOR_EGRESS_COUNTER_READ(r, p)                               MREAD_8((uint8_t *)p, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_EGRESS_COUNTER_WRITE(v, p)                              MWRITE_8((uint8_t *)p, v)
#define RDD_ETH_TX_MAC_DESCRIPTOR_INGRESS_COUNTER_READ(r, p)                              MREAD_8((uint8_t *)p + 4, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_INGRESS_COUNTER_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 4, v)
#define RDD_ETH_TX_MAC_DESCRIPTOR_RATE_LIMITER_ID_READ(r, p)                              MREAD_8((uint8_t *)p + 5, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_RATE_LIMITER_ID_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 5, v)
#define RDD_ETH_TX_MAC_DESCRIPTOR_TX_TASK_NUMBER_READ(r, p)                               MREAD_8((uint8_t *)p + 6, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_TX_TASK_NUMBER_WRITE(v, p)                              MWRITE_8((uint8_t *)p + 6, v)
#define RDD_ETH_TX_MAC_DESCRIPTOR_EMAC_MASK_READ(r, p)                                    MREAD_8((uint8_t *)p + 8, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_EMAC_MASK_WRITE(v, p)                                   MWRITE_8((uint8_t *)p + 8, v)
#define RDD_ETH_TX_MAC_DESCRIPTOR_TX_QUEUES_STATUS_READ(r, p)                             MREAD_8((uint8_t *)p + 9, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_TX_QUEUES_STATUS_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 9, v)
#define RDD_ETH_TX_MAC_DESCRIPTOR_GPIO_FLOW_CONTROL_VECTOR_PTR_READ(r, p)                 MREAD_16((uint8_t *)p + 10, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_GPIO_FLOW_CONTROL_VECTOR_PTR_WRITE(v, p)                MWRITE_16((uint8_t *)p + 10, v)
#define RDD_ETH_TX_MAC_DESCRIPTOR_PACKET_COUNTERS_PTR_0_READ(r, p)                        MREAD_16((uint8_t *)p + 12, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_PACKET_COUNTERS_PTR_0_WRITE(v, p)                       MWRITE_16((uint8_t *)p + 12, v)
#define RDD_ETH_TX_MAC_DESCRIPTOR_BBH_DESTINATION_0_READ(r, p)                            MREAD_8((uint8_t *)p + 15, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_BBH_DESTINATION_0_WRITE(v, p)                           MWRITE_8((uint8_t *)p + 15, v)
#define RDD_ETH_TX_MAC_DESCRIPTOR_PACKET_COUNTERS_PTR_1_READ(r, p)                        MREAD_16((uint8_t *)p + 16, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_PACKET_COUNTERS_PTR_1_WRITE(v, p)                       MWRITE_16((uint8_t *)p + 16, v)
#define RDD_ETH_TX_MAC_DESCRIPTOR_BBH_DESTINATION_1_READ(r, p)                            MREAD_8((uint8_t *)p + 19, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_BBH_DESTINATION_1_WRITE(v, p)                           MWRITE_8((uint8_t *)p + 19, v)
#define RDD_ETH_TX_MAC_DESCRIPTOR_PACKET_COUNTERS_PTR_2_READ(r, p)                        MREAD_16((uint8_t *)p + 20, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_PACKET_COUNTERS_PTR_2_WRITE(v, p)                       MWRITE_16((uint8_t *)p + 20, v)
#define RDD_ETH_TX_MAC_DESCRIPTOR_BBH_DESTINATION_2_READ(r, p)                            MREAD_8((uint8_t *)p + 23, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_BBH_DESTINATION_2_WRITE(v, p)                           MWRITE_8((uint8_t *)p + 23, v)
#define RDD_ETH_TX_MAC_DESCRIPTOR_EGRESS_PORT_READ(r, p)                                  MREAD_8((uint8_t *)p + 24, r)
#define RDD_ETH_TX_MAC_DESCRIPTOR_EGRESS_PORT_WRITE(v, p)                                 MWRITE_8((uint8_t *)p + 24, v)
#if defined DSL_63138

#define RDD_ETH_TX_MAC_TABLE_SIZE     10
typedef struct
{
	RDD_ETH_TX_MAC_DESCRIPTOR_DTS	entry[ RDD_ETH_TX_MAC_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_MAC_TABLE_DTS;

#define RDD_ETH_TX_MAC_TABLE_PTR()	( RDD_ETH_TX_MAC_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_MAC_TABLE_ADDRESS )

#endif

typedef struct
{
	uint8_t	reserved_fw_only	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ONE_BYTE_DTS;

#if defined DSL_63138

#define RDD_REVERSE_FFI_TABLE_SIZE     256
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_REVERSE_FFI_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_REVERSE_FFI_TABLE_DTS;

#define RDD_REVERSE_FFI_TABLE_PTR()	( RDD_REVERSE_FFI_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + REVERSE_FFI_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	reserved_fw_only	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FOUR_BYTES_DTS;

#if defined DSL_63138

#define RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS;

#define RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_PTR()	( RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS;

#define RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_PTR()	( RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_ADDRESS )

#endif

typedef struct
{
	uint32_t	msg_type        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	if_id           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	common_hdr_flags	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	epoch           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	request_id      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	status          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_ring_id    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dma_done_mark   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_COMPLETE_DESCRIPTOR_DTS;

#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_MSG_TYPE_READ(r, p)                         MREAD_8((uint8_t *)p, r)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_MSG_TYPE_WRITE(v, p)                        MWRITE_8((uint8_t *)p, v)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_MSG_TYPE_L_READ( wv )                       FIELD_GET( wv, 24, 8 )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_MSG_TYPE_L_WRITE( v, wv )                   FIELD_SET( v, 24, 8, wv )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_IF_ID_READ(r, p)                            MREAD_8((uint8_t *)p + 1, r)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_IF_ID_WRITE(v, p)                           MWRITE_8((uint8_t *)p + 1, v)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_IF_ID_L_READ( wv )                          FIELD_GET( wv, 16, 8 )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_IF_ID_L_WRITE( v, wv )                      FIELD_SET( v, 16, 8, wv )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_COMMON_HDR_FLAGS_READ(r, p)                 MREAD_8((uint8_t *)p + 2, r)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_COMMON_HDR_FLAGS_WRITE(v, p)                MWRITE_8((uint8_t *)p + 2, v)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_COMMON_HDR_FLAGS_L_READ( wv )               FIELD_GET( wv, 8, 8 )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_COMMON_HDR_FLAGS_L_WRITE( v, wv )           FIELD_SET( v, 8, 8, wv )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_EPOCH_READ(r, p)                            MREAD_8((uint8_t *)p + 3, r)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_EPOCH_WRITE(v, p)                           MWRITE_8((uint8_t *)p + 3, v)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_EPOCH_L_READ( wv )                          FIELD_GET( wv, 0, 8 )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_EPOCH_L_WRITE( v, wv )                      FIELD_SET( v, 0, 8, wv )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_REQUEST_ID_READ(r, p)                       MREAD_32((uint8_t *)p + 4, r)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_REQUEST_ID_WRITE(v, p)                      MWRITE_32((uint8_t *)p + 4, v)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_REQUEST_ID_L_READ( wv )                     FIELD_GET( wv, 0, 32 )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_REQUEST_ID_L_WRITE( v, wv )                 FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_STATUS_READ(r, p)                           MREAD_16((uint8_t *)p + 8, r)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_STATUS_WRITE(v, p)                          MWRITE_16((uint8_t *)p + 8, v)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_STATUS_L_READ( wv )                         FIELD_GET( wv, 16, 16 )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_STATUS_L_WRITE( v, wv )                     FIELD_SET( v, 16, 16, wv )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_FLOW_RING_ID_READ(r, p)                     MREAD_16((uint8_t *)p + 10, r)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_FLOW_RING_ID_WRITE(v, p)                    MWRITE_16((uint8_t *)p + 10, v)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_FLOW_RING_ID_L_READ( wv )                   FIELD_GET( wv, 0, 16 )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_FLOW_RING_ID_L_WRITE( v, wv )               FIELD_SET( v, 0, 16, wv )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_DMA_DONE_MARK_READ(r, p)                    MREAD_32((uint8_t *)p + 12, r)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_DMA_DONE_MARK_WRITE(v, p)                   MWRITE_32((uint8_t *)p + 12, v)
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_DMA_DONE_MARK_L_READ( wv )                  FIELD_GET( wv, 0, 32 )
#define RDD_DHD_TX_COMPLETE_DESCRIPTOR_DMA_DONE_MARK_L_WRITE( v, wv )              FIELD_SET( v, 0, 32, wv )
#if defined DSL_63138

#define RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_TX_COMPLETE_DESCRIPTOR_DTS	entry[ RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_DTS;

#define RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_PTR()	( RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DHD_TX_COMPLETE_FLOW_RING_BUFFER_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_RUNNER_FWTRACE_MAINA_PARAM_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINA_PARAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINA_PARAM_DTS;

#define RDD_RUNNER_FWTRACE_MAINA_PARAM_PTR()	( RDD_RUNNER_FWTRACE_MAINA_PARAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + RUNNER_FWTRACE_MAINA_PARAM_ADDRESS )

#endif

typedef struct
{
	uint32_t	current_budget      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	budget_limit_exp    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	budget_limit        	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocated_budget_exp	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocated_budget    	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RATE_LIMITER_ENTRY_DTS;

#define RDD_RATE_LIMITER_ENTRY_CURRENT_BUDGET_READ(r, p)                       MREAD_32((uint8_t *)p, r)
#define RDD_RATE_LIMITER_ENTRY_CURRENT_BUDGET_WRITE(v, p)                      MWRITE_32((uint8_t *)p, v)
#define RDD_RATE_LIMITER_ENTRY_BUDGET_LIMIT_EXP_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_RATE_LIMITER_ENTRY_BUDGET_LIMIT_EXP_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_RATE_LIMITER_ENTRY_BUDGET_LIMIT_READ(r, p)                         FIELD_MREAD_16((uint8_t *)p + 4, 0, 15, r)
#define RDD_RATE_LIMITER_ENTRY_BUDGET_LIMIT_WRITE(v, p)                        FIELD_MWRITE_16((uint8_t *)p + 4, 0, 15, v)
#define RDD_RATE_LIMITER_ENTRY_ALLOCATED_BUDGET_EXP_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 6, 7, 1, r)
#define RDD_RATE_LIMITER_ENTRY_ALLOCATED_BUDGET_EXP_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 6, 7, 1, v)
#define RDD_RATE_LIMITER_ENTRY_ALLOCATED_BUDGET_READ(r, p)                     FIELD_MREAD_16((uint8_t *)p + 6, 0, 15, r)
#define RDD_RATE_LIMITER_ENTRY_ALLOCATED_BUDGET_WRITE(v, p)                    FIELD_MWRITE_16((uint8_t *)p + 6, 0, 15, v)
#if defined DSL_63138

#define RDD_DS_RATE_LIMITER_TABLE_SIZE     32
typedef struct
{
	RDD_RATE_LIMITER_ENTRY_DTS	entry[ RDD_DS_RATE_LIMITER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_RATE_LIMITER_TABLE_DTS;

#define RDD_DS_RATE_LIMITER_TABLE_PTR()	( RDD_DS_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_RATE_LIMITER_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	head_ptr              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tail_ptr              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ingress_packet_counter	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_packet_counter 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_threshold      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	profile_ptr           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rs_status_offset      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rs_group_status_offset	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	status_offset         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_DTS;

#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_HEAD_PTR_READ(r, p)                               MREAD_16((uint8_t *)p, r)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_HEAD_PTR_WRITE(v, p)                              MWRITE_16((uint8_t *)p, v)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TAIL_PTR_READ(r, p)                               MREAD_16((uint8_t *)p + 2, r)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TAIL_PTR_WRITE(v, p)                              MWRITE_16((uint8_t *)p + 2, v)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_INGRESS_PACKET_COUNTER_READ(r, p)                 MREAD_16((uint8_t *)p + 4, r)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_INGRESS_PACKET_COUNTER_WRITE(v, p)                MWRITE_16((uint8_t *)p + 4, v)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_EGRESS_PACKET_COUNTER_READ(r, p)                  MREAD_16((uint8_t *)p + 6, r)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_EGRESS_PACKET_COUNTER_WRITE(v, p)                 MWRITE_16((uint8_t *)p + 6, v)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_PACKET_THRESHOLD_READ(r, p)                       MREAD_16((uint8_t *)p + 8, r)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_PACKET_THRESHOLD_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 8, v)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_PROFILE_PTR_READ(r, p)                            MREAD_16((uint8_t *)p + 10, r)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_PROFILE_PTR_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 10, v)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_RS_STATUS_OFFSET_READ(r, p)                       MREAD_8((uint8_t *)p + 12, r)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_RS_STATUS_OFFSET_WRITE(v, p)                      MWRITE_8((uint8_t *)p + 12, v)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_RS_GROUP_STATUS_OFFSET_READ(r, p)                 MREAD_8((uint8_t *)p + 13, r)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_RS_GROUP_STATUS_OFFSET_WRITE(v, p)                MWRITE_8((uint8_t *)p + 13, v)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_STATUS_OFFSET_READ(r, p)                          MREAD_8((uint8_t *)p + 14, r)
#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_STATUS_OFFSET_WRITE(v, p)                         MWRITE_8((uint8_t *)p + 14, v)
#if defined DSL_63138

#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_SIZE     128
typedef struct
{
	RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_DTS	entry[ RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_DTS;

#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_PTR()	( RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_ADDRESS )

#endif

typedef struct
{
	uint16_t	reserved             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	cpu_reason           	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	ingress_classify_mode	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	ingress_flow         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_WAN_FLOW_ENTRY_DTS;

#define RDD_DS_WAN_FLOW_ENTRY_CPU_REASON_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p, 1, 6, r)
#define RDD_DS_WAN_FLOW_ENTRY_CPU_REASON_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p, 1, 6, v)
#define RDD_DS_WAN_FLOW_ENTRY_INGRESS_CLASSIFY_MODE_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 0, 1, r)
#define RDD_DS_WAN_FLOW_ENTRY_INGRESS_CLASSIFY_MODE_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 0, 1, v)
#define RDD_DS_WAN_FLOW_ENTRY_INGRESS_FLOW_READ(r, p)                          MREAD_8((uint8_t *)p + 1, r)
#define RDD_DS_WAN_FLOW_ENTRY_INGRESS_FLOW_WRITE(v, p)                         MWRITE_8((uint8_t *)p + 1, v)
#if defined DSL_63138

#define RDD_DS_WAN_FLOW_TABLE_SIZE     256
typedef struct
{
	RDD_DS_WAN_FLOW_ENTRY_DTS	entry[ RDD_DS_WAN_FLOW_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_WAN_FLOW_TABLE_DTS;

#define RDD_DS_WAN_FLOW_TABLE_PTR()	( RDD_DS_WAN_FLOW_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_WAN_FLOW_TABLE_ADDRESS )

#endif
#define RDD_ETH_RX_DESCRIPTORS_RESERVED_FW_ONLY_NUMBER	2

typedef struct
{
	uint32_t	reserved_fw_only[RDD_ETH_RX_DESCRIPTORS_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_RX_DESCRIPTORS_DTS;

#if defined DSL_63138

#define RDD_ETH0_RX_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_ETH_RX_DESCRIPTORS_DTS	entry[ RDD_ETH0_RX_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH0_RX_DESCRIPTORS_DTS;

#define RDD_ETH0_RX_DESCRIPTORS_PTR()	( RDD_ETH0_RX_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH0_RX_DESCRIPTORS_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_INGRESS_HANDLER_SKB_DATA_POINTER_SIZE     32
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_INGRESS_HANDLER_SKB_DATA_POINTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_HANDLER_SKB_DATA_POINTER_DTS;

#define RDD_INGRESS_HANDLER_SKB_DATA_POINTER_PTR()	( RDD_INGRESS_HANDLER_SKB_DATA_POINTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + INGRESS_HANDLER_SKB_DATA_POINTER_ADDRESS )

#endif
#define RDD_RUNNER_FLOW_HEADER_BUFFER_RESERVED_FW_ONLY_NUMBER	32

typedef struct
{
	uint32_t	reserved_fw_only[RDD_RUNNER_FLOW_HEADER_BUFFER_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FLOW_HEADER_BUFFER_DTS;


typedef struct
{
	uint32_t	offset    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	value     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mask      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hits      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_WAN_UDP_FILTER_ENTRY_DTS;

#define RDD_DS_WAN_UDP_FILTER_ENTRY_OFFSET_READ(r, p)                 MREAD_32((uint8_t *)p, r)
#define RDD_DS_WAN_UDP_FILTER_ENTRY_OFFSET_WRITE(v, p)                MWRITE_32((uint8_t *)p, v)
#define RDD_DS_WAN_UDP_FILTER_ENTRY_VALUE_READ(r, p)                  MREAD_32((uint8_t *)p + 4, r)
#define RDD_DS_WAN_UDP_FILTER_ENTRY_VALUE_WRITE(v, p)                 MWRITE_32((uint8_t *)p + 4, v)
#define RDD_DS_WAN_UDP_FILTER_ENTRY_MASK_READ(r, p)                   MREAD_32((uint8_t *)p + 8, r)
#define RDD_DS_WAN_UDP_FILTER_ENTRY_MASK_WRITE(v, p)                  MWRITE_32((uint8_t *)p + 8, v)
#define RDD_DS_WAN_UDP_FILTER_ENTRY_HITS_READ(r, p)                   MREAD_32((uint8_t *)p + 12, r)
#define RDD_DS_WAN_UDP_FILTER_ENTRY_HITS_WRITE(v, p)                  MWRITE_32((uint8_t *)p + 12, v)
#if defined DSL_63138

#define RDD_DS_WAN_UDP_FILTER_TABLE_SIZE     32
typedef struct
{
	RDD_DS_WAN_UDP_FILTER_ENTRY_DTS	entry[ RDD_DS_WAN_UDP_FILTER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_WAN_UDP_FILTER_TABLE_DTS;

#define RDD_DS_WAN_UDP_FILTER_TABLE_PTR()	( RDD_DS_WAN_UDP_FILTER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_WAN_UDP_FILTER_TABLE_ADDRESS )

#endif

typedef struct
{
	uint8_t	u8        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_PORT_HEADER_ENTRY_DTS;

#define RDD_FC_MCAST_PORT_HEADER_ENTRY_U8_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_FC_MCAST_PORT_HEADER_ENTRY_U8_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#if defined DSL_63138

#define RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE     8
#define RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE2    64
typedef struct
{
	RDD_FC_MCAST_PORT_HEADER_ENTRY_DTS	entry[ RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE ][ RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_PORT_HEADER_BUFFER_DTS;

#define RDD_FC_MCAST_PORT_HEADER_BUFFER_PTR()	( RDD_FC_MCAST_PORT_HEADER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + FC_MCAST_PORT_HEADER_BUFFER_ADDRESS )

#endif

typedef struct
{
	uint32_t	reserved0 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_DTS;


typedef struct
{
	uint32_t	valid            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	command          	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_high_prio     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	gso              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	emac             	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_queue         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_bridge_port  	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length    	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs_flag         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	lag_port_pti     	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	message_parameter	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_offset   	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_CORE_DTS;

#define RDD_CPU_TX_DESCRIPTOR_CORE_VALID_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_CORE_VALID_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_CORE_VALID_L_READ( wv )                           FIELD_GET( wv, 31, 1 )
#define RDD_CPU_TX_DESCRIPTOR_CORE_VALID_L_WRITE( v, wv )                       FIELD_SET( v, 31, 1, wv )
#define RDD_CPU_TX_DESCRIPTOR_CORE_COMMAND_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p, 4, 3, r)
#define RDD_CPU_TX_DESCRIPTOR_CORE_COMMAND_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p, 4, 3, v)
#define RDD_CPU_TX_DESCRIPTOR_CORE_COMMAND_L_READ( wv )                         FIELD_GET( wv, 28, 3 )
#define RDD_CPU_TX_DESCRIPTOR_CORE_COMMAND_L_WRITE( v, wv )                     FIELD_SET( v, 28, 3, wv )
#define RDD_CPU_TX_DESCRIPTOR_CORE_IS_HIGH_PRIO_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p, 3, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_CORE_IS_HIGH_PRIO_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p, 3, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_CORE_IS_HIGH_PRIO_L_READ( wv )                    FIELD_GET( wv, 27, 1 )
#define RDD_CPU_TX_DESCRIPTOR_CORE_IS_HIGH_PRIO_L_WRITE( v, wv )                FIELD_SET( v, 27, 1, wv )
#define RDD_CPU_TX_DESCRIPTOR_CORE_GSO_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p, 2, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_CORE_GSO_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p, 2, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_CORE_GSO_L_READ( wv )                             FIELD_GET( wv, 26, 1 )
#define RDD_CPU_TX_DESCRIPTOR_CORE_GSO_L_WRITE( v, wv )                         FIELD_SET( v, 26, 1, wv )
#define RDD_CPU_TX_DESCRIPTOR_CORE_EMAC_READ(r, p)                              FIELD_MREAD_16((uint8_t *)p, 6, 4, r)
#define RDD_CPU_TX_DESCRIPTOR_CORE_EMAC_WRITE(v, p)                             FIELD_MWRITE_16((uint8_t *)p, 6, 4, v)
#define RDD_CPU_TX_DESCRIPTOR_CORE_EMAC_L_READ( wv )                            FIELD_GET( wv, 22, 4 )
#define RDD_CPU_TX_DESCRIPTOR_CORE_EMAC_L_WRITE( v, wv )                        FIELD_SET( v, 22, 4, wv )
#define RDD_CPU_TX_DESCRIPTOR_CORE_TX_QUEUE_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 1, 3, 3, r)
#define RDD_CPU_TX_DESCRIPTOR_CORE_TX_QUEUE_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 1, 3, 3, v)
#define RDD_CPU_TX_DESCRIPTOR_CORE_TX_QUEUE_L_READ( wv )                        FIELD_GET( wv, 19, 3 )
#define RDD_CPU_TX_DESCRIPTOR_CORE_TX_QUEUE_L_WRITE( v, wv )                    FIELD_SET( v, 19, 3, wv )
#define RDD_CPU_TX_DESCRIPTOR_CORE_SRC_BRIDGE_PORT_READ(r, p)                   FIELD_MREAD_32((uint8_t *)p + 0, 14, 5, r)
#define RDD_CPU_TX_DESCRIPTOR_CORE_SRC_BRIDGE_PORT_WRITE(v, p)                  FIELD_MWRITE_32((uint8_t *)p + 0, 14, 5, v)
#define RDD_CPU_TX_DESCRIPTOR_CORE_SRC_BRIDGE_PORT_L_READ( wv )                 FIELD_GET( wv, 14, 5 )
#define RDD_CPU_TX_DESCRIPTOR_CORE_SRC_BRIDGE_PORT_L_WRITE( v, wv )             FIELD_SET( v, 14, 5, wv )
#define RDD_CPU_TX_DESCRIPTOR_CORE_PACKET_LENGTH_READ(r, p)                     FIELD_MREAD_16((uint8_t *)p + 2, 0, 14, r)
#define RDD_CPU_TX_DESCRIPTOR_CORE_PACKET_LENGTH_WRITE(v, p)                    FIELD_MWRITE_16((uint8_t *)p + 2, 0, 14, v)
#define RDD_CPU_TX_DESCRIPTOR_CORE_PACKET_LENGTH_L_READ( wv )                   FIELD_GET( wv, 0, 14 )
#define RDD_CPU_TX_DESCRIPTOR_CORE_PACKET_LENGTH_L_WRITE( v, wv )               FIELD_SET( v, 0, 14, wv )
#define RDD_CPU_TX_DESCRIPTOR_CORE_ABS_FLAG_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_CORE_ABS_FLAG_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_CORE_ABS_FLAG_L_READ( wv )                        FIELD_GET( wv, 31, 1 )
#define RDD_CPU_TX_DESCRIPTOR_CORE_ABS_FLAG_L_WRITE( v, wv )                    FIELD_SET( v, 31, 1, wv )
#define RDD_CPU_TX_DESCRIPTOR_CORE_LAG_PORT_PTI_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 4, 4, 2, r)
#define RDD_CPU_TX_DESCRIPTOR_CORE_LAG_PORT_PTI_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 4, 4, 2, v)
#define RDD_CPU_TX_DESCRIPTOR_CORE_LAG_PORT_PTI_L_READ( wv )                    FIELD_GET( wv, 28, 2 )
#define RDD_CPU_TX_DESCRIPTOR_CORE_LAG_PORT_PTI_L_WRITE( v, wv )                FIELD_SET( v, 28, 2, wv )
#define RDD_CPU_TX_DESCRIPTOR_CORE_MESSAGE_PARAMETER_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 4, 7, 5, r)
#define RDD_CPU_TX_DESCRIPTOR_CORE_MESSAGE_PARAMETER_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 4, 7, 5, v)
#define RDD_CPU_TX_DESCRIPTOR_CORE_MESSAGE_PARAMETER_L_READ( wv )               FIELD_GET( wv, 23, 5 )
#define RDD_CPU_TX_DESCRIPTOR_CORE_MESSAGE_PARAMETER_L_WRITE( v, wv )           FIELD_SET( v, 23, 5, wv )
#define RDD_CPU_TX_DESCRIPTOR_CORE_PAYLOAD_OFFSET_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 5, 0, 7, r)
#define RDD_CPU_TX_DESCRIPTOR_CORE_PAYLOAD_OFFSET_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 5, 0, 7, v)
#define RDD_CPU_TX_DESCRIPTOR_CORE_PAYLOAD_OFFSET_L_READ( wv )                  FIELD_GET( wv, 16, 7 )
#define RDD_CPU_TX_DESCRIPTOR_CORE_PAYLOAD_OFFSET_L_WRITE( v, wv )              FIELD_SET( v, 16, 7, wv )
#if defined DSL_63138

typedef struct
{
	uint32_t	reserved0    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1    	:17	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	buffer_number	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_BPM_DTS;

#define RDD_CPU_TX_DESCRIPTOR_BPM_BUFFER_NUMBER_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 6, 0, 15, r)
#define RDD_CPU_TX_DESCRIPTOR_BPM_BUFFER_NUMBER_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 6, 0, 15, v)
#define RDD_CPU_TX_DESCRIPTOR_BPM_BUFFER_NUMBER_L_READ( wv )               FIELD_GET( wv, 0, 15 )
#define RDD_CPU_TX_DESCRIPTOR_BPM_BUFFER_NUMBER_L_WRITE( v, wv )           FIELD_SET( v, 0, 15, wv )
#endif

typedef struct
{
	uint32_t	reserved0 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1 	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	skb_index 	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_ABS_DTS;

#define RDD_CPU_TX_DESCRIPTOR_ABS_SKB_INDEX_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_CPU_TX_DESCRIPTOR_ABS_SKB_INDEX_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#define RDD_CPU_TX_DESCRIPTOR_ABS_SKB_INDEX_L_READ( wv )               FIELD_GET( wv, 0, 14 )
#define RDD_CPU_TX_DESCRIPTOR_ABS_SKB_INDEX_L_WRITE( v, wv )           FIELD_SET( v, 0, 14, wv )

typedef struct
{
	uint32_t	reserved0          	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	downstream_wan_flow	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1          	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2          	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_DS_FAST_DTS;

#define RDD_CPU_TX_DESCRIPTOR_DS_FAST_DOWNSTREAM_WAN_FLOW_READ(r, p)                 FIELD_MREAD_32((uint8_t *)p + 0, 14, 8, r)
#define RDD_CPU_TX_DESCRIPTOR_DS_FAST_DOWNSTREAM_WAN_FLOW_WRITE(v, p)                FIELD_MWRITE_32((uint8_t *)p + 0, 14, 8, v)
#define RDD_CPU_TX_DESCRIPTOR_DS_FAST_DOWNSTREAM_WAN_FLOW_L_READ( wv )               FIELD_GET( wv, 14, 8 )
#define RDD_CPU_TX_DESCRIPTOR_DS_FAST_DOWNSTREAM_WAN_FLOW_L_WRITE( v, wv )           FIELD_SET( v, 14, 8, wv )

typedef struct
{
	uint32_t	reserved0        	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_high_prio     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	upstream_gem_flow	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1        	:19	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_queue         	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2        	:23	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_US_FAST_DTS;

#define RDD_CPU_TX_DESCRIPTOR_US_FAST_IS_HIGH_PRIO_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p, 3, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_US_FAST_IS_HIGH_PRIO_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p, 3, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_US_FAST_IS_HIGH_PRIO_L_READ( wv )                    FIELD_GET( wv, 27, 1 )
#define RDD_CPU_TX_DESCRIPTOR_US_FAST_IS_HIGH_PRIO_L_WRITE( v, wv )                FIELD_SET( v, 27, 1, wv )
#define RDD_CPU_TX_DESCRIPTOR_US_FAST_UPSTREAM_GEM_FLOW_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 3, 8, r)
#define RDD_CPU_TX_DESCRIPTOR_US_FAST_UPSTREAM_GEM_FLOW_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 3, 8, v)
#define RDD_CPU_TX_DESCRIPTOR_US_FAST_UPSTREAM_GEM_FLOW_L_READ( wv )               FIELD_GET( wv, 19, 8 )
#define RDD_CPU_TX_DESCRIPTOR_US_FAST_UPSTREAM_GEM_FLOW_L_WRITE( v, wv )           FIELD_SET( v, 19, 8, wv )
#define RDD_CPU_TX_DESCRIPTOR_US_FAST_TX_QUEUE_READ(r, p)                          FIELD_MREAD_16((uint8_t *)p + 4, 7, 9, r)
#define RDD_CPU_TX_DESCRIPTOR_US_FAST_TX_QUEUE_WRITE(v, p)                         FIELD_MWRITE_16((uint8_t *)p + 4, 7, 9, v)
#define RDD_CPU_TX_DESCRIPTOR_US_FAST_TX_QUEUE_L_READ( wv )                        FIELD_GET( wv, 23, 9 )
#define RDD_CPU_TX_DESCRIPTOR_US_FAST_TX_QUEUE_L_WRITE( v, wv )                    FIELD_SET( v, 23, 9, wv )

typedef struct
{
	uint32_t	reserved0 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1 	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	en_1588   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2 	:27	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_DS_PICO_DTS;

#define RDD_CPU_TX_DESCRIPTOR_DS_PICO_EN_1588_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 4, 3, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_DS_PICO_EN_1588_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 4, 3, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_DS_PICO_EN_1588_L_READ( wv )                 FIELD_GET( wv, 27, 1 )
#define RDD_CPU_TX_DESCRIPTOR_DS_PICO_EN_1588_L_WRITE( v, wv )             FIELD_SET( v, 27, 1, wv )

typedef struct
{
	uint32_t	reserved0     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid_multicast	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid          	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2     	:26	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI_DTS;

#define RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI_SSID_MULTICAST_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI_SSID_MULTICAST_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI_SSID_MULTICAST_L_READ( wv )               FIELD_GET( wv, 30, 1 )
#define RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI_SSID_MULTICAST_L_WRITE( v, wv )           FIELD_SET( v, 30, 1, wv )
#define RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI_SSID_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 4, 2, 4, r)
#define RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI_SSID_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 4, 2, 4, v)
#define RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI_SSID_L_READ( wv )                         FIELD_GET( wv, 26, 4 )
#define RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI_SSID_L_WRITE( v, wv )                     FIELD_SET( v, 26, 4, wv )

typedef struct
{
	uint32_t	valid       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	command     	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0   	:28	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1   	:28	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	message_type	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_MESSAGE_DESCRIPTOR_DTS;

#define RDD_CPU_TX_MESSAGE_DESCRIPTOR_VALID_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_CPU_TX_MESSAGE_DESCRIPTOR_VALID_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_CPU_TX_MESSAGE_DESCRIPTOR_COMMAND_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p, 4, 3, r)
#define RDD_CPU_TX_MESSAGE_DESCRIPTOR_COMMAND_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p, 4, 3, v)
#define RDD_CPU_TX_MESSAGE_DESCRIPTOR_MESSAGE_TYPE_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 7, 0, 4, r)
#define RDD_CPU_TX_MESSAGE_DESCRIPTOR_MESSAGE_TYPE_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 7, 0, 4, v)
#define RDD_CONNECTION_CONTEXT_MULTICAST_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER	16

typedef struct
{
	uint32_t	reserved_fw_only[RDD_CONNECTION_CONTEXT_MULTICAST_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CONNECTION_CONTEXT_MULTICAST_BUFFER_ENTRY_DTS;

#if defined DSL_63138

#define RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_SIZE     8
typedef struct
{
	RDD_CONNECTION_CONTEXT_MULTICAST_BUFFER_ENTRY_DTS	entry[ RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_DTS;

#define RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_PTR()	( RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_ADDRESS )

#endif
#if defined DSL_63138

typedef struct
{
	uint32_t	last_sbn        	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fstat_cell      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_id         	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length   	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fstat_error     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error_type      	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ih_buffer_number	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_memory   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	buffer_number   	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_RX_DESCRIPTOR_DTS;

#define RDD_BBH_RX_DESCRIPTOR_LAST_SBN_READ(r, p)                         FIELD_MREAD_16((uint8_t *)p, 6, 10, r)
#define RDD_BBH_RX_DESCRIPTOR_LAST_SBN_WRITE(v, p)                        FIELD_MWRITE_16((uint8_t *)p, 6, 10, v)
#define RDD_BBH_RX_DESCRIPTOR_FSTAT_CELL_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 1, 5, 1, r)
#define RDD_BBH_RX_DESCRIPTOR_FSTAT_CELL_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 1, 5, 1, v)
#define RDD_BBH_RX_DESCRIPTOR_FLOW_ID_READ(r, p)                          FIELD_MREAD_32((uint8_t *)p + 0, 14, 7, r)
#define RDD_BBH_RX_DESCRIPTOR_FLOW_ID_WRITE(v, p)                         FIELD_MWRITE_32((uint8_t *)p + 0, 14, 7, v)
#define RDD_BBH_RX_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                    FIELD_MREAD_16((uint8_t *)p + 2, 0, 14, r)
#define RDD_BBH_RX_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                   FIELD_MWRITE_16((uint8_t *)p + 2, 0, 14, v)
#define RDD_BBH_RX_DESCRIPTOR_ERROR_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_BBH_RX_DESCRIPTOR_ERROR_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_BBH_RX_DESCRIPTOR_FSTAT_ERROR_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 4, 5, 1, r)
#define RDD_BBH_RX_DESCRIPTOR_FSTAT_ERROR_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 4, 5, 1, v)
#define RDD_BBH_RX_DESCRIPTOR_ERROR_TYPE_READ(r, p)                       FIELD_MREAD_16((uint8_t *)p + 4, 6, 7, r)
#define RDD_BBH_RX_DESCRIPTOR_ERROR_TYPE_WRITE(v, p)                      FIELD_MWRITE_16((uint8_t *)p + 4, 6, 7, v)
#define RDD_BBH_RX_DESCRIPTOR_IH_BUFFER_NUMBER_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 5, 0, 6, r)
#define RDD_BBH_RX_DESCRIPTOR_IH_BUFFER_NUMBER_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 5, 0, 6, v)
#define RDD_BBH_RX_DESCRIPTOR_TARGET_MEMORY_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 6, 7, 1, r)
#define RDD_BBH_RX_DESCRIPTOR_TARGET_MEMORY_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 6, 7, 1, v)
#define RDD_BBH_RX_DESCRIPTOR_BUFFER_NUMBER_READ(r, p)                    FIELD_MREAD_16((uint8_t *)p + 6, 0, 15, r)
#define RDD_BBH_RX_DESCRIPTOR_BUFFER_NUMBER_WRITE(v, p)                   FIELD_MWRITE_16((uint8_t *)p + 6, 0, 15, v)
#endif
#if defined DSL_63138

#define RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_SIZE     64
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_DTS;

#define RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_PTR()	( RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_LAN_ENQUEUE_SQ_PD_ADDRESS )

#endif
#define RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY_RESERVED_FW_ONLY_NUMBER	2

typedef struct
{
	uint32_t	reserved_fw_only[RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY_DTS;

#if defined DSL_63138

#define RDD_DS_CPU_TX_BBH_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY_DTS	entry[ RDD_DS_CPU_TX_BBH_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_TX_BBH_DESCRIPTORS_DTS;

#define RDD_DS_CPU_TX_BBH_DESCRIPTORS_PTR()	( RDD_DS_CPU_TX_BBH_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_TX_BBH_DESCRIPTORS_ADDRESS )

#endif
#define RDD_PROFILING_BUFFER_PICO_RUNNER_RESERVED_FW_ONLY_NUMBER	64

typedef struct
{
	uint32_t	reserved_fw_only[RDD_PROFILING_BUFFER_PICO_RUNNER_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PROFILING_BUFFER_PICO_RUNNER_DTS;


typedef struct
{
	uint32_t	next_rule_cfg_id    	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	next_group_id       	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rule_type           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	lookup_mode         	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hit_action          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	miss_action         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2           	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	generic_rule_index_1	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	generic_rule_index_2	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_mask            	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_DTS;

#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_NEXT_RULE_CFG_ID_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p, 3, 5, r)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_NEXT_RULE_CFG_ID_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p, 3, 5, v)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_NEXT_GROUP_ID_READ(r, p)                        FIELD_MREAD_16((uint8_t *)p, 6, 5, r)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_NEXT_GROUP_ID_WRITE(v, p)                       FIELD_MWRITE_16((uint8_t *)p, 6, 5, v)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_RULE_TYPE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 1, 4, 2, r)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_RULE_TYPE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 1, 4, 2, v)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_LOOKUP_MODE_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 1, 2, 2, r)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_LOOKUP_MODE_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 1, 2, 2, v)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_HIT_ACTION_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 1, 1, 1, r)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_HIT_ACTION_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 1, 1, 1, v)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_MISS_ACTION_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 1, 0, 1, r)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_MISS_ACTION_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 1, 0, 1, v)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_GENERIC_RULE_INDEX_1_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 4, 2, 2, r)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_GENERIC_RULE_INDEX_1_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 4, 2, 2, v)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_GENERIC_RULE_INDEX_2_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 4, 0, 2, r)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_GENERIC_RULE_INDEX_2_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 4, 0, 2, v)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_KEY_MASK_READ(r, p)                             FIELD_MREAD_32((uint8_t *)p + 4, 0, 24, r)
#define RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_KEY_MASK_WRITE(v, p)                            FIELD_MWRITE_32((uint8_t *)p + 4, 0, 24, v)
#if defined DSL_63138

#define RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_SIZE     16
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	reserved0     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid_multicast	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid          	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	radio_idx     	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_ring_id  	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2     	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DHD_DESCRIPTOR_DTS;

#define RDD_CPU_TX_DHD_DESCRIPTOR_SSID_MULTICAST_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_CPU_TX_DHD_DESCRIPTOR_SSID_MULTICAST_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_CPU_TX_DHD_DESCRIPTOR_SSID_MULTICAST_L_READ( wv )               FIELD_GET( wv, 30, 1 )
#define RDD_CPU_TX_DHD_DESCRIPTOR_SSID_MULTICAST_L_WRITE( v, wv )           FIELD_SET( v, 30, 1, wv )
#define RDD_CPU_TX_DHD_DESCRIPTOR_SSID_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 4, 2, 4, r)
#define RDD_CPU_TX_DHD_DESCRIPTOR_SSID_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 4, 2, 4, v)
#define RDD_CPU_TX_DHD_DESCRIPTOR_SSID_L_READ( wv )                         FIELD_GET( wv, 26, 4 )
#define RDD_CPU_TX_DHD_DESCRIPTOR_SSID_L_WRITE( v, wv )                     FIELD_SET( v, 26, 4, wv )
#define RDD_CPU_TX_DHD_DESCRIPTOR_RADIO_IDX_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 4, 0, 2, r)
#define RDD_CPU_TX_DHD_DESCRIPTOR_RADIO_IDX_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 4, 0, 2, v)
#define RDD_CPU_TX_DHD_DESCRIPTOR_RADIO_IDX_L_READ( wv )                    FIELD_GET( wv, 24, 2 )
#define RDD_CPU_TX_DHD_DESCRIPTOR_RADIO_IDX_L_WRITE( v, wv )                FIELD_SET( v, 24, 2, wv )
#define RDD_CPU_TX_DHD_DESCRIPTOR_FLOW_RING_ID_READ(r, p)                   FIELD_MREAD_32((uint8_t *)p + 4, 14, 10, r)
#define RDD_CPU_TX_DHD_DESCRIPTOR_FLOW_RING_ID_WRITE(v, p)                  FIELD_MWRITE_32((uint8_t *)p + 4, 14, 10, v)
#define RDD_CPU_TX_DHD_DESCRIPTOR_FLOW_RING_ID_L_READ( wv )                 FIELD_GET( wv, 14, 10 )
#define RDD_CPU_TX_DHD_DESCRIPTOR_FLOW_RING_ID_L_WRITE( v, wv )             FIELD_SET( v, 14, 10, wv )

typedef struct
{
	uint32_t	reserved0   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dhd_msg_type	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	radio_idx   	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_ring_id	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	disabled    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_DTS;

#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_DHD_MSG_TYPE_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 4, 6, 2, r)
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_DHD_MSG_TYPE_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 4, 6, 2, v)
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_DHD_MSG_TYPE_L_READ( wv )               FIELD_GET( wv, 30, 2 )
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_DHD_MSG_TYPE_L_WRITE( v, wv )           FIELD_SET( v, 30, 2, wv )
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_RADIO_IDX_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 4, 4, 2, r)
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_RADIO_IDX_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 4, 4, 2, v)
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_RADIO_IDX_L_READ( wv )                  FIELD_GET( wv, 28, 2 )
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_RADIO_IDX_L_WRITE( v, wv )              FIELD_SET( v, 28, 2, wv )
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_FLOW_RING_ID_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 4, 2, 10, r)
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_FLOW_RING_ID_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 4, 2, 10, v)
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_FLOW_RING_ID_L_READ( wv )               FIELD_GET( wv, 18, 10 )
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_FLOW_RING_ID_L_WRITE( v, wv )           FIELD_SET( v, 18, 10, wv )
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_DISABLED_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 5, 1, 1, r)
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_DISABLED_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 5, 1, 1, v)
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_DISABLED_L_READ( wv )                   FIELD_GET( wv, 17, 1 )
#define RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_DISABLED_L_WRITE( v, wv )               FIELD_SET( v, 17, 1, wv )

typedef struct
{
	uint32_t	reserved0                  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	guaranteed_free_count_incr 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	guaranteed_free_count_delta	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR_DTS;

#define RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR_GUARANTEED_FREE_COUNT_INCR_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR_GUARANTEED_FREE_COUNT_INCR_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR_GUARANTEED_FREE_COUNT_INCR_L_READ( wv )                FIELD_GET( wv, 31, 1 )
#define RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR_GUARANTEED_FREE_COUNT_INCR_L_WRITE( v, wv )            FIELD_SET( v, 31, 1, wv )
#define RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR_GUARANTEED_FREE_COUNT_DELTA_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 4, 0, 15, r)
#define RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR_GUARANTEED_FREE_COUNT_DELTA_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 4, 0, 15, v)
#define RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR_GUARANTEED_FREE_COUNT_DELTA_L_READ( wv )               FIELD_GET( wv, 16, 15 )
#define RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR_GUARANTEED_FREE_COUNT_DELTA_L_WRITE( v, wv )           FIELD_SET( v, 16, 15, wv )

typedef struct
{
	uint32_t	us_flow_control_mode    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0               	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	max_low_threshold       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	min_high_threshold      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	max_high_threshold      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	low_large_interval_flag 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1               	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	low_drop_constant       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	high_large_interval_flag	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2               	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	high_drop_constant      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_QUEUE_PROFILE_DTS;

#define RDD_QUEUE_PROFILE_US_FLOW_CONTROL_MODE_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_QUEUE_PROFILE_US_FLOW_CONTROL_MODE_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_QUEUE_PROFILE_MAX_LOW_THRESHOLD_READ(r, p)                        MREAD_16((uint8_t *)p + 2, r)
#define RDD_QUEUE_PROFILE_MAX_LOW_THRESHOLD_WRITE(v, p)                       MWRITE_16((uint8_t *)p + 2, v)
#define RDD_QUEUE_PROFILE_MIN_HIGH_THRESHOLD_READ(r, p)                       MREAD_16((uint8_t *)p + 4, r)
#define RDD_QUEUE_PROFILE_MIN_HIGH_THRESHOLD_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 4, v)
#define RDD_QUEUE_PROFILE_MAX_HIGH_THRESHOLD_READ(r, p)                       MREAD_16((uint8_t *)p + 6, r)
#define RDD_QUEUE_PROFILE_MAX_HIGH_THRESHOLD_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 6, v)
#define RDD_QUEUE_PROFILE_LOW_LARGE_INTERVAL_FLAG_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 8, 7, 1, r)
#define RDD_QUEUE_PROFILE_LOW_LARGE_INTERVAL_FLAG_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 8, 7, 1, v)
#define RDD_QUEUE_PROFILE_LOW_DROP_CONSTANT_READ(r, p)                        MREAD_16((uint8_t *)p + 10, r)
#define RDD_QUEUE_PROFILE_LOW_DROP_CONSTANT_WRITE(v, p)                       MWRITE_16((uint8_t *)p + 10, v)
#define RDD_QUEUE_PROFILE_HIGH_LARGE_INTERVAL_FLAG_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 12, 7, 1, r)
#define RDD_QUEUE_PROFILE_HIGH_LARGE_INTERVAL_FLAG_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 12, 7, 1, v)
#define RDD_QUEUE_PROFILE_HIGH_DROP_CONSTANT_READ(r, p)                       MREAD_16((uint8_t *)p + 14, r)
#define RDD_QUEUE_PROFILE_HIGH_DROP_CONSTANT_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 14, v)
#if defined DSL_63138

#define RDD_DS_QUEUE_PROFILE_TABLE_SIZE     8
typedef struct
{
	RDD_QUEUE_PROFILE_DTS	entry[ RDD_DS_QUEUE_PROFILE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_QUEUE_PROFILE_TABLE_DTS;

#define RDD_DS_QUEUE_PROFILE_TABLE_PTR()	( RDD_DS_QUEUE_PROFILE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_QUEUE_PROFILE_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DHD_TX_POST_PD_INGRESS_QUEUE_SIZE     32
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DHD_TX_POST_PD_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_PD_INGRESS_QUEUE_DTS;

#define RDD_DHD_TX_POST_PD_INGRESS_QUEUE_PTR()	( RDD_DHD_TX_POST_PD_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DHD_TX_POST_PD_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_DTS;

#define RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR()	( RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_ADDRESS )

#endif
#define RDD_GSO_DESC_ENTRY_FRAG_DATA_NUMBER	18
#define RDD_GSO_DESC_ENTRY_FRAG_LEN_NUMBER	18

typedef struct
{
	uint32_t	data                                              	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	len                                               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	linear_len                                        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mss                                               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0                                         	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_allocated                                      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	nr_frags                                          	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	frag_data[RDD_GSO_DESC_ENTRY_FRAG_DATA_NUMBER];
	uint16_t	frag_len[RDD_GSO_DESC_ENTRY_FRAG_LEN_NUMBER];
	uint32_t	reserved2                                         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_DESC_ENTRY_DTS;

#define RDD_GSO_DESC_ENTRY_DATA_READ(r, p)                         MREAD_32((uint8_t *)p, r)
#define RDD_GSO_DESC_ENTRY_DATA_WRITE(v, p)                        MWRITE_32((uint8_t *)p, v)
#define RDD_GSO_DESC_ENTRY_LEN_READ(r, p)                          MREAD_16((uint8_t *)p + 4, r)
#define RDD_GSO_DESC_ENTRY_LEN_WRITE(v, p)                         MWRITE_16((uint8_t *)p + 4, v)
#define RDD_GSO_DESC_ENTRY_LINEAR_LEN_READ(r, p)                   MREAD_16((uint8_t *)p + 6, r)
#define RDD_GSO_DESC_ENTRY_LINEAR_LEN_WRITE(v, p)                  MWRITE_16((uint8_t *)p + 6, v)
#define RDD_GSO_DESC_ENTRY_MSS_READ(r, p)                          MREAD_16((uint8_t *)p + 8, r)
#define RDD_GSO_DESC_ENTRY_MSS_WRITE(v, p)                         MWRITE_16((uint8_t *)p + 8, v)
#define RDD_GSO_DESC_ENTRY_IS_ALLOCATED_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 10, 0, 1, r)
#define RDD_GSO_DESC_ENTRY_IS_ALLOCATED_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 10, 0, 1, v)
#define RDD_GSO_DESC_ENTRY_NR_FRAGS_READ(r, p)                     MREAD_8((uint8_t *)p + 11, r)
#define RDD_GSO_DESC_ENTRY_NR_FRAGS_WRITE(v, p)                    MWRITE_8((uint8_t *)p + 11, v)
#define RDD_GSO_DESC_ENTRY_FRAG_DATA_READ(r, p, i)                 MREAD_I_32((uint8_t *)p + 16, i, r)
#define RDD_GSO_DESC_ENTRY_FRAG_DATA_WRITE(v, p, i)                MWRITE_I_32((uint8_t *)p + 16, i, v)
#define RDD_GSO_DESC_ENTRY_FRAG_LEN_READ(r, p, i)                  FIELD_MREAD_I_32((uint8_t *)p + 88, 8, 16, i, r)
#define RDD_GSO_DESC_ENTRY_FRAG_LEN_WRITE(v, p, i)                 FIELD_MWRITE_I_32((uint8_t *)p + 88, 8, 16, i, v)
#if defined DSL_63138

#define RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_DTS;

#define RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_PTR()	( RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_RX_SQ_PD_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_DTS;

#define RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_PTR()	( RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_DTS;

#define RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_PTR()	( RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_SIZE     10
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_DTS;

#define RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_PTR()	( RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_ABSOLUTE_TX_BBH_COUNTER_ADDRESS )

#endif
#if defined DSL_63138

typedef struct
{
	uint32_t	head_pointer             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tail_pointer             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	guaranteed_free_count    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	non_guaranteed_free_count	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	guaranteed_threshold     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_DTS;

#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_HEAD_POINTER_READ(r, p)                              MREAD_16((uint8_t *)p, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_HEAD_POINTER_WRITE(v, p)                             MWRITE_16((uint8_t *)p, v)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_TAIL_POINTER_READ(r, p)                              MREAD_16((uint8_t *)p + 2, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_TAIL_POINTER_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 2, v)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_FREE_COUNT_READ(r, p)                     MREAD_16((uint8_t *)p + 4, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_FREE_COUNT_WRITE(v, p)                    MWRITE_16((uint8_t *)p + 4, v)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_NON_GUARANTEED_FREE_COUNT_READ(r, p)                 MREAD_16((uint8_t *)p + 6, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_NON_GUARANTEED_FREE_COUNT_WRITE(v, p)                MWRITE_16((uint8_t *)p + 6, v)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_THRESHOLD_READ(r, p)                      MREAD_16((uint8_t *)p + 8, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_THRESHOLD_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 8, v)
#endif

typedef struct
{
	uint16_t	number_of_active_tasks	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TIMER_CONTROL_DESCRIPTOR_DTS;

#define RDD_TIMER_CONTROL_DESCRIPTOR_NUMBER_OF_ACTIVE_TASKS_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_TIMER_CONTROL_DESCRIPTOR_NUMBER_OF_ACTIVE_TASKS_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)
#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_ENTRY_RESERVED_FW_ONLY_NUMBER	16

typedef struct
{
	uint16_t	reserved_fw_only[RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_ENTRY_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_ENTRY_DTS;

#if defined DSL_63138

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_SIZE     5
typedef struct
{
	RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_ENTRY_DTS	entry[ RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_DTS;

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_PTR()	( RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_SKB_ENQUEUED_INDEXES_FIFO_ADDRESS )

#endif

typedef struct
{
	uint32_t	ring_ptr  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ring_size 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ring_base 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ring_end  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_COMPLETE_RING_DESCRIPTOR_DTS;

#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_RING_PTR_READ(r, p)                  MREAD_32((uint8_t *)p, r)
#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_RING_PTR_WRITE(v, p)                 MWRITE_32((uint8_t *)p, v)
#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_RING_SIZE_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_RING_SIZE_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)
#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_RING_BASE_READ(r, p)                 MREAD_32((uint8_t *)p + 8, r)
#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_RING_BASE_WRITE(v, p)                MWRITE_32((uint8_t *)p + 8, v)
#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_RING_END_READ(r, p)                  MREAD_32((uint8_t *)p + 12, r)
#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_RING_END_WRITE(v, p)                 MWRITE_32((uint8_t *)p + 12, v)
#if defined DSL_63138

#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_COMPLETE_RING_DESCRIPTOR_DTS	entry[ RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_DTS;

#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_PTR()	( RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_RUNNER_FWTRACE_PICOA_PARAM_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_PICOA_PARAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_PICOA_PARAM_DTS;

#define RDD_RUNNER_FWTRACE_PICOA_PARAM_PTR()	( RDD_RUNNER_FWTRACE_PICOA_PARAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + RUNNER_FWTRACE_PICOA_PARAM_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_GPON_RX_DIRECT_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_GPON_RX_DIRECT_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_RX_DIRECT_DESCRIPTORS_DTS;

#define RDD_GPON_RX_DIRECT_DESCRIPTORS_PTR()	( RDD_GPON_RX_DIRECT_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GPON_RX_DIRECT_DESCRIPTORS_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_CPU_RX_PD_INGRESS_QUEUE_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_CPU_RX_PD_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_PD_INGRESS_QUEUE_DTS;

#define RDD_CPU_RX_PD_INGRESS_QUEUE_PTR()	( RDD_CPU_RX_PD_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_RX_PD_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DS_SQ_ENQUEUE_QUEUE_SIZE     64
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_DS_SQ_ENQUEUE_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_SQ_ENQUEUE_QUEUE_DTS;

#define RDD_DS_SQ_ENQUEUE_QUEUE_PTR()	( RDD_DS_SQ_ENQUEUE_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_SQ_ENQUEUE_QUEUE_ADDRESS )

#endif
#define RDD_CPU_TX_MESSAGE_DATA_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER	16

typedef struct
{
	uint32_t	reserved_fw_only[RDD_CPU_TX_MESSAGE_DATA_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_MESSAGE_DATA_BUFFER_ENTRY_DTS;

#if defined DSL_63138

#define RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_DTS;

#define RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_PTR()	( RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_RX_FAST_PD_INGRESS_QUEUE_ADDRESS )

#endif

typedef struct
{
	uint8_t	reserved_fw_only	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_QUEUE_ENTRY_DTS;

#if defined DSL_63138

#define RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_DTS;

#define RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_PTR()	( RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_RX_PICO_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DS_NULL_BUFFER_SIZE     3
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DS_NULL_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_NULL_BUFFER_DTS;

#define RDD_DS_NULL_BUFFER_PTR()	( RDD_DS_NULL_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_NULL_BUFFER_ADDRESS )

#endif

typedef struct
{
	uint32_t	wfd_0_ssid_state_vector	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_1_ssid_state_vector	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_2_ssid_state_vector	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_SSID_STATS_STATE_ENTRY_DTS;

#define RDD_WLAN_MCAST_SSID_STATS_STATE_ENTRY_WFD_0_SSID_STATE_VECTOR_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_WLAN_MCAST_SSID_STATS_STATE_ENTRY_WFD_0_SSID_STATE_VECTOR_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)
#define RDD_WLAN_MCAST_SSID_STATS_STATE_ENTRY_WFD_1_SSID_STATE_VECTOR_READ(r, p)                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_WLAN_MCAST_SSID_STATS_STATE_ENTRY_WFD_1_SSID_STATE_VECTOR_WRITE(v, p)                MWRITE_16((uint8_t *)p + 2, v)
#define RDD_WLAN_MCAST_SSID_STATS_STATE_ENTRY_WFD_2_SSID_STATE_VECTOR_READ(r, p)                 MREAD_16((uint8_t *)p + 4, r)
#define RDD_WLAN_MCAST_SSID_STATS_STATE_ENTRY_WFD_2_SSID_STATE_VECTOR_WRITE(v, p)                MWRITE_16((uint8_t *)p + 4, v)

typedef struct
{
	uint16_t	ownership 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	reserved  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	skb_index 	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FREE_SKB_INDEXES_FIFO_ENTRY_DTS;

#define RDD_FREE_SKB_INDEXES_FIFO_ENTRY_OWNERSHIP_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_FREE_SKB_INDEXES_FIFO_ENTRY_OWNERSHIP_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_FREE_SKB_INDEXES_FIFO_ENTRY_SKB_INDEX_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 0, 14, r)
#define RDD_FREE_SKB_INDEXES_FIFO_ENTRY_SKB_INDEX_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 0, 14, v)

#define RDD_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_SIZE     8
typedef struct
{
	RDD_FREE_SKB_INDEXES_FIFO_ENTRY_DTS	entry[ RDD_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS;

#define RDD_DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR()	( RDD_DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_ADDRESS )

#define RDD_RUNNER_FLOW_IH_RESPONSE_RESERVED_FW_ONLY_NUMBER	2

typedef struct
{
	uint32_t	reserved_fw_only[RDD_RUNNER_FLOW_IH_RESPONSE_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FLOW_IH_RESPONSE_DTS;


typedef struct
{
	uint32_t	service_queues_status    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_status      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	scheduler_method_not_used	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	overall_rate_limiter_mode	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0                	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_SERVICE_TM_DESCRIPTOR_ENTRY_DTS;

#define RDD_DS_SERVICE_TM_DESCRIPTOR_ENTRY_SERVICE_QUEUES_STATUS_READ(r, p)                     MREAD_8((uint8_t *)p, r)
#define RDD_DS_SERVICE_TM_DESCRIPTOR_ENTRY_SERVICE_QUEUES_STATUS_WRITE(v, p)                    MWRITE_8((uint8_t *)p, v)
#define RDD_DS_SERVICE_TM_DESCRIPTOR_ENTRY_RATE_LIMITER_STATUS_READ(r, p)                       MREAD_8((uint8_t *)p + 1, r)
#define RDD_DS_SERVICE_TM_DESCRIPTOR_ENTRY_RATE_LIMITER_STATUS_WRITE(v, p)                      MWRITE_8((uint8_t *)p + 1, v)
#define RDD_DS_SERVICE_TM_DESCRIPTOR_ENTRY_SCHEDULER_METHOD_NOT_USED_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 2, 7, 1, r)
#define RDD_DS_SERVICE_TM_DESCRIPTOR_ENTRY_SCHEDULER_METHOD_NOT_USED_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 2, 7, 1, v)
#define RDD_DS_SERVICE_TM_DESCRIPTOR_ENTRY_OVERALL_RATE_LIMITER_MODE_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 2, 6, 1, r)
#define RDD_DS_SERVICE_TM_DESCRIPTOR_ENTRY_OVERALL_RATE_LIMITER_MODE_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 2, 6, 1, v)

typedef struct
{
	uint32_t	rx_bbh_descriptor_0           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rx_bbh_descriptor_1           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_bbh_descriptor_0           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_bbh_descriptor_1           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rx_packets                    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rx_octets                     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_packets                    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_octets                     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dropped_packets               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dropped_no_bpm_buffer         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dropped_parse_failed          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dropped_linear_length_invalid 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	queue_full                    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	summary                       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_header_offset              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_header_length              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_total_length               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_id                         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_fragment_flags_reserved    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_fragment_flags_df          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_fragment_flags_mf          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_fragment_offset            	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_flags                      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_protocol                   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipv4_csum                     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_header_length          	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	seg_count                     	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	nr_frags                      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	frag_index                    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_udp_header_offset         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_udp_header_length         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_udp_total_length          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_sequence                  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_flags                     	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	version                       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_udp_csum                  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mss                           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mss_adjust                    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	seg_length                    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	seg_bytes_left                	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	max_chunk_length              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	chunk_bytes_left              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_bytes_left            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_ptr                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_length                	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	linear_length                 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_packet_ptr                 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_packet_length              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	udp_first_packet_length       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	udp_first_packet_ptr          	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	udp_first_packet_buffer_number	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bpm_buffer_number             	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length                 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0                     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipv6_ip_id                    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	auth_state_3                  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	debug_0                       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_CONTEXT_ENTRY_DTS;

#define RDD_GSO_CONTEXT_ENTRY_RX_BBH_DESCRIPTOR_0_READ(r, p)                            MREAD_32((uint8_t *)p, r)
#define RDD_GSO_CONTEXT_ENTRY_RX_BBH_DESCRIPTOR_0_WRITE(v, p)                           MWRITE_32((uint8_t *)p, v)
#define RDD_GSO_CONTEXT_ENTRY_RX_BBH_DESCRIPTOR_1_READ(r, p)                            MREAD_32((uint8_t *)p + 4, r)
#define RDD_GSO_CONTEXT_ENTRY_RX_BBH_DESCRIPTOR_1_WRITE(v, p)                           MWRITE_32((uint8_t *)p + 4, v)
#define RDD_GSO_CONTEXT_ENTRY_TX_BBH_DESCRIPTOR_0_READ(r, p)                            MREAD_32((uint8_t *)p + 8, r)
#define RDD_GSO_CONTEXT_ENTRY_TX_BBH_DESCRIPTOR_0_WRITE(v, p)                           MWRITE_32((uint8_t *)p + 8, v)
#define RDD_GSO_CONTEXT_ENTRY_TX_BBH_DESCRIPTOR_1_READ(r, p)                            MREAD_32((uint8_t *)p + 12, r)
#define RDD_GSO_CONTEXT_ENTRY_TX_BBH_DESCRIPTOR_1_WRITE(v, p)                           MWRITE_32((uint8_t *)p + 12, v)
#define RDD_GSO_CONTEXT_ENTRY_RX_PACKETS_READ(r, p)                                     MREAD_32((uint8_t *)p + 16, r)
#define RDD_GSO_CONTEXT_ENTRY_RX_PACKETS_WRITE(v, p)                                    MWRITE_32((uint8_t *)p + 16, v)
#define RDD_GSO_CONTEXT_ENTRY_RX_OCTETS_READ(r, p)                                      MREAD_32((uint8_t *)p + 20, r)
#define RDD_GSO_CONTEXT_ENTRY_RX_OCTETS_WRITE(v, p)                                     MWRITE_32((uint8_t *)p + 20, v)
#define RDD_GSO_CONTEXT_ENTRY_TX_PACKETS_READ(r, p)                                     MREAD_32((uint8_t *)p + 24, r)
#define RDD_GSO_CONTEXT_ENTRY_TX_PACKETS_WRITE(v, p)                                    MWRITE_32((uint8_t *)p + 24, v)
#define RDD_GSO_CONTEXT_ENTRY_TX_OCTETS_READ(r, p)                                      MREAD_32((uint8_t *)p + 28, r)
#define RDD_GSO_CONTEXT_ENTRY_TX_OCTETS_WRITE(v, p)                                     MWRITE_32((uint8_t *)p + 28, v)
#define RDD_GSO_CONTEXT_ENTRY_DROPPED_PACKETS_READ(r, p)                                MREAD_32((uint8_t *)p + 32, r)
#define RDD_GSO_CONTEXT_ENTRY_DROPPED_PACKETS_WRITE(v, p)                               MWRITE_32((uint8_t *)p + 32, v)
#define RDD_GSO_CONTEXT_ENTRY_DROPPED_NO_BPM_BUFFER_READ(r, p)                          MREAD_16((uint8_t *)p + 36, r)
#define RDD_GSO_CONTEXT_ENTRY_DROPPED_NO_BPM_BUFFER_WRITE(v, p)                         MWRITE_16((uint8_t *)p + 36, v)
#define RDD_GSO_CONTEXT_ENTRY_DROPPED_PARSE_FAILED_READ(r, p)                           MREAD_16((uint8_t *)p + 38, r)
#define RDD_GSO_CONTEXT_ENTRY_DROPPED_PARSE_FAILED_WRITE(v, p)                          MWRITE_16((uint8_t *)p + 38, v)
#define RDD_GSO_CONTEXT_ENTRY_DROPPED_LINEAR_LENGTH_INVALID_READ(r, p)                  MREAD_16((uint8_t *)p + 40, r)
#define RDD_GSO_CONTEXT_ENTRY_DROPPED_LINEAR_LENGTH_INVALID_WRITE(v, p)                 MWRITE_16((uint8_t *)p + 40, v)
#define RDD_GSO_CONTEXT_ENTRY_QUEUE_FULL_READ(r, p)                                     MREAD_16((uint8_t *)p + 42, r)
#define RDD_GSO_CONTEXT_ENTRY_QUEUE_FULL_WRITE(v, p)                                    MWRITE_16((uint8_t *)p + 42, v)
#define RDD_GSO_CONTEXT_ENTRY_SUMMARY_READ(r, p)                                        MREAD_32((uint8_t *)p + 44, r)
#define RDD_GSO_CONTEXT_ENTRY_SUMMARY_WRITE(v, p)                                       MWRITE_32((uint8_t *)p + 44, v)
#define RDD_GSO_CONTEXT_ENTRY_IP_HEADER_OFFSET_READ(r, p)                               MREAD_8((uint8_t *)p + 48, r)
#define RDD_GSO_CONTEXT_ENTRY_IP_HEADER_OFFSET_WRITE(v, p)                              MWRITE_8((uint8_t *)p + 48, v)
#define RDD_GSO_CONTEXT_ENTRY_IP_HEADER_LENGTH_READ(r, p)                               MREAD_8((uint8_t *)p + 49, r)
#define RDD_GSO_CONTEXT_ENTRY_IP_HEADER_LENGTH_WRITE(v, p)                              MWRITE_8((uint8_t *)p + 49, v)
#define RDD_GSO_CONTEXT_ENTRY_IP_TOTAL_LENGTH_READ(r, p)                                MREAD_16((uint8_t *)p + 50, r)
#define RDD_GSO_CONTEXT_ENTRY_IP_TOTAL_LENGTH_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 50, v)
#define RDD_GSO_CONTEXT_ENTRY_IP_ID_READ(r, p)                                          MREAD_16((uint8_t *)p + 52, r)
#define RDD_GSO_CONTEXT_ENTRY_IP_ID_WRITE(v, p)                                         MWRITE_16((uint8_t *)p + 52, v)
#define RDD_GSO_CONTEXT_ENTRY_IP_FRAGMENT_FLAGS_RESERVED_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 54, 7, 1, r)
#define RDD_GSO_CONTEXT_ENTRY_IP_FRAGMENT_FLAGS_RESERVED_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 54, 7, 1, v)
#define RDD_GSO_CONTEXT_ENTRY_IP_FRAGMENT_FLAGS_DF_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 54, 6, 1, r)
#define RDD_GSO_CONTEXT_ENTRY_IP_FRAGMENT_FLAGS_DF_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 54, 6, 1, v)
#define RDD_GSO_CONTEXT_ENTRY_IP_FRAGMENT_FLAGS_MF_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 54, 5, 1, r)
#define RDD_GSO_CONTEXT_ENTRY_IP_FRAGMENT_FLAGS_MF_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 54, 5, 1, v)
#define RDD_GSO_CONTEXT_ENTRY_IP_FRAGMENT_OFFSET_READ(r, p)                             FIELD_MREAD_16((uint8_t *)p + 54, 0, 13, r)
#define RDD_GSO_CONTEXT_ENTRY_IP_FRAGMENT_OFFSET_WRITE(v, p)                            FIELD_MWRITE_16((uint8_t *)p + 54, 0, 13, v)
#define RDD_GSO_CONTEXT_ENTRY_IP_FLAGS_READ(r, p)                                       MREAD_8((uint8_t *)p + 56, r)
#define RDD_GSO_CONTEXT_ENTRY_IP_FLAGS_WRITE(v, p)                                      MWRITE_8((uint8_t *)p + 56, v)
#define RDD_GSO_CONTEXT_ENTRY_IP_PROTOCOL_READ(r, p)                                    MREAD_8((uint8_t *)p + 57, r)
#define RDD_GSO_CONTEXT_ENTRY_IP_PROTOCOL_WRITE(v, p)                                   MWRITE_8((uint8_t *)p + 57, v)
#define RDD_GSO_CONTEXT_ENTRY_IPV4_CSUM_READ(r, p)                                      MREAD_16((uint8_t *)p + 58, r)
#define RDD_GSO_CONTEXT_ENTRY_IPV4_CSUM_WRITE(v, p)                                     MWRITE_16((uint8_t *)p + 58, v)
#define RDD_GSO_CONTEXT_ENTRY_PACKET_HEADER_LENGTH_READ(r, p)                           MREAD_8((uint8_t *)p + 60, r)
#define RDD_GSO_CONTEXT_ENTRY_PACKET_HEADER_LENGTH_WRITE(v, p)                          MWRITE_8((uint8_t *)p + 60, v)
#define RDD_GSO_CONTEXT_ENTRY_SEG_COUNT_READ(r, p)                                      MREAD_8((uint8_t *)p + 61, r)
#define RDD_GSO_CONTEXT_ENTRY_SEG_COUNT_WRITE(v, p)                                     MWRITE_8((uint8_t *)p + 61, v)
#define RDD_GSO_CONTEXT_ENTRY_NR_FRAGS_READ(r, p)                                       MREAD_8((uint8_t *)p + 62, r)
#define RDD_GSO_CONTEXT_ENTRY_NR_FRAGS_WRITE(v, p)                                      MWRITE_8((uint8_t *)p + 62, v)
#define RDD_GSO_CONTEXT_ENTRY_FRAG_INDEX_READ(r, p)                                     MREAD_8((uint8_t *)p + 63, r)
#define RDD_GSO_CONTEXT_ENTRY_FRAG_INDEX_WRITE(v, p)                                    MWRITE_8((uint8_t *)p + 63, v)
#define RDD_GSO_CONTEXT_ENTRY_TCP_UDP_HEADER_OFFSET_READ(r, p)                          MREAD_8((uint8_t *)p + 64, r)
#define RDD_GSO_CONTEXT_ENTRY_TCP_UDP_HEADER_OFFSET_WRITE(v, p)                         MWRITE_8((uint8_t *)p + 64, v)
#define RDD_GSO_CONTEXT_ENTRY_TCP_UDP_HEADER_LENGTH_READ(r, p)                          MREAD_8((uint8_t *)p + 65, r)
#define RDD_GSO_CONTEXT_ENTRY_TCP_UDP_HEADER_LENGTH_WRITE(v, p)                         MWRITE_8((uint8_t *)p + 65, v)
#define RDD_GSO_CONTEXT_ENTRY_TCP_UDP_TOTAL_LENGTH_READ(r, p)                           MREAD_16((uint8_t *)p + 66, r)
#define RDD_GSO_CONTEXT_ENTRY_TCP_UDP_TOTAL_LENGTH_WRITE(v, p)                          MWRITE_16((uint8_t *)p + 66, v)
#define RDD_GSO_CONTEXT_ENTRY_TCP_SEQUENCE_READ(r, p)                                   MREAD_32((uint8_t *)p + 68, r)
#define RDD_GSO_CONTEXT_ENTRY_TCP_SEQUENCE_WRITE(v, p)                                  MWRITE_32((uint8_t *)p + 68, v)
#define RDD_GSO_CONTEXT_ENTRY_TCP_FLAGS_READ(r, p)                                      MREAD_8((uint8_t *)p + 72, r)
#define RDD_GSO_CONTEXT_ENTRY_TCP_FLAGS_WRITE(v, p)                                     MWRITE_8((uint8_t *)p + 72, v)
#define RDD_GSO_CONTEXT_ENTRY_VERSION_READ(r, p)                                        MREAD_8((uint8_t *)p + 73, r)
#define RDD_GSO_CONTEXT_ENTRY_VERSION_WRITE(v, p)                                       MWRITE_8((uint8_t *)p + 73, v)
#define RDD_GSO_CONTEXT_ENTRY_TCP_UDP_CSUM_READ(r, p)                                   MREAD_16((uint8_t *)p + 74, r)
#define RDD_GSO_CONTEXT_ENTRY_TCP_UDP_CSUM_WRITE(v, p)                                  MWRITE_16((uint8_t *)p + 74, v)
#define RDD_GSO_CONTEXT_ENTRY_MSS_READ(r, p)                                            MREAD_16((uint8_t *)p + 76, r)
#define RDD_GSO_CONTEXT_ENTRY_MSS_WRITE(v, p)                                           MWRITE_16((uint8_t *)p + 76, v)
#define RDD_GSO_CONTEXT_ENTRY_MSS_ADJUST_READ(r, p)                                     MREAD_16((uint8_t *)p + 78, r)
#define RDD_GSO_CONTEXT_ENTRY_MSS_ADJUST_WRITE(v, p)                                    MWRITE_16((uint8_t *)p + 78, v)
#define RDD_GSO_CONTEXT_ENTRY_SEG_LENGTH_READ(r, p)                                     MREAD_16((uint8_t *)p + 80, r)
#define RDD_GSO_CONTEXT_ENTRY_SEG_LENGTH_WRITE(v, p)                                    MWRITE_16((uint8_t *)p + 80, v)
#define RDD_GSO_CONTEXT_ENTRY_SEG_BYTES_LEFT_READ(r, p)                                 MREAD_16((uint8_t *)p + 82, r)
#define RDD_GSO_CONTEXT_ENTRY_SEG_BYTES_LEFT_WRITE(v, p)                                MWRITE_16((uint8_t *)p + 82, v)
#define RDD_GSO_CONTEXT_ENTRY_MAX_CHUNK_LENGTH_READ(r, p)                               MREAD_8((uint8_t *)p + 84, r)
#define RDD_GSO_CONTEXT_ENTRY_MAX_CHUNK_LENGTH_WRITE(v, p)                              MWRITE_8((uint8_t *)p + 84, v)
#define RDD_GSO_CONTEXT_ENTRY_CHUNK_BYTES_LEFT_READ(r, p)                               MREAD_8((uint8_t *)p + 85, r)
#define RDD_GSO_CONTEXT_ENTRY_CHUNK_BYTES_LEFT_WRITE(v, p)                              MWRITE_8((uint8_t *)p + 85, v)
#define RDD_GSO_CONTEXT_ENTRY_PAYLOAD_BYTES_LEFT_READ(r, p)                             MREAD_16((uint8_t *)p + 86, r)
#define RDD_GSO_CONTEXT_ENTRY_PAYLOAD_BYTES_LEFT_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 86, v)
#define RDD_GSO_CONTEXT_ENTRY_PAYLOAD_PTR_READ(r, p)                                    MREAD_32((uint8_t *)p + 88, r)
#define RDD_GSO_CONTEXT_ENTRY_PAYLOAD_PTR_WRITE(v, p)                                   MWRITE_32((uint8_t *)p + 88, v)
#define RDD_GSO_CONTEXT_ENTRY_PAYLOAD_LENGTH_READ(r, p)                                 MREAD_16((uint8_t *)p + 92, r)
#define RDD_GSO_CONTEXT_ENTRY_PAYLOAD_LENGTH_WRITE(v, p)                                MWRITE_16((uint8_t *)p + 92, v)
#define RDD_GSO_CONTEXT_ENTRY_LINEAR_LENGTH_READ(r, p)                                  MREAD_16((uint8_t *)p + 94, r)
#define RDD_GSO_CONTEXT_ENTRY_LINEAR_LENGTH_WRITE(v, p)                                 MWRITE_16((uint8_t *)p + 94, v)
#define RDD_GSO_CONTEXT_ENTRY_TX_PACKET_PTR_READ(r, p)                                  MREAD_32((uint8_t *)p + 96, r)
#define RDD_GSO_CONTEXT_ENTRY_TX_PACKET_PTR_WRITE(v, p)                                 MWRITE_32((uint8_t *)p + 96, v)
#define RDD_GSO_CONTEXT_ENTRY_TX_PACKET_LENGTH_READ(r, p)                               MREAD_16((uint8_t *)p + 100, r)
#define RDD_GSO_CONTEXT_ENTRY_TX_PACKET_LENGTH_WRITE(v, p)                              MWRITE_16((uint8_t *)p + 100, v)
#define RDD_GSO_CONTEXT_ENTRY_UDP_FIRST_PACKET_LENGTH_READ(r, p)                        MREAD_16((uint8_t *)p + 102, r)
#define RDD_GSO_CONTEXT_ENTRY_UDP_FIRST_PACKET_LENGTH_WRITE(v, p)                       MWRITE_16((uint8_t *)p + 102, v)
#define RDD_GSO_CONTEXT_ENTRY_UDP_FIRST_PACKET_PTR_READ(r, p)                           MREAD_32((uint8_t *)p + 104, r)
#define RDD_GSO_CONTEXT_ENTRY_UDP_FIRST_PACKET_PTR_WRITE(v, p)                          MWRITE_32((uint8_t *)p + 104, v)
#define RDD_GSO_CONTEXT_ENTRY_UDP_FIRST_PACKET_BUFFER_NUMBER_READ(r, p)                 MREAD_32((uint8_t *)p + 108, r)
#define RDD_GSO_CONTEXT_ENTRY_UDP_FIRST_PACKET_BUFFER_NUMBER_WRITE(v, p)                MWRITE_32((uint8_t *)p + 108, v)
#define RDD_GSO_CONTEXT_ENTRY_BPM_BUFFER_NUMBER_READ(r, p)                              MREAD_32((uint8_t *)p + 112, r)
#define RDD_GSO_CONTEXT_ENTRY_BPM_BUFFER_NUMBER_WRITE(v, p)                             MWRITE_32((uint8_t *)p + 112, v)
#define RDD_GSO_CONTEXT_ENTRY_PACKET_LENGTH_READ(r, p)                                  MREAD_16((uint8_t *)p + 116, r)
#define RDD_GSO_CONTEXT_ENTRY_PACKET_LENGTH_WRITE(v, p)                                 MWRITE_16((uint8_t *)p + 116, v)
#define RDD_GSO_CONTEXT_ENTRY_IPV6_IP_ID_READ(r, p)                                     MREAD_32((uint8_t *)p + 120, r)
#define RDD_GSO_CONTEXT_ENTRY_IPV6_IP_ID_WRITE(v, p)                                    MWRITE_32((uint8_t *)p + 120, v)
#define RDD_GSO_CONTEXT_ENTRY_AUTH_STATE_3_READ(r, p)                                   MREAD_32((uint8_t *)p + 124, r)
#define RDD_GSO_CONTEXT_ENTRY_AUTH_STATE_3_WRITE(v, p)                                  MWRITE_32((uint8_t *)p + 124, v)
#define RDD_GSO_CONTEXT_ENTRY_DEBUG_0_READ(r, p)                                        MREAD_32((uint8_t *)p + 128, r)
#define RDD_GSO_CONTEXT_ENTRY_DEBUG_0_WRITE(v, p)                                       MWRITE_32((uint8_t *)p + 128, v)

typedef struct
{
	uint32_t	reserved_fw_only	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CONNECTION_TABLE_CONFIG_DTS;


typedef struct
{
	uint32_t	reserved_fw_only	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CONTEXT_TABLE_CONFIG_DTS;

#if defined DSL_63138

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_SIZE     8
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_DTS;

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_PTR()	( RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_ADDRESS )

#endif

typedef struct
{
	uint32_t	ring_value  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = ring_value, size = 32 bits
	uint32_t	request_id  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0   	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	buffer_type 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1   	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2   	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ownership   	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3   	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	status      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_ring_id	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_COMPLETE_RING_ENTRY_DTS;

#define RDD_DHD_COMPLETE_RING_ENTRY_RING_VALUE_READ(r, p)                   MREAD_32((uint8_t *)p, r)
#define RDD_DHD_COMPLETE_RING_ENTRY_RING_VALUE_WRITE(v, p)                  MWRITE_32((uint8_t *)p, v)
#define RDD_DHD_COMPLETE_RING_ENTRY_RING_VALUE_L_READ( wv )                 FIELD_GET( wv, 0, 32 )
#define RDD_DHD_COMPLETE_RING_ENTRY_RING_VALUE_L_WRITE( v, wv )             FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_COMPLETE_RING_ENTRY_REQUEST_ID_READ(r, p)                   MREAD_32((uint8_t *)p, r)
#define RDD_DHD_COMPLETE_RING_ENTRY_REQUEST_ID_WRITE(v, p)                  MWRITE_32((uint8_t *)p, v)
#define RDD_DHD_COMPLETE_RING_ENTRY_REQUEST_ID_L_READ( wv )                 FIELD_GET( wv, 0, 32 )
#define RDD_DHD_COMPLETE_RING_ENTRY_REQUEST_ID_L_WRITE( v, wv )             FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_COMPLETE_RING_ENTRY_BUFFER_TYPE_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p, 0, 2, r)
#define RDD_DHD_COMPLETE_RING_ENTRY_BUFFER_TYPE_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p, 0, 2, v)
#define RDD_DHD_COMPLETE_RING_ENTRY_BUFFER_TYPE_L_READ( wv )                FIELD_GET( wv, 24, 2 )
#define RDD_DHD_COMPLETE_RING_ENTRY_BUFFER_TYPE_L_WRITE( v, wv )            FIELD_SET( v, 24, 2, wv )
#define RDD_DHD_COMPLETE_RING_ENTRY_OWNERSHIP_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p, 0, 2, r)
#define RDD_DHD_COMPLETE_RING_ENTRY_OWNERSHIP_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p, 0, 2, v)
#define RDD_DHD_COMPLETE_RING_ENTRY_OWNERSHIP_L_READ( wv )                  FIELD_GET( wv, 24, 2 )
#define RDD_DHD_COMPLETE_RING_ENTRY_OWNERSHIP_L_WRITE( v, wv )              FIELD_SET( v, 24, 2, wv )
#define RDD_DHD_COMPLETE_RING_ENTRY_STATUS_READ(r, p)                       MREAD_16((uint8_t *)p + 4, r)
#define RDD_DHD_COMPLETE_RING_ENTRY_STATUS_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 4, v)
#define RDD_DHD_COMPLETE_RING_ENTRY_STATUS_L_READ( wv )                     FIELD_GET( wv, 16, 16 )
#define RDD_DHD_COMPLETE_RING_ENTRY_STATUS_L_WRITE( v, wv )                 FIELD_SET( v, 16, 16, wv )
#define RDD_DHD_COMPLETE_RING_ENTRY_FLOW_RING_ID_READ(r, p)                 MREAD_16((uint8_t *)p + 6, r)
#define RDD_DHD_COMPLETE_RING_ENTRY_FLOW_RING_ID_WRITE(v, p)                MWRITE_16((uint8_t *)p + 6, v)
#define RDD_DHD_COMPLETE_RING_ENTRY_FLOW_RING_ID_L_READ( wv )               FIELD_GET( wv, 0, 16 )
#define RDD_DHD_COMPLETE_RING_ENTRY_FLOW_RING_ID_L_WRITE( v, wv )           FIELD_SET( v, 0, 16, wv )
#if defined DSL_63138

#define RDD_DHD_COMPLETE_RING_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_COMPLETE_RING_ENTRY_DTS	entry[ RDD_DHD_COMPLETE_RING_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_COMPLETE_RING_BUFFER_DTS;

#define RDD_DHD_COMPLETE_RING_BUFFER_PTR()	( RDD_DHD_COMPLETE_RING_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DHD_COMPLETE_RING_BUFFER_ADDRESS )

#endif

typedef struct
{
	uint8_t	ih_buffer 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PARALLEL_PROCESSING_ENTRY_DTS;

#define RDD_PARALLEL_PROCESSING_ENTRY_IH_BUFFER_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_PARALLEL_PROCESSING_ENTRY_IH_BUFFER_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#if defined DSL_63138

#define RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_SIZE     4
typedef struct
{
	RDD_PARALLEL_PROCESSING_ENTRY_DTS	entry[ RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_DTS;

#define RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR()	( RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_ADDRESS )

#endif
#define RDD_MULTICAST_HEADER_BUFFER_RESERVED_FW_ONLY_NUMBER	16

typedef struct
{
	uint32_t	reserved_fw_only[RDD_MULTICAST_HEADER_BUFFER_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_MULTICAST_HEADER_BUFFER_DTS;

#if defined DSL_63138

#define RDD_GPON_RX_NORMAL_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_GPON_RX_NORMAL_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_RX_NORMAL_DESCRIPTORS_DTS;

#define RDD_GPON_RX_NORMAL_DESCRIPTORS_PTR()	( RDD_GPON_RX_NORMAL_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GPON_RX_NORMAL_DESCRIPTORS_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_DTS;

#define RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_PTR()	( RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_MULTICAST_INGRESS_QUEUE_ADDRESS )

#endif

typedef struct
{
	uint16_t	primitive_address	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPE_COMMAND_PRIMITIVE_ENTRY_DTS;

#define RDD_GPE_COMMAND_PRIMITIVE_ENTRY_PRIMITIVE_ADDRESS_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_GPE_COMMAND_PRIMITIVE_ENTRY_PRIMITIVE_ADDRESS_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)
#if defined DSL_63138

#define RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_SIZE     32
typedef struct
{
	RDD_GPE_COMMAND_PRIMITIVE_ENTRY_DTS	entry[ RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_DTS;

#define RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_PTR()	( RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_GPE_COMMAND_PRIMITIVE_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DS_ROUTER_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DS_ROUTER_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_ROUTER_INGRESS_QUEUE_DTS;

#define RDD_DS_ROUTER_INGRESS_QUEUE_PTR()	( RDD_DS_ROUTER_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_ROUTER_INGRESS_QUEUE_ADDRESS )

#endif

typedef struct
{
	uint32_t	msg_type             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	if_id                	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	common_hdr_flags     	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	epoch                	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	request_id           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_eth_hdr_0         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_eth_hdr_1         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_eth_hdr_2         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_eth_hdr_3         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flags                	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	seg_cnt              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	metadata_buf_addr_low	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	metadata_buf_addr_hi 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_buf_addr_low    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_buf_addr_hi     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	meta_buf_len         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_len             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved             	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_DESCRIPTOR_DTS;

#define RDD_DHD_TX_POST_DESCRIPTOR_MSG_TYPE_READ(r, p)                              MREAD_8((uint8_t *)p, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_MSG_TYPE_WRITE(v, p)                             MWRITE_8((uint8_t *)p, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_MSG_TYPE_L_READ( wv )                            FIELD_GET( wv, 24, 8 )
#define RDD_DHD_TX_POST_DESCRIPTOR_MSG_TYPE_L_WRITE( v, wv )                        FIELD_SET( v, 24, 8, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_IF_ID_READ(r, p)                                 MREAD_8((uint8_t *)p + 1, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_IF_ID_WRITE(v, p)                                MWRITE_8((uint8_t *)p + 1, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_IF_ID_L_READ( wv )                               FIELD_GET( wv, 16, 8 )
#define RDD_DHD_TX_POST_DESCRIPTOR_IF_ID_L_WRITE( v, wv )                           FIELD_SET( v, 16, 8, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_COMMON_HDR_FLAGS_READ(r, p)                      MREAD_8((uint8_t *)p + 2, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_COMMON_HDR_FLAGS_WRITE(v, p)                     MWRITE_8((uint8_t *)p + 2, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_COMMON_HDR_FLAGS_L_READ( wv )                    FIELD_GET( wv, 8, 8 )
#define RDD_DHD_TX_POST_DESCRIPTOR_COMMON_HDR_FLAGS_L_WRITE( v, wv )                FIELD_SET( v, 8, 8, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_EPOCH_READ(r, p)                                 MREAD_8((uint8_t *)p + 3, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_EPOCH_WRITE(v, p)                                MWRITE_8((uint8_t *)p + 3, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_EPOCH_L_READ( wv )                               FIELD_GET( wv, 0, 8 )
#define RDD_DHD_TX_POST_DESCRIPTOR_EPOCH_L_WRITE( v, wv )                           FIELD_SET( v, 0, 8, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_REQUEST_ID_READ(r, p)                            MREAD_32((uint8_t *)p + 4, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_REQUEST_ID_WRITE(v, p)                           MWRITE_32((uint8_t *)p + 4, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_REQUEST_ID_L_READ( wv )                          FIELD_GET( wv, 0, 32 )
#define RDD_DHD_TX_POST_DESCRIPTOR_REQUEST_ID_L_WRITE( v, wv )                      FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_0_READ(r, p)                          MREAD_32((uint8_t *)p + 8, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_0_WRITE(v, p)                         MWRITE_32((uint8_t *)p + 8, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_0_L_READ( wv )                        FIELD_GET( wv, 0, 32 )
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_0_L_WRITE( v, wv )                    FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_1_READ(r, p)                          MREAD_32((uint8_t *)p + 12, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_1_WRITE(v, p)                         MWRITE_32((uint8_t *)p + 12, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_1_L_READ( wv )                        FIELD_GET( wv, 0, 32 )
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_1_L_WRITE( v, wv )                    FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_2_READ(r, p)                          MREAD_32((uint8_t *)p + 16, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_2_WRITE(v, p)                         MWRITE_32((uint8_t *)p + 16, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_2_L_READ( wv )                        FIELD_GET( wv, 0, 32 )
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_2_L_WRITE( v, wv )                    FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_3_READ(r, p)                          MREAD_16((uint8_t *)p + 20, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_3_WRITE(v, p)                         MWRITE_16((uint8_t *)p + 20, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_3_L_READ( wv )                        FIELD_GET( wv, 16, 16 )
#define RDD_DHD_TX_POST_DESCRIPTOR_TX_ETH_HDR_3_L_WRITE( v, wv )                    FIELD_SET( v, 16, 16, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_FLAGS_READ(r, p)                                 MREAD_8((uint8_t *)p + 22, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_FLAGS_WRITE(v, p)                                MWRITE_8((uint8_t *)p + 22, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_FLAGS_L_READ( wv )                               FIELD_GET( wv, 8, 8 )
#define RDD_DHD_TX_POST_DESCRIPTOR_FLAGS_L_WRITE( v, wv )                           FIELD_SET( v, 8, 8, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_SEG_CNT_READ(r, p)                               MREAD_8((uint8_t *)p + 23, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_SEG_CNT_WRITE(v, p)                              MWRITE_8((uint8_t *)p + 23, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_SEG_CNT_L_READ( wv )                             FIELD_GET( wv, 0, 8 )
#define RDD_DHD_TX_POST_DESCRIPTOR_SEG_CNT_L_WRITE( v, wv )                         FIELD_SET( v, 0, 8, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_METADATA_BUF_ADDR_LOW_READ(r, p)                 MREAD_32((uint8_t *)p + 24, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_METADATA_BUF_ADDR_LOW_WRITE(v, p)                MWRITE_32((uint8_t *)p + 24, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_METADATA_BUF_ADDR_LOW_L_READ( wv )               FIELD_GET( wv, 0, 32 )
#define RDD_DHD_TX_POST_DESCRIPTOR_METADATA_BUF_ADDR_LOW_L_WRITE( v, wv )           FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_METADATA_BUF_ADDR_HI_READ(r, p)                  MREAD_32((uint8_t *)p + 28, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_METADATA_BUF_ADDR_HI_WRITE(v, p)                 MWRITE_32((uint8_t *)p + 28, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_METADATA_BUF_ADDR_HI_L_READ( wv )                FIELD_GET( wv, 0, 32 )
#define RDD_DHD_TX_POST_DESCRIPTOR_METADATA_BUF_ADDR_HI_L_WRITE( v, wv )            FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_DATA_BUF_ADDR_LOW_READ(r, p)                     MREAD_32((uint8_t *)p + 32, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_DATA_BUF_ADDR_LOW_WRITE(v, p)                    MWRITE_32((uint8_t *)p + 32, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_DATA_BUF_ADDR_LOW_L_READ( wv )                   FIELD_GET( wv, 0, 32 )
#define RDD_DHD_TX_POST_DESCRIPTOR_DATA_BUF_ADDR_LOW_L_WRITE( v, wv )               FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_DATA_BUF_ADDR_HI_READ(r, p)                      MREAD_32((uint8_t *)p + 36, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_DATA_BUF_ADDR_HI_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 36, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_DATA_BUF_ADDR_HI_L_READ( wv )                    FIELD_GET( wv, 0, 32 )
#define RDD_DHD_TX_POST_DESCRIPTOR_DATA_BUF_ADDR_HI_L_WRITE( v, wv )                FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_META_BUF_LEN_READ(r, p)                          MREAD_16((uint8_t *)p + 40, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_META_BUF_LEN_WRITE(v, p)                         MWRITE_16((uint8_t *)p + 40, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_META_BUF_LEN_L_READ( wv )                        FIELD_GET( wv, 16, 16 )
#define RDD_DHD_TX_POST_DESCRIPTOR_META_BUF_LEN_L_WRITE( v, wv )                    FIELD_SET( v, 16, 16, wv )
#define RDD_DHD_TX_POST_DESCRIPTOR_DATA_LEN_READ(r, p)                              MREAD_16((uint8_t *)p + 42, r)
#define RDD_DHD_TX_POST_DESCRIPTOR_DATA_LEN_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 42, v)
#define RDD_DHD_TX_POST_DESCRIPTOR_DATA_LEN_L_READ( wv )                            FIELD_GET( wv, 0, 16 )
#define RDD_DHD_TX_POST_DESCRIPTOR_DATA_LEN_L_WRITE( v, wv )                        FIELD_SET( v, 0, 16, wv )
#if defined DSL_63138

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_SIZE     8
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_DTS;

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_PTR()	( RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_DTS;

#define RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_PTR()	( RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_RX_FAST_INGRESS_QUEUE_ADDRESS )

#endif

typedef struct
{
	uint32_t	reserved_fw_only	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DEBUG_BUFFER_ENTRY_DTS;

#if defined DSL_63138

#define RDD_DS_DEBUG_BUFFER_SIZE     32
typedef struct
{
	RDD_DEBUG_BUFFER_ENTRY_DTS	entry[ RDD_DS_DEBUG_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DEBUG_BUFFER_DTS;

#define RDD_DS_DEBUG_BUFFER_PTR()	( RDD_DS_DEBUG_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_DEBUG_BUFFER_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DS_FW_MAC_ADDRS_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DS_FW_MAC_ADDRS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FW_MAC_ADDRS_DTS;

#define RDD_DS_FW_MAC_ADDRS_PTR()	( RDD_DS_FW_MAC_ADDRS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FW_MAC_ADDRS_ADDRESS )

#endif

typedef struct
{
	uint32_t	valid                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlan_head_index        	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bucket_overflow_counter	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	command_list_length_64 	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_extend             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_multicast           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	protocol               	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	number_of_tags         	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2              	:30	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_ip                 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_ip                 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_CONNECTION_ENTRY_DTS;

#define RDD_FC_MCAST_CONNECTION_ENTRY_VALID_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_FC_MCAST_CONNECTION_ENTRY_VALID_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_FC_MCAST_CONNECTION_ENTRY_VLAN_HEAD_INDEX_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p, 0, 7, r)
#define RDD_FC_MCAST_CONNECTION_ENTRY_VLAN_HEAD_INDEX_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p, 0, 7, v)
#define RDD_FC_MCAST_CONNECTION_ENTRY_BUCKET_OVERFLOW_COUNTER_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 2, 5, 3, r)
#define RDD_FC_MCAST_CONNECTION_ENTRY_BUCKET_OVERFLOW_COUNTER_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 2, 5, 3, v)
#define RDD_FC_MCAST_CONNECTION_ENTRY_COMMAND_LIST_LENGTH_64_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 2, 1, 4, r)
#define RDD_FC_MCAST_CONNECTION_ENTRY_COMMAND_LIST_LENGTH_64_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 2, 1, 4, v)
#define RDD_FC_MCAST_CONNECTION_ENTRY_KEY_EXTEND_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 2, 0, 1, r)
#define RDD_FC_MCAST_CONNECTION_ENTRY_KEY_EXTEND_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 2, 0, 1, v)
#define RDD_FC_MCAST_CONNECTION_ENTRY_IS_MULTICAST_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 3, 7, 1, r)
#define RDD_FC_MCAST_CONNECTION_ENTRY_IS_MULTICAST_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 3, 7, 1, v)
#define RDD_FC_MCAST_CONNECTION_ENTRY_PROTOCOL_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 3, 0, 7, r)
#define RDD_FC_MCAST_CONNECTION_ENTRY_PROTOCOL_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 3, 0, 7, v)
#define RDD_FC_MCAST_CONNECTION_ENTRY_NUMBER_OF_TAGS_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 4, 6, 2, r)
#define RDD_FC_MCAST_CONNECTION_ENTRY_NUMBER_OF_TAGS_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 4, 6, 2, v)
#define RDD_FC_MCAST_CONNECTION_ENTRY_SRC_IP_READ(r, p)                                  MREAD_32((uint8_t *)p + 8, r)
#define RDD_FC_MCAST_CONNECTION_ENTRY_SRC_IP_WRITE(v, p)                                 MWRITE_32((uint8_t *)p + 8, v)
#define RDD_FC_MCAST_CONNECTION_ENTRY_DST_IP_READ(r, p)                                  MREAD_32((uint8_t *)p + 12, r)
#define RDD_FC_MCAST_CONNECTION_ENTRY_DST_IP_WRITE(v, p)                                 MWRITE_32((uint8_t *)p + 12, v)

typedef struct
{
	uint32_t	state                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2             	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	lag_port              	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_high_prio          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_length      	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_push               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_command_list_length	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	queue                 	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_offset             	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_PORT_CONTEXT_ENTRY_DTS;

#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_STATE_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_STATE_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_LAG_PORT_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 1, 6, 2, r)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_LAG_PORT_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 1, 6, 2, v)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_IS_HIGH_PRIO_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 1, 5, 1, r)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_IS_HIGH_PRIO_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 1, 5, 1, v)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_L2_HEADER_LENGTH_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 1, 0, 5, r)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_L2_HEADER_LENGTH_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 1, 0, 5, v)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_L2_PUSH_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 2, 7, 1, r)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_L2_PUSH_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 2, 7, 1, v)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_L2_COMMAND_LIST_LENGTH_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 2, 0, 7, r)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_L2_COMMAND_LIST_LENGTH_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 2, 0, 7, v)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_QUEUE_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 3, 5, 3, r)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_QUEUE_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 3, 5, 3, v)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_L2_OFFSET_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 3, 0, 5, r)
#define RDD_FC_MCAST_PORT_CONTEXT_ENTRY_L2_OFFSET_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 3, 0, 5, v)

typedef struct
{
	uint8_t	reserved_fw_only	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PARALLEL_PROCESSING_TASK_REORDER_ENTRY_DTS;

#if defined DSL_63138

#define RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_SIZE     4
typedef struct
{
	RDD_PARALLEL_PROCESSING_TASK_REORDER_ENTRY_DTS	entry[ RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_DTS;

#define RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_PTR()	( RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DS_DATA_POINTER_DUMMY_TARGET_SIZE     5
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DS_DATA_POINTER_DUMMY_TARGET_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DATA_POINTER_DUMMY_TARGET_DTS;

#define RDD_DS_DATA_POINTER_DUMMY_TARGET_PTR()	( RDD_DS_DATA_POINTER_DUMMY_TARGET_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_DATA_POINTER_DUMMY_TARGET_ADDRESS )

#endif

typedef struct
{
	uint32_t	reserved_fw_only	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FIREWALL_IPV6_R16_BUFFER_ENTRY_DTS;

#if defined DSL_63138

#define RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_SIZE     8
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_DTS;

#define RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_PTR()	( RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DS_DHD_TX_POST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DS_DHD_TX_POST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DHD_TX_POST_INGRESS_QUEUE_DTS;

#define RDD_DS_DHD_TX_POST_INGRESS_QUEUE_PTR()	( RDD_DS_DHD_TX_POST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_DHD_TX_POST_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DS_DHD_FLOW_RING_DROP_COUNTER_SIZE     5
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DS_DHD_FLOW_RING_DROP_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DHD_FLOW_RING_DROP_COUNTER_DTS;

#define RDD_DS_DHD_FLOW_RING_DROP_COUNTER_PTR()	( RDD_DS_DHD_FLOW_RING_DROP_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_DHD_FLOW_RING_DROP_COUNTER_ADDRESS )

#endif

typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPTV_COUNTERS_BUFFER_DTS;


typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_PICO_INGRESS_QUEUE_PTR_DTS;


typedef struct
{
	uint32_t	dhd_context_ptr 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dhd_host_buf_ptr	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dhd_l2_buf      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ret_addr        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY_DTS;

#define RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY_DHD_CONTEXT_PTR_READ(r, p)                  MREAD_16((uint8_t *)p, r)
#define RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY_DHD_CONTEXT_PTR_WRITE(v, p)                 MWRITE_16((uint8_t *)p, v)
#define RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY_DHD_HOST_BUF_PTR_READ(r, p)                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY_DHD_HOST_BUF_PTR_WRITE(v, p)                MWRITE_16((uint8_t *)p + 2, v)
#define RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY_DHD_L2_BUF_READ(r, p)                       MREAD_16((uint8_t *)p + 4, r)
#define RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY_DHD_L2_BUF_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 4, v)
#define RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY_RET_ADDR_READ(r, p)                         MREAD_16((uint8_t *)p + 6, r)
#define RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY_RET_ADDR_WRITE(v, p)                        MWRITE_16((uint8_t *)p + 6, v)

#define RDD_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_SIZE     8
typedef struct
{
	RDD_FREE_SKB_INDEXES_FIFO_ENTRY_DTS	entry[ RDD_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS;

#define RDD_DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR()	( RDD_DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_ADDRESS )

#define RDD_HASH_BUFFER_RESERVED_FW_ONLY_NUMBER	4

typedef struct
{
	uint32_t	reserved_fw_only[RDD_HASH_BUFFER_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_HASH_BUFFER_DTS;


typedef struct
{
	uint32_t	valid            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	command          	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipsec            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu_rx_queue     	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	upstream         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sa_update        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sa_index         	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length    	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs_flag         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1        	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error            	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	esphdr_offset    	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs_address_index	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_IPSEC_DTS;

#define RDD_CPU_TX_DESCRIPTOR_IPSEC_VALID_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_VALID_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_VALID_L_READ( wv )                           FIELD_GET( wv, 31, 1 )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_VALID_L_WRITE( v, wv )                       FIELD_SET( v, 31, 1, wv )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_COMMAND_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p, 4, 3, r)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_COMMAND_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p, 4, 3, v)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_COMMAND_L_READ( wv )                         FIELD_GET( wv, 28, 3 )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_COMMAND_L_WRITE( v, wv )                     FIELD_SET( v, 28, 3, wv )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_IPSEC_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p, 2, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_IPSEC_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p, 2, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_IPSEC_L_READ( wv )                           FIELD_GET( wv, 26, 1 )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_IPSEC_L_WRITE( v, wv )                       FIELD_SET( v, 26, 1, wv )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_CPU_RX_QUEUE_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p, 6, 4, r)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_CPU_RX_QUEUE_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p, 6, 4, v)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_CPU_RX_QUEUE_L_READ( wv )                    FIELD_GET( wv, 22, 4 )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_CPU_RX_QUEUE_L_WRITE( v, wv )                FIELD_SET( v, 22, 4, wv )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_UPSTREAM_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 1, 5, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_UPSTREAM_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 1, 5, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_UPSTREAM_L_READ( wv )                        FIELD_GET( wv, 21, 1 )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_UPSTREAM_L_WRITE( v, wv )                    FIELD_SET( v, 21, 1, wv )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_SA_UPDATE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 1, 4, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_SA_UPDATE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 1, 4, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_SA_UPDATE_L_READ( wv )                       FIELD_GET( wv, 20, 1 )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_SA_UPDATE_L_WRITE( v, wv )                   FIELD_SET( v, 20, 1, wv )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_SA_INDEX_READ(r, p)                          FIELD_MREAD_32((uint8_t *)p + 0, 14, 6, r)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_SA_INDEX_WRITE(v, p)                         FIELD_MWRITE_32((uint8_t *)p + 0, 14, 6, v)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_SA_INDEX_L_READ( wv )                        FIELD_GET( wv, 14, 6 )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_SA_INDEX_L_WRITE( v, wv )                    FIELD_SET( v, 14, 6, wv )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_PACKET_LENGTH_READ(r, p)                     FIELD_MREAD_16((uint8_t *)p + 2, 0, 14, r)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_PACKET_LENGTH_WRITE(v, p)                    FIELD_MWRITE_16((uint8_t *)p + 2, 0, 14, v)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_PACKET_LENGTH_L_READ( wv )                   FIELD_GET( wv, 0, 14 )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_PACKET_LENGTH_L_WRITE( v, wv )               FIELD_SET( v, 0, 14, wv )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ABS_FLAG_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ABS_FLAG_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ABS_FLAG_L_READ( wv )                        FIELD_GET( wv, 31, 1 )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ABS_FLAG_L_WRITE( v, wv )                    FIELD_SET( v, 31, 1, wv )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ERROR_READ(r, p)                             FIELD_MREAD_16((uint8_t *)p + 4, 6, 3, r)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ERROR_WRITE(v, p)                            FIELD_MWRITE_16((uint8_t *)p + 4, 6, 3, v)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ERROR_L_READ( wv )                           FIELD_GET( wv, 22, 3 )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ERROR_L_WRITE( v, wv )                       FIELD_SET( v, 22, 3, wv )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ESPHDR_OFFSET_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 5, 0, 6, r)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ESPHDR_OFFSET_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 5, 0, 6, v)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ESPHDR_OFFSET_L_READ( wv )                   FIELD_GET( wv, 16, 6 )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ESPHDR_OFFSET_L_WRITE( v, wv )               FIELD_SET( v, 16, 6, wv )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ABS_ADDRESS_INDEX_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 6, 0, 15, r)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ABS_ADDRESS_INDEX_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 6, 0, 15, v)
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ABS_ADDRESS_INDEX_L_READ( wv )               FIELD_GET( wv, 0, 15 )
#define RDD_CPU_TX_DESCRIPTOR_IPSEC_ABS_ADDRESS_INDEX_L_WRITE( v, wv )           FIELD_SET( v, 0, 15, wv )

typedef struct
{
	uint32_t	reserved0    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error        	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu_rx_queue 	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	upstream     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2    	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_DESCRIPTOR_IPSEC_DTS;

#define RDD_CPU_RX_DESCRIPTOR_IPSEC_ERROR_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p, 4, 3, r)
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_ERROR_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p, 4, 3, v)
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_ERROR_L_READ( wv )                       FIELD_GET( wv, 28, 3 )
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_ERROR_L_WRITE( v, wv )                   FIELD_SET( v, 28, 3, wv )
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_CPU_RX_QUEUE_READ(r, p)                  FIELD_MREAD_16((uint8_t *)p, 6, 4, r)
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_CPU_RX_QUEUE_WRITE(v, p)                 FIELD_MWRITE_16((uint8_t *)p, 6, 4, v)
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_CPU_RX_QUEUE_L_READ( wv )                FIELD_GET( wv, 22, 4 )
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_CPU_RX_QUEUE_L_WRITE( v, wv )            FIELD_SET( v, 22, 4, wv )
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_UPSTREAM_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 1, 5, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_UPSTREAM_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 1, 5, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_UPSTREAM_L_READ( wv )                    FIELD_GET( wv, 21, 1 )
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_UPSTREAM_L_WRITE( v, wv )                FIELD_SET( v, 21, 1, wv )
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_PACKET_LENGTH_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 2, 0, 14, r)
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_PACKET_LENGTH_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 2, 0, 14, v)
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_PACKET_LENGTH_L_READ( wv )               FIELD_GET( wv, 0, 14 )
#define RDD_CPU_RX_DESCRIPTOR_IPSEC_PACKET_LENGTH_L_WRITE( v, wv )           FIELD_SET( v, 0, 14, wv )
#if defined DSL_63138

#define RDD_WLAN_MCAST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_WLAN_MCAST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_INGRESS_QUEUE_DTS;

#define RDD_WLAN_MCAST_INGRESS_QUEUE_PTR()	( RDD_WLAN_MCAST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + WLAN_MCAST_INGRESS_QUEUE_ADDRESS )

#endif

typedef struct
{
	uint32_t	mtu_minus_40                      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	us_padding_max_size               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	us_padding_cpu_max_size           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop_precedence_eligibility_vector	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_ether_type_1               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_ether_type_2               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_ether_type_3               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timer_scheduler_period            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	active_policers_vector            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policers_period                   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ds_rate_shaper_timer              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	us_rate_controller_timer          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	us_rate_limit_sustain_budget_limit	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hash_based_forwarding_port_count  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inter_lan_scheduling_mode         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	broadcom_switch_port              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mirroring_port                    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ds_connection_miss_action         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	us_pci_flow_cache_enable          	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	global_ingress_config             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pci_ls_dp_eligibility_vector      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ds_ingress_policers_mode          	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	debug_mode                        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SYSTEM_CONFIGURATION_DTS;

#define RDD_SYSTEM_CONFIGURATION_MTU_MINUS_40_READ(r, p)                                       MREAD_16((uint8_t *)p, r)
#define RDD_SYSTEM_CONFIGURATION_MTU_MINUS_40_WRITE(v, p)                                      MWRITE_16((uint8_t *)p, v)
#define RDD_SYSTEM_CONFIGURATION_US_PADDING_MAX_SIZE_READ(r, p)                                MREAD_16((uint8_t *)p + 2, r)
#define RDD_SYSTEM_CONFIGURATION_US_PADDING_MAX_SIZE_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 2, v)
#define RDD_SYSTEM_CONFIGURATION_US_PADDING_CPU_MAX_SIZE_READ(r, p)                            MREAD_16((uint8_t *)p + 4, r)
#define RDD_SYSTEM_CONFIGURATION_US_PADDING_CPU_MAX_SIZE_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 4, v)
#define RDD_SYSTEM_CONFIGURATION_DROP_PRECEDENCE_ELIGIBILITY_VECTOR_READ(r, p)                 MREAD_16((uint8_t *)p + 6, r)
#define RDD_SYSTEM_CONFIGURATION_DROP_PRECEDENCE_ELIGIBILITY_VECTOR_WRITE(v, p)                MWRITE_16((uint8_t *)p + 6, v)
#define RDD_SYSTEM_CONFIGURATION_EGRESS_ETHER_TYPE_1_READ(r, p)                                MREAD_16((uint8_t *)p + 8, r)
#define RDD_SYSTEM_CONFIGURATION_EGRESS_ETHER_TYPE_1_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 8, v)
#define RDD_SYSTEM_CONFIGURATION_EGRESS_ETHER_TYPE_2_READ(r, p)                                MREAD_16((uint8_t *)p + 10, r)
#define RDD_SYSTEM_CONFIGURATION_EGRESS_ETHER_TYPE_2_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 10, v)
#define RDD_SYSTEM_CONFIGURATION_EGRESS_ETHER_TYPE_3_READ(r, p)                                MREAD_16((uint8_t *)p + 12, r)
#define RDD_SYSTEM_CONFIGURATION_EGRESS_ETHER_TYPE_3_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 12, v)
#define RDD_SYSTEM_CONFIGURATION_TIMER_SCHEDULER_PERIOD_READ(r, p)                             MREAD_16((uint8_t *)p + 14, r)
#define RDD_SYSTEM_CONFIGURATION_TIMER_SCHEDULER_PERIOD_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 14, v)
#define RDD_SYSTEM_CONFIGURATION_ACTIVE_POLICERS_VECTOR_READ(r, p)                             MREAD_16((uint8_t *)p + 16, r)
#define RDD_SYSTEM_CONFIGURATION_ACTIVE_POLICERS_VECTOR_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 16, v)
#define RDD_SYSTEM_CONFIGURATION_POLICERS_PERIOD_READ(r, p)                                    MREAD_16((uint8_t *)p + 18, r)
#define RDD_SYSTEM_CONFIGURATION_POLICERS_PERIOD_WRITE(v, p)                                   MWRITE_16((uint8_t *)p + 18, v)
#define RDD_SYSTEM_CONFIGURATION_DS_RATE_SHAPER_TIMER_READ(r, p)                               MREAD_16((uint8_t *)p + 20, r)
#define RDD_SYSTEM_CONFIGURATION_DS_RATE_SHAPER_TIMER_WRITE(v, p)                              MWRITE_16((uint8_t *)p + 20, v)
#define RDD_SYSTEM_CONFIGURATION_US_RATE_CONTROLLER_TIMER_READ(r, p)                           MREAD_16((uint8_t *)p + 22, r)
#define RDD_SYSTEM_CONFIGURATION_US_RATE_CONTROLLER_TIMER_WRITE(v, p)                          MWRITE_16((uint8_t *)p + 22, v)
#define RDD_SYSTEM_CONFIGURATION_US_RATE_LIMIT_SUSTAIN_BUDGET_LIMIT_READ(r, p)                 MREAD_8((uint8_t *)p + 24, r)
#define RDD_SYSTEM_CONFIGURATION_US_RATE_LIMIT_SUSTAIN_BUDGET_LIMIT_WRITE(v, p)                MWRITE_8((uint8_t *)p + 24, v)
#define RDD_SYSTEM_CONFIGURATION_HASH_BASED_FORWARDING_PORT_COUNT_READ(r, p)                   MREAD_8((uint8_t *)p + 25, r)
#define RDD_SYSTEM_CONFIGURATION_HASH_BASED_FORWARDING_PORT_COUNT_WRITE(v, p)                  MWRITE_8((uint8_t *)p + 25, v)
#define RDD_SYSTEM_CONFIGURATION_INTER_LAN_SCHEDULING_MODE_READ(r, p)                          MREAD_8((uint8_t *)p + 26, r)
#define RDD_SYSTEM_CONFIGURATION_INTER_LAN_SCHEDULING_MODE_WRITE(v, p)                         MWRITE_8((uint8_t *)p + 26, v)
#define RDD_SYSTEM_CONFIGURATION_BROADCOM_SWITCH_PORT_READ(r, p)                               MREAD_8((uint8_t *)p + 27, r)
#define RDD_SYSTEM_CONFIGURATION_BROADCOM_SWITCH_PORT_WRITE(v, p)                              MWRITE_8((uint8_t *)p + 27, v)
#define RDD_SYSTEM_CONFIGURATION_MIRRORING_PORT_READ(r, p)                                     MREAD_8((uint8_t *)p + 28, r)
#define RDD_SYSTEM_CONFIGURATION_MIRRORING_PORT_WRITE(v, p)                                    MWRITE_8((uint8_t *)p + 28, v)
#define RDD_SYSTEM_CONFIGURATION_DS_CONNECTION_MISS_ACTION_READ(r, p)                          MREAD_8((uint8_t *)p + 29, r)
#define RDD_SYSTEM_CONFIGURATION_DS_CONNECTION_MISS_ACTION_WRITE(v, p)                         MWRITE_8((uint8_t *)p + 29, v)
#define RDD_SYSTEM_CONFIGURATION_US_PCI_FLOW_CACHE_ENABLE_READ(r, p)                           MREAD_8((uint8_t *)p + 30, r)
#define RDD_SYSTEM_CONFIGURATION_US_PCI_FLOW_CACHE_ENABLE_WRITE(v, p)                          MWRITE_8((uint8_t *)p + 30, v)
#define RDD_SYSTEM_CONFIGURATION_GLOBAL_INGRESS_CONFIG_READ(r, p)                              MREAD_8((uint8_t *)p + 31, r)
#define RDD_SYSTEM_CONFIGURATION_GLOBAL_INGRESS_CONFIG_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 31, v)
#define RDD_SYSTEM_CONFIGURATION_PCI_LS_DP_ELIGIBILITY_VECTOR_READ(r, p)                       MREAD_16((uint8_t *)p + 32, r)
#define RDD_SYSTEM_CONFIGURATION_PCI_LS_DP_ELIGIBILITY_VECTOR_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 32, v)
#define RDD_SYSTEM_CONFIGURATION_DS_INGRESS_POLICERS_MODE_READ(r, p)                           MREAD_8((uint8_t *)p + 34, r)
#define RDD_SYSTEM_CONFIGURATION_DS_INGRESS_POLICERS_MODE_WRITE(v, p)                          MWRITE_8((uint8_t *)p + 34, v)
#define RDD_SYSTEM_CONFIGURATION_DEBUG_MODE_READ(r, p)                                         MREAD_8((uint8_t *)p + 35, r)
#define RDD_SYSTEM_CONFIGURATION_DEBUG_MODE_WRITE(v, p)                                        MWRITE_8((uint8_t *)p + 35, v)

typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FREE_PACKET_DESCRIPTORS_POOL_THRESHOLD_DTS;

#if defined DSL_63138

#define RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_SIZE     8
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_DTS;

#define RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_PTR()	( RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_ADDRESS )

#endif

typedef struct
{
	uint8_t	physical_port	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BROADCOM_SWITCH_PORT_MAPPING_DTS;

#define RDD_BROADCOM_SWITCH_PORT_MAPPING_PHYSICAL_PORT_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_BROADCOM_SWITCH_PORT_MAPPING_PHYSICAL_PORT_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#if defined DSL_63138

#define RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_SIZE     16
typedef struct
{
	RDD_BROADCOM_SWITCH_PORT_MAPPING_DTS	entry[ RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_DTS;

#define RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_PTR()	( RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_ADDRESS )

#endif

typedef struct
{
	uint16_t	sa_desc_idx	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_SA_DESC_CAM_DTS;

#define RDD_IPSEC_SA_DESC_CAM_SA_DESC_IDX_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_IPSEC_SA_DESC_CAM_SA_DESC_IDX_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)
#define RDD_IPSEC_SA_DESC_CAM_SA_DESC_IDX_L_READ( wv )               FIELD_GET( wv, 0, 16 )
#define RDD_IPSEC_SA_DESC_CAM_SA_DESC_IDX_L_WRITE( v, wv )           FIELD_SET( v, 0, 16, wv )
#if defined DSL_63138

#define RDD_IPSEC_DS_SA_DESC_CAM_TABLE_SIZE     16
typedef struct
{
	RDD_IPSEC_SA_DESC_CAM_DTS	entry[ RDD_IPSEC_DS_SA_DESC_CAM_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_SA_DESC_CAM_TABLE_DTS;

#define RDD_IPSEC_DS_SA_DESC_CAM_TABLE_PTR()	( RDD_IPSEC_DS_SA_DESC_CAM_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_DS_SA_DESC_CAM_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_IPSEC_US_SA_DESC_CAM_TABLE_SIZE     16
typedef struct
{
	RDD_IPSEC_SA_DESC_CAM_DTS	entry[ RDD_IPSEC_US_SA_DESC_CAM_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_US_SA_DESC_CAM_TABLE_DTS;

#define RDD_IPSEC_US_SA_DESC_CAM_TABLE_PTR()	( RDD_IPSEC_US_SA_DESC_CAM_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_US_SA_DESC_CAM_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_ETH_TX_SCRATCH_SIZE     16
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_ETH_TX_SCRATCH_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_SCRATCH_DTS;

#define RDD_ETH_TX_SCRATCH_PTR()	( RDD_ETH_TX_SCRATCH_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_SCRATCH_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_GSO_TX_DHD_L2_BUFFER_SIZE     22
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_GSO_TX_DHD_L2_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_TX_DHD_L2_BUFFER_DTS;

#define RDD_GSO_TX_DHD_L2_BUFFER_PTR()	( RDD_GSO_TX_DHD_L2_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GSO_TX_DHD_L2_BUFFER_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_CPU_TX_DHD_L2_BUFFER_SIZE     22
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_CPU_TX_DHD_L2_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DHD_L2_BUFFER_DTS;

#define RDD_CPU_TX_DHD_L2_BUFFER_PTR()	( RDD_CPU_TX_DHD_L2_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_TX_DHD_L2_BUFFER_ADDRESS )

#endif

typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_PICO_INGRESS_QUEUE_PTR_DTS;

#if defined DSL_63138

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_SIZE     5
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_DTS;

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_PTR()	( RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_ADDRESS )

#endif
#if defined DSL_63138

typedef struct
{
	uint8_t	status_vector	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_EMACS_STATUS_ENTRY_DTS;

#define RDD_ETH_TX_EMACS_STATUS_ENTRY_STATUS_VECTOR_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_ETH_TX_EMACS_STATUS_ENTRY_STATUS_VECTOR_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#endif

typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BPM_DDR_BUFFER_HEADROOM_SIZE_DTS;

#define RDD_SIXTEEN_BYTES_RESERVED_FW_ONLY_NUMBER	4

typedef struct
{
	uint32_t	reserved_fw_only[RDD_SIXTEEN_BYTES_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SIXTEEN_BYTES_DTS;


typedef struct
{
	uint32_t	request_id  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_buf_ptr	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_buf_len	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_buffer   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	radio_idx   	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wifi_ssid   	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_ring_id	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1   	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	eth_tx_queue	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_CONTEXT_ENTRY_DTS;

#define RDD_DHD_TX_POST_CONTEXT_ENTRY_REQUEST_ID_READ(r, p)                   MREAD_32((uint8_t *)p, r)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_REQUEST_ID_WRITE(v, p)                  MWRITE_32((uint8_t *)p, v)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_DATA_BUF_PTR_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_DATA_BUF_PTR_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_DATA_BUF_LEN_READ(r, p)                 MREAD_16((uint8_t *)p + 8, r)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_DATA_BUF_LEN_WRITE(v, p)                MWRITE_16((uint8_t *)p + 8, v)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_L2_BUFFER_READ(r, p)                    MREAD_16((uint8_t *)p + 10, r)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_L2_BUFFER_WRITE(v, p)                   MWRITE_16((uint8_t *)p + 10, v)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_RADIO_IDX_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 12, 6, 2, r)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_RADIO_IDX_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 12, 6, 2, v)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_WIFI_SSID_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 12, 2, 4, r)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_WIFI_SSID_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 12, 2, 4, v)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_FLOW_RING_ID_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 12, 0, 10, r)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_FLOW_RING_ID_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 12, 0, 10, v)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_ETH_TX_QUEUE_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 15, 0, 3, r)
#define RDD_DHD_TX_POST_CONTEXT_ENTRY_ETH_TX_QUEUE_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 15, 0, 3, v)

typedef struct
{
	uint8_t	egress_port	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_HASH_BASED_FORWARDING_PORT_ENTRY_DTS;

#define RDD_HASH_BASED_FORWARDING_PORT_ENTRY_EGRESS_PORT_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_HASH_BASED_FORWARDING_PORT_ENTRY_EGRESS_PORT_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#if defined DSL_63138

#define RDD_HASH_BASED_FORWARDING_PORT_TABLE_SIZE     4
typedef struct
{
	RDD_HASH_BASED_FORWARDING_PORT_ENTRY_DTS	entry[ RDD_HASH_BASED_FORWARDING_PORT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_HASH_BASED_FORWARDING_PORT_TABLE_DTS;

#define RDD_HASH_BASED_FORWARDING_PORT_TABLE_PTR()	( RDD_HASH_BASED_FORWARDING_PORT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + HASH_BASED_FORWARDING_PORT_TABLE_ADDRESS )

#endif

typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION_DTS;


typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_FAST_INGRESS_QUEUE_PTR_DTS;


typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PARALLEL_PROCESSING_IH_BUFFER_PTR_DTS;


typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ANY_SRC_PORT_FLOW_COUNTER_DTS;

#if defined DSL_63138

#define RDD_GSO_TX_DHD_HOST_BUF_PTR_SIZE     4
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_GSO_TX_DHD_HOST_BUF_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_TX_DHD_HOST_BUF_PTR_DTS;

#define RDD_GSO_TX_DHD_HOST_BUF_PTR_PTR()	( RDD_GSO_TX_DHD_HOST_BUF_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GSO_TX_DHD_HOST_BUF_PTR_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_CPU_TX_DHD_HOST_BUF_PTR_SIZE     4
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_CPU_TX_DHD_HOST_BUF_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DHD_HOST_BUF_PTR_DTS;

#define RDD_CPU_TX_DHD_HOST_BUF_PTR_PTR()	( RDD_CPU_TX_DHD_HOST_BUF_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_TX_DHD_HOST_BUF_PTR_ADDRESS )

#endif

typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_PHYSICAL_PORT_DTS;


typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_CONGESTION_STATE_ENTRY_DTS;


typedef struct
{
	uint8_t	dummy_store	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DUMMY_STORE_ENTRY_DTS;

#define RDD_DUMMY_STORE_ENTRY_DUMMY_STORE_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_DUMMY_STORE_ENTRY_DUMMY_STORE_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#if defined DSL_63138

typedef struct
{
	uint8_t	emac_offset	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_INTER_LAN_SCHEDULING_OFFSET_ENTRY_DTS;

#define RDD_ETH_TX_INTER_LAN_SCHEDULING_OFFSET_ENTRY_EMAC_OFFSET_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_ETH_TX_INTER_LAN_SCHEDULING_OFFSET_ENTRY_EMAC_OFFSET_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#endif

typedef struct
{
	uint8_t	reserved0       	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	available_slave3	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	available_slave2	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	available_slave1	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	available_slave0	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PARALLEL_PROCESSING_SLAVE_VECTOR_DTS;

#define RDD_PARALLEL_PROCESSING_SLAVE_VECTOR_AVAILABLE_SLAVE3_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 3, 1, r)
#define RDD_PARALLEL_PROCESSING_SLAVE_VECTOR_AVAILABLE_SLAVE3_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 3, 1, v)
#define RDD_PARALLEL_PROCESSING_SLAVE_VECTOR_AVAILABLE_SLAVE2_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 2, 1, r)
#define RDD_PARALLEL_PROCESSING_SLAVE_VECTOR_AVAILABLE_SLAVE2_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 2, 1, v)
#define RDD_PARALLEL_PROCESSING_SLAVE_VECTOR_AVAILABLE_SLAVE1_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 1, 1, r)
#define RDD_PARALLEL_PROCESSING_SLAVE_VECTOR_AVAILABLE_SLAVE1_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 1, 1, v)
#define RDD_PARALLEL_PROCESSING_SLAVE_VECTOR_AVAILABLE_SLAVE0_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 0, 1, r)
#define RDD_PARALLEL_PROCESSING_SLAVE_VECTOR_AVAILABLE_SLAVE0_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 0, 1, v)
/* PRIVATE_B */
#if defined DSL_63138

#define RDD_US_INGRESS_HANDLER_BUFFER_SIZE     32
typedef struct
{
	RDD_IH_BUFFER_DTS	entry[ RDD_US_INGRESS_HANDLER_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_HANDLER_BUFFER_DTS;

#define RDD_US_INGRESS_HANDLER_BUFFER_PTR()	( RDD_US_INGRESS_HANDLER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_HANDLER_BUFFER_ADDRESS )

#endif
#define RDD_CSO_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER	32

typedef struct
{
	uint32_t	reserved_fw_only[RDD_CSO_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CSO_BUFFER_ENTRY_DTS;

#define RDD_CSO_PSEUDO_HEADER_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER	10

typedef struct
{
	uint32_t	reserved_fw_only[RDD_CSO_PSEUDO_HEADER_BUFFER_ENTRY_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CSO_PSEUDO_HEADER_BUFFER_ENTRY_DTS;

#define RDD_US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE_PTR()	( RDD_US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE_ADDRESS )

#if defined DSL_63138

#define RDD_US_CPU_REASON_TO_METER_TABLE_SIZE     64
typedef struct
{
	RDD_CPU_REASON_TO_METER_ENTRY_DTS	entry[ RDD_US_CPU_REASON_TO_METER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_REASON_TO_METER_TABLE_DTS;

#define RDD_US_CPU_REASON_TO_METER_TABLE_PTR()	( RDD_US_CPU_REASON_TO_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_REASON_TO_METER_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_MAIN_PROFILING_BUFFER_RUNNER_SIZE     32
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_US_MAIN_PROFILING_BUFFER_RUNNER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_MAIN_PROFILING_BUFFER_RUNNER_DTS;

#define RDD_US_MAIN_PROFILING_BUFFER_RUNNER_PTR()	( RDD_US_MAIN_PROFILING_BUFFER_RUNNER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_MAIN_PROFILING_BUFFER_RUNNER_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_RUNNER_FLOW_HEADER_BUFFER_SIZE     3
typedef struct
{
	RDD_RUNNER_FLOW_HEADER_BUFFER_DTS	entry[ RDD_US_RUNNER_FLOW_HEADER_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RUNNER_FLOW_HEADER_BUFFER_DTS;

#define RDD_US_RUNNER_FLOW_HEADER_BUFFER_PTR()	( RDD_US_RUNNER_FLOW_HEADER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RUNNER_FLOW_HEADER_BUFFER_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_QUEUE_PROFILE_TABLE_SIZE     8
typedef struct
{
	RDD_QUEUE_PROFILE_DTS	entry[ RDD_US_QUEUE_PROFILE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_QUEUE_PROFILE_TABLE_DTS;

#define RDD_US_QUEUE_PROFILE_TABLE_PTR()	( RDD_US_QUEUE_PROFILE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_QUEUE_PROFILE_TABLE_ADDRESS )

#endif
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_CONTROLLER_ADDR_NUMBER	4

typedef struct
{
	uint32_t	reserved0                                                                           	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_priority                                                               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_mode                                                                   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	schedule                                                                            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_destination                                                                     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_controllers_status                                                             	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_controllers_sustain_vector                                                     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_controllers_peak_vector                                                        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_burst_counter                                                                  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_offset                                                                         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_scheduling_mode                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                                           	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ack_pending_epon                                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ack_pending                                                                         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	byte_counter                                                                        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	rate_controller_addr[RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_CONTROLLER_ADDR_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_CHANNEL_8_39_DESCRIPTOR_DTS;

#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_LIMITER_PRIORITY_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p, 1, 1, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_LIMITER_PRIORITY_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p, 1, 1, v)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_LIMITER_MODE_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p, 0, 1, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_LIMITER_MODE_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p, 0, 1, v)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_SCHEDULE_READ(r, p)                                        MREAD_8((uint8_t *)p + 1, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_SCHEDULE_WRITE(v, p)                                       MWRITE_8((uint8_t *)p + 1, v)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_BBH_DESTINATION_READ(r, p)                                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_BBH_DESTINATION_WRITE(v, p)                                MWRITE_16((uint8_t *)p + 2, v)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_CONTROLLERS_STATUS_READ(r, p)                         MREAD_32((uint8_t *)p + 4, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_CONTROLLERS_STATUS_WRITE(v, p)                        MWRITE_32((uint8_t *)p + 4, v)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_CONTROLLERS_SUSTAIN_VECTOR_READ(r, p)                 MREAD_32((uint8_t *)p + 8, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_CONTROLLERS_SUSTAIN_VECTOR_WRITE(v, p)                MWRITE_32((uint8_t *)p + 8, v)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_CONTROLLERS_PEAK_VECTOR_READ(r, p)                    MREAD_32((uint8_t *)p + 12, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_CONTROLLERS_PEAK_VECTOR_WRITE(v, p)                   MWRITE_32((uint8_t *)p + 12, v)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_PEAK_BURST_COUNTER_READ(r, p)                              MREAD_16((uint8_t *)p + 16, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_PEAK_BURST_COUNTER_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 16, v)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_PEAK_OFFSET_READ(r, p)                                     MREAD_8((uint8_t *)p + 18, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_PEAK_OFFSET_WRITE(v, p)                                    MWRITE_8((uint8_t *)p + 18, v)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_PEAK_SCHEDULING_MODE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 19, 7, 1, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_PEAK_SCHEDULING_MODE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 19, 7, 1, v)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_ACK_PENDING_EPON_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 19, 1, 1, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_ACK_PENDING_EPON_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 19, 1, 1, v)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_ACK_PENDING_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 19, 0, 1, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_ACK_PENDING_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 19, 0, 1, v)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_BYTE_COUNTER_READ(r, p)                                    MREAD_32((uint8_t *)p + 20, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_BYTE_COUNTER_WRITE(v, p)                                   MWRITE_32((uint8_t *)p + 20, v)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_CONTROLLER_ADDR_READ(r, p, i)                         MREAD_I_16((uint8_t *)p + 24, i, r)
#define RDD_WAN_CHANNEL_8_39_DESCRIPTOR_RATE_CONTROLLER_ADDR_WRITE(v, p, i)                        MWRITE_I_16((uint8_t *)p + 24, i, v)
#if defined DSL_63138

#define RDD_WAN_CHANNELS_8_39_TABLE_SIZE     32
typedef struct
{
	RDD_WAN_CHANNEL_8_39_DESCRIPTOR_DTS	entry[ RDD_WAN_CHANNELS_8_39_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_CHANNELS_8_39_TABLE_DTS;

#define RDD_WAN_CHANNELS_8_39_TABLE_PTR()	( RDD_WAN_CHANNELS_8_39_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + WAN_CHANNELS_8_39_TABLE_ADDRESS )

#endif
#define RDD_US_POLICER_TABLE_PTR()	( RDD_US_POLICER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_POLICER_TABLE_ADDRESS )

#define RDD_US_CPU_RX_METER_TABLE_PTR()	( RDD_US_CPU_RX_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_RX_METER_TABLE_ADDRESS )

#if defined DSL_63138

#define RDD_US_CPU_TX_BBH_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY_DTS	entry[ RDD_US_CPU_TX_BBH_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_TX_BBH_DESCRIPTORS_DTS;

#define RDD_US_CPU_TX_BBH_DESCRIPTORS_PTR()	( RDD_US_CPU_TX_BBH_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_TX_BBH_DESCRIPTORS_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_FORWARDING_MATRIX_TABLE_SIZE     9
#define RDD_US_FORWARDING_MATRIX_TABLE_SIZE2    16
typedef struct
{
	RDD_FORWARDING_MATRIX_ENTRY_DTS	entry[ RDD_US_FORWARDING_MATRIX_TABLE_SIZE ][ RDD_US_FORWARDING_MATRIX_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FORWARDING_MATRIX_TABLE_DTS;

#define RDD_US_FORWARDING_MATRIX_TABLE_PTR()	( RDD_US_FORWARDING_MATRIX_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FORWARDING_MATRIX_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_SIZE     8
typedef struct
{
	RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY_DTS	entry[ RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_DTS;

#define RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_PTR()	( RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_TIMER_SCHEDULER_PRIMITIVE_TABLE_ADDRESS )

#endif
#define RDD_US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_PTR()	( RDD_US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS )


typedef struct
{
	uint32_t	reserved0                         	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ptm_bonding                       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	traffic_class_to_queue_table_index	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wan_channel_id                    	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pbits_to_queue_table_index        	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	crc_calc                          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wan_port_id_or_fstat              	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_WAN_FLOW_ENTRY_DTS;

#define RDD_US_WAN_FLOW_ENTRY_PTM_BONDING_READ(r, p)                                        FIELD_MREAD_8((uint8_t *)p, 1, 1, r)
#define RDD_US_WAN_FLOW_ENTRY_PTM_BONDING_WRITE(v, p)                                       FIELD_MWRITE_8((uint8_t *)p, 1, 1, v)
#define RDD_US_WAN_FLOW_ENTRY_TRAFFIC_CLASS_TO_QUEUE_TABLE_INDEX_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 6, 3, r)
#define RDD_US_WAN_FLOW_ENTRY_TRAFFIC_CLASS_TO_QUEUE_TABLE_INDEX_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 6, 3, v)
#define RDD_US_WAN_FLOW_ENTRY_WAN_CHANNEL_ID_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 1, 0, 6, r)
#define RDD_US_WAN_FLOW_ENTRY_WAN_CHANNEL_ID_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 1, 0, 6, v)
#define RDD_US_WAN_FLOW_ENTRY_PBITS_TO_QUEUE_TABLE_INDEX_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 2, 5, 3, r)
#define RDD_US_WAN_FLOW_ENTRY_PBITS_TO_QUEUE_TABLE_INDEX_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 2, 5, 3, v)
#define RDD_US_WAN_FLOW_ENTRY_CRC_CALC_READ(r, p)                                           FIELD_MREAD_8((uint8_t *)p + 2, 4, 1, r)
#define RDD_US_WAN_FLOW_ENTRY_CRC_CALC_WRITE(v, p)                                          FIELD_MWRITE_8((uint8_t *)p + 2, 4, 1, v)
#define RDD_US_WAN_FLOW_ENTRY_WAN_PORT_ID_OR_FSTAT_READ(r, p)                               FIELD_MREAD_16((uint8_t *)p + 2, 0, 12, r)
#define RDD_US_WAN_FLOW_ENTRY_WAN_PORT_ID_OR_FSTAT_WRITE(v, p)                              FIELD_MWRITE_16((uint8_t *)p + 2, 0, 12, v)
#if defined DSL_63138

#define RDD_US_WAN_FLOW_TABLE_SIZE     256
typedef struct
{
	RDD_US_WAN_FLOW_ENTRY_DTS	entry[ RDD_US_WAN_FLOW_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_WAN_FLOW_TABLE_DTS;

#define RDD_US_WAN_FLOW_TABLE_PTR()	( RDD_US_WAN_FLOW_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_WAN_FLOW_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_SIZE     32
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_DTS;

#define RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_PTR()	( RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_HANDLER_SKB_DATA_POINTER_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_SIZE     16
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_ADDRESS )

#endif

typedef struct
{
	uint8_t	queue          	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	rate_controller	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_QUEUE_ENTRY_DTS;

#define RDD_US_QUEUE_ENTRY_QUEUE_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p, 5, 3, r)
#define RDD_US_QUEUE_ENTRY_QUEUE_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p, 5, 3, v)
#define RDD_US_QUEUE_ENTRY_RATE_CONTROLLER_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 0, 5, r)
#define RDD_US_QUEUE_ENTRY_RATE_CONTROLLER_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 0, 5, v)
#if defined DSL_63138

#define RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_SIZE     8
#define RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_SIZE2    8
typedef struct
{
	RDD_US_QUEUE_ENTRY_DTS	entry[ RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_SIZE ][ RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_DTS;

#define RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_PTR()	( RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_TRAFFIC_CLASS_TO_QUEUE_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS;

#define RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_PTR()	( RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS;

#define RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_PTR()	( RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_SIZE     32
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_RATE_LIMITER_TABLE_SIZE     16
typedef struct
{
	RDD_RATE_LIMITER_ENTRY_DTS	entry[ RDD_US_RATE_LIMITER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RATE_LIMITER_TABLE_DTS;

#define RDD_US_RATE_LIMITER_TABLE_PTR()	( RDD_US_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RATE_LIMITER_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	msg_type             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	if_id                	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	common_hdr_flags     	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	epoch                	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	request_id           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	meta_buf_len         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_len             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved             	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	metadata_buf_addr_low	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	metadata_buf_addr_hi 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_buf_addr_low    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_buf_addr_hi     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_POST_DESCRIPTOR_DTS;

#define RDD_DHD_RX_POST_DESCRIPTOR_MSG_TYPE_READ(r, p)                              MREAD_8((uint8_t *)p, r)
#define RDD_DHD_RX_POST_DESCRIPTOR_MSG_TYPE_WRITE(v, p)                             MWRITE_8((uint8_t *)p, v)
#define RDD_DHD_RX_POST_DESCRIPTOR_MSG_TYPE_L_READ( wv )                            FIELD_GET( wv, 24, 8 )
#define RDD_DHD_RX_POST_DESCRIPTOR_MSG_TYPE_L_WRITE( v, wv )                        FIELD_SET( v, 24, 8, wv )
#define RDD_DHD_RX_POST_DESCRIPTOR_IF_ID_READ(r, p)                                 MREAD_8((uint8_t *)p + 1, r)
#define RDD_DHD_RX_POST_DESCRIPTOR_IF_ID_WRITE(v, p)                                MWRITE_8((uint8_t *)p + 1, v)
#define RDD_DHD_RX_POST_DESCRIPTOR_IF_ID_L_READ( wv )                               FIELD_GET( wv, 16, 8 )
#define RDD_DHD_RX_POST_DESCRIPTOR_IF_ID_L_WRITE( v, wv )                           FIELD_SET( v, 16, 8, wv )
#define RDD_DHD_RX_POST_DESCRIPTOR_COMMON_HDR_FLAGS_READ(r, p)                      MREAD_8((uint8_t *)p + 2, r)
#define RDD_DHD_RX_POST_DESCRIPTOR_COMMON_HDR_FLAGS_WRITE(v, p)                     MWRITE_8((uint8_t *)p + 2, v)
#define RDD_DHD_RX_POST_DESCRIPTOR_COMMON_HDR_FLAGS_L_READ( wv )                    FIELD_GET( wv, 8, 8 )
#define RDD_DHD_RX_POST_DESCRIPTOR_COMMON_HDR_FLAGS_L_WRITE( v, wv )                FIELD_SET( v, 8, 8, wv )
#define RDD_DHD_RX_POST_DESCRIPTOR_EPOCH_READ(r, p)                                 MREAD_8((uint8_t *)p + 3, r)
#define RDD_DHD_RX_POST_DESCRIPTOR_EPOCH_WRITE(v, p)                                MWRITE_8((uint8_t *)p + 3, v)
#define RDD_DHD_RX_POST_DESCRIPTOR_EPOCH_L_READ( wv )                               FIELD_GET( wv, 0, 8 )
#define RDD_DHD_RX_POST_DESCRIPTOR_EPOCH_L_WRITE( v, wv )                           FIELD_SET( v, 0, 8, wv )
#define RDD_DHD_RX_POST_DESCRIPTOR_REQUEST_ID_READ(r, p)                            MREAD_32((uint8_t *)p + 4, r)
#define RDD_DHD_RX_POST_DESCRIPTOR_REQUEST_ID_WRITE(v, p)                           MWRITE_32((uint8_t *)p + 4, v)
#define RDD_DHD_RX_POST_DESCRIPTOR_REQUEST_ID_L_READ( wv )                          FIELD_GET( wv, 0, 32 )
#define RDD_DHD_RX_POST_DESCRIPTOR_REQUEST_ID_L_WRITE( v, wv )                      FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_RX_POST_DESCRIPTOR_META_BUF_LEN_READ(r, p)                          MREAD_16((uint8_t *)p + 8, r)
#define RDD_DHD_RX_POST_DESCRIPTOR_META_BUF_LEN_WRITE(v, p)                         MWRITE_16((uint8_t *)p + 8, v)
#define RDD_DHD_RX_POST_DESCRIPTOR_META_BUF_LEN_L_READ( wv )                        FIELD_GET( wv, 16, 16 )
#define RDD_DHD_RX_POST_DESCRIPTOR_META_BUF_LEN_L_WRITE( v, wv )                    FIELD_SET( v, 16, 16, wv )
#define RDD_DHD_RX_POST_DESCRIPTOR_DATA_LEN_READ(r, p)                              MREAD_16((uint8_t *)p + 10, r)
#define RDD_DHD_RX_POST_DESCRIPTOR_DATA_LEN_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 10, v)
#define RDD_DHD_RX_POST_DESCRIPTOR_DATA_LEN_L_READ( wv )                            FIELD_GET( wv, 0, 16 )
#define RDD_DHD_RX_POST_DESCRIPTOR_DATA_LEN_L_WRITE( v, wv )                        FIELD_SET( v, 0, 16, wv )
#define RDD_DHD_RX_POST_DESCRIPTOR_METADATA_BUF_ADDR_LOW_READ(r, p)                 MREAD_32((uint8_t *)p + 16, r)
#define RDD_DHD_RX_POST_DESCRIPTOR_METADATA_BUF_ADDR_LOW_WRITE(v, p)                MWRITE_32((uint8_t *)p + 16, v)
#define RDD_DHD_RX_POST_DESCRIPTOR_METADATA_BUF_ADDR_LOW_L_READ( wv )               FIELD_GET( wv, 0, 32 )
#define RDD_DHD_RX_POST_DESCRIPTOR_METADATA_BUF_ADDR_LOW_L_WRITE( v, wv )           FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_RX_POST_DESCRIPTOR_METADATA_BUF_ADDR_HI_READ(r, p)                  MREAD_32((uint8_t *)p + 20, r)
#define RDD_DHD_RX_POST_DESCRIPTOR_METADATA_BUF_ADDR_HI_WRITE(v, p)                 MWRITE_32((uint8_t *)p + 20, v)
#define RDD_DHD_RX_POST_DESCRIPTOR_METADATA_BUF_ADDR_HI_L_READ( wv )                FIELD_GET( wv, 0, 32 )
#define RDD_DHD_RX_POST_DESCRIPTOR_METADATA_BUF_ADDR_HI_L_WRITE( v, wv )            FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_RX_POST_DESCRIPTOR_DATA_BUF_ADDR_LOW_READ(r, p)                     MREAD_32((uint8_t *)p + 24, r)
#define RDD_DHD_RX_POST_DESCRIPTOR_DATA_BUF_ADDR_LOW_WRITE(v, p)                    MWRITE_32((uint8_t *)p + 24, v)
#define RDD_DHD_RX_POST_DESCRIPTOR_DATA_BUF_ADDR_LOW_L_READ( wv )                   FIELD_GET( wv, 0, 32 )
#define RDD_DHD_RX_POST_DESCRIPTOR_DATA_BUF_ADDR_LOW_L_WRITE( v, wv )               FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_RX_POST_DESCRIPTOR_DATA_BUF_ADDR_HI_READ(r, p)                      MREAD_32((uint8_t *)p + 28, r)
#define RDD_DHD_RX_POST_DESCRIPTOR_DATA_BUF_ADDR_HI_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 28, v)
#define RDD_DHD_RX_POST_DESCRIPTOR_DATA_BUF_ADDR_HI_L_READ( wv )                    FIELD_GET( wv, 0, 32 )
#define RDD_DHD_RX_POST_DESCRIPTOR_DATA_BUF_ADDR_HI_L_WRITE( v, wv )                FIELD_SET( v, 0, 32, wv )

typedef struct
{
	uint32_t	msg_type            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	if_id               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	common_hdr_flags    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	epoch               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	request_id          	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	compl_msg_hdr_status	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_ring_id        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	meta_buf_len        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_len            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_offset         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flags               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rx_status_0         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rx_status_1         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dma_done_mark       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_COMPLETE_DESCRIPTOR_DTS;

#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_MSG_TYPE_READ(r, p)                             MREAD_8((uint8_t *)p, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_MSG_TYPE_WRITE(v, p)                            MWRITE_8((uint8_t *)p, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_MSG_TYPE_L_READ( wv )                           FIELD_GET( wv, 24, 8 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_MSG_TYPE_L_WRITE( v, wv )                       FIELD_SET( v, 24, 8, wv )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_IF_ID_READ(r, p)                                MREAD_8((uint8_t *)p + 1, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_IF_ID_WRITE(v, p)                               MWRITE_8((uint8_t *)p + 1, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_IF_ID_L_READ( wv )                              FIELD_GET( wv, 16, 8 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_IF_ID_L_WRITE( v, wv )                          FIELD_SET( v, 16, 8, wv )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_COMMON_HDR_FLAGS_READ(r, p)                     MREAD_8((uint8_t *)p + 2, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_COMMON_HDR_FLAGS_WRITE(v, p)                    MWRITE_8((uint8_t *)p + 2, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_COMMON_HDR_FLAGS_L_READ( wv )                   FIELD_GET( wv, 8, 8 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_COMMON_HDR_FLAGS_L_WRITE( v, wv )               FIELD_SET( v, 8, 8, wv )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_EPOCH_READ(r, p)                                MREAD_8((uint8_t *)p + 3, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_EPOCH_WRITE(v, p)                               MWRITE_8((uint8_t *)p + 3, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_EPOCH_L_READ( wv )                              FIELD_GET( wv, 0, 8 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_EPOCH_L_WRITE( v, wv )                          FIELD_SET( v, 0, 8, wv )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_REQUEST_ID_READ(r, p)                           MREAD_32((uint8_t *)p + 4, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_REQUEST_ID_WRITE(v, p)                          MWRITE_32((uint8_t *)p + 4, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_REQUEST_ID_L_READ( wv )                         FIELD_GET( wv, 0, 32 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_REQUEST_ID_L_WRITE( v, wv )                     FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_COMPL_MSG_HDR_STATUS_READ(r, p)                 MREAD_16((uint8_t *)p + 8, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_COMPL_MSG_HDR_STATUS_WRITE(v, p)                MWRITE_16((uint8_t *)p + 8, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_COMPL_MSG_HDR_STATUS_L_READ( wv )               FIELD_GET( wv, 16, 16 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_COMPL_MSG_HDR_STATUS_L_WRITE( v, wv )           FIELD_SET( v, 16, 16, wv )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_FLOW_RING_ID_READ(r, p)                         MREAD_16((uint8_t *)p + 10, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_FLOW_RING_ID_WRITE(v, p)                        MWRITE_16((uint8_t *)p + 10, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_FLOW_RING_ID_L_READ( wv )                       FIELD_GET( wv, 0, 16 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_FLOW_RING_ID_L_WRITE( v, wv )                   FIELD_SET( v, 0, 16, wv )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_META_BUF_LEN_READ(r, p)                         MREAD_16((uint8_t *)p + 12, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_META_BUF_LEN_WRITE(v, p)                        MWRITE_16((uint8_t *)p + 12, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_META_BUF_LEN_L_READ( wv )                       FIELD_GET( wv, 16, 16 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_META_BUF_LEN_L_WRITE( v, wv )                   FIELD_SET( v, 16, 16, wv )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_DATA_LEN_READ(r, p)                             MREAD_16((uint8_t *)p + 14, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_DATA_LEN_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 14, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_DATA_LEN_L_READ( wv )                           FIELD_GET( wv, 0, 16 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_DATA_LEN_L_WRITE( v, wv )                       FIELD_SET( v, 0, 16, wv )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_DATA_OFFSET_READ(r, p)                          MREAD_16((uint8_t *)p + 16, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_DATA_OFFSET_WRITE(v, p)                         MWRITE_16((uint8_t *)p + 16, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_DATA_OFFSET_L_READ( wv )                        FIELD_GET( wv, 16, 16 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_DATA_OFFSET_L_WRITE( v, wv )                    FIELD_SET( v, 16, 16, wv )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_FLAGS_READ(r, p)                                MREAD_16((uint8_t *)p + 18, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_FLAGS_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 18, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_FLAGS_L_READ( wv )                              FIELD_GET( wv, 0, 16 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_FLAGS_L_WRITE( v, wv )                          FIELD_SET( v, 0, 16, wv )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_RX_STATUS_0_READ(r, p)                          MREAD_32((uint8_t *)p + 20, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_RX_STATUS_0_WRITE(v, p)                         MWRITE_32((uint8_t *)p + 20, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_RX_STATUS_0_L_READ( wv )                        FIELD_GET( wv, 0, 32 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_RX_STATUS_0_L_WRITE( v, wv )                    FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_RX_STATUS_1_READ(r, p)                          MREAD_32((uint8_t *)p + 24, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_RX_STATUS_1_WRITE(v, p)                         MWRITE_32((uint8_t *)p + 24, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_RX_STATUS_1_L_READ( wv )                        FIELD_GET( wv, 0, 32 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_RX_STATUS_1_L_WRITE( v, wv )                    FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_DMA_DONE_MARK_READ(r, p)                        MREAD_32((uint8_t *)p + 28, r)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_DMA_DONE_MARK_WRITE(v, p)                       MWRITE_32((uint8_t *)p + 28, v)
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_DMA_DONE_MARK_L_READ( wv )                      FIELD_GET( wv, 0, 32 )
#define RDD_DHD_RX_COMPLETE_DESCRIPTOR_DMA_DONE_MARK_L_WRITE( v, wv )                  FIELD_SET( v, 0, 32, wv )
#define RDD_US_PICO_TIMER_TASK_DESCRIPTOR_TABLE_PTR()	( RDD_US_PICO_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS )

#if defined DSL_63138

#define RDD_US_CONNECTION_CONTEXT_BUFFER_SIZE     8
typedef struct
{
	RDD_CONNECTION_CONTEXT_BUFFER_ENTRY_DTS	entry[ RDD_US_CONNECTION_CONTEXT_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CONNECTION_CONTEXT_BUFFER_DTS;

#define RDD_US_CONNECTION_CONTEXT_BUFFER_PTR()	( RDD_US_CONNECTION_CONTEXT_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CONNECTION_CONTEXT_BUFFER_ADDRESS )

#endif

typedef struct
{
	uint32_t	vlan_cmd_index                	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	qos_rule_match                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	qos_rule_overrun_wan_flow_mode	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wan_flow_mapping_mode         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wan_flow_mapping_table        	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	opbit_remark_mode             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipbit_remark_mode             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wan_flow                      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	qos_mapping_mode              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	traffic_class                 	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_controller               	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop                          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu                           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                     	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dei_remark_enable             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dei_value                     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_mode                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_id                    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                     	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_pbit                    	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inner_pbit                    	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp_remarking_mode           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp                          	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ecn                           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_VLAN_CMD_INDEX_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p, 1, 7, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_VLAN_CMD_INDEX_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p, 1, 7, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_QOS_RULE_MATCH_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p, 0, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_QOS_RULE_MATCH_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p, 0, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_QOS_RULE_OVERRUN_WAN_FLOW_MODE_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 1, 7, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_QOS_RULE_OVERRUN_WAN_FLOW_MODE_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 1, 7, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_WAN_FLOW_MAPPING_MODE_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 1, 6, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_WAN_FLOW_MAPPING_MODE_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 1, 6, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_WAN_FLOW_MAPPING_TABLE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 1, 3, 3, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_WAN_FLOW_MAPPING_TABLE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 1, 3, 3, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OPBIT_REMARK_MODE_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 1, 2, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OPBIT_REMARK_MODE_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 1, 2, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_IPBIT_REMARK_MODE_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 1, 1, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_IPBIT_REMARK_MODE_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 1, 1, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_WAN_FLOW_READ(r, p)                                       FIELD_MREAD_32((uint8_t *)p + 0, 9, 8, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_WAN_FLOW_WRITE(v, p)                                      FIELD_MWRITE_32((uint8_t *)p + 0, 9, 8, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_QOS_MAPPING_MODE_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 2, 0, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_QOS_MAPPING_MODE_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 2, 0, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_TRAFFIC_CLASS_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 3, 5, 3, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_TRAFFIC_CLASS_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 3, 5, 3, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_CONTROLLER_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 3, 0, 5, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_CONTROLLER_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 3, 0, 5, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DROP_READ(r, p)                                           FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DROP_WRITE(v, p)                                          FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_CPU_READ(r, p)                                            FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_CPU_WRITE(v, p)                                           FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_REMARK_ENABLE_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 5, 7, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_REMARK_ENABLE_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 5, 7, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_VALUE_READ(r, p)                                      FIELD_MREAD_8((uint8_t *)p + 5, 6, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_VALUE_WRITE(v, p)                                     FIELD_MWRITE_8((uint8_t *)p + 5, 6, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_MODE_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p + 5, 5, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_MODE_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p + 5, 5, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_ID_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 5, 1, 4, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_ID_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 5, 1, 4, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OUTER_PBIT_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 6, 4, 3, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OUTER_PBIT_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 6, 4, 3, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_INNER_PBIT_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 6, 1, 3, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_INNER_PBIT_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 6, 1, 3, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_REMARKING_MODE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 6, 0, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_REMARKING_MODE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 6, 0, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_READ(r, p)                                           FIELD_MREAD_8((uint8_t *)p + 7, 2, 6, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_WRITE(v, p)                                          FIELD_MWRITE_8((uint8_t *)p + 7, 2, 6, v)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_ECN_READ(r, p)                                            FIELD_MREAD_8((uint8_t *)p + 7, 0, 2, r)
#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_ECN_WRITE(v, p)                                           FIELD_MWRITE_8((uint8_t *)p + 7, 0, 2, v)
#if defined DSL_63138

#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_SIZE     256
typedef struct
{
	RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_ADDRESS )

#endif
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_CONTROLLER_ADDR_NUMBER	32

typedef struct
{
	uint32_t	reserved0                                                                           	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_priority                                                               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_mode                                                                   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	schedule                                                                            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_destination                                                                     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_controllers_status                                                             	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_controllers_sustain_vector                                                     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_controllers_peak_vector                                                        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_burst_counter                                                                  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_offset                                                                         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_scheduling_mode                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                                           	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ack_pending_epon                                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ack_pending                                                                         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	byte_counter                                                                        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	rate_controller_addr[RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_CONTROLLER_ADDR_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_CHANNEL_0_7_DESCRIPTOR_DTS;

#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_LIMITER_PRIORITY_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p, 1, 1, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_LIMITER_PRIORITY_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p, 1, 1, v)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_LIMITER_MODE_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p, 0, 1, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_LIMITER_MODE_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p, 0, 1, v)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_SCHEDULE_READ(r, p)                                        MREAD_8((uint8_t *)p + 1, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_SCHEDULE_WRITE(v, p)                                       MWRITE_8((uint8_t *)p + 1, v)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_BBH_DESTINATION_READ(r, p)                                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_BBH_DESTINATION_WRITE(v, p)                                MWRITE_16((uint8_t *)p + 2, v)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_CONTROLLERS_STATUS_READ(r, p)                         MREAD_32((uint8_t *)p + 4, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_CONTROLLERS_STATUS_WRITE(v, p)                        MWRITE_32((uint8_t *)p + 4, v)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_CONTROLLERS_SUSTAIN_VECTOR_READ(r, p)                 MREAD_32((uint8_t *)p + 8, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_CONTROLLERS_SUSTAIN_VECTOR_WRITE(v, p)                MWRITE_32((uint8_t *)p + 8, v)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_CONTROLLERS_PEAK_VECTOR_READ(r, p)                    MREAD_32((uint8_t *)p + 12, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_CONTROLLERS_PEAK_VECTOR_WRITE(v, p)                   MWRITE_32((uint8_t *)p + 12, v)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_PEAK_BURST_COUNTER_READ(r, p)                              MREAD_16((uint8_t *)p + 16, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_PEAK_BURST_COUNTER_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 16, v)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_PEAK_OFFSET_READ(r, p)                                     MREAD_8((uint8_t *)p + 18, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_PEAK_OFFSET_WRITE(v, p)                                    MWRITE_8((uint8_t *)p + 18, v)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_PEAK_SCHEDULING_MODE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 19, 7, 1, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_PEAK_SCHEDULING_MODE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 19, 7, 1, v)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_ACK_PENDING_EPON_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 19, 1, 1, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_ACK_PENDING_EPON_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 19, 1, 1, v)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_ACK_PENDING_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 19, 0, 1, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_ACK_PENDING_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 19, 0, 1, v)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_BYTE_COUNTER_READ(r, p)                                    MREAD_32((uint8_t *)p + 20, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_BYTE_COUNTER_WRITE(v, p)                                   MWRITE_32((uint8_t *)p + 20, v)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_CONTROLLER_ADDR_READ(r, p, i)                         MREAD_I_16((uint8_t *)p + 24, i, r)
#define RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_CONTROLLER_ADDR_WRITE(v, p, i)                        MWRITE_I_16((uint8_t *)p + 24, i, v)
#if defined DSL_63138

#define RDD_WAN_CHANNELS_0_7_TABLE_SIZE     8
typedef struct
{
	RDD_WAN_CHANNEL_0_7_DESCRIPTOR_DTS	entry[ RDD_WAN_CHANNELS_0_7_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_CHANNELS_0_7_TABLE_DTS;

#define RDD_WAN_CHANNELS_0_7_TABLE_PTR()	( RDD_WAN_CHANNELS_0_7_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + WAN_CHANNELS_0_7_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
typedef struct
{
	RDD_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS	entry[ RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_DTS;

#define RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_PTR()	( RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
typedef struct
{
	RDD_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS	entry[ RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_DTS;

#define RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_PTR()	( RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS )

#endif

typedef struct
{
	uint32_t	current_budget           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop_threshold           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	xoff_threshold           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocated_budget_mantisa 	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocated_budget_exponent	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	active_pause_flag        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_rx_address           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_RATE_LIMITER_ENTRY_DTS;

#define RDD_INGRESS_RATE_LIMITER_ENTRY_CURRENT_BUDGET_READ(r, p)                            MREAD_32((uint8_t *)p, r)
#define RDD_INGRESS_RATE_LIMITER_ENTRY_CURRENT_BUDGET_WRITE(v, p)                           MWRITE_32((uint8_t *)p, v)
#define RDD_INGRESS_RATE_LIMITER_ENTRY_DROP_THRESHOLD_READ(r, p)                            MREAD_32((uint8_t *)p + 4, r)
#define RDD_INGRESS_RATE_LIMITER_ENTRY_DROP_THRESHOLD_WRITE(v, p)                           MWRITE_32((uint8_t *)p + 4, v)
#define RDD_INGRESS_RATE_LIMITER_ENTRY_XOFF_THRESHOLD_READ(r, p)                            MREAD_32((uint8_t *)p + 8, r)
#define RDD_INGRESS_RATE_LIMITER_ENTRY_XOFF_THRESHOLD_WRITE(v, p)                           MWRITE_32((uint8_t *)p + 8, v)
#define RDD_INGRESS_RATE_LIMITER_ENTRY_ALLOCATED_BUDGET_MANTISA_READ(r, p)                  FIELD_MREAD_16((uint8_t *)p + 12, 2, 14, r)
#define RDD_INGRESS_RATE_LIMITER_ENTRY_ALLOCATED_BUDGET_MANTISA_WRITE(v, p)                 FIELD_MWRITE_16((uint8_t *)p + 12, 2, 14, v)
#define RDD_INGRESS_RATE_LIMITER_ENTRY_ALLOCATED_BUDGET_EXPONENT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 13, 0, 2, r)
#define RDD_INGRESS_RATE_LIMITER_ENTRY_ALLOCATED_BUDGET_EXPONENT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 13, 0, 2, v)
#define RDD_INGRESS_RATE_LIMITER_ENTRY_ACTIVE_PAUSE_FLAG_READ(r, p)                         MREAD_8((uint8_t *)p + 14, r)
#define RDD_INGRESS_RATE_LIMITER_ENTRY_ACTIVE_PAUSE_FLAG_WRITE(v, p)                        MWRITE_8((uint8_t *)p + 14, v)
#define RDD_INGRESS_RATE_LIMITER_ENTRY_BBH_RX_ADDRESS_READ(r, p)                            MREAD_8((uint8_t *)p + 15, r)
#define RDD_INGRESS_RATE_LIMITER_ENTRY_BBH_RX_ADDRESS_WRITE(v, p)                           MWRITE_8((uint8_t *)p + 15, v)
#if defined DSL_63138

#define RDD_US_INGRESS_RATE_LIMITER_TABLE_SIZE     5
typedef struct
{
	RDD_INGRESS_RATE_LIMITER_ENTRY_DTS	entry[ RDD_US_INGRESS_RATE_LIMITER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_RATE_LIMITER_TABLE_DTS;

#define RDD_US_INGRESS_RATE_LIMITER_TABLE_PTR()	( RDD_US_INGRESS_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_RATE_LIMITER_TABLE_ADDRESS )

#endif
#if defined DSL_63138

typedef struct
{
	uint16_t	port_sel  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	reserved0 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	pkt_eop   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	frag_size 	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DSL_PTM_BOND_TX_HDR_ENTRY_DTS;

#define RDD_DSL_PTM_BOND_TX_HDR_ENTRY_PORT_SEL_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_DSL_PTM_BOND_TX_HDR_ENTRY_PORT_SEL_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_DSL_PTM_BOND_TX_HDR_ENTRY_PKT_EOP_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p, 4, 1, r)
#define RDD_DSL_PTM_BOND_TX_HDR_ENTRY_PKT_EOP_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p, 4, 1, v)
#define RDD_DSL_PTM_BOND_TX_HDR_ENTRY_FRAG_SIZE_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 0, 12, r)
#define RDD_DSL_PTM_BOND_TX_HDR_ENTRY_FRAG_SIZE_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 0, 12, v)
#endif
#if defined DSL_63138

#define RDD_DSL_PTM_BOND_TX_HDR_TABLE_SIZE     8
typedef struct
{
	RDD_DSL_PTM_BOND_TX_HDR_ENTRY_DTS	entry[ RDD_DSL_PTM_BOND_TX_HDR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DSL_PTM_BOND_TX_HDR_TABLE_DTS;

#define RDD_DSL_PTM_BOND_TX_HDR_TABLE_PTR()	( RDD_DSL_PTM_BOND_TX_HDR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DSL_PTM_BOND_TX_HDR_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_SIZE     3
typedef struct
{
	RDD_RUNNER_FLOW_HEADER_DESCRIPTOR_DTS	entry[ RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_DTS;

#define RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_PTR()	( RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RUNNER_FLOW_HEADER_DESCRIPTOR_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_CPU_RX_PICO_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_US_CPU_RX_PICO_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_RX_PICO_INGRESS_QUEUE_DTS;

#define RDD_US_CPU_RX_PICO_INGRESS_QUEUE_PTR()	( RDD_US_CPU_RX_PICO_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_RX_PICO_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_ROUTER_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_US_ROUTER_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_ROUTER_INGRESS_QUEUE_DTS;

#define RDD_US_ROUTER_INGRESS_QUEUE_PTR()	( RDD_US_ROUTER_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_ROUTER_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_SIZE     32
typedef struct
{
	RDD_GPE_COMMAND_PRIMITIVE_ENTRY_DTS	entry[ RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_DTS;

#define RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_PTR()	( RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_GPE_COMMAND_PRIMITIVE_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_CPU_RX_FAST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_US_CPU_RX_FAST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_RX_FAST_INGRESS_QUEUE_DTS;

#define RDD_US_CPU_RX_FAST_INGRESS_QUEUE_PTR()	( RDD_US_CPU_RX_FAST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_RX_FAST_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_DEBUG_BUFFER_SIZE     32
typedef struct
{
	RDD_DEBUG_BUFFER_ENTRY_DTS	entry[ RDD_US_DEBUG_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_DEBUG_BUFFER_DTS;

#define RDD_US_DEBUG_BUFFER_PTR()	( RDD_US_DEBUG_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_DEBUG_BUFFER_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_FW_MAC_ADDRS_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_US_FW_MAC_ADDRS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FW_MAC_ADDRS_DTS;

#define RDD_US_FW_MAC_ADDRS_PTR()	( RDD_US_FW_MAC_ADDRS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FW_MAC_ADDRS_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DSL_PTM_BOND_TX_HDR_DEBUG_TABLE_SIZE     8
typedef struct
{
	RDD_DSL_PTM_BOND_TX_HDR_ENTRY_DTS	entry[ RDD_DSL_PTM_BOND_TX_HDR_DEBUG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DSL_PTM_BOND_TX_HDR_DEBUG_TABLE_DTS;

#define RDD_DSL_PTM_BOND_TX_HDR_DEBUG_TABLE_PTR()	( RDD_DSL_PTM_BOND_TX_HDR_DEBUG_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DSL_PTM_BOND_TX_HDR_DEBUG_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_DHD_TX_POST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_US_DHD_TX_POST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_DHD_TX_POST_INGRESS_QUEUE_DTS;

#define RDD_US_DHD_TX_POST_INGRESS_QUEUE_PTR()	( RDD_US_DHD_TX_POST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_DHD_TX_POST_INGRESS_QUEUE_ADDRESS )

#endif

typedef struct
{
	uint16_t	wan_channel_ptr	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_ENTRY_DTS;

#define RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_ENTRY_WAN_CHANNEL_PTR_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_ENTRY_WAN_CHANNEL_PTR_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)
#if defined DSL_63138

#define RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_SIZE     48
typedef struct
{
	RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_ENTRY_DTS	entry[ RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_DTS;

#define RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_PTR()	( RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_ADDRESS )

#endif
#define RDD_US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR()	( RDD_US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_ADDRESS )

#if defined DSL_63138

#define RDD_RUNNER_FWTRACE_MAINB_PARAM_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINB_PARAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINB_PARAM_DTS;

#define RDD_RUNNER_FWTRACE_MAINB_PARAM_PTR()	( RDD_RUNNER_FWTRACE_MAINB_PARAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + RUNNER_FWTRACE_MAINB_PARAM_ADDRESS )

#endif

typedef struct
{
	uint32_t	summary                  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	linear_length            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_header_length     	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_protocol              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_header_offset         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_header_length         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_total_length          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipv4_csum                	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_udp_header_offset    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_udp_header_length    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_udp_total_length     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_udp_csum             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	max_chunk_length         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	chunk_bytes_left         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	nr_frags                 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	frag_index               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	frag_len                 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	frag_data                	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	good_csum_packets        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_csum_packets          	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bad_ipv4_hdr_csum_packets	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bad_tcp_udp_csum_packets 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fail_code                	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dma_sync                 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	seg_length               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	seg_bytes_left           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_length           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_bytes_left       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_0               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_ptr              	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_1               	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ddr_payload_offset       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ddr_src_address          	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	saved_ih_buffer_number   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	saved_csum32_ret_addr    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	saved_r16                	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CSO_CONTEXT_ENTRY_DTS;

#define RDD_CSO_CONTEXT_ENTRY_SUMMARY_READ(r, p)                                   MREAD_32((uint8_t *)p, r)
#define RDD_CSO_CONTEXT_ENTRY_SUMMARY_WRITE(v, p)                                  MWRITE_32((uint8_t *)p, v)
#define RDD_CSO_CONTEXT_ENTRY_LINEAR_LENGTH_READ(r, p)                             MREAD_16((uint8_t *)p + 4, r)
#define RDD_CSO_CONTEXT_ENTRY_LINEAR_LENGTH_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 4, v)
#define RDD_CSO_CONTEXT_ENTRY_PACKET_LENGTH_READ(r, p)                             MREAD_16((uint8_t *)p + 6, r)
#define RDD_CSO_CONTEXT_ENTRY_PACKET_LENGTH_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 6, v)
#define RDD_CSO_CONTEXT_ENTRY_PACKET_HEADER_LENGTH_READ(r, p)                      MREAD_8((uint8_t *)p + 8, r)
#define RDD_CSO_CONTEXT_ENTRY_PACKET_HEADER_LENGTH_WRITE(v, p)                     MWRITE_8((uint8_t *)p + 8, v)
#define RDD_CSO_CONTEXT_ENTRY_IP_PROTOCOL_READ(r, p)                               MREAD_8((uint8_t *)p + 9, r)
#define RDD_CSO_CONTEXT_ENTRY_IP_PROTOCOL_WRITE(v, p)                              MWRITE_8((uint8_t *)p + 9, v)
#define RDD_CSO_CONTEXT_ENTRY_IP_HEADER_OFFSET_READ(r, p)                          MREAD_8((uint8_t *)p + 10, r)
#define RDD_CSO_CONTEXT_ENTRY_IP_HEADER_OFFSET_WRITE(v, p)                         MWRITE_8((uint8_t *)p + 10, v)
#define RDD_CSO_CONTEXT_ENTRY_IP_HEADER_LENGTH_READ(r, p)                          MREAD_8((uint8_t *)p + 11, r)
#define RDD_CSO_CONTEXT_ENTRY_IP_HEADER_LENGTH_WRITE(v, p)                         MWRITE_8((uint8_t *)p + 11, v)
#define RDD_CSO_CONTEXT_ENTRY_IP_TOTAL_LENGTH_READ(r, p)                           MREAD_16((uint8_t *)p + 12, r)
#define RDD_CSO_CONTEXT_ENTRY_IP_TOTAL_LENGTH_WRITE(v, p)                          MWRITE_16((uint8_t *)p + 12, v)
#define RDD_CSO_CONTEXT_ENTRY_IPV4_CSUM_READ(r, p)                                 MREAD_16((uint8_t *)p + 14, r)
#define RDD_CSO_CONTEXT_ENTRY_IPV4_CSUM_WRITE(v, p)                                MWRITE_16((uint8_t *)p + 14, v)
#define RDD_CSO_CONTEXT_ENTRY_TCP_UDP_HEADER_OFFSET_READ(r, p)                     MREAD_8((uint8_t *)p + 16, r)
#define RDD_CSO_CONTEXT_ENTRY_TCP_UDP_HEADER_OFFSET_WRITE(v, p)                    MWRITE_8((uint8_t *)p + 16, v)
#define RDD_CSO_CONTEXT_ENTRY_TCP_UDP_HEADER_LENGTH_READ(r, p)                     MREAD_8((uint8_t *)p + 17, r)
#define RDD_CSO_CONTEXT_ENTRY_TCP_UDP_HEADER_LENGTH_WRITE(v, p)                    MWRITE_8((uint8_t *)p + 17, v)
#define RDD_CSO_CONTEXT_ENTRY_TCP_UDP_TOTAL_LENGTH_READ(r, p)                      MREAD_16((uint8_t *)p + 18, r)
#define RDD_CSO_CONTEXT_ENTRY_TCP_UDP_TOTAL_LENGTH_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 18, v)
#define RDD_CSO_CONTEXT_ENTRY_TCP_UDP_CSUM_READ(r, p)                              MREAD_16((uint8_t *)p + 20, r)
#define RDD_CSO_CONTEXT_ENTRY_TCP_UDP_CSUM_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 20, v)
#define RDD_CSO_CONTEXT_ENTRY_MAX_CHUNK_LENGTH_READ(r, p)                          MREAD_8((uint8_t *)p + 22, r)
#define RDD_CSO_CONTEXT_ENTRY_MAX_CHUNK_LENGTH_WRITE(v, p)                         MWRITE_8((uint8_t *)p + 22, v)
#define RDD_CSO_CONTEXT_ENTRY_CHUNK_BYTES_LEFT_READ(r, p)                          MREAD_8((uint8_t *)p + 23, r)
#define RDD_CSO_CONTEXT_ENTRY_CHUNK_BYTES_LEFT_WRITE(v, p)                         MWRITE_8((uint8_t *)p + 23, v)
#define RDD_CSO_CONTEXT_ENTRY_NR_FRAGS_READ(r, p)                                  MREAD_8((uint8_t *)p + 24, r)
#define RDD_CSO_CONTEXT_ENTRY_NR_FRAGS_WRITE(v, p)                                 MWRITE_8((uint8_t *)p + 24, v)
#define RDD_CSO_CONTEXT_ENTRY_FRAG_INDEX_READ(r, p)                                MREAD_8((uint8_t *)p + 25, r)
#define RDD_CSO_CONTEXT_ENTRY_FRAG_INDEX_WRITE(v, p)                               MWRITE_8((uint8_t *)p + 25, v)
#define RDD_CSO_CONTEXT_ENTRY_FRAG_LEN_READ(r, p)                                  MREAD_16((uint8_t *)p + 26, r)
#define RDD_CSO_CONTEXT_ENTRY_FRAG_LEN_WRITE(v, p)                                 MWRITE_16((uint8_t *)p + 26, v)
#define RDD_CSO_CONTEXT_ENTRY_FRAG_DATA_READ(r, p)                                 MREAD_32((uint8_t *)p + 28, r)
#define RDD_CSO_CONTEXT_ENTRY_FRAG_DATA_WRITE(v, p)                                MWRITE_32((uint8_t *)p + 28, v)
#define RDD_CSO_CONTEXT_ENTRY_GOOD_CSUM_PACKETS_READ(r, p)                         MREAD_32((uint8_t *)p + 32, r)
#define RDD_CSO_CONTEXT_ENTRY_GOOD_CSUM_PACKETS_WRITE(v, p)                        MWRITE_32((uint8_t *)p + 32, v)
#define RDD_CSO_CONTEXT_ENTRY_NO_CSUM_PACKETS_READ(r, p)                           MREAD_32((uint8_t *)p + 36, r)
#define RDD_CSO_CONTEXT_ENTRY_NO_CSUM_PACKETS_WRITE(v, p)                          MWRITE_32((uint8_t *)p + 36, v)
#define RDD_CSO_CONTEXT_ENTRY_BAD_IPV4_HDR_CSUM_PACKETS_READ(r, p)                 MREAD_32((uint8_t *)p + 40, r)
#define RDD_CSO_CONTEXT_ENTRY_BAD_IPV4_HDR_CSUM_PACKETS_WRITE(v, p)                MWRITE_32((uint8_t *)p + 40, v)
#define RDD_CSO_CONTEXT_ENTRY_BAD_TCP_UDP_CSUM_PACKETS_READ(r, p)                  MREAD_32((uint8_t *)p + 44, r)
#define RDD_CSO_CONTEXT_ENTRY_BAD_TCP_UDP_CSUM_PACKETS_WRITE(v, p)                 MWRITE_32((uint8_t *)p + 44, v)
#define RDD_CSO_CONTEXT_ENTRY_FAIL_CODE_READ(r, p)                                 MREAD_8((uint8_t *)p + 48, r)
#define RDD_CSO_CONTEXT_ENTRY_FAIL_CODE_WRITE(v, p)                                MWRITE_8((uint8_t *)p + 48, v)
#define RDD_CSO_CONTEXT_ENTRY_DMA_SYNC_READ(r, p)                                  MREAD_8((uint8_t *)p + 49, r)
#define RDD_CSO_CONTEXT_ENTRY_DMA_SYNC_WRITE(v, p)                                 MWRITE_8((uint8_t *)p + 49, v)
#define RDD_CSO_CONTEXT_ENTRY_SEG_LENGTH_READ(r, p)                                MREAD_16((uint8_t *)p + 50, r)
#define RDD_CSO_CONTEXT_ENTRY_SEG_LENGTH_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 50, v)
#define RDD_CSO_CONTEXT_ENTRY_SEG_BYTES_LEFT_READ(r, p)                            MREAD_16((uint8_t *)p + 52, r)
#define RDD_CSO_CONTEXT_ENTRY_SEG_BYTES_LEFT_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 52, v)
#define RDD_CSO_CONTEXT_ENTRY_PAYLOAD_LENGTH_READ(r, p)                            MREAD_16((uint8_t *)p + 54, r)
#define RDD_CSO_CONTEXT_ENTRY_PAYLOAD_LENGTH_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 54, v)
#define RDD_CSO_CONTEXT_ENTRY_PAYLOAD_BYTES_LEFT_READ(r, p)                        MREAD_16((uint8_t *)p + 56, r)
#define RDD_CSO_CONTEXT_ENTRY_PAYLOAD_BYTES_LEFT_WRITE(v, p)                       MWRITE_16((uint8_t *)p + 56, v)
#define RDD_CSO_CONTEXT_ENTRY_PAYLOAD_PTR_READ(r, p)                               MREAD_32((uint8_t *)p + 60, r)
#define RDD_CSO_CONTEXT_ENTRY_PAYLOAD_PTR_WRITE(v, p)                              MWRITE_32((uint8_t *)p + 60, v)
#define RDD_CSO_CONTEXT_ENTRY_DDR_PAYLOAD_OFFSET_READ(r, p)                        MREAD_8((uint8_t *)p + 67, r)
#define RDD_CSO_CONTEXT_ENTRY_DDR_PAYLOAD_OFFSET_WRITE(v, p)                       MWRITE_8((uint8_t *)p + 67, v)
#define RDD_CSO_CONTEXT_ENTRY_DDR_SRC_ADDRESS_READ(r, p)                           MREAD_32((uint8_t *)p + 68, r)
#define RDD_CSO_CONTEXT_ENTRY_DDR_SRC_ADDRESS_WRITE(v, p)                          MWRITE_32((uint8_t *)p + 68, v)
#define RDD_CSO_CONTEXT_ENTRY_SAVED_IH_BUFFER_NUMBER_READ(r, p)                    MREAD_32((uint8_t *)p + 72, r)
#define RDD_CSO_CONTEXT_ENTRY_SAVED_IH_BUFFER_NUMBER_WRITE(v, p)                   MWRITE_32((uint8_t *)p + 72, v)
#define RDD_CSO_CONTEXT_ENTRY_SAVED_CSUM32_RET_ADDR_READ(r, p)                     MREAD_32((uint8_t *)p + 76, r)
#define RDD_CSO_CONTEXT_ENTRY_SAVED_CSUM32_RET_ADDR_WRITE(v, p)                    MWRITE_32((uint8_t *)p + 76, v)
#define RDD_CSO_CONTEXT_ENTRY_SAVED_R16_READ(r, p)                                 MREAD_32((uint8_t *)p + 80, r)
#define RDD_CSO_CONTEXT_ENTRY_SAVED_R16_WRITE(v, p)                                MWRITE_32((uint8_t *)p + 80, v)

typedef struct
{
	uint8_t	reserved_fw_only	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_ABSOLUTE_TX_COUNTER_DTS;

#if defined DSL_63138

#define RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_SIZE     40
typedef struct
{
	RDD_GPON_ABSOLUTE_TX_COUNTER_DTS	entry[ RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_DTS;

#define RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_PTR()	( RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_DHD_FLOW_RING_DROP_COUNTER_SIZE     5
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_US_DHD_FLOW_RING_DROP_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_DHD_FLOW_RING_DROP_COUNTER_DTS;

#define RDD_US_DHD_FLOW_RING_DROP_COUNTER_PTR()	( RDD_US_DHD_FLOW_RING_DROP_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_DHD_FLOW_RING_DROP_COUNTER_ADDRESS )

#endif
#define RDD_US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR()	( RDD_US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_ADDRESS )

#if defined DSL_63138

#define RDD_RUNNER_FWTRACE_PICOB_PARAM_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_PICOB_PARAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_PICOB_PARAM_DTS;

#define RDD_RUNNER_FWTRACE_PICOB_PARAM_PTR()	( RDD_RUNNER_FWTRACE_PICOB_PARAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + RUNNER_FWTRACE_PICOB_PARAM_ADDRESS )

#endif

typedef struct
{
	uint8_t	flow_id   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_ENTRY_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_ENTRY_FLOW_ID_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_ENTRY_FLOW_ID_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#if defined DSL_63138

#define RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_SIZE     32
typedef struct
{
	RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_ENTRY_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_ADDRESS )

#endif
#if defined DSL_63138

typedef struct
{
	uint32_t	guaranteed_free_count    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	non_guaranteed_free_count	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	guaranteed_threshold     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_DTS;

#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_FREE_COUNT_READ(r, p)                     MREAD_16((uint8_t *)p, r)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_FREE_COUNT_WRITE(v, p)                    MWRITE_16((uint8_t *)p, v)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_NON_GUARANTEED_FREE_COUNT_READ(r, p)                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_NON_GUARANTEED_FREE_COUNT_WRITE(v, p)                MWRITE_16((uint8_t *)p + 2, v)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_THRESHOLD_READ(r, p)                      MREAD_16((uint8_t *)p + 4, r)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_THRESHOLD_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 4, v)
#endif
#if defined DSL_63138

#define RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_SIZE     8
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_DTS;

#define RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_PTR()	( RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_SIZE     16
typedef struct
{
	RDD_BROADCOM_SWITCH_PORT_MAPPING_DTS	entry[ RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_DTS;

#define RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_PTR()	( RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_SIZE     3
#define RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_SIZE2    6
typedef struct
{
	RDD_CPU_REASON_TO_METER_ENTRY_DTS	entry[ RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_SIZE ][ RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_DTS;

#define RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_PTR()	( RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_WAN_TX_SCRATCH_SIZE     16
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_WAN_TX_SCRATCH_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_TX_SCRATCH_DTS;

#define RDD_WAN_TX_SCRATCH_PTR()	( RDD_WAN_TX_SCRATCH_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + WAN_TX_SCRATCH_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DATA_POINTER_DUMMY_TARGET_SIZE     2
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DATA_POINTER_DUMMY_TARGET_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DATA_POINTER_DUMMY_TARGET_DTS;

#define RDD_DATA_POINTER_DUMMY_TARGET_PTR()	( RDD_DATA_POINTER_DUMMY_TARGET_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DATA_POINTER_DUMMY_TARGET_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_SIZE     14
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_DTS;

#define RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_PTR()	( RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + CPU_TX_DHD_LAYER2_HEADER_BUFFER_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_SIZE     4
typedef struct
{
	RDD_PARALLEL_PROCESSING_ENTRY_DTS	entry[ RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_DTS;

#define RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR()	( RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_SIZE     4
typedef struct
{
	RDD_PARALLEL_PROCESSING_TASK_REORDER_ENTRY_DTS	entry[ RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_DTS;

#define RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_PTR()	( RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_SIZE     8
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_DTS;

#define RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_PTR()	( RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_SIZE     8
typedef struct
{
	RDD_BROADCOM_SWITCH_PORT_MAPPING_DTS	entry[ RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_DTS;

#define RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_PTR()	( RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_ADDRESS )

#endif

typedef struct
{
	uint8_t	exponent  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RATE_CONTROLLER_EXPONENT_ENTRY_DTS;

#define RDD_RATE_CONTROLLER_EXPONENT_ENTRY_EXPONENT_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_RATE_CONTROLLER_EXPONENT_ENTRY_EXPONENT_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)

#define RDD_RATE_CONTROLLER_EXPONENT_TABLE_SIZE     4
typedef struct
{
	RDD_RATE_CONTROLLER_EXPONENT_ENTRY_DTS	entry[ RDD_RATE_CONTROLLER_EXPONENT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RATE_CONTROLLER_EXPONENT_TABLE_DTS;

#define RDD_US_RATE_CONTROLLER_EXPONENT_TABLE_PTR()	( RDD_US_RATE_CONTROLLER_EXPONENT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RATE_CONTROLLER_EXPONENT_TABLE_ADDRESS )


typedef struct
{
	uint16_t	entry     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR_DTS;

#define RDD_LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR_ENTRY_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR_ENTRY_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)

typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR_DTS;


typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_ENQUEUE_INGRESS_QUEUE_PTR_ENTRY_DTS;

#if defined DSL_63138

#define RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_SIZE     40
typedef struct
{
	RDD_GPON_ABSOLUTE_TX_COUNTER_DTS	entry[ RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_DTS;

#define RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_PTR()	( RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + GPON_ABSOLUTE_TX_BBH_COUNTER_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_ETH1_RX_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_ETH_RX_DESCRIPTORS_DTS	entry[ RDD_ETH1_RX_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH1_RX_DESCRIPTORS_DTS;

#define RDD_ETH1_RX_DESCRIPTORS_PTR()	( RDD_ETH1_RX_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + ETH1_RX_DESCRIPTORS_ADDRESS )

#endif

typedef struct
{
	uint32_t	reserved_fw_only	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_WAN_CHANNEL_INDEX_DTS;

/* COMMON_A */
#if defined DSL_63138

#define RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_SIZE     384
typedef struct
{
	RDD_SIXTEEN_BYTES_DTS	entry[ RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_DTS;

#define RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_PTR()	( RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + SERVICE_QUEUES_DDR_CACHE_FIFO_ADDRESS )

#endif
#define RDD_RUNNER_SCRATCHPAD_RESERVED_FW_ONLY_NUMBER	64

typedef struct
{
	uint32_t	reserved_fw_only[RDD_RUNNER_SCRATCHPAD_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_SCRATCHPAD_DTS;

#if defined DSL_63138

#define RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_SIZE     8
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_DTS;

#define RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_PTR()	( RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + FC_MCAST_RUNNER_A_SCRATCHPAD_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_CPU_RX_RUNNER_A_SCRATCHPAD_SIZE     16
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_CPU_RX_RUNNER_A_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_RUNNER_A_SCRATCHPAD_DTS;

#define RDD_CPU_RX_RUNNER_A_SCRATCHPAD_PTR()	( RDD_CPU_RX_RUNNER_A_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + CPU_RX_RUNNER_A_SCRATCHPAD_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_SIZE     8
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_DTS;

#define RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_PTR()	( RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_RUNNER_A_SCRATCHPAD_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_RUNNER_FWTRACE_MAINA_BASE_SIZE     128
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINA_BASE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINA_BASE_DTS;

#define RDD_RUNNER_FWTRACE_MAINA_BASE_PTR()	( RDD_RUNNER_FWTRACE_MAINA_BASE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RUNNER_FWTRACE_MAINA_BASE_ADDRESS )

#endif

typedef struct
{
	uint32_t	mac_address_high	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mac_address_mid 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mac_address_low 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	radio_index     	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid            	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flowring_index  	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1       	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_priority     	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reference_count 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_DHD_STATION_ENTRY_DTS;

#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_MAC_ADDRESS_HIGH_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_MAC_ADDRESS_HIGH_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_MAC_ADDRESS_MID_READ(r, p)                  MREAD_16((uint8_t *)p + 2, r)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_MAC_ADDRESS_MID_WRITE(v, p)                 MWRITE_16((uint8_t *)p + 2, v)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_MAC_ADDRESS_LOW_READ(r, p)                  MREAD_16((uint8_t *)p + 4, r)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_MAC_ADDRESS_LOW_WRITE(v, p)                 MWRITE_16((uint8_t *)p + 4, v)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_RADIO_INDEX_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 6, 6, 2, r)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_RADIO_INDEX_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 6, 6, 2, v)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_SSID_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 6, 2, 4, r)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_SSID_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 6, 2, 4, v)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_FLOWRING_INDEX_READ(r, p)                   FIELD_MREAD_16((uint8_t *)p + 6, 0, 10, r)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_FLOWRING_INDEX_WRITE(v, p)                  FIELD_MWRITE_16((uint8_t *)p + 6, 0, 10, v)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_TX_PRIORITY_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 8, 0, 3, r)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_TX_PRIORITY_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 8, 0, 3, v)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_REFERENCE_COUNT_READ(r, p)                  MREAD_8((uint8_t *)p + 9, r)
#define RDD_WLAN_MCAST_DHD_STATION_ENTRY_REFERENCE_COUNT_WRITE(v, p)                 MWRITE_8((uint8_t *)p + 9, v)
#if defined DSL_63138

#define RDD_WLAN_MCAST_DHD_STATION_TABLE_SIZE     64
typedef struct
{
	RDD_WLAN_MCAST_DHD_STATION_ENTRY_DTS	entry[ RDD_WLAN_MCAST_DHD_STATION_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_DHD_STATION_TABLE_DTS;

#define RDD_WLAN_MCAST_DHD_STATION_TABLE_PTR()	( RDD_WLAN_MCAST_DHD_STATION_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_DHD_STATION_TABLE_ADDRESS )

#endif

typedef struct
{
	uint8_t	cpu_rx_queue	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_REASON_TO_CPU_RX_QUEUE_ENTRY_DTS;

#define RDD_CPU_REASON_TO_CPU_RX_QUEUE_ENTRY_CPU_RX_QUEUE_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_CPU_REASON_TO_CPU_RX_QUEUE_ENTRY_CPU_RX_QUEUE_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)

#define RDD_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_SIZE     2
#define RDD_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_SIZE2    64
typedef struct
{
	RDD_CPU_REASON_TO_CPU_RX_QUEUE_ENTRY_DTS	entry[ RDD_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_SIZE ][ RDD_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_DTS;

#define RDD_DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_PTR()	( RDD_DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_ADDRESS )


typedef struct
{
	uint32_t	ds_dhd_doorbell           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ds_rd_fr_r2d_indexes      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ds_wr_fr_r2d_indexes      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_rd_fr_d2r_indexes      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_wr_fr_d2r_indexes      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_complete_packet_counter	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_DTS;

#define RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_DS_DHD_DOORBELL_READ(r, p)                            MREAD_32((uint8_t *)p, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_DS_DHD_DOORBELL_WRITE(v, p)                           MWRITE_32((uint8_t *)p, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_DS_RD_FR_R2D_INDEXES_READ(r, p)                       MREAD_16((uint8_t *)p + 4, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_DS_RD_FR_R2D_INDEXES_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 4, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_DS_WR_FR_R2D_INDEXES_READ(r, p)                       MREAD_16((uint8_t *)p + 6, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_DS_WR_FR_R2D_INDEXES_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 6, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_TX_RD_FR_D2R_INDEXES_READ(r, p)                       MREAD_16((uint8_t *)p + 8, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_TX_RD_FR_D2R_INDEXES_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 8, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_TX_WR_FR_D2R_INDEXES_READ(r, p)                       MREAD_16((uint8_t *)p + 10, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_TX_WR_FR_D2R_INDEXES_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 10, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_TX_COMPLETE_PACKET_COUNTER_READ(r, p)                 MREAD_16((uint8_t *)p + 12, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_TX_COMPLETE_PACKET_COUNTER_WRITE(v, p)                MWRITE_16((uint8_t *)p + 12, v)
#if defined DSL_63138

#define RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_SIZE     3
typedef struct
{
	RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_DTS	entry[ RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_DTS;

#define RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_PTR()	( RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DHD_RADIO_INSTANCE_COMMON_A_DATA_ADDRESS )

#endif

typedef struct
{
	uint32_t	reserved_fw_only	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FREE_SKB_INDEXES_FIFO_TAIL_DTS;

#if defined DSL_63138

#define RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_SIZE     2
typedef struct
{
	RDD_FREE_SKB_INDEXES_FIFO_TAIL_DTS	entry[ RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_DTS;

#define RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_PTR()	( RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + FREE_SKB_INDEXES_DDR_FIFO_TAIL_ADDRESS )

#endif
#define RDD_BPM_REPLY_RESERVED_FW_ONLY_NUMBER	12

typedef struct
{
	uint32_t	reserved_fw_only[RDD_BPM_REPLY_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BPM_REPLY_DTS;

#if defined DSL_63138

#define RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_SIZE     128
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_DTS;

#define RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_PTR()	( RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RATE_SHAPERS_STATUS_DESCRIPTOR_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_DTS;

#define RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_PTR()	( RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RUNNER_FWTRACE_MAINA_CURR_OFFSET_ADDRESS )

#endif
#define RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_ENTRY_RESERVED_FW_ONLY_NUMBER	24

typedef struct
{
	uint16_t	reserved_fw_only[RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_ENTRY_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_ENTRY_DTS;

#if defined DSL_63138

#define RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_SIZE     32
typedef struct
{
	RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_ENTRY_DTS	entry[ RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_DTS;

#define RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_PTR()	( RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + GPON_SKB_ENQUEUED_INDEXES_FIFO_ADDRESS )

#endif

typedef struct
{
	uint32_t	valid            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dhd_list_size    	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_proxy_enabled 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_priority      	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_0_priority   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_1_priority   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_2_priority   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_0_ssid_vector	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_1_ssid_vector	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_2_ssid_vector	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_FWD_ENTRY_DTS;

#define RDD_WLAN_MCAST_FWD_ENTRY_VALID_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_WLAN_MCAST_FWD_ENTRY_VALID_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_WLAN_MCAST_FWD_ENTRY_DHD_LIST_SIZE_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p, 0, 7, r)
#define RDD_WLAN_MCAST_FWD_ENTRY_DHD_LIST_SIZE_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p, 0, 7, v)
#define RDD_WLAN_MCAST_FWD_ENTRY_IS_PROXY_ENABLED_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 1, 6, 1, r)
#define RDD_WLAN_MCAST_FWD_ENTRY_IS_PROXY_ENABLED_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 1, 6, 1, v)
#define RDD_WLAN_MCAST_FWD_ENTRY_TX_PRIORITY_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 1, 3, 3, r)
#define RDD_WLAN_MCAST_FWD_ENTRY_TX_PRIORITY_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 1, 3, 3, v)
#define RDD_WLAN_MCAST_FWD_ENTRY_WFD_0_PRIORITY_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 1, 2, 1, r)
#define RDD_WLAN_MCAST_FWD_ENTRY_WFD_0_PRIORITY_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 1, 2, 1, v)
#define RDD_WLAN_MCAST_FWD_ENTRY_WFD_1_PRIORITY_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 1, 1, 1, r)
#define RDD_WLAN_MCAST_FWD_ENTRY_WFD_1_PRIORITY_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 1, 1, 1, v)
#define RDD_WLAN_MCAST_FWD_ENTRY_WFD_2_PRIORITY_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 1, 0, 1, r)
#define RDD_WLAN_MCAST_FWD_ENTRY_WFD_2_PRIORITY_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 1, 0, 1, v)
#define RDD_WLAN_MCAST_FWD_ENTRY_WFD_0_SSID_VECTOR_READ(r, p)                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_WLAN_MCAST_FWD_ENTRY_WFD_0_SSID_VECTOR_WRITE(v, p)                MWRITE_16((uint8_t *)p + 2, v)
#define RDD_WLAN_MCAST_FWD_ENTRY_WFD_1_SSID_VECTOR_READ(r, p)                 MREAD_16((uint8_t *)p + 4, r)
#define RDD_WLAN_MCAST_FWD_ENTRY_WFD_1_SSID_VECTOR_WRITE(v, p)                MWRITE_16((uint8_t *)p + 4, v)
#define RDD_WLAN_MCAST_FWD_ENTRY_WFD_2_SSID_VECTOR_READ(r, p)                 MREAD_16((uint8_t *)p + 6, r)
#define RDD_WLAN_MCAST_FWD_ENTRY_WFD_2_SSID_VECTOR_WRITE(v, p)                MWRITE_16((uint8_t *)p + 6, v)
#if defined DSL_63138

#define RDD_WLAN_MCAST_FWD_TABLE_SIZE     64
typedef struct
{
	RDD_WLAN_MCAST_FWD_ENTRY_DTS	entry[ RDD_WLAN_MCAST_FWD_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_FWD_TABLE_DTS;

#define RDD_WLAN_MCAST_FWD_TABLE_PTR()	( RDD_WLAN_MCAST_FWD_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_FWD_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_RUNNER_FWTRACE_PICOA_BASE_SIZE     128
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_PICOA_BASE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_PICOA_BASE_DTS;

#define RDD_RUNNER_FWTRACE_PICOA_BASE_PTR()	( RDD_RUNNER_FWTRACE_PICOA_BASE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RUNNER_FWTRACE_PICOA_BASE_ADDRESS )

#endif

typedef struct
{
	uint32_t	head_idx            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tail_idx            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_counter      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	valid_entries_number	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tail_entry          	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	head_entry          	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_threshold    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	queue_state         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	profile_id          	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved            	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tail_base_entry     	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	profile_en          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	union_field1        	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = union_field1, size = 7 bits
	uint32_t	reserved0           	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop_bit            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_controller_id  	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	queue_mask          	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cache_ptr           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DDR_QUEUE_DESCRIPTOR_DTS;

#define RDD_DDR_QUEUE_DESCRIPTOR_HEAD_IDX_READ(r, p)                             MREAD_16((uint8_t *)p, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_HEAD_IDX_WRITE(v, p)                            MWRITE_16((uint8_t *)p, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_TAIL_IDX_READ(r, p)                             MREAD_16((uint8_t *)p + 2, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_TAIL_IDX_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 2, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_PACKET_COUNTER_READ(r, p)                       MREAD_16((uint8_t *)p + 4, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_PACKET_COUNTER_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 4, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_VALID_ENTRIES_NUMBER_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 6, 4, 4, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_VALID_ENTRIES_NUMBER_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 6, 4, 4, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_TAIL_ENTRY_READ(r, p)                           FIELD_MREAD_16((uint8_t *)p + 6, 6, 6, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_TAIL_ENTRY_WRITE(v, p)                          FIELD_MWRITE_16((uint8_t *)p + 6, 6, 6, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_HEAD_ENTRY_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 7, 0, 6, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_HEAD_ENTRY_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 7, 0, 6, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_PACKET_THRESHOLD_READ(r, p)                     MREAD_16((uint8_t *)p + 8, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_PACKET_THRESHOLD_WRITE(v, p)                    MWRITE_16((uint8_t *)p + 8, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_QUEUE_STATE_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 10, 7, 1, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_QUEUE_STATE_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 10, 7, 1, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_PROFILE_ID_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 10, 2, 5, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_PROFILE_ID_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 10, 2, 5, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_TAIL_BASE_ENTRY_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 11, 0, 6, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_TAIL_BASE_ENTRY_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 11, 0, 6, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_PROFILE_EN_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 12, 7, 1, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_PROFILE_EN_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 12, 7, 1, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_UNION_FIELD1_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 12, 0, 7, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_UNION_FIELD1_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 12, 0, 7, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_DROP_BIT_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 12, 0, 1, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_DROP_BIT_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 12, 0, 1, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_RATE_CONTROLLER_ID_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 12, 0, 7, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_RATE_CONTROLLER_ID_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 12, 0, 7, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_QUEUE_MASK_READ(r, p)                           MREAD_8((uint8_t *)p + 13, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_QUEUE_MASK_WRITE(v, p)                          MWRITE_8((uint8_t *)p + 13, v)
#define RDD_DDR_QUEUE_DESCRIPTOR_CACHE_PTR_READ(r, p)                            MREAD_16((uint8_t *)p + 14, r)
#define RDD_DDR_QUEUE_DESCRIPTOR_CACHE_PTR_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 14, v)
#if defined DSL_63138

#define RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_SIZE     32
typedef struct
{
	RDD_DDR_QUEUE_DESCRIPTOR_DTS	entry[ RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_DTS;

#define RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_PTR()	( RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + SERVICE_QUEUES_DESCRIPTOR_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	mac_address_high	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mac_address_low 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reference_count 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_DTS;

#define RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_MAC_ADDRESS_HIGH_READ(r, p)                 MREAD_32((uint8_t *)p, r)
#define RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_MAC_ADDRESS_HIGH_WRITE(v, p)                MWRITE_32((uint8_t *)p, v)
#define RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_MAC_ADDRESS_LOW_READ(r, p)                  MREAD_16((uint8_t *)p + 4, r)
#define RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_MAC_ADDRESS_LOW_WRITE(v, p)                 MWRITE_16((uint8_t *)p + 4, v)
#define RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_REFERENCE_COUNT_READ(r, p)                  MREAD_8((uint8_t *)p + 6, r)
#define RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_REFERENCE_COUNT_WRITE(v, p)                 MWRITE_8((uint8_t *)p + 6, v)
#if defined DSL_63138

#define RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_SIZE     48
typedef struct
{
	RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_DTS	entry[ RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_DTS;

#define RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_PTR()	( RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	current_timeout            	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	current_packet_count       	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	configured_timeout         	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	configured_max_packet_count	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INTERRUPT_COALESCING_CONFIG_DTS;

#define RDD_INTERRUPT_COALESCING_CONFIG_CURRENT_TIMEOUT_READ(r, p)                             FIELD_MREAD_16((uint8_t *)p, 6, 10, r)
#define RDD_INTERRUPT_COALESCING_CONFIG_CURRENT_TIMEOUT_WRITE(v, p)                            FIELD_MWRITE_16((uint8_t *)p, 6, 10, v)
#define RDD_INTERRUPT_COALESCING_CONFIG_CURRENT_PACKET_COUNT_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 1, 0, 6, r)
#define RDD_INTERRUPT_COALESCING_CONFIG_CURRENT_PACKET_COUNT_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 1, 0, 6, v)
#define RDD_INTERRUPT_COALESCING_CONFIG_CONFIGURED_TIMEOUT_READ(r, p)                          FIELD_MREAD_16((uint8_t *)p + 2, 6, 10, r)
#define RDD_INTERRUPT_COALESCING_CONFIG_CONFIGURED_TIMEOUT_WRITE(v, p)                         FIELD_MWRITE_16((uint8_t *)p + 2, 6, 10, v)
#define RDD_INTERRUPT_COALESCING_CONFIG_CONFIGURED_MAX_PACKET_COUNT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 3, 0, 6, r)
#define RDD_INTERRUPT_COALESCING_CONFIG_CONFIGURED_MAX_PACKET_COUNT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 3, 0, 6, v)
#if defined DSL_63138

#define RDD_INTERRUPT_COALESCING_CONFIG_TABLE_SIZE     16
typedef struct
{
	RDD_INTERRUPT_COALESCING_CONFIG_DTS	entry[ RDD_INTERRUPT_COALESCING_CONFIG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INTERRUPT_COALESCING_CONFIG_TABLE_DTS;

#define RDD_INTERRUPT_COALESCING_CONFIG_TABLE_PTR()	( RDD_INTERRUPT_COALESCING_CONFIG_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + INTERRUPT_COALESCING_CONFIG_TABLE_ADDRESS )

#endif

typedef struct
{
	uint8_t	reserved1 	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	pbits     	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	dei       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DSCP_TO_PBITS_DEI_ENTRY_DTS;

#define RDD_DSCP_TO_PBITS_DEI_ENTRY_PBITS_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p, 1, 3, r)
#define RDD_DSCP_TO_PBITS_DEI_ENTRY_PBITS_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p, 1, 3, v)
#define RDD_DSCP_TO_PBITS_DEI_ENTRY_DEI_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p, 0, 1, r)
#define RDD_DSCP_TO_PBITS_DEI_ENTRY_DEI_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p, 0, 1, v)
#if defined DSL_63138

#define RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_SIZE2    64
typedef struct
{
	RDD_DSCP_TO_PBITS_DEI_ENTRY_DTS	entry[ RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_DTS;

#define RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_PTR()	( RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + GLOBAL_DSCP_TO_PBITS_DEI_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	packets   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bytes     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_SSID_STATS_ENTRY_DTS;

#define RDD_WLAN_MCAST_SSID_STATS_ENTRY_PACKETS_READ(r, p)                 MREAD_32((uint8_t *)p, r)
#define RDD_WLAN_MCAST_SSID_STATS_ENTRY_PACKETS_WRITE(v, p)                MWRITE_32((uint8_t *)p, v)
#define RDD_WLAN_MCAST_SSID_STATS_ENTRY_BYTES_READ(r, p)                   MREAD_32((uint8_t *)p + 4, r)
#define RDD_WLAN_MCAST_SSID_STATS_ENTRY_BYTES_WRITE(v, p)                  MWRITE_32((uint8_t *)p + 4, v)
#if defined DSL_63138

#define RDD_WLAN_MCAST_SSID_STATS_TABLE_SIZE     48
typedef struct
{
	RDD_WLAN_MCAST_SSID_STATS_ENTRY_DTS	entry[ RDD_WLAN_MCAST_SSID_STATS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_SSID_STATS_TABLE_DTS;

#define RDD_WLAN_MCAST_SSID_STATS_TABLE_PTR()	( RDD_WLAN_MCAST_SSID_STATS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_SSID_STATS_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	trace_on      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	trace_off_perm	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	unused        	:30	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocs        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TRACE_C_ENTRY_DTS;

#define RDD_TRACE_C_ENTRY_TRACE_ON_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_TRACE_C_ENTRY_TRACE_ON_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_TRACE_C_ENTRY_TRACE_OFF_PERM_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_TRACE_C_ENTRY_TRACE_OFF_PERM_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_TRACE_C_ENTRY_UNUSED_READ(r, p)                         FIELD_MREAD_32((uint8_t *)p, 0, 30, r)
#define RDD_TRACE_C_ENTRY_UNUSED_WRITE(v, p)                        FIELD_MWRITE_32((uint8_t *)p, 0, 30, v)
#define RDD_TRACE_C_ENTRY_ALLOCS_READ(r, p)                         MREAD_32((uint8_t *)p + 4, r)
#define RDD_TRACE_C_ENTRY_ALLOCS_WRITE(v, p)                        MWRITE_32((uint8_t *)p + 4, v)
#if defined DSL_63138

#define RDD_TRACE_C_TABLE_SIZE     4
typedef struct
{
	RDD_TRACE_C_ENTRY_DTS	entry[ RDD_TRACE_C_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TRACE_C_TABLE_DTS;

#define RDD_TRACE_C_TABLE_PTR()	( RDD_TRACE_C_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + TRACE_C_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	sustain_scheduling_mode  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_scheduling_mode     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	overall_rate_limiter_mode	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved                 	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_ffi_offset          	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sustain_ffi_offset       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queues_status    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_status      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sustain_vector           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_vector              	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_CFG_ENTRY_DTS;

#define RDD_SERVICE_QUEUES_CFG_ENTRY_SUSTAIN_SCHEDULING_MODE_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_SUSTAIN_SCHEDULING_MODE_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_PEAK_SCHEDULING_MODE_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_PEAK_SCHEDULING_MODE_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_OVERALL_RATE_LIMITER_MODE_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_OVERALL_RATE_LIMITER_MODE_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_PEAK_FFI_OFFSET_READ(r, p)                           MREAD_8((uint8_t *)p + 2, r)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_PEAK_FFI_OFFSET_WRITE(v, p)                          MWRITE_8((uint8_t *)p + 2, v)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_SUSTAIN_FFI_OFFSET_READ(r, p)                        MREAD_8((uint8_t *)p + 3, r)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_SUSTAIN_FFI_OFFSET_WRITE(v, p)                       MWRITE_8((uint8_t *)p + 3, v)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_SERVICE_QUEUES_STATUS_READ(r, p)                     MREAD_32((uint8_t *)p + 4, r)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_SERVICE_QUEUES_STATUS_WRITE(v, p)                    MWRITE_32((uint8_t *)p + 4, v)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_RATE_LIMITER_STATUS_READ(r, p)                       MREAD_32((uint8_t *)p + 8, r)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_RATE_LIMITER_STATUS_WRITE(v, p)                      MWRITE_32((uint8_t *)p + 8, v)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_SUSTAIN_VECTOR_READ(r, p)                            MREAD_32((uint8_t *)p + 12, r)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_SUSTAIN_VECTOR_WRITE(v, p)                           MWRITE_32((uint8_t *)p + 12, v)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_PEAK_VECTOR_READ(r, p)                               MREAD_32((uint8_t *)p + 16, r)
#define RDD_SERVICE_QUEUES_CFG_ENTRY_PEAK_VECTOR_WRITE(v, p)                              MWRITE_32((uint8_t *)p + 16, v)
#define RDD_DS_RATE_CONTROLLER_EXPONENT_TABLE_PTR()	( RDD_DS_RATE_CONTROLLER_EXPONENT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_RATE_CONTROLLER_EXPONENT_TABLE_ADDRESS )


typedef struct
{
	uint16_t	invalid     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	reserved    	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	radio_idx   	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	flow_ring_id	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_DTS;

#define RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_INVALID_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_INVALID_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_INVALID_L_READ( wv )                    FIELD_GET( wv, 15, 1 )
#define RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_INVALID_L_WRITE( v, wv )                FIELD_SET( v, 15, 1, wv )
#define RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_RADIO_IDX_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p, 2, 2, r)
#define RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_RADIO_IDX_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p, 2, 2, v)
#define RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_RADIO_IDX_L_READ( wv )                  FIELD_GET( wv, 10, 2 )
#define RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_RADIO_IDX_L_WRITE( v, wv )              FIELD_SET( v, 10, 2, wv )
#define RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_FLOW_RING_ID_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 0, 10, r)
#define RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_FLOW_RING_ID_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 0, 10, v)
#define RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_FLOW_RING_ID_L_READ( wv )               FIELD_GET( wv, 0, 10 )
#define RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_FLOW_RING_ID_L_WRITE( v, wv )           FIELD_SET( v, 0, 10, wv )
#if defined DSL_63138

#define RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_SIZE     16
typedef struct
{
	RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_DTS	entry[ RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_DTS;

#define RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_PTR()	( RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_DHD_FLOW_RING_CACHE_LKP_TABLE_ADDRESS )

#endif
#define RDD_PM_COUNTERS_BUFFER_RESERVED_FW_ONLY_NUMBER	8

typedef struct
{
	uint32_t	reserved_fw_only[RDD_PM_COUNTERS_BUFFER_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PM_COUNTERS_BUFFER_DTS;


typedef struct
{
	uint32_t	valid                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context_index          	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bucket_overflow_counter	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	command_list_length_64 	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_extend             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	protocol               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_port               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_port               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_ip                 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_ip                 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CONNECTION_ENTRY_DTS;

#define RDD_CONNECTION_ENTRY_VALID_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_CONNECTION_ENTRY_VALID_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_CONNECTION_ENTRY_CONTEXT_INDEX_READ(r, p)                           FIELD_MREAD_16((uint8_t *)p, 0, 15, r)
#define RDD_CONNECTION_ENTRY_CONTEXT_INDEX_WRITE(v, p)                          FIELD_MWRITE_16((uint8_t *)p, 0, 15, v)
#define RDD_CONNECTION_ENTRY_BUCKET_OVERFLOW_COUNTER_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 2, 5, 3, r)
#define RDD_CONNECTION_ENTRY_BUCKET_OVERFLOW_COUNTER_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 2, 5, 3, v)
#define RDD_CONNECTION_ENTRY_COMMAND_LIST_LENGTH_64_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 2, 1, 4, r)
#define RDD_CONNECTION_ENTRY_COMMAND_LIST_LENGTH_64_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 2, 1, 4, v)
#define RDD_CONNECTION_ENTRY_KEY_EXTEND_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 2, 0, 1, r)
#define RDD_CONNECTION_ENTRY_KEY_EXTEND_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 2, 0, 1, v)
#define RDD_CONNECTION_ENTRY_PROTOCOL_READ(r, p)                                MREAD_8((uint8_t *)p + 3, r)
#define RDD_CONNECTION_ENTRY_PROTOCOL_WRITE(v, p)                               MWRITE_8((uint8_t *)p + 3, v)
#define RDD_CONNECTION_ENTRY_SRC_PORT_READ(r, p)                                MREAD_16((uint8_t *)p + 4, r)
#define RDD_CONNECTION_ENTRY_SRC_PORT_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 4, v)
#define RDD_CONNECTION_ENTRY_DST_PORT_READ(r, p)                                MREAD_16((uint8_t *)p + 6, r)
#define RDD_CONNECTION_ENTRY_DST_PORT_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 6, v)
#define RDD_CONNECTION_ENTRY_SRC_IP_READ(r, p)                                  MREAD_32((uint8_t *)p + 8, r)
#define RDD_CONNECTION_ENTRY_SRC_IP_WRITE(v, p)                                 MWRITE_32((uint8_t *)p + 8, v)
#define RDD_CONNECTION_ENTRY_DST_IP_READ(r, p)                                  MREAD_32((uint8_t *)p + 12, r)
#define RDD_CONNECTION_ENTRY_DST_IP_WRITE(v, p)                                 MWRITE_32((uint8_t *)p + 12, v)
#if defined DSL_63138

#define RDD_DS_CONNECTION_BUFFER_TABLE_SIZE     5
#define RDD_DS_CONNECTION_BUFFER_TABLE_SIZE2    4
typedef struct
{
	RDD_CONNECTION_ENTRY_DTS	entry[ RDD_DS_CONNECTION_BUFFER_TABLE_SIZE ][ RDD_DS_CONNECTION_BUFFER_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CONNECTION_BUFFER_TABLE_DTS;

#define RDD_DS_CONNECTION_BUFFER_TABLE_PTR()	( RDD_DS_CONNECTION_BUFFER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_CONNECTION_BUFFER_TABLE_ADDRESS )

#endif

typedef struct
{
	uint16_t	port      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_L4_DST_PORT_ENTRY_DTS;

#define RDD_L4_DST_PORT_ENTRY_PORT_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_L4_DST_PORT_ENTRY_PORT_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)
#if defined DSL_63138

#define RDD_DS_L4_DST_PORT_TABLE_SIZE     256
typedef struct
{
	RDD_L4_DST_PORT_ENTRY_DTS	entry[ RDD_DS_L4_DST_PORT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_L4_DST_PORT_TABLE_DTS;

#define RDD_DS_L4_DST_PORT_TABLE_PTR()	( RDD_DS_L4_DST_PORT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_L4_DST_PORT_TABLE_ADDRESS )

#endif

typedef struct
{
	uint16_t	is_tcp    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	is_static 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	refcnt    	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	reason    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_L4_DST_PORT_CONTEXT_DTS;

#define RDD_L4_DST_PORT_CONTEXT_IS_TCP_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_L4_DST_PORT_CONTEXT_IS_TCP_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_L4_DST_PORT_CONTEXT_IS_STATIC_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_L4_DST_PORT_CONTEXT_IS_STATIC_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_L4_DST_PORT_CONTEXT_REFCNT_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p, 0, 6, r)
#define RDD_L4_DST_PORT_CONTEXT_REFCNT_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p, 0, 6, v)
#define RDD_L4_DST_PORT_CONTEXT_REASON_READ(r, p)                    MREAD_8((uint8_t *)p + 1, r)
#define RDD_L4_DST_PORT_CONTEXT_REASON_WRITE(v, p)                   MWRITE_8((uint8_t *)p + 1, v)
#if defined DSL_63138

#define RDD_L4_DST_PORT_CONTEXT_TABLE_SIZE     256
typedef struct
{
	RDD_L4_DST_PORT_CONTEXT_DTS	entry[ RDD_L4_DST_PORT_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_L4_DST_PORT_CONTEXT_TABLE_DTS;

#define RDD_L4_DST_PORT_CONTEXT_TABLE_PTR()	( RDD_L4_DST_PORT_CONTEXT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + L4_DST_PORT_CONTEXT_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_SIZE     16
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_DTS;

#define RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_PTR()	( RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_ADDRESS )

#endif

typedef struct
{
	uint32_t	flow_ring_base_low 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_ring_base_high	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	size               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flags              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_DTS;

#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_FLOW_RING_BASE_LOW_READ(r, p)                  MREAD_32((uint8_t *)p, r)
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_FLOW_RING_BASE_LOW_WRITE(v, p)                 MWRITE_32((uint8_t *)p, v)
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_FLOW_RING_BASE_LOW_L_READ( wv )                FIELD_GET( wv, 0, 32 )
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_FLOW_RING_BASE_LOW_L_WRITE( v, wv )            FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_FLOW_RING_BASE_HIGH_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_FLOW_RING_BASE_HIGH_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_FLOW_RING_BASE_HIGH_L_READ( wv )               FIELD_GET( wv, 0, 32 )
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_FLOW_RING_BASE_HIGH_L_WRITE( v, wv )           FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_SIZE_READ(r, p)                                MREAD_16((uint8_t *)p + 8, r)
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_SIZE_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 8, v)
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_SIZE_L_READ( wv )                              FIELD_GET( wv, 16, 16 )
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_SIZE_L_WRITE( v, wv )                          FIELD_SET( v, 16, 16, wv )
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_FLAGS_READ(r, p)                               MREAD_16((uint8_t *)p + 10, r)
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_FLAGS_WRITE(v, p)                              MWRITE_16((uint8_t *)p + 10, v)
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_FLAGS_L_READ( wv )                             FIELD_GET( wv, 0, 16 )
#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_FLAGS_L_WRITE( v, wv )                         FIELD_SET( v, 0, 16, wv )
#define RDD_PM_COUNTERS_RESERVED_FW_ONLY_NUMBER	1552

typedef struct
{
	uint32_t	reserved_fw_only[RDD_PM_COUNTERS_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PM_COUNTERS_DTS;


typedef struct
{
	uint32_t	size      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	addr      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DDR_QUEUE_ADDRESS_ENTRY_DTS;

#define RDD_DDR_QUEUE_ADDRESS_ENTRY_SIZE_READ(r, p)                      MREAD_16((uint8_t *)p, r)
#define RDD_DDR_QUEUE_ADDRESS_ENTRY_SIZE_WRITE(v, p)                     MWRITE_16((uint8_t *)p, v)
#define RDD_DDR_QUEUE_ADDRESS_ENTRY_ADDR_READ(r, p)                      MREAD_32((uint8_t *)p + 4, r)
#define RDD_DDR_QUEUE_ADDRESS_ENTRY_ADDR_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 4, v)
#if defined DSL_63138

#define RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_SIZE     32
typedef struct
{
	RDD_DDR_QUEUE_ADDRESS_ENTRY_DTS	entry[ RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_DTS;

#define RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_PTR()	( RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_ADDRESS )

#endif
#if defined DSL_63138

typedef struct
{
	uint32_t	reserved0         	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_offset    	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length     	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1         	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error_type        	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_bridge_port	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_memory     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	buffer_number     	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETHWAN2_RX_DESCRIPTOR_DTS;

#define RDD_ETHWAN2_RX_DESCRIPTOR_PAYLOAD_OFFSET_READ(r, p)                     FIELD_MREAD_32((uint8_t *)p + 0, 14, 7, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_PAYLOAD_OFFSET_WRITE(v, p)                    FIELD_MWRITE_32((uint8_t *)p + 0, 14, 7, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 2, 0, 14, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 2, 0, 14, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_ERROR_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_ERROR_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_ERROR_TYPE_READ(r, p)                         FIELD_MREAD_16((uint8_t *)p + 4, 6, 7, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_ERROR_TYPE_WRITE(v, p)                        FIELD_MWRITE_16((uint8_t *)p + 4, 6, 7, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_SOURCE_BRIDGE_PORT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 5, 0, 6, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_SOURCE_BRIDGE_PORT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 5, 0, 6, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_TARGET_MEMORY_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 6, 7, 1, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_TARGET_MEMORY_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 6, 7, 1, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_BUFFER_NUMBER_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 6, 0, 15, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_BUFFER_NUMBER_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 6, 0, 15, v)
#endif
#if defined DSL_63138

#define RDD_ETHWAN2_RX_INGRESS_QUEUE_SIZE     32
typedef struct
{
	RDD_ETHWAN2_RX_DESCRIPTOR_DTS	entry[ RDD_ETHWAN2_RX_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETHWAN2_RX_INGRESS_QUEUE_DTS;

#define RDD_ETHWAN2_RX_INGRESS_QUEUE_PTR()	( RDD_ETHWAN2_RX_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + ETHWAN2_RX_INGRESS_QUEUE_ADDRESS )

#endif

typedef struct
{
	uint32_t	flow_id                 	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_chksum_verified      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_bridge_port      	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length           	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_offset_flag     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reason                  	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dest_ssid               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2               	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	descriptor_type         	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ownership               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	host_data_buffer_pointer	:31	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4               	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_sync_1588_entry_index	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wl_metadata             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_DESCRIPTOR_DTS;

#define RDD_CPU_RX_DESCRIPTOR_FLOW_ID_READ(r, p)                                  FIELD_MREAD_16((uint8_t *)p, 4, 12, r)
#define RDD_CPU_RX_DESCRIPTOR_FLOW_ID_WRITE(v, p)                                 FIELD_MWRITE_16((uint8_t *)p, 4, 12, v)
#define RDD_CPU_RX_DESCRIPTOR_IS_CHKSUM_VERIFIED_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 1, 3, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_IS_CHKSUM_VERIFIED_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 1, 3, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_SOURCE_BRIDGE_PORT_READ(r, p)                       FIELD_MREAD_32((uint8_t *)p + 0, 14, 5, r)
#define RDD_CPU_RX_DESCRIPTOR_SOURCE_BRIDGE_PORT_WRITE(v, p)                      FIELD_MWRITE_32((uint8_t *)p + 0, 14, 5, v)
#define RDD_CPU_RX_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                            FIELD_MREAD_16((uint8_t *)p + 2, 0, 14, r)
#define RDD_CPU_RX_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                           FIELD_MWRITE_16((uint8_t *)p + 2, 0, 14, v)
#define RDD_CPU_RX_DESCRIPTOR_PAYLOAD_OFFSET_FLAG_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_PAYLOAD_OFFSET_FLAG_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_REASON_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p + 4, 1, 6, r)
#define RDD_CPU_RX_DESCRIPTOR_REASON_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p + 4, 1, 6, v)
#define RDD_CPU_RX_DESCRIPTOR_DEST_SSID_READ(r, p)                                FIELD_MREAD_32((uint8_t *)p + 4, 9, 16, r)
#define RDD_CPU_RX_DESCRIPTOR_DEST_SSID_WRITE(v, p)                               FIELD_MWRITE_32((uint8_t *)p + 4, 9, 16, v)
#define RDD_CPU_RX_DESCRIPTOR_DESCRIPTOR_TYPE_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 7, 0, 4, r)
#define RDD_CPU_RX_DESCRIPTOR_DESCRIPTOR_TYPE_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 7, 0, 4, v)
#define RDD_CPU_RX_DESCRIPTOR_OWNERSHIP_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 8, 7, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_OWNERSHIP_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 8, 7, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_HOST_DATA_BUFFER_POINTER_READ(r, p)                 FIELD_MREAD_32((uint8_t *)p + 8, 0, 31, r)
#define RDD_CPU_RX_DESCRIPTOR_HOST_DATA_BUFFER_POINTER_WRITE(v, p)                FIELD_MWRITE_32((uint8_t *)p + 8, 0, 31, v)
#define RDD_CPU_RX_DESCRIPTOR_IP_SYNC_1588_ENTRY_INDEX_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 13, 0, 4, r)
#define RDD_CPU_RX_DESCRIPTOR_IP_SYNC_1588_ENTRY_INDEX_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 13, 0, 4, v)
#define RDD_CPU_RX_DESCRIPTOR_WL_METADATA_READ(r, p)                              MREAD_16((uint8_t *)p + 14, r)
#define RDD_CPU_RX_DESCRIPTOR_WL_METADATA_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 14, v)
#if defined DSL_63138

#define RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_SIZE     14
typedef struct
{
	RDD_CPU_RX_DESCRIPTOR_DTS	entry[ RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_DTS;

#define RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_PTR()	( RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_RING_PACKET_DESCRIPTORS_CACHE_ADDRESS )

#endif

typedef struct
{
	uint32_t	reserved0        	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	entries_counter  	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	size_of_entry    	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	number_of_entries	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ring_pointer     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	interrupt_id     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop_counter     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RING_DESCRIPTOR_DTS;

#define RDD_RING_DESCRIPTOR_ENTRIES_COUNTER_READ(r, p)                   FIELD_MREAD_16((uint8_t *)p, 0, 11, r)
#define RDD_RING_DESCRIPTOR_ENTRIES_COUNTER_WRITE(v, p)                  FIELD_MWRITE_16((uint8_t *)p, 0, 11, v)
#define RDD_RING_DESCRIPTOR_SIZE_OF_ENTRY_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 2, 3, 5, r)
#define RDD_RING_DESCRIPTOR_SIZE_OF_ENTRY_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 2, 3, 5, v)
#define RDD_RING_DESCRIPTOR_NUMBER_OF_ENTRIES_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 2, 0, 11, r)
#define RDD_RING_DESCRIPTOR_NUMBER_OF_ENTRIES_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 2, 0, 11, v)
#define RDD_RING_DESCRIPTOR_RING_POINTER_READ(r, p)                      MREAD_32((uint8_t *)p + 4, r)
#define RDD_RING_DESCRIPTOR_RING_POINTER_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 4, v)
#define RDD_RING_DESCRIPTOR_INTERRUPT_ID_READ(r, p)                      MREAD_16((uint8_t *)p + 8, r)
#define RDD_RING_DESCRIPTOR_INTERRUPT_ID_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 8, v)
#define RDD_RING_DESCRIPTOR_DROP_COUNTER_READ(r, p)                      MREAD_16((uint8_t *)p + 10, r)
#define RDD_RING_DESCRIPTOR_DROP_COUNTER_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 10, v)
#if defined DSL_63138

#define RDD_RING_DESCRIPTORS_TABLE_SIZE     12
typedef struct
{
	RDD_RING_DESCRIPTOR_DTS	entry[ RDD_RING_DESCRIPTORS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RING_DESCRIPTORS_TABLE_DTS;

#define RDD_RING_DESCRIPTORS_TABLE_PTR()	( RDD_RING_DESCRIPTORS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RING_DESCRIPTORS_TABLE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_MAIN_A_DEBUG_TRACE_SIZE     512
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_MAIN_A_DEBUG_TRACE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_MAIN_A_DEBUG_TRACE_DTS;

#define RDD_MAIN_A_DEBUG_TRACE_PTR()	( RDD_MAIN_A_DEBUG_TRACE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + MAIN_A_DEBUG_TRACE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_PICO_A_DEBUG_TRACE_SIZE     512
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_PICO_A_DEBUG_TRACE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PICO_A_DEBUG_TRACE_DTS;

#define RDD_PICO_A_DEBUG_TRACE_PTR()	( RDD_PICO_A_DEBUG_TRACE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + PICO_A_DEBUG_TRACE_ADDRESS )

#endif
/* COMMON_B */

typedef struct
{
	uint32_t	head_ptr           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tail_ptr           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_counter     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	index              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_threshold   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	profile_ptr        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_controller_ptr	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	queue_mask         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_TX_QUEUE_DESCRIPTOR_DTS;

#define RDD_WAN_TX_QUEUE_DESCRIPTOR_HEAD_PTR_READ(r, p)                            MREAD_16((uint8_t *)p, r)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_HEAD_PTR_WRITE(v, p)                           MWRITE_16((uint8_t *)p, v)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_TAIL_PTR_READ(r, p)                            MREAD_16((uint8_t *)p + 2, r)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_TAIL_PTR_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 2, v)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_PACKET_COUNTER_READ(r, p)                      MREAD_16((uint8_t *)p + 4, r)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_PACKET_COUNTER_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 4, v)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_INDEX_READ(r, p)                               MREAD_8((uint8_t *)p + 6, r)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_INDEX_WRITE(v, p)                              MWRITE_8((uint8_t *)p + 6, v)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_PACKET_THRESHOLD_READ(r, p)                    MREAD_16((uint8_t *)p + 8, r)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_PACKET_THRESHOLD_WRITE(v, p)                   MWRITE_16((uint8_t *)p + 8, v)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_PROFILE_PTR_READ(r, p)                         MREAD_16((uint8_t *)p + 10, r)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_PROFILE_PTR_WRITE(v, p)                        MWRITE_16((uint8_t *)p + 10, v)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_RATE_CONTROLLER_PTR_READ(r, p)                 MREAD_16((uint8_t *)p + 12, r)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_RATE_CONTROLLER_PTR_WRITE(v, p)                MWRITE_16((uint8_t *)p + 12, v)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_QUEUE_MASK_READ(r, p)                          MREAD_16((uint8_t *)p + 14, r)
#define RDD_WAN_TX_QUEUE_DESCRIPTOR_QUEUE_MASK_WRITE(v, p)                         MWRITE_16((uint8_t *)p + 14, v)
#if defined DSL_63138

#define RDD_WAN_TX_QUEUES_TABLE_SIZE     256
typedef struct
{
	RDD_WAN_TX_QUEUE_DESCRIPTOR_DTS	entry[ RDD_WAN_TX_QUEUES_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_TX_QUEUES_TABLE_DTS;

#define RDD_WAN_TX_QUEUES_TABLE_PTR()	( RDD_WAN_TX_QUEUES_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + WAN_TX_QUEUES_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_US_CONNECTION_BUFFER_TABLE_SIZE     5
#define RDD_US_CONNECTION_BUFFER_TABLE_SIZE2    4
typedef struct
{
	RDD_CONNECTION_ENTRY_DTS	entry[ RDD_US_CONNECTION_BUFFER_TABLE_SIZE ][ RDD_US_CONNECTION_BUFFER_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CONNECTION_BUFFER_TABLE_DTS;

#define RDD_US_CONNECTION_BUFFER_TABLE_PTR()	( RDD_US_CONNECTION_BUFFER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_CONNECTION_BUFFER_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_IPV6_HOST_ADDRESS_CRC_TABLE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_IPV6_HOST_ADDRESS_CRC_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPV6_HOST_ADDRESS_CRC_TABLE_DTS;

#define RDD_IPV6_HOST_ADDRESS_CRC_TABLE_PTR()	( RDD_IPV6_HOST_ADDRESS_CRC_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + IPV6_HOST_ADDRESS_CRC_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_SIZE     16
typedef struct
{
	RDD_DDR_QUEUE_ADDRESS_ENTRY_DTS	entry[ RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_DTS;

#define RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_PTR()	( RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + EPON_DDR_QUEUE_ADDRESS_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_SIZE     32
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_DTS;

#define RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR()	( RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_ADDRESS - 0x8000 )

#endif

typedef struct
{
	uint32_t	context        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0      	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pbits          	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_outer       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlan           	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	gem_flow_extend	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	aging          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	skip           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	valid          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_CONTEXT_READ(r, p)                         MREAD_8((uint8_t *)p, r)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_CONTEXT_WRITE(v, p)                        MWRITE_8((uint8_t *)p, v)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_PBITS_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 4, 1, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_PBITS_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 4, 1, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_NO_OUTER_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 4, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_NO_OUTER_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 4, 0, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_VLAN_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p + 4, 12, 12, r)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_VLAN_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p + 4, 12, 12, v)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_GEM_FLOW_EXTEND_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 6, 4, 8, r)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_GEM_FLOW_EXTEND_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 6, 4, 8, v)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_AGING_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 7, 2, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_AGING_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 7, 2, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_SKIP_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 7, 1, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_SKIP_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 7, 1, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_VALID_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 7, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_VALID_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 7, 0, 1, v)

typedef struct
{
	uint32_t	context        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0      	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pbits          	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_outer       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlan           	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2      	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_port_extend	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	aging          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	skip           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	valid          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_CONTEXT_READ(r, p)                         MREAD_8((uint8_t *)p, r)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_CONTEXT_WRITE(v, p)                        MWRITE_8((uint8_t *)p, v)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_PBITS_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 4, 1, 3, r)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_PBITS_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 4, 1, 3, v)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_NO_OUTER_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 4, 0, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_NO_OUTER_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 4, 0, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_VLAN_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p + 4, 12, 12, r)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_VLAN_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p + 4, 12, 12, v)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_SRC_PORT_EXTEND_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 6, 4, 5, r)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_SRC_PORT_EXTEND_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 6, 4, 5, v)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_AGING_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 7, 2, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_AGING_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 7, 2, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_SKIP_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 7, 1, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_SKIP_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 7, 1, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_VALID_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 7, 0, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_VALID_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 7, 0, 1, v)

typedef struct
{
	uint32_t	context    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_index  	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	gem_flow   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inner_pbits	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_inner   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inner_vlan 	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_pbits	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_outer   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_vlan 	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	aging      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	skip       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	valid      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_CONTEXT_READ(r, p)                     MREAD_8((uint8_t *)p, r)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_CONTEXT_WRITE(v, p)                    MWRITE_8((uint8_t *)p, v)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_KEY_INDEX_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 1, 4, 4, r)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_KEY_INDEX_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 1, 4, 4, v)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_GEM_FLOW_READ(r, p)                    FIELD_MREAD_16((uint8_t *)p + 2, 4, 8, r)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_GEM_FLOW_WRITE(v, p)                   FIELD_MWRITE_16((uint8_t *)p + 2, 4, 8, v)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_INNER_PBITS_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 3, 1, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_INNER_PBITS_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 3, 1, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_NO_INNER_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 3, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_NO_INNER_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 3, 0, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_INNER_VLAN_READ(r, p)                  FIELD_MREAD_16((uint8_t *)p + 4, 4, 12, r)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_INNER_VLAN_WRITE(v, p)                 FIELD_MWRITE_16((uint8_t *)p + 4, 4, 12, v)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_OUTER_PBITS_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 5, 1, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_OUTER_PBITS_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 5, 1, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_NO_OUTER_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 5, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_NO_OUTER_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 5, 0, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_OUTER_VLAN_READ(r, p)                  FIELD_MREAD_16((uint8_t *)p + 6, 4, 12, r)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_OUTER_VLAN_WRITE(v, p)                 FIELD_MWRITE_16((uint8_t *)p + 6, 4, 12, v)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_AGING_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 7, 2, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_AGING_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 7, 2, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_SKIP_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 7, 1, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_SKIP_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 7, 1, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_VALID_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 7, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_VALID_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 7, 0, 1, v)

typedef struct
{
	uint32_t	context        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_index      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid           	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_bridge_port	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inner_pbits    	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_inner       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inner_vlan     	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_pbits    	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_outer       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_vlan     	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	aging          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	skip           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	valid          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_CONTEXT_READ(r, p)                         MREAD_8((uint8_t *)p, r)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_CONTEXT_WRITE(v, p)                        MWRITE_8((uint8_t *)p, v)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_KEY_INDEX_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 1, 4, 4, r)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_KEY_INDEX_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 1, 4, 4, v)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_SSID_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 2, 4, 4, r)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_SSID_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 2, 4, 4, v)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_SRC_BRIDGE_PORT_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 2, 4, 8, r)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_SRC_BRIDGE_PORT_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 2, 4, 8, v)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_INNER_PBITS_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 3, 1, 3, r)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_INNER_PBITS_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 3, 1, 3, v)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_NO_INNER_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 3, 0, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_NO_INNER_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 3, 0, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_INNER_VLAN_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 4, 4, 12, r)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_INNER_VLAN_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 4, 4, 12, v)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_OUTER_PBITS_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 5, 1, 3, r)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_OUTER_PBITS_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 5, 1, 3, v)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_NO_OUTER_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 5, 0, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_NO_OUTER_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 5, 0, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_OUTER_VLAN_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 6, 4, 12, r)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_OUTER_VLAN_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 6, 4, 12, v)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_AGING_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 7, 2, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_AGING_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 7, 2, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_SKIP_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 7, 1, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_SKIP_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 7, 1, 1, v)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_VALID_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 7, 0, 1, r)
#define RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_VALID_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 7, 0, 1, v)

typedef struct
{
	uint32_t	context   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_index 	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_0     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_1     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	aging     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	skip      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	valid     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_DTS;

#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_CONTEXT_READ(r, p)                   MREAD_8((uint8_t *)p, r)
#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_CONTEXT_WRITE(v, p)                  MWRITE_8((uint8_t *)p, v)
#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_KEY_INDEX_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 1, 4, 4, r)
#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_KEY_INDEX_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 1, 4, 4, v)
#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_KEY_0_READ(r, p)                     FIELD_MREAD_32((uint8_t *)p + 0, 4, 16, r)
#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_KEY_0_WRITE(v, p)                    FIELD_MWRITE_32((uint8_t *)p + 0, 4, 16, v)
#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_KEY_1_READ(r, p)                     { uint32_t temp; FIELD_MREAD_32((uint8_t *)p, 0, 4, temp); r = temp << 28; FIELD_MREAD_32(((uint8_t *)p + 4), 4, 28, temp); r = r | temp; }
#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_KEY_1_WRITE(v, p)                    { FIELD_MWRITE_32((uint8_t *)p, 0, 4, ((v & 0xf0000000) >> 28)); FIELD_MWRITE_32(((uint8_t *)p + 4), 4, 28, (v & 0x0fffffff)); }
#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_AGING_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 7, 2, 1, r)
#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_AGING_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 7, 2, 1, v)
#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_SKIP_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 7, 1, 1, r)
#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_SKIP_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 7, 1, 1, v)
#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_VALID_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 7, 0, 1, r)
#define RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_VALID_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 7, 0, 1, v)
#if defined DSL_63138

#define RDD_RUNNER_FWTRACE_MAINB_BASE_SIZE     128
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINB_BASE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINB_BASE_DTS;

#define RDD_RUNNER_FWTRACE_MAINB_BASE_PTR()	( RDD_RUNNER_FWTRACE_MAINB_BASE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + RUNNER_FWTRACE_MAINB_BASE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_RUNNER_FWTRACE_PICOB_BASE_SIZE     128
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_PICOB_BASE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_PICOB_BASE_DTS;

#define RDD_RUNNER_FWTRACE_PICOB_BASE_PTR()	( RDD_RUNNER_FWTRACE_PICOB_BASE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + RUNNER_FWTRACE_PICOB_BASE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_US_L4_DST_PORT_TABLE_SIZE     256
typedef struct
{
	RDD_L4_DST_PORT_ENTRY_DTS	entry[ RDD_US_L4_DST_PORT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_L4_DST_PORT_TABLE_DTS;

#define RDD_US_L4_DST_PORT_TABLE_PTR()	( RDD_US_L4_DST_PORT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_L4_DST_PORT_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_CPU_RX_RUNNER_B_SCRATCHPAD_SIZE     16
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_CPU_RX_RUNNER_B_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_RUNNER_B_SCRATCHPAD_DTS;

#define RDD_CPU_RX_RUNNER_B_SCRATCHPAD_PTR()	( RDD_CPU_RX_RUNNER_B_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + CPU_RX_RUNNER_B_SCRATCHPAD_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_EPON_DDR_CACHE_FIFO_SIZE     192
typedef struct
{
	RDD_BBH_TX_DESCRIPTOR_DTS	entry[ RDD_EPON_DDR_CACHE_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EPON_DDR_CACHE_FIFO_DTS;

#define RDD_EPON_DDR_CACHE_FIFO_PTR()	( RDD_EPON_DDR_CACHE_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + EPON_DDR_CACHE_FIFO_ADDRESS - 0x8000 )

#endif

typedef struct
{
	uint32_t	flow_ring_base_low 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_ring_base_high	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	size               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flags              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rd_idx             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wr_idx             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_DTS;

#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLOW_RING_BASE_LOW_READ(r, p)                  MREAD_32((uint8_t *)p, r)
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLOW_RING_BASE_LOW_WRITE(v, p)                 MWRITE_32((uint8_t *)p, v)
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLOW_RING_BASE_LOW_L_READ( wv )                FIELD_GET( wv, 0, 32 )
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLOW_RING_BASE_LOW_L_WRITE( v, wv )            FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLOW_RING_BASE_HIGH_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLOW_RING_BASE_HIGH_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLOW_RING_BASE_HIGH_L_READ( wv )               FIELD_GET( wv, 0, 32 )
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLOW_RING_BASE_HIGH_L_WRITE( v, wv )           FIELD_SET( v, 0, 32, wv )
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_SIZE_READ(r, p)                                MREAD_16((uint8_t *)p + 8, r)
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_SIZE_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 8, v)
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_SIZE_L_READ( wv )                              FIELD_GET( wv, 16, 16 )
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_SIZE_L_WRITE( v, wv )                          FIELD_SET( v, 16, 16, wv )
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLAGS_READ(r, p)                               MREAD_16((uint8_t *)p + 10, r)
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLAGS_WRITE(v, p)                              MWRITE_16((uint8_t *)p + 10, v)
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLAGS_L_READ( wv )                             FIELD_GET( wv, 0, 16 )
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLAGS_L_WRITE( v, wv )                         FIELD_SET( v, 0, 16, wv )
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_RD_IDX_READ(r, p)                              MREAD_16((uint8_t *)p + 12, r)
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_RD_IDX_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 12, v)
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_RD_IDX_L_READ( wv )                            FIELD_GET( wv, 16, 16 )
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_RD_IDX_L_WRITE( v, wv )                        FIELD_SET( v, 16, 16, wv )
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_WR_IDX_READ(r, p)                              MREAD_16((uint8_t *)p + 14, r)
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_WR_IDX_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 14, v)
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_WR_IDX_L_READ( wv )                            FIELD_GET( wv, 0, 16 )
#define RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_WR_IDX_L_WRITE( v, wv )                        FIELD_SET( v, 0, 16, wv )
#if defined DSL_63138

#define RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_SIZE     16
typedef struct
{
	RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_DTS	entry[ RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_DTS;

#define RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_PTR()	( RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + DHD_FLOW_RING_CACHE_CTX_TABLE_ADDRESS - 0x8000 )

#endif
#define RDD_FC_FLOW_IP_ADDRESSES_ENTRY_SA_DA_ADDRESSES_NUMBER	32
#define RDD_FC_FLOW_IP_ADDRESSES_ENTRY_RESERVED0_NUMBER	4
#define RDD_FC_FLOW_IP_ADDRESSES_ENTRY_RESERVED1_NUMBER	4

typedef struct
{
	uint8_t	sa_da_addresses[RDD_FC_FLOW_IP_ADDRESSES_ENTRY_SA_DA_ADDRESSES_NUMBER];
	uint8_t	reserved0[RDD_FC_FLOW_IP_ADDRESSES_ENTRY_RESERVED0_NUMBER];
	uint32_t	reference_count                                                           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved1[RDD_FC_FLOW_IP_ADDRESSES_ENTRY_RESERVED1_NUMBER];
	uint32_t	is_ipv6_address                                                           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_FLOW_IP_ADDRESSES_ENTRY_DTS;

#define RDD_FC_FLOW_IP_ADDRESSES_ENTRY_SA_DA_ADDRESSES_READ(r, p, i)              MREAD_I_8((uint8_t *)p, i, r)
#define RDD_FC_FLOW_IP_ADDRESSES_ENTRY_SA_DA_ADDRESSES_WRITE(v, p, i)             MWRITE_I_8((uint8_t *)p, i, v)
#define RDD_FC_FLOW_IP_ADDRESSES_ENTRY_REFERENCE_COUNT_READ(r, p)                 MREAD_32((uint8_t *)p + 36, r)
#define RDD_FC_FLOW_IP_ADDRESSES_ENTRY_REFERENCE_COUNT_WRITE(v, p)                MWRITE_32((uint8_t *)p + 36, v)
#define RDD_FC_FLOW_IP_ADDRESSES_ENTRY_IS_IPV6_ADDRESS_READ(r, p)                 MREAD_32((uint8_t *)p + 40, r)
#define RDD_FC_FLOW_IP_ADDRESSES_ENTRY_IS_IPV6_ADDRESS_WRITE(v, p)                MWRITE_32((uint8_t *)p + 40, v)
#if defined DSL_63138

#define RDD_FC_FLOW_IP_ADDRESSES_TABLE_SIZE     4
typedef struct
{
	RDD_FC_FLOW_IP_ADDRESSES_ENTRY_DTS	entry[ RDD_FC_FLOW_IP_ADDRESSES_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_FLOW_IP_ADDRESSES_TABLE_DTS;

#define RDD_FC_FLOW_IP_ADDRESSES_TABLE_PTR()	( RDD_FC_FLOW_IP_ADDRESSES_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + FC_FLOW_IP_ADDRESSES_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_DTS;

#define RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_PTR()	( RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + RUNNER_FWTRACE_MAINB_CURR_OFFSET_ADDRESS - 0x8000 )

#endif
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_TX_QUEUE_ADDR_NUMBER	8

typedef struct
{
	uint32_t	current_peak_budget                                                     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocated_peak_budget_exponent                                          	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocated_peak_budget                                                   	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_budget_limit_exponent                                              	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_budget_limit                                                       	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	current_sustain_budget                                                  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocated_sustain_budget                                                	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_controller_mask                                                    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wan_channel_ptr                                                         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	priority_queues_status                                                  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_burst_counter                                                      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_weight                                                             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0                                                               	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	peak_burst_flag                                                         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	tx_queue_addr[RDD_US_RATE_CONTROLLER_DESCRIPTOR_TX_QUEUE_ADDR_NUMBER];
	uint32_t	reserved1                                                               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RATE_CONTROLLER_DESCRIPTOR_DTS;

#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_CURRENT_PEAK_BUDGET_READ(r, p)                            MREAD_32((uint8_t *)p, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_CURRENT_PEAK_BUDGET_WRITE(v, p)                           MWRITE_32((uint8_t *)p, v)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_ALLOCATED_PEAK_BUDGET_EXPONENT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 4, 6, 2, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_ALLOCATED_PEAK_BUDGET_EXPONENT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 4, 6, 2, v)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_ALLOCATED_PEAK_BUDGET_READ(r, p)                          FIELD_MREAD_16((uint8_t *)p + 4, 0, 14, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_ALLOCATED_PEAK_BUDGET_WRITE(v, p)                         FIELD_MWRITE_16((uint8_t *)p + 4, 0, 14, v)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_PEAK_BUDGET_LIMIT_EXPONENT_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 6, 6, 2, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_PEAK_BUDGET_LIMIT_EXPONENT_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 6, 6, 2, v)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_PEAK_BUDGET_LIMIT_READ(r, p)                              FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_PEAK_BUDGET_LIMIT_WRITE(v, p)                             FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_CURRENT_SUSTAIN_BUDGET_READ(r, p)                         MREAD_32((uint8_t *)p + 8, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_CURRENT_SUSTAIN_BUDGET_WRITE(v, p)                        MWRITE_32((uint8_t *)p + 8, v)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_ALLOCATED_SUSTAIN_BUDGET_READ(r, p)                       MREAD_32((uint8_t *)p + 12, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_ALLOCATED_SUSTAIN_BUDGET_WRITE(v, p)                      MWRITE_32((uint8_t *)p + 12, v)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_RATE_CONTROLLER_MASK_READ(r, p)                           MREAD_32((uint8_t *)p + 16, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_RATE_CONTROLLER_MASK_WRITE(v, p)                          MWRITE_32((uint8_t *)p + 16, v)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_WAN_CHANNEL_PTR_READ(r, p)                                MREAD_16((uint8_t *)p + 20, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_WAN_CHANNEL_PTR_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 20, v)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_PRIORITY_QUEUES_STATUS_READ(r, p)                         MREAD_16((uint8_t *)p + 22, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_PRIORITY_QUEUES_STATUS_WRITE(v, p)                        MWRITE_16((uint8_t *)p + 22, v)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_PEAK_BURST_COUNTER_READ(r, p)                             MREAD_16((uint8_t *)p + 24, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_PEAK_BURST_COUNTER_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 24, v)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_PEAK_WEIGHT_READ(r, p)                                    MREAD_8((uint8_t *)p + 26, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_PEAK_WEIGHT_WRITE(v, p)                                   MWRITE_8((uint8_t *)p + 26, v)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_PEAK_BURST_FLAG_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 27, 0, 1, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_PEAK_BURST_FLAG_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 27, 0, 1, v)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_TX_QUEUE_ADDR_READ(r, p, i)                               MREAD_I_16((uint8_t *)p + 28, i, r)
#define RDD_US_RATE_CONTROLLER_DESCRIPTOR_TX_QUEUE_ADDR_WRITE(v, p, i)                              MWRITE_I_16((uint8_t *)p + 28, i, v)
#if defined DSL_63138

#define RDD_US_RATE_CONTROLLERS_TABLE_SIZE     128
typedef struct
{
	RDD_US_RATE_CONTROLLER_DESCRIPTOR_DTS	entry[ RDD_US_RATE_CONTROLLERS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RATE_CONTROLLERS_TABLE_DTS;

#define RDD_US_RATE_CONTROLLERS_TABLE_PTR()	( RDD_US_RATE_CONTROLLERS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_RATE_CONTROLLERS_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_RUNNER_B_SCRATCHPAD_SIZE     8
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_RUNNER_B_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_B_SCRATCHPAD_DTS;

#define RDD_RUNNER_B_SCRATCHPAD_PTR()	( RDD_RUNNER_B_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + RUNNER_B_SCRATCHPAD_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_US_RING_PACKET_DESCRIPTORS_CACHE_SIZE     14
typedef struct
{
	RDD_CPU_RX_DESCRIPTOR_DTS	entry[ RDD_US_RING_PACKET_DESCRIPTORS_CACHE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RING_PACKET_DESCRIPTORS_CACHE_DTS;

#define RDD_US_RING_PACKET_DESCRIPTORS_CACHE_PTR()	( RDD_US_RING_PACKET_DESCRIPTORS_CACHE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_RING_PACKET_DESCRIPTORS_CACHE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_IPV4_HOST_ADDRESS_TABLE_SIZE     8
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_IPV4_HOST_ADDRESS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPV4_HOST_ADDRESS_TABLE_DTS;

#define RDD_IPV4_HOST_ADDRESS_TABLE_PTR()	( RDD_IPV4_HOST_ADDRESS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + IPV4_HOST_ADDRESS_TABLE_ADDRESS - 0x8000 )

#endif
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_PER_AC_AGGREGATION_THRESHOLDS_NUMBER	4
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_PER_AC_AGGREGATION_TIMEOUTS_NUMBER	4
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_PER_AC_AGGREGATION_TIMEOUT_CNTRS_NUMBER	4

typedef struct
{
	uint32_t	us_dhd_doorbell                                                                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	r2d_wr_fr_desc_base_ptr                                                                                           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	d2r_rd_fr_desc_base_ptr                                                                                           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	r2d_rd_fr_desc_base_ptr                                                                                           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	d2r_wr_fr_desc_base_ptr                                                                                           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rx_post_fr_base_ptr                                                                                               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_complete_fr_base_ptr                                                                                           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rx_complete_fr_base_ptr                                                                                           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_post_mgmt_fr_base_ptr                                                                                          	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rx_post_r2d_index                                                                                                 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	us_rd_fr_r2d_indexes                                                                                              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	us_wr_fr_r2d_indexes                                                                                              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rx_rd_fr_d2r_indexes                                                                                              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rx_wr_fr_d2r_indexes                                                                                              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	add_llcsnap_header                                                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	aggregation_bypass_cpu_tx                                                                                         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	aggregation_bypass_non_udp_tcp                                                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                                                                         	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	aggregation_bypass_tcp_pktlen                                                                                     	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	per_ac_aggregation_thresholds[RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_PER_AC_AGGREGATION_THRESHOLDS_NUMBER];
	uint8_t	per_ac_aggregation_timeouts[RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_PER_AC_AGGREGATION_TIMEOUTS_NUMBER];
	uint8_t	per_ac_aggregation_timeout_cntrs[RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_PER_AC_AGGREGATION_TIMEOUT_CNTRS_NUMBER];
	uint32_t	reserved2                                                                                                         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_DTS;

#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_US_DHD_DOORBELL_READ(r, p)                                  MREAD_32((uint8_t *)p, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_US_DHD_DOORBELL_WRITE(v, p)                                 MWRITE_32((uint8_t *)p, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_R2D_WR_FR_DESC_BASE_PTR_READ(r, p)                          MREAD_32((uint8_t *)p + 4, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_R2D_WR_FR_DESC_BASE_PTR_WRITE(v, p)                         MWRITE_32((uint8_t *)p + 4, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_D2R_RD_FR_DESC_BASE_PTR_READ(r, p)                          MREAD_32((uint8_t *)p + 8, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_D2R_RD_FR_DESC_BASE_PTR_WRITE(v, p)                         MWRITE_32((uint8_t *)p + 8, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_R2D_RD_FR_DESC_BASE_PTR_READ(r, p)                          MREAD_32((uint8_t *)p + 12, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_R2D_RD_FR_DESC_BASE_PTR_WRITE(v, p)                         MWRITE_32((uint8_t *)p + 12, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_D2R_WR_FR_DESC_BASE_PTR_READ(r, p)                          MREAD_32((uint8_t *)p + 16, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_D2R_WR_FR_DESC_BASE_PTR_WRITE(v, p)                         MWRITE_32((uint8_t *)p + 16, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_RX_POST_FR_BASE_PTR_READ(r, p)                              MREAD_32((uint8_t *)p + 20, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_RX_POST_FR_BASE_PTR_WRITE(v, p)                             MWRITE_32((uint8_t *)p + 20, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_TX_COMPLETE_FR_BASE_PTR_READ(r, p)                          MREAD_32((uint8_t *)p + 24, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_TX_COMPLETE_FR_BASE_PTR_WRITE(v, p)                         MWRITE_32((uint8_t *)p + 24, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_RX_COMPLETE_FR_BASE_PTR_READ(r, p)                          MREAD_32((uint8_t *)p + 28, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_RX_COMPLETE_FR_BASE_PTR_WRITE(v, p)                         MWRITE_32((uint8_t *)p + 28, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_TX_POST_MGMT_FR_BASE_PTR_READ(r, p)                         MREAD_32((uint8_t *)p + 32, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_TX_POST_MGMT_FR_BASE_PTR_WRITE(v, p)                        MWRITE_32((uint8_t *)p + 32, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_RX_POST_R2D_INDEX_READ(r, p)                                MREAD_16((uint8_t *)p + 36, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_RX_POST_R2D_INDEX_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 36, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_US_RD_FR_R2D_INDEXES_READ(r, p)                             MREAD_16((uint8_t *)p + 38, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_US_RD_FR_R2D_INDEXES_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 38, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_US_WR_FR_R2D_INDEXES_READ(r, p)                             MREAD_16((uint8_t *)p + 40, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_US_WR_FR_R2D_INDEXES_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 40, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_RX_RD_FR_D2R_INDEXES_READ(r, p)                             MREAD_16((uint8_t *)p + 42, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_RX_RD_FR_D2R_INDEXES_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 42, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_RX_WR_FR_D2R_INDEXES_READ(r, p)                             MREAD_16((uint8_t *)p + 44, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_RX_WR_FR_D2R_INDEXES_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 44, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_ADD_LLCSNAP_HEADER_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 46, 7, 1, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_ADD_LLCSNAP_HEADER_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 46, 7, 1, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_AGGREGATION_BYPASS_CPU_TX_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 46, 6, 1, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_AGGREGATION_BYPASS_CPU_TX_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 46, 6, 1, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_AGGREGATION_BYPASS_NON_UDP_TCP_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 46, 5, 1, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_AGGREGATION_BYPASS_NON_UDP_TCP_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 46, 5, 1, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_AGGREGATION_BYPASS_TCP_PKTLEN_READ(r, p)                    MREAD_8((uint8_t *)p + 47, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_AGGREGATION_BYPASS_TCP_PKTLEN_WRITE(v, p)                   MWRITE_8((uint8_t *)p + 47, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_PER_AC_AGGREGATION_THRESHOLDS_READ(r, p, i)                 MREAD_I_8((uint8_t *)p + 48, i, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_PER_AC_AGGREGATION_THRESHOLDS_WRITE(v, p, i)                MWRITE_I_8((uint8_t *)p + 48, i, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_PER_AC_AGGREGATION_TIMEOUTS_READ(r, p, i)                   MREAD_I_8((uint8_t *)p + 52, i, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_PER_AC_AGGREGATION_TIMEOUTS_WRITE(v, p, i)                  MWRITE_I_8((uint8_t *)p + 52, i, v)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_PER_AC_AGGREGATION_TIMEOUT_CNTRS_READ(r, p, i)              MREAD_I_8((uint8_t *)p + 56, i, r)
#define RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_PER_AC_AGGREGATION_TIMEOUT_CNTRS_WRITE(v, p, i)             MWRITE_I_8((uint8_t *)p + 56, i, v)
#if defined DSL_63138

#define RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_SIZE     3
typedef struct
{
	RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_DTS	entry[ RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_DTS;

#define RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_PTR()	( RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + DHD_RADIO_INSTANCE_COMMON_B_DATA_ADDRESS - 0x8000 )

#endif
#define RDD_DUMMY_RATE_CONTROLLER_DESCRIPTOR_RESERVED_FW_ONLY_NUMBER	16

typedef struct
{
	uint32_t	reserved_fw_only[RDD_DUMMY_RATE_CONTROLLER_DESCRIPTOR_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DUMMY_RATE_CONTROLLER_DESCRIPTOR_DTS;

#if defined DSL_63138

#define RDD_MAIN_B_DEBUG_TRACE_SIZE     512
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_MAIN_B_DEBUG_TRACE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_MAIN_B_DEBUG_TRACE_DTS;

#define RDD_MAIN_B_DEBUG_TRACE_PTR()	( RDD_MAIN_B_DEBUG_TRACE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + MAIN_B_DEBUG_TRACE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_PICO_B_DEBUG_TRACE_SIZE     512
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_PICO_B_DEBUG_TRACE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PICO_B_DEBUG_TRACE_DTS;

#define RDD_PICO_B_DEBUG_TRACE_PTR()	( RDD_PICO_B_DEBUG_TRACE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + PICO_B_DEBUG_TRACE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_SIZE     16
typedef struct
{
	RDD_DDR_QUEUE_DESCRIPTOR_DTS	entry[ RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_DTS;

#define RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_PTR()	( RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + EPON_DDR_QUEUE_DESCRIPTORS_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_SIZE     40
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_DTS;

#define RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_PTR()	( RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_ADDRESS - 0x8000 )

#endif
#define RDD_DUMMY_WAN_TX_QUEUE_DESCRIPTOR_RESERVED_FW_ONLY_NUMBER	4

typedef struct
{
	uint32_t	reserved_fw_only[RDD_DUMMY_WAN_TX_QUEUE_DESCRIPTOR_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DUMMY_WAN_TX_QUEUE_DESCRIPTOR_DTS;

#if defined DSL_63138

#define RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_SIZE     8
typedef struct
{
	RDD_BROADCOM_SWITCH_PORT_MAPPING_DTS	entry[ RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_DTS;

#define RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR()	( RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_SIZE     4
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_DTS;

#define RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_PTR()	( RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_ADDRESS - 0x8000 )

#endif

typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR_DTS;

#if defined DSL_63138

#define RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_SIZE     40
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_DTS;

#define RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_PTR()	( RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_ADDRESS - 0x8000 )

#endif
#define RDD_US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_PTR()	( RDD_US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_ADDRESS - 0x8000 )

#define RDD_PACKET_SRAM_TO_DDR_COPY_BUFFER_RESERVED_FW_ONLY_NUMBER	32

typedef struct
{
	uint32_t	reserved_fw_only[RDD_PACKET_SRAM_TO_DDR_COPY_BUFFER_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PACKET_SRAM_TO_DDR_COPY_BUFFER_DTS;

#define RDD_LAN_INGRESS_FIFO_ENTRY_RESERVED_FW_ONLY_NUMBER	32

typedef struct
{
	uint16_t	reserved_fw_only[RDD_LAN_INGRESS_FIFO_ENTRY_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_LAN_INGRESS_FIFO_ENTRY_DTS;

#if defined DSL_63138

#define RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_SIZE     16
typedef struct
{
	RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_DTS	entry[ RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_DTS;

#define RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_PTR()	( RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_DHD_FLOW_RING_CACHE_LKP_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_WAN_ENQUEUE_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_WAN_ENQUEUE_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_ENQUEUE_INGRESS_QUEUE_DTS;

#define RDD_WAN_ENQUEUE_INGRESS_QUEUE_PTR()	( RDD_WAN_ENQUEUE_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + WAN_ENQUEUE_INGRESS_QUEUE_ADDRESS - 0x8000 )

#endif
/* DDR */
#define RDD_BPM_PACKET_BUFFER_RESERVED_FW_ONLY_NUMBER	512

typedef struct
{
	uint32_t	reserved_fw_only[RDD_BPM_PACKET_BUFFER_RESERVED_FW_ONLY_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BPM_PACKET_BUFFER_DTS;

#if defined DSL_63138

#define RDD_BPM_PACKET_BUFFERS_SIZE     7680
typedef struct
{
	RDD_BPM_PACKET_BUFFER_DTS	entry[ RDD_BPM_PACKET_BUFFERS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BPM_PACKET_BUFFERS_DTS;

#endif

#define RDD_CONNECTION_TABLE_SIZE     32768
typedef struct
{
	RDD_CONNECTION_ENTRY_DTS	entry[ RDD_CONNECTION_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CONNECTION_TABLE_DTS;

#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_NUMBER	112

typedef struct
{
	uint32_t	flow_hits                                                             	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_bytes                                                            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	multicast_flag                                                        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	overflow                                                              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_routed                                                             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_tos_mangle                                                         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_l2_accel                                                           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mtu                                                                   	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tos                                                                   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_high_prio                                                          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_mapt_us                                                            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_df                                                                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue_id                                                      	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_unicast_wfd_any                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	priority                                                              	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_prio                                                              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_idx                                                               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_phy                                                            	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_addresses_table_index                                              	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	link_specific_union                                                   	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	command_list[RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_NUMBER];
	uint32_t	valid                                                                 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	command_list_length_64                                                	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4                                                             	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_unicast_wfd_nic                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	connection_direction                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	connection_table_index                                                	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_DTS;

#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_FLOW_HITS_READ(r, p)                                MREAD_32((uint8_t *)p, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_FLOW_HITS_WRITE(v, p)                               MWRITE_32((uint8_t *)p, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_FLOW_BYTES_READ(r, p)                               MREAD_32((uint8_t *)p + 4, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_FLOW_BYTES_WRITE(v, p)                              MWRITE_32((uint8_t *)p + 4, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_MULTICAST_FLAG_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 8, 7, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_MULTICAST_FLAG_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 8, 7, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_OVERFLOW_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 8, 6, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_OVERFLOW_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 8, 6, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_ROUTED_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 8, 5, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_ROUTED_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 8, 5, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_TOS_MANGLE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 8, 4, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_TOS_MANGLE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 8, 4, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_L2_ACCEL_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 8, 3, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_L2_ACCEL_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 8, 3, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_MTU_READ(r, p)                                      FIELD_MREAD_16((uint8_t *)p + 8, 0, 11, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_MTU_WRITE(v, p)                                     FIELD_MWRITE_16((uint8_t *)p + 8, 0, 11, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_TOS_READ(r, p)                                      MREAD_8((uint8_t *)p + 10, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_TOS_WRITE(v, p)                                     MWRITE_8((uint8_t *)p + 10, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_HIGH_PRIO_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 11, 7, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_HIGH_PRIO_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 11, 7, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_MAPT_US_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 11, 6, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_MAPT_US_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 11, 6, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_DF_READ(r, p)                                    FIELD_MREAD_8((uint8_t *)p + 11, 5, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_DF_WRITE(v, p)                                   FIELD_MWRITE_8((uint8_t *)p + 11, 5, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_SERVICE_QUEUE_ID_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 11, 0, 5, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_SERVICE_QUEUE_ID_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 11, 0, 5, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_DROP_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 12, 7, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_DROP_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 12, 7, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_UNICAST_WFD_ANY_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 12, 6, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_UNICAST_WFD_ANY_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 12, 6, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_PRIORITY_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 12, 2, 4, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_PRIORITY_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 12, 2, 4, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_WFD_PRIO_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 12, 1, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_WFD_PRIO_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 12, 1, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_WFD_IDX_READ(r, p)                                  FIELD_MREAD_16((uint8_t *)p + 12, 7, 2, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_WFD_IDX_WRITE(v, p)                                 FIELD_MWRITE_16((uint8_t *)p + 12, 7, 2, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_EGRESS_PHY_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 13, 5, 2, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_EGRESS_PHY_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 13, 5, 2, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IP_ADDRESSES_TABLE_INDEX_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 13, 2, 3, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IP_ADDRESSES_TABLE_INDEX_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 13, 2, 3, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_LINK_SPECIFIC_UNION_READ(r, p)                      FIELD_MREAD_32((uint8_t *)p + 12, 0, 18, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_LINK_SPECIFIC_UNION_WRITE(v, p)                     FIELD_MWRITE_32((uint8_t *)p + 12, 0, 18, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_READ(r, p, i)                          MREAD_I_8((uint8_t *)p + 16, i, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_WRITE(v, p, i)                         MWRITE_I_8((uint8_t *)p + 16, i, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_VALID_READ(r, p)                                    MREAD_8((uint8_t *)p + 128, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_VALID_WRITE(v, p)                                   MWRITE_8((uint8_t *)p + 128, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_LENGTH_64_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 129, 4, 4, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_LENGTH_64_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 129, 4, 4, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_UNICAST_WFD_NIC_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 129, 1, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_IS_UNICAST_WFD_NIC_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 129, 1, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_CONNECTION_DIRECTION_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 129, 0, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_CONNECTION_DIRECTION_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 129, 0, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_CONNECTION_TABLE_INDEX_READ(r, p)                   MREAD_16((uint8_t *)p + 130, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_CONNECTION_TABLE_INDEX_WRITE(v, p)                  MWRITE_16((uint8_t *)p + 130, v)

typedef struct
{
	uint32_t	reserved1      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4      	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_info    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = egress_info, size = 2 bits
	uint32_t	lag_port       	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_mode    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	egress_port    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	traffic_class  	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_controller	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_DTS;

#define RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_EGRESS_INFO_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 13, 0, 2, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_EGRESS_INFO_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 13, 0, 2, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_LAG_PORT_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 13, 0, 2, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_LAG_PORT_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 13, 0, 2, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_EGRESS_MODE_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 13, 0, 1, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_EGRESS_MODE_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 13, 0, 1, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_EGRESS_PORT_READ(r, p)                     MREAD_8((uint8_t *)p + 14, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_EGRESS_PORT_WRITE(v, p)                    MWRITE_8((uint8_t *)p + 14, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_TRAFFIC_CLASS_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 15, 5, 3, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_TRAFFIC_CLASS_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 15, 5, 3, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_RATE_CONTROLLER_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 15, 0, 5, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_RATE_CONTROLLER_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 15, 0, 5, v)

typedef struct
{
	uint32_t	reserved1 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4 	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	chain_idx 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_UCAST_FLOW_CONTEXT_WFD_NIC_ENTRY_DTS;

#define RDD_FC_UCAST_FLOW_CONTEXT_WFD_NIC_ENTRY_CHAIN_IDX_READ(r, p)                 MREAD_8((uint8_t *)p + 15, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_WFD_NIC_ENTRY_CHAIN_IDX_WRITE(v, p)                MWRITE_8((uint8_t *)p + 15, v)

typedef struct
{
	uint32_t	reserved1   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4   	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wifi_ssid   	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_ring_id	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_UCAST_FLOW_CONTEXT_WFD_DHD_ENTRY_DTS;

#define RDD_FC_UCAST_FLOW_CONTEXT_WFD_DHD_ENTRY_WIFI_SSID_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 14, 2, 4, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_WFD_DHD_ENTRY_WIFI_SSID_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 14, 2, 4, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_WFD_DHD_ENTRY_FLOW_RING_ID_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 14, 0, 10, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_WFD_DHD_ENTRY_FLOW_RING_ID_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 14, 0, 10, v)

typedef struct
{
	uint32_t	reserved1   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	radio_idx   	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wifi_ssid   	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_ring_id	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_UCAST_FLOW_CONTEXT_RNR_DHD_ENTRY_DTS;

#define RDD_FC_UCAST_FLOW_CONTEXT_RNR_DHD_ENTRY_RADIO_IDX_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 14, 6, 2, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_RNR_DHD_ENTRY_RADIO_IDX_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 14, 6, 2, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_RNR_DHD_ENTRY_WIFI_SSID_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 14, 2, 4, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_RNR_DHD_ENTRY_WIFI_SSID_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 14, 2, 4, v)
#define RDD_FC_UCAST_FLOW_CONTEXT_RNR_DHD_ENTRY_FLOW_RING_ID_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 14, 0, 10, r)
#define RDD_FC_UCAST_FLOW_CONTEXT_RNR_DHD_ENTRY_FLOW_RING_ID_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 14, 0, 10, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_NUMBER	112

typedef struct
{
	uint32_t	flow_hits                                                                	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_bytes                                                               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	multicast_flag                                                           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	overflow                                                                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_routed                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_tos_mangle                                                            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_l2_accel                                                              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mtu                                                                      	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tos                                                                      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_high_prio                                                             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                                                                	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue_id                                                         	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop                                                                     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_unicast_wfd_any                                                       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	priority                                                                 	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_prio                                                                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_idx                                                                  	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_phy                                                               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_addresses_table_index                                                 	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	link_specific_union                                                      	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	command_list[RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_NUMBER];
	uint32_t	valid                                                                    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	command_list_length_64                                                   	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4                                                                	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_unicast_wfd_nic                                                       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	connection_direction                                                     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	connection_table_index                                                   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_DTS;

#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_FLOW_HITS_READ(r, p)                                MREAD_32((uint8_t *)p, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_FLOW_HITS_WRITE(v, p)                               MWRITE_32((uint8_t *)p, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_FLOW_BYTES_READ(r, p)                               MREAD_32((uint8_t *)p + 4, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_FLOW_BYTES_WRITE(v, p)                              MWRITE_32((uint8_t *)p + 4, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_MULTICAST_FLAG_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 8, 7, 1, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_MULTICAST_FLAG_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 8, 7, 1, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_OVERFLOW_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 8, 6, 1, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_OVERFLOW_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 8, 6, 1, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_ROUTED_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 8, 5, 1, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_ROUTED_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 8, 5, 1, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_TOS_MANGLE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 8, 4, 1, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_TOS_MANGLE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 8, 4, 1, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_L2_ACCEL_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 8, 3, 1, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_L2_ACCEL_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 8, 3, 1, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_MTU_READ(r, p)                                      FIELD_MREAD_16((uint8_t *)p + 8, 0, 11, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_MTU_WRITE(v, p)                                     FIELD_MWRITE_16((uint8_t *)p + 8, 0, 11, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_TOS_READ(r, p)                                      MREAD_8((uint8_t *)p + 10, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_TOS_WRITE(v, p)                                     MWRITE_8((uint8_t *)p + 10, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_HIGH_PRIO_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 11, 7, 1, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_HIGH_PRIO_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 11, 7, 1, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_SERVICE_QUEUE_ID_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 11, 0, 5, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_SERVICE_QUEUE_ID_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 11, 0, 5, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_DROP_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 12, 7, 1, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_DROP_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 12, 7, 1, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_UNICAST_WFD_ANY_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 12, 6, 1, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_UNICAST_WFD_ANY_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 12, 6, 1, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_PRIORITY_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 12, 2, 4, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_PRIORITY_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 12, 2, 4, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_WFD_PRIO_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 12, 1, 1, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_WFD_PRIO_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 12, 1, 1, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_WFD_IDX_READ(r, p)                                  FIELD_MREAD_16((uint8_t *)p + 12, 7, 2, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_WFD_IDX_WRITE(v, p)                                 FIELD_MWRITE_16((uint8_t *)p + 12, 7, 2, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_EGRESS_PHY_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 13, 5, 2, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_EGRESS_PHY_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 13, 5, 2, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IP_ADDRESSES_TABLE_INDEX_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 13, 2, 3, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IP_ADDRESSES_TABLE_INDEX_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 13, 2, 3, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_LINK_SPECIFIC_UNION_READ(r, p)                      FIELD_MREAD_32((uint8_t *)p + 12, 0, 18, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_LINK_SPECIFIC_UNION_WRITE(v, p)                     FIELD_MWRITE_32((uint8_t *)p + 12, 0, 18, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_READ(r, p, i)                          MREAD_I_8((uint8_t *)p + 16, i, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_WRITE(v, p, i)                         MWRITE_I_8((uint8_t *)p + 16, i, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_VALID_READ(r, p)                                    MREAD_8((uint8_t *)p + 128, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_VALID_WRITE(v, p)                                   MWRITE_8((uint8_t *)p + 128, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_LENGTH_64_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 129, 4, 4, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_LENGTH_64_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 129, 4, 4, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_UNICAST_WFD_NIC_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 129, 1, 1, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_UNICAST_WFD_NIC_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 129, 1, 1, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_CONNECTION_DIRECTION_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 129, 0, 1, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_CONNECTION_DIRECTION_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 129, 0, 1, v)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_CONNECTION_TABLE_INDEX_READ(r, p)                   MREAD_16((uint8_t *)p + 130, r)
#define RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_CONNECTION_TABLE_INDEX_WRITE(v, p)                  MWRITE_16((uint8_t *)p + 130, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_PORT_CONTEXT_NUMBER	8
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_L3_COMMAND_LIST_NUMBER	20
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_RESERVED4_NUMBER	56

typedef struct
{
	uint32_t	flow_hits                                                                  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_bytes                                                                 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	multicast_flag                                                             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	overflow                                                                   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_routed                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_tos_mangle                                                              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	number_of_ports                                                            	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	port_mask                                                                  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                                                                  	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mtu                                                                        	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tos                                                                        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                                                                  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wlan_mcast_clients                                                         	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wlan_mcast_index                                                           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mcast_port_header_buffer_ptr                                               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	port_context[RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_PORT_CONTEXT_NUMBER];
	uint8_t	l3_command_list[RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_L3_COMMAND_LIST_NUMBER];
	uint8_t	reserved4[RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_RESERVED4_NUMBER];
	uint32_t	valid                                                                      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	command_list_length_64                                                     	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved5                                                                  	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	connection_direction                                                       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	connection_table_index                                                     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_DTS;

#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_FLOW_HITS_READ(r, p)                                    MREAD_32((uint8_t *)p, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_FLOW_HITS_WRITE(v, p)                                   MWRITE_32((uint8_t *)p, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_FLOW_BYTES_READ(r, p)                                   MREAD_32((uint8_t *)p + 4, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_FLOW_BYTES_WRITE(v, p)                                  MWRITE_32((uint8_t *)p + 4, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_MULTICAST_FLAG_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 8, 7, 1, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_MULTICAST_FLAG_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 8, 7, 1, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_OVERFLOW_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 8, 6, 1, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_OVERFLOW_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 8, 6, 1, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_IS_ROUTED_READ(r, p)                                    FIELD_MREAD_8((uint8_t *)p + 8, 5, 1, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_IS_ROUTED_WRITE(v, p)                                   FIELD_MWRITE_8((uint8_t *)p + 8, 5, 1, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_IS_TOS_MANGLE_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 8, 4, 1, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_IS_TOS_MANGLE_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 8, 4, 1, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_NUMBER_OF_PORTS_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 8, 0, 4, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_NUMBER_OF_PORTS_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 8, 0, 4, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_PORT_MASK_READ(r, p)                                    MREAD_8((uint8_t *)p + 9, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_PORT_MASK_WRITE(v, p)                                   MWRITE_8((uint8_t *)p + 9, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_MTU_READ(r, p)                                          FIELD_MREAD_16((uint8_t *)p + 10, 0, 11, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_MTU_WRITE(v, p)                                         FIELD_MWRITE_16((uint8_t *)p + 10, 0, 11, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_TOS_READ(r, p)                                          MREAD_8((uint8_t *)p + 12, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_TOS_WRITE(v, p)                                         MWRITE_8((uint8_t *)p + 12, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_WLAN_MCAST_CLIENTS_READ(r, p)                           MREAD_8((uint8_t *)p + 14, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_WLAN_MCAST_CLIENTS_WRITE(v, p)                          MWRITE_8((uint8_t *)p + 14, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_WLAN_MCAST_INDEX_READ(r, p)                             MREAD_8((uint8_t *)p + 15, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_WLAN_MCAST_INDEX_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 15, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_MCAST_PORT_HEADER_BUFFER_PTR_READ(r, p)                 MREAD_32((uint8_t *)p + 16, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_MCAST_PORT_HEADER_BUFFER_PTR_WRITE(v, p)                MWRITE_32((uint8_t *)p + 16, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_PORT_CONTEXT_READ(r, p, i)                              MREAD_I_32((uint8_t *)p + 20, i, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_PORT_CONTEXT_WRITE(v, p, i)                             MWRITE_I_32((uint8_t *)p + 20, i, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_L3_COMMAND_LIST_READ(r, p, i)                           MREAD_I_8((uint8_t *)p + 52, i, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_L3_COMMAND_LIST_WRITE(v, p, i)                          MWRITE_I_8((uint8_t *)p + 52, i, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_VALID_READ(r, p)                                        MREAD_8((uint8_t *)p + 128, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_VALID_WRITE(v, p)                                       MWRITE_8((uint8_t *)p + 128, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_LENGTH_64_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 129, 4, 4, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_LENGTH_64_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 129, 4, 4, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_CONNECTION_DIRECTION_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 129, 0, 1, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_CONNECTION_DIRECTION_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 129, 0, 1, v)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_CONNECTION_TABLE_INDEX_READ(r, p)                       MREAD_16((uint8_t *)p + 130, r)
#define RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_CONNECTION_TABLE_INDEX_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 130, v)
#if defined DSL_63138

#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE_SIZE     8
typedef struct
{
	RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_DTS	entry[ RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE_DTS;

#endif
#if defined DSL_63138

#define RDD_DHD_RX_POST_DDR_BUFFER_SIZE     1024
typedef struct
{
	RDD_DHD_RX_POST_DESCRIPTOR_DTS	entry[ RDD_DHD_RX_POST_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_POST_DDR_BUFFER_DTS;

#endif
#if defined DSL_63138

#define RDD_DHD_RX_COMPLETE_DDR_BUFFER_SIZE     1024
typedef struct
{
	RDD_DHD_RX_COMPLETE_DESCRIPTOR_DTS	entry[ RDD_DHD_RX_COMPLETE_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_COMPLETE_DDR_BUFFER_DTS;

#endif
#if defined DSL_63138

#define RDD_DHD_TX_POST_DDR_BUFFER_SIZE     8
#define RDD_DHD_TX_POST_DDR_BUFFER_SIZE2    16
typedef struct
{
	RDD_DHD_TX_POST_DESCRIPTOR_DTS	entry[ RDD_DHD_TX_POST_DDR_BUFFER_SIZE ][ RDD_DHD_TX_POST_DDR_BUFFER_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_DDR_BUFFER_DTS;

#endif
#if defined DSL_63138

#define RDD_DHD_TX_COMPLETE_DDR_BUFFER_SIZE     16
typedef struct
{
	RDD_DHD_TX_COMPLETE_DESCRIPTOR_DTS	entry[ RDD_DHD_TX_COMPLETE_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_COMPLETE_DDR_BUFFER_DTS;

#endif
#if defined DSL_63138

#define RDD_R2D_WR_ARR_DDR_BUFFER_SIZE     128
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_R2D_WR_ARR_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_R2D_WR_ARR_DDR_BUFFER_DTS;

#endif
#if defined DSL_63138

#define RDD_D2R_RD_ARR_DDR_BUFFER_SIZE     128
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_D2R_RD_ARR_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_D2R_RD_ARR_DDR_BUFFER_DTS;

#endif
#if defined DSL_63138

#define RDD_R2D_RD_ARR_DDR_BUFFER_SIZE     128
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_R2D_RD_ARR_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_R2D_RD_ARR_DDR_BUFFER_DTS;

#endif
#if defined DSL_63138

#define RDD_D2R_WR_ARR_DDR_BUFFER_SIZE     128
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_D2R_WR_ARR_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_D2R_WR_ARR_DDR_BUFFER_DTS;

#endif
#define RDD_WLAN_MCAST_DHD_LIST_ENTRY_ARRAY_DHD_STATION_NUMBER	64

typedef struct
{
	uint8_t	dhd_station[RDD_WLAN_MCAST_DHD_LIST_ENTRY_ARRAY_DHD_STATION_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_DHD_LIST_ENTRY_ARRAY_DTS;

#define RDD_WLAN_MCAST_DHD_LIST_ENTRY_ARRAY_DHD_STATION_READ(r, p, i)              MREAD_I_8((uint8_t *)p, i, r)
#define RDD_WLAN_MCAST_DHD_LIST_ENTRY_ARRAY_DHD_STATION_WRITE(v, p, i)             MWRITE_I_8((uint8_t *)p, i, v)
#if defined DSL_63138

#define RDD_WLAN_MCAST_DHD_LIST_TABLE_SIZE     64
typedef struct
{
	RDD_WLAN_MCAST_DHD_LIST_ENTRY_ARRAY_DTS	entry[ RDD_WLAN_MCAST_DHD_LIST_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_DHD_LIST_TABLE_DTS;

#endif

typedef struct
{
	uint8_t	valid     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	index     	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_DHD_LIST_ENTRY_DTS;

#define RDD_WLAN_MCAST_DHD_LIST_ENTRY_VALID_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_WLAN_MCAST_DHD_LIST_ENTRY_VALID_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_WLAN_MCAST_DHD_LIST_ENTRY_INDEX_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 0, 7, r)
#define RDD_WLAN_MCAST_DHD_LIST_ENTRY_INDEX_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 0, 7, v)
/* PSRAM */
/* PRIVATE_A */
#if defined DSL_63148

#define RDD_INGRESS_HANDLER_BUFFER_SIZE     32
typedef struct
{
	RDD_IH_BUFFER_DTS	entry[ RDD_INGRESS_HANDLER_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_HANDLER_BUFFER_DTS;

#define RDD_INGRESS_HANDLER_BUFFER_PTR()	( RDD_INGRESS_HANDLER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + INGRESS_HANDLER_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

typedef struct
{
	uint32_t	crc_calc          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wan_port_or_fstat 	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_bridge_port	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length     	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	absolute_normal   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	last_indication   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pti               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	_1588             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	add_indication    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	header_number     	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_offset    	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_memory     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_location   	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = packet_location, size = 14 bits
	uint32_t	buffer_number     	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs_address_index 	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_DESCRIPTOR_DTS;

#define RDD_BBH_TX_DESCRIPTOR_CRC_CALC_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_CRC_CALC_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_WAN_PORT_OR_FSTAT_READ(r, p)                  FIELD_MREAD_16((uint8_t *)p, 3, 12, r)
#define RDD_BBH_TX_DESCRIPTOR_WAN_PORT_OR_FSTAT_WRITE(v, p)                 FIELD_MWRITE_16((uint8_t *)p, 3, 12, v)
#define RDD_BBH_TX_DESCRIPTOR_SOURCE_BRIDGE_PORT_READ(r, p)                 FIELD_MREAD_32((uint8_t *)p + 0, 14, 5, r)
#define RDD_BBH_TX_DESCRIPTOR_SOURCE_BRIDGE_PORT_WRITE(v, p)                FIELD_MWRITE_32((uint8_t *)p + 0, 14, 5, v)
#define RDD_BBH_TX_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 2, 0, 14, r)
#define RDD_BBH_TX_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 2, 0, 14, v)
#define RDD_BBH_TX_DESCRIPTOR_ABSOLUTE_NORMAL_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_ABSOLUTE_NORMAL_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_LAST_INDICATION_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_LAST_INDICATION_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_PTI_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 4, 4, 2, r)
#define RDD_BBH_TX_DESCRIPTOR_PTI_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 4, 4, 2, v)
#define RDD_BBH_TX_DESCRIPTOR__1588_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 4, 3, 1, r)
#define RDD_BBH_TX_DESCRIPTOR__1588_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 4, 3, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_ADD_INDICATION_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 4, 2, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_ADD_INDICATION_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 4, 2, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_HEADER_NUMBER_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 4, 7, 3, r)
#define RDD_BBH_TX_DESCRIPTOR_HEADER_NUMBER_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 4, 7, 3, v)
#define RDD_BBH_TX_DESCRIPTOR_PAYLOAD_OFFSET_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 5, 0, 7, r)
#define RDD_BBH_TX_DESCRIPTOR_PAYLOAD_OFFSET_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 5, 0, 7, v)
#define RDD_BBH_TX_DESCRIPTOR_TARGET_MEMORY_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 6, 7, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_TARGET_MEMORY_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 6, 7, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_PACKET_LOCATION_READ(r, p)                    FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_BBH_TX_DESCRIPTOR_PACKET_LOCATION_WRITE(v, p)                   FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#define RDD_BBH_TX_DESCRIPTOR_BUFFER_NUMBER_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_BBH_TX_DESCRIPTOR_BUFFER_NUMBER_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#define RDD_BBH_TX_DESCRIPTOR_ABS_ADDRESS_INDEX_READ(r, p)                  FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_BBH_TX_DESCRIPTOR_ABS_ADDRESS_INDEX_WRITE(v, p)                 FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#endif
#if defined DSL_63148

#define RDD_DS_CONNECTION_CONTEXT_BUFFER_SIZE     8
typedef struct
{
	RDD_CONNECTION_CONTEXT_BUFFER_ENTRY_DTS	entry[ RDD_DS_CONNECTION_CONTEXT_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CONNECTION_CONTEXT_BUFFER_DTS;

#define RDD_DS_CONNECTION_CONTEXT_BUFFER_PTR()	( RDD_DS_CONNECTION_CONTEXT_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CONNECTION_CONTEXT_BUFFER_ADDRESS )

#endif
#define RDD_DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE_PTR()	( RDD_DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_DS_CPU_REASON_TO_METER_TABLE_SIZE     64
typedef struct
{
	RDD_CPU_REASON_TO_METER_ENTRY_DTS	entry[ RDD_DS_CPU_REASON_TO_METER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_REASON_TO_METER_TABLE_DTS;

#define RDD_DS_CPU_REASON_TO_METER_TABLE_PTR()	( RDD_DS_CPU_REASON_TO_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_REASON_TO_METER_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_SIZE     8
typedef struct
{
	RDD_DS_SERVICE_QUEUE_DESCRIPTOR_DTS	entry[ RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_DTS;

#define RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_PTR()	( RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_ADDRESS )

#endif
#define RDD_DS_POLICER_TABLE_PTR()	( RDD_DS_POLICER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_POLICER_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_IPSEC_DS_BUFFER_POOL_SIZE     2
typedef struct
{
	RDD_IPSEC_DS_BUFFER_DTS	entry[ RDD_IPSEC_DS_BUFFER_POOL_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_BUFFER_POOL_DTS;

#define RDD_IPSEC_DS_BUFFER_POOL_PTR()	( RDD_IPSEC_DS_BUFFER_POOL_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_DS_BUFFER_POOL_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_IPSEC_DS_SA_DESC_TABLE_SIZE     16
typedef struct
{
	RDD_IPSEC_SA_DESC_DTS	entry[ RDD_IPSEC_DS_SA_DESC_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_SA_DESC_TABLE_DTS;

#define RDD_IPSEC_DS_SA_DESC_TABLE_PTR()	( RDD_IPSEC_DS_SA_DESC_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_DS_SA_DESC_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_IPSEC_US_SA_DESC_TABLE_SIZE     16
typedef struct
{
	RDD_IPSEC_SA_DESC_DTS	entry[ RDD_IPSEC_US_SA_DESC_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_US_SA_DESC_TABLE_DTS;

#define RDD_IPSEC_US_SA_DESC_TABLE_PTR()	( RDD_IPSEC_US_SA_DESC_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_US_SA_DESC_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_SIZE     32
typedef struct
{
	RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_DTS	entry[ RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_DTS;

#define RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_PTR()	( RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + SERVICE_QUEUES_RATE_LIMITER_TABLE_ADDRESS )

#endif
#define RDD_DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_PTR()	( RDD_DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_ETH_TX_LOCAL_REGISTERS_SIZE     9
typedef struct
{
	RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_DTS	entry[ RDD_ETH_TX_LOCAL_REGISTERS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_LOCAL_REGISTERS_DTS;

#define RDD_ETH_TX_LOCAL_REGISTERS_PTR()	( RDD_ETH_TX_LOCAL_REGISTERS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_LOCAL_REGISTERS_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_SIZE     8
typedef struct
{
	RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY_DTS	entry[ RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_DTS;

#define RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_PTR()	( RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_SIZE     32
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_DTS;

#define RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_PTR()	( RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_MAIN_PROFILING_BUFFER_RUNNER_ADDRESS )

#endif
#define RDD_DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE_PTR()	( RDD_DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_RATE_LIMITER_REMAINDER_TABLE_SIZE     32
typedef struct
{
	RDD_RATE_LIMITER_REMAINDER_ENTRY_DTS	entry[ RDD_RATE_LIMITER_REMAINDER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RATE_LIMITER_REMAINDER_TABLE_DTS;

#define RDD_RATE_LIMITER_REMAINDER_TABLE_PTR()	( RDD_RATE_LIMITER_REMAINDER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + RATE_LIMITER_REMAINDER_TABLE_ADDRESS )

#endif
#if defined DSL_63148

typedef struct
{
	uint32_t	vlan_index_table_ptr	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	opbit_remark_mode   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipbit_remark_mode   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wifi_ssid           	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dei_remark_enable   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dei_value           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue_mode  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	forward_mode        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_port         	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	qos_mapping_mode    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	traffic_class       	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_mode        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_id          	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_shaping_mode   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	union_field1        	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = union_field1, size = 7 bits
	uint32_t	rate_shaper_id      	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1           	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue       	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	subnet_id           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_pbit          	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inner_pbit          	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp_remarking_mode 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp                	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ecn                 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_VLAN_INDEX_TABLE_PTR_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 3, 13, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_VLAN_INDEX_TABLE_PTR_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 3, 13, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OPBIT_REMARK_MODE_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 1, 2, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OPBIT_REMARK_MODE_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 1, 2, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_IPBIT_REMARK_MODE_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 1, 1, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_IPBIT_REMARK_MODE_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 1, 1, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_WIFI_SSID_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p + 0, 13, 4, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_WIFI_SSID_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p + 0, 13, 4, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_REMARK_ENABLE_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 2, 4, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_REMARK_ENABLE_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 2, 4, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_VALUE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 2, 3, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_VALUE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 2, 3, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 2, 2, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 2, 2, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_FORWARD_MODE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 2, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_FORWARD_MODE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 2, 0, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_EGRESS_PORT_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 3, 4, 4, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_EGRESS_PORT_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 3, 4, 4, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_QOS_MAPPING_MODE_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 3, 3, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_QOS_MAPPING_MODE_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 3, 3, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_TRAFFIC_CLASS_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 3, 0, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_TRAFFIC_CLASS_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 3, 0, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DROP_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DROP_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_CPU_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_CPU_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_MODE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 4, 5, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_MODE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 4, 5, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_ID_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 4, 1, 4, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_ID_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 4, 1, 4, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_SHAPING_MODE_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 4, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_SHAPING_MODE_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 4, 0, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_UNION_FIELD1_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 5, 1, 7, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_UNION_FIELD1_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 5, 1, 7, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_SHAPER_ID_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 5, 1, 7, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_SHAPER_ID_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 5, 1, 7, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SERVICE_QUEUE_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 5, 1, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SERVICE_QUEUE_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 5, 1, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SUBNET_ID_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p + 4, 15, 2, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SUBNET_ID_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p + 4, 15, 2, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OUTER_PBIT_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 6, 4, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OUTER_PBIT_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 6, 4, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_INNER_PBIT_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 6, 1, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_INNER_PBIT_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 6, 1, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_REMARKING_MODE_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 6, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_REMARKING_MODE_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 6, 0, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 7, 2, 6, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 7, 2, 6, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_ECN_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 7, 0, 2, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_ECN_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 7, 0, 2, v)
#endif
#if defined DSL_63148

#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_SIZE     256
typedef struct
{
	RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_FC_MCAST_CONNECTION2_TABLE_SIZE     128
typedef struct
{
	RDD_FC_MCAST_CONNECTION2_ENTRY_DTS	entry[ RDD_FC_MCAST_CONNECTION2_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_CONNECTION2_TABLE_DTS;

#define RDD_FC_MCAST_CONNECTION2_TABLE_PTR()	( RDD_FC_MCAST_CONNECTION2_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + FC_MCAST_CONNECTION2_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_ETH_TX_QUEUES_POINTERS_TABLE_SIZE     72
typedef struct
{
	RDD_ETH_TX_QUEUE_POINTERS_ENTRY_DTS	entry[ RDD_ETH_TX_QUEUES_POINTERS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_QUEUES_POINTERS_TABLE_DTS;

#define RDD_ETH_TX_QUEUES_POINTERS_TABLE_PTR()	( RDD_ETH_TX_QUEUES_POINTERS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_QUEUES_POINTERS_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
typedef struct
{
	RDD_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS	entry[ RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_DTS;

#define RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_PTR()	( RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_ETH_TX_QUEUES_TABLE_SIZE     72
typedef struct
{
	RDD_ETH_TX_QUEUE_DESCRIPTOR_DTS	entry[ RDD_ETH_TX_QUEUES_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_QUEUES_TABLE_DTS;

#define RDD_ETH_TX_QUEUES_TABLE_PTR()	( RDD_ETH_TX_QUEUES_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_QUEUES_TABLE_ADDRESS )

#endif
#define RDD_DS_CPU_RX_METER_TABLE_PTR()	( RDD_DS_CPU_RX_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_RX_METER_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_DS_FORWARDING_MATRIX_TABLE_SIZE     9
#define RDD_DS_FORWARDING_MATRIX_TABLE_SIZE2    16
typedef struct
{
	RDD_FORWARDING_MATRIX_ENTRY_DTS	entry[ RDD_DS_FORWARDING_MATRIX_TABLE_SIZE ][ RDD_DS_FORWARDING_MATRIX_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FORWARDING_MATRIX_TABLE_DTS;

#define RDD_DS_FORWARDING_MATRIX_TABLE_PTR()	( RDD_DS_FORWARDING_MATRIX_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FORWARDING_MATRIX_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
typedef struct
{
	RDD_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS	entry[ RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_DTS;

#define RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_PTR()	( RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_SIZE     32
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_ETH_TX_MAC_TABLE_SIZE     10
typedef struct
{
	RDD_ETH_TX_MAC_DESCRIPTOR_DTS	entry[ RDD_ETH_TX_MAC_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_MAC_TABLE_DTS;

#define RDD_ETH_TX_MAC_TABLE_PTR()	( RDD_ETH_TX_MAC_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_MAC_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_REVERSE_FFI_TABLE_SIZE     256
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_REVERSE_FFI_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_REVERSE_FFI_TABLE_DTS;

#define RDD_REVERSE_FFI_TABLE_PTR()	( RDD_REVERSE_FFI_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + REVERSE_FFI_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS;

#define RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_PTR()	( RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS;

#define RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_PTR()	( RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_TX_COMPLETE_DESCRIPTOR_DTS	entry[ RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_DTS;

#define RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_PTR()	( RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DHD_TX_COMPLETE_FLOW_RING_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_RUNNER_FWTRACE_MAINA_PARAM_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINA_PARAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINA_PARAM_DTS;

#define RDD_RUNNER_FWTRACE_MAINA_PARAM_PTR()	( RDD_RUNNER_FWTRACE_MAINA_PARAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + RUNNER_FWTRACE_MAINA_PARAM_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_RATE_LIMITER_TABLE_SIZE     32
typedef struct
{
	RDD_RATE_LIMITER_ENTRY_DTS	entry[ RDD_DS_RATE_LIMITER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_RATE_LIMITER_TABLE_DTS;

#define RDD_DS_RATE_LIMITER_TABLE_PTR()	( RDD_DS_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_RATE_LIMITER_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_SIZE     128
typedef struct
{
	RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_DTS	entry[ RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_DTS;

#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_PTR()	( RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_WAN_FLOW_TABLE_SIZE     256
typedef struct
{
	RDD_DS_WAN_FLOW_ENTRY_DTS	entry[ RDD_DS_WAN_FLOW_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_WAN_FLOW_TABLE_DTS;

#define RDD_DS_WAN_FLOW_TABLE_PTR()	( RDD_DS_WAN_FLOW_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_WAN_FLOW_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_ETH0_RX_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_ETH_RX_DESCRIPTORS_DTS	entry[ RDD_ETH0_RX_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH0_RX_DESCRIPTORS_DTS;

#define RDD_ETH0_RX_DESCRIPTORS_PTR()	( RDD_ETH0_RX_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH0_RX_DESCRIPTORS_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_INGRESS_HANDLER_SKB_DATA_POINTER_SIZE     32
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_INGRESS_HANDLER_SKB_DATA_POINTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_HANDLER_SKB_DATA_POINTER_DTS;

#define RDD_INGRESS_HANDLER_SKB_DATA_POINTER_PTR()	( RDD_INGRESS_HANDLER_SKB_DATA_POINTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + INGRESS_HANDLER_SKB_DATA_POINTER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_WAN_UDP_FILTER_TABLE_SIZE     32
typedef struct
{
	RDD_DS_WAN_UDP_FILTER_ENTRY_DTS	entry[ RDD_DS_WAN_UDP_FILTER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_WAN_UDP_FILTER_TABLE_DTS;

#define RDD_DS_WAN_UDP_FILTER_TABLE_PTR()	( RDD_DS_WAN_UDP_FILTER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_WAN_UDP_FILTER_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE     8
#define RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE2    64
typedef struct
{
	RDD_FC_MCAST_PORT_HEADER_ENTRY_DTS	entry[ RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE ][ RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_PORT_HEADER_BUFFER_DTS;

#define RDD_FC_MCAST_PORT_HEADER_BUFFER_PTR()	( RDD_FC_MCAST_PORT_HEADER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + FC_MCAST_PORT_HEADER_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

typedef struct
{
	uint32_t	reserved0    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1    	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	buffer_number	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_BPM_DTS;

#define RDD_CPU_TX_DESCRIPTOR_BPM_BUFFER_NUMBER_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_CPU_TX_DESCRIPTOR_BPM_BUFFER_NUMBER_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#define RDD_CPU_TX_DESCRIPTOR_BPM_BUFFER_NUMBER_L_READ( wv )               FIELD_GET( wv, 0, 14 )
#define RDD_CPU_TX_DESCRIPTOR_BPM_BUFFER_NUMBER_L_WRITE( v, wv )           FIELD_SET( v, 0, 14, wv )
#endif
#if defined DSL_63148

#define RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_SIZE     8
typedef struct
{
	RDD_CONNECTION_CONTEXT_MULTICAST_BUFFER_ENTRY_DTS	entry[ RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_DTS;

#define RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_PTR()	( RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

typedef struct
{
	uint32_t	last_sbn        	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fstat_cell      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_id         	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length   	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fstat_error     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error_type      	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ih_buffer_number	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_memory   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	buffer_number   	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_RX_DESCRIPTOR_DTS;

#define RDD_BBH_RX_DESCRIPTOR_LAST_SBN_READ(r, p)                         FIELD_MREAD_16((uint8_t *)p, 6, 10, r)
#define RDD_BBH_RX_DESCRIPTOR_LAST_SBN_WRITE(v, p)                        FIELD_MWRITE_16((uint8_t *)p, 6, 10, v)
#define RDD_BBH_RX_DESCRIPTOR_FSTAT_CELL_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 1, 5, 1, r)
#define RDD_BBH_RX_DESCRIPTOR_FSTAT_CELL_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 1, 5, 1, v)
#define RDD_BBH_RX_DESCRIPTOR_FLOW_ID_READ(r, p)                          FIELD_MREAD_32((uint8_t *)p + 0, 14, 7, r)
#define RDD_BBH_RX_DESCRIPTOR_FLOW_ID_WRITE(v, p)                         FIELD_MWRITE_32((uint8_t *)p + 0, 14, 7, v)
#define RDD_BBH_RX_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                    FIELD_MREAD_16((uint8_t *)p + 2, 0, 14, r)
#define RDD_BBH_RX_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                   FIELD_MWRITE_16((uint8_t *)p + 2, 0, 14, v)
#define RDD_BBH_RX_DESCRIPTOR_ERROR_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_BBH_RX_DESCRIPTOR_ERROR_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_BBH_RX_DESCRIPTOR_FSTAT_ERROR_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 4, 5, 1, r)
#define RDD_BBH_RX_DESCRIPTOR_FSTAT_ERROR_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 4, 5, 1, v)
#define RDD_BBH_RX_DESCRIPTOR_ERROR_TYPE_READ(r, p)                       FIELD_MREAD_16((uint8_t *)p + 4, 6, 7, r)
#define RDD_BBH_RX_DESCRIPTOR_ERROR_TYPE_WRITE(v, p)                      FIELD_MWRITE_16((uint8_t *)p + 4, 6, 7, v)
#define RDD_BBH_RX_DESCRIPTOR_IH_BUFFER_NUMBER_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 5, 0, 6, r)
#define RDD_BBH_RX_DESCRIPTOR_IH_BUFFER_NUMBER_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 5, 0, 6, v)
#define RDD_BBH_RX_DESCRIPTOR_TARGET_MEMORY_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 6, 7, 1, r)
#define RDD_BBH_RX_DESCRIPTOR_TARGET_MEMORY_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 6, 7, 1, v)
#define RDD_BBH_RX_DESCRIPTOR_BUFFER_NUMBER_READ(r, p)                    FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_BBH_RX_DESCRIPTOR_BUFFER_NUMBER_WRITE(v, p)                   FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#endif
#if defined DSL_63148

#define RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_SIZE     64
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_DTS;

#define RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_PTR()	( RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_LAN_ENQUEUE_SQ_PD_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_CPU_TX_BBH_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY_DTS	entry[ RDD_DS_CPU_TX_BBH_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_TX_BBH_DESCRIPTORS_DTS;

#define RDD_DS_CPU_TX_BBH_DESCRIPTORS_PTR()	( RDD_DS_CPU_TX_BBH_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_TX_BBH_DESCRIPTORS_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_SIZE     16
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_QUEUE_PROFILE_TABLE_SIZE     8
typedef struct
{
	RDD_QUEUE_PROFILE_DTS	entry[ RDD_DS_QUEUE_PROFILE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_QUEUE_PROFILE_TABLE_DTS;

#define RDD_DS_QUEUE_PROFILE_TABLE_PTR()	( RDD_DS_QUEUE_PROFILE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_QUEUE_PROFILE_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DHD_TX_POST_PD_INGRESS_QUEUE_SIZE     32
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DHD_TX_POST_PD_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_PD_INGRESS_QUEUE_DTS;

#define RDD_DHD_TX_POST_PD_INGRESS_QUEUE_PTR()	( RDD_DHD_TX_POST_PD_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DHD_TX_POST_PD_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_DTS;

#define RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR()	( RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_DTS;

#define RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_PTR()	( RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_RX_SQ_PD_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_DTS;

#define RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_PTR()	( RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_DTS;

#define RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_PTR()	( RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_SIZE     10
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_DTS;

#define RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_PTR()	( RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_ABSOLUTE_TX_BBH_COUNTER_ADDRESS )

#endif
#if defined DSL_63148

typedef struct
{
	uint32_t	head_pointer             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tail_pointer             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	guaranteed_free_count    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	non_guaranteed_free_count	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	guaranteed_threshold     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_DTS;

#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_HEAD_POINTER_READ(r, p)                              MREAD_16((uint8_t *)p, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_HEAD_POINTER_WRITE(v, p)                             MWRITE_16((uint8_t *)p, v)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_TAIL_POINTER_READ(r, p)                              MREAD_16((uint8_t *)p + 2, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_TAIL_POINTER_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 2, v)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_FREE_COUNT_READ(r, p)                     MREAD_16((uint8_t *)p + 4, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_FREE_COUNT_WRITE(v, p)                    MWRITE_16((uint8_t *)p + 4, v)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_NON_GUARANTEED_FREE_COUNT_READ(r, p)                 MREAD_16((uint8_t *)p + 6, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_NON_GUARANTEED_FREE_COUNT_WRITE(v, p)                MWRITE_16((uint8_t *)p + 6, v)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_THRESHOLD_READ(r, p)                      MREAD_16((uint8_t *)p + 8, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_THRESHOLD_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 8, v)
#endif
#if defined DSL_63148

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_SIZE     5
typedef struct
{
	RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_ENTRY_DTS	entry[ RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_DTS;

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_PTR()	( RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_SKB_ENQUEUED_INDEXES_FIFO_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_COMPLETE_RING_DESCRIPTOR_DTS	entry[ RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_DTS;

#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_PTR()	( RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_RUNNER_FWTRACE_PICOA_PARAM_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_PICOA_PARAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_PICOA_PARAM_DTS;

#define RDD_RUNNER_FWTRACE_PICOA_PARAM_PTR()	( RDD_RUNNER_FWTRACE_PICOA_PARAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + RUNNER_FWTRACE_PICOA_PARAM_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_GPON_RX_DIRECT_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_GPON_RX_DIRECT_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_RX_DIRECT_DESCRIPTORS_DTS;

#define RDD_GPON_RX_DIRECT_DESCRIPTORS_PTR()	( RDD_GPON_RX_DIRECT_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GPON_RX_DIRECT_DESCRIPTORS_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_CPU_RX_PD_INGRESS_QUEUE_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_CPU_RX_PD_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_PD_INGRESS_QUEUE_DTS;

#define RDD_CPU_RX_PD_INGRESS_QUEUE_PTR()	( RDD_CPU_RX_PD_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_RX_PD_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_SQ_ENQUEUE_QUEUE_SIZE     64
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_DS_SQ_ENQUEUE_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_SQ_ENQUEUE_QUEUE_DTS;

#define RDD_DS_SQ_ENQUEUE_QUEUE_PTR()	( RDD_DS_SQ_ENQUEUE_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_SQ_ENQUEUE_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_DTS;

#define RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_PTR()	( RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_RX_FAST_PD_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_DTS;

#define RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_PTR()	( RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_RX_PICO_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_NULL_BUFFER_SIZE     3
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DS_NULL_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_NULL_BUFFER_DTS;

#define RDD_DS_NULL_BUFFER_PTR()	( RDD_DS_NULL_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_NULL_BUFFER_ADDRESS )

#endif
#define RDD_DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR()	( RDD_DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_SIZE     8
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_DTS;

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_PTR()	( RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DHD_COMPLETE_RING_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_COMPLETE_RING_ENTRY_DTS	entry[ RDD_DHD_COMPLETE_RING_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_COMPLETE_RING_BUFFER_DTS;

#define RDD_DHD_COMPLETE_RING_BUFFER_PTR()	( RDD_DHD_COMPLETE_RING_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DHD_COMPLETE_RING_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_SIZE     4
typedef struct
{
	RDD_PARALLEL_PROCESSING_ENTRY_DTS	entry[ RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_DTS;

#define RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR()	( RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_GPON_RX_NORMAL_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_GPON_RX_NORMAL_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_RX_NORMAL_DESCRIPTORS_DTS;

#define RDD_GPON_RX_NORMAL_DESCRIPTORS_PTR()	( RDD_GPON_RX_NORMAL_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GPON_RX_NORMAL_DESCRIPTORS_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_DTS;

#define RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_PTR()	( RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_MULTICAST_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_SIZE     32
typedef struct
{
	RDD_GPE_COMMAND_PRIMITIVE_ENTRY_DTS	entry[ RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_DTS;

#define RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_PTR()	( RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_GPE_COMMAND_PRIMITIVE_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_ROUTER_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DS_ROUTER_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_ROUTER_INGRESS_QUEUE_DTS;

#define RDD_DS_ROUTER_INGRESS_QUEUE_PTR()	( RDD_DS_ROUTER_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_ROUTER_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_SIZE     8
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_DTS;

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_PTR()	( RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_DTS;

#define RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_PTR()	( RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_RX_FAST_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_DEBUG_BUFFER_SIZE     32
typedef struct
{
	RDD_DEBUG_BUFFER_ENTRY_DTS	entry[ RDD_DS_DEBUG_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DEBUG_BUFFER_DTS;

#define RDD_DS_DEBUG_BUFFER_PTR()	( RDD_DS_DEBUG_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_DEBUG_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_FW_MAC_ADDRS_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DS_FW_MAC_ADDRS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FW_MAC_ADDRS_DTS;

#define RDD_DS_FW_MAC_ADDRS_PTR()	( RDD_DS_FW_MAC_ADDRS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FW_MAC_ADDRS_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_SIZE     4
typedef struct
{
	RDD_PARALLEL_PROCESSING_TASK_REORDER_ENTRY_DTS	entry[ RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_DTS;

#define RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_PTR()	( RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_DATA_POINTER_DUMMY_TARGET_SIZE     5
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DS_DATA_POINTER_DUMMY_TARGET_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DATA_POINTER_DUMMY_TARGET_DTS;

#define RDD_DS_DATA_POINTER_DUMMY_TARGET_PTR()	( RDD_DS_DATA_POINTER_DUMMY_TARGET_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_DATA_POINTER_DUMMY_TARGET_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_SIZE     8
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_DTS;

#define RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_PTR()	( RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_DHD_TX_POST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DS_DHD_TX_POST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DHD_TX_POST_INGRESS_QUEUE_DTS;

#define RDD_DS_DHD_TX_POST_INGRESS_QUEUE_PTR()	( RDD_DS_DHD_TX_POST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_DHD_TX_POST_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_DHD_FLOW_RING_DROP_COUNTER_SIZE     5
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DS_DHD_FLOW_RING_DROP_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DHD_FLOW_RING_DROP_COUNTER_DTS;

#define RDD_DS_DHD_FLOW_RING_DROP_COUNTER_PTR()	( RDD_DS_DHD_FLOW_RING_DROP_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_DHD_FLOW_RING_DROP_COUNTER_ADDRESS )

#endif
#define RDD_DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR()	( RDD_DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_WLAN_MCAST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_WLAN_MCAST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_INGRESS_QUEUE_DTS;

#define RDD_WLAN_MCAST_INGRESS_QUEUE_PTR()	( RDD_WLAN_MCAST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + WLAN_MCAST_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_SIZE     8
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_DTS;

#define RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_PTR()	( RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_SIZE     16
typedef struct
{
	RDD_BROADCOM_SWITCH_PORT_MAPPING_DTS	entry[ RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_DTS;

#define RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_PTR()	( RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_IPSEC_DS_SA_DESC_CAM_TABLE_SIZE     16
typedef struct
{
	RDD_IPSEC_SA_DESC_CAM_DTS	entry[ RDD_IPSEC_DS_SA_DESC_CAM_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_SA_DESC_CAM_TABLE_DTS;

#define RDD_IPSEC_DS_SA_DESC_CAM_TABLE_PTR()	( RDD_IPSEC_DS_SA_DESC_CAM_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_DS_SA_DESC_CAM_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_IPSEC_US_SA_DESC_CAM_TABLE_SIZE     16
typedef struct
{
	RDD_IPSEC_SA_DESC_CAM_DTS	entry[ RDD_IPSEC_US_SA_DESC_CAM_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_US_SA_DESC_CAM_TABLE_DTS;

#define RDD_IPSEC_US_SA_DESC_CAM_TABLE_PTR()	( RDD_IPSEC_US_SA_DESC_CAM_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_US_SA_DESC_CAM_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_ETH_TX_SCRATCH_SIZE     16
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_ETH_TX_SCRATCH_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_SCRATCH_DTS;

#define RDD_ETH_TX_SCRATCH_PTR()	( RDD_ETH_TX_SCRATCH_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_SCRATCH_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_GSO_TX_DHD_L2_BUFFER_SIZE     22
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_GSO_TX_DHD_L2_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_TX_DHD_L2_BUFFER_DTS;

#define RDD_GSO_TX_DHD_L2_BUFFER_PTR()	( RDD_GSO_TX_DHD_L2_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GSO_TX_DHD_L2_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_CPU_TX_DHD_L2_BUFFER_SIZE     22
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_CPU_TX_DHD_L2_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DHD_L2_BUFFER_DTS;

#define RDD_CPU_TX_DHD_L2_BUFFER_PTR()	( RDD_CPU_TX_DHD_L2_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_TX_DHD_L2_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_SIZE     5
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_DTS;

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_PTR()	( RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_ADDRESS )

#endif
#if defined DSL_63148

typedef struct
{
	uint8_t	status_vector	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_EMACS_STATUS_ENTRY_DTS;

#define RDD_ETH_TX_EMACS_STATUS_ENTRY_STATUS_VECTOR_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_ETH_TX_EMACS_STATUS_ENTRY_STATUS_VECTOR_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#endif
#if defined DSL_63148

#define RDD_HASH_BASED_FORWARDING_PORT_TABLE_SIZE     4
typedef struct
{
	RDD_HASH_BASED_FORWARDING_PORT_ENTRY_DTS	entry[ RDD_HASH_BASED_FORWARDING_PORT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_HASH_BASED_FORWARDING_PORT_TABLE_DTS;

#define RDD_HASH_BASED_FORWARDING_PORT_TABLE_PTR()	( RDD_HASH_BASED_FORWARDING_PORT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + HASH_BASED_FORWARDING_PORT_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_GSO_TX_DHD_HOST_BUF_PTR_SIZE     4
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_GSO_TX_DHD_HOST_BUF_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_TX_DHD_HOST_BUF_PTR_DTS;

#define RDD_GSO_TX_DHD_HOST_BUF_PTR_PTR()	( RDD_GSO_TX_DHD_HOST_BUF_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GSO_TX_DHD_HOST_BUF_PTR_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_CPU_TX_DHD_HOST_BUF_PTR_SIZE     4
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_CPU_TX_DHD_HOST_BUF_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DHD_HOST_BUF_PTR_DTS;

#define RDD_CPU_TX_DHD_HOST_BUF_PTR_PTR()	( RDD_CPU_TX_DHD_HOST_BUF_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_TX_DHD_HOST_BUF_PTR_ADDRESS )

#endif
#if defined DSL_63148

typedef struct
{
	uint8_t	emac_offset	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_INTER_LAN_SCHEDULING_OFFSET_ENTRY_DTS;

#define RDD_ETH_TX_INTER_LAN_SCHEDULING_OFFSET_ENTRY_EMAC_OFFSET_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_ETH_TX_INTER_LAN_SCHEDULING_OFFSET_ENTRY_EMAC_OFFSET_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#endif
/* PRIVATE_B */
#if defined DSL_63148

#define RDD_US_INGRESS_HANDLER_BUFFER_SIZE     32
typedef struct
{
	RDD_IH_BUFFER_DTS	entry[ RDD_US_INGRESS_HANDLER_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_HANDLER_BUFFER_DTS;

#define RDD_US_INGRESS_HANDLER_BUFFER_PTR()	( RDD_US_INGRESS_HANDLER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_HANDLER_BUFFER_ADDRESS )

#endif
#define RDD_US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE_PTR()	( RDD_US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_US_CPU_REASON_TO_METER_TABLE_SIZE     64
typedef struct
{
	RDD_CPU_REASON_TO_METER_ENTRY_DTS	entry[ RDD_US_CPU_REASON_TO_METER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_REASON_TO_METER_TABLE_DTS;

#define RDD_US_CPU_REASON_TO_METER_TABLE_PTR()	( RDD_US_CPU_REASON_TO_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_REASON_TO_METER_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_MAIN_PROFILING_BUFFER_RUNNER_SIZE     32
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_US_MAIN_PROFILING_BUFFER_RUNNER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_MAIN_PROFILING_BUFFER_RUNNER_DTS;

#define RDD_US_MAIN_PROFILING_BUFFER_RUNNER_PTR()	( RDD_US_MAIN_PROFILING_BUFFER_RUNNER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_MAIN_PROFILING_BUFFER_RUNNER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_RUNNER_FLOW_HEADER_BUFFER_SIZE     3
typedef struct
{
	RDD_RUNNER_FLOW_HEADER_BUFFER_DTS	entry[ RDD_US_RUNNER_FLOW_HEADER_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RUNNER_FLOW_HEADER_BUFFER_DTS;

#define RDD_US_RUNNER_FLOW_HEADER_BUFFER_PTR()	( RDD_US_RUNNER_FLOW_HEADER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RUNNER_FLOW_HEADER_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_QUEUE_PROFILE_TABLE_SIZE     8
typedef struct
{
	RDD_QUEUE_PROFILE_DTS	entry[ RDD_US_QUEUE_PROFILE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_QUEUE_PROFILE_TABLE_DTS;

#define RDD_US_QUEUE_PROFILE_TABLE_PTR()	( RDD_US_QUEUE_PROFILE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_QUEUE_PROFILE_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_WAN_CHANNELS_8_39_TABLE_SIZE     32
typedef struct
{
	RDD_WAN_CHANNEL_8_39_DESCRIPTOR_DTS	entry[ RDD_WAN_CHANNELS_8_39_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_CHANNELS_8_39_TABLE_DTS;

#define RDD_WAN_CHANNELS_8_39_TABLE_PTR()	( RDD_WAN_CHANNELS_8_39_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + WAN_CHANNELS_8_39_TABLE_ADDRESS )

#endif
#define RDD_US_POLICER_TABLE_PTR()	( RDD_US_POLICER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_POLICER_TABLE_ADDRESS )

#define RDD_US_CPU_RX_METER_TABLE_PTR()	( RDD_US_CPU_RX_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_RX_METER_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_US_CPU_TX_BBH_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY_DTS	entry[ RDD_US_CPU_TX_BBH_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_TX_BBH_DESCRIPTORS_DTS;

#define RDD_US_CPU_TX_BBH_DESCRIPTORS_PTR()	( RDD_US_CPU_TX_BBH_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_TX_BBH_DESCRIPTORS_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_FORWARDING_MATRIX_TABLE_SIZE     9
#define RDD_US_FORWARDING_MATRIX_TABLE_SIZE2    16
typedef struct
{
	RDD_FORWARDING_MATRIX_ENTRY_DTS	entry[ RDD_US_FORWARDING_MATRIX_TABLE_SIZE ][ RDD_US_FORWARDING_MATRIX_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FORWARDING_MATRIX_TABLE_DTS;

#define RDD_US_FORWARDING_MATRIX_TABLE_PTR()	( RDD_US_FORWARDING_MATRIX_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FORWARDING_MATRIX_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_SIZE     8
typedef struct
{
	RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY_DTS	entry[ RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_DTS;

#define RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_PTR()	( RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_TIMER_SCHEDULER_PRIMITIVE_TABLE_ADDRESS )

#endif
#define RDD_US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_PTR()	( RDD_US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_US_WAN_FLOW_TABLE_SIZE     256
typedef struct
{
	RDD_US_WAN_FLOW_ENTRY_DTS	entry[ RDD_US_WAN_FLOW_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_WAN_FLOW_TABLE_DTS;

#define RDD_US_WAN_FLOW_TABLE_PTR()	( RDD_US_WAN_FLOW_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_WAN_FLOW_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_SIZE     32
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_DTS;

#define RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_PTR()	( RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_HANDLER_SKB_DATA_POINTER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_SIZE     16
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_SIZE     8
#define RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_SIZE2    8
typedef struct
{
	RDD_US_QUEUE_ENTRY_DTS	entry[ RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_SIZE ][ RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_DTS;

#define RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_PTR()	( RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_TRAFFIC_CLASS_TO_QUEUE_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS;

#define RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_PTR()	( RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS;

#define RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_PTR()	( RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_SIZE     32
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_RATE_LIMITER_TABLE_SIZE     16
typedef struct
{
	RDD_RATE_LIMITER_ENTRY_DTS	entry[ RDD_US_RATE_LIMITER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RATE_LIMITER_TABLE_DTS;

#define RDD_US_RATE_LIMITER_TABLE_PTR()	( RDD_US_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RATE_LIMITER_TABLE_ADDRESS )

#endif
#define RDD_US_PICO_TIMER_TASK_DESCRIPTOR_TABLE_PTR()	( RDD_US_PICO_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_US_CONNECTION_CONTEXT_BUFFER_SIZE     8
typedef struct
{
	RDD_CONNECTION_CONTEXT_BUFFER_ENTRY_DTS	entry[ RDD_US_CONNECTION_CONTEXT_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CONNECTION_CONTEXT_BUFFER_DTS;

#define RDD_US_CONNECTION_CONTEXT_BUFFER_PTR()	( RDD_US_CONNECTION_CONTEXT_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CONNECTION_CONTEXT_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_SIZE     256
typedef struct
{
	RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_WAN_CHANNELS_0_7_TABLE_SIZE     8
typedef struct
{
	RDD_WAN_CHANNEL_0_7_DESCRIPTOR_DTS	entry[ RDD_WAN_CHANNELS_0_7_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_CHANNELS_0_7_TABLE_DTS;

#define RDD_WAN_CHANNELS_0_7_TABLE_PTR()	( RDD_WAN_CHANNELS_0_7_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + WAN_CHANNELS_0_7_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
typedef struct
{
	RDD_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS	entry[ RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_DTS;

#define RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_PTR()	( RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
typedef struct
{
	RDD_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS	entry[ RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_DTS;

#define RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_PTR()	( RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_INGRESS_RATE_LIMITER_TABLE_SIZE     5
typedef struct
{
	RDD_INGRESS_RATE_LIMITER_ENTRY_DTS	entry[ RDD_US_INGRESS_RATE_LIMITER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_RATE_LIMITER_TABLE_DTS;

#define RDD_US_INGRESS_RATE_LIMITER_TABLE_PTR()	( RDD_US_INGRESS_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_RATE_LIMITER_TABLE_ADDRESS )

#endif
#if defined DSL_63148

typedef struct
{
	uint16_t	port_sel  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	reserved0 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	pkt_eop   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	frag_size 	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DSL_PTM_BOND_TX_HDR_ENTRY_DTS;

#define RDD_DSL_PTM_BOND_TX_HDR_ENTRY_PORT_SEL_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_DSL_PTM_BOND_TX_HDR_ENTRY_PORT_SEL_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_DSL_PTM_BOND_TX_HDR_ENTRY_PKT_EOP_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p, 4, 1, r)
#define RDD_DSL_PTM_BOND_TX_HDR_ENTRY_PKT_EOP_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p, 4, 1, v)
#define RDD_DSL_PTM_BOND_TX_HDR_ENTRY_FRAG_SIZE_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 0, 12, r)
#define RDD_DSL_PTM_BOND_TX_HDR_ENTRY_FRAG_SIZE_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 0, 12, v)
#endif
#if defined DSL_63148

#define RDD_DSL_PTM_BOND_TX_HDR_TABLE_SIZE     8
typedef struct
{
	RDD_DSL_PTM_BOND_TX_HDR_ENTRY_DTS	entry[ RDD_DSL_PTM_BOND_TX_HDR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DSL_PTM_BOND_TX_HDR_TABLE_DTS;

#define RDD_DSL_PTM_BOND_TX_HDR_TABLE_PTR()	( RDD_DSL_PTM_BOND_TX_HDR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DSL_PTM_BOND_TX_HDR_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_SIZE     3
typedef struct
{
	RDD_RUNNER_FLOW_HEADER_DESCRIPTOR_DTS	entry[ RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_DTS;

#define RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_PTR()	( RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RUNNER_FLOW_HEADER_DESCRIPTOR_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_CPU_RX_PICO_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_US_CPU_RX_PICO_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_RX_PICO_INGRESS_QUEUE_DTS;

#define RDD_US_CPU_RX_PICO_INGRESS_QUEUE_PTR()	( RDD_US_CPU_RX_PICO_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_RX_PICO_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_ROUTER_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_US_ROUTER_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_ROUTER_INGRESS_QUEUE_DTS;

#define RDD_US_ROUTER_INGRESS_QUEUE_PTR()	( RDD_US_ROUTER_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_ROUTER_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_SIZE     32
typedef struct
{
	RDD_GPE_COMMAND_PRIMITIVE_ENTRY_DTS	entry[ RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_DTS;

#define RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_PTR()	( RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_GPE_COMMAND_PRIMITIVE_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_CPU_RX_FAST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_US_CPU_RX_FAST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_RX_FAST_INGRESS_QUEUE_DTS;

#define RDD_US_CPU_RX_FAST_INGRESS_QUEUE_PTR()	( RDD_US_CPU_RX_FAST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_RX_FAST_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_DEBUG_BUFFER_SIZE     32
typedef struct
{
	RDD_DEBUG_BUFFER_ENTRY_DTS	entry[ RDD_US_DEBUG_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_DEBUG_BUFFER_DTS;

#define RDD_US_DEBUG_BUFFER_PTR()	( RDD_US_DEBUG_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_DEBUG_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_FW_MAC_ADDRS_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_US_FW_MAC_ADDRS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FW_MAC_ADDRS_DTS;

#define RDD_US_FW_MAC_ADDRS_PTR()	( RDD_US_FW_MAC_ADDRS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FW_MAC_ADDRS_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DSL_PTM_BOND_TX_HDR_DEBUG_TABLE_SIZE     8
typedef struct
{
	RDD_DSL_PTM_BOND_TX_HDR_ENTRY_DTS	entry[ RDD_DSL_PTM_BOND_TX_HDR_DEBUG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DSL_PTM_BOND_TX_HDR_DEBUG_TABLE_DTS;

#define RDD_DSL_PTM_BOND_TX_HDR_DEBUG_TABLE_PTR()	( RDD_DSL_PTM_BOND_TX_HDR_DEBUG_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DSL_PTM_BOND_TX_HDR_DEBUG_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_DHD_TX_POST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_US_DHD_TX_POST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_DHD_TX_POST_INGRESS_QUEUE_DTS;

#define RDD_US_DHD_TX_POST_INGRESS_QUEUE_PTR()	( RDD_US_DHD_TX_POST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_DHD_TX_POST_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_SIZE     48
typedef struct
{
	RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_ENTRY_DTS	entry[ RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_DTS;

#define RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_PTR()	( RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_ADDRESS )

#endif
#define RDD_US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR()	( RDD_US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_RUNNER_FWTRACE_MAINB_PARAM_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINB_PARAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINB_PARAM_DTS;

#define RDD_RUNNER_FWTRACE_MAINB_PARAM_PTR()	( RDD_RUNNER_FWTRACE_MAINB_PARAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + RUNNER_FWTRACE_MAINB_PARAM_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_SIZE     40
typedef struct
{
	RDD_GPON_ABSOLUTE_TX_COUNTER_DTS	entry[ RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_DTS;

#define RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_PTR()	( RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_DHD_FLOW_RING_DROP_COUNTER_SIZE     5
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_US_DHD_FLOW_RING_DROP_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_DHD_FLOW_RING_DROP_COUNTER_DTS;

#define RDD_US_DHD_FLOW_RING_DROP_COUNTER_PTR()	( RDD_US_DHD_FLOW_RING_DROP_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_DHD_FLOW_RING_DROP_COUNTER_ADDRESS )

#endif
#define RDD_US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR()	( RDD_US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_RUNNER_FWTRACE_PICOB_PARAM_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_PICOB_PARAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_PICOB_PARAM_DTS;

#define RDD_RUNNER_FWTRACE_PICOB_PARAM_PTR()	( RDD_RUNNER_FWTRACE_PICOB_PARAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + RUNNER_FWTRACE_PICOB_PARAM_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_SIZE     32
typedef struct
{
	RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_ENTRY_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_ADDRESS )

#endif
#if defined DSL_63148

typedef struct
{
	uint32_t	guaranteed_free_count    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	non_guaranteed_free_count	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	guaranteed_threshold     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_DTS;

#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_FREE_COUNT_READ(r, p)                     MREAD_16((uint8_t *)p, r)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_FREE_COUNT_WRITE(v, p)                    MWRITE_16((uint8_t *)p, v)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_NON_GUARANTEED_FREE_COUNT_READ(r, p)                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_NON_GUARANTEED_FREE_COUNT_WRITE(v, p)                MWRITE_16((uint8_t *)p + 2, v)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_THRESHOLD_READ(r, p)                      MREAD_16((uint8_t *)p + 4, r)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_THRESHOLD_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 4, v)
#endif
#if defined DSL_63148

#define RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_SIZE     8
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_DTS;

#define RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_PTR()	( RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_SIZE     16
typedef struct
{
	RDD_BROADCOM_SWITCH_PORT_MAPPING_DTS	entry[ RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_DTS;

#define RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_PTR()	( RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_SIZE     3
#define RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_SIZE2    6
typedef struct
{
	RDD_CPU_REASON_TO_METER_ENTRY_DTS	entry[ RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_SIZE ][ RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_DTS;

#define RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_PTR()	( RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_WAN_TX_SCRATCH_SIZE     16
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_WAN_TX_SCRATCH_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_TX_SCRATCH_DTS;

#define RDD_WAN_TX_SCRATCH_PTR()	( RDD_WAN_TX_SCRATCH_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + WAN_TX_SCRATCH_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DATA_POINTER_DUMMY_TARGET_SIZE     2
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DATA_POINTER_DUMMY_TARGET_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DATA_POINTER_DUMMY_TARGET_DTS;

#define RDD_DATA_POINTER_DUMMY_TARGET_PTR()	( RDD_DATA_POINTER_DUMMY_TARGET_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DATA_POINTER_DUMMY_TARGET_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_SIZE     14
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_DTS;

#define RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_PTR()	( RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + CPU_TX_DHD_LAYER2_HEADER_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_SIZE     4
typedef struct
{
	RDD_PARALLEL_PROCESSING_ENTRY_DTS	entry[ RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_DTS;

#define RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR()	( RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_SIZE     4
typedef struct
{
	RDD_PARALLEL_PROCESSING_TASK_REORDER_ENTRY_DTS	entry[ RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_DTS;

#define RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_PTR()	( RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_SIZE     8
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_DTS;

#define RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_PTR()	( RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_SIZE     8
typedef struct
{
	RDD_BROADCOM_SWITCH_PORT_MAPPING_DTS	entry[ RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_DTS;

#define RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_PTR()	( RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_ADDRESS )

#endif
#define RDD_US_RATE_CONTROLLER_EXPONENT_TABLE_PTR()	( RDD_US_RATE_CONTROLLER_EXPONENT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RATE_CONTROLLER_EXPONENT_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_SIZE     40
typedef struct
{
	RDD_GPON_ABSOLUTE_TX_COUNTER_DTS	entry[ RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_DTS;

#define RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_PTR()	( RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + GPON_ABSOLUTE_TX_BBH_COUNTER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_ETH1_RX_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_ETH_RX_DESCRIPTORS_DTS	entry[ RDD_ETH1_RX_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH1_RX_DESCRIPTORS_DTS;

#define RDD_ETH1_RX_DESCRIPTORS_PTR()	( RDD_ETH1_RX_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + ETH1_RX_DESCRIPTORS_ADDRESS )

#endif
/* COMMON_A */
#if defined DSL_63148

#define RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_SIZE     384
typedef struct
{
	RDD_SIXTEEN_BYTES_DTS	entry[ RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_DTS;

#define RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_PTR()	( RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + SERVICE_QUEUES_DDR_CACHE_FIFO_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_SIZE     8
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_DTS;

#define RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_PTR()	( RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + FC_MCAST_RUNNER_A_SCRATCHPAD_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_CPU_RX_RUNNER_A_SCRATCHPAD_SIZE     16
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_CPU_RX_RUNNER_A_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_RUNNER_A_SCRATCHPAD_DTS;

#define RDD_CPU_RX_RUNNER_A_SCRATCHPAD_PTR()	( RDD_CPU_RX_RUNNER_A_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + CPU_RX_RUNNER_A_SCRATCHPAD_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_SIZE     8
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_DTS;

#define RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_PTR()	( RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_RUNNER_A_SCRATCHPAD_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_RUNNER_FWTRACE_MAINA_BASE_SIZE     128
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINA_BASE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINA_BASE_DTS;

#define RDD_RUNNER_FWTRACE_MAINA_BASE_PTR()	( RDD_RUNNER_FWTRACE_MAINA_BASE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RUNNER_FWTRACE_MAINA_BASE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_WLAN_MCAST_DHD_STATION_TABLE_SIZE     64
typedef struct
{
	RDD_WLAN_MCAST_DHD_STATION_ENTRY_DTS	entry[ RDD_WLAN_MCAST_DHD_STATION_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_DHD_STATION_TABLE_DTS;

#define RDD_WLAN_MCAST_DHD_STATION_TABLE_PTR()	( RDD_WLAN_MCAST_DHD_STATION_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_DHD_STATION_TABLE_ADDRESS )

#endif
#define RDD_DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_PTR()	( RDD_DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_SIZE     3
typedef struct
{
	RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_DTS	entry[ RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_DTS;

#define RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_PTR()	( RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DHD_RADIO_INSTANCE_COMMON_A_DATA_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_SIZE     2
typedef struct
{
	RDD_FREE_SKB_INDEXES_FIFO_TAIL_DTS	entry[ RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_DTS;

#define RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_PTR()	( RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + FREE_SKB_INDEXES_DDR_FIFO_TAIL_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_SIZE     128
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_DTS;

#define RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_PTR()	( RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RATE_SHAPERS_STATUS_DESCRIPTOR_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_DTS;

#define RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_PTR()	( RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RUNNER_FWTRACE_MAINA_CURR_OFFSET_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_SIZE     32
typedef struct
{
	RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_ENTRY_DTS	entry[ RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_DTS;

#define RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_PTR()	( RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + GPON_SKB_ENQUEUED_INDEXES_FIFO_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_WLAN_MCAST_FWD_TABLE_SIZE     64
typedef struct
{
	RDD_WLAN_MCAST_FWD_ENTRY_DTS	entry[ RDD_WLAN_MCAST_FWD_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_FWD_TABLE_DTS;

#define RDD_WLAN_MCAST_FWD_TABLE_PTR()	( RDD_WLAN_MCAST_FWD_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_FWD_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_RUNNER_FWTRACE_PICOA_BASE_SIZE     128
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_PICOA_BASE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_PICOA_BASE_DTS;

#define RDD_RUNNER_FWTRACE_PICOA_BASE_PTR()	( RDD_RUNNER_FWTRACE_PICOA_BASE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RUNNER_FWTRACE_PICOA_BASE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_SIZE     32
typedef struct
{
	RDD_DDR_QUEUE_DESCRIPTOR_DTS	entry[ RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_DTS;

#define RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_PTR()	( RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + SERVICE_QUEUES_DESCRIPTOR_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_SIZE     48
typedef struct
{
	RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_DTS	entry[ RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_DTS;

#define RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_PTR()	( RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_INTERRUPT_COALESCING_CONFIG_TABLE_SIZE     16
typedef struct
{
	RDD_INTERRUPT_COALESCING_CONFIG_DTS	entry[ RDD_INTERRUPT_COALESCING_CONFIG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INTERRUPT_COALESCING_CONFIG_TABLE_DTS;

#define RDD_INTERRUPT_COALESCING_CONFIG_TABLE_PTR()	( RDD_INTERRUPT_COALESCING_CONFIG_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + INTERRUPT_COALESCING_CONFIG_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_SIZE2    64
typedef struct
{
	RDD_DSCP_TO_PBITS_DEI_ENTRY_DTS	entry[ RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_DTS;

#define RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_PTR()	( RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + GLOBAL_DSCP_TO_PBITS_DEI_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_WLAN_MCAST_SSID_STATS_TABLE_SIZE     48
typedef struct
{
	RDD_WLAN_MCAST_SSID_STATS_ENTRY_DTS	entry[ RDD_WLAN_MCAST_SSID_STATS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_SSID_STATS_TABLE_DTS;

#define RDD_WLAN_MCAST_SSID_STATS_TABLE_PTR()	( RDD_WLAN_MCAST_SSID_STATS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_SSID_STATS_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_TRACE_C_TABLE_SIZE     4
typedef struct
{
	RDD_TRACE_C_ENTRY_DTS	entry[ RDD_TRACE_C_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TRACE_C_TABLE_DTS;

#define RDD_TRACE_C_TABLE_PTR()	( RDD_TRACE_C_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + TRACE_C_TABLE_ADDRESS )

#endif
#define RDD_DS_RATE_CONTROLLER_EXPONENT_TABLE_PTR()	( RDD_DS_RATE_CONTROLLER_EXPONENT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_RATE_CONTROLLER_EXPONENT_TABLE_ADDRESS )

#if defined DSL_63148

#define RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_SIZE     16
typedef struct
{
	RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_DTS	entry[ RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_DTS;

#define RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_PTR()	( RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_DHD_FLOW_RING_CACHE_LKP_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_CONNECTION_BUFFER_TABLE_SIZE     5
#define RDD_DS_CONNECTION_BUFFER_TABLE_SIZE2    4
typedef struct
{
	RDD_CONNECTION_ENTRY_DTS	entry[ RDD_DS_CONNECTION_BUFFER_TABLE_SIZE ][ RDD_DS_CONNECTION_BUFFER_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CONNECTION_BUFFER_TABLE_DTS;

#define RDD_DS_CONNECTION_BUFFER_TABLE_PTR()	( RDD_DS_CONNECTION_BUFFER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_CONNECTION_BUFFER_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_L4_DST_PORT_TABLE_SIZE     256
typedef struct
{
	RDD_L4_DST_PORT_ENTRY_DTS	entry[ RDD_DS_L4_DST_PORT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_L4_DST_PORT_TABLE_DTS;

#define RDD_DS_L4_DST_PORT_TABLE_PTR()	( RDD_DS_L4_DST_PORT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_L4_DST_PORT_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_L4_DST_PORT_CONTEXT_TABLE_SIZE     256
typedef struct
{
	RDD_L4_DST_PORT_CONTEXT_DTS	entry[ RDD_L4_DST_PORT_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_L4_DST_PORT_CONTEXT_TABLE_DTS;

#define RDD_L4_DST_PORT_CONTEXT_TABLE_PTR()	( RDD_L4_DST_PORT_CONTEXT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + L4_DST_PORT_CONTEXT_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_SIZE     16
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_DTS;

#define RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_PTR()	( RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_SIZE     32
typedef struct
{
	RDD_DDR_QUEUE_ADDRESS_ENTRY_DTS	entry[ RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_DTS;

#define RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_PTR()	( RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_ADDRESS )

#endif
#if defined DSL_63148

typedef struct
{
	uint32_t	reserved0         	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_offset    	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length     	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1         	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error_type        	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_bridge_port	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_memory     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	buffer_number     	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETHWAN2_RX_DESCRIPTOR_DTS;

#define RDD_ETHWAN2_RX_DESCRIPTOR_PAYLOAD_OFFSET_READ(r, p)                     FIELD_MREAD_32((uint8_t *)p + 0, 14, 7, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_PAYLOAD_OFFSET_WRITE(v, p)                    FIELD_MWRITE_32((uint8_t *)p + 0, 14, 7, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 2, 0, 14, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 2, 0, 14, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_ERROR_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_ERROR_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_ERROR_TYPE_READ(r, p)                         FIELD_MREAD_16((uint8_t *)p + 4, 6, 7, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_ERROR_TYPE_WRITE(v, p)                        FIELD_MWRITE_16((uint8_t *)p + 4, 6, 7, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_SOURCE_BRIDGE_PORT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 5, 0, 6, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_SOURCE_BRIDGE_PORT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 5, 0, 6, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_TARGET_MEMORY_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 6, 7, 1, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_TARGET_MEMORY_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 6, 7, 1, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_BUFFER_NUMBER_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_BUFFER_NUMBER_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#endif
#if defined DSL_63148

#define RDD_ETHWAN2_RX_INGRESS_QUEUE_SIZE     32
typedef struct
{
	RDD_ETHWAN2_RX_DESCRIPTOR_DTS	entry[ RDD_ETHWAN2_RX_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETHWAN2_RX_INGRESS_QUEUE_DTS;

#define RDD_ETHWAN2_RX_INGRESS_QUEUE_PTR()	( RDD_ETHWAN2_RX_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + ETHWAN2_RX_INGRESS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_SIZE     14
typedef struct
{
	RDD_CPU_RX_DESCRIPTOR_DTS	entry[ RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_DTS;

#define RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_PTR()	( RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_RING_PACKET_DESCRIPTORS_CACHE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_RING_DESCRIPTORS_TABLE_SIZE     12
typedef struct
{
	RDD_RING_DESCRIPTOR_DTS	entry[ RDD_RING_DESCRIPTORS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RING_DESCRIPTORS_TABLE_DTS;

#define RDD_RING_DESCRIPTORS_TABLE_PTR()	( RDD_RING_DESCRIPTORS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RING_DESCRIPTORS_TABLE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_MAIN_A_DEBUG_TRACE_SIZE     512
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_MAIN_A_DEBUG_TRACE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_MAIN_A_DEBUG_TRACE_DTS;

#define RDD_MAIN_A_DEBUG_TRACE_PTR()	( RDD_MAIN_A_DEBUG_TRACE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + MAIN_A_DEBUG_TRACE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_PICO_A_DEBUG_TRACE_SIZE     512
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_PICO_A_DEBUG_TRACE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PICO_A_DEBUG_TRACE_DTS;

#define RDD_PICO_A_DEBUG_TRACE_PTR()	( RDD_PICO_A_DEBUG_TRACE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + PICO_A_DEBUG_TRACE_ADDRESS )

#endif
/* COMMON_B */
#if defined DSL_63148

#define RDD_WAN_TX_QUEUES_TABLE_SIZE     256
typedef struct
{
	RDD_WAN_TX_QUEUE_DESCRIPTOR_DTS	entry[ RDD_WAN_TX_QUEUES_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_TX_QUEUES_TABLE_DTS;

#define RDD_WAN_TX_QUEUES_TABLE_PTR()	( RDD_WAN_TX_QUEUES_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + WAN_TX_QUEUES_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_US_CONNECTION_BUFFER_TABLE_SIZE     5
#define RDD_US_CONNECTION_BUFFER_TABLE_SIZE2    4
typedef struct
{
	RDD_CONNECTION_ENTRY_DTS	entry[ RDD_US_CONNECTION_BUFFER_TABLE_SIZE ][ RDD_US_CONNECTION_BUFFER_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CONNECTION_BUFFER_TABLE_DTS;

#define RDD_US_CONNECTION_BUFFER_TABLE_PTR()	( RDD_US_CONNECTION_BUFFER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_CONNECTION_BUFFER_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_IPV6_HOST_ADDRESS_CRC_TABLE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_IPV6_HOST_ADDRESS_CRC_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPV6_HOST_ADDRESS_CRC_TABLE_DTS;

#define RDD_IPV6_HOST_ADDRESS_CRC_TABLE_PTR()	( RDD_IPV6_HOST_ADDRESS_CRC_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + IPV6_HOST_ADDRESS_CRC_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_SIZE     16
typedef struct
{
	RDD_DDR_QUEUE_ADDRESS_ENTRY_DTS	entry[ RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_DTS;

#define RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_PTR()	( RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + EPON_DDR_QUEUE_ADDRESS_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_SIZE     32
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_DTS;

#define RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR()	( RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_RUNNER_FWTRACE_MAINB_BASE_SIZE     128
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINB_BASE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINB_BASE_DTS;

#define RDD_RUNNER_FWTRACE_MAINB_BASE_PTR()	( RDD_RUNNER_FWTRACE_MAINB_BASE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + RUNNER_FWTRACE_MAINB_BASE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_RUNNER_FWTRACE_PICOB_BASE_SIZE     128
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_PICOB_BASE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_PICOB_BASE_DTS;

#define RDD_RUNNER_FWTRACE_PICOB_BASE_PTR()	( RDD_RUNNER_FWTRACE_PICOB_BASE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + RUNNER_FWTRACE_PICOB_BASE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_US_L4_DST_PORT_TABLE_SIZE     256
typedef struct
{
	RDD_L4_DST_PORT_ENTRY_DTS	entry[ RDD_US_L4_DST_PORT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_L4_DST_PORT_TABLE_DTS;

#define RDD_US_L4_DST_PORT_TABLE_PTR()	( RDD_US_L4_DST_PORT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_L4_DST_PORT_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_CPU_RX_RUNNER_B_SCRATCHPAD_SIZE     16
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_CPU_RX_RUNNER_B_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_RUNNER_B_SCRATCHPAD_DTS;

#define RDD_CPU_RX_RUNNER_B_SCRATCHPAD_PTR()	( RDD_CPU_RX_RUNNER_B_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + CPU_RX_RUNNER_B_SCRATCHPAD_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_EPON_DDR_CACHE_FIFO_SIZE     192
typedef struct
{
	RDD_BBH_TX_DESCRIPTOR_DTS	entry[ RDD_EPON_DDR_CACHE_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EPON_DDR_CACHE_FIFO_DTS;

#define RDD_EPON_DDR_CACHE_FIFO_PTR()	( RDD_EPON_DDR_CACHE_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + EPON_DDR_CACHE_FIFO_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_SIZE     16
typedef struct
{
	RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_DTS	entry[ RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_DTS;

#define RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_PTR()	( RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + DHD_FLOW_RING_CACHE_CTX_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_FC_FLOW_IP_ADDRESSES_TABLE_SIZE     4
typedef struct
{
	RDD_FC_FLOW_IP_ADDRESSES_ENTRY_DTS	entry[ RDD_FC_FLOW_IP_ADDRESSES_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_FLOW_IP_ADDRESSES_TABLE_DTS;

#define RDD_FC_FLOW_IP_ADDRESSES_TABLE_PTR()	( RDD_FC_FLOW_IP_ADDRESSES_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + FC_FLOW_IP_ADDRESSES_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_DTS;

#define RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_PTR()	( RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + RUNNER_FWTRACE_MAINB_CURR_OFFSET_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_US_RATE_CONTROLLERS_TABLE_SIZE     128
typedef struct
{
	RDD_US_RATE_CONTROLLER_DESCRIPTOR_DTS	entry[ RDD_US_RATE_CONTROLLERS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RATE_CONTROLLERS_TABLE_DTS;

#define RDD_US_RATE_CONTROLLERS_TABLE_PTR()	( RDD_US_RATE_CONTROLLERS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_RATE_CONTROLLERS_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_RUNNER_B_SCRATCHPAD_SIZE     8
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_RUNNER_B_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_B_SCRATCHPAD_DTS;

#define RDD_RUNNER_B_SCRATCHPAD_PTR()	( RDD_RUNNER_B_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + RUNNER_B_SCRATCHPAD_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_US_RING_PACKET_DESCRIPTORS_CACHE_SIZE     14
typedef struct
{
	RDD_CPU_RX_DESCRIPTOR_DTS	entry[ RDD_US_RING_PACKET_DESCRIPTORS_CACHE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RING_PACKET_DESCRIPTORS_CACHE_DTS;

#define RDD_US_RING_PACKET_DESCRIPTORS_CACHE_PTR()	( RDD_US_RING_PACKET_DESCRIPTORS_CACHE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_RING_PACKET_DESCRIPTORS_CACHE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_IPV4_HOST_ADDRESS_TABLE_SIZE     8
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_IPV4_HOST_ADDRESS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPV4_HOST_ADDRESS_TABLE_DTS;

#define RDD_IPV4_HOST_ADDRESS_TABLE_PTR()	( RDD_IPV4_HOST_ADDRESS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + IPV4_HOST_ADDRESS_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_SIZE     3
typedef struct
{
	RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_DTS	entry[ RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_DTS;

#define RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_PTR()	( RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + DHD_RADIO_INSTANCE_COMMON_B_DATA_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_MAIN_B_DEBUG_TRACE_SIZE     512
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_MAIN_B_DEBUG_TRACE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_MAIN_B_DEBUG_TRACE_DTS;

#define RDD_MAIN_B_DEBUG_TRACE_PTR()	( RDD_MAIN_B_DEBUG_TRACE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + MAIN_B_DEBUG_TRACE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_PICO_B_DEBUG_TRACE_SIZE     512
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_PICO_B_DEBUG_TRACE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PICO_B_DEBUG_TRACE_DTS;

#define RDD_PICO_B_DEBUG_TRACE_PTR()	( RDD_PICO_B_DEBUG_TRACE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + PICO_B_DEBUG_TRACE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_SIZE     16
typedef struct
{
	RDD_DDR_QUEUE_DESCRIPTOR_DTS	entry[ RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_DTS;

#define RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_PTR()	( RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + EPON_DDR_QUEUE_DESCRIPTORS_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_SIZE     40
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_DTS;

#define RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_PTR()	( RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_SIZE     8
typedef struct
{
	RDD_BROADCOM_SWITCH_PORT_MAPPING_DTS	entry[ RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_DTS;

#define RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR()	( RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_SIZE     4
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_DTS;

#define RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_PTR()	( RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_SIZE     40
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_DTS;

#define RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_PTR()	( RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_ADDRESS - 0x8000 )

#endif
#define RDD_US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_PTR()	( RDD_US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_ADDRESS - 0x8000 )

#if defined DSL_63148

#define RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_SIZE     16
typedef struct
{
	RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_DTS	entry[ RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_DTS;

#define RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_PTR()	( RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_DHD_FLOW_RING_CACHE_LKP_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_WAN_ENQUEUE_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_WAN_ENQUEUE_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_ENQUEUE_INGRESS_QUEUE_DTS;

#define RDD_WAN_ENQUEUE_INGRESS_QUEUE_PTR()	( RDD_WAN_ENQUEUE_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + WAN_ENQUEUE_INGRESS_QUEUE_ADDRESS - 0x8000 )

#endif
/* DDR */
#if defined DSL_63148

#define RDD_BPM_PACKET_BUFFERS_SIZE     7680
typedef struct
{
	RDD_BPM_PACKET_BUFFER_DTS	entry[ RDD_BPM_PACKET_BUFFERS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BPM_PACKET_BUFFERS_DTS;

#endif
#if defined DSL_63148

#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE_SIZE     8
typedef struct
{
	RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_DTS	entry[ RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE_DTS;

#endif
#if defined DSL_63148

#define RDD_DHD_RX_POST_DDR_BUFFER_SIZE     1024
typedef struct
{
	RDD_DHD_RX_POST_DESCRIPTOR_DTS	entry[ RDD_DHD_RX_POST_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_POST_DDR_BUFFER_DTS;

#endif
#if defined DSL_63148

#define RDD_DHD_RX_COMPLETE_DDR_BUFFER_SIZE     1024
typedef struct
{
	RDD_DHD_RX_COMPLETE_DESCRIPTOR_DTS	entry[ RDD_DHD_RX_COMPLETE_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_COMPLETE_DDR_BUFFER_DTS;

#endif
#if defined DSL_63148

#define RDD_DHD_TX_POST_DDR_BUFFER_SIZE     8
#define RDD_DHD_TX_POST_DDR_BUFFER_SIZE2    16
typedef struct
{
	RDD_DHD_TX_POST_DESCRIPTOR_DTS	entry[ RDD_DHD_TX_POST_DDR_BUFFER_SIZE ][ RDD_DHD_TX_POST_DDR_BUFFER_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_DDR_BUFFER_DTS;

#endif
#if defined DSL_63148

#define RDD_DHD_TX_COMPLETE_DDR_BUFFER_SIZE     16
typedef struct
{
	RDD_DHD_TX_COMPLETE_DESCRIPTOR_DTS	entry[ RDD_DHD_TX_COMPLETE_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_COMPLETE_DDR_BUFFER_DTS;

#endif
#if defined DSL_63148

#define RDD_R2D_WR_ARR_DDR_BUFFER_SIZE     128
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_R2D_WR_ARR_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_R2D_WR_ARR_DDR_BUFFER_DTS;

#endif
#if defined DSL_63148

#define RDD_D2R_RD_ARR_DDR_BUFFER_SIZE     128
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_D2R_RD_ARR_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_D2R_RD_ARR_DDR_BUFFER_DTS;

#endif
#if defined DSL_63148

#define RDD_R2D_RD_ARR_DDR_BUFFER_SIZE     128
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_R2D_RD_ARR_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_R2D_RD_ARR_DDR_BUFFER_DTS;

#endif
#if defined DSL_63148

#define RDD_D2R_WR_ARR_DDR_BUFFER_SIZE     128
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_D2R_WR_ARR_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_D2R_WR_ARR_DDR_BUFFER_DTS;

#endif
#if defined DSL_63148

#define RDD_WLAN_MCAST_DHD_LIST_TABLE_SIZE     64
typedef struct
{
	RDD_WLAN_MCAST_DHD_LIST_ENTRY_ARRAY_DTS	entry[ RDD_WLAN_MCAST_DHD_LIST_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_DHD_LIST_TABLE_DTS;

#endif
/* PSRAM */
/* PRIVATE_A */
#if defined WL4908

#define RDD_INGRESS_HANDLER_BUFFER_SIZE     32
typedef struct
{
	RDD_IH_BUFFER_DTS	entry[ RDD_INGRESS_HANDLER_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_HANDLER_BUFFER_DTS;

#define RDD_INGRESS_HANDLER_BUFFER_PTR()	( RDD_INGRESS_HANDLER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + INGRESS_HANDLER_BUFFER_ADDRESS )

#endif
#if defined WL4908

typedef struct
{
	uint32_t	reserved0            	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wred_bit_reserved0   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_queue_reserved0   	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_port_reserved0	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	header_number        	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_bridge_port   	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length        	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	absolute_normal      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	misc                 	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = misc, size = 3 bits
	uint32_t	last_indication      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pti                  	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ring_id              	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	payload_offset       	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_memory        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ddr_params           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = ddr_params, size = 2 bits
	uint32_t	ddr_id               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	packet_location      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = packet_location, size = 16 bits
	uint32_t	buffer_number        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2            	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs_address_index    	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_DESCRIPTOR_DTS;

#define RDD_BBH_TX_DESCRIPTOR_WRED_BIT_RESERVED0_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p, 3, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_WRED_BIT_RESERVED0_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p, 3, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_TX_QUEUE_RESERVED0_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p, 0, 3, r)
#define RDD_BBH_TX_DESCRIPTOR_TX_QUEUE_RESERVED0_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p, 0, 3, v)
#define RDD_BBH_TX_DESCRIPTOR_EGRESS_PORT_RESERVED0_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 1, 3, 5, r)
#define RDD_BBH_TX_DESCRIPTOR_EGRESS_PORT_RESERVED0_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 1, 3, 5, v)
#define RDD_BBH_TX_DESCRIPTOR_HEADER_NUMBER_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 1, 0, 3, r)
#define RDD_BBH_TX_DESCRIPTOR_HEADER_NUMBER_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 1, 0, 3, v)
#define RDD_BBH_TX_DESCRIPTOR_SOURCE_BRIDGE_PORT_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 2, 4, 4, r)
#define RDD_BBH_TX_DESCRIPTOR_SOURCE_BRIDGE_PORT_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 2, 4, 4, v)
#define RDD_BBH_TX_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                         FIELD_MREAD_16((uint8_t *)p + 2, 0, 12, r)
#define RDD_BBH_TX_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                        FIELD_MWRITE_16((uint8_t *)p + 2, 0, 12, v)
#define RDD_BBH_TX_DESCRIPTOR_ABSOLUTE_NORMAL_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_ABSOLUTE_NORMAL_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_MISC_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 4, 4, 3, r)
#define RDD_BBH_TX_DESCRIPTOR_MISC_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 4, 4, 3, v)
#define RDD_BBH_TX_DESCRIPTOR_LAST_INDICATION_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_LAST_INDICATION_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_PTI_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p + 4, 4, 2, r)
#define RDD_BBH_TX_DESCRIPTOR_PTI_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p + 4, 4, 2, v)
#define RDD_BBH_TX_DESCRIPTOR_RING_ID_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 4, 4, 3, r)
#define RDD_BBH_TX_DESCRIPTOR_RING_ID_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 4, 4, 3, v)
#define RDD_BBH_TX_DESCRIPTOR_PAYLOAD_OFFSET_READ(r, p)                        FIELD_MREAD_16((uint8_t *)p + 4, 3, 9, r)
#define RDD_BBH_TX_DESCRIPTOR_PAYLOAD_OFFSET_WRITE(v, p)                       FIELD_MWRITE_16((uint8_t *)p + 4, 3, 9, v)
#define RDD_BBH_TX_DESCRIPTOR_TARGET_MEMORY_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 5, 2, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_TARGET_MEMORY_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 5, 2, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_DDR_PARAMS_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 5, 0, 2, r)
#define RDD_BBH_TX_DESCRIPTOR_DDR_PARAMS_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 5, 0, 2, v)
#define RDD_BBH_TX_DESCRIPTOR_DDR_ID_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 5, 1, 1, r)
#define RDD_BBH_TX_DESCRIPTOR_DDR_ID_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 5, 1, 1, v)
#define RDD_BBH_TX_DESCRIPTOR_PACKET_LOCATION_READ(r, p)                       MREAD_16((uint8_t *)p + 6, r)
#define RDD_BBH_TX_DESCRIPTOR_PACKET_LOCATION_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 6, v)
#define RDD_BBH_TX_DESCRIPTOR_BUFFER_NUMBER_READ(r, p)                         MREAD_16((uint8_t *)p + 6, r)
#define RDD_BBH_TX_DESCRIPTOR_BUFFER_NUMBER_WRITE(v, p)                        MWRITE_16((uint8_t *)p + 6, v)
#define RDD_BBH_TX_DESCRIPTOR_ABS_ADDRESS_INDEX_READ(r, p)                     FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_BBH_TX_DESCRIPTOR_ABS_ADDRESS_INDEX_WRITE(v, p)                    FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#endif
#if defined WL4908

#define RDD_DS_CONNECTION_CONTEXT_BUFFER_SIZE     8
typedef struct
{
	RDD_CONNECTION_CONTEXT_BUFFER_ENTRY_DTS	entry[ RDD_DS_CONNECTION_CONTEXT_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CONNECTION_CONTEXT_BUFFER_DTS;

#define RDD_DS_CONNECTION_CONTEXT_BUFFER_PTR()	( RDD_DS_CONNECTION_CONTEXT_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CONNECTION_CONTEXT_BUFFER_ADDRESS )

#endif
#define RDD_DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE_PTR()	( RDD_DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE_ADDRESS )

#if defined WL4908

#define RDD_DS_CPU_REASON_TO_METER_TABLE_SIZE     64
typedef struct
{
	RDD_CPU_REASON_TO_METER_ENTRY_DTS	entry[ RDD_DS_CPU_REASON_TO_METER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_REASON_TO_METER_TABLE_DTS;

#define RDD_DS_CPU_REASON_TO_METER_TABLE_PTR()	( RDD_DS_CPU_REASON_TO_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_REASON_TO_METER_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_SIZE     8
typedef struct
{
	RDD_DS_SERVICE_QUEUE_DESCRIPTOR_DTS	entry[ RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_DTS;

#define RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_PTR()	( RDD_DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_SERVICE_QUEUES_DESCRIPTORS_TABLE_ADDRESS )

#endif
#define RDD_DS_POLICER_TABLE_PTR()	( RDD_DS_POLICER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_POLICER_TABLE_ADDRESS )

#if defined WL4908

#define RDD_IPSEC_DS_BUFFER_POOL_SIZE     2
typedef struct
{
	RDD_IPSEC_DS_BUFFER_DTS	entry[ RDD_IPSEC_DS_BUFFER_POOL_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_BUFFER_POOL_DTS;

#define RDD_IPSEC_DS_BUFFER_POOL_PTR()	( RDD_IPSEC_DS_BUFFER_POOL_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_DS_BUFFER_POOL_ADDRESS )

#endif
#if defined WL4908

#define RDD_IPSEC_DS_SA_DESC_TABLE_SIZE     16
typedef struct
{
	RDD_IPSEC_SA_DESC_DTS	entry[ RDD_IPSEC_DS_SA_DESC_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_SA_DESC_TABLE_DTS;

#define RDD_IPSEC_DS_SA_DESC_TABLE_PTR()	( RDD_IPSEC_DS_SA_DESC_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_DS_SA_DESC_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_IPSEC_US_SA_DESC_TABLE_SIZE     16
typedef struct
{
	RDD_IPSEC_SA_DESC_DTS	entry[ RDD_IPSEC_US_SA_DESC_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_US_SA_DESC_TABLE_DTS;

#define RDD_IPSEC_US_SA_DESC_TABLE_PTR()	( RDD_IPSEC_US_SA_DESC_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_US_SA_DESC_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_SIZE     32
typedef struct
{
	RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_DTS	entry[ RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_DTS;

#define RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_PTR()	( RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + SERVICE_QUEUES_RATE_LIMITER_TABLE_ADDRESS )

#endif
#define RDD_DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_PTR()	( RDD_DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS )

#if defined WL4908

#define RDD_ETH_TX_LOCAL_REGISTERS_SIZE     9
typedef struct
{
	RDD_ETH_TX_LOCAL_REGISTERS_ENTRY_DTS	entry[ RDD_ETH_TX_LOCAL_REGISTERS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_LOCAL_REGISTERS_DTS;

#define RDD_ETH_TX_LOCAL_REGISTERS_PTR()	( RDD_ETH_TX_LOCAL_REGISTERS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_LOCAL_REGISTERS_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_SIZE     8
typedef struct
{
	RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY_DTS	entry[ RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_DTS;

#define RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_PTR()	( RDD_DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_TIMER_SCHEDULER_PRIMITIVE_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_SIZE     32
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_DTS;

#define RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_PTR()	( RDD_DS_MAIN_PROFILING_BUFFER_RUNNER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_MAIN_PROFILING_BUFFER_RUNNER_ADDRESS )

#endif
#define RDD_DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE_PTR()	( RDD_DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS )

#if defined WL4908

#define RDD_RATE_LIMITER_REMAINDER_TABLE_SIZE     32
typedef struct
{
	RDD_RATE_LIMITER_REMAINDER_ENTRY_DTS	entry[ RDD_RATE_LIMITER_REMAINDER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RATE_LIMITER_REMAINDER_TABLE_DTS;

#define RDD_RATE_LIMITER_REMAINDER_TABLE_PTR()	( RDD_RATE_LIMITER_REMAINDER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + RATE_LIMITER_REMAINDER_TABLE_ADDRESS )

#endif
#if defined WL4908

typedef struct
{
	uint32_t	vlan_index_table_ptr	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	opbit_remark_mode   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipbit_remark_mode   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wifi_ssid           	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dei_remark_enable   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dei_value           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue_mode  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	forward_mode        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_port         	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	qos_mapping_mode    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	traffic_class       	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_mode        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_id          	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_shaping_mode   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	union_field1        	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = union_field1, size = 7 bits
	uint32_t	rate_shaper_id      	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1           	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue       	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	subnet_id           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_pbit          	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inner_pbit          	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp_remarking_mode 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp                	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ecn                 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_VLAN_INDEX_TABLE_PTR_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 3, 13, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_VLAN_INDEX_TABLE_PTR_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 3, 13, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OPBIT_REMARK_MODE_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 1, 2, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OPBIT_REMARK_MODE_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 1, 2, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_IPBIT_REMARK_MODE_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 1, 1, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_IPBIT_REMARK_MODE_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 1, 1, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_WIFI_SSID_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p + 0, 13, 4, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_WIFI_SSID_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p + 0, 13, 4, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_REMARK_ENABLE_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 2, 4, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_REMARK_ENABLE_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 2, 4, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_VALUE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 2, 3, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DEI_VALUE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 2, 3, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 2, 2, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 2, 2, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_FORWARD_MODE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 2, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_FORWARD_MODE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 2, 0, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_EGRESS_PORT_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 3, 4, 4, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_EGRESS_PORT_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 3, 4, 4, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_QOS_MAPPING_MODE_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 3, 3, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_QOS_MAPPING_MODE_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 3, 3, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_TRAFFIC_CLASS_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 3, 0, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_TRAFFIC_CLASS_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 3, 0, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DROP_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DROP_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_CPU_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_CPU_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_MODE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 4, 5, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_MODE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 4, 5, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_ID_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 4, 1, 4, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_POLICER_ID_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 4, 1, 4, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_SHAPING_MODE_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 4, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_SHAPING_MODE_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 4, 0, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_UNION_FIELD1_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 5, 1, 7, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_UNION_FIELD1_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 5, 1, 7, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_SHAPER_ID_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 5, 1, 7, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_RATE_SHAPER_ID_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 5, 1, 7, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SERVICE_QUEUE_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 5, 1, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SERVICE_QUEUE_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 5, 1, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SUBNET_ID_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p + 4, 15, 2, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_SUBNET_ID_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p + 4, 15, 2, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OUTER_PBIT_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 6, 4, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_OUTER_PBIT_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 6, 4, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_INNER_PBIT_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 6, 1, 3, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_INNER_PBIT_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 6, 1, 3, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_REMARKING_MODE_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 6, 0, 1, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_REMARKING_MODE_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 6, 0, 1, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 7, 2, 6, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DSCP_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 7, 2, 6, v)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_ECN_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 7, 0, 2, r)
#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_ECN_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 7, 0, 2, v)
#endif
#if defined WL4908

#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_SIZE     256
typedef struct
{
	RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_FC_MCAST_CONNECTION2_TABLE_SIZE     128
typedef struct
{
	RDD_FC_MCAST_CONNECTION2_ENTRY_DTS	entry[ RDD_FC_MCAST_CONNECTION2_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_CONNECTION2_TABLE_DTS;

#define RDD_FC_MCAST_CONNECTION2_TABLE_PTR()	( RDD_FC_MCAST_CONNECTION2_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + FC_MCAST_CONNECTION2_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_ETH_TX_QUEUES_POINTERS_TABLE_SIZE     72
typedef struct
{
	RDD_ETH_TX_QUEUE_POINTERS_ENTRY_DTS	entry[ RDD_ETH_TX_QUEUES_POINTERS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_QUEUES_POINTERS_TABLE_DTS;

#define RDD_ETH_TX_QUEUES_POINTERS_TABLE_PTR()	( RDD_ETH_TX_QUEUES_POINTERS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_QUEUES_POINTERS_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
typedef struct
{
	RDD_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS	entry[ RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_DTS;

#define RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_PTR()	( RDD_DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS )

#endif
#if defined WL4908

#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_SIZE     128
typedef struct
{
	RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_DTS	entry[ RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_DTS;

#define RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_PTR()	( RDD_ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_DTS;

#define RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_PTR()	( RDD_DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS;

#define RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_PTR()	( RDD_DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS;

#define RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_PTR()	( RDD_DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_SIZE     32
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_RATE_LIMITER_TABLE_SIZE     32
typedef struct
{
	RDD_RATE_LIMITER_ENTRY_DTS	entry[ RDD_DS_RATE_LIMITER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_RATE_LIMITER_TABLE_DTS;

#define RDD_DS_RATE_LIMITER_TABLE_PTR()	( RDD_DS_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_RATE_LIMITER_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_ETH_TX_QUEUES_TABLE_SIZE     72
typedef struct
{
	RDD_ETH_TX_QUEUE_DESCRIPTOR_DTS	entry[ RDD_ETH_TX_QUEUES_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_QUEUES_TABLE_DTS;

#define RDD_ETH_TX_QUEUES_TABLE_PTR()	( RDD_ETH_TX_QUEUES_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_QUEUES_TABLE_ADDRESS )

#endif
#define RDD_DS_CPU_RX_METER_TABLE_PTR()	( RDD_DS_CPU_RX_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_RX_METER_TABLE_ADDRESS )

#if defined WL4908

#define RDD_DS_FORWARDING_MATRIX_TABLE_SIZE     9
#define RDD_DS_FORWARDING_MATRIX_TABLE_SIZE2    16
typedef struct
{
	RDD_FORWARDING_MATRIX_ENTRY_DTS	entry[ RDD_DS_FORWARDING_MATRIX_TABLE_SIZE ][ RDD_DS_FORWARDING_MATRIX_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FORWARDING_MATRIX_TABLE_DTS;

#define RDD_DS_FORWARDING_MATRIX_TABLE_PTR()	( RDD_DS_FORWARDING_MATRIX_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FORWARDING_MATRIX_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
typedef struct
{
	RDD_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS	entry[ RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_DTS;

#define RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_PTR()	( RDD_DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS )

#endif
#if defined WL4908

#define RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_TX_COMPLETE_DESCRIPTOR_DTS	entry[ RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_DTS;

#define RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_PTR()	( RDD_DHD_TX_COMPLETE_FLOW_RING_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DHD_TX_COMPLETE_FLOW_RING_BUFFER_ADDRESS )

#endif
#if defined WL4908

#define RDD_RUNNER_FWTRACE_MAINA_PARAM_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINA_PARAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINA_PARAM_DTS;

#define RDD_RUNNER_FWTRACE_MAINA_PARAM_PTR()	( RDD_RUNNER_FWTRACE_MAINA_PARAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + RUNNER_FWTRACE_MAINA_PARAM_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_WAN_FLOW_TABLE_SIZE     256
typedef struct
{
	RDD_DS_WAN_FLOW_ENTRY_DTS	entry[ RDD_DS_WAN_FLOW_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_WAN_FLOW_TABLE_DTS;

#define RDD_DS_WAN_FLOW_TABLE_PTR()	( RDD_DS_WAN_FLOW_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_WAN_FLOW_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_WAN_UDP_FILTER_TABLE_SIZE     32
typedef struct
{
	RDD_DS_WAN_UDP_FILTER_ENTRY_DTS	entry[ RDD_DS_WAN_UDP_FILTER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_WAN_UDP_FILTER_TABLE_DTS;

#define RDD_DS_WAN_UDP_FILTER_TABLE_PTR()	( RDD_DS_WAN_UDP_FILTER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_WAN_UDP_FILTER_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE     8
#define RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE2    64
typedef struct
{
	RDD_FC_MCAST_PORT_HEADER_ENTRY_DTS	entry[ RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE ][ RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_PORT_HEADER_BUFFER_DTS;

#define RDD_FC_MCAST_PORT_HEADER_BUFFER_PTR()	( RDD_FC_MCAST_PORT_HEADER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + FC_MCAST_PORT_HEADER_BUFFER_ADDRESS )

#endif
#if defined WL4908

typedef struct
{
	uint32_t	reserved0    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1    	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	buffer_number	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_BPM_DTS;

#define RDD_CPU_TX_DESCRIPTOR_BPM_BUFFER_NUMBER_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_CPU_TX_DESCRIPTOR_BPM_BUFFER_NUMBER_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#define RDD_CPU_TX_DESCRIPTOR_BPM_BUFFER_NUMBER_L_READ( wv )               FIELD_GET( wv, 0, 14 )
#define RDD_CPU_TX_DESCRIPTOR_BPM_BUFFER_NUMBER_L_WRITE( v, wv )           FIELD_SET( v, 0, 14, wv )
#endif
#if defined WL4908

#define RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_SIZE     8
typedef struct
{
	RDD_CONNECTION_CONTEXT_MULTICAST_BUFFER_ENTRY_DTS	entry[ RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_DTS;

#define RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_PTR()	( RDD_DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CONNECTION_CONTEXT_MULTICAST_BUFFER_ADDRESS )

#endif
#if defined WL4908

typedef struct
{
	uint32_t	last_sbn        	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_offset  	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length   	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1       	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error_type      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ih_buffer_number	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_memory   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ddr_id          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	buffer_number   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_RX_DESCRIPTOR_DTS;

#define RDD_BBH_RX_DESCRIPTOR_LAST_SBN_READ(r, p)                         FIELD_MREAD_16((uint8_t *)p, 6, 10, r)
#define RDD_BBH_RX_DESCRIPTOR_LAST_SBN_WRITE(v, p)                        FIELD_MWRITE_16((uint8_t *)p, 6, 10, v)
#define RDD_BBH_RX_DESCRIPTOR_PAYLOAD_OFFSET_READ(r, p)                   FIELD_MREAD_32((uint8_t *)p + 0, 13, 9, r)
#define RDD_BBH_RX_DESCRIPTOR_PAYLOAD_OFFSET_WRITE(v, p)                  FIELD_MWRITE_32((uint8_t *)p + 0, 13, 9, v)
#define RDD_BBH_RX_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                    FIELD_MREAD_16((uint8_t *)p + 2, 0, 12, r)
#define RDD_BBH_RX_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                   FIELD_MWRITE_16((uint8_t *)p + 2, 0, 12, v)
#define RDD_BBH_RX_DESCRIPTOR_ERROR_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_BBH_RX_DESCRIPTOR_ERROR_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_BBH_RX_DESCRIPTOR_ERROR_TYPE_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 4, 1, 4, r)
#define RDD_BBH_RX_DESCRIPTOR_ERROR_TYPE_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 4, 1, 4, v)
#define RDD_BBH_RX_DESCRIPTOR_IH_BUFFER_NUMBER_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 4, 3, 6, r)
#define RDD_BBH_RX_DESCRIPTOR_IH_BUFFER_NUMBER_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 4, 3, 6, v)
#define RDD_BBH_RX_DESCRIPTOR_TARGET_MEMORY_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 5, 2, 1, r)
#define RDD_BBH_RX_DESCRIPTOR_TARGET_MEMORY_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 5, 2, 1, v)
#define RDD_BBH_RX_DESCRIPTOR_DDR_ID_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 5, 1, 1, r)
#define RDD_BBH_RX_DESCRIPTOR_DDR_ID_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 5, 1, 1, v)
#define RDD_BBH_RX_DESCRIPTOR_BUFFER_NUMBER_READ(r, p)                    MREAD_16((uint8_t *)p + 6, r)
#define RDD_BBH_RX_DESCRIPTOR_BUFFER_NUMBER_WRITE(v, p)                   MWRITE_16((uint8_t *)p + 6, v)
#endif
#if defined WL4908

#define RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_SIZE     64
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_DTS;

#define RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_PTR()	( RDD_DOWNSTREAM_LAN_ENQUEUE_SQ_PD_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_LAN_ENQUEUE_SQ_PD_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_CPU_TX_BBH_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY_DTS	entry[ RDD_DS_CPU_TX_BBH_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_TX_BBH_DESCRIPTORS_DTS;

#define RDD_DS_CPU_TX_BBH_DESCRIPTORS_PTR()	( RDD_DS_CPU_TX_BBH_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_TX_BBH_DESCRIPTORS_ADDRESS )

#endif
#if defined WL4908

#define RDD_REVERSE_FFI_TABLE_SIZE     256
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_REVERSE_FFI_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_REVERSE_FFI_TABLE_DTS;

#define RDD_REVERSE_FFI_TABLE_PTR()	( RDD_REVERSE_FFI_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + REVERSE_FFI_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_DTS;

#define RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_PTR()	( RDD_CPU_RX_SQ_PD_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_RX_SQ_PD_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DHD_TX_POST_PD_INGRESS_QUEUE_SIZE     32
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DHD_TX_POST_PD_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_PD_INGRESS_QUEUE_DTS;

#define RDD_DHD_TX_POST_PD_INGRESS_QUEUE_PTR()	( RDD_DHD_TX_POST_PD_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DHD_TX_POST_PD_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_INGRESS_HANDLER_SKB_DATA_POINTER_SIZE     32
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_INGRESS_HANDLER_SKB_DATA_POINTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_HANDLER_SKB_DATA_POINTER_DTS;

#define RDD_INGRESS_HANDLER_SKB_DATA_POINTER_PTR()	( RDD_INGRESS_HANDLER_SKB_DATA_POINTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + INGRESS_HANDLER_SKB_DATA_POINTER_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_SIZE     16
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_QUEUE_PROFILE_TABLE_SIZE     8
typedef struct
{
	RDD_QUEUE_PROFILE_DTS	entry[ RDD_DS_QUEUE_PROFILE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_QUEUE_PROFILE_TABLE_DTS;

#define RDD_DS_QUEUE_PROFILE_TABLE_PTR()	( RDD_DS_QUEUE_PROFILE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_QUEUE_PROFILE_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_DTS;

#define RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR()	( RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_DTS;

#define RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_PTR()	( RDD_DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_SQ_ENQUEUE_QUEUE_SIZE     64
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_DS_SQ_ENQUEUE_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_SQ_ENQUEUE_QUEUE_DTS;

#define RDD_DS_SQ_ENQUEUE_QUEUE_PTR()	( RDD_DS_SQ_ENQUEUE_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_SQ_ENQUEUE_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_SIZE     10
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_DTS;

#define RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_PTR()	( RDD_EMAC_ABSOLUTE_TX_BBH_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_ABSOLUTE_TX_BBH_COUNTER_ADDRESS )

#endif
#if defined WL4908

typedef struct
{
	uint32_t	head_pointer             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tail_pointer             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	guaranteed_free_count    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	non_guaranteed_free_count	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	guaranteed_threshold     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_DTS;

#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_HEAD_POINTER_READ(r, p)                              MREAD_16((uint8_t *)p, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_HEAD_POINTER_WRITE(v, p)                             MWRITE_16((uint8_t *)p, v)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_TAIL_POINTER_READ(r, p)                              MREAD_16((uint8_t *)p + 2, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_TAIL_POINTER_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 2, v)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_FREE_COUNT_READ(r, p)                     MREAD_16((uint8_t *)p + 4, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_FREE_COUNT_WRITE(v, p)                    MWRITE_16((uint8_t *)p + 4, v)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_NON_GUARANTEED_FREE_COUNT_READ(r, p)                 MREAD_16((uint8_t *)p + 6, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_NON_GUARANTEED_FREE_COUNT_WRITE(v, p)                MWRITE_16((uint8_t *)p + 6, v)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_THRESHOLD_READ(r, p)                      MREAD_16((uint8_t *)p + 8, r)
#define RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_THRESHOLD_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 8, v)
#endif
#if defined WL4908

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_SIZE     5
typedef struct
{
	RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_ENTRY_DTS	entry[ RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_DTS;

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_PTR()	( RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_SKB_ENQUEUED_INDEXES_FIFO_ADDRESS )

#endif
#if defined WL4908

#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_COMPLETE_RING_DESCRIPTOR_DTS	entry[ RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_DTS;

#define RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_PTR()	( RDD_DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DHD_COMPLETE_RING_DESCRIPTOR_BUFFER_ADDRESS )

#endif
#if defined WL4908

#define RDD_RUNNER_FWTRACE_PICOA_PARAM_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_PICOA_PARAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_PICOA_PARAM_DTS;

#define RDD_RUNNER_FWTRACE_PICOA_PARAM_PTR()	( RDD_RUNNER_FWTRACE_PICOA_PARAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + RUNNER_FWTRACE_PICOA_PARAM_ADDRESS )

#endif
#if defined WL4908

#define RDD_GPON_RX_DIRECT_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_GPON_RX_DIRECT_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_RX_DIRECT_DESCRIPTORS_DTS;

#define RDD_GPON_RX_DIRECT_DESCRIPTORS_PTR()	( RDD_GPON_RX_DIRECT_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GPON_RX_DIRECT_DESCRIPTORS_ADDRESS )

#endif
#if defined WL4908

#define RDD_CPU_RX_PD_INGRESS_QUEUE_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_CPU_RX_PD_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_PD_INGRESS_QUEUE_DTS;

#define RDD_CPU_RX_PD_INGRESS_QUEUE_PTR()	( RDD_CPU_RX_PD_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_RX_PD_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_DTS;

#define RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_PTR()	( RDD_DS_CPU_RX_PICO_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_RX_PICO_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_DTS;

#define RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_PTR()	( RDD_CPU_RX_FAST_PD_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_RX_FAST_PD_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_DTS;

#define RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_PTR()	( RDD_DOWNSTREAM_MULTICAST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DOWNSTREAM_MULTICAST_INGRESS_QUEUE_ADDRESS )

#endif

typedef struct
{
	uint32_t	reserved_fw_only	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BYTES_4_DTS;

#if defined WL4908

#define RDD_DS_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE     8
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_DS_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS;

#define RDD_DS_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_PTR()	( RDD_DS_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_ADDRESS )

#endif
#define RDD_DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR()	( RDD_DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_ADDRESS )

#if defined WL4908

#define RDD_DS_FAST_MALLOC_RESULT_TABLE_SIZE     2
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_DS_FAST_MALLOC_RESULT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FAST_MALLOC_RESULT_TABLE_DTS;

#define RDD_DS_FAST_MALLOC_RESULT_TABLE_PTR()	( RDD_DS_FAST_MALLOC_RESULT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FAST_MALLOC_RESULT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_PICO_MALLOC_RESULT_TABLE_SIZE     2
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_DS_PICO_MALLOC_RESULT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PICO_MALLOC_RESULT_TABLE_DTS;

#define RDD_DS_PICO_MALLOC_RESULT_TABLE_PTR()	( RDD_DS_PICO_MALLOC_RESULT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_MALLOC_RESULT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_SIZE     8
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_DTS;

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_PTR()	( RDD_EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE     8
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_DS_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS;

#define RDD_DS_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_PTR()	( RDD_DS_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_ROUTER_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DS_ROUTER_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_ROUTER_INGRESS_QUEUE_DTS;

#define RDD_DS_ROUTER_INGRESS_QUEUE_PTR()	( RDD_DS_ROUTER_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_ROUTER_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_SIZE     32
typedef struct
{
	RDD_GPE_COMMAND_PRIMITIVE_ENTRY_DTS	entry[ RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_DTS;

#define RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_PTR()	( RDD_DS_GPE_COMMAND_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_GPE_COMMAND_PRIMITIVE_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_DTS;

#define RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_PTR()	( RDD_DS_CPU_RX_FAST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_CPU_RX_FAST_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_DEBUG_BUFFER_SIZE     32
typedef struct
{
	RDD_DEBUG_BUFFER_ENTRY_DTS	entry[ RDD_DS_DEBUG_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DEBUG_BUFFER_DTS;

#define RDD_DS_DEBUG_BUFFER_PTR()	( RDD_DS_DEBUG_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_DEBUG_BUFFER_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_FW_MAC_ADDRS_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DS_FW_MAC_ADDRS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FW_MAC_ADDRS_DTS;

#define RDD_DS_FW_MAC_ADDRS_PTR()	( RDD_DS_FW_MAC_ADDRS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FW_MAC_ADDRS_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_NULL_BUFFER_SIZE     3
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_DS_NULL_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_NULL_BUFFER_DTS;

#define RDD_DS_NULL_BUFFER_PTR()	( RDD_DS_NULL_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_NULL_BUFFER_ADDRESS )

#endif
#if defined WL4908

#define RDD_DHD_COMPLETE_RING_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_COMPLETE_RING_ENTRY_DTS	entry[ RDD_DHD_COMPLETE_RING_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_COMPLETE_RING_BUFFER_DTS;

#define RDD_DHD_COMPLETE_RING_BUFFER_PTR()	( RDD_DHD_COMPLETE_RING_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DHD_COMPLETE_RING_BUFFER_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_DHD_TX_POST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_DS_DHD_TX_POST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DHD_TX_POST_INGRESS_QUEUE_DTS;

#define RDD_DS_DHD_TX_POST_INGRESS_QUEUE_PTR()	( RDD_DS_DHD_TX_POST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_DHD_TX_POST_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_SIZE     8
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_DTS;

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_PTR()	( RDD_EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR_ADDRESS )

#endif
#if defined WL4908

#define RDD_WLAN_MCAST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_WLAN_MCAST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_INGRESS_QUEUE_DTS;

#define RDD_WLAN_MCAST_INGRESS_QUEUE_PTR()	( RDD_WLAN_MCAST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + WLAN_MCAST_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_DATA_POINTER_DUMMY_TARGET_SIZE     5
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DS_DATA_POINTER_DUMMY_TARGET_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DATA_POINTER_DUMMY_TARGET_DTS;

#define RDD_DS_DATA_POINTER_DUMMY_TARGET_PTR()	( RDD_DS_DATA_POINTER_DUMMY_TARGET_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_DATA_POINTER_DUMMY_TARGET_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_SIZE     4
typedef struct
{
	RDD_PARALLEL_PROCESSING_ENTRY_DTS	entry[ RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_DTS;

#define RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR()	( RDD_DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_ADDRESS )

#endif
#if defined WL4908

#define RDD_ETH_TX_MAC_TABLE_SIZE     8
typedef struct
{
	RDD_ETH_TX_MAC_DESCRIPTOR_DTS	entry[ RDD_ETH_TX_MAC_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_MAC_TABLE_DTS;

#define RDD_ETH_TX_MAC_TABLE_PTR()	( RDD_ETH_TX_MAC_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_MAC_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_DHD_FLOW_RING_DROP_COUNTER_SIZE     5
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DS_DHD_FLOW_RING_DROP_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DHD_FLOW_RING_DROP_COUNTER_DTS;

#define RDD_DS_DHD_FLOW_RING_DROP_COUNTER_PTR()	( RDD_DS_DHD_FLOW_RING_DROP_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_DHD_FLOW_RING_DROP_COUNTER_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_SIZE     4
typedef struct
{
	RDD_PARALLEL_PROCESSING_TASK_REORDER_ENTRY_DTS	entry[ RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_DTS;

#define RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_PTR()	( RDD_DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO_ADDRESS )

#endif
#define RDD_DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR()	( RDD_DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_ADDRESS )

#if defined WL4908

#define RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_SIZE     8
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_DTS;

#define RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_PTR()	( RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_SIZE     8
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_DTS;

#define RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_PTR()	( RDD_DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_SIZE     16
typedef struct
{
	RDD_BROADCOM_SWITCH_PORT_MAPPING_DTS	entry[ RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_DTS;

#define RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_PTR()	( RDD_DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_IPSEC_DS_SA_DESC_CAM_TABLE_SIZE     16
typedef struct
{
	RDD_IPSEC_SA_DESC_CAM_DTS	entry[ RDD_IPSEC_DS_SA_DESC_CAM_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_SA_DESC_CAM_TABLE_DTS;

#define RDD_IPSEC_DS_SA_DESC_CAM_TABLE_PTR()	( RDD_IPSEC_DS_SA_DESC_CAM_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_DS_SA_DESC_CAM_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_IPSEC_US_SA_DESC_CAM_TABLE_SIZE     16
typedef struct
{
	RDD_IPSEC_SA_DESC_CAM_DTS	entry[ RDD_IPSEC_US_SA_DESC_CAM_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_US_SA_DESC_CAM_TABLE_DTS;

#define RDD_IPSEC_US_SA_DESC_CAM_TABLE_PTR()	( RDD_IPSEC_US_SA_DESC_CAM_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_US_SA_DESC_CAM_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_ETH_TX_SCRATCH_SIZE     16
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_ETH_TX_SCRATCH_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_SCRATCH_DTS;

#define RDD_ETH_TX_SCRATCH_PTR()	( RDD_ETH_TX_SCRATCH_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + ETH_TX_SCRATCH_ADDRESS )

#endif
#if defined WL4908

#define RDD_GSO_TX_DHD_L2_BUFFER_SIZE     22
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_GSO_TX_DHD_L2_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_TX_DHD_L2_BUFFER_DTS;

#define RDD_GSO_TX_DHD_L2_BUFFER_PTR()	( RDD_GSO_TX_DHD_L2_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GSO_TX_DHD_L2_BUFFER_ADDRESS )

#endif
#if defined WL4908

#define RDD_CPU_TX_DHD_L2_BUFFER_SIZE     22
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_CPU_TX_DHD_L2_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DHD_L2_BUFFER_DTS;

#define RDD_CPU_TX_DHD_L2_BUFFER_PTR()	( RDD_CPU_TX_DHD_L2_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_TX_DHD_L2_BUFFER_ADDRESS )

#endif
#if defined WL4908

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_SIZE     5
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_DTS;

#define RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_PTR()	( RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS_ADDRESS )

#endif
#if defined WL4908

typedef struct
{
	uint8_t	status_vector	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_EMACS_STATUS_ENTRY_DTS;

#define RDD_ETH_TX_EMACS_STATUS_ENTRY_STATUS_VECTOR_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_ETH_TX_EMACS_STATUS_ENTRY_STATUS_VECTOR_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#endif
#if defined WL4908

#define RDD_HASH_BASED_FORWARDING_PORT_TABLE_SIZE     4
typedef struct
{
	RDD_HASH_BASED_FORWARDING_PORT_ENTRY_DTS	entry[ RDD_HASH_BASED_FORWARDING_PORT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_HASH_BASED_FORWARDING_PORT_TABLE_DTS;

#define RDD_HASH_BASED_FORWARDING_PORT_TABLE_PTR()	( RDD_HASH_BASED_FORWARDING_PORT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + HASH_BASED_FORWARDING_PORT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_GSO_TX_DHD_HOST_BUF_PTR_SIZE     4
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_GSO_TX_DHD_HOST_BUF_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_TX_DHD_HOST_BUF_PTR_DTS;

#define RDD_GSO_TX_DHD_HOST_BUF_PTR_PTR()	( RDD_GSO_TX_DHD_HOST_BUF_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GSO_TX_DHD_HOST_BUF_PTR_ADDRESS )

#endif
#if defined WL4908

#define RDD_CPU_TX_DHD_HOST_BUF_PTR_SIZE     4
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_CPU_TX_DHD_HOST_BUF_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DHD_HOST_BUF_PTR_DTS;

#define RDD_CPU_TX_DHD_HOST_BUF_PTR_PTR()	( RDD_CPU_TX_DHD_HOST_BUF_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_TX_DHD_HOST_BUF_PTR_ADDRESS )

#endif

typedef struct
{
	uint16_t	reserved_fw_only	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BYTES_2_DTS;

#if defined WL4908

typedef struct
{
	uint8_t	emac_offset	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH_TX_INTER_LAN_SCHEDULING_OFFSET_ENTRY_DTS;

#define RDD_ETH_TX_INTER_LAN_SCHEDULING_OFFSET_ENTRY_EMAC_OFFSET_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_ETH_TX_INTER_LAN_SCHEDULING_OFFSET_ENTRY_EMAC_OFFSET_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#endif

typedef struct
{
	uint8_t	reserved_fw_only	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BYTE_1_DTS;

#if defined WL4908

#define RDD_GPON_RX_NORMAL_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_GPON_RX_NORMAL_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_RX_NORMAL_DESCRIPTORS_DTS;

#define RDD_GPON_RX_NORMAL_DESCRIPTORS_PTR()	( RDD_GPON_RX_NORMAL_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GPON_RX_NORMAL_DESCRIPTORS_ADDRESS )

#endif
/* PRIVATE_B */
#if defined WL4908

#define RDD_US_INGRESS_HANDLER_BUFFER_SIZE     32
typedef struct
{
	RDD_IH_BUFFER_DTS	entry[ RDD_US_INGRESS_HANDLER_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_HANDLER_BUFFER_DTS;

#define RDD_US_INGRESS_HANDLER_BUFFER_PTR()	( RDD_US_INGRESS_HANDLER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_HANDLER_BUFFER_ADDRESS )

#endif
#define RDD_US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE_PTR()	( RDD_US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE_ADDRESS )

#if defined WL4908

#define RDD_US_CPU_REASON_TO_METER_TABLE_SIZE     64
typedef struct
{
	RDD_CPU_REASON_TO_METER_ENTRY_DTS	entry[ RDD_US_CPU_REASON_TO_METER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_REASON_TO_METER_TABLE_DTS;

#define RDD_US_CPU_REASON_TO_METER_TABLE_PTR()	( RDD_US_CPU_REASON_TO_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_REASON_TO_METER_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_MAIN_PROFILING_BUFFER_RUNNER_SIZE     32
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_US_MAIN_PROFILING_BUFFER_RUNNER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_MAIN_PROFILING_BUFFER_RUNNER_DTS;

#define RDD_US_MAIN_PROFILING_BUFFER_RUNNER_PTR()	( RDD_US_MAIN_PROFILING_BUFFER_RUNNER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_MAIN_PROFILING_BUFFER_RUNNER_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_RUNNER_FLOW_HEADER_BUFFER_SIZE     3
typedef struct
{
	RDD_RUNNER_FLOW_HEADER_BUFFER_DTS	entry[ RDD_US_RUNNER_FLOW_HEADER_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RUNNER_FLOW_HEADER_BUFFER_DTS;

#define RDD_US_RUNNER_FLOW_HEADER_BUFFER_PTR()	( RDD_US_RUNNER_FLOW_HEADER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RUNNER_FLOW_HEADER_BUFFER_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_QUEUE_PROFILE_TABLE_SIZE     8
typedef struct
{
	RDD_QUEUE_PROFILE_DTS	entry[ RDD_US_QUEUE_PROFILE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_QUEUE_PROFILE_TABLE_DTS;

#define RDD_US_QUEUE_PROFILE_TABLE_PTR()	( RDD_US_QUEUE_PROFILE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_QUEUE_PROFILE_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_WAN_CHANNELS_8_39_TABLE_SIZE     32
typedef struct
{
	RDD_WAN_CHANNEL_8_39_DESCRIPTOR_DTS	entry[ RDD_WAN_CHANNELS_8_39_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_CHANNELS_8_39_TABLE_DTS;

#define RDD_WAN_CHANNELS_8_39_TABLE_PTR()	( RDD_WAN_CHANNELS_8_39_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + WAN_CHANNELS_8_39_TABLE_ADDRESS )

#endif
#define RDD_US_POLICER_TABLE_PTR()	( RDD_US_POLICER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_POLICER_TABLE_ADDRESS )

#define RDD_US_CPU_RX_METER_TABLE_PTR()	( RDD_US_CPU_RX_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_RX_METER_TABLE_ADDRESS )

#if defined WL4908

#define RDD_US_CPU_TX_BBH_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY_DTS	entry[ RDD_US_CPU_TX_BBH_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_TX_BBH_DESCRIPTORS_DTS;

#define RDD_US_CPU_TX_BBH_DESCRIPTORS_PTR()	( RDD_US_CPU_TX_BBH_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_TX_BBH_DESCRIPTORS_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_FORWARDING_MATRIX_TABLE_SIZE     9
#define RDD_US_FORWARDING_MATRIX_TABLE_SIZE2    16
typedef struct
{
	RDD_FORWARDING_MATRIX_ENTRY_DTS	entry[ RDD_US_FORWARDING_MATRIX_TABLE_SIZE ][ RDD_US_FORWARDING_MATRIX_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FORWARDING_MATRIX_TABLE_DTS;

#define RDD_US_FORWARDING_MATRIX_TABLE_PTR()	( RDD_US_FORWARDING_MATRIX_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FORWARDING_MATRIX_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_SIZE     8
typedef struct
{
	RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY_DTS	entry[ RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_DTS;

#define RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_PTR()	( RDD_US_TIMER_SCHEDULER_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_TIMER_SCHEDULER_PRIMITIVE_TABLE_ADDRESS )

#endif
#define RDD_US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_PTR()	( RDD_US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS )

#if defined WL4908

#define RDD_US_WAN_FLOW_TABLE_SIZE     256
typedef struct
{
	RDD_US_WAN_FLOW_ENTRY_DTS	entry[ RDD_US_WAN_FLOW_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_WAN_FLOW_TABLE_DTS;

#define RDD_US_WAN_FLOW_TABLE_PTR()	( RDD_US_WAN_FLOW_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_WAN_FLOW_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_SIZE     32
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_DTS;

#define RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_PTR()	( RDD_US_INGRESS_HANDLER_SKB_DATA_POINTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_HANDLER_SKB_DATA_POINTER_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_SIZE     16
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_SIZE     8
#define RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_SIZE2    8
typedef struct
{
	RDD_US_QUEUE_ENTRY_DTS	entry[ RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_SIZE ][ RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_DTS;

#define RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_PTR()	( RDD_US_TRAFFIC_CLASS_TO_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_TRAFFIC_CLASS_TO_QUEUE_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS;

#define RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_PTR()	( RDD_US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS;

#define RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_PTR()	( RDD_US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_SIZE     32
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_RATE_LIMITER_TABLE_SIZE     16
typedef struct
{
	RDD_RATE_LIMITER_ENTRY_DTS	entry[ RDD_US_RATE_LIMITER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RATE_LIMITER_TABLE_DTS;

#define RDD_US_RATE_LIMITER_TABLE_PTR()	( RDD_US_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RATE_LIMITER_TABLE_ADDRESS )

#endif
#define RDD_US_PICO_TIMER_TASK_DESCRIPTOR_TABLE_PTR()	( RDD_US_PICO_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS )

#if defined WL4908

#define RDD_US_CONNECTION_CONTEXT_BUFFER_SIZE     8
typedef struct
{
	RDD_CONNECTION_CONTEXT_BUFFER_ENTRY_DTS	entry[ RDD_US_CONNECTION_CONTEXT_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CONNECTION_CONTEXT_BUFFER_DTS;

#define RDD_US_CONNECTION_CONTEXT_BUFFER_PTR()	( RDD_US_CONNECTION_CONTEXT_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CONNECTION_CONTEXT_BUFFER_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_SIZE     256
typedef struct
{
	RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_CLASSIFICATION_CONTEXT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_WAN_CHANNELS_0_7_TABLE_SIZE     8
typedef struct
{
	RDD_WAN_CHANNEL_0_7_DESCRIPTOR_DTS	entry[ RDD_WAN_CHANNELS_0_7_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_CHANNELS_0_7_TABLE_DTS;

#define RDD_WAN_CHANNELS_0_7_TABLE_PTR()	( RDD_WAN_CHANNELS_0_7_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + WAN_CHANNELS_0_7_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
typedef struct
{
	RDD_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS	entry[ RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_DTS;

#define RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_PTR()	( RDD_US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
typedef struct
{
	RDD_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY_DTS	entry[ RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_DTS;

#define RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_PTR()	( RDD_US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_INGRESS_RATE_LIMITER_TABLE_SIZE     5
typedef struct
{
	RDD_INGRESS_RATE_LIMITER_ENTRY_DTS	entry[ RDD_US_INGRESS_RATE_LIMITER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_RATE_LIMITER_TABLE_DTS;

#define RDD_US_INGRESS_RATE_LIMITER_TABLE_PTR()	( RDD_US_INGRESS_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_RATE_LIMITER_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DHD_RX_FPM_ALLOC_RESULT_TABLE_SIZE     8
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_DHD_RX_FPM_ALLOC_RESULT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_FPM_ALLOC_RESULT_TABLE_DTS;

#define RDD_DHD_RX_FPM_ALLOC_RESULT_TABLE_PTR()	( RDD_DHD_RX_FPM_ALLOC_RESULT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DHD_RX_FPM_ALLOC_RESULT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_CPU_RX_PICO_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_US_CPU_RX_PICO_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_RX_PICO_INGRESS_QUEUE_DTS;

#define RDD_US_CPU_RX_PICO_INGRESS_QUEUE_PTR()	( RDD_US_CPU_RX_PICO_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_RX_PICO_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_ROUTER_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_US_ROUTER_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_ROUTER_INGRESS_QUEUE_DTS;

#define RDD_US_ROUTER_INGRESS_QUEUE_PTR()	( RDD_US_ROUTER_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_ROUTER_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_0_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE     8
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_US_0_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_0_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS;

#define RDD_US_0_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_PTR()	( RDD_US_0_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_0_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_0_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE     8
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_US_0_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_0_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS;

#define RDD_US_0_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_PTR()	( RDD_US_0_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_0_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_CPU_RX_FAST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_US_CPU_RX_FAST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_RX_FAST_INGRESS_QUEUE_DTS;

#define RDD_US_CPU_RX_FAST_INGRESS_QUEUE_PTR()	( RDD_US_CPU_RX_FAST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_RX_FAST_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_DEBUG_BUFFER_SIZE     32
typedef struct
{
	RDD_DEBUG_BUFFER_ENTRY_DTS	entry[ RDD_US_DEBUG_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_DEBUG_BUFFER_DTS;

#define RDD_US_DEBUG_BUFFER_PTR()	( RDD_US_DEBUG_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_DEBUG_BUFFER_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_FW_MAC_ADDRS_SIZE     16
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_US_FW_MAC_ADDRS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FW_MAC_ADDRS_DTS;

#define RDD_US_FW_MAC_ADDRS_PTR()	( RDD_US_FW_MAC_ADDRS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FW_MAC_ADDRS_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_1_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE     8
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_US_1_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_1_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS;

#define RDD_US_1_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_PTR()	( RDD_US_1_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_1_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_1_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE     8
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_US_1_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_1_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS;

#define RDD_US_1_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_PTR()	( RDD_US_1_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_1_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_DHD_TX_POST_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_US_DHD_TX_POST_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_DHD_TX_POST_INGRESS_QUEUE_DTS;

#define RDD_US_DHD_TX_POST_INGRESS_QUEUE_PTR()	( RDD_US_DHD_TX_POST_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_DHD_TX_POST_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_SIZE     48
typedef struct
{
	RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_ENTRY_DTS	entry[ RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_DTS;

#define RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_PTR()	( RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_2_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE     8
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_US_2_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_2_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS;

#define RDD_US_2_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_PTR()	( RDD_US_2_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_2_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_2_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE     8
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_US_2_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_2_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS;

#define RDD_US_2_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_PTR()	( RDD_US_2_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_2_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_SIZE     3
typedef struct
{
	RDD_RUNNER_FLOW_HEADER_DESCRIPTOR_DTS	entry[ RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_DTS;

#define RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_PTR()	( RDD_US_RUNNER_FLOW_HEADER_DESCRIPTOR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RUNNER_FLOW_HEADER_DESCRIPTOR_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_SIZE     32
typedef struct
{
	RDD_GPE_COMMAND_PRIMITIVE_ENTRY_DTS	entry[ RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_DTS;

#define RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_PTR()	( RDD_US_GPE_COMMAND_PRIMITIVE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_GPE_COMMAND_PRIMITIVE_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_SIZE     40
typedef struct
{
	RDD_GPON_ABSOLUTE_TX_COUNTER_DTS	entry[ RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_DTS;

#define RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_PTR()	( RDD_GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + GPON_ABSOLUTE_TX_FIRMWARE_COUNTER_ADDRESS )

#endif
#if defined WL4908

#define RDD_RUNNER_FWTRACE_MAINB_PARAM_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINB_PARAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINB_PARAM_DTS;

#define RDD_RUNNER_FWTRACE_MAINB_PARAM_PTR()	( RDD_RUNNER_FWTRACE_MAINB_PARAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + RUNNER_FWTRACE_MAINB_PARAM_ADDRESS )

#endif
#if defined WL4908

#define RDD_RUNNER_FWTRACE_PICOB_PARAM_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_PICOB_PARAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_PICOB_PARAM_DTS;

#define RDD_RUNNER_FWTRACE_PICOB_PARAM_PTR()	( RDD_RUNNER_FWTRACE_PICOB_PARAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + RUNNER_FWTRACE_PICOB_PARAM_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_DHD_FLOW_RING_DROP_COUNTER_SIZE     5
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_US_DHD_FLOW_RING_DROP_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_DHD_FLOW_RING_DROP_COUNTER_DTS;

#define RDD_US_DHD_FLOW_RING_DROP_COUNTER_PTR()	( RDD_US_DHD_FLOW_RING_DROP_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_DHD_FLOW_RING_DROP_COUNTER_ADDRESS )

#endif
#define RDD_US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR()	( RDD_US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_ADDRESS )

#if defined WL4908

#define RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_SIZE     8
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_DTS;

#define RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_PTR()	( RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_FAST_MALLOC_RESULT_TABLE_SIZE     2
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_US_FAST_MALLOC_RESULT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FAST_MALLOC_RESULT_TABLE_DTS;

#define RDD_US_FAST_MALLOC_RESULT_TABLE_PTR()	( RDD_US_FAST_MALLOC_RESULT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FAST_MALLOC_RESULT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_SIZE     16
typedef struct
{
	RDD_BROADCOM_SWITCH_PORT_MAPPING_DTS	entry[ RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_DTS;

#define RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_PTR()	( RDD_US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE_ADDRESS )

#endif
#define RDD_US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR()	( RDD_US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_ADDRESS )

#if defined WL4908

#define RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_SIZE     32
typedef struct
{
	RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_ENTRY_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_WAN_TX_SCRATCH_SIZE     16
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_WAN_TX_SCRATCH_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_TX_SCRATCH_DTS;

#define RDD_WAN_TX_SCRATCH_PTR()	( RDD_WAN_TX_SCRATCH_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + WAN_TX_SCRATCH_ADDRESS )

#endif
#if defined WL4908

#define RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_SIZE     40
typedef struct
{
	RDD_GPON_ABSOLUTE_TX_COUNTER_DTS	entry[ RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_DTS;

#define RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_PTR()	( RDD_GPON_ABSOLUTE_TX_BBH_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + GPON_ABSOLUTE_TX_BBH_COUNTER_ADDRESS )

#endif
#if defined WL4908

#define RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_SIZE     3
#define RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_SIZE2    6
typedef struct
{
	RDD_CPU_REASON_TO_METER_ENTRY_DTS	entry[ RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_SIZE ][ RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_DTS;

#define RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_PTR()	( RDD_CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_PICO_MALLOC_RESULT_TABLE_SIZE     2
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_US_PICO_MALLOC_RESULT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PICO_MALLOC_RESULT_TABLE_DTS;

#define RDD_US_PICO_MALLOC_RESULT_TABLE_PTR()	( RDD_US_PICO_MALLOC_RESULT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_MALLOC_RESULT_TABLE_ADDRESS )

#endif
#if defined WL4908

typedef struct
{
	uint32_t	guaranteed_free_count    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	non_guaranteed_free_count	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	guaranteed_threshold     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_DTS;

#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_FREE_COUNT_READ(r, p)                     MREAD_16((uint8_t *)p, r)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_FREE_COUNT_WRITE(v, p)                    MWRITE_16((uint8_t *)p, v)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_NON_GUARANTEED_FREE_COUNT_READ(r, p)                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_NON_GUARANTEED_FREE_COUNT_WRITE(v, p)                MWRITE_16((uint8_t *)p + 2, v)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_THRESHOLD_READ(r, p)                      MREAD_16((uint8_t *)p + 4, r)
#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY_GUARANTEED_THRESHOLD_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 4, v)
#endif
#if defined WL4908

#define RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_SIZE     14
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_DTS;

#define RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_PTR()	( RDD_CPU_TX_DHD_LAYER2_HEADER_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + CPU_TX_DHD_LAYER2_HEADER_BUFFER_ADDRESS )

#endif
#if defined WL4908

#define RDD_DATA_POINTER_DUMMY_TARGET_SIZE     2
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_DATA_POINTER_DUMMY_TARGET_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DATA_POINTER_DUMMY_TARGET_DTS;

#define RDD_DATA_POINTER_DUMMY_TARGET_PTR()	( RDD_DATA_POINTER_DUMMY_TARGET_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DATA_POINTER_DUMMY_TARGET_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_SIZE     4
typedef struct
{
	RDD_PARALLEL_PROCESSING_ENTRY_DTS	entry[ RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_DTS;

#define RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR()	( RDD_US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_SIZE     4
typedef struct
{
	RDD_PARALLEL_PROCESSING_TASK_REORDER_ENTRY_DTS	entry[ RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_DTS;

#define RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_PTR()	( RDD_US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PARALLEL_PROCESSING_TASK_REORDER_FIFO_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_SIZE     8
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_DTS;

#define RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_PTR()	( RDD_US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_SIZE     8
typedef struct
{
	RDD_BROADCOM_SWITCH_PORT_MAPPING_DTS	entry[ RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_DTS;

#define RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_PTR()	( RDD_BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE_ADDRESS )

#endif
#define RDD_US_RATE_CONTROLLER_EXPONENT_TABLE_PTR()	( RDD_US_RATE_CONTROLLER_EXPONENT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_RATE_CONTROLLER_EXPONENT_TABLE_ADDRESS )

#if defined WL4908

#define RDD_ETH2_RX_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_ETH_RX_DESCRIPTORS_DTS	entry[ RDD_ETH2_RX_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH2_RX_DESCRIPTORS_DTS;

#define RDD_ETH2_RX_DESCRIPTORS_PTR()	( RDD_ETH2_RX_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + ETH2_RX_DESCRIPTORS_ADDRESS )

#endif
#if defined WL4908

#define RDD_ETH1_RX_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_ETH_RX_DESCRIPTORS_DTS	entry[ RDD_ETH1_RX_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH1_RX_DESCRIPTORS_DTS;

#define RDD_ETH1_RX_DESCRIPTORS_PTR()	( RDD_ETH1_RX_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + ETH1_RX_DESCRIPTORS_ADDRESS )

#endif
#if defined WL4908

#define RDD_ETH0_RX_DESCRIPTORS_SIZE     32
typedef struct
{
	RDD_ETH_RX_DESCRIPTORS_DTS	entry[ RDD_ETH0_RX_DESCRIPTORS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETH0_RX_DESCRIPTORS_DTS;

#define RDD_ETH0_RX_DESCRIPTORS_PTR()	( RDD_ETH0_RX_DESCRIPTORS_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + ETH0_RX_DESCRIPTORS_ADDRESS )

#endif
/* COMMON_A */
#if defined WL4908

#define RDD_CPU_RX_RUNNER_A_SCRATCHPAD_SIZE     16
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_CPU_RX_RUNNER_A_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_RUNNER_A_SCRATCHPAD_DTS;

#define RDD_CPU_RX_RUNNER_A_SCRATCHPAD_PTR()	( RDD_CPU_RX_RUNNER_A_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + CPU_RX_RUNNER_A_SCRATCHPAD_ADDRESS )

#endif
#if defined WL4908

#define RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_SIZE     256
typedef struct
{
	RDD_SIXTEEN_BYTES_DTS	entry[ RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_DTS;

#define RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_PTR()	( RDD_SERVICE_QUEUES_DDR_CACHE_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + SERVICE_QUEUES_DDR_CACHE_FIFO_ADDRESS )

#endif
#if defined WL4908

#define RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_SIZE     8
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_DTS;

#define RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_PTR()	( RDD_FC_MCAST_RUNNER_A_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + FC_MCAST_RUNNER_A_SCRATCHPAD_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_SIZE     8
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_DS_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_DTS;

#define RDD_DS_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_PTR()	( RDD_DS_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_ADDRESS )

#endif
#if defined WL4908

#define RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_SIZE     8
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_DTS;

#define RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_PTR()	( RDD_WLAN_MCAST_RUNNER_A_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_RUNNER_A_SCRATCHPAD_ADDRESS )

#endif
#if defined WL4908

#define RDD_RUNNER_FWTRACE_MAINA_BASE_SIZE     128
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINA_BASE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINA_BASE_DTS;

#define RDD_RUNNER_FWTRACE_MAINA_BASE_PTR()	( RDD_RUNNER_FWTRACE_MAINA_BASE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RUNNER_FWTRACE_MAINA_BASE_ADDRESS )

#endif
#if defined WL4908

#define RDD_WLAN_MCAST_DHD_STATION_TABLE_SIZE     64
typedef struct
{
	RDD_WLAN_MCAST_DHD_STATION_ENTRY_DTS	entry[ RDD_WLAN_MCAST_DHD_STATION_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_DHD_STATION_TABLE_DTS;

#define RDD_WLAN_MCAST_DHD_STATION_TABLE_PTR()	( RDD_WLAN_MCAST_DHD_STATION_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_DHD_STATION_TABLE_ADDRESS )

#endif
#define RDD_DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_PTR()	( RDD_DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_ADDRESS )

#if defined WL4908

#define RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_SIZE     3
typedef struct
{
	RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY_DTS	entry[ RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_DTS;

#define RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_PTR()	( RDD_DHD_RADIO_INSTANCE_COMMON_A_DATA_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DHD_RADIO_INSTANCE_COMMON_A_DATA_ADDRESS )

#endif
#if defined WL4908

#define RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_SIZE     2
typedef struct
{
	RDD_FREE_SKB_INDEXES_FIFO_TAIL_DTS	entry[ RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_DTS;

#define RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_PTR()	( RDD_FREE_SKB_INDEXES_DDR_FIFO_TAIL_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + FREE_SKB_INDEXES_DDR_FIFO_TAIL_ADDRESS )

#endif
#if defined WL4908

#define RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_SIZE     128
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_DTS;

#define RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_PTR()	( RDD_RATE_SHAPERS_STATUS_DESCRIPTOR_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RATE_SHAPERS_STATUS_DESCRIPTOR_ADDRESS )

#endif
#if defined WL4908

#define RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_DTS;

#define RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_PTR()	( RDD_RUNNER_FWTRACE_MAINA_CURR_OFFSET_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RUNNER_FWTRACE_MAINA_CURR_OFFSET_ADDRESS )

#endif
#if defined WL4908

#define RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_SIZE     32
typedef struct
{
	RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_ENTRY_DTS	entry[ RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_DTS;

#define RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_PTR()	( RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + GPON_SKB_ENQUEUED_INDEXES_FIFO_ADDRESS )

#endif
#if defined WL4908

#define RDD_WLAN_MCAST_FWD_TABLE_SIZE     64
typedef struct
{
	RDD_WLAN_MCAST_FWD_ENTRY_DTS	entry[ RDD_WLAN_MCAST_FWD_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_FWD_TABLE_DTS;

#define RDD_WLAN_MCAST_FWD_TABLE_PTR()	( RDD_WLAN_MCAST_FWD_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_FWD_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_RUNNER_FWTRACE_PICOA_BASE_SIZE     128
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_PICOA_BASE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_PICOA_BASE_DTS;

#define RDD_RUNNER_FWTRACE_PICOA_BASE_PTR()	( RDD_RUNNER_FWTRACE_PICOA_BASE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RUNNER_FWTRACE_PICOA_BASE_ADDRESS )

#endif
#if defined WL4908

#define RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_SIZE     32
typedef struct
{
	RDD_DDR_QUEUE_DESCRIPTOR_DTS	entry[ RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_DTS;

#define RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_PTR()	( RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + SERVICE_QUEUES_DESCRIPTOR_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_SIZE     48
typedef struct
{
	RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_DTS	entry[ RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_DTS;

#define RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_PTR()	( RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_INTERRUPT_COALESCING_CONFIG_TABLE_SIZE     16
typedef struct
{
	RDD_INTERRUPT_COALESCING_CONFIG_DTS	entry[ RDD_INTERRUPT_COALESCING_CONFIG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INTERRUPT_COALESCING_CONFIG_TABLE_DTS;

#define RDD_INTERRUPT_COALESCING_CONFIG_TABLE_PTR()	( RDD_INTERRUPT_COALESCING_CONFIG_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + INTERRUPT_COALESCING_CONFIG_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_SIZE2    64
typedef struct
{
	RDD_DSCP_TO_PBITS_DEI_ENTRY_DTS	entry[ RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_DTS;

#define RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_PTR()	( RDD_GLOBAL_DSCP_TO_PBITS_DEI_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + GLOBAL_DSCP_TO_PBITS_DEI_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_WLAN_MCAST_SSID_STATS_TABLE_SIZE     48
typedef struct
{
	RDD_WLAN_MCAST_SSID_STATS_ENTRY_DTS	entry[ RDD_WLAN_MCAST_SSID_STATS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_SSID_STATS_TABLE_DTS;

#define RDD_WLAN_MCAST_SSID_STATS_TABLE_PTR()	( RDD_WLAN_MCAST_SSID_STATS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + WLAN_MCAST_SSID_STATS_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_TRACE_C_TABLE_SIZE     4
typedef struct
{
	RDD_TRACE_C_ENTRY_DTS	entry[ RDD_TRACE_C_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TRACE_C_TABLE_DTS;

#define RDD_TRACE_C_TABLE_PTR()	( RDD_TRACE_C_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + TRACE_C_TABLE_ADDRESS )

#endif
#define RDD_DS_RATE_CONTROLLER_EXPONENT_TABLE_PTR()	( RDD_DS_RATE_CONTROLLER_EXPONENT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_RATE_CONTROLLER_EXPONENT_TABLE_ADDRESS )

#if defined WL4908

#define RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_SIZE     16
typedef struct
{
	RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_DTS	entry[ RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_DTS;

#define RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_PTR()	( RDD_DS_DHD_FLOW_RING_CACHE_LKP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_DHD_FLOW_RING_CACHE_LKP_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_CONNECTION_BUFFER_TABLE_SIZE     5
#define RDD_DS_CONNECTION_BUFFER_TABLE_SIZE2    4
typedef struct
{
	RDD_CONNECTION_ENTRY_DTS	entry[ RDD_DS_CONNECTION_BUFFER_TABLE_SIZE ][ RDD_DS_CONNECTION_BUFFER_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CONNECTION_BUFFER_TABLE_DTS;

#define RDD_DS_CONNECTION_BUFFER_TABLE_PTR()	( RDD_DS_CONNECTION_BUFFER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_CONNECTION_BUFFER_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_L4_DST_PORT_TABLE_SIZE     256
typedef struct
{
	RDD_L4_DST_PORT_ENTRY_DTS	entry[ RDD_DS_L4_DST_PORT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_L4_DST_PORT_TABLE_DTS;

#define RDD_DS_L4_DST_PORT_TABLE_PTR()	( RDD_DS_L4_DST_PORT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_L4_DST_PORT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_L4_DST_PORT_CONTEXT_TABLE_SIZE     256
typedef struct
{
	RDD_L4_DST_PORT_CONTEXT_DTS	entry[ RDD_L4_DST_PORT_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_L4_DST_PORT_CONTEXT_TABLE_DTS;

#define RDD_L4_DST_PORT_CONTEXT_TABLE_PTR()	( RDD_L4_DST_PORT_CONTEXT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + L4_DST_PORT_CONTEXT_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_SIZE     16
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_DTS;

#define RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_PTR()	( RDD_DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DHD_FLOW_RING_SHADOW_WR_PTR_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DHD_TX_POST_BUFFERS_THRESHOLD_SIZE     2
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_DHD_TX_POST_BUFFERS_THRESHOLD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_BUFFERS_THRESHOLD_DTS;

#define RDD_DHD_TX_POST_BUFFERS_THRESHOLD_PTR()	( RDD_DHD_TX_POST_BUFFERS_THRESHOLD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DHD_TX_POST_BUFFERS_THRESHOLD_ADDRESS )

#endif
#if defined WL4908

#define RDD_DHD_TX_POST_BUFFERS_IN_USE_COUNTER_SIZE     2
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_DHD_TX_POST_BUFFERS_IN_USE_COUNTER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_BUFFERS_IN_USE_COUNTER_DTS;

#define RDD_DHD_TX_POST_BUFFERS_IN_USE_COUNTER_PTR()	( RDD_DHD_TX_POST_BUFFERS_IN_USE_COUNTER_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DHD_TX_POST_BUFFERS_IN_USE_COUNTER_ADDRESS )

#endif
#if defined WL4908

#define RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_SIZE     32
typedef struct
{
	RDD_DDR_QUEUE_ADDRESS_ENTRY_DTS	entry[ RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_DTS;

#define RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_PTR()	( RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_ADDRESS )

#endif
#if defined WL4908

typedef struct
{
	uint32_t	reserved0         	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_offset    	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length     	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2         	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error_type        	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_bridge_port	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_memory     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ddr_id            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	buffer_number     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETHWAN2_RX_DESCRIPTOR_DTS;

#define RDD_ETHWAN2_RX_DESCRIPTOR_PAYLOAD_OFFSET_READ(r, p)                     FIELD_MREAD_32((uint8_t *)p + 0, 13, 9, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_PAYLOAD_OFFSET_WRITE(v, p)                    FIELD_MWRITE_32((uint8_t *)p + 0, 13, 9, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 2, 0, 12, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 2, 0, 12, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_ERROR_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_ERROR_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_ERROR_TYPE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 4, 1, 4, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_ERROR_TYPE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 4, 1, 4, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_SOURCE_BRIDGE_PORT_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 4, 3, 6, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_SOURCE_BRIDGE_PORT_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 4, 3, 6, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_TARGET_MEMORY_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 5, 2, 1, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_TARGET_MEMORY_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 5, 2, 1, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_DDR_ID_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 5, 1, 1, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_DDR_ID_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 5, 1, 1, v)
#define RDD_ETHWAN2_RX_DESCRIPTOR_BUFFER_NUMBER_READ(r, p)                      MREAD_16((uint8_t *)p + 6, r)
#define RDD_ETHWAN2_RX_DESCRIPTOR_BUFFER_NUMBER_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 6, v)
#endif
#if defined WL4908

#define RDD_ETHWAN2_RX_INGRESS_QUEUE_SIZE     32
typedef struct
{
	RDD_ETHWAN2_RX_DESCRIPTOR_DTS	entry[ RDD_ETHWAN2_RX_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_ETHWAN2_RX_INGRESS_QUEUE_DTS;

#define RDD_ETHWAN2_RX_INGRESS_QUEUE_PTR()	( RDD_ETHWAN2_RX_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + ETHWAN2_RX_INGRESS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_SIZE     14
typedef struct
{
	RDD_CPU_RX_DESCRIPTOR_DTS	entry[ RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_DTS;

#define RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_PTR()	( RDD_DS_RING_PACKET_DESCRIPTORS_CACHE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_RING_PACKET_DESCRIPTORS_CACHE_ADDRESS )

#endif
#if defined WL4908

#define RDD_RING_DESCRIPTORS_TABLE_SIZE     12
typedef struct
{
	RDD_RING_DESCRIPTOR_DTS	entry[ RDD_RING_DESCRIPTORS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RING_DESCRIPTORS_TABLE_DTS;

#define RDD_RING_DESCRIPTORS_TABLE_PTR()	( RDD_RING_DESCRIPTORS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + RING_DESCRIPTORS_TABLE_ADDRESS )

#endif
#if defined WL4908

#define RDD_MAIN_A_DEBUG_TRACE_SIZE     512
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_MAIN_A_DEBUG_TRACE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_MAIN_A_DEBUG_TRACE_DTS;

#define RDD_MAIN_A_DEBUG_TRACE_PTR()	( RDD_MAIN_A_DEBUG_TRACE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + MAIN_A_DEBUG_TRACE_ADDRESS )

#endif
#if defined WL4908

#define RDD_PICO_A_DEBUG_TRACE_SIZE     512
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_PICO_A_DEBUG_TRACE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PICO_A_DEBUG_TRACE_DTS;

#define RDD_PICO_A_DEBUG_TRACE_PTR()	( RDD_PICO_A_DEBUG_TRACE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + PICO_A_DEBUG_TRACE_ADDRESS )

#endif
/* COMMON_B */
#if defined WL4908

#define RDD_WAN_TX_QUEUES_TABLE_SIZE     256
typedef struct
{
	RDD_WAN_TX_QUEUE_DESCRIPTOR_DTS	entry[ RDD_WAN_TX_QUEUES_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_TX_QUEUES_TABLE_DTS;

#define RDD_WAN_TX_QUEUES_TABLE_PTR()	( RDD_WAN_TX_QUEUES_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + WAN_TX_QUEUES_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_US_CONNECTION_BUFFER_TABLE_SIZE     5
#define RDD_US_CONNECTION_BUFFER_TABLE_SIZE2    4
typedef struct
{
	RDD_CONNECTION_ENTRY_DTS	entry[ RDD_US_CONNECTION_BUFFER_TABLE_SIZE ][ RDD_US_CONNECTION_BUFFER_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CONNECTION_BUFFER_TABLE_DTS;

#define RDD_US_CONNECTION_BUFFER_TABLE_PTR()	( RDD_US_CONNECTION_BUFFER_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_CONNECTION_BUFFER_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_IPV6_HOST_ADDRESS_CRC_TABLE_SIZE     16
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_IPV6_HOST_ADDRESS_CRC_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPV6_HOST_ADDRESS_CRC_TABLE_DTS;

#define RDD_IPV6_HOST_ADDRESS_CRC_TABLE_PTR()	( RDD_IPV6_HOST_ADDRESS_CRC_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + IPV6_HOST_ADDRESS_CRC_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_SIZE     16
typedef struct
{
	RDD_DDR_QUEUE_ADDRESS_ENTRY_DTS	entry[ RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_DTS;

#define RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_PTR()	( RDD_EPON_DDR_QUEUE_ADDRESS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + EPON_DDR_QUEUE_ADDRESS_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_SIZE     32
typedef struct
{
	RDD_BBH_RX_DESCRIPTOR_DTS	entry[ RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_DTS;

#define RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR()	( RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_RUNNER_FWTRACE_MAINB_BASE_SIZE     128
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINB_BASE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINB_BASE_DTS;

#define RDD_RUNNER_FWTRACE_MAINB_BASE_PTR()	( RDD_RUNNER_FWTRACE_MAINB_BASE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + RUNNER_FWTRACE_MAINB_BASE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_RUNNER_FWTRACE_PICOB_BASE_SIZE     128
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_PICOB_BASE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_PICOB_BASE_DTS;

#define RDD_RUNNER_FWTRACE_PICOB_BASE_PTR()	( RDD_RUNNER_FWTRACE_PICOB_BASE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + RUNNER_FWTRACE_PICOB_BASE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_US_L4_DST_PORT_TABLE_SIZE     256
typedef struct
{
	RDD_L4_DST_PORT_ENTRY_DTS	entry[ RDD_US_L4_DST_PORT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_L4_DST_PORT_TABLE_DTS;

#define RDD_US_L4_DST_PORT_TABLE_PTR()	( RDD_US_L4_DST_PORT_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_L4_DST_PORT_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_CPU_RX_RUNNER_B_SCRATCHPAD_SIZE     16
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_CPU_RX_RUNNER_B_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_RUNNER_B_SCRATCHPAD_DTS;

#define RDD_CPU_RX_RUNNER_B_SCRATCHPAD_PTR()	( RDD_CPU_RX_RUNNER_B_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + CPU_RX_RUNNER_B_SCRATCHPAD_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_EPON_DDR_CACHE_FIFO_SIZE     192
typedef struct
{
	RDD_BBH_TX_DESCRIPTOR_DTS	entry[ RDD_EPON_DDR_CACHE_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EPON_DDR_CACHE_FIFO_DTS;

#define RDD_EPON_DDR_CACHE_FIFO_PTR()	( RDD_EPON_DDR_CACHE_FIFO_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + EPON_DDR_CACHE_FIFO_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_SIZE     16
typedef struct
{
	RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_DTS	entry[ RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_DTS;

#define RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_PTR()	( RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + DHD_FLOW_RING_CACHE_CTX_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_FC_FLOW_IP_ADDRESSES_TABLE_SIZE     4
typedef struct
{
	RDD_FC_FLOW_IP_ADDRESSES_ENTRY_DTS	entry[ RDD_FC_FLOW_IP_ADDRESSES_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_FLOW_IP_ADDRESSES_TABLE_DTS;

#define RDD_FC_FLOW_IP_ADDRESSES_TABLE_PTR()	( RDD_FC_FLOW_IP_ADDRESSES_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + FC_FLOW_IP_ADDRESSES_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_SIZE     2
typedef struct
{
	RDD_EIGHT_BYTES_DTS	entry[ RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_DTS;

#define RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_PTR()	( RDD_RUNNER_FWTRACE_MAINB_CURR_OFFSET_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + RUNNER_FWTRACE_MAINB_CURR_OFFSET_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_US_RATE_CONTROLLERS_TABLE_SIZE     128
typedef struct
{
	RDD_US_RATE_CONTROLLER_DESCRIPTOR_DTS	entry[ RDD_US_RATE_CONTROLLERS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RATE_CONTROLLERS_TABLE_DTS;

#define RDD_US_RATE_CONTROLLERS_TABLE_PTR()	( RDD_US_RATE_CONTROLLERS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_RATE_CONTROLLERS_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_RUNNER_B_SCRATCHPAD_SIZE     8
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_RUNNER_B_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_B_SCRATCHPAD_DTS;

#define RDD_RUNNER_B_SCRATCHPAD_PTR()	( RDD_RUNNER_B_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + RUNNER_B_SCRATCHPAD_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_US_RING_PACKET_DESCRIPTORS_CACHE_SIZE     14
typedef struct
{
	RDD_CPU_RX_DESCRIPTOR_DTS	entry[ RDD_US_RING_PACKET_DESCRIPTORS_CACHE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RING_PACKET_DESCRIPTORS_CACHE_DTS;

#define RDD_US_RING_PACKET_DESCRIPTORS_CACHE_PTR()	( RDD_US_RING_PACKET_DESCRIPTORS_CACHE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_RING_PACKET_DESCRIPTORS_CACHE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_IPV4_HOST_ADDRESS_TABLE_SIZE     8
typedef struct
{
	RDD_FOUR_BYTES_DTS	entry[ RDD_IPV4_HOST_ADDRESS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPV4_HOST_ADDRESS_TABLE_DTS;

#define RDD_IPV4_HOST_ADDRESS_TABLE_PTR()	( RDD_IPV4_HOST_ADDRESS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + IPV4_HOST_ADDRESS_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_SIZE     3
typedef struct
{
	RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY_DTS	entry[ RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_DTS;

#define RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_PTR()	( RDD_DHD_RADIO_INSTANCE_COMMON_B_DATA_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + DHD_RADIO_INSTANCE_COMMON_B_DATA_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_MAIN_B_DEBUG_TRACE_SIZE     512
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_MAIN_B_DEBUG_TRACE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_MAIN_B_DEBUG_TRACE_DTS;

#define RDD_MAIN_B_DEBUG_TRACE_PTR()	( RDD_MAIN_B_DEBUG_TRACE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + MAIN_B_DEBUG_TRACE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_PICO_B_DEBUG_TRACE_SIZE     512
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_PICO_B_DEBUG_TRACE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PICO_B_DEBUG_TRACE_DTS;

#define RDD_PICO_B_DEBUG_TRACE_PTR()	( RDD_PICO_B_DEBUG_TRACE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + PICO_B_DEBUG_TRACE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_SIZE     16
typedef struct
{
	RDD_DDR_QUEUE_DESCRIPTOR_DTS	entry[ RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_DTS;

#define RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_PTR()	( RDD_EPON_DDR_QUEUE_DESCRIPTORS_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + EPON_DDR_QUEUE_DESCRIPTORS_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_SIZE     40
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_DTS;

#define RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_PTR()	( RDD_GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + GPON_SKB_ENQUEUED_INDEXES_FREE_PTR_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_SIZE     8
typedef struct
{
	RDD_BROADCOM_SWITCH_PORT_MAPPING_DTS	entry[ RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_DTS;

#define RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR()	( RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_SIZE     4
typedef struct
{
	RDD_ONE_BYTE_DTS	entry[ RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_DTS;

#define RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_PTR()	( RDD_CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_SIZE     40
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_DTS;

#define RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_PTR()	( RDD_GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + GPON_SKB_ENQUEUED_INDEXES_PUT_PTR_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_US_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_SIZE     8
typedef struct
{
	RDD_RUNNER_SCRATCHPAD_DTS	entry[ RDD_US_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_DTS;

#define RDD_US_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_PTR()	( RDD_US_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_ADDRESS - 0x8000 )

#endif
#define RDD_US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_PTR()	( RDD_US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE_ADDRESS - 0x8000 )

#if defined WL4908

#define RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_SIZE     16
typedef struct
{
	RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_DTS	entry[ RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_DTS;

#define RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_PTR()	( RDD_US_DHD_FLOW_RING_CACHE_LKP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_DHD_FLOW_RING_CACHE_LKP_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_WAN_ENQUEUE_INGRESS_QUEUE_SIZE     64
typedef struct
{
	RDD_INGRESS_QUEUE_ENTRY_DTS	entry[ RDD_WAN_ENQUEUE_INGRESS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WAN_ENQUEUE_INGRESS_QUEUE_DTS;

#define RDD_WAN_ENQUEUE_INGRESS_QUEUE_PTR()	( RDD_WAN_ENQUEUE_INGRESS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + WAN_ENQUEUE_INGRESS_QUEUE_ADDRESS - 0x8000 )

#endif
/* DDR */
#if defined WL4908

#define RDD_BPM_PACKET_BUFFERS_SIZE     7680
typedef struct
{
	RDD_BPM_PACKET_BUFFER_DTS	entry[ RDD_BPM_PACKET_BUFFERS_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BPM_PACKET_BUFFERS_DTS;

#endif

typedef struct
{
	uint32_t	valid                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context_index          	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bucket_overflow_counter	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	overflow               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_extend             	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	protocol               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_port               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_port               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_ip                 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_ip                 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NAT_CACHE_LKP_ENTRY_DTS;

#define RDD_NAT_CACHE_LKP_ENTRY_VALID_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_NAT_CACHE_LKP_ENTRY_VALID_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_NAT_CACHE_LKP_ENTRY_CONTEXT_INDEX_READ(r, p)                           FIELD_MREAD_16((uint8_t *)p, 0, 15, r)
#define RDD_NAT_CACHE_LKP_ENTRY_CONTEXT_INDEX_WRITE(v, p)                          FIELD_MWRITE_16((uint8_t *)p, 0, 15, v)
#define RDD_NAT_CACHE_LKP_ENTRY_BUCKET_OVERFLOW_COUNTER_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 2, 5, 3, r)
#define RDD_NAT_CACHE_LKP_ENTRY_BUCKET_OVERFLOW_COUNTER_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 2, 5, 3, v)
#define RDD_NAT_CACHE_LKP_ENTRY_OVERFLOW_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 2, 4, 1, r)
#define RDD_NAT_CACHE_LKP_ENTRY_OVERFLOW_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 2, 4, 1, v)
#define RDD_NAT_CACHE_LKP_ENTRY_KEY_EXTEND_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 2, 0, 4, r)
#define RDD_NAT_CACHE_LKP_ENTRY_KEY_EXTEND_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 2, 0, 4, v)
#define RDD_NAT_CACHE_LKP_ENTRY_PROTOCOL_READ(r, p)                                MREAD_8((uint8_t *)p + 3, r)
#define RDD_NAT_CACHE_LKP_ENTRY_PROTOCOL_WRITE(v, p)                               MWRITE_8((uint8_t *)p + 3, v)
#define RDD_NAT_CACHE_LKP_ENTRY_SRC_PORT_READ(r, p)                                MREAD_16((uint8_t *)p + 4, r)
#define RDD_NAT_CACHE_LKP_ENTRY_SRC_PORT_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 4, v)
#define RDD_NAT_CACHE_LKP_ENTRY_DST_PORT_READ(r, p)                                MREAD_16((uint8_t *)p + 6, r)
#define RDD_NAT_CACHE_LKP_ENTRY_DST_PORT_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 6, v)
#define RDD_NAT_CACHE_LKP_ENTRY_SRC_IP_READ(r, p)                                  MREAD_32((uint8_t *)p + 8, r)
#define RDD_NAT_CACHE_LKP_ENTRY_SRC_IP_WRITE(v, p)                                 MWRITE_32((uint8_t *)p + 8, v)
#define RDD_NAT_CACHE_LKP_ENTRY_DST_IP_READ(r, p)                                  MREAD_32((uint8_t *)p + 12, r)
#define RDD_NAT_CACHE_LKP_ENTRY_DST_IP_WRITE(v, p)                                 MWRITE_32((uint8_t *)p + 12, v)

typedef struct
{
	uint32_t	valid                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context_index          	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bucket_overflow_counter	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	overflow               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_extend             	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	protocol               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved               	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tos                    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_mac_crc            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_mac_crc            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NAT_CACHE_L2_LKP_ENTRY_DTS;

#define RDD_NAT_CACHE_L2_LKP_ENTRY_VALID_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_VALID_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_CONTEXT_INDEX_READ(r, p)                           FIELD_MREAD_16((uint8_t *)p, 0, 15, r)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_CONTEXT_INDEX_WRITE(v, p)                          FIELD_MWRITE_16((uint8_t *)p, 0, 15, v)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_BUCKET_OVERFLOW_COUNTER_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 2, 5, 3, r)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_BUCKET_OVERFLOW_COUNTER_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 2, 5, 3, v)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_OVERFLOW_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 2, 4, 1, r)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_OVERFLOW_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 2, 4, 1, v)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_KEY_EXTEND_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 2, 0, 4, r)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_KEY_EXTEND_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 2, 0, 4, v)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_PROTOCOL_READ(r, p)                                MREAD_8((uint8_t *)p + 3, r)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_PROTOCOL_WRITE(v, p)                               MWRITE_8((uint8_t *)p + 3, v)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_TOS_READ(r, p)                                     MREAD_8((uint8_t *)p + 7, r)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_TOS_WRITE(v, p)                                    MWRITE_8((uint8_t *)p + 7, v)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_SRC_MAC_CRC_READ(r, p)                             MREAD_32((uint8_t *)p + 8, r)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_SRC_MAC_CRC_WRITE(v, p)                            MWRITE_32((uint8_t *)p + 8, v)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_DST_MAC_CRC_READ(r, p)                             MREAD_32((uint8_t *)p + 12, r)
#define RDD_NAT_CACHE_L2_LKP_ENTRY_DST_MAC_CRC_WRITE(v, p)                            MWRITE_32((uint8_t *)p + 12, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_NUMBER	44

typedef struct
{
	uint32_t	status_0                                                                  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = status_0, size = 32 bits
	uint32_t	reserved0                                                                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	natc_hit                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                                 	:29	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	activity_status                                                           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_hits                                                                 	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	flow_bytes                                                                	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	multicast_flag                                                            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context_continuation_flag                                                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_routed                                                                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_tos_mangle                                                             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_l2_accel                                                               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mtu                                                                       	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tos                                                                       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_high_prio                                                              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_mapt_us                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_df                                                                     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue_id                                                          	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop                                                                      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_unicast_wfd_any                                                        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	priority                                                                  	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_prio                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_idx                                                                   	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_phy                                                                	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_addresses_table_index                                                  	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	link_specific_union                                                       	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	command_list[RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_NUMBER];
	uint32_t	context_continuation_table_index                                          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	command_list_remaining_length                                             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_DTS;

#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_STATUS_0_READ(r, p)                                         MREAD_32((uint8_t *)p, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_STATUS_0_WRITE(v, p)                                        MWRITE_32((uint8_t *)p, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_NATC_HIT_READ(r, p)                                         FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_NATC_HIT_WRITE(v, p)                                        FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_ACTIVITY_STATUS_READ(r, p)                                  MREAD_8((uint8_t *)p, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_ACTIVITY_STATUS_WRITE(v, p)                                 MWRITE_8((uint8_t *)p, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_FLOW_HITS_READ(r, p)                                        FIELD_MREAD_32((uint8_t *)p + 0, 0, 24, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_FLOW_HITS_WRITE(v, p)                                       FIELD_MWRITE_32((uint8_t *)p + 0, 0, 24, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_FLOW_BYTES_READ(r, p)                                       MREAD_32((uint8_t *)p + 4, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_FLOW_BYTES_WRITE(v, p)                                      MWRITE_32((uint8_t *)p + 4, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_MULTICAST_FLAG_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p + 8, 7, 1, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_MULTICAST_FLAG_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p + 8, 7, 1, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_CONTEXT_CONTINUATION_FLAG_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 8, 6, 1, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_CONTEXT_CONTINUATION_FLAG_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 8, 6, 1, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_ROUTED_READ(r, p)                                        FIELD_MREAD_8((uint8_t *)p + 8, 5, 1, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_ROUTED_WRITE(v, p)                                       FIELD_MWRITE_8((uint8_t *)p + 8, 5, 1, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_TOS_MANGLE_READ(r, p)                                    FIELD_MREAD_8((uint8_t *)p + 8, 4, 1, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_TOS_MANGLE_WRITE(v, p)                                   FIELD_MWRITE_8((uint8_t *)p + 8, 4, 1, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_L2_ACCEL_READ(r, p)                                      FIELD_MREAD_8((uint8_t *)p + 8, 3, 1, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_L2_ACCEL_WRITE(v, p)                                     FIELD_MWRITE_8((uint8_t *)p + 8, 3, 1, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_MTU_READ(r, p)                                              FIELD_MREAD_16((uint8_t *)p + 8, 0, 11, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_MTU_WRITE(v, p)                                             FIELD_MWRITE_16((uint8_t *)p + 8, 0, 11, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_TOS_READ(r, p)                                              MREAD_8((uint8_t *)p + 10, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_TOS_WRITE(v, p)                                             MWRITE_8((uint8_t *)p + 10, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_HIGH_PRIO_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 11, 7, 1, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_HIGH_PRIO_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 11, 7, 1, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_MAPT_US_READ(r, p)                                       FIELD_MREAD_8((uint8_t *)p + 11, 6, 1, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_MAPT_US_WRITE(v, p)                                      FIELD_MWRITE_8((uint8_t *)p + 11, 6, 1, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_DF_READ(r, p)                                            FIELD_MREAD_8((uint8_t *)p + 11, 5, 1, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_DF_WRITE(v, p)                                           FIELD_MWRITE_8((uint8_t *)p + 11, 5, 1, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_SERVICE_QUEUE_ID_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 11, 0, 5, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_SERVICE_QUEUE_ID_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 11, 0, 5, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_DROP_READ(r, p)                                             FIELD_MREAD_8((uint8_t *)p + 12, 7, 1, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_DROP_WRITE(v, p)                                            FIELD_MWRITE_8((uint8_t *)p + 12, 7, 1, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_UNICAST_WFD_ANY_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 12, 6, 1, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IS_UNICAST_WFD_ANY_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 12, 6, 1, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_PRIORITY_READ(r, p)                                         FIELD_MREAD_8((uint8_t *)p + 12, 2, 4, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_PRIORITY_WRITE(v, p)                                        FIELD_MWRITE_8((uint8_t *)p + 12, 2, 4, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_WFD_PRIO_READ(r, p)                                         FIELD_MREAD_8((uint8_t *)p + 12, 1, 1, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_WFD_PRIO_WRITE(v, p)                                        FIELD_MWRITE_8((uint8_t *)p + 12, 1, 1, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_WFD_IDX_READ(r, p)                                          FIELD_MREAD_16((uint8_t *)p + 12, 7, 2, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_WFD_IDX_WRITE(v, p)                                         FIELD_MWRITE_16((uint8_t *)p + 12, 7, 2, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_EGRESS_PHY_READ(r, p)                                       FIELD_MREAD_8((uint8_t *)p + 13, 5, 2, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_EGRESS_PHY_WRITE(v, p)                                      FIELD_MWRITE_8((uint8_t *)p + 13, 5, 2, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IP_ADDRESSES_TABLE_INDEX_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 13, 2, 3, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_IP_ADDRESSES_TABLE_INDEX_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 13, 2, 3, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_LINK_SPECIFIC_UNION_READ(r, p)                              FIELD_MREAD_32((uint8_t *)p + 12, 0, 18, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_LINK_SPECIFIC_UNION_WRITE(v, p)                             FIELD_MWRITE_32((uint8_t *)p + 12, 0, 18, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_READ(r, p, i)                                  MREAD_I_8((uint8_t *)p + 16, i, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_WRITE(v, p, i)                                 MWRITE_I_8((uint8_t *)p + 16, i, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_CONTEXT_CONTINUATION_TABLE_INDEX_READ(r, p)                 MREAD_16((uint8_t *)p + 60, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_CONTEXT_CONTINUATION_TABLE_INDEX_WRITE(v, p)                MWRITE_16((uint8_t *)p + 60, v)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_REMAINING_LENGTH_READ(r, p)                    MREAD_16((uint8_t *)p + 62, r)
#define RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_REMAINING_LENGTH_WRITE(v, p)                   MWRITE_16((uint8_t *)p + 62, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_NUMBER	44

typedef struct
{
	uint32_t	status_0                                                                     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = status_0, size = 32 bits
	uint32_t	reserved0                                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	natc_hit                                                                     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                                    	:29	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	activity_status                                                              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_hits                                                                    	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	flow_bytes                                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	multicast_flag                                                               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context_continuation_flag                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_routed                                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_tos_mangle                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_l2_accel                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mtu                                                                          	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tos                                                                          	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_high_prio                                                                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                                                                    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue_id                                                             	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop                                                                         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_unicast_wfd_any                                                           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	priority                                                                     	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_prio                                                                     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wfd_idx                                                                      	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_phy                                                                   	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_addresses_table_index                                                     	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	link_specific_union                                                          	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	command_list[RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_NUMBER];
	uint32_t	context_continuation_table_index                                             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	command_list_remaining_length                                                	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_DTS;

#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_STATUS_0_READ(r, p)                                         MREAD_32((uint8_t *)p, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_STATUS_0_WRITE(v, p)                                        MWRITE_32((uint8_t *)p, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_NATC_HIT_READ(r, p)                                         FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_NATC_HIT_WRITE(v, p)                                        FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_ACTIVITY_STATUS_READ(r, p)                                  MREAD_8((uint8_t *)p, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_ACTIVITY_STATUS_WRITE(v, p)                                 MWRITE_8((uint8_t *)p, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_FLOW_HITS_READ(r, p)                                        FIELD_MREAD_32((uint8_t *)p + 0, 0, 24, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_FLOW_HITS_WRITE(v, p)                                       FIELD_MWRITE_32((uint8_t *)p + 0, 0, 24, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_FLOW_BYTES_READ(r, p)                                       MREAD_32((uint8_t *)p + 4, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_FLOW_BYTES_WRITE(v, p)                                      MWRITE_32((uint8_t *)p + 4, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_MULTICAST_FLAG_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p + 8, 7, 1, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_MULTICAST_FLAG_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p + 8, 7, 1, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_CONTEXT_CONTINUATION_FLAG_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 8, 6, 1, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_CONTEXT_CONTINUATION_FLAG_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 8, 6, 1, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_ROUTED_READ(r, p)                                        FIELD_MREAD_8((uint8_t *)p + 8, 5, 1, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_ROUTED_WRITE(v, p)                                       FIELD_MWRITE_8((uint8_t *)p + 8, 5, 1, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_TOS_MANGLE_READ(r, p)                                    FIELD_MREAD_8((uint8_t *)p + 8, 4, 1, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_TOS_MANGLE_WRITE(v, p)                                   FIELD_MWRITE_8((uint8_t *)p + 8, 4, 1, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_L2_ACCEL_READ(r, p)                                      FIELD_MREAD_8((uint8_t *)p + 8, 3, 1, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_L2_ACCEL_WRITE(v, p)                                     FIELD_MWRITE_8((uint8_t *)p + 8, 3, 1, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_MTU_READ(r, p)                                              FIELD_MREAD_16((uint8_t *)p + 8, 0, 11, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_MTU_WRITE(v, p)                                             FIELD_MWRITE_16((uint8_t *)p + 8, 0, 11, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_TOS_READ(r, p)                                              MREAD_8((uint8_t *)p + 10, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_TOS_WRITE(v, p)                                             MWRITE_8((uint8_t *)p + 10, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_HIGH_PRIO_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 11, 7, 1, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_HIGH_PRIO_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 11, 7, 1, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_SERVICE_QUEUE_ID_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 11, 0, 5, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_SERVICE_QUEUE_ID_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 11, 0, 5, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_DROP_READ(r, p)                                             FIELD_MREAD_8((uint8_t *)p + 12, 7, 1, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_DROP_WRITE(v, p)                                            FIELD_MWRITE_8((uint8_t *)p + 12, 7, 1, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_UNICAST_WFD_ANY_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 12, 6, 1, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_IS_UNICAST_WFD_ANY_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 12, 6, 1, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_PRIORITY_READ(r, p)                                         FIELD_MREAD_8((uint8_t *)p + 12, 2, 4, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_PRIORITY_WRITE(v, p)                                        FIELD_MWRITE_8((uint8_t *)p + 12, 2, 4, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_WFD_PRIO_READ(r, p)                                         FIELD_MREAD_8((uint8_t *)p + 12, 1, 1, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_WFD_PRIO_WRITE(v, p)                                        FIELD_MWRITE_8((uint8_t *)p + 12, 1, 1, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_WFD_IDX_READ(r, p)                                          FIELD_MREAD_16((uint8_t *)p + 12, 7, 2, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_WFD_IDX_WRITE(v, p)                                         FIELD_MWRITE_16((uint8_t *)p + 12, 7, 2, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_EGRESS_PHY_READ(r, p)                                       FIELD_MREAD_8((uint8_t *)p + 13, 5, 2, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_EGRESS_PHY_WRITE(v, p)                                      FIELD_MWRITE_8((uint8_t *)p + 13, 5, 2, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_IP_ADDRESSES_TABLE_INDEX_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 13, 2, 3, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_IP_ADDRESSES_TABLE_INDEX_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 13, 2, 3, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_LINK_SPECIFIC_UNION_READ(r, p)                              FIELD_MREAD_32((uint8_t *)p + 12, 0, 18, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_LINK_SPECIFIC_UNION_WRITE(v, p)                             FIELD_MWRITE_32((uint8_t *)p + 12, 0, 18, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_READ(r, p, i)                                  MREAD_I_8((uint8_t *)p + 16, i, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_WRITE(v, p, i)                                 MWRITE_I_8((uint8_t *)p + 16, i, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_CONTEXT_CONTINUATION_TABLE_INDEX_READ(r, p)                 MREAD_16((uint8_t *)p + 60, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_CONTEXT_CONTINUATION_TABLE_INDEX_WRITE(v, p)                MWRITE_16((uint8_t *)p + 60, v)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_REMAINING_LENGTH_READ(r, p)                    MREAD_16((uint8_t *)p + 62, r)
#define RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_REMAINING_LENGTH_WRITE(v, p)                   MWRITE_16((uint8_t *)p + 62, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_PORT_CONTEXT_NUMBER	8
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_L3_COMMAND_LIST_NUMBER	8

typedef struct
{
	uint32_t	flow_hits                                                                      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_bytes                                                                     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	multicast_flag                                                                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context_continuation_flag                                                      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_routed                                                                      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_tos_mangle                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	number_of_ports                                                                	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	port_mask                                                                      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                                                                      	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mtu                                                                            	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tos                                                                            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                                                                      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wlan_mcast_clients                                                             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wlan_mcast_index                                                               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mcast_port_header_buffer_ptr                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	port_context[RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_PORT_CONTEXT_NUMBER];
	uint8_t	l3_command_list[RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_L3_COMMAND_LIST_NUMBER];
	uint32_t	context_continuation_table_index                                               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	command_list_remaining_length                                                  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_DTS;

#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_FLOW_HITS_READ(r, p)                                        MREAD_32((uint8_t *)p, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_FLOW_HITS_WRITE(v, p)                                       MWRITE_32((uint8_t *)p, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_FLOW_BYTES_READ(r, p)                                       MREAD_32((uint8_t *)p + 4, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_FLOW_BYTES_WRITE(v, p)                                      MWRITE_32((uint8_t *)p + 4, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_MULTICAST_FLAG_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p + 8, 7, 1, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_MULTICAST_FLAG_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p + 8, 7, 1, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_CONTEXT_CONTINUATION_FLAG_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 8, 6, 1, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_CONTEXT_CONTINUATION_FLAG_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 8, 6, 1, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_IS_ROUTED_READ(r, p)                                        FIELD_MREAD_8((uint8_t *)p + 8, 5, 1, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_IS_ROUTED_WRITE(v, p)                                       FIELD_MWRITE_8((uint8_t *)p + 8, 5, 1, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_IS_TOS_MANGLE_READ(r, p)                                    FIELD_MREAD_8((uint8_t *)p + 8, 4, 1, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_IS_TOS_MANGLE_WRITE(v, p)                                   FIELD_MWRITE_8((uint8_t *)p + 8, 4, 1, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_NUMBER_OF_PORTS_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 8, 0, 4, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_NUMBER_OF_PORTS_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 8, 0, 4, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_PORT_MASK_READ(r, p)                                        MREAD_8((uint8_t *)p + 9, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_PORT_MASK_WRITE(v, p)                                       MWRITE_8((uint8_t *)p + 9, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_MTU_READ(r, p)                                              FIELD_MREAD_16((uint8_t *)p + 10, 0, 11, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_MTU_WRITE(v, p)                                             FIELD_MWRITE_16((uint8_t *)p + 10, 0, 11, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_TOS_READ(r, p)                                              MREAD_8((uint8_t *)p + 12, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_TOS_WRITE(v, p)                                             MWRITE_8((uint8_t *)p + 12, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_WLAN_MCAST_CLIENTS_READ(r, p)                               MREAD_8((uint8_t *)p + 14, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_WLAN_MCAST_CLIENTS_WRITE(v, p)                              MWRITE_8((uint8_t *)p + 14, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_WLAN_MCAST_INDEX_READ(r, p)                                 MREAD_8((uint8_t *)p + 15, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_WLAN_MCAST_INDEX_WRITE(v, p)                                MWRITE_8((uint8_t *)p + 15, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_MCAST_PORT_HEADER_BUFFER_PTR_READ(r, p)                     MREAD_32((uint8_t *)p + 16, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_MCAST_PORT_HEADER_BUFFER_PTR_WRITE(v, p)                    MWRITE_32((uint8_t *)p + 16, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_PORT_CONTEXT_READ(r, p, i)                                  MREAD_I_32((uint8_t *)p + 20, i, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_PORT_CONTEXT_WRITE(v, p, i)                                 MWRITE_I_32((uint8_t *)p + 20, i, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_L3_COMMAND_LIST_READ(r, p, i)                               MREAD_I_8((uint8_t *)p + 52, i, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_L3_COMMAND_LIST_WRITE(v, p, i)                              MWRITE_I_8((uint8_t *)p + 52, i, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_CONTEXT_CONTINUATION_TABLE_INDEX_READ(r, p)                 MREAD_16((uint8_t *)p + 60, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_CONTEXT_CONTINUATION_TABLE_INDEX_WRITE(v, p)                MWRITE_16((uint8_t *)p + 60, v)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_REMAINING_LENGTH_READ(r, p)                    MREAD_16((uint8_t *)p + 62, r)
#define RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_COMMAND_LIST_REMAINING_LENGTH_WRITE(v, p)                   MWRITE_16((uint8_t *)p + 62, v)
#if defined WL4908
#define RDD_CONTEXT_CONTINUATION_ENTRY_COMMAND_LIST_NUMBER	68

typedef struct
{
	uint32_t	valid                                                               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	overflow                                                            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	connection_direction                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_unicast_wfd_nic                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                           	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	connection_table_index                                              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                                                           	:17	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_index                                                          	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	command_list[RDD_CONTEXT_CONTINUATION_ENTRY_COMMAND_LIST_NUMBER];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CONTEXT_CONTINUATION_ENTRY_DTS;

#define RDD_CONTEXT_CONTINUATION_ENTRY_VALID_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_CONTEXT_CONTINUATION_ENTRY_VALID_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_CONTEXT_CONTINUATION_ENTRY_OVERFLOW_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_CONTEXT_CONTINUATION_ENTRY_OVERFLOW_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_CONTEXT_CONTINUATION_ENTRY_CONNECTION_DIRECTION_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_CONTEXT_CONTINUATION_ENTRY_CONNECTION_DIRECTION_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_CONTEXT_CONTINUATION_ENTRY_IS_UNICAST_WFD_NIC_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p, 4, 1, r)
#define RDD_CONTEXT_CONTINUATION_ENTRY_IS_UNICAST_WFD_NIC_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p, 4, 1, v)
#define RDD_CONTEXT_CONTINUATION_ENTRY_CONNECTION_TABLE_INDEX_READ(r, p)                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_CONTEXT_CONTINUATION_ENTRY_CONNECTION_TABLE_INDEX_WRITE(v, p)                MWRITE_16((uint8_t *)p + 2, v)
#define RDD_CONTEXT_CONTINUATION_ENTRY_FLOW_INDEX_READ(r, p)                             FIELD_MREAD_16((uint8_t *)p + 6, 0, 15, r)
#define RDD_CONTEXT_CONTINUATION_ENTRY_FLOW_INDEX_WRITE(v, p)                            FIELD_MWRITE_16((uint8_t *)p + 6, 0, 15, v)
#define RDD_CONTEXT_CONTINUATION_ENTRY_COMMAND_LIST_READ(r, p, i)                        MREAD_I_8((uint8_t *)p + 8, i, r)
#define RDD_CONTEXT_CONTINUATION_ENTRY_COMMAND_LIST_WRITE(v, p, i)                       MWRITE_I_8((uint8_t *)p + 8, i, v)
#endif
#if defined WL4908

#define RDD_CONTEXT_CONTINUATION_TABLE_SIZE     65536
typedef struct
{
	RDD_CONTEXT_CONTINUATION_ENTRY_DTS	entry[ RDD_CONTEXT_CONTINUATION_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CONTEXT_CONTINUATION_TABLE_DTS;

#endif
#if defined WL4908

#define RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE_SIZE     8
typedef struct
{
	RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_DTS	entry[ RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE_DTS;

#endif
#if defined WL4908

#define RDD_DHD_RX_POST_DDR_BUFFER_SIZE     1024
typedef struct
{
	RDD_DHD_RX_POST_DESCRIPTOR_DTS	entry[ RDD_DHD_RX_POST_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_POST_DDR_BUFFER_DTS;

#endif
#if defined WL4908

#define RDD_DHD_RX_COMPLETE_DDR_BUFFER_SIZE     1024
typedef struct
{
	RDD_DHD_RX_COMPLETE_DESCRIPTOR_DTS	entry[ RDD_DHD_RX_COMPLETE_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_COMPLETE_DDR_BUFFER_DTS;

#endif
#if defined WL4908

#define RDD_DHD_TX_POST_DDR_BUFFER_SIZE     8
#define RDD_DHD_TX_POST_DDR_BUFFER_SIZE2    16
typedef struct
{
	RDD_DHD_TX_POST_DESCRIPTOR_DTS	entry[ RDD_DHD_TX_POST_DDR_BUFFER_SIZE ][ RDD_DHD_TX_POST_DDR_BUFFER_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_POST_DDR_BUFFER_DTS;

#endif
#if defined WL4908

#define RDD_DHD_TX_COMPLETE_DDR_BUFFER_SIZE     16
typedef struct
{
	RDD_DHD_TX_COMPLETE_DESCRIPTOR_DTS	entry[ RDD_DHD_TX_COMPLETE_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_TX_COMPLETE_DDR_BUFFER_DTS;

#endif
#if defined WL4908

#define RDD_R2D_WR_ARR_DDR_BUFFER_SIZE     128
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_R2D_WR_ARR_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_R2D_WR_ARR_DDR_BUFFER_DTS;

#endif
#if defined WL4908

#define RDD_D2R_RD_ARR_DDR_BUFFER_SIZE     128
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_D2R_RD_ARR_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_D2R_RD_ARR_DDR_BUFFER_DTS;

#endif
#if defined WL4908

#define RDD_R2D_RD_ARR_DDR_BUFFER_SIZE     128
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_R2D_RD_ARR_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_R2D_RD_ARR_DDR_BUFFER_DTS;

#endif
#if defined WL4908

#define RDD_D2R_WR_ARR_DDR_BUFFER_SIZE     128
typedef struct
{
	RDD_TWO_BYTES_DTS	entry[ RDD_D2R_WR_ARR_DDR_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_D2R_WR_ARR_DDR_BUFFER_DTS;

#endif
#if defined WL4908

#define RDD_WLAN_MCAST_DHD_LIST_TABLE_SIZE     64
typedef struct
{
	RDD_WLAN_MCAST_DHD_LIST_ENTRY_ARRAY_DTS	entry[ RDD_WLAN_MCAST_DHD_LIST_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_WLAN_MCAST_DHD_LIST_TABLE_DTS;

#endif
/* PSRAM */
#if defined DSL_63138 || defined DSL_63148 || defined WL4908

typedef union
{
	RDD_BBH_TX_DESCRIPTOR_DTS        bbh_tx_descriptor;
	RDD_PACKET_DESCRIPTOR_DTS        packet_descriptor;
	RDD_SERVICE_QUEUE_DESCRIPTOR_DTS service_queue_descriptor;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PACKET_DESCRIPTOR_UNION_DTS;

#endif
#if defined DSL_63138

#define RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_SIZE     2048
typedef struct
{
	RDD_DS_PACKET_DESCRIPTOR_UNION_DTS	entry[ RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_DTS;

#define RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_PTR()	( RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FREE_PACKET_DESCRIPTORS_POOL_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_SIZE     2048
typedef struct
{
	RDD_DS_PACKET_DESCRIPTOR_UNION_DTS	entry[ RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_DTS;

#define RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_PTR()	( RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FREE_PACKET_DESCRIPTORS_POOL_ADDRESS )

#endif
#if defined WL4908

#define RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_SIZE     2048
typedef struct
{
	RDD_DS_PACKET_DESCRIPTOR_UNION_DTS	entry[ RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_DTS;

#define RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_PTR()	( RDD_DS_FREE_PACKET_DESCRIPTORS_POOL_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FREE_PACKET_DESCRIPTORS_POOL_ADDRESS )

#endif
#if defined DSL_63138 || defined DSL_63148 || defined WL4908

typedef union
{
	RDD_CPU_TX_DESCRIPTOR_DS_FAST_DTS      cpu_tx_descriptor_ds_fast;
	RDD_CPU_TX_MESSAGE_DESCRIPTOR_DTS      cpu_tx_message_descriptor;
	RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI_DTS cpu_tx_descriptor_ds_pico_wifi;
	RDD_CPU_TX_DESCRIPTOR_ABS_DTS          cpu_tx_descriptor_abs;
	RDD_CPU_TX_DESCRIPTOR_CORE_DTS         cpu_tx_descriptor_core;
	RDD_CPU_TX_DESCRIPTOR_US_FAST_DTS      cpu_tx_descriptor_us_fast;
	RDD_CPU_TX_DESCRIPTOR_DS_PICO_DTS      cpu_tx_descriptor_ds_pico;
	RDD_CPU_TX_DESCRIPTOR_BPM_DTS          cpu_tx_descriptor_bpm;
	RDD_CPU_TX_DESCRIPTOR_DTS              cpu_tx_descriptor;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_PICO_DESCRIPTOR_UNION_DTS;

#endif
#if defined DSL_63138

#define RDD_GSO_PICO_QUEUE_SIZE     64
typedef struct
{
	RDD_GSO_PICO_DESCRIPTOR_UNION_DTS	entry[ RDD_GSO_PICO_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_PICO_QUEUE_DTS;

#define RDD_GSO_PICO_QUEUE_PTR()	( RDD_GSO_PICO_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GSO_PICO_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_GSO_PICO_QUEUE_SIZE     64
typedef struct
{
	RDD_GSO_PICO_DESCRIPTOR_UNION_DTS	entry[ RDD_GSO_PICO_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_PICO_QUEUE_DTS;

#define RDD_GSO_PICO_QUEUE_PTR()	( RDD_GSO_PICO_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GSO_PICO_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_GSO_PICO_QUEUE_SIZE     64
typedef struct
{
	RDD_GSO_PICO_DESCRIPTOR_UNION_DTS	entry[ RDD_GSO_PICO_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GSO_PICO_QUEUE_DTS;

#define RDD_GSO_PICO_QUEUE_PTR()	( RDD_GSO_PICO_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + GSO_PICO_QUEUE_ADDRESS )

#endif
#if defined DSL_63138 || defined DSL_63148 || defined WL4908

typedef union
{
	RDD_CPU_TX_DESCRIPTOR_DS_FAST_DTS                      cpu_tx_descriptor_ds_fast;
	RDD_CPU_TX_MESSAGE_DESCRIPTOR_DTS                      cpu_tx_message_descriptor;
	RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI_DTS                 cpu_tx_descriptor_ds_pico_wifi;
	RDD_CPU_TX_DESCRIPTOR_ABS_DTS                          cpu_tx_descriptor_abs;
	RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR_DTS cpu_tx_update_pd_pool_quota_message_descriptor;
	RDD_CPU_TX_DESCRIPTOR_CORE_DTS                         cpu_tx_descriptor_core;
	RDD_CPU_TX_DESCRIPTOR_US_FAST_DTS                      cpu_tx_descriptor_us_fast;
	RDD_CPU_TX_DHD_DESCRIPTOR_DTS                          cpu_tx_dhd_descriptor;
	RDD_CPU_TX_DESCRIPTOR_DS_PICO_DTS                      cpu_tx_descriptor_ds_pico;
	RDD_CPU_TX_DESCRIPTOR_BPM_DTS                          cpu_tx_descriptor_bpm;
	RDD_CPU_TX_DESCRIPTOR_DTS                              cpu_tx_descriptor;
	RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR_DTS                  cpu_tx_dhd_message_descriptor;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_PICO_DESCRIPTOR_UNION_DTS;

#endif
#if defined DSL_63138

#define RDD_CPU_TX_PICO_QUEUE_SIZE     16
typedef struct
{
	RDD_CPU_TX_PICO_DESCRIPTOR_UNION_DTS	entry[ RDD_CPU_TX_PICO_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_PICO_QUEUE_DTS;

#define RDD_CPU_TX_PICO_QUEUE_PTR()	( RDD_CPU_TX_PICO_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_TX_PICO_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_CPU_TX_PICO_QUEUE_SIZE     16
typedef struct
{
	RDD_CPU_TX_PICO_DESCRIPTOR_UNION_DTS	entry[ RDD_US_CPU_TX_PICO_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_TX_PICO_QUEUE_DTS;

#define RDD_US_CPU_TX_PICO_QUEUE_PTR()	( RDD_US_CPU_TX_PICO_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_TX_PICO_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_CPU_TX_PICO_QUEUE_SIZE     16
typedef struct
{
	RDD_CPU_TX_PICO_DESCRIPTOR_UNION_DTS	entry[ RDD_CPU_TX_PICO_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_PICO_QUEUE_DTS;

#define RDD_CPU_TX_PICO_QUEUE_PTR()	( RDD_CPU_TX_PICO_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_TX_PICO_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_CPU_TX_PICO_QUEUE_SIZE     16
typedef struct
{
	RDD_CPU_TX_PICO_DESCRIPTOR_UNION_DTS	entry[ RDD_US_CPU_TX_PICO_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_TX_PICO_QUEUE_DTS;

#define RDD_US_CPU_TX_PICO_QUEUE_PTR()	( RDD_US_CPU_TX_PICO_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_TX_PICO_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_CPU_TX_PICO_QUEUE_SIZE     16
typedef struct
{
	RDD_CPU_TX_PICO_DESCRIPTOR_UNION_DTS	entry[ RDD_CPU_TX_PICO_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_PICO_QUEUE_DTS;

#define RDD_CPU_TX_PICO_QUEUE_PTR()	( RDD_CPU_TX_PICO_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_TX_PICO_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_CPU_TX_PICO_QUEUE_SIZE     16
typedef struct
{
	RDD_CPU_TX_PICO_DESCRIPTOR_UNION_DTS	entry[ RDD_US_CPU_TX_PICO_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_TX_PICO_QUEUE_DTS;

#define RDD_US_CPU_TX_PICO_QUEUE_PTR()	( RDD_US_CPU_TX_PICO_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_TX_PICO_QUEUE_ADDRESS )

#endif
#if defined DSL_63138 || defined DSL_63148 || defined WL4908

typedef union
{
	RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_DTS        ingress_classification_short_lookup_entry;
	RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_DTS        ds_ingress_classification_ih_lookup_entry;
	RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_DTS ds_ingress_classification_optimized_lookup_entry;
	RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_DTS us_ingress_classification_optimized_lookup_entry;
	RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_DTS        us_ingress_classification_ih_lookup_entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_CLASSIFICATION_LOOKUP_UNION_DTS;

#endif
#if defined DSL_63138

#define RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_SIZE     256
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_LOOKUP_UNION_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_SIZE     256
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_LOOKUP_UNION_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_SIZE     256
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_LOOKUP_UNION_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_SIZE     256
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_LOOKUP_UNION_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_SIZE     256
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_LOOKUP_UNION_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_SIZE     256
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_LOOKUP_UNION_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_INGRESS_CLASSIFICATION_LOOKUP_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

typedef union
{
	RDD_NAT_CACHE_LKP_ENTRY_DTS    nat_cache_lkp_entry;
	RDD_NAT_CACHE_L2_LKP_ENTRY_DTS nat_cache_l2_lkp_entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NAT_CACHE_LKUP_EXTENSION_ENTRY_UNION_DTS;

#endif
#if defined WL4908

#define RDD_NAT_CACHE_EXTENSION_TABLE_SIZE     7
typedef struct
{
	RDD_NAT_CACHE_LKUP_EXTENSION_ENTRY_UNION_DTS	entry[ RDD_NAT_CACHE_EXTENSION_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NAT_CACHE_EXTENSION_TABLE_DTS;

#endif
#if defined DSL_63138 || defined DSL_63148 || defined WL4908

typedef union
{
	RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY_DTS        ingress_classification_short_lookup_entry;
	RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_DTS        ds_ingress_classification_ih_lookup_entry;
	RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_DTS ds_ingress_classification_optimized_lookup_entry;
	RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY_DTS us_ingress_classification_optimized_lookup_entry;
	RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY_DTS        us_ingress_classification_ih_lookup_entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_CLASSIFICATION_LOOKUP_CAM_UNION_DTS;

#endif
#if defined DSL_63138

#define RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_SIZE     32
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_LOOKUP_CAM_UNION_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138

#define RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_SIZE     32
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_LOOKUP_CAM_UNION_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_SIZE     32
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_LOOKUP_CAM_UNION_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63148

#define RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_SIZE     32
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_LOOKUP_CAM_UNION_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_SIZE     32
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_LOOKUP_CAM_UNION_DTS	entry[ RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_DTS;

#define RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_PTR()	( RDD_DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_ADDRESS - 0x8000 )

#endif
#if defined WL4908

#define RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_SIZE     32
typedef struct
{
	RDD_INGRESS_CLASSIFICATION_LOOKUP_CAM_UNION_DTS	entry[ RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_DTS;

#define RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_PTR()	( RDD_US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE_ADDRESS - 0x8000 )

#endif
#if defined DSL_63138 || defined DSL_63148 || defined WL4908

typedef union
{
	RDD_DHD_RX_COMPLETE_DESCRIPTOR_DTS dhd_rx_complete_descriptor;
	RDD_DHD_RX_POST_DESCRIPTOR_DTS     dhd_rx_post_descriptor;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_FLOW_RING_BUFFER_UNION_DTS;

#endif
#if defined DSL_63138

#define RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_FLOW_RING_BUFFER_UNION_DTS	entry[ RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_DTS;

#define RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_PTR()	( RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DHD_RX_COMPLETE_FLOW_RING_BUFFER_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_DHD_RX_POST_FLOW_RING_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_FLOW_RING_BUFFER_UNION_DTS	entry[ RDD_DHD_RX_POST_FLOW_RING_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_POST_FLOW_RING_BUFFER_DTS;

#define RDD_DHD_RX_POST_FLOW_RING_BUFFER_PTR()	( RDD_DHD_RX_POST_FLOW_RING_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DHD_RX_POST_FLOW_RING_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_FLOW_RING_BUFFER_UNION_DTS	entry[ RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_DTS;

#define RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_PTR()	( RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DHD_RX_COMPLETE_FLOW_RING_BUFFER_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_DHD_RX_POST_FLOW_RING_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_FLOW_RING_BUFFER_UNION_DTS	entry[ RDD_DHD_RX_POST_FLOW_RING_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_POST_FLOW_RING_BUFFER_DTS;

#define RDD_DHD_RX_POST_FLOW_RING_BUFFER_PTR()	( RDD_DHD_RX_POST_FLOW_RING_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DHD_RX_POST_FLOW_RING_BUFFER_ADDRESS )

#endif
#if defined WL4908

#define RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_FLOW_RING_BUFFER_UNION_DTS	entry[ RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_DTS;

#define RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_PTR()	( RDD_DHD_RX_COMPLETE_FLOW_RING_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DHD_RX_COMPLETE_FLOW_RING_BUFFER_ADDRESS )

#endif
#if defined WL4908

#define RDD_DHD_RX_POST_FLOW_RING_BUFFER_SIZE     3
typedef struct
{
	RDD_DHD_FLOW_RING_BUFFER_UNION_DTS	entry[ RDD_DHD_RX_POST_FLOW_RING_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DHD_RX_POST_FLOW_RING_BUFFER_DTS;

#define RDD_DHD_RX_POST_FLOW_RING_BUFFER_PTR()	( RDD_DHD_RX_POST_FLOW_RING_BUFFER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + DHD_RX_POST_FLOW_RING_BUFFER_ADDRESS )

#endif
#if defined DSL_63138 || defined DSL_63148 || defined WL4908

typedef union
{
	RDD_BBH_TX_DESCRIPTOR_DTS bbh_tx_descriptor;
	RDD_PACKET_DESCRIPTOR_DTS packet_descriptor;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_PACKET_DESCRIPTOR_UNION_DTS;

#endif
#if defined DSL_63138

#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_SIZE     3072
typedef struct
{
	RDD_US_PACKET_DESCRIPTOR_UNION_DTS	entry[ RDD_US_FREE_PACKET_DESCRIPTORS_POOL_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DTS;

#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_PTR()	( RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FREE_PACKET_DESCRIPTORS_POOL_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_SIZE     3072
typedef struct
{
	RDD_US_PACKET_DESCRIPTOR_UNION_DTS	entry[ RDD_US_FREE_PACKET_DESCRIPTORS_POOL_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DTS;

#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_PTR()	( RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FREE_PACKET_DESCRIPTORS_POOL_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_SIZE     3072
typedef struct
{
	RDD_US_PACKET_DESCRIPTOR_UNION_DTS	entry[ RDD_US_FREE_PACKET_DESCRIPTORS_POOL_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DTS;

#define RDD_US_FREE_PACKET_DESCRIPTORS_POOL_PTR()	( RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FREE_PACKET_DESCRIPTORS_POOL_ADDRESS )

#endif
#if defined WL4908

typedef union
{
	RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY_DTS fc_natc_l2_ucast_flow_context_entry;
	RDD_FC_UCAST_FLOW_CONTEXT_WFD_NIC_ENTRY_DTS fc_ucast_flow_context_wfd_nic_entry;
	RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_DTS fc_ucast_flow_context_eth_xtm_entry;
	RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY_DTS    fc_natc_ucast_flow_context_entry;
	RDD_FC_UCAST_FLOW_CONTEXT_RNR_DHD_ENTRY_DTS fc_ucast_flow_context_rnr_dhd_entry;
	RDD_FC_UCAST_FLOW_CONTEXT_WFD_DHD_ENTRY_DTS fc_ucast_flow_context_wfd_dhd_entry;
	RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY_DTS    fc_natc_mcast_flow_context_entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NATC_CONTEXT_ENTRY_UNION_DTS;

#endif
#if defined WL4908

#define RDD_NATC_CONTEXT_TABLE_SIZE     65536
typedef struct
{
	RDD_NATC_CONTEXT_ENTRY_UNION_DTS	entry[ RDD_NATC_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NATC_CONTEXT_TABLE_DTS;

#endif
#if defined WL4908

typedef union
{
	RDD_NAT_CACHE_LKP_ENTRY_DTS    nat_cache_lkp_entry;
	RDD_NAT_CACHE_L2_LKP_ENTRY_DTS nat_cache_l2_lkp_entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NAT_CACHE_LKUP_ENTRY_UNION_DTS;

#endif
#if defined WL4908

#define RDD_NAT_CACHE_TABLE_SIZE     65536
typedef struct
{
	RDD_NAT_CACHE_LKUP_ENTRY_UNION_DTS	entry[ RDD_NAT_CACHE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NAT_CACHE_TABLE_DTS;

#endif
#if defined DSL_63138 || defined DSL_63148 || defined WL4908

typedef union
{
	RDD_CPU_RX_DESCRIPTOR_IPSEC_DTS cpu_rx_descriptor_ipsec;
	RDD_CPU_TX_DESCRIPTOR_IPSEC_DTS cpu_tx_descriptor_ipsec;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_DESCRIPTOR_UNION_DTS;

#endif
#if defined DSL_63138

#define RDD_IPSEC_DS_QUEUE_SIZE     64
typedef struct
{
	RDD_IPSEC_DS_DESCRIPTOR_UNION_DTS	entry[ RDD_IPSEC_DS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_QUEUE_DTS;

#define RDD_IPSEC_DS_QUEUE_PTR()	( RDD_IPSEC_DS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_DS_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_IPSEC_DS_QUEUE_SIZE     64
typedef struct
{
	RDD_IPSEC_DS_DESCRIPTOR_UNION_DTS	entry[ RDD_IPSEC_DS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_QUEUE_DTS;

#define RDD_IPSEC_DS_QUEUE_PTR()	( RDD_IPSEC_DS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_DS_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_IPSEC_DS_QUEUE_SIZE     64
typedef struct
{
	RDD_IPSEC_DS_DESCRIPTOR_UNION_DTS	entry[ RDD_IPSEC_DS_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPSEC_DS_QUEUE_DTS;

#define RDD_IPSEC_DS_QUEUE_PTR()	( RDD_IPSEC_DS_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + IPSEC_DS_QUEUE_ADDRESS )

#endif
#if defined DSL_63138 || defined DSL_63148 || defined WL4908

typedef union
{
	RDD_CPU_TX_DESCRIPTOR_DS_FAST_DTS      cpu_tx_descriptor_ds_fast;
	RDD_CPU_TX_MESSAGE_DESCRIPTOR_DTS      cpu_tx_message_descriptor;
	RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI_DTS cpu_tx_descriptor_ds_pico_wifi;
	RDD_CPU_TX_DESCRIPTOR_ABS_DTS          cpu_tx_descriptor_abs;
	RDD_CPU_TX_DESCRIPTOR_CORE_DTS         cpu_tx_descriptor_core;
	RDD_CPU_TX_DESCRIPTOR_US_FAST_DTS      cpu_tx_descriptor_us_fast;
	RDD_CPU_TX_DESCRIPTOR_DS_PICO_DTS      cpu_tx_descriptor_ds_pico;
	RDD_CPU_TX_DESCRIPTOR_BPM_DTS          cpu_tx_descriptor_bpm;
	RDD_CPU_TX_DESCRIPTOR_DTS              cpu_tx_descriptor;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_FAST_DESCRIPTOR_UNION_DTS;

#endif
#if defined DSL_63138

#define RDD_CPU_TX_FAST_QUEUE_SIZE     16
typedef struct
{
	RDD_CPU_TX_FAST_DESCRIPTOR_UNION_DTS	entry[ RDD_CPU_TX_FAST_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_FAST_QUEUE_DTS;

#define RDD_CPU_TX_FAST_QUEUE_PTR()	( RDD_CPU_TX_FAST_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_TX_FAST_QUEUE_ADDRESS )

#endif
#if defined DSL_63138

#define RDD_US_CPU_TX_FAST_QUEUE_SIZE     16
typedef struct
{
	RDD_CPU_TX_FAST_DESCRIPTOR_UNION_DTS	entry[ RDD_US_CPU_TX_FAST_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_TX_FAST_QUEUE_DTS;

#define RDD_US_CPU_TX_FAST_QUEUE_PTR()	( RDD_US_CPU_TX_FAST_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_TX_FAST_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_CPU_TX_FAST_QUEUE_SIZE     16
typedef struct
{
	RDD_CPU_TX_FAST_DESCRIPTOR_UNION_DTS	entry[ RDD_CPU_TX_FAST_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_FAST_QUEUE_DTS;

#define RDD_CPU_TX_FAST_QUEUE_PTR()	( RDD_CPU_TX_FAST_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_TX_FAST_QUEUE_ADDRESS )

#endif
#if defined DSL_63148

#define RDD_US_CPU_TX_FAST_QUEUE_SIZE     16
typedef struct
{
	RDD_CPU_TX_FAST_DESCRIPTOR_UNION_DTS	entry[ RDD_US_CPU_TX_FAST_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_TX_FAST_QUEUE_DTS;

#define RDD_US_CPU_TX_FAST_QUEUE_PTR()	( RDD_US_CPU_TX_FAST_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_TX_FAST_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_CPU_TX_FAST_QUEUE_SIZE     16
typedef struct
{
	RDD_CPU_TX_FAST_DESCRIPTOR_UNION_DTS	entry[ RDD_CPU_TX_FAST_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_FAST_QUEUE_DTS;

#define RDD_CPU_TX_FAST_QUEUE_PTR()	( RDD_CPU_TX_FAST_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + CPU_TX_FAST_QUEUE_ADDRESS )

#endif
#if defined WL4908

#define RDD_US_CPU_TX_FAST_QUEUE_SIZE     16
typedef struct
{
	RDD_CPU_TX_FAST_DESCRIPTOR_UNION_DTS	entry[ RDD_US_CPU_TX_FAST_QUEUE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_TX_FAST_QUEUE_DTS;

#define RDD_US_CPU_TX_FAST_QUEUE_PTR()	( RDD_US_CPU_TX_FAST_QUEUE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_CPU_TX_FAST_QUEUE_ADDRESS )

#endif
#if defined DSL_63138 || defined DSL_63148 || defined WL4908

typedef union
{
	RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY_DTS fc_ucast_flow_context_eth_xtm_entry;
	RDD_FC_UCAST_FLOW_CONTEXT_WFD_NIC_ENTRY_DTS fc_ucast_flow_context_wfd_nic_entry;
	RDD_FC_MCAST_FLOW_CONTEXT_ENTRY_DTS         fc_mcast_flow_context_entry;
	RDD_FC_UCAST_FLOW_CONTEXT_ENTRY_DTS         fc_ucast_flow_context_entry;
	RDD_FC_UCAST_FLOW_CONTEXT_RNR_DHD_ENTRY_DTS fc_ucast_flow_context_rnr_dhd_entry;
	RDD_FC_UCAST_FLOW_CONTEXT_WFD_DHD_ENTRY_DTS fc_ucast_flow_context_wfd_dhd_entry;
	RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY_DTS      fc_l2_ucast_flow_context_entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CONTEXT_ENTRY_UNION_DTS;

#endif
#if defined DSL_63138

#define RDD_CONTEXT_TABLE_SIZE     16512
typedef struct
{
	RDD_CONTEXT_ENTRY_UNION_DTS	entry[ RDD_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CONTEXT_TABLE_DTS;

#endif
#if defined DSL_63148

#define RDD_CONTEXT_TABLE_SIZE     16512
typedef struct
{
	RDD_CONTEXT_ENTRY_UNION_DTS	entry[ RDD_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CONTEXT_TABLE_DTS;

#endif
#if defined WL4908

typedef struct
{
	RDD_CONTEXT_ENTRY_UNION_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CONTEXT_TABLE_DTS;

#endif

#if defined DSL_63138
typedef enum
{
	MODE_FIRST =    0,
	MODE_DISABLED    = 0,
	MODE_ENABLED     = 1,
	MODE_LAST =     1
} rdd_mode;
typedef enum
{
	SEMAPHORE_IO_FIRST =      272,
	SEMAPHORE_IO_ADDRESS_0     = 272,
	SEMAPHORE_IO_ADDRESS_1     = 273,
	SEMAPHORE_IO_ADDRESS_2     = 274,
	SEMAPHORE_IO_ADDRESS_3     = 275,
	SEMAPHORE_IO_ADDRESS_4     = 276,
	SEMAPHORE_IO_ADDRESS_5     = 277,
	SEMAPHORE_IO_ADDRESS_7     = 279,
	SEMAPHORE_IO_ADDRESS_8     = 280,
	SEMAPHORE_IO_ADDRESS_9     = 281,
	SEMAPHORE_IO_ADDRESS_10    = 282,
	SEMAPHORE_IO_ADDRESS_11    = 283,
	SEMAPHORE_IO_ADDRESS_12    = 284,
	SEMAPHORE_IO_ADDRESS_13    = 285,
	SEMAPHORE_IO_ADDRESS_14    = 286,
	SEMAPHORE_IO_ADDRESS_15    = 287,
	SEMAPHORE_IO_LAST =       287
} rdd_semaphore_io;
typedef enum
{
	HASH_RESULT_FIRST =  0,
	HASH_RESULT_SLOT_0    = 0,
	HASH_RESULT_SLOT_1    = 1,
	HASH_RESULT_SLOT_2    = 2,
	HASH_RESULT_SLOT_3    = 3,
	HASH_RESULT_SLOT_4    = 4,
	HASH_RESULT_SLOT_5    = 5,
	HASH_RESULT_LAST =   5
} rdd_hash_result;
typedef enum
{
	HASH_RESULT_IO_FIRST =     32,
	HASH_RESULT_IO_ADDRESS_0    = 32,
	HASH_RESULT_IO_ADDRESS_1    = 36,
	HASH_RESULT_IO_ADDRESS_2    = 40,
	HASH_RESULT_IO_ADDRESS_3    = 44,
	HASH_RESULT_IO_ADDRESS_4    = 48,
	HASH_RESULT_IO_ADDRESS_5    = 52,
	HASH_RESULT_IO_LAST =      52
} rdd_hash_result_io;
typedef enum
{
	DMA_LOOKUP_RESULT_FIRST =      0,
	DMA_LOOKUP_RESULT_SLOT_0        = 0,
	DMA_LOOKUP_RESULT_SLOT_1        = 1,
	DMA_LOOKUP_RESULT_SLOT_2        = 2,
	DMA_LOOKUP_RESULT_SLOT_3        = 3,
	DMA_LOOKUP_RESULT_SLOT_4        = 4,
	DMA_LOOKUP_RESULT_FOUR_STEPS    = 4,
	DMA_LOOKUP_RESULT_SLOT_5        = 5,
	DMA_LOOKUP_RESULT_SLOT_6        = 6,
	DMA_LOOKUP_RESULT_SLOT_7        = 7,
	DMA_LOOKUP_RESULT_LAST =       7
} rdd_dma_lookup_result;
typedef enum
{
	DMA_LOOKUP_RESULT_IO_FIRST =     64,
	DMA_LOOKUP_RESULT_IO_ADDRESS_0    = 64,
	DMA_LOOKUP_RESULT_IO_ADDRESS_1    = 68,
	DMA_LOOKUP_RESULT_IO_ADDRESS_2    = 72,
	DMA_LOOKUP_RESULT_IO_ADDRESS_3    = 76,
	DMA_LOOKUP_RESULT_IO_ADDRESS_4    = 80,
	DMA_LOOKUP_RESULT_IO_ADDRESS_5    = 84,
	DMA_LOOKUP_RESULT_IO_ADDRESS_6    = 88,
	DMA_LOOKUP_RESULT_IO_ADDRESS_7    = 92,
	DMA_LOOKUP_RESULT_IO_LAST =      92
} rdd_dma_lookup_result_io;
typedef enum
{
	CAM_RESULT_FIRST =   0,
	CAM_RESULT_SLOT_0     = 0,
	CAM_RESULT_SLOT_1     = 1,
	CAM_RESULT_SLOT_2     = 2,
	CAM_RESULT_SLOT_3     = 3,
	CAM_RESULT_SLOT_4     = 4,
	CAM_RESULT_SLOT_5     = 5,
	CAM_RESULT_SLOT_6     = 6,
	CAM_RESULT_SLOT_7     = 7,
	CAM_RESULT_HIT_BIT    = 8,
	CAM_RESULT_LAST =    8
} rdd_cam_result;
typedef enum
{
	CAM_RESULT_IO_FIRST =     96,
	CAM_RESULT_IO_ADDRESS_0    = 96,
	CAM_RESULT_IO_ADDRESS_1    = 100,
	CAM_RESULT_IO_ADDRESS_2    = 104,
	CAM_RESULT_IO_ADDRESS_3    = 108,
	CAM_RESULT_IO_ADDRESS_4    = 112,
	CAM_RESULT_IO_ADDRESS_5    = 116,
	CAM_RESULT_IO_ADDRESS_6    = 120,
	CAM_RESULT_IO_ADDRESS_7    = 124,
	CAM_RESULT_IO_LAST =      124
} rdd_cam_result_io;
typedef enum
{
	CAM_SEARCH_FIRST =     2,
	CAM_SEARCH_DEPTH_4      = 2,
	CAM_SEARCH_DEPTH_8      = 3,
	CAM_SEARCH_DEPTH_16     = 4,
	CAM_SEARCH_DEPTH_32     = 5,
	CAM_SEARCH_DEPTH_128    = 7,
	CAM_SEARCH_LAST =      7
} rdd_cam_search;
typedef enum
{
	BBH_RX_ERROR_CODE_FIRST =            1,
	BBH_RX_ERROR_CODE_CRC                 = 1,
	BBH_RX_ERROR_CODE_NO_BPM              = 2,
	BBH_RX_ERROR_CODE_NO_SBPM             = 4,
	BBH_RX_ERROR_CODE_NO_DMA              = 8,
	BBH_RX_ERROR_CODE_NO_SDMA             = 16,
	BBH_RX_ERROR_CODE_PACKET_TOO_SHORT    = 32,
	BBH_RX_ERROR_CODE_PACKET_TOO_LONG     = 64,
	BBH_RX_ERROR_CODE_LAST =             64
} rdd_bbh_rx_error_code;
typedef enum
{
	IPSEC_RANGE_IO_FIRST =     524,
	IPSEC_RANGE_IO_ADDRESS_3    = 524,
	IPSEC_RANGE_IO_LAST =      524
} rdd_ipsec_range_io;
typedef enum
{
	RDD_EMAC_FIRST =    0,
	RDD_EMAC_ID_WIFI     = 0,
	RDD_EMAC_ID_0        = 1,
	RDD_EMAC_ID_1        = 2,
	RDD_EMAC_ID_2        = 3,
	RDD_EMAC_ID_3        = 4,
	RDD_EMAC_ID_4        = 5,
	RDD_EMAC_ID_5        = 6,
	RDD_EMAC_ID_6        = 7,
	RDD_EMAC_ID_7        = 8,
	RDD_EMAC_ID_COUNT    = 9,
	RDD_EMAC_LAST =     9
} rdd_rdd_emac;
typedef enum
{
	ACTION_FIRST =     0,
	ACTION_FORWARD      = 0,
	ACTION_TRAP         = 1,
	ACTION_DROP         = 2,
	ACTION_MULTICAST    = 3,
	ACTION_LAST =      3
} rdd_action;
typedef enum
{
	LAYER3_IPV6_HEADER_FIRST =         8,
	LAYER3_IPV6_HEADER_SRC_IP_OFFSET    = 8,
	LAYER3_IPV6_HEADER_DST_IP_OFFSET    = 24,
	LAYER3_IPV6_HEADER_LAST =          24
} rdd_layer3_ipv6_header;
typedef enum
{
	LAYER3_HEADER_FIRST =               0,
	LAYER3_HEADER_TRAFIC_CLASS_OFFSET    = 0,
	LAYER3_HEADER_TOS_OFFSET             = 1,
	LAYER3_HEADER_FLAGS_OFFSET           = 6,
	LAYER3_HEADER_HOP_LIMIT_OFFSET       = 7,
	LAYER3_HEADER_TTL_OFFSET             = 8,
	LAYER3_HEADER_PROTOCOL_OFFSET        = 9,
	LAYER3_HEADER_IP_CHECKSUM_OFFSET     = 10,
	LAYER3_HEADER_SRC_IP_OFFSET          = 12,
	LAYER3_HEADER_DST_IP_OFFSET          = 16,
	LAYER3_HEADER_LAST =                16
} rdd_layer3_header;
typedef enum
{
	LAYER4_HEADER_FIRST =               0,
	LAYER4_HEADER_SRC_PORT_OFFSET        = 0,
	LAYER4_HEADER_ESP_SPI_OFFSET         = 0,
	LAYER4_HEADER_DST_PORT_OFFSET        = 2,
	LAYER4_HEADER_UDP_CHECKSUM_OFFSET    = 6,
	LAYER4_HEADER_GRE_CALL_ID_OFFSET     = 6,
	LAYER4_HEADER_TCP_FLAGS_OFFSET       = 13,
	LAYER4_HEADER_TCP_CHECKSUM_OFFSET    = 16,
	LAYER4_HEADER_LAST =                16
} rdd_layer4_header;
typedef enum
{
	PARSER_L2_PROTOCOL_FIRST =          1,
	PARSER_L2_PROTOCOL_PPPOE_D           = 1,
	PARSER_L2_PROTOCOL_PPPOE_S           = 2,
	PARSER_L2_PROTOCOL_USER_DEFINED_0    = 8,
	PARSER_L2_PROTOCOL_USER_DEFINED_1    = 9,
	PARSER_L2_PROTOCOL_USER_DEFINED_2    = 10,
	PARSER_L2_PROTOCOL_USER_DEFINED_3    = 11,
	PARSER_L2_PROTOCOL_ARP               = 12,
	PARSER_L2_PROTOCOL__1588             = 13,
	PARSER_L2_PROTOCOL__802_1X           = 14,
	PARSER_L2_PROTOCOL_MASK              = 15,
	PARSER_L2_PROTOCOL__802_1AG_CFM      = 15,
	PARSER_L2_PROTOCOL_LAST =           15
} rdd_parser_l2_protocol;
typedef enum
{
	PARSER_L3_PROTOCOL_FIRST = 0,
	PARSER_L3_PROTOCOL_OTHER    = 0,
	PARSER_L3_PROTOCOL_IPV4     = 1,
	PARSER_L3_PROTOCOL_IPV6     = 2,
	PARSER_L3_PROTOCOL_MASK     = 3,
	PARSER_L3_PROTOCOL_LAST =  3
} rdd_parser_l3_protocol;
typedef enum
{
	PARSER_L4_PROTOCOL_FIRST =          0,
	PARSER_L4_PROTOCOL_OTHER             = 0,
	PARSER_L4_PROTOCOL_TCP               = 1,
	PARSER_L4_PROTOCOL_UDP               = 2,
	PARSER_L4_PROTOCOL_IGMP              = 3,
	PARSER_L4_PROTOCOL_ICMP              = 4,
	PARSER_L4_PROTOCOL_ICMPV6            = 5,
	PARSER_L4_PROTOCOL_ESP               = 6,
	PARSER_L4_PROTOCOL_GRE               = 7,
	PARSER_L4_PROTOCOL_USER_DEFINED_0    = 8,
	PARSER_L4_PROTOCOL_USER_DEFINED_1    = 9,
	PARSER_L4_PROTOCOL_USER_DEFINED_2    = 10,
	PARSER_L4_PROTOCOL_USER_DEFINED_3    = 11,
	PARSER_L4_PROTOCOL_RESERVED          = 12,
	PARSER_L4_PROTOCOL_IPV6              = 13,
	PARSER_L4_PROTOCOL_AH                = 14,
	PARSER_L4_PROTOCOL_NOT_PARSED        = 15,
	PARSER_L4_PROTOCOL_MASK              = 15,
	PARSER_L4_PROTOCOL_LAST =           15
} rdd_parser_l4_protocol;
typedef enum
{
	ACTION_ECN_FIRST =            0,
	ACTION_ECN_REMARKING_OFFSET    = 0,
	ACTION_ECN_REMARKING_WIDTH     = 2,
	ACTION_ECN_LAST =             2
} rdd_action_ecn;
typedef enum
{
	ACTION_DSCP_FIRST =                          2,
	ACTION_DSCP_REMARKING_OFFSET                  = 2,
	ACTION_DSCP_REMARKING_TRAFFIC_CLASS_OFFSET    = 4,
	ACTION_DSCP_REMARKING_WIDTH                   = 6,
	ACTION_DSCP_REMARKING_TRAFFIC_CLASS_WIDTH     = 8,
	ACTION_DSCP_LAST =                           8
} rdd_action_dscp;
typedef enum
{
	ACTION_OUTER_FIRST =                      14,
	ACTION_OUTER_PBITS_REMARKING_VID_OFFSET    = 14,
	ACTION_OUTER_LAST =                       14
} rdd_action_outer;
typedef enum
{
	ACTION_INNER_FIRST =                      18,
	ACTION_INNER_PBITS_REMARKING_VID_OFFSET    = 18,
	ACTION_INNER_LAST =                       18
} rdd_action_inner;
typedef enum
{
	ACTION_PBITS_FIRST =                   2,
	ACTION_PBITS_REMARKING_DSCP_OFFSET      = 2,
	ACTION_PBITS_REMARKING_PACKET_WIDTH     = 3,
	ACTION_PBITS_REMARKING_DSCP_WIDTH       = 6,
	ACTION_PBITS_REMARKING_PACKET_OFFSET    = 13,
	ACTION_PBITS_LAST =                    13
} rdd_action_pbits;
typedef enum
{
	ACTION_DS_LITE_FIRST = 40,
	ACTION_DS_LITE_SIZE    = 40,
	ACTION_DS_LITE_LAST = 40
} rdd_action_ds_lite;
typedef enum
{
	DS_ACTION_ID_FIRST =     0,
	DS_ACTION_ID_TRAP         = 0,
	DS_ACTION_ID_TTL          = 2,
	DS_ACTION_ID_DSCP         = 4,
	DS_ACTION_ID_NAT          = 5,
	DS_ACTION_ID_GRE          = 6,
	DS_ACTION_ID_OPBITS       = 7,
	DS_ACTION_ID_IPBITS       = 8,
	DS_ACTION_ID_DS_LITE      = 9,
	DS_ACTION_ID_PPPOE        = 10,
	DS_ACTION_ID_TOTAL_NUM    = 17,
	DS_ACTION_ID_LAST =      17
} rdd_ds_action_id;
typedef enum
{
	US_ACTION_ID_FIRST =     0,
	US_ACTION_ID_TRAP         = 0,
	US_ACTION_ID_TTL          = 2,
	US_ACTION_ID_DSCP         = 4,
	US_ACTION_ID_NAT          = 5,
	US_ACTION_ID_GRE          = 6,
	US_ACTION_ID_OPBITS       = 7,
	US_ACTION_ID_IPBITS       = 8,
	US_ACTION_ID_DS_LITE      = 9,
	US_ACTION_ID_PPPOE        = 10,
	US_ACTION_ID_TOTAL_NUM    = 17,
	US_ACTION_ID_LAST =      17
} rdd_us_action_id;
typedef enum
{
	RDD_VPORT_FIRST =  0,
	RDD_VPORT_ID_0      = 0,
	RDD_VPORT_ID_1      = 1,
	RDD_VPORT_ID_2      = 2,
	RDD_VPORT_ID_3      = 3,
	RDD_VPORT_ID_4      = 4,
	RDD_VPORT_ID_5      = 5,
	RDD_VPORT_ID_6      = 6,
	RDD_VPORT_ID_7      = 7,
	RDD_VPORT_ID_8      = 8,
	RDD_VPORT_ID_9      = 9,
	RDD_VPORT_ID_10     = 10,
	RDD_VPORT_ID_11     = 11,
	RDD_VPORT_ID_12     = 12,
	RDD_VPORT_ID_13     = 13,
	RDD_VPORT_ID_14     = 14,
	RDD_VPORT_ID_15     = 15,
	RDD_VPORT_ID_16     = 16,
	RDD_VPORT_ID_17     = 17,
	RDD_VPORT_ID_18     = 18,
	RDD_VPORT_ID_19     = 19,
	RDD_VPORT_ID_20     = 20,
	RDD_VPORT_ID_21     = 21,
	RDD_VPORT_ID_22     = 22,
	RDD_VPORT_ID_23     = 23,
	RDD_VPORT_ID_24     = 24,
	RDD_VPORT_ID_25     = 25,
	RDD_VPORT_ID_26     = 26,
	RDD_VPORT_ID_27     = 27,
	RDD_VPORT_ID_28     = 28,
	RDD_VPORT_ID_29     = 29,
	RDD_VPORT_ID_30     = 30,
	RDD_VPORT_ID_31     = 31,
	RDD_VPORT_ID_32     = 32,
	RDD_VPORT_ID_33     = 33,
	RDD_VPORT_ID_34     = 34,
	RDD_VPORT_ID_35     = 35,
	RDD_VPORT_ID_36     = 36,
	RDD_VPORT_ID_37     = 37,
	RDD_VPORT_ID_38     = 38,
	RDD_VPORT_ID_39     = 39,
	RDD_VPORT_ID_ANY    = 40,
	RDD_VPORT_LAST =   40
} rdd_rdd_vport;
typedef enum
{
	DSCP_TO_FIRST =              6,
	DSCP_TO_PBITS_SHIFT_OFFSET    = 6,
	DSCP_TO_LAST =               6
} rdd_dscp_to;
typedef enum
{
	RESOLUTION_CONTEXT_FIRST =                       0,
	RESOLUTION_CONTEXT_VIRTUAL_SRC_PORT_OFFSET        = 0,
	RESOLUTION_CONTEXT_GPE_DMA_OFFSET_WIDTH           = 1,
	RESOLUTION_CONTEXT_GPE_HEADER_LENGTH_WIDTH        = 1,
	RESOLUTION_CONTEXT_GPE_HEADER_IH_PTR_WIDTH        = 2,
	RESOLUTION_CONTEXT_GPE_COMMAND_LIST_PTR_WIDTH     = 2,
	RESOLUTION_CONTEXT_GPE_PACKET_DRR_PTR_WIDTH       = 4,
	RESOLUTION_CONTEXT_GPE_HEADER_LENGTH_OFFSET       = 6,
	RESOLUTION_CONTEXT_GPE_DMA_OFFSET_OFFSET          = 7,
	RESOLUTION_CONTEXT_GPE_COMMAND_LIST_PTR_OFFSET    = 8,
	RESOLUTION_CONTEXT_GPE_HEADER_IH_PTR_OFFSET       = 10,
	RESOLUTION_CONTEXT_GPE_PACKET_DRR_PTR_OFFSET      = 12,
	RESOLUTION_CONTEXT_LAST =                        12
} rdd_resolution_context;
typedef enum
{
	FR_FORMAT_FIRST =     0,
	FR_FORMAT_WI_WI64      = 0,
	FR_FORMAT_WI_CWI32     = 1,
	FR_FORMAT_WI_CWI64     = 2,
	FR_FORMAT_WI_ACWI32    = 3,
	FR_FORMAT_WI_ACWI64    = 4,
	FR_FORMAT_LAST =      4
} rdd_fr_format;
#endif

#if defined DSL_63148
typedef enum
{
	MODE_FIRST =    0,
	MODE_DISABLED    = 0,
	MODE_ENABLED     = 1,
	MODE_LAST =     1
} rdd_mode;
typedef enum
{
	SEMAPHORE_IO_FIRST =      272,
	SEMAPHORE_IO_ADDRESS_0     = 272,
	SEMAPHORE_IO_ADDRESS_1     = 273,
	SEMAPHORE_IO_ADDRESS_2     = 274,
	SEMAPHORE_IO_ADDRESS_3     = 275,
	SEMAPHORE_IO_ADDRESS_4     = 276,
	SEMAPHORE_IO_ADDRESS_5     = 277,
	SEMAPHORE_IO_ADDRESS_7     = 279,
	SEMAPHORE_IO_ADDRESS_8     = 280,
	SEMAPHORE_IO_ADDRESS_9     = 281,
	SEMAPHORE_IO_ADDRESS_10    = 282,
	SEMAPHORE_IO_ADDRESS_11    = 283,
	SEMAPHORE_IO_ADDRESS_12    = 284,
	SEMAPHORE_IO_ADDRESS_13    = 285,
	SEMAPHORE_IO_ADDRESS_14    = 286,
	SEMAPHORE_IO_ADDRESS_15    = 287,
	SEMAPHORE_IO_LAST =       287
} rdd_semaphore_io;
typedef enum
{
	HASH_RESULT_FIRST =  0,
	HASH_RESULT_SLOT_0    = 0,
	HASH_RESULT_SLOT_1    = 1,
	HASH_RESULT_SLOT_2    = 2,
	HASH_RESULT_SLOT_3    = 3,
	HASH_RESULT_SLOT_4    = 4,
	HASH_RESULT_SLOT_5    = 5,
	HASH_RESULT_LAST =   5
} rdd_hash_result;
typedef enum
{
	HASH_RESULT_IO_FIRST =     32,
	HASH_RESULT_IO_ADDRESS_0    = 32,
	HASH_RESULT_IO_ADDRESS_1    = 36,
	HASH_RESULT_IO_ADDRESS_2    = 40,
	HASH_RESULT_IO_ADDRESS_3    = 44,
	HASH_RESULT_IO_ADDRESS_4    = 48,
	HASH_RESULT_IO_ADDRESS_5    = 52,
	HASH_RESULT_IO_LAST =      52
} rdd_hash_result_io;
typedef enum
{
	DMA_LOOKUP_RESULT_FIRST =      0,
	DMA_LOOKUP_RESULT_SLOT_0        = 0,
	DMA_LOOKUP_RESULT_SLOT_1        = 1,
	DMA_LOOKUP_RESULT_SLOT_2        = 2,
	DMA_LOOKUP_RESULT_SLOT_3        = 3,
	DMA_LOOKUP_RESULT_SLOT_4        = 4,
	DMA_LOOKUP_RESULT_FOUR_STEPS    = 4,
	DMA_LOOKUP_RESULT_SLOT_5        = 5,
	DMA_LOOKUP_RESULT_SLOT_6        = 6,
	DMA_LOOKUP_RESULT_SLOT_7        = 7,
	DMA_LOOKUP_RESULT_LAST =       7
} rdd_dma_lookup_result;
typedef enum
{
	DMA_LOOKUP_RESULT_IO_FIRST =     64,
	DMA_LOOKUP_RESULT_IO_ADDRESS_0    = 64,
	DMA_LOOKUP_RESULT_IO_ADDRESS_1    = 68,
	DMA_LOOKUP_RESULT_IO_ADDRESS_2    = 72,
	DMA_LOOKUP_RESULT_IO_ADDRESS_3    = 76,
	DMA_LOOKUP_RESULT_IO_ADDRESS_4    = 80,
	DMA_LOOKUP_RESULT_IO_ADDRESS_5    = 84,
	DMA_LOOKUP_RESULT_IO_ADDRESS_6    = 88,
	DMA_LOOKUP_RESULT_IO_ADDRESS_7    = 92,
	DMA_LOOKUP_RESULT_IO_LAST =      92
} rdd_dma_lookup_result_io;
typedef enum
{
	CAM_RESULT_FIRST =   0,
	CAM_RESULT_SLOT_0     = 0,
	CAM_RESULT_SLOT_1     = 1,
	CAM_RESULT_SLOT_2     = 2,
	CAM_RESULT_SLOT_3     = 3,
	CAM_RESULT_SLOT_4     = 4,
	CAM_RESULT_SLOT_5     = 5,
	CAM_RESULT_SLOT_6     = 6,
	CAM_RESULT_SLOT_7     = 7,
	CAM_RESULT_HIT_BIT    = 8,
	CAM_RESULT_LAST =    8
} rdd_cam_result;
typedef enum
{
	CAM_RESULT_IO_FIRST =     96,
	CAM_RESULT_IO_ADDRESS_0    = 96,
	CAM_RESULT_IO_ADDRESS_1    = 100,
	CAM_RESULT_IO_ADDRESS_2    = 104,
	CAM_RESULT_IO_ADDRESS_3    = 108,
	CAM_RESULT_IO_ADDRESS_4    = 112,
	CAM_RESULT_IO_ADDRESS_5    = 116,
	CAM_RESULT_IO_ADDRESS_6    = 120,
	CAM_RESULT_IO_ADDRESS_7    = 124,
	CAM_RESULT_IO_LAST =      124
} rdd_cam_result_io;
typedef enum
{
	CAM_SEARCH_FIRST =     2,
	CAM_SEARCH_DEPTH_4      = 2,
	CAM_SEARCH_DEPTH_8      = 3,
	CAM_SEARCH_DEPTH_16     = 4,
	CAM_SEARCH_DEPTH_32     = 5,
	CAM_SEARCH_DEPTH_128    = 7,
	CAM_SEARCH_LAST =      7
} rdd_cam_search;
typedef enum
{
	BBH_RX_ERROR_CODE_FIRST =            1,
	BBH_RX_ERROR_CODE_CRC                 = 1,
	BBH_RX_ERROR_CODE_NO_BPM              = 2,
	BBH_RX_ERROR_CODE_NO_SBPM             = 4,
	BBH_RX_ERROR_CODE_NO_DMA              = 8,
	BBH_RX_ERROR_CODE_NO_SDMA             = 16,
	BBH_RX_ERROR_CODE_PACKET_TOO_SHORT    = 32,
	BBH_RX_ERROR_CODE_PACKET_TOO_LONG     = 64,
	BBH_RX_ERROR_CODE_LAST =             64
} rdd_bbh_rx_error_code;
typedef enum
{
	IPSEC_RANGE_IO_FIRST =     524,
	IPSEC_RANGE_IO_ADDRESS_3    = 524,
	IPSEC_RANGE_IO_LAST =      524
} rdd_ipsec_range_io;
typedef enum
{
	RDD_EMAC_FIRST =    0,
	RDD_EMAC_ID_WIFI     = 0,
	RDD_EMAC_ID_0        = 1,
	RDD_EMAC_ID_1        = 2,
	RDD_EMAC_ID_2        = 3,
	RDD_EMAC_ID_3        = 4,
	RDD_EMAC_ID_4        = 5,
	RDD_EMAC_ID_5        = 6,
	RDD_EMAC_ID_6        = 7,
	RDD_EMAC_ID_7        = 8,
	RDD_EMAC_ID_COUNT    = 9,
	RDD_EMAC_LAST =     9
} rdd_rdd_emac;
typedef enum
{
	ACTION_FIRST =     0,
	ACTION_FORWARD      = 0,
	ACTION_TRAP         = 1,
	ACTION_DROP         = 2,
	ACTION_MULTICAST    = 3,
	ACTION_LAST =      3
} rdd_action;
typedef enum
{
	LAYER3_IPV6_HEADER_FIRST =         8,
	LAYER3_IPV6_HEADER_SRC_IP_OFFSET    = 8,
	LAYER3_IPV6_HEADER_DST_IP_OFFSET    = 24,
	LAYER3_IPV6_HEADER_LAST =          24
} rdd_layer3_ipv6_header;
typedef enum
{
	LAYER3_HEADER_FIRST =               0,
	LAYER3_HEADER_TRAFIC_CLASS_OFFSET    = 0,
	LAYER3_HEADER_TOS_OFFSET             = 1,
	LAYER3_HEADER_FLAGS_OFFSET           = 6,
	LAYER3_HEADER_HOP_LIMIT_OFFSET       = 7,
	LAYER3_HEADER_TTL_OFFSET             = 8,
	LAYER3_HEADER_PROTOCOL_OFFSET        = 9,
	LAYER3_HEADER_IP_CHECKSUM_OFFSET     = 10,
	LAYER3_HEADER_SRC_IP_OFFSET          = 12,
	LAYER3_HEADER_DST_IP_OFFSET          = 16,
	LAYER3_HEADER_LAST =                16
} rdd_layer3_header;
typedef enum
{
	LAYER4_HEADER_FIRST =               0,
	LAYER4_HEADER_SRC_PORT_OFFSET        = 0,
	LAYER4_HEADER_ESP_SPI_OFFSET         = 0,
	LAYER4_HEADER_DST_PORT_OFFSET        = 2,
	LAYER4_HEADER_UDP_CHECKSUM_OFFSET    = 6,
	LAYER4_HEADER_GRE_CALL_ID_OFFSET     = 6,
	LAYER4_HEADER_TCP_FLAGS_OFFSET       = 13,
	LAYER4_HEADER_TCP_CHECKSUM_OFFSET    = 16,
	LAYER4_HEADER_LAST =                16
} rdd_layer4_header;
typedef enum
{
	PARSER_L2_PROTOCOL_FIRST =          1,
	PARSER_L2_PROTOCOL_PPPOE_D           = 1,
	PARSER_L2_PROTOCOL_PPPOE_S           = 2,
	PARSER_L2_PROTOCOL_USER_DEFINED_0    = 8,
	PARSER_L2_PROTOCOL_USER_DEFINED_1    = 9,
	PARSER_L2_PROTOCOL_USER_DEFINED_2    = 10,
	PARSER_L2_PROTOCOL_USER_DEFINED_3    = 11,
	PARSER_L2_PROTOCOL_ARP               = 12,
	PARSER_L2_PROTOCOL__1588             = 13,
	PARSER_L2_PROTOCOL__802_1X           = 14,
	PARSER_L2_PROTOCOL_MASK              = 15,
	PARSER_L2_PROTOCOL__802_1AG_CFM      = 15,
	PARSER_L2_PROTOCOL_LAST =           15
} rdd_parser_l2_protocol;
typedef enum
{
	PARSER_L3_PROTOCOL_FIRST = 0,
	PARSER_L3_PROTOCOL_OTHER    = 0,
	PARSER_L3_PROTOCOL_IPV4     = 1,
	PARSER_L3_PROTOCOL_IPV6     = 2,
	PARSER_L3_PROTOCOL_MASK     = 3,
	PARSER_L3_PROTOCOL_LAST =  3
} rdd_parser_l3_protocol;
typedef enum
{
	PARSER_L4_PROTOCOL_FIRST =          0,
	PARSER_L4_PROTOCOL_OTHER             = 0,
	PARSER_L4_PROTOCOL_TCP               = 1,
	PARSER_L4_PROTOCOL_UDP               = 2,
	PARSER_L4_PROTOCOL_IGMP              = 3,
	PARSER_L4_PROTOCOL_ICMP              = 4,
	PARSER_L4_PROTOCOL_ICMPV6            = 5,
	PARSER_L4_PROTOCOL_ESP               = 6,
	PARSER_L4_PROTOCOL_GRE               = 7,
	PARSER_L4_PROTOCOL_USER_DEFINED_0    = 8,
	PARSER_L4_PROTOCOL_USER_DEFINED_1    = 9,
	PARSER_L4_PROTOCOL_USER_DEFINED_2    = 10,
	PARSER_L4_PROTOCOL_USER_DEFINED_3    = 11,
	PARSER_L4_PROTOCOL_RESERVED          = 12,
	PARSER_L4_PROTOCOL_IPV6              = 13,
	PARSER_L4_PROTOCOL_AH                = 14,
	PARSER_L4_PROTOCOL_NOT_PARSED        = 15,
	PARSER_L4_PROTOCOL_MASK              = 15,
	PARSER_L4_PROTOCOL_LAST =           15
} rdd_parser_l4_protocol;
typedef enum
{
	ACTION_ECN_FIRST =            0,
	ACTION_ECN_REMARKING_OFFSET    = 0,
	ACTION_ECN_REMARKING_WIDTH     = 2,
	ACTION_ECN_LAST =             2
} rdd_action_ecn;
typedef enum
{
	ACTION_DSCP_FIRST =                          2,
	ACTION_DSCP_REMARKING_OFFSET                  = 2,
	ACTION_DSCP_REMARKING_TRAFFIC_CLASS_OFFSET    = 4,
	ACTION_DSCP_REMARKING_WIDTH                   = 6,
	ACTION_DSCP_REMARKING_TRAFFIC_CLASS_WIDTH     = 8,
	ACTION_DSCP_LAST =                           8
} rdd_action_dscp;
typedef enum
{
	ACTION_OUTER_FIRST =                      14,
	ACTION_OUTER_PBITS_REMARKING_VID_OFFSET    = 14,
	ACTION_OUTER_LAST =                       14
} rdd_action_outer;
typedef enum
{
	ACTION_INNER_FIRST =                      18,
	ACTION_INNER_PBITS_REMARKING_VID_OFFSET    = 18,
	ACTION_INNER_LAST =                       18
} rdd_action_inner;
typedef enum
{
	ACTION_PBITS_FIRST =                   2,
	ACTION_PBITS_REMARKING_DSCP_OFFSET      = 2,
	ACTION_PBITS_REMARKING_PACKET_WIDTH     = 3,
	ACTION_PBITS_REMARKING_DSCP_WIDTH       = 6,
	ACTION_PBITS_REMARKING_PACKET_OFFSET    = 13,
	ACTION_PBITS_LAST =                    13
} rdd_action_pbits;
typedef enum
{
	ACTION_DS_LITE_FIRST = 40,
	ACTION_DS_LITE_SIZE    = 40,
	ACTION_DS_LITE_LAST = 40
} rdd_action_ds_lite;
typedef enum
{
	DS_ACTION_ID_FIRST =     0,
	DS_ACTION_ID_TRAP         = 0,
	DS_ACTION_ID_TTL          = 2,
	DS_ACTION_ID_DSCP         = 4,
	DS_ACTION_ID_NAT          = 5,
	DS_ACTION_ID_GRE          = 6,
	DS_ACTION_ID_OPBITS       = 7,
	DS_ACTION_ID_IPBITS       = 8,
	DS_ACTION_ID_DS_LITE      = 9,
	DS_ACTION_ID_PPPOE        = 10,
	DS_ACTION_ID_TOTAL_NUM    = 17,
	DS_ACTION_ID_LAST =      17
} rdd_ds_action_id;
typedef enum
{
	US_ACTION_ID_FIRST =     0,
	US_ACTION_ID_TRAP         = 0,
	US_ACTION_ID_TTL          = 2,
	US_ACTION_ID_DSCP         = 4,
	US_ACTION_ID_NAT          = 5,
	US_ACTION_ID_GRE          = 6,
	US_ACTION_ID_OPBITS       = 7,
	US_ACTION_ID_IPBITS       = 8,
	US_ACTION_ID_DS_LITE      = 9,
	US_ACTION_ID_PPPOE        = 10,
	US_ACTION_ID_TOTAL_NUM    = 17,
	US_ACTION_ID_LAST =      17
} rdd_us_action_id;
typedef enum
{
	RDD_VPORT_FIRST =  0,
	RDD_VPORT_ID_0      = 0,
	RDD_VPORT_ID_1      = 1,
	RDD_VPORT_ID_2      = 2,
	RDD_VPORT_ID_3      = 3,
	RDD_VPORT_ID_4      = 4,
	RDD_VPORT_ID_5      = 5,
	RDD_VPORT_ID_6      = 6,
	RDD_VPORT_ID_7      = 7,
	RDD_VPORT_ID_8      = 8,
	RDD_VPORT_ID_9      = 9,
	RDD_VPORT_ID_10     = 10,
	RDD_VPORT_ID_11     = 11,
	RDD_VPORT_ID_12     = 12,
	RDD_VPORT_ID_13     = 13,
	RDD_VPORT_ID_14     = 14,
	RDD_VPORT_ID_15     = 15,
	RDD_VPORT_ID_16     = 16,
	RDD_VPORT_ID_17     = 17,
	RDD_VPORT_ID_18     = 18,
	RDD_VPORT_ID_19     = 19,
	RDD_VPORT_ID_20     = 20,
	RDD_VPORT_ID_21     = 21,
	RDD_VPORT_ID_22     = 22,
	RDD_VPORT_ID_23     = 23,
	RDD_VPORT_ID_24     = 24,
	RDD_VPORT_ID_25     = 25,
	RDD_VPORT_ID_26     = 26,
	RDD_VPORT_ID_27     = 27,
	RDD_VPORT_ID_28     = 28,
	RDD_VPORT_ID_29     = 29,
	RDD_VPORT_ID_30     = 30,
	RDD_VPORT_ID_31     = 31,
	RDD_VPORT_ID_32     = 32,
	RDD_VPORT_ID_33     = 33,
	RDD_VPORT_ID_34     = 34,
	RDD_VPORT_ID_35     = 35,
	RDD_VPORT_ID_36     = 36,
	RDD_VPORT_ID_37     = 37,
	RDD_VPORT_ID_38     = 38,
	RDD_VPORT_ID_39     = 39,
	RDD_VPORT_ID_ANY    = 40,
	RDD_VPORT_LAST =   40
} rdd_rdd_vport;
typedef enum
{
	DSCP_TO_FIRST =              6,
	DSCP_TO_PBITS_SHIFT_OFFSET    = 6,
	DSCP_TO_LAST =               6
} rdd_dscp_to;
typedef enum
{
	RESOLUTION_CONTEXT_FIRST =                       0,
	RESOLUTION_CONTEXT_VIRTUAL_SRC_PORT_OFFSET        = 0,
	RESOLUTION_CONTEXT_GPE_DMA_OFFSET_WIDTH           = 1,
	RESOLUTION_CONTEXT_GPE_HEADER_LENGTH_WIDTH        = 1,
	RESOLUTION_CONTEXT_GPE_HEADER_IH_PTR_WIDTH        = 2,
	RESOLUTION_CONTEXT_GPE_COMMAND_LIST_PTR_WIDTH     = 2,
	RESOLUTION_CONTEXT_GPE_PACKET_DRR_PTR_WIDTH       = 4,
	RESOLUTION_CONTEXT_GPE_HEADER_LENGTH_OFFSET       = 6,
	RESOLUTION_CONTEXT_GPE_DMA_OFFSET_OFFSET          = 7,
	RESOLUTION_CONTEXT_GPE_COMMAND_LIST_PTR_OFFSET    = 8,
	RESOLUTION_CONTEXT_GPE_HEADER_IH_PTR_OFFSET       = 10,
	RESOLUTION_CONTEXT_GPE_PACKET_DRR_PTR_OFFSET      = 12,
	RESOLUTION_CONTEXT_LAST =                        12
} rdd_resolution_context;
typedef enum
{
	FR_FORMAT_FIRST =     0,
	FR_FORMAT_WI_WI64      = 0,
	FR_FORMAT_WI_CWI32     = 1,
	FR_FORMAT_WI_CWI64     = 2,
	FR_FORMAT_WI_ACWI32    = 3,
	FR_FORMAT_WI_ACWI64    = 4,
	FR_FORMAT_LAST =      4
} rdd_fr_format;
#endif

#if defined WL4908
typedef enum
{
	MODE_FIRST =    0,
	MODE_DISABLED    = 0,
	MODE_ENABLED     = 1,
	MODE_LAST =     1
} rdd_mode;
typedef enum
{
	SEMAPHORE_IO_FIRST =      272,
	SEMAPHORE_IO_ADDRESS_0     = 272,
	SEMAPHORE_IO_ADDRESS_1     = 273,
	SEMAPHORE_IO_ADDRESS_2     = 274,
	SEMAPHORE_IO_ADDRESS_3     = 275,
	SEMAPHORE_IO_ADDRESS_4     = 276,
	SEMAPHORE_IO_ADDRESS_5     = 277,
	SEMAPHORE_IO_ADDRESS_7     = 279,
	SEMAPHORE_IO_ADDRESS_8     = 280,
	SEMAPHORE_IO_ADDRESS_9     = 281,
	SEMAPHORE_IO_ADDRESS_10    = 282,
	SEMAPHORE_IO_ADDRESS_11    = 283,
	SEMAPHORE_IO_ADDRESS_12    = 284,
	SEMAPHORE_IO_ADDRESS_13    = 285,
	SEMAPHORE_IO_ADDRESS_14    = 286,
	SEMAPHORE_IO_ADDRESS_15    = 287,
	SEMAPHORE_IO_LAST =       287
} rdd_semaphore_io;
typedef enum
{
	HASH_RESULT_FIRST =  0,
	HASH_RESULT_SLOT_0    = 0,
	HASH_RESULT_SLOT_1    = 1,
	HASH_RESULT_SLOT_2    = 2,
	HASH_RESULT_SLOT_3    = 3,
	HASH_RESULT_SLOT_4    = 4,
	HASH_RESULT_SLOT_5    = 5,
	HASH_RESULT_LAST =   5
} rdd_hash_result;
typedef enum
{
	HASH_RESULT_IO_FIRST =     32,
	HASH_RESULT_IO_ADDRESS_0    = 32,
	HASH_RESULT_IO_ADDRESS_1    = 36,
	HASH_RESULT_IO_ADDRESS_2    = 40,
	HASH_RESULT_IO_ADDRESS_3    = 44,
	HASH_RESULT_IO_ADDRESS_4    = 48,
	HASH_RESULT_IO_ADDRESS_5    = 52,
	HASH_RESULT_IO_LAST =      52
} rdd_hash_result_io;
typedef enum
{
	DMA_LOOKUP_RESULT_FIRST =      0,
	DMA_LOOKUP_RESULT_SLOT_0        = 0,
	DMA_LOOKUP_RESULT_SLOT_1        = 1,
	DMA_LOOKUP_RESULT_SLOT_2        = 2,
	DMA_LOOKUP_RESULT_SLOT_3        = 3,
	DMA_LOOKUP_RESULT_SLOT_4        = 4,
	DMA_LOOKUP_RESULT_FOUR_STEPS    = 4,
	DMA_LOOKUP_RESULT_SLOT_5        = 5,
	DMA_LOOKUP_RESULT_SLOT_6        = 6,
	DMA_LOOKUP_RESULT_SLOT_7        = 7,
	DMA_LOOKUP_RESULT_LAST =       7
} rdd_dma_lookup_result;
typedef enum
{
	DMA_LOOKUP_RESULT_IO_FIRST =     64,
	DMA_LOOKUP_RESULT_IO_ADDRESS_0    = 64,
	DMA_LOOKUP_RESULT_IO_ADDRESS_1    = 68,
	DMA_LOOKUP_RESULT_IO_ADDRESS_2    = 72,
	DMA_LOOKUP_RESULT_IO_ADDRESS_3    = 76,
	DMA_LOOKUP_RESULT_IO_ADDRESS_4    = 80,
	DMA_LOOKUP_RESULT_IO_ADDRESS_5    = 84,
	DMA_LOOKUP_RESULT_IO_ADDRESS_6    = 88,
	DMA_LOOKUP_RESULT_IO_ADDRESS_7    = 92,
	DMA_LOOKUP_RESULT_IO_LAST =      92
} rdd_dma_lookup_result_io;
typedef enum
{
	CAM_RESULT_FIRST =   0,
	CAM_RESULT_SLOT_0     = 0,
	CAM_RESULT_SLOT_1     = 1,
	CAM_RESULT_SLOT_2     = 2,
	CAM_RESULT_SLOT_3     = 3,
	CAM_RESULT_SLOT_4     = 4,
	CAM_RESULT_SLOT_5     = 5,
	CAM_RESULT_SLOT_6     = 6,
	CAM_RESULT_SLOT_7     = 7,
	CAM_RESULT_HIT_BIT    = 8,
	CAM_RESULT_LAST =    8
} rdd_cam_result;
typedef enum
{
	CAM_RESULT_IO_FIRST =     96,
	CAM_RESULT_IO_ADDRESS_0    = 96,
	CAM_RESULT_IO_ADDRESS_1    = 100,
	CAM_RESULT_IO_ADDRESS_2    = 104,
	CAM_RESULT_IO_ADDRESS_3    = 108,
	CAM_RESULT_IO_ADDRESS_4    = 112,
	CAM_RESULT_IO_ADDRESS_5    = 116,
	CAM_RESULT_IO_ADDRESS_6    = 120,
	CAM_RESULT_IO_ADDRESS_7    = 124,
	CAM_RESULT_IO_LAST =      124
} rdd_cam_result_io;
typedef enum
{
	CAM_SEARCH_FIRST =     2,
	CAM_SEARCH_DEPTH_4      = 2,
	CAM_SEARCH_DEPTH_8      = 3,
	CAM_SEARCH_DEPTH_16     = 4,
	CAM_SEARCH_DEPTH_32     = 5,
	CAM_SEARCH_DEPTH_128    = 7,
	CAM_SEARCH_LAST =      7
} rdd_cam_search;
typedef enum
{
	BBH_RX_ERROR_CODE_FIRST =            1,
	BBH_RX_ERROR_CODE_CRC                 = 1,
	BBH_RX_ERROR_CODE_NO_BPM              = 2,
	BBH_RX_ERROR_CODE_NO_SBPM             = 3,
	BBH_RX_ERROR_CODE_NO_DMA              = 4,
	BBH_RX_ERROR_CODE_NO_SDMA             = 5,
	BBH_RX_ERROR_CODE_PACKET_TOO_SHORT    = 6,
	BBH_RX_ERROR_CODE_PACKET_TOO_LONG     = 7,
	BBH_RX_ERROR_CODE_THIRD_FLOW          = 8,
	BBH_RX_ERROR_CODE_SOP_AFTER_SOP       = 9,
	BBH_RX_ERROR_CODE_LAST =             9
} rdd_bbh_rx_error_code;
typedef enum
{
	IPSEC_RANGE_IO_FIRST =     524,
	IPSEC_RANGE_IO_ADDRESS_3    = 524,
	IPSEC_RANGE_IO_LAST =      524
} rdd_ipsec_range_io;
typedef enum
{
	RDD_EMAC_FIRST =    0,
	RDD_EMAC_ID_WIFI     = 0,
	RDD_EMAC_ID_0        = 1,
	RDD_EMAC_ID_1        = 2,
	RDD_EMAC_ID_2        = 3,
	RDD_EMAC_ID_3        = 4,
	RDD_EMAC_ID_4        = 5,
	RDD_EMAC_ID_5        = 6,
	RDD_EMAC_ID_6        = 7,
	RDD_EMAC_ID_7        = 8,
	RDD_EMAC_ID_COUNT    = 9,
	RDD_EMAC_LAST =     9
} rdd_rdd_emac;
typedef enum
{
	FPM_ALLOC_FIRST =              0,
	FPM_ALLOC_CHUNKS_8_OFFSET       = 0,
	FPM_ALLOC_CHUNKS_4_OFFSET       = 8,
	FPM_ALLOC_RESULT_SIZE           = 8,
	FPM_ALLOC_TOKEN_INDEX_OFFSET    = 12,
	FPM_ALLOC_CHUNKS_2_OFFSET       = 16,
	FPM_ALLOC_TOKEN_INDEX_WIDTH     = 18,
	FPM_ALLOC_CHUNKS_1_OFFSET       = 24,
	FPM_ALLOC_TOKEN_VALID_OFFSET    = 31,
	FPM_ALLOC_POOL_BASE             = 2193621504,
	FPM_ALLOC_POOL0_BASE            = 2193622016,
	FPM_ALLOC_LAST =               2193622016
} rdd_fpm_alloc;
typedef enum
{
	ACTION_FIRST =     0,
	ACTION_FORWARD      = 0,
	ACTION_TRAP         = 1,
	ACTION_DROP         = 2,
	ACTION_MULTICAST    = 3,
	ACTION_LAST =      3
} rdd_action;
typedef enum
{
	LAYER3_IPV6_HEADER_FIRST =         8,
	LAYER3_IPV6_HEADER_SRC_IP_OFFSET    = 8,
	LAYER3_IPV6_HEADER_DST_IP_OFFSET    = 24,
	LAYER3_IPV6_HEADER_LAST =          24
} rdd_layer3_ipv6_header;
typedef enum
{
	LAYER3_HEADER_FIRST =               0,
	LAYER3_HEADER_TRAFIC_CLASS_OFFSET    = 0,
	LAYER3_HEADER_TOS_OFFSET             = 1,
	LAYER3_HEADER_FLAGS_OFFSET           = 6,
	LAYER3_HEADER_HOP_LIMIT_OFFSET       = 7,
	LAYER3_HEADER_TTL_OFFSET             = 8,
	LAYER3_HEADER_PROTOCOL_OFFSET        = 9,
	LAYER3_HEADER_IP_CHECKSUM_OFFSET     = 10,
	LAYER3_HEADER_SRC_IP_OFFSET          = 12,
	LAYER3_HEADER_DST_IP_OFFSET          = 16,
	LAYER3_HEADER_LAST =                16
} rdd_layer3_header;
typedef enum
{
	LAYER4_HEADER_FIRST =               0,
	LAYER4_HEADER_SRC_PORT_OFFSET        = 0,
	LAYER4_HEADER_ESP_SPI_OFFSET         = 0,
	LAYER4_HEADER_DST_PORT_OFFSET        = 2,
	LAYER4_HEADER_UDP_CHECKSUM_OFFSET    = 6,
	LAYER4_HEADER_GRE_CALL_ID_OFFSET     = 6,
	LAYER4_HEADER_TCP_FLAGS_OFFSET       = 13,
	LAYER4_HEADER_TCP_CHECKSUM_OFFSET    = 16,
	LAYER4_HEADER_LAST =                16
} rdd_layer4_header;
typedef enum
{
	PARSER_L2_PROTOCOL_FIRST =          1,
	PARSER_L2_PROTOCOL_PPPOE_D           = 1,
	PARSER_L2_PROTOCOL_PPPOE_S           = 2,
	PARSER_L2_PROTOCOL_USER_DEFINED_0    = 8,
	PARSER_L2_PROTOCOL_USER_DEFINED_1    = 9,
	PARSER_L2_PROTOCOL_USER_DEFINED_2    = 10,
	PARSER_L2_PROTOCOL_USER_DEFINED_3    = 11,
	PARSER_L2_PROTOCOL_ARP               = 12,
	PARSER_L2_PROTOCOL__1588             = 13,
	PARSER_L2_PROTOCOL__802_1X           = 14,
	PARSER_L2_PROTOCOL_MASK              = 15,
	PARSER_L2_PROTOCOL__802_1AG_CFM      = 15,
	PARSER_L2_PROTOCOL_LAST =           15
} rdd_parser_l2_protocol;
typedef enum
{
	PARSER_L3_PROTOCOL_FIRST = 0,
	PARSER_L3_PROTOCOL_OTHER    = 0,
	PARSER_L3_PROTOCOL_IPV4     = 1,
	PARSER_L3_PROTOCOL_IPV6     = 2,
	PARSER_L3_PROTOCOL_MASK     = 3,
	PARSER_L3_PROTOCOL_LAST =  3
} rdd_parser_l3_protocol;
typedef enum
{
	PARSER_L4_PROTOCOL_FIRST =          0,
	PARSER_L4_PROTOCOL_OTHER             = 0,
	PARSER_L4_PROTOCOL_TCP               = 1,
	PARSER_L4_PROTOCOL_UDP               = 2,
	PARSER_L4_PROTOCOL_IGMP              = 3,
	PARSER_L4_PROTOCOL_ICMP              = 4,
	PARSER_L4_PROTOCOL_ICMPV6            = 5,
	PARSER_L4_PROTOCOL_ESP               = 6,
	PARSER_L4_PROTOCOL_GRE               = 7,
	PARSER_L4_PROTOCOL_USER_DEFINED_0    = 8,
	PARSER_L4_PROTOCOL_USER_DEFINED_1    = 9,
	PARSER_L4_PROTOCOL_USER_DEFINED_2    = 10,
	PARSER_L4_PROTOCOL_USER_DEFINED_3    = 11,
	PARSER_L4_PROTOCOL_RESERVED          = 12,
	PARSER_L4_PROTOCOL_IPV6              = 13,
	PARSER_L4_PROTOCOL_AH                = 14,
	PARSER_L4_PROTOCOL_NOT_PARSED        = 15,
	PARSER_L4_PROTOCOL_MASK              = 15,
	PARSER_L4_PROTOCOL_LAST =           15
} rdd_parser_l4_protocol;
typedef enum
{
	ACTION_ECN_FIRST =            0,
	ACTION_ECN_REMARKING_OFFSET    = 0,
	ACTION_ECN_REMARKING_WIDTH     = 2,
	ACTION_ECN_LAST =             2
} rdd_action_ecn;
typedef enum
{
	ACTION_DSCP_FIRST =                          2,
	ACTION_DSCP_REMARKING_OFFSET                  = 2,
	ACTION_DSCP_REMARKING_TRAFFIC_CLASS_OFFSET    = 4,
	ACTION_DSCP_REMARKING_WIDTH                   = 6,
	ACTION_DSCP_REMARKING_TRAFFIC_CLASS_WIDTH     = 8,
	ACTION_DSCP_LAST =                           8
} rdd_action_dscp;
typedef enum
{
	ACTION_OUTER_FIRST =                      14,
	ACTION_OUTER_PBITS_REMARKING_VID_OFFSET    = 14,
	ACTION_OUTER_LAST =                       14
} rdd_action_outer;
typedef enum
{
	ACTION_INNER_FIRST =                      18,
	ACTION_INNER_PBITS_REMARKING_VID_OFFSET    = 18,
	ACTION_INNER_LAST =                       18
} rdd_action_inner;
typedef enum
{
	ACTION_PBITS_FIRST =                   2,
	ACTION_PBITS_REMARKING_DSCP_OFFSET      = 2,
	ACTION_PBITS_REMARKING_PACKET_WIDTH     = 3,
	ACTION_PBITS_REMARKING_DSCP_WIDTH       = 6,
	ACTION_PBITS_REMARKING_PACKET_OFFSET    = 13,
	ACTION_PBITS_LAST =                    13
} rdd_action_pbits;
typedef enum
{
	ACTION_DS_LITE_FIRST = 40,
	ACTION_DS_LITE_SIZE    = 40,
	ACTION_DS_LITE_LAST = 40
} rdd_action_ds_lite;
typedef enum
{
	DS_ACTION_ID_FIRST =     0,
	DS_ACTION_ID_TRAP         = 0,
	DS_ACTION_ID_TTL          = 2,
	DS_ACTION_ID_DSCP         = 4,
	DS_ACTION_ID_NAT          = 5,
	DS_ACTION_ID_GRE          = 6,
	DS_ACTION_ID_OPBITS       = 7,
	DS_ACTION_ID_IPBITS       = 8,
	DS_ACTION_ID_DS_LITE      = 9,
	DS_ACTION_ID_PPPOE        = 10,
	DS_ACTION_ID_TOTAL_NUM    = 17,
	DS_ACTION_ID_LAST =      17
} rdd_ds_action_id;
typedef enum
{
	US_ACTION_ID_FIRST =     0,
	US_ACTION_ID_TRAP         = 0,
	US_ACTION_ID_TTL          = 2,
	US_ACTION_ID_DSCP         = 4,
	US_ACTION_ID_NAT          = 5,
	US_ACTION_ID_GRE          = 6,
	US_ACTION_ID_OPBITS       = 7,
	US_ACTION_ID_IPBITS       = 8,
	US_ACTION_ID_DS_LITE      = 9,
	US_ACTION_ID_PPPOE        = 10,
	US_ACTION_ID_TOTAL_NUM    = 17,
	US_ACTION_ID_LAST =      17
} rdd_us_action_id;
typedef enum
{
	RDD_VPORT_FIRST =  0,
	RDD_VPORT_ID_0      = 0,
	RDD_VPORT_ID_1      = 1,
	RDD_VPORT_ID_2      = 2,
	RDD_VPORT_ID_3      = 3,
	RDD_VPORT_ID_4      = 4,
	RDD_VPORT_ID_5      = 5,
	RDD_VPORT_ID_6      = 6,
	RDD_VPORT_ID_7      = 7,
	RDD_VPORT_ID_8      = 8,
	RDD_VPORT_ID_9      = 9,
	RDD_VPORT_ID_10     = 10,
	RDD_VPORT_ID_11     = 11,
	RDD_VPORT_ID_12     = 12,
	RDD_VPORT_ID_13     = 13,
	RDD_VPORT_ID_14     = 14,
	RDD_VPORT_ID_15     = 15,
	RDD_VPORT_ID_16     = 16,
	RDD_VPORT_ID_17     = 17,
	RDD_VPORT_ID_18     = 18,
	RDD_VPORT_ID_19     = 19,
	RDD_VPORT_ID_20     = 20,
	RDD_VPORT_ID_21     = 21,
	RDD_VPORT_ID_22     = 22,
	RDD_VPORT_ID_23     = 23,
	RDD_VPORT_ID_24     = 24,
	RDD_VPORT_ID_25     = 25,
	RDD_VPORT_ID_26     = 26,
	RDD_VPORT_ID_27     = 27,
	RDD_VPORT_ID_28     = 28,
	RDD_VPORT_ID_29     = 29,
	RDD_VPORT_ID_30     = 30,
	RDD_VPORT_ID_31     = 31,
	RDD_VPORT_ID_32     = 32,
	RDD_VPORT_ID_33     = 33,
	RDD_VPORT_ID_34     = 34,
	RDD_VPORT_ID_35     = 35,
	RDD_VPORT_ID_36     = 36,
	RDD_VPORT_ID_37     = 37,
	RDD_VPORT_ID_38     = 38,
	RDD_VPORT_ID_39     = 39,
	RDD_VPORT_ID_ANY    = 40,
	RDD_VPORT_LAST =   40
} rdd_rdd_vport;
typedef enum
{
	DSCP_TO_FIRST =              6,
	DSCP_TO_PBITS_SHIFT_OFFSET    = 6,
	DSCP_TO_LAST =               6
} rdd_dscp_to;
typedef enum
{
	RESOLUTION_CONTEXT_FIRST =                       0,
	RESOLUTION_CONTEXT_VIRTUAL_SRC_PORT_OFFSET        = 0,
	RESOLUTION_CONTEXT_GPE_DMA_OFFSET_WIDTH           = 1,
	RESOLUTION_CONTEXT_GPE_HEADER_LENGTH_WIDTH        = 1,
	RESOLUTION_CONTEXT_GPE_HEADER_IH_PTR_WIDTH        = 2,
	RESOLUTION_CONTEXT_GPE_COMMAND_LIST_PTR_WIDTH     = 2,
	RESOLUTION_CONTEXT_GPE_PACKET_DRR_PTR_WIDTH       = 4,
	RESOLUTION_CONTEXT_GPE_HEADER_LENGTH_OFFSET       = 6,
	RESOLUTION_CONTEXT_GPE_DMA_OFFSET_OFFSET          = 7,
	RESOLUTION_CONTEXT_GPE_COMMAND_LIST_PTR_OFFSET    = 8,
	RESOLUTION_CONTEXT_GPE_HEADER_IH_PTR_OFFSET       = 10,
	RESOLUTION_CONTEXT_GPE_PACKET_DRR_PTR_OFFSET      = 12,
	RESOLUTION_CONTEXT_LAST =                        12
} rdd_resolution_context;
typedef enum
{
	FR_FORMAT_FIRST =     0,
	FR_FORMAT_WI_WI64      = 0,
	FR_FORMAT_WI_CWI32     = 1,
	FR_FORMAT_WI_CWI64     = 2,
	FR_FORMAT_WI_ACWI32    = 3,
	FR_FORMAT_WI_ACWI64    = 4,
	FR_FORMAT_LAST =      4
} rdd_fr_format;
#endif
#endif /* _RDD_DATA_STRUCTURES_AUTO_H */
