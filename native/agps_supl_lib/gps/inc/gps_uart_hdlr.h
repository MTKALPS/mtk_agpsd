/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*  gps_uart_hdlr.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  GPS related function define in GPS task, such as GPS uart and NMEA parser
*
* Author:
* -------
*  Hai Wang (MBJ06018)
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
 * Aug 18 2009 mtk80018
 * [MAUI_01939383] [AGPS 2G CP] 70.7.4.2 fail because measurement error with cause not enough sat
 *
 *
 * Aug 6 2009 mtk80018
 * [MAUI_01886224] [AGPS 2G CP] RRLP R5
 *
 *
 * Jun 5 2008 mbj06018
 * [MAUI_01065164] [GPS] Add a switch of GPS power saving in engineer mode
 *
 *
 * May 23 2008 mbj06018
 * [MAUI_01046192] [AGPS]Check in RTC syn EM104 return can write at mdi_gps
 *
 *
 * Apr 29 2008 mbj06018
 * [MAUI_00317568] AGPS: [1] Fatal Error (306, 88880026) - GPS
 *
 *
 * Apr 17 2008 mbj06018
 * [MAUI_00655816] [AGPS]AGPS check in
 *
 *
 * Apr 14 2008 mbj06018
 * [MAUI_00654075] [GIS]Check in RAW data callback one sentence
 *
 *
 * Feb 21 2008 mtk01206
 * [MAUI_00628364] [GIS_Sunavi][1] Assert fail: (UARTPort[port].ownerid == ownerid) uart_vfifo.c 337 -
 *
 *
 * Feb 5 2008 mtk01206
 * [MAUI_00617221] [GPS][Modify] Modify MT3316/MT3318 authentication process
 *
 *
 * Jan 11 2008 mbj06018
 * [MAUI_00515786] [GIS][Sunavi][Check in]08.02 to 07b maui with new lib
 *
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*******************************************************************************/
#ifndef __GPS_UART_HDLR_H__
#define __GPS_UART_HDLR_H__

#include "mdi_gps.h"

#if defined(__GPS_SUPPORT__)||defined(__BT_GPS_SUPPORT__)
/*config*/
#define GPS_AREA_EVENTS_SUPPORT_NUM         (5)

/*defination*/
#define GPS_UART_EARTH_RADIUS               (6378137)
#define PI                                  (3.1415926)

#define GPS_UART_OPEN_FINISH_EVENT          (0x0001)
#define GPS_UART_READ_FINISH_EVENT          (0x0002)
#define GPS_UART_WRITE_FINISH_EVENT         (0x0004)
#define GPS_UART_CLOSE_FINISH_EVENT         (0x0008)

#define GPS_UART_RING_BUF_SIZE              (2*1024)
#define GPS_UART_RING_MIN_PER_IND           (100)
#define GPS_UART_RING_EXP_INTERVAL          (100)
#define GPS_UART_RING_SENTENCE_NUM          (30)

#define GPS_UART_RAW_BUF_SIZE               (30)
#define GPS_UART_MAX_MOD_PER_PORT           (3)
#define GPS_DUMMY_PORT                      (0xff)
#define GPS_UART_CHECK_VER_INTERVAL         (800)
#define GPS_UART_CHECK_CHIP_ID_INTERVAL     (900)
#define GPS_UART_ENABLE_DEBUG_INFO_INTERVAL (1000)
#define GPS_UART_AUTHENTICATION_INTERVAL    (3000)
#define GPS_UART_MODIS_UART_SM_INTERVAL     (800)
#define GPS_TRACE_MAX_LENGTH                 100
#define GPS_UART_SWITCH_MODE_INTERVAL       (1000)

#define GPS_DUMMY_HANDLE                0xFF
#define GPS_NMEA_BUFFER_SIZE            256
#define GPS_NMEA_MAX_SVVIEW             MDI_GPS_NMEA_MAX_SVVIEW
#define GPS_PARSER_MAX_SUB_FEILD        16
#define GPS_PARSER_GGA_FEILDS           14
#define GPS_PARSER_GLL_FEILDS           7
#define GPS_PARSER_GSA_FEILDS           17
#define GPS_PARSER_GSV_FEILDS           19
#define GPS_PARSER_RMC_FEILDS           12
#define GPS_PARSER_VTG_FEILDS           9
#define GPS_PARSER_SENTECE_BUF_SIZE     GPS_NMEA_BUFFER_SIZE
#define GPS_PARSER_SENTECE_BUF_NUM      5
#define GPS_PARSER_P_RSP_MAX            20
#define GPS_PARSER_POS_FEILDS           20
#define GPS_PARSER_MEAS_FEILDS          30
#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)
#define GPS_PARSER_FTIME_FEILDS         10
#endif

