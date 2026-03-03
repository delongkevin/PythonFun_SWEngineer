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
 *  01.02.01   2019-01-31  viscb   ESCAN00101958    Read programming counter instead of programming attempts
 *  01.02.02   2019-07-12  viscb   ESCAN00103713    Support for ClearDiagnosticInformation for demo application only
 *  02.00.00   2020-03-26  vistbe  FBL-1510         Upgrade to latest reference implementation
 *  02.01.00   2020-12-17  vistbe  FBL-1352         Added support for Authenticated Diagnostics
 *  02.02.00   2021-04-12  vistmo  FBL-2961         Added support for Authenticated Diagnostics with vHSM
 *  02.03.00   2021-06-16  vistbe  FBL-3275         Added support Authenticated Diagnostics with escrypt library
 *  02.04.00   2022-06-14  visrie  FBL-5323         Support CSR Request - 0xD00A
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


#define FBL_APDI_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "Csm.h"
#include "Crypto_30_vHsm.h"
/***********************************************************************************************************************
 *  For testing purpose
 **********************************************************************************************************************/

uint8 test = 3;
uint8 Write_test_F110[4]={0xAA,0x55,0xAA,0x55};
uint8 Write_test_F110_FlashDefinitionNumber[2]= {0xAA,0x55};

uint8 Write_test_F132[10]={0xAA,0x55,0xAA,0x55,0xAA,0x55,0x01,0x02,0x03,0x04};
uint8 Write_test_F133[10]={0xAA,0x55,0xAA,0x55,0xAA,0x55,0x01,0x02,0x03,0x04};
uint8 Write_test_F134[11]={0xAA,0x55,0xAA,0x55,0xAA,0x55,0x01,0x02,0x03,0x04,0x01};

uint8 Write_test_F187[11]={0x01,0x02,0x03,0x55,0xAA,0x55,0x01,0x02,0x03,0x04,0x11};
uint8 Write_test_F188[11]={0xAA,0x01,0x02,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12};

uint8 Write_test_F18A[10]={0x01,0x55,0x03,0x55,0xAA,0x55,0x01,0x02,0x03,0x04};
uint8 Write_test_F18B[10]={0x02,0x03,0x04,0x55,0xAA,0x55,0x01,0x02,0x10,0x08};

uint8 Write_test_F194[11]={0x01,0x02,0x03,0x55,0xAA,0x55,0x01,0x02,0x03,0x04,0x11};
uint8 Write_test_F195[2]={0xBB,0xAA};

uint8 Write_test_F180[13]={0x22,0x32,0x03,0x55,0xAA,0x55,0x01,0x02,0x03,0x04,0x11,0x12,0x13};

uint8 Write_test_F1B3[13]={0x22,0x08,0x15,0x55,0xAA,0x55,0x01,0x02,0x03,0x04,0x11,0x12,0x13};

uint8 Write_test_F1B4[91]={ 0x28,0x08,0x15,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x01,
							0x22,0x08,0x16,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x02,
							0x28,0x08,0x17,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x03,
							0x23,0x09,0x15,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x04,
							0x24,0x10,0x13,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x05,
							0x28,0x01,0x31,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x06,
							0x22,0x02,0x05,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x07
							};

uint8 Write_test_F1B5[26]={ 0x22,0x08,0x15,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x01,
							0x27,0x08,0x16,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x07,0x06
                           };

uint8 Write_test_2010[2] ={0xFE,0x01};
uint8 Write_test_201A[2] ={0x01,0x02};
uint8 Write_test_2002[2] ={0xAA,0xBB};

uint8 Write_test_F190[17]={0x22,0x08,0x15,0x55,0xAA,0x55,0x01,0x02,0x03,0x04,0x11,0x12,0x13,0x14,0x15,0x16,0x17};
uint8 Write_test_F122[100]={0x28,0x08,0x15,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x01,
                            0x22,0x08,0x16,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x02,
                            0x28,0x08,0x17,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x03,
                            0x23,0x09,0x15,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x04,
                            0x24,0x10,0x13,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x05,
                            0x28,0x01,0x31,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x06,
                            0x28,0x01,0x31,0x03,0x55,0x01,0x02,0x03,0x04,0x01,0x12,0x00,0x06,
                            0x22,0x02,0x05,0x03,0x55,0x01,0x02,0x03,0x04
                            };

uint8 pki_uuid[kDiagRslDidEcuPkiUuid]={0x47,0xbc,0x49,0xd0,0x77,0xfc,0x11,0xee,0x99,0x9d,0xfc,0x9a,0x85,0x04,0x13,0x15};

uint8 Fill_IssuerName_2030[38u]={0x20u};
uint8 Fill_SerialNumber_2030[12]={0x00u};
/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLKBAPI_FRAMEDIAG_FCA_VERSION != 0x0204u ) || \
    ( FBLKBAPI_FRAMEDIAG_FCA_RELEASE_VERSION != 0x00u )
# error "Error in fbl_apdi.c: Source and header file are inconsistent!"
#endif

#if ( FBLKBAPI_FRAMEDIAG_FCA_VERSION != _FBLKBAPI_FRAMEDIAG_OEM_VERSION )
# error "Error in fbl_apdi.c: Source and v_ver.h are inconsistent!"
#endif
#if ( FBLKBAPI_FRAMEDIAG_FCA_RELEASE_VERSION != _FBLKBAPI_FRAMEDIAG_OEM_RELEASE_VERSION )
# error "Error in fbl_apdi.c: Source and v_ver.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  LOCAL VARIABLES
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  External FUNCTIONS and Data
 **********************************************************************************************************************/

extern tFblResult ApplFblSaveCertTimeInfo(void);
extern void SecureLogEvent(const EventType Event, const EventSubType SubEvent, const uint8* EventData);
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
/** Security access delay [ms] */
extern V_MEMRAM0 V_MEMRAM1 vuint32              V_MEMRAM2      secSecurityAccessDelay;
#endif
/** Diagnostic error code */
extern V_MEMRAM0 V_MEMRAM1 vuint8               V_MEMRAM2      diagErrorCode;

 /***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Compatibility define */
#if !defined( kDiagRslReadDataByIdentifier )
# define kDiagRslReadDataByIdentifier kDiagRslWriteDataByIdentifier
#endif

#define D_F112_PT_ESLM_HARDWARE_NUMBER_ADDRESS              ((uint32 *)0X97BFFC12U) /*EOL DID: F112 */
#define D_FD38_PROGRAMMED_ASSEMBLY_ADDRESS                  ((uint32 *)0X97BFFC1CU) /*EOL DID: FD38 */
#define D_F191_FCA_ESLM_ECU_HARDWARE_NUMBER_ADDRESS         ((uint32 *)0X97BFFC2CU) /*EOL DID: F191 */
#define D_F192_SUPPLIER_ECU_HARDWARE_PART_NUMBER_ADDRESS    ((uint32 *)0X97BFFC37U) /*EOL DID: F192 */
#define D_F193_SUPPLIER_ECU_HARDWARE_VERSION_NUMBER_ADDRESS ((uint32 *)0X97BFFC42U) /*EOL DID: F193 */
#define D_F18C_ECU_SERIAL_NUMBER_ADDRESS                    ((uint32 *)0X97BFFC43U) /*EOL DID: F18C */
#define D_DID_F18C_DATA_LEN                         	15u

#define kDiagDidOffset                                    2u

/* Programming preconditions */
#define kProgPrecondEngineSpeed                          0x01u
#define kProgPrecondInputShaftRpm                        0x03u
#define kProgPrecondOutputShaftRpm                       0x04u
#define kProgPrecondVehicleSpeed                         0x05u
#define kProgPrecondControlIsActive                      0x06u
#define kProgPrecondIgnitionOnRequired                   0x07u
#define kProgPrecondIgnitionOff                          0x09u
#define kProgPrecondLowBatteryVoltage                    0x0Au
#define kProgPrecondHighTemerature                       0x0Bu
#define kProgPrecondLowTemperature                       0x0Cu
#define kProgPrecondHighBatteryVoltage                   0x0Du

#define FBL_BLOCK_NUMBER                     0u
#define CAL_LB_BLOCK_NUMBER                  1u
#define EXTENDEDKEYRING_BLOCK_NUMBER         2u
#define SECURITY_CERT_LB_BLOCK_NUMBER        3u
#define MCU10_APPLICATION_LB_BLOCK_NUMBER    4u
#define LATEAPP1_MCU20_MCU21_LB_BLOCK_NUMBER 5u
#define ATFOPTEE_LB_BLOCK_NUMBER             6u
#define IFSQNX_LB_BLOCK_NUMBER               7u
#define C7X_LB_BLOCK_NUMBER                  8u

/*Bit 0 � ECU Software Mode (1=application, 0 = boot) - 0
Bit 1 � Gateway (1=ECU is a gateway, 0=ECU is NOT a gateway) - 0
Bit 2 � Slave ECU (1=ECU is Slave, 0=ECU is NOT a Slave) - 1
Bit 3 � Reserved (set to zero) - 0*/
#define BOOT_RUNNING_SLAVE_ECU                           0x04u

#define D_ISSUER_NAME_FULLSIZE          64u
#define D_SERIAL_NUMBER_FULLSIZE        32u
#define TOTAL_NO_OF_DCL_ENTRIES         16u
#define SIZE_OF_DCL_ENTRIES             (TOTAL_NO_OF_DCL_ENTRIES*(D_ISSUER_NAME_FULLSIZE+D_SERIAL_NUMBER_FULLSIZE))

#define DiagGetError()                    ( diagErrorCode )                   /**< Get error (NRC) code */
/* ADA defines */
# if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
#  define FBL_ADA_CERT_SERIALNUMBER_ID        1u
#  define FBL_ADA_CERT_ISSUERNAME_ID          3u
#  define FBL_ADA_CERT_TESTERROLE_ID          15u
#  define FBL_ADA_CERT_SERIALNUMBER_LEN       20u
#  define FBL_ADA_CERT_ISSUERNAME_LEN         26u
#  define FBL_ADA_CERT_TESTERROLE_LEN         1u
#  define FBL_ADA_CERT_SERIALNUMBER_ISSUERNAME_LIST_MAX  10
# endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */

#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED)
# if !defined( kDiagMaxFailedAttempts )
/* 21 is the maximum failed counter value for the result of the formula Delay Time = 2^n seconds
   to fit into a 32 bit variable (as milliseconds) */
#define kDiagMaxFailedAttempts 21u
# endif /* !defined( kDiagMaxFailedAttempts ) */
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */

#define DiagGetError()                    ( diagErrorCode )                   /**< Get error (NRC) code */

#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
/* Formula: Delay timer = 2 ^ n seconds (* 1000 as we need this value in milliseconds) */
# define FBL_SEC_DELAY_TIMEOUT(invalidCount) ((((vuint32)1u << (invalidCount)) * 1000u) / kDiagCallCycle)
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */
/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
/* PRQA S 3218 1 */ /* MD_FblKbApiFrame_3218_FileScopeStatic */
V_MEMROM0 static V_MEMROM1_FAR vuint8 V_MEMROM2_FAR fblSupportedPreconditions[] =
{
   kProgPrecondEngineSpeed,
   kProgPrecondInputShaftRpm,
   kProgPrecondOutputShaftRpm,
   kProgPrecondVehicleSpeed,
   kProgPrecondControlIsActive,
   kProgPrecondIgnitionOnRequired,
   kProgPrecondIgnitionOff,
   kProgPrecondLowBatteryVoltage,
   kProgPrecondHighTemerature,
   kProgPrecondLowTemperature,
   kProgPrecondHighBatteryVoltage
};

