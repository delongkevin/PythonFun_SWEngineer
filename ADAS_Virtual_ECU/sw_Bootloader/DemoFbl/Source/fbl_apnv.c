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
 *  01.00.01   2018-10-05  visqps  ESCAN00100943    Support automatic DemoAppl creation
 *  01.01.00   2018-11-06  viscb   ESCAN00101235    Support for security class Vendor
 *  01.02.00   2019-01-29  viscb   ESCAN00101939    Store boot software fingerprint
 *  01.02.01   2019-07-19  vistbe  ESCAN00102567    SHA-256 Application Logical Block Hash Not Supported
 *  02.00.00   2020-03-26  vistbe  FBL-1510         Upgrade to latest reference implementation
 *  02.01.00   2020-07-13  visrie  FBL-2021         Added support for OTA
 *  02.01.01   2020-08-04  visjdn  ESCAN00106902    Wrong NV metadata index calculated
 *  02.02.00   2020-09-17  visrie  FBL-2139         Added support for vHsm
 *  02.03.00   2020-10-11  vistbe  FBL-2419         Add support for FblLib_SecBoot_Escrypt
 *                                 ESCAN00107820    Compiler error: kFblFileHeaderSize not defined
 *                                 ESCAN00107932    Memory can be overwritten in ApplFblHandleCertUpdate
 *                                 ESCAN00107933    Block validation fails
 *  02.04.00   2020-12-17  vistbe  FBL-1352         Updated for new version of GHS Library
 *  02.04.01   2021-01-07  visjdn  ESCAN00107451    Undefined API ApplFblAdjustLbtBlockData
 *  02.05.00   2021-11-08  vistbe  FBL-3863         Add support for new GHS library
 *  02.05.01   2022-02-16  visrie  ESCAN00108220    FCA Header is not consider during certificate update
 *                                 ESCAN00108922    Getting a module index do not work
 *                                 ESCAN00109142    Wrong block hash extracted
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY (kbFbl_apAPI.c)
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2018-09-14  visrie  ESCAN00100739    Added support for FblLib_NvPattern
 *                                                  Removed unused code
 *                         viscb   ESCAN00101418    Callout function for memory condition check
 *                         visach  ESCAN00101686    Added interface definition for vendor verification routine
 *  02.01.00   2019-02-26  visrie  ESCAN00102257    Added additional callout functions
 *  02.01.01   2019-09-23  visrie  FBL-452          Added support for FrArTp
 *  02.02.00   2019-12-05  visrie  FBL-458          Added FblMio callout functions
 *  02.03.00   2020-05-07  visrie  FBL-1414         Added callout functions for One-Step-Updater
 *  02.03.01   2020-06-02  visjdn  ESCAN00106533    Update to latest MISRA version
 *  02.03.02   2020-09-14  visrcn  FBL-2257         Add MISRA justifications
 *  02.03.03   2020-11-23  visrcn  FBL-2564         Add MISRA justifications
 *  02.03.04   2021-03-19  visjdn  FBL-2916         Add MISRA justifications
 *  02.04.00   2021-05-26  vishor  FBL-3165         MISRA corrections and justifications
 *  02.05.00   2021-06-15  visrie  FBL-3591         Provide default implementation for ApplFbl_DetEntryHandler
 *                                                  Add MISRA justifications
 *  02.06.00   2021-07-15  visjdn  FBL-3381         Re-mapping of EcuM_SetWakeupEvent
 *  02.07.00   2021-07-22  visrie  FBL-3822         Update to QAC9 Helix-2021
 *  02.08.00   2021-09-14  visjdn  FBL-2859         Add MISRA justifications
 *  02.09.00   2021-10-12  vistmo  FBL-3901         Add authentication callbacks
 *  02.10.00   2021-10-15  visrie  FBL-3945         Remove content of ApplFblStartApplication
 *  02.10.01   2021-11-12  vishor  ESCAN00110133    Compiler error: Unknown symbols
 *                                                   ApplFblSave/RestoreStatusSector/Dynamic
 *  02.10.02   2022-06-27  visrie  FBL-4694         Add MISRA justifications
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY (KbFbl_apOem.c)
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.02   2018-08-10  viscb   -                Release
 *  01.00.03   2018-09-25  visqps  ESCAN00100849    Support automatic DemoAppl creation
 *  01.01.00   2018-11-06  viscb   ESCAN00101210    Added bootmanager information structure
 *                         viscb   ESCAN00101238    Support for security class Vendor
 *  01.02.00   2019-01-29  viscb   ESCAN00101942    Changed type of certState from enum to vuint8
 *  01.03.00   2019-02-20  visshs  ESCAN00102196    Add support for LZMA decompression
 *  02.00.00   2020-03-26  vistbe  FBL-1510         Upgrade to latest reference implementation
 *                                 ESCAN00105994    DIDs do not report correct information for all logical blocks
 *  02.01.00   2020-07-13  visrie  FBL-2021         Added support for OTA
 *  02.02.00   2020-10-11  vistbe  FBL-2419         Add support for FblLib_SecBoot_Escrypt
 *  02.03.00   2020-12-17  vistbe  FBL-1352         Added support for Authenticated Diagnostics
 *  02.04.00   2021-04-12  vistmo  FBL-2961         Added support for Authenticated Diagnostics with vHSM
 *  02.04.01   2021-08-05  visrie  ESCAN00109778    Compiler error: Incompatible type for ApplFblNvWriteSegmentCount
 *                                                   and ApplFblNvReadSegmentCount
 *  02.04.02   2022-06-20  vishor  ESCAN00106412    LZMA decompression fails with COMPRESS_LZMA_STATUS_BITSTREAM_ERROR
 *                                 ESCAN00108782    [XCP] Bootloader does not process XCP messages
 *                                 ESCAN00108761    Incorrect value returned for DID F186
 **********************************************************************************************************************/


#define FBL_APNV_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
# include "cmpr_inc.h"

#include "BrsMain.h"
#include "BrsHw.h"
# include "Det.h"
# if (DET_ENABLED == STD_ON)
#   include "Can_30_Mcan.h"
#   include "CanTp.h"
# endif

#if (SEC_SECURITY_CLASS == SEC_CLASS_VENDOR)
#  include "Csm.h"
#include "Crypto_30_vHsm.h"
#endif
#   include "vstdlib.h"


/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLKBAPI_FRAMENV_FCA_VERSION != 0x0205u ) || \
    ( FBLKBAPI_FRAMENV_FCA_RELEASE_VERSION != 0x01u )
# error "Error in fbl_apnv.c Source and header file are inconsistent!"
#endif

#if ( (FBLKBAPI_FRAMENV_FCA_VERSION != _FBLKBAPI_FRAMENV_OEM_VERSION ) || \
      (FBLKBAPI_FRAMENV_FCA_RELEASE_VERSION != _FBLKBAPI_FRAMENV_OEM_RELEASE_VERSION) )
# error "Error in fbl_apxx.c: Source and v_ver.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
#endif /* FBL_ENABLE_PRESENCE_PATTERN */

/* Configuration check */
#if ( kEepSizeValidityFlags != kNrOfValidationBytes )
# error "Size of block validity data is not correct. Check GENy configuration of size."
#endif

#if defined( FBL_ENABLE_WRAPPER_NV )
# if (( kEepSizeSegmentLengthList < (4u * SWM_DATA_MAX_NOAR) ) || \
     ( kEepSizeSegmentAddrList < (4u * SWM_DATA_MAX_NOAR) ))
#  error "Error in WrapNv_Cfg.h: Configuration error (kEepSizeSegmentLists too small)"
# endif
# if (kEepSizeSegmentLengthList != kEepSizeSegmentAddrList)
#  error "Error in WrapNv_Cfg.h: Configuration error (kEepSizeSegmentAddrList and kEepSizeSegmentLists must be of the same size)"
# endif
#endif /* FBL_ENABLE_WRAPPER_NV */

/* Specify logical block number which has the identification data of the application */
#define kFblBlockNumberOfIdentification   0u

/* Define FCA file header size (if not provided by FblLib_SecBoot) */
#if !defined( kFblFileHeaderSize )
# define kFblFileHeaderSize 0x1C0u
#endif

/* Offset into FCA file header for file digest/hash */
#define kFcaHdrOffsetFileDigest 8u
#define CERTIFICATE_OFFSET 64u
#define FILE_SIZE_OFFSET 4

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
#endif /* FBL_ENABLE_PRESENCE_PATTERN */

typedef vuint16   tFblApnvProgCountType;

/* Time stamp */
typedef struct
{
  uint16 year;
  uint8 month;
  uint8 day;
  uint8 hour;
  uint8 minute;
  uint8 second;
} CertDateTimeType_t;

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/* Buffer for fingerprint */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 blockFingerprint[kEepSizeFingerprint];
V_MEMRAM0  V_MEMRAM1 SecureLogRecord_t V_MEMRAM2  SecureLogRecord_Group_2;
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 KeyElementID[2];
V_MEMRAM0 static V_MEMRAM1 SecureLogRecord_t V_MEMRAM2 SecureLogRecord_Group1;
V_MEMRAM0 static V_MEMRAM1 SecureLogRecord_t V_MEMRAM2 SecureLogRecord_Group2;
#if defined( FBL_APPL_ENABLE_STARTUP_DEPENDENCY_CHECK )
#else
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
V_MEMRAM0 static V_MEMRAM1 tBlockDescriptor V_MEMRAM2 currentValidatedBlock;
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
#endif /* FBL_APPL_ENABLE_STARTUP_DEPENDENCY_CHECK */

uint8 MCU_1_InvalidateFlag = FALSE;
uint8 SW_Identification_FblUpdtr[10u] = {0x55, 0x50, 0x44, 0x41, 0x54, 0x45, 0x52, 0x5F, 0x5F, 0x5F};
vuint8 buffer_FblUpdtr[kApplInfoSizeSoftwareIdentification_F181]; /*SW-Identification from NAND*/
vuint8 buffer_FblUpdtrNvM[kApplInfoSizeSoftwareIdentification_F181]; /*SW-Identification from NvM*/
boolean s_BootUpdater = FALSE;
uint8 NotBeforeTime[15];
uint32 NotBeforeTimeLen = 15U;

