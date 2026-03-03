/* Kernbauer Version: 1.12 Konfiguration: FBL Erzeugungsgangnummer: 1 */

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application dependent callout routines
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
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *  01.00.01   2018-10-05  visqps  ESCAN00100941    No changes
 *  01.01.00   2018-11-06  viscb   ESCAN00101211    No changes
 *                                 ESCAN00101239    Support for security class Vendor
 *  01.02.00   2019-01-29  viscb   ESCAN00101940    Additional functions for file header verification
 *  01.02.01   2019-07-19  vistbe  ESCAN00103774    SHA-256 Application Logical Block Hash Not Supported
 *  02.00.00   2020-03-26  vistbe  FBL-1510         Upgrade to latest reference implementation
 *  02.01.00   2020-10-11  vistbe  FBL-2419         Add support for FblLib_SecBoot_Escrypt
 *  02.02.00   2021-04-12  vistmo  FBL-2961         Added support for Authenticated Diagnostics with vHSM
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

#ifndef FBL_AP_H
#define FBL_AP_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblKbApi CQComponent : Implementation */
#define FBLKBAPI_VERSION                           0x0210u
#define FBLKBAPI_RELEASE_VERSION                   0x02u

/* ##V_CFG_MANAGEMENT ##CQProject : FblKbApi_Brs CQComponent : Implementation */
#define FBLKBAPI_BRS_VERSION          0x0201u
#define FBLKBAPI_BRS_RELEASE_VERSION  0x00u

/* ##V_CFG_MANAGEMENT ##CQProject : FblKbApi_Fca CQComponent : Implementation */
#define FBLKBAPI_FCA_VERSION                       0x0204u
#define FBLKBAPI_FCA_RELEASE_VERSION               0x02u

/* ##V_CFG_MANAGEMENT ##CQProject : FblKbApi_Frame_Fca CQComponent : Implementation */
#define FBLKBAPI_FRAME_FCA_VERSION                 0x0202u
#define FBLKBAPI_FRAME_FCA_RELEASE_VERSION         0x00u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Logical block table dependency and validity check configuration */
/* PRQA S 3453 TAG_FblAp_3453_2 */ /* MD_CBD_19.7 */
/** System must consist of at least two logical blocks to activate dependency check */
#define FBL_MIN_BLOCKS_FOR_DEPENDENCY    2u
/** First logical block number of the application */
#define FBL_START_LBT_APP                1u
/* PRQA L:TAG_FblAp_3453_2 */

#if ( DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON )
# define FBL_CW_CFG_PTR activeCwConfiguration
#endif
#define FBL_MAX_DID_COUNT    8u
#define CERTSTORE_INFO_HEADER_OFFSET 0x43C0
#define kApplInfoSizeFingerPrint 13

/* Part Number: Application software information */
#define kApplInfoSizeSoftwareIdentification_F181 13
#define kApplInfoSizeSwEbomPartNumber_F122 10
#define kApplInfoSizeHwCompatibilityCounter 1
#define kApplInfoSizeHwCompatibilityField 2
#define kApplInfoSizeSwCompatibility 10
#define kApplInfoSizeEbomEcuPartNumber_F132 10
#define kApplInfoSizeEBOMAssemblyPartNumber_F133 10
#define kApplInfoSizeCODEPAssemblyPartNumber_F134 11
#define kApplInfoSizeCodepEcupartNumber_F187 11
#define kApplInfoSizeFCAESLMECUSoftwareNumber_F188 11
#define kApplInfoSizeFCAESLMECUSoftwareCalibrationNumber_F18A 10
#define kApplInfoSizeFCAESLMECUSoftwareApplicationNumber_F18B 10
#define kApplInfoSizeSupplierECUSoftwarePartNumber_F194 11
#define kApplInfoSizeSupplierECUSoftwareVersionNumber_F195 2
#define kApplInfoSizeDiagnosticVersionFlashDefinition_F110 6

#define kApplInfoSizeHwCompatibilityCount           1u
#define kApplInfoSizeHwCompatibility                2u
#define kApplInfoNumberHwCompatibilityEntries       2u

