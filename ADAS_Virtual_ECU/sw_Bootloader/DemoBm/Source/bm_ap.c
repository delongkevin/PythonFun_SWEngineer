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
 *  01.00.00   2019-01-28  visrie  -                Initial version
 *  01.01.00   2019-02-18  vismvi  ESCAN00102171    Variable declared but never referenced
 *                         visrie  ESCAN00102310    Added callout to check reprogramming flag
 *  01.01.01   2019-03-07  visrie  ESCAN00102386    Fixed compiler error in ApplFbl_DetEntryHandler
 *                                 ESCAN00102399    Check NvPattern only for non-RAM blocks
 *  02.00.00   2019-05-02  visrie  ESCAN00102518    Added support to read block/application validity from NV-Memory
 *                                 ESCAN00102761    Added support for 3rd Party Tricore HSM
 *                                 ESCAN00103026    Provide BmHeader instead of StartAddress to ApplFblBmStartSoftware
 *  03.00.00   2019-07-17  visrie  ESCAN00103750    Removed target order list configuration
 *  03.01.00   2019-08-14  visrie  FBL-487          Exclude callouts if overwritten by OEM/HW layer
 *  03.01.01   2019-09-04  visrcn  ESCAN00103607    Memory qualifier mismatch
 *  04.00.00   2019-12-04  visrie  FBL-456          Updated to new LibSecBoot interface
 *                                 ESCAN00105135    Added support for new BRS API
 *  04.01.00   2020-01-16  visrie  FBL-524          Added support for vHsm SecBoot library
 *  05.00.00   2020-04-09  visrie  FBL-1016         Support new vBaseEnv, added support for VTT
 *  05.01.00   2020-04-29  vistmo  FBL-1584         Added OTA startup support
 *  05.02.00   2020-08-13  vistmo  FBL-1489         Added support for OTA swap activation
 *  05.02.01   2021-03-17  vishor  ESCAN00108386    ApplFblBmIsValidBlock implementation does not consider
 *                                                   all possible use cases
 *                                 FBL-3018         No changes
 *  05.03.00   2021-08-11  visrie  FBL-3394         Move default implementation of CheckReprogFlag into FblBm_Ap
 *  05.04.00   2021-09-17  visjdn  FBL-3865         Add default SecBoot implementation for GHS/Escrypt
 *  05.04.01   2022-04-06  vismix  FBL-4773         Support THUMB mode
 *  05.05.00   2022-04-07  vishor  FBL-4822         Add support for new MagicFlag value and Swap API
 *  05.05.01   2022-06-23  vismix  ESCAN00111879    Boot manager does not wait for HSM update recovery
 *  05.06.00   2022-07-13  vismix  FBL-5391         Add callout for missing optional dependency
 **********************************************************************************************************************/

#define BM_AP_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "bm_ap.h"
#include "bm_main.h"
#include "fbl_inc.h"
#include "Csm.h"
#include "Csm_Cfg.h"
#include "Crypto_30_vHsm.h"

#if defined( FBL_ENABLE_HARDWARE_SWAP )
# include "fbl_swap.h"
#endif

#include "fbl_main_types.h"

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
# include "Det.h"
#endif
#if defined( FBLBM_ENABLE_SECURE_BOOT )
# include "fbl_secboot.h"
//#  include "Csm.h"
//#  include "Crypto_30_vHsm.h"
#endif /* FBLBM_AP_ENABLE_3RD_PARTY_TRICORE_HSM_USED */

# include "BrsHw.h"
#include "bm_rprc.h"
#include "ti/board/src/j721s2_hyd/include/board_power.h"
/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLBM_AP_VERSION != 0x0506u ) || \
    ( FBLBM_AP_RELEASE_VERSION != 0x00u )
# error "Error in bm_ap.c: Source and Header file are inconsistent!"
#endif
/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
/* Bootloader RAM/ROM location and length for copying application from ROM to RAM before execution */
#define BM_FBL_ROM_LOC     0x00280000ul /* CUSTOMER TODO: Replace this ROM address with the start of your FBL in ROM */
#define BM_FBL_RAM_LOC     0x90900000ul /* CUSTOMER TODO: Replace this RAM address with the start of your FBL in RAM */
#define BM_FBL_LENGTH      0x00080000ul /* CUSTOMER TODO: Replace this LENGTH with the LEGNTH of your FBL in ROM */

/* Application RAM/ROM location and length for copying application from ROM to RAM before execution */
#define BM_APPL_ROM_LOC     0x00300400ul /* CUSTOMER TODO: Replace this ROM address with the start of your APPL in ROM */
#define BM_APPL_RAM_LOC     0x97200000ul /* CUSTOMER TODO: Replace this RAM address with the start of your APPL in RAM */
#define BM_APPL_LENGTH      0x00180000ul /* CUSTOMER TODO: Replace this LENGTH with the LEGNTH of your APPL in ROM (LENGTH TO BE COPIED) */

/* Updater RAM/ROM location and length for copying application from ROM to RAM before execution */
#define BM_FBLUPD_ROM_LOC     0x00300000ul
#define BM_FBLUPD_RAM_LOC     0x97200000ul
#define BM_FBLUPD_LENGTH      0x00180000ul /* For DemoAppl/DemoUpdater, we only care about actual code (not fill code) */

/*Application starts at 0x300000 and first 1kB for FCA Header + BmHdrHeader*/
#define QSPI_OFFSET_MCU_1_0_APP_IMAGE 0x00300260ul

#define MCU10_FCA_HDR_START_ADDRESS       0x00300000ul
#define MCU10_FCA_HDR_SIGNATURE_ADDRESS   0x003000B0ul
#define FBL_FCA_HDR_START_ADDRESS         0x00280000ul
#define FBL_FCA_HDR_SIGNATURE_ADDRESS     0x002800B0ul

#define HSM_2_HOST_IPC_VALUE     *((volatile uint32 *)0x41C00904ul)
#define HSM_NVM_READALL_DONE     (uint32)0x4

#define HOST_TO_HSM_CURRENT_TIMESTAMP_AVAILAIBILITY_ADDR ((volatile uint32 *)0x41C00908)
#define HOST_TO_HSM_CURRENT_TIMESTAMP_ADDR ((volatile uint32 *)0x41C0090C)
#define HOST_TO_HSM_CURRENT_TIMESTAMP_DATA *((volatile uint32 *)0x41C0090C)
#define HOST_TO_HSM_SEC_COUNTER_ADDR ((volatile uint32 *)0x41C0091B)

#define FCA_HDR_SIGNATURE_LENGTH  256
#define HEADER_SIZE               0xB0
#define FCA_SD15HEADER_LEN        0x1C0
#define BUFFER_SIZE 4096
#define FILE_SIZE_OFFSET 4
#define FILE_DIGEST_OFFSET 8
#define SEC_SIZE_HASH_SHA256 32

#define D_MCU_1_0_AUTH_FLAG_STATUS                ((uint8 *)0x4028000CU)

#define APPLN_AUTH_OR_PARSE_FAIL_PATTERN 0xA5
#define APPLN_AUTH_OR_PARSE_FAIL_PATTERN_CLR 0x00
#define APPLN_AUTH_OR_PARSE_FAIL_CNT 3
#define APPLN_AUTH_OR_PARSE_FAIL_CNT_INIT 0
#define MCU_1_0_AUTH_FLAG_STATUS_INIT_VALUE 0x0

vuint8 MCU1_0_AuthStatus[2u] = {APPLN_AUTH_OR_PARSE_FAIL_PATTERN_CLR,APPLN_AUTH_OR_PARSE_FAIL_CNT_INIT};


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

void FblEcuReset(void);
uint8 FCAHeaderFileDigest[SEC_SIZE_HASH_SHA256] = { 0u };
volatile uint32 Size ;
volatile uint8 *FileSize;
uint32 nCnt;
uint32 RemainingByteCnt;
volatile uint8 Readbuffer[BUFFER_SIZE];
uint8 calculatedFileDigest[32] = {0};
uint32 Resultlength = 32;
tFblAddress FileAddress;
SecureLogRecord_t  SecureLogRecord_Group2;
tFblBmHdrHeader fblbmheader_fallback;
//#define MCU1_CPU0_ID 0x04u

extern uint8 SystemTime[15];
extern uint32 SecondCounter;
const uint8 DefaultSystemTime[15] = {0x32,0x30,0x32,0x33,0x30,0x39,0x32,0x36,0x31,0x34,0x34,0x35,0x34,0x32,0x5a};
const uint8 DefaultSecondCounter[4] = {0x0};

uint8 *ptr = NULL_PTR;
uint8 *SecCnt = NULL_PTR;
#if defined( _MICROSOFT_C_VTT_ )
# define FBLBM_AP_ENABLE_VTT_USECASE
#endif /* _MICROSOFT_C_VTT_ */

/* If no explicit LB for the LBT exists use the bootloader LB */
#if !defined( FBL_MTAB_LBT_BLOCK_NUMBER )
# define FBL_MTAB_LBT_BLOCK_NUMBER                       FBL_MTAB_BOOTLOADER_BLOCK_NUMBER
#endif /* FBL_MTAB_LBT_BLOCK_NUMBER */

/* Helper macro to get number of array entries */
#if defined( FBLBMAP_ARRAY_SIZE )
#else
# define FBLBMAP_ARRAY_SIZE(arr)                         (sizeof(arr) / sizeof((arr)[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define FBLBMAP_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
V_MEMRAM0 static V_MEMRAM1 vuintx V_MEMRAM2 g_ApplFblBmSearchUpdaterHeaderIndex;
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */

#define FBLBMAP_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if defined( FBLBM_ENABLE_SECURE_BOOT )
#  define FBLBMAP_RAMCODE_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
static void ApplFblBmWaitForHsm(void);
#  define FBLBMAP_RAMCODE_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBLBM_ENABLE_SECURE_BOOT */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