#define GPS_PARSER_P_CMD_LENGTH         3
#define GPS_PARSER_P_CMD_DATA_START     9
#define GPS_PARSER_P_CMD_010            10          /*GPS System boot up finished*/
#define GPS_PARSER_P_CMD_705            705         /*GPS Version*/
#define GPS_PARSER_P_CMD_704            704         /*GPS Version*/
#define GPS_PARSER_P_CMD_714            714         /*Clock Drift Information*/

#define GPS_PARSER_P_CMD_HEAD           "$PMTK%03d"

#define GPS_PARSER_P_CMD_RESPONSE                   001
#define GPS_PARSER_P_CMD_MODE_SWITCH                290
/*Assist data part*/
#define GPS_PARSER_P_CMD_REQUEST_ASSIST             730
/*Assist data part*/
#define GPS_PARSER_P_CMD_ASSIST_RTI                 717
#define GPS_PARSER_P_CMD_ASSIST_ACQUISITION         718
#define GPS_PARSER_P_CMD_ASSIST_ALMANAC             711
#define GPS_PARSER_P_CMD_ASSIST_UTC                 716
#define GPS_PARSER_P_CMD_ASSIST_IONOSPHERE          715
#define GPS_PARSER_P_CMD_ASSIST_NAVIGATION_MODEL    710
#define GPS_PARSER_P_CMD_ASSIST_DGPS_CORRECTION     720
#define GPS_PARSER_P_CMD_ASSIST_REF_LOCATION        713
#define GPS_PARSER_P_CMD_ASSIST_REF_TIME            712
#define GPS_PARSER_P_CMD_ASSIST_TOW_ASSIST          725

#define GPS_PARSER_P_CMD_POS                        731
#define GPS_PARSER_P_CMD_LOC_ERROR                  733
#define GPS_PARSER_P_CMD_MEAS                       732
#define GPS_PARSER_P_CMD_MEAS_REQ                   485

#if 1 //Fine time is for CP only but not for UP. Do not turn on options of fine time for Android load. So we just enable constant definitions here. //#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)
/* Fine Time Assistance */
#define GPS_PARSER_P_CMD_ASSIST_FINE_TIME           719
/* Get Fine Time Info */
#define GPS_PARSER_P_CMD_FTIME_ERROR                735
#define GPS_PARSER_P_CMD_FTIME                      734
#define GPS_PARSER_P_CMD_FTIME_REQ                  484
/* Fine Time Assistance for SP -- added by AW */
#define GPS_PARSER_P_CMD_FTIME_FSYNC_MEAS_REQ       736
#define GPS_PARSER_P_CMD_FTIME_FSYNC_MEAS_RESP      737
#define GPS_PARSER_P_CMD_FTIME_MD_SLEEP_CTRL        738
#endif

#define GPS_PARSER_P_CMD_VALID_OK                   3


#define GPS_NMEA_SEND_BUFFER_SIZE               300
#define GPS_NMEA_SEND_TEMP_BUFFER_SIZE          50
#define GPS_NMEA_SEND_NAVIGATION_W_SIZE         24
#define GPS_NMEA_SEND_ALMANAC_W_SIZE            8


#define GPS_PARSER_P_VERSION_MAX        MDI_GPS_PARSER_P_VERSION_MAX
#define GPS_PARSER_P_MAX_SUB_FEILD      16
#define GPS_PARSER_P_RELEASE_FEILDS     2
#define GPS_PARSER_P_730_FEILDS         (GPS_ASSIST_DATA_SUB_ITEMS_FEILDS * 2 + 5)

#define GPS_CRC_CHECK_FAILD             0

#define GPS_RET_CODE_ERROR              (-1)
#define GPS_RET_CODE_OK                 0

#define GPS_NMEA_BITMAP_GGA     (1<<0)
#define GPS_NMEA_BITMAP_GSA     (1<<1)
#define GPS_NMEA_BITMAP_GSV     (1<<2)
#define GPS_NMEA_BITMAP_RMC     (1<<3)
#define GPS_NMEA_BITMAP_VTG     (1<<4)
#define GPS_NMEA_BITMAP_GLL     (1<<5)

