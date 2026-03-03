/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Diagnostic services supported in boot mode
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
 *                                 ESCAN00105933    TransferData Retransmission is not handled correctly
 *                                 ESCAN00105934    CommunicationControl -- Subfunction 01 not supported
 *                                 ESCAN00105730    Request upload is incorrectly accepted by functional request
 *                                 ESCAN00105864    Incorrect minimum length definition for several services
 *  02.00.01   2020-05-26  visjdn  ESCAN00105865    Corrected the sent NRC for a RequestTransferExit with invalid length
 *  02.01.00   2020-06-16  vistbe  FBL-1919         Retrieve block descriptor by means of (logical) block index
 *  02.02.00   2020-07-13  visrie  FBL-2021         Added support for OTA
 *                                 ESCAN00106775    Fixed missing NRC for RC-LogicalBlockHash
 *  02.02.01   2020-11-02  visrcn  ESCAN00105639    FblDiagDownloadCheck does not allow reporting of correct
 *                                                  Check Verification Result
 *  02.03.00   2020-12-17  vistbe  FBL-1352         Add support for Authenticated Diagnostics
 *  02.04.00   2021-04-14  vistmo  FBL-2961         Add support for Authenticated Diagnostics with vHSM
 *                                                  Added/adapted MemMap sections
 *  02.04.01   2021-08-18  vistbe  ESCAN00109813    FBL does not respond to EraseMemory and communication is locked
 *  02.05.00   2021-08-24  vishor  FBL-3800         Support Sub-Functions of FOTA Rollback Routine D006
 *  02.05.01   2021-11-09  visrie  ESCAN00110248    Wrong NRC sent by erase routine when FlashDriver is
 *                                                   missing/incorrect
 *  02.06.00   2022-01-20  vistmo  FBL-4156         Update to specification CS.00099 - Rev D (2020-12-14)
 *  02.06.01   2022-02-16  visrie  ESCAN00110576    Incorrect NRC general reject sent instead of subfunction not supported
 *                                 ESCAN00110609    Response timeout during routineControl - start SW rollback
 *  02.07.00   2022-06-14  visrie  ESCAN00111989    Support CSR Request - 0xD00A
 *  02.07.01   2022-07-27  vismix  ESCAN00109293    Flash driver download is not working
 *  02.07.02   2022-10-14  visjns  ESCAN00112112    No changes
 *  02.07.03   2022-11-16  vismix  ESCAN00112841    Security Access - Send Key is accepted after Security Access NRC
 *                                 ESCAN00112884    The security access delay timer is not started in all cases
 *  02.07.04   2022-11-21  vismix  ESCAN00112934    Delay Timer value is falsely reset
 *  02.08.00   2022-12-02  visjdn  FBL-6117         Remove backup creation
 *                                 ESCAN00110368    Compiler error: illegal else without matching if in API
 *                                                    FblDiagRequestDownloadLengthCheck
 *                                 ESCAN00112786    SecurityAccess delay timer is twice as large
 *                                 ESCAN00113224    WriteDataByIdentifier is only supported in programming session
 **********************************************************************************************************************/

#define FBL_DIAG_OEM_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Common Bootloader includes */
#include "fbl_inc.h"
/* Core Diagnostic interface and global symbols */
#include "fbl_diag_core.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* Diagnostic OEM module version check */
#if ((FBLDIAG_14229_FCA_VERSION != 0x0208u) || \
     (FBLDIAG_14229_FCA_RELEASE_VERSION != 0x00u))
# error "Error in fbl_diag_oem.c: Source and header file are inconsistent!"
#endif
#if(( FBLDIAG_14229_FCA_VERSION != _FBLDIAG_OEM_VERSION ) || \
    ( FBLDIAG_14229_FCA_RELEASE_VERSION != _FBLDIAG_OEM_RELEASE_VERSION ))
# error "Error in fbl_diag_oem.c: Source and v_ver.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  TYPE DEFINITIONS
 **********************************************************************************************************************/

#if defined( FBL_DIAG_ENABLE_FLASHDRV_ROM )
/** Structure to initialize flash drivers from ROM */
typedef struct
{
   V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3 * sourceBuffer;  /**< Flash driver image source buffer */
   V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * destBuffer;    /**< Flash driver destination buffer */
   vuint32 copySize;                                     /**< Size of data to be copied */
   vuint8 decryptValue;                                  /**< Value to decrypt XOR-encrypted driver */
} tFlashDriverInitData;
#endif /* FBL_DIAG_ENABLE_FLASHDRV_ROM */

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( FBL_DIAG_FLASH_CODE_BASE_ADDR )
/* Allow to override the flashCode base address for certain platforms.
 * Example: For word-addressed platforms the download address of the flash driver is going to be virtual, i.e. twice
 *          the physical address. For those platforms the base address can be overwritten in a user configuration file. */
#else
# define FBL_DIAG_FLASH_CODE_BASE_ADDR    ((tFblAddress)flashCode)
#endif

#if defined( FBL_ENABLE_UNALIGNED_DATA_TRANSFER )
   /* Report full diagnostic buffer size */
# define FBL_DIAG_RESPONSE_BUFFER_SIZE FBL_DIAG_BUFFER_LENGTH
#else
   /* Calculate buffer size so that a multiple of the diagnostic bufffer size + 2 is reported */
# define FBL_DIAG_RESPONSE_BUFFER_SIZE ((((FBL_DIAG_SEGMENT_SIZE - 1u) ^ 0xFFFFFFFFu) & (FBL_DIAG_BUFFER_LENGTH - 2u)) + 2u)
#endif /* FBL_ENABLE_UNALIGNED_DATA_TRANSFER */

#if( FBL_DIAG_RESPONSE_BUFFER_SIZE >= 0x1000000u )
# define FBL_DIAG_RESPONSE_BUFFER_LFI 4u
#elif( FBL_DIAG_RESPONSE_BUFFER_SIZE >= 0x10000u )
# define FBL_DIAG_RESPONSE_BUFFER_LFI 3u
#else
# define FBL_DIAG_RESPONSE_BUFFER_LFI 2u
#endif

#if !defined( FBL_DIAG_BOOT_TIMOUT_COUNTER )
# define FBL_DIAG_BOOT_TIMOUT_COUNTER     25u         /**< Bootloader application start timeout [ms], < 255ms */
#endif

#if defined( FBL_DIAG_ENABLE_SECACCESS_STANDARD )
# if !defined( FBL_DIAG_SEED_TIMEOUT_COUNTER )
#  define FBL_DIAG_SEED_TIMEOUT_COUNTER     20000u     /**< Seed start timeout [ms] */
# endif /* FBL_DIAG_SEED_TIMEOUT_COUNTER */
#endif /* FBL_DIAG_ENABLE_SECACCESS_STANDARD */

#if !defined( kFblDiagAddrFormat )
# define kFblDiagAddrFormat               4u
#endif
#if !defined( kFblDiagLengthFormat )
# define kFblDiagLengthFormat             4u
#endif

#define FBL_DIAG_UPLOAD_NOTRETRY          0u
#define FBL_DIAG_UPLOAD_RETRY             1u

#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
/* Formula: Delay timer = 2 ^ n seconds (* 1000 as we need this value in milliseconds) */
# define FBL_SEC_DELAY_TIMEOUT(invalidCount) ((((vuint32)1u << (invalidCount)) * 1000u) / kDiagCallCycle)
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */

/***********************************************************************************************************************
 *  State handling
 **********************************************************************************************************************/
/* Download sequence states */
#define FblDiagSetSecurityKeyAllowed()    SetFblDiagState( kFblDiagStateSecurityKeyAllowed )
#define FblDiagClrSecurityKeyAllowed()    ClrFblDiagState( kFblDiagStateSecurityKeyAllowed )
#define FblDiagSetSecurityUnlock()        SetFblDiagState( kFblDiagStateSecurityUnlock )
#define FblDiagClrSecurityUnlock()        ClrFblDiagState( kFblDiagStateSecurityUnlock )
#define FblDiagSetLogBlockHashRequested() SetFblDiagState( kFblDiagStateLogBlockHashRequested )
#define FblDiagClrLogBlockHashRequested() ClrFblDiagState( kFblDiagStateLogBlockHashRequested )
#define FblDiagSetFingerprintValid()      SetFblDiagState( kFblDiagStateFingerprintValid )
#define FblDiagClrFingerprintValid()      ClrFblDiagState( kFblDiagStateFingerprintValid )
#define FblDiagSetEraseSucceeded()        SetFblDiagState( kFblDiagStateEraseSucceeded )
#define FblDiagClrEraseSucceeded()        ClrFblDiagState( kFblDiagStateEraseSucceeded )
#define FblDiagSetTransferDataAllowed()   SetFblDiagState( kFblDiagStateTransferDataAllowed )
#define FblDiagClrTransferDataAllowed()   ClrFblDiagState( kFblDiagStateTransferDataAllowed )
#define FblDiagSetTransferDataSucceeded() SetFblDiagState( kFblDiagStateTransferDataSucceeded )
#define FblDiagClrTransferDataSucceeded() ClrFblDiagState( kFblDiagStateTransferDataSucceeded )
#define FblDiagSetChecksumAllowed()       SetFblDiagState( kFblDiagStateChecksumAllowed )
#define FblDiagClrChecksumAllowed()       ClrFblDiagState( kFblDiagStateChecksumAllowed )
#define FblDiagSetFlashDriverPresent()    SetFblDiagState( kFblDiagStateFlashDriverPresent )
#define FblDiagClrFlashDriverPresent()    ClrFblDiagState( kFblDiagStateFlashDriverPresent )
#define FblDiagSetBootTimeoutActive()     SetFblDiagState( kFblDiagStateIdxBootTimeoutActive )
#define FblDiagClrBootTimeoutActive()     ClrFblDiagState( kFblDiagStateIdxBootTimeoutActive )
#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
# define FblDiagSetDownloadRequest()      SetFblDiagState( kFblDiagStateDownloadRequest )
# define FblDiagClrDownloadRequest()      ClrFblDiagState( kFblDiagStateDownloadRequest )
# define FblDiagSetUploadRequest()        SetFblDiagState( kFblDiagStateUploadRequest )
# define FblDiagClrUploadRequest()        ClrFblDiagState( kFblDiagStateUploadRequest )
#endif

/***********************************************************************************************************************
 *  Local constants
 **********************************************************************************************************************/
#define kDiagInitSequenceNum     ((vuint8) 0x01u)

#if defined( FBL_DIAG_ENABLE_FLASHDRV_ROM )
# if !defined( FLASH_DRIVER_INIT_DATA )
/** Initialization data for default flash driver. If additional drivers should be initialized, please overwrite macro. */
#  define FLASH_DRIVER_INIT_DATA {{flashDrvBlk0, flashCode, FLASHDRV_BLOCK0_LENGTH, FLASHDRV_DECRYPTVALUE}}
# endif
#endif /* FBL_DIAG_ENABLE_FLASHDRV_ROM */

#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED)
# if !defined( kDiagMaxFailedAttempts )
/* 21 is the maximum failed counter value for the result of the formula Delay Time = 2^n seconds
   to fit into a 32 bit variable (as milliseconds) */
#define kDiagMaxFailedAttempts 21u
# endif /* !defined( kDiagMaxFailedAttempts ) */
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Diagnostic service help functions */
static void FblDiagSessionControlParamInit(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static vuint8 FblDiagDownloadCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Erase help functions */
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
static tFlashStatus FblDiagGetEraseState( void );
#endif
static tFblResult FblDiagEraseBlock( V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 *pBlockDescriptor );
static tFblResult FblDiagCheckErasePreconditions(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagData,
                                                 V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * pEraseAddress,
                                                 V_MEMRAM1 tFblLength V_MEMRAM2 V_MEMRAM3 * pEraseLength);
static tFblResult FblDiagCheckWriteFingerprintPreconditions(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagData,
                                                            tCwDataLengthType diagReqDataLen,
                                                            vuint16 dataIdentifier,
                                                            V_MEMRAM1 tFblLbtBlockType V_MEMRAM2 V_MEMRAM3 * pBlockType,
                                                            V_MEMRAM1 tFblLbtBlockIndex V_MEMRAM2 V_MEMRAM3 * pBlockIndex );

static tFblResult FblDiagCheckProgAttemptCounter( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 *pBlockDescriptor);
static tFblResult FblDiagPrepareFlashDriver( void );
/* Request download help functions */
static tFblResult FblDiagCheckRequestDownloadPreconditions(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagData,
                                                           V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo);
#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
/* Request download help functions */
static tFblResult FblDiagCheckRequestUploadPreconditions(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagData,
                                                         V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo);
#endif
#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
static tFblResult FblDiagCheckForFlashDriverDownload(V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo);
static tFblResult FblDiagCheckFlashDriverDownload(V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo);
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */
static tFblResult FblDiagCheckFlashMemoryDownload(V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo);
static tFblResult FblDiagPrepareFirstDownloadSegment(V_MEMRAM1 tFblMemBlockInfo V_MEMRAM2 V_MEMRAM3 * pBlockInfo,
                                                     V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo,
                                                     tFblLbtBlockNr tempBlockNr);


/* NRC handler functions */
static tFblResult FblDiagProcessSubfunctionNrc(vuint32 serviceErrorMask);
static tFblResult FblDiagProcessServiceNrc(vuint32 serviceErrorMask);
static tFblResult FblDiagProcessRoutineNrc(vuint32 serviceErrorMask);
static tFblResult FblDiagProcessSecurityAccessNrc(vuint32 serviceErrorMask);

/* Length check functions */
static tFblResult FblDiagNoneLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Session handling */
static tFblResult FblDiagDefaultSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagProgrammingSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagExtendedSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagTesterPresentMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Reset */
static tFblResult FblDiagEcuResetMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* DID handling */
static tFblResult FblDiagDataByIdLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagReadDataByIdMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagWriteDataByIdMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Security access */
static tFblResult FblDiagSecurityAccessLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
#if defined( FBL_DIAG_ENABLE_SECACCESS_STANDARD )
static tFblResult FblDiagSecAccessSeedMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagSecAccessKeyMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
#elif defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
static tFblResult FblDiagSecAccessRequestChallengeMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagSecAccessSendSignedChallengeMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
#endif /* FBL_DIAG_ENABLE_SECACCESS_* */

/* Communication control / DTC handling */
static tFblResult FblDiagCommCtrlMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
#if defined( FBL_DIAG_ENABLE_CLEAR_DIAGNOSTIC_INFORMATION )
static tFblResult FblDiagClearDiagnosticInformation(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
#endif
static tFblResult FblDiagReadDtcByStatusMask(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Routine control */
static tFblResult FblDiagRCStartBootBlockHashMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartApplBlockHashMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartDataBlockHashMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
static tFblResult FblDiagRCStartCheckProgPreCondMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
#endif /* FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS */


static tFblResult FblDiagRCStartCheckProgramMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

static tFblResult FblDiagRCStartEraseMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartCheckProgDepMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartCSRTriggerMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Data transfer */
static tFblResult FblDiagRequestDownloadLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRequestDownloadMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
static tFblResult FblDiagRequestUploadLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRequestUploadMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
#endif
static tFblResult FblDiagTransferDataLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagTransferDataMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagReqTransferExitMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

static tFblResult FblDiagCommonBlockHashMainHandler(tFblLbtBlockType blockType, vuint8 *pbDiagData);

/* Service pre-handler functions */
static tFblResult FblDiagDefaultPreHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL CONSTANTS
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBL_DIAG_ENABLE_FLASHDRV_ROM )
/** List of flash driver source and destination buffers to be initialized. */ /* PRQA S 3218 1 */ /* MD_FblDiag_3218 */
V_MEMROM0 static V_MEMROM1 tFlashDriverInitData V_MEMROM2 kFlashDriverInitData[] = FLASH_DRIVER_INIT_DATA;
#endif /* FBL_DIAG_ENABLE_FLASHDRV_ROM */


#define FBLDIAG_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLDIAG_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/** Current block sequence counter */
V_MEMRAM0 static V_MEMRAM1 vuint8               V_MEMRAM2      currentSequenceCnt;
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
/** Invalid key counter */
V_MEMRAM0 static V_MEMRAM1 vuint8               V_MEMRAM2      secSendKeyInvalid;   /* PRQA S 3218 */ /* MD_FblDiag_3218 */
#endif

/* Segment handling variables */
/** Verification information to be transmitted to security module */
V_MEMRAM0 static V_MEMRAM1 SecM_VerifyParamType       V_MEMRAM2 verifyParam;
/** Download segment information. Used for gap fill and data verification. */
V_MEMRAM0 static V_MEMRAM1 FL_SegmentInfoType         V_MEMRAM2 downloadSegments[SWM_DATA_MAX_NOAR];  /* PRQA S 3218 */ /* MD_FblDiag_3218 */
#if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
/** Verification information to be transmitted to security module - pipelined verification */
V_MEMRAM0 static V_MEMRAM1 SecM_SignatureParamType    V_MEMRAM2 pipeSigParam; /* PRQA S 3218 */ /* MD_FblDiag_3218 */
/** Length of already verified data */
V_MEMRAM0 static V_MEMRAM1 vuint32                    V_MEMRAM2 pipeSigDataLength;  /* PRQA S 3218 */ /* MD_FblDiag_3218 */
#endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */

/* Download handling variables */
/** Transfer block information */
V_MEMRAM0 static V_MEMRAM1 tBlockDescriptor     V_MEMRAM2      downloadBlockDescriptor;
#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
/** Transfer block index */
V_MEMRAM0 static V_MEMRAM1 tFblLbtBlockIndex    V_MEMRAM2      downloadBlockIndex;
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */
/** Number of remaining transfer bytes */
V_MEMRAM0 static V_MEMRAM1 tFblLength           V_MEMRAM2      transferRemainder;
/** Block sequence counter */
V_MEMRAM0 static V_MEMRAM1 vuint8               V_MEMRAM2      expectedSequenceCnt;
/** Last erased block */
V_MEMRAM0 static V_MEMRAM1 tFblLbtBlockNr       V_MEMRAM2      lastErasedBlock;

/* Boot timeout handling */
/** Boot timeout counter */
V_MEMRAM0 static V_MEMRAM1 vuintx               V_MEMRAM2      bootTimeoutCounter;

#if defined( FBL_DIAG_ENABLE_SECACCESS_STANDARD )
/* Seed timeout handling */
/** Seed timeout counter */
V_MEMRAM0 static V_MEMRAM1 vuintx               V_MEMRAM2      seedTimeoutCounter;
#endif /* FBL_DIAG_ENABLE_SECACCESS_STANDARD */

# if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
V_MEMRAM0 static V_MEMRAM1 tFlashStatus         V_MEMRAM2      erasedStatus;
#endif
#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
/* Temporary copy for segement info during upload service */
V_MEMRAM0 static V_MEMRAM1 tFblMemSegmentInfo   V_MEMRAM2      segmentInfoUpload;
V_MEMRAM0 static V_MEMRAM1 tFblLength           V_MEMRAM2      prevTransferRemainder;
V_MEMRAM0 static V_MEMRAM1 tFblAddress          V_MEMRAM2      prevLogicalAddress;
#endif


#define FBLDIAG_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Diagnostic handler function call table
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Subfunction table configuration
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/** Sub-function defintion for Default Session (01) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableDsc_DefaultSession[] = { kDiagSubDefaultSession };
/** Sub-function defintion for Programming Session (02) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableDsc_ProgSession[] = { kDiagSubProgrammingSession };
/** Sub-function defintion for Extended Session (03) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableDsc_ExtendedSession[] = { kDiagSubExtendedDiagSession };

/** Sub-function definition for Diagnostic Session Control service (10) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableSessionControl[] =
{
   /* Default Session (01) */
   {
      kFblDiagSubtableDsc_DefaultSession,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlDiagnosticSessionControl,
      (tFblDiagLengthCheck)0u,
      FblDiagDefaultSessionMainHandler
   },
   /* Programming Session (02) */
   {
      kFblDiagSubtableDsc_ProgSession,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlDiagnosticSessionControl,
      (tFblDiagLengthCheck)0u,
      FblDiagProgrammingSessionMainHandler
   },
   /* Extended Session (03) */
   {
      kFblDiagSubtableDsc_ExtendedSession,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlDiagnosticSessionControl,
      (tFblDiagLengthCheck)0u,
      FblDiagExtendedSessionMainHandler
   }
};

/** Sub-function definition for Hard Reset sub-function (01) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableEcuReset_HardReset[] = { kDiagSubHardReset };

/** Sub-function definition for ECU Reset service (11) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableEcuReset[] =
{
   /* Hard Reset (01) */
   {
      kFblDiagSubtableEcuReset_HardReset,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming),
      kDiagRqlEcuReset,
      (tFblDiagLengthCheck)0u,
      FblDiagEcuResetMainHandler
   }
};

