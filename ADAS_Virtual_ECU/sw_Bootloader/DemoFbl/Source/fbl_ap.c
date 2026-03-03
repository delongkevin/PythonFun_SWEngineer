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

#include "ti/csl/csl_types.h"
#include "ti/drv/sciclient/sciclient.h"
#include "ti/cslr_intr_mcu_r5fss0_core0.h"
#include "ti/csl/arch/r5/csl_arm_r5_mpu.h"
#include "ti/board/src/j721s2_hyd/include/board_power.h"
#include "ti/gpio.h"

#include "BrsMain.h"
#include "BrsHw.h"
# include "Det.h"
# if (DET_ENABLED == STD_ON)
#   include "Can_30_Mcan.h"
#   include "CanTp.h"
# endif
#include "Csm.h"
# include "fbl_apnv.h"
# include "fbl_diag.h"
# include "fbl_diag_core.h"

#define CSL_WKUP_CTRL_MMR0_CFG0_BASE        0x43000000UL
#define CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG31  0x0001C07CUL
#define CSL_WKUP_GPIO0_BASE  			    0x42110000UL
#define GPIO_DIRECTION_OUTPUT               0U

#define D_EOL_MARKER_DATA_ADDRESS      		((uint32 *)0X97BFFC00U) /*EOL*/
#define SIZE_OF_EOL_MARKER_DATA 			4u
#define D_EOL_MARKER_DATA                   0xA5u,0xA5u,0xA5u,0xA5u

static const uint8 s_Verify_EOL_Marker_Data_au8[SIZE_OF_EOL_MARKER_DATA] = {D_EOL_MARKER_DATA};
boolean IsEOlDataAvailaible = FALSE;
uint8 MCU1_0_AuthFailStatus = FALSE;
uint8 ActualMarkerData_au8[SIZE_OF_EOL_MARKER_DATA] = {0};
sint8 MemCmpResult = 0 ;
vuint8 flashStatBuffer[2u];
#define CSL_REG32_WR(p, v)  (CSL_REG32_WR_RAW((volatile uint32 *) (p), (uint32) (v)))

// static inline void CSL_REG32_WR_RAW(volatile uint32 * const p, uint32 v)
// {
//   *p = v;
//   return;
// }

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

/* TODO : Enable below source code after secure boot is integrated */
#if 0
#if ( (FBLSB_API_REFERENCE_VERSION_MAJOR != 0x02u) || \
      (FBLSB_API_REFERENCE_VERSION_MINOR < 0x01u) )
# error "A newer version of FblLib_SecBoot is required which contains the API FblSb_GetExtendedErrorCode"
#endif
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

#define F181_OFFSET kApplInfoOffsetSoftwareIdentification_F181
#define F122_OFFSET kApplInfoOffsetSwEbomPartNumber_F122
#define F132_OFFSET kApplInfoOffsetEbomEcuPartNumber_F132
#define F133_OFFSET kApplInfoOffsetEBOMAssemblyPartNumber_F133
#define F134_OFFSET kApplInfoOffsetCODEPAssemblyPartNumber_F134
#define F187_OFFSET kApplInfoOffsetCodepEcupartNumber_F187
#define F188_OFFSET kApplInfoOffsetFCAESLMECUSoftwareNumber_F188
#define F18A_OFFSET kApplInfoOffsetFCAESLMECUSoftwareCalibrationNumber_F18A
#define F18B_OFFSET kApplInfoOffsetFCAESLMECUSoftwareApplicationNumber_F18B
#define F194_OFFSET kApplInfoOffsetSupplierECUSoftwarePartNumber_F194
#define F195_OFFSET kApplInfoOffsetSupplierECUSoftwareVersionNumber_F195
#define F110_OFFSET kApplInfoOffsetDiagnosticVersionFlashDefinition_F110

#define INFO_HEADER_SIZE 128u

#define INFO_HEADER_START_ADDRESS 0x3001C0ul



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
   {  0x93u,               0x33,             0x45,             0x53  },

   /* F110 data - Diagnostic Veriant*/
   { 0x00u, 0x30u},

   /* F110 data - Software Defintion Number */
   { 0x00u, 0x01u},

   /* F110 data - Supplier ID */
   { 0x00u, 0x49},

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
   { 0x20 },

   /* F180  Boot Software Version information */
   { 0x19, 0x04, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },

   /* F154 Hardware Supplier Identification */
   { 0x00, 0x49 },

   /* F155 Software Supplier Identification */
   { 0x00, 0x049 },

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

/* Tester Present counter */
uint32 TesterPresentCounter = 0;
/* Tester Present flag */
uint8 TesterPresentFlag = FALSE;