#define kFblNoOfSupportedPrecond (sizeof(fblSupportedPreconditions) / sizeof(vuint8))

# if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 diagChallengeBuffer[kSecAuthPrgNonceLength + kSecAuthPrgChallengeLength];
V_MEMRAM0 static V_MEMRAM1 vuint32 V_MEMRAM2 tmrCertValid = 0uL;
vuint8 testerRole[FBL_ADA_CERT_TESTERROLE_LEN];
static vuint8 ADASuccessFlag;
# endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

static tFblResult ApplFblReadProgAttemptCounter(vuint8 *targetBuffer, tFblLbtBlockType blockType);
static tFblResult ApplFblReadEcuDiagnosticIdentification(vuint8 *targetBuffer);
static tFblResult ApplFblReadVehicleManufEcuHwNumber(vuint8 *targetBuffer);
#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
static void ApplFblInvalidateCertificate(void);
static void ApplFblStoreCertSerialNumber(const V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * serNum);
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */

/***********************************************************************************************************************
 *  Local FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  ApplFblReadProgAttemptCounter
 **********************************************************************************************************************/
/*! \brief         Read programming attempt counter for each logical block
 *  \details       This function copies the current programming attempt counter (2 bytes) and the max. number of
 *                 supported programming attempts (2 bytes) of each logical block of the given type.
 *  \param[in]     targetBuffer Pointer to diag reponse buffer
 *  \param[in]     blockType Boot/code/data block
 *  \return        kFblOk Data copied successfully kFblFailed if NV read access failed
 **********************************************************************************************************************/
static tFblResult ApplFblReadProgAttemptCounter(vuint8 *targetBuffer, tFblLbtBlockType blockType)
{

	vuint16 currentProgAttempts;
	vuint16 targetIdx;
	tFblResult result;
	tBlockDescriptor iterBlock;
	tFblLbtBlockFilter blockFilter;
	tFblLbtMaxProgAttempts maxProgAttempts;

	targetIdx = 0u;
	result = kFblOk;

      FblLbtBlockFilterSetBlockType(&blockFilter, blockType);
      iterBlock = FblLbtBlockFirst(&blockFilter);
      while (FblLbtBlockDone() == FALSE)
      {
         result |= ApplFblGetProgAttempts(iterBlock, &currentProgAttempts);

         /* Current programming attempt counter */
         targetBuffer[targetIdx] = (vuint8)(currentProgAttempts >> 8u);
         targetBuffer[targetIdx + 1u] = (vuint8)(currentProgAttempts & 0xFFu);

         /* Maximum number of programming attempts from logical block table configuration */
         result |= FblLbtGetBlockMaxProgAttemptsByNr(iterBlock.blockNr, &maxProgAttempts);

         targetBuffer[targetIdx + 2u] = (vuint8)(maxProgAttempts >> 8u) ;
         targetBuffer[targetIdx + 3u] = (vuint8)(maxProgAttempts & 0xFFu);

         targetIdx += 4u;

         /* Prepare next cycle */
         iterBlock = FblLbtBlockNext();
      }
   

   return result;
}

/***********************************************************************************************************************
 *  ApplFblReadEcuDiagnosticIdentification
 **********************************************************************************************************************/
/*! \brief         Copy the requested ECU Diagnostic Information into the targetBuffer
 *  \details       This function is called for the ReadDataByIdentifier - F110h DID. The requested data is provided
 *                 from NVM and from common data structure.
 *  \param[in]     targetBuffer Pointer to diag reponse buffer
 *  \return        kFblOk Data copied successfully kFblFailed if NV read access failed
 **********************************************************************************************************************/
static tFblResult ApplFblReadEcuDiagnosticIdentification(vuint8 *targetBuffer)
{
   tFblResult result;
   vuint8 idx;
   uint8 flashDefinitionNumberTemp[2u];

   idx = 0u;

   /* Read Diagnostic Variant (2 bytes) */
   targetBuffer[idx] = fblCommonData.diagnosticVariant[0];
   idx++;
   targetBuffer[idx] = fblCommonData.diagnosticVariant[1];
   idx++;

   /* Read Diagnostic Version+FDN (6 bytes) */
   result = ApplFblNvReadDiagnosticVersion(&targetBuffer[idx]); /*NvM param - DID_F110_Ecu_Diag_Id_FlashDefinitionNumber*/
   idx += 6u;

   /* Read Supplier ID (2 bytes) */
   targetBuffer[idx] = fblCommonData.supplierId[0];
   idx++;
   targetBuffer[idx] = fblCommonData.supplierId[1];

   return result;
}

/***********************************************************************************************************************
 *  ApplFblReadVehicleManufEcuHwNumber
 **********************************************************************************************************************/
/*! \brief         Copy the requested Vehicle Manufacturer ECU Hardware Number into the targetBuffer
 *  \details       This function is called for the ReadDataByIdentifier - F191h DID
 *  \param[in]     targetBuffer Pointer to diag reponse buffer
 *  \return        kFblOk Data copied successfully
 **********************************************************************************************************************/
static tFblResult ApplFblReadVehicleManufEcuHwNumber(vuint8 *targetBuffer)
{
	tFblResult result = kFblOk;
	if(IsEOlDataAvailaible == TRUE)
	{
		(void)MEMCPY(&targetBuffer[0u], D_F191_FCA_ESLM_ECU_HARDWARE_NUMBER_ADDRESS, kDiagRslDidVehicleManufECUHwNo);
	}
	else
	{
		result = kFblFailed;
	}
   return result;
}

#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
/***********************************************************************************************************************
*  ApplFblInvalidateCertificate
***********************************************************************************************************************/
/*! \brief        Invalidate the loaded certificate for ADA
*   \return       void
**********************************************************************************************************************/
static void ApplFblInvalidateCertificate(void)
{
   vuint8 tmpCert = 0u;

   /* Set the certificate to not valid.
    * This operation will replace the first byte of the certificate
    * with the value 0x00, causing the parsing to fail. This will
    * invalidate the certificate.
    */
   (void)SecM_AuthDiag_Certificate_SetValue(&tmpCert, 1u);
}
/***********************************************************************************************************************
*  ApplFblStoreCertSerialNumber
***********************************************************************************************************************/
/*! \brief      Store the certificate serial number
*  \param[in]   serNum Pointer to a serial number of the certificate
*  \return      void
**********************************************************************************************************************/
/* PRQA S 3219 1 */ /* MD_FblKbApiFrame_3219 */
static void ApplFblStoreCertSerialNumber (const V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * serNum)
{
   vuint8 localSerNum[FBL_ADA_CERT_SERIALNUMBER_LEN];
   vsint8 idx;

   /* Shift the list */
   for (idx = FBL_ADA_CERT_SERIALNUMBER_ISSUERNAME_LIST_MAX - 2; idx >= 0; idx--)
   {
     (void)ApplFblNvReadSerialNumber((vuint16)idx, localSerNum);
     (void)ApplFblNvWriteSerialNumber(((vuint16)idx + 1u), localSerNum);
   }
   /* Write always the new serial number at position 0 */
  (void)ApplFblNvWriteSerialNumber(0u, serNum);
}

/***********************************************************************************************************************
*  ApplFblStoreCertIssuerName
***********************************************************************************************************************/
/*! \brief      Store the certificate Issuer Name
*  \param[in]   IssuerName Pointer to a Issuer Name of the certificate
*  \return      void
**********************************************************************************************************************/
/* PRQA S 3219 1 */ /* MD_FblKbApiFrame_3219 */
static void ApplFblStoreCertIssuerName (const V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * IssuerName)
{
   vuint8 localIssuerName[FBL_ADA_CERT_ISSUERNAME_LEN];
   vsint8 idx;

   /* Shift the list */
   for (idx = FBL_ADA_CERT_SERIALNUMBER_ISSUERNAME_LIST_MAX - 2; idx >= 0; idx--)
   {
     (void)ApplFblNvReadIssuerName((vuint16)idx, localIssuerName);
     (void)ApplFblNvWriteIssuerName(((vuint16)idx + 1u), localIssuerName);
   }
   /* Write always the new serial number at position 0 */
  (void)ApplFblNvWriteIssuerName(0u, IssuerName);
}
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */
/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ApplDiagUserService
 **********************************************************************************************************************/
/*! \brief         Call-back function for user diagnostic services. pbDiagData points to subfunction.
 *  \details       This function is called when a diagnostic service has been received that is not managed by the FBL
 *                 itself -> can be managed by user.
 *  \param[in,out] pbDiagData Pointer to diag service data (after SID!)
 *  \param[in]     diagReqDataLen Service data length (without SID!)
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
void ApplDiagUserService( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
   (void)diagReqDataLen;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   switch (diagServiceCurrent) /* PRQA S 3315 */ /* MD_FblKbApiOem_3315 */
   {
      default:
      {
         DiagNRCServiceNotSupported();
         break;
      }
   }
}

/***********************************************************************************************************************
 *  ApplDiagUserSubFunction
 **********************************************************************************************************************/
/*! \brief         Call-back function for user diagnostic services. pbDiagData points to subfunction.
 *  \details       This function is called when the bootloader manages the diagnostic service, but the sub-parameter
 *                 is unknown -> subparameter of the service can be managed by user.
 *  \param[in,out] pbDiagData Pointer to diag service data (after SID!)
 *  \param[in]     diagReqDataLen Service data length (without SID!!)
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
void ApplDiagUserSubFunction( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
   (void)diagReqDataLen;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

   /* If you want to support different sub functions, add appropriate code */
   switch (diagServiceCurrent) /* PRQA S 3315 */ /* MD_FblKbApiOem_3315 */
   {
      default:
      {
         DiagNRCSubFunctionNotSupported();
         break;
      }
   }
}

/***********************************************************************************************************************
 *  ApplFblCheckProgPreconditions
 **********************************************************************************************************************/
/*! \brief         This function is called by the diagnostic module to check the programming preconditions.
 *  \param[in,out] pbDiagData Pointer to diagnostic data buffer
 *  \param[in]     diagReqDataLen The request data length
 *  \return        If all conditions are correct, the function returns kFblOk, otherwise kFblFailed.
 **********************************************************************************************************************/
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
tFblResult ApplFblCheckProgPreconditions( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
   vuint8   unfullfilledCnt;
   vuint8   idx;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

   /* Counter for unfulfilled preconditions */
   unfullfilledCnt = 0u;

   /* Check all preconditions                                                 *
    * Return all preconditions that are not fulfilled according to 09010-02   */
   for (idx = 0u ; idx < kFblNoOfSupportedPrecond ; idx++)
   {
      switch (fblSupportedPreconditions[idx])
      {
         case kProgPrecondEngineSpeed:

            /* Example: Test if programming preconditions are fulfilled */
            /*
            if (preCondition != OK)
            {
               ** Copy code of unfulfilled precondition into response message **
               pbDiagData[kDiagLocFmtStartPreCond+unfullfilledCnt] = kProgPrecondEngineSpeed;
               unfullfilledCnt++;
            }
            */

            break;
         case kProgPrecondInputShaftRpm:
            break;
         case kProgPrecondOutputShaftRpm:
            break;
         case kProgPrecondVehicleSpeed:
            break;
         case kProgPrecondControlIsActive:
            break;
         case kProgPrecondIgnitionOnRequired:
            break;
         case kProgPrecondIgnitionOff:
            break;
         case kProgPrecondLowBatteryVoltage:
            break;
         case kProgPrecondHighTemerature:
            break;
         case kProgPrecondLowTemperature:
            break;
         case kProgPrecondHighBatteryVoltage:
            break;
         default: /* PRQA S 2016 */ /*  MD_MSR_EmptyClause */

            break;
      }
   }

   /* tbd */
   /* Set Number of Programming Conditions */
   pbDiagData[kDiagLocFmtNrOfPrecond] = unfullfilledCnt;

   DiagProcessingDone( (tCwDataLengthType)(4u + (tCwDataLengthType)unfullfilledCnt));  /* Always send positive response */
   return kFblOk;

   /*PRQA S 6030 1 */ /* MD_MSR_STCYC */
} /* PRQA S 6030 */ /* MD_MSR_STCYC */

