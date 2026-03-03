/* Kernbauer Version: 1.12 Konfiguration: FBL Erzeugungsgangnummer: 1 */

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application dependent routines
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
 *  01.00.01   2018-10-05  visqps  ESCAN00100941    Support automatic DemoAppl creation
 *  01.01.00   2018-11-06  viscb   ESCAN00101211    Support for bootmanager
 *                                 ESCAN00101239    No changes
 *  01.02.00   2019-01-29  viscb   ESCAN00101940    Additional functions for file header verification
 *  01.02.01   2019-07-19  vistbe  ESCAN00103774    SHA-256 Application Logical Block Hash Not Supported
 *  02.00.00   2020-03-26  vistbe  FBL-1510         Upgrade to latest reference implementation
 *  02.01.00   2020-10-11  vistbe  FBL-2419         Add support for FblLib_SecBoot_Escrypt
 *  02.02.00   2021-04-12  vistmo  FBL-2961         Added support for Authenticated Diagnostics with vHSM
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


#define FBL_AP_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
# include "cmpr_inc.h"

# include "Det.h"
# if (DET_ENABLED == STD_ON)
#   include "Can.h"
#   include "CanTp.h"
# endif

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLKBAPI_FCA_VERSION != 0x0204u ) || \
    ( FBLKBAPI_FCA_RELEASE_VERSION != 0x02u )
# error "Error in fbl_apXX.c: Source and Header file are inconsistent!"
#endif

#if ( FBLKBAPI_FCA_VERSION != _FBLKBAPI_OEM_VERSION ) || \
    ( FBLKBAPI_FCA_RELEASE_VERSION != _FBLKBAPI_OEM_RELEASE_VERSION )
# error "Error in fbl_apXX.c: Source and v_ver.h are inconsistent!"
#endif

#if ( FBLKBAPI_VERSION != 0x0210u ) || \
    ( FBLKBAPI_RELEASE_VERSION != 0x02u )
# error "Error in FBL_APxx.C: Source and header file are inconsistent!"
#endif
#if ( FBLKBAPI_VERSION != _FBLKBAPI_VERSION ) || \
    ( FBLKBAPI_RELEASE_VERSION != _FBLKBAPI_RELEASE_VERSION )
# error "Error in FBL_APxx.C: Source and V_VER.H are inconsistent!"
#endif

#if ( FBLKBAPI_FRAME_FCA_VERSION != 0x0202u ) || \
    ( FBLKBAPI_FRAME_FCA_RELEASE_VERSION != 0x00u )
# error "Error in fbl_ap.c: Source and header file are inconsistent!"
#endif

#if ( FBLKBAPI_FRAME_FCA_VERSION != _FBLKBAPI_FRAME_OEM_VERSION )
# error "Error in fbl_apxx.c: Source and v_ver.h are inconsistent!"
#endif
#if ( FBLKBAPI_FRAME_FCA_RELEASE_VERSION != _FBLKBAPI_FRAME_OEM_RELEASE_VERSION )
# error "Error in fbl_apxx.c: Source and v_ver.h are inconsistent!"
#endif

#if ( (FBLSB_API_REFERENCE_VERSION_MAJOR != 0x02u) || \
      (FBLSB_API_REFERENCE_VERSION_MINOR < 0x01u) )
# error "A newer version of FblLib_SecBoot is required which contains the API FblSb_GetExtendedErrorCode"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/


/* Security seed response status defines */
#define kSeedAlreadyRequested             0x00u    /**< Seed sent out, but no key received */
#define kNewSeedRequest                   0x01u    /**< No seed sent out, new seed should be sent */

/* Configure Seed/Key implementation in callback file */


#if defined( FBL_ENABLE_DATA_PROCESSING )
# if !defined( GetOemProcessingModeSupported )
/* Accept compression and encryption */
#  define GetOemProcessingModeSupported(m) (GetOemCompressionMode((m)) || GetOemEncryptionMode((m)))
# endif /* GetOemProcessingModeSupported */

# if !defined( GetOemCompressionMode )
#  if defined( FBL_ENABLE_COMPRESSION_MODE )
/* Accept compression routine "1" */
#   define GetOemCompressionMode(m) (((m) & kDiagFmtCompressionMask) == 0x10u)
#  else
/* No compression routine supported */
#   define GetOemCompressionMode(m) (0u != 0u)
#  endif /* FBL_ENABLE_COMPRESSION_MODE */
# endif /* GetOemCompressionMode */

# if !defined( GetOemEncryptionMode )
#  if defined( FBL_ENABLE_ENCRYPTION_MODE )
/* Accept encryption routine "1" */
#    define GetOemEncryptionMode(m) (((m) & kDiagFmtEncryptionMask) == 0x01u)
#  else
/* No encryption routine supported */
#   define GetOemEncryptionMode(m) (0u != 0u)
#  endif /* FBL_ENABLE_ENCRYPTION_MODE */
# endif /* GetOemEncryptionMode */
#endif /* FBL_ENABLE_DATA_PROCESSING */


/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

/* Check for unsupported configurations. */
#if defined( FBL_LBT_ENABLE_REPROGRAMMABLE_LBT )
# error "Reprogrammable Logical Block Table is currently not supported"
#endif /* FBL_LBT_ENABLE_REPROGRAMMABLE_LBT */


/* Static_seed indicates if a previously generated and stored seed shall be reused upon a repeated request  *
 * Static_seed == false is currently not implemented                                                        */
#define Static_seed                       0x01u

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/* The following constant is used by the HW/SW compatibility check. *
 * This value has to be replaced by the ECU-specific data.
 */