uint8 SystemTime[15] = {0};
boolean IsSystemTimeSet = FALSE;
uint32 TimestampCounter = 0;
uint32 SecondCounter = 0;
static uint32 IncCounter;
uint8 NotAfterTime[15];
uint32 NotAfterTimeLen = 15U;
uint32 NotAfterEpochFormat = 0;
boolean CertificateExpired = FALSE;
uint32 SessionSecondCounter = 0;
boolean CheckCertSessionValid = FALSE;

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if !defined( FBL_ENABLE_PRESENCE_PATTERN )
static tFblResult ApplFblChgBlockValid( vuint8 mode, tBlockDescriptor descriptor );
#endif /* FBL_ENABLE_PRESENCE_PATTERN */

uint32 getTimeStamp(void);
void TimeStampIncrement(void);
tFblResult ApplFblSaveCertTimeInfo(void);
Std_ReturnType getEpochTime(uint8* LocSystemTime, uint32* LocTimestampCounter);
void CheckAuthCertiValidity(void);
void SecureLogEvent(const EventType Event, const EventSubType SubEvent, const uint8* EventData);

static SecureLogRecord_t * getEventGroup(const EventType Event, uint8* GrpId);

static Std_ReturnType ParseUTCGeneralizedTime(P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) timeElementPtr,
                                       uint16 timeElementDataLength,
                                       P2VAR(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) parsedTimePtr);

static Std_ReturnType ConvertDateToUnixTime(P2CONST(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) date, P2VAR(uint32, AUTOMATIC, AUTOMATIC) unixTime);

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/

# if !defined( FBL_ENABLE_PRESENCE_PATTERN )
/***********************************************************************************************************************
 *  ApplFblChgBlockValid
 **********************************************************************************************************************/
/*! \brief       This function changes the validation flag of a logical block.
 *               The state information is stored inverted.
 *  \pre         EEPROM driver must be initialized before call
 *  \param[in]   mode (kEepValidateBlock/kEepInvalidateBlock)
 *  \param[in]   descriptor Block descriptor
 *  \return      kFblOk if successful, kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult ApplFblChgBlockValid( vuint8 mode, tBlockDescriptor descriptor )
{
   vuint8         validityMask;
   tFblResult     result;

   vuint8         byteIdx;
   vuint8         validityFlags[kEepSizeValidityFlags];
   vuint8         validityCheck[kEepSizeValidityFlags];

   byteIdx = (vuint8)(descriptor.blockNr >> 0x03u);
   validityMask = (vuint8)(0x01u << (descriptor.blockNr & 0x07u));

   result = kFblFailed;

   if (((ApplFblNvReadValidityFlags(validityFlags))) == kFblOk)
   {
      if (mode == kEepValidateBlock)
      {
         validityFlags[byteIdx] &= FblInvert8Bit(validityMask);
      }
      else
      {
         validityFlags[byteIdx] |= validityMask;
      }

      /* Modify validity flags */
      if (ApplFblNvWriteValidityFlags(validityFlags) == kFblOk)
      {
         /* Read modified flags */
         if (ApplFblNvReadValidityFlags(validityCheck) == kFblOk)
         {
            /* Check if flags were written correctly */
            if (validityCheck[byteIdx] == validityFlags[byteIdx])
            {
               result = kFblOk;
            }
         }
      }
   }
   return result;
}
#endif /* FBL_ENABLE_PRESENCE_PATTERN */

/***********************************************************************************************************************
 *  ApplFblAdjustLbtBlockData
 **********************************************************************************************************************/
/*! \brief         This function is called whenever the bootloader queries the range for the logical blocks.
 *  \details       This info is typically stored in fbl_mtab.c and generated from GENy. This function
 *                 can be used to spare a range from the LBT at runtime that shall not be flashed, e.g. PresencePattern.
 *  \param[in,out] blockDescriptor Pointer to LBT-Descriptor
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblAdjustLbtBlockData( tBlockDescriptor * blockDescriptor )
{
   tFblResult        result;
#if defined( FBL_ENABLE_PRESENCE_PATTERN )
   IO_PositionType   presPtnAddress;
   IO_SizeType       presPtnLen;
#endif

#if !defined( FBL_ENABLE_PRESENCE_PATTERN )
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_DummyStmt */
   (void)blockDescriptor;
# endif
#endif

   /* Initialize variables */
   result = kFblOk;

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
   /* Calculate location of presence pattern.           */
   /* Note that the end of the block descriptor already */
   /* points to the presence pattern itself.            */
   if (result == kFblOk) /* PRQA S 2995, 2991 */ /* MD_FblKbApiOem_2995_2991 */
   {
      /* PRQA S 4342,4521 1 */ /* MD_FblKbApiOem_4342_4521_ConfigurationEnumLengthCast */
      memSegment = FblNvPatternGetBaseAddr(blockDescriptor->blockNr, (tFblNvPatternId)(kFblNvPatternId_Last - 1u), &presPtnAddress, &presPtnLen);

      if (memSegment >= 0)
      {
         /* Reduce length by NvPattern area */
         blockDescriptor->blockLength = presPtnAddress - blockDescriptor->blockStartAddress;
      }
      else
      {
         result = kFblFailed;
      }
   }
#endif

   return result;
}

/***********************************************************************************************************************
 *  ApplFblGetModuleHeaderAddress
 **********************************************************************************************************************/
/*! \brief       This function has to return the address of the module header.
 *  \pre         Logical blocks need a module header
 *  \param[in]   blockNr
 *  \return      Address of module header information structure
 **********************************************************************************************************************/
tFblAddress ApplFblGetModuleHeaderAddress( vuint8 blockNr )
{
   tBlockDescriptor blockDescriptor;
   tFblAddress moduleHeaderAddr = 0u;

   /* The module header (containing the software identification information   *
    * and the interface version for consistency check) may be placed          *
    * at e.g.                                                                 *
    * - the beginning of the logical block (offset = +0x00 ) or               *
    * - with an offset to the beginning of the block (offset = +0xXX)         *
    * - with an offset to the end of the block (offset = blockEndAddress-0xXX)*
    * To provide an application specific flexibility, this function can       *
    * return the address depending on the block type and -number.             */

   /* Determine the module header address: */
   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
	   moduleHeaderAddr = blockDescriptor.blockStartAddress + 0x1C0;
   }

   return moduleHeaderAddr;
}

#if defined( FBL_CW_ENABLE_MULTIPLE_CONNECTIONS )
/* PRQA S 3673 8 */ /* MD_MSR_Rule8.13 */
/***********************************************************************************************************************
*  ApplFblWriteDcmDslRxTesterSourceAddr
**********************************************************************************************************************/
/*! \brief       Function to write DcmDsl Rx Tester Source Address to non-volatile memory
 *  \param[in]   buffer Pointer to byte array containing the tester source address
 *  \return      Result of write operation
**********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblWriteDcmDslRxTesterSourceAddr(vuint8* buffer)
{
   return ApplFblNvWriteDcmDslRxTesterSourceAddr(buffer);
}

/***********************************************************************************************************************
*  ApplFblReadDcmDslRxTesterSourceAddr
**********************************************************************************************************************/
/*! \brief       Function to read DcmDsl Rx Tester Source Address from non-volatile memory
 *  \param[out]  buffer Pointer to byte array containing the tester source address
 *  \return      Result of read operation
**********************************************************************************************************************/
tFblResult ApplFblReadDcmDslRxTesterSourceAddr(vuint8* buffer)
{
   return ApplFblNvReadDcmDslRxTesterSourceAddr(buffer);
}
#endif /* FBL_CW_ENABLE_MULTIPLE_CONNECTIONS */

/***********************************************************************************************************************
 *  ApplFblExtProgRequest
 **********************************************************************************************************************/
/*! \brief       Function is called on power-on reset to check if an external programming request exists.
 *  \details     If the flag is set, the flag is cleared and the function returns kProgRequest.
 *  \return      kProgRequest = external programming request, kNoProgRequest = programming request flag not set
 **********************************************************************************************************************/
tFblProgStatus ApplFblExtProgRequest( void )
{
   tFblProgStatus progStatus;
# if defined( FBL_ENABLE_FBL_START )
   /* Check a pattern in uninitialized RAM to see if this
    * is a reprogramming request from the application */
   if (FblBmChkFblStartMagicFlag())
   {
      /* Clear immediately the request */
      FblBmClrMagicFlag();
#  if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
      /* The ADA authentication state can be marked as authenticated.
       * The authentication already occured in the application, before
       * jumping to the FBL.
       */
      ApplFblSetAuthenticationState(kFblAuthenticated);
#  endif
      progStatus = kProgRequest;
   }
# else /* ! FBL_ENABLE_FBL_START */
   vuint8 progReqFlag;

   /* Check the reprogramming request flag */
   if (ApplFblNvReadProgReqFlag(&progReqFlag) == kFblOk)
   {
      if (progReqFlag == kEepFblReprogram)
      {
         /* Reprogramming flag is set, clear flag */
         progReqFlag = 0u;
         (void)ApplFblNvWriteProgReqFlag(&progReqFlag);  /* PRQA S 3425 */ /* MD_FblKbApiOem_3425 */
#  if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
      /* The ADA authentication state can be marked as authenticated.
       * The authentication already occured in the application, before
       * jumping to the FBL.
       */
      ApplFblSetAuthenticationState(kFblAuthenticated);
#  endif
         progStatus = kProgRequest;
      }
      else /* != kEepFblReprogram */
      {
         progStatus = kNoProgRequest;
      }
   }
# endif /* ! FBL_ENABLE_FBL_START */
   else
   {
      progStatus = kNoProgRequest;
   }
# if defined( FBLBM_ENABLE_SECURE_BOOT )
#  if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY )
   if (FblBmChkInitKeysMagicFlag())
   {
      /* Do not clear magic flag, as it is later evaluated again */
      progStatus = kInitKeysRequest;
   }
#  endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY */
#  if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
   if (FblBmChkInitCmacMagicFlag())
   {
      /* Do not clear magic flag, as it is later evaluated again */
      progStatus = kInitMacsRequest;
   }
#  endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */
# endif /* FBLBM_ENABLE_SECURE_BOOT */

   return progStatus;
}

/***********************************************************************************************************************
 *  ApplFblGetApplStatus
 **********************************************************************************************************************/
/*! \brief       Function checks if the application is successfully validated or not.
 *  \details     Returns kApplValid if application is valid (all mandatory blocks available) and application start is
 *               allowed. Otherwise it returns kApplInvalid.
 **********************************************************************************************************************/