/* PRQA S 2889 8 */ /* MD_FblKbApiFrame_2889 */
/***********************************************************************************************************************
 *  ApplFblReadDataByIdentifier
 **********************************************************************************************************************/
/*! \brief         ReadDataByIdentifier service function.
 *  \param[in,out] pbDiagData Pointer to diag service data (after SID!)
 *  \param[in]     diagReqDataLen Service data length (without SID!)
 **********************************************************************************************************************/
/* PRQA S 2889, 6010, 6030, 6050, 6080 1 */ /* MD_FblKbApi_2889, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
void ApplFblReadDataByIdentifier( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
   typedef struct {
      vuint16   did;
      vuint16   maxSize;
   } tDid;
	Crypto_VerifyResultType verifyResult;
	SecureLogRecord_t  SecureLogRecord_GroupOne;
	SecureLogRecord_t  SecureLogRecord_GroupTwo;
	vuint8 NvReadResult;
   static V_MEMROM1 tDid V_MEMROM2 didTable[] =
   {
      /* Data identifier , record length */
      { kFblDiagDidVehicleNetworkSecurityStatus , kDiagRslDidVehicleNetworkSecurityStatus },
	  { kFblDiagDidDiagToolAndSessionStatus     , kDiagRslDidDiagToolAndSessionStatus     },
      { kFblDiagDidOdometerHighResolution       , kDiagRslDidOdometerHighResolution       },
      { kFblDiagDidOdometerContentLastPrg       , kDiagRslDidOdometerContentLastPrg       },
      { kFblDiagDidBootSwProgAttemptCounter     , kDiagRslDidBootSwProgAttemptCounter     },
      { kFblDiagDidProgrammingStatus            , kDiagRslDidProgrammingStatus            },
      { kFblDiagDidApplSwReprogAttemptCounter   , kDiagRslDidApplSwReprogAttemptCounter   },
      { kFblDiagDidApplDataReprogAttemptCounter , kDiagRslDidApplDataReprogAttemptCounter },
      { kFblDiagDidDiagnosticSpecInfo           , kDiagRslDidDiagnosticSpecInfo           },
      { kFblDiagDidEcuDiagIdentification        , kDiagRslDidEcuDiagIdentification        },
      { kFblDiagDidEcuIdentificationHwPartNo    , kDiagRslDidEcuIdentificationHwPartNo    },
      { kFblDiagDidSwEbomPartNo                 , kDiagRslDidSwEbomPartNo                 },
      { kFblDiagDidEbomEcuPartNo                , kDiagRslDidEbomEcuPartNo                },
	  {kFblDiagDidEBOMAssemblyPartNumber        , kDiagRslDidEBOMAssemblyPartNumber       },
	  {kFblDiagDidCODEPAssemblyPartNumber       , kDiagRslDidCODEPAssemblyPartNumber      },
      { kFblDiagDidHardwareSupplierId           , kDiagRslDidHardwareSupplierId           },
      { kFblDiagDidSoftwareSupplierId           , kDiagRslDidSoftwareSupplierId           },
      { kFblDiagDidBootSwVersionInfo            , kDiagRslDidBootSwVersionInfo            },
      { kFblDiagDidActiveDiagSessDid            , kDiagRslDidActiveDiagSessDid            },
      { kFblDiagDidCodepEcuPartNo               , kDiagRslDidCodepEcuPartNo               },
      { kFblDiagDidVehicleManufEcuSwNo          , kDiagRslDidVehicleManufEcuSwNo          },
	  {kFblDiagDidECUSoftwareCalibrationNumber  , kDiagRslDidECUSoftwareCalibrationNumber },
	  {kFblDiagDidSoftwareApplicationNumber     , kDiagRslDidSoftwareApplicationNumber    },
      { kFblDiagDidEcuSerialNumber              , kDiagRslDidEcuSerialNumber              },
      { kFblDiagDidVehicleManufECUHwNo          , kDiagRslDidVehicleManufECUHwNo          }, /* F191 */
      { kFblDiagDidSupplierManufECUHwPartNo     , kDiagRslDidSupplierManufECUHwPartNo     }, /* F192 */
      { kFblDiagDidSupplierManufECUHwVersionNo  , kDiagRslDidSupplierManufECUHwVersionNo  }, /* F193 */
      { kFblDiagDidSupplierManufECUSwPartNo      , kDiagRslDidSupplierManufECUSwPartNo    },
      { kFblDiagDidSupplierManufECUSwVersionNo  , kDiagRslDidSupplierManufECUSwVersionNo  },
      { kFblDiagDidExRegOrTypeApprovalNo        , kDiagRslDidExRegOrTypeApprovalNo        },
      { kFblDiagDidSystemIdentificationData     , kDiagRslDidSystemIdentificationData     },
      { kFblDiagDidVectorDeliveryId             , kDiagRslDidVectorDeliveryId             },
      { kFblDiagDidAlgorithmIdNumberReprog      , kDiagRslDidAlgorithmIdNumberReprog      },
      { kFblDiagDidBootSwFingerprintRead        , kDiagRslDidBootSwFingerprintRead        },
      { kFblDiagDidApplSwFingerprintRead        , kDiagRslDidApplSwFingerprintRead        },
      { kFblDiagDidApplDataFingerprintRead      , kDiagRslDidApplDataFingerprintRead      },
      { kFblDiagDidEcuPkiUuid                   , kDiagRslDidEcuPkiUuid                   }, /* 2951 */
	   { kFblDiagDidProgrammedAssembly           , kDiagRslDidProgrammedAssembly			   }, /* FD38 */
      { kFblDiagDidPolicyType          			, kDiagRslDidPolicyType			  		      }, /* 2954*/
      { kFblDiagDidActiveRole          			, kDiagRslDidActiveRole			  		      }, /* 0108*/
      { kFblDiagDidAppSWHeaderInfo	            , kDiagRslDidAppSWHeaderInfo	            }, /*	2957	*/
      { kFblDiagDidAppSWHeaderUuid	            , kDiagRslDidAppSWHeaderUuid	            }, /*	2958	*/
      { kFblDiagDidAppDataConfigInfo	         , kDiagRslDidAppDataConfigInfo	         }, /*	2959	*/
      { kFblDiagDidAppDataHeaderUuid	         , kDiagRslDidAppDataHeaderUuid	         }, /*	295A	*/
      { kFblDiagDidAppHtaHeaderInfo	            , kDiagRslDidAppHtaHeaderInfo	            }, /*	295B	*/
      { kFblDiagDidAppHtaHeaderUuid	            , kDiagRslDidAppHtaHeaderUuid	            }, /*	295C	*/
      { kFblDiagDidAppDCLHeaderUuid	            , kDiagRslDidAppDCLHeaderUuid	            }, /*	295E	*/
      { kFblDiagDidAppDCLHeaderInfo             , kDiagRslDidAppDCLHeaderInfo	            }, /*	295F	*/
      { kFblDiagDidAuthenticDiagPrevAccess	   , kDiagRslDidAuthenticDiagPrevAccess      }, /*	2030	*/
      { kFblDiagDidDisallowedCertList	         , kDiagRslDidDisallowedCertList	         }, /*	2031	*/
      { kFblDiagDidSecureLog	                  , kDiagRslDidSecureLog	                  }, /*	2032	*/
      { kFblDiagDidSecurityStatus	            , kDiagRslDidSecurityStatus	            }, /*	100C	*/
      { kFblDiagDidPublicCertRegion	            , kDiagRslDidPublicCertRegion	            }, /*	F111	*/
      { kFblDiagDidBootFailureReason	         , kDiagRslDidBootFailureReason	         }  /*	201F	*/
   };

   vuint16 diagRespDataLen;

   vuint16 didIdx;
   vuint16 outIdx;
   vuint16 outIdxAdd;
   vuint16 currentDid;
   vuint16 didNo;
   vuint8  didBuffer[(FBL_MAX_DID_COUNT << 1u)];
   vuint16 i, j;
   vuint8* diagData;
   vuint8* Data;
   tBlockDescriptor iterBlock;
   tFblLbtBlockFilter blockFilter;
   uint8 securityState_u8;
   uint8 blockCount;
   uint8 tempVal_u8;
   uint8 tempVal1_u8;

   tFblResult result;
   vuint16 idx;

   vuint8 dummySWNo[10] = {'D','U','M','M','Y','P','A','R','T','N'};

   vuint8 PlannedRel_au8[8] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};

   vuint8 currentVIN[17] =    {(vuint8)' ', (vuint8)' ', (vuint8)' ', (vuint8)' ',
                               (vuint8)' ', (vuint8)' ', (vuint8)' ', (vuint8)' ',
                               (vuint8)' ', (vuint8)' ', (vuint8)' ', (vuint8)' ',
                               (vuint8)' ', (vuint8)' ', (vuint8)' ', (vuint8)' ',
                               (vuint8)' ' };

   vuint8 idx1 = 0;
   Std_ReturnType v_retVal_u8 = E_NOT_OK;
   Std_ReturnType retval;
   uint8 v_LoopIdx_CertInfo_u8;
   uint8 DCLEntries[SIZE_OF_DCL_ENTRIES] = {0};
   uint32 DCLlength = SIZE_OF_DCL_ENTRIES;

   /* Check diagnostic request length */
   if (   (diagReqDataLen < kDiagRqlReadDataByIdentifier)
       || ((diagReqDataLen & 0x01u) != 0u)
      )
   {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
      return;
   }

   /* If necessary this check could be used to
    * ensure a prior security access. It could
    * also be used for certain data identifiers. */
   /*
   if (!GetSecurityUnlock())
   {
      DiagNRCSecurityAccessDenied();
      return;
   }
   */

   didNo = (diagReqDataLen / 2u);

   if (didNo > FBL_MAX_DID_COUNT)
   {
      DiagNRCRequestOutOfRange();
      return;
   }

   for (i = 0u; i < diagReqDataLen; i++)
   {
      didBuffer[i] = pbDiagData[i];
   }

   outIdx = 0u;
   didIdx = 0u;
   i = 0u;
   result = kFblOk;
   while((i < didNo) && (result == kFblOk))
   {
      currentDid =  ((vuint16)didBuffer[didIdx]) << 8u;
      currentDid |= (vuint16)didBuffer[didIdx + 1u];

      diagData = &pbDiagData[outIdx];

      diagData[0] = didBuffer[didIdx];
      diagData[1] = didBuffer[didIdx + 1u];

      didIdx += 2u;

      outIdxAdd = 0u;
      for (j = 0u; j < (sizeof(didTable)/sizeof(tDid)); j++)
      {
         if (didTable[j].did == currentDid)
         {
            outIdxAdd = didTable[j].maxSize + kDiagRslReadDataByIdentifier;
            break;
         }
      }

      if (outIdxAdd != 0u)
      {
         /* Check if response still fits into diag buffer */
         if ((outIdx + outIdxAdd) > (vuint16)(FBL_DIAG_BUFFER_LENGTH - 1u))
         {
            DiagNRCRequestOutOfRange();
            return;
         }

         switch (currentDid)
         {
            case kFblDiagDidVehicleNetworkSecurityStatus :
            {
               /* ToDo: Copy diagnostic data if required */
               break;
            }

            /* 100B - Diagnostic Tool and Session Status */
            case kFblDiagDidDiagToolAndSessionStatus:
            {
            	if (GetDiagProgrammingSession())
            	{
            		diagData[kDiagDidOffset] = (uint8)(1u << 2u);
            	}
            	else if (GetDiagExtendedSession())
            	{
            		diagData[kDiagDidOffset] = (uint8)(1u << 3u);
            	}
            	else
            	{
            		diagData[kDiagDidOffset] = (uint8)(1u << 1u);
            	}

            	/*Tester is present*/
            	diagData[kDiagDidOffset] |= TesterPresentFlag;

            	break;
            }

            case kFblDiagDidOdometerHighResolution       :
            {
               /* ToDo: Copy diagnostic data if required */
               break;
            }

            /*2002*/
            case kFblDiagDidOdometerContentLastPrg       :
            {
            	result =ApplFblNvReadDID_2002_OdoFlashing(&diagData[kDiagDidOffset]);

            	break;
            }

            /* 2003 */
            case kFblDiagDidBootSwProgAttemptCounter     :
            {
               result = ApplFblReadProgAttemptCounter(&diagData[kDiagDidOffset], kBlockTypeBoot);
               break;
            }

            /* 2010 - Programming status */
            case kFblDiagDidProgrammingStatus            :
            {
               vuint8 BlockFlashStatus[10];
               vuint8 progStatBuffer[2];
               vuint8 IsApplBlockInvalid = FALSE;
               vuint8 IsDataBlockInvalid = FALSE;
               diagData[kDiagDidOffset] = 0xFF;
               DiagExRCRResponsePending(kForceSendResponsePending);
               diagData[kDiagDidOffset] &= ~(uint8)(1u << 0u);

               for (idx = 0u; idx < 10u; idx++)
               {
                  ApplFblNvReadFlashStatus(idx, &BlockFlashStatus[idx]);
                  if (BlockFlashStatus[idx] == 1u)
                  {
                     /* Check Programming status of Appl Sw block */
                     /* Bit1: Logical block 4: MCU10_Application_LB
                      * Bit2: Logical block 5: LateApp1_MCU20_MCU21_LB
                      * Bit3: Logical block 6: AtfOptee_LB
                      * Bit4: Logical block 7: IfsQNX_LB
                      * Bit5: Logical block 8: C7x_LB */
                     if (idx >= MCU10_APPLICATION_LB_BLOCK_NUMBER && idx <= C7X_LB_BLOCK_NUMBER)
                     {
                        IsApplBlockInvalid = TRUE;
                     }
                     /* Check Programming status of Data block */
                     /* Bit6: Logical block 1: CAL_LB
                     * Bit7: Logical block 2: ExtendedKeyRing
                     * Bit8: Logical block 2: SecCert */
                     else if (idx >= CAL_LB_BLOCK_NUMBER && idx <= SECURITY_CERT_LB_BLOCK_NUMBER)
                     {
                        IsDataBlockInvalid = TRUE;
                     }
                     else
                     {
                        /* Do Nothing */
                     }
                  }
               }
               diagData[kDiagDidOffset] &= ~(uint8)(IsApplBlockInvalid << 1u);
               diagData[kDiagDidOffset] &= ~(uint8)(IsDataBlockInvalid << 2u);
               ApplFblNvReadProgrammingStatus(progStatBuffer);
               diagData[kDiagDidOffset + 1] = progStatBuffer[1];
               break;
            }

            /* 201A */
            case kFblDiagDidApplSwReprogAttemptCounter   :
            {
                /* Send response pending in case of long NV accesses */
                DiagExRCRResponsePending(kForceSendResponsePending);
            	result = ApplFblReadProgAttemptCounter(&diagData[kDiagDidOffset], kBlockTypeCode);

            	break;
            }

            /* 201B */
            case kFblDiagDidApplDataReprogAttemptCounter :
            {
               result = ApplFblReadProgAttemptCounter(&diagData[kDiagDidOffset], kBlockTypeData);
               break;
            }

            /* F10D */
            case kFblDiagDidDiagnosticSpecInfo           :
            {
               for (idx = 0u; idx < kDiagRslDidDiagnosticSpecInfo; idx++)
               {
                  diagData[kDiagDidOffset + idx] = fblCommonData.diagSpecInfo[idx];
               }
               break;
            }

            /* F110 */
            case kFblDiagDidEcuDiagIdentification        :
            {
               result = ApplFblReadEcuDiagnosticIdentification(&diagData[kDiagDidOffset]);
               break;
            }

            /* F112 */
            case kFblDiagDidEcuIdentificationHwPartNo    :
            {
            	if(IsEOlDataAvailaible == TRUE)
            	{
            		(void)MEMCPY(&diagData[kDiagDidOffset], D_F112_PT_ESLM_HARDWARE_NUMBER_ADDRESS, kDiagRslDidEcuIdentificationHwPartNo);
            	}
            	else
            	{
            		result = kFblFailed;
            	}
            	break;
            }

            /* F122 */
            case kFblDiagDidSwEbomPartNo                 :
            {
            	/* Send response pending for following NV-access */
            	DiagExRCRResponsePending(kForceSendRpIfNotInProgress);

            	/* Iterate over the logical block table and report part number of all blocks */
            	tFblLbtBlockCount blockCount = FBL_LBT_BLOCK_COUNT;
            	idx = 0;
            	/* Read boot block SW Ebom no */
            	FblLbtBlockFilterSetBlockType(&blockFilter, kBlockTypeBoot);
            	iterBlock = FblLbtBlockFirst(&blockFilter);
            	while (FblLbtBlockDone() == FALSE)
            	{
            		result |= ApplFblNvReadSwEbomPartNumber(iterBlock.blockNr, &diagData[kDiagDidOffset + (idx*kApplInfoSizeSwEbomPartNumber_F122)]);
            		idx++;
            		/* Prepare next cycle */
            		iterBlock = FblLbtBlockNext();
            	}

            	/* Read Code blocks SW Ebom no */
            	FblLbtBlockFilterSetBlockType(&blockFilter, kBlockTypeCode);
            	iterBlock = FblLbtBlockFirst(&blockFilter);
            	while (FblLbtBlockDone() == FALSE)
            	{
            		result |= ApplFblNvReadSwEbomPartNumber(iterBlock.blockNr, &diagData[kDiagDidOffset + (idx*kApplInfoSizeSwEbomPartNumber_F122)]);
            		++idx;

            		/* Prepare next cycle */
            		iterBlock = FblLbtBlockNext();
            	}

            	/* Read data blocks SW Ebom no */
            	FblLbtBlockFilterSetBlockType(&blockFilter, kBlockTypeData);
            	iterBlock = FblLbtBlockFirst(&blockFilter);
            	while (FblLbtBlockDone() == FALSE)
            	{
            		result |= ApplFblNvReadSwEbomPartNumber(iterBlock.blockNr, &diagData[kDiagDidOffset + (idx*kApplInfoSizeSwEbomPartNumber_F122)]);
            		idx++;
            		/* Prepare next cycle */
            		iterBlock = FblLbtBlockNext();
            	}

            	/* Change output length to actual length */
            	outIdxAdd = (kDiagDidOffset + ((vuint16)blockCount * kApplInfoSizeSwEbomPartNumber_F122));

            	break;
            }

            /* F132 */
            case kFblDiagDidEbomEcuPartNo                :
            {
               result = ApplFblNvReadEbomEcuPartNumber(&diagData[kDiagDidOffset]);

               break;
            }

            /* F133 */
            case kFblDiagDidEBOMAssemblyPartNumber                :
            {
               result = ApplFblNvReadEbomAssemblyPartNumber(&diagData[kDiagDidOffset]);
               break;
            }

            /* F134 */
            case kFblDiagDidCODEPAssemblyPartNumber                :
            {
            	result = ApplFblNvReadCodepAssemblyPartNumber(&diagData[kDiagDidOffset]);
            	break;
            }

            /* F154 */
            case kFblDiagDidHardwareSupplierId           :
            {
               diagData[kDiagDidOffset] = fblCommonData.HwSupplierId[0];
               diagData[kDiagDidOffset + 1u] = fblCommonData.HwSupplierId[1];
               break;
            }

            /* F155 */
            case kFblDiagDidSoftwareSupplierId           :
            {
               diagData[kDiagDidOffset] = fblCommonData.swSupplierId[0];
               diagData[kDiagDidOffset + 1u] = fblCommonData.swSupplierId[1];
               break;
            }

            /* F180 */
            case kFblDiagDidBootSwVersionInfo            :
            {
            	uint8 diagDataTemp[13];

            	/* Number of boot software logical blocks */
            	diagData[kDiagDidOffset] = kBlockTypeBootBlockCount;

            	result = ApplFblNvReadSoftwareIdentification(FBL_LBT_FBL_LB_BLOCK_NUMBER,&diagData[kDiagDidOffset+1]);

               break;
            }

            /* F186 */
            case kFblDiagDidActiveDiagSessDid            :
            {
               /* Active diagnostic session */
               if (GetDiagProgrammingSession())
               {
                  diagData[kDiagDidOffset] = kDiagSubProgrammingSession;
               }
               else if (GetDiagExtendedSession())
               {
                  diagData[kDiagDidOffset] = kDiagSubExtendedDiagSession;
               }
               else
               {
                  diagData[kDiagDidOffset] = kDiagSubDefaultSession;
               }

               /* Active Diagnostic Session of ECU - (1: Application, 0: Boot)*/
               diagData[kDiagDidOffset + 1u] = BOOT_RUNNING_SLAVE_ECU;

               /*Get security status*/
               #ifdef FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED
               securityState_u8 = ApplFblGetAuthenticationState();
               #else
               securityState_u8 = FblDiagGetSecurityUnlock();
               #endif
               diagData[kDiagDidOffset + 2u] = securityState_u8;

               break;
            }

            /* F187 */
            case kFblDiagDidCodepEcuPartNo               :
            {
               result = ApplFblNvReadCoDePEcuPartNumber(&diagData[kDiagDidOffset]);
               break;
            }

            /* F188 */
            case kFblDiagDidVehicleManufEcuSwNo          :
            {
               result = ApplFblNvReadVehicleManufEcuSwNumber(&diagData[kDiagDidOffset]);
               break;
            }

            /* F18A */
            case kFblDiagDidECUSoftwareCalibrationNumber :
            {
            	result = ApplFblNvReadDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num(&diagData[kDiagDidOffset]);
            	break;
            }

            /* F18B */
            case kFblDiagDidSoftwareApplicationNumber:
            {
            	result = ApplFblNvReadDID_F18B_FCA_ESLM_ECU_SW_App_Num(&diagData[kDiagDidOffset]);
            }
            	break;

            /* F18C */
            case kFblDiagDidEcuSerialNumber              :
            {
            	if(IsEOlDataAvailaible == TRUE)
            	{
            		(void)MEMCPY(&diagData[kDiagDidOffset], D_F18C_ECU_SERIAL_NUMBER_ADDRESS, kDiagRslDidEcuSerialNumber);
            	}
            	else
            	{
            		result = kFblFailed;
            	}
            	break;
            }

            /* F191 */
            case kFblDiagDidVehicleManufECUHwNo          :
            {
               result = ApplFblReadVehicleManufEcuHwNumber(&diagData[kDiagDidOffset]);
               break;
            }

            /* F192 */
            case kFblDiagDidSupplierManufECUHwPartNo      :
            {
            	if(IsEOlDataAvailaible == TRUE)
            	{
            		(void)MEMCPY(&diagData[kDiagDidOffset], D_F192_SUPPLIER_ECU_HARDWARE_PART_NUMBER_ADDRESS, kDiagRslDidSupplierManufECUHwPartNo);
            	}
            	else
            	{
            		result = kFblFailed;
            	}
            	break;
            }

            /* F193 */
            case kFblDiagDidSupplierManufECUHwVersionNo   :
            {
            	if(IsEOlDataAvailaible == TRUE)
            	{
            		(void)MEMCPY(&diagData[kDiagDidOffset], D_F193_SUPPLIER_ECU_HARDWARE_VERSION_NUMBER_ADDRESS, kDiagRslDidSupplierManufECUHwVersionNo);
            	}
            	else
            	{
            		result = kFblFailed;
            	}
               break;
            }

            /* F194 */
            case kFblDiagDidSupplierManufECUSwPartNo     :
            {
            	result = ApplFblNvReadDID_F194_Supplier_Ecu_SW_PartNum(&diagData[kDiagDidOffset]);
               break;
            }

            /* F195 */
            case kFblDiagDidSupplierManufECUSwVersionNo  :
            {
            	result = ApplFblNvReadDID_F195_Supplier_Ecu_SW_VerNum(&diagData[kDiagDidOffset]);
               break;
            }

            /* F196 */
            case kFblDiagDidExRegOrTypeApprovalNo        :
            {
               for (idx = 0; idx < kDiagRslDidExRegOrTypeApprovalNo; idx++)
               {
                  diagData[kDiagDidOffset + idx] = 0xAAu;
               }
               break;
            }

            /* F1A0 */
            case kFblDiagDidSystemIdentificationData     :
            {
            	 /* Send response pending in case of long NV accesses */
            	   DiagExRCRResponsePending(kForceSendResponsePending);

               idx = kDiagDidOffset;
               /*F187 */
               result = ApplFblNvReadCoDePEcuPartNumber(&diagData[idx]); /* F187 */

               idx += kDiagRslDidCodepEcuPartNo;

               /*F132*/
               result |= ApplFblNvReadEbomEcuPartNumber(&diagData[idx]);  /* F132 */

               idx += kDiagRslDidEbomEcuPartNo;

               /* F191 */
               result |= ApplFblReadVehicleManufEcuHwNumber(&diagData[idx]); /* F191 */

               idx += kDiagRslDidVehicleManufECUHwNo;

               /*F188 ASCII 11 bytes*/
               result |= ApplFblNvReadVehicleManufEcuSwNumber(&diagData[idx]); /*F188*/

               idx += kDiagRslDidCodepEcuPartNo;

               /*F18B ASCII 10 bytes*/
               result |= ApplFblNvReadDID_F18B_FCA_ESLM_ECU_SW_App_Num(&diagData[idx]); /*F18B*/

               idx += kDiagRslDidSoftwareApplicationNumber;

               /*F18A ASCII 10 bytes*/
               result |= ApplFblNvReadDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num(&diagData[idx]); /*F18A*/

               idx += kDiagRslDidECUSoftwareCalibrationNumber;

               /* F1B0 */
               /*TODO: Current VIN implementation pending*/
               for (j = 0; j < kDiagRslDidVinCurrent; j++)                          /* F1B0 */
               {
                  diagData[idx + j] = currentVIN[j];
               }

               idx += kDiagRslDidVinCurrent;

               /* F110 */
               result |= ApplFblReadEcuDiagnosticIdentification(&diagData[idx]); /* F110 */
               break;
            }

            /* F1A2 */
            case kFblDiagDidVectorDeliveryId             :
            {
               /* BSW (3 bytes) */
               diagData[kDiagDidOffset + 0u] = 0x28u;
               diagData[kDiagDidOffset + 1u] = 0x07u;
               diagData[kDiagDidOffset + 2u] = 0x12u;

               /* CBD (4 bytes)*/
               diagData[kDiagDidOffset + 3u] = 0x02u;
               diagData[kDiagDidOffset + 4u] = 0x10u;
               diagData[kDiagDidOffset + 5u] = 0x11u;
               diagData[kDiagDidOffset + 6u] = 0x46u;

               /* Vector Delivery Number (1 byte) */
               diagData[kDiagDidOffset + 7u] = 0x13u;

               /* ASR Revision (1 byte)*/
               diagData[kDiagDidOffset + 8u] = 0x04u;

               /* SLP (1 byte)*/
               diagData[kDiagDidOffset + 9u] = 0x05u;
               break;
            }

            /* F1A4 */
            case kFblDiagDidAlgorithmIdNumberReprog      :
            {
               diagData[kDiagDidOffset] = fblCommonData.algorithmIdNumber[0];
               diagData[kDiagDidOffset + 1u] = fblCommonData.algorithmIdNumber[1];
               break;
            }

            /* F1B3 */
            case kFblDiagDidBootSwFingerprintRead        :
            {
            	diagData[kDiagDidOffset] = kBlockTypeBootBlockCount; /* Number of Logical block - Bootloader*/
            	diagData[kDiagDidOffset +1u] = FBL_LBT_FBL_LB_BLOCK_INDEX;   /* Logical Block number */
            	result = ApplFblNvReadFingerprint(FBL_LBT_FBL_LB_BLOCK_NUMBER, &diagData[kDiagDidOffset+2u]);
            	break;
            }

            /* F1B4 */
            case kFblDiagDidApplSwFingerprintRead        :
            {
            	/* Send response pending for following NV-access */
            	DiagExRCRResponsePending(kForceSendRpIfNotInProgress);

            	/* Number of application software blocks */
            	diagData[kDiagDidOffset] = kBlockTypeCodeBlockCount;
            	uint8 Offset = 3;

            	FblLbtBlockFilterSetBlockType(&blockFilter, kBlockTypeCode);
            	iterBlock = FblLbtBlockFirst(&blockFilter);
            	while (FblLbtBlockDone() == FALSE)
            	{
            		diagData[Offset] = iterBlock.blockIndex;
            		Offset++;
            		result |= ApplFblNvReadFingerprint(iterBlock.blockNr, &diagData[Offset]);
            		Offset+=kApplInfoSizeFingerPrint;

            		/* Prepare next cycle */
            		iterBlock = FblLbtBlockNext();
            	}
               break;
            }
            /*F1B5*/
            case kFblDiagDidApplDataFingerprintRead      :
            {
            	/* Send response pending for following NV-access */
            	DiagExRCRResponsePending(kForceSendRpIfNotInProgress);

            	/* Number of application software blocks */
            	diagData[kDiagDidOffset] = kBlockTypeDataBlockCount;
            	uint8 Offset = 3;

            	FblLbtBlockFilterSetBlockType(&blockFilter, kBlockTypeData);
            	iterBlock = FblLbtBlockFirst(&blockFilter);
            	while (FblLbtBlockDone() == FALSE)
            	{
            		diagData[Offset] = iterBlock.blockIndex;
            		Offset++;
            		result |= ApplFblNvReadFingerprint(iterBlock.blockNr, &diagData[Offset]);
            		Offset+=kApplInfoSizeFingerPrint;
            		/* Prepare next cycle */
            		iterBlock = FblLbtBlockNext();
            	}

               break;
            }
            case kFblDiagDidEcuPkiUuid: /* 2951 */
            {
               DiagExRCRResponsePending(kForceSendRpIfNotInProgress);
               ApplFblNvReadUuid(FBL_LBT_SECURITY_CERT_LB_BLOCK_NUMBER, &diagData[kDiagDidOffset] );
               /*for (idx = 0; idx < kDiagRslDidEcuPkiUuid; idx++)
           	   {
           	       diagData[kDiagDidOffset + idx] = pki_uuid[idx];
           	   }*/
            	break;
            }
            /* DID: FD38 */
            case kFblDiagDidProgrammedAssembly:
            {
            	if(IsEOlDataAvailaible == TRUE)
            	{
            		(void)MEMCPY(&diagData[kDiagDidOffset], D_FD38_PROGRAMMED_ASSEMBLY_ADDRESS, kDiagRslDidProgrammedAssembly);
            	}
            	else
            	{
            		result = kFblFailed;
            	}
            	break;
            }
			   /* 0x2954 */
            case kFblDiagDidPolicyType :
            {
            	diagData[kDiagDidOffset]=CUSTOMER_INTENT_POLICY;
            }
            break;
			   /* 0x0108u */
            case kFblDiagDidActiveRole :
            {
            	uint32 TesterRole; 
               #ifdef FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED
            	if(0U==ADASuccessFlag)
            	{
            		TesterRole = (1u<<11u);
            	}
            	else
            	{
            		TesterRole =(1<<testerRole[0]);
            	}
               #else
               TesterRole = (1u<<11u);
               #endif
               diagData[kDiagDidOffset+0u] =(uint8)((TesterRole & 0xFF000000u) >> 24u);
               diagData[kDiagDidOffset+1u] =(uint8)((TesterRole & 0x00FF0000u) >> 16u);
               diagData[kDiagDidOffset+2u] =(uint8)((TesterRole & 0x0000FF00u) >> 8u);
               diagData[kDiagDidOffset+3u] =(uint8)((TesterRole & 0x000000FFu));

            }
            break;

            case kFblDiagDidAppSWHeaderInfo:   /*	2957	*/
            {
               vuint8 blockCount;
               DiagExRCRResponsePending(kForceSendResponsePending);
               ApplFblNvReadFileHeaderInfo(0u, &diagData[kDiagDidOffset]);
               ApplFblNvReadUuid(0u, &diagData[kDiagDidOffset+kApplInfoSizeFileHeaderInfo]);
               for(blockCount = 4u;blockCount < FBL_LBT_BLOCK_COUNT;blockCount++)
		         {
                  ApplFblNvReadFileHeaderInfo(blockCount, &diagData[(blockCount-3u)*kApplInfoSizeFileHeaderInfo+((blockCount-3u)*kApplInfoSizeUuid)+kDiagDidOffset]);
                  ApplFblNvReadUuid(blockCount, &diagData[(blockCount-2u)*kApplInfoSizeFileHeaderInfo+((blockCount-3u)*kApplInfoSizeUuid)+kDiagDidOffset]);
               }
               break;
            }

            case kFblDiagDidAppSWHeaderUuid:   /*	2958	*/
            {
               vuint8 blockCount;
               DiagExRCRResponsePending(kForceSendResponsePending);
               ApplFblNvReadUuid(0u, &diagData[kDiagDidOffset]);
               for(blockCount = 4u;blockCount < FBL_LBT_BLOCK_COUNT;blockCount++)
		         {
                  ApplFblNvReadUuid(blockCount, &diagData[(blockCount-3u)*kApplInfoSizeUuid+kDiagDidOffset]);
               }
               break;
            }

            case kFblDiagDidAppDataConfigInfo:  /*	2959	*/
            {
               DiagExRCRResponsePending(kForceSendResponsePending);
               ApplFblNvReadFileHeaderInfo(1u, &diagData[kDiagDidOffset]);
               ApplFblNvReadUuid(1u, &diagData[kDiagDidOffset+kApplInfoSizeFileHeaderInfo]);
               ApplFblNvReadFileHeaderInfo(2u, &diagData[kApplInfoSizeFileHeaderInfo+kApplInfoSizeUuid+kDiagDidOffset]);
               ApplFblNvReadUuid(2u, &diagData[(kApplInfoSizeFileHeaderInfo*2u)+kApplInfoSizeUuid+kDiagDidOffset]);
               break;
            }

            case kFblDiagDidAppDataHeaderUuid:  /*	295A	*/
            {
               ApplFblNvReadUuid(1u, &diagData[kDiagDidOffset]);
               ApplFblNvReadUuid(2u, &diagData[kApplInfoSizeUuid+kDiagDidOffset]);
               break;
            }

            case kFblDiagDidAppHtaHeaderInfo:  /*	295B	*/
            {
               ApplFblNvReadFileHeaderInfo(0u, &diagData[kDiagDidOffset]);
               break;
            }

            case kFblDiagDidAppHtaHeaderUuid:  /*	295C	*/
            {
               ApplFblNvReadUuid(0u, &diagData[kDiagDidOffset]);
               break;
            }

            case kFblDiagDidAppDCLHeaderUuid:  /*	295E	*/
            {
               ApplFblNvReadUuid(3u, &diagData[kDiagDidOffset]);
               break;
            }

            case kFblDiagDidAppDCLHeaderInfo:   /*	295F	*/
            {
               ApplFblNvReadFileHeaderInfo(3u, &diagData[kDiagDidOffset]);
               ApplFblNvReadUuid(3u, &diagData[kDiagDidOffset+kApplInfoSizeFileHeaderInfo]);
               break;
            }
            /*	2030	*/

            case kFblDiagDidAuthenticDiagPrevAccess:  
            {
               DiagExRCRResponsePending(kForceSendResponsePending);
               for (idx = 0; idx < kFblSizePreviousAccessList; idx++)
               {
                  MEMCPY(&diagData[((kApplInfoSizeIssuerName)*idx)+(kApplInfoSizeSerialNumber*(idx))+ kDiagDidOffset], &Fill_IssuerName_2030[0u], kApplInfoSizeIssuerNameOffset);
                  ApplFblNvReadIssuerName(idx,  &diagData[kApplInfoSizeIssuerNameOffset+(kApplInfoSizeIssuerName*(idx))+(kApplInfoSizeSerialNumber*(idx))+kDiagDidOffset]);
                  MEMCPY(&diagData[((kApplInfoSizeIssuerName)*(idx+1u))+(kApplInfoSizeSerialNumber*(idx))+kDiagDidOffset], &Fill_SerialNumber_2030[0u], kApplInfoSizeSerialNumberOffset);
                  ApplFblNvReadSerialNumber(idx,  &diagData[kApplInfoSizeSerialNumberOffset+((kApplInfoSizeIssuerName*(idx+1u)))+(kApplInfoSizeSerialNumber*(idx))+kDiagDidOffset]);
               }
               break;
            }

            case kFblDiagDidDisallowedCertList:  /*	2031	*/
            {
            	DiagExRCRResponsePending(kForceSendResponsePending);
                retval = Csm_RandomGenerate(CsmConf_CsmJob_CsmJob_ReadDCLEntries, &DCLEntries[0], &DCLlength);
                Data = &diagData[kDiagDidOffset];
                if(retval != E_NOT_OK)
                {
                    for (v_LoopIdx_CertInfo_u8 = 0 ; v_LoopIdx_CertInfo_u8 < 32; v_LoopIdx_CertInfo_u8++)
                    {
                       /* Set issuer name default value */
                       VStdLib_MemSet(&Data[(v_LoopIdx_CertInfo_u8*D_ISSUER_NAME_FULLSIZE)+(v_LoopIdx_CertInfo_u8*D_SERIAL_NUMBER_FULLSIZE)], 0x20, D_ISSUER_NAME_FULLSIZE);

                       /* Set serial number default value */
                       VStdLib_MemSet(&Data[((v_LoopIdx_CertInfo_u8 + 1)*D_ISSUER_NAME_FULLSIZE)+(v_LoopIdx_CertInfo_u8*D_SERIAL_NUMBER_FULLSIZE)], 0x00, D_SERIAL_NUMBER_FULLSIZE);
                    }

                    VStdLib_MemCpy(&Data[0], &DCLEntries[0], DCLlength);
                }
                else
                {
                    /* Do Nothing */
                }
               break;
            }

            case kFblDiagDidSecureLog:   /* 2032    */
            {

                /* Send response pending for following NV-access */
                DiagExRCRResponsePending(kForceSendRpIfNotInProgress);
                memset(&diagData[kDiagDidOffset],0x0,kDiagRslDidSecureLog);
                NvReadResult=ApplFblNvReadSecureLogGroup1(&SecureLogRecord_GroupOne);
                SecureLogRecord_GroupOne.Valid=(E_OK==NvReadResult)?TRUE:FALSE;
                NvReadResult=ApplFblNvReadSecureLogGroup2(&SecureLogRecord_GroupTwo);
                SecureLogRecord_GroupTwo.Valid=(E_OK==NvReadResult)?TRUE:FALSE;

                Data = &diagData[kDiagDidOffset];
            	Data[0] = SecureLogRecord_GroupOne.Valid;
            	Data[1u] = (uint8)RIGHTSHIFT_BIT(SecureLogRecord_GroupOne.GroupCnt, 24U);
            	Data[2u] = (uint8)RIGHTSHIFT_BIT(SecureLogRecord_GroupOne.GroupCnt, 16U);
            	Data[3u] = (uint8)RIGHTSHIFT_BIT(SecureLogRecord_GroupOne.GroupCnt, 8U);
            	Data[4u] = (uint8)SecureLogRecord_GroupOne.GroupCnt;

            	for(uint8 ndx = 0; ndx < D_RECORD_PER_GRP; ndx++)
            	{
            		Data[5u+D_LOG_ENTRY_EXPORT_SIZE*ndx] = D_RECORD_DATA_SIZE;
            		VStdLib_MemCpy(&Data[5u+D_LOG_ENTRY_EXPORT_SIZE*ndx+1u],SecureLogRecord_GroupOne.RecordEntry[ndx],D_RECORD_DATA_SIZE);
            		Csm_MacVerify(CsmConf_CsmJob_CsmJob_MacVerify,CRYPTO_OPERATIONMODE_SINGLECALL, (uint8*)SecureLogRecord_GroupOne.RecordEntry[ndx], D_RECORD_DATA_SIZE,
            				(uint8*)&SecureLogRecord_GroupOne.RecordEntry[ndx][D_RECORD_DATA_SIZE], D_CMAC_LEN, &verifyResult);
            		if(verifyResult == E_OK)
            		{
            			Data[5u+D_LOG_ENTRY_EXPORT_SIZE*ndx] |= 0x80;
            		}
            		else
            		{
            			/* do nothing */
            		}
            	}

            	Data[325u] = SecureLogRecord_GroupTwo.Valid;
            	Data[326u] = (uint8)RIGHTSHIFT_BIT(SecureLogRecord_GroupTwo.GroupCnt, 24U);
            	Data[327u] = (uint8)RIGHTSHIFT_BIT(SecureLogRecord_GroupTwo.GroupCnt, 16U);
            	Data[328u] = (uint8)RIGHTSHIFT_BIT(SecureLogRecord_GroupTwo.GroupCnt, 8U);
            	Data[329u] = (uint8)SecureLogRecord_GroupTwo.GroupCnt;

            	for(uint8 ndx = 0; ndx < D_RECORD_PER_GRP; ndx++)
            	{
            		Data[330u+D_LOG_ENTRY_EXPORT_SIZE*ndx] = D_RECORD_DATA_SIZE;
            		VStdLib_MemCpy(&Data[330u+D_LOG_ENTRY_EXPORT_SIZE*ndx+1u],SecureLogRecord_GroupTwo.RecordEntry[ndx],D_RECORD_DATA_SIZE);
            		Csm_MacVerify(CsmConf_CsmJob_CsmJob_MacVerify,CRYPTO_OPERATIONMODE_SINGLECALL, (uint8*)SecureLogRecord_GroupTwo.RecordEntry[ndx], D_RECORD_DATA_SIZE,
            				(uint8*)&SecureLogRecord_GroupTwo.RecordEntry[ndx][D_RECORD_DATA_SIZE], D_CMAC_LEN, &verifyResult);
            		if(verifyResult == E_OK)
            		{
            			Data[330u+D_LOG_ENTRY_EXPORT_SIZE*ndx] |= 0x80;
            		}
            		else
            		{
            			/* do nothing */
            		}
            	}
            	break;
            }

            case kFblDiagDidSecurityStatus:   /*	100C	*/
            {
               uint32 TesterRole; 
               /*Get security status*/
               #ifdef FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED
               securityState_u8 = ApplFblGetAuthenticationState();
               #else
               securityState_u8 = FblDiagGetSecurityUnlock();
               #endif
               diagData[kDiagDidOffset] = securityState_u8;

               #ifdef FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED
               if(0U==ADASuccessFlag)
               {
            	   TesterRole = (1u<<11u);
               }
               else
               {
            	   TesterRole =(1<<testerRole[0]);
               }
               #else
               TesterRole = (1u<<11u);
               #endif
               diagData[kDiagDidOffset+1u] =(uint8)((TesterRole & 0xFF000000u) >> 24u);
               diagData[kDiagDidOffset+2u] =(uint8)((TesterRole & 0x00FF0000u) >> 16u);
               diagData[kDiagDidOffset+3u] =(uint8)((TesterRole & 0x0000FF00u) >> 8u);
               diagData[kDiagDidOffset+4u] =(uint8)((TesterRole & 0x000000FFu));

               break;
            }

            case kFblDiagDidPublicCertRegion:  /*	F111	*/
            {
               diagData[kDiagDidOffset]=REST_OF_WORLD;
               break;
            }

            case kFblDiagDidBootFailureReason:  /*	201F	*/
            {
               vuint8 BlockFlahStatus[10];
               vuint8 varTemp1=0x00;
               vuint8 varTemp2=0x00;
               vuint8 varTempContainer=0x00;
               DiagExRCRResponsePending(kForceSendResponsePending);
               for (idx = 0u; idx < 10u ; idx++)
               {
                  ApplFblNvReadFlashStatus(idx, &BlockFlahStatus[idx]);
               }

               /* Bit0: Logical block 0: FBL (Bit always set to 0)
                * Bit1: Logical block 4: MCU10_Application_LB
                * Bit2: Logical block 5: LateApp1_MCU20_MCU21_LB
                * Bit3: Logical block 6: AtfOptee_LB
                * Bit4: Logical block 7: IfsQNX_LB
                * Bit5: Logical block 8: C7x_LB */
               for (idx = MCU10_APPLICATION_LB_BLOCK_NUMBER; idx <= C7X_LB_BLOCK_NUMBER; idx++)
               {
                  if (BlockFlahStatus[idx] == 1u)
                  {

                     varTempContainer |=((BlockFlahStatus[idx] << (idx-3u)) & 0xFF);
                     varTemp1 |=varTempContainer;
                     
                  }
                  varTempContainer=0x00;
               }

               /* Bit6: Logical block 1: CAL_LB
                * Bit7: Logical block 2: ExtendedKeyRing */
               for (idx = CAL_LB_BLOCK_NUMBER; idx <= EXTENDEDKEYRING_BLOCK_NUMBER; idx++)
               {
                  varTempContainer=0x00;
                  if (BlockFlahStatus[idx] == 1u)
                  {
                     varTempContainer |=((BlockFlahStatus[idx] << (idx+5u)) & 0xFF);
                     varTemp2 |=varTempContainer;
                     
                  }
                  varTempContainer=0x00;
               }
               varTemp1 |=varTemp2;
               
               diagData[kDiagDidOffset] = varTemp1;
               /* Bit8: Logical block 3: Security_Cert_LB */
               ApplFblNvReadFlashStatus(SECURITY_CERT_LB_BLOCK_NUMBER, &diagData[kDiagDidOffset+1u]);

               break;
            }

            default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
            {
               break;
            }
         } /* switch (currentDid) */
         outIdx += outIdxAdd;
      } /* if (outIdxAdd != 0u) */
      i++;
   }

   if (result != kFblOk)
   {
      /* Data could not be read successfully from NVM */
      DiagNRCConditionsNotCorrect();
   }
   else if (outIdx == 0u)
   {
      DiagNRCRequestOutOfRange();
   }
   else
   {
      /* No error occured - send positive response */
   }

   diagRespDataLen = outIdx;

   /* Transmit response message:
    * If a negative response has to be transmitted, the length parameter is
    * ignored. In case of a positive response, the length parameter does not
    * include the service id. */
   DiagProcessingDone(diagRespDataLen);