/*EOL: F193 SUPPLY ECU VERSION PART NUMBER*/
#define D_SUPPLY_ECU_VERSION_PAR_NUMBER                 ((uint32 *)0X97BFFC42U) /*EOL*/

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
V_MEMRAM0  V_MEMRAM1 SecureLogRecord_t V_MEMRAM2  SecureLogRecord_Group2;
#if 0
#if defined( FBL_ENABLE_VECTOR_HW )
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 flashlight;
#endif
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

extern void SecureLogEvent(const EventType Event, const EventSubType SubEvent, const uint8* EventData);
/***********************************************************************************************************************
 *  ApplFblStartApplication
 **********************************************************************************************************************/
/*! \brief       Function is called before any other FBL initialization
 **********************************************************************************************************************/
void ApplFblStartApplication( void )
{
}

volatile uint8 debugFblVar = 1;
/***********************************************************************************************************************
 *  ApplFblInit
 **********************************************************************************************************************/
/*! \brief       Function is called before any other FBL initialization
 **********************************************************************************************************************/
void ApplFblInit( void )
{

#if 1
	while(debugFblVar==0)
	{

	}
#endif

	Sciclient_ConfigPrms_t clientPrms;
	int32_t ret = (uint8)CSL_EFAIL;

	(void)Sciclient_configPrmsInit(&clientPrms);
	clientPrms.opModeFlag = SCICLIENT_SERVICE_OPERATION_MODE_POLLED;
	clientPrms.pBoardCfgPrms = NULL;
	clientPrms.isSecureMode = 0; /* default board cfg is for non-secure mode */
	clientPrms.c66xRatRegion = 0;
	clientPrms.skipLocalBoardCfgProcess = TRUE;
	//clientPrms.skipLocalBoardCfgProcess = FALSE;

	ret= Sciclient_init(&clientPrms);
	if(ret!=CSL_PASS)
	{
		while(1);
	}

#if 1
	ret = Sciclient_boardCfg(NULL);
	if(ret!=CSL_PASS)
	{
		while(1);
	}
	ret =Sciclient_boardCfgPm(NULL);
	if(ret!=CSL_PASS)
	{
		while(1);
	}
	ret = Sciclient_boardCfgSec(NULL);
	if(ret!=CSL_PASS)
	{
		while(1);
	}
	ret = Sciclient_boardCfgRm(NULL);
	if(ret!=CSL_PASS)
	{
		while(1);
	}
#endif
#if defined( BRS_FBL_LEGACY )
# if defined( BRSHW_PREINIT_AVAILABLE )
   /* HW specific pre-initialization. */
   BrsHwPreInitPowerOn();
# endif /* BRSHW_PREINIT_AVAILABLE */

# if defined( BRS_ENABLE_WATCHDOG )
   /* Disable Watchdog */
   BrsHwWatchdogInitPowerOn();
# endif /* BRS_ENABLE_WATCHDOG */

# if defined( BRS_ENABLE_PLLCLOCKS )
   /* Initialize the PLLs. */
   BrsHwPllInitPowerOn();
# endif /* BRS_ENABLE_PLLCLOCKS */

# if defined( BRSHW_DISABLE_ECC_AVAILABLE )
   /* Disable Flash ECC error reporting. */
   BrsHwDisableEccErrorReporting();
# endif /* BRSHW_DISABLE_ECC_AVAILABLE */

# if defined( FBL_ENABLE_PRE_TIMERINIT )
   /* Timer is stopped by mode switch and has to be re-initialized. */
   FblTimerInit();
# endif /* FBL_ENABLE_PRE_TIMERINIT */

# if defined( FBL_ENABLE_VECTOR_HW ) && \
     defined( BRS_ENABLE_PORT )
   /* Perform Port configuration. */
   BrsHwPortInitPowerOn();
# endif /* FBL_ENABLE_VECTOR_HW && BRS_ENABLE_PORT */
#endif /* BRS_FBL_LEGACY */
   /* Initialize Ports */
   BrsHwPortInitPowerOn();
   /* Initialize NvM-Driver */

#if defined( WRAPNV_USECASE_DRVEEP )
   (void)EepromDriver_InitSync(V_NULL);
#else
   WrapNv_Init();
#endif

   /* Init Seed response status */
   securitySeedResponse = kNewSeedRequest;
   /* Check if Abnormal reset happened */
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
    	  /* Disable Watchdog during FBL initialization */
    	  PMIC_Disable_Wdg();
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
         /* Read NvM blocks after init */
         ApplFblNvReadSecondCounter(&SecondCounter);
         ApplFblNvReadSystemTimestamp(&SystemTime[0]);
         ApplFblNvReadCertificateExpired(&CertificateExpired);
         ApplFblNvReadFlashStatus(FBL_LBT_MCU10_APPLICATION_LB_BLOCK_NUMBER, &MCU1_0_AuthFailStatus);
         ApplFblNvReadProgrammingStatus(flashStatBuffer);
         /* Check if System time was successfully parsed and has some value saved in NvM */
         if(SystemTime[0] != 0xFF)
         {
            IsSystemTimeSet = TRUE;
            /* Store latest system time in epoch format in TimestampCounter */
            getEpochTime(&SystemTime[0], &TimestampCounter);
         }
         /* Copy EOL Marker in local variable */
         (void)MEMCPY(ActualMarkerData_au8, D_EOL_MARKER_DATA_ADDRESS, (uint8)SIZE_OF_EOL_MARKER_DATA);
         /* Compare it for validation */
         MemCmpResult = memcmp(ActualMarkerData_au8,s_Verify_EOL_Marker_Data_au8,(uint8)SIZE_OF_EOL_MARKER_DATA);
         if(0u==MemCmpResult)
         {
        	 IsEOlDataAvailaible = TRUE;
         }
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
    	 ApplFblNANDMemInit();
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
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);   /* PRQA S 2986 */ /* MD_FblKbApiOem_2986 */
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
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);   /* PRQA S 2986 */ /* MD_FblKbApiOem_2986 */
   /* Give vHSM access to data flash operations */
   opMode = CRYPTO_30_VHSM_DATAFLASH_STOP;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);

   /* Simulate DET functionality in case of any error */
   assertFblUser(retVal == E_OK, kFblSysAssertDet);
}
#endif /* FBL_MIO_ENABLE_HOOKS */

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
   if(diagServiceCurrent == kDiagSidTesterPresent)
   {
	   FblTesterPresentCounterReload();
	   TesterPresentFlag = TRUE;
   }
   
   if(diagServiceCurrent == kDiagSidTransferData)
   {
      /* Send response pending in case of long NV accesses */
      FblDiagSetRcrRpAllowed();
      DiagExRCRResponsePending(kForceSendResponsePending);
   }

