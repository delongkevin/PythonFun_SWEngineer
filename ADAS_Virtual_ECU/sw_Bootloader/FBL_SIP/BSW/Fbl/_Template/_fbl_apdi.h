/* Kernbauer Version: 1.12 Konfiguration: FBL Erzeugungsgangnummer: 1 */

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application dependent diagnostic routines
 *
 *  \note          Please note, that this file contains a collection of callback functions to be used with the
 *                 Flash Bootloader. These functions may influence the behavior of the bootloader in principle.
 *                 Therefore, great care must be taken to verify the correctness of the implementation.
 *                 The contents of the originally delivered files are only examples resp. implementation proposals.
 *                 With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                 Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                 admissible by law or statute.
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2018-08-10  viscb   -                Release
 *  01.01.00   2018-09-18  viscb   ESCAN00100804    Add application support for service ClearDiagnosticInformation
 *  01.02.00   2018-11-02  viscb   ESCAN00101214    ApplFblClearDiagnosticInformation generally available
 *  01.02.01   2019-01-31  viscb   ESCAN00101958    No changes
 *  01.02.02   2019-07-12  viscb   ESCAN00103713    Support for ClearDiagnosticInformation for demo application only
 *  02.00.00   2020-03-26  vistbe  FBL-1510         Upgrade to latest reference implementation
 *  02.01.00   2020-12-17  vistbe  FBL-1352         Added support for Authenticated Diagnostics
 *  02.02.00   2021-04-12  vistmo  FBL-2961         Added support for Authenticated Diagnostics with vHSM
 *  02.03.00   2021-06-16  vistbe  FBL-3275         No changes
 *  02.04.00   2022-06-14  visrie  FBL-5323         Support CSR Request - 0xD00A
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2018-09-14  visrie  ESCAN00100739    Added support for FblLib_NvPattern
 *                                                  Removed unused code
 *                         viscb   ESCAN00101418    Callout function for memory condition check
 *                         visach  ESCAN00101686    No changes
 *  02.01.00   2019-02-26  visrie  ESCAN00102257    Added additional callout functions
 *  02.01.01   2019-09-23  visrie  FBL-452          No changes
 *  02.02.00   2019-12-05  visrie  FBL-458          Added FblMio callout functions
 *  02.03.00   2020-05-07  visrie  FBL-1414         Added callout functions for One-Step-Updater
 *  02.03.01   2020-06-02  visjdn  ESCAN00106533    No changes
 *  02.03.02   2020-09-14  visrcn  FBL-2257         No changes
 *  02.03.03   2020-11-23  visrcn  FBL-2564         No changes
 *  02.03.04   2021-03-19  visjdn  FBL-2916         No changes
 *  02.04.00   2021-05-25  vishor  FBL-3165         MISRA corrections and justifications
 *  02.05.00   2021-06-15  visrie  FBL-3591         No changes
 *  02.06.00   2021-07-15  visjdn  FBL-3381         Re-mapping of EcuM_SetWakeupEvent
 *  02.07.00   2021-07-23  visrie  FBL-3822         No changes
 *  02.08.00   2021-09-14  visjdn  FBL-2859         No changes
 *  02.09.00   2021-10-12  vistmo  FBL-3901         Add authentication callbacks
 *  02.10.00   2021-10-15  visrie  FBL-3945         Remove content of ApplFblStartApplication
 *  02.10.01   2021-11-12  vishor  ESCAN00110133    Compiler error: Unknown symbols
 *                                                   ApplFblSave/RestoreStatusSector/Dynamic
 *  02.10.02   2022-06-27  visrie  FBL-4694         No changes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY (KbFbl_apOem.h)
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.02   2018-08-10  viscb   -                Release
 *  01.00.03   2018-09-25  visqps  ESCAN00100849    No changes
 *  01.01.00   2018-11-06  viscb   ESCAN00101210    No changes
 *                         viscb   ESCAN00101238    Support for security class Vendor
 *  01.02.00   2019-01-29  viscb   ESCAN00101942    Changed type of certState from enum to vuint8
 *  01.03.00   2019-02-20  visshs  ESCAN00102196    No changes
 *  02.00.00   2020-03-26  vistbe  FBL-1510         Upgrade to latest reference implementation
 *                                 ESCAN00105994    No changes
 *  02.01.00   2020-07-13  visrie  FBL-2021         Added support for OTA
 *  02.02.00   2020-10-11  vistbe  FBL-2419         No changes
 *  02.03.00   2020-12-17  vistbe  FBL-1352         No changes
 *  02.04.00   2021-04-12  vistmo  FBL-2961         No changes
 *  02.04.01   2021-08-05  visrie  ESCAN00109778    No changes
 *  02.04.02   2022-06-20  vishor  ESCAN00106412    No changes
 *                                 ESCAN00108782    No changes
 *                                 ESCAN00108761    No changes
 **********************************************************************************************************************/