tApplStatus ApplFblGetApplStatus( void )
{
   tApplStatus applicationStatus;
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
   tBlockDescriptor iterBlock;
   tFblLbtBlockFilter blockFilter;
# else
   vuint8 applValidity;
# endif /* FBL_ENABLE_PRESENCE_PATTERN */

   /* Initialize variables */
   applicationStatus = kApplInvalid;

# if defined( FBL_ENABLE_PRESENCE_PATTERN )
   /* Read validity from application validity pattern
    * Scan all logical blocks until one block with application valid flag is found */
   FblLbtBlockFilterInit(&blockFilter);
   iterBlock = FblLbtBlockFirst(&blockFilter);
   while ( (FblLbtBlockDone() == FALSE) && (applicationStatus == kApplInvalid) )
   {
      if (ApplFblChkApplPresence(&iterBlock) == kFblOk)
      {
         applicationStatus = kApplValid;
      }
      /* Prepare next cycle */
      iterBlock = FblLbtBlockNext();
   }
# else
   /* Read validity from NV-memory */
   if (ApplFblNvReadApplValidity(&applValidity) == kFblOk)
   {
      if (applValidity == kEepApplConsistent)
      {
         applicationStatus = kApplValid;
      }
   }
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
   return applicationStatus;
}

/***********************************************************************************************************************
 *  ApplFblIsValidApp
 **********************************************************************************************************************/
/*! \brief       Function is called on power-up to check if the application is successfully validated or not.
 *  \details     Returns kApplValid if application is valid (all mandatory blocks available) and application start is
 *               allowed. Otherwise it returns kApplInvalid.
 **********************************************************************************************************************/
/* PRQA S 2889 1 */ /* MD_FblKbApi_2889 */
tApplStatus ApplFblIsValidApp( void )
{
   tApplStatus applicationStatus;
   applicationStatus = ApplFblGetApplStatus();

   if (applicationStatus == kApplValid)
   {
      /* Check for abnormal shutdown */
      if (ApplFblGetShutdownStatus() == kFblShutdownStatusAbnormal)
      {
         /* In case of an abnormal shutdown, always return an invalid application
            so that diagnostic messages can be processed for the configured delay time. */
         SetFblMainState( kFblMainStateApplicationValid );

         applicationStatus = kApplInvalid;
      }
   }
   ApplFblClrShutdownStatus();

   return applicationStatus;
}

/***********************************************************************************************************************
 *  ApplFblValidateBlock
 **********************************************************************************************************************/
/*! \brief       Function is called after a successful download (CRC check was successful) to validate the logical block
 *  \pre         Logical block must be successfully downloaded
 *  \param[in]   blockDescriptor Block descriptor structure
 *  \return      kFblOk: validation successfully performed, kFblFailed: validation failed
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
tFblResult ApplFblValidateBlock( tBlockDescriptor blockDescriptor )
{
   /* Req: 16760571, 16442223 */
   vuint8 flashStatPass = 0x00;
   tFblResult result;
   tBlockDescriptor localBlockDescriptor;
   vuint8 conditionCheck=0u;
   vuint8 index;

   /* Local variables for update of NVM-data */
   vuint8 buffer[kApplInfoSizeSoftwareIdentification_F181];
   vuint8 fileHeaderTemp_buffer[kApplInfoSizeFileHeaderInfo];
   tFblAddress applHdrAddr, fileHrdAddr;
   vuint32 nvModuleId;

   localBlockDescriptor = blockDescriptor;
   nvModuleId = ApplFblGetNvModuleId(localBlockDescriptor.blockNr);
   applHdrAddr = ApplFblGetModuleHeaderAddress(localBlockDescriptor.blockNr);
   if(blockDescriptor.blockNr == FBL_LBT_SECURITY_CERT_LB_BLOCK_NUMBER)
   {
	   applHdrAddr = blockDescriptor.blockStartAddress + CERTSTORE_INFO_HEADER_OFFSET;
   }
   if (FblLbtGetBlockDescriptorByNr(nvModuleId, &localBlockDescriptor) == kFblOk)
   {
	   fileHrdAddr = blockDescriptor.blockStartAddress;
   }

   if(blockDescriptor.blockNr == FBL_LBT_MCU10_APPLICATION_LB_BLOCK_NUMBER) /* This check is for FblUpdtr */
   {
      /* Read SW Identification data of LB:01 (Here we are checking FblUpdater)*/
      (void)FblReadProm(applHdrAddr + kApplInfoOffsetSoftwareIdentification_F181 , buffer_FblUpdtr, kApplInfoSizeSoftwareIdentification_F181);
      ApplFblNvReadSoftwareIdentification(FBL_LBT_FBL_LB_BLOCK_NUMBER, buffer_FblUpdtrNvM);
      if(0u == VStdLib_MemCmp(SW_Identification_FblUpdtr,&buffer_FblUpdtr[3], 10u ))
      {
         s_BootUpdater = TRUE; 
      }
   }
    if(s_BootUpdater != TRUE)
    {
    	ApplFblNvWriteFlashStatus(nvModuleId,&flashStatPass); /* Update the flash status */
      (void)FblReadProm(fileHrdAddr + kApplInfoOffsetFileHeaderInfo, fileHeaderTemp_buffer, kApplInfoSizeFileHeaderInfo);
      ApplFblNvWriteFileHeaderInfo((IO_PositionType)nvModuleId, fileHeaderTemp_buffer);

      (void)FblReadProm(fileHrdAddr + kApplInfoOffsetUuid, fileHeaderTemp_buffer, kApplInfoSizeUuid);
      ApplFblNvWriteUuid((IO_PositionType)nvModuleId, fileHeaderTemp_buffer);

      /* Read F122 - EBOM ECU Part Number from current logical block and update NVM */
      (void)FblReadProm(applHdrAddr + kApplInfoOffsetSwEbomPartNumber_F122, buffer, kApplInfoSizeSwEbomPartNumber_F122);
      result = ApplFblNvWriteSwEbomPartNumber((IO_PositionType)nvModuleId, buffer);

      /* Read F181 / F182 - Application Software / Data Identifiction */
      (void)FblReadProm(applHdrAddr + kApplInfoOffsetSoftwareIdentification_F181, buffer, kApplInfoSizeSoftwareIdentification_F181);
      if (ApplFblNvWriteSoftwareIdentification((IO_PositionType)nvModuleId, buffer) != kFblOk)
      {
         result = kFblFailed;
      }
      #if ( SEC_SECURITY_CLASS == SEC_CLASS_VENDOR )
      if (ApplFblHandleCertUpdate(&localBlockDescriptor) != kFblOk)
      {
         result = kFblFailed;
      }
      #endif
   }



   if (result == kFblOk)
   {
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
      /* Save block descriptor of currently validated block.
       * The block descriptor will be used to validate the application. */
      currentValidatedBlock = localBlockDescriptor;

      if (ApplFblSetModulePresence(&localBlockDescriptor) != kFblOk)
      {
         result = kFblFailed;
      }
# else
      /* Set current block valid */
      if (ApplFblChgBlockValid(kEepValidateBlock, localBlockDescriptor) != kFblOk)
      {
         result = kFblFailed;
      }
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
   }

   return result;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  ApplFblInvalidateBlock
 **********************************************************************************************************************/
/*! \brief       Whenever the bootloader needs to delete data, this function is called
 *               to invalidate the current logical block.
 *  \param[in]   blockDescriptor Block descriptor structure
 *  \return      kFblOk: invalidation successfully performed, kFblFailed: invalidation failed
 **********************************************************************************************************************/
tFblResult ApplFblInvalidateBlock( tBlockDescriptor blockDescriptor )
{
   tFblResult result;
   vuint8 flashStatfailed = 0x01;
   tBlockDescriptor localBlockDescriptor;
   vuint32 nvModuleId;

   localBlockDescriptor = blockDescriptor;
   if(blockDescriptor.blockNr == FBL_LBT_MCU10_APPLICATION_LB_BLOCK_NUMBER)
   {
	   MCU_1_InvalidateFlag = TRUE ;
   }
   nvModuleId = ApplFblGetNvModuleId(localBlockDescriptor.blockNr);
   ApplFblNvWriteFlashStatus(nvModuleId,&flashStatfailed);  
   /* Invalidate application validity flag */
   result = ApplFblInvalidateApp(localBlockDescriptor);

   /* Erase valid flag of current block */
   if (result == kFblOk)
   {
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
      /* Only invalidate block if it is not valid */
      result = ApplFblClrModulePresence(&localBlockDescriptor);
# else
      result = ApplFblChgBlockValid(kEepInvalidateBlock, localBlockDescriptor);
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
   }

   /* Write fingerprint (from RAM buffer) into meta data table */
   result |= ApplFblNvWriteFingerprint((IO_PositionType)nvModuleId, blockFingerprint);

   return result;
}

/***********************************************************************************************************************
 *  ApplFblIsValidBlock
 **********************************************************************************************************************/
/*! \brief       Check if a logical block is valid or not.
 *  \param[in]   blockNr The number of the logical block.
 *  \return      Returns kFblOk if the logical block is valid. Otherwise it returns kFblFailed.
 **********************************************************************************************************************/
tFblResult ApplFblIsValidBlock( vuint8 blockNr )
{
#if defined( FBL_ENABLE_PRESENCE_PATTERN )
   tBlockDescriptor blockDescriptor;
#else
   vuint8      validityFlags[kEepSizeValidityFlags];
   vuint8      validityMask;
   vuint8      byteIdx;
#endif
   tFblResult  result;

   /* Assume block is invalid */
   result = kFblFailed;

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
   /* Get logical block data structure */
   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      /* Check presence pattern in logical block */
      if (ApplFblChkModulePresence(&blockDescriptor) == kFblOk)
      {
    	  if(blockNr == FBL_LBT_MCU10_APPLICATION_LB_BLOCK_NUMBER)
    	  {
    		  if(ApplFblChkApplPresence(&blockDescriptor) == kFblOk)
    		  {
    			  result = kFblOk;
    		  }
    	  }
    	  else
    	  {
    		  result = kFblOk;
    	  }
      }
   }
#else
   /* Calculate index and mask for validity bit of logical block */
   byteIdx        = (blockNr >> 0x03u);
   validityMask   = (vuint8)(0x01u << (blockNr & 0x07u));

   /* Read validity information from non-volatile memory */
   if (ApplFblNvReadValidityFlags(validityFlags) == kFblOk)
   {
      if ((validityFlags[byteIdx] & validityMask) == 0u)
      {
         /* Block is valid */
         result = kFblOk;
      }
   }
#endif /* FBL_ENABLE_PRESENCE_PATTERN */
   return result;
}

#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
/***********************************************************************************************************************
 *  ApplFblRWSecurityAccessDelayFlag
 **********************************************************************************************************************/