/* PRQA S 3218 1 */ /* MD_FblKbApiFrame_3218_FileScopeStatic */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 HardwareCompatibilityVersion[2] = {0x00u,0x12u};


#if defined( FBL_ENABLE_COMMON_DATA )
# define FBLCOMMONDATA_START_SEC_CONST
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* Common data structure definition                                        *
 * This information is shared with the application and has to be adapted   *
 * to ECU specific values. The data is also used in DIDs supported by the  *
 * Bootloader. */
V_MEMROM0 V_MEMROM1_FAR tFblCommonData V_MEMROM2_FAR fblCommonData =
{
   /* F10D - Diagnostic Specification Information */
   /* CS.00100 Version     CS00101 Version   CS.00102 Version  CS-00099 Version  */
   {  0x91u,               0x32,             0x42,             0x51  },

   /* F110 data - Diagnostic Veriant*/
   { 0x00u, 0x01u},

   /* F110 data - Software Defintion Number */
   { 0x00u, 0x01u},

   /* F110 data - Supplier ID */
   { 0x00u, 0x0D},

   /* F190 VIN Original */
   {(vuint8)'V', (vuint8)'I', (vuint8)'N', (vuint8)'_',
    (vuint8)'O', (vuint8)'R', (vuint8)'I', (vuint8)'G',
    (vuint8)'I', (vuint8)'N', (vuint8)'A', (vuint8)'L',
    (vuint8)'1', (vuint8)'2', (vuint8)'3', (vuint8)'4',
    (vuint8)'5' },

   /* F191  Vehicle Manufacturer ECUHardware Number */
   {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},

   /* F192 Supplier Manufacturer ECU Hardware Part Number */
   {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},

   /* F193 Supplier Manufacturer ECU Hardware Version Number */
   { 0x01 },

   /* F180  Boot Software Version information */
   { 0x18, 0x27, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },

   /* F154 Hardware Supplier Identification */
   { 0x01, 0x02 },

   /* F155 Software Supplier Identification */
   { 0x00, 0x01 },

   /* F1A4 */
   { 0x00u, 0x01 },

   /* Standard Bootloader software information (BCD encoded)               *
    * Information is provided with the bootloader delivery.                */
   {
     (vuint8)(FBL_VERSION>>8), (vuint8)FBL_VERSION, (vuint8)FBL_RELEASE_VERSION,
     0u, 0u,
     0u, 0u,
     0u
   },
};
# define FBLCOMMONDATA_STOP_SEC_CONST
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBL_ENABLE_COMMON_DATA */

#define FBLAP_SHUTDOWNSTATUS_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMRAM0 V_MEMRAM1 tFblShutdownStatus V_MEMRAM2 fblShutdownStatus;
#define FBLAP_SHUTDOWNSTATUS_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON )
/** Pointer to select active ECU of a multiple identity configuration */
P2CONST(FblCw_ConfigType, AUTOMATIC, FBLCW_INIT_DATA) activeCwConfiguration;
#endif /* DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

V_MEMRAM0 static V_MEMRAM1 SecM_SeedType V_MEMRAM2 secSeedInput;     /**< Initial seed value */
V_MEMRAM0 static V_MEMRAM1 SecM_SeedType V_MEMRAM2 seed;             /**< Current seed value */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 securitySeedResponse;    /**< Seed response status */

#if defined( FBL_ENABLE_VECTOR_HW )
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 flashlight;
#endif

/***********************************************************************************************************************
 *  EXTERNAL DATA
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ApplFblInit
 **********************************************************************************************************************/
/*! \brief       Function is called before any other FBL initialization
 **********************************************************************************************************************/
void ApplFblInit( void )
{
   /* Initialize NvM-Driver */
#if defined( WRAPNV_USECASE_DRVEEP )
   (void)EepromDriver_InitSync(V_NULL);
#else
   WrapNv_Init();
#endif

   /* Init Seed response status */
   securitySeedResponse = kNewSeedRequest;

}

/***********************************************************************************************************************
 *  ApplFblStartup
 **********************************************************************************************************************/
/*! \brief       Bootloader initialization callback
 *  \details     This function is called during the Bootloader initialization if the application software is
 *               not started. It can be used to perform initializations which are not needed if the application
 *               software is started. Please note that the function is called several times with different
 *               initposition values. Timer and hardware can be accessed in post-init phase only.
 *  \param[in]   initposition Initialization state of Bootloader.
 **********************************************************************************************************************/
void ApplFblStartup( vuint8 initposition )
{
   switch (initposition)
   {
      case (kFblInitPreCallback | kFblInitBaseInitialization):
      {
         break;
      }
      case (kFblInitPreCallback | kFblInitFblCommunication):
      {
#if ( DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON )
         /* TODO: Add your code to decide which variant should be selected,
            e.g. based on a NV-memory entry, pin value or other value.
         */
         activeCwConfiguration = FblCw_Config_Left_Ptr;
         /* activeCwConfiguration = FblCw_Config_Right_Ptr; */
#endif /* DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON */

         break;
      }
      case (kFblInitPreCallback | kFblInitFblFinalize):
      {
         break;
      }
      case (kFblInitPostCallback | kFblInitBaseInitialization):
      {
         /* Basic hardware initialization */
         ApplFblInit();
         break;
      }
      case (kFblInitPostCallback | kFblInitFblCommunication):
      {
         break;
      }
      case (kFblInitPostCallback | kFblInitFblFinalize):
      {
#if defined( FBLBM_ENABLE_SECURE_BOOT )
         ApplFblSbStartup();
#endif /* FBLBM_ENABLE_SECURE_BOOT */
         break;
      }
      default:
      {
         /* PRQA S 2741,4558 1 */ /* MD_FblKbApiOem_2741_4558 */
         assertFblInternal(0u, kFblSysAssertParameterOutOfRange);
         break; /* PRQA S 2880 */ /* MD_MSR_Unreachable */
      }
   }
}