#ifndef FBL_APDI_H
#define FBL_APDI_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblKbApi_FrameDiag_Fca CQComponent : Implementation */
#define FBLKBAPI_FRAMEDIAG_FCA_VERSION           0x0204u
#define FBLKBAPI_FRAMEDIAG_FCA_RELEASE_VERSION   0x00u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define kFblSizeLogBlockHash                     20u
#define kFblSizeLogHashPadding                   12u
#define kFblSizeFiatVersionInformation           13u
#define kFblSizeFiatPartNumber                   11u
#define kFblSizeFiatVersionNumber                1u
#define kFblSizeFiatEcuSoftwareNumber            11u


/* Supported diagnostic Data Identifiers */
#define kFblDiagDidVehicleNetworkSecurityStatus  0x100Au  /* C16 */
#define kFblDiagDidOdometerHighResolution        0x2000u  /* C12 */
#define kFblDiagDidOdometer                      0x2001u  /* C12 */
#define kFblDiagDidOdometerContentLastPrg        0x2002u  /* C1 */
#define kFblDiagDidBootSwProgAttemptCounter      0x2003u  /* C1 */
#define kFblDiagDidProgrammingStatus             0x2010u  /* C1 */
#define kFblDiagDidApplSwReprogAttemptCounter    0x201Au  /* C1 */
#define kFblDiagDidApplDataReprogAttemptCounter  0x201Bu  /* C1 */
#define kFblDiagDidEcuPkiUuid                    0x2951u
#define kFblDiagDidDiagnosticSpecInfo            0xF10Du  /* C1 */
#define kFblDiagDidEcuDiagIdentification         0xF110u  /* C1 */
#define kFblDiagDidEcuIdentificationHwPartNo     0xF112u  /* M */
#define kFblDiagDidSwEbomPartNo                  0xF122u  /* M */
#define kFblDiagDidEbomEcuPartNo                 0xF132u  /* C1 */
#define kFblDiagDidHardwareSupplierId            0xF154u  /* C1 */
#define kFblDiagDidSoftwareSupplierId            0xF155u  /* C1 */
#define kFblDiagDidVehicleIdentification         0xF158u  /* C7 */
#define kFblDiagDidBootSwVersionInfo             0xF180u  /* M */
#define kFblDiagDidApplSwIdentification          0xF181u  /* M */
#define kFblDiagDidApplDataIdentification        0xF182u  /* M */
#define kFblDiagDidActiveDiagSessDid             0xF186u  /* C1 */
#define kFblDiagDidCodepEcuPartNo                0xF187u  /* C1 */
#define kFblDiagDidVehicleManufEcuSwNo           0xF188u  /* C1 */
#define kFblDiagDidEcuSerialNumber               0xF18Cu  /* C1 */
#define kFblDiagDidVinOriginal                   0xF190u  /* C1 */
#define kFblDiagDidVehicleManufECUHwNo           0xF191u  /* C1 */
#define kFblDiagDidSupplierManufECUHwPartNo      0xF192u  /* C1 */
#define kFblDiagDidSupplierManufECUHwVersionNo   0xF193u  /* C1 */
#define kFblDiagDidSupplierManufECUSwPartNo      0xF194u  /* C1 */
#define kFblDiagDidSupplierManufECUSwVersionNo   0xF195u  /* C1 */
#define kFblDiagDidExRegOrTypeApprovalNo         0xF196u  /* C5 */
#define kFblDiagDidSystemIdentificationData      0xF1A0u  /* C1 */
#define kFblDiagDidVectorDeliveryId              0xF1A2u  /* C1 */
#define kFblDiagDidAlgorithmIdNumberReprog       0xF1A4u  /* C1 */
#define kFblDiagDidVinCurrent                    0xF1B0u  /* C1 */
#define kFblDiagDidBootSwFingerprintRead         0xF1B3u  /* C4 */
#define kFblDiagDidApplSwFingerprintRead         0xF1B4u  /* C4 */
#define kFblDiagDidApplDataFingerprintRead       0xF1B5u  /* C4 */
#define kFblDiagDidBootSwFingerprintWrite        0xF183u  /* C14 */
#define kFblDiagDidApplSwFingerprintWrite        0xF184u  /* C14 */
#define kFblDiagDidApplDataFingerprintWrite      0xF185u  /* C14 */