void FblEcuReset(void)
{
	struct tisci_msg_sys_reset_req request={0};
	struct tisci_msg_sys_reset_resp response = {0};

	Sciclient_ReqPrm_t reqParam;
	Sciclient_RespPrm_t respParam;

	/*Make STB and EN Pin to Low so that the Transciever goes to Standby*/
/*   GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 4, GPIO_DIRECTION_OUTPUT);
   GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 5, GPIO_DIRECTION_OUTPUT);

   GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 4, GPIO_PIN_LOW);
   GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 5, GPIO_PIN_LOW);*/

/*	GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 1U, GPIO_DIRECTION_OUTPUT);
	GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 15U, GPIO_DIRECTION_OUTPUT);

   GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 1U, GPIO_PIN_LOW);
   GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE,15U, GPIO_PIN_LOW);*/

	//VStdLib_MemClr(&request, sizeof(request));
	//request.domain = 0x0; /* Whole System reset */

	reqParam.messageType = (uint16_t) TISCI_MSG_SYS_RESET;
	reqParam.flags = (uint32_t) TISCI_MSG_FLAG_AOP;
	reqParam.pReqPayload = (const uint8_t *) &request;
	reqParam.reqPayloadSize = (uint32_t) sizeof (request);
	reqParam.timeout = (uint32_t) SCICLIENT_SERVICE_WAIT_FOREVER;
	respParam.flags = (uint32_t) 0; /* Populated by the API */
	respParam.pRespPayload = (uint8_t *) &response;
	respParam.respPayloadSize = (uint32_t) sizeof (response);
	//reqParam.forwardStatus= (uint8)156;

	Sciclient_service(&reqParam, &respParam);
}

#if defined( FBLBM_ENABLE_SECURE_BOOT )
#  define FBLBMAP_RAMCODE_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  ApplFblBmWaitForHsm
 **********************************************************************************************************************/
/*! \brief        Wait until vHSM is ready
 **********************************************************************************************************************/
static void ApplFblBmWaitForHsm(void)
{
   Std_ReturnType retVal;
   uint32 keyLength;
   uint32 hsm2host;
   uint32 host2hsm;

   /* Wait until vHsm has been started */
   do
   {
      keyLength = 4u;
      retVal = Csm_KeyElementGet(0u, CRYPTO_KE_CUSTOM_VHSM_STATUS_HSM2HOST, (uint8 *)&hsm2host, &keyLength);
      assertFblUser(retVal == E_OK, kFblSysAssertDet);
   } while (hsm2host == 0u);

   /* When a vHsmUpd is pending */
   if ((hsm2host & (1uL << CRYPTO_30_VHSM_HSM2HOST_UPDATERRUNNING)) == (1uL << CRYPTO_30_VHSM_HSM2HOST_UPDATERRUNNING))
   {
      keyLength = 4u;
#   error "Comment this line if vHsmUpdater is not used. If vHsmUpdater is used, please assign the value <vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtIpc/vHsmUpd_ExtIpcWaitMask> configured in the vHsm-updater to host2hsm below"
      host2hsm = 0x80000000u;
      /* Set configured Bit pattern to signalize the vHsmUpd that update can be started */
      retVal = Csm_KeyElementSet(0u, CRYPTO_KE_CUSTOM_VHSM_STATUS_HOST2HSM, (uint8 *)&host2hsm, keyLength);
      assertFblUser(retVal == E_OK, kFblSysAssertDet);

      /* Wait until vHsmUpd has been finished */
      do
      {
         FblLookForWatchdogVoid();

         keyLength = 4u;
         retVal = Csm_KeyElementGet(0u, CRYPTO_KE_CUSTOM_VHSM_STATUS_HSM2HOST, (uint8 *)&hsm2host, &keyLength);
         assertFblUser(retVal == E_OK, kFblSysAssertDet);
      } while ((hsm2host & ((1u << CRYPTO_30_VHSM_HSM2HOST_READY) | (1u << CRYPTO_30_VHSM_HSM2HOST_ACTIVE))) != ((1u << CRYPTO_30_VHSM_HSM2HOST_READY) | (1u << CRYPTO_30_VHSM_HSM2HOST_ACTIVE)));
   }

   /* Wait until vHsm is ready */
   Crypto_30_vHsm_WaitForHsmRam();
}
#  define FBLBMAP_RAMCODE_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBLBM_ENABLE_SECURE_BOOT */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#define FBLBMAP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
static tFblResult Bm_QSPIBootImage(sblEntryPoint_t *pEntry, uint32_t imageOffset);
int32_t BM_QSPI_ReadSectors(void *dstAddr, void *srcOffsetAddr, uint32_t length);
void BM_QSPI_seek(void *srcAddr, uint32_t location);
tFblLength FblReadPromPageAlign( tFblAddress address, V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * buffer, tFblLength length );
vuint8 BM_secureboot(tFblAddress target_Address);
extern uint32 getTimeStamp(void);

vuint8 SD15HeaderBuffer[FCA_SD15HEADER_LEN]={0};
vuint8 SD15HeaderBuffer_signature[FCA_HDR_SIGNATURE_LENGTH]={0};

/***********************************************************************************************************************
 *  ApplFblBmPowerOnPre
 **********************************************************************************************************************/
/*! \brief        Initialization callout
 **********************************************************************************************************************/
void ApplFblBmPowerOnPre( void )
{

}

/***********************************************************************************************************************
 *  ApplFblBmPowerOnPost
 **********************************************************************************************************************/
/*! \brief        Initialization callout
 **********************************************************************************************************************/
void ApplFblBmPowerOnPost( void )
{

}

/***********************************************************************************************************************
 *  ApplFblBmInitPre
 **********************************************************************************************************************/
/*! \brief        Initialization callout
 **********************************************************************************************************************/
volatile static int debug_Var=1;
void ApplFblBmInitPre( void )
{

	while (debug_Var == 0)
	{
	}

#  if defined( BRSHW_PREINIT_AVAILABLE )
   /* HW specific pre-initialization. */
   BrsHwPreInitPowerOn();
#  endif /* BRSHW_PREINIT_AVAILABLE */

#  if defined( BRS_ENABLE_WATCHDOG )
   /* Disable Watchdog */
   BrsHwWatchdogInitPowerOn();
#  endif /* BRS_ENABLE_WATCHDOG */

#  if defined( BRS_ENABLE_PLLCLOCKS )
   /* Initialize the PLLs. */
   BrsHwPllInitPowerOn();
#  endif /* BRS_ENABLE_PLLCLOCKS */

#  if defined( BRSHW_DISABLE_ECC_AVAILABLE )
   /* Disable Flash ECC error reporting. */
   BrsHwDisableEccErrorReporting();
#  endif /* BRSHW_DISABLE_ECC_AVAILABLE */

#  if defined( FBL_ENABLE_PRE_TIMERINIT )
   /* Timer is stopped by mode switch and has to be re-initialized. */
   FblTimerInit();
#  endif /* FBL_ENABLE_PRE_TIMERINIT */

}

IO_ErrorType result;
#if 0
vuint8 readBuffer[512], readBuffer1[512];
vuint8 lateapp1_0[15];
vuint8 lateapp1_1[15];
vuint8 lateapp2_0[15];
vuint8 lateapp2_1[15];
vuint8 atf_optee_0[15];
vuint8 atf_optee_1[15];
vuint8 ifs_qnx_0[15];
vuint8 ifs_qnx_1[15];
vuint8 apps_0[15];
vuint8 apps_1[15];
vuint8 c7x_0[15];
vuint8 c7x_1[15];
vuint8 cal_0[15];
vuint8 cal_1[15];
vuint8 secCert_0[15];
vuint8 secCert_1[15];
#endif

/* Application software information */
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

/* Offsets to start address of structure */

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

#define kApplInfoSizeFileHeaderInfo	160u
#define kApplInfoSizeUuid	16u

#define kApplInfoOffsetFileHeaderInfo                                    0u
#define kApplInfoOffsetUuid                                          (kApplInfoOffsetFileHeaderInfo             + kApplInfoSizeFileHeaderInfo)

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
#define FILE_INFO_HEADER_SIZE 176u
#define APP_INFO_HEADER_OFFSET 0x1C0ul
#define CERTSTORE_INFO_HEADER_OFFSET 0x43C0ul

#define MCU1_0_APP_HEADER_START_ADDRESS 0x3001C0ul
#define LATEAPP1_APP_HEADER_START_ADDR 	0x004801C0ul
#define ATF_OPTEE_APP_HEADER_START_ADDR 0x011801C0ul
#define IFS_QNX_APP_HEADER_START_ADDR 	0x012001C0ul
#define C7x_APP_HEADER_START_ADDR 		0x03A001C0ul
#define CAL_DATA_HEADER_START_ADDR 		0x044001C0ul
#define EXTENDED_KEYRING_DATA_HEADER_START_ADDR 0x45001C0ul
#define SecCert_DATA_HEADER_START_ADDR 	0x066401C0ul

uint8 InfoHeaderBuff[INFO_HEADER_SIZE];
uint8 FileInfoHeaderBuff[FILE_INFO_HEADER_SIZE];


uint8 BootSoftwareVersionInformation_F180[13] = {0x19, 0x04, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};
uint8 BootSoftwareEBOMPartNumber_F122[10] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
uint8 reprogAttemptCounter[2];

uint8 SupplierECUSoftwarePartNumber_F194[kApplInfoSizeSupplierECUSoftwarePartNumber_F194];
uint8 SupplierECUSoftwareVersionNumber_F195[kApplInfoSizeSupplierECUSoftwareVersionNumber_F195];
uint8 ECUDiagnosticIdentification_F110[kApplInfoSizeDiagnosticVersionFlashDefinition_F110];
uint8 EBOMAssemblyPartNumber_F133[kApplInfoSizeEBOMAssemblyPartNumber_F133];
uint8 CODEPAssemblyPartNumber_F134[kApplInfoSizeCODEPAssemblyPartNumber_F134];
uint8 FCAESLMECUSoftwareCalibrationNumber_F18A[kApplInfoSizeFCAESLMECUSoftwareCalibrationNumber_F18A];
uint8 FCAESLMECUSoftwareApplicationNumber_F18B[kApplInfoSizeFCAESLMECUSoftwareApplicationNumber_F18B];

uint8 EbomEcuPartNumber_F132[kApplInfoSizeEbomEcuPartNumber_F132];
uint8 CodepEcupartNumber_F187[kApplInfoSizeCodepEcupartNumber_F187];
uint8 FCAESLMECUSoftwareNumber_F188[kApplInfoSizeFCAESLMECUSoftwareNumber_F188];

uint8 SoftwareIdentification_F181[kApplInfoSizeSoftwareIdentification_F181*10];
uint8 SoftwareEBOMPartNumber_F122[kApplInfoSizeSwEbomPartNumber_F122*10];

uint8 AppSWHeaderInfo_2957[kApplInfoSizeFileHeaderInfo*6];
uint8 AppSWHeaderUuid_2958[kApplInfoSizeUuid*6];
uint8 AppDataConfigInfo_2959[kApplInfoSizeFileHeaderInfo*2];
uint8 AppDataHeaderUuid_295A[kApplInfoSizeUuid*2];
uint8 AppDCLHeaderUuid_2951[kApplInfoSizeUuid];
uint8 AppDCLHeaderInfo_295F[kApplInfoSizeFileHeaderInfo];