/*! \brief       Read/write security access delay flag.
 *  \details     In read mode, the function will return the current value of the security access delay flag. In write
 *               mode it will return the return code of the EEPROM driver.
 *  \param[in]   mode The mode to be used (kEepReadData/kEepWriteData)
 *  \param[in]   value The value to be written
 *  \return      Status of access delay flag/return code of EEPROM driver
 **********************************************************************************************************************/
vuint8 ApplFblRWSecurityAccessDelayFlag( vuint8 mode, vuint8 value )
{
   tFblResult readResult;
   vuint8 buffer;
   vuint8 result;

   /* Read security access delay flag */
   readResult = (tFblResult)ApplFblNvReadSecAccessDelayFlag(&buffer);

   if (mode == kEepWriteData)
   {
      /* Check if read was successful and if the new value is already stored in memory */
      if ((readResult == kFblOk) && (buffer == value))
      {
         result = kFblOk;
      }
      else
      {
         buffer = value;
         result = ((tFblResult)ApplFblNvWriteSecAccessDelayFlag(&buffer));
      }
   }
   else
   {
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
      /* Parameters not used: avoid compiler warning */
      (void)value;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif
      /* Check if read was successful */
      if (readResult == kFblOk)
      {
         result = buffer;
      }
      else
      {
         /* Read failed */
         result = kEepSecAccessDelayActive;
      }
   }

   return result;
}
#endif

/***********************************************************************************************************************
 *  ApplFblStoreFingerprint
 **********************************************************************************************************************/
/*! \brief       This function is called by the WriteDataByIdentifier service
 *               to store the received fingerprint in a temporary RAM buffer.
 *  \details     The fingerprint is written into a non-volatile memory when the corresponding logical block is invalidated.
 *  \param[in]   buffer Pointer to received fingerprint
 *  \return      kFblOk = fingerprint successfully stored
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblStoreFingerprint( vuint8 * buffer )
{
   /* Copy Fingerprint - programmingDate and repairShopCodeOrTesterSerialNumber */
   /* PRQA S 0314 1 */ /* MD_FblKbApiOem_0314_MemCpy */
   (void)MEMCPY(blockFingerprint, buffer, kEepSizeFingerprint);

   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblStoreBootFingerprint
 **********************************************************************************************************************/
/*! \brief       This function is called by the WriteDataByIdentifier service
 *               to store the received boot software fingerprint.
 *  \details     This function can be used to store a bootloader fingerprint in NV memory.
 *  \param[in]   blockDescriptor Describes the logical block to which the current fingerprint belongs
 *  \param[in]   buffer Pointer to received fingerprint
 *  \return      kFblOk = fingerprint successfully stored
 **********************************************************************************************************************/
tFblResult ApplFblStoreBootFingerprint( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
   const vuint8 * buffer )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)blockDescriptor;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
   (void)buffer;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif
   /* ToDo: Store boot software fingerprint in NVM if supported */

   /* Per default, WriteDataById - writeBootSoftwareFingerprint is not supported */
   DiagNRCRequestOutOfRange();

   return kFblFailed;
}

/***********************************************************************************************************************
 *  ApplFblErrorNotification
 **********************************************************************************************************************/
/*! \brief       Call-back function for diagnostic trouble code entries.
 *  \details     This function is called whenever a flash programming error occurred.
 *  \param[in]   errorType The error type
 *  \param[in]   errorCode The error code
 **********************************************************************************************************************/
void ApplFblErrorNotification( tFblErrorType errorType, tFblErrorCode errorCode )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)errorType;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
   (void)errorCode;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif
}


/***********************************************************************************************************************
 *  ApplFblIncProgCounts
 **********************************************************************************************************************/
/*! \brief       Increment programming counter
 *  \param[in]   blockDescriptor Block descriptor
 *  \return      kFblOk / kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblIncProgCounts( tBlockDescriptor blockDescriptor )
{
   tFblApnvProgCountType progCounts;
   vuint8 nvBuffer[sizeof(tFblApnvProgCountType)];
   tFblResult status;

   status = (tFblResult)ApplFblNvReadProgCounter((IO_PositionType)blockDescriptor.blockNr, nvBuffer);
   progCounts = (tFblApnvProgCountType)FblMemGetInteger(sizeof(nvBuffer), nvBuffer);

   if (status == kFblOk)
   {
      /* Value is stored inverted because of erase value */
      progCounts = FblInvert16Bit(progCounts);
      progCounts++;
      progCounts = FblInvert16Bit(progCounts);

      FblMemSetInteger(sizeof(nvBuffer), progCounts, nvBuffer);
      status = (tFblResult)ApplFblNvWriteProgCounter((IO_PositionType)blockDescriptor.blockNr, nvBuffer);
   }

   return status;
}

/***********************************************************************************************************************
 *  ApplFblGetProgCounts
 **********************************************************************************************************************/
/*! \brief       Get programming counter
 *  \param[in]   blockDescriptor Block descriptor
 *  \param[in]   progCounts The programming counter
 *  \return      kFblOk / kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblGetProgCounts( tBlockDescriptor blockDescriptor, V_MEMRAM1 vuint16 V_MEMRAM2 V_MEMRAM3 * progCounts)
{
   tFblResult status;
   vuint8 nvBuffer[sizeof(tFblApnvProgCountType)];
   tFblApnvProgCountType tempCount;

   status = (tFblResult)ApplFblNvReadProgCounter((IO_PositionType)blockDescriptor.blockNr, nvBuffer);

   tempCount = (tFblApnvProgCountType)FblMemGetInteger(sizeof(nvBuffer), nvBuffer);
   tempCount = FblInvert16Bit(tempCount);
   *progCounts = (vuint16)tempCount;

   return status;
}

/***********************************************************************************************************************
 *  ApplFblIncProgAttempts
 **********************************************************************************************************************/
/*! \brief       Increment programming attempt counter
 *  \param[in]   blockDescriptor Block descriptor
 *  \return      kFblOk / kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblIncProgAttempts( tBlockDescriptor blockDescriptor )
{
   tFblApnvProgCountType progAttempts;
   vuint8 nvBuffer[sizeof(tFblApnvProgCountType)];
   tFblResult status;

   status = (tFblResult)ApplFblNvReadProgAttempts((IO_PositionType)blockDescriptor.blockNr, nvBuffer);
   progAttempts = (tFblApnvProgCountType)FblMemGetInteger(sizeof(nvBuffer), nvBuffer);

   if (status == kFblOk)
   {
      /* Value is stored inverted because of erase value */
      progAttempts = FblInvert16Bit(progAttempts);
      progAttempts++;
      progAttempts = FblInvert16Bit(progAttempts);

      FblMemSetInteger(sizeof(nvBuffer), progAttempts, nvBuffer);
      status = (tFblResult)ApplFblNvWriteProgAttempts((IO_PositionType)blockDescriptor.blockNr, nvBuffer);
   }

   return status;
}

/***********************************************************************************************************************
 *  ApplFblGetProgAttempts
 **********************************************************************************************************************/
/*! \brief       Get programming attempt counter
 *  \param[in]   blockDescriptor Block descriptor
 *  \param[out]  progAttempts The returned programming attempts
 *  \return      kFblOk / kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblGetProgAttempts( tBlockDescriptor blockDescriptor, V_MEMRAM1 vuint16 V_MEMRAM2 V_MEMRAM3 * progAttempts )
{
   tFblResult status;
   vuint8 nvBuffer[sizeof(tFblApnvProgCountType)];
   tFblApnvProgCountType tempCount;

   /* Send response pending in case of long NV accesses */
   DiagExRCRResponsePending(kForceSendResponsePending);

   status = (tFblResult)ApplFblNvReadProgAttempts((IO_PositionType)blockDescriptor.blockNr, nvBuffer);
   tempCount = (tFblApnvProgCountType)FblMemGetInteger(sizeof(nvBuffer), nvBuffer);
   tempCount = FblInvert16Bit(tempCount);
   *progAttempts = (vuint16)tempCount;

   return status;
}

# if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
/***********************************************************************************************************************
 *  ApplFblWriteSecAccessInvalidCount
 **********************************************************************************************************************/
/*! \brief       Write number of invalid security access attempts
 *  \param[in]   invalidCount Number of the invalid security access attempts
 *  \return      kFblOk / kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblWriteSecAccessInvalidCount( V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * invalidCount )
{
   vuint8 buffer;

   buffer = FblInvert8Bit(*invalidCount);

   return (tFblResult)ApplFblNvWriteSecAccessInvalidCount(&buffer);
}

/***********************************************************************************************************************
 *  ApplFblGetSecAccessInvalidCount
 **********************************************************************************************************************/
/*! \brief       Read number of invalid security access attempts
 *  \param[out]  invalidCount The returned number of invalid security access attempts
 *  \return      kFblOk / kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblReadSecAccessInvalidCount( V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * invalidCount )
{
   tFblResult status;

   status = (tFblResult)ApplFblNvReadSecAccessInvalidCount(invalidCount);

   if (status == kFblOk)
   {
      *invalidCount = FblInvert8Bit(*invalidCount);
   }
   else
   {
      *invalidCount = 0u;
   }

   return status;
}
# endif /* FBL_ENABLE_SEC_ACCESS_DELAY */

#if defined( SEC_ENABLE_CRC_TOTAL )
/***********************************************************************************************************************
 *  ApplFblWriteCRCTotal
 **********************************************************************************************************************/
/*! \brief       Store CRC total. String buffer used to avoid little/big endian permutation.
 *  \param[in]   blockDescriptor Block descriptor
 *  \param[in]   crcStart Start address of CRC calculation
 *  \param[in]   crcLength Length of CRC calculation
 *  \param[in]   crcValue The CRC value
 *  \return      kFblOk / kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblWriteCRCTotal( V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor, vuint32 crcStart, vuint32 crcLength, vuint32 crcValue )
{
   tFblResult status;
   vuint8 strConversionBuffer[4u];

   status = kFblOk;

# if ( kEepSizeCRCStart  != 4u ) || \
     ( kEepSizeCRCLength != 4u ) || \
     ( kEepSizeCRCValue  != 4u )
#  error "Error in fbl_apnv.c: Configuration error (kEepSizeCRC... != 4)"
# endif

   FblMemSetInteger(kEepSizeCRCStart, crcStart, strConversionBuffer);
   status |= (tFblResult)ApplFblNvWriteCRCStart(blockDescriptor->blockNr, strConversionBuffer);

   FblMemSetInteger(kEepSizeCRCLength, crcLength, strConversionBuffer);
   status |= (tFblResult)ApplFblNvWriteCRCLength(blockDescriptor->blockNr, strConversionBuffer);

   FblMemSetInteger(kEepSizeCRCValue, crcValue, strConversionBuffer);
   status |= (tFblResult)ApplFblNvWriteCRCValue(blockDescriptor->blockNr, strConversionBuffer);

   return status;
}
#endif /* SEC_ENABLE_CRC_TOTAL */

