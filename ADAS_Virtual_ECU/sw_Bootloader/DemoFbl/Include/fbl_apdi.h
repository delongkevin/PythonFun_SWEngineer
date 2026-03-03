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
#define kFblSizePreviousAccessList               10u

#define kApplInfoSizeFileHeaderInfo 160
#define kApplInfoSizeFileHeaderUuid 16

/* 2954: Policy Type */
#define CUSTOMER_INTENT_POLICY                   4u
/* F111: Public Certificates - Regional Support */
#define REST_OF_WORLD                            0x04

/* Supported diagnostic Data Identifiers */
#define kFblDiagDidVehicleNetworkSecurityStatus  0x100Au  /* C16 */
#define kFblDiagDidDiagToolAndSessionStatus      0x100B            /*Magna*/
#define kFblDiagDidOdometerHighResolution        0x2000u  /* C12 */
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
#define kFblDiagDidEBOMAssemblyPartNumber        0xF133u           /* Magna */
#define kFblDiagDidCODEPAssemblyPartNumber       0xF134u           /* Magna */
#define kFblDiagDidHardwareSupplierId            0xF154u  /* C1 */
#define kFblDiagDidSoftwareSupplierId            0xF155u  /* C1 */
#define kFblDiagDidBootSwVersionInfo             0xF180u  /* M */
#define kFblDiagDidActiveDiagSessDid             0xF186u  /* C1 */
#define kFblDiagDidCodepEcuPartNo                0xF187u  /* C1 */
#define kFblDiagDidVehicleManufEcuSwNo           0xF188u  /* C1 */
#define kFblDiagDidECUSoftwareCalibrationNumber  0xF18Au           /* Magna */
#define kFblDiagDidSoftwareApplicationNumber     0xF18Bu           /* Magna */
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
#define kFblDiagDidBootSwFingerprintRead         0xF1B3u  /* C4 */
#define kFblDiagDidApplSwFingerprintRead         0xF1B4u  /* C4 */
#define kFblDiagDidApplDataFingerprintRead       0xF1B5u  /* C4 */
#define kFblDiagDidBootSwFingerprintWrite        0xF183u  /* C14 */
#define kFblDiagDidApplSwFingerprintWrite        0xF184u  /* C14 */
#define kFblDiagDidApplDataFingerprintWrite      0xF185u  /* C14 */
#define kFblDiagDidProgrammedAssembly            0xFD38u  /* FD38 */
#define kFblDiagDidPolicyType		           	    0x2954u /*	2954	*/
#define kFblDiagDidAppSWHeaderInfo	             0x2957u	/*	2957	*/
#define kFblDiagDidAppSWHeaderUuid	             0x2958u	/*	2958	*/
#define kFblDiagDidAppDataConfigInfo	          0x2959u	/*	2959	*/
#define kFblDiagDidAppDataHeaderUuid	          0x295Au	/*	295A	*/
#define kFblDiagDidAppHtaHeaderInfo	             0x295Bu	/*	295B	*/
#define kFblDiagDidAppHtaHeaderUuid	             0x295Cu	/*	295C	*/
#define kFblDiagDidAppDCLHeaderUuid	             0x295Eu	/*	295E	*/
#define kFblDiagDidAppDCLHeaderInfo              0x295Fu	/*	295F	*/
#define kFblDiagDidAuthenticDiagPrevAccess	    0x2030u	/*	2030	*/
#define kFblDiagDidDisallowedCertList	          0x2031u	/*	2031	*/
#define kFblDiagDidSecureLog	                   0x2032u	/*	2032	*/
#define kFblDiagDidSecurityStatus	             0x100Cu	/*	100C	*/
#define kFblDiagDidPublicCertRegion	             0xF111u	/*	F111	*/
#define kFblDiagDidActiveRole		           	    0x0108u /*	0108	*/
#define kFblDiagDidBootFailureReason		       0x201Fu /*	201F	*/