/* PRQA S 6050, 6080 1 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  ApplDiagWriteDataByIdentifier
 **********************************************************************************************************************/
/*! \brief         WriteDataByIdentifier service function.
 *  \param[in,out] pbDiagData Pointer to diag service data (after SID!)
 *  \param[in]     diagReqDataLen Service data length (without SID!)
 *  \return        Success of operation
 **********************************************************************************************************************/
/* PRQA S 3673, 6030, 6080 1 */ /* MD_FblKbApi_3673, MD_MSR_STCYC, MD_MSR_STMIF */
vuint8 ApplFblWriteDataByIdentifier( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
   /* Two-byte routine identifier */
   vuint16 diagFmtDataId;
   vuint8 result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

   /* Initialize variables */
   result = kFblOk; /* PRQA S 2982 */ /* MD_FblKbApiOem_2982_2983 */

   /* Read two-byte routineControlId (minimum length already checked) */
   /* PRQA S 2983 2 */ /* MD_FblKbApiOem_2982_2983 */
   diagFmtDataId =  (vuint16)pbDiagData[0] << 8;
   diagFmtDataId |= (vuint16)pbDiagData[1];  /* PRQA S 3199 */ /* MD_FblKbApiOem_3199 */

   switch (diagFmtDataId) /* PRQA S 3315 */ /* MD_FblKbApiOem_3315 */
   {
      default:
      {
         DiagNRCRequestOutOfRange();
         result = kFblFailed;
         break;
      }
   }

   return result;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

#if defined( FBL_DIAG_ENABLE_CLEAR_DIAGNOSTIC_INFORMATION )
/***********************************************************************************************************************
 *  ApplFblClearDiagnosticInformation
 **********************************************************************************************************************/
/*! \brief         Service function clear diagnostic trouble codes
 *  \param[in,out] pbDiagData Pointer to diag service data (after service ID)
 *  \param[in]     diagReqDataLen Service data length (without service ID)
 *  \return        kFblOk: service processed successfully, kFblFailed: Service processing failed.
 **********************************************************************************************************************/
tFblResult ApplFblClearDiagnosticInformation( vuint8 *pbDiagData, tTpDataType diagReqDataLen )
{
   tFblResult result;

   if (  (pbDiagData[kDiagLocFmtSubparam] == 0xFFu)
      && (pbDiagData[kDiagLocFmtSubparam + 1u] == 0xFFu)
      && (pbDiagData[kDiagLocFmtSubparam + 2u] == 0xFFu))
   {
      DiagProcessingDone(kDiagRslClearDiagInfo);
      result = kFblOk;
   }
   else
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }

   return result;
}
#endif /* FBL_DIAG_ENABLE_CLEAR_DIAGNOSTIC_INFORMATION */

