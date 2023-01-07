/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   tls_const.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains constants defined for TLS.
 *
 * Author:
 * -------
 *   Wyatt Sun
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 19 2012 archilis.wang
 * [ALPS00303520] [Merge] Level 3 SW modules ���ɦ� Level 2 on ALPS.ICS2.MP
 * [Merge] Level 3 SW modules ���ɦ� Level 2 on ALPS.ICS2.MP
 *
 * Mar 31 2009 mtk01264
 * [MAUI_01655762] JAVA(OpenSSL)_ it can't get message
 * Support retrieving peer certificate on session resumption.
 *
 * Mar 17 2009 mtk01264
 * [MAUI_01646558] [TLS] Check-in OpenSSL and revise TLS
 * Check in revised TLS
 *
 * Dec 20 2007 mtk01264
 * [MAUI_00593347] [Email] Assert fail: 0 tls_common.c 687 - TLS
 * Add history log label
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _TLS_CONST_H_
#define _TLS_CONST_H_

#ifndef __cplusplus

/******************************************************************************
 * <GROUP Constants>
 *
 * Maximum number of concurrent supported global contexts.
 * Ref. tls_new_ctx().
******************************************************************************/
#define TLS_MAX_GLOBAL_CTX (3)



/******************************************************************************
 * <GROUP Constants>
 *
 * Maximum number of available ciphers.
 * Ref. tls_set_ciphers().
******************************************************************************/
#define TLS_MAX_CIPHERS             (MAX_CIPHER_NUM)



/******************************************************************************
 * <GROUP Constants>
 *
 * Limitation of processing certificate types in a certificate request message
 * from server.
 * Ref . app_tls_client_auth_ind_struct.
 ******************************************************************************/
#define TLS_MAX_CLIENT_AUTH         (7)



/******************************************************************************
 * <GROUP Constants>
 *
 * Special identifier to load all trusted certifictes in the system.
 * Ref. tls_set_verify().
******************************************************************************/
#define TLS_ALL_ROOT_CERTS          (0xFF)

#endif /* __cplusplus */
#endif /* !_TLS_CONST_H_ */


