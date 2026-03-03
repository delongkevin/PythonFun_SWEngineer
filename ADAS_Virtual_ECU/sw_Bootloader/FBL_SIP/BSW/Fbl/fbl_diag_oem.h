/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Diagnostic module external interface - OEM specific extension
 *                 Declaration of functions, variables, and constants
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
 *  02.00.00   2020-03-25  vistbe  FBL-1510         Upgrade to latest reference implementation
 *                                 ESCAN00105933    No changes
 *                                 ESCAN00105934    No changes
 *                                 ESCAN00105730    No changes
 *                                 ESCAN00105864    Incorrect minimum length definition for several services
 *  02.00.01   2020-05-26  visjdn  ESCAN00105865    No changes
 *  02.01.00   2020-06-16  vistbe  FBL-1919         No changes
 *  02.02.00   2020-07-13  visrie  FBL-2021         Added support for OTA
 *                                 ESCAN00106775    No changes
 *  02.02.01   2020-11-02  visrcn  ESCAN00105639    FblDiagDownloadCheck does not allow reporting of correct
 *                                                  Check Verification Result
 *  02.03.00   2020-12-17  vistbe  FBL-1352         Add support for Authenticated Diagnostics
 *  02.04.00   2021-04-14  vistmo  FBL-2961         Added/adapted MemMap sections
 *  02.04.01   2021-08-18  vistbe  ESCAN00109813    No changes
 *  02.05.00   2021-08-24  vishor  FBL-3800         Support Sub-Functions of FOTA Rollback Routine D006
 *  02.05.01   2021-11-09  visrie  ESCAN00110248    No changes
 *  02.06.00   2022-01-20  vistmo  FBL-4156         Update to specification CS.00099 - Rev D (2020-12-14)
 *  02.06.01   2022-02-16  visrie  ESCAN00110576    No changes
 *                                 ESCAN00110609    No changes
 *  02.07.00   2022-06-14  visrie  ESCAN00111989    Support CSR Request - 0xD00A
 *  02.07.01   2022-07-27  vismix  ESCAN00109293    No changes
 *  02.07.02   2022-10-14  visjns  ESCAN00112112    FBL does not respond to services during download
 *  02.07.03   2022-11-16  vismix  ESCAN00112841    No changes
 *                                 ESCAN00112884    No changes
 *  02.07.04   2022-11-21  vismix  ESCAN00112934    No changes
 *  02.08.00   2022-12-02  visjdn  FBL-6117         Remove backup creation
 *                                 ESCAN00110368    No changes
 *                                 ESCAN00112786    No changes
 *                                 ESCAN00113224    No changes
 **********************************************************************************************************************/

#ifndef FBL_DIAG_OEM_H
#define FBL_DIAG_OEM_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : FblDiag_14229_Fca CQComponent : Implementation */
#define FBLDIAG_14229_FCA_VERSION            0x0208u
#define FBLDIAG_14229_FCA_RELEASE_VERSION    0x00u

#define FBL_VERSION                          _VECTOR_SIP_VERSION
#define FBL_RELEASE_VERSION                  _VECTOR_SIP_RELEASE_VERSION

/* Reference interface version */
/** Major interface version identifies incompatible changes */
#define FBL_DIAGCORE_API_REFERENCE_VERSION_MAJOR     0x04u
/** Minor interface version identifies backward compatible changes */
#define FBL_DIAGCORE_API_REFERENCE_VERSION_MINOR     0x03u
/** Release interface version identifies cosmetic changes */
#define FBL_DIAGCORE_API_REFERENCE_VERSION_RELEASE   0x00u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Special values for indices into logical block table */
#define kBlockNrInvalid                0xFFu

/***********************************************************************************************************************
 *  Diagnostic configuration switches
 **********************************************************************************************************************/


/* Select set of features from diagnostic core */
#define FBL_DIAG_ENABLE_14229_2013
#define FBL_DIAG_ENABLE_OEM_INITPOWERON
#define FBL_DIAG_ENABLE_CORE_PREWRITE
#define FBL_DIAG_ENABLE_CORE_POSTWRITE
#define FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING
#define FBL_DIAG_ENABLE_CORE_STAYINBOOT
#define FBL_DIAG_ENABLE_CORE_WRITE_SECACCESSDELAY_FLAG
#define FBL_DIAG_DISABLE_SPS_EXTENDED_SESSION

#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
# define FBL_DIAG_DISABLE_CORE_READ_SECACCESSDELAY_FLAG
#else
# define FBL_DIAG_ENABLE_CORE_READ_SECACCESSDELAY_FLAG
#endif
#define FBL_DIAG_DISABLE_CORE_OTA