/***********************************************************************************************************************
 *  ApplFblCheckProgConditions
 **********************************************************************************************************************/
/*! \brief       This function is called after receiving the service request sessionControl ProgrammingSession to check
 *               the programming conditions like reprogramming counter, ambient temperature, programming voltage, etc.
 *  \return      If all conditions are correct, the function returns kFblOk, otherwise kFblFailed.
 **********************************************************************************************************************/
tFblResult ApplFblCheckProgConditions( void )
{
#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
   vuint16 diagRespDataLen;
#endif /* FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS */
   tFblResult result;

   result = kFblOk;

#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
   diagRespDataLen = 3;

   /* Transmit response message:*/
   DiagProcessingDone(diagRespDataLen);
#endif /* FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS */

  return result;
}

/***********************************************************************************************************************
 *  ApplFblCheckConditions
 **********************************************************************************************************************/
/*! \brief         Check conditions for diagnostic services
 *  \details       This function is called for each diagnostic service.
 *  \param[in,out] pbDiagData Pointer to diagnostic data buffer
 *  \param[in]     diagReqDataLen The request data length
 *  \return        kFblOk or kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblCheckConditions( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   /* Parse Service IDs */

   /*
   switch (diagServiceCurrent)
   {
      case kDiagSidDiagnosticSessionControl:
      {
         if (...)
         {
            DiagNRCConditionsNotCorrect();
            return kFblFailed;
         }

         break;
      }
      case kDiagSidEcuReset:
      {
         break;
      }
      case kDiagSidReadDataByIdentifier:
      {
         break;
      }
      case kDiagSidSecurityAccess:
      {
         break;
      }
      case kDiagSidCommunicationControl:
      {
         break;
      }
      case kDiagSidWriteDataByIdentifier:
      {
         break;
      }
      case kDiagSidRoutineControl:
      {
         break;
      }
      case kDiagSidRequestDownload:
      {
         break;
      }
      case kDiagSidTransferData:
      {
         break;
      }
      case kDiagSidRequestTransferExit:
      {
         break;
      }
      case kDiagSidTesterPresent:
      {
         break;
      }
      case kDiagSidControlDTCSetting:
      {
         break;
      }
      default:
      {
         break;
      }
   }
   */

   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblCheckHwSwCompatibility
 **********************************************************************************************************************/
/*! \brief       Check if current logical block is compatible with hardware
 *  \pre         Logical block has to be valid
 *  \param[in]   blockIdx Index of logical block
 *  \return      Status of hardware-software compatibility check
 **********************************************************************************************************************/
vuint8 ApplFblCheckHwSwCompatibility( vuint8 blockIdx )
{
   vuint8 compatibilityListLength;
   FBL_ADDR_TYPE pCompatibilityField;
   vuint8 versionBuffer[2u];
   vuint8 listIndex;
   vuint8 returnValue;

   /* Preset values */
   listIndex = 0u;
   returnValue = kDiagCheckCompatibilitySwHw;

   /* Get address of compatibility list */
   pCompatibilityField = (ApplFblGetModuleHeaderAddress(blockIdx) + kApplInfoOffsetHwCompatibilityCounter );

   /* Read length of compatibility list */
   (void)FblReadProm(pCompatibilityField, &compatibilityListLength, 1u);
   pCompatibilityField += kApplInfoSizeHwCompatibilityCount;

   /* Compare compatibility list to hardware compatibility version */
   while ((listIndex < compatibilityListLength) && (returnValue == kDiagCheckCompatibilitySwHw))
   {
      (void)FblReadProm(pCompatibilityField, versionBuffer, 2u);
      if ((versionBuffer[0u] == HardwareCompatibilityVersion[0u]) &&
          (versionBuffer[1u] == HardwareCompatibilityVersion[1u]))
      {
         returnValue = kDiagCheckCompatibilityOk;
      }
      pCompatibilityField += 2u;
      listIndex++;
   }

   return returnValue;
}

/***********************************************************************************************************************
 *  ApplFblCheckSwSwCompatibility
 **********************************************************************************************************************/
/*! \brief       Check if logical blocks are compatible
 *  \return      Status of software-software compatibility check
 **********************************************************************************************************************/
