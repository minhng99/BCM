#ifndef IMAGE_3_CODE_ADDRESSES
#define IMAGE_3_CODE_ADDRESSES

#define image_3_start_task_initialization_task		(0x18)
#define image_3_initialization_task		(0x18)
#define image_3_start_task_update_fifo_read_1st_wakeup_request		(0x1128)
#define image_3_update_fifo_read_1st_wakeup_request		(0x1128)
#define image_3_start_task_ghost_reporting_1st_wakeup_request		(0xC38)
#define image_3_ghost_reporting_1st_wakeup_request		(0xC38)
#define image_3_start_task_tx_task_1st_wakeup_request		(0x178)
#define image_3_tx_task_1st_wakeup_request		(0x178)
#define image_3_start_task_budget_allocator_1st_wakeup_request		(0x6A0)
#define image_3_budget_allocator_1st_wakeup_request		(0x6A0)
#define image_3_start_task_debug_routine		(0x8C)
#define image_3_debug_routine		(0x8C)
#define image_3_start_task_ovl_budget_allocator_1st_wakeup_request		(0x98C)
#define image_3_ovl_budget_allocator_1st_wakeup_request		(0x98C)
#define image_3_start_task_flush_task_1st_wakeup_request		(0x1040)
#define image_3_flush_task_1st_wakeup_request		(0x1040)
#define image_3_debug_routine_handler		(0xC)
#define image_3_scheduling_update_status		(0x3B8)
#define image_3_scheduling_action_not_valid		(0x454)
#define image_3_basic_scheduler_update_dwrr		(0x564)
#define image_3_complex_scheduler_update_dwrr_basic_schedulers		(0x66C)
#define image_3_complex_scheduler_update_dwrr_queues		(0x67C)
#define image_3_basic_rate_limiter_complex_scheduler		(0xA60)
#define image_3_basic_rate_limiter_basic_scheduler_no_cs		(0xA90)
#define image_3_basic_rate_limiter_queue_with_cs_bs		(0xAC0)
#define image_3_basic_rate_limiter_queue_with_bs		(0xB10)
#define image_3_ovl_rate_limiter		(0xB44)
#define image_3_complex_rate_limiter_queue_sir		(0xB58)
#define image_3_complex_rate_limiter_queue_pir		(0xB90)
#define image_3_complex_rate_limiter_basic_scheduler_sir		(0xBC8)
#define image_3_complex_rate_limiter_basic_scheduler_pir		(0xC00)

#endif