#define FBL_DIAG_ENABLE_SERVICE_PREHANDLER
#define FBL_DIAG_ENABLE_SERVICE_POSTHANDLER

#define FBL_DIAG_ENABLE_OEM_POSTINIT
#define FBL_DIAG_ENABLE_OEM_TIMERTASK

/***********************************************************************************************************************
 *  State handling
 **********************************************************************************************************************/

/* Download sequence */
#define kFblDiagStateSecurityKeyAllowed         ( kFblDiagLastCoreStateIdx + 1u )
#define kFblDiagStateSecurityUnlock             ( kFblDiagLastCoreStateIdx + 2u )
#define kFblDiagStateLogBlockHashRequested      ( kFblDiagLastCoreStateIdx + 3u )
#define kFblDiagStateFingerprintValid           ( kFblDiagLastCoreStateIdx + 4u )
#define kFblDiagStateEraseSucceeded             ( kFblDiagLastCoreStateIdx + 5u )
#define kFblDiagStateTransferDataAllowed        ( kFblDiagLastCoreStateIdx + 6u )
#define kFblDiagStateTransferDataSucceeded      ( kFblDiagLastCoreStateIdx + 7u )
#define kFblDiagStateChecksumAllowed            ( kFblDiagLastCoreStateIdx + 8u )
#define kFblDiagStateFlashDriverPresent         ( kFblDiagLastCoreStateIdx + 9u )
#define kFblDiagStateIdxBootTimeoutActive       ( kFblDiagLastCoreStateIdx + 10u)
#define kFblDiagStateDownloadRequest            ( kFblDiagLastCoreStateIdx + 11u)
#define kFblDiagStateUploadRequest              ( kFblDiagLastCoreStateIdx + 12u)
#define kFblDiagStateRollbackFromFbl            ( kFblDiagLastCoreStateIdx + 13u)
#if defined( FBL_DIAG_ENABLE_BACKUP_CREATION )
# define kFblDiagStateBackupCreated             ( kFblDiagLastCoreStateIdx + 14u)

# define kFblDiagLastOemStateIdx                kFblDiagStateBackupCreated
#else
# define kFblDiagLastOemStateIdx                kFblDiagStateRollbackFromFbl
#endif /* FBL_DIAG_ENABLE_BACKUP_CREATION */

/* Download sequence states */
#define FblDiagGetSecurityKeyAllowed()          GetFblDiagState( kFblDiagStateSecurityKeyAllowed )
#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
/* Special handling for authenticated diagnostics */
#define FblDiagGetSecurityUnlock()              (ApplFblGetAuthenticationState() == kFblAuthenticated)
#else
#define FblDiagGetSecurityUnlock()              GetFblDiagState( kFblDiagStateSecurityUnlock )
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */
#define FblDiagGetLogBlockHashRequested()       GetFblDiagState( kFblDiagStateLogBlockHashRequested )
#define FblDiagGetFingerprintValid()            GetFblDiagState( kFblDiagStateFingerprintValid )
#define FblDiagGetEraseSucceeded()              GetFblDiagState( kFblDiagStateEraseSucceeded )
#define FblDiagGetTransferDataAllowed()         GetFblDiagState( kFblDiagStateTransferDataAllowed )
#define FblDiagGetTransferDataSucceeded()       GetFblDiagState( kFblDiagStateTransferDataSucceeded )
#define FblDiagGetChecksumAllowed()             GetFblDiagState( kFblDiagStateChecksumAllowed )
#define FblDiagGetFlashDriverPresent()          GetFblDiagState( kFblDiagStateFlashDriverPresent )
#define FblDiagGetBootTimeoutActive()           GetFblDiagState( kFblDiagStateIdxBootTimeoutActive )
#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
# define FblDiagGetDownloadRequest()            GetFblDiagState( kFblDiagStateDownloadRequest )
# define FblDiagGetUploadRequest()              GetFblDiagState( kFblDiagStateUploadRequest )
#endif

/* Data length definitions */
#define kDiagSizeLogicalBlockHash               20u

/***********************************************************************************************************************
 *  Service handling
 **********************************************************************************************************************/

#if !defined( kDiagSidRequestUpload )
# define kDiagSidRequestUpload                           0x35u    /**< Service ID - Request Upload */
#endif

#define kFblDiagResponseResetPostHandler           FblDiagDefaultPostHandler
#define kFblDiagResponseSdsPostHandler             FblDiagDefaultPostHandler

/* ControlDTCSetting */
#define kDiagSubDtcOn                                    0x01u    /**< Subservice ID - DTC on */
#define kDiagSubDtcOff                                   0x02u    /**< Subservice ID - DTC off */