void ApplFblBackUpAllPartNumbers(void)
{
	vuint8 blockCount;
	vuint8 flashStatBuffer[2u] = {0xFF, 0x00};
	vuint8 defaultFlashStatus = 0x00; // Flash status: 0x00=Pass (Considered that all app images flash correctly initially)
	const vuint8 progSuccessful = 0xA5;
	uint16 progAttempts;
	uint8 nvBuffer[sizeof(uint16)]={0x0,0x0};
	IO_PositionType *InfoHeaderAddress, *FileInfoHeaderAddress;
	V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 blockFingerprint[kEepSizeFingerprint] = {23,04,14,'P','R','O','D','U','C','T','I','O','N'};
	/*Read all part numbers from Pflash and backup to EEPROM*/
	InfoHeaderAddress = FblLogicalBlockTable.logicalBlock[FBL_LBT_MCU10_APPLICATION_LB_BLOCK_NUMBER].blockStartAddress + APP_INFO_HEADER_OFFSET;
	if (IO_E_OK == MemDriver_RReadSync(InfoHeaderBuff, INFO_HEADER_SIZE, InfoHeaderAddress))
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
		ApplFblNvWriteEbomEcuPartNumber(EbomEcuPartNumber_F132);                                    	/*0xF132*/
		ApplFblNvWriteCoDePEcuPartNumber(CodepEcupartNumber_F187);      			                	/*0xF187*/
		ApplFblNvWriteVehicleManufEcuSwNumber(FCAESLMECUSoftwareNumber_F188);                      		/*0xF188*/

		ApplFblNvWriteDID_F194_Supplier_Ecu_SW_PartNum(SupplierECUSoftwarePartNumber_F194);         	/*0xF194*/
		ApplFblNvWriteDID_F195_Supplier_Ecu_SW_VerNum(SupplierECUSoftwareVersionNumber_F195);       	/*0xF195*/
		ApplFblNvWriteDiagnosticVersion(ECUDiagnosticIdentification_F110);                          	/*F110*/
		ApplFblNvWriteEbomAssemblyPartNumber(EBOMAssemblyPartNumber_F133);                          	/*0xF133*/


		ApplFblNvWriteCodepAssemblyPartNumber(CODEPAssemblyPartNumber_F134);                         	/*0xF134*/
		ApplFblNvWriteDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num(FCAESLMECUSoftwareCalibrationNumber_F18A);    	/*0xF18A*/
		ApplFblNvWriteDID_F18B_FCA_ESLM_ECU_SW_App_Num(FCAESLMECUSoftwareApplicationNumber_F18B);    	/*0xF18B*/

		ApplFblNvWriteSoftwareIdentification(FBL_LBT_FBL_BLOCK_NUMBER,BootSoftwareVersionInformation_F180);                	/*F180*/
		ApplFblNvWriteSwEbomPartNumber(FBL_LBT_FBL_BLOCK_NUMBER,BootSoftwareEBOMPartNumber_F122);								/*F122*/

		ApplFblNvWriteProgrammingStatus(flashStatBuffer);

		/* Dumy Values passed in LB 0 (i.e: FBL), as FBL dose't have file header */
		vuint16 idx;
		for (idx = 0u; idx < kApplInfoSizeFileHeaderInfo; idx++)
			{
				AppSWHeaderInfo_2957[idx] = 0x20u;
			}
		for (idx = 0u; idx < kApplInfoSizeUuid; idx++)
			{
				AppSWHeaderUuid_2958[idx] = 0x20u;
			}

		for(blockCount = 1u;blockCount < FBL_LBT_BLOCK_COUNT;blockCount++)
		{
			InfoHeaderAddress = FblLogicalBlockTable.logicalBlock[blockCount].blockStartAddress + APP_INFO_HEADER_OFFSET;
			if(blockCount == FBL_LBT_SECURITY_CERT_LB_BLOCK_NUMBER)
			{
				InfoHeaderAddress = FblLogicalBlockTable.logicalBlock[blockCount].blockStartAddress + CERTSTORE_INFO_HEADER_OFFSET;
			}
			FileInfoHeaderAddress = FblLogicalBlockTable.logicalBlock[blockCount].blockStartAddress;
			if (IO_E_OK == MemDriver_RReadSync(InfoHeaderBuff, (kApplInfoSizeSoftwareIdentification_F181+kApplInfoSizeSwEbomPartNumber_F122), InfoHeaderAddress))
			{
				(void)MEMCPY(&SoftwareIdentification_F181[(blockCount-1)*kApplInfoSizeSoftwareIdentification_F181], &InfoHeaderBuff[F181_OFFSET], kApplInfoSizeSoftwareIdentification_F181);
				(void)MEMCPY(&SoftwareEBOMPartNumber_F122[(blockCount-1)*kApplInfoSizeSwEbomPartNumber_F122], &InfoHeaderBuff[F122_OFFSET], kApplInfoSizeSwEbomPartNumber_F122);

			}
			if(blockCount<3u)
			{
				/* File Header Info and UUID for LB 6 and 7 in buffer */
				if (IO_E_OK == MemDriver_RReadSync(FileInfoHeaderBuff, (kApplInfoSizeFileHeaderInfo+kApplInfoSizeUuid), FileInfoHeaderAddress))
				{
					(void)MEMCPY(&AppDataConfigInfo_2959[(blockCount-1)*kApplInfoSizeFileHeaderInfo], &FileInfoHeaderBuff[kApplInfoOffsetFileHeaderInfo], kApplInfoSizeFileHeaderInfo);
					(void)MEMCPY(&AppDataHeaderUuid_295A[(blockCount-1)*kApplInfoSizeUuid], &FileInfoHeaderBuff[kApplInfoOffsetUuid], kApplInfoSizeUuid);
				}
			}
			else if (blockCount == 3u)
			{
				/* File Header Info and UUID for LB 8 in buffer */
				if (IO_E_OK == MemDriver_RReadSync(FileInfoHeaderBuff, (kApplInfoSizeFileHeaderInfo+kApplInfoSizeUuid), FileInfoHeaderAddress))
				{
					(void)MEMCPY(&AppDCLHeaderInfo_295F[0u], &FileInfoHeaderBuff[kApplInfoOffsetFileHeaderInfo], kApplInfoSizeFileHeaderInfo);
					(void)MEMCPY(&AppDCLHeaderUuid_2951[0u], &FileInfoHeaderBuff[kApplInfoOffsetUuid], kApplInfoSizeUuid);
				}
			}
			else if(blockCount > 3u)
			{
			    /* File header info for LB 1 to 5 (Code block) */
				if (IO_E_OK == MemDriver_RReadSync(FileInfoHeaderBuff, (kApplInfoSizeFileHeaderInfo+kApplInfoSizeUuid), FileInfoHeaderAddress))
				{
					(void)MEMCPY(&AppSWHeaderInfo_2957[(blockCount-3)*kApplInfoSizeFileHeaderInfo], &FileInfoHeaderBuff[kApplInfoOffsetFileHeaderInfo], kApplInfoSizeFileHeaderInfo);
					(void)MEMCPY(&AppSWHeaderUuid_2958[(blockCount-3)*kApplInfoSizeUuid], &FileInfoHeaderBuff[kApplInfoOffsetUuid], kApplInfoSizeUuid);
				}
			}

		}

		/* Dumy Values passed in LB 0 (i.e: FBL), as FBL dose't have file header */
		ApplFblNvWriteFileHeaderInfo((0u),&AppSWHeaderInfo_2957[0u]);
	    ApplFblNvWriteUuid((0u),&AppSWHeaderUuid_2958[0u]);

		for(blockCount = 1u; blockCount < FBL_LBT_BLOCK_COUNT; blockCount++)
		{
			ApplFblNvWriteSoftwareIdentification(blockCount,&SoftwareIdentification_F181[(blockCount-1)*kApplInfoSizeSoftwareIdentification_F181]); /*F181*/
			ApplFblNvWriteSwEbomPartNumber(blockCount,&SoftwareEBOMPartNumber_F122[(blockCount-1)*kApplInfoSizeSwEbomPartNumber_F122]);

			/* Copy File Header Info and UUID for LB 6 and 7 in NvM */
			if(blockCount<3u)
			{
				ApplFblNvWriteFileHeaderInfo((blockCount),&AppDataConfigInfo_2959[(blockCount-1)*kApplInfoSizeFileHeaderInfo]);
				ApplFblNvWriteUuid((blockCount),&AppDataHeaderUuid_295A[(blockCount-1)*kApplInfoSizeUuid]);
			}
			/* Copy File Header Info and UUID for LB 8 in NvM */
			else if (blockCount == 3u)
			{
				ApplFblNvWriteFileHeaderInfo((blockCount),&AppDCLHeaderInfo_295F[0u]);
				ApplFblNvWriteUuid((blockCount),&AppDCLHeaderUuid_2951[0u]);
			}
			/* Copy File header info for LB 1 to 5 in NvM */
			else if(blockCount > 3u)
			{
				ApplFblNvWriteFileHeaderInfo((blockCount),&AppSWHeaderInfo_2957[(blockCount-3)*kApplInfoSizeFileHeaderInfo]);
				ApplFblNvWriteUuid((blockCount),&AppSWHeaderUuid_2958[(blockCount-3)*kApplInfoSizeUuid]);
			}

		}

		/*Set ProgReq Flag to 0xA5 so that application knows there was a
		 * successful re -programming and it can write latest Odo value and other information */
		ApplFblNvWriteProgReqFlag(&progSuccessful);
		progAttempts = FblMemGetInteger(sizeof(nvBuffer), nvBuffer);
		progAttempts = FblInvert16Bit(progAttempts);
		FblMemSetInteger(sizeof(nvBuffer), progAttempts, nvBuffer);

		for(blockCount=0;blockCount<FBL_LBT_BLOCK_COUNT;blockCount++)
		{
			ApplFblNvWriteFingerprint((IO_PositionType)blockCount, blockFingerprint);
			ApplFblNvWriteProgAttempts(blockCount, nvBuffer);
			ApplFblNvWriteFlashStatus(blockCount,&defaultFlashStatus); //keeping flash status as TRUE (Considering: Production flash successful)
		}

		/* Backup Current time and timestamp */
		   ApplFblNvWriteSecondCounter(&DefaultSecondCounter[0]);
		   ApplFblNvWriteSystemTimestamp(DefaultSystemTime);
	}
}