/** ReadDTC subfunction ID table */
/** Sub-function definition for ReadDTC - Report DTC by Status Mask (xx) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableReadDtcInfo_ReadDtcByStatusMask[] = { kDiagSubReportDTCByStatusMask };

/** Sub-function definition for ReadDTC service (19) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableReadDtcInfo[] =
{
   {
      kFblDiagSubtableReadDtcInfo_ReadDtcByStatusMask,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlReadDtcByStatusMask,
      (tFblDiagLengthCheck)0u,
      FblDiagReadDtcByStatusMask
   }
};

#if defined( FBL_DIAG_ENABLE_SECACCESS_STANDARD )
/** Sub-function definition for Request Seed sub-function (01) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableSecAccess_Seed[] = { kFblDiagSubRequestSeed };
/** Sub-function definition for Send Key sub-function (02) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableSecAccess_Key[] = { kFblDiagSubSendKey };
#elif defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
/** Sub-function definition for Request Challenge sub-function (0x11) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableSecAccess_RequestChallenge[] = { kFblDiagSubRequestChallenge };
/** Sub-function definition for Send Signed Challenge sub-function (0x12) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableSecAccess_SendSignedChallenge[] = { kFblDiagSubSendSignedChallenge };
#endif /* FBL_DIAG_ENABLE_SECACCESS_* */

/** Sub-function definition for Security Access service (27) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableSecAccess[] =
{
#if defined( FBL_DIAG_ENABLE_SECACCESS_STANDARD )
   /* Request Seed (01) */
   {
      kFblDiagSubtableSecAccess_Seed,
      (kFblDiagOptionSessionProgramming),
      kDiagRqlSecurityAccessSeed,
      (tFblDiagLengthCheck)0u,
      FblDiagSecAccessSeedMainHandler
   },
   /* Send Key (02) */
   {
      kFblDiagSubtableSecAccess_Key,
      (kFblDiagOptionSessionProgramming),
      kDiagRqlSecurityAccessKey,
      (tFblDiagLengthCheck)0u,
      FblDiagSecAccessKeyMainHandler
   }
#elif defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
   /* Request Challenge - authenticated reprogramming (0x11) */
   {
      kFblDiagSubtableSecAccess_RequestChallenge,
      (kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming),
      kDiagRqlSecurityAccessReqChallenge,
      FblDiagNoneLengthCheck,
      FblDiagSecAccessRequestChallengeMainHandler
   },
   /* Send Signed Challenge - authenticated reprogramming (0x12) */
   {
      kFblDiagSubtableSecAccess_SendSignedChallenge,
      (kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming),
      kDiagRqlSecurityAccessSendSignedChallenge,
      FblDiagNoneLengthCheck,
      FblDiagSecAccessSendSignedChallengeMainHandler
   }
#endif /* FBL_DIAG_ENABLE_SECACCESS_* */
};

/** Sub-function definition for EnableRxAndEnableTx sub-function (00) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableCommControl_EnRxEnTx[] = { kDiagSubEnableRxAndTx };
/** Sub-function definition for EnableRxAndDisableTx sub-function (01) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableCommControl_EnRxDisTx[] = { kDiagSubEnableRxAndDisableTx };

/** Sub-function defintion for Communication Control service (28) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableCommControl[] =
{
   /* Enable Rx and Tx (00) */
   {
       kFblDiagSubtableCommControl_EnRxEnTx,
       (kFblDiagOptionSessionExtended | kFblDiagOptionFunctionalRequest),
       kDiagRqlCommunicationControl,
       (tFblDiagLengthCheck)0u,
       FblDiagCommCtrlMainHandler
   },
   /* Enable Rx and Disable Tx (01) */
   {
       kFblDiagSubtableCommControl_EnRxDisTx,
      (kFblDiagOptionSessionExtended | kFblDiagOptionFunctionalRequest),
      kDiagRqlCommunicationControl,
      (tFblDiagLengthCheck)0u,
      FblDiagCommCtrlMainHandler
   }
};

/** Sub-function / RID definition for Boot Logical Block Hash (01D000) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartBootBlockHash[] = { kDiagSubStartRoutine, kDiagRoutineIdBootLogicalBlockHashHigh, kDiagRoutineIdBootLogicalBlockHashLow };

/** Sub-function / RID definition for Application Logical Block Hash (01D003) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartApplBlockHash[] = { kDiagSubStartRoutine, kDiagRoutineIdApplSwLogicalBlockHashHigh, kDiagRoutineIdApplSwLogicalBlockHashLow };

/** Sub-function / RID definition for Application Logical Block Hash (01D004) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartDataBlockHash[] = { kDiagSubStartRoutine, kDiagRoutineIdApplDataLogicalBlockHashHigh, kDiagRoutineIdApplDataLogicalBlockHashLow };

#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
/** Sub-function / RID definition for check programming preconditions (01D002) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartProgPreCond[] = { kDiagSubStartRoutine, kDiagRoutineIdCheckProgPreCondHigh, kDiagRoutineIdCheckProgPreCondLow };
#endif /* FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS */


/** Sub-function / RID definition for checksum verification (01F000) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartChkProgram[] = { kDiagSubStartRoutine, kDiagRoutineIdCheckProgramHigh, kDiagRoutineIdCheckProgramLow };

/** Sub-function / RID definition for erase memory request (01FF00) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartErase[] = { kDiagSubStartRoutine, kDiagRoutineIdEraseMemoryHigh, kDiagRoutineIdEraseMemoryLow };

/** Sub-function / RID definition for check programming dependencies request (01FF01) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartChkDep[] = { kDiagSubStartRoutine, kDiagRoutineIdCheckProgDepHigh, kDiagRoutineIdCheckProgDepLow };

/** Sub-function / RID definition for certificate signing request trigger (01D00A) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartCSRTrigger[] = { kDiagSubStartRoutine, kDiagRoutineIdCSRTriggerHigh, kDiagRoutineIdCSRTriggerLow };

/** Sub-function / RID defintion for Routine Control service (31) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableRoutine[] =
{
   /* Boot Logical Block Hash (01D000) */
   {
      kFblDiagSubtableRC_StartBootBlockHash,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControlLogicalBlockHash,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartBootBlockHashMainHandler
   },

   /* Application Logical Block Hash (01D003) */
   {
      kFblDiagSubtableRC_StartApplBlockHash,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControlLogicalBlockHash,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartApplBlockHashMainHandler
   },

   /* Application Data Logical Block Hash (01D004) */
   {
      kFblDiagSubtableRC_StartDataBlockHash,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControlLogicalBlockHash,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartDataBlockHashMainHandler
   },

#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
   /* Check programming pre-conditions (01D002) */
   {
      kFblDiagSubtableRC_StartProgPreCond,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControlProgPreCond,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartCheckProgPreCondMainHandler
   },
#endif


   /* Check Program request (01F000) */
   {
      kFblDiagSubtableRC_StartChkProgram,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService),
      kDiagRqlRoutineControlCheckProgram,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartCheckProgramMainHandler
   },

   /* Erase memory request (01FF00) */
   {
      kFblDiagSubtableRC_StartErase,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest | kFblDiagOptionSecuredService),
      kDiagRqlRoutineControlEraseRoutine,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartEraseMainHandler
   },
   /* Check programming dependencies (01FF01) */
   {
      kFblDiagSubtableRC_StartChkDep,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest | kFblDiagOptionSecuredService),
      kDiagRqlRoutineControlCheckProgDep,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartCheckProgDepMainHandler
   },
   /* Certificate signing request trigger (01D00A) */
   {
      kFblDiagSubtableRC_StartCSRTrigger,
      (kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControlCSRTrigger,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartCSRTriggerMainHandler
   }
};

/** Sub-function definition for Zero sub-function (00) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableTesterPresent_ZeroSubfunction[] = { kDiagSubTesterPresent };

/** Sub-function definition for Tester Present service (3E) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableTesterPresent[] =
{
   /* Zero sub-function (00) */
   {
      kFblDiagSubtableTesterPresent_ZeroSubfunction,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlTesterPresent,
      (tFblDiagLengthCheck)0u,
      FblDiagTesterPresentMainHandler
   }
};

/***********************************************************************************************************************
 *  Main service table configuration
 **********************************************************************************************************************/

/** Table of supported diagnostic servcies */
V_MEMROM0 V_MEMROM1 tFblDiagServiceTable V_MEMROM2 kFblDiagServiceTable[] =
{
   /* Diagnostic Session Control (10) */
   {
      kDiagSidDiagnosticSessionControl,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionServiceIsSubfunction | kFblDiagOptionFunctionalRequest),
      kDiagRqlDiagnosticSessionControl,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableSessionControl),
      ARRAY_SIZE(kFblDiagSubtableDsc_DefaultSession),
      kFblDiagSubtableSessionControl,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   },
   /* ECU Reset (11) */
   {
      kDiagSidEcuReset,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionServiceIsSubfunction),
      kDiagRqlEcuReset,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableEcuReset),
      ARRAY_SIZE(kFblDiagSubtableEcuReset_HardReset),
      kFblDiagSubtableEcuReset,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   },

   /* Read DTC Information (19) */
   {
      kDiagSidReadDTCInformation,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionServiceIsSubfunction | kFblDiagOptionFunctionalRequest),
      kDiagRqlServiceWithSubfunction,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableReadDtcInfo),
      ARRAY_SIZE(kFblDiagSubtableReadDtcInfo_ReadDtcByStatusMask),
      kFblDiagSubtableReadDtcInfo,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   },
   /* Read Data by Identifier (22) */
   {
      kDiagSidReadDataByIdentifier,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlReadDataByIdentifier,
      FblDiagDataByIdLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagReadDataByIdMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
   /* Security Access (27) */
   {
      kDiagSidSecurityAccess,
      (kFblDiagSecurityAccessSessionMask | kFblDiagOptionServiceIsSubfunction),
      kDiagRqlServiceWithSubfunction,
      FblDiagSecurityAccessLengthCheck,
      ARRAY_SIZE(kFblDiagSubtableSecAccess),
#if defined( FBL_DIAG_ENABLE_SECACCESS_STANDARD)
      ARRAY_SIZE(kFblDiagSubtableSecAccess_Seed),
#elif defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
      ARRAY_SIZE(kFblDiagSubtableSecAccess_RequestChallenge),
#endif /* FBL_DIAG_ENABLE_SECACCESS_* */
      kFblDiagSubtableSecAccess,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSecurityAccessNrc,
      FblDiagDefaultPostHandler
   },
   /* Communication Control (28) */
   {
      kDiagSidCommunicationControl,
      (kFblDiagOptionSessionExtended | kFblDiagOptionServiceIsSubfunction | kFblDiagOptionFunctionalRequest),
      kDiagRqlServiceWithSubfunction,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableCommControl),
      ARRAY_SIZE(kFblDiagSubtableCommControl_EnRxDisTx),
      kFblDiagSubtableCommControl,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   },
   /* Write Data by Identifier (2E) */
   {
      kDiagSidWriteDataByIdentifier,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming),
      kDiagRqlWriteDataByIdentifier,
      FblDiagDataByIdLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagWriteDataByIdMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
   /* Routine Control (31) */
   {
      kDiagSidRoutineControl,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionServiceIsSubfunction | kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControl,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableRoutine),
      ARRAY_SIZE(kFblDiagSubtableRC_StartChkProgram),
      kFblDiagSubtableRoutine,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessRoutineNrc,
      FblDiagDefaultPostHandler
   },
   /* Request Download (34) */
   {
      kDiagSidRequestDownload,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService),
      kDiagRqlRequestDownload,
      FblDiagRequestDownloadLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagRequestDownloadMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
   /* Request Upload (35) */
   {
      kDiagSidRequestUpload,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService ),
      kDiagRqlRequestUpload,
      FblDiagRequestUploadLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagRequestUploadMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