/* Security access */
/* Subservice IDs and lengths of security access can be overwritten
 * - e.g. by a user configuration file. */
#if !defined( kFblDiagSubRequestSeed )
# define kFblDiagSubRequestSeed                          0x01u    /**< Subservice ID - Request seed */
#endif
#if !defined( kFblDiagSubSendKey )
# define kFblDiagSubSendKey                              0x02u    /**< Subservice ID - Send key */
#endif

#if !defined( kFblDiagSubRequestChallenge )
# define kFblDiagSubRequestChallenge                     0x11u    /**< Subservice ID - Request challenge */
#endif
#if !defined( kFblDiagSubSendSignedChallenge )
# define kFblDiagSubSendSignedChallenge                  0x12u    /**< Subservice ID - Send signed challenge */
#endif

#if !defined( kFblDiagSecurityAccessSessionMask )
# if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
#  define kFblDiagSecurityAccessSessionMask               (kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming)
# else
#  define kFblDiagSecurityAccessSessionMask               kFblDiagOptionSessionProgramming
# endif /* FBL_DIAG_ENABLE_SECACCESS_* */
#endif /* !defined( kFblDiagSecurityAccessSessionMask ) */

#define kSecSeedLength                                   SEC_SEED_LENGTH   /**< Length of seed provided by ECU */
#define kSecKeyLength                                    SEC_KEY_LENGTH    /**< Length of key provided by ECU */
#define kSecMaxInvalidKeys                               2u                /**< Maximum number of invalid keys for starting security access timer */

#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
# define kSecAuthPrgCertLength                            1536u             /**< Length of certificate sent to ECU */
# define kSecAuthPrgChallengeLength                       32u               /**< Length of challenge provided by the ECU */
# define kSecAuthPrgNonceLength                           32u               /**< Length of Nonce sent to the ECU */
# define kSecAuthPrgSignatureLength                       256u              /**< Length of signature sent to the ECU */
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */

/* OEM specific RoutineControl, RoutineIdentifier */
#define kDiagRoutineIdBootLogicalBlockHash               0xD000u
#define kDiagRoutineIdBootLogicalBlockHashHigh           GET_ID_HIGH(kDiagRoutineIdBootLogicalBlockHash)
#define kDiagRoutineIdBootLogicalBlockHashLow            GET_ID_LOW(kDiagRoutineIdBootLogicalBlockHash)

#define kDiagRoutineIdApplSwLogicalBlockHash             0xD003u
#define kDiagRoutineIdApplSwLogicalBlockHashHigh         GET_ID_HIGH(kDiagRoutineIdApplSwLogicalBlockHash)
#define kDiagRoutineIdApplSwLogicalBlockHashLow          GET_ID_LOW(kDiagRoutineIdApplSwLogicalBlockHash)

#define kDiagRoutineIdApplDataLogicalBlockHash           0xD004u
#define kDiagRoutineIdApplDataLogicalBlockHashHigh       GET_ID_HIGH(kDiagRoutineIdApplDataLogicalBlockHash)
#define kDiagRoutineIdApplDataLogicalBlockHashLow        GET_ID_LOW(kDiagRoutineIdApplDataLogicalBlockHash)

#define kDiagRoutineIdCheckProgPreCond                   0xD002u
#define kDiagRoutineIdCheckProgPreCondHigh               GET_ID_HIGH(kDiagRoutineIdCheckProgPreCond)
#define kDiagRoutineIdCheckProgPreCondLow                GET_ID_LOW(kDiagRoutineIdCheckProgPreCond)

#define kDiagRoutineIdSwRollback                         0xD006u
#define kDiagRoutineIdSwRollbackHigh                     GET_ID_HIGH(kDiagRoutineIdSwRollback)
#define kDiagRoutineIdSwRollbackLow                      GET_ID_LOW(kDiagRoutineIdSwRollback)

#define kDiagRoutineIdCSRTrigger                         0xD00Au
#define kDiagRoutineIdCSRTriggerHigh                     GET_ID_HIGH(kDiagRoutineIdCSRTrigger)
#define kDiagRoutineIdCSRTriggerLow                      GET_ID_LOW(kDiagRoutineIdCSRTrigger)

#define kDiagRoutineIdCheckProgram                       0xF000u
#define kDiagRoutineIdCheckProgramHigh                   GET_ID_HIGH(kDiagRoutineIdCheckProgram)
#define kDiagRoutineIdCheckProgramLow                    GET_ID_LOW(kDiagRoutineIdCheckProgram)