/* Part Number: Offsets to start address of structure */
#define kApplInfoOffsetSoftwareIdentification_F181 					0u
#define kApplInfoOffsetSwEbomPartNumber_F122 						(kApplInfoOffsetSoftwareIdentification_F181	           		+ kApplInfoSizeSoftwareIdentification_F181   			)
#define kApplInfoOffsetHwCompatibilityCounter						(kApplInfoOffsetSwEbomPartNumber_F122       				+ kApplInfoSizeSwEbomPartNumber_F122    				)
#define kApplInfoOffsetHwCompatibilityField							(kApplInfoOffsetHwCompatibilityCounter           			+ kApplInfoSizeHwCompatibilityCounter		           	)
#define kApplInfoOffsetSwCompatibility 								(kApplInfoOffsetHwCompatibilityField           				+ kApplInfoSizeHwCompatibilityField           			)
#define kApplInfoOffsetEbomEcuPartNumber_F132						(kApplInfoOffsetSwCompatibility           					+ kApplInfoSizeSwCompatibility         					)
#define kApplInfoOffsetEBOMAssemblyPartNumber_F133					(kApplInfoOffsetEbomEcuPartNumber_F132           			+ kApplInfoSizeEbomEcuPartNumber_F132    				)
#define kApplInfoOffsetCODEPAssemblyPartNumber_F134					(kApplInfoOffsetEBOMAssemblyPartNumber_F133           		+ kApplInfoSizeEBOMAssemblyPartNumber_F133          	)
#define kApplInfoOffsetCodepEcupartNumber_F187						(kApplInfoOffsetCODEPAssemblyPartNumber_F134           		+ kApplInfoSizeCODEPAssemblyPartNumber_F134           	)
#define kApplInfoOffsetFCAESLMECUSoftwareNumber_F188				(kApplInfoOffsetCodepEcupartNumber_F187           			+ kApplInfoSizeCodepEcupartNumber_F187           		)
#define kApplInfoOffsetFCAESLMECUSoftwareCalibrationNumber_F18A		(kApplInfoOffsetFCAESLMECUSoftwareNumber_F188           	+ kApplInfoSizeFCAESLMECUSoftwareNumber_F188           	)
#define kApplInfoOffsetFCAESLMECUSoftwareApplicationNumber_F18B		(kApplInfoOffsetFCAESLMECUSoftwareCalibrationNumber_F18A	+ kApplInfoSizeFCAESLMECUSoftwareCalibrationNumber_F18A )
#define kApplInfoOffsetSupplierECUSoftwarePartNumber_F194			(kApplInfoOffsetFCAESLMECUSoftwareApplicationNumber_F18B    + kApplInfoSizeFCAESLMECUSoftwareApplicationNumber_F18B )
#define kApplInfoOffsetSupplierECUSoftwareVersionNumber_F195		(kApplInfoOffsetSupplierECUSoftwarePartNumber_F194          + kApplInfoSizeSupplierECUSoftwarePartNumber_F194       )
#define kApplInfoOffsetDiagnosticVersionFlashDefinition_F110		(kApplInfoOffsetSupplierECUSoftwareVersionNumber_F195       + kApplInfoSizeSupplierECUSoftwareVersionNumber_F195    )

/* File Header : Application software information */
#define kApplInfoSizeFileHeaderInfo	160u
#define kApplInfoSizeUuid	16u

/* File Header : Offsets to start address of structure */
#define kApplInfoOffsetFileHeaderInfo                                0u
#define kApplInfoOffsetUuid                                          (kApplInfoOffsetFileHeaderInfo             + kApplInfoSizeFileHeaderInfo)

/* Authenticated Prevous Access Info */
#define kApplInfoSizeIssuerName	64u
#define kApplInfoSizeSerialNumber	32u

#define kApplInfoSizeIssuerNameOffset	38u
#define kApplInfoSizeSerialNumberOffset	12u

/** Status information about certificates in logical block */
#define kApplInfoCertificateNone                    0u
#define kApplInfoCertificatePresent                 1u

typedef uint8 KeyM_CertificateStatusType;

# ifndef KEYM_CERTIFICATE_VALID /* COV_KEYM_NON_RTE */
#  define KEYM_CERTIFICATE_VALID                                      (0x00u)
# endif

/* The certificate is invalid (unspecified failure) */
# ifndef KEYM_CERTIFICATE_INVALID /* COV_KEYM_NON_RTE */
#  define KEYM_CERTIFICATE_INVALID                                    (0x01u)
# endif

/* Certificate has not been parsed so far. */
# ifndef KEYM_CERTIFICATE_NOT_PARSED /* COV_KEYM_NON_RTE */
#  define KEYM_CERTIFICATE_NOT_PARSED                                 (0x02u)
# endif

/* Certificate parsed but not yet validated */
# ifndef KEYM_CERTIFICATE_PARSED_NOT_VALIDATED /* COV_KEYM_NON_RTE */
#  define KEYM_CERTIFICATE_PARSED_NOT_VALIDATED                       (0x03u)
# endif

/* Certificate not set */
# ifndef KEYM_CERTIFICATE_NOT_AVAILABLE /* COV_KEYM_NON_RTE */
#  define KEYM_CERTIFICATE_NOT_AVAILABLE                              (0x04u)
# endif

/* Certificate verification failed - Invalid Time Period */
# ifndef KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL                     (0x05u)
# endif