/* Data identifier response length */
#define kDiagRslDidVehicleNetworkSecurityStatus           0u
#define kDiagRslDidOdometerHighResolution                 3u
#define kDiagRslDidOdometer                               2u
#define kDiagRslDidOdometerContentLastPrg                 2u
#define kDiagRslDidBootSwProgAttemptCounter               4u  /* 4 bytes per block */
#define kDiagRslDidProgrammingStatus                      2u
#define kDiagRslDidApplSwReprogAttemptCounter             4u  /* 4 bytes per block */
#define kDiagRslDidApplDataReprogAttemptCounter           4u  /* 4 bytes per block */
#define kDiagRslDidEcuPkiUuid                            16u
#define kDiagRslDidDiagnosticSpecInfo                     4u
#define kDiagRslDidEcuDiagIdentification                 10u
#define kDiagRslDidEcuIdentificationHwPartNo             10u  /* Hardware EBOM Part number */
#define kDiagRslDidSwEbomPartNo                          11u  /* 20 hex white space ASCI chars if not supported */
#define kDiagRslDidEbomEcuPartNo                         10u
#define kDiagRslDidHardwareSupplierId                     2u
#define kDiagRslDidSoftwareSupplierId                     2u
#define kDiagRslDidVehicleIdentification                  4u
#define kDiagRslDidBootSwVersionInfo                     13u  /* 1 bytes number of blocks + 13 bytes per block */
#define kDiagRslDidApplSwIdentification                  13u
#define kDiagRslDidApplDataIdentification                13u
#define kDiagRslDidActiveDiagSessDid                      2u
#define kDiagRslDidCodepEcuPartNo                        11u
#define kDiagRslDidVehicleManufEcuSwNo                   11u
#define kDiagRslDidEcuSerialNumber                       15u
#define kDiagRslDidVinOriginal                           17u
#define kDiagRslDidVehicleManufECUHwNo                   11u
#define kDiagRslDidSupplierManufECUHwPartNo              11u
#define kDiagRslDidSupplierManufECUHwVersionNo            1u
#define kDiagRslDidSupplierManufECUSwPartNo              11u
#define kDiagRslDidSupplierManufECUSwVersionNo            2u
#define kDiagRslDidExRegOrTypeApprovalNo                  5u
#define kDiagRslDidSystemIdentificationData              59u
#define kDiagRslDidVectorDeliveryId                      10u
#define kDiagRslDidAlgorithmIdNumberReprog                2u
#define kDiagRslDidVinCurrent                            17u
#define kDiagRslDidBootSwFingerprintRead                 14u  /* 1 byte number of blocks + 13 bytes per block */
#define kDiagRslDidApplSwFingerprintRead                 14u
#define kDiagRslDidApplDataFingerprintRead               14u
#define kDiagRslDidBootSwFingerprintWrite                14u
#define kDiagRslDidApplSwFingerprintWrite                14u
#define kDiagRslDidApplDataFingerprintWrite              14u
#define kDiagRslDidBootSwFingerprintReadAuth             14u  /* 1 byte number of blocks + 13 bytes per block */
#define kDiagRslDidApplSwFingerprintReadAuth             14u
#define kDiagRslDidApplDataFingerprintReadAuth           14u
#define kDiagRslDidBootSwFingerprintWriteAuth            14u
#define kDiagRslDidApplSwFingerprintWriteAuth            14u
#define kDiagRslDidApplDataFingerprintWriteAuth          14u