#define kDiagRoutineIdEraseMemory                        0xFF00u
#define kDiagRoutineIdEraseMemoryHigh                    GET_ID_HIGH(kDiagRoutineIdEraseMemory)
#define kDiagRoutineIdEraseMemoryLow                     GET_ID_LOW(kDiagRoutineIdEraseMemory)

#define kDiagRoutineIdCheckProgDep                       0xFF01u
#define kDiagRoutineIdCheckProgDepHigh                   GET_ID_HIGH(kDiagRoutineIdCheckProgDep)
#define kDiagRoutineIdCheckProgDepLow                    GET_ID_LOW(kDiagRoutineIdCheckProgDep)

/* RoutineControl response codes */
#define kDiagCheckVerificationOk                         0x00u    /**< Routine Control - Check Memory routine finished successfully */
#define kDiagCheckVerificationGeneralFailure             0x01u    /**< Routine Control - Check Memory routine general failure */
#define kDiagCheckVerificationCRCFailed                  0x02u    /**< Routine Control - Check Memory routine CRC failed */
#define kDiagCheckVerificationSignatureFailed            0x04u    /**< Routine Control - Check Memory routine Signature failed */
#define kDiagCheckVerificationRWMemoryFailure            0x80u    /**< Routine Control - Check Memory routine R/W memory failure */
#define kDiagEraseMemoryOk                               0x00u    /**< Routine Control - Erase Memory routine finished successfully */
#define kDiagEraseMemoryFailed                           0x01u    /**< Routine Control - Erase Memory routine failed */
#define kDiagCheckCompatibilityOk                        0x00u    /**< Routine Control - Check Programming Dependencies OK */
#define kDiagCheckCompatibilityFailed                    0x01u    /**< Routine Control - Check Programming Dependencies Failed */
#define kDiagCheckCompatibilitySwHw                      0x02u    /**< Routine Control - Check Programming Dependencies HW/SW incompatible */
#define kDiagCheckCompatibilitySwSw                      0x03u    /**< Routine Control - Check Programming Dependencies SW/SW incompatible */
#define kDiagCheckCompatibilityBlockMissing              0x04u    /**< Routine Control - Check Programming Dependencies Mandatory Block Missing */

#define kDiagRollbackRoutineSuccessful                   0x00u
#define kDiagRollbackRoutineUnsuccessful                 0x01u
#define kDiagRollbackRoutineInProgress                   0x03u
#define kDiagRollbackRoutineNotStarted                   0x04u
#define kDiagRollbackRoutineRequested                    0x05u

/* Defines for additional length codes for optional request parameters */
#if (SEC_SECURITY_CLASS == SEC_CLASS_DDD)
# define kSecCRCLength                                   SEC_VERIFY_CLASS_DDD_VERIFY_SIZE
# define kSecSigLength                                   0u
/* Two bytes CRC length */
# define kSecLengthInfo                                  2u
#endif /* SEC_SECURITY_CLASS == SEC_CLASS_DDD */
#if (SEC_SECURITY_CLASS == SEC_CLASS_CCC)
# if !defined( kSecCRCLength )
#  define kSecCRCLength                                  0u
# endif
# if !defined( kSecSigLength )
#  define kSecSigLength                                  128u
# endif
# if !defined( kSecLengthInfo )
/* Two bytes signature length */
#  define kSecLengthInfo                                 2u
# endif
#endif /* SEC_SECURITY_CLASS == SEC_CLASS_CCC */
#if (SEC_SECURITY_CLASS == SEC_CLASS_VENDOR)
# if !defined( kSecCRCLength )
#  define kSecCRCLength                                  0u
# endif
# if !defined( kSecSigLength )
#  define kSecSigLength                                  0u
# endif
# if !defined( kSecLengthInfo )
#  define kSecLengthInfo                                 0u
# endif
#endif /* SEC_SECURITY_CLASS == SEC_CLASS_VENDOR */

/* Data identifier for WriteDataByIdentifier service */
#define kFblDiagDidBootSwFingerprintWrite                0xF183u
#define kFblDiagDidApplSwFingerprintWrite                0xF184u
#define kFblDiagDidApplDataFingerprintWrite              0xF185u

/* Special return code for ApplFblWriteDataByIdentifier */
#define kDiagReturnValidationOk                          0x5Cu
#define kDiagReturnValidationFailed                      (kFblFailed)

/* Request parameter lengths excluding the service ID */
#define kDiagRqlDiagnosticSessionControlParameter           0u
#define kDiagRqlSecurityAccessSeedParameter                 0u
#define kDiagRqlSecurityAccessKeyParameter                  kSecKeyLength

#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
# define kDiagRqlSecurityAccessReqChallengeParameter        kSecAuthPrgCertLength
# define kDiagRqlSecurityAccessSendSignedChallengeParameter (kSecAuthPrgNonceLength + kSecAuthPrgSignatureLength)
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */

