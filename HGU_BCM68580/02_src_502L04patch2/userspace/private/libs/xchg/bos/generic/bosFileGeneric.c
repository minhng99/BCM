/****************************************************************************
*
* <:copyright-BRCM:2002:proprietary:standard
* 
*    Copyright (c) 2002 Broadcom 
*    All Rights Reserved
* 
*  This program is the proprietary software of Broadcom and/or its
*  licensors, and may only be used, duplicated, modified or distributed pursuant
*  to the terms and conditions of a separate, written license agreement executed
*  between you and Broadcom (an "Authorized License").  Except as set forth in
*  an Authorized License, Broadcom grants no license (express or implied), right
*  to use, or waiver of any kind with respect to the Software, and Broadcom
*  expressly reserves all rights in and to the Software and all intellectual
*  property rights therein.  IF YOU HAVE NO AUTHORIZED LICENSE, THEN YOU HAVE
*  NO RIGHT TO USE THIS SOFTWARE IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY
*  BROADCOM AND DISCONTINUE ALL USE OF THE SOFTWARE.
* 
*  Except as expressly set forth in the Authorized License,
* 
*  1. This program, including its structure, sequence and organization,
*     constitutes the valuable trade secrets of Broadcom, and you shall use
*     all reasonable efforts to protect the confidentiality thereof, and to
*     use this information only in connection with your use of Broadcom
*     integrated circuit products.
* 
*  2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
*     AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
*     WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
*     RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND
*     ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT,
*     FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR
*     COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE
*     TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR
*     PERFORMANCE OF THE SOFTWARE.
* 
*  3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR
*     ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL,
*     INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY
*     WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
*     IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES;
*     OR (ii) ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE
*     SOFTWARE ITSELF OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS
*     SHALL APPLY NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY
*     LIMITED REMEDY.
* :>
*****************************************************************************/
/**
*
*  @file    bosFileGeneric.c
*
*  @brief   Contains OS independant definitions for the BOS File module.
*
****************************************************************************/

/* ---- Include Files ---------------------------------------------------- */

#include <bosCfg.h>

#if BOS_CFG_FILE

#include <bosFile.h>
#include <bosFilePrivate.h>
#include <bosError.h>

#if BOS_CFG_RESET_SUPPORT
#include <bosTask.h>
#endif

/**
 * @addtogroup bosFile
 * @{
 */

/* ---- Public Variables ------------------------------------------------- */

#if BOS_CFG_ERROR_FUNCTION_STRINGS

const char *gBosFileFunctionName[ BOS_FILE_NUM_FUNC_ID ];

#endif   /* BOS_CFG_ERROR_FUNCTION_STRINGS */

/* ---- Private Constants and Types -------------------------------------- */
/* ---- Private Variables ------------------------------------------------ */
/* ---- Private Function Prototypes -------------------------------------- */
/* ---- Functions -------------------------------------------------------- */

#if BOS_CFG_ERROR_FUNCTION_STRINGS

/***************************************************************************/
/**
*  Initializes the contents of @a gBosFileFunctionName, which is used to
*  translate function IDs into character strings.
*/

void bosFileInitFunctionNames( void )
{
   gBosFileFunctionName[ BOS_FILE_INIT_FUNC_ID  ] = "bosFileInit";
   gBosFileFunctionName[ BOS_FILE_TERM_FUNC_ID  ] = "bosFileTerm";
   gBosFileFunctionName[ BOS_FILE_OPEN_FUNC_ID  ] = "bosFileOpen";
   gBosFileFunctionName[ BOS_FILE_CLOSE_FUNC_ID ] = "bosFileClose";
   gBosFileFunctionName[ BOS_FILE_READ_FUNC_ID  ] = "bosFileRead";
   gBosFileFunctionName[ BOS_FILE_WRITE_FUNC_ID ] = "bosFileWrite";
   gBosFileFunctionName[ BOS_FILE_SEEK_FUNC_ID ] = "bosFileSeek";
   
   bosErrorAddFunctionStrings( BOS_FILE_MODULE, gBosFileFunctionName, BOS_FILE_NUM_FUNC_ID );

} /* bosFileInitFunctioNames */

#endif   /* BOS_CFG_ERROR_FUNCTION_STRINGS */

/***************************************************************************/

#if BOS_CFG_RESET_SUPPORT

/* Add logic for reset support code */

#endif   /* BOS_CFG_RESET_SUPPORT */

/** @} */

#endif   /* BOS_CFG_FILE */