#endif
   /* Transfer Data (36) */
   {
      kDiagSidTransferData,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService),
      kDiagRqlTransferData,
      FblDiagTransferDataLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagTransferDataMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
   /* Request Transfer Exit (37) */
   {
      kDiagSidRequestTransferExit,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService),
      kDiagRqlRequestTransferExit,
      FblDiagNoneLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagReqTransferExitMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
   /* Tester Present (3E) */
   {
      kDiagSidTesterPresent,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionServiceIsSubfunction | kFblDiagOptionFunctionalRequest),
      kDiagRqlTesterPresent,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableTesterPresent),
      ARRAY_SIZE(kFblDiagSubtableTesterPresent_ZeroSubfunction),
      kFblDiagSubtableTesterPresent,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   }
#if defined( FBL_DIAG_ENABLE_CLEAR_DIAGNOSTIC_INFORMATION )
   ,{
      kDiagSidClearDiagInfo,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionFunctionalRequest),
      kDiagRqlClearDiagInfo,
      (tFblDiagLengthCheck)0u,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagClearDiagnosticInformation,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   }
#endif /* FBL_DIAG_ENABLE_CLEAR_DIAGNOSTIC_INFORMATION */
};

/** Size of service table */
V_MEMROM0 V_MEMROM1 vuintx V_MEMROM2 kSizeOfServiceTable = ARRAY_SIZE(kFblDiagServiceTable);

#define FBLDIAG_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Service support functions
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  FblDiagDownloadCheck
 **********************************************************************************************************************/
/*! \brief       Verify the downloaded data.
 *  \details     Uses the configured security module to verify if the download has been done correctly and
 *               the data is allowed to be downloaded. Also calculates CRC total if enabled.
 *  \pre         Logical block or flash driver has to be downloaded completely.
 *  \param[in]   pbDiagData Pointer to data in the diagBuffer (without SID).
 *  \param[in]   diagReqDataLen Length of data (without SID).
 *  \return      Verification result supplied by the security module.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static vuint8 FblDiagDownloadCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   vuint8 result;
#if (( SEC_SECURITY_CLASS == SEC_CLASS_DDD )    || \
     ( SEC_SECURITY_CLASS == SEC_CLASS_CCC ))
   tFblMemBlockVerifyData verifyData;
   SecM_StatusType verifyErrorCode;
#endif

#if ( SEC_SECURITY_CLASS == SEC_CLASS_VENDOR )
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
   (void)pbDiagData;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */
#endif /* SEC_SECURITY_CLASS == SEC_CLASS_VENDOR */

   /* Length is not explicitly submitted - use (request length - sub-parameter and routine ID length) */

#if (( SEC_SECURITY_CLASS == SEC_CLASS_DDD )    || \
     ( SEC_SECURITY_CLASS == SEC_CLASS_CCC ))

# if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
   verifyData.verifyDataPipe.length = diagReqDataLen - 5u;
   verifyData.verifyDataPipe.data = (V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *)&pbDiagData[kDiagLocFmtRoutineStatus + 2u];
# endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */

# if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT )
   verifyData.verifyDataOutput.length = diagReqDataLen - (tFblLength)3u;
   verifyData.verifyDataOutput.data = (V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *)&pbDiagData[kDiagLocFmtRoutineStatus];
# endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT */

   /* Call verification routine */
   if (FblMemRemapStatus(FblMemBlockVerify(&verifyData, &verifyErrorCode)) != (FBL_MEM_STATUS_TYPE)kFblMemStatus_Ok)
   {
      if (verifyErrorCode == SECM_OK)
      {
         /* If no verification error code is provided, return general error */
         result = kDiagCheckVerificationGeneralFailure;
      }
      else
      {
         result = verifyErrorCode;
      }
   }
   else
   {
      result = kDiagCheckVerificationOk;
   }
#endif /* ( SEC_SECURITY_CLASS == SEC_CLASS_DDD ) || ( SEC_SECURITY_CLASS == SEC_CLASS_CCC ) */
#if ( SEC_SECURITY_CLASS == SEC_CLASS_VENDOR )
   result = ApplFblVerifyFcaHeader(downloadBlockDescriptor.blockNr, &(verifyParam.segmentList));
#endif /* ( SEC_SECURITY_CLASS == SEC_CLASS_VENDOR ) */

   if (result == kDiagCheckVerificationOk)
   {
      if (FblDiagGetTransferTypeFlash())
      {
         (void)FblRealTimeSupport();
#if defined( SEC_ENABLE_CRC_TOTAL )
         (void)ApplFblWriteCRCTotal(&downloadBlockDescriptor,
                                    (vuint32)verifyParam.blockStartAddress,
                                    (vuint32)verifyParam.blockLength,
                                    (vuint32)verifyParam.crcTotal
                                   );
#endif /* SEC_ENABLE_CRC_TOTAL */

         /* Call validation function to inform application */
         if (ApplFblValidateBlock(downloadBlockDescriptor) != kFblOk)
         {
            result = kDiagCheckVerificationGeneralFailure;
         }
         else if (ApplFblWriteSegmentList(downloadBlockDescriptor.blockNr, &verifyParam.segmentList) != kFblOk)
         {
            result = kDiagCheckVerificationGeneralFailure;
         }
         else
         {
            /* Increment programming success counter */
            (void)ApplFblIncProgCounts(downloadBlockDescriptor);
         }
      }
#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
      else /* Download of flash driver */
      {
         /* Send response pending for flash driver initialization */
         DiagExRCRResponsePending(kForceSendRpIfNotInProgress);

         /* Mark flash driver as present */
         FblDiagSetFlashDriverPresent();

         if (FblDiagPrepareFlashDriver() == kFblOk)
         {
            /* Expect download of application next */
            FblDiagSetTransferTypeFlash();
         }
         else
         {
            /* Flash driver initialization failed */
            result = kDiagCheckVerificationGeneralFailure;
         }
      }
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */
   }

   return result;
}

#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
/***********************************************************************************************************************
 *  FblDiagGetEraseState
 **********************************************************************************************************************/
/*! \brief       This function checks if the current logical block is erased.
 *  \details     If the memoryStatus flag indicates
 *               "erased", an additional user callback is called in order to
 *               make sure, that the erase routine actually can be omitted.
 *  \return      kFlashErased if block is already erased, kFlashNotErased if block is not erased
 **********************************************************************************************************************/
static tFlashStatus FblDiagGetEraseState( void )
{
   tFlashStatus status;
   vuint8 memoryStatus;

   status = kFlashNotErased;

   /* Check if the memory status flag indicates "erased" */
   if (ApplFblReadMemoryStatus(downloadBlockDescriptor.blockNr, &memoryStatus) == kFblOk)
   {
      if (memoryStatus == kDiagMemStatErased )
      {
         /* Invoke callback */
         status = ApplFblGetBlockErased(downloadBlockDescriptor);
      }
   }
   return status;
}
#endif   /* FBL_ENABLE_FLASH_ERASED_DETECTION */

/***********************************************************************************************************************
 *  FblDiagEraseBlock
 **********************************************************************************************************************/
/*! \brief       Erase selected block
 *  \details     Prepare data structure for FblLib_Mem and erase block
 *  \pre         Flash driver initialized, erase pre-conditions have been checked
 *  \param[in]   pBlockDescriptor Pointer to block descriptor structure
 *  \return      Erase result
 **********************************************************************************************************************/
static tFblResult FblDiagEraseBlock( V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 *pBlockDescriptor )
{
   tFblResult result;
   tFblMemBlockInfo blockInfo;
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
   vuint8 memoryStatus;
#endif


   /* Initialize block structure for FblLib_Mem */
   blockInfo.targetAddress = pBlockDescriptor->blockStartAddress;
   blockInfo.targetLength = pBlockDescriptor->blockLength;
   blockInfo.logicalAddress = pBlockDescriptor->blockStartAddress;
   blockInfo.logicalLength = pBlockDescriptor->blockLength;

   /* Start erase by FblLib_Mem */
   if (
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
      (erasedStatus == kFlashErased) ||
#endif
      (FblMemBlockEraseIndication(&blockInfo) == kFblMemStatus_Ok) /* PRQA S 3415 */ /* MD_FblDiagOem_3415 */
      )
   {
      /* Erase succeeded */
      FblDiagSetEraseSucceeded();

#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
      erasedStatus = kFlashErased;
      memoryStatus = kDiagMemStatErased;
#endif
      /* After erase, the first segment of a logical block will be downloaded */

      /* Adjust the size of the logical block according to presence pattern size. */
      (void)ApplFblAdjustLbtBlockData(pBlockDescriptor);

      /* Initialize segment counter */
      FblDiagSegmentInit();

      result = kFblOk;
   }
   else
   {
      /* Erase failed */
      result = kFblFailed;
   }

   if (result != kFblOk)
   {
      /* Erase failed */
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
      erasedStatus = kFlashNotErased;
      memoryStatus = kDiagMemStatProgrammed;
#endif
      FblDiagClrEraseSucceeded();
   }

#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
   /* Update memory status in NVM */
   if (ApplFblWriteMemoryStatus(pBlockDescriptor->blockNr, &memoryStatus) != kFblOk)
   {
      result = kFblFailed;
   }
#endif
   return result;
}

/***********************************************************************************************************************
 *  FblDiagCheckErasePreconditions
 **********************************************************************************************************************/
/*! \brief         Verify that all erase preconditions are fulfilled
 *  \pre           Fingerprint is available, memory driver initialized.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[out]    pEraseAddress Start address of erase area
 *  \param[out]    pEraseLength Length of erase area
 *  \return        kFblOk: Preconditions fulfilled; kFblFailed: Preconditions not fulfilled
 **********************************************************************************************************************/