#if !defined( kDiagRqlWriteDataByIdentifierFingerPrintParameter )
# define kDiagRqlWriteDataByIdentifierFingerPrintParameter  (1u + 3u + 10u)
#endif
#define kDiagRqlRoutineControlCheckRoutineParameter         (kSecLengthInfo + kSecCRCLength + kSecSigLength)
#define kDiagRqlRoutineControlAddrAndLenFormatIdParameter   1u
#if defined( FBL_DIAG_ENABLE_CONTROLDTC_OPTIONRECORD )
# define kDiagRqlControlDTCSettingParameter                 3u
#else
# define kDiagRqlControlDTCSettingParameter                 0u
#endif /* FBL_DIAG_ENABLE_CONTROLDTC_OPTIONRECORD */

/* Request lengths excluding the service ID */
#define kDiagRqlServiceWithSubfunction             1u
#define kDiagRqlDiagnosticSessionControl           (1u + kDiagRqlDiagnosticSessionControlParameter)
#define kDiagRqlEcuReset                           1u
#define kDiagRqlReadDtc                            1u
#define kDiagRqlReadDtcByStatusMask                2u
#define kDiagRqlReadDataByIdentifier               2u
#define kDiagRqlSecurityAccessSeed                 (1u + kDiagRqlSecurityAccessSeedParameter)
#define kDiagRqlSecurityAccessKey                  (1u + kDiagRqlSecurityAccessKeyParameter)

/* Minimum length definitions (full length is checked within main handler)*/
#define kDiagRqlSecurityAccessReqChallenge         1u
#define kDiagRqlSecurityAccessSendSignedChallenge  1u

#define kDiagRqlCommunicationControl               2u
#define kDiagRqlWriteDataByIdentifier              3u /* DID + at least 1 byte data */
#define kDiagRqlWriteDataByIdentifierFingerPrint   (kDiagRqlWriteDataByIdentifier -1u + kDiagRqlWriteDataByIdentifierFingerPrintParameter)
#define kDiagRqlRoutineControl                     3u
#define kDiagRqlRoutineControlLogicalBlockHash     kDiagRqlRoutineControl + 1u
#define kDiagRqlRoutineControlProgPreCond          kDiagRqlRoutineControl
#define kDiagRqlRoutineControlSwRollback           kDiagRqlRoutineControl
#define kDiagRqlRoutineControlCSRTrigger           kDiagRqlRoutineControl
#define kDiagRqlRoutineControlCheckProgram         (kDiagRqlRoutineControl + kDiagRqlRoutineControlCheckRoutineParameter)
#define kDiagRqlRoutineControlEraseRoutine         kDiagRqlRoutineControl

#define kDiagRqlRoutineControlCheckProgDep         kDiagRqlRoutineControl

#define kDiagRqlRequestDownload                    4u /* DFI + ALFI + at least 1 byte for address and length */
#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
# define kDiagRqlRequestUpload                     4u /* DFI + ALFI + at least 1 byte for address and length */
#endif
#define kDiagRqlTransferData                       1u
#define kDiagRqlRequestTransferExit                0u
#define kDiagRqlTesterPresent                      1u
#define kDiagRqlControlDTCSetting                  (1u + kDiagRqlControlDTCSettingParameter)
#define kDiagRqlClearDiagInfo                      3u

/* Response parameter lengths excluding the service ID */
#define kDiagRslEcuResetParameter                           0u
#define kDiagRslDiagnosticSessionControlParameter           4u
#define kDiagRslSecurityAccessSeedParameter                 kSecSeedLength
#define kDiagRslSecurityAccessKeyParameter                  0u

#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
# define kDiagRslSecurityAccessReqChallengeParameter        kSecAuthPrgChallengeLength /* 32 Byte Challenge */
# define kDiagRslSecurityAccessSendSignedChallengeParameter 0u
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */

#define kDiagRslRoutineControlEraseRoutineParameter         0u
#define kDiagRslRoutineControlCheckRoutineParameter         1u
#define kDiagRslRoutineControlCheckPreCondParameter         3u
#define kDiagRslRoutineControlCSRTriggerParameter           1u
#define kDiagRslTransferDataParameter                       0u
#define kDiagRslRequestTransferExitParameter                0u

/* Response lengths excluding the service ID */
#define kDiagRslDiagnosticSessionControl           (1u + kDiagRslDiagnosticSessionControlParameter)
#define kDiagRslEcuReset                           (1u + kDiagRslEcuResetParameter)
#define kDiagRslSecurityAccessSeed                 (1u + kDiagRslSecurityAccessSeedParameter)
#define kDiagRslSecurityAccessKey                  (1u + kDiagRslSecurityAccessKeyParameter)