vuint8 ApplFblCheckSwSwCompatibility( void )
{
#if ( FBL_LBT_BLOCK_COUNT < FBL_MIN_BLOCKS_FOR_DEPENDENCY )
   /* Only one block, no inconsistency possible */
   return kDiagCheckCompatibilityOk;
#else
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
   vuintx i;
# endif
   tBlockDescriptor iterBlock;
   tFblLbtBlockFilter blockFilter;
   vuint8 actualVersion[2];
   vuint8 referenceVersion[2];
   vuint8 validityFlags[kEepSizeValidityFlags];
   vuint8 result;
   boolean referenceBlockFound = FALSE;

   result = kDiagCheckCompatibilityOk;

# if defined( FBL_ENABLE_PRESENCE_PATTERN )
   for (i = 0u; i < sizeof(validityFlags); i++)
   {
      validityFlags[i] = 0xFFu;
   }
   FblLbtBlockFilterInit(&blockFilter);
   iterBlock = FblLbtBlockFirst(&blockFilter);
   while (FblLbtBlockDone() == FALSE)
   {
      /* Check for blocks with stored validity flags */
      {
         if (FblNvPatternGet(&iterBlock, kFblNvPatternId_BlockValidity) == kFblOk)
         {
            /* If present, clear the validity flag (inverse logic!!) */
            validityFlags[(iterBlock.blockNr >> 3u)] &= FblInvert8Bit(1u << (iterBlock.blockNr & 7u));
         }
      }

      /* Prepare next cycle */
      iterBlock = FblLbtBlockNext();
   }
# else
   /* Read validity flags */
   if (ApplFblNvReadValidityFlags(validityFlags) != kFblOk)
   {
      /* General failure - validity flags couldn't be read */
      result = kDiagCheckCompatibilityFailed;
   }

   if (result == kDiagCheckCompatibilityOk)
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
   {
      FblLbtBlockFilterInit(&blockFilter);
      iterBlock = FblLbtBlockFirst(&blockFilter);

      while (FblLbtBlockDone() == FALSE)
      {
         /* Boot blocks are not considered for compatibility check */
         if (iterBlock.blockType != kBlockTypeBoot)
         {
            if (referenceBlockFound != TRUE)
            {
               /* First non-Boot block is used as reference */
               (void)FblReadProm(ApplFblGetModuleHeaderAddress(iterBlock.blockNr) + kApplInfoOffsetSwCompatibility,
                  (vuint8 *)&referenceVersion, kApplInfoSizeSwCompatibility);
               referenceBlockFound = TRUE;
            }
            else
            {
               /* Check is performed for valid logical blocks only. If an optional block  *
               * is not valid, the compatibility status will be ignored.                 */
               if ((validityFlags[iterBlock.blockNr >> 3u] & (vuint8)(1u << (iterBlock.blockNr & 7u))) == 0u)
               {
                  /* Check if module version matches */
                  (void)FblReadProm(ApplFblGetModuleHeaderAddress(iterBlock.blockNr) + kApplInfoOffsetSwCompatibility,
                     (vuint8 *)&actualVersion, kApplInfoSizeSwCompatibility);
                  if ((referenceVersion[0] != actualVersion[0]) ||
                     (referenceVersion[1] != actualVersion[1]))
                  {
                     /* Inconsistency found */
                     result = kDiagCheckCompatibilitySwSw;
                  }
               }
            }
         }
         /* Prepare next cycle */
         iterBlock = FblLbtBlockNext();
      }
   }

   /* All blocks successfully checked */
   return result;
#endif /* FBL_LBT_BLOCK_COUNT < FBL_MIN_BLOCKS_FOR_DEPENDENCY */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  ApplFblCheckProgDependencies
 **********************************************************************************************************************/
/*! \brief       Check if programming dependencies are given
 *  \return      Status of programming dependencies (OEM specific)
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
vuint8 ApplFblCheckProgDependencies( void )
{
   vuint8 result;
#if defined( FBL_ENABLE_PRESENCE_PATTERN )
   vuintx i;
#endif
   tBlockDescriptor iterBlock;
   tFblLbtBlockFilter blockFilter;
   vuint8 validityFlags[kEepSizeValidityFlags];

   /* Initialize variables */
   result = kDiagCheckCompatibilityOk;

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
   for (i = 0u; i < sizeof(validityFlags); i++)
   {
      validityFlags[i] = 0xFFu;
   }
   FblLbtBlockFilterInit(&blockFilter);
   iterBlock = FblLbtBlockFirst(&blockFilter);
   while (FblLbtBlockDone() == FALSE)
   {
      /* Check for blocks with stored validity flags */
      if (ApplFblChkModulePresence(&iterBlock) == kFblOk)
      {
         /* If present, clear the validity flag (inverse logic!!) */
         validityFlags[(iterBlock.blockNr >> 3u)] &= FblInvert8Bit(1u << (iterBlock.blockNr & 7u));
      }

      /* Prepare next cycle */
      iterBlock = FblLbtBlockNext();
   }
#else
   if (ApplFblNvReadValidityFlags(validityFlags) != kFblOk)
   {
      result = kDiagCheckCompatibilityFailed;   /* General failure - validity flags couldn't be read */
   }

   if (result == kDiagCheckCompatibilityOk)
#endif /* FBL_ENABLE_PRESENCE_PATTERN */
   {
      FblLbtBlockFilterInit(&blockFilter);
      FblLbtBlockFilterSetMandatoryType(&blockFilter, TRUE);
      iterBlock = FblLbtBlockFirst(&blockFilter);
      while ((FblLbtBlockDone() == FALSE) && (result == kDiagCheckCompatibilityOk))
      {
         /* A set bit means that the block is not present */
         if ((validityFlags[(iterBlock.blockNr >> 3u)] & (1u << (iterBlock.blockNr & 7u))) != 0u)
         {
            result = kDiagCheckCompatibilityBlockMissing;
         }

         /* Prepare next cycle */
         iterBlock = FblLbtBlockNext();
      }
   }

   /* Check compatibility between valid logical blocks and bootloader */
   if (result == kDiagCheckCompatibilityOk)
   {
      /* Check Sw/Sw compatibility */
      result = ApplFblCheckSwSwCompatibility();
   }

   if (result == kDiagCheckCompatibilityOk)
   {
      /* Check Hw/Sw-compatibility of all programmed logical blocks */

      FblLbtBlockFilterInit(&blockFilter);
      iterBlock = FblLbtBlockFirst(&blockFilter);
      while ((FblLbtBlockDone() == FALSE) && (result == kDiagCheckCompatibilityOk))
      {
         /* Check if block is programmed */
         if ( ((validityFlags[iterBlock.blockNr >> 3u] & (vuint8)(1u << (iterBlock.blockNr & 7u))) == 0u) &&
              (iterBlock.blockType != kBlockTypeBoot) )
         {
            result = ApplFblCheckHwSwCompatibility((vuint8)iterBlock.blockNr);
         }

         /* Prepare next cycle */
         iterBlock = FblLbtBlockNext();
      }
   }

   /* If required, additional checks can be added here */

   return result;
   /* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

#if ( SEC_SECURITY_CLASS == SEC_CLASS_VENDOR )
/***********************************************************************************************************************
 *  ApplFblVerifyFcaHeader
 **********************************************************************************************************************/
/*! \brief       Verify FCA file header after download of logical block
 *  \detail      This function performs the full download verification based on the signature- and hash information
 *  \param[in]   blockNr Number of logical block
 *  \param[in]   segmentList List of download segments
 *               of the file header provided in the download data of the logical block.
 *  \return      Verification result
 **********************************************************************************************************************/
vuint8 ApplFblVerifyFcaHeader(vuint8 blockNr, V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * segmentList)
{
   vuint8 result;
   tBlockDescriptor blockDescriptor;

   result = kDiagCheckVerificationGeneralFailure;

   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      if (FblSb_UpdateBlockMac(&blockDescriptor, segmentList) == kFblOk)
      {
         result = kDiagCheckCompatibilityOk;
      }
      else
      {
         /* Get extended error code and map to diagnostic response code */
         tFblSbExtErrCode extErrorCode;

         extErrorCode = FblSb_GetExtendedErrorCode();

         switch (extErrorCode)
         {
            case FBLSB_EXT_ERR_CODE_CRC:
            {
               result = kDiagCheckVerificationCRCFailed;
               break;
            }
            case FBLSB_EXT_ERR_CODE_SIGNATURE:
            {
               result = kDiagCheckVerificationSignatureFailed;
               break;
            }
            case FBLSB_EXT_ERR_CODE_MEMORY:
            {
               result = kDiagCheckVerificationRWMemoryFailure;
               break;
            }
            default:
            {
               /* Nothing to be done here as result was already initialized to kDiagCheckVerificationGeneralFailure */
               break;
            }
         }
      }
   }

   return result;
}
#endif /* SEC_SECURITY_CLASS == SEC_CLASS_VENDOR */