uint8 EOL_Pattern[4096];
void ApplFblNANDMemInit(void)
{
	vuint32 i;
	vuint32 j;
	vuint8* EOLBuffer;
	vuint8 progReqFlag = 0;

	EOLBuffer = 0x97BFFC00U;
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
	if(IO_E_OK != MemDriver_InitSync(0x300000))
	{
		while(1);
	}

	memSegment = FblMemSegmentNrGet(0x07D00000);
	if(IO_E_OK != MemDriver_InitSync(0x07D00000))
	{
		while(1);
	}

	memSegment = FblMemSegmentNrGet(0x480000);
	if(IO_E_OK != MemDriver_InitSync(0x480000))
	{
		while(1);
	}

	memSegment = FblMemSegmentNrGet(0x1180000);
	if(IO_E_OK != MemDriver_InitSync(0x1180000))
	{
		while(1);
	}
	memSegment = FblMemSegmentNrGet(0x1200000);
	if(IO_E_OK != MemDriver_InitSync(0x1200000))
	{
		while(1);
	}
	memSegment = FblMemSegmentNrGet(0x3A00000);
	if(IO_E_OK != MemDriver_InitSync(0x3A00000))
	{
		while(1);
	}
	memSegment = FblMemSegmentNrGet(0x4400000);
	if(IO_E_OK != MemDriver_InitSync(0x4400000))
	{
		while(1);
	}
	memSegment = FblMemSegmentNrGet(0x4500000);
	if(IO_E_OK != MemDriver_InitSync(0x4500000))
	{
		while(1);
	}
	memSegment = FblMemSegmentNrGet(0x6640000);
	if(IO_E_OK != MemDriver_InitSync(0x6640000))
	{
		while(1);
	}
	memSegment = FblMemSegmentNrGet(0x6C80000);
	if(IO_E_OK != MemDriver_InitSync(0x6C80000))
	{
		while(1);
	}
	memSegment = FblMemSegmentNrGet(0x6600000ul);
	if(IO_E_OK != MemDriver_InitSync(0x6600000ul))
	{
		while(1);
	}
	//if (FblReadPromPageAlign(0x280000ul, EOLBuffer, 1024u))// Test Code
	result = FblReadPromPageAlign(0x6C60000ul, EOLBuffer, 1024u);
	if (result)
	{

	}
	else
	{
		while(1);
	}

	memSegment = FblMemSegmentNrGet(0x6C60800ul);
	if(IO_E_OK != MemDriver_InitSync(0x6C60800ul))
	{
		while(1);
	}
	result = FblReadPromPageAlign(0x6C61000ul, &EOL_Pattern, 1024u);
	if (result)
	{

	}
	else
	{
		while(1);
	}

	if(EOL_Pattern[0] != 0xB5)
	{
		PMIC_Disable_Wdg();
		ApplFblBackUpAllPartNumbers();
		EOL_Pattern[0] = 0xB5;
		if(IO_E_NOT_OK == MemDriver_RWriteSync(&EOL_Pattern,4096,0x6C61000ul))
		{
			while(1);
		}
	}


	 /* Test Code for EEPROM- Jump to Boot
	  * Revert back once Retention RAM issue is fixed (Soft reset issue)*/
#if 0
	ApplFblNvReadProgReqFlag(&progReqFlag);

	/* for prog req - 0xB5u*/
	ApplFblNvWriteProgReqFlag(&progReqFlag);
#endif


#if 0
	result = IO_E_NOT_OK;
	for (i = 0; i<512; i++)
	{
		readBuffer[i] = 0;
	}
	if (FblReadPromPageAlign(0x47F000ul, readBuffer, 512u))
	{

	}
	else
	{
		while(1);
	}
	if (FblReadPromPageAlign(0x47F800ul, readBuffer1, 512u))
	{
	}
	else
	{
		while(1);
	}
/**********************************************************************************/
	if (FblReadPromPageAlign(0xC7F000ul, lateapp1_0, 15u))
	{

	}
	else
	{
		while(1);
	}
	if (FblReadPromPageAlign(0xC7F800ul, lateapp1_1, 15u))
	{
	}
	else
	{
		while(1);
	}
/**********************************************************************************/

/**********************************************************************************/
	if (FblReadPromPageAlign(0x117F000ul, lateapp2_0, 15u))
	{

	}
	else
	{
		while(1);
	}
	if (FblReadPromPageAlign(0x117F800ul, lateapp2_1, 15u))
	{
	}
	else
	{
		while(1);
	}
/**********************************************************************************/

/**********************************************************************************/
	if (FblReadPromPageAlign(0x11FF000ul, atf_optee_0, 15u))
	{

	}
	else
	{
		while(1);
	}
	if (FblReadPromPageAlign(0x11FF800ul, atf_optee_1, 15u))
	{
	}
	else
	{
		while(1);
	}
/**********************************************************************************/

/**********************************************************************************/
	if (FblReadPromPageAlign(0x1DFF000ul, ifs_qnx_0, 15u))
	{

	}
	else
	{
		while(1);
	}
	if (FblReadPromPageAlign(0x1DFF800ul, ifs_qnx_1, 15u))
	{
	}
	else
	{
		while(1);
	}
/**********************************************************************************/

/**********************************************************************************/
	if (FblReadPromPageAlign(0x36FF000ul, apps_0, 15u))
	{

	}
	else
	{
		while(1);
	}
	if (FblReadPromPageAlign(0x36FF800ul, apps_1, 15u))
	{
	}
	else
	{
		while(1);
	}
/**********************************************************************************/

/**********************************************************************************/
	if (FblReadPromPageAlign(0x4FFF000ul, c7x_0, 15u))
	{

	}
	else
	{
		while(1);
	}
	if (FblReadPromPageAlign(0x4FFF800ul, c7x_1, 15u))
	{
	}
	else
	{
		while(1);
	}
/**********************************************************************************/

/**********************************************************************************/
	if (FblReadPromPageAlign(0x50FF000ul, cal_0, 15u))
	{

	}
	else
	{
		while(1);
	}
	if (FblReadPromPageAlign(0x50FF800ul, cal_1, 15u))
	{
	}
	else
	{
		while(1);
	}
/**********************************************************************************/

/**********************************************************************************/
	if (FblReadPromPageAlign(0x775F000ul, secCert_0, 15u))
	{

	}
	else
	{
		while(1);
	}
	if (FblReadPromPageAlign(0x775F800ul, secCert_1, 15u))
	{
	}
	else
	{
		while(1);
	}
/**********************************************************************************/
#endif
}

/***********************************************************************************************************************
 *  ApplFblBmInitPost
 **********************************************************************************************************************/
/*! \brief        Initialization callout
 **********************************************************************************************************************/
//volatile static int debug_Var=1;
//vuint8 readBuffer1[4095];
void ApplFblBmInitPost( void )
{
	uint32_t *buffPtr;
	volatile uint32_t Hsm2HostValue;
	buffPtr = (uint32_t)0x9D000000;

#if defined (ENABLE_SD15_SECURE_BOOT)
	/* Wait until vHSM is ready */
	Crypto_30_vHsm_WaitForHsmRam();
#endif	

#if defined( FBLBM_ENABLE_SECURE_BOOT )
   volatile vuint8 executeTestcode = kFblOk;

   /* Wait until vHSM is ready */
   Crypto_30_vHsm_WaitForHsmRam();

   if (executeTestcode == kFblOk) /* Testcode to initialize RAM key, to simulate written key */
   {
      Std_ReturnType retVal;
      uint8 version[3u] = {0u};
      uint32 versionLength = sizeof( version );
      Crypto_VerifyResultType result = CRYPTO_E_VER_NOT_OK;
      const uint8 key[16u] = {0u};
      uint8 mac[16u] = {0u};
      const uint8 data[16u] = {0u};
      uint32 length = sizeof( mac );

      /* Get the Version of the vHsm Firmware */
      retVal = Crypto_30_vHsm_KeyElementGet( CryptoConf_CryptoKey_vHsm_Info, CRYPTO_KE_CUSTOM_VHSM_VERSION, version, &versionLength );

      /* Fill the key used for the CMAC and set it to valid */
      retVal |= Csm_KeyElementSet( CsmConf_CsmKey_CsmKey_SymmetricKey, CRYPTO_KE_MAC_KEY, key, sizeof( key ) );
      retVal |= Csm_KeySetValid( CsmConf_CsmKey_CsmKey_SymmetricKey );

      /* Generate the CMAC with the software implementation on the vHsm */
      retVal |= Csm_MacGenerate( CsmConf_CsmJob_CsmJob_MacGen_Key1, CRYPTO_OPERATIONMODE_SINGLECALL, data, sizeof( data ), mac, &length );
      retVal |= Csm_MacVerify( CsmConf_CsmJob_CsmJob_MacVer_Key1, CRYPTO_OPERATIONMODE_SINGLECALL, data, sizeof( data ), mac, sizeof( mac ) * 8u, &result );

      if (retVal != E_OK)
      {
         while (1u)
         {
            ;
         }
      }
   }
#endif /* FBLBM_ENABLE_SECURE_BOOT */
#if defined( FBL_ENABLE_HARDWARE_SWAP )
   /* Execute the flash partition swap */
   (void)FblSwapActivate();
#endif /* FBL_ENABLE_HARDWARE_SWAP */

   while (debug_Var == 0)
   {
   }

/*	fblBmMagicFlag[0] = 0x50;
	fblBmMagicFlag[1] = 0x72;
	fblBmMagicFlag[2] = 0x6F;
	fblBmMagicFlag[3] = 0x67;
	fblBmMagicFlag[4] = 0x53;
	fblBmMagicFlag[5] = 0x69;
	fblBmMagicFlag[6] = 0x67;
	fblBmMagicFlag[7] = 0x6E;*/

   ApplFblNANDMemInit();
   (void)MEMCPY(MCU1_0_AuthStatus, D_MCU_1_0_AUTH_FLAG_STATUS, 2u);
   /* Check if there are any garbage values */
   if((MCU1_0_AuthStatus[0]!= APPLN_AUTH_OR_PARSE_FAIL_PATTERN)||(MCU1_0_AuthStatus[1u] > APPLN_AUTH_OR_PARSE_FAIL_CNT))
   {
	   /* Initialize MCU_1_0_AUTH_FLAG_STATUS values */
	   memset(D_MCU_1_0_AUTH_FLAG_STATUS,MCU_1_0_AUTH_FLAG_STATUS_INIT_VALUE,2);
	   memset(MCU1_0_AuthStatus,MCU_1_0_AUTH_FLAG_STATUS_INIT_VALUE,2);
   }

   //FblReadProm(0x300704, readBuffer1, 0x400);

   //FblReadPromPageAlign(0x300FC4, readBuffer1, 0xA3C);

/*   if (IO_E_OK ==  Bm_QSPIBootImage(&k3xx_evmEntry, QSPI_OFFSET_MCU_1_0_APP_IMAGE))
   {

	   BM_SlaveCoreBoot(MCU1_CPU0_ID, 0, &k3xx_evmEntry, SBL_REQUEST_CORE);
	    control never reach beyond above line , it will transfer the control to 0x00 where MCU1_0 app reset handler is stored
  }*/

   /* Read NvM blocks after init */
   ApplFblNvReadSecondCounter(&SecondCounter);
   ApplFblNvReadSystemTimestamp(&SystemTime[0]);

   ptr = HOST_TO_HSM_CURRENT_TIMESTAMP_ADDR;
   for(int i = 0;i<15;i++)
   {
	   ptr[i]=SystemTime[i];
   }

   ptr = HOST_TO_HSM_SEC_COUNTER_ADDR;
   SecCnt = &SecondCounter;
   for(int i = 0 ; i<4 ;i++)
   {
	   ptr[i] = SecCnt[i];
   }
   ptr = HOST_TO_HSM_CURRENT_TIMESTAMP_AVAILAIBILITY_ADDR;
   memset(ptr,0xA5,4);

   /* Call vMemAccM_MainFunction() cyclically until NvM_ReadAll is complete on HSM side. This is required for
    * NvM read using Satellite communication */

   do
   {
       vMemAccM_MainFunction();
       Hsm2HostValue = HSM_2_HOST_IPC_VALUE;
   }while ((Hsm2HostValue & HSM_NVM_READALL_DONE) == 0);

}