/* PRQA S 3673 3 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagCheckErasePreconditions(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagData,
                                                 V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * pEraseAddress,
                                                 V_MEMRAM1 tFblLength V_MEMRAM2 V_MEMRAM3 * pEraseLength)
{
   tFblResult result;
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pEraseAddress;
   (void)pEraseLength;
   (void)pbDiagData;
#endif

   if (!FblDiagGetFingerprintValid())
   {
      /* Invalid sequence - send NRC 0x24 */
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   else if (FblDiagPrepareFlashDriver() != kFblOk)
   {
      /* Invalid sequence - send NRC 0x22 */
      DiagNRCConditionsNotCorrect();
      result = kFblFailed;
   }
   else
   {
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagCheckWriteFingerprintPreconditions
 **********************************************************************************************************************/
/*! \brief         Check write fingerprint request and preconditions
 *  \pre           Logical block has has been requested.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Data length (without SID).
 *  \param[in]     dataIdentifier Received DID
 *  \param[out]    pBlockType Type of logical block (boot, code or data)
 *  \param[out]    pBlockIndex Logical block index
 *  \return        kFblOk: Preconditions fulfilled; kFblFailed: Preconditions not fulfilled
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagCheckWriteFingerprintPreconditions(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagData,
                                                            tCwDataLengthType diagReqDataLen,
                                                            vuint16 dataIdentifier,
                                                            V_MEMRAM1 tFblLbtBlockType V_MEMRAM2 V_MEMRAM3 * pBlockType,
                                                            V_MEMRAM1 tFblLbtBlockIndex V_MEMRAM2 V_MEMRAM3 * pBlockIndex )
{
   tFblResult result;

   result = kFblOk;

   if (!FblDiagGetProgrammingSession())
   {
      /* The ECU is not in programming session */
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   else if (diagReqDataLen != kDiagRqlWriteDataByIdentifierFingerPrint)
   {
      /* Request length is incorrect */
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
      result = kFblFailed;
   }
   else if (!FblDiagGetSecurityUnlock())
   {
      /* The ECU is locked */
      DiagNRCSecurityAccessDenied();
      result = kFblFailed;
   }
   else
   {
      /* Everything ok */
      switch(dataIdentifier)
      {
         case kFblDiagDidBootSwFingerprintWrite:
         {
            *pBlockType = (vuint8)kBlockTypeBoot;
            break;
         }

         case kFblDiagDidApplSwFingerprintWrite:
         {
            *pBlockType = (vuint8)kBlockTypeCode;
            break;
         }

         case kFblDiagDidApplDataFingerprintWrite:
         {
            *pBlockType = (vuint8)kBlockTypeData;
            break;
         }

         default:
         {
            *pBlockType = kBlockTypeNone;
            result = kFblFailed;
            break;
         }
      }
   }

   if (result == kFblOk)
   {
      *pBlockIndex = pbDiagData[kDiagLocFmtDataRecord];
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagPrepareFlashDriver
 **********************************************************************************************************************/
/*! \brief         Prepare flash driver for usage
 *  \return        Preparation result
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static tFblResult FblDiagPrepareFlashDriver( void )
{
   tFblResult result;
   tFlashErrorCode flashErrorCode;
#if defined( FBL_DIAG_ENABLE_FLASHDRV_ROM )
   vuintx flashDriverIndex;
   vuint32 byteIndex;
   V_MEMROM1 tFlashDriverInitData V_MEMROM2 V_MEMROM3 * flashDriverInitData;
#endif /* FBL_DIAG_ENABLE_FLASHDRV_ROM */

   /* Initialize variable */
   result = kFblFailed;

   if (!FblDiagGetMemDriverInitialized())
   {
#if defined( FBL_DIAG_ENABLE_FLASHDRV_ROM )
      /* Use flash driver from image in case no driver has been downloaded */
      if (!FblDiagGetFlashDriverPresent())
      {
         /* Copy data of all configured flash drivers */
         for (flashDriverIndex = 0u; flashDriverIndex < ARRAY_SIZE(kFlashDriverInitData); flashDriverIndex++)
         {
            flashDriverInitData = &kFlashDriverInitData[flashDriverIndex];

            /* Check if target buffer is big enough for data */
            if (flashDriverInitData->copySize > FLASH_SIZE)
            {
               /* Data doesn't fit into buffer. Assumes that all buffers are configured to the same size
                * if more than one buffer is used.
               */
               FblErrStatSetError(FBL_ERR_FLASHCODE_EXCEEDS_MEMORY);
               break;
            }

            for (byteIndex = 0u; byteIndex < flashDriverInitData->copySize; byteIndex++)
            {
               flashDriverInitData->destBuffer[byteIndex] = (flashDriverInitData->decryptValue ^ flashDriverInitData->sourceBuffer[byteIndex]);
               if ((byteIndex & 0xFFu) == 0x00u)
               {
                  FblLookForWatchdogVoid();
               }
            }
         }
         /* Data copied */
         FblDiagSetFlashDriverPresent();
      }
#endif /* FBL_DIAG_ENABLE_FLASHDRV_ROM */

      if (FblDiagGetFlashDriverPresent())  /* PRQA S 2991, 2995 */ /* MD_FblDiag_2991_2995_RedundantCondition */
      {
         /* Initialize version */
         FblErrStatSetFlashDrvVersion();

         /* Turn on programming voltage (if necessary) */
         ApplFblSetVfp();

         /* Initialze memory drivers */
         FblCwSetOfflineMode();
         /* Check version and initialize flash driver */
         flashErrorCode = MemDriver_InitSync(V_NULL);
         FblCwSetOnlineMode();

         if (flashErrorCode == IO_E_OK)
         {
            FblDiagSetMemDriverInitialized();
            result = kFblOk;
         }
         else
         {
            FblErrStatSetError(FBL_ERR_FLASHCODE_INIT_FAILED);
            FblErrStatSetFlashDrvError(flashErrorCode);
         }
      }
   }
   else
   {
      /* Flash driver already initialized */
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagCheckProgAttemptCounter
 **********************************************************************************************************************/
/*! \brief         Check if programming attempt counter allows another programming cycle
 *  \pre           Response pending processing has been started, block has been selected
 *  \param[in]     pBlockDescriptor Pointer to current download block descriptor
 *  \return        kFblOk: Programming allowed; kFblFailed: Programming not allowed
 **********************************************************************************************************************/
static tFblResult FblDiagCheckProgAttemptCounter(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2  V_MEMRAM3 *pBlockDescriptor)
{
   tFblResult result;
   vuint16 progAttempts;
   tFblLbtMaxProgAttempts maxProgAttempts;

   /* Initialize variables */
   if (ApplFblGetProgAttempts(*pBlockDescriptor, &progAttempts) != kFblOk)
   {
      /* Programming attempt counter couldn't be read. Use 0 as default value. */
      progAttempts = 0u;
   }

   result = FblLbtGetBlockMaxProgAttemptsByNr(pBlockDescriptor->blockNr, &maxProgAttempts);

   /* Check if logical block does not restrict the number of programming attempts */
   if ( (result == kFblOk) && (maxProgAttempts != 0u) )
   {
      /* Check logical block programming attempts */
      if (progAttempts >= maxProgAttempts)
      {
         /* Logical block cannot be programmed anymore */
         FblErrStatSetError(FBL_ERR_FLASH_PROG_CONDITIONS);
         DiagNRCConditionsNotCorrect();
         result = kFblFailed;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagCheckRequestDownloadPreconditions
 **********************************************************************************************************************/
/*! \brief         Verify that all request download preconditions are fulfilled
 *  \pre           Fingerprint is available
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[out]    pSegmentInfo FblLib_Mem segment information for this download
 *  \return        kFblOk: Preconditions fulfilled; kFblFailed: Preconditions not fulfilled
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagCheckRequestDownloadPreconditions(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagData,
                                                           V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo)
{
   tFblResult result;

   vuint8  lengthFormat;
   vuint8  addrFormat;

   /* Initialize variables */
   pSegmentInfo->logicalAddress = 0u;
   pSegmentInfo->logicalLength = 0u;
   pSegmentInfo->targetAddress = 0u;
   pSegmentInfo->targetLength = 0u;

   /* Get length and address format from message */
   lengthFormat = (vuint8)((pbDiagData[kDiagLocFmtFormatOffset] & 0xF0u) >> 4u);
   addrFormat = (vuint8) (pbDiagData[kDiagLocFmtFormatOffset] & 0x0Fu);

   /* Read compression and encryption method */
   pSegmentInfo->dataFormat = (tFblMemDfi)pbDiagData[kDiagLocFmtSubparam];

   if ((FblDiagGetTransferDataAllowed()) || (!FblDiagGetFingerprintValid()))
   {
      /* Invalid sequence - send NRC 0x24 because of RQMT 5-118, CS.00101 Rev C */
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   else
   {
      /* Get memoryAddress */
      pSegmentInfo->logicalAddress = FblMemGetInteger(addrFormat, &(pbDiagData[kDiagLocFmtAddrOffset]));
      /* Get memorySize */
      pSegmentInfo->logicalLength = FblMemGetInteger(lengthFormat, &(pbDiagData[kDiagLocFmtAddrOffset + addrFormat]));

      result = kFblOk;
   }

   return result;
}

#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
/***********************************************************************************************************************
 *  FblDiagCheckRequestUploadPreconditions
 **********************************************************************************************************************/
/*! \brief         Verify that all request upload preconditions are fulfilled
 *  \pre           -
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[out]    pSegmentInfo FblLib_Mem segment information for this download
 *  \return        kFblOk: Preconditions fulfilled; kFblFailed: Preconditions not fulfilled
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagCheckRequestUploadPreconditions(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagData,
                                                         V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo)
{
   tFblResult result;

   vuint8  lengthFormat;
   vuint8  addrFormat;

   /* Initialize variables */
   pSegmentInfo->logicalAddress = 0u;
   pSegmentInfo->logicalLength = 0u;
   pSegmentInfo->targetAddress = 0u;
   pSegmentInfo->targetLength = 0u;
   pSegmentInfo->type = kFblMemType_RAM;

   /* Get length and address format from message */
   lengthFormat = (vuint8)((pbDiagData[kDiagLocFmtFormatOffset] & 0xF0u) >> 4u);
   addrFormat = (vuint8) (pbDiagData[kDiagLocFmtFormatOffset] & 0x0Fu);

   /* Initialize with no data processing */
   pSegmentInfo->dataFormat = kDiagSubNoDataProcessing;

   if (FblDiagGetTransferDataAllowed())
   {
      /* Invalid sequence - send NRC 0x24 because of RQMT 5-118, CS.00101 Rev C */
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   else
   {
      /* Get memoryAddress */
      pSegmentInfo->logicalAddress = FblMemGetInteger(addrFormat, &(pbDiagData[kDiagLocFmtAddrOffset]));
      /* Get memorySize */
      pSegmentInfo->logicalLength = FblMemGetInteger(lengthFormat, &(pbDiagData[kDiagLocFmtAddrOffset + addrFormat]));

      result = kFblOk;
   }

   return result;
}
#endif

#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
/***********************************************************************************************************************
 *  FblDiagCheckForFlashDriverDownload
 **********************************************************************************************************************/
/*! \brief         Check if a flash driver or application should be downloaded
 *  \pre           Download precondition check succeeded
 *  \param[in,out] pSegmentInfo FblLib_Mem segment information for this download
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
static tFblResult FblDiagCheckForFlashDriverDownload(V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo)
{
   tFblResult result;

   /* Initialize variables */
   result = kFblOk;

# if defined( FLASHCODE_RELOCATABLE ) || \
     defined( FLASH_DRIVER_RELOCATABLE )
   /* For relocatable drivers: If erase succeeded state is set, assume a data download
      is performed. Otherwise, a driver download is assumed. This enables downloads to
      logical blocks starting with address 0x00 in combination with relocatable flash
      drivers.
   */
   if ((pSegmentInfo->logicalAddress == 0u) && (!FblDiagGetEraseSucceeded()))
# else
   if (pSegmentInfo->logicalAddress == FBL_DIAG_FLASH_CODE_BASE_ADDR) /* PRQA S 0306 */ /* MD_FblDiagOem_0306 */
# endif /* FLASHCODE_RELOCATABLE || FLASH_DRIVER_RELOCATABLE */
   {
      /* Download of flash driver requested */
      FblDiagClrFlashDriverPresent();
      /* Deinit flash driver in case it is already initialized */
      if (FblDiagGetMemDriverInitialized())
      {
         DiagExRCRResponsePending(kForceSendRpIfNotInProgress);
         FblDiagClrMemDriverInitialized();
         (void)MemDriver_DeinitSync(V_NULL);
      }
      /* Download of flash driver requested */
      FblDiagClrTransferTypeFlash();
      pSegmentInfo->type = kFblMemType_RAM;
   }
   else
   {
      /* Download of data requested */
      FblDiagSetTransferTypeFlash();

      /* Set target memory type for download */
      pSegmentInfo->type = kFblMemType_ROM;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagCheckFlashDriverDownload
 **********************************************************************************************************************/
/*! \brief         Check if the download request matches the flash driver buffer
 *  \param[in,out] pSegmentInfo FblLib_Mem segment information for this download
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
static tFblResult FblDiagCheckFlashDriverDownload(V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo)
{
   tFblResult result;

   /* Initialize target address. This address is used to store the downloaded data */
#if defined( FLASHCODE_RELOCATABLE ) || \
    defined( FLASH_DRIVER_RELOCATABLE )
   pSegmentInfo->targetAddress = FBL_DIAG_FLASH_CODE_BASE_ADDR; /* PRQA S 0306 */ /* MD_FblDiagOem_0306 */
#else
   pSegmentInfo->targetAddress = pSegmentInfo->logicalAddress;
#endif /* FLASHCODE_RELOCATABLE || FLASH_DRIVER_RELOCATABLE */

   /* Store download length */
   pSegmentInfo->targetLength = pSegmentInfo->logicalLength;

   /* Check if flash driver fits into flash driver buffer */ /* PRQA S 0306 1 */ /* MD_FblDiagOem_0306 */
   if (FblLbtCheckRangeContained(pSegmentInfo->targetAddress, pSegmentInfo->targetLength, FBL_DIAG_FLASH_CODE_BASE_ADDR, FLASH_SIZE) == kFblOk)
   {
      /* Initialize segment counter */
      FblDiagSegmentInit();
      /* Copy data and address of first segment to initialize downloadHeader */
      (void)FblDiagSegmentNext();

      result = kFblOk;
   }
   else
   {
      FblErrStatSetError(FBL_ERR_FLASHCODE_EXCEEDS_MEMORY);
      DiagNRCRequestOutOfRange();

      result = kFblFailed;
   }

   /* Verification routine of first logical block used for flash driver */
   downloadBlockDescriptor.blockNr = 0u;

   return result;
}
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */

/***********************************************************************************************************************
 *  FblDiagCheckFlashMemoryDownload
 **********************************************************************************************************************/
/*! \brief         Check if the download request matches the erased logical block
 *  \param[in,out] pSegmentInfo FblLib_Mem segment information for this download
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static tFblResult FblDiagCheckFlashMemoryDownload(V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo)
{
   FL_SegmentInfoType * segment; /* PRQA S 3678 */ /* MD_MSR_Rule8.13 */

   tFblResult result;

   /* Initialize variables */
   result = kFblOk;

   /* Memory driver has to be available */
   if (!FblDiagGetMemDriverInitialized())
   {
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   /* Memory has to be erased in case of first segment in logical block */
   else if ((segmentCount == 0u) && (!FblDiagGetEraseSucceeded()))
   {
      /* Invalid sequence - send NRC 0x24  */
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   /* Verify addresses (address must be in the area described by downloadBlockDescriptor)
      * this check requires WriteDataByIdentifier (Fingerprint), because this initializes downloadBlockDescriptor */
   else if (   (FblLbtCheckRangeContained(pSegmentInfo->logicalAddress,
                                       pSegmentInfo->logicalLength,
                                       downloadBlockDescriptor.blockStartAddress,
                                       downloadBlockDescriptor.blockLength) != kFblOk)
            || ( transferRemainder == 0u)
            )
   {
      FblErrStatSetError(FBL_ERR_LBT_ADDR_MISMATCH);
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   else
   {
      if (FblDiagSegmentNext() == kSwmOutOfRange)
      {
         FblErrStatSetError(FBL_ERR_TOO_MANY_SEGMENTS_IN_MODULE);
         DiagNRCRequestOutOfRange();
         result = kFblFailed;
      }
      else
      {
         /* Store address/length information of RequestDownload for flash operation */
         pSegmentInfo->targetAddress = pSegmentInfo->logicalAddress;
         pSegmentInfo->targetLength = pSegmentInfo->logicalLength;

         /* Check if requested segment overlaps with previously downloaded data */
         if (segmentCount > 1u)
         {
            /* Download second segment */
            segment = &verifyParam.segmentList.segmentInfo[segmentCount - 2u];

            if (   (pSegmentInfo->targetAddress <= segment->transferredAddress)
                || ((pSegmentInfo->targetAddress - segment->transferredAddress) < segment->length)
               )
            {
               /* New segment is not in order or overlaps previous one */
               DiagNRCRequestOutOfRange();
               result = kFblFailed;
            }
         }
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagPrepareFirstDownloadSegment
 **********************************************************************************************************************/
/*! \brief         Add block structure to FblLib_Mem data
 *  \param[out]    pBlockInfo Logical block information data provided to FblLib_Mem
 *  \param[in]     pSegmentInfo Segment information of requested download
 *  \param[in]     tempBlockNr Logical index of verification routine for this download
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 3 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagPrepareFirstDownloadSegment(V_MEMRAM1 tFblMemBlockInfo V_MEMRAM2 V_MEMRAM3 * pBlockInfo,
                                                     V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo,
                                                     tFblLbtBlockNr tempBlockNr)
{
   tFblResult result;
   tFblDiagNrc libMemResult;
   tExportFct exportFct;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pSegmentInfo;
#endif

   /* Initialize variables */
   result = kFblOk;
   exportFct = V_NULL;

   /* Info: Flash driver uses verification routines of first logical block */
#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT )
   if (result == kFblOk)   /* PRQA S 2991, 2995 */ /* MD_FblDiag_2991_2995_RedundantCondition */
   {
      result = FblLbtGetBlockVerifyOutputFuncByNr(tempBlockNr, &exportFct);
   }
   if (result == kFblOk)
   {
      pBlockInfo->verifyRoutineOutput.function = (tFblMemVerifyFctOutput)exportFct;    /* PRQA S 0313 */ /* MD_FblDiagOem_0313 */
      pBlockInfo->verifyRoutineOutput.param = (V_MEMRAM1 tFblMemVerifyParamOutput V_MEMRAM2 V_MEMRAM3 *)&verifyParam;
   }
#endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT */

#if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
   if (result == kFblOk)   /* PRQA S 2991, 2995 */ /* MD_FblDiag_2991_2995_RedundantCondition */
   {
      result = FblLbtGetBlockVerifyPipelinedFuncByNr(tempBlockNr, &exportFct);
   }
   if (result == kFblOk)
   {
      /* Configure pipelined verification */
      pBlockInfo->verifyRoutinePipe.function = (tFblMemVerifyFctInput)exportFct; /* PRQA S 0313 */ /* MD_FblDiagOem_0313 */
      pBlockInfo->verifyRoutinePipe.param = (V_MEMRAM1 tFblMemVerifyParamInput V_MEMRAM2 V_MEMRAM3 *)&pipeSigParam;
      /* Force use of internal workspace */
      pipeSigParam.currentHash.sigResultBuffer = (SecM_ResultBufferType)V_NULL;  /* PRQA S 0306 */ /* MD_FblDiagOem_0306 */
      pipeSigParam.currentHash.length = 0u;
      pipeSigParam.currentDataLength = &pipeSigDataLength;
   }
#endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */
   if (result == kFblOk)
   {
      pBlockInfo->segmentList = &verifyParam.segmentList;
      pBlockInfo->maxSegments = SWM_DATA_MAX_NOAR;
      verifyParam.segmentList.segmentInfo = downloadSegments;

      /* Prepare block data structure */
      if (FblDiagGetTransferTypeFlash())
      {
         pBlockInfo->targetAddress = downloadBlockDescriptor.blockStartAddress;
         pBlockInfo->targetLength = downloadBlockDescriptor.blockLength;
         pBlockInfo->logicalAddress = downloadBlockDescriptor.blockStartAddress;
         pBlockInfo->logicalLength = downloadBlockDescriptor.blockLength;

         pBlockInfo->readFct = (tFblMemVerifyReadFct)FblReadProm;
      }
#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
      else
      {
         pBlockInfo->targetAddress = pSegmentInfo->targetAddress;
         pBlockInfo->targetLength = pSegmentInfo->targetLength;
         pBlockInfo->logicalAddress = pSegmentInfo->logicalAddress;
         pBlockInfo->logicalLength = pSegmentInfo->logicalLength;

         pBlockInfo->readFct = (tFblMemVerifyReadFct)FblReadRam;
      }
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */

      /* Add block to FblLib_Mem state machine */
      libMemResult = FblMemRemapStatus(FblMemBlockStartIndication(pBlockInfo));
      /* Check if FblLib_Mem reported an error */
      if (libMemResult != kDiagErrorNone)
      {
         FblDiagSetError(libMemResult);
         result = kFblFailed;
      }
   }

   return result;
}


/***********************************************************************************************************************
 *  FblDiagSessionControlParamInit
 **********************************************************************************************************************/
/*! \brief         Initialization of session control request response.
 *  \param[in,out] pbDiagData Pointer to data in the diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Data length (without SID).
 **********************************************************************************************************************/
static void FblDiagSessionControlParamInit(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   /* Reset internal states */
   FblDiagClrSecurityKeyAllowed();
   FblDiagClrSecurityUnlock();
   FblDiagClrFingerprintValid();
   FblDiagClrEraseSucceeded();
   FblDiagClrTransferDataAllowed();
   FblDiagClrTransferDataSucceeded();
   FblDiagClrChecksumAllowed();

   /* Reset variables */
   transferRemainder = 0u;
   FblDiagSetLastErasedBlock(kBlockNrInvalid);
   /* Initialize flash driver download handling */
   FblDiagClrTransferTypeFlash();

   /* Initialize segment counter */
   FblDiagSegmentInit();

   /* Initialize security module */
   (void)ApplFblSecurityInit();

#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
   erasedStatus = kFlashNotErased;
#endif

   /* Prepare diagnostic response */
   pbDiagData[kDiagLocFmtSubparam + 1u] = (vuint8)(((vuint16)kDiagSessionTimingP2 >> 8u) & 0xFFu);
   pbDiagData[kDiagLocFmtSubparam + 2u] = (vuint8)(kDiagSessionTimingP2 & 0xFFu);
   pbDiagData[kDiagLocFmtSubparam + 3u] = (vuint8)((kDiagSessionTimingP2Star >> 8u) & 0xFFu);
   pbDiagData[kDiagLocFmtSubparam + 4u] = (vuint8)(kDiagSessionTimingP2Star & 0xFFu);
}

/***********************************************************************************************************************
 *  FblDiagOemInitPowerOn
 **********************************************************************************************************************/
/*! \brief       Initialize module variables
 **********************************************************************************************************************/
void FblDiagOemInitPowerOn(void)
{
   expectedSequenceCnt = 0;
   FblDiagSetLastErasedBlock(kBlockNrInvalid);
}

/***********************************************************************************************************************
 *  FblDiagOemPostInit
 **********************************************************************************************************************/
/*! \brief       Finish OEM specific initialization tasks
 **********************************************************************************************************************/
void FblDiagOemPostInit(void)
{
   /* Activate boot timeout counter in case an application software could be started */
   if (FblMainGetApplicationValid())
   {
      FblDiagSetBootTimeoutActive();
      bootTimeoutCounter = FBL_DIAG_BOOT_TIMOUT_COUNTER;
   }

#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED)
   if (ApplFblGetSecAccessDelayFlag())
   {
      vuint8 invalidCount;

      /* Get Number of previously failed attempts */
      if (ApplFblReadSecAccessInvalidCount(&invalidCount) != kFblOk)
      {
         invalidCount = kDiagMaxFailedAttempts;
      }

      /* Calculate delay timer */
      secSecurityAccessDelay = FBL_SEC_DELAY_TIMEOUT(invalidCount);
   }
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */
}

/***********************************************************************************************************************
 *  FblDiagGetLastErasedBlock
 **********************************************************************************************************************/
/*! \brief       Returns last erased logical block or kBlockNrInvalid if no block has been erased yet.
 **********************************************************************************************************************/
vuint8 FblDiagGetLastErasedBlock(void)
{
   return lastErasedBlock;
}

/***********************************************************************************************************************
 *  FblDiagSetLastErasedBlock
 **********************************************************************************************************************/
/*! \brief       Sets last erased logical block.
 *  \param[in]   blockNr Block number of last erased logical block
 **********************************************************************************************************************/
void FblDiagSetLastErasedBlock(tFblLbtBlockNr blockNr)
{
   lastErasedBlock = blockNr;
}

/***********************************************************************************************************************
 *  FblDiagOemTimerTask
 **********************************************************************************************************************/
/*! \brief       This function handles the FBL Bootloader timeout
 *  \details     When a timeout occurs the application is started.
 **********************************************************************************************************************/
void FblDiagOemTimerTask(void)
{
   /* Check if timer should be decremented */
   if (FblDiagGetBootTimeoutActive())
   {
      if (bootTimeoutCounter > 0u)
      {
         bootTimeoutCounter--;
      }
      else
      {
         /* Boot timeout counter expired. Start application */
         /* Deinitialize communication wrapper */
#if( FBL_CW_API_REFERENCE_VERSION_MAJOR == 0x02u )
         FblCw_Deinit();
#else
         FblCwDeinit();
#endif
#if defined( FBL_WATCHDOG_ON )
         /* Synchronize watchdog before application start */
         ApplFblWDLong();
#endif /* FBL_WATCHDOG_ON */
         /* Stop timer to avoid a timer interrupt
            after application start */
         FblTimerStopp();

         /* Start application code */
         ApplFblStartApplication();
      }
   }
#if defined( FBL_DIAG_ENABLE_SECACCESS_STANDARD )
   /* Check if seed timer should be decremented */
   if (seedTimeoutCounter > 0u)
   {
      seedTimeoutCounter--;
   }
#endif /* FBL_DIAG_ENABLE_SECACCESS_STANDARD */
   /* Trigger periodical evaluation of ADA certificate validity
    * if a valid certificate is present
    */
#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
   if (ApplFblGetAuthenticationState() == kFblAuthenticated)
   {
      ApplFblAuthenticationTimerTask();
   }
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */
}

/***********************************************************************************************************************
 *  FblDiagProcessServiceNrc
 **********************************************************************************************************************/
/*! \brief       This routine maps service check errors to NRCs
 *  \details     The checks done against the service table can be mapped to NRCs here. This function can be
 *               used as default NRC handler for services without sub-table entry.
 *  \param[in]   serviceErrorMask Error bit mask of table check
 *  \return      kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static tFblResult FblDiagProcessServiceNrc(vuint32 serviceErrorMask)
{
   tFblResult result;

   /* Initialize variables */
   result = kFblOk;

   /* Check if service should be supported functionally and drop support if not */
   if ((serviceErrorMask & kFblDiagServiceNoFuncSupport) != 0u)
   {
      DiagSetNoResponse();
   }
   else
   {
      /* Service supported in active session? */
      if ((serviceErrorMask & kFblDiagServiceSessionFailure) == kFblDiagServiceSessionFailure)
      {
         DiagNRCServiceNotSupportedInActiveSession();
      }
      /* Check for security access */
      else if ((serviceErrorMask & kFblDiagServiceSecAccessFailure) == kFblDiagServiceSecAccessFailure)
      {
         DiagNRCSecurityAccessDenied();
      }
      /* Minimum length check on service level */
      else if ((serviceErrorMask & kFblDiagServiceMinLenFailure) == kFblDiagServiceMinLenFailure)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
      }
      /* Pending length checks */
      else if ((serviceErrorMask & kFblDiagServiceLenFailure) == kFblDiagServiceLenFailure)
      {
         /* Set default NRC if no NRC has been set in callout function. */
         if (DiagGetError() == kDiagErrorNone)
         {
            DiagNRCIncorrectMessageLengthOrInvalidFormat();
         }
      }
      else if ((serviceErrorMask & kFblDiagServicePrehandlerFailure) == kFblDiagServicePrehandlerFailure)
      {
         /* Set default NRC if no NRC has been set in callout function. */
         if (DiagGetError() == kDiagErrorNone)
         {
            DiagNRCConditionsNotCorrect();
         }
      }
      /* Remaining, uncovered errors */
      else
      {
         DiagNRCGeneralReject();
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagProcessSubfunctionNrc
 **********************************************************************************************************************/
/*! \brief       This routine maps service check errors to NRCs
 *  \details     The checks done against the service table can be mapped to NRCs here. This function can be
 *               used as default NRC handler for services with sub-functions.
 *  \param[in]   serviceErrorMask Error bit mask of table check
 *  \return      kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
static tFblResult FblDiagProcessSubfunctionNrc(vuint32 serviceErrorMask)
{
   tFblResult result;

   /* Initialize variables */
   result = kFblOk;

   /* Check if service should be supported functionally and drop support if not */
   if ((serviceErrorMask & (kFblDiagServiceNoFuncSupport | kFblDiagSubNoFuncSupport)) != 0u)
   {
      DiagSetNoResponse();
   }
   else
   {
      /* Service supported in active session? */
      if ((serviceErrorMask & kFblDiagServiceSessionFailure) == kFblDiagServiceSessionFailure)
      {
         DiagNRCServiceNotSupportedInActiveSession();
      }
      /* Minimum length check on service level */
      else if ((serviceErrorMask & kFblDiagServiceMinLenFailure) == kFblDiagServiceMinLenFailure)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
      }
      /* Check if sub-function is supported */
      else if ((serviceErrorMask & kFblDiagSubfunctionNotFound) == kFblDiagSubfunctionNotFound)
      {
#if defined( FBL_ENABLE_USERSUBFUNCTION )
         /* Subfunction not found in check
          * Call user handler to manage its own subfunction */
         FblDiagSetRcrRpAllowed();
         ApplDiagUserSubFunction(&DiagBuffer[kDiagFmtSubparam], DiagDataLength);
#else
         DiagNRCSubFunctionNotSupported();
#endif /* FBL_ENABLE_USERSUBFUNCTION */
      }
      /* Check if sub-parameter is supported */
      else if ((serviceErrorMask & kFblDiagSubparamNotFound) == kFblDiagSubparamNotFound)
      {
         DiagNRCRequestOutOfRange();
      }
      /* Check for security access (service level and sub-function level) */
      else if ((serviceErrorMask & (kFblDiagServiceSecAccessFailure | kFblDiagSubfuncSecAccessFailure | kFblDiagSubparamSecAccessFailure)) != 0u)
      {
         DiagNRCSecurityAccessDenied();
      }
      /* Pending length checks */
      else if ((serviceErrorMask & (kFblDiagServiceLenFailure | kFblDiagSubMinLenFailure | kFblDiagSubLenFailure)) != 0u)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
      }
      /* Subfunction session check */
      else if ((serviceErrorMask & (kFblDiagSubfuncSessionFailure | kFblDiagSubparamSessionFailure)) != 0u)
      {
         DiagNRCSubfunctionNotSupportedInActiveSession();
      }
      else if ((serviceErrorMask & kFblDiagServicePrehandlerFailure) == kFblDiagServicePrehandlerFailure)
      {
         /* Set default NRC if no NRC has been set in callout function. */
         if (DiagGetError() == kDiagErrorNone)
         {
            DiagNRCConditionsNotCorrect();
         }
      }
      /* Remaining, uncovered errors */
      else
      {
         DiagNRCGeneralReject();
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagProcessRoutineNrc
 **********************************************************************************************************************/
/*! \brief       This routine maps service check errors to NRCs
 *  \details     The checks done against the service table can be mapped to NRCs here. This function can
 *               be used as a NRC hanler for the routine control service.
 *  \param[in]   serviceErrorMask Error bit mask of table check
 *  \return      kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
static tFblResult FblDiagProcessRoutineNrc(vuint32 serviceErrorMask)
{
   tFblResult result;

   /* Initialize variables */
   result = kFblOk;

   /* Check if service should be supported functionally and drop support if not */
   if ((serviceErrorMask & (kFblDiagServiceNoFuncSupport | kFblDiagSubNoFuncSupport)) != 0u)
   {
      DiagSetNoResponse();
   }
   else
   {
      /* Service supported in active session? */
      if ((serviceErrorMask & kFblDiagServiceSessionFailure) == kFblDiagServiceSessionFailure)
      {
         DiagNRCServiceNotSupportedInActiveSession();
      }
      /* Minimum length check on service level */
      else if ((serviceErrorMask & kFblDiagServiceMinLenFailure) == kFblDiagServiceMinLenFailure)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
      }
      /* Check if sub-parameter is supported and supported in active session */
      else if ((serviceErrorMask & (kFblDiagSubparamNotFound | kFblDiagSubparamSessionFailure)) != 0u)
      {
#if defined( FBL_ENABLE_USERROUTINE )
         /* Subfunction not found in check
          * Call user handler to manage its own subfunction */
         FblDiagSetRcrRpAllowed();
         ApplDiagUserRoutine(&DiagBuffer[kDiagFmtSubparam], DiagDataLength);
#else
         DiagNRCRequestOutOfRange();
#endif /* FBL_ENABLE_USERSUBFUNCTION */
      }
      /* Check for security access (service level and sub-function level) */
      else if ((serviceErrorMask & (kFblDiagServiceSecAccessFailure | kFblDiagSubfuncSecAccessFailure | kFblDiagSubparamSecAccessFailure)) != 0u)
      {
         DiagNRCSecurityAccessDenied();
      }
      /* Check if sub-function is supported */
      else if ((serviceErrorMask & (kFblDiagSubfunctionNotFound | kFblDiagSubTableNotFound)) != 0u)
      {
#if defined( FBL_ENABLE_USERSUBFUNCTION )
         /* Subfunction not found in check
          * Call user handler to manage its own subfunction */
         FblDiagSetRcrRpAllowed();
         ApplDiagUserSubFunction(&DiagBuffer[kDiagFmtSubparam], DiagDataLength);
#else
         DiagNRCSubFunctionNotSupported();
#endif /* FBL_ENABLE_USERSUBFUNCTION */
      }
      /* Pending length checks */
      else if ((serviceErrorMask & (kFblDiagServiceLenFailure | kFblDiagSubMinLenFailure | kFblDiagSubLenFailure)) != 0u)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
      }
      /* Subfunction session check */
      else if ((serviceErrorMask & (kFblDiagSubfuncSessionFailure | kFblDiagSubparamSessionFailure)) != 0u)
      {
         DiagNRCSubfunctionNotSupportedInActiveSession();
      }
      else if ((serviceErrorMask & kFblDiagServicePrehandlerFailure) == kFblDiagServicePrehandlerFailure)
      {
         /* Set default NRC if no NRC has been set in callout function. */
         if (DiagGetError() == kDiagErrorNone)
         {
            DiagNRCConditionsNotCorrect();
         }
      }
      /* Remaining, uncovered errors */
      else
      {
         DiagNRCGeneralReject();
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagProcessSecurityAccessNrc
 **********************************************************************************************************************/
/*! \brief       This routine maps service check errors to NRCs (SPEC-16324910)
 *  \details     The checks done against the service table can be mapped to NRCs here. This function can
 *               be used as a NRC handler for the routine control service.
 *  \param[in]   serviceErrorMask Error bit mask of table check
 *  \return      kFblOk/kFblFailed
 **********************************************************************************************************************/
static tFblResult FblDiagProcessSecurityAccessNrc(vuint32 serviceErrorMask)
{
   tFblResult result;

   result = FblDiagProcessSubfunctionNrc(serviceErrorMask);

   if (DiagGetError() != kDiagErrorNone)
   {
      /* New seed must be requested */
      FblDiagClrSecurityKeyAllowed();
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagNoneLengthCheck
 **********************************************************************************************************************/
/*! \brief         Lenght check function with actually no check implementation.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Length of data (without SID).
 *  \return        kFblOk: Length check OK;
 **********************************************************************************************************************/
static tFblResult FblDiagNoneLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   /* Nothing to do here. Length check should be done in corresponding user callback function. */
   return kFblOk;
}

/***********************************************************************************************************************
 *  Diagnostic main handler service functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblDiagDefaultSessionMainHandler
 **********************************************************************************************************************/
/*! \brief         Default session request service handler.
 *  \param[in,out] pbDiagData Pointer to data in diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Data length (without SID).
 *  \return        Result: Always kFblOk.
 **********************************************************************************************************************/
static tFblResult FblDiagDefaultSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
   vuint8 responseFlag;
#endif /* FBL_ENABLE_REPONSE_AFTER_RESET */

   /* Request bootloader reset */
   FblDiagSetWaitEcuReset();

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
   /* Send response pending before reset */
   DiagExRCRResponsePending(kForceSendResponsePending);

   /* Set flag for response after reset */
   responseFlag = RESET_RESPONSE_SDS_REQUIRED;
   (void)ApplFblWriteResetResponseFlag(&responseFlag);   /* PRQA S 3425 */ /* MD_FblDiag_3425 */
   /* Save target address */
   if (FblCwSaveResponseAddress() != kFblOk) /* PRQA S 3325 */ /* MD_MSR_Unreachable */
   {  /* PRQA S 3201 */ /* MD_MSR_Unreachable */
      /* If clause is necessary here to process return value or macro. However,
       * there is currently no strategy to handle this error. */
   }
#else
   /* Prepare response and reset states */
   FblDiagSessionControlParamInit(pbDiagData, diagReqDataLen);
   /* Send response */
   DiagProcessingDone(kDiagRslDiagnosticSessionControl);
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */
   FblDiagSetEcuResetFctFinished();

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagExtendedSessionMainHandler
 **********************************************************************************************************************/
/*! \brief         Extended session request service handler.
 *  \param[in,out] pbDiagData Pointer to data in diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Data length (without SID).
 *  \return        Result: Always kFblOk.
 **********************************************************************************************************************/
static tFblResult FblDiagExtendedSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   /* Change to extended session */
   FblDiagSetExtendedSession();

   /* Prepare response and reset states */
   FblDiagSessionControlParamInit(pbDiagData, diagReqDataLen);
   /* Send response */
   DiagProcessingDone(kDiagRslDiagnosticSessionControl);

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagProgrammingSessionMainHandler
 **********************************************************************************************************************/
/*! \brief         Programming session request service handler.
 *  \param[in,out] pbDiagData Pointer to data in diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Data length (without SID).
 *  \return        Result: kFblOk if reprogramming conditions are fulfilled, kFblFailed if not.
 **********************************************************************************************************************/
static tFblResult FblDiagProgrammingSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

   /* Check of programming preconditions done? */
#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
   if ((!FblDiagGetPreconditionsChecked()) && (!FblMainGetStartFromAppl()))
#else
   if (ApplFblCheckProgConditions() != kFblOk)
#endif /* FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS */
   {
      /* Check of programming preconditions failed */
      FblErrStatSetError(FBL_ERR_FLASH_PROG_CONDITIONS);
      DiagNRCConditionsNotCorrect();
      result = kFblFailed;
   }
   else
   {
      /* Check of programming preconditions succeeded - switch to programming session */
      /* Change to programming session */
      FblDiagSetProgrammingSession();

      /* Prepare response and reset states */
      FblDiagSessionControlParamInit(pbDiagData, diagReqDataLen);
      /* Send response */
      DiagProcessingDone(kDiagRslDiagnosticSessionControl);
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagEcuResetMainHandler
 **********************************************************************************************************************/
/*! \brief         Function manages the EcuReset service request
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        Result: Always kFblOk.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagEcuResetMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
   vuint8 responseFlag;
#endif /* FBL_ENABLE_REPONSE_AFTER_RESET */

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
   (void)pbDiagData;
#endif

   /* Request bootloader reset */
   FblDiagSetWaitEcuReset();

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
   /* Send response pending before reset */
   DiagExRCRResponsePending(kForceSendResponsePending);

   /* Set flag for response after reset */
   responseFlag = RESET_RESPONSE_ECURESET_REQUIRED;
   (void)ApplFblWriteResetResponseFlag(&responseFlag);   /* PRQA S 3425 */ /* MD_FblDiag_3425 */
   /* Save target address */
   if (FblCwSaveResponseAddress() != kFblOk) /* PRQA S 3325 */ /* MD_MSR_Unreachable */
   {  /* PRQA S 3201 */ /* MD_MSR_Unreachable */
      /* If clause is necessary here to process return value or macro. However,
       * there is currently no strategy to handle this error. */
   }
#else
   /* Send response */
   DiagProcessingDone(kDiagRslEcuReset);
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */
   FblDiagSetEcuResetFctFinished();

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagSecurityAccessLengthCheck
 **********************************************************************************************************************/
/*! \brief         Lenght check function for Security Access service.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Length of data (without SID).
 *  \return        kFblOk: Length check OK; kFblFailed: Length check failed
 **********************************************************************************************************************/
static tFblResult FblDiagSecurityAccessLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
   vuint8 result;

   /* Initialize return value */
   result = kFblOk;

   if (pbDiagData[0] == kFblDiagSubSendKey)
   {
      if (diagReqDataLen != kDiagRqlSecurityAccessKey)
      {
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
         /* If a security key is expected but the request length is not correct, set delay flag    *
          * in NV-memory but do not activate delay timer.                                          */
         if (FblDiagGetSecurityKeyAllowed())
         {
            /* New seed must be requested */
            FblDiagClrSecurityKeyAllowed();

            /* Send response pending for following NV-access */
            DiagExRCRResponsePending(kForceSendRpIfNotInProgress);

            /* Read invalid access counter */
            if (ApplFblReadSecAccessInvalidCount(&secSendKeyInvalid) != kFblOk)
            {
               /* If read failed set default value */
               secSendKeyInvalid = (kSecMaxInvalidKeys - 1u);
            }

            /* Increment counter, avoid overrun */
            if (secSendKeyInvalid < kSecMaxInvalidKeys)
            {
               secSendKeyInvalid++;
               (void)ApplFblWriteSecAccessInvalidCount(&secSendKeyInvalid);
            }

            if (secSendKeyInvalid >= kSecMaxInvalidKeys)
            {
               /* Too many invalid security attempts, enable security access delay */
               SetSecurityAccessDelay();
               (void)ApplFblSetSecAccessDelayFlag();
            }
         }
#endif
         /* Send NRC 0x13 - incorrectMessageLength */
         result = kFblFailed;
      }
   }
   return result;
}

#if defined( FBL_DIAG_ENABLE_SECACCESS_STANDARD )
/***********************************************************************************************************************
 *  FblDiagSecAccessSeedMainHandler
 **********************************************************************************************************************/
/*! \brief         Request Seed request main handler.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagSecAccessSeedMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
# endif

   /* Initialize variables */
   result = kFblOk;

# if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
   /* Check if security level is locked (delay counter is active) */
   if (GetSecurityAccessDelay() > 0u)
   {
      DiagNRCRequiredTimeDelayNotExpired();
      result = kFblFailed;
   }
# endif /* FBL_ENABLE_SEC_ACCESS_DELAY */

   if (result == kFblOk)
   {
      /* Check if security level is already active */
      if (FblDiagGetSecurityUnlock())
      {
         vuintx i;

         /* ECU is already unlocked, send zero seed */
         for (i = 0; i < kSecSeedLength; i++)
         {
            pbDiagData[kDiagLocFmtSeedKeyStart + i] = 0x00u;
         }
      }
      else
      {
         /* Generate seed by application function */
         if (ApplFblSecuritySeed() == kFblOk)
         {
            /* Accept security key next */
            FblDiagSetSecurityKeyAllowed();
         }
         else
         {
            /* Error occurred during seed computation */
            FblErrStatSetError(FBL_ERR_SEED_GENERATION_FAILED);
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }
      }
   }

   /* Send positive response if seed was computed correctly */
   if (result == kFblOk)
   {
      /* Start a local timer for seed validity */
      seedTimeoutCounter = FBL_DIAG_SEED_TIMEOUT_COUNTER;
      DiagProcessingDone(kDiagRslSecurityAccessSeed);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagSecAccessKeyMainHandler
 **********************************************************************************************************************/
/*! \brief         Send Key request main handler.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagSecAccessKeyMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
   (void)pbDiagData;
# endif

   /* Check preconditions for key processing */
   if (    (!FblDiagGetSecurityKeyAllowed())
# if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
        || (GetSecurityAccessDelay() > 0u)
# endif /* FBL_EANBLE_SECURITY_ACCESS_DELAY */
        || (seedTimeoutCounter == 0u)
      )
   {
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   else
   {
      /* Send response pending */
      DiagExRCRResponsePending(kForceSendResponsePending);

      /* No second key allowed for this seed */
      FblDiagClrSecurityKeyAllowed();

      /* Check security access key in application function */
      if (ApplFblSecurityKey() == kFblOk)
      {
         /* Security access successful */
         FblDiagSetSecurityUnlock();
         result = kFblOk;
# if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
         /* Reset invalid counter */
         secSendKeyInvalid = 0u;
         /* Reset flags in non-volatile memory */
         (void)ApplFblClrSecAccessDelayFlag();
         (void)ApplFblWriteSecAccessInvalidCount(&secSendKeyInvalid);
# endif /* FBL_ENABLE_SEC_ACCESS_DELAY */
      }
      else
      {
         result = kFblFailed;
# if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
         /* Read invalid access counter */
         if (ApplFblReadSecAccessInvalidCount(&secSendKeyInvalid) != kFblOk)
         {
            /* If read failed set default value */
            secSendKeyInvalid = (kSecMaxInvalidKeys - 1u);
         }

         secSendKeyInvalid++;

         if (secSendKeyInvalid >= kSecMaxInvalidKeys)
         {
            /* Too many invalid security attempts, enable security access delay */
            SetSecurityAccessDelay();
            (void)ApplFblSetSecAccessDelayFlag();

            DiagNRCExceedNumberOfAttempts();
         }
         else
         {
            /* Write counter to non-volatile memory */
            (void)ApplFblWriteSecAccessInvalidCount(&secSendKeyInvalid);

            DiagNRCInvalidKey();
         }
# else
         DiagNRCInvalidKey();
# endif /* FBL_ENABLE_SEC_ACCESS_DELAY */
      }
   }

   if (result == kFblOk)
   {
      DiagProcessingDone(kDiagRslSecurityAccessKey);
   }

   return result;
}
#elif defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
/***********************************************************************************************************************
 *  FblDiagSecAccessRequestChallengeMainHandler
 **********************************************************************************************************************/
/*! \brief         Request Seed request main handler for authenticated reprogramming.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static tFblResult FblDiagSecAccessRequestChallengeMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

   /* Initialize variables */
   result = kFblOk;

# if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
   /* Check if security level is locked (delay counter is active) */
   if (GetSecurityAccessDelay() > 0u)
   {
      DiagNRCRequiredTimeDelayNotExpired();
      result = kFblFailed;
   }
# endif /* FBL_ENABLE_SEC_ACCESS_DELAY */

   if (result == kFblOk)
   {
      /* Check request length */
      if (diagReqDataLen != (kDiagRqlSecurityAccessReqChallenge + kDiagRqlSecurityAccessReqChallengeParameter))
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
         result = kFblFailed;
      }
      else
      {
         /* Send response pending */
         DiagExRCRResponsePending(kForceSendResponsePending);

         result = ApplFblSecAccessRequestChallenge(pbDiagData, diagReqDataLen);

         if (result == kFblFailed)
         {
            /* Check if callback function has set an NRC */
            if (DiagGetError() == kDiagErrorNone)
            {
               /* Callback function indicated an error but did not set an NRC, use 0x35 InvalidKey as fallback */
               DiagNRCInvalidKey();
            }
            if (DiagGetError() == kDiagNrcInvalidKey)
            {
               /* Enable Security Access Delay */
               vuint8 invalidCount;

               /* Get Number of previously failed attempts */
               if (ApplFblReadSecAccessInvalidCount(&invalidCount) != kFblOk)
               {
                  invalidCount = kDiagMaxFailedAttempts;
               }

               /* Avoid overflow of either failure counter or delay time calculation */
               if (invalidCount < kDiagMaxFailedAttempts)
               {
                  invalidCount++;
               }

               (void)ApplFblWriteSecAccessInvalidCount(&invalidCount);

               /* Calculate delay timer */
               secSecurityAccessDelay = FBL_SEC_DELAY_TIMEOUT(invalidCount);
               ApplFblSetSecAccessDelayFlag();
            }
         }
      }
   }

   /* Send positive response if seed was computed correctly */
   if (result == kFblOk)
   {
      FblDiagSetSecurityKeyAllowed();
      DiagProcessingDone(kDiagRslSecurityAccessReqChallenge);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagSecAccessSendSignedChallengeMainHandler
 **********************************************************************************************************************/
/*! \brief         Send Key request main handler.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
static tFblResult FblDiagSecAccessSendSignedChallengeMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

   /* Initialize variables */
   result = kFblOk;

# if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
   /* Check if security level is locked (delay counter is active) */
   if (GetSecurityAccessDelay() > 0u)
   {
      DiagNRCRequiredTimeDelayNotExpired();
      result = kFblFailed;
   }
# endif /* FBL_ENABLE_SEC_ACCESS_DELAY */

   if (result == kFblOk)
   {
      if (!FblDiagGetSecurityKeyAllowed())
      {
         DiagNRCRequestSequenceError();
         result = kFblFailed;
      }
   }

   if (result == kFblOk)
   {
      if (diagReqDataLen != (kDiagRqlSecurityAccessSendSignedChallenge + kDiagRqlSecurityAccessSendSignedChallengeParameter))
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
         result = kFblFailed;
      }
      else
      {
         /* Send response pending */
         DiagExRCRResponsePending(kForceSendResponsePending);

         result = ApplFblSecAccessSendSignedChallenge(pbDiagData, diagReqDataLen);
         if (result == kFblFailed)
         {
            /* Check if callback function has set an NRC */
            if (DiagGetError() == kDiagErrorNone)
            {
               /* Callback function indicated an error but did not set an NRC, use 0x35 InvalidKey as fallback */
               DiagNRCInvalidKey();
            }
            if (DiagGetError() == kDiagNrcInvalidKey)
            {
               /* Enable Security Access Delay */
               vuint8 invalidCount;

               /* Get Number of previously failed attempts */
               if (ApplFblReadSecAccessInvalidCount(&invalidCount) != kFblOk)
               {
                  invalidCount = kDiagMaxFailedAttempts;
               }

               /* Avoid overflow of either failure counter or delay time calculation */
               if (invalidCount < kDiagMaxFailedAttempts)
               {
                  invalidCount++;
               }

               (void)ApplFblWriteSecAccessInvalidCount(&invalidCount);

               /* Calculate delay timer */
               secSecurityAccessDelay = FBL_SEC_DELAY_TIMEOUT(invalidCount);
               ApplFblSetSecAccessDelayFlag();
            }
         }
      }
   }

   if (result == kFblOk)
   {
      /* Reset security access delay */
      vuint8 invalidCount = 0u;

      ApplFblClrSecAccessDelayFlag();
      (void)ApplFblWriteSecAccessInvalidCount(&invalidCount);

      FblDiagClrSecurityKeyAllowed();
      DiagProcessingDone(kDiagRslSecurityAccessSendSignedChallenge);
   }

   return result;
}
#endif /* FBL_DIAG_ENABLE_SECACCESS_* */

/***********************************************************************************************************************
 *  FblDiagCommCtrlMainHandler
 **********************************************************************************************************************/
/*! \brief         Communication Control request main handler.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagCommCtrlMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   /* Check communication type (Bits 1-7 must be 0) */
   if (pbDiagData[kDiagLocFmtSubparam + 0x01u] != kDiagSubNormalCommunication)
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   else
   {
      /* Simply transmit a positive response message with subfunction parameter */
      DiagProcessingDone(kDiagRslCommunicationControl);
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagDataByIdLengthCheck
 **********************************************************************************************************************/
/*! \brief         Read/WriteDataByIdentifier service dynamic length check.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Length of data (without SID).
 *  \return        kFblOk: Length check OK; kFblFailed: Length check failed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagDataByIdLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   /* Nothing to do here. Length check should be done in corresponding user callback function. */
   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagWriteDataByIdMainHandler
 **********************************************************************************************************************/
/*! \brief         WriteDataByIdentifier service, handling of fingerprint and identification data.
 *  \pre           Request only accepted after successful security access procedure.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Length of data (without SID).
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 6050, 6080 1 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
static tFblResult FblDiagWriteDataByIdMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;
   vuint16 dataIdentifier;
   tFblLbtBlockIndex curBlockIndex;
   tFblLbtBlockType curBlockType;
   tBlockDescriptor tempBlockDescriptor;

   curBlockType = kBlockTypeNone;

   dataIdentifier = ((vuint16)((vuint16)pbDiagData[kDiagLocFmtDataIdHigh] << 8u)) | ((vuint16)pbDiagData[kDiagLocFmtDataIdLow]);
   if (     (dataIdentifier != kFblDiagDidBootSwFingerprintWrite)
      &&    (dataIdentifier != kFblDiagDidApplSwFingerprintWrite)
      &&    (dataIdentifier != kFblDiagDidApplDataFingerprintWrite))
   {
      /* Call user callout function for non-fingerprint DIDs */
      result = ApplFblWriteDataByIdentifier(pbDiagData, diagReqDataLen);
   }
   else
   {
      result = FblDiagCheckWriteFingerprintPreconditions(pbDiagData, diagReqDataLen, dataIdentifier, &curBlockType, &curBlockIndex);

      if (result == kFblOk)
      {
         result = FblLbtGetBlockDescriptorByIndex(curBlockIndex, &tempBlockDescriptor);

         if ((result == kFblOk) && (tempBlockDescriptor.blockType == curBlockType))
         {
            /* Initialize error status block number */
            FblErrStatSetBlockNr(tempBlockDescriptor.blockNr);

            result = FblDiagCheckProgAttemptCounter(&tempBlockDescriptor);
            if (result == kFblOk)
            {
               /* Initialize blockdescriptor and index with currently active logical block*/
               downloadBlockDescriptor = tempBlockDescriptor;
#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
               downloadBlockIndex = curBlockIndex;
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */
               /* Store fingerprint */
               if (curBlockType == kBlockTypeBoot)
               {
                  result = ApplFblStoreBootFingerprint(&downloadBlockDescriptor, &pbDiagData[kDiagLocFmtDataRecord + 1u]);
               }
               else
               {
                  result = ApplFblStoreFingerprint(&pbDiagData[kDiagLocFmtDataRecord + 1u]);
               }
            }
            else
            {
               /* Reached maximum number of programming attempts - reject programming attempt with NRC 0x72 (RQMT5-111)*/
               DiagNRCGeneralProgrammingFailure();
            }
         }
         else
         {
            /* Unsupported logical block type or index */
            DiagNRCRequestOutOfRange();
            result = kFblFailed;
         }
      }

      /* Init block descriptor */
      if (result == kFblOk)
      {
         /* Fingerprint accepted */
         FblDiagSetFingerprintValid();
      }
   }

   if (DiagGetError() != kDiagErrorNone)
   {
      /* NRC already set - do nothing */
      result = kFblFailed;
   }
   else
   {
      /* Send positive response */
      DiagProcessingDone(kDiagRslWriteDataByIdentifier);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagRCStartBootBlockHash - StartRoutine-CalcChecsum
 **********************************************************************************************************************/
/*! \brief       Run the hash calculation prior to the flash download.
 *  \param[in]   pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]   diagReqDataLen Length of data (without SID)
 *  \return      kFblOk:     service processed successfully (goto next state)
 *               kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartBootBlockHashMainHandler (vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* parameter not used */
   (void)diagReqDataLen;
#endif

   return FblDiagCommonBlockHashMainHandler(kBlockTypeBoot, pbDiagData);
}

/***********************************************************************************************************************
 *  FblDiagRCStartApplBlockHashMainHandler
 **********************************************************************************************************************/
/*! \brief       Run the hash calculation prior to the flash download.
 *  \param[in]   pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]   diagReqDataLen Length of data (without SID)
 *  \return      kFblOk:     service processed successfully (goto next state)
 *               kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartApplBlockHashMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* parameter not used */
   (void)diagReqDataLen;
#endif

   return FblDiagCommonBlockHashMainHandler(kBlockTypeCode, pbDiagData);
}

/***********************************************************************************************************************
 *  FblDiagRCStartDataBlockHashMainHandler
 **********************************************************************************************************************/
/*! \brief       Run the hash calculation prior to the flash download.
 *  \param[in]   pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]   diagReqDataLen Length of data (without SID)
 *  \return      kFblOk:     service processed successfully (goto next state)
 *               kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartDataBlockHashMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameter not used */
   (void)diagReqDataLen;
#endif

   return FblDiagCommonBlockHashMainHandler(kBlockTypeData, pbDiagData);
}

#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
/***********************************************************************************************************************
 *  FblDiagRCStartCheckProgPreCondMainHandler
 **********************************************************************************************************************/
/*! \brief         Check Programming Preconditions service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartCheckProgPreCondMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
   (void)diagReqDataLen;
# endif

   /* Clear status variables */
   FblDiagClrFingerprintValid();

   /* Check for preconditions - response should be prepared in callback function */
   if (ApplFblCheckProgPreconditions(pbDiagData, diagReqDataLen) == kFblOk)
   {
      FblDiagSetPreconditionsChecked();
   }
   else
   {
      FblDiagClrPreconditionsChecked();
   }

   /* DiagProcessingDone is called from callback function */
   return kFblOk;
}
#endif /* FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS */


/***********************************************************************************************************************
 *  FblDiagRCStartCheckProgramMainHandler
 **********************************************************************************************************************/
/*! \brief         Routine Control - Check Program.
 *  \pre           Data to be checked has been downloaded to the corresponding memory.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
static tFblResult FblDiagRCStartCheckProgramMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblDiagNrc serviceNrc;
   vuint8 checkResult;
   tFblResult result;
   vuint8 *localPbDiagData = pbDiagData;
#if (kSecLengthInfo != 0u)
   vuint32 reqLengthInfo;
#endif

   /* Initialize variables */
   serviceNrc = kDiagErrorNone;
   checkResult = kDiagCheckVerificationGeneralFailure;

   /* Check state flags */
   if (    (!FblDiagGetFingerprintValid())
        || (!FblDiagGetTransferDataSucceeded())
        || (!FblDiagGetChecksumAllowed())
      )
   {
      /* Invalid sequence - send NRC 0x24 */
      serviceNrc = kDiagNrcRequestSequenceError;
   }

   /*
    * IF the length information field in the diag request is available, check if number
    * of CRC / signature bytes is correct
    */
#if (kSecLengthInfo != 0u)
   if (serviceNrc == kDiagErrorNone)
   {
# if ((SEC_SECURITY_CLASS == SEC_CLASS_DDD) || \
      (SEC_SECURITY_CLASS == SEC_CLASS_CCC))
      reqLengthInfo = (((vuint32)localPbDiagData[kDiagLocFmtRoutineStatus]) << 8u) | (vuint32)localPbDiagData[kDiagLocFmtRoutineStatus + 1u];
#  if ( SEC_SECURITY_CLASS == SEC_CLASS_DDD )
      if (reqLengthInfo != kSecCRCLength)
#  endif
#  if ( SEC_SECURITY_CLASS == SEC_CLASS_CCC )
      if (reqLengthInfo != kSecSigLength)
#  endif
# endif
      {
         serviceNrc = kDiagNrcRequestOutOfRange;
      }
   }
#endif /* kSecLengthInfo != 0u */
   if (serviceNrc == kDiagErrorNone)
   {
      /* Invoke LibMem block end indication */
      serviceNrc = FblMemRemapStatus(FblMemBlockEndIndication());
   }

   if (serviceNrc == kDiagErrorNone)
   {
      /* Watchdog and response pending handling */
      (void)FblRealTimeSupport();

      /* Do verification */
#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT )
      (void)SecM_InitVerification(V_NULL);
#endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT */
      checkResult = FblDiagDownloadCheck(localPbDiagData, diagReqDataLen);

      /* Reinit FblLib_Mem to make sure status variables are set correctly */
      (void)FblMemInit();
      localPbDiagData = FblDiagMemGetActiveBuffer();
#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT )
      (void)SecM_DeinitVerification(V_NULL);
#endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT */
   }
   else
   {
      /* Prepare NRC possibly set before */
      FblDiagSetError(serviceNrc);
   }

   if (DiagGetError() != kDiagErrorNone)
   {
      /* NRC already set - do nothing */
      result = kFblFailed;
   }
   else
   {
      /* No NRC set - submit positive response */
      localPbDiagData[kDiagLocFmtRoutineStatus] = checkResult;
      DiagProcessingDone(kDiagRslRoutineControlCheckRoutine);
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagRCStartEraseMainHandler
 **********************************************************************************************************************/
/*! \brief         Routine Control - Erase Memory.
 *  \pre           Fingerprint is available, memory driver initialized.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF  */
static tFblResult FblDiagRCStartEraseMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblAddress memoryAddress;
   tFblLength memorySize;

   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   /* Verify all erase preconditions are fulfilled */
   result = FblDiagCheckErasePreconditions(pbDiagData, &memoryAddress, &memorySize);

   if (result == kFblOk)
   {
      /* Send response pending in case of long NV accesses */
      DiagExRCRResponsePending(kForceSendResponsePending);

   }

   if (result == kFblOk)
   {
#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
      /* Renew the downloadBlockDescriptor that may have been overwritten by the flash driver download */
      result = FblLbtGetBlockDescriptorByIndex(downloadBlockIndex, &downloadBlockDescriptor);

      if (result == kFblFailed)
      {
         /* Getting Blockdescriptor by previous stored downloadBlockIndex fails */
         DiagNRCConditionsNotCorrect();
      }
      else
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */
      {
         /* Invalidate logical block to be erased */
         if (ApplFblInvalidateBlock(downloadBlockDescriptor) != kFblOk)
         {
            /* Block could not be invalidated or programming attempt counter could not be stored */
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }
      }
   }

   if (result == kFblOk)
   {
      (void)FblRealTimeSupport();

#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
      /* Determine the flash memory status               *
       * Programming attempt counter increment only if   *
       * flash is not erased.                            */
      erasedStatus = FblDiagGetEraseState();

      if (erasedStatus == kFlashNotErased)
#endif
      {
         /* Increase programming attempt counter */
         if (ApplFblIncProgAttempts(downloadBlockDescriptor) != kFblOk)
         {
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }
      }
   }

   if (result == kFblOk)
   {
      result = FblDiagEraseBlock(&downloadBlockDescriptor);
      if (result == kFblOk)
      {
         /* Update Programming Status */
         (void)ApplFblProgStatusEraseUpdate(kDiagProgStatEraseSucceeded);

         FblDiagSetLastErasedBlock(downloadBlockDescriptor.blockNr);

         /* Send positive response */
         DiagProcessingDone(kDiagRslRoutineControlEraseRoutine);
      }
      else
      {
         /* Update Programming Status */
         (void)ApplFblProgStatusEraseUpdate(kDiagProgStatEraseFailed_General);

         /* Send negative response */
         DiagNRCGeneralProgrammingFailure();
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagRCStartCheckProgDepMainHandler
 **********************************************************************************************************************/
/*! \brief         Check program dependencies
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartCheckProgDepMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;
   vuint8 dependencyStatus;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   result = kFblFailed;
   if (!FblDiagGetLogBlockHashRequested() && !FblDiagGetFingerprintValid())
   {
      DiagNRCRequestSequenceError();
   }
   else
   {

      /* Call function to check programming dependencies */
      dependencyStatus = ApplFblCheckProgDependencies();

      /* Preset RoutineStatus for response */
      pbDiagData[kDiagLocFmtRoutineStatus] = kDiagCheckCompatibilityOk;

      if (dependencyStatus == kDiagCheckCompatibilityOk )
      {
         /* Set application valid flag */
         result = ApplFblValidateApp();
      }

      if (result == kFblOk)
      {
         DiagProcessingDone(kDiagRslRoutineControlCheckRoutine);
      }
      else
      {
         if (DiagGetError() == kDiagErrorNone)
         {
            DiagNRCGeneralProgrammingFailure();
         }
      }
   }
   return result;
}

/***********************************************************************************************************************
 *  FblDiagRequestDownloadLengthCheck
 **********************************************************************************************************************/
/*! \brief         Request download length check
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: Length of check request is OK; kFblFailed: Length check failed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagRequestDownloadLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

   vuint8 addrFormat;
   vuint8 lengthFormat;
   vuint8 dataFormat;

   /* Intialize result */
   result = kFblFailed;

   /* Get length and address format from message */
   lengthFormat = (vuint8)((pbDiagData[kDiagLocFmtFormatOffset] & 0xF0u) >> 4u);
   addrFormat   = (vuint8)(pbDiagData[kDiagLocFmtFormatOffset] & 0x0Fu);

   /* Read compression and encryption method */
   dataFormat = (tFblMemDfi)pbDiagData[kDiagLocFmtSubparam];

#if defined( FBL_ENABLE_DATA_PROCESSING )
# if defined( FBL_ENABLE_ENCRYPTION_MODE )
# else
   /* No encrypted data supported */
   if (FblDiagGetEncryptionMode(dataFormat) != kDiagSubNoEncryption)
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
# endif /* FBL_ENABLE_ENCRYPTION_MODE */
# if defined( FBL_ENABLE_COMPRESSION_MODE )
# else
   /* No compressed data supported */
   if (FblDiagGetCompressionMode(dataFormat) != kDiagSubNoCompression)
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
# endif /* FBL_ENABLE_COMPRESSION_MODE */
#else
   if (dataFormat != kDiagSubNoDataProcessing)
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
#endif /* FBL_ENABLE_DATA_PROCESSING */

   if (DiagGetError() == kDiagErrorNone)
   {
      if ((addrFormat != kFblDiagAddrFormat) || (lengthFormat != kFblDiagLengthFormat))   /* Check length of request against calculated length */
      {
         DiagNRCRequestOutOfRange();
         result = kFblFailed;
      }
      /* Subtract 2 bytes as the definition kDiagRqlRequestDownload already contains 1 byte minimum length for address and length */
      else if (diagReqDataLen != ((vuint16)kDiagRqlRequestDownload - 2u + (vuint16)lengthFormat + (vuint16)addrFormat))
      {
         result = kFblFailed;
      }
      else
      {
         result = kFblOk;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagRCStartCSRTriggerMainHandler
 **********************************************************************************************************************/
/*! \brief         Certificate signing request trigger
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartCSRTriggerMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   result = ApplFblCSRTrigger();

   pbDiagData[kDiagLocFmtRoutineStatus] = result;
   DiagProcessingDone(kDiagRslRoutineControlCSRTrigger);

   return result;
}

#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
/***********************************************************************************************************************
 *  FblDiagRequestUploadLengthCheck
 **********************************************************************************************************************/
/*! \brief         Request upload length check
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: Length of check request is OK; kFblFailed: Length check failed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagRequestUploadLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;
   vuint8 addrFormat;
   vuint8 lengthFormat;
   vuint8 dataFormat;

   /* Get length and address format from message */
   lengthFormat = (vuint8)((pbDiagData[kDiagLocFmtFormatOffset] & 0xF0u) >> 4u);
   addrFormat   = (vuint8)(pbDiagData[kDiagLocFmtFormatOffset] & 0x0Fu);

   /* Read compression and encryption method */
   dataFormat = (tFblMemDfi)pbDiagData[kDiagLocFmtSubparam];

   if (dataFormat != kDiagSubNoDataProcessing)
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   else if ( (addrFormat != kFblDiagAddrFormat) || (lengthFormat != kFblDiagLengthFormat) )   /* Check length of request against calculated length */
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   /* Subtract 2 bytes as the definition kDiagRqlRequestDownload already contains 1 byte minimum length for address and length */
   else if(diagReqDataLen != ((vuint16)kDiagRqlRequestUpload -2u + (vuint16)lengthFormat + (vuint16)addrFormat))
   {
      result = kFblFailed;
   }
   else
   {
      result = kFblOk;
   }

   return result;
}
#endif

/***********************************************************************************************************************
 *  FblDiagRequestDownloadMainHandler
 **********************************************************************************************************************/
/*! \brief         Request download service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
static tFblResult FblDiagRequestDownloadMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblMemBlockInfo blockInfo;
   tFblMemSegmentInfo segmentInfoLocal;
   tFblResult result;
   tFblDiagNrc libMemResult;
   vuint8 *localPbDiagData = pbDiagData;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   /* Initialize variables */
   segmentInfoLocal.logicalAddress = 0u;
   segmentInfoLocal.logicalLength = 0u;

   /* Verify all programming preconditions are fulfilled. Get address and length (logical) from request */
   result = FblDiagCheckRequestDownloadPreconditions(localPbDiagData, &segmentInfoLocal);

#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
   /* Flash Driver download? */
   if (result == kFblOk)
   {
      result = FblDiagCheckForFlashDriverDownload(&segmentInfoLocal);
   }
#else
   FblDiagSetTransferTypeFlash();
   segmentInfoLocal.type = kFblMemType_ROM;
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */

   if (result == kFblOk)
   {
      /* Get length from request */
      transferRemainder = segmentInfoLocal.logicalLength;

      /* Initialize error status address */
      FblErrStatSetAddress(segmentInfoLocal.logicalAddress);

      /* Init expected sequence counter for TransferData */
      expectedSequenceCnt = kDiagInitSequenceNum;
      /* Init current sequence counter for TransferData */
      currentSequenceCnt = kDiagInitSequenceNum;

      /* Prepare download of application or flash driver. Target addresses are valid after these calls */
      if (FblDiagGetTransferTypeFlash())
      {
         result = FblDiagCheckFlashMemoryDownload(&segmentInfoLocal);
      }
#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
      else
      {
         result = FblDiagCheckFlashDriverDownload(&segmentInfoLocal);
      }
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */
   }

   /* First download segment */
   if ((result == kFblOk) && (segmentCount <= 1u))
   {
      /* The downloadBlockDescriptor.blockNr is initialized at different locations before:
         - In FblDiagCheckFlashDriverDownload for flash driver download
         - In FblDiagWriteDataByIdMainHandler (Fingerprint) for flash download */
      result = FblDiagPrepareFirstDownloadSegment(&blockInfo, &segmentInfoLocal, downloadBlockDescriptor.blockNr);
      (void)FblDiagMemGetActiveBuffer();
   }

   /* Add segment data to FblLib_Mem */
   if (result == kFblOk)
   {
      /* Indicate start of new segment */
      libMemResult = FblMemRemapStatus(FblMemSegmentStartIndication(&segmentInfoLocal));
      localPbDiagData = FblDiagMemGetActiveBuffer();
      if (libMemResult == kDiagErrorNone)
      {
         /* Init expected sequence counter for TransferData */
         expectedSequenceCnt = kDiagInitSequenceNum;
         /* Init current sequence counter for TransferData */
         currentSequenceCnt = kDiagInitSequenceNum;

         /* Now allow reception of TransferData */
         FblDiagSetTransferDataAllowed();
         FblDiagClrTransferDataSucceeded();
         FblDiagClrChecksumAllowed();

#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
         /* Keep track that RequestDownload command was sent, for Transfer Data */
         FblDiagSetDownloadRequest();
         /* Clear out Upload Request flag, if eventual set for a previous error */
         FblDiagClrUploadRequest();
#endif

         /* Prepare response */
         localPbDiagData[kDiagLocFmtSubparam] = (FBL_DIAG_RESPONSE_BUFFER_LFI << 4u);
         FblMemSetInteger(FBL_DIAG_RESPONSE_BUFFER_LFI, FBL_DIAG_RESPONSE_BUFFER_SIZE, &localPbDiagData[kDiagLocFmtSubparam + 1u]);

         DiagProcessingDone(kDiagRslRequestDownload + FBL_DIAG_RESPONSE_BUFFER_LFI);
      }
      else
      {
         /* Set NRC provided by FblLib_Mem */
         FblDiagSetError(libMemResult);
         result = kFblFailed;
      }
   }

   return result;
}

#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
/***********************************************************************************************************************
 *  FblDiagRequestUploadMainHandler
 **********************************************************************************************************************/
/*! \brief         Request upload service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRequestUploadMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblMemSegmentInfo segmentInfoLocal;
   tFblResult result;
   vuint8 *localPbDiagData = pbDiagData;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   /* Verify all programming preconditions are fulfilled. Get address and length (logical) from request */
   result = FblDiagCheckRequestUploadPreconditions(localPbDiagData, &segmentInfoLocal);

   /* Save the segment information, for the transfer download */
   segmentInfoUpload = segmentInfoLocal;


   if (result == kFblOk)
   {
      /* Get length from request */
      transferRemainder = segmentInfoLocal.logicalLength;
      /* Initialize error status address */
      FblErrStatSetAddress(segmentInfoLocal.logicalAddress);
      /* Init expected sequence counter for TransferData */
      expectedSequenceCnt = kDiagInitSequenceNum;
      /* Init current sequence counter for TransferData */
      currentSequenceCnt = kDiagInitSequenceNum;
      /* Update Retry variables */
      prevTransferRemainder = 0u;
      prevLogicalAddress = 0u;

      /* Now allow transfer data */
      FblDiagSetTransferDataAllowed();
      FblDiagClrTransferDataSucceeded();

      /* Keep track that RequestDownload command was sent, for Transfer Data */
      FblDiagSetUploadRequest();
      /* Clear out Download Request flag, if eventual set for a previous error */
      FblDiagClrDownloadRequest();

      /* Prepare response */
      localPbDiagData[kDiagLocFmtSubparam] = (FBL_DIAG_RESPONSE_BUFFER_LFI << 4u);
      FblMemSetInteger(FBL_DIAG_RESPONSE_BUFFER_LFI, FBL_DIAG_RESPONSE_BUFFER_SIZE, &localPbDiagData[kDiagLocFmtSubparam + 1u]);
      DiagProcessingDone(kDiagRslRequestUpload + FBL_DIAG_RESPONSE_BUFFER_LFI);
   }

   return result;
}
#endif

/***********************************************************************************************************************
 *  FblDiagTransferDataLengthCheck
 **********************************************************************************************************************/
/*! \brief         Transfer data length check
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: Length of transfer data service is OK; kFblFailed: Length check failed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagTransferDataLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
#endif

#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
   if ( (FblDiagGetDownloadRequest()) && ((diagReqDataLen <= (kDiagRqlTransferData)) || (diagReqDataLen > (tTpDataType)(FBL_DIAG_RESPONSE_BUFFER_SIZE - 1u))) )
   {
      /* Requested transfer length is larger than indicated data length */
      FblDiagClrTransferDataAllowed();
      result = kFblFailed;
   }
   else if ( (FblDiagGetUploadRequest()) && (diagReqDataLen != (kDiagRqlTransferData)) )
#else
   if ((diagReqDataLen <= (kDiagRqlTransferData)) || (diagReqDataLen > (tTpDataType)(FBL_DIAG_RESPONSE_BUFFER_SIZE - 1u)))
#endif
   {
      /* Requested transfer length is larger than indicated data length */
      FblDiagClrTransferDataAllowed();
      result = kFblFailed;
   }
   else
   {
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagTransferDataMainHandler
 **********************************************************************************************************************/
/*! \brief         TransferData service function;
 *  \pre           TransferData must be enabled by RequestDownload service
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673, 6010, 6030, 6080 1 */ /* MD_MSR_Rule8.13, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
static tFblResult FblDiagTransferDataMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;
   tFblDiagNrc libMemResult;
   tFblLength transferDataLength;
   vuint8 *localPbDiagData = pbDiagData; /* PRQA S 3678 */ /* MD_MSR_Rule8.13 */
#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
   vuint8 uploadReTx;
#endif
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
   vuint8 memoryStatus;
#endif

   if (!FblDiagGetTransferDataAllowed())
   {
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   else
   {
#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
      /* Initialize retransmission flag */
      uploadReTx = FBL_DIAG_UPLOAD_NOTRETRY;
#endif
      result = kFblOk;

      /* Check if the requested sequence number is expected */
      if (localPbDiagData[kDiagLocFmtSubparam] != expectedSequenceCnt)
      {
         /* Check if sequence number corresponds to a retransmission of the last message */
         if (localPbDiagData[kDiagLocFmtSubparam] == currentSequenceCnt)
         {
#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
            uploadReTx = FBL_DIAG_UPLOAD_RETRY;
            if (FblDiagGetDownloadRequest())
#endif
            {
               /* Repetition of last transferData request
                * For download mode, simply send a positive response without loading data to memory
                */
               DiagProcessingDone(kDiagRslTransferData);
            }
         }
         else /* Sequence number is not for a retry */
         {
            /* Send a WrongSequenceError */
            DiagNRCWrongBlockSequenceCounter();
            result = kFblFailed;
         }
      }
      else
      {
#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
         if (FblDiagGetDownloadRequest())
#endif
         {
            /* Data download has been requested */
            /* Length without sequence counter byte */
            transferDataLength = diagReqDataLen - 1uL;

#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
            if (erasedStatus == kFlashErased)
            {
               erasedStatus = kFlashNotErased;
               memoryStatus = kDiagMemStatProgrammed;

               /* Update memory status in NVM just before flash programming starts */
               if (ApplFblWriteMemoryStatus(downloadBlockDescriptor.blockNr, &memoryStatus) != kFblOk)
               {
                  DiagNRCConditionsNotCorrect();
                  result = kFblFailed;
               }
            }
#endif
            if (result == kFblOk)
            {
               /* Indicate data to FblLib_Mem */
               FblDiagClrEraseSucceeded();
               libMemResult = FblMemRemapStatus(FblMemDataIndication(DiagBuffer, kDiagFmtDataOffset, transferDataLength));

               /* Caution: Depending on configuration, DiagBuffer pointer may change. */
               localPbDiagData = FblDiagMemGetActiveBuffer(); /* PRQA S 2983 */ /* MD_FblDiagOem_2983 */
               if (libMemResult == kDiagErrorNone)
               {
                  /* Memorize current counter */
                  currentSequenceCnt = expectedSequenceCnt;
                  /* Sequence counter value of next transferData request
                   * Note: We do not rely on an implicit 8-bit caused overflow at 256, which does not happen on certain platforms */
                  expectedSequenceCnt = ((expectedSequenceCnt + 1u) & 0xFFu);

                  DiagProcessingDone(kDiagRslTransferData);
                  result = kFblOk;
               }
               else
               {
                  FblDiagSetError(libMemResult);
                  FblDiagClrTransferDataAllowed();
                  result = kFblFailed;
               }
            }
         }
      }
#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
      if (FblDiagGetUploadRequest())
      {
         /*
         * Check if the requested length exceeds the diag buffer size.
         * kDiagFmtDataOffset accounts for service ID and block sequence counter.
         */

         if (uploadReTx == FBL_DIAG_UPLOAD_RETRY)
         {
            /* Re-initialize variable for a retry Transfer Data */
            transferRemainder = prevTransferRemainder;
            segmentInfoUpload.logicalAddress = prevLogicalAddress;
         }

         /* Save an eventual parameter copy in case of retry */
         prevTransferRemainder = transferRemainder;
         prevLogicalAddress = segmentInfoUpload.logicalAddress;

         if (transferRemainder > 0u)
         {
            if (transferRemainder > (tFblLength)(FBL_DIAG_BUFFER_LENGTH - kDiagFmtDataOffset))
            {
               transferDataLength = (tCwDataLengthType)(FBL_DIAG_BUFFER_LENGTH - kDiagFmtDataOffset);
            }
            else
            {
               transferDataLength = (tCwDataLengthType)transferRemainder;
            }

            transferRemainder -= transferDataLength;

            /* Data upload has been requested */
            if (FblReadProm(segmentInfoUpload.logicalAddress, &localPbDiagData[kDiagFmtDataOffset - 1u], transferDataLength) != transferDataLength)
            {
               /* Tried accessing non supported memory location */
               DiagNRCRequestOutOfRange();
               result = kFblFailed;
            }
            else /* Success */
            {
               segmentInfoUpload.logicalAddress += transferDataLength;
               DiagProcessingDone((vuint16)transferDataLength + 1u);

               if (uploadReTx == FBL_DIAG_UPLOAD_NOTRETRY)
               {
                  /* Memorize current counter */
                  currentSequenceCnt = expectedSequenceCnt;
                  /* Sequence counter value of next transferData request
                   * Note: We do not rely on an implicit 8-bit caused overflow at 256, which does not happen on certain platforms */
                  expectedSequenceCnt = ((expectedSequenceCnt + 1u) & 0xFFu);
               }
            }
         }
         else
         {
            /* A transfer data was issued by the tester, but no data left to send out.
             * In this case a Transfer Suspend NRC can be set.
             * Download is interrupted.
             */
            DiagNRCTransferDataSuspended();
            FblDiagClrTransferDataAllowed();
            result = kFblFailed;
         }
      }
#endif
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagReqTransferExitMainHandler
 **********************************************************************************************************************/
/*! \brief         RequestTransferExit service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagReqTransferExitMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;
   tFblDiagNrc libMemResult;
   tFblLength  totalProgramLength;  /* Total number of programmed bytes */

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
#endif

   /* Do sequence and parameter checks */
   if (!FblDiagGetTransferDataAllowed())
   {
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   /* Total length check - must be done here to be compliant to the ISO check sequence */
   else if (diagReqDataLen != kDiagRqlRequestTransferExit)
   {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
      result = kFblFailed;
   }
   else
   {
      FblDiagClrTransferDataAllowed();

#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
      libMemResult = kDiagErrorNone;
      if (FblDiagGetDownloadRequest())
#endif
      {
         /* Finalize programming of current segment */
         libMemResult = FblMemRemapStatus((FblMemSegmentEndIndication(&totalProgramLength)));
         (void)FblDiagMemGetActiveBuffer();
      }

      if (libMemResult == kDiagErrorNone)
      {
         /* RequestTransferExit was successful */
         FblDiagSetTransferDataSucceeded();
         FblDiagSetChecksumAllowed();
         DiagProcessingDone(kDiagRslRequestTransferExit);
         result = kFblOk;
      }
      else
      {
         /* Set return value of FblLib_Mem as NRC */
         FblDiagSetError(libMemResult);
         result = kFblFailed;
      }
   }

#if defined( FBL_DIAG_ENABLE_REQUEST_UPLOAD )
   FblDiagClrDownloadRequest();
   FblDiagClrUploadRequest();
#endif

   return result;
}

/***********************************************************************************************************************
 *  FblDiagTesterPresentMainHandler
 **********************************************************************************************************************/
/*! \brief         FblTesterPresent service function.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagTesterPresentMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   DiagProcessingDone(kDiagRslTesterPresent);

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagReadDataByIdMainHandler
 **********************************************************************************************************************/
/*! \brief         ReadDataByIdentifier service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 *********************************************************************************************************************/
static tFblResult FblDiagReadDataByIdMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   ApplFblReadDataByIdentifier(pbDiagData, diagReqDataLen);

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagCommonBlockHashMainHandler
 **********************************************************************************************************************/
/*! \brief       Run the hash calculation prior to the flash download for all block types.
 *  \param[in]   pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]   diagReqDataLen Length of data (without SID)
 *  \return      kFblOk:     service processed successfully (goto next state)
 *               kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagCommonBlockHashMainHandler(tFblLbtBlockType blockType, vuint8 *pbDiagData)
{
   tFblLbtBlockIndex curBlockIdx;
   tFblResult result;
   tBlockDescriptor tempBlockDescriptor;

   curBlockIdx = pbDiagData[kDiagLocFmtRoutineStatus];

   result = FblLbtGetBlockDescriptorByIndex(curBlockIdx, &tempBlockDescriptor);

   if (result == kFblOk)
   {
      /* Initialize error status block number */
      FblErrStatSetBlockNr(tempBlockDescriptor.blockNr);

      if (tempBlockDescriptor.blockType == blockType)
      {
         /* Get hash of requested logical block */
         if (ApplFblGetBlockHash(tempBlockDescriptor.blockNr, &pbDiagData[kDiagLocFmtRoutineStatus]) != kFblOk)
         {
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }
      }
      else
      {
         /* Logical block type is not correct for this block number */
         DiagNRCRequestOutOfRange();
         result = kFblFailed;
      }
   }
   else
   {
      /* Invalid block index */
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }

   if (result == kFblOk)
   {
      FblDiagSetLogBlockHashRequested();

      /* Send positive response */
      DiagProcessingDone(kDiagRslRoutineControlCalcBlockHash);
   }
   return result;
}

#if defined( FBL_DIAG_ENABLE_CLEAR_DIAGNOSTIC_INFORMATION )
/***********************************************************************************************************************
 *  FblDiagClearDiagnosticInformation
 **********************************************************************************************************************/
/*! \brief         ClearDiagnosticInformation service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 *********************************************************************************************************************/
static tFblResult FblDiagClearDiagnosticInformation(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   /* Call user function */
   return ApplFblClearDiagnosticInformation(pbDiagData, diagReqDataLen);
}
#endif /* FBL_DIAG_ENABLE_CLEAR_DIAGNOSTIC_INFORMATION */

/***********************************************************************************************************************
 *  FblDiagReadDtcByStatusMask
 **********************************************************************************************************************/
/*! \brief         Read DTC by status mask service function.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagReadDtcByStatusMask(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   /* Call user function to read DTCs from memory */
   return ApplFblReportDTCByStatusMask(pbDiagData, diagReqDataLen);
}

/***********************************************************************************************************************
 * Diagnostic pre handler service functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblDiagDefaultPreHandler
 **********************************************************************************************************************/
/*! \brief         Pre-handler function to call ApplFblCheckConditions()
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 *********************************************************************************************************************/
static tFblResult FblDiagDefaultPreHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   return ApplFblCheckConditions(pbDiagData, diagReqDataLen);
}

#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 * Diagnostic post handler service functions
 **********************************************************************************************************************/

/* Start section to execute code from RAM */
#define FBLDIAG_RAMCODE_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  FblDiagDefaultPostHandler
 **********************************************************************************************************************/
/*! \brief       Can be used to switch to next state AFTER successful transmission of the service, e.g. EcuReset.
 *  \param[in]   postParam Parameter indicating service response.
 **********************************************************************************************************************/
void FblDiagDefaultPostHandler( vuint8 postParam )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)postParam;
#endif
   if(FblDiagGetDefaultSession())
   {
      FblCwResetResponseAddress();
   }

   /* Valid UDS request processed. Stop application boot timeout counter */
   if ((postParam == kDiagPostPosResponse) || (postParam == kDiagPostNoResponse))
   {
      /* Check if this post handler is called because of response after reset */
      if (GetFblMainState( kFblMainStateStartFromReset ))
      {
         ClrFblMainState( kFblMainStateStartFromReset );
      }
      else
      {
         /* Real message received */
         FblDiagClrBootTimeoutActive();
      }
   }
   /* Activate S3 timeout in case an application software is present even in default session */
   if ((postParam != kDiagPostRcrRp) && (FblMainGetApplicationValid()))
   {
      ResetTesterTimeout();
   }

}
/* Stop section to execute code from RAM */
#define FBLDIAG_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLDIAG_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_FblDiagOem_0306:
      Reason: Address conversion between integer values and pointers is required to allow for hardware independent
      configuration and address range checks.
      Risk: The size of integer required to hold the result of a pointer cast is implementation defined.
      Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
      specific basis.

   MD_FblDiagOem_0313:
      Reason: Signature/checksum verification functions are stored as void pointers as actual type is not known at
       configuration time.
      Risk: Function signature not compatible with expected type.
      Prevention: Integrator has to take care the configured functions match with the expected signature.

   MD_FblDiagOem_2983:
      Reason: Increases maintainability for future enhancements.
      Risk: Unnecessary waste of resources.
      Prevention: No prevention required.

   MD_FblDiagOem_3415:
      Reason: If condition relies on lazy evaluation, second argument only executed if initial condition is/isnot fullfilled.
      Risk: No identifiable risk.
      Prevention: No prevention required.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_DIAG_OEM.C
 **********************************************************************************************************************/