/***********************************************************************************************************************
 *  ApplTrcvrNormalMode
 **********************************************************************************************************************/
/*! \brief       Activate transceiver if necessary (e.g. pin configuration ENABLE = 1, _STDBY = 1)
 **********************************************************************************************************************/
void ApplTrcvrNormalMode( void )
{
}

/***********************************************************************************************************************
 *  ApplTrcvrSleepMode
 **********************************************************************************************************************/
/*! \brief       Turn off the transceiver to enter sleep mode (e.g. pin configuration ENABLE = 1, _STDBY = 0)
 **********************************************************************************************************************/
void ApplTrcvrSleepMode( void )
{
}

#if defined( FBL_MIO_ENABLE_HOOKS )
/***********************************************************************************************************************
 *  ApplFblPreMemDriver
 **********************************************************************************************************************/
/*! \brief        Function is called before the memory driver is executed.
 *  \param[in]    device   Memory device, which is going to be used.
 *  \param[in]    function Function of the memory device, which is going to be called.
 **********************************************************************************************************************/
void ApplFblPreMemDriver( vuint8 device, vuint8 function )
{
   uint8 opMode;
   Std_ReturnType retVal = E_OK;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)device;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
   (void)function;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif
   /* Suspend vHSM operations in data flash */
   opMode = CRYPTO_30_VHSM_DATAFLASH_START;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);
   /* Suspend vHSM operations in code flash -> send it to RAM loop */
   opMode = CRYPTO_30_VHSM_CODEFLASH_START;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);

   /* Simulate DET functionality in case of any error */
   assertFblUser(retVal == E_OK, kFblSysAssertDet);
}
#endif /* FBL_MIO_ENABLE_HOOKS */

#if defined( FBL_MIO_ENABLE_HOOKS )
/***********************************************************************************************************************
 *  ApplFblPostMemDriver
 **********************************************************************************************************************/
/*! \brief        Function is called after the memory driver has finished the operation.
 *  \param[in]    device   Memory device, which is going to be used.
 *  \param[in]    function Function of the memory device, which is going to be called.
 **********************************************************************************************************************/
void ApplFblPostMemDriver( vuint8 device, vuint8 function )
{
   uint8 opMode;
   Std_ReturnType retVal = E_OK;
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)device;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
   (void)function;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif
   /* Get vHSM back from RAM loop */
   opMode = CRYPTO_30_VHSM_CODEFLASH_STOP;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);
   /* Give vHSM access to data flash operations */
   opMode = CRYPTO_30_VHSM_DATAFLASH_STOP;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);

   /* Simulate DET functionality in case of any error */
   assertFblUser(retVal == E_OK, kFblSysAssertDet);
}
#endif /* FBL_MIO_ENABLE_HOOKS */

/***********************************************************************************************************************
 *  ApplFblSetVfp
 **********************************************************************************************************************/
/*! \brief       Function is called when the FBL enters programming mode.
 *  \details     Port bits have to be set so that the required programming voltage is available.
 **********************************************************************************************************************/
void ApplFblSetVfp( void )
{
}

/***********************************************************************************************************************
 *  ApplFblResetVfp
 **********************************************************************************************************************/