#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
# define kDiagRslSecurityAccessReqChallenge         (1u + kDiagRslSecurityAccessReqChallengeParameter)
# define kDiagRslSecurityAccessSendSignedChallenge  (1u + kDiagRslSecurityAccessSendSignedChallengeParameter)
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */

#define kDiagRslCommunicationControl               1u
#define kDiagRslWriteDataByIdentifier              2u
#define kDiagRslRoutineControlEraseRoutine         (3u + kDiagRslRoutineControlEraseRoutineParameter)
#define kDiagRslRoutineControlCheckRoutine         (3u + kDiagRslRoutineControlCheckRoutineParameter)
#define kDiagRslRoutineControlCheckPreCond         (3u + kDiagRslRoutineControlCheckPreCondParameter)
#define kDiagRslRoutineControlSwRollback           3u
#define kDiagRslRoutineControlCSRTrigger           (3u + kDiagRslRoutineControlCSRTriggerParameter)
#define kDiagRslRequestDownload                    1u
#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
# define kDiagRslRequestUpload                     1u
#endif
#define kDiagRslTransferData                       (1u + kDiagRslTransferDataParameter)
#define kDiagRslRequestTransferExit                (0u + kDiagRslRequestTransferExitParameter)
#define kDiagRslTesterPresent                      1u
#define kDiagRslControlDTCSetting                  1u
#define kDiagRslClearDiagInfo                      0u

#if !defined( SECM_HASH_SIZE )
# define SECM_HASH_SIZE                            20u
#endif
#define kDiagRslRoutineControlCalcBlockHash        (3u + SECM_HASH_SIZE)

/* Diagnostic service format definitions */
#define kDiagFmtServiceId                    0u                               /**< Position of service id */
#define kDiagFmtpbDiagData                   1u                               /**< Access parameter to remove service ID */
#define kDiagFmtSubparam                     (kDiagFmtServiceId + 1u)         /**< Position of DID */
#define kDiagFmtDataIdSize                   2u                               /**< Size of data identifier  (2 bytes) */
#define kDiagFmtDataIdHigh                   (kDiagFmtServiceId + 1u)         /**< Position of data identifier (MSB) */
#define kDiagFmtDataIdLow                    (kDiagFmtDataIdHigh + 1u)        /**< Position of data identifier (LSB) */
#define kDiagFmtSubFctDataIdHigh             (kDiagFmtSubparam + 1u)          /**< Position of data identifier (MSB) */
#define kDiagFmtSubFctDataIdLow              (kDiagFmtSubFctDataIdHigh + 1u)  /**< Position of data identifier (LSB) */
#define kDiagFmtDataRecord                   (kDiagFmtDataIdLow + 1u)         /**< Position of record data identifier */
#define kDiagFmtSequenceCnt                  (kDiagFmtServiceId + 1u)         /**< Position of sequence counter */
#define kDiagFmtDataOffset                   (kDiagFmtSequenceCnt + 1u)       /**< Offset to download data in TransferData frame */
#define kDiagFmtFormatOffset                 2u
#define kDiagFmtNegResponse                  (kDiagFmtSubparam + 1u)          /**< Position of negative response code */
#define kDiagFmtAddrOffset                   3u
#define kDiagFmtRoutineIdHigh                (kDiagFmtSubparam + 1u)          /**< RoutineControl service formats */
#define kDiagFmtRoutineIdLow                 (kDiagFmtRoutineIdHigh + 1u)
#define kDiagFmtRoutineStatus                (kDiagFmtRoutineIdLow + 1u)
#define kDiagFmtRoutineAlfi                  (kDiagFmtRoutineIdLow + 1u)
#define kDiagFmtStartAddress                 (kDiagFmtRoutineAlfi + 1u)
#define kDiagFmtStopAddress                  (kDiagFmtStartAddress + 4u)
#define kDiagFmtChecksumHigh                 (kDiagFmtStopAddress + 4u)
#define kDiagFmtChecksumLow                  (kDiagFmtChecksumHigh + 1u)
#define kDiagFmtSeedKeyStart                 (kDiagFmtSubparam + 1u)          /**< Start index of seed/key value */

/* Diagnostic service index to diagnostic parameters.
 * This index shall only be used with the pointer to diag-buffer
 * that was passed to the function as a parameter.
 * NOTE:  You MUST NOT use the kDiagLocFmtXxx with the global DiagBuffer!!! */