/* DTC handling definitions */
#define kDiagDtcStatus                                   0x0Fu
#define kDiagDtc_ECMPCM_NotProgrammedCodeInternal        0x00160200uL
#define kDiagDtc_TCM_NotProgrammedCodeInternal           0x001DC600uL
#define kDiagDtc_OCM_NotProgrammedCodeInternal           0x0B225000uL
#define kDiagDtc_MCPA_NotProgrammedCodeInternal          0x001A4F00uL
#define kDiagDtc_MCPB_NotProgrammedCodeInternal          0x001A5200uL
#define kDiagDtc_CtrlModProgErr_NotProgammedCodeInternal 0x00060200uL

/* ToDo: Select DTC for current ECU */
#define kDiagDtc_NotProgrammedCodeInternal                kDiagDtc_CtrlModProgErr_NotProgammedCodeInternal

/* Define the periodical timer for ADA certificate validation check */
#if !defined( FBL_APPL_ADA_CERT_VALIDATION_TIMER )
# define FBL_APPL_ADA_CERT_VALIDATION_TIMER 60000uL
#endif
/***********************************************************************************************************************
*  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
typedef enum
{
   kFblAnonymous = 0u,
   kFblAuthenticated
}tFblAuthenticationState;
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

void ApplDiagUserService( vuint8 * pbDiagData, tTpDataType diagReqDataLen );
void ApplDiagUserSubFunction( vuint8 * pbDiagData, tTpDataType diagReqDataLen );
tFblResult ApplFblCheckProgPreconditions( vuint8 * pbDiagData, tTpDataType diagReqDataLen );
void ApplFblReadDataByIdentifier( vuint8 * pbDiagData, tTpDataType diagReqDataLen );
vuint8 ApplFblWriteDataByIdentifier( vuint8 * pbDiagData, tTpDataType diagReqDataLen );
#if defined( FBL_DIAG_ENABLE_CLEAR_DIAGNOSTIC_INFORMATION )
tFblResult ApplFblClearDiagnosticInformation( vuint8 *pbDiagData, tTpDataType diagReqDataLen );
#endif
tFblResult ApplFblReportDTCByStatusMask( vuint8 *pbDiagData, tTpDataType diagReqDataLen );
#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
tFblResult ApplFblSecAccessRequestChallenge( vuint8* pbDiagData, tTpDataType diagReqDataLen );
tFblResult ApplFblSecAccessSendSignedChallenge( vuint8* pbDiagData, tTpDataType diagReqDataLen );
tFblAuthenticationState ApplFblGetAuthenticationState( void );
void ApplFblSetAuthenticationState( tFblAuthenticationState authState );
void ApplFblAuthenticationTimerTask( void );
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */
tFblResult ApplFblCSRTrigger( void );
#if defined( FBL_ENABLE_DEBUG_STATUS )
void ApplFblInitErrStatus( void );
#endif

#endif /* FBL_APDI_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_APDI.H
 **********************************************************************************************************************/
