/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 * 
 * MediaTek Inc. (C) 2010. All rights reserved.
 * 
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

/****************************************************************************
 *
 *               Assignment : MTK ASN.1 Compiler
 *               CONFIDENTIAL
 *               Copyright (C) 2004 UbiNetics Ltd. All rights reserved.
 *               Cambridge Technology Centre
 *               Melbourn Royston
 *               Herts SG8 6DP UK
 *               Tel: +44 1763 262222
 *
 *****************************************************************************/
 /****************************************************************************
 *
 * COMPONENT:   UPER	SUPL
 * MODULE:      supl
 * DESCRIPTION: Autogenerated by ASN.1 Compiler - UPER (Version 1.0)
 *
 ****************************************************************************/

/**
 * @file supl.h
 *
 * ASN.1 header file
 *
 */

#if !defined _SUPL_H
#define _SUPL_H



/* ENUMERATED NotificationType */
typedef enum
{
   supl_NotificationType_noNotificationNoVerification,
   supl_NotificationType_notificationOnly,
   supl_NotificationType_notificationAndVerficationAllowedNA,
   supl_NotificationType_notificationAndVerficationDeniedNA,
   supl_NotificationType_privacyOverride
    // ...
}
supl_NotificationType;

/* ENUMERATED EncodingType */
typedef enum
{
   supl_EncodingType_ucs2,
   supl_EncodingType_gsmDefault,
   supl_EncodingType_utf8
    // ...
}
supl_EncodingType;

#define supl_maxReqLength 50
#define supl_maxClientLength 50
/* ENUMERATED FormatIndicator */
typedef enum
{
   supl_FormatIndicator_logicalName,
   supl_FormatIndicator_e_mailAddress,
   supl_FormatIndicator_msisdn,
   supl_FormatIndicator_url,
   supl_FormatIndicator_sipUrl,
   supl_FormatIndicator_min,
   supl_FormatIndicator_mdn,
   supl_FormatIndicator_imsPublicIdentity
    // ...
}
supl_FormatIndicator;

/* ENUMERATED SLPMode */
typedef enum
{
   supl_SLPMode_proxy,
   supl_SLPMode_nonProxy
}
supl_SLPMode;

/* BIT STRING MAC */
typedef struct supl_MAC
{
   U8 numBits;
   U8 stringData[8];
}
supl_MAC;

/* BIT STRING KeyIdentity */
typedef struct supl_KeyIdentity
{
   U16 numBits;
   U8 *stringData;
}
supl_KeyIdentity;