/* Certificate verification failed - Invalid Signature */
# ifndef KEYM_E_CERTIFICATE_SIGNATURE_FAIL /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_SIGNATURE_FAIL                           (0x06u)
# endif

/* Certificate verification failed - Invalid Chain of Trust */
# ifndef KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST                   (0x07u)
# endif

/* Certificate verification failed - Invalid Type */
# ifndef KEYM_E_CERTIFICATE_INVALID_TYPE /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_INVALID_TYPE                             (0x08u)
# endif

/* Certificate verification failed - Invalid Format */
# ifndef KEYM_E_CERTIFICATE_INVALID_FORMAT /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_INVALID_FORMAT                           (0x09u)
# endif

/* Certificate verification failed - Invalid Content */
# ifndef KEYM_E_CERTIFICATE_INVALID_CONTENT /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_INVALID_CONTENT                          (0x0Au)
# endif

/* Certificate verification failed - Invalid Scope */
# ifndef KEYM_E_CERTIFICATE_REVOKED /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_REVOKED                                  (0x0Bu)
# endif

#define INFO_HEADER_SIZE 128u
#define INFO_HEADER_START_ADDRESS 0x3001C0ul

#define D_CMAC_LEN 16u
#define D_HASH_LEN 32u
#define D_SIGN_LEN 256u

#define D_DATA_LEN 24u
#define D_RECORD_PER_GRP 10u
#define D_REC_STORAGE_SIZE 48u

#define D_SEC_NUM_SIZE    2u
#define D_TIMESTAMP_SIZE  4u
#define D_EVENT_TYPE_SIZE 1u
#define D_SUB_TYPE_SIZE   1u
#define D_EVENT_DATA_SIZE 23u

#define D_RECORD_DATA_SIZE (D_SEC_NUM_SIZE + D_TIMESTAMP_SIZE + D_EVENT_TYPE_SIZE + D_SUB_TYPE_SIZE + D_EVENT_DATA_SIZE)


#define D_SEC_NUM_POS     0u
#define D_TIMESTAMP_POS   (D_SEC_NUM_POS + D_SEC_NUM_SIZE)
#define D_EVENT_TYPE_POS  (D_TIMESTAMP_POS + D_TIMESTAMP_SIZE)
#define D_SUB_TYPE_POS    (D_EVENT_TYPE_POS + D_EVENT_TYPE_SIZE)
#define D_EVENT_DATA_POS  (D_SUB_TYPE_POS + D_SUB_TYPE_SIZE)
#define D_CMAC_POS        (D_EVENT_DATA_POS + D_EVENT_DATA_SIZE)

#define D_LOG_ENTRY_EXPORT_SIZE (D_RECORD_DATA_SIZE + 1u)
#define RIGHTSHIFT_BIT(x, pos)  (x >> pos)

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/** Status information to detect abnormal shutdown */
typedef enum
{
   kFblShutdownStatusNormal = 0u,
   kFblShutdownStatusAbnormal
}tFblShutdownStatus;

typedef enum e_EventType
{
AUTHNTICATION_FAILURE = 1,
FAILED_AUTHORIZATION_ATTEMPTS = 2,
UNAUTHORIZED_ACCESS = 7,
CYBERSEC_FAILURE = 8,
UNDEFINED_EVENT
} EventType;

typedef enum e_EventSubType
{
  No_SUB_TYPE = 0,
  SEC_BOOT_FAILURE =1,
  SEC_FLASHING_FAILURE =2,
  CERTIFICATE_FAILURE =3,
}EventSubType;

typedef struct
{
  uint8 Valid;
  uint8 RecId;
  uint16 SecId;
  uint32 GroupCnt;
  uint8 RecordEntry[D_RECORD_PER_GRP][D_REC_STORAGE_SIZE];
} SecureLogRecord_t;
/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

#if ( DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON )
/** Pointer to select active ECU of a multiple identity configuration */
extern P2CONST(FblCw_ConfigType, AUTOMATIC, FBLCW_INIT_DATA) activeCwConfiguration;
#endif /* DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON */


#if defined( FBL_ENABLE_COMMON_DATA )
# define FBLAP_FBLCOMMONDATA_START_SEC_CONST
# include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMROM0 extern V_MEMROM1 tFblCommonData V_MEMROM2 fblCommonData;
# define FBLAP_FBLCOMMONDATA_STOP_SEC_CONST
# include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBL_ENABLE_COMMON_DATA */