#define kDiagLocFmtSubparam                              0u                                  /**< Position of DID */
#define kDiagLocFmtSubfunction                           0u                                  /**< Position of Subfunction */
#define kDiagLocFmtDataIdHigh                            0u                                  /**< Position of data identifier (MSB) */
#define kDiagLocFmtDataIdLow                             (kDiagLocFmtDataIdHigh + 1u)        /**< Position of data identifier (LSB) */
#define kDiagLocFmtSubFctDataIdHigh                      (kDiagLocFmtSubfunction + 1u)       /**< Position of data identifier (MSB) for a subfunction */
#define kDiagLocFmtSubFctDataIdLow                       (kDiagLocFmtSubFctDataIdHigh + 1u)  /**< Position of data identifier (LSB) for a subfunction */
#define kDiagLocFmtDataRecord                            (kDiagLocFmtDataIdLow + 1u)         /**< Position of record data identifier */
#define kDiagLocFmtSequenceCnt                           0u                                  /**< Position of sequence counter */
#define kDiagLocFmtDataOffset                            (kDiagLocFmtSequenceCnt + 1u)       /**< Offset to download data in TransferData frame */
#define kDiagLocFmtFormatOffset                          1u
#define kDiagLocFmtNegResponse                           (kDiagLocFmtSubparam + 1u)          /**< Position of negative response code */
#define kDiagLocFmtAddrOffset                            2u
#define kDiagLocFmtRoutineIdHigh                         (kDiagLocFmtSubparam + 1u)          /**< RoutineControl service formats */
#define kDiagLocFmtRoutineIdLow                          (kDiagLocFmtRoutineIdHigh + 1u)
#define kDiagLocFmtRoutineStatus                         (kDiagLocFmtRoutineIdLow + 1u)
#define kDiagLocFmtRoutineAlfi                           (kDiagLocFmtRoutineIdLow + 1u)
#define kDiagLocFmtStartAddress                          (kDiagLocFmtRoutineAlfi + 1u)
#define kDiagLocFmtStopAddress                           (kDiagLocFmtStartAddress + 4u)
#define kDiagLocFmtChecksumHigh                          (kDiagLocFmtStopAddress + 4u)
#define kDiagLocFmtChecksumLow                           (kDiagLocFmtChecksumHigh + 1u)
#define kDiagLocFmtSeedKeyStart                          (kDiagLocFmtSubparam + 1u)          /**< Start index of seed/key value */
#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
# define kDiagLocFmtReqChallengeCert                     (kDiagLocFmtSubfunction + 1u)
# define kDiagLocFmtReqChallengeChallenge                (kDiagLocFmtSubfunction + 1u)
# define kDiagLocFmtSendSignedChallengeNonce             (kDiagLocFmtSubfunction + 1u)
# define kDiagLocFmtSendSignedChallengeSignature         (kDiagLocFmtSendSignedChallengeNonce + kSecAuthPrgNonceLength)
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */

/* Index to local var. array in RoutineControl(CheckPrecondition) */
#define kDiagLocFmtNrOfPrecond                           ((vuint8) (kDiagLocFmtRoutineIdLow + 1u))
#define kDiagLocFmtStartPreCond                          ((vuint8) (kDiagLocFmtNrOfPrecond + 1u))

/* Parameters for OTA */
#define kDiagRqlStartFromOta                             kDiagRqlRoutineControlSwRollback
#define kFblDiagResponseOtaPostHandler                   FblDiagDefaultPostHandler

/***********************************************************************************************************************
 *  Error handling
 **********************************************************************************************************************/
#if defined( FBL_ENABLE_DEBUG_STATUS )
/* Error codes for detailed error status reporting */
# define FBL_ERR_NONE                        0x00u

# define FBL_ERR_FLASH_ERASE_ERROR           0x10u
# define FBL_ERR_FLASH_PROG_ERROR            0x11u
# define FBL_ERR_FLASH_PROG_CONDITIONS       0x12u

# define FBL_ERR_APPL_OVERLAPPING            0x20u
# define FBL_ERR_APPL_NOT_ALIGNED            0x21u
# define FBL_ERR_TOO_MANY_SEGMENTS_IN_MODULE 0x22u
# define FBL_ERR_NO_MEMORY_REGION_FOUND      0x23u
# define FBL_ERR_SEED_GENERATION_FAILED      0x24u
# define FBL_ERR_GAP_FILL                    0x25u
# define FBL_ERR_VERIFICATION                0x26u

# define FBL_ERR_FLASHCODE_INIT_FAILED       0x30u
# define FBL_ERR_FLASHCODE_EXCEEDS_MEMORY    0x31u
# define FBL_ERR_FLASHCODE_NOT_ACCEPTED      0x32u