/* SEQUENCE PosTechnology */
typedef struct supl_PosTechnology
{
   Bool agpsSETassisted; /* MANDATORY */
   Bool agpsSETBased; /* MANDATORY */
   Bool autonomousGPS; /* MANDATORY */
   Bool aFLT; /* MANDATORY */
   Bool eCID; /* MANDATORY */
   Bool eOTD; /* MANDATORY */
   Bool oTDOA; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_PosTechnology;

/* ENUMERATED PrefMethod */
typedef enum
{
   supl_PrefMethod_agpsSETassistedPreferred,
   supl_PrefMethod_agpsSETBasedPreferred,
   supl_PrefMethod_noPreference
}
supl_PrefMethod;

/* SEQUENCE PosProtocol */
typedef struct supl_PosProtocol
{
   Bool tia801; /* MANDATORY */
   Bool rrlp; /* MANDATORY */
   Bool rrc; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_PosProtocol;

/* BIT STRING SETAuthKey-shortKey */
typedef struct supl_SETAuthKey_shortKey
{
   U8 numBits;
   U8 stringData[16];
}
supl_SETAuthKey_shortKey;

/* BIT STRING SETAuthKey-longKey */
typedef struct supl_SETAuthKey_longKey
{
   U16 numBits;
   U8 stringData[32];
}
supl_SETAuthKey_longKey;

/* CHOICE SETAuthKey */
typedef enum
{
   supl_SETAuthKey_shortKey_selected = 1,
   supl_SETAuthKey_longKey_selected,
   supl_SETAuthKey_UnKnowItem_selected
}
supl_SETAuthKey_selector;

typedef struct supl_SETAuthKey
{
   supl_SETAuthKey_selector selection;

   union
   {
      supl_SETAuthKey_shortKey shortKey;
      supl_SETAuthKey_longKey longKey;
   applib_ChoiceUnKnow	UnKnowItem;
   }
   choice;
}
supl_SETAuthKey;

/* BIT STRING KeyIdentity4 */
typedef struct supl_KeyIdentity4
{
   U16 numBits;
   U8 *stringData;
}
supl_KeyIdentity4;

/* SEQUENCE SatelliteInfoElement */
typedef struct supl_SatelliteInfoElement
{
   U8 satId; /* MANDATORY */
   U8 iODE; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
*supl_SatelliteInfoElement;

/* OCTET STRING PosPayLoad-tia801payload */
typedef struct supl_PosPayLoad_tia801payload
{
   U16 numOctets;
   U8 *stringData;
}
supl_PosPayLoad_tia801payload;

/* OCTET STRING PosPayLoad-rrcPayload */
typedef struct supl_PosPayLoad_rrcPayload
{
   U16 numOctets;
   U8 *stringData;
}
supl_PosPayLoad_rrcPayload;

/* OCTET STRING PosPayLoad-rrlpPayload */
typedef struct supl_PosPayLoad_rrlpPayload
{
   U16 numOctets;
   U8 *stringData;
}
supl_PosPayLoad_rrlpPayload;

/* CHOICE PosPayLoad */
typedef enum
{
   supl_PosPayLoad_tia801payload_selected = 1,
   supl_PosPayLoad_rrcPayload_selected,
   supl_PosPayLoad_rrlpPayload_selected,
   supl_PosPayLoad_UnKnowItem_selected
}
supl_PosPayLoad_selector;

typedef struct supl_PosPayLoad
{
   supl_PosPayLoad_selector selection;

   union
   {
      supl_PosPayLoad_tia801payload tia801payload;
      supl_PosPayLoad_rrcPayload rrcPayload;
      supl_PosPayLoad_rrlpPayload rrlpPayload;
   applib_ChoiceUnKnow	UnKnowItem;
   }
   choice;
}
supl_PosPayLoad;

/* BIT STRING SETNonce */
typedef struct supl_SETNonce
{
   U8 numBits;
   U8 stringData[16];
}
supl_SETNonce;

/* BIT STRING KeyIdentity2 */
typedef struct supl_KeyIdentity2
{
   U16 numBits;
   U8 *stringData;
}
supl_KeyIdentity2;

/* BIT STRING SPCAuthKey-shortKey */
typedef struct supl_SPCAuthKey_shortKey
{
   U8 numBits;
   U8 stringData[16];
}
supl_SPCAuthKey_shortKey;

/* BIT STRING SPCAuthKey-longKey */
typedef struct supl_SPCAuthKey_longKey
{
   U16 numBits;
   U8 stringData[32];
}
supl_SPCAuthKey_longKey;

/* CHOICE SPCAuthKey */
typedef enum
{
   supl_SPCAuthKey_shortKey_selected = 1,
   supl_SPCAuthKey_longKey_selected,
   supl_SPCAuthKey_UnKnowItem_selected
}
supl_SPCAuthKey_selector;

typedef struct supl_SPCAuthKey
{
   supl_SPCAuthKey_selector selection;

   union
   {
      supl_SPCAuthKey_shortKey shortKey;
      supl_SPCAuthKey_longKey longKey;
   applib_ChoiceUnKnow	UnKnowItem;
   }
   choice;
}
supl_SPCAuthKey;

/* BIT STRING KeyIdentity3 */
typedef struct supl_KeyIdentity3
{
   U8 numBits;
   U8 stringData[16];
}
supl_KeyIdentity3;

/* SEQUENCE Version */
typedef struct supl_Version
{
   U8 maj; /* MANDATORY */
   U8 min; /* MANDATORY */
   U8 servind; /* MANDATORY */
}
supl_Version;

/* OCTET STRING IPAddress-ipv4Address */
typedef struct supl_IPAddress_ipv4Address
{
   U8 numOctets;
   U8 stringData[4];
}
supl_IPAddress_ipv4Address;

/* OCTET STRING IPAddress-ipv6Address */
typedef struct supl_IPAddress_ipv6Address
{
   U8 numOctets;
   U8 stringData[16];
}
supl_IPAddress_ipv6Address;

/* CHOICE IPAddress */
typedef enum
{
   supl_IPAddress_ipv4Address_selected = 1,
   supl_IPAddress_ipv6Address_selected
}
supl_IPAddress_selector;

typedef struct supl_IPAddress
{
   supl_IPAddress_selector selection;

   union
   {
      supl_IPAddress_ipv4Address ipv4Address;
      supl_IPAddress_ipv6Address ipv6Address;
   }
   choice;
}
*supl_IPAddress;

typedef    applib_asn_VisibleString 		supl_FQDN;

/* BIT STRING Ver */
typedef struct supl_Ver
{
   U8 numBits;
   U8 stringData[8];
}
supl_Ver;

/* ENUMERATED Status */
typedef enum
{
   supl_Status_stale,
   supl_Status_current,
   supl_Status_unknown
    // ...
}
supl_Status;

/* ENUMERATED AltitudeInfo-altitudeDirection */
typedef enum
{
   supl_AltitudeInfo_altitudeDirection_height,
   supl_AltitudeInfo_altitudeDirection_depth
}
supl_AltitudeInfo_altitudeDirection;

/* SEQUENCE AltitudeInfo */
typedef struct supl_AltitudeInfo
{
   supl_AltitudeInfo_altitudeDirection altitudeDirection; /* MANDATORY */
   U16 altitude; /* MANDATORY */
   U8 altUncertainty; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_AltitudeInfo;

/* SEQUENCE CdmaCellInformation */
typedef struct supl_CdmaCellInformation
{
   U16 refNID; /* MANDATORY */
   U16 refSID; /* MANDATORY */
   U16 refBASEID; /* MANDATORY */
   U32 refBASELAT; /* MANDATORY */
   U32 reBASELONG; /* MANDATORY */
   U16 refREFPN; /* MANDATORY */
   U16 refWeekNumber; /* MANDATORY */
   U32 refSeconds; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_CdmaCellInformation;

/* INTEGER UARFCN */
typedef U16 supl_UARFCN;

/* SEQUENCE NMRelement */
typedef struct supl_NMRelement
{
   U16 aRFCN; /* MANDATORY */
   U8 bSIC; /* MANDATORY */
   U8 rxLev; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
*supl_NMRelement;

/* INTEGER UTRA-CarrierRSSI */
typedef U8 supl_UTRA_CarrierRSSI;

/* INTEGER CellParametersID */
typedef U8 supl_CellParametersID;

/* INTEGER TGSN */
typedef U8 supl_TGSN;

/* INTEGER PrimaryCCPCH-RSCP */
typedef U8 supl_PrimaryCCPCH_RSCP;

/* INTEGER TimeslotISCP */
typedef U8 supl_TimeslotISCP;

/* SEQUENCE OF TimeslotISCP-List */
typedef struct supl_TimeslotISCP_List
{
   U8 numElements;

   supl_TimeslotISCP element[14];
}
supl_TimeslotISCP_List;

/* SEQUENCE PrimaryCPICH-Info */
typedef struct supl_PrimaryCPICH_Info
{
   U16 primaryScramblingCode; /* MANDATORY */
}
supl_PrimaryCPICH_Info;

/* INTEGER CPICH-Ec-N0 */
typedef U8 supl_CPICH_Ec_N0;

/* INTEGER CPICH-RSCP */
typedef U8 supl_CPICH_RSCP;

/* INTEGER Pathloss */
typedef U8 supl_Pathloss;

#define supl_maxCellMeas 32
#define supl_maxFreq 8
#define supl_maxTS 14
/* ENUMERATED StatusCode */
typedef enum
{
   supl_StatusCode_unspecified,
   supl_StatusCode_systemFailure,
   supl_StatusCode_unexpectedMessage,
   supl_StatusCode_protocolError,
   supl_StatusCode_dataMissing,
   supl_StatusCode_unexpectedDataValue,
   supl_StatusCode_posMethodFailure,
   supl_StatusCode_posMethodMismatch,
   supl_StatusCode_posProtocolMismatch,
   supl_StatusCode_targetSETnotReachable,
   supl_StatusCode_versionNotSupported,
   supl_StatusCode_resourceShortage,
   supl_StatusCode_invalidSessionId,
   supl_StatusCode_nonProxyModeNotSupported,
   supl_StatusCode_proxyModeNotSupported,
   supl_StatusCode_positioningNotPermitted,
   supl_StatusCode_authNetFailure,
   supl_StatusCode_authSuplinitFailure,
   supl_StatusCode_consentDeniedByUser,
   supl_StatusCode_consentGrantedByUser
    // ...
}
supl_StatusCode;

/* SEQUENCE QoP */
typedef struct supl_QoP
{
   U8 validity;

   #define supl_QoP_veracc_valid 0x04
   #define supl_QoP_maxLocAge_valid 0x02
   #define supl_QoP_delay_valid 0x01

   U8 horacc; /* MANDATORY */
   U8 veracc; /* OPTIONAL */
   U16 maxLocAge; /* OPTIONAL */
   U8 delay; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_QoP;

/* BIT STRING Horvel-bearing */
typedef struct supl_Horvel_bearing
{
   U8 numBits;
   U8 stringData[2];
}
supl_Horvel_bearing;

/* BIT STRING Horvel-horspeed */
typedef struct supl_Horvel_horspeed
{
   U8 numBits;
   U8 stringData[2];
}
supl_Horvel_horspeed;

/* SEQUENCE Horvel */
typedef struct supl_Horvel
{
   supl_Horvel_bearing bearing; /* MANDATORY */
   supl_Horvel_horspeed horspeed; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_Horvel;

/* BIT STRING Horandvervel-verdirect */
typedef struct supl_Horandvervel_verdirect
{
   U8 numBits;
   U8 stringData[1];
}
supl_Horandvervel_verdirect;

/* BIT STRING Horandvervel-bearing */
typedef struct supl_Horandvervel_bearing
{
   U8 numBits;
   U8 stringData[2];
}
supl_Horandvervel_bearing;

/* BIT STRING Horandvervel-horspeed */
typedef struct supl_Horandvervel_horspeed
{
   U8 numBits;
   U8 stringData[2];
}
supl_Horandvervel_horspeed;

/* BIT STRING Horandvervel-verspeed */
typedef struct supl_Horandvervel_verspeed
{
   U8 numBits;
   U8 stringData[1];
}
supl_Horandvervel_verspeed;

/* SEQUENCE Horandvervel */
typedef struct supl_Horandvervel
{
   supl_Horandvervel_verdirect verdirect; /* MANDATORY */
   supl_Horandvervel_bearing bearing; /* MANDATORY */
   supl_Horandvervel_horspeed horspeed; /* MANDATORY */
   supl_Horandvervel_verspeed verspeed; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_Horandvervel;

/* BIT STRING Horveluncert-bearing */
typedef struct supl_Horveluncert_bearing
{
   U8 numBits;
   U8 stringData[2];
}
supl_Horveluncert_bearing;

/* BIT STRING Horveluncert-horspeed */
typedef struct supl_Horveluncert_horspeed
{
   U8 numBits;
   U8 stringData[2];
}
supl_Horveluncert_horspeed;

/* BIT STRING Horveluncert-uncertspeed */
typedef struct supl_Horveluncert_uncertspeed
{
   U8 numBits;
   U8 stringData[1];
}
supl_Horveluncert_uncertspeed;

/* SEQUENCE Horveluncert */
typedef struct supl_Horveluncert
{
   supl_Horveluncert_bearing bearing; /* MANDATORY */
   supl_Horveluncert_horspeed horspeed; /* MANDATORY */
   supl_Horveluncert_uncertspeed uncertspeed; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_Horveluncert;

/* BIT STRING Horandveruncert-verdirect */
typedef struct supl_Horandveruncert_verdirect
{
   U8 numBits;
   U8 stringData[1];
}
supl_Horandveruncert_verdirect;

/* BIT STRING Horandveruncert-bearing */
typedef struct supl_Horandveruncert_bearing
{
   U8 numBits;
   U8 stringData[2];
}
supl_Horandveruncert_bearing;

/* BIT STRING Horandveruncert-horspeed */
typedef struct supl_Horandveruncert_horspeed
{
   U8 numBits;
   U8 stringData[2];
}
supl_Horandveruncert_horspeed;

/* BIT STRING Horandveruncert-verspeed */
typedef struct supl_Horandveruncert_verspeed
{
   U8 numBits;
   U8 stringData[1];
}
supl_Horandveruncert_verspeed;

/* BIT STRING Horandveruncert-horuncertspeed */
typedef struct supl_Horandveruncert_horuncertspeed
{
   U8 numBits;
   U8 stringData[1];
}
supl_Horandveruncert_horuncertspeed;

/* BIT STRING Horandveruncert-veruncertspeed */
typedef struct supl_Horandveruncert_veruncertspeed
{
   U8 numBits;
   U8 stringData[1];
}
supl_Horandveruncert_veruncertspeed;

/* SEQUENCE Horandveruncert */
typedef struct supl_Horandveruncert
{
   supl_Horandveruncert_verdirect verdirect; /* MANDATORY */
   supl_Horandveruncert_bearing bearing; /* MANDATORY */
   supl_Horandveruncert_horspeed horspeed; /* MANDATORY */
   supl_Horandveruncert_verspeed verspeed; /* MANDATORY */
   supl_Horandveruncert_horuncertspeed horuncertspeed; /* MANDATORY */
   supl_Horandveruncert_veruncertspeed veruncertspeed; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_Horandveruncert;

/* ENUMERATED PosMethod */
typedef enum
{
   supl_PosMethod_agpsSETassisted,
   supl_PosMethod_agpsSETbased,
   supl_PosMethod_agpsSETassistedpref,
   supl_PosMethod_agpsSETbasedpref,
   supl_PosMethod_autonomousGPS,
   supl_PosMethod_aFLT,
   supl_PosMethod_eCID,
   supl_PosMethod_eOTD,
   supl_PosMethod_oTDOA,
   supl_PosMethod_noPosition
    // ...
}
supl_PosMethod;

/* OCTET STRING Notification-requestorId */
typedef struct supl_Notification_requestorId
{
   U16 numOctets;
   U8 *stringData;
}
supl_Notification_requestorId;

/* OCTET STRING Notification-clientName */
typedef struct supl_Notification_clientName
{
   U16 numOctets;
   U8 *stringData;
}
supl_Notification_clientName;

/* SEQUENCE Notification */
typedef struct supl_Notification
{
   U8 validity;

   #define supl_Notification_encodingType_valid 0x10
   #define supl_Notification_requestorId_valid 0x08
   #define supl_Notification_requestorIdType_valid 0x04
   #define supl_Notification_clientName_valid 0x02
   #define supl_Notification_clientNameType_valid 0x01

   supl_NotificationType notificationType; /* MANDATORY */
   supl_EncodingType encodingType; /* OPTIONAL */
   supl_Notification_requestorId requestorId; /* OPTIONAL */
   supl_FormatIndicator requestorIdType; /* OPTIONAL */
   supl_Notification_clientName clientName; /* OPTIONAL */
   supl_FormatIndicator clientNameType; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_Notification;

/* SEQUENCE SETCapabilities */
typedef struct supl_SETCapabilities
{
   supl_PosTechnology posTechnology; /* MANDATORY */
   supl_PrefMethod prefMethod; /* MANDATORY */
   supl_PosProtocol posProtocol; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_SETCapabilities;

/* SEQUENCE OF SatelliteInfo */
typedef struct supl_SatelliteInfo
{
   U8 numElements;

   supl_SatelliteInfoElement element[31];
}
supl_SatelliteInfo;

/* SEQUENCE SUPLAUTHREQ */
typedef struct supl_SUPLAUTHREQ
{
   supl_SETNonce sETNonce; /* MANDATORY */
   supl_KeyIdentity2 keyIdentity2; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
*supl_SUPLAUTHREQ;

/* SEQUENCE SUPLAUTHRESP */
typedef struct supl_SUPLAUTHRESP
{
   U8 validity;

   #define supl_SUPLAUTHRESP_sPCAuthKey_valid 0x04
   #define supl_SUPLAUTHRESP_keyIdentity3_valid 0x02
   #define supl_SUPLAUTHRESP_statusCode_valid 0x01

   supl_SPCAuthKey sPCAuthKey; /* OPTIONAL */
   supl_KeyIdentity3 keyIdentity3; /* OPTIONAL */
   supl_StatusCode statusCode; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_SUPLAUTHRESP;

/* OCTET STRING SETId-msisdn */
typedef struct supl_SETId_msisdn
{
   U8 numOctets;
   U8 stringData[8];
}
supl_SETId_msisdn;

/* OCTET STRING SETId-mdn */
typedef struct supl_SETId_mdn
{
   U8 numOctets;
   U8 stringData[8];
}
supl_SETId_mdn;

/* BIT STRING SETId-min */
typedef struct supl_SETId_min
{
   U8 numBits;
   U8 stringData[5];
}
supl_SETId_min;

/* OCTET STRING SETId-imsi */
typedef struct supl_SETId_imsi
{
   U8 numOctets;
   U8 stringData[8];
}
supl_SETId_imsi;

/* CHOICE SETId */
typedef enum
{
   supl_SETId_msisdn_selected = 1,
   supl_SETId_mdn_selected,
   supl_SETId_min_selected,
   supl_SETId_imsi_selected,
   supl_SETId_nai_selected,
   supl_SETId_iPAddress_selected,
   supl_SETId_UnKnowItem_selected
}
supl_SETId_selector;

typedef struct supl_SETId
{
   supl_SETId_selector selection;

   union
   {
      supl_SETId_msisdn msisdn;
      supl_SETId_mdn mdn;
      supl_SETId_min min;
      supl_SETId_imsi imsi;
      applib_asn_IA5String nai;
      supl_IPAddress iPAddress;
   applib_ChoiceUnKnow	UnKnowItem;
   }
   choice;
}
supl_SETId;

/* CHOICE SLPAddress */
typedef enum
{
   supl_SLPAddress_iPAddress_selected = 1,
   supl_SLPAddress_fQDN_selected,
   supl_SLPAddress_UnKnowItem_selected
}
supl_SLPAddress_selector;

typedef struct supl_SLPAddress
{
   supl_SLPAddress_selector selection;

   union
   {
      supl_IPAddress iPAddress;
      supl_FQDN fQDN;
   applib_ChoiceUnKnow	UnKnowItem;
   }
   choice;
}
supl_SLPAddress;

/* ENUMERATED PositionEstimate-latitudeSign */
typedef enum
{
   supl_PositionEstimate_latitudeSign_north,
   supl_PositionEstimate_latitudeSign_south
}
supl_PositionEstimate_latitudeSign;

/* SEQUENCE PositionEstimate-uncertainty */
typedef struct supl_PositionEstimate_uncertainty
{
   U8 uncertaintySemiMajor; /* MANDATORY */
   U8 uncertaintySemiMinor; /* MANDATORY */
   U8 orientationMajorAxis; /* MANDATORY */
}
supl_PositionEstimate_uncertainty;

/* SEQUENCE PositionEstimate */
typedef struct supl_PositionEstimate
{
   U8 validity;

   #define supl_PositionEstimate_uncertainty_valid 0x04
   #define supl_PositionEstimate_confidence_valid 0x02
   #define supl_PositionEstimate_altitudeInfo_valid 0x01

   supl_PositionEstimate_latitudeSign latitudeSign; /* MANDATORY */
   U32 latitude; /* MANDATORY */
   S32 longitude; /* MANDATORY */
   supl_PositionEstimate_uncertainty uncertainty; /* OPTIONAL */
   U8 confidence; /* OPTIONAL */
   supl_AltitudeInfo altitudeInfo; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_PositionEstimate;

/* SEQUENCE FrequencyInfoFDD */
typedef struct supl_FrequencyInfoFDD
{
   U8 validity;

   #define supl_FrequencyInfoFDD_uarfcn_UL_valid 0x01

   supl_UARFCN uarfcn_UL; /* OPTIONAL */
   supl_UARFCN uarfcn_DL; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_FrequencyInfoFDD;

/* SEQUENCE FrequencyInfoTDD */
typedef struct supl_FrequencyInfoTDD
{
   supl_UARFCN uarfcn_Nt; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_FrequencyInfoTDD;

/* SEQUENCE OF NMR */
typedef struct supl_NMR
{
   U8 numElements;

   supl_NMRelement element[15];
}
supl_NMR;

/* SEQUENCE CellMeasuredResults-modeSpecificInfo-fdd */
typedef struct supl_CellMeasuredResults_modeSpecificInfo_fdd
{
   U8 validity;

   #define supl_CellMeasuredResults_modeSpecificInfo_fdd_cpich_Ec_N0_valid 0x04
   #define supl_CellMeasuredResults_modeSpecificInfo_fdd_cpich_RSCP_valid 0x02
   #define supl_CellMeasuredResults_modeSpecificInfo_fdd_pathloss_valid 0x01

   supl_PrimaryCPICH_Info primaryCPICH_Info; /* MANDATORY */
   supl_CPICH_Ec_N0 cpich_Ec_N0; /* OPTIONAL */
   supl_CPICH_RSCP cpich_RSCP; /* OPTIONAL */
   supl_Pathloss pathloss; /* OPTIONAL */
}
supl_CellMeasuredResults_modeSpecificInfo_fdd;

/* SEQUENCE CellMeasuredResults-modeSpecificInfo-tdd */
typedef struct supl_CellMeasuredResults_modeSpecificInfo_tdd
{
   U8 validity;

   #define supl_CellMeasuredResults_modeSpecificInfo_tdd_proposedTGSN_valid 0x08
   #define supl_CellMeasuredResults_modeSpecificInfo_tdd_primaryCCPCH_RSCP_valid 0x04
   #define supl_CellMeasuredResults_modeSpecificInfo_tdd_pathloss_valid 0x02
   #define supl_CellMeasuredResults_modeSpecificInfo_tdd_timeslotISCP_List_valid 0x01

   supl_CellParametersID cellParametersID; /* MANDATORY */
   supl_TGSN proposedTGSN; /* OPTIONAL */
   supl_PrimaryCCPCH_RSCP primaryCCPCH_RSCP; /* OPTIONAL */
   supl_Pathloss pathloss; /* OPTIONAL */
   supl_TimeslotISCP_List timeslotISCP_List; /* OPTIONAL */
}
supl_CellMeasuredResults_modeSpecificInfo_tdd;

/* CHOICE CellMeasuredResults-modeSpecificInfo */
typedef enum
{
   supl_CellMeasuredResults_modeSpecificInfo_fdd_selected = 1,
   supl_CellMeasuredResults_modeSpecificInfo_tdd_selected
}
supl_CellMeasuredResults_modeSpecificInfo_selector;

typedef struct supl_CellMeasuredResults_modeSpecificInfo
{
   supl_CellMeasuredResults_modeSpecificInfo_selector selection;

   union
   {
      supl_CellMeasuredResults_modeSpecificInfo_fdd fdd;
      supl_CellMeasuredResults_modeSpecificInfo_tdd tdd;
   }
   choice;
}
supl_CellMeasuredResults_modeSpecificInfo;

/* SEQUENCE CellMeasuredResults */
typedef struct supl_CellMeasuredResults
{
   U8 validity;

   #define supl_CellMeasuredResults_cellIdentity_valid 0x01

   U32 cellIdentity; /* OPTIONAL */
   supl_CellMeasuredResults_modeSpecificInfo modeSpecificInfo; /* MANDATORY */
}
#if _FP_CR_SYNC_MAUI_03018028_ == 0
supl_CellMeasuredResults;
#else
*supl_CellMeasuredResults;
#endif

/* CHOICE Velocity */
typedef enum
{
   supl_Velocity_horvel_selected = 1,
   supl_Velocity_horandvervel_selected,
   supl_Velocity_horveluncert_selected,
   supl_Velocity_horandveruncert_selected,
   supl_Velocity_UnKnowItem_selected
}
supl_Velocity_selector;

typedef struct supl_Velocity
{
   supl_Velocity_selector selection;

   union
   {
      supl_Horvel horvel;
      supl_Horandvervel horandvervel;
      supl_Horveluncert horveluncert;
      supl_Horandveruncert horandveruncert;
   applib_ChoiceUnKnow	UnKnowItem;
   }
   choice;
}
supl_Velocity;

/* SEQUENCE SUPLINIT */
typedef struct supl_SUPLINIT
{
   U8 validity;

   #define supl_SUPLINIT_notification_valid 0x10
   #define supl_SUPLINIT_sLPAddress_valid 0x08
   #define supl_SUPLINIT_qoP_valid 0x04
   #define supl_SUPLINIT_mAC_valid 0x02
   #define supl_SUPLINIT_keyIdentity_valid 0x01

   supl_PosMethod posMethod; /* MANDATORY */
   supl_Notification notification; /* OPTIONAL */
   supl_SLPAddress sLPAddress; /* OPTIONAL */
   supl_QoP qoP; /* OPTIONAL */
   supl_SLPMode sLPMode; /* MANDATORY */
   supl_MAC mAC; /* OPTIONAL */
   supl_KeyIdentity keyIdentity; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
*supl_SUPLINIT;

/* SEQUENCE SUPLRESPONSE */
typedef struct supl_SUPLRESPONSE
{
   U8 validity;

   #define supl_SUPLRESPONSE_sLPAddress_valid 0x04
   #define supl_SUPLRESPONSE_sETAuthKey_valid 0x02
   #define supl_SUPLRESPONSE_keyIdentity4_valid 0x01

   supl_PosMethod posMethod; /* MANDATORY */
   supl_SLPAddress sLPAddress; /* OPTIONAL */
   supl_SETAuthKey sETAuthKey; /* OPTIONAL */
   supl_KeyIdentity4 keyIdentity4; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
*supl_SUPLRESPONSE;

/* SEQUENCE NavigationModel */
typedef struct supl_NavigationModel
{
   U8 validity;

   #define supl_NavigationModel_satInfo_valid 0x01

   U16 gpsWeek; /* MANDATORY */
   U8 gpsToe; /* MANDATORY */
   U8 nSAT; /* MANDATORY */
   U8 toeLimit; /* MANDATORY */
   supl_SatelliteInfo satInfo; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_NavigationModel;

/* SEQUENCE SUPLPOS */
typedef struct supl_SUPLPOS
{
   U8 validity;

   #define supl_SUPLPOS_velocity_valid 0x01

   supl_PosPayLoad posPayLoad; /* MANDATORY */
   supl_Velocity velocity; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
*supl_SUPLPOS;

/* SEQUENCE SetSessionID */
typedef struct supl_SetSessionID
{
   U16 sessionId; /* MANDATORY */
   supl_SETId setId; /* MANDATORY */
}
supl_SetSessionID;

/* OCTET STRING SlpSessionID-sessionID */
typedef struct supl_SlpSessionID_sessionID
{
   U8 numOctets;
   U8 stringData[4];
}
supl_SlpSessionID_sessionID;

/* SEQUENCE SlpSessionID */
typedef struct supl_SlpSessionID
{
   supl_SlpSessionID_sessionID sessionID; /* MANDATORY */
   supl_SLPAddress slpId; /* MANDATORY */
}
supl_SlpSessionID;

/* SEQUENCE Position */
typedef struct supl_Position
{
   U8 validity;

   #define supl_Position_velocity_valid 0x01

   applib_asn_UTCTime timestamp; /* MANDATORY */
   supl_PositionEstimate positionEstimate; /* MANDATORY */
   supl_Velocity velocity; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_Position;

/* SEQUENCE GsmCellInformation */
typedef struct supl_GsmCellInformation
{
   U8 validity;

   #define supl_GsmCellInformation_nMR_valid 0x02
   #define supl_GsmCellInformation_tA_valid 0x01

   U16 refMCC; /* MANDATORY */
   U16 refMNC; /* MANDATORY */
   U16 refLAC; /* MANDATORY */
   U16 refCI; /* MANDATORY */
   supl_NMR nMR; /* OPTIONAL */
   U8 tA; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_GsmCellInformation;

/* CHOICE FrequencyInfo-modeSpecificInfo */
typedef enum
{
   supl_FrequencyInfo_modeSpecificInfo_fdd_selected = 1,
   supl_FrequencyInfo_modeSpecificInfo_tdd_selected,
   supl_FrequencyInfo_modeSpecificInfo_UnKnowItem_selected
}
supl_FrequencyInfo_modeSpecificInfo_selector;

typedef struct supl_FrequencyInfo_modeSpecificInfo
{
   supl_FrequencyInfo_modeSpecificInfo_selector selection;

   union
   {
      supl_FrequencyInfoFDD fdd;
      supl_FrequencyInfoTDD tdd;
   applib_ChoiceUnKnow	UnKnowItem;
   }
   choice;
}
supl_FrequencyInfo_modeSpecificInfo;

/* SEQUENCE FrequencyInfo */
typedef struct supl_FrequencyInfo
{
   supl_FrequencyInfo_modeSpecificInfo modeSpecificInfo; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_FrequencyInfo;

/* SEQUENCE OF CellMeasuredResultsList */
typedef struct supl_CellMeasuredResultsList
{
   U8 numElements;

   supl_CellMeasuredResults element[32];
}
supl_CellMeasuredResultsList;

/* SEQUENCE RequestedAssistData */
typedef struct supl_RequestedAssistData
{
   U8 validity;

   #define supl_RequestedAssistData_navigationModelData_valid 0x01

   Bool almanacRequested; /* MANDATORY */
   Bool utcModelRequested; /* MANDATORY */
   Bool ionosphericModelRequested; /* MANDATORY */
   Bool dgpsCorrectionsRequested; /* MANDATORY */
   Bool referenceLocationRequested; /* MANDATORY */
   Bool referenceTimeRequested; /* MANDATORY */
   Bool acquisitionAssistanceRequested; /* MANDATORY */
   Bool realTimeIntegrityRequested; /* MANDATORY */
   Bool navigationModelRequested; /* MANDATORY */
   supl_NavigationModel navigationModelData; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_RequestedAssistData;

/* SEQUENCE SUPLEND */
typedef struct supl_SUPLEND
{
   U8 validity;

   #define supl_SUPLEND_position_valid 0x04
   #define supl_SUPLEND_statusCode_valid 0x02
   #define supl_SUPLEND_ver_valid 0x01

   supl_Position position; /* OPTIONAL */
   supl_StatusCode statusCode; /* OPTIONAL */
   supl_Ver ver; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
*supl_SUPLEND;

/* SEQUENCE SessionID */
typedef struct supl_SessionID
{
   U8 validity;

   #define supl_SessionID_setSessionID_valid 0x02
   #define supl_SessionID_slpSessionID_valid 0x01

   supl_SetSessionID setSessionID; /* OPTIONAL */
   supl_SlpSessionID slpSessionID; /* OPTIONAL */
}
supl_SessionID;

/* SEQUENCE MeasuredResults */
typedef struct supl_MeasuredResults
{
   U8 validity;

   #define supl_MeasuredResults_frequencyInfo_valid 0x04
   #define supl_MeasuredResults_utra_CarrierRSSI_valid 0x02
   #define supl_MeasuredResults_cellMeasuredResultsList_valid 0x01

   supl_FrequencyInfo frequencyInfo; /* OPTIONAL */
   supl_UTRA_CarrierRSSI utra_CarrierRSSI; /* OPTIONAL */
   supl_CellMeasuredResultsList cellMeasuredResultsList; /* OPTIONAL */
}
#if _FP_CR_SYNC_MAUI_03018028_ == 0
supl_MeasuredResults;
#else
*supl_MeasuredResults;
#endif

/* SEQUENCE OF MeasuredResultsList */
typedef struct supl_MeasuredResultsList
{
   U8 numElements;

   supl_MeasuredResults element[8];
}
supl_MeasuredResultsList;

/* SEQUENCE WcdmaCellInformation */
typedef struct supl_WcdmaCellInformation
{
   U8 validity;

   #define supl_WcdmaCellInformation_frequencyInfo_valid 0x04
   #define supl_WcdmaCellInformation_primaryScramblingCode_valid 0x02
   #define supl_WcdmaCellInformation_measuredResultsList_valid 0x01

   U16 refMCC; /* MANDATORY */
   U16 refMNC; /* MANDATORY */
   U32 refUC; /* MANDATORY */
   supl_FrequencyInfo frequencyInfo; /* OPTIONAL */
   U16 primaryScramblingCode; /* OPTIONAL */
   supl_MeasuredResultsList measuredResultsList; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
#if _FP_CR_SYNC_MAUI_03018028_ == 0
*supl_WcdmaCellInformation;
#else
supl_WcdmaCellInformation;
#endif

/* CHOICE CellInfo */
typedef enum
{
   supl_CellInfo_gsmCell_selected = 1,
   supl_CellInfo_wcdmaCell_selected,
   supl_CellInfo_cdmaCell_selected,
   supl_CellInfo_UnKnowItem_selected
}
supl_CellInfo_selector;

typedef struct supl_CellInfo
{
   supl_CellInfo_selector selection;

   union
   {
      supl_GsmCellInformation gsmCell;
      supl_WcdmaCellInformation wcdmaCell;
      supl_CdmaCellInformation cdmaCell;
   applib_ChoiceUnKnow	UnKnowItem;
   }
   choice;
}
supl_CellInfo;

/* SEQUENCE LocationId */
typedef struct supl_LocationId
{
   supl_CellInfo cellInfo; /* MANDATORY */
   supl_Status status; /* MANDATORY */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
supl_LocationId;

/* SEQUENCE SUPLSTART */
typedef struct supl_SUPLSTART
{
   U8 validity;

   #define supl_SUPLSTART_qoP_valid 0x01

   supl_SETCapabilities sETCapabilities; /* MANDATORY */
   supl_LocationId locationId; /* MANDATORY */
   supl_QoP qoP; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
*supl_SUPLSTART;

/* SEQUENCE SUPLPOSINIT */
typedef struct supl_SUPLPOSINIT
{
   U8 validity;

   #define supl_SUPLPOSINIT_requestedAssistData_valid 0x08
   #define supl_SUPLPOSINIT_position_valid 0x04
   #define supl_SUPLPOSINIT_sUPLPOS_valid 0x02
   #define supl_SUPLPOSINIT_ver_valid 0x01

   supl_SETCapabilities sETCapabilities; /* MANDATORY */
   supl_RequestedAssistData requestedAssistData; /* OPTIONAL */
   supl_LocationId locationId; /* MANDATORY */
   supl_Position position; /* OPTIONAL */
   supl_SUPLPOS sUPLPOS; /* OPTIONAL */
   supl_Ver ver; /* OPTIONAL */


   applib_UnKnowExtensionItemArray	UnKnowItem;
}
*supl_SUPLPOSINIT;

/* CHOICE UlpMessage */
typedef enum
{
   supl_UlpMessage_msSUPLINIT_selected = 1,
   supl_UlpMessage_msSUPLSTART_selected,
   supl_UlpMessage_msSUPLRESPONSE_selected,
   supl_UlpMessage_msSUPLPOSINIT_selected,
   supl_UlpMessage_msSUPLPOS_selected,
   supl_UlpMessage_msSUPLEND_selected,
   supl_UlpMessage_msSUPLAUTHREQ_selected,
   supl_UlpMessage_msSUPLAUTHRESP_selected,
   supl_UlpMessage_UnKnowItem_selected
}
supl_UlpMessage_selector;

typedef struct supl_UlpMessage
{
   supl_UlpMessage_selector selection;

   union
   {
      supl_SUPLINIT msSUPLINIT;
      supl_SUPLSTART msSUPLSTART;
      supl_SUPLRESPONSE msSUPLRESPONSE;
      supl_SUPLPOSINIT msSUPLPOSINIT;
      supl_SUPLPOS msSUPLPOS;
      supl_SUPLEND msSUPLEND;
      supl_SUPLAUTHREQ msSUPLAUTHREQ;
      supl_SUPLAUTHRESP msSUPLAUTHRESP;
   applib_ChoiceUnKnow	UnKnowItem;
   }
   choice;
}
supl_UlpMessage;

/* SEQUENCE ULP-PDU */
typedef struct supl_ULP_PDU
{
   U16 length; /* MANDATORY */
   supl_Version version; /* MANDATORY */
   supl_SessionID sessionID; /* MANDATORY */
   supl_UlpMessage message; /* MANDATORY */
}
supl_ULP_PDU;


//Encode Function  Declaration
extern U32 AsnEncode_supl_ULP_PDU( supl_ULP_PDU *pType, U8 **ppEncoded, U32 *pEncodedLength, applib_AsnCustomMemFunctions *pMemFuncs );




//Decode Function  Declaration
extern U32 AsnDecode_supl_ULP_PDU( supl_ULP_PDU **ppType, U8 *pEncoded, U32 *pEncodedLength, void *pAppContext, applib_AsnCustomMemFunctions *pMemFuncs );






#endif /* _SUPL_H */