#define FBLAP_SHUTDOWNSTATUS_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
V_MEMRAM0 extern V_MEMRAM1 tFblShutdownStatus V_MEMRAM2 fblShutdownStatus;
#define FBLAP_SHUTDOWNSTATUS_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Tester Present counter */
extern uint32 TesterPresentCounter;
/* Variable to Check if EOL Data is present */
extern boolean IsEOlDataAvailaible;
/* Tester Present flag */
extern uint8 TesterPresentFlag;
# define kFblTesterPresentTime                     ((vuint32)(FBL_DIAG_TIME_P3MAX))
# define FblTesterPresentCounterReload()                ( TesterPresentCounter = kFblTesterPresentTime)
# define FblDecTesterPresentCounter()                   ( TesterPresentCounter-- )
# define FblGetTesterPresentCounter()                   ((vuint32) TesterPresentCounter )
/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

void ApplFblInit( void );
void ApplFblStartup( vuint8 initposition );
tFblResult ApplFblCheckProgConditions( void );
tFblResult ApplFblCheckConditions( vuint8 * pbDiagData, tTpDataType diagReqDataLen );
vuint8 ApplFblCheckHwSwCompatibility(vuint8 blockIdx);
vuint8 ApplFblCheckSwSwCompatibility(void);
vuint8 ApplFblCheckProgDependencies( void );
#if ( SEC_SECURITY_CLASS == SEC_CLASS_VENDOR )
vuint8 ApplFblVerifyFcaHeader(vuint8 blockNr, V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * segmentList);
#endif /* SEC_SECURITY_CLASS == SEC_CLASS_VENDOR */
void ApplTrcvrNormalMode( void );
void ApplTrcvrSleepMode( void );
#if defined( FBL_MIO_ENABLE_HOOKS )
void ApplFblPreMemDriver( vuint8 device, vuint8 function );
#endif /* FBL_MIO_ENABLE_HOOKS */
#if defined( FBL_MIO_ENABLE_HOOKS )
void ApplFblPostMemDriver( vuint8 device, vuint8 function );
#endif /* FBL_MIO_ENABLE_HOOKS */
void ApplFblSetVfp( void );
void ApplFblResetVfp( void );
void ApplFblReset( void );
#define FBLAP_RAMCODE_START_SEC_CODE_EXPORT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
vuint8 ApplFblSecuritySeedInit( void );
#define FBLAP_RAMCODE_STOP_SEC_CODE_EXPORT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#if defined( FBL_DIAG_ENABLE_SECACCESS_STANDARD )
vuint8 ApplFblSecuritySeed( void );
vuint8 ApplFblSecurityKey( void );
#endif /* FBL_DIAG_ENABLE_SECACCESS_STANDARD */
vuint8 ApplFblSecurityInit( void );
#if defined( FBL_ENABLE_DATA_PROCESSING )
tFblResult ApplFblInitDataProcessing( tProcParam * procParam );
tFblResult ApplFblDataProcessing( tProcParam * procParam );
tFblResult ApplFblDeinitDataProcessing( tProcParam * procParam );
#endif /* FBL_ENABLE_DATA_PROCESSING */

#if defined( FBL_ENABLE_APPL_TASK ) || \
    defined( FBL_ENABLE_APPL_TIMER_TASK )
#if defined( FBL_ENABLE_APPL_TASK ) || \
    defined( FBL_ENABLE_APPL_TIMER_TASK )
void ApplFblTask( void );
#endif /* FBL_ENABLE_APPL_TASK || FBL_ENABLE_APPL_TIMER_TASK */
#endif /* FBL_ENABLE_APPL_TASK || FBL_ENABLE_APPL_TIMER_TASK */
#if defined( FBL_ENABLE_APPL_TASK ) ||\
    defined( FBL_ENABLE_APPL_STATE_TASK )
#if defined( FBL_ENABLE_APPL_TASK ) ||\
    defined( FBL_ENABLE_APPL_STATE_TASK )
void ApplFblStateTask( void );
#endif /* FBL_ENABLE_APPL_TASK || FBL_ENABLE_APPL_STATE_TASK */
#endif /* FBL_ENABLE_APPL_TASK || FBL_ENABLE_APPL_STATE_TASK */

void ApplFblCanBusOff( void );


#if defined( FBL_ENABLE_SLEEPMODE )
void ApplFblBusSleep( void );
#endif /* FBL_ENABLE_SLEEPMODE */


/* Additional functions depending on hardware platform requirements */

/* Callout functions for shutdown status handling */
void ApplFblSetShutdownStatus(tFblShutdownStatus status);
tFblShutdownStatus ApplFblGetShutdownStatus(void);
void ApplFblClrShutdownStatus(void);

#if defined( FBL_ENABLE_ASSERTION )
void ApplFblFatalError( FBL_DECL_ASSERT_EXTENDED_INFO(vuint8 errorCode) );
#endif
#endif /* FBL_AP_H */

void ApplFblNANDMemInit(void);

/***********************************************************************************************************************
 *  END OF FILE: FBL_AP.H
 **********************************************************************************************************************/
