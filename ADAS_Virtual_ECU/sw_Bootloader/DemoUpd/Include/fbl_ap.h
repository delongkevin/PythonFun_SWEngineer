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


/* Application software information */
#define kApplInfoSizeLogBlockHash                  20u
#define kApplInfoSizeLogHashPadding                12u
#define kApplInfoSizeSwEbomPartNumber              11u
#define kApplInfoSizeEbomEcuPartNumber             10u
#define kApplInfoSizeCodepEcuPartNumber            11u
#define kApplInfoSizeVehicleManEcuSwNumber         11u
#define kApplInfoSizeExhaustRegulationTan           6u
#define kApplInfoSizeSoftwareIdentification        13u
#define kApplInfoSizeAlignment                      2u
#define kApplInfoSizeCertState                      sizeof(vuint32)
#define kApplInfoSizeCertSourceAddr                 sizeof(vuint32)
#define kApplInfoSizeCertLength                     sizeof(vuint32)

#define kApplInfoSizeSwCompatibility                2u
#define kApplInfoSizeHwCompatibilityCount           1u
#define kApplInfoSizeHwCompatibility                2u
#define kApplInfoNumberHwCompatibilityEntries       3u

/* Offsets to start address of structure */
#define kApplInfoOffsetLogBlockHash                0u
#define kApplInfoOffsetLogHashPadding              (kApplInfoOffsetLogBlockHash           + kApplInfoSizeLogBlockHash           )
#define kApplInfoOffsetSwEbomPartNumber            (kApplInfoOffsetLogHashPadding         + kApplInfoSizeLogHashPadding         )
#define kApplInfoOffsetEbomEcuPartNumber           (kApplInfoOffsetSwEbomPartNumber       + kApplInfoSizeSwEbomPartNumber       )
#define kApplInfoOffsetCodepEcuPartNumber          (kApplInfoOffsetEbomEcuPartNumber      + kApplInfoSizeEbomEcuPartNumber      )
#define kApplInfoOffsetVehicleManEcuSwNumber       (kApplInfoOffsetCodepEcuPartNumber     + kApplInfoSizeCodepEcuPartNumber     )
#define kApplInfoOffsetExhaustRegulationTan        (kApplInfoOffsetVehicleManEcuSwNumber  + kApplInfoSizeVehicleManEcuSwNumber  )
#define kApplInfoOffsetSoftwareIdentification      (kApplInfoOffsetExhaustRegulationTan   + kApplInfoSizeExhaustRegulationTan   )
#define kApplInfoOffsetAlignment                   (kApplInfoOffsetSoftwareIdentification + kApplInfoSizeSoftwareIdentification )
#define kApplInfoOffsetCertState                   (kApplInfoOffsetAlignment              + kApplInfoSizeAlignment              )
#define kApplInfoOffsetCertSourceAddr              (kApplInfoOffsetCertState              + kApplInfoSizeCertState              )
#define kApplInfoOffsetCertLength                  (kApplInfoOffsetCertSourceAddr         + kApplInfoSizeCertSourceAddr         )

#define kApplInfoOffsetSwCompatibility             (kApplInfoOffsetCertLength             + kApplInfoSizeCertLength             )
#define kApplInfoOffsetHwCompatibilityCounter      (kApplInfoOffsetSwCompatibility        + kApplInfoSizeSwCompatibility        )
#define kApplInfoOffsetHwCompatibilityField        (kApplInfoOffsetHwCompatibilityCounter + kApplInfoSizeHwCompatibilityCounter )

/** Status information about certificates in logical block */
#define kApplInfoCertificateNone                    0u
#define kApplInfoCertificatePresent                 1u

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/** Status information to detect abnormal shutdown */
typedef enum
{
   kFblShutdownStatusNormal = 0u,
   kFblShutdownStatusAbnormal
}tFblShutdownStatus;

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

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

void ApplFblInit( void );
void ApplFblStartup( vuint8 initposition );
tFblResult ApplFblCheckProgConditions( void );
//tFblResult ApplFblCheckConditions( vuint8 * pbDiagData, tTpDataType diagReqDataLen );
vuint8 ApplFblCheckHwSwCompatibility(vuint8 blockIdx);
vuint8 ApplFblCheckSwSwCompatibility(void);
vuint8 ApplFblCheckProgDependencies( void );
// #if ( SEC_SECURITY_CLASS == SEC_CLASS_VENDOR )
// vuint8 ApplFblVerifyFcaHeader(vuint8 blockNr, V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * segmentList);
// #endif /* SEC_SECURITY_CLASS == SEC_CLASS_VENDOR */
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

/***********************************************************************************************************************
 *  END OF FILE: FBL_AP.H
 **********************************************************************************************************************/