/***********************************************************************************************************************
 *  ApplFblValidateApp
 **********************************************************************************************************************/
/*! \brief       Function is called after a successful download to validate a file.
 *  \pre         Complete file must be successfully downloaded
 *  \return      kFblOk = validation successfully performed, kFblFailed = validation failed
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
tFblResult ApplFblValidateApp( void )
{
   tFblResult result;
#if defined( FBL_ENABLE_PRESENCE_PATTERN )
#else
   vuint8 applValidity;
#endif /* FBL_ENABLE_PRESENCE_PATTERN */
   vuint8 applUpdate;

   /* Local variables for update of NVM-data */
   vuint8 buffer[kApplInfoSizeCodepEcupartNumber_F187];
   tFblAddress applHdrAddr;

   /* Update Programming Status, application and data valid */
   result = ApplFblProgStatusUpdate(kDiagProgStatAppl | kDiagProgStatData, 0u);

   applHdrAddr = ApplFblGetModuleHeaderAddress(kFblBlockNumberOfIdentification);

   /* Read EBOM ECU Part Number from logical block and update NVM */
 /*  (void)FblReadProm(applHdrAddr + kApplInfoOffsetEbomEcuPartNumber, buffer, kApplInfoSizeEbomEcuPartNumber);

   result |= ApplFblNvWriteEbomEcuPartNumber(buffer);

    Read CODEP ECU Part Number from logical block and update NVM
   (void)FblReadProm(applHdrAddr + kApplInfoOffsetCodepEcuPartNumber, buffer, kApplInfoSizeCodepEcuPartNumber);
   result |= ApplFblNvWriteCoDePEcuPartNumber(buffer);

    Read EROTAN from logical block and update NVM
   (void)FblReadProm(applHdrAddr + kApplInfoOffsetExhaustRegulationTan, buffer, kApplInfoSizeExhaustRegulationTan);
   result |= ApplFblNvWriteExhaustRegulationTan(buffer);*/

   if (result == kFblOk)
   {
# if defined( FBL_ENABLE_PRESENCE_PATTERN )

	   if(MCU_1_InvalidateFlag == TRUE)
	   {
		   FblLbtGetBlockDescriptorByNr(FBL_LBT_MCU10_APPLICATION_LB_BLOCK_NUMBER, &currentValidatedBlock);
		   /* Set presence pattern in last flashed logical block. */
		   result = ApplFblSetApplPresence(&currentValidatedBlock);
	   }
# else
      applValidity = kEepApplConsistent;
      result = (tFblResult)ApplFblNvWriteApplValidity(&applValidity);
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
      /* Application has been updated - set flag in NVM */
      applUpdate = kEepApplUpdate;
      result |= ApplFblNvWriteApplUpdate(&applUpdate);
   }

   return result;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  ApplFblInvalidateApp
 **********************************************************************************************************************/
/*! \brief       Function is called before erasure of the application
 *  \return      kFblOk = invalidation successfully performed, kFblFailed = invalidation failed
 **********************************************************************************************************************/
tFblResult ApplFblInvalidateApp(tBlockDescriptor blockDescriptor)
{
   tFblResult result;

# if defined( FBL_ENABLE_PRESENCE_PATTERN )

# else
   vuint8 applValidity;
# endif /* FBL_ENABLE_PRESENCE_PATTERN */

   /* Update Programming Status, application and data not valid */
   (void)ApplFblProgStatusUpdate(0u, kDiagProgStatAppl | kDiagProgStatData);

# if defined( FBL_ENABLE_PRESENCE_PATTERN )
   result = ApplFblClrApplPresence(&blockDescriptor);
# else
   applValidity = kEepApplInconsistent;
   result = (tFblResult)ApplFblNvWriteApplValidity(&applValidity);
# endif /* FBL_ENABLE_PRESENCE_PATTERN */

   return result;
}

/***********************************************************************************************************************
 *  ApplFblGetBlockHash
 **********************************************************************************************************************/
/*! \brief       Provides the logical block hash of requested block
 *  \details     This function is called when the diagnostic service
 *               RoutineControl-blockHash is received. If the requested
 *               block is valid, the hash is copied into the given buffer.
 *  \param[in]   blockNr Number of requested logical block
 *  \param[out]  targetBuffer Output data buffer (diagnostics buffer )
 *  \return      kFblOk / kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblGetBlockHash( vuint8 blockNr, vuint8 *targetBuffer )
{
   tBlockDescriptor blockDescriptor;
   tFblAddress hashAddress;
   vuint8      index;
   tFblResult  result;

   /* Check if requested logical block is valid */
   result = ApplFblIsValidBlock(blockNr);

   if (result == kFblOk)
   {
      /* Logical block is valid */
#if ( SEC_SECURITY_CLASS == SEC_CLASS_VENDOR ) && defined ( FBL_APPL_ENABLE_SHA256_BLOCKHASH )
      tBlockDescriptor blockDescriptor;
      tFblBmHdrHeader bmHeader;

      /* Get block descriptor of requested logical block from corresponding BM Header */
      result = FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor);

      if (result == kFblOk)
      {
         /* Read and check BM Header */
         if (FblReadProm(blockDescriptor.bmHeaderAddress, (vuint8 *)&bmHeader, sizeof(bmHeader)) != sizeof(bmHeader))
         {
            result = kFblFailed;
         }
         else
         {
            result = FblBmHdrCheckConsistency(&bmHeader);
         }
      }
      if (result == kFblOk)
      {
         uint32 signatureAddress;
         uint32 signatureLength;

         /* Extract the signature position, which is the FCA header */
         ApplFblSbGetSignatureInfo(&blockDescriptor, &bmHeader, &signatureAddress, &signatureLength);
         hashAddress = signatureAddress + kFcaHdrOffsetFileDigest;
      }
#else
      result = FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor);
      if (result == kFblOk)
         {
            /* Get header address of requested logical block */
            hashAddress = blockDescriptor.blockStartAddress + kFcaHdrOffsetFileDigest ;
         }
#endif /* SEC_SECURITY_CLASS == SEC_CLASS_VENDOR && FBL_APPL_ENABLE_SHA256_BLOCKHASH */
      if (result == kFblOk) /* PRQA S 2991, 2995 */ /* MD_FblKbApiFrame_2991_2995 */
      {
         /* Copy block hash */
         if (FblReadProm(hashAddress, targetBuffer, SECM_HASH_SIZE) != SECM_HASH_SIZE)
         {
            result = kFblFailed;
         }
      }
   }
   else
   {
      /* Logical block not valid - fill hash with flash erase code */
      /* Relevant if e.g. the previous download was only partly performed, */
      for (index = 0u; index < SECM_HASH_SIZE; index++)
      {
         targetBuffer[index] = FBL_FLASH_DELETED;
      }
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblProgStatusUpdate
 **********************************************************************************************************************/
/*! \brief       Update the programming status information in NVM
 *  \details     This function updates bytes 0
 *               Bit 0: 0: Running in boot, 1: Running in application
 *               Bit 1: 0: Application not valid, 1: Application valid
 *               Bit 2: 0: Data not valid, 1: Data valid
 *  \param[in]   progStatSet Programming status flags that shall be set
 *  \param[in]   progStatClr Programming status flags that shall be cleared
 *  \return      kFblOk / kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblProgStatusUpdate(vuint8 progStatSet, vuint8 progStatClr)
{
   vuint8 progStatBuffer[2];
   tFblResult result;

   result = ApplFblNvReadProgrammingStatus(progStatBuffer);
   if (result == kFblOk)
   {
      /* Set/ clear new programming status */
      progStatBuffer[kDiagProgStat] |= (progStatSet & 0x07u);
      progStatBuffer[kDiagProgStat] &= FblInvert8Bit(progStatClr & 0x07u);

      /* Reserved bits must be set to 1 */
      progStatBuffer[kDiagProgStat] |= kDiagProgStatReserved;

      result = ApplFblNvWriteProgrammingStatus(progStatBuffer);
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblProgStatusEraseUpdate
 **********************************************************************************************************************/
/*! \brief       Update the Erase Verification status information in NVM
 *  \details     This function updates bytes 1
 *               00: Erase Compleded Successfully
 *               01: Erase Failed general failure
 *               02: Erase Failed voltage too high
 *               03: Erase Failed voltage too low
 *               04: Erase Failed temperature too high
 *               05: Erase Failed temperature too low
 *  \param[in]   eraseVer Erase verification status
 *  \return      kFblOk / kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblProgStatusEraseUpdate(vuint8 eraseVer)
{
   vuint8 progStatBuffer[2];
   tFblResult result;

   result = ApplFblNvReadProgrammingStatus(progStatBuffer);
   if (result == kFblOk)
   {
      /* Set new Erase Verification status */
      progStatBuffer[kDiagProgStatEraseVer] = eraseVer;
      result = ApplFblNvWriteProgrammingStatus(progStatBuffer);
   }

   return result;
}


#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
/***********************************************************************************************************************
 *  ApplFblGetBlockErased
 **********************************************************************************************************************/
/*! \brief       Function is called by the diagnostic layer to check if the erase procedure can be omitted or not.
 *  \param[in]   blockDescriptor Block descriptor structure with information about the region
 *  \return      kFlashErased = Region is in erased state, kFlashNotErased = Region is not in erased state
 **********************************************************************************************************************/
tFlashStatus ApplFblGetBlockErased( tBlockDescriptor blockDescriptor )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)blockDescriptor;   /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

   /* This function is called when the Memory Status Information in  *
    * the NVM is in state "erased".                                  *
    *                                                                *
    * Please note, that this function may be also called for other   *
    * memory devices types than flash if multiple memory devices are *
    * configured (e.g. EEPROM).                                      */

   /* ToDo: Make sure that the given logical block is really erased. *
    *       Otherwise, kFlashNotErased must be returned.             */

   return kFlashNotErased;
}
#endif /* FBL_ENABLE_FLASH_ERASED_DETECTION */

/***********************************************************************************************************************
 *  ApplFblWriteSegmentList
 **********************************************************************************************************************/
