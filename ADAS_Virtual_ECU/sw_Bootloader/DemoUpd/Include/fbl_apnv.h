/* Kernbauer Version: 1.12 Konfiguration: FBL Erzeugungsgangnummer: 1 */

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application dependent nonvolatile memory access routines
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
 *  01.00.01   2018-10-05  visqps  ESCAN00100943    No changes
 *  01.01.00   2018-11-06  viscb   ESCAN00101235    Support for security class Vendor
 *  01.02.00   2019-01-29  viscb   ESCAN00101939    Store boot software fingerprint
 *  01.02.01   2019-07-19  vistbe  ESCAN00102567    No changes
 *  02.00.00   2020-03-26  vistbe  FBL-1510         Upgrade to latest reference implementation
 *  02.01.00   2020-07-13  visrie  FBL-2021         Added support for OTA
 *  02.01.01   2020-08-04  visjdn  ESCAN00106902    No changes
 *  02.02.00   2020-09-17  visrie  FBL-2139         No changes
 *  02.03.00   2020-10-11  vistbe  FBL-2419         No changes
 *                                 ESCAN00107820    No changes
 *                                 ESCAN00107932    No changes
 *                                 ESCAN00107933    No changes
 *  02.04.00   2020-12-17  vistbe  FBL-1352         No changes
 *  02.04.01   2021-01-07  visjdn  ESCAN00107451    Undefined API ApplFblAdjustLbtBlockData
 *  02.05.00   2021-11-08  vistbe  FBL-3863         No changes
 *  02.05.01   2022-02-16  visrie  ESCAN00108220    No changes
 *                                 ESCAN00108922    No changes
 *                                 ESCAN00109142    No changes
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

#ifndef FBL_APNV_H
#define FBL_APNV_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblKbApi_FrameNv_Fca CQComponent : Implementation */
#define FBLKBAPI_FRAMENV_FCA_VERSION             0x0205u
#define FBLKBAPI_FRAMENV_FCA_RELEASE_VERSION     0x01u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Programming Status
 **********************************************************************************************************************/

/* Byte 0 Programming Status Mode, Application, Data */
#define kDiagProgStatMode                       1u
#define kDiagProgStatAppl                       2u
#define kDiagProgStatData                       4u
#define kDiagProgStatReserved                0xF8u

/* Byte1 Erase Verification */
#define kDiagProgStatEraseSucceeded             0u
#define kDiagProgStatEraseFailed_General        1u
#define kDiagProgStatEraseFailed_VoltageTooHigh 2u
#define kDiagProgStatEraseFailed_VoltageTooLow  3u
#define kDiagProgStatEraseFailed_TempTooLow     4u
#define kDiagProgStatEraseFailed_TempTooHigh    5u

/* Indices of programming status bytes */
#define kDiagProgStat                           0u
#define kDiagProgStatEraseVer                   1u

/* Memory status information in NVM for flash erased detection */
#if !defined(kDiagMemStatErased)
# define kDiagMemStatErased                  0xC3u
#endif
#if !defined(kDiagMemStatProgrammed)
# define kDiagMemStatProgrammed              0x5Au
#endif

/* ValidityFlags */
#define kEepValidateBlock                 0x01u
#define kEepInvalidateBlock               0x02u
/* ApplValidity */
# define kEepApplConsistent               0xD1u
# define kEepApplInconsistent             0xFFu


/* Application update flag */
#define kEepApplUpdate                    kEepApplConsistent

/* SecAccessDelayFlags */
#define kEepSecAccessDelayActive          0xA7u
#define kEepSecAccessDelayInactive        0xFFu

/* Size of validation bitfield */
# if defined( kEepSizeValidityFlags )
# else
#  define kEepSizeValidityFlags           (kNrOfValidationBytes)
# endif

/* -- Flash access macros -- */
/* PRQA S 3453 8 */ /* MD_MSR_FctLikeMacro */
#define ApplFblReadPromSwVersion(descriptor, buffer) \
   FblReadProm((descriptor).blockStartAddress, (buffer), kApplInfoSizeSwVersion)
#define ApplFblReadPromSwPartNumber(descriptor, buffer) \
   FblReadProm((descriptor).blockStartAddress+kApplInfoOffsetSwPartNumber, (buffer), kApplInfoSizeSwPartNumber)
#define ApplFblReadPromSwSupplierInformation(descriptor, buffer) \
   FblReadProm((descriptor).blockStartAddress+kApplInfoOffsetSwSupplierInformation, (buffer), kApplInfoSizeSwSupplierInformation)

# if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
/* Security access delay flag macros */
#  define ApplFblGetSecAccessDelayFlag() \
   (ApplFblRWSecurityAccessDelayFlag(kEepReadData, 0u) != kEepSecAccessDelayInactive)
#  define ApplFblSetSecAccessDelayFlag() \
   (void)ApplFblRWSecurityAccessDelayFlag(kEepWriteData, kEepSecAccessDelayActive)
#   define ApplFblClrSecAccessDelayFlag() \
   (void)ApplFblRWSecurityAccessDelayFlag(kEepWriteData, kEepSecAccessDelayInactive)
# endif /* FBL_ENABLE_SEC_ACCESS_DELAY */