/*Version*/
typedef struct
{
    kal_char    version[MDI_GPS_PARSER_P_VERSION_MAX];
    kal_uint32  number;
} gps_p_release_struct;


typedef struct
{
    kal_char    command[GPS_PARSER_P_RSP_MAX];
    kal_uint16  command_num;
    kal_char    result;
} gps_p_response_struct;


typedef struct
{
    gps_p_release_struct    release;
} gps_p_info_struct;


typedef enum
{
    GPS_NMEA_STR = 0,
    GPS_NMEA_DATA,
    GPS_NMEA_CHECKSUM1,
    GPS_NMEA_CHECKSUM2,
    GPS_NMEA_END_CR,
    GPS_NMEA_END_LF
} gps_parser_state;

typedef enum
{
    GPS_NEXT_JOB_IDLE = 0,
    GPS_NEXT_JOB_CLEAR_NVRAM,
    GPS_NEXT_JOB_CLOSE_PORT,
    GPS_NEXT_JOB_END
} gps_next_job_enum;

typedef struct
{
    mdi_gps_nmea_gga_struct    gga;
    mdi_gps_nmea_gsa_struct    gsa;
    mdi_gps_nmea_gsv_struct    gsv;
    mdi_gps_nmea_rmc_struct    rmc;
    mdi_gps_nmea_vtg_struct    vtg;
    mdi_gps_nmea_gll_struct    gll;
}mdi_gps_nmea_info_struct;


typedef struct
{
    gps_parser_state         state;
    mdi_gps_nmea_info_struct nmea;              /*parser work buffer*/
    mdi_gps_nmea_info_struct nmea_to_app;       /*store parsered data to app*/
    mdi_gps_p_info_struct    p_info;       /*store parsered data to app*/
    kal_mutexid              mutex;
    kal_uint8                sentence_buffer_index;
    kal_char                 sentence_buffer[GPS_PARSER_SENTECE_BUF_NUM][GPS_PARSER_SENTECE_BUF_SIZE];
    kal_bool                 is_enabled;
    kal_bool                 sentence_enabled;
    kal_bool                 is_init_GPS_RTC;
    kal_bool                 is_gps_fixed;
    kal_bool                 is_gps_time_syn;
} gps_parser_context_struct;
#ifdef __AGPS_CONTROL_PLANE__
//GPS AREA EVENT
typedef struct
{
    gps_area_event_add_req_struct event;
    kal_bool    is_valid;
    module_type module;
} gps_area_events_single_struct;

typedef struct
{
    gps_area_events_single_struct events[GPS_AREA_EVENTS_SUPPORT_NUM];
} gps_area_events_context_struct;
#endif
typedef struct
{
    kal_bool    catcher_logging;
    kal_bool    file_logging;
    kal_bool    agent_logging;
    kal_bool    debug_info;
} gps_logging_ctx_struct;


typedef struct
{
    kal_bool        is_need_indicate;
    kal_uint32      read_p;
} gps_uart_ring_buffer_read_struct;

typedef struct
{
    gps_uart_ring_buffer_read_struct        read[GPS_UART_MAX_MOD_PER_PORT];
    kal_char                                buffer[GPS_UART_RING_BUF_SIZE];
    kal_uint32                              write_p;
    kal_mutexid                             mutex;
} gps_uart_ring_buffer_struct;

typedef struct
{
    kal_bool        is_need_indicate;
    kal_uint32      sentence_start_p[GPS_UART_RING_SENTENCE_NUM];
    kal_uint16      sentence_length[GPS_UART_RING_SENTENCE_NUM];
    kal_uint8       read_index;
    module_type     mod_id;
} gps_uart_ring_sentence_buffer_read_struct;

typedef struct
{
    gps_uart_ring_sentence_buffer_read_struct        read[GPS_UART_MAX_MOD_PER_PORT];
    kal_char                                buffer[GPS_UART_RING_BUF_SIZE];
    kal_uint32                              write_p;
    kal_uint32                              write_index;
    kal_mutexid                             mutex;
} gps_uart_ring_sentence_buffer_struct;

