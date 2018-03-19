/*
 * system object ioctl functions implementation file.
 * This ioctl file is generated automatically. Do not edit!
 */
#include "rdpa_api.h"
#include "rdpa_user.h"
#include "rdpa_user_int.h"
#include "rdpa_system_user_ioctl_ag.h"

static int rdpa_user_system_drv(rdpa_ioctl_cmd_t *pa)
{
	BDMF_TRACE_DBG("inside rdpa_user_system_drv\n");

	if (!(pa->drv = rdpa_system_drv()))
	{
		BDMF_TRACE_DBG("rdpa_system_drv failed\n");
	}

	return 0;
}

static int rdpa_user_system_get(rdpa_ioctl_cmd_t *pa)
{
	BDMF_TRACE_DBG("inside rdpa_user_system_drv\n");

	if ((pa->ret = rdpa_system_get(&pa->mo)))
	{
		BDMF_TRACE_DBG("rdpa_system_get failed ret: %d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_system_init_cfg_get(rdpa_ioctl_cmd_t *pa)
{
	rdpa_system_init_cfg_t  parm;

	BDMF_TRACE_DBG("inside system_user_init_cfg_get\n");

	if ((pa->ret = rdpa_system_init_cfg_get(pa->mo, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_init_cfg_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(rdpa_system_init_cfg_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_system_init_cfg_set(rdpa_ioctl_cmd_t *pa)
{
	rdpa_system_init_cfg_t  parm;

	BDMF_TRACE_DBG("inside system_user_init_cfg_set\n");

	if (copy_from_user((void *)&parm, (void *)(long)pa->ptr, sizeof(rdpa_system_init_cfg_t )))
	{
		BDMF_TRACE_ERR("failed to copy from user\n");
		return -1;
	}

	if ((pa->ret = rdpa_system_init_cfg_set(pa->mo, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_init_cfg_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_system_cfg_get(rdpa_ioctl_cmd_t *pa)
{
	rdpa_system_cfg_t  parm;

	BDMF_TRACE_DBG("inside system_user_cfg_get\n");

	if ((pa->ret = rdpa_system_cfg_get(pa->mo, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_cfg_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(rdpa_system_cfg_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_system_cfg_set(rdpa_ioctl_cmd_t *pa)
{
	rdpa_system_cfg_t  parm;

	BDMF_TRACE_DBG("inside system_user_cfg_set\n");

	if (copy_from_user((void *)&parm, (void *)(long)pa->ptr, sizeof(rdpa_system_cfg_t )))
	{
		BDMF_TRACE_ERR("failed to copy from user\n");
		return -1;
	}

	if ((pa->ret = rdpa_system_cfg_set(pa->mo, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_cfg_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_system_sw_version_get(rdpa_ioctl_cmd_t *pa)
{
	rdpa_sw_version_t  parm;

	BDMF_TRACE_DBG("inside system_user_sw_version_get\n");

	if ((pa->ret = rdpa_system_sw_version_get(pa->mo, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_sw_version_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(rdpa_sw_version_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_system_clock_gate_get(rdpa_ioctl_cmd_t *pa)
{
	bdmf_boolean parm;

	BDMF_TRACE_DBG("inside system_user_clock_gate_get\n");

	if ((pa->ret = rdpa_system_clock_gate_get(pa->mo, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_clock_gate_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(bdmf_boolean)))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_system_clock_gate_set(rdpa_ioctl_cmd_t *pa)
{

	BDMF_TRACE_DBG("inside system_user_clock_gate_set\n");

	if ((pa->ret = rdpa_system_clock_gate_set(pa->mo, (bdmf_boolean)(long)pa->parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_clock_gate_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_system_drop_precedence_get(rdpa_ioctl_cmd_t *pa)
{
	rdpa_dp_key_t  ai;
	bdmf_boolean parm;

	BDMF_TRACE_DBG("inside system_user_drop_precedence_get\n");

	if (copy_from_user((void *)&ai, (void *)(long)pa->ai_ptr, sizeof(rdpa_dp_key_t )))
	{
		BDMF_TRACE_ERR("failed to copy from user\n");
		return -1;
	}

	if ((pa->ret = rdpa_system_drop_precedence_get(pa->mo, &ai, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_drop_precedence_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ai_ptr, (void *)&ai, sizeof(rdpa_dp_key_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(bdmf_boolean)))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_system_drop_precedence_set(rdpa_ioctl_cmd_t *pa)
{
	rdpa_dp_key_t  ai;

	BDMF_TRACE_DBG("inside system_user_drop_precedence_set\n");

	if (copy_from_user((void *)&ai, (void *)(long)pa->ai_ptr, sizeof(rdpa_dp_key_t )))
	{
		BDMF_TRACE_ERR("failed to copy from user\n");
		return -1;
	}

	if ((pa->ret = rdpa_system_drop_precedence_set(pa->mo, &ai, (bdmf_boolean)(long)pa->parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_drop_precedence_set failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ai_ptr, (void *)&ai, sizeof(rdpa_dp_key_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_system_drop_precedence_get_next(rdpa_ioctl_cmd_t *pa)
{
	rdpa_dp_key_t  ai;

	BDMF_TRACE_DBG("inside system_user_drop_precedence_get_next\n");

	if (copy_from_user((void *)&ai, (void *)(long)pa->ai_ptr, sizeof(rdpa_dp_key_t )))
	{
		BDMF_TRACE_ERR("failed to copy from user\n");
		return -1;
	}

	if ((pa->ret = rdpa_system_drop_precedence_get_next(pa->mo, &ai)))
	{
		BDMF_TRACE_DBG("rdpa_system_drop_precedence_get_next failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ai_ptr, (void *)&ai, sizeof(rdpa_dp_key_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_system_tpid_detect_get(rdpa_ioctl_cmd_t *pa)
{
	rdpa_tpid_detect_cfg_t  parm;

	BDMF_TRACE_DBG("inside system_user_tpid_detect_get\n");

	if ((pa->ret = rdpa_system_tpid_detect_get(pa->mo, pa->ai, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_tpid_detect_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(rdpa_tpid_detect_cfg_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_system_tpid_detect_set(rdpa_ioctl_cmd_t *pa)
{
	rdpa_tpid_detect_cfg_t  parm;

	BDMF_TRACE_DBG("inside system_user_tpid_detect_set\n");

	if (copy_from_user((void *)&parm, (void *)(long)pa->ptr, sizeof(rdpa_tpid_detect_cfg_t )))
	{
		BDMF_TRACE_ERR("failed to copy from user\n");
		return -1;
	}

	if ((pa->ret = rdpa_system_tpid_detect_set(pa->mo, pa->ai, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_tpid_detect_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_system_tod_get(rdpa_ioctl_cmd_t *pa)
{
	rdpa_system_tod_t  parm;

	BDMF_TRACE_DBG("inside system_user_tod_get\n");

	if ((pa->ret = rdpa_system_tod_get(pa->mo, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_tod_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(rdpa_system_tod_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_system_cpu_reason_to_tc_get(rdpa_ioctl_cmd_t *pa)
{
	bdmf_number parm;

	BDMF_TRACE_DBG("inside system_user_cpu_reason_to_tc_get\n");

	if ((pa->ret = rdpa_system_cpu_reason_to_tc_get(pa->mo, pa->ai, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_cpu_reason_to_tc_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(bdmf_number)))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_system_cpu_reason_to_tc_set(rdpa_ioctl_cmd_t *pa)
{

	BDMF_TRACE_DBG("inside system_user_cpu_reason_to_tc_set\n");

	if ((pa->ret = rdpa_system_cpu_reason_to_tc_set(pa->mo, pa->ai, (bdmf_number)(long)pa->parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_cpu_reason_to_tc_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_system_qm_cfg_get(rdpa_ioctl_cmd_t *pa)
{
	rdpa_qm_cfg_t  parm;

	BDMF_TRACE_DBG("inside system_user_qm_cfg_get\n");

	if ((pa->ret = rdpa_system_qm_cfg_get(pa->mo, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_qm_cfg_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(rdpa_qm_cfg_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_system_qm_cfg_set(rdpa_ioctl_cmd_t *pa)
{
	rdpa_qm_cfg_t  parm;

	BDMF_TRACE_DBG("inside system_user_qm_cfg_set\n");

	if (copy_from_user((void *)&parm, (void *)(long)pa->ptr, sizeof(rdpa_qm_cfg_t )))
	{
		BDMF_TRACE_ERR("failed to copy from user\n");
		return -1;
	}

	if ((pa->ret = rdpa_system_qm_cfg_set(pa->mo, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_system_qm_cfg_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

long rdpa_system_ag_ioctl(unsigned int op, rdpa_ioctl_cmd_t *pa)
{
	int ret;

	switch (op){
		case RDPA_SYSTEM_DRV:
			ret = rdpa_user_system_drv(pa);
			break;

		case RDPA_SYSTEM_GET:
			ret = rdpa_user_system_get(pa);
			break;

		case RDPA_SYSTEM_INIT_CFG_GET:
			ret = rdpa_user_system_init_cfg_get(pa);
			break;

		case RDPA_SYSTEM_INIT_CFG_SET:
			ret = rdpa_user_system_init_cfg_set(pa);
			break;

		case RDPA_SYSTEM_CFG_GET:
			ret = rdpa_user_system_cfg_get(pa);
			break;

		case RDPA_SYSTEM_CFG_SET:
			ret = rdpa_user_system_cfg_set(pa);
			break;

		case RDPA_SYSTEM_SW_VERSION_GET:
			ret = rdpa_user_system_sw_version_get(pa);
			break;

		case RDPA_SYSTEM_CLOCK_GATE_GET:
			ret = rdpa_user_system_clock_gate_get(pa);
			break;

		case RDPA_SYSTEM_CLOCK_GATE_SET:
			ret = rdpa_user_system_clock_gate_set(pa);
			break;

		case RDPA_SYSTEM_DROP_PRECEDENCE_GET:
			ret = rdpa_user_system_drop_precedence_get(pa);
			break;

		case RDPA_SYSTEM_DROP_PRECEDENCE_SET:
			ret = rdpa_user_system_drop_precedence_set(pa);
			break;

		case RDPA_SYSTEM_DROP_PRECEDENCE_GET_NEXT:
			ret = rdpa_user_system_drop_precedence_get_next(pa);
			break;

		case RDPA_SYSTEM_TPID_DETECT_GET:
			ret = rdpa_user_system_tpid_detect_get(pa);
			break;

		case RDPA_SYSTEM_TPID_DETECT_SET:
			ret = rdpa_user_system_tpid_detect_set(pa);
			break;

		case RDPA_SYSTEM_TOD_GET:
			ret = rdpa_user_system_tod_get(pa);
			break;

		case RDPA_SYSTEM_CPU_REASON_TO_TC_GET:
			ret = rdpa_user_system_cpu_reason_to_tc_get(pa);
			break;

		case RDPA_SYSTEM_CPU_REASON_TO_TC_SET:
			ret = rdpa_user_system_cpu_reason_to_tc_set(pa);
			break;

		case RDPA_SYSTEM_QM_CFG_GET:
			ret = rdpa_user_system_qm_cfg_get(pa);
			break;

		case RDPA_SYSTEM_QM_CFG_SET:
			ret = rdpa_user_system_qm_cfg_set(pa);
			break;

		default:
			BDMF_TRACE_ERR("no such ioctl cmd: %u\n", op);
			ret = EINVAL;
		}

	return ret;
}