#if defined( FBLBM_AP_CALLOUT_RESET )
/***********************************************************************************************************************
 *  ApplFblBmReset
 **********************************************************************************************************************/
/*! \brief        Issue Reset
 **********************************************************************************************************************/
void ApplFblBmReset(void)
{
	JSR(0x9700af70);
   /* Reset ECU */
   BrsHwSoftwareResetECU();
}
#endif /* FBLBM_AP_CALLOUT_RESET */

/***********************************************************************************************************************
 *  ApplFblCopyApplFromRomToRam
 **********************************************************************************************************************/
/*! \brief       Copy a module from external flash to RAM
 *  \pre         Module is programmed to external flash
 *  \return      kFblOk copy successful, otherwise kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblCopyModuleFromRomToRam( vuint32 romAddr, vuint32 ramAddr, vuint32 size )
{
   volatile tFblResult returnCode;
   vuint32 localReadLength;
   vuint32 currentLength;
   vuint32 localReadAddress;
   vuint32 localReadBuffer;

   returnCode = kFblOk;

   localReadLength = size;
   localReadAddress = romAddr;
   localReadBuffer = ramAddr;

/*   while (   (localReadLength > 0u)
          && (returnCode == kFblOk))
   {*/
      /* Limit current read length to FLS Copy Buffer Size */
/*      if (localReadLength > FLS_INT_READ_SIZE)
      {
         currentLength = FLS_INT_READ_SIZE;
      }
      else
      {
         currentLength = localReadLength;
      }*/

      returnCode = ((tFblResult)MemDriver_RReadSync((IO_MemPtrType)localReadBuffer, (IO_SizeType)localReadLength, (IO_PositionType)localReadAddress));

      /* Prepare parameters for next cycle */
/*      localReadLength  -= currentLength;
      localReadAddress += currentLength;
      localReadBuffer  += currentLength;*/
/*   }*/

   return returnCode;
}

#if defined( FBLBM_AP_CALLOUT_CHECK_TARGET_VALIDITY )
/***********************************************************************************************************************
 *  ApplFblBmCheckTargetValidity
 **********************************************************************************************************************/
/*! \brief        Checks the validity of the target (Usually: Is the Application Validity Presence Pattern set)
 *  \param[in]    targetHandle Target handle (e.g. Bootloader, Application, Updater)
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
tFblResult ApplFblBmCheckTargetValidity(tFblBmHdrTargetHandle targetHandle)
{
   tFblResult result;
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
   vuint8 flashStatBuffer[2u];
   vuint8 blockNo;
   tBlockDescriptor blockDescriptor;
   vuint8 device;
   ApplFblNvReadProgrammingStatus(flashStatBuffer);

# else
   vuint8 applValidity;
# endif

	/*while (debug_Var == 1)
	{
	}*/

   /* Check overall application validity for Application target */
   if (targetHandle == FBLBMHDR_TARGET_APPL)
   {
      result = kFblFailed;

# if defined( FBL_ENABLE_PRESENCE_PATTERN )
      /* Check if any PP for appl validity is set */
      blockNo = 0u;

      while ((blockNo < FblLbtGetBlockCount()) && (result != kFblOk))
      {
         if (kFblOk == FblLbtGetBlockDescriptorByNr(blockNo, &blockDescriptor))
         {
            if (kFblOk == FblMemGetDeviceByRange(blockDescriptor.blockStartAddress, blockDescriptor.blockLength, &device))
            {
/*#  if defined( kMioDeviceRam )*/
               /* Do not check the presence pattern for RAM */
               if (/*(device != kMioDeviceRam) && */(blockDescriptor.mandatoryType != FALSE))
/*#  endif*/
               {
                  result = FblNvPatternGet(&blockDescriptor, kFblNvPatternId_ApplValidity);
               }
            }
         }

         /* Prepare index for next loop */
         blockNo++;
      }
# else
      /* Read validity from NV-memory */
      if (ApplFblNvReadApplValidity(&applValidity) == kFblOk)
      {
         if (applValidity == kFblApplicationValid)
         {
            result = kFblOk;
         }
      }
# endif
   }
   else
   {
      /* For all other targets, no overall validity is necessary */
      result = kFblOk;
   }


/******************************************************************/
#if 0
   else if(targetHandle == FBLBMHDR_TARGET_FBLUPDATER)
   {
	   result = kFblFailed;
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
      /* Check if any PP for appl validity is set */
      blockNo = 0u;

      while ((blockNo < FblLbtGetBlockCount()) && (result != kFblOk))
      {
         if (kFblOk == FblLbtGetBlockDescriptorByNr(blockNo, &blockDescriptor))
         {
            if (kFblOk == FblMemGetDeviceByRange(blockDescriptor.blockStartAddress, blockDescriptor.blockLength, &device))
            {
/*#  if defined( kMioDeviceRam )*/
               /* Do not check the presence pattern for RAM */
               if ( /*(device != kMioDeviceRam) &&*/ (blockDescriptor.mandatoryType != FALSE) )
/*#  endif*/
               {
                  result = FblNvPatternGet(&blockDescriptor, kFblNvPatternId_ApplValidity);
               }
            }
         }

         /* Prepare index for next loop */
         blockNo++;
      }
# else
      /* Read validity from NV-memory */
      if (ApplFblNvReadApplValidity(&applValidity) == kFblOk)
      {
         if (applValidity == kFblApplicationValid)
         {
            result = kFblOk;
         }
      }
# endif
   }
#endif
/******************************************************************/
   /* Check if any block flash correctly or not OR Abnormal reset */
   if(0xF9 == flashStatBuffer[0u])
   {
        result = kFblFailed;   
   }

   else
   {
	   /* Do Nothing */
   }
   return result;
}
#endif /* FBLBM_AP_CALLOUT_CHECK_TARGET_VALIDITY */


#if defined( FBLBM_AP_CALLOUT_IS_VALIDBLOCK )
/***********************************************************************************************************************
 *  ApplFblBmIsValidBlock
 **********************************************************************************************************************/
/*! \brief        Checks the preconditions of a specific target
 *  \param[in]    targetHandle Target handle (e.g. Bootloader, Application)
 *  \param[in]    pLogicalBlock Pointer to current logical block
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblBmIsValidBlock(tFblBmHdrTargetHandle targetHandle,
   const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * pLogicalBlock)
{
   tFblResult result;
   tFblHeader fblBmFblHeader;
# if defined( FBL_ENABLE_PRESENCE_PATTERN ) || defined( FBLBM_ENABLE_STANDALONE_MODE )
   vuint8 device;
# endif /* FBL_ENABLE_PRESENCE_PATTERN || FBLBM_ENABLE_STANDALONE_MODE */
# if !defined( FBL_ENABLE_PRESENCE_PATTERN )
   vuint8 validityFlags[kEepSizeValidityFlags];
   vuint8 validityMask;
   vuint8 byteIdx;
# endif /* !FBL_ENABLE_PRESENCE_PATTERN */

# if (!defined( FBLBM_ENABLE_STANDALONE_MODE ) || defined( FBL_ENABLE_PRESENCE_PATTERN ))
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)targetHandle;
#  endif /* V_ENABLE_USE_DUMMY_STATEMENT */
# endif /* ( !FBLBM_ENABLE_STANDALONE_MODE || FBL_ENABLE_PRESENCE_PATTERN ) */

   result = kFblFailed;

# if defined( FBLBM_ENABLE_STANDALONE_MODE ) && !defined( FBL_ENABLE_PRESENCE_PATTERN)
#   error "If presence pattern is disabled special handling must be configured for the FBL because          \
           validity flags are not available for the FBL."
   /* Perform presence pattern check only for FBL, use NV validity flags for other blocks */
   if (targetHandle == FBLBMHDR_TARGET_FBL)
# endif /* FBLBM_ENABLE_STANDALONE_MODE && !FBL_ENABLE_PRESENCE_PATTERN */
# if defined( FBL_ENABLE_PRESENCE_PATTERN ) || defined( FBLBM_ENABLE_STANDALONE_MODE )
   {
	   //TODO: Code is needed but we need to write logic for page boundary check and handling
	   FblReadPromPageAlign(FblBmHeader.fblHeaderAddress, (vuint8*) &fblBmFblHeader, sizeof(tFblHeader));
	   FblReadPromPageAlign(((vuint32)fblBmFblHeader.pLogicalBlockTable-BM_FBL_RAM_LOC+BM_FBL_ROM_LOC), (vuint8*) fblBmFblHeader.pLogicalBlockTable, 0x300u);
	   FblReadPromPageAlign(fblBmFblHeader.bmHeader, (vuint8*) &fblbmheader_fallback, sizeof(fblbmheader_fallback));

 	   /* Check the presence pattern value */
	   if (kFblOk == FblMemGetDeviceByRange(pLogicalBlock->blockStartAddress, pLogicalBlock->blockLength, &device))
	   {
/*#  if defined( kMioDeviceRam )*/
		   /* Do not check the presence pattern for RAM */
		   if (/* (device != kMioDeviceRam) &&*/ (pLogicalBlock->mandatoryType != FALSE) )
/*#  endif*/ /* kMioDeviceRam */
		   {
			   result = FblNvPatternGetByBlockDescriptor(pLogicalBlock, kFblNvPatternId_BlockValidity );
		   }
	   }
   }
