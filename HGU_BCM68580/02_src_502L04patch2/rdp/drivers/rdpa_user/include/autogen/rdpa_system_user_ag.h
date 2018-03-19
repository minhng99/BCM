// <:copyright-BRCM:2013:DUAL/GPL:standard
// 
//    Copyright (c) 2013 Broadcom 
//    All Rights Reserved
// 
// Unless you and Broadcom execute a separate written software license
// agreement governing use of this software, this software is licensed
// to you under the terms of the GNU General Public License version 2
// (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
// with the following added to such license:
// 
//    As a special exception, the copyright holders of this software give
//    you permission to link this software with independent modules, and
//    to copy and distribute the resulting executable under terms of your
//    choice, provided that you also meet, for each linked independent
//    module, the terms and conditions of the license of that module.
//    An independent module is a module which is not derived from this
//    software.  The special exception does not apply to any modifications
//    of the software.
// 
// Not withstanding the above, under no circumstances may you combine
// this software in any way with any other Broadcom software provided
// under a license other than the GPL, without Broadcom's express prior
// written consent.
// 
// :>
/*
 * system object user header file.
 * This header file is generated automatically. Do not edit!
 */
#ifndef _RDPA_AG_SYSTEM_USR_H_
#define _RDPA_AG_SYSTEM_USR_H_

#include <sys/ioctl.h>
#include "rdpa_user.h"
#include "rdpa_user_types.h"
#include "rdpa_system_user_ioctl_ag.h"

/** \addtogroup system
 * @{
 */


/** Get system type handle.
 *
 * This handle should be passed to bdmf_new_and_set() function in
 * order to create a system object.
 * \return system type handle
 */
static inline bdmf_type_handle rdpa_system_drv(void)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret = 0;

	pa.cmd = RDPA_SYSTEM_DRV;
	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return 0;
	}

	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, Errno[%s] ret=%d\n", strerror(errno), ret);
		close(fd);
		return 0;
	}

	close(fd);
	return pa.drv;
}

/** Get system object.

 * This function returns system object instance.
 * \param[out] system_obj    Object handle
 * \return    0=OK or error <0
 */
static inline int rdpa_system_get(bdmf_object_handle *system_obj)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret = 0;

	pa.cmd = RDPA_SYSTEM_GET;
	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, Errno[%s] ret=%d\n", strerror(errno), ret);
		close(fd);
		return ret;
	}

	*system_obj = pa.mo;
	close(fd);
	return pa.ret;
}

