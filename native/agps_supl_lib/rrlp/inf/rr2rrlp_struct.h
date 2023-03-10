/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  rr2rrlp_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains SUPL task entry function.
 *
 * Author:
 * -------
 *  mtk01162 (Lanslo Yang)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 19 2012 archilis.wang
 * [ALPS00303520] [Merge] Level 3 SW modules ?????? Level 2 on ALPS.ICS2.MP
 * [Merge] Level 3 SW modules ?????? Level 2 on ALPS.ICS2.MP
 *
 * Feb 25 2008 mtk01162
 * [MAUI_00623349] [AGPS] AGPS feature check-in
 * 
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef RR2RRLP_STRUCT_H
#define RR2RRLP_STRUCT_H

typedef struct
{
   kal_uint16                 mcc;
   kal_uint16                 mnc;
   kal_uint16                 lac;
   kal_uint16                 ci;
   kal_uint8                  nmr_idx;         /* index to nmr_cell array */
}rr_rrlp_cell_info_struct;

typedef struct
{
   kal_uint16                 arfcn;
   kal_uint8                  bsic;
   kal_uint8                  rx_lev;
}rr_rrlp_nmr_cell_struct;

typedef struct
{
   kal_uint8                  nmr_cell_num;    /* number of cell with nmr infor. */ 
   rr_rrlp_nmr_cell_struct    nmr_cell[15];    /* max reported cell number is defined to be 15 according to supl spec. */
}rr_rrlp_nmr_struct;

typedef struct
{
   kal_int32                  reported_FN;     /* current reported frame number */
   rr_rrlp_cell_info_struct   serv_info;       /* serving cell information */
   kal_uint8                  ncell_num;       /* neighbor cell number */
   rr_rrlp_cell_info_struct   ncell_info[6];   /* max allowed number of neighbor cell is defined to be 6 */
   rr_rrlp_nmr_struct         nmr;             /* network measurement report infor => only valid for serving cell? */
}rr_rrlp_cell_info_report_struct;

#endif /* RR2RRLP_STRUCT_H */