/***********************************************************************************************************************
 *  ApplFblReportDTCByStatusMask
 **********************************************************************************************************************/
/*! \brief         Read DTC by status mask service function
 *  \param[in,out] pbDiagData Pointer to diag service data (after service ID)
 *  \param[in]     diagReqDataLen Service data length (without service ID)
 *  \return        Read result
 **********************************************************************************************************************/
tFblResult ApplFblReportDTCByStatusMask( vuint8* pbDiagData, tTpDataType diagReqDataLen )
{
   tFblResult result;

   vuint16 diagRespDataLen;
   vuint8 dtcMask;

   /* Output pointer */
   vuint8* diagData;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif /* V_ENABLE_USE_DUMMY_STATEMENT */
   result = kFblOk;

   /* Initialize Response data length */
   diagRespDataLen = 0x02u;
   dtcMask = pbDiagData[1u];
   diagData = &pbDiagData[2u];

   if (((ApplFblGetApplStatus() == kApplValid) && (MCU1_0_AuthFailStatus == FALSE)) && (flashStatBuffer[0x00] == 0xFF))
   {
      /* If the application is valid send response with no DTCs */
      pbDiagData[1u] = 0xFFu;
   }
   else
   {
      if ((kDiagDtcStatus & dtcMask) != 0x00u)
      {
         diagData[0] = (vuint8)((kDiagDtc_NotProgrammedCodeInternal >> 16u) & 0xFFu);
         diagData[1] = (vuint8)((kDiagDtc_NotProgrammedCodeInternal >> 8u) & 0xFFu);
         diagData[2] = (vuint8)(kDiagDtc_NotProgrammedCodeInternal & 0xFFu);
         diagData[3] = kDiagDtcStatus;

         diagRespDataLen += 4u;
      }
   }

   DiagProcessingDone(diagRespDataLen);
   return result;
}