/*! \brief       This function is called when the programming is done.
 **********************************************************************************************************************/
void ApplFblResetVfp( void )
{
}

/***********************************************************************************************************************
 *  ApplFblReset
 **********************************************************************************************************************/
/*! \brief       This function performs a reset.
 *  \details     The function will wait until the reset is performed. Please note: This function will
 *               never return to the calling code.
 **********************************************************************************************************************/
void ApplFblReset( void )
{
   /* Set flag for regular shutdown */
   ApplFblSetShutdownStatus(kFblShutdownStatusNormal);

}

# define FBLAP_RAMCODE_START_SEC_CODE
# include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  ApplFblSecuritySeedInit
 **********************************************************************************************************************/
/*! \brief       Initialize seed values.
 *  \return      Status of seed initialization
 **********************************************************************************************************************/
vuint8 ApplFblSecuritySeedInit( void )
{
#if defined( FBL_DIAG_ENABLE_SECACCESS_STANDARD )
   /* Initialize seed values */
   secSeedInput.seedY += secSeedInput.seedX;
   secSeedInput.seedX = FblGetTimerValue();
#endif /* FBL_DIAG_ENABLE_SECACCESS_STANDARD */

   return kFblOk;
}
# define FBLAP_RAMCODE_STOP_SEC_CODE
# include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBL_DIAG_ENABLE_SECACCESS_STANDARD )
/***********************************************************************************************************************
 *  ApplFblSecuritySeed
 **********************************************************************************************************************/
/*! \brief       This function is called when the tester requests the security seed.
 *  \return      Status of seed generation
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
vuint8 ApplFblSecuritySeed( void )
{
   vuint8 result;

   result = kFblOk;

   /* Last seed is repeated if it was already sent to tester */

   if (securitySeedResponse != kSeedAlreadyRequested)
   {
      /* Ensure that seed has been initialized */
      while ((0u == secSeedInput.seedX) || (0u == secSeedInput.seedY))
      {
         (void)ApplFblSecuritySeedInit();
      }

      /* Generate seed */
      if (SECM_OK == SecM_GenerateSeed(&secSeedInput))
      {
         /* Save last seed */
         seed = secSeedInput;
      }
      else
      {
         result = kFblFailed;
      }
   }

   /* Write seed value into DiagBuffer */
   if (kFblOk == result)
   {
      FblMemSetInteger(SEC_SEED_LENGTH, seed.seedX, &DiagBuffer[kDiagFmtSeedKeyStart]);

      /* Set seed status to seed requested */
      securitySeedResponse = kSeedAlreadyRequested;
   }

   return result;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  ApplFblSecurityKey
 **********************************************************************************************************************/
/*! \brief       This function is called when the security key has been received from tester
 *  \return      Status of key verification
 **********************************************************************************************************************/
vuint8 ApplFblSecurityKey( void )
{
   vuint8 result;

   SecM_KeyType key;

   /* Initialize variables */
   result = kFblFailed;

   /* Key received => New seed can be requested */
   securitySeedResponse = kNewSeedRequest;

   /* Check key from tester */
   key = FblMemGetInteger(SEC_KEY_LENGTH, &DiagBuffer[kDiagFmtSeedKeyStart]);
   if (SECM_OK == SecM_CompareKey(key, seed))
   {
      /* Key bytes are accepted */
      result = kFblOk;
   }

   return result;
}
#endif /* FBL_DIAG_ENABLE_SECACCESS_STANDARD */

/***********************************************************************************************************************
 *  ApplFblSecurityInit
 **********************************************************************************************************************/
/*! \brief       Initialize security module.
 *  \return      Status of security module initialization
 **********************************************************************************************************************/
vuint8 ApplFblSecurityInit( void )
{
#if defined( FBL_DIAG_ENABLE_SECACCESS_STANDARD )
   secSeedInput.seedX = 0u;
   secSeedInput.seedY = 0u;
#endif /* FBL_DIAG_ENABLE_SECACCESS_STANDARD*/

   return kFblOk;
}

#if defined( FBL_ENABLE_DATA_PROCESSING )
/***********************************************************************************************************************
 *  ApplFblInitDataProcessing
 **********************************************************************************************************************/