/*   switch (diagServiceCurrent)
   {
      case kDiagSidDiagnosticSessionControl:
      {
         break;
      }
      case kDiagSidEcuReset:
      {
         break;
      }
      case kDiagSidReadDataByIdentifier:
      {
    	  FblDiagSetRcrRpAllowed();
    	   Send response pending in case of long NV accesses
    	  DiagExRCRResponsePending(kForceSendResponsePending);

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
    	  FblDiagSetRcrRpAllowed();
    	   Send response pending in case of long NV accesses
    	  DiagExRCRResponsePending(kForceSendResponsePending);

         break;
      }
      case kDiagSidRoutineControl:
      {
    	  FblDiagSetRcrRpAllowed();
    	   Send response pending in case of long NV accesses
    	  DiagExRCRResponsePending(kForceSendResponsePending);
         break;
      }
      case kDiagSidRequestDownload:
      {
         break;
      }
      case kDiagSidTransferData:
      {
    	  if(0x00 == pbDiagData[1])
    	  {
    		  FblDiagSetRcrRpAllowed();
    		   Send response pending in case of long NV accesses
    		  DiagExRCRResponsePending(kForceSendResponsePending);
    	  }
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
   }*/

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
   vuint8 compatibilityByte;
   FBL_ADDR_TYPE pCompatibilityField;
   vuint8 returnValue;
   vuint8 SupplyECUVer_F193;

   /* Preset values */
   returnValue = kDiagCheckCompatibilitySwHw;

   /* Get address of compatibility list */
   pCompatibilityField = (ApplFblGetModuleHeaderAddress(blockIdx) + kApplInfoOffsetHwCompatibilityCounter );
   
   if(blockIdx == FBL_LBT_SECURITY_CERT_LB_BLOCK_NUMBER) 
   {
      pCompatibilityField = (ApplFblGetModuleHeaderAddress(blockIdx) - 0x1C0 + CERTSTORE_INFO_HEADER_OFFSET +kApplInfoOffsetHwCompatibilityCounter);
   }

   /* Read HW compatibility Byte: from part num header */
   (void)FblReadProm(pCompatibilityField, &compatibilityByte, 1u);
   /* Read SUPPLY ECU VERSION PART NUMBER F193: from EOL */
   (void)MEMCPY(&SupplyECUVer_F193, D_SUPPLY_ECU_VERSION_PAR_NUMBER, 1u);

   /* Compare compatibility list to hardware compatibility version */
   if ((SupplyECUVer_F193 == compatibilityByte))
   {
      returnValue = kDiagCheckCompatibilityOk;
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
   vuint8 actualVersion;
   vuint8 referenceVersion[kApplInfoSizeSwCompatibility];
   vuint8 validityFlags[kEepSizeValidityFlags];
   vuint8 result;
   boolean referenceBlockFound = FALSE;
   tFblAddress moduleHeaderAddr;
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

      while (referenceBlockFound!=TRUE)
      {
         /* Boot blocks are not considered for compatibility check */
         if ((iterBlock.blockType != kBlockTypeBoot)&&(iterBlock.blockType != kBlockTypeData))
         {
            if (referenceBlockFound != TRUE)
            {
               /* First non-Boot and non-Data block is used as reference */
               (void)FblReadProm(ApplFblGetModuleHeaderAddress(iterBlock.blockNr) + kApplInfoOffsetSwCompatibility,
                  (vuint8 *)&referenceVersion, kApplInfoSizeSwCompatibility);
               referenceBlockFound = TRUE;
            }
         }
         /* Prepare next cycle */
         iterBlock = FblLbtBlockNext();
      }

      FblLbtBlockFilterInit(&blockFilter);
      iterBlock = FblLbtBlockFirst(&blockFilter);

      while (FblLbtBlockDone() == FALSE)
      {
    	  /* Boot blocks are not considered for compatibility check */
    	  if (iterBlock.blockType != kBlockTypeBoot)
    	  {
    		  /* Check is performed for valid logical blocks only. If an optional block  *
    		   * is not valid, the compatibility status will be ignored.                 */
    		  if ((validityFlags[iterBlock.blockNr >> 3u] & (vuint8)(1u << (iterBlock.blockNr & 7u))) == 0u)
    		  {
    			  moduleHeaderAddr = ApplFblGetModuleHeaderAddress(iterBlock.blockNr);
    			  if(iterBlock.blockNr == FBL_LBT_SECURITY_CERT_LB_BLOCK_NUMBER)
    			  {
    				  moduleHeaderAddr = iterBlock.blockStartAddress+CERTSTORE_INFO_HEADER_OFFSET;
    			  }
    			  /* Check if module version matches */
    			  (void)FblReadProm(moduleHeaderAddr + kApplInfoOffsetSwCompatibility,
    					  (vuint8 *)&actualVersion, 1);
    			  if (referenceVersion[iterBlock.blockNr] != actualVersion)
    			  {
    				  /* Inconsistency found */
    				  result = kDiagCheckCompatibilitySwSw;
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
uint8 InfoHeaderBuff[400];
uint8 SupplierECUSoftwarePartNumber_F194[kApplInfoSizeSupplierECUSoftwarePartNumber_F194];
uint8 SupplierECUSoftwareVersionNumber_F195[kApplInfoSizeSupplierECUSoftwareVersionNumber_F195];
uint8 ECUDiagnosticIdentification_F110[kApplInfoSizeDiagnosticVersionFlashDefinition_F110];
uint8 EBOMAssemblyPartNumber_F133[kApplInfoSizeEBOMAssemblyPartNumber_F133];
uint8 SoftwareEBOMPartNumber_F122[kApplInfoSizeSwEbomPartNumber_F122];
uint8 CODEPAssemblyPartNumber_F134[kApplInfoSizeCODEPAssemblyPartNumber_F134];
uint8 FCAESLMECUSoftwareCalibrationNumber_F18A[kApplInfoSizeFCAESLMECUSoftwareCalibrationNumber_F18A];
uint8 FCAESLMECUSoftwareApplicationNumber_F18B[kApplInfoSizeFCAESLMECUSoftwareApplicationNumber_F18B];

uint8 EbomEcuPartNumber_F132[kApplInfoSizeEbomEcuPartNumber_F132];
uint8 CodepEcupartNumber_F187[kApplInfoSizeCodepEcupartNumber_F187];
uint8 FCAESLMECUSoftwareNumber_F188[kApplInfoSizeFCAESLMECUSoftwareNumber_F188];
uint8 SoftwareIdentification_F181[kApplInfoSizeSoftwareIdentification_F181];

uint8 BootSoftwareVersionInformation_F180[13] = {0x19, 0x04, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};
uint8 reprogAttemptCounter[2];
uint8 buff[10];

vuint8 ApplFblCheckProgDependencies( void )
{
   vuint8 result;
   vuint8 blockCount;
#if defined( FBL_ENABLE_PRESENCE_PATTERN )
   vuintx i;
#endif
   tBlockDescriptor iterBlock;
   tFblLbtBlockFilter blockFilter;
   vuint8 validityFlags[kEepSizeValidityFlags];
   const vuint8 progSuccessful = 0xA5;

   /* Initialize variables */
   result = kDiagCheckCompatibilityOk;
   /* Send response pending in case of long NV accesses */
   DiagExRCRResponsePending(kForceSendResponsePending);
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

   if(s_BootUpdater != TRUE) /*s_BootUpdater != TRUE (i.e, its not Fbl updater)*/
   {
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

      /*Check if all dependency checks are passed*/
      if(kFblOk == result)
      {
         /*Read all part numbers from Pflash and backup to EEPROM*/
         if (IO_E_OK == MemDriver_RReadSync(InfoHeaderBuff, INFO_HEADER_SIZE, INFO_HEADER_START_ADDRESS))
         {

            (void)MEMCPY(EbomEcuPartNumber_F132, &InfoHeaderBuff[F132_OFFSET], kApplInfoSizeEbomEcuPartNumber_F132);
            (void)MEMCPY(CodepEcupartNumber_F187, &InfoHeaderBuff[F187_OFFSET], kApplInfoSizeCodepEcupartNumber_F187);
            (void)MEMCPY(FCAESLMECUSoftwareNumber_F188, &InfoHeaderBuff[F188_OFFSET], kApplInfoSizeFCAESLMECUSoftwareNumber_F188);

            (void)MEMCPY(SupplierECUSoftwarePartNumber_F194, &InfoHeaderBuff[F194_OFFSET], kApplInfoSizeSupplierECUSoftwarePartNumber_F194);
            (void)MEMCPY(SupplierECUSoftwareVersionNumber_F195, &InfoHeaderBuff[F195_OFFSET], kApplInfoSizeSupplierECUSoftwareVersionNumber_F195);
            (void)MEMCPY(ECUDiagnosticIdentification_F110, &InfoHeaderBuff[F110_OFFSET], kApplInfoSizeDiagnosticVersionFlashDefinition_F110);
            (void)MEMCPY(EBOMAssemblyPartNumber_F133, &InfoHeaderBuff[F133_OFFSET], kApplInfoSizeEBOMAssemblyPartNumber_F133);
            (void)MEMCPY(CODEPAssemblyPartNumber_F134, &InfoHeaderBuff[F134_OFFSET], kApplInfoSizeCODEPAssemblyPartNumber_F134);
            (void)MEMCPY(FCAESLMECUSoftwareCalibrationNumber_F18A, &InfoHeaderBuff[F18A_OFFSET], kApplInfoSizeFCAESLMECUSoftwareCalibrationNumber_F18A);
            (void)MEMCPY(FCAESLMECUSoftwareApplicationNumber_F18B, &InfoHeaderBuff[F18B_OFFSET], kApplInfoSizeFCAESLMECUSoftwareApplicationNumber_F18B);

            /*Backup all part numbers to EEPROM*/
            ApplFblNvWriteEbomEcuPartNumber(EbomEcuPartNumber_F132);                                    /*0xF132*/
            ApplFblNvWriteCoDePEcuPartNumber(CodepEcupartNumber_F187);      			                   /*0xF187*/
            ApplFblNvWriteVehicleManufEcuSwNumber(FCAESLMECUSoftwareNumber_F188);                       /*0xF188*/

            ApplFblNvWriteDID_F194_Supplier_Ecu_SW_PartNum(SupplierECUSoftwarePartNumber_F194);         /*0xF194*/
            ApplFblNvWriteDID_F195_Supplier_Ecu_SW_VerNum(SupplierECUSoftwareVersionNumber_F195);       /*0xF195*/
            ApplFblNvWriteDiagnosticVersion(ECUDiagnosticIdentification_F110);                          /*F110*/
            ApplFblNvWriteEbomAssemblyPartNumber(EBOMAssemblyPartNumber_F133);                          /*0xF133*/

            ApplFblNvWriteCodepAssemblyPartNumber(CODEPAssemblyPartNumber_F134);                         /*0xF134*/
            ApplFblNvWriteDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num(FCAESLMECUSoftwareCalibrationNumber_F18A);    /*0xF18A*/
            ApplFblNvWriteDID_F18B_FCA_ESLM_ECU_SW_App_Num(FCAESLMECUSoftwareApplicationNumber_F18B);    /*0xF18B*/

            ApplFblNvWriteSoftwareIdentification(0,BootSoftwareVersionInformation_F180);                /*F180*/

            /*Set ProgReq Flag to 0xA5 so that application knows there was a
               * successful re -programming and it can write latest Odo value and other information */
            ApplFblNvWriteProgReqFlag(&progSuccessful);

            /*Temporary code to fill odo flashing.
               * Remove the 2 lines below after application has implemented odo value writing in app
               * based on the above ProgReqFlag*/
            ApplFblNvReadProgAttempts(0u,reprogAttemptCounter);
            ApplFblNvWriteDID_2002_OdoFlashing(reprogAttemptCounter);
         }
      }
   }
   else /* Req: 16442522 : s_BootUpdater = True (bypass the compatibility checks)*/
   {
      result = kFblOk;
   }
   /* If required, additional checks can be added here */

   return result;
   /* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

#if ( SEC_SECURITY_CLASS == SEC_CLASS_VENDOR )
	// FCA Header length assuming single segment	
#define FCA_SD15HEADER_LEN 0x1C0
#define BUFFER_SIZE 2048u
#define FILE_SIZE_OFFSET 4u
#define FILE_DIGEST_OFFSET 8u
vuint8 SD15HeaderBuffer[FCA_SD15HEADER_LEN]={0u};
uint8 segmentList [1]= {0u};
vuint32 SigVerifydataLength = 1u;
uint32 dataLength = 0u;
vuint8 verifyResult = CRYPTO_E_VER_OK;

uint8 FCAHeaderFileDigest[SEC_SIZE_HASH_SHA256] = { 0u };

volatile uint32 Size = 0u;
volatile uint8 *FileSize = NULL_PTR;
volatile uint8 Readbuffer[BUFFER_SIZE] = {0u};
uint8 calculatedFileDigest[SEC_SIZE_HASH_SHA256] = {0u};
uint32 Resultlength = 32u;
uint8 *FileAddress = NULL_PTR;
uint8 *BlkAddress = NULL_PTR;

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
   uint32 nCnt = 0u;
   uint32 RemainingByteCnt = 0u;
   uint8 RemainingByteFlag = 0u;
	vuint8 result = kDiagCheckVerificationGeneralFailure;
	vuint8 localRetVal = E_NOT_OK;
	vuint8 Chkresult = kFblFailed;
	tBlockDescriptor blockDescriptor;
	tFblBmHdrHeader bmHdrHeader;
	const uint8 * dataPtr = segmentList;
	uint32 VerifyMacLen = D_CMAC_LEN;
	SecureLogRecord_t *group;
	uint32 TimeStamp = getTimeStamp();
	DiagExRCRResponsePending(kForceSendResponsePending);
	if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
	{
		/* Read SD15 Header to RAM buffer*/
		if (FblReadProm(blockDescriptor.blockStartAddress, (vuint8 *)&SD15HeaderBuffer, FCA_SD15HEADER_LEN)== FCA_SD15HEADER_LEN)
		{
			/* PRQA S 0306 2 */ /* MD_FblLibSecBoot_0306 */
			if (E_OK == Csm_SignatureVerify(CsmConf_CsmJob_CsmJob_Fca_HeaderVerify, CRYPTO_OPERATIONMODE_SINGLECALL, dataPtr, SigVerifydataLength, (P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR))SD15HeaderBuffer, FCA_SD15HEADER_LEN, &verifyResult))
			{
				if(CRYPTO_E_VER_OK == verifyResult)
				{
					FileSize = &SD15HeaderBuffer[FILE_SIZE_OFFSET];
					memcpy(FCAHeaderFileDigest,&SD15HeaderBuffer[FILE_DIGEST_OFFSET],SEC_SIZE_HASH_SHA256);
					Size = (((uint32)FileSize[0u] << 24u) | (((uint32)FileSize[1u]) << 16u ) | (((uint32)FileSize[2u]) << 8u ) | ((uint32)FileSize[3u])); /* Extract the File size information */   
               nCnt = Size / BUFFER_SIZE;
               RemainingByteCnt = Size % BUFFER_SIZE;

               if (nCnt > 0)
               {
                  dataLength = BUFFER_SIZE;
               }    
               else 
               {
                  dataLength = RemainingByteCnt;
               }
					FileAddress = blockDescriptor.blockStartAddress + FCA_SD15HEADER_LEN;
					BlkAddress = FileAddress;
					localRetVal = Csm_Hash(CsmConf_CsmJob_CsmJob_CalculateHash,CRYPTO_OPERATIONMODE_START,NULL_PTR,0,NULL_PTR,NULL_PTR);
					if(localRetVal == E_OK )
					{
						do{
							localRetVal = E_NOT_OK;
							if((nCnt % 50u) == 0u)
							{
								DiagExRCRResponsePending(kForceSendResponsePending);
							}
							if(nCnt == 0u)
							{
                        if (RemainingByteCnt == 0)
                        {
                           break;
                        }
								dataLength = RemainingByteCnt;
                        RemainingByteFlag = 1u;
							}
							if (FblReadProm(BlkAddress, (vuint8 *)Readbuffer, dataLength) == dataLength)
							{
								localRetVal = Csm_Hash(CsmConf_CsmJob_CsmJob_CalculateHash,CRYPTO_OPERATIONMODE_UPDATE,(vuint8 *)Readbuffer,dataLength,calculatedFileDigest,&Resultlength);
							}
							if(localRetVal == E_NOT_OK)
							{
								break;
							}

							if(nCnt > 0u)
							{
								nCnt = nCnt-1;
							}
							BlkAddress = BlkAddress + BUFFER_SIZE;

						}while(RemainingByteFlag != 1u);
					}

					if(localRetVal == E_OK)
					{
						localRetVal =  Csm_Hash(CsmConf_CsmJob_CsmJob_CalculateHash,CRYPTO_OPERATIONMODE_FINISH,NULL_PTR,0,calculatedFileDigest,&Resultlength);
						if(localRetVal == E_OK)
						{
							if(0u == memcmp(calculatedFileDigest,FCAHeaderFileDigest,SEC_SIZE_HASH_SHA256))
							{
								result = kDiagCheckVerificationOk;
							}
							else
							{
								result = kDiagCheckVerificationCRCFailed;
							}
						}
					}
					if(localRetVal == E_NOT_OK)
					{
						result = kDiagCheckVerificationGeneralFailure;
					}

				}
				else
				{
					result = kDiagCheckVerificationSignatureFailed;
				}
			}

		}
	}

	if(kDiagCheckVerificationOk!=result)
	{
		/*Log Starting address of the Block*/
		SecureLogEvent(CYBERSEC_FAILURE, SEC_FLASHING_FAILURE, &blockDescriptor.blockStartAddress);

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
	uint32 delaycnt;
	/* Transition to Standby mode */
	GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 1U, GPIO_PIN_LOW);
	for(delaycnt=0;delaycnt<50000;delaycnt++);
	GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE,15U, GPIO_PIN_HIGH);
	for(delaycnt=0;delaycnt<50000;delaycnt++);
}

/***********************************************************************************************************************
 *  ApplFblSetVfp
 **********************************************************************************************************************/
/*! \brief       Function is called when the FBL enters programming mode.
 *  \details     Port bits have to be set so that the required programming voltage is available.
 **********************************************************************************************************************/
void ApplFblSetVfp( void )
{
   /* Set flash programming voltage */
#if defined( BRSHW_VOLTAGE_FOR_FLASH_PROGRAMMING_AVAILABLE )
   BrsHwSetVfp();
#endif
}

/***********************************************************************************************************************
 *  ApplFblResetVfp
 **********************************************************************************************************************/
/*! \brief       This function is called when the programming is done.
 **********************************************************************************************************************/
void ApplFblResetVfp( void )
{
   /* Reset flash programming voltage */
#if defined( BRSHW_VOLTAGE_FOR_FLASH_PROGRAMMING_AVAILABLE )
   BrsHwResetVfp();
#endif
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
   /* Jump to Brs_PreMainStartup in the bootmanager */
//   JSR(0x9700af70);
   /*
       Set flag for regular shutdown 
   ApplFblSetShutdownStatus(kFblShutdownStatusNormal);
   */
   /* Reset ECU */
   BrsHwSoftwareResetECU();
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
   //if (SECM_OK == SecM_CompareKey(key, seed))
   //{
      /* Key bytes are accepted */
      result = kFblOk;

   //}

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

   /* Conclude data processing in last round */
   result = ApplFblDataProcessing(procParam);


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
   static V_MEMRAM1 vuint16 V_MEMRAM2 flashlight;
   static boolean IsNvmBlockRead = FALSE;
#if 0   /*Enable to check dummy CAN message*/
   Can_PduType dummy;
   uint8 myMsg[8] = { 0x04, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88 };
#endif
   static uint8 u8toggleLed = FALSE;
    uint32 regVal = 0;
	
   flashlight++;

   /* Increment timestamp counter */
   TimeStampIncrement();

   /* Check validity only after ADA security access */
   if((CheckCertSessionValid == TRUE) && (GetCurrentSession() != kFblDiagStateMaskSessionDefault))
   {
       /* Check certificate validity based on second counter */
       CheckAuthCertiValidity();
   }
   else
   {
	   CheckCertSessionValid = FALSE;
   }


   if(FblGetTesterPresentCounter() != 0)
   {
	   FblDecTesterPresentCounter();
   }
   else
   {
	   TesterPresentFlag = FALSE;
   }

   if (flashlight >= 500u)
   {
      flashlight = 0u;

      u8toggleLed = ((~u8toggleLed) & 0x01);

      regVal = 0x08050007U;
      CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG31, regVal);
      /* Set WAKEUP_GPIO0_31 Pin direction to output and toggle */
      GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 31U, GPIO_DIRECTION_OUTPUT);
      GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE,31U, u8toggleLed);

#if 0
      u8toggleLed = ((~u8toggleLed) & 0x01);

      /* Set WAKEUP_GPIO0_32 Pin direction to output and toggle */
      GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 32U, GPIO_DIRECTION_OUTPUT);
      GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE,32U, u8toggleLed);

      u8toggleLed = ((~u8toggleLed) & 0x01);