# endif /* FBL_ENABLE_PRESENCE_PATTERN || FBLBM_ENABLE_STANDALONE_MODE */
# if !defined( FBL_ENABLE_PRESENCE_PATTERN )
#  if defined( FBLBM_ENABLE_STANDALONE_MODE )
   /* Check NV validity flags if block other than FBL is checked */
   else
#  endif /* FBLBM_ENABLE_STANDALONE_MODE */
   {
      /* Calculate index and mask for validity bit of logical block */
      byteIdx = (pLogicalBlock->blockNr >> 0x03u);
      validityMask = (vuint8)(0x01u << (pLogicalBlock->blockNr & 0x07u));

      /* Read validity information from non-volatile memory */
      if (ApplFblNvReadValidityFlags(validityFlags) == kFblOk)
      {
         if ((validityFlags[byteIdx] & validityMask) == 0u)
         {
            /* Block is valid */
            result = kFblOk;
         }
      }
   }
# endif /* !FBL_ENABLE_PRESENCE_PATTERN */

   return result;

   //return kFblOk;
}
#endif /* FBLBM_AP_CALLOUT_IS_VALIDBLOCK */

#if defined( FBLBM_CALLOUT_IS_OPTIONALBLOCK )
/***********************************************************************************************************************
 *  ApplFblBmIsOptionalBlock
 **********************************************************************************************************************/
/*! \brief        Callout when logical block is optional and not present
 *  \param[in]    targetHandle Target handle (e.g. Bootloader, Application)
 *  \param[in]    pLogicalBlock Pointer to current logical block
 **********************************************************************************************************************/
void ApplFblBmIsOptionalBlock(tFblBmHdrTargetHandle targetHandle,
   const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * pLogicalBlock)
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)targetHandle;
   (void)pLogicalBlock;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */
}
#endif /* FBLBM_CALLOUT_IS_OPTIONALBLOCK */

#if defined( FBLBM_AP_CALLOUT_START_SOFTWARE )
/***********************************************************************************************************************
 *  ApplFblBmStartSoftware
 **********************************************************************************************************************/
/*! \brief       This function is called to start a software (e.g. Bootloader)
 *  \details     Please note: The function will never return because control is handed over to the running software.
 *  \param[in]   bmHeader Pointer to the targets BM Header structure, which shall be started
 **********************************************************************************************************************/
void ApplFblBmStartSoftware(const V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 V_MEMRAM3 * bmHeader)
{
   uint32 startAddress;

	/*while (debug_Var == 1)
	{
	}*/

	/* 
		The logic for calculating the addresses for copy is currently hard coded. 
		Most significant difference is that bmEntryAddress is assumed to be in ROM
		we have to change the startaddress to calculate the RAM address
	*/
	if (bmHeader->bmTargetHandle == FBLBMHDR_TARGET_APPL)
	{
#if 0
		/* Copy Application/Updater from ROM to RAM */
		ApplFblCopyModuleFromRomToRam(BM_APPL_ROM_LOC, BM_APPL_RAM_LOC, BM_APPL_LENGTH);
		/* FblStart function from BM must be in RAM so that that the application can jump to it */
		startAddress = (bmHeader->bmEntryAddress);
		/* TODO - Replace the following with a custom jump address */
		JSR(startAddress);
#endif

#if defined (ENABLE_SD15_SECURE_BOOT)
		if (BM_secureboot(MCU10_FCA_HDR_START_ADDRESS) == kDiagCheckVerificationOk)
#endif
		{

			if (IO_E_OK ==  Bm_QSPIBootImage(&k3xx_evmEntry, QSPI_OFFSET_MCU_1_0_APP_IMAGE))
			{
				BM_SlaveCoreBoot(MCU1_CPU0_ID, 0, &k3xx_evmEntry, SBL_REQUEST_CORE);
				/* control never reach beyond above line , it will transfer the control to 0x00 where MCU1_0 app reset handler is stored */
			}

		}
		/* if appimage parsing or secure boot of MCU1_0 fails, jump to bootloader as fall-back solution */
		if ((MCU1_0_AuthStatus[0u] == APPLN_AUTH_OR_PARSE_FAIL_PATTERN)&&(MCU1_0_AuthStatus[1u] == APPLN_AUTH_OR_PARSE_FAIL_CNT))
		{
			ApplFblCopyModuleFromRomToRam(BM_FBL_ROM_LOC, BM_FBL_RAM_LOC, BM_FBL_LENGTH);
			startAddress = (fblbmheader_fallback.bmEntryAddress);
			JSR(startAddress);
		}
		else
		{
			MCU1_0_AuthStatus[0u] = 0xA5;
			MCU1_0_AuthStatus[1u] = MCU1_0_AuthStatus[1] + 1u;
			MEMCPY(D_MCU_1_0_AUTH_FLAG_STATUS,MCU1_0_AuthStatus, 2u);
			FblEcuReset();
		}
		/* Stuck in BM if its not possible to jump in FBL (Safestate) or Application after safe state count is reached */
		while(1);

	}/* end of if (bmHeader->bmTargetHandle == FBLBMHDR_TARGET_APPL) */
	else if (bmHeader->bmTargetHandle == FBLBMHDR_TARGET_FBL)
	{

#if defined (ENABLE_SD15_SECURE_BOOT)
         if (BM_secureboot(FBL_FCA_HDR_START_ADDRESS) == kDiagCheckVerificationOk)
#endif
         {
      		/* Copy bootloader from ROM to RAM */
            ApplFblCopyModuleFromRomToRam(BM_FBL_ROM_LOC, BM_FBL_RAM_LOC, BM_FBL_LENGTH);
       		/* TODO - Replace the following with a custom jump address */
            startAddress = (bmHeader->bmEntryAddress);
            JSR(startAddress);
          }

	} /* end of (bmHeader->bmTargetHandle == FBLBMHDR_TARGET_FBL) */

	else if (bmHeader->bmTargetHandle == FBLBMHDR_TARGET_FBLUPDATER)
	{
//		/* Copy Application/Updater from ROM to RAM */
//		ApplFblCopyModuleFromRomToRam(BM_FBLUPD_ROM_LOC, BM_FBLUPD_RAM_LOC, BM_FBLUPD_LENGTH);
//        /* FblStart function from BM must be in RAM so that that the application can jump to it */
//		/* TODO - Replace the following with a custom jump address */
//		JSR(bmHeader->bmEntryAddress);
		// while(debugVar);
#if defined (ENABLE_SD15_SECURE_BOOT)
        if (BM_secureboot(MCU10_FCA_HDR_START_ADDRESS) == kDiagCheckVerificationOk)
#endif
        {
		   if (IO_E_OK ==  Bm_QSPIBootImage(&k3xx_evmEntry, QSPI_OFFSET_MCU_1_0_APP_IMAGE))
		   {
			   /* Disable watchdog before jumping to Updater */
			   PMIC_Disable_Wdg();
			  JSR(bmHeader->bmEntryAddress);
            //  BM_SlaveCoreBoot(MCU1_CPU0_ID, 0, &k3xx_evmEntry, SBL_REQUEST_CORE);
			  /* control never reach beyond above line , it will transfer the control to 0x00 where MCU1_0 app reset handler is stored */
		   }
        }
	}
	
   /* JSR(bmHeader->bmEntryAddress);  */ /* PRQA S 0305 */ /* MD_FblBmAp_0305 */

#if 0
# if defined( BRS_INSTRUCTION_SET_THUMB )
   JSR(bmHeader->bmEntryAddress | 1u);  /* PRQA S 0305 */ /* MD_FblBmAp_0305 */
# else
   JSR(bmHeader->bmEntryAddress);  /* PRQA S 0305 */ /* MD_FblBmAp_0305 */
# endif
# endif

# if defined( FBL_ENABLE_SYSTEM_CHECK )
# endif /* FBL_ENABLE_SYSTEM_CHECK */
}
#endif /* FBLBM_AP_CALLOUT_START_SOFTWARE* */

#if defined( FBLBM_ENABLE_SECURE_BOOT )
# if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY )
#  if defined( FBLBM_AP_CALLOUT_GET_KEYEMPTY )
/***********************************************************************************************************************
 *  ApplFblBmGetKeyEmpty
 **********************************************************************************************************************/
/*! \brief        Checks if now keys has been programmed so far
 *  \return       FBLBM_KEY_IS_AVAILABLE      if the keys are already programmed
                  FBLBM_KEY_IS_NOT_AVAILABLE  else
 **********************************************************************************************************************/
tFblBmKeyEmptyResult ApplFblBmGetKeyEmpty( void )
{
   /* TODO customer: implement check if key is available here. This can be done by querying the HSM/SHE (depending
    * on the used hardware) or e.g. by checking a pattern in the flash which indicates that the FBL has written the key
    * into the Crypto.
    */
   tFblBmKeyEmptyResult result;

#    error "No default implementation for this variant available."
   /* Per default assume that the key is available */
   result = FBLBM_KEY_IS_AVAILABLE;

   return result;
}
#  endif /* FBLBM_AP_CALLOUT_GET_KEYEMPTY */
# endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY */

# if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
#  if defined( FBLBM_AP_CALLOUT_GET_FBL_CMACERASED )
/***********************************************************************************************************************
 *  ApplFblBmGetFblCmacErased
 **********************************************************************************************************************/
/*! \brief        Checks if MACs for the FBL has been programmed so far
 *  \return       FBLBM_MAC_IS_AVAILABLE     If the MACs of the FBL are already written
 *                FBLBM_MAC_IS_NOT_AVAILABLE Else. E.g. because the FBL is just flashed by a debugger
 **********************************************************************************************************************/
tFblBmMacEmptyResult ApplFblBmGetFblCmacErased( const tFblBmBlockInfo * fblBlockInfo )
{
   /* TODO customer: implement check if CMAC is available here. This can be done by checking the CMAC content or e.g.
    * by checking a pattern in the flash which indicates that the FBL CMAC was already written
    */

   tFblBmMacEmptyResult result;


#    if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)fblBlockInfo;
#    endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   if (ApplFblSbIsInitialStartup() == kFblOk)
   {
      /* This is the first startup, the SecureBootSegments needs to be updated */
      result = FBLBM_MAC_IS_NOT_AVAILABLE;
   }
   else
   {
      result = FBLBM_MAC_IS_AVAILABLE;
   }

   return result;
}
#  endif /* FBLBM_AP_CALLOUT_GET_FBL_CMACERASED */
# endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */
#endif /* FBLBM_ENABLE_SECURE_BOOT */

#if defined( FBLBM_AP_CALLOUT_CHECKREPROGFLAG )
/***********************************************************************************************************************
 *  ApplFblBmCheckReprogFlag
 **********************************************************************************************************************/