/* Data identifier response length */
#define kDiagRslDidVehicleNetworkSecurityStatus           0u
#define kDiagRslDidDiagToolAndSessionStatus           	  1u
#define kDiagRslDidOdometerHighResolution                 3u
#define kDiagRslDidOdometerContentLastPrg                 2u
#define kDiagRslDidBootSwProgAttemptCounter               4u  /* 4 bytes per block */
#define kDiagRslDidProgrammingStatus                      2u
#define kDiagRslDidApplSwReprogAttemptCounter             (kBlockTypeCodeBlockCount*4u) /* 4 bytes per block for attempt counter, 4 bytes per block for Max number of attempt counter */
#define kDiagRslDidApplDataReprogAttemptCounter           (kBlockTypeDataBlockCount*4u)  /* 4 bytes per block */
#define kDiagRslDidEcuPkiUuid                            16u
#define kDiagRslDidDiagnosticSpecInfo                     4u
#define kDiagRslDidEcuDiagIdentification                 10u
#define kDiagRslDidEcuIdentificationHwPartNo             10u  /* Hardware EBOM Part number */
#define kDiagRslDidSwEbomPartNo                          (FBL_LBT_BLOCK_COUNT*10u)  /* 20 hex white space ASCI chars if not supported */
#define kDiagRslDidEbomEcuPartNo                         10u
#define kDiagRslDidEBOMAssemblyPartNumber                10u /* Magna */
#define kDiagRslDidCODEPAssemblyPartNumber               11u /* Magna */
#define kDiagRslDidHardwareSupplierId                     2u
#define kDiagRslDidSoftwareSupplierId                     2u
#define kDiagRslDidVehicleIdentification                  4u
#define kDiagRslDidBootSwVersionInfo                     14u  /* 1 byte number of blocks + 1 byte Year + 1 byte week + 1 byte patch level + 10 byte SwIdent */
#define kDiagRslDidApplSwIdentification                  (kBlockTypeCodeBlockCount*13u)  /*13 bytes per application SW logical blocks. No Logical blocks 7. 13*7=91*/
#define kDiagRslDidApplDataIdentification                (kBlockTypeDataBlockCount*13u)  /*13 bytes per application Data logical blocks. No Logical blocks 2. 13*2=26*/
#define kDiagRslDidActiveDiagSessDid                      3u
#define kDiagRslDidCodepEcuPartNo                        11u
#define kDiagRslDidVehicleManufEcuSwNo                   11u
#define kDiagRslDidECUSoftwareCalibrationNumber          10u
#define kDiagRslDidSoftwareApplicationNumber             10u
#define kDiagRslDidEcuSerialNumber                       15u
#define kDiagRslDidVinOriginal                           17u
#define kDiagRslDidVehicleManufECUHwNo                   11u
#define kDiagRslDidSupplierManufECUHwPartNo              11u
#define kDiagRslDidSupplierManufECUHwVersionNo            1u
#define kDiagRslDidSupplierManufECUSwPartNo              11u
#define kDiagRslDidSupplierManufECUSwVersionNo            2u
#define kDiagRslDidExRegOrTypeApprovalNo                  5u
#define kDiagRslDidSystemIdentificationData              90u
#define kDiagRslDidVectorDeliveryId                      10u
#define kDiagRslDidAlgorithmIdNumberReprog                2u
#define kDiagRslDidVinCurrent                            17u
#define kDiagRslDidBootSwFingerprintRead                 15u  /* 1 byte number of blocks + 13 bytes per block */
#define kDiagRslDidApplSwFingerprintRead                 1u + (kBlockTypeCodeBlockCount*14u)
#define kDiagRslDidApplDataFingerprintRead               1u + (kBlockTypeDataBlockCount*14u)
#define kDiagRslDidBootSwFingerprintWrite                14u
#define kDiagRslDidApplSwFingerprintWrite                14u
#define kDiagRslDidApplDataFingerprintWrite              14u
#define kDiagRslDidBootSwFingerprintReadAuth             14u  /* 1 byte number of blocks + 13 bytes per block */
#define kDiagRslDidApplSwFingerprintReadAuth             14u
#define kDiagRslDidApplDataFingerprintReadAuth           14u
#define kDiagRslDidBootSwFingerprintWriteAuth            14u
#define kDiagRslDidApplSwFingerprintWriteAuth            14u
#define kDiagRslDidApplDataFingerprintWriteAuth          14u
#define kDiagRslDidPCBSerialNumber     				      14u
#define kDiagRslDidProgrammedAssembly          	 		   16u   /* FD38 */
#define kDiagRslDidPolicyType		           	 	      	1u
#define kDiagRslDidAppSWHeaderInfo	                     1056u	/*	2957	*/
#define kDiagRslDidAppSWHeaderUuid	                     96u	/*	2958	*/
#define kDiagRslDidAppDataConfigInfo	                  352u	/*	2959	*/
#define kDiagRslDidAppDataHeaderUuid	                  32u	/*	295A	*/
#define kDiagRslDidAppHtaHeaderInfo	                     176u	/*	295B	*/
#define kDiagRslDidAppHtaHeaderUuid	                     16u	/*	295C	*/
#define kDiagRslDidAppDCLHeaderUuid	                     16u	/*	295E	*/
#define kDiagRslDidAppDCLHeaderInfo	                     176u	/*	295F	*/
#define kDiagRslDidAuthenticDiagPrevAccess	            960u	/*	2030	*/
#define kDiagRslDidDisallowedCertList	                  3072u	/*	2031	*/
#define kDiagRslDidSecureLog	                           1296u	/*	2032	*/
#define kDiagRslDidSecurityStatus	                     5u  	/*	100C	*/
#define kDiagRslDidPublicCertRegion	                     1u 	/*	F111	*/
#define kDiagRslDidActiveRole		           	 		      4u
#define kDiagRslDidBootFailureReason		               2u    /* 201F */

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
extern uint8 MCU1_0_AuthFailStatus;
extern vuint8 flashStatBuffer[2u];
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