#endif

#if defined( FBL_ENABLE_VECTOR_HW )
      /* Toggle testport */
      /* Please check if this port is usable on your board */
# if defined( BRS_ENABLE_SUPPORT_LEDS )
#  if defined( BRSMAIN_VERSION ) && ( BRSMAIN_VERSION >= 0x0200u)
      BrsMainTogglePin(BRSMAIN_TOGGLEPIN_LED);
#  else
      BrsHwTogglePin(BRSHW_TOGGLEPIN_LED);
#  endif /* BRSMAIN_VERSION */
# endif /* BRS_ENABLE_SUPPORT_LEDS */
#endif /* FBL_ENABLE_VECTOR_HW */

#if 0 /*Enable to check dummy CAN message*/
      /* DEBUG: send a CAN test message to verify bootloader base timing */
      dummy.id = 0x18DAA0FF;                /* ID of dummy message */
      dummy.length = sizeof(myMsg);    /* Set message length to 8 */
      dummy.sdu = (uint8*)&myMsg[0];
      dummy.swPduHandle = 0u;
      Can_30_Mcan_Write(0u, &dummy);
#endif

   }
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
    if(FblMainGetFblShutdownRequest())
    {
        /* Save Second counter to NvM */
        ApplFblNvWriteSecondCounter(&SecondCounter);
    }

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
#  if defined( CAN_30_MCAN_MODULE_ID )
      case CAN_30_MCAN_MODULE_ID:
      {
         switch (ErrorId)
         {
            case CAN_30_MCAN_E_DATALOST:
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
IO_ErrorType result;
vuint8 readBuffer[512], writeBuffer[2048], readBuffer1[512], readBuffer2[1024];
uint8* readbuff = (uint8*)0x9d000000;
void ApplFblNANDMemInit(void)
{
	vuint32 i;
	vuint32 j;
	uint8 u8toggleLed = TRUE;
	/*pflaherty
	   External flash memory and spi can be tested with a series of read and write checks.
	   This avoids the requirement to download a logical block in order to access the external flash
	 */
	/*
	      We can access vMemAccM functions directly to test the read and write functionality.
	      We benefit, in that we have a method to test the driver - but, we must verify all of the following configurations
	      vMemAccM, vMem_Fbl, vMem_30_vxNand, vXSpi
	 */

	memSegment = FblMemSegmentNrGet(0x300000);
	if(IO_E_OK != MemDriver_InitSync((void *)0x300000))
	{
		while(1);
	}
/*	if(IO_E_OK != FblMemEraseRegion(0x300000 addr, 0x180000ul length))
	{
		while(1);
	}*/
	result = IO_E_NOT_OK;
	for (i = 0; i<512; i++)
	{
		readBuffer[i] = 0;
	}
	for (i = 0,j=0; i<2048; i++,j++)
	{
		writeBuffer[i] = j;

		j = (j==255)?0:i;
	}
#if 0
   /* Set WAKEUP_GPIO0_32 Pin direction to output and toggle */
    GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 32U, GPIO_DIRECTION_OUTPUT);
    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE,32U, u8toggleLed);

    u8toggleLed = ((~u8toggleLed) & 0x01);

    /*Read 1 Mega Bytes*/
	i = MemDriver_RReadSync(readbuff, 1048576u, 0x300000ul);
	if((IO_E_OK == i)||(IO_E_ERASED == i))
	{

	}
	else
	{
		while(1);
	}
	GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE,32U, u8toggleLed);

#endif

#if 0

//	if (IO_E_OK == MemDriver_REraseSync(0x180000u, 0x300000ul))
//	{
		if (IO_E_OK == MemDriver_RReadSync(readBuffer, 512u, 0x300000ul))
		{
			/*if (IO_E_OK == MemDriver_RWriteSync(writeBuffer, 2048u, 0x300000ul))
			{
				if (IO_E_OK == MemDriver_RReadSync(readBuffer, 512u, 0x300000ul))
				{
					result = IO_E_OK;
				}
				else
				{
					while(1);
				}
			}
			else
			{
				while(1);
			}*/
		}
		else
		{
			while(1);
		}
		if (IO_E_OK == MemDriver_RReadSync(readBuffer1, 512u, 0x388000ul))
		{
		}
		else
		{
			while(1);
		}
		if (IO_E_OK == MemDriver_RReadSync(readBuffer2, 512u, 0x3888F0ul))
		{
		}
		else
		{
			while(1);
		}
//	}
//else
//{
//		while(1);
//	}
#endif
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