/*! \brief       Store the segment list structure.
 *  \details     The segment list structure must be stored to be able to calculate the checksum again when a
 *               RoutineControl-VerifyMemoryContent request is received.
 *  \param[in]   blockNr Correlates to the member of tBlockDescriptor to identify the logical block
 *  \param[in]   segmentList Structure was passed to the security module to calculate the signature/checksum
 *  \return      Returns kFblOk if the write operation was successful. Otherwise it returns kFblFailed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblWriteSegmentList( vuint8 blockNr, V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * segmentList )
{
   tFblResult result;
   vuint8 segmentAddrList[kEepSizeSegmentAddrList];
   vuint8 segmentLengthList[kEepSizeSegmentLengthList];
   vuint8 segmentCount[kEepSizeSegmentCount];
   vuint32 moduleId;
   vuintx segIndx;

   moduleId = ApplFblGetNvModuleId(blockNr);

   /* Verify parameters */ /* PRQA S 2742, 2880 2 */ /* MD_FblKbApiOem_2742, MD_MSR_Unreachable */
   assertFblInternal(sizeof(segmentList->segmentInfo[0u].length) == sizeof(vuint32), kFblOemAssertParameterOutOfRange);
   assertFblInternal(segmentList->nrOfSegments <= SWM_DATA_MAX_NOAR, kFblOemAssertParameterOutOfRange);

   /* Serialize count, address- and length information */
   FblMemSetInteger(kEepSizeSegmentCount, segmentList->nrOfSegments, segmentCount);
   for (segIndx = 0u; segIndx < segmentList->nrOfSegments; segIndx++)
   {
      FblMemSetInteger(sizeof(vuint32), segmentList->segmentInfo[segIndx].targetAddress, &segmentAddrList[segIndx * sizeof(vuint32)]);
      FblMemSetInteger(sizeof(vuint32), segmentList->segmentInfo[segIndx].length, &segmentLengthList[segIndx * sizeof(vuint32)]);
   }

   /* Store data in non-volatile memory */
   result = ApplFblNvWriteSegmentCount((IO_PositionType)moduleId, segmentCount);
   result |= (tFblResult)ApplFblNvWriteSegmentAddrList((IO_PositionType)moduleId, segmentAddrList);
   result |= (tFblResult)ApplFblNvWriteSegmentLengthList((IO_PositionType)moduleId, segmentLengthList);

   return result;
}

/***********************************************************************************************************************
 *  ApplFblReadSegmentList
 **********************************************************************************************************************/
/*! \brief       Retrieve the whole segment list structure.
 *  \details     The whole segment list structure must be retrieved to calculate the checksum again after a
 *               RoutineControl-VerifyMemoryContent request was received.
 *  \param[in]   blockNr Correlates to the member of tBlockDescriptor to identify the logical block
 *  \param[out]  segmentList Structure will be passed to the security module to calculate the signature/checksum again
 *  \return      Returns kFblOk if the read operation was successful. Otherwise it returns kFblFailed.
 **********************************************************************************************************************/
tFblResult ApplFblReadSegmentList( vuint8 blockNr, V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * segmentList )
{
   tFblResult result;
   vuint8 segmentAddrList[kEepSizeSegmentAddrList];
   vuint8 segmentLengthList[kEepSizeSegmentLengthList];
   vuint8 segmentCount[kEepSizeSegmentCount];
   vuintx segIndx;
   V_MEMRAM1 FL_SegmentInfoType V_MEMRAM2 V_MEMRAM3 * segInfo;
   vuint32 moduleId;

   moduleId = ApplFblGetNvModuleId(blockNr);

   result = ApplFblNvReadSegmentCount(moduleId, segmentCount);
   if (result == kFblOk)
   {
      /* De-serialze data from non-volatile memory */
      segmentList->nrOfSegments = FblMemGetInteger(kEepSizeSegmentCount, segmentCount);
      assertFblInternal(segmentList->nrOfSegments <= SWM_DATA_MAX_NOAR, kFblOemAssertParameterOutOfRange);

      result = ApplFblNvReadSegmentAddrList(moduleId, segmentAddrList);
      result |= (tFblResult)ApplFblNvReadSegmentLengthList(moduleId, segmentLengthList);
   }

   if (result == kFblOk)
   {
      segInfo = segmentList->segmentInfo;

      for (segIndx = 0u; segIndx < segmentList->nrOfSegments; segIndx++)
      {
         /* De-serialze data from non-volatile memory */
         segInfo[segIndx].transferredAddress = FblMemGetInteger(sizeof(vuint32), &segmentAddrList[segIndx * sizeof(vuint32)]);
         segInfo[segIndx].targetAddress = segInfo[segIndx].transferredAddress;
         segInfo[segIndx].length = FblMemGetInteger(sizeof(vuint32), &segmentLengthList[segIndx * sizeof(vuint32)]);
      }
   }

   return result;
}


/***********************************************************************************************************************
 *  ApplFblGetModuleId
 **********************************************************************************************************************/
/*! \brief       Function is called to get module idx for NV data structure
 *  \param[in]   blockNr Logical block number
 *  \return      Module idx for NV data structure
 **********************************************************************************************************************/
vuint32 ApplFblGetNvModuleId(tFblLbtBlockNr blockNr)
{
   vuint32 nvmModuleIndex;
   nvmModuleIndex = blockNr;

   return nvmModuleIndex;
}

/***********************************************************************************************************************
 *  ParseUTCGeneralizedTime
 **********************************************************************************************************************/
/*! \brief       Parse UTC/Generalized Time from ASCII timestamp received from user certificate
 *  \param[in]   timeElementPtr - Pointer to timestamp array received from user certificate
 *               timeElementDataLength - timestamp array length
 *  \param[out]  parsedTimePtr - Pointer to parsed UTC/Generalized Time
 *  \return      retVal - E_OK/E_NOT_OK
 **********************************************************************************************************************/
Std_ReturnType ParseUTCGeneralizedTime(P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) timeElementPtr,
                                       uint16 timeElementDataLength,
                                       P2VAR(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) parsedTimePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) timeElement = timeElementPtr;

  /* ----- Implementation ----------------------------------------------- */
  /* Generally:
  * UTC Formats:
  *    YYMMDDhhmm[ss]Z
  *    YYMMDDhhmm[ss](+|-)hhmm
  *  Generalized Time Formats:
  *    YYYYMMDDHH[MM[SS[.fff]]]
  *    YYYYMMDDHH[MM[SS[.fff]]]Z
  *    YYYYMMDDHH[MM[SS[.fff]]](+|-)HHMM
  */

  /* # Only UTC or Generalized Time with non-optional minutes and seconds are supported,
  *  milliseconds [.fff] and difference to local time (+|-)HHMM is not supported. */

  /* # Check that last sign is a 'Z' 0x5A. */
  if (timeElement[timeElementDataLength - 1u] != 0x5Au)
  {
    retVal = E_NOT_OK;
  }

  if (retVal == E_OK)
  {
    /* # If the element data length is 13, extract the year according to the UTC format. */
    if (timeElementDataLength == 13u)
    {
      /* UTC time with 2 digits Year */
      parsedTimePtr->year = ((uint16)timeElement[0] - 0x30u) * 10u;
      parsedTimePtr->year += (uint16)timeElement[1u] - 0x30u;

      if (parsedTimePtr->year >= 50u)
      {
        parsedTimePtr->year += 1900u;
      }
      else
      {
        parsedTimePtr->year += 2000u;
      }
      timeElement = &(timeElement[2u]);
    }
    /* # If the element data length is 15, extract the year according to the Generalized Time format. */
    else if (timeElementDataLength == 15u)
    {
      /* Generalized time with 4 digits Year */
      parsedTimePtr->year = (((uint16)timeElement[0u] - 0x30u) * 1000u);
      parsedTimePtr->year += ((((uint16)timeElement[1u] - 0x30u) * 100u));
      parsedTimePtr->year += ((((uint16)timeElement[2u] - 0x30u) * 10u));
      parsedTimePtr->year += (((uint16)timeElement[3u] - 0x30u));
      timeElement = &(timeElement[4u]);
    }
    else
    {
      /* invalid time format */
      retVal = E_NOT_OK;
    }
  }

  if (retVal == E_OK)
  {
    /* # Extract the remaining date and time information without differentiating between UTC and
    * Generalized Time format. */
    parsedTimePtr->month = (uint8)((timeElement[0u] - 0x30u) * 10u);
    parsedTimePtr->month += ((uint8)(timeElement[1u] - 0x30u));
    parsedTimePtr->day = (uint8)((timeElement[2u] - 0x30u) * 10u);
    parsedTimePtr->day += ((uint8)(timeElement[3u] - 0x30u));
    parsedTimePtr->hour = (uint8)((timeElement[4u] - 0x30u) * 10u);
    parsedTimePtr->hour += ((uint8)(timeElement[5u] - 0x30u));
    parsedTimePtr->minute = (uint8)((timeElement[6u] - 0x30u) * 10u);
    parsedTimePtr->minute += ((uint8)(timeElement[7u] - 0x30u));
    parsedTimePtr->second = (uint8)((timeElement[8u] - 0x30u) * 10u);
    parsedTimePtr->second += ((uint8)(timeElement[9u] - 0x30u));
  }

  return retVal;
}

/***********************************************************************************************************************
 *  ConvertDateToUnixTime
 **********************************************************************************************************************/
/*! \brief       Convert Date/time received from ParseUTCGeneralizedTime() To Unix Time
 *  \param[in]   date - received from ParseUTCGeneralizedTime()
 *  \param[out]  unixTime - unix/epoch Time
 *  \return      retVal - E_OK/E_NOT_OK
 **********************************************************************************************************************/
Std_ReturnType ConvertDateToUnixTime(
  P2CONST(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) date,
  P2VAR(uint32, AUTOMATIC, AUTOMATIC) unixTime)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  uint32 y;
  uint32 m;
  uint32 d;

  /* ----- Implementation ----------------------------------------------- */
  /* Year */
  y = date->year;
  /* Month of year */
  m = date->month;
  /* Day of month */
  d = date->day;

  /* January and February are counted as months 13 and 14 of the previous year */
  if (m <= 2u)
  {
    m += 12u;
    y -= 1u;
  }

  /* # Convert years to days */
  /* A leap year must be evenly divisible by 4. If the year can also be evenly divided by 100, it is not a leap year, unless
     the year is also evenly divisible by 400. */
  *unixTime = ((365u * y) + (y / 4u) - (y / 100u) + (y / 400u));

  /* # Convert months to days */
  /* This formula takes into account the uneven number of days in the months across a year */
  *unixTime += ((30u * m) + (3u * (m + 1u) / 5u) + d);

  /* # Unix time starts on January 1st, 1970 */
  if (*unixTime < 719561u)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    *unixTime -= 719561u;
    /* # Convert days to seconds */
    *unixTime *= 86400u;
    /* # Add hours, minutes and seconds */
    *unixTime += ((3600u * (uint32)(date->hour)) + (60u * (uint32)(date->minute)) + (uint32)(date->second));
  }

  return retVal;
}