/*! \brief        Checks if a reprogramming request flag is set.
 *  \return       Result of operation
 *                   kFblOk when reprogramming request flag is set
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblBmCheckReprogFlag( void )
{
   tFblResult result = kFblFailed;
# if !defined( FBL_ENABLE_FBL_START )
   vuint8 progReqFlag = 0u;
# endif

# if defined( FBL_ENABLE_FBL_START )
   if (FblBmChkFblStartMagicFlag())
   {
      /* FblStart magic flag is set, do not clear flag as the Bootloader requires it as well */
      result = kFblOk;
   }
# else
   /* Check the reprogramming request flag */
   if (ApplFblNvReadProgReqFlag(&progReqFlag) == kFblOk)
   {
      if (progReqFlag == kEepFblReprogram)
      {
         /* UDS-Reprogramming flag is set, do not clear flag as the Bootloader requires it as well */
         result = kFblOk;
      }
#  if defined( FBL_ENABLE_XCP )
      else if (progReqFlag == kEepFblXcpProgram)
      {
         /* XCP-Reprogramming flag is set, do not clear flag as the Bootloader requires it as well */
         result = kFblOk;
      }
#  endif
#  if defined( FBL_ENABLE_OTA )
      else if (progReqFlag == kEepFblOtaReprogram)
      {
         /* OTA-Reprogramming flag is set, do not clear flag as the Bootloader requires it as well */
         result = kFblOk;
      }
#  endif
      else
      {
         /* Nothing to do */
      }
   }
# endif /* FBL_ENABLE_FBL_START */

# if defined( FBLBM_MAIN_ENABLE_MAGICFLAG ) &&  \
     defined( FBLBM_ENABLE_SECURE_BOOT ) &&     \
     defined( FBLBM_MAIN_ENABLE_HARDWARE_SWAP )
   if (FblBmChkSBUpdateMagicFlag())
   {
      /* Start FBL in case of secure boot update */
      result = kFblOk;
   }
# endif

   return result;
}
#endif /* FBLBM_AP_CALLOUT_CHECKREPROGFLAG */

#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
# if defined( FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_INIT )
/***********************************************************************************************************************
 *  ApplFblBmSearchUpdaterHeaderInit
 **********************************************************************************************************************/
/*! \brief        Prepare search for updater BmHeader location
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblBmSearchUpdaterHeaderInit(void)
{
   g_ApplFblBmSearchUpdaterHeaderIndex = 0u;
   return kFblOk;
}
# endif /* FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_INIT */

# if defined( FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_HEADER_ADDRESS )
/***********************************************************************************************************************
 *  ApplFblBmSearchUpdaterHeaderAddress
 **********************************************************************************************************************/
/*! \brief        Get address of possible location of a BmHeader for the Failsafe Updater
 *  \param[out]   headerAddress  Address where the BmHeader could possible be located
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblBmSearchUpdaterHeaderAddress(vuint32 * headerAddress)
{
   vuint32 offset = 0u;
   (* headerAddress) = FlashBlock[g_ApplFblBmSearchUpdaterHeaderIndex].begin + offset;
   return kFblOk;
}
# endif /* FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_HEADER_ADDRESS */

# if defined( FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_NEXT )
/***********************************************************************************************************************
 *  ApplFblBmSearchUpdaterHeaderNext
 **********************************************************************************************************************/
/*! \brief        Get (next) possible location of a BmHeader for the Failsafe Updater
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblBmSearchUpdaterHeaderNext(void)
{
   tFblResult result;

   g_ApplFblBmSearchUpdaterHeaderIndex++;

   if (g_ApplFblBmSearchUpdaterHeaderIndex < kNrOfFlashBlock)
   {
      result = kFblOk;
   }
   else
   {
      result = kFblFailed;
   }

   return result;
}
# endif /* FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_NEXT */
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */

#if defined( FBLBM_AP_CALLOUT_FATAL_ERROR )
/***********************************************************************************************************************
 *  ApplFblBmFatalError
 **********************************************************************************************************************/
/*! \brief       This function is called in case no valid starting software was found
 *  \details     Provide here some final tasks which shall be executed
 **********************************************************************************************************************/
void ApplFblBmFatalError(tFblBmError error)
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)error;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

# if defined( FBL_ENABLE_SYSTEM_CHECK )
   /* Code should never be reached */
   while (1u)
   {
      ;
   }
# endif /* FBL_ENABLE_SYSTEM_CHECK */
}
#endif /* FBLBM_AP_CALLOUT_FATAL_ERROR */

/*-- Other callout functions -----------------------------------------------------------------------------------------*/

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
# if defined( FBL_ENABLE_ASSERTION )
/***********************************************************************************************************************
 *  ApplFblFatalError
 **********************************************************************************************************************/
/*! \brief       Will be called in case of an urecoverable error
 **********************************************************************************************************************/
void ApplFblFatalError( FBL_DECL_ASSERT_EXTENDED_INFO(vuint8 errorCode) )
{
   /* Change this variable in debugger in order to return to caller */
   volatile vuint8 stayInWhile = 1u;

#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)errorCode;
#  endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   while (0u != stayInWhile)
   {
      FblLookForWatchdogVoid();
   }
}
# endif /* FBL_ENABLE_ASSERTION */

# if (DET_ENABLED == STD_ON)
/***********************************************************************************************************************
 *  ApplFbl_DetEntryHandler
 **********************************************************************************************************************/
/*! \brief       Called by DET module to check if a DET error is intended bootloader behavior or not.
 *  \param[in]   ModuleId Code number of the encountered assertion
 *  \param[in]   InstanceId Name of the affected module (Only if extended info is enabled)
 *  \param[in]   ApiId Line number where the assertion occurred (Only if extended info is enabled)
 *  \param[in]   ErrorId Line number where the assertion occurred (Only if extended info is enabled)
 *  \return      Report if error should be handed over to DET or not
 **********************************************************************************************************************/