/*! \brief         This function is called to initialize the application specific data processing function.
 *  \param[in,out] procParam Processing parameter data structure
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblInitDataProcessing( tProcParam * procParam )
{
   tFblResult result;

   /* Check if data format is supported */
   if (GetOemProcessingModeSupported(procParam->mode))
   {
# if defined( FBL_ENABLE_COMPRESSION_MODE )
      /* Default compression mode */
      if (GetOemCompressionMode(procParam->mode))  /* PRQA S 2991, 2995 */ /* MD_FblKbApiOem_2995_2991 */
      {
         /* Initialize decompression */
         InitDecompressionVL();
         result = kFblOk;
      }
      else
# endif /* FBL_ENABLE_COMPRESSION_MODE */
      {
         result = kFblOk;
      }

   }
   else
   {
      result = kFblFailed;
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblDataProcessing
 **********************************************************************************************************************/
/*! \brief         Data processing function.
 *  \pre           Data processing has to be initialized by call of ApplFblInitDataProcessing
 *  \param[in,out] procParam Processing parameter data structure
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673, 6010, 6030, 6080 1 */ /* MD_FblKbApi_3673, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
tFblResult ApplFblDataProcessing( tProcParam * procParam )
{
   tFblResult              result;
#  if defined( FBL_ENABLE_COMPRESSION_MODE )
   tCmprParam              cmprParam;
   tFblResult              lastCallByLibMem;
#  endif /* FBL_ENABLE_COMPRESSION_MODE */


   /* Initialize variables */
   result = kFblFailed;

# if defined( FBL_ENABLE_COMPRESSION_MODE )
   /* Last call by FblLib_Mem is done with length = 0 */
   if (procParam->dataLength == 0u)
   {
      lastCallByLibMem = kFblOk; /* PRQA S 2983 */ /* MD_FblKbApiOem_2982_2983 */
   }
   else
   {
      lastCallByLibMem = kFblFailed;   /* PRQA S 2983 */ /* MD_FblKbApiOem_2982_2983 */
   }
# endif /* FBL_ENABLE_COMPRESSION_MODE */

   /* Check if data format is supported */
   if (GetOemProcessingModeSupported(procParam->mode))
   {
      result = kFblOk;

      {
#  if defined( FBL_ENABLE_COMPRESSION_MODE )
         /* Directly pass input buffer to decompression */
         cmprParam.inputBuffer = procParam->dataBuffer;
         cmprParam.inputLength = procParam->dataLength;
#  endif /* FBL_ENABLE_COMPRESSION_MODE */
      }

#  if defined( FBL_ENABLE_COMPRESSION_MODE )
      /* Check if compression mode is supported */
      /* PRQA S 2991, 2995 1 */ /* MD_FblKbApiOem_2995_2991 */
      if (GetOemCompressionMode(procParam->mode))
      {
         /* Check if optional decryption was successful */
         /* PRQA S 2991, 2995 1 */ /* MD_FblKbApiOem_2995_2991 */
         if (result == kFblOk)
         {
            /* Initialize decompression variables */
            cmprParam.outputBuffer = procParam->dataOutBuffer;
            cmprParam.outputLength = procParam->dataOutMaxLength;

            /* Decompress block */
            if (DecompressBlockVL(&cmprParam) == kCmprOk)
            {
               {
                  /* Processed input length */
                  procParam->dataLength = (vuint16)(cmprParam.inputLength);
               }

               /* Resulting output length */
               procParam->dataOutLength = (vuint16)(cmprParam.outputLength);
            }
            else
            {
               result = kFblFailed;
            }
         }
      }
#  endif /* FBL_ENABLE_COMPRESSION_MODE */
   }

   return result;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  ApplFblDeinitDataProcessing
 **********************************************************************************************************************/
/*! \brief         Deinitialize data processing function.
 *  \pre           Data processing has to be initialized by call of ApplFblInitDataProcessing
 *  \param[in,out] procParam Processing parameter data structure
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblDeinitDataProcessing( tProcParam * procParam )
{
   tFblResult result;

   result = kFblOk;

#  if !defined( FBL_ENABLE_ENCRYPTION_MODE )
#   if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)procParam;
#   endif /* V_ENABLE_USE_DUMMY_STATEMENT */
#  endif /* !FBL_ENABLE_ENCRYPTION_MODE */

   /* FblLibMem makes sure that data has been processed completely */

   return result;
}
#endif /* FBL_ENABLE_DATA_PROCESSING */

#if defined( FBL_ENABLE_APPL_TASK ) || \
    defined( FBL_ENABLE_APPL_TIMER_TASK )
/***********************************************************************************************************************
 *  ApplFblTask
 **********************************************************************************************************************/
/*! \brief       1ms user task.
 *  \details     This function is called every millisecond if the Bootloader is in idle state. It is not called during
 *               flash operations.
 **********************************************************************************************************************/
void ApplFblTask( void )
{

}
#endif /* FBL_ENABLE_APPL_TASK || FBL_ENABLE_APPL_TIMER_TASK */

#if defined( FBL_ENABLE_APPL_TASK ) ||\
    defined( FBL_ENABLE_APPL_STATE_TASK )
/***********************************************************************************************************************
 *  ApplFblStateTask
 **********************************************************************************************************************/
/*! \brief       Background user task.
 *  \details     This function is polled if the Bootloader is in idle state. It is not called during flash operations.
 **********************************************************************************************************************/
void ApplFblStateTask( void )
{
}
#endif /* FBL_ENABLE_APPL_TASK || FBL_ENABLE_APPL_STATE_TASK */

/***********************************************************************************************************************
 *  ApplFblCanBusOff
 **********************************************************************************************************************/
/*! \brief       This call-back function is called if the CAN controller enters bus-off state.
 **********************************************************************************************************************/
void ApplFblCanBusOff( void )
{
   /* Bus off detected, issue ECU reset */
   ApplFblReset();
}



#if defined( FBL_ENABLE_SLEEPMODE )
/***********************************************************************************************************************
 *  ApplFblBusSleep
 **********************************************************************************************************************/
/*! \brief       Indicates transition to bus silence.
 *  \details     By calling this function the FBL indicates the application
 *               that the bootloader can go to sleep (bus silence, no diagnostic requests).
 **********************************************************************************************************************/
void ApplFblBusSleep( void )
{

#if defined( FBL_WATCHDOG_ON )
   /* Wait for watchdog to be triggered */
   while (FblLookForWatchdog() != FBL_WD_TRIGGERED)
   {
      ;
   }
#endif

   /* ToDo: Shutdown of CAN and ECU */
   {
      /* Put transceiver in sleepmode, power down */
      ApplTrcvrSleepMode();

      /* ToDo: Wait for power down, check for wakeup request */
      while(1)
      {
         ;
      }
   }
   /* Wakeup request received, generate reset */
   ApplFblReset();
}
#endif /* FBL_ENABLE_SLEEPMODE */




/***********************************************************************************************************************
 *  ApplFblSetShutdownStatus
 **********************************************************************************************************************/