/***********************************************************************************************************************
 *  getTimeStamp
 **********************************************************************************************************************/
/*! \brief       return TimeStamp from secure logging
 *  \param[in]   None
 *  \param[out]  None
 *  \return      TimestampCounter - System timestamp + Seconds elapsed since certificate acceptance
 **********************************************************************************************************************/
uint32 getTimeStamp(void)
{
    uint32 LatestTimeStamp;
    /* TimeStamp = SystemTimeStamp(notBeforeTime of Certificate) + Elapsed seconds since last IGN ON */
    LatestTimeStamp = TimestampCounter + SecondCounter;

    return LatestTimeStamp;
}

/***********************************************************************************************************************
 *  getEpochTime
 **********************************************************************************************************************/
/*! \brief       return TimeStamp from secure logging
 *  \param[in]   LocSystemTime - Latest system time
 *  \param[out]  LocTimestampCounter - Timestamp in epoch format
 *  \return      retVal - E_OK/E_NOT_OK
 **********************************************************************************************************************/
Std_ReturnType getEpochTime(uint8* LocSystemTime, uint32* LocTimestampCounter)
{
    Std_ReturnType retVal = E_NOT_OK;
    CertDateTimeType_t UTCGenTime = {0};

    if (LocSystemTime != NULL_PTR)
    {
        retVal = ParseUTCGeneralizedTime(LocSystemTime, 15, &UTCGenTime);
        if(retVal == E_OK)
        {
            retVal = ConvertDateToUnixTime(&UTCGenTime, LocTimestampCounter);
        }
    }
    else
    {
        /* Do Nothing */
    }

    return retVal;
}

/***********************************************************************************************************************
 *  TimeStampIncrement
 **********************************************************************************************************************/
/*! \brief       Increment Seconds counter
 *  \param[in]   None
 *  \param[out]  None
 *  \return      None
 **********************************************************************************************************************/
void TimeStampIncrement(void)
{
	static uint8 flag = 0;

    if(IsSystemTimeSet != FALSE)
    {
        IncCounter += 1;

        /* % by 1000m because IncCounter is incremented once every 1ms */
        if((IncCounter % 1000) == 0)
        {
            /* Increment seconds passed */
        	SecondCounter += 1;
            if(CheckCertSessionValid == TRUE)
            {
                /* Increment seconds passed in current extended session */
                SessionSecondCounter += 1;
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
    	/* Do Nothing */
    }

}

/***********************************************************************************************************************
 *  CheckAuthCertiValidity
 **********************************************************************************************************************/
/*! \brief       Check validity of authenticated certificate based on session counter
 *  \param[in]   None
 *  \param[out]  None
 *  \return      None
 **********************************************************************************************************************/
void CheckAuthCertiValidity(void)
{
    uint32 LatestTimeStamp = 0;

    /* Get latest timestamp value */
    LatestTimeStamp = TimestampCounter + SessionSecondCounter;
    /* Check if received certificate is already expired OR if latest timestamp is greater than not-after time of certificate */
    if((CertificateExpired == TRUE) || (LatestTimeStamp > NotAfterEpochFormat))
    {
    	CheckCertSessionValid = FALSE;
    	/* Set certificate expired flag */
    	CertificateExpired = TRUE;
        ApplFblNvWriteCertificateExpired(&CertificateExpired);
        /* Request bootloader reset */
        FblSetShutdownRequest();
    }
}

/***********************************************************************************************************************
 *  ApplFblSaveCertTimeInfo
 **********************************************************************************************************************/
/*! \brief       Save Certificate Time Information and check if received cert has already expired based on session second counter
 *  \param[in]   None
 *  \param[out]  None
 *  \return      None
 **********************************************************************************************************************/
tFblResult ApplFblSaveCertTimeInfo(void)
{
    tFblResult ret_val = kFblOk;
    sint8 CompResult = 0;

    KeyElementID[0] = 0;
    KeyElementID[1] = 9 ;  /* Assign not after time Element id from certificate */
    Csm_AEADEncrypt(CsmConf_CsmJob_CsmJob_GetRoleFromTesterCertificate,CRYPTO_OPERATIONMODE_SINGLECALL,&KeyElementID[0], 2,NULL_PTR, 0,&NotAfterTime[0],&NotAfterTimeLen,NULL_PTR,NULL_PTR);

    /* Store latest not after time in epoch format in TimestampCounter */
    getEpochTime(&NotAfterTime[0], &NotAfterEpochFormat);

    KeyElementID[0] = 0;
    KeyElementID[1] = 8 ;  /* Assign not before time Element id from certificate */
    Csm_AEADEncrypt(CsmConf_CsmJob_CsmJob_GetRoleFromTesterCertificate,CRYPTO_OPERATIONMODE_SINGLECALL,&KeyElementID[0], 2,NULL_PTR, 0,&NotBeforeTime[0],&NotBeforeTimeLen,NULL_PTR,NULL_PTR);
    CompResult = VStdLib_MemCmpLarge(&NotBeforeTime[0], &SystemTime[0], 15);

    if(CompResult > 0)
    {
        /* Enable flag to check session validity using second counter */
        CheckCertSessionValid = TRUE;

        CertificateExpired = FALSE;
        ApplFblNvWriteCertificateExpired(&CertificateExpired);

        /* Save latest System time in NvM if latest retrieved system time from certificate is not equal to stored system time */
        VStdLib_MemCpyLarge(&SystemTime[0],&NotBeforeTime[0], 15);
        ApplFblNvWriteSystemTimestamp(&SystemTime[0]);
        IsSystemTimeSet = TRUE;

        /* Reset Second counter to 0 */
        SecondCounter = 0;
        SessionSecondCounter = 0;
        ApplFblNvWriteSecondCounter(&SecondCounter);

        /* Store latest system time in epoch format in TimestampCounter */
        getEpochTime(&SystemTime[0], &TimestampCounter);
        /* Set Current time and second counter in HSM */
        Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_CurrentTimeStamp,CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_CryptoKeyElement_CurrentTimeStamp,SystemTime,15);
        Csm_KeySetValid(CsmConf_CsmKey_CsmKey_CurrentTimeStamp);
        Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_SecondCounter,CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_CryptoKeyElement_SecondCounter,&SecondCounter,4);
        Csm_KeySetValid(CsmConf_CsmKey_CsmKey_SecondCounter);
    }
    else if((CompResult == 0) && (CertificateExpired == TRUE))
    {
        ret_val = kFblFailed;
    }
    else
    {
        CheckCertSessionValid = TRUE;
    }

    return ret_val;
}
/***********************************************************************************************************************
 *  SecureLogEvent
 **********************************************************************************************************************/
/*! \brief       Log security access failed events to NvM
 *  \param[in]   None
 *  \param[out]  None
 *  \return      None
 **********************************************************************************************************************/
void SecureLogEvent(const EventType Event, const EventSubType SubEvent, const uint8* EventData)
{
	uint32 VerifyMacLen = D_CMAC_LEN;
	SecureLogRecord_t *group;
	uint32 TimeStamp = getTimeStamp();
	static uint8 GroupID;
	uint32 TargetAddress;
	uint32 *TargetAddressPtr = EventData;

	group = getEventGroup(Event,&GroupID);

	if(1U==GroupID)
	{
		ApplFblNvReadSecureLogGroup1(&SecureLogRecord_Group1);
		group = &SecureLogRecord_Group1;
	}
	else if(2U==GroupID)
	{
		ApplFblNvReadSecureLogGroup2(&SecureLogRecord_Group2);
		group = &SecureLogRecord_Group2;
	}
	else
	{

	}

	group->RecordEntry[group->RecId][D_SEC_NUM_POS] = (uint8)RIGHTSHIFT_BIT(group->SecId,8U);
	group->RecordEntry[group->RecId][D_SEC_NUM_POS+1u] = (uint8)group->SecId;

	group->RecordEntry[group->RecId][D_TIMESTAMP_POS] = (uint8)RIGHTSHIFT_BIT(TimeStamp,24U);
	group->RecordEntry[group->RecId][D_TIMESTAMP_POS+1u] = (uint8)RIGHTSHIFT_BIT(TimeStamp,16U);
	group->RecordEntry[group->RecId][D_TIMESTAMP_POS+2u] = (uint8)RIGHTSHIFT_BIT(TimeStamp,8U);
	group->RecordEntry[group->RecId][D_TIMESTAMP_POS+3u] = (uint8)TimeStamp;

	group->RecordEntry[group->RecId][D_EVENT_TYPE_POS] = Event;

	group->RecordEntry[group->RecId][D_SUB_TYPE_POS] = SubEvent;
	/*Log Event Data*/
	if(SubEvent == SEC_FLASHING_FAILURE)
	{
		TargetAddress = *TargetAddressPtr;
		group->RecordEntry[group->RecId][D_EVENT_DATA_POS] = (uint8)RIGHTSHIFT_BIT(TargetAddress,24U);
		group->RecordEntry[group->RecId][D_EVENT_DATA_POS+1u] = (uint8)RIGHTSHIFT_BIT(TargetAddress,16U);
		group->RecordEntry[group->RecId][D_EVENT_DATA_POS+2u] = (uint8)RIGHTSHIFT_BIT(TargetAddress,8U);
		group->RecordEntry[group->RecId][D_EVENT_DATA_POS+3u] = (uint8)TargetAddress;
	}
	else
	{
		VStdLib_MemCpy(&(group->RecordEntry[group->RecId][D_EVENT_DATA_POS]),EventData,D_EVENT_DATA_SIZE);
	}

	Csm_MacGenerate(CsmConf_CsmJob_CsmJob_MacGenerate,CRYPTO_OPERATIONMODE_SINGLECALL, (uint8*)&(group->RecordEntry[group->RecId][0]), D_RECORD_DATA_SIZE, &(group->RecordEntry[group->RecId][D_RECORD_DATA_SIZE]),&VerifyMacLen);
	Csm_MacVerify(CsmConf_CsmJob_CsmJob_MacVerify,CRYPTO_OPERATIONMODE_SINGLECALL, (uint8*)&(group->RecordEntry[group->RecId][0]), D_RECORD_DATA_SIZE, &(group->RecordEntry[group->RecId][D_RECORD_DATA_SIZE]),VerifyMacLen,  (uint8*)&(group->RecordEntry[group->RecId][D_REC_STORAGE_SIZE-1u]));

	/*Increment variables for next event logging*/
	group->GroupCnt++;
	group->SecId++;
	group->RecId++;
	if(group->RecId == D_RECORD_PER_GRP)
	{
		group->RecId = 0;
	}

	if(1U==GroupID)
	{
		ApplFblNvWriteSecureLogGroup1(&SecureLogRecord_Group1);
	}
	else if(2U==GroupID)
	{
		ApplFblNvWriteSecureLogGroup2(&SecureLogRecord_Group2);
	}
	else
	{

	}
}
/***********************************************************************************************************************
 *  getEventGroup
 **********************************************************************************************************************/
