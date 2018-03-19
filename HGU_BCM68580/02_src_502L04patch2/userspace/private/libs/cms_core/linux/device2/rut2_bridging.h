/***********************************************************************
 *
 *  Copyright (c) 2012  Broadcom Corporation
 *  All Rights Reserved
 *
<:label-BRCM:2012:proprietary:standard

 This program is the proprietary software of Broadcom and/or its
 licensors, and may only be used, duplicated, modified or distributed pursuant
 to the terms and conditions of a separate, written license agreement executed
 between you and Broadcom (an "Authorized License").  Except as set forth in
 an Authorized License, Broadcom grants no license (express or implied), right
 to use, or waiver of any kind with respect to the Software, and Broadcom
 expressly reserves all rights in and to the Software and all intellectual
 property rights therein.  IF YOU HAVE NO AUTHORIZED LICENSE, THEN YOU HAVE
 NO RIGHT TO USE THIS SOFTWARE IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY
 BROADCOM AND DISCONTINUE ALL USE OF THE SOFTWARE.

 Except as expressly set forth in the Authorized License,

 1. This program, including its structure, sequence and organization,
    constitutes the valuable trade secrets of Broadcom, and you shall use
    all reasonable efforts to protect the confidentiality thereof, and to
    use this information only in connection with your use of Broadcom
    integrated circuit products.

 2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
    AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
    WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
    RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND
    ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT,
    FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR
    COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE
    TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR
    PERFORMANCE OF THE SOFTWARE.

 3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR
    ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL,
    INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY
    WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
    IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES;
    OR (ii) ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE
    SOFTWARE ITSELF OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS
    SHALL APPLY NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY
    LIMITED REMEDY.
:>
 *
 ************************************************************************/

#ifndef __RUT2_BRIDGING_H__
#define __RUT2_BRIDGING_H__

/*!\file rut2_bridging.h
 * \brief Helper functions for BRIDGING functionality.
 *
 * In most cases, the functions in this file should only be called by
 * RCL, STL, and other RUT functions.
 */


#include "cms.h"

/** Given the iidStack of a bridge port, return the Linux interface
 *  name of the containing bridge (e.g. br0, br1, etc)
 *
 * @param iidStack         (IN) iidStack of the port object
 * @param bridgeIntfName  (OUT) The containing parent bridge
 *
 * @return CmsRet
 */
CmsRet rutBridge_getParentBridgeIntfName_dev2(const InstanceIdStack *iidStack,
                                              char *bridgeIntfName);


/** Add interface to a bridge.
 *
 * @param intfName   (IN) name of the interface to add to the bridge
 * @param brIntfName (IN) name of the bridge
 *
 * @return CmsRet
 */
CmsRet rutBridge_addIntfNameToBridge_dev2(const char *intfName, const char *brIntfName);


/** Add intf FullPath to a bridge.
 *
 * @param fullPath   (IN) fullpath to the interface to add to the bridge
 * @param brIntfName (IN) name of the bridge
 *
 * @return CmsRet
 */
CmsRet rutBridge_addFullPathToBridge_dev2(const char *fullPath, const char *brIntfName);


/** Remove the specified interface from its bridge.  Specifically, it
 *  deletes the Bridge.Port object, but it does not delete the
 *  interface object.
 *
 * @param intfName  (IN) name of the interface to remove from bridge
 *
 */
void rutBridge_deleteIntfNameFromBridge_dev2(const char *intfName);




#endif  /* __RUT2_BRIDGING_H__ */