# define FBL_ERR_LBT_MISSING_INVALID_FORMAT  0x40u
# define FBL_ERR_LBT_ADDR_MISMATCH           0x41u
# define FBL_ERR_LBT_BLOCK_INDEX_EXCEEDED    0x42u
# define FBL_ERR_LBT_NOT_REPROGRAMMABLE      0x43u
# define FBL_ERR_LBT_BLOCK_INDEX_ILLEGAL     0x44u

# define FBL_ERR_DATA_OVERFLOW               0x50u

/* Macros for error status reporting */
# define FblErrStatSetSId(id)                (errStatLastServiceId = (id))
# define FblErrStatSetState(state)           (errStatFblStates = (state))
# define FblErrStatSetFlashDrvError(error)   (errStatFlashDrvErrorCode = (error))
# define FblErrStatSetFlashDrvVersion()      \
{                                            \
   errStatFlashDrvVersion[0] = flashCode[0]; \
   errStatFlashDrvVersion[1] = flashCode[1]; \
   errStatFlashDrvVersion[2] = flashCode[3]; \
}
# define FblErrStatSetError(error)           (errStatErrorCode = (error))
# define FblErrStatSetBlockNr(blockNumber)   (errStatDescriptor.blockNr = (blockNumber))
# define FblErrStatSetAddress(address)       (errStatDescriptor.blockStartAddress = (address))
#else
# define FblErrStatSetSId(id)
# define FblErrStatSetState(state)
# define FblErrStatSetFlashDrvError(error)
# define FblErrStatSetFlashDrvVersion()
# define FblErrStatSetError(error)
# define FblErrStatSetBlockNr(blockNr)
# define FblErrStatSetAddress(address)
#endif

#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
/* OEM specific NRC values */
# define kDiagNrcRevokedKey                   0xFAu
# define kDiagNrcExpiredKey                   0xFBu

# define DiagNRCRevokedKey()                  FblDiagSetError(kDiagNrcRevokedKey)
# define DiagNRCExpiredKey()                  FblDiagSetError(kDiagNrcExpiredKey)
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */


/***********************************************************************************************************************
 *  Data processing
 **********************************************************************************************************************/

#define kDiagSubDefaultEncryption         0x01u
#define kDiagSubDefaultCompression        0x01u

/***********************************************************************************************************************
 *  LOGICAL BLOCK TYPES
 **********************************************************************************************************************/

#define kBlockTypeNone    0xFFu

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

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

vuint8 FblDiagGetLastErasedBlock(void);
void FblDiagSetLastErasedBlock(tFblLbtBlockNr blockNr);

#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBL_ENABLE_DEBUG_STATUS )
/* Variables for error status reporting */
V_MEMRAM0 extern V_MEMRAM1      vuint16            V_MEMRAM2      errStatErrorCode;
V_MEMRAM0 extern V_MEMRAM1      vuint16            V_MEMRAM2      errStatFblStates;
V_MEMRAM0 extern V_MEMRAM1      vuint8             V_MEMRAM2      errStatLastServiceId;
V_MEMRAM0 extern V_MEMRAM1      vuint8             V_MEMRAM2      errStatFlashDrvVersion[3];
V_MEMRAM0 extern V_MEMRAM1      vuint16            V_MEMRAM2      errStatFlashDrvErrorCode;
V_MEMRAM0 extern V_MEMRAM1      tBlockDescriptor   V_MEMRAM2      errStatDescriptor;
#endif


#define FBLDIAG_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

/* Check for unsupported configurations. These checks cannot be done in the generation tool. */

#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT ) && \
    defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
# error "Output verification and pipelined verification mustn't be combined."
#endif
#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT ) || \
    defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
#else
# error "At least one verification method must be activated."
#endif

/* Check for configured verification offsets */
#if( SEC_SECURITY_CLASS == SEC_CLASS_DDD )
# if( SEC_VER_CRC_OFFSET != 2u )
#  error "Invalid CRC offset. CRC offset needs to be set to 2 bytes"
# endif
#endif
#if( SEC_SECURITY_CLASS == SEC_CLASS_CCC )
# if( SEC_VER_SIG_OFFSET != 2u )
#  error "Invalid signature offset. Signature offset needs to be set to 2 bytes"
# endif
#endif
#if( SEC_SECURITY_CLASS == SEC_CLASS_C )
# error "Unsupported security class. The security classes DDD, CCC and Vendor are supported only."
#endif
#if defined( SEC_ENABLE_CRC_WRITTEN )
# error "Invalid sec mod configuration. CRC Written is not supported"
#endif

#endif /* FBL_DIAG_OEM_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_DIAG_OEM.H
 **********************************************************************************************************************/
