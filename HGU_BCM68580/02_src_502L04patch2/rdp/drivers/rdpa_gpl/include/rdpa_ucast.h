/*
* <:copyright-BRCM:2013:DUAL/GPL:standard
* 
*    Copyright (c) 2013 Broadcom 
*    All Rights Reserved
* 
* Unless you and Broadcom execute a separate written software license
* agreement governing use of this software, this software is licensed
* to you under the terms of the GNU General Public License version 2
* (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
* with the following added to such license:
* 
*    As a special exception, the copyright holders of this software give
*    you permission to link this software with independent modules, and
*    to copy and distribute the resulting executable under terms of your
*    choice, provided that you also meet, for each linked independent
*    module, the terms and conditions of the license of that module.
*    An independent module is a module which is not derived from this
*    software.  The special exception does not apply to any modifications
*    of the software.
* 
* Not withstanding the above, under no circumstances may you combine
* this software in any way with any other Broadcom software provided
* under a license other than the GPL, without Broadcom's express prior
* written consent.
* 
* :> 
*/

#ifndef _RDPA_UCAST_H_
#define _RDPA_UCAST_H_

#include <bdmf_interface.h>
#include "rdpa_ip_class_basic.h"
#include "rdpa_cpu.h"
#include "rdpa_egress_tm.h"
#include "rdpa_cmd_list.h"

#define RDPA_UCAST_IP_ADDRESSES_TABLE_SIZE           4
#define RDPA_UCAST_IP_ADDRESSES_TABLE_INDEX_INVALID  RDPA_UCAST_IP_ADDRESSES_TABLE_SIZE

#define RDPA_UCAST_MAX_DS_WAN_UDP_FILTERS            32

#define RDPA_UCAST_IP_HOST_ADDRESS_TABLE_SIZE         8

#if defined(DSL_63138) || defined(DSL_63148) || defined (WL4908) || defined(BCM63158)
/* Count of MAC entries implemented in runner firmware: */
#define RDPA_FIRMWARE_MAC_DA_FILT_COUNT              16
/* Count of IH hardware filters dedicated to other purposes (of the 8 total) */
#define RDPA_IH_DA_FILTER_MAC                         3
/* Number of usable IH mac filters */
#define RDP_DRV_IH_MAC_DA_FILT_COUNT                 (8 - RDPA_IH_DA_FILTER_MAC)
/* IH + Firmware filters available for our use */
#define RDPA_UCAST_HOST_MAC_ADDRESS_TABLE_SIZE       (RDP_DRV_IH_MAC_DA_FILT_COUNT + RDPA_FIRMWARE_MAC_DA_FILT_COUNT)
#else
#define RDPA_UCAST_HOST_MAC_ADDRESS_TABLE_SIZE       8
#endif

/** 5-tuple based IP flow classifaction result.\n
 * Each result determines L2/3/4 header manipulation, forwarding decision and QoS mapping information.\n
 */
typedef struct {
    rdpa_if egress_if;                                     /**< RDPA Egress Interface */
    uint32_t queue_id;                                     /**< Egress queue id */
    uint8_t service_queue_id;                              /**< Service queue id */
    int wan_flow;                                          /**< DSL ATM/PTM US channel */
    int wan_flow_mode;                                          /**< DSL ATM/PTM US channel */
    uint8_t is_routed;                                     /**< 1: Routed Flow; 0: Bridged Flow */
    uint8_t is_l2_accel;                                   /**< 1: L2 acceleratd Flow; 0: L3 accelerated Flow */
    uint8_t tc;                                            /**< 6-bit traffic class value */
    uint8_t is_wred_high_prio;                             /**< 1: WRED High Priority class, 0: WRED Low Priority class */
    uint8_t is_mapt_us;                                    /**< 1: MAP-T Upstream Flow; 0: Not MAP-T Upstream Flow */
    uint8_t is_df;                                         /**< 1: IPv4 DF flag set (Only used with is_mapt_us) */
    uint8_t drop;                                          /**< 1: Drop packets; 0: Forward packets */
    uint8_t ip_addresses_table_index;                      /**< IP Addresses Table index assigned to flow */
    uint16_t mtu;                                          /**< Egress Port MTU */
    uint8_t tos;                                           /**< Learned RX ToS value */
    uint8_t lag_port;                                      /**< Runner Egress LAG Port */
    union {
        uint32_t wl_metadata;                              /**< WL metadata */
        rdpa_wfd_t wfd;
        rdpa_rnr_t rnr;
    };
    uint8_t cmd_list_length;                               /**< Command List Length, in bytes */
    uint32_t cmd_list[RDPA_CMD_LIST_UCAST_LIST_SIZE_32];   /**< Command List */
} rdpa_ip_flow_result_t;

/** 5-tuple based IP flow classifaction info (key + result).\n
 */
typedef struct {
    rdpa_ip_flow_key_t key;          /**< 5-tuple based IP flow key */
    rdpa_ip_flow_result_t result;    /**< 5-tuple based IP flow result */
} rdpa_ip_flow_info_t;

/** IP SA/DA Address Table.\n
 */
typedef struct
{
    bdmf_ip_t src_addr;
    bdmf_ip_t dst_addr;
    uint16_t reference_count;
    uint16_t sram_address;
} rdpa_ip_addresses_table_t;

/** IP SA/DA Address Table.\n
 */
typedef struct
{
    uint32_t offset;
    uint32_t value;
    uint32_t mask;
    uint32_t hits;
} rdpa_ds_wan_udp_filter_t;

/** IPv4 Host Address Table.\n
 */
typedef struct
{
    bdmf_ipv4 ipv4_host_address;
    uint16_t  reference_count;
} rdpa_ipv4_host_address_table_t;

/** IPv6 Host Address Table.\n
 */
typedef struct
{
    bdmf_ipv6_t ipv6_host_address;
    uint16_t    reference_count;
} rdpa_ipv6_host_address_table_t;

/** Host MAC Address Table.\n
 */
typedef struct
{
    bdmf_mac_t host_mac_address;
    uint16_t  reference_count;
} rdpa_host_mac_address_table_t;

/** Flow Cache Accel Mode.\n
 */
typedef struct
{
    uint32_t  fc_accel_mode;
} rdpa_fc_accel_mode_t;

/** @} end of ip_class Doxygen group. */

#endif /* _RDPA_UCAST_H_ */
