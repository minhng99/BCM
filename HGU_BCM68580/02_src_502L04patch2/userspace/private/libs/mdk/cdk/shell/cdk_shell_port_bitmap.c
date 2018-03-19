/*
 * $Id: cdk_shell_port_bitmap.c,v 1.4 Broadcom SDK $
 * $Copyright: Copyright 2013 Broadcom Corporation.
 * This program is the proprietary software of Broadcom Corporation
 * and/or its licensors, and may only be used, duplicated, modified
 * or distributed pursuant to the terms and conditions of a separate,
 * written license agreement executed between you and Broadcom
 * (an "Authorized License").  Except as set forth in an Authorized
 * License, Broadcom grants no license (express or implied), right
 * to use, or waiver of any kind with respect to the Software, and
 * Broadcom expressly reserves all rights in and to the Software
 * and all intellectual property rights therein.  IF YOU HAVE
 * NO AUTHORIZED LICENSE, THEN YOU HAVE NO RIGHT TO USE THIS SOFTWARE
 * IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY BROADCOM AND DISCONTINUE
 * ALL USE OF THE SOFTWARE.  
 *  
 * Except as expressly set forth in the Authorized License,
 *  
 * 1.     This program, including its structure, sequence and organization,
 * constitutes the valuable trade secrets of Broadcom, and you shall use
 * all reasonable efforts to protect the confidentiality thereof,
 * and to use this information only in connection with your use of
 * Broadcom integrated circuit products.
 *  
 * 2.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS
 * PROVIDED "AS IS" AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES,
 * REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY,
 * OR OTHERWISE, WITH RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY
 * DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY,
 * NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES,
 * ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING
 * OUT OF USE OR PERFORMANCE OF THE SOFTWARE.
 * 
 * 3.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 * BROADCOM OR ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL,
 * INCIDENTAL, SPECIAL, INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER
 * ARISING OUT OF OR IN ANY WAY RELATING TO YOUR USE OF OR INABILITY
 * TO USE THE SOFTWARE EVEN IF BROADCOM HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES; OR (ii) ANY AMOUNT IN EXCESS OF
 * THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF OR USD 1.00,
 * WHICHEVER IS GREATER. THESE LIMITATIONS SHALL APPLY NOTWITHSTANDING
 * ANY FAILURE OF ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.$
 */

#include <cdk/cdk_chip.h>
#include <cdk/cdk_printf.h>
#include <cdk/cdk_shell.h>

/*
 * Function:
 *	cdk_shell_bit_range
 * Purpose:
 *	Create bit range string
 * Parameters:
 *	buf - (OUT) output buffer for bit range string
 *	size - size of output buffer
 *	pbmp - port bitmap to print
 *	mask - port bitmap that determines how many words to print
 * Returns:
 *      Always 0
 */
int
cdk_shell_port_bitmap(char *buf, int size,
                      const cdk_pbmp_t *pbmp, const cdk_pbmp_t *mask)
{
    int idx, pbm_no, len;
    const char *cp;
    uint32_t pbm;

    /* Start with an empty string */
    buf[0] = 0;
    len = 0;

    if (pbmp  == NULL || mask == NULL) {
        return -1;
    }

    pbm_no = 0;
    for (idx = (CDK_PBMP_WORD_MAX - 1); idx >= 0; idx--) {
        pbm = CDK_PBMP_WORD_GET(*mask, idx);
        if (pbm || pbm_no) {
            pbm_no++;
        }
        if (pbm_no == 0) {
            continue;
        }
        if (pbm_no == 1) {
            cp = "0x";
        } else {
            cp = "_";
        }
        if ((size - len) > 0) {
            len += CDK_SNPRINTF(&buf[len], size - len, cp); 
        }
        pbm = CDK_PBMP_WORD_GET(*pbmp, idx);
        if ((size - len) > 0) {
            len += CDK_SNPRINTF(&buf[len], size - len, "%08"PRIx32"", pbm);
        }
    }

    /* Ensure string is properly terminated */
    buf[size - 1] = 0;

    return 0;
}