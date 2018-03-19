#ifndef IMAGE_5_CODE_ADDRESSES
#define IMAGE_5_CODE_ADDRESSES

#define image_5_start_task_initialization_task		(0x18)
#define image_5_initialization_task		(0x18)
#define image_5_start_task_processing_wakeup_request		(0xE00)
#define image_5_processing_wakeup_request		(0xE00)
#define image_5_start_task_debug_routine		(0x3274)
#define image_5_debug_routine		(0x3274)
#define image_5_debug_routine_handler		(0xC)
#define image_5_action_nat_ds		(0x4C)
#define image_5_action_nat_us		(0xF4)
#define image_5_action_ttl_decrement		(0x19C)
#define image_5_action_gre_remark		(0x218)
#define image_5_action_exception		(0x21C)
#define image_5_action_dscp_remarking_rule_based		(0x268)
#define image_5_action_dscp_remarking_flow_based		(0x2E0)
#define image_5_action_outer_pbits_remarking_ds		(0x358)
#define image_5_action_outer_pbits_remarking_us		(0x3F4)
#define image_5_action_pbits_remarking_rule_based		(0x490)
#define image_5_action_inner_pbits_remarking_ds		(0x4E0)
#define image_5_action_inner_pbits_remarking_us		(0x57C)
#define image_5_action_pppoe		(0x618)
#define image_5_action_dslite		(0x654)
#define image_5_action_l2gre		(0x8C8)
#define image_5_action_default		(0x8CC)
#define image_5_action_vlan_rule_base		(0x8D8)
#define image_5_action_vlan_iptv		(0x8EC)
#define image_5_action_tc_to_queue_iptv		(0x8F8)
#define image_5_action_tc_to_queue_ds_rule_based		(0x93C)
#define image_5_action_tc_to_queue_us_rule_based		(0x980)
#define image_5_action_iptv_exception		(0x9D4)
#define image_5_action_pbit_to_queue_ds_rule_based		(0x9D8)
#define image_5_action_pbit_to_queue_us_rule_based		(0xA48)
#define image_5_action_pbit_to_queue_local_switching		(0xAB8)
#define image_5_action_pbit_to_gem_us_rule_based		(0xB28)
#define image_5_action_no_fwd		(0xB8C)
#define image_5_action_no_fwd_iptv		(0xBD8)
#define image_5_action_drop_precedence_rule_based		(0xBEC)
#define image_5_action_llc_snap_set_len		(0xC90)
#define image_5_action_dei_rule_based		(0xD3C)
#define image_5_action_dei_flow_based		(0xDE0)
#define image_5_rule_based_resolution_invoke_bridge_ds		(0x14F0)
#define image_5_mcast_repl_0_header_update		(0x1894)
#define image_5_mcast_repl_res_loop_header_update		(0x1934)
#define image_5_processing_drop_packet		(0x19C4)
#define image_5_processing_header_update		(0x1A94)
#define image_5_processing_layer2_header_copy_30_bytes_8_bytes_align		(0x1B34)
#define image_5_processing_layer2_header_copy_22_bytes_8_bytes_align		(0x1B3C)
#define image_5_processing_layer2_header_copy_14_bytes_8_bytes_align		(0x1B44)
#define image_5_processing_layer2_header_copy_30_bytes_4_bytes_align		(0x1B58)
#define image_5_processing_layer2_header_copy_22_bytes_4_bytes_align		(0x1B68)
#define image_5_processing_layer2_header_copy_14_bytes_4_bytes_align		(0x1B78)
#define image_5_processing_layer2_header_copy_26_bytes_8_bytes_align		(0x1B98)
#define image_5_processing_layer2_header_copy_18_bytes_8_bytes_align		(0x1BA4)
#define image_5_processing_layer2_header_copy_18_bytes_4_bytes_align		(0x1BC8)
#define image_5_processing_layer2_header_copy_26_bytes_4_bytes_align		(0x1BD4)
#define image_5_processing_header_update_length_calc		(0x1BE0)
#define image_5_processing_done		(0x1C70)
#define image_5_mcast_resolution_common_actions_done		(0x1F80)
#define image_5_mcast_exception		(0x2234)
#define image_5_tcam_cmd_parser_1		(0x27B4)
#define image_5_tcam_cmd_parser_2		(0x27C0)
#define image_5_tcam_cmd_parser_4		(0x27CC)
#define image_5_tcam_cmd_parser_6		(0x27D8)
#define image_5_tcam_cmd_parser_8		(0x27F8)
#define image_5_tcam_cmd_packet		(0x2804)
#define image_5_tcam_cmd_l3_hdr		(0x2818)
#define image_5_tcam_cmd_l4_hdr		(0x2828)
#define image_5_tcam_cmd_ingress_port		(0x2880)
#define image_5_tcam_cmd_gem_flow		(0x288C)
#define image_5_tcam_cmd_src_ip		(0x2898)
#define image_5_tcam_cmd_dst_ip		(0x28C0)
#define image_5_gpe_cmd_replace_16		(0x2A94)
#define image_5_gpe_cmd_replace_32		(0x2A9C)
#define image_5_gpe_cmd_replace_bits_16		(0x2AB4)
#define image_5_gpe_cmd_copy_bits_16		(0x2AD4)
#define image_5_gpe_cmd_skip_if		(0x2B04)
#define image_5_gpe_vlan_action_cmd_drop		(0x2B24)
#define image_5_gpe_vlan_action_cmd_dscp		(0x2B28)
#define image_5_gpe_vlan_action_cmd_mac_hdr_copy		(0x2B80)
#define image_5_cpu_mcast_execution_engine_done		(0x3414)

#endif