#if defined( FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED )
/***********************************************************************************************************************
 *  ApplFblSecAccessRequestChallenge
 **********************************************************************************************************************/
/*! \brief         Service function for SecurityAccess - requestSeed (authenticated reprogramming)
 *  \param[in,out] pbDiagData Pointer to diag service data (after service ID)
 *  \param[in]     diagReqDataLen Service data length (without service ID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
vuint8 certStatus;
vuint32 certStatusLen = 4;
uint8 SeedLength = kSecAuthPrgChallengeLength;

tFblResult ApplFblSecAccessRequestChallenge( vuint8* pbDiagData, tTpDataType diagReqDataLen )
{
   tFblResult result = kFblFailed;
   SecM_StatusType secResult;
   uint8 CertSerNum[FBL_ADA_CERT_SERIALNUMBER_LEN] = {0};
   uint32 SerialNumLen = FBL_ADA_CERT_SERIALNUMBER_LEN;
   vuint8 certElementId[2];
   uint8 localSeed[kSecAuthPrgChallengeLength] = {0};
   tFblAuthenticationState AuthState = kFblAnonymous;

   AuthState = ApplFblGetAuthenticationState();

   /* Security access delay timing */
   if (secSecurityAccessDelay > 0u)
   {
      /* Delay timer not expired */
      DiagNRCRequiredTimeDelayNotExpired();
   }
   else if(AuthState == kFblAuthenticated)
   {
      /* Copy all 0s into the diagnostic buffer for the response */
      /* PRQA S 0314 2*/ /* MD_FblKbApiFrame_0314_0315 */
      (void)MEMCPY(&diagChallengeBuffer[kSecAuthPrgNonceLength], localSeed, kSecAuthPrgChallengeLength);
      (void)MEMCPY(&pbDiagData[kDiagLocFmtReqChallengeChallenge], &diagChallengeBuffer[kSecAuthPrgNonceLength], kSecAuthPrgChallengeLength);
      result = kFblOk;
   }
   else
   {
      /* Reset authentication state in case of new ADA request */
      ApplFblSetAuthenticationState(kFblAnonymous);
      /* Set Current time and second counter in HSM */
      Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_CurrentTimeStamp,CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_CryptoKeyElement_CurrentTimeStamp,SystemTime,15);
      Csm_KeySetValid(CsmConf_CsmKey_CsmKey_CurrentTimeStamp);
      Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_SecondCounter,CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_CryptoKeyElement_SecondCounter,&SecondCounter,4);
      Csm_KeySetValid(CsmConf_CsmKey_CsmKey_SecondCounter);
      /* Set the new certificate */

      Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_KeyMCertificate_ADA_L4, CryptoConf_CryptoKeyElement_Crypto_30_vHsm_KeyM_KeyM_Certificate, &pbDiagData[kDiagLocFmtReqChallengeCert], diagReqDataLen - 1uL);
      Csm_KeySetValid(CsmConf_CsmKey_CsmKey_KeyMCertificate_ADA_L4);
      /* Check certificate verification result */
      secResult = SecM_AuthDiag_Certificate_GetStatus(&certStatus, &certStatusLen);
      if (secResult == SECM_OK)
      {
         switch(certStatus)
         {
            case KEYM_CERTIFICATE_VALID :
            {
               (void)Csm_RandomGenerate(CsmConf_CsmJob_CsmJob_TRNGGen,localSeed, &SeedLength);
               /* Copy the generated challenge into the diagnostic buffer for the response */
               /* PRQA S 0314 2*/ /* MD_FblKbApiFrame_0314_0315 */
               (void)MEMCPY(&diagChallengeBuffer[kSecAuthPrgNonceLength], localSeed, kSecAuthPrgChallengeLength);
               (void)MEMCPY(&pbDiagData[kDiagLocFmtReqChallengeChallenge], &diagChallengeBuffer[kSecAuthPrgNonceLength], kSecAuthPrgChallengeLength);
               result = kFblOk;
               break;
            }
            case KEYM_E_CERTIFICATE_REVOKED :
            {
               DiagNRCRevokedKey();
               /* Create string ID with the correct field ID for Serial Number */
               FblMemSetInteger(2u, FBL_ADA_CERT_SERIALNUMBER_ID, certElementId);
               Smh_GetCertificateElement_ADACert(SECM_OPERATIONMODE_SINGLECALL, certElementId, sizeof(certElementId), NULL_PTR, 0u, CertSerNum, &SerialNumLen, NULL_PTR, NULL_PTR);
               /*Log Cert Serial no. as failed event*/
               SecureLogEvent(AUTHNTICATION_FAILURE, No_SUB_TYPE, CertSerNum);
               break;
            }
            case KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL:
            {
               DiagNRCExpiredKey();
               /* Create string ID with the correct field ID for Serial Number */
               FblMemSetInteger(2u, FBL_ADA_CERT_SERIALNUMBER_ID, certElementId);
               Smh_GetCertificateElement_ADACert(SECM_OPERATIONMODE_SINGLECALL, certElementId, sizeof(certElementId), NULL_PTR, 0u, CertSerNum, &SerialNumLen, NULL_PTR, NULL_PTR);
               /*Log Cert Serial no. as failed event*/
               SecureLogEvent(AUTHNTICATION_FAILURE, No_SUB_TYPE, CertSerNum);
               break;
            }
            default :
            {
               /* For any other error send the NRC Invalid Key */
               DiagNRCInvalidKey();
               /* Create string ID with the correct field ID for Serial Number */
               FblMemSetInteger(2u, FBL_ADA_CERT_SERIALNUMBER_ID, certElementId);
               Smh_GetCertificateElement_ADACert(SECM_OPERATIONMODE_SINGLECALL, certElementId, sizeof(certElementId), NULL_PTR, 0u, CertSerNum, &SerialNumLen, NULL_PTR, NULL_PTR);
               /*Log Cert Serial no. as failed event*/
               SecureLogEvent(AUTHNTICATION_FAILURE, No_SUB_TYPE, CertSerNum);
               break;
            }
         }
      }
      else
      {
          /* For any other error send the NRC Invalid Key */
          DiagNRCInvalidKey();
      }
   }

   if (result == kFblFailed)
   {
      if ((DiagGetError() == kDiagNrcRevokedKey) || (DiagGetError() == kDiagNrcExpiredKey))
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
      else
      {
         /* Do nothing */
      }

      /* In case of failure the eventual loaded certificate shall be removed */
      ApplFblInvalidateCertificate();
      /* Reset ADA status*/
      ADASuccessFlag=0U;

   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblSecAccessSendSignedChallenge
 **********************************************************************************************************************/
/*! \brief         Service function for SecurityAccess - sendSeed (authenticated reprogramming)
 *  \param[in,out] pbDiagData Pointer to diag service data (after service ID)
 *  \param[in]     diagReqDataLen Service data length (without service ID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
tFblResult ApplFblSecAccessSendSignedChallenge( vuint8* pbDiagData, tTpDataType diagReqDataLen )
{
   tFblResult result;

   SecM_SignatureParamType verifyChallenge;

	uint8 CertSerNum[FBL_ADA_CERT_SERIALNUMBER_LEN] = {0};
	uint32 SerialNumLen = FBL_ADA_CERT_SERIALNUMBER_LEN;
    vuint8 certElementId[2];

# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   /* PRQA S 0314 1*/ /* MD_FblKbApiFrame_0314_0315 */
   (void)MEMCPY(diagChallengeBuffer, &pbDiagData[kDiagLocFmtSendSignedChallengeNonce], kSecAuthPrgNonceLength);
   verifyChallenge.currentHash.sigResultBuffer = (SecM_ResultBufferType)SEC_DEFAULT_WORKSPACE; /* PRQA S 0306 */ /* MD_FblKbApiFrame_0306 */
   verifyChallenge.currentHash.length = SEC_DEFAULT_WORKSPACE_SIZE;
   verifyChallenge.currentDataLength = V_NULL;
   verifyChallenge.sigSourceBuffer = diagChallengeBuffer;
   verifyChallenge.sigByteCount = kSecAuthPrgNonceLength + kSecAuthPrgChallengeLength;
   verifyChallenge.wdTriggerFct = (FL_WDTriggerFctType)FblRealTimeSupport; /* PRQA S 0313 */ /* MD_FblKbApiFrame_0313_WDTriggerFctType */
   verifyChallenge.key = V_NULL;

   result = kFblOk;

   verifyChallenge.sigState = SEC_HASH_INIT;
   if (SecM_AuthDiag_Certificate_VerifySign(&verifyChallenge) != SECM_VER_OK)
   {
      result = kFblFailed;
   }

   if (result == kFblOk)
   {
      verifyChallenge.sigState = SEC_HASH_COMPUTE;
      if (SecM_AuthDiag_Certificate_VerifySign(&verifyChallenge) != SECM_VER_OK)
      {
         result = kFblFailed;
      }
   }

   if (result == kFblOk)
   {
      verifyChallenge.sigState = SEC_HASH_FINALIZE;
      if (SecM_AuthDiag_Certificate_VerifySign(&verifyChallenge) != SECM_VER_OK)
      {
         result = kFblFailed;
      }
   }

   if (result == kFblOk)
   {
      verifyChallenge.sigState = SEC_SIG_VERIFY;
      verifyChallenge.sigSourceBuffer = &pbDiagData[kDiagLocFmtSendSignedChallengeSignature];
      verifyChallenge.sigByteCount = SEC_SIZE_SIG_RSA2048;
      if (SecM_AuthDiag_Certificate_VerifySign(&verifyChallenge) != SECM_VER_OK)
      {
         result = kFblFailed;
      }
      else
      {
         vuint32 testerRoleDatalength = FBL_ADA_CERT_TESTERROLE_LEN;
         vuint8 serialNumber[FBL_ADA_CERT_SERIALNUMBER_LEN];
         vuint32 serialNumberDatalength = FBL_ADA_CERT_SERIALNUMBER_LEN;
         vuint8 IssuerName[FBL_ADA_CERT_ISSUERNAME_LEN];
         vuint32 IssuerNameDatalength = FBL_ADA_CERT_ISSUERNAME_LEN;
         /* Role can be extracted as an example. The customer can
          * use this information for further checks.
          */
         /* Check if the last session was terminated due to expiry of the same received certificate  */
         result = ApplFblSaveCertTimeInfo();
         if(result == kFblOk)
         {
             /* Create string ID with the correct field ID (i.e. 21 for tester role) */
             FblMemSetInteger(2u, FBL_ADA_CERT_TESTERROLE_ID, certElementId);
             /* Extract tester role field. Tester role can be used then for further checks. */
             if (Smh_GetCertificateElement_ADACert(SECM_OPERATIONMODE_SINGLECALL, certElementId, sizeof(certElementId), NULL_PTR, 0u, testerRole, &testerRoleDatalength, NULL_PTR, NULL_PTR) == SECM_OK)
             {
                /* Create string ID with the correct field ID (i.e. 1 for serial number) */
                FblMemSetInteger(2u, FBL_ADA_CERT_SERIALNUMBER_ID, certElementId);
        		 if (Smh_GetCertificateElement_ADACert(SECM_OPERATIONMODE_SINGLECALL, certElementId, sizeof(certElementId), NULL_PTR, 0u, serialNumber, &serialNumberDatalength, NULL_PTR, NULL_PTR) == SECM_OK)
        		 {
                ApplFblStoreCertSerialNumber(serialNumber);
                /* Create string ID with the correct field ID for issuer name */
                FblMemSetInteger(2u, FBL_ADA_CERT_ISSUERNAME_ID, certElementId);
                /* Extract the issuer name in NVM */
                if (Smh_GetCertificateElement_ADACert(SECM_OPERATIONMODE_SINGLECALL, certElementId, sizeof(certElementId), NULL_PTR, 0u, IssuerName, &IssuerNameDatalength, NULL_PTR, NULL_PTR) == SECM_OK)
                {
                   ApplFblStoreCertIssuerName(IssuerName);
                   /* Reset certificate validation timer */
                   tmrCertValid = 0u;
                   /* Challenge successfull. Store the result */
                   ApplFblSetAuthenticationState(kFblAuthenticated);
                   /* Store the serial number in NVM */
                   ADASuccessFlag=1U;
                   /* Set ADA status to Success*/

        			 }
        			 else
        			 {
        				 result = kFblFailed;
        			 }
                }
                else
                {
                   result = kFblFailed;
                }
             }
             else
             {
                result = kFblFailed;
             }
         }
         else
         {
            result = kFblFailed;
         }
      }
   }

   if (result == kFblFailed)
   {
	  /* Create string ID with the correct field ID for issuer name */
	  FblMemSetInteger(2u, FBL_ADA_CERT_SERIALNUMBER_ID, certElementId);
	  Smh_GetCertificateElement_ADACert(SECM_OPERATIONMODE_SINGLECALL, certElementId, sizeof(certElementId), NULL_PTR, 0u, CertSerNum, &SerialNumLen, NULL_PTR, NULL_PTR);
	  /*Log Cert Serial no. as failed event*/
	  SecureLogEvent(AUTHNTICATION_FAILURE, No_SUB_TYPE, CertSerNum);
      /* Remove certificate */
      ApplFblInvalidateCertificate();
      /* Return Invalid Key NRC */
      DiagNRCInvalidKey();
      /* Reset ADA status*/
      ADASuccessFlag=0U;
   }

   return result;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/***********************************************************************************************************************
 *  ApplFblAuthenticationTimerTask
***********************************************************************************************************************/
/*! \brief       Function triggered every 1 ms for time evaluation of certificate validation
 *  \return      void
**********************************************************************************************************************/
void ApplFblAuthenticationTimerTask(void)
{
   KeyM_CertificateStatusType status = 0u;
   SecM_WordType statusLength = 1u;

   if (!FblMainGetStartFromAppl())
   {
      /* Increase verification timer */
      tmrCertValid++;

      if (tmrCertValid == FBL_APPL_ADA_CERT_VALIDATION_TIMER)
      {
         /* Run certificate validation */
         (void)SecM_AuthDiag_Certificate_SetVerify(&status, statusLength);
         if (SecM_AuthDiag_Certificate_GetStatus(&status, &statusLength) == SECM_OK)
         {
            if (status != SECM_OK)
            {
               /* If the certificate in invalid remove authentication flag */
               ApplFblSetAuthenticationState(kFblAnonymous);
            }
         }
         /* Reset the timer */
         tmrCertValid = 0u;
      }
   }
}

/***********************************************************************************************************************
 *  ApplFblSetAuthenticationState
***********************************************************************************************************************/
/*! \brief       Sets the current state of the authentication
 *  \param[in]   authState Authentication state
 *  \return      void
**********************************************************************************************************************/
void ApplFblSetAuthenticationState(tFblAuthenticationState authState)
{
   vuint8 authBuf;

   authBuf = (vuint8)authState;
   /* Store the authentication state */
   (void)SecM_AuthDiag_SetStatus(&authBuf, 1u);
}
/***********************************************************************************************************************
 *  ApplFblGetAuthenticationState
 **********************************************************************************************************************/
/*! \brief        Gets the current state of the authentication
 *  \return       kFblAuthenticated: Authentication was performed succesfully, kFblAnonymous else
 **********************************************************************************************************************/
tFblAuthenticationState ApplFblGetAuthenticationState(void)
{
   tFblAuthenticationState authState = kFblAnonymous;

   vuint8 authBuf;
   vuint32 authBufLen = 1u;

   if (SecM_AuthDiag_GetStatus(&authBuf, &authBufLen) == SECM_OK)
   {
      if (authBuf == (vuint8)kFblAuthenticated)
      {
         authState = kFblAuthenticated;
      }
   }

   return authState;
}
#endif /* FBL_DIAG_ENABLE_SECACCESS_AUTHENTICATED */

/***********************************************************************************************************************
 *  ApplFblCSRTrigger
 **********************************************************************************************************************/
/*! \brief        Triggers the certificate signing request
 *  \return       kFblOk: CSR trigger was successful, kFblFailed: otherwise
 **********************************************************************************************************************/
tFblResult ApplFblCSRTrigger(void)
{
   /* TODO customer: implement handling to trigger CSR */

   return kFblFailed;
}

#if defined( FBL_ENABLE_DEBUG_STATUS )
/***********************************************************************************************************************
 *  ApplFblInitErrStatus
 **********************************************************************************************************************/
/*! \brief       Initialize error status information.
 **********************************************************************************************************************/
void ApplFblInitErrStatus( void )
{
   errStatFlashDrvVersion[0u] = 0u;
   errStatFlashDrvVersion[1u] = 0u;
   errStatFlashDrvVersion[2u] = 0u;
   errStatFlashDrvErrorCode = 0u;
   errStatErrorCode = 0u;
   errStatFblStates = 0u;
   errStatLastServiceId = 0u;
   errStatDescriptor.blockNr = 0;
   errStatDescriptor.blockStartAddress = 0;
}
#endif

/* module specific MISRA deviations:
   MD_FblKbApiFrame_0306:
     Reason: Address conversion between integer values and pointers is required to allow for hardware independent configuration and address range checks.
     Risk: The size of integer required to hold the result of a pointer cast is implementation-defined.
     Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware specific basis.
   MD_FblKbApiFrame_0313_WDTriggerFctType:
      Reason: Security module expects a watchdog handler with return type 'void'. The usage of a wrapper function is
              avoided due to higher voted requirements for minimized stack and runtime usage applied on the code.
      Risk: Potentially undefined behavior of the used compiler which usually leads to a warning or error during
            compilation.
      Prevention: The respective functionality is part of integration testing and will hence be verified before delivery.
   MD_FblKbApiFrame_0314_0315:
      Reason: Type conversion to void * is necessary to use the standard MEMCPY API
      Risk: No identifiable risk.
      Prevention: No prevention required.
   MD_FblKbApiFrame_2889:
      Reason:     Using multiple return paths makes this function more readable
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiFrame_3218_FileScopeStatic:
      Reason:     Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk:       Unintended use of object in wrong scope.
      Prevention: Architectural pattern supports prevention of incorrect use of objects in wrong context.
                  Code inspection focus on correct use of objects.

   MD_FblKbApiFrame_3219:
      Reason:     The function is used only for some configurations and can be in the future extended to other use case.
      Risk:       The function is never used.
      Prevention: Function effective usage shall be determined during code review and testing.

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
 *  END OF FILE: FBL_APDI.C
 **********************************************************************************************************************/
