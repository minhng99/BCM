/****************************************************************************
*
*     <:copyright-BRCM:2001:proprietary:standard
*     
*        Copyright (c) 2001 Broadcom 
*        All Rights Reserved
*     
*      This program is the proprietary software of Broadcom and/or its
*      licensors, and may only be used, duplicated, modified or distributed pursuant
*      to the terms and conditions of a separate, written license agreement executed
*      between you and Broadcom (an "Authorized License").  Except as set forth in
*      an Authorized License, Broadcom grants no license (express or implied), right
*      to use, or waiver of any kind with respect to the Software, and Broadcom
*      expressly reserves all rights in and to the Software and all intellectual
*      property rights therein.  IF YOU HAVE NO AUTHORIZED LICENSE, THEN YOU HAVE
*      NO RIGHT TO USE THIS SOFTWARE IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY
*      BROADCOM AND DISCONTINUE ALL USE OF THE SOFTWARE.
*     
*      Except as expressly set forth in the Authorized License,
*     
*      1. This program, including its structure, sequence and organization,
*         constitutes the valuable trade secrets of Broadcom, and you shall use
*         all reasonable efforts to protect the confidentiality thereof, and to
*         use this information only in connection with your use of Broadcom
*         integrated circuit products.
*     
*      2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
*         AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
*         WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
*         RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND
*         ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT,
*         FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR
*         COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE
*         TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR
*         PERFORMANCE OF THE SOFTWARE.
*     
*      3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR
*         ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL,
*         INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY
*         WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
*         IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES;
*         OR (ii) ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE
*         SOFTWARE ITSELF OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS
*         SHALL APPLY NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY
*         LIMITED REMEDY.
*     :>
*****************************************************************************/
/**
*
*  @file    bosCritSectLinuxUser.c
*
*  @brief   LinuxUser implementation of the BOS Critical Section Module
*
****************************************************************************/

/* ---- Include Files ---------------------------------------------------- */

#include <bosCfg.h>

#if BOS_CFG_CRITSECT

#include <bosError.h>
#include <bosErrorLinuxUser.h>
#include <bosCritSect.h>
#include <bosCritSectPrivate.h>


/* ---- Public Variables ------------------------------------------------- */

#if BOS_CFG_CRITSECT_USE_GLOBAL
BOS_CRITSECT gBosGlobalCritSect;
BOS_CRITSECT *BOS_CFG_GLOBAL_CRITSECT = &gBosGlobalCritSect;
#endif

/* ---- Private Constants and Types -------------------------------------- */
/* ---- Private Variables ------------------------------------------------ */

static   BOS_BOOL gbosCritSectInitialized = BOS_FALSE;

/* ---- Private Function Prototypes -------------------------------------- */

/* ---- Functions -------------------------------------------------------- */

/***************************************************************************/

BOS_STATUS bosCritSectInit( void )
{
   BOS_ASSERT( !gbosCritSectInitialized );

   bosCritSectInitFunctionNames();

#if BOS_CFG_CRITSECT_USE_GLOBAL
   bosCritSectCreate( BOS_CFG_GLOBAL_CRITSECT );
#endif

   gbosCritSectInitialized = BOS_TRUE;

   return BOS_STATUS_OK;

} /* bosCritSectInit */

/***************************************************************************/

BOS_STATUS bosCritSectTerm( void )
{
   BOS_ASSERT( gbosCritSectInitialized );

   gbosCritSectInitialized = BOS_FALSE;

#if BOS_CFG_CRITSECT_USE_GLOBAL
   bosCritSectDestroy( BOS_CFG_GLOBAL_CRITSECT );
#endif

   return BOS_STATUS_OK;

} /* bosCritSectTerm */

/***************************************************************************/

BOS_STATUS bosCritSectCreate( BOS_CRITSECT* critSect )
{
   return bosMutexCreate( "CRSN", (BOS_MUTEX*)critSect );

} /* bosCritSectCreate */

/***************************************************************************/

BOS_STATUS bosCritSectDestroy( BOS_CRITSECT* critSect )
{
   return bosMutexDestroy( (BOS_MUTEX*)critSect );

} /* bosCritSectDestroy */

/***************************************************************************/

BOS_STATUS bosCritSectEnter( BOS_CRITSECT* critSect )
{
   return bosMutexAcquire( (BOS_MUTEX*)critSect );
} /* bosCritSectEnter */

/***************************************************************************/

BOS_STATUS bosCritSectLeave( BOS_CRITSECT* critSect )
{
   return bosMutexRelease( (BOS_MUTEX*)critSect );

} /* bosCritSectLeave */

#endif   /* BOS_CFG_CRITSECT */