/*! \brief       This callback sets the shutdown status to be able to determine on startup if a normal or abnormal
 *               shutdown occured.
 *  \param[in]   status New shutdown status
 **********************************************************************************************************************/
void ApplFblSetShutdownStatus(tFblShutdownStatus status)
{
   fblShutdownStatus = status;
}

/***********************************************************************************************************************
 *  ApplFblGetShutdownStatus
 **********************************************************************************************************************/
/*! \brief       This callback returns the current shutdown status
 *  \return      Shutdown status
 **********************************************************************************************************************/
tFblShutdownStatus ApplFblGetShutdownStatus(void)
{
   return fblShutdownStatus;
}

/***********************************************************************************************************************
 *  ApplFblClrShutdownStatus
 **********************************************************************************************************************/
/*! \brief       Sets the shutdown status to abnormal (default)
 *  \return      Shutdown status
 **********************************************************************************************************************/
void ApplFblClrShutdownStatus(void)
{
   fblShutdownStatus = kFblShutdownStatusAbnormal;
}

#if defined( FBL_ENABLE_ASSERTION )
/***********************************************************************************************************************
 *  ApplFblFatalError
 **********************************************************************************************************************/
/*! \brief       If the bootloader assertions are enabled, this function will be called in case an invalid bootloader
 *               state is encountered.
 *  \param[in]   errorCode Code number of the encountered assertion
 *  \param[in]   module Name of the affected module (Only if extended info is enabled)
 *  \param[in]   line Line number where the assertion occurred (Only if extended info is enabled)
 **********************************************************************************************************************/
void ApplFblFatalError( FBL_DECL_ASSERT_EXTENDED_INFO(vuint8 errorCode) )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)errorCode;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

   /* TODO: This feature should be activated in development only. Please make sure this
            function isn't called in production code and assertions are disabled in GENy
            (set "Project State" to "Production (default)" or "Production (reduced tests)".
   */
   while (1)
   {
      ;
   }
}
#endif

#if (DET_ENABLED == STD_ON)
# define FBLAP_RAMCODE_START_SEC_CODE
# include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  ApplFbl_DetEntryHandler
 **********************************************************************************************************************/
/*! \brief       Called by DET module to check if a DET error is intended bootloader behavior or not.
 *  \param[in]   ModuleId Code number of the encountered assertion
 *  \param[in]   InstanceId Name of the affected module (Only if extended info is enabled)
 *  \param[in]   ApiId Line number where the assertion occurred (Only if extended info is enabled)
 *  \param[in]   ErrorId Line number where the assertion occurred (Only if extended info is enabled)
 *  \return      Report if error should be handed over to DET or not (E_OK or FALSE depending on interface)
 **********************************************************************************************************************/
# if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
FUNC(Std_ReturnType, DET_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
# else
FUNC(boolean, DET_APPL_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
# endif
{
# if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
   Std_ReturnType result = E_OK;
# else
   boolean result = FALSE;
# endif

# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_DummyStmt */
   (void)InstanceId;
   (void)ApiId;
# endif

   switch (ModuleId)
   {
#  if defined( CANTP_MODULE_ID )
      case CANTP_MODULE_ID:
      {
         switch (ErrorId)
         {
            /* CAN TP errors which can be triggered from outside shouldn't trigger a DET. */
            case CANTP_E_PARAM_CONFIG:
            case CANTP_E_INVALID_RX_BUFFER:
            case CANTP_E_INVALID_RX_LENGTH:
            case CANTP_E_INVALID_TATYPE:
            case CANTP_E_INVALID_FRAME_TYPE:
            case CANTP_E_RX_TIMEOUT_AR:
            case CANTP_E_RX_TIMEOUT_BR:
            case CANTP_E_RX_TIMEOUT_CR:
            case CANTP_E_RX_INVALID_SN:
            case CANTP_E_RX_WFTMAX:
            case CANTP_E_RX_RESTART:
            case CANTP_E_TX_TIMEOUT_AS:
            case CANTP_E_TX_TIMEOUT_BS:
            case CANTP_E_TX_TIMEOUT_CS:
            case CANTP_E_TX_FC_OVFL:
            case CANTP_E_TX_INVALID_FS:
            case CANTP_E_TX_RES_STMIN:
            case CANTP_E_TX_TRANSMIT_ERROR:
            case CANTP_E_NO_ERROR:
            {
#   if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
               result = E_NOT_OK;
#   else
               result = TRUE;
#   endif
               break;
            }
            default:
            {
               /* Keep error */
               break;
            }
         }
         break;
      }
#  endif /* CANTP_MODULE_ID */
#  if defined( CAN_MODULE_ID )
      case CAN_MODULE_ID:
      {
         switch (ErrorId)
         {
            case CAN_E_DATALOST:
            {
#   if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
               result = E_NOT_OK;
#   else
               result = TRUE;
#   endif
               break;
            }
            default:
            {
               /* Keep error */
               break;
            }
         }
         break;
      }
#  endif /* CAN_MODULE_ID */
      default:
      {
         /* Unknown module. Keep error. */
         break;
      }
   }

   return result;
}
# define FBLAP_RAMCODE_STOP_SEC_CODE
# include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

/* module specific MISRA deviations:
   MD_FblKbApiFrame_3218_FileScopeStatic:
      Reason:     Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk:       Unintended use of object in wrong scope.
      Prevention: Architectural pattern supports prevention of incorrect use of objects in wrong context.
                  Code inspection focus on correct use of objects.
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
 *  END OF FILE: FBL_AP.C
 **********************************************************************************************************************/