/* Reset response flag access macros */  /* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
#define ApplFblReadResetResponseFlag(buffer)       ApplFblNvReadResetResponseFlag(buffer)
#define ApplFblWriteResetResponseFlag(buffer)      ApplFblNvWriteResetResponseFlag(buffer)

/* Memory status access macros */
/* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
#define ApplFblReadMemoryStatus(blockNr, buffer)   ApplFblNvReadMemoryStatus((IO_PositionType)(blockNr), (buffer))
#define ApplFblWriteMemoryStatus(blockNr, buffer)  ApplFblNvWriteMemoryStatus((IO_PositionType)(blockNr), (buffer))

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
/* PRQA S 3453 6 */ /* MD_MSR_FctLikeMacro */
# define ApplFblChkModulePresence(bd)        FblNvPatternGet((bd), kFblNvPatternId_BlockValidity)
# define ApplFblSetModulePresence(bd)        FblNvPatternSet((bd), kFblNvPatternId_BlockValidity)
# define ApplFblClrModulePresence(bd)        FblNvPatternClr((bd), kFblNvPatternId_BlockValidity)
# define ApplFblChkApplPresence(bd)          FblNvPatternGet((bd), kFblNvPatternId_ApplValidity)
# define ApplFblSetApplPresence(bd)          FblNvPatternSet((bd), kFblNvPatternId_ApplValidity)
# define ApplFblClrApplPresence(bd)          FblNvPatternClr((bd), kFblNvPatternId_ApplValidity)
#endif /* FBL_ENABLE_PRESENCE_PATTERN */


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

tFblAddress ApplFblGetModuleHeaderAddress( vuint8 blockNr );

#if defined( FBL_CW_ENABLE_MULTIPLE_CONNECTIONS )
tFblResult ApplFblWriteDcmDslRxTesterSourceAddr(vuint8* buffer);
tFblResult ApplFblReadDcmDslRxTesterSourceAddr(vuint8* buffer);
#endif /* FBL_CW_ENABLE_MULTIPLE_CONNECTIONS */

tFblProgStatus ApplFblExtProgRequest( void );
tApplStatus ApplFblGetApplStatus( void );
tApplStatus ApplFblIsValidApp( void );
tFblResult ApplFblValidateBlock( tBlockDescriptor blockDescriptor );
tFblResult ApplFblInvalidateBlock( tBlockDescriptor blockDescriptor );
tFblResult ApplFblIsValidBlock( vuint8 blockNr );
tFblResult ApplFblStoreFingerprint( vuint8 * buffer );
tFblResult ApplFblStoreBootFingerprint( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor, const vuint8 * buffer );
tFblResult ApplFblIncProgCounts( tBlockDescriptor blockDescriptor );
tFblResult ApplFblGetProgCounts( tBlockDescriptor blockDescriptor, V_MEMRAM1 vuint16 V_MEMRAM2 V_MEMRAM3 * progCounts);
tFblResult ApplFblIncProgAttempts( tBlockDescriptor blockDescriptor );
tFblResult ApplFblGetProgAttempts( tBlockDescriptor blockDescriptor, V_MEMRAM1 vuint16 V_MEMRAM2 V_MEMRAM3 * progAttempts );
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
vuint8 ApplFblRWSecurityAccessDelayFlag( vuint8 mode, vuint8 value );
#endif
# if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
tFblResult ApplFblWriteSecAccessInvalidCount( V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * invalidCount );
tFblResult ApplFblReadSecAccessInvalidCount( V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * invalidCount );
# endif
void ApplFblErrorNotification( tFblErrorType errorType, tFblErrorCode errorCode );
tFblResult ApplFblAdjustLbtBlockData(tBlockDescriptor * blockDescriptor);
#if defined( SEC_ENABLE_CRC_TOTAL )
tFblResult ApplFblWriteCRCTotal( V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor, vuint32 crcStart, vuint32 crcLength, vuint32 crcValue );
#endif /* SEC_ENABLE_CRC_TOTAL */

tFblResult ApplFblValidateApp( void );
tFblResult ApplFblInvalidateApp( void );

tFblResult ApplFblGetBlockHash( vuint8 blockNr, vuint8 *targetBuffer );
tFblResult ApplFblProgStatusUpdate(vuint8 progStatSet, vuint8 progStatClr);
tFblResult ApplFblProgStatusEraseUpdate( vuint8 eraseVer );
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
tFlashStatus ApplFblGetBlockErased( tBlockDescriptor blockDescriptor );
#endif /* FBL_ENABLE_FLASH_ERASED_DETECTION */
// tFblResult ApplFblWriteSegmentList( vuint8 blockNr, V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * segmentList );
// tFblResult ApplFblReadSegmentList( vuint8 blockNr, V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * segmentList );
vuint32 ApplFblGetNvModuleId(tFblLbtBlockNr blockNr);
#if (SEC_SECURITY_CLASS == SEC_CLASS_VENDOR)
tFblResult ApplFblHandleCertUpdate(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor);
#endif /* SEC_SECURITY_CLASS == SEC_CLASS_VENDOR */

#endif /* FBL_APNV_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_APNV.H
 **********************************************************************************************************************/