/*! \brief      Get Secure Log group info before logging event in NvM
 *  \param[in]   None
 *  \param[out]  None
 *  \return      None
 **********************************************************************************************************************/
SecureLogRecord_t * getEventGroup(const EventType Event, uint8* GrpId)
{
	SecureLogRecord_t *EventGroup;
	switch (Event)
	{
		case AUTHNTICATION_FAILURE:
	  	case FAILED_AUTHORIZATION_ATTEMPTS:
	  		EventGroup = &SecureLogRecord_Group1;
	  		*GrpId=1U;
		break;

	  	case UNAUTHORIZED_ACCESS:
	  	case CYBERSEC_FAILURE:
	  		EventGroup = &SecureLogRecord_Group2;
	  		*GrpId=2U;
		break;

	  	default:
		break;
	}

	return EventGroup;
}
#if (SEC_SECURITY_CLASS == SEC_CLASS_VENDOR)
/***********************************************************************************************************************
 *  ApplFblHandleCertUpdate
 **********************************************************************************************************************/
/*! \brief       Checks if the given logical block has got a certificate list and updates the cert store accordingly
 *  \param[in]   blockDescriptor Pointer to current logical block descriptor
 *  \return      kkFblOk Cert store successfully updated or not needed
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */

Crypto_VerifyResultType verifyResultGVCS;
tFblResult ApplFblHandleCertUpdate(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor)
{
	tFblResult result = kFblFailed;
	vuint32 applHeaderAddr;
	uint8 *CertStore ;

	vuint32 certSourceAddr;
	tFblLength certStoreBinaryLength , CertStoreLength;
	vuint32 certState;
	uint8* FileSizeTemp;
	uint8 FileHeader[kFblFileHeaderSize]={0};
	CertStore = 0x41010200;

	uint8 CertSerNum[20U] = {0};
	uint32 SerialNumLen = 20U;
	/* Set Current time and second counter in HSM */
    Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_CurrentTimeStamp,CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_CryptoKeyElement_CurrentTimeStamp,SystemTime,15);
    Csm_KeySetValid(CsmConf_CsmKey_CsmKey_CurrentTimeStamp);
    Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_SecondCounter,CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_CryptoKeyElement_SecondCounter,&SecondCounter,4);
    Csm_KeySetValid(CsmConf_CsmKey_CsmKey_SecondCounter);

	if(blockDescriptor->blockNr == FBL_LBT_SECURITY_CERT_LB_BLOCK_NUMBER)
	{
		(void)FblReadProm(blockDescriptor->blockStartAddress, (vuint8 *)FileHeader, kFblFileHeaderSize);
		memcpy(CertStore,FileHeader,kFblFileHeaderSize);
		FileSizeTemp = &FileHeader[FILE_SIZE_OFFSET];
		certStoreBinaryLength = (((uint32)FileSizeTemp[0u] << 24u) | (((uint32)FileSizeTemp[1u]) << 16u ) | (((uint32)FileSizeTemp[2u]) << 8u ) | ((uint32)FileSizeTemp[3u])); /* Extract the File size information */
		CertStoreLength = certStoreBinaryLength;
		(void)FblReadProm(blockDescriptor->blockStartAddress+kFblFileHeaderSize, (vuint8 *)(CertStore+kFblFileHeaderSize), CertStoreLength);

		if (Csm_SignatureVerify(CsmConf_CsmJob_CsmJob_GVCS_UpdateCertStore, CRYPTO_OPERATIONMODE_SINGLECALL,
				(uint8 *)(CertStore+kFblFileHeaderSize), CertStoreLength,
				(uint8 *)CertStore, kFblFileHeaderSize,
				&verifyResultGVCS) == E_OK)
		{
			if (verifyResultGVCS == CRYPTO_E_VER_OK)
			{
				result = kFblOk;
			}
		}
	}
	else
	{
		result = kFblOk ;

	}
	if(kFblFailed == result)
	{
		/*Log Certificate Installation Failure Event*/
		/*Extract certificate Serial Number*/
		//TBD: HSM shall set Sr No. of invalidated certificate. FBL shall get it through Key Element ID
		//KeyElementID[0U] = 0U;
		//KeyElementID[1U] = 1U ;  /* Assign Serial No. key Element id from certificate */
		//Csm_AEADEncrypt(CsmConf_CsmJob_CsmJob_GetRoleFromTesterCertificate,CRYPTO_OPERATIONMODE_SINGLECALL,&KeyElementID[0U],2U,NULL_PTR,0U,CertSerNum,&SerialNumLen,NULL_PTR,NULL_PTR);
		SecureLogEvent(CYBERSEC_FAILURE, CERTIFICATE_FAILURE, CertSerNum);
	}

	return result;
}
#endif /* SEC_SECURITY_CLASS == SEC_CLASS_VENDOR */

/* module specific MISRA deviations:

   MD_FblKbApiFrame_0306:
      Reason:     Address conversion between integer values and pointers is required to allow for hardware independent
                  configuration and address range checks.
      Risk:       The size of integer required to hold the result of a pointer cast is implementation-defined.
      Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
                  specific basis. The correctness of the respective implementation is verified by runtime tests.

   MD_FblKbApiFrame_2983:
      Reason:     Value assignment is done but assigned value is not used in all configurations.
      Risk:       Adds an possibly unused assignment which could result in a compiler warning.
      Prevention: Ignore compiler warning if observed.

   MD_FblKbApiFrame_2991_2995:
      Reason:     Code is shared between different configurations. In other configurations,
                  the result of the comparison/logical operation is not invariant.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiFrame_5209:
      Reason:     Basic types are used in API of third party library
      Risk:       No risk
      Prevention: No prevention necessary.

   MD_FblKbApi_2889:
      Reason:     Multiple return paths are used to reduce code complexity, increase readability and reducing nesting level.
      Risk:       Some operations intended to conclude the function (e.g. states cleaning) can be unintentionally jumped.
      Prevention: Code inspection and runtime tests.

   MD_FblKbApi_3201:
      Reason: Configuration or platform specific dependent unreachable code.
      Risk: Incorrect behavior depend on settings.
      Prevention: No prevention required.

   MD_FblKbApi_3218_FileScopeStatic:
      Reason: Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk: Unintended use of object in wrong scope.
      Prevention: Architectural pattern supports prevention of incorrect use of objects in wrong context.
                  Code inspection focus on correct use of objects.

   MD_FblKbApi_3325:
      Reason: This control expression is always true or false depend on configuration aspect and used platform specific
              implementation.
      Risk: Incorrect behavior depend on settings.
      Prevention: No prevention required.

   MD_FblKbApi_3353:
      Reason: Variable is set in an other function via call-by-reference.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApi_3673:
      Reason: Function is part of the bootloader API which provides the possibility to influence the bootloader behavior
              by modifying the output parameters. The provided default implementation of the function doesn't
              necessarily make use of all available parameters.
      Risk: The parameter value might be changed unintentionally, thus causing malfunction in the calling instance.
      Prevention: Provide detailed information about the API and its usage in the user documentation.

   MD_FblKbApiOem_0314_MemCpy:
      Reason:     The copy function have a void pointer as a function parameter.
      Risk:       No risk, because the underlying vuint8 pointer type is known.
      Prevention: No prevention necessary.

   MD_FblKbApiOem_2741_4558:
      Reason:     Assertion macros have to be disabled in production code and are used only for development.
      Risk:       Assertion code may be enabled in production code unintentionally. If a assertion condition is unexpectedly
                  false, the code is active. A problem may occur if the Macro is additionally changed from single statement
                  to multiple statement.
      Prevention: Macro is not allowed to be changed without review. Development code is automatically disabled via
                  configuration of project state "Production".

   MD_FblKbApiOem_2742:
      Reason:     Compiler related constand expression to check actual size.
      Risk:       No risk.
      Prevention: No prevention required. (Note: assertions are disabled in production software).

   MD_FblKbApiOem_2982_2983:
      Reason:     The assignment or initialization may not be necessary but it increases maintainability for future enhancements.
      Risk:       Unnecessary waste of resources.
      Prevention: No prevention required.

   MD_FblKbApiOem_2995_2991:
      Reason:     Code is shared between different configurations. In other configurations,
                  the result of the comparison/logical operation is not invariant.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_3199:
      Reason:     Value assignment is done but assigned value is not used in all configurations.
      Risk:       Adds an possibly unused assignment which could result in a compiler warning.
      Prevention: Ignore compiler warning if observed.

   MD_FblKbApiOem_3315:
      Reason:     Example code shows how the function can be implemented and is therefore left empty.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_3425:
      Reason:     The WrapNv call uses the ternary operator to remap the return value of IO_E_OK to kFblOk. As both of
                  them are defined to the value zero the remapping has no side affects.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_4342_4521_ConfigurationEnumLengthCast:
      Reason:     The last element of an enum is used to determine the number of entries. This is required for
                  configurable code. The enum must have more than one entry - therefore it is always possible to
                  determine the last (length - 1) one.
      Risk:       No identifiable risk.
      Prevention: No prevention required.


   MD_FblKbApiOem_3218:
      Reason:     The configuration constants of this module are kept at a central location for a better overview and
                  maintenance. Scope is larger than required (whole file instead of one function).
      Risk:       Name conflicts with local variables.
      Prevention: Double check variable names. Use "local/tmp/temp" as prefixes for local variables.

*/

/***********************************************************************************************************************
 *  FBL_APNV.C
 **********************************************************************************************************************/