#  if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
FUNC(Std_ReturnType, DET_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
#  else
FUNC(boolean, DET_APPL_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
#  endif /* DET_AR_RELEASE_ */
{
#  if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
   Std_ReturnType result = E_OK;
   /* Use result value of E_NOT_OK to ignore the DET */
#  else
   boolean result = FALSE;
   /* Use result value of TRUE to ignore the DET */
#  endif /* DET_AR_RELEASE_ */

#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)ModuleId;
   (void)InstanceId;
   (void)ApiId;
   (void)ErrorId;
#  endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   return result;
}
# endif /* DET_ENABLED == STD_ON */
#endif /* FBLBM_ENABLE_STANDALONE_MODE */



/***********************************************************************************************************************
 *  Bm__OSPIBootImage
 **********************************************************************************************************************/
/*! \brief       Called by ApplFblBmStartSoftware to parse the appimage file from NOR flash.
 *  \param[in]   pEntry
 *  \param[in]   imageOffset -  Image offset  NOR flash
 *  \return      KFblOk - If appImage is successfully parsed and loaded into destination memory
 *               KFblFailed - If appImage is NOT parsed successfully
 **********************************************************************************************************************/
static tFblResult Bm_QSPIBootImage(sblEntryPoint_t *pEntry, uint32_t imageOffset)
{
    int32_t retVal = kFblFailed;

#    ifdef SECURE_BOOT
    uint32_t authenticated = 0;
    uint32_t srcAddr = 0;
    uint32_t imgOffset = 0;
#    else
    uint32_t offset = 0;
#    endif

    /* Initialization of the function pointers. */
    fp_readData = &BM_QSPI_ReadSectors;
    fp_seek     = &BM_QSPI_seek;

#    ifndef SECURE_BOOT
    /* Load the MAIN domain remotecore images included in the appimage */
    offset = imageOffset;
    retVal = BM_MulticoreImageParse((void *) &offset,

                                      imageOffset,
                                      pEntry,
                                      SBL_SKIP_BOOT_AFTER_COPY);
#    else
    retVal = SBL_loadQSPIBootData();

    if (retVal == kFblOk)
    {
        /* authentiate it */
        authenticated = SBL_authentication(sblInBootData.sbl_boot_buff);
        if (authenticated == 0)
        {
            /* fails authentiation */
           /* SBL_log(SBL_LOG_ERR, "\n OSPI Boot - fail authentication\n");*/

            retVal = kFblFailed;
        }
        else
        {
            /* need to skip the TOC headers */
            imgOffset = ((uint32_t*)sblInBootData.sbl_boot_buff)[0];
            srcAddr = (uint32_t)(sblInBootData.sbl_boot_buff) + imgOffset;
            retVal = SBL_MulticoreImageParse((void *)srcAddr, 0, pEntry,
                                             SBL_SKIP_BOOT_AFTER_COPY);
        }
    }
    else
    {
        retVal = kFblFailed;
       /* SBL_log(SBL_LOG_ERR, "\n OSPI Boot - problem processing image \n");*/
    }
#    endif

        return retVal;

}

/***********************************************************************************************************************
 *  BM_OSPI_ReadSectors
 **********************************************************************************************************************/
/*! \brief      To read the NOR flash over OSPI.
 *  \param[in]   dstAddr - pointer that holds  the data read from NOR flash
 *  \param[in]   srcOffsetAddr -  pointer that holds the address to read
 *  \return      KFblOk - If read operation is OK
 *               KFblFailed - If read operation is NOT OK
 **********************************************************************************************************************/

int32_t BM_QSPI_ReadSectors(void *dstAddr,
                             void *srcOffsetAddr,
                             uint32_t length)
{
	int32_t ret;
	ret = FblReadPromPageAlign( *((IO_PositionType *)srcOffsetAddr), (IO_MemPtrType *)dstAddr, length );
	*((uint32_t *) srcOffsetAddr) += length;

	return ret;
}

#define PAGE_ALIGN 0xFFFFF000
#define PAGE_SIZE 0x1000
#define PAGE_LENGTH 0xFFF

tFblLength FblReadPromPageAlign( tFblAddress address, V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * buffer, tFblLength length )
 {
	uint32 retVal_u32 = 0u;
	uint32 startAddressOfPage_u32;
	uint32 endAddressofPage_u32;
	uint32 remainingLenght;
	uint32 readLength;
	uint32 localReadLength;
	uint32 readAddress;
	uint32 count = 0u;

	readAddress = address;
	readLength  = length;

	 startAddressOfPage_u32 = readAddress & PAGE_ALIGN;

	 /*Check if read data is in one page*/
	 if (((readAddress - startAddressOfPage_u32)+length) <= PAGE_SIZE)
	 {
		 /*No Alignment to be done as read is in a single page*/
		 retVal_u32 = FblReadProm( readAddress, buffer, length );
	 }
	 else
	 {
		 /*Alignment is needed as read is out of the page bounds*/
		 endAddressofPage_u32 = (startAddressOfPage_u32 + PAGE_SIZE);

		 /*Calculate read length for this Page*/
		 localReadLength = (endAddressofPage_u32 - readAddress);

		 while(0u < readLength)
		 {
			 /*read data of this page*/
			 retVal_u32 += FblReadProm(readAddress, &buffer[count], localReadLength);

			 /*Increment the counter by the amount of data read from each page*/
			 count += localReadLength;

			 /*reduce the read length by the actual amount of data read */
			 readLength = length - count;

			 /*set read address for next cycle*/
			 readAddress += localReadLength;

			 /*Calculate read length for this Page*/
			 localReadLength = ((readLength < PAGE_SIZE)? readLength : PAGE_SIZE);
		 }


	 }

	 return retVal_u32;
 }


/***********************************************************************************************************************
 *  BM_OSPI_seek
 **********************************************************************************************************************/
/*! \brief       BM_OSPI_seek
 *  \param[in]   srcAddr -
 *  \param[in]   location -
 *  \return
 **********************************************************************************************************************/
void BM_QSPI_seek(void *srcAddr, uint32_t location)
{
    *((uint32_t *) srcAddr) = location;
}

/***********************************************************************************************************************
 *  BM_OSPI_seek
 **********************************************************************************************************************/
/*! \brief       BM_secureboot
 *  \param[in]   target_Address -
 *  \return
 **********************************************************************************************************************/
#if defined (ENABLE_SD15_SECURE_BOOT)
vuint8 BM_secureboot(tFblAddress target_Address)

{
	vuint8 MCU1_0_AuthFailStatus = FALSE;
	vuint8 LogAuthFailureAttempt = FALSE ;
    vuint8 result = kDiagCheckVerificationGeneralFailure;
	vuint8 localRetVal = E_NOT_OK;
	vuint8 Chkresult = kFblFailed;
	Crypto_VerifyResultType verifyResult;
    vuint32 dataLength = 1;
    const uint8 * dataPtr = NULL;

	uint32 VerifyMacLen = D_CMAC_LEN;
	SecureLogRecord_t *group;
	uint32 TimeStamp = getTimeStamp();

        /* Read SD15 Header to RAM buffer*/
		if (FblReadProm(target_Address, (vuint8 *)&SD15HeaderBuffer, sizeof(SD15HeaderBuffer))== sizeof(SD15HeaderBuffer))
		{
			/* PRQA S 0306 2 */ /* MD_FblLibSecBoot_0306 */
			if (E_OK == Csm_SignatureVerify(CsmConf_CsmJob_CsmJob_Fca_HeaderVerify, CRYPTO_OPERATIONMODE_SINGLECALL, dataPtr, dataLength, (P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR))SD15HeaderBuffer, FCA_SD15HEADER_LEN, &verifyResult))
			{
				if(CRYPTO_E_VER_OK == verifyResult)
				{
					FileSize = &SD15HeaderBuffer[FILE_SIZE_OFFSET];
					memcpy(FCAHeaderFileDigest,&SD15HeaderBuffer[FILE_DIGEST_OFFSET],SEC_SIZE_HASH_SHA256);
					Size = (((uint32)FileSize[0u] << 24u) | (((uint32)FileSize[1u]) << 16u ) | (((uint32)FileSize[2u]) << 8u ) | ((uint32)FileSize[3u])); /* Extract the File size information */
					nCnt= Size/BUFFER_SIZE;
					RemainingByteCnt = Size%BUFFER_SIZE;
					FileAddress = target_Address + FCA_SD15HEADER_LEN;
					Size = BUFFER_SIZE;
					Csm_Hash(CsmConf_CsmJob_CsmJob_CalculateHash,CRYPTO_OPERATIONMODE_START,NULL_PTR,0,NULL_PTR,NULL_PTR);
					if (FblReadProm(FileAddress, (vuint8 *)Readbuffer, Size) == Size)
					{
						localRetVal = Csm_Hash(CsmConf_CsmJob_CsmJob_CalculateHash,CRYPTO_OPERATIONMODE_UPDATE,(vuint8 *)Readbuffer,Size,calculatedFileDigest,&Resultlength);
						if(E_OK == localRetVal)
						{
							for(uint16 i = 0 ; i<nCnt -1 ; i++)
							{
								FileAddress = FileAddress + BUFFER_SIZE;
								if (FblReadProm(FileAddress, (vuint8 *)Readbuffer, Size) == Size)
								{
									localRetVal = Csm_Hash(CsmConf_CsmJob_CsmJob_CalculateHash,CRYPTO_OPERATIONMODE_UPDATE,(vuint8 *)Readbuffer,Size,calculatedFileDigest,&Resultlength);
									if(E_NOT_OK == localRetVal)
									{
										localRetVal = E_NOT_OK;
										break;
									}
								}
								else
								{
									localRetVal = E_NOT_OK;
									break;
								}
							}

							if(localRetVal == E_OK)
							{
								Size = RemainingByteCnt ;
								FileAddress = FileAddress + BUFFER_SIZE;
								if (FblReadProm(FileAddress, (vuint8 *)Readbuffer, Size) == Size)
								{
									if(E_OK == Csm_Hash(CsmConf_CsmJob_CsmJob_CalculateHash,CRYPTO_OPERATIONMODE_UPDATE,Readbuffer,Size,calculatedFileDigest,NULL_PTR))
									{
										(void) Csm_Hash(CsmConf_CsmJob_CsmJob_CalculateHash,CRYPTO_OPERATIONMODE_FINISH,NULL_PTR,0,calculatedFileDigest,&Resultlength);
										if(0 == memcmp(calculatedFileDigest,FCAHeaderFileDigest,SEC_SIZE_HASH_SHA256))
										{
											result = kDiagCheckVerificationOk;
										}
										else
										{
											result = kDiagCheckVerificationCRCFailed;
										}
									}
									else
									{
										result = kDiagCheckVerificationGeneralFailure;
									}
								}
								else
								{
									result = kDiagCheckVerificationGeneralFailure;
								}
							}
							else
							{
								result = kDiagCheckVerificationGeneralFailure;
							}
						}
						else
						{
							result = kDiagCheckVerificationGeneralFailure;
						}
					}
					else
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

		else
		{
		   result = kDiagCheckVerificationGeneralFailure;

		}

		(void)FblTimerInit();
		if(MCU10_FCA_HDR_START_ADDRESS == target_Address)
		{
			ApplFblNvReadFlashStatus(FBL_LBT_MCU10_APPLICATION_LB_BLOCK_NUMBER, &MCU1_0_AuthFailStatus);
			if((kDiagCheckVerificationOk != result) && (MCU1_0_AuthFailStatus == FALSE))
			{
				LogAuthFailureAttempt = TRUE ;
				MCU1_0_AuthFailStatus = TRUE ; /* State MCU1_0 authentication failure in 201F DID */
				ApplFblNvWriteFlashStatus(FBL_LBT_MCU10_APPLICATION_LB_BLOCK_NUMBER,&MCU1_0_AuthFailStatus);
			}
			else if((kDiagCheckVerificationOk == result) && (MCU1_0_AuthFailStatus == TRUE))
			{
				MCU1_0_AuthFailStatus = FALSE ; /* State MCU1_0 authentication SUCCESS in 201F DID */
				ApplFblNvWriteFlashStatus(FBL_LBT_MCU10_APPLICATION_LB_BLOCK_NUMBER,&MCU1_0_AuthFailStatus);
				memset(D_MCU_1_0_AUTH_FLAG_STATUS,MCU_1_0_AUTH_FLAG_STATUS_INIT_VALUE,2);
				memset(MCU1_0_AuthStatus,MCU_1_0_AUTH_FLAG_STATUS_INIT_VALUE,2);
			}
			else
			{
				/* Do nothing */
			}
		}
		else if((FBL_FCA_HDR_START_ADDRESS == target_Address) && (kDiagCheckVerificationOk != result ))
		{
			LogAuthFailureAttempt = TRUE ;
		}

		if(TRUE == LogAuthFailureAttempt)
		{

			ApplFblNvReadSecureLogGroup2(&SecureLogRecord_Group2);
			group = &SecureLogRecord_Group2;

			group->RecordEntry[group->RecId][D_SEC_NUM_POS] = (uint8)RIGHTSHIFT_BIT(group->SecId,8U);
			group->RecordEntry[group->RecId][D_SEC_NUM_POS+1u] = (uint8)group->SecId;

			group->RecordEntry[group->RecId][D_TIMESTAMP_POS] = (uint8)RIGHTSHIFT_BIT(TimeStamp,24U);
			group->RecordEntry[group->RecId][D_TIMESTAMP_POS+1u] = (uint8)RIGHTSHIFT_BIT(TimeStamp,16U);
			group->RecordEntry[group->RecId][D_TIMESTAMP_POS+2u] = (uint8)RIGHTSHIFT_BIT(TimeStamp,8U);
			group->RecordEntry[group->RecId][D_TIMESTAMP_POS+3u] = (uint8)TimeStamp;

			group->RecordEntry[group->RecId][D_EVENT_TYPE_POS] = CYBERSEC_FAILURE;

			group->RecordEntry[group->RecId][D_SUB_TYPE_POS] = SEC_BOOT_FAILURE;

			/*Log Secure Boot address */
			group->RecordEntry[group->RecId][D_EVENT_DATA_POS] = (uint8)RIGHTSHIFT_BIT(target_Address,24U);
			group->RecordEntry[group->RecId][D_EVENT_DATA_POS+1u] = (uint8)RIGHTSHIFT_BIT(target_Address,16U);
			group->RecordEntry[group->RecId][D_EVENT_DATA_POS+2u] = (uint8)RIGHTSHIFT_BIT(target_Address,8U);
			group->RecordEntry[group->RecId][D_EVENT_DATA_POS+3u] = (uint8)target_Address;

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
			ApplFblNvWriteSecureLogGroup2(&SecureLogRecord_Group2);
		}

		FblTimerStopp()

	return result;

}
#endif /* end of ENABLE_SD15_SECURE_BOOT */


#define FBLBMAP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* module specific MISRA deviations:

   MD_FblBmAp_0305:
      Reason:     Boot manager needs to jump to a memory location to start a target/software.
      Risk:       Unintended jump to wrong memory location.
      Prevention: No prevention possible, address is defined by the corresponding target.

   MD_FblBmAp_0306:
      Reason:     Address conversion between integer values and pointers is required to allow for hardware independent
                  configuration and address range checks.
      Risk:       The size of integer required to hold the result of a pointer cast is implementation-defined.
      Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
                  specific basis. The correctness of the respective implementation is verified by runtime tests.

*/

/***********************************************************************************************************************
 *  END OF FILE: BM_AP.C
 **********************************************************************************************************************/