typedef struct
{
    gps_uart_ring_buffer_struct        ring;
    gps_uart_ring_sentence_buffer_struct    nmea_ring;
    module_type     mod_id[GPS_UART_MAX_MOD_PER_PORT];
    kal_char        buffer[GPS_UART_RAW_BUF_SIZE];
    kal_bool        is_raw_data_mode[GPS_UART_MAX_MOD_PER_PORT];
    kal_bool        is_location_mode[GPS_UART_MAX_MOD_PER_PORT];
    kal_bool        is_need_location_ind[GPS_UART_MAX_MOD_PER_PORT];
    kal_uint8       nmea_to_app_bit[GPS_UART_MAX_MOD_PER_PORT];   /*store parsered data btimap to app*/
    kal_bool        is_lct_with_qop_mode[GPS_UART_MAX_MOD_PER_PORT];
    kal_uint8       port_num;

    kal_int16       last_switch_mode;       /*mb ma*/
    kal_int16       org_gps_mode;       /*mb ma*/
    kal_int16       curr_gps_mode;      /*mb ma*/
    kal_int16       prefer_gps_mode;    /*mb ma*/
    kal_int16       query_gps_mode;    /*mb ma*/
    module_type     request_mod_id[GPS_UART_MAX_MOD_PER_PORT];
    kal_uint8       request_count[GPS_UART_MAX_MOD_PER_PORT];
} gps_port_cntx_struct;


typedef struct
{
    kal_uint32 v_drv_counter;
    kal_char   v_drv_buf[GPS_NMEA_BUFFER_SIZE];
    gps_parser_context_struct   parser;
    gps_logging_ctx_struct      logging;
    gps_port_cntx_struct        port;
#ifdef __AGPS_CONTROL_PLANE__
    gps_area_events_context_struct  area_events;
#endif
    kal_bool                    is_timer_started;
    kal_bool                    is_start_ok;
    gps_next_job_enum           next_job;
    gps_p_response_struct       response;
}gps_uart_context_struct;


extern kal_bool     gps_msg_hdlr(ilm_struct *ilm_ptr);
extern void         gps_set_work_port(kal_uint8 port);
extern void         gps_enable_parser(void);
extern kal_bool     gps_disable_parser(void);
extern kal_bool     gps_is_parser_enabled(void);

extern kal_int16 gps_uart_read_data_nmea(kal_uint8 port, kal_uint8 *buffer, kal_uint16 length,kal_uint32 *readed);
extern kal_int16 gps_uart_read_data_dbg(kal_uint8 port, kal_uint8 *buffer, kal_uint16 length,kal_uint32 *readed);
extern void gps_logging_catcher_enable(void);
extern void gps_logging_catcher_disable(void);
extern void gps_logging_agent_enable(void);
extern void gps_logging_agent_disable(void);
extern void gps_nmea_eng_sentence_disable(void);
extern void gps_nmea_eng_sentence_enable(void);
extern void gps_debug_info_enable(void);
extern void gps_debug_info_disable(void);
extern void gps_power_saving_mode_enable(void);
extern void gps_power_saving_mode_disable(void);

extern kal_char* gps_p_get_fireware_version(void);

extern void gps_send_msg(msg_type msg_id,module_type dst_mod, void* local_param_ptr);
extern kal_uint32 gps_uart_write_internal(kal_int16 port,kal_uint8* data_p,kal_uint32 length);
extern kal_bool gps_find_sub_field(
                const kal_char* str,
                kal_int32 num_cmms,
                kal_char sub[][GPS_PARSER_MAX_SUB_FEILD],
                kal_uint8 *found_fields);
extern kal_bool gps_is_integer(const kal_char *str);
extern kal_bool gps_is_float(const kal_char *str);
extern kal_bool gps_uart_write_gps_cmd(kal_uint16 port,mdi_gps_uart_cmd_type_enum cmd,void *param);
extern void gps_nmea_get_gsv_from_buffer(mdi_gps_nmea_gsv_struct* gsv);
extern kal_uint8 gps_get_nmea_location(kal_uint8 port,mdi_gps_nmea_info_struct *nmea_ptr);
extern kal_bool gps_p_response_parser(const kal_char* str, gps_p_response_struct* data);
extern kal_bool gps_uart_is_mode_ready(void);
extern kal_int16 gps_get_work_mode(void);
extern void gps_uart_restore2prefer_mode(void);
extern kal_uint32 gps_uart_clear_on_broad_gps_nvram(void);
extern kal_bool gps_is_start_finished(void);
extern void gps_uart_reset_query_mode(void);

#endif /*__GPS_SUPPORT__*/
#endif /*__GPS_UART_HDLR_H__*/