/** Get system/init_cfg attribute.
 *
 * Get Initial System Configuration.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[out]  init_cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_system_init_cfg_get(bdmf_object_handle mo_, rdpa_system_init_cfg_t * init_cfg_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ptr = (uint32_t)init_cfg_;
	pa.cmd = RDPA_SYSTEM_INIT_CFG_GET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Set system/init_cfg attribute.
 *
 * Set Initial System Configuration.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   init_cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_system_init_cfg_set(bdmf_object_handle mo_, const rdpa_system_init_cfg_t * init_cfg_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ptr = (uint32_t)init_cfg_;
	pa.cmd = RDPA_SYSTEM_INIT_CFG_SET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Get system/cfg attribute.
 *
 * Get System Configuration that can be changes in run-time.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[out]  cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_cfg_get(bdmf_object_handle mo_, rdpa_system_cfg_t * cfg_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ptr = (uint32_t)cfg_;
	pa.cmd = RDPA_SYSTEM_CFG_GET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Set system/cfg attribute.
 *
 * Set System Configuration that can be changes in run-time.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_cfg_set(bdmf_object_handle mo_, const rdpa_system_cfg_t * cfg_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ptr = (uint32_t)cfg_;
	pa.cmd = RDPA_SYSTEM_CFG_SET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Get system/sw_version attribute.
 *
 * Get software version.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[out]  sw_version_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_sw_version_get(bdmf_object_handle mo_, rdpa_sw_version_t * sw_version_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ptr = (uint32_t)sw_version_;
	pa.cmd = RDPA_SYSTEM_SW_VERSION_GET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Get system/clock_gate attribute.
 *
 * Get Enable/Disable clock auto-gating feature.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[out]  clock_gate_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_clock_gate_get(bdmf_object_handle mo_, bdmf_boolean *clock_gate_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ptr = (uint32_t)clock_gate_;
	pa.cmd = RDPA_SYSTEM_CLOCK_GATE_GET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Set system/clock_gate attribute.
 *
 * Set Enable/Disable clock auto-gating feature.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   clock_gate_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_clock_gate_set(bdmf_object_handle mo_, bdmf_boolean clock_gate_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.parm = (uint64_t)(long)clock_gate_;
	pa.cmd = RDPA_SYSTEM_CLOCK_GATE_SET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Get system/drop_precedence attribute entry.
 *
 * Get Drop precedence flow entry.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  drop_precedence_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_drop_precedence_get(bdmf_object_handle mo_, rdpa_dp_key_t * ai_, bdmf_boolean *drop_precedence_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ai_ptr = (uint32_t)ai_;
	pa.ptr = (uint32_t)drop_precedence_;
	pa.cmd = RDPA_SYSTEM_DROP_PRECEDENCE_GET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Set system/drop_precedence attribute entry.
 *
 * Set Drop precedence flow entry.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[in]   drop_precedence_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_drop_precedence_set(bdmf_object_handle mo_, rdpa_dp_key_t * ai_, bdmf_boolean drop_precedence_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ai_ptr = (uint32_t)ai_;
	pa.parm = (uint64_t)(long)drop_precedence_;
	pa.cmd = RDPA_SYSTEM_DROP_PRECEDENCE_SET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Get next system/drop_precedence attribute entry.
 *
 * Get next Drop precedence flow entry.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in,out]   ai_ Attribute array index
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_drop_precedence_get_next(bdmf_object_handle mo_, rdpa_dp_key_t * ai_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ai_ptr = (uint32_t)ai_;
	pa.cmd = RDPA_SYSTEM_DROP_PRECEDENCE_GET_NEXT;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Get system/tpid_detect attribute entry.
 *
 * Get TPID Detect.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  tpid_detect_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_tpid_detect_get(bdmf_object_handle mo_, rdpa_tpid_detect_t ai_, rdpa_tpid_detect_cfg_t * tpid_detect_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ai = (bdmf_index)(long)ai_;
	pa.ptr = (uint32_t)tpid_detect_;
	pa.cmd = RDPA_SYSTEM_TPID_DETECT_GET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Set system/tpid_detect attribute entry.
 *
 * Set TPID Detect.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[in]   tpid_detect_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_tpid_detect_set(bdmf_object_handle mo_, rdpa_tpid_detect_t ai_, const rdpa_tpid_detect_cfg_t * tpid_detect_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ai = (bdmf_index)(long)ai_;
	pa.ptr = (uint32_t)tpid_detect_;
	pa.cmd = RDPA_SYSTEM_TPID_DETECT_SET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Get system/tod attribute.
 *
 * Get Time Of Day.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[out]  tod_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_tod_get(bdmf_object_handle mo_, rdpa_system_tod_t * tod_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ptr = (uint32_t)tod_;
	pa.cmd = RDPA_SYSTEM_TOD_GET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Get system/cpu_reason_to_tc attribute entry.
 *
 * Get CPU Reason to TC global configuration.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  cpu_reason_to_tc_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_cpu_reason_to_tc_get(bdmf_object_handle mo_, rdpa_cpu_reason ai_, bdmf_number *cpu_reason_to_tc_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ai = (bdmf_index)(long)ai_;
	pa.ptr = (uint32_t)cpu_reason_to_tc_;
	pa.cmd = RDPA_SYSTEM_CPU_REASON_TO_TC_GET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Set system/cpu_reason_to_tc attribute entry.
 *
 * Set CPU Reason to TC global configuration.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[in]   cpu_reason_to_tc_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_cpu_reason_to_tc_set(bdmf_object_handle mo_, rdpa_cpu_reason ai_, bdmf_number cpu_reason_to_tc_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ai = (bdmf_index)(long)ai_;
	pa.parm = (uint64_t)(long)cpu_reason_to_tc_;
	pa.cmd = RDPA_SYSTEM_CPU_REASON_TO_TC_SET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Get system/qm_cfg attribute.
 *
 * Get Configuration for dynamic Queue allocation.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[out]  qm_cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_system_qm_cfg_get(bdmf_object_handle mo_, rdpa_qm_cfg_t * qm_cfg_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ptr = (uint32_t)qm_cfg_;
	pa.cmd = RDPA_SYSTEM_QM_CFG_GET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}


/** Set system/qm_cfg attribute.
 *
 * Set Configuration for dynamic Queue allocation.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   qm_cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_system_qm_cfg_set(bdmf_object_handle mo_, const rdpa_qm_cfg_t * qm_cfg_)
{
	rdpa_ioctl_cmd_t pa = {0};
	int fd, ret;

	pa.mo = mo_;
	pa.ptr = (uint32_t)qm_cfg_;
	pa.cmd = RDPA_SYSTEM_QM_CFG_SET;

	fd = open(RDPA_USR_DEV_NAME, O_RDWR);
	if (fd < 0)
	{
		rdpa_usr_error("%s: %s\n", RDPA_USR_DEV_NAME, strerror(errno));
		return -EINVAL;
	}
	ret = ioctl(fd, RDPA_SYSTEM_IOCTL, &pa);
	if (ret)
	{
		rdpa_usr_error("ioctl failed, ret=%d\n", ret);
		close(fd);
		return ret;
	}

	close(fd);
	return pa.ret;
}

/** @} end of system Doxygen group */




#endif /* _RDPA_AG_SYSTEM_USR_H_ */
