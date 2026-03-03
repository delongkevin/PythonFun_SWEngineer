/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  CDD_CryptoMgr.c
 *           Config:  D:/CVADAS/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  CDD_CryptoMgr
 *  Generation Time:  2024-12-03 16:36:45
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <CDD_CryptoMgr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * ADAStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_OpStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_ServiceIdType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_CDD_CryptoMgr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Enums.h"
#include "vstdlib.h"
#include "Crypto_30_vHsm.h"
#include "Csm.h"
#include "Dcm.h"
#include "NvM.h"
#include "vDiagSecAcc.h"
#include "vDiagSecAcc_Cbk.h"
#include "SecurityAccess.h"

#define D_DID_2032_DATA_LEN  (1296u)
#define D_DID_2031_DATA_LEN  (1536u)
#define D_DID_2951_DATA_LEN (16u)
#define D_DID_2957_DATA_LEN (1056u)
#define D_DID_2958_DATA_LEN (96u)
#define D_DID_2959_DATA_LEN (352u)
#define D_DID_295A_DATA_LEN (32u)
#define D_DID_295B_DATA_LEN (176u)
#define D_DID_295C_DATA_LEN (16u)
#define D_DID_295E_DATA_LEN (16u)
#define D_DID_295F_DATA_LEN (176u)
#define D_F111_CHINA_MAINLAND (16u)
#define CUSTOMER_INTENT_POLICY (4u)
#define WITHOUT_AUTHENTICATION (0x00u)
#define WITH_AUTHENTICATION (0x01u)
#define D_BLANK_ASCII (0x20u)
#define D_DEFAULT_SN (0x00u)
#define D_DEFAULT_ASCII (0x00u)
#define D_CMAC_LEN (16u)
#define REGION_CHINA (0x01u)
#define REGION_REST_OF_WORLD (0x04u)
#define MAX_SEC_INVALID_COUNT (21U)
#define SEC_DIAG_DEFAULT_ROLE (0x800u)
#define D_SYSTEM_TIME_LENGTH 15U
#define D_RECORD_PER_GRP (10u)
#define D_REC_STORAGE_SIZE (48u)
#define D_SEC_NUM_SIZE    (2u)
#define D_TIMESTAMP_SIZE  (4u)
#define D_EVENT_TYPE_SIZE (1u)
#define D_SUB_TYPE_SIZE   (1u)
#define D_EVENT_DATA_SIZE (23u)

#define D_RECORD_DATA_SIZE (D_SEC_NUM_SIZE + D_TIMESTAMP_SIZE + D_EVENT_TYPE_SIZE + D_SUB_TYPE_SIZE + D_EVENT_DATA_SIZE)

#define D_SEC_NUM_POS     (0u)
#define D_TIMESTAMP_POS   (D_SEC_NUM_POS + D_SEC_NUM_SIZE)
#define D_EVENT_TYPE_POS  (D_TIMESTAMP_POS + D_TIMESTAMP_SIZE)
#define D_SUB_TYPE_POS    (D_EVENT_TYPE_POS + D_EVENT_TYPE_SIZE)
#define D_EVENT_DATA_POS  (D_SUB_TYPE_POS + D_SUB_TYPE_SIZE)
/* below macro Kept For future use case */
/*
 * #define D_CMAC_POS        (D_EVENT_DATA_POS + D_EVENT_DATA_SIZE)
 */

#define D_LOG_ENTRY_EXPORT_SIZE (D_RECORD_DATA_SIZE + 1u)

/* Below Values are defined as per vector bootloader code */
#define SEC_DELAY_ACTIVE          (0xA7u)
#define SEC_DELAY_INACTIVE        (0xFFu)

/* NRC for Revoked and Expired Key */
#define DCM_E_REVOKED_KEY (0xFAu)
#define DCM_E_EXPIRED_KEY (0xFBu)

/* KeyM Certificate Status  */
#  define KEYM_CERTIFICATE_VALID                                      (0x00u)
#  define KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL                     (0x05u)
#  define KEYM_E_CERTIFICATE_INVALID_TYPE                             (0x08u)
#  define KEYM_E_CERTIFICATE_REVOKED                                  (0x0Bu)


/* Formula: Delay timer = 2 ^ n seconds (* 1000 as we need this value in milliseconds) */
# define CRYPTO_SEC_DELAY_TIMEOUT(Invalid_Count) ((((uint32)1u << (Invalid_Count)) * 1000u) / DCM_TASK_CYCLE_MS)
# define CRYPTO_INVERT_8_BIT(x)         ((uint8) ((x) ^ ((uint8)0xFFu)))
#define D_FILEHEADER_UUID_SIZE (16u)
#define D_FILEHEADER_INFO_UUID_SIZE (176u)
#define D_FILEHEADER_INFO_SIZE (160u)

#define D_ISSUER_NAME_FULLSIZE (64u)
#define D_SERIAL_NUMBER_FULLSIZE (32u)
#define D_ISSUER_NAME_SIZE (26u)
#define D_SERIAL_NUMBER_SIZE (20u)
#define D_CERTACCESSINFO_RECORDS (10u)
#define D_CERTACCESSINFO_SIZE ((D_ISSUER_NAME_SIZE*D_CERTACCESSINFO_RECORDS)+(D_SERIAL_NUMBER_SIZE*D_CERTACCESSINFO_RECORDS))

/** Module specific magic numbers **/
#define THREE_TWENTY_FIVE  325u
#define THREE_TWENTY_SIX   326u
#define THREE_TWENTY_SEVEN 327u
#define THREE_TWENTY_EIGHT 328u
#define THREE_TWENTY_NINE  329u
#define THREE_THIRTY  330u
#define VALID_BIT_MASK 0x80u
#define INVALID_SYSTEM_TIME 0xFFu
#define UTC_OR_GENERALIZED_TIME_LAST_BYTE_Z 0x5Au
#define SYSTEM_TIME_DATA_ELEMENT_LENGTH 13u
#define FOURTY_EIGHT 48u
#define CSM_SIGNATURE_LENGTH 64u
#define D_KEY_ELEMENT_LENGTH 2U
#define D_SIGNATURE_INPUT_LENGTH 256u
#define THIRTY_TWO_BYTE 32u
#define D_SIGN_LENGTH 32u
#define ADA_CERTIFICATE_LENGTH 1536u
#define SECOND_COUNTER_LENGTH 4u
/***********************************/

typedef enum
{
  AUTHNTICATION_FAILURE = 1,
  FAILED_AUTHORIZATION_ATTEMPTS = 2,
  UNAUTHORIZED_ACCESS = 7,
  CYBERSEC_FAILURE = 8,
  NO_FAILED_EVENT = 0xFF
} EventType;

typedef enum
{
  No_SUB_TYPE = 0,
  /*
   * below Enum Values are used in Boot Mananger and FBL to report Cybersecurity failures
   * SEC_BOOT_FAILURE =1,
   * SEC_FLASHING_FAILURE =2,
   * CERTIFICATE_FAILURE =3,
   */
}EventSubType;

typedef struct
{
  uint8 fileHeaderInfo_au8[D_FILEHEADER_INFO_SIZE];
  uint8 fileHeaderUuid_au8[D_FILEHEADER_UUID_SIZE];
} fileHeader_t;

typedef struct
{
  uint8 IssuerName_au8[D_ISSUER_NAME_SIZE];
  uint8 SerialNumber_au8[D_SERIAL_NUMBER_SIZE];
} CertAccessInfo_t;

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

static fileHeader_t s_fileHeader_Arr_as[e_NINE];
static uint8 v_fileHeaderCounter_u8 = (uint8)e_ZERO;

static CertAccessInfo_t s_CertAccessInfo_Arr_as[e_TEN];
static uint8 v_CertAccessInfoCounter_u8 = (uint8)e_ZERO;

static uint8 v_2030_CertAccess_issuer_u8[D_ISSUER_NAME_SIZE*D_CERTACCESSINFO_RECORDS] ;
static uint8 v_2030_CertAccess_SerialNo_u8[D_SERIAL_NUMBER_SIZE*D_CERTACCESSINFO_RECORDS];

static uint8 v_2951_secfileHeaderUuid_u8[D_DID_2951_DATA_LEN];
static uint8 v_2957_swfileHeaderInfo_u8[D_DID_2957_DATA_LEN];
static uint8 v_2958_swfileHeaderUuid_u8[D_DID_2958_DATA_LEN];
static uint8 v_2959_datafileHeaderInfo_u8[D_DID_2959_DATA_LEN];
static uint8 v_295A_datafileHeaderUuid_u8[D_DID_295A_DATA_LEN];
static uint8 v_295B_HTAHeaderInfo_u8[D_DID_295B_DATA_LEN];
static uint8 v_295C_HTAHeaderUuid_u8[D_DID_295C_DATA_LEN];
static uint8 v_295F_secfileHeaderInfo_u8[D_DID_295F_DATA_LEN];
static uint8 v_295E_secfileHeaderUuid_u8[D_DID_295E_DATA_LEN];

VAR(SecureLogRecord_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP)Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_Mirror_Copy;
VAR(SecureLogRecord_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP)Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_Mirror_Copy;


static SecureLogRecord_t SecureLogRecord_Group1 = {0};
static SecureLogRecord_t SecureLogRecord_Group2 = {0};
static uint32 Secure_Delay_Timer = 0U;
static boolean Secure_Delay_Timer_Flag = FALSE;
static boolean InvalidCount_NvMWrite_Flag = FALSE;
static boolean DelayFlag_NvMWrite_Flag = FALSE;
static boolean Security_Status_Flag = FALSE;
static boolean Session_Timeout_Flag;
static uint8 Invalid_Count = 0U;
static uint8 Delay_Flag = SEC_DELAY_INACTIVE;
static uint32 SecDiagCurrentRole = SEC_DIAG_DEFAULT_ROLE;

static volatile EventType FailedEvent = NO_FAILED_EVENT;
uint8 CertSerNum[D_EVENT_DATA_SIZE] = {0};
VAR(uint8, CSM_VAR_INIT) Csm_InputData_ADASigVeri[CSM_SIGNATURE_LENGTH]={0};

uint8 SystemTime[D_SYSTEM_TIME_LENGTH] = {0};
static boolean IsSystemTimeSet = FALSE;
static uint32 TimestampCounter = 0u;
static uint32 NotAfterEpochFormat = 0u;
static uint32 SessionSecondCounter = 0u;
uint32 SecondCounter = 0u;
uint8 KeyElementID[D_KEY_ELEMENT_LENGTH]={0};
uint8 CurrentRole[D_KEY_ELEMENT_LENGTH]={0};
uint32 CurrentRoleLen = 1U;
uint8 SerialNum[D_SERIAL_NUMBER_SIZE] = {0};
uint32 SerialNumLen = D_SERIAL_NUMBER_SIZE;
uint8 IssuerName[D_ISSUER_NAME_SIZE]= {0};
uint32 IssuerNameLen = D_ISSUER_NAME_SIZE;
uint8 NotBeforeTime[D_SYSTEM_TIME_LENGTH] = {0};
uint32 NotBeforeTimeLen = D_SYSTEM_TIME_LENGTH;
uint8 NotAfterTime[D_SYSTEM_TIME_LENGTH]={0};
uint32 NotAfterTimeLen = D_SYSTEM_TIME_LENGTH;
static boolean CertificateExpired = FALSE;
static boolean CheckCertSessionValid = FALSE;
uint8 DCLEntries[D_DID_2031_DATA_LEN] = {0};


static void f_logEvent_v(const EventType Event, const EventSubType SubEvent, const uint8* EventData);

static SecureLogRecord_t * getEventGroup(const EventType Event, uint8* GrpId);

static uint32 getTimeStamp(void);

static void TimeStampIncrement(void);

static Std_ReturnType getEpochTime(const uint8* LocSystemTime, uint32* LocTimestampCounter);

static void CheckAuthCertiValidity(void);

static void f_UpdateTesterCertElements_v(void);
static void f_UpdateADAFailedAttempt_v(void);
static Std_ReturnType ParseUTCGeneralizedTime(P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) timeElementPtr,
                                       uint16 timeElementDataLength,
                                       P2VAR(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) parsedTimePtr);

static Std_ReturnType ConvertDateToUnixTime(P2CONST(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) date, P2VAR(uint32, AUTOMATIC, AUTOMATIC) unixTime);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * ADAStatusType: Integer in interval [0...255]
 * Dcm_OpStatusType: Integer in interval [0...64]
 * NvM_RequestResultType: Integer in interval [0...8]
 * NvM_RequestResultType: Integer in interval [0...255]
 * NvM_ServiceIdType: Integer in interval [6...12]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * Array_04Byte: Array with 4 element(s) of type uint8
 * Array_10Byte: Array with 10 element(s) of type uint8
 * Array_11Byte: Array with 11 element(s) of type uint8
 * Array_15Bytes: Array with 15 element(s) of type uint8
 * Dcm_Data1056ByteType: Array with 1056 element(s) of type uint8
 * Dcm_Data1296ByteType: Array with 1296 element(s) of type uint8
 * Dcm_Data16ByteType: Array with 16 element(s) of type uint8
 * Dcm_Data176ByteType: Array with 176 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data2ByteType: Array with 2 element(s) of type uint8
 * Dcm_Data3072ByteType: Array with 3072 element(s) of type uint8
 * Dcm_Data32ByteType: Array with 32 element(s) of type uint8
 * Dcm_Data352ByteType: Array with 352 element(s) of type uint8
 * Dcm_Data4ByteType: Array with 4 element(s) of type uint8
 * Dcm_Data5ByteType: Array with 5 element(s) of type uint8
 * Dcm_Data960ByteType: Array with 960 element(s) of type uint8
 * Dcm_Data96ByteType: Array with 96 element(s) of type uint8
 * Rte_DT_SecureLogRecord_t_4: Array with 10 element(s) of type Rte_DT_SecureLogRecord_t_4_0
 * Rte_DT_SecureLogRecord_t_4_0: Array with 48 element(s) of type uint8
 *
 * Record Types:
 * =============
 * ME_Hydra2defs_S_CodingTableExt_t: Record with elements
 *   bValid of type boolean
 *   ConfigCode of type Array_11Byte
 *   TesterCode of type Array_10Byte
 *   ProductionDate of type Array_04Byte
 *   CanNode14trscm_uint8 of type uint8
 *   Variant_ID of type uint8
 *   CanNode27Asm_uint8 of type uint8
 *   CanNode63ttm_uint8 of type uint8
 *   CanNode67dtcm_uint8 of type uint8
 *   CanNode95itcm_uint8 of type uint8
 *   StopandStart of type uint8
 *   DriverSide of type uint8
 *   Tyresize_uint16 of type uint16
 *   Wheelbase of type uint8
 *   Rearviewcamera of type uint8
 *   Parkwithstop of type uint8
 *   SteeringRatio_uint8 of type uint8
 *   Gearboxtype of type uint8
 *   Drivetypevariant of type uint8
 *   Pamtuningset of type uint8
 *   Semiautopark of type uint8
 *   VehicleLineConfiguration_uint8 of type uint8
 *   CountryCode_uint8 of type uint8
 *   Srt of type uint8
 *   PAMConfig_uint8 of type uint8
 *   ModelYear_uint8 of type uint8
 *   Hybridtype of type uint8
 *   Pulloutcontrol of type uint8
 *   Surroundviewcamera of type uint8
 *   Forwardfacingcamera of type uint8
 *   Autonomylevel of type uint8
 *   Fullautomaticparking of type uint8
 *   Radiodisplay of type uint8
 *   Mirrortype of type uint8
 *   Auxiliarycamera of type uint8
 *   Trailerreverseguide of type uint8
 *   Trailersurround of type uint8
 *   Trailerreversesteering of type uint8
 *   Trailerhitchassist of type uint8
 *   CVPAM_Presence_uint8 of type uint8
 *   SideDistanceWarning of type uint8
 *   PROXIWriteCounter of type uint8
 * SecureLogRecord_t: Record with elements
 *   Valid of type uint8
 *   RecId of type uint8
 *   SecId of type uint16
 *   GroupCnt of type uint32
 *   RecordEntry of type Rte_DT_SecureLogRecord_t_4
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   SecureLogRecord_t *Rte_Pim_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_MirrorBlock(void)
 *   SecureLogRecord_t *Rte_Pim_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_MirrorBlock(void)
 *   uint32 *Rte_Pim_NvMBlockDescriptor_SecondCounter_MirrorBlock(void)
 *   uint8 *Rte_Pim_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_MirrorBlock(void)
 *   uint8 *Rte_Pim_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_MirrorBlock(void)
 *   boolean *Rte_Pim_NvMBlockDescriptor_CertificateExpired_MirrorBlock(void)
 *   uint8 *Rte_Pim_NvMBlockDescriptor_SystemTimestamp_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Array_15Bytes
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint32 Rte_CData_NvMBlockDescriptor_SecondCounter_DefaultValue(void)
 *   uint8 Rte_CData_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_DefaultValue(void)
 *   uint8 Rte_CData_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_DefaultValue(void)
 *   boolean Rte_CData_NvMBlockDescriptor_CertificateExpired_DefaultValue(void)
 *   uint8 *Rte_CData_NvMBlockDescriptor_SystemTimestamp_DefaultValue(void)
 *     Returnvalue: uint8* is of type Array_15Bytes
 *   SecureLogRecord_t *Rte_CData_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_DefaultValue(void)
 *   SecureLogRecord_t *Rte_CData_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_DefaultValue(void)
 *
 *********************************************************************************************************************/


#define CDD_CryptoMgr_START_SEC_CODE
#include "CDD_CryptoMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {1E5C9F41-2B38-40e1-953D-07120248D6AD}*/
	(void)OpStatus;
	Std_ReturnType ret = E_NOT_OK;
	if (NULL_PTR != Data)
	{
        Data[e_ZERO] =(uint8)((SecDiagCurrentRole & (uint32)FOURTH_BYTE_MASK) >> (uint32)BIT_SHIFT_TWENTYFOUR_BIT);
        Data[e_ONE] =(uint8)((SecDiagCurrentRole &(uint32) THIRD_BYTE_MASK) >> (uint32)BIT_SHIFT_SIXTEEN_BIT);
        Data[e_TWO] =(uint8)((SecDiagCurrentRole & (uint32)SECOND_BYTE_MASK) >> (uint32)BIT_SHIFT_EIGHT_BIT);
        Data[e_THREE] =(uint8)((SecDiagCurrentRole & (uint32)FIRST_BYTE_MASK));
		ret = RTE_E_OK;
	}
	else
	{
		/*Do nothing */
	}

	return ret;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22100C_Security_Status_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22100C_Security_Status_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22100C_Security_Status_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data5ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22100C_Security_Status_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22100C_Security_Status_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22100C_Security_Status_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22100C_Security_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22100C_Security_Status_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {00D7A7C7-F7BB-4467-8B13-739FFDED981E}*/
	(void)OpStatus;
	Std_ReturnType ret = E_NOT_OK;

	if (NULL_PTR != Data)
	{
	  if((boolean)TRUE==Security_Status_Flag)
	  {
		  Data[e_ZERO]= WITH_AUTHENTICATION;
	  }
	  else
	  {
		  Data[e_ZERO]= WITHOUT_AUTHENTICATION;
	  }
      Data[e_ONE] =(uint8)((SecDiagCurrentRole & (uint32)FOURTH_BYTE_MASK) >> (uint32)BIT_SHIFT_TWENTYFOUR_BIT);
      Data[e_TWO] =(uint8)((SecDiagCurrentRole & (uint32)THIRD_BYTE_MASK) >> (uint32)BIT_SHIFT_SIXTEEN_BIT);
      Data[e_THREE] =(uint8)((SecDiagCurrentRole & (uint32)SECOND_BYTE_MASK) >> (uint32)BIT_SHIFT_EIGHT_BIT);
      Data[e_FOUR] =(uint8)((SecDiagCurrentRole & (uint32)FIRST_BYTE_MASK));
	  ret = RTE_E_OK;
	}
	else
	{
		/*Do nothing */
	}

	return ret;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22201F_Boot_Failure_Reason_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22201F_Boot_Failure_Reason_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22201F_Boot_Failure_Reason_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {00062B86-18C4-4dc2-9E0C-ED6BA7E9D04F}*/
  (void)OpStatus;
  uint16 v_FlashStatus_u16;
  (void)Rte_Read_RpFlashSts_v_FlashSts_u16(&v_FlashStatus_u16);
  /* Lower byte from v_FlashStatus_u16 contains Secure flash/secure boot failure status for FBL logical blocks so
  it is typecasted with uint8 and single byte is used as per DID implementation */
  Data[e_ZERO]=(uint8)v_FlashStatus_u16;

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data960ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {3E40B93E-251C-4e92-9495-B4695470B684}*/
  /* ReqID:-  */
  (void)OpStatus;
  Std_ReturnType v_retVal_u8 =RTE_E_DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_E_NOT_OK ;
  uint16 v_LoopIdx_CertInfo_u16;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    for (v_LoopIdx_CertInfo_u16=(uint16)e_ZERO ; v_LoopIdx_CertInfo_u16 < (uint16)e_TEN; v_LoopIdx_CertInfo_u16++)
    {
      /* Previous Certificate: Access Issuer name */
      VStdLib_MemSet(&Data[((v_LoopIdx_CertInfo_u16*(uint16)D_ISSUER_NAME_FULLSIZE)+(v_LoopIdx_CertInfo_u16*(uint16)D_SERIAL_NUMBER_FULLSIZE))], D_BLANK_ASCII, D_ISSUER_NAME_FULLSIZE);
      VStdLib_MemCpy(&Data[((v_LoopIdx_CertInfo_u16*(uint16)D_ISSUER_NAME_FULLSIZE)+(v_LoopIdx_CertInfo_u16*(uint16)D_SERIAL_NUMBER_FULLSIZE)+((uint16)D_ISSUER_NAME_FULLSIZE-(uint16)D_ISSUER_NAME_SIZE))], &v_2030_CertAccess_issuer_u8[(v_LoopIdx_CertInfo_u16*(uint16)D_ISSUER_NAME_SIZE)], D_ISSUER_NAME_SIZE);

      /* Previous Certificate: Access Serial Number */
      VStdLib_MemSet(&Data[(((v_LoopIdx_CertInfo_u16+(uint16)e_ONE)*(uint16)D_ISSUER_NAME_FULLSIZE)+(v_LoopIdx_CertInfo_u16*(uint16)D_SERIAL_NUMBER_FULLSIZE))], D_DEFAULT_SN, D_SERIAL_NUMBER_FULLSIZE);
      VStdLib_MemCpy(&Data[(((v_LoopIdx_CertInfo_u16+(uint16)e_ONE)*(uint16)D_ISSUER_NAME_FULLSIZE)+(v_LoopIdx_CertInfo_u16*(uint16)D_SERIAL_NUMBER_FULLSIZE)+((uint16)D_SERIAL_NUMBER_FULLSIZE-(uint16)D_SERIAL_NUMBER_SIZE))], &v_2030_CertAccess_SerialNo_u8[(uint16)(v_LoopIdx_CertInfo_u16*(uint16)D_SERIAL_NUMBER_SIZE)], D_SERIAL_NUMBER_SIZE);
    }

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    /* Do Nothing */
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_222031_Disallowed_Certificate_List_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3072ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_222031_Disallowed_Certificate_List_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_222031_Disallowed_Certificate_List_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {3EE9EE99-0685-4484-8C27-B68CF5F9B2ED}*/

  Std_ReturnType v_retVal_u8 = RTE_E_DataServices_Data_222031_Disallowed_Certificate_List_Read_E_NOT_OK;
  uint16 v_LoopIdx_CertInfo_u8;
  uint32 DCLlength = D_DID_2031_DATA_LEN;
  (void)OpStatus;

  if(NULL_PTR != Data)
  {
	  v_retVal_u8 = Csm_RandomGenerate(CsmConf_CsmJob_CsmJob_ReadDCLEntries, &DCLEntries[0], &DCLlength);

	  if(v_retVal_u8 != (Std_ReturnType)E_NOT_OK)
	  {
		  for (v_LoopIdx_CertInfo_u8=(uint16)e_ZERO ; v_LoopIdx_CertInfo_u8 < (uint16)e_THIRTY_TWO; v_LoopIdx_CertInfo_u8++)
		  {
			  /* Set issuer name default value */
			  VStdLib_MemSet(&Data[(v_LoopIdx_CertInfo_u8*(uint16)D_ISSUER_NAME_FULLSIZE)+(v_LoopIdx_CertInfo_u8*(uint16)D_SERIAL_NUMBER_FULLSIZE)], D_DEFAULT_ASCII, D_ISSUER_NAME_FULLSIZE);

			  /* Set serial number default value */
			  VStdLib_MemSet(&Data[((v_LoopIdx_CertInfo_u8+(uint16)e_ONE)*(uint16)D_ISSUER_NAME_FULLSIZE)+(v_LoopIdx_CertInfo_u8*(uint16)D_SERIAL_NUMBER_FULLSIZE)], D_DEFAULT_SN, D_SERIAL_NUMBER_FULLSIZE);
		  }

		  VStdLib_MemCpy(&Data[ZEROTH_BYTE], &DCLEntries[ZEROTH_BYTE], DCLlength);

		  v_retVal_u8 = RTE_E_OK;
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

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_222032_Secure_Log_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_222032_Secure_Log_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_222032_Secure_Log_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1296ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_222032_Secure_Log_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_222032_Secure_Log_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222032_Secure_Log_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222032_Secure_Log_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222032_Secure_Log_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {FCBC5B0D-DDB6-48fd-9BE1-86B40AED835D}*/
	Std_ReturnType v_retVal_u8 = RTE_E_DataServices_Data_222032_Secure_Log_Read_E_NOT_OK;
	Crypto_VerifyResultType verifyResult = E_NOT_OK;
    uint16 ndx;
    (void)OpStatus;
    if(NULL_PTR != Data)
    {
	VStdLib_MemClr(&Data[ZEROTH_BYTE],D_DID_2032_DATA_LEN);
	Data[ZEROTH_BYTE] = SecureLogRecord_Group1.Valid;
	Data[FIRST_BYTE] = (uint8)RIGHTSHIFT_BIT(SecureLogRecord_Group1.GroupCnt, BIT_SHIFT_TWENTYFOUR_BIT);
	Data[SECOND_BYTE] = (uint8)RIGHTSHIFT_BIT(SecureLogRecord_Group1.GroupCnt, BIT_SHIFT_SIXTEEN_BIT);
	Data[THIRD_BYTE] = (uint8)RIGHTSHIFT_BIT(SecureLogRecord_Group1.GroupCnt, BIT_SHIFT_EIGHT_BIT);
	Data[FOURTH_BYTE] = (uint8)SecureLogRecord_Group1.GroupCnt;

	for(ndx = 0; ndx < (uint16)D_RECORD_PER_GRP; ndx++)
	{
	  Data[FIFTH_BYTE+(D_LOG_ENTRY_EXPORT_SIZE*ndx)] = D_RECORD_DATA_SIZE;
	  VStdLib_MemCpy(&Data[(uint16)(FIFTH_BYTE+(D_LOG_ENTRY_EXPORT_SIZE*ndx)+1u)], SecureLogRecord_Group1.RecordEntry[ndx],D_RECORD_DATA_SIZE);
	  (void)Csm_MacVerify(CsmConf_CsmJob_CsmJob_SecureLog_MacVerify,CRYPTO_OPERATIONMODE_SINGLECALL, (uint8*)SecureLogRecord_Group1.RecordEntry[ndx], D_RECORD_DATA_SIZE,
	                (uint8*)&SecureLogRecord_Group1.RecordEntry[ndx][D_RECORD_DATA_SIZE], D_CMAC_LEN, &verifyResult);
	  /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if(verifyResult == (Crypto_VerifyResultType)E_OK)
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
	  {
	    Data[FIFTH_BYTE+(D_LOG_ENTRY_EXPORT_SIZE*ndx)] |= (uint8)VALID_BIT_MASK;
	  }
	  else
	  {
	    /* do nothing */
	  }
	}

	Data[THREE_TWENTY_FIVE] = SecureLogRecord_Group2.Valid;
	Data[THREE_TWENTY_SIX] = (uint8)RIGHTSHIFT_BIT(SecureLogRecord_Group2.GroupCnt, BIT_SHIFT_TWENTYFOUR_BIT);
	Data[THREE_TWENTY_SEVEN] = (uint8)RIGHTSHIFT_BIT(SecureLogRecord_Group2.GroupCnt, BIT_SHIFT_SIXTEEN_BIT);
	Data[THREE_TWENTY_EIGHT] = (uint8)RIGHTSHIFT_BIT(SecureLogRecord_Group2.GroupCnt, BIT_SHIFT_EIGHT_BIT);
	Data[THREE_TWENTY_NINE] = (uint8)SecureLogRecord_Group2.GroupCnt;

	for(ndx = 0; ndx <(uint16) D_RECORD_PER_GRP; ndx++)
	{
	  Data[(uint16)(THREE_THIRTY+(D_LOG_ENTRY_EXPORT_SIZE*ndx))] = D_RECORD_DATA_SIZE;
	  VStdLib_MemCpy(&Data[(uint16)(THREE_THIRTY+(D_LOG_ENTRY_EXPORT_SIZE*ndx)+1u)],SecureLogRecord_Group2.RecordEntry[ndx],D_RECORD_DATA_SIZE);
	  (void)Csm_MacVerify(CsmConf_CsmJob_CsmJob_SecureLog_MacVerify,CRYPTO_OPERATIONMODE_SINGLECALL, (uint8*)SecureLogRecord_Group2.RecordEntry[ndx], D_RECORD_DATA_SIZE,
	                (uint8*)&SecureLogRecord_Group2.RecordEntry[ndx][D_RECORD_DATA_SIZE], D_CMAC_LEN, &verifyResult);
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
	  if(verifyResult == (Crypto_VerifyResultType)E_OK)
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
	  {
	    Data[(uint16)(THREE_THIRTY+(D_LOG_ENTRY_EXPORT_SIZE*ndx))] |= (uint8)VALID_BIT_MASK;
	  }
	  else
	  {
	    /* do nothing */
	  }
	}
    	v_retVal_u8 = RTE_E_OK;
    }
    else
    {
    	/* Do Nothing */
    }

	return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_222951_Certificate_Store_UUID_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data16ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_222951_Certificate_Store_UUID_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_222951_Certificate_Store_UUID_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {22887979-2EF6-4b5c-8685-B60525319E3F}*/
 Std_ReturnType v_retVal_u8 = RTE_E_DataServices_Data_222951_Certificate_Store_UUID_Read_E_NOT_OK;
 (void)OpStatus;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    VStdLib_MemCpy(Data, &v_2951_secfileHeaderUuid_u8[(uint8)e_ZERO], D_DID_2951_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
	  /* Do Nothing */
  }

  return v_retVal_u8;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_222954_Policy_Type_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_222954_Policy_Type_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_222954_Policy_Type_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_222954_Policy_Type_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_222954_Policy_Type_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222954_Policy_Type_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222954_Policy_Type_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222954_Policy_Type_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {52777128-909E-40de-B8A4-19BF57FAE387}*/
  (void)OpStatus;
  Data[e_ZERO] = (uint8)CUSTOMER_INTENT_POLICY;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1056ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {6F5E08AA-FE87-437e-BF3D-01565170D81F}*/
  /* ReqID:-  */
Std_ReturnType v_retVal_u8 = RTE_E_DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_E_NOT_OK;
  (void)OpStatus;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send LB 0 to 6 Application Software File Header Information */
    VStdLib_MemCpy(Data, &v_2957_swfileHeaderInfo_u8[(uint8)e_ZERO], D_DID_2957_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
	  /* Do Nothing */
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data96ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {13F9DAAD-2DF7-496c-9310-ABE962B0D12B}*/
  /* ReqID:-  */
Std_ReturnType v_retVal_u8 = RTE_E_DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_E_NOT_OK;
  (void)OpStatus;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send LB 0 to 5 Application Software File Header Uuid */
    VStdLib_MemCpy(Data, &v_2958_swfileHeaderUuid_u8[(uint8)e_ZERO], D_DID_2958_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
	  /* Do Nothing */
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data352ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {02858709-5E88-4010-BB54-E04B23DB36AD}*/
  /* ReqID:-  */
Std_ReturnType v_retVal_u8 = RTE_E_DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_E_NOT_OK;
  (void)OpStatus;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send LB 6 and 7 Application Software File Header Information */
    VStdLib_MemCpy(Data, &v_2959_datafileHeaderInfo_u8[(uint8)e_ZERO], D_DID_2959_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    /* Do Nothing */
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data32ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {6C914B32-5945-48e9-B108-ED0B5AC57B91}*/
  Std_ReturnType v_retVal_u8 = RTE_E_DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_E_NOT_OK;
  (void)OpStatus;


  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send LB 6 and 7 Application Software File Header Uuid */
    VStdLib_MemCpy(Data, &v_295A_datafileHeaderUuid_u8[(uint8)e_ZERO], D_DID_295A_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
	  /* Do Nothing */
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22295B_HTA_Header_Info_Read
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22295B_HTA_Header_Info_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22295B_HTA_Header_Info_Read(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data176ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22295B_HTA_Header_Info_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22295B_HTA_Header_Info_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22295B_HTA_Header_Info_Read_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295B_HTA_Header_Info_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22295B_HTA_Header_Info_Read (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {F249FAD7-EEC4-471a-BC84-2909E3D8E5B1}*/
  Std_ReturnType v_retVal_u8 = RTE_E_DataServices_Data_22295B_HTA_Header_Info_Read_E_NOT_OK;
  (void)OpStatus;
  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send LB 0 File Header Information */
    VStdLib_MemCpy(Data, &v_295B_HTAHeaderInfo_u8[(uint8)e_ZERO], D_DID_295B_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
	  /* Do Nothing */
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22295C_HTA_Header_UUID_Read
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22295C_HTA_Header_UUID_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22295C_HTA_Header_UUID_Read(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data16ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22295C_HTA_Header_UUID_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22295C_HTA_Header_UUID_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22295C_HTA_Header_UUID_Read_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295C_HTA_Header_UUID_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22295C_HTA_Header_UUID_Read (returns application error)
 *********************************************************************************************************************/
 /* DD-ID: {163685CC-1D10-4e6a-92DF-EDE23FE5E9A2}*/
  Std_ReturnType v_retVal_u8 = RTE_E_DataServices_Data_22295C_HTA_Header_UUID_Read_E_NOT_OK;
  (void)OpStatus;
  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send LB 0 File Header Information */
    VStdLib_MemCpy(Data, &v_295C_HTAHeaderUuid_u8[(uint8)e_ZERO], D_DID_295C_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    /* Do Nothing */
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22295E_DCL_Header_UUID_Read
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22295E_DCL_Header_UUID_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22295E_DCL_Header_UUID_Read(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data16ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22295E_DCL_Header_UUID_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22295E_DCL_Header_UUID_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22295E_DCL_Header_UUID_Read_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295E_DCL_Header_UUID_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22295E_DCL_Header_UUID_Read (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {082F2A22-111B-4000-9799-9A34EB8D3C4B}*/
  Std_ReturnType v_retVal_u8 = RTE_E_DataServices_Data_22295E_DCL_Header_UUID_Read_E_NOT_OK;
  (void)OpStatus;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send LB 8 Application Software File Header Uuid */
    VStdLib_MemCpy(Data, &v_295E_secfileHeaderUuid_u8[(uint8)e_ZERO], D_DID_295E_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    /* Do Nothing */
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data176ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {018F851A-9E2F-48c7-9486-BC0578875C7D}*/
  /* ReqID:-  */

  Std_ReturnType v_retVal_u8=RTE_E_DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_E_NOT_OK;
  (void)OpStatus;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send LB 8 Application Software File Header Information */
    VStdLib_MemCpy(Data, &v_295F_secfileHeaderInfo_u8[(uint8)e_ZERO], D_DID_295F_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    /* Do Nothing */
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F111_Public_Certificates_Regional_Support_Read>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RpProxiConfigData_ProxiData(ME_Hydra2defs_S_CodingTableExt_t *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {3493164F-31F3-4109-8C3F-3C0DFEE7C859}*/
	Std_ReturnType v_retVal_u8 = RTE_E_DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_E_NOT_OK;
	(void)OpStatus;
	ME_Hydra2defs_S_CodingTableExt_t ProxiConfigData = {0};

	(void)Rte_Read_RpProxiConfigData_ProxiData(&ProxiConfigData);
	if (NULL_PTR != Data)
	{
		Data[e_ZERO] = ((uint8)D_F111_CHINA_MAINLAND == ProxiConfigData.CountryCode_uint8) ? REGION_CHINA : REGION_REST_OF_WORLD;
		v_retVal_u8 = RTE_E_OK;
	}
	else
	{
		/*Do nothing */
	}

	return v_retVal_u8;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CryptoArray_CryptoArray
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CryptoArray> of PortPrototype <PpCryptoArray>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RE_CryptoArray_CryptoArray(uint8 *CertPtr, uint16 CertLen)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CryptoArray_CryptoArray_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_CryptoMgr_CODE) RE_CryptoArray_CryptoArray(P2VAR(uint8, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) CertPtr, uint16 CertLen) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CryptoArray_CryptoArray
 *********************************************************************************************************************/
  /* DD-ID: {58C0DC21-A7E2-4074-8F24-CDAA76107FF4}*/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CryptoMgr_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_DS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_SetDataIndex(uint8 DataIndex)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_DS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DS_FileHeader_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_DS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DS_FileHeader_SetDataIndex(uint8 DataIndex)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_DS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CryptoMgr_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_CryptoMgr_CODE) RE_CryptoMgr_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CryptoMgr_Init
 *********************************************************************************************************************/
  /* DD-ID: {E6369FB1-3A92-42f6-AC65-961656F6E151}*/

	uint8 LocalInvalidCnt;
	uint32 Local_Secure_Delay_Timer;
	LocalInvalidCnt=*Rte_Pim_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_MirrorBlock();
	Delay_Flag=*Rte_Pim_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_MirrorBlock();

    VStdLib_MemCpyLarge(&SystemTime[0],&Rte_CDD_CryptoMgr_NvMBlockDescriptor_SystemTimestamp_MirrorBlock[0], D_SYSTEM_TIME_LENGTH);
    SecondCounter = *Rte_Pim_NvMBlockDescriptor_SecondCounter_MirrorBlock();
    CertificateExpired = *Rte_Pim_NvMBlockDescriptor_CertificateExpired_MirrorBlock();

    /* Check if System time was successfully parsed and has some value saved in NvM */
    if(SystemTime[0] != (uint8)INVALID_SYSTEM_TIME)
    {
        IsSystemTimeSet = TRUE;
        /* Store latest system time in epoch format in TimestampCounter */
        (void)getEpochTime(&SystemTime[0], &TimestampCounter);
    }
    else
    {
    	/* Do Nothing */
    }
    Invalid_Count = CRYPTO_INVERT_8_BIT(LocalInvalidCnt);
	if((uint8)SEC_DELAY_ACTIVE == Delay_Flag)
	{
		Local_Secure_Delay_Timer = CRYPTO_SEC_DELAY_TIMEOUT(Invalid_Count);
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */ 
		if(sizeof(Secure_Delay_Timer)<= Local_Secure_Delay_Timer)
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
		{
			Secure_Delay_Timer=CRYPTO_SEC_DELAY_TIMEOUT(Invalid_Count); /* Calculate delay timer */
			Secure_Delay_Timer_Flag=TRUE;  /*Start Delay Timer*/
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

	/*Read the File Header data directly from the Nvm starting with zero index*/
  (void)Rte_Call_NvMService_AC3_SRBS_DS_FileHeader_SetDataIndex(v_fileHeaderCounter_u8);
  (void)Rte_Call_NvMService_AC3_SRBS_DS_FileHeader_ReadBlock(&s_fileHeader_Arr_as[v_fileHeaderCounter_u8]);

 	/*Read the Certificate Access Info data directly from the Nvm starting with zero index*/
  (void)Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_SetDataIndex(v_CertAccessInfoCounter_u8);
  (void)Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_ReadBlock(&s_CertAccessInfo_Arr_as[v_CertAccessInfoCounter_u8]);

	/*Read Secure Logs from NvM*/
  (void)Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup1_ReadBlock(&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_Mirror_Copy);
  (void)Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup2_ReadBlock(&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_Mirror_Copy);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CryptoMgr_Main
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RpFlashSts_v_FlashSts_u16(uint16 *data)
 *   Std_ReturnType Rte_Read_RpProxiConfigData_ProxiData(ME_Hydra2defs_S_CodingTableExt_t *data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_DS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup1_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup1_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup1_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup2_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup2_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup2_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SecAccessDelayFlag_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SecAccessDelayFlag_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SecAccessInvalidCount_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SecAccessInvalidCount_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CryptoMgr_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_CryptoMgr_CODE) RE_CryptoMgr_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CryptoMgr_Main
 *********************************************************************************************************************/
  /* DD-ID: {01777C8E-7921-419e-B9B7-611171F86BD5}*/
	NvM_RequestResultType ErrorStatus = NVM_REQ_NOT_OK;
	NvM_RequestResultType InvalidCount_ErrStatus = NVM_REQ_NOT_OK;
	NvM_RequestResultType DelayFlag_ErrStatus = NVM_REQ_NOT_OK;
	uint8 LocalInvalidCnt;

	(void)Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup1_GetErrorStatus(&ErrorStatus);
	if((NvM_RequestResultType)NVM_REQ_PENDING!=ErrorStatus)
	{
	  VStdLib_MemCpy(&SecureLogRecord_Group1,&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_Mirror_Copy,sizeof(SecureLogRecord_Group1));
	  SecureLogRecord_Group1.Valid=((NvM_RequestResultType)NVM_REQ_OK==ErrorStatus)?(uint8)TRUE:(uint8)FALSE;
	}
	else
	{
		/* Do nothing */
	}
	(void)Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup2_GetErrorStatus(&ErrorStatus);
	if((NvM_RequestResultType)NVM_REQ_PENDING!=ErrorStatus)
	{
	  VStdLib_MemCpy(&SecureLogRecord_Group2,&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_Mirror_Copy,sizeof(SecureLogRecord_Group2));
	  SecureLogRecord_Group2.Valid=((NvM_RequestResultType)NVM_REQ_OK==ErrorStatus)?(uint8)TRUE:(uint8)FALSE;
	}
	else
	{
		/* Do nothing */
	}

    /* Increment timestamp counter */
    TimeStampIncrement();

	switch(FailedEvent)
	{
	case AUTHNTICATION_FAILURE:
		/*Extract Serial Number*/
		KeyElementID[e_ZERO] = (uint8)e_ZERO;
		KeyElementID[e_ONE] = (uint8)e_ONE ;  /* Assign Serial No. key Element id from certificate */
		(void)Csm_AEADEncrypt(CsmConf_CsmJob_CsmJob_GetRoleFromTesterCertificate,CRYPTO_OPERATIONMODE_SINGLECALL,&KeyElementID[e_ZERO],(uint8)e_TWO,NULL_PTR,(uint8)e_ZERO,&CertSerNum[e_ZERO],&SerialNumLen,NULL_PTR,NULL_PTR);
		f_logEvent_v(AUTHNTICATION_FAILURE, No_SUB_TYPE, CertSerNum);

	    /* Clear buffer and reset length to 20 */
	    SerialNumLen = (uint32)D_SERIAL_NUMBER_SIZE;
	    (void)VStdLib_MemSet(&CertSerNum[e_ZERO], (uint8)0, D_EVENT_DATA_SIZE);

		break;
	case FAILED_AUTHORIZATION_ATTEMPTS:
		/*Extract Serial Number*/
		KeyElementID[e_ZERO] = (uint8)e_ZERO;
		KeyElementID[e_ONE] = (uint8)e_ONE ;  /* Assign Serial No. key Element id from certificate */
		(void)Csm_AEADEncrypt(CsmConf_CsmJob_CsmJob_GetRoleFromTesterCertificate,CRYPTO_OPERATIONMODE_SINGLECALL,&KeyElementID[e_ZERO],(uint8)e_TWO,NULL_PTR,(uint8)e_ZERO,&CertSerNum[e_ZERO],&SerialNumLen,NULL_PTR,NULL_PTR);
		f_logEvent_v(FAILED_AUTHORIZATION_ATTEMPTS, No_SUB_TYPE, CertSerNum);

	    /* Clear buffer and reset length to 20 */
	    SerialNumLen = (uint32)D_SERIAL_NUMBER_SIZE;
	    (void)VStdLib_MemSet(&CertSerNum[e_ZERO], (uint8)0, D_EVENT_DATA_SIZE);

		break;
	case CYBERSEC_FAILURE:
		f_logEvent_v(CYBERSEC_FAILURE, No_SUB_TYPE, CertSerNum);
		break;
	default:
		/* Do nothing */
		break;
	}

    if((SecDiagCurrentRole != (uint32)SEC_DIAG_DEFAULT_ROLE) && (CheckCertSessionValid == (boolean)TRUE))
    {
        CheckAuthCertiValidity();
    }
    else
    {
        /* Reset flag to stop check certificate session validity on seconds passed */
        CheckCertSessionValid = (boolean)FALSE;
    }

	/* check if current session is timed out or security access failed */
	if(((boolean)TRUE == Session_Timeout_Flag) || ((boolean)FALSE == Security_Status_Flag))
	{
		SecDiagCurrentRole = (uint32)SEC_DIAG_DEFAULT_ROLE;
	}
	else
	{
		/* Do Nothing */
	}
	if((boolean)TRUE==Secure_Delay_Timer_Flag)
	{
		if((uint8)e_ZERO == Secure_Delay_Timer)
		{
			Secure_Delay_Timer_Flag = FALSE;
		}
		else
		{
			Secure_Delay_Timer-- ;
		}
		if(Secure_Delay_Timer_Flag == (boolean)FALSE)
		{
			Delay_Flag = SEC_DELAY_INACTIVE ;
			DelayFlag_NvMWrite_Flag = TRUE;
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

	if((boolean)TRUE==InvalidCount_NvMWrite_Flag)
	{
		(void)Rte_Call_NvMService_AC3_SRBS_SecAccessInvalidCount_GetErrorStatus(&InvalidCount_ErrStatus);
		if((NvM_RequestResultType)NVM_REQ_PENDING!=InvalidCount_ErrStatus)
		{
			LocalInvalidCnt = CRYPTO_INVERT_8_BIT (Invalid_Count);
			if(LocalInvalidCnt != *Rte_Pim_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_MirrorBlock())
			{
				*Rte_Pim_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_MirrorBlock()=LocalInvalidCnt;
				(void)Rte_Call_NvMService_AC3_SRBS_SecAccessInvalidCount_WriteBlock(Rte_Pim_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_MirrorBlock());
			}
			else
			{
				/* Do Nothing */
			}
			InvalidCount_NvMWrite_Flag=FALSE;
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

	if((boolean)TRUE==DelayFlag_NvMWrite_Flag)
	{
		(void)Rte_Call_NvMService_AC3_SRBS_SecAccessDelayFlag_GetErrorStatus(&DelayFlag_ErrStatus);
		if((NvM_RequestResultType)NVM_REQ_PENDING!=DelayFlag_ErrStatus)
		{
			if(Delay_Flag != *Rte_Pim_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_MirrorBlock())
			{
				*Rte_Pim_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_MirrorBlock()=Delay_Flag;
				(void)Rte_Call_NvMService_AC3_SRBS_SecAccessDelayFlag_WriteBlock(Rte_Pim_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_MirrorBlock());
			}
			else
			{
				/* Do Nothing */
			}
			DelayFlag_NvMWrite_Flag=FALSE;
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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Get_SecureAuthenticationStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_ADAStatus> of PortPrototype <PpSecureAuthenticationStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RE_Get_SecureAuthenticationStatus(ADAStatusType *ADAStatus)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Get_SecureAuthenticationStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_CryptoMgr_CODE) RE_Get_SecureAuthenticationStatus(P2VAR(ADAStatusType, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) ADAStatus) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Get_SecureAuthenticationStatus
 *********************************************************************************************************************/
  /* DD-ID: {89EDA195-F2BF-4c60-8700-C910A84849CF}*/
	*ADAStatus=((boolean)TRUE==Security_Status_Flag)?WITH_AUTHENTICATION:WITHOUT_AUTHENTICATION;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_CertAccessInfo_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvM_RpNotifyJobEnd_NvMBlockDescriptor_CertAccessInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_CertAccessInfo_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_CertAccessInfo_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_CryptoMgr_CODE) RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_CertAccessInfo_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_CertAccessInfo_JobFinished
 *********************************************************************************************************************/
  /* DD-ID: {DFC9D997-D7FF-4272-BF6E-4F858F27314F}*/
 uint8 v_LoopIdx_CertAccessInfo_u8 ;

  if ((ServiceId == (NvM_ServiceIdType)NVM_READ_BLOCK)  && (JobResult == (NvM_RequestResultType)NVM_REQ_OK))
  {
    /* Incrementing the v_CertAccessInfoCounter_u8 to read next certificate information */
    INCREMENT_VALUE_BYONE(v_CertAccessInfoCounter_u8);

    if(v_CertAccessInfoCounter_u8 < (uint8)e_TEN)
    {
      (void)Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_SetDataIndex(v_CertAccessInfoCounter_u8);
      (void)Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_ReadBlock(&s_CertAccessInfo_Arr_as[v_CertAccessInfoCounter_u8]);
    }
    else
    {
      for (v_LoopIdx_CertAccessInfo_u8= (uint8)e_ZERO ; v_LoopIdx_CertAccessInfo_u8 < (uint8)e_TEN; v_LoopIdx_CertAccessInfo_u8++)
      {

           /*2030: Issuer Name */
          VStdLib_MemCpy(&v_2030_CertAccess_issuer_u8[v_LoopIdx_CertAccessInfo_u8*(uint16)D_ISSUER_NAME_SIZE], &s_CertAccessInfo_Arr_as[v_LoopIdx_CertAccessInfo_u8].IssuerName_au8, D_ISSUER_NAME_SIZE);

          /*2030: Serial Number */
          VStdLib_MemCpy(&v_2030_CertAccess_SerialNo_u8[v_LoopIdx_CertAccessInfo_u8*(uint16)D_SERIAL_NUMBER_SIZE], &s_CertAccessInfo_Arr_as[v_LoopIdx_CertAccessInfo_u8].SerialNumber_au8, D_SERIAL_NUMBER_SIZE);

      }

    }
  }
  else
  {
	  /* Do Nothing */
  }

  if ((ServiceId == (NvM_ServiceIdType)NVM_WRITE_BLOCK)  && (JobResult == (NvM_RequestResultType)NVM_REQ_OK))
  {
    /* Incrementing the v_CertAccessInfoCounter_u8 to write next certificate information */
    INCREMENT_VALUE_BYONE(v_CertAccessInfoCounter_u8);
    if(v_CertAccessInfoCounter_u8 < (uint8)e_TEN)
    {
      (void)Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_SetDataIndex(v_CertAccessInfoCounter_u8);
      (void)Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_WriteBlock(&s_CertAccessInfo_Arr_as[v_CertAccessInfoCounter_u8]);
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

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_FileHeader_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvM_RpNotifyJobEnd_NvMBlockDescriptor_FileHeader>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_FileHeader_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_FileHeader_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_CryptoMgr_CODE) RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_FileHeader_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_FileHeader_JobFinished
 *********************************************************************************************************************/
  /* DD-ID: {74BDE9F4-CBD7-4baa-9746-95AF7DFDEBDB}*/

  uint8 v_LoopIdx_fileHeader_u8;

  if ((ServiceId == (NvM_ServiceIdType)NVM_READ_BLOCK)  && (JobResult == (NvM_RequestResultType)NVM_REQ_OK))
  {
    /* Incrementing the v_fileHeaderCounter_u8 to read next certificate information */
    INCREMENT_VALUE_BYONE(v_fileHeaderCounter_u8);

    if(v_fileHeaderCounter_u8 < (uint8)e_NINE)
    {
       (void)Rte_Call_NvMService_AC3_SRBS_DS_FileHeader_SetDataIndex(v_fileHeaderCounter_u8);
       (void)Rte_Call_NvMService_AC3_SRBS_DS_FileHeader_ReadBlock(&s_fileHeader_Arr_as[v_fileHeaderCounter_u8]);
    }
    else
    {
      /* Send file Header info data into DID */
      for (v_LoopIdx_fileHeader_u8= (uint8)e_ZERO ; v_LoopIdx_fileHeader_u8 < (uint8)e_NINE; v_LoopIdx_fileHeader_u8++)
      {
        if (v_LoopIdx_fileHeader_u8 == (uint8) e_ZERO)
        {
          /*2957 : Copied LB 0 Info and uuid */
          VStdLib_MemCpy(&v_2957_swfileHeaderInfo_u8[v_LoopIdx_fileHeader_u8], &s_fileHeader_Arr_as[v_LoopIdx_fileHeader_u8], D_FILEHEADER_INFO_UUID_SIZE);
          /*2958 : Copied LB 0 Uuid*/
          VStdLib_MemCpy(&v_2958_swfileHeaderUuid_u8[v_LoopIdx_fileHeader_u8], &s_fileHeader_Arr_as[v_LoopIdx_fileHeader_u8].fileHeaderUuid_au8, D_FILEHEADER_UUID_SIZE);

          /*295B : Copied LB 0 Info and uuid */
          VStdLib_MemCpy(&v_295B_HTAHeaderInfo_u8[v_LoopIdx_fileHeader_u8], &s_fileHeader_Arr_as[
          v_LoopIdx_fileHeader_u8], D_FILEHEADER_INFO_UUID_SIZE);
           /*295C : Copied LB 0 Uuid*/
          VStdLib_MemCpy(&v_295C_HTAHeaderUuid_u8[v_LoopIdx_fileHeader_u8], &s_fileHeader_Arr_as[
          v_LoopIdx_fileHeader_u8].fileHeaderUuid_au8, D_FILEHEADER_UUID_SIZE);
        }
        else if ( v_LoopIdx_fileHeader_u8 < ((uint8)e_THREE))
        {
          /*2959 : Copied LB 6 and 7 Info and uuid*/
          VStdLib_MemCpy(&v_2959_datafileHeaderInfo_u8[(v_LoopIdx_fileHeader_u8-(uint8)e_ONE)*D_FILEHEADER_INFO_UUID_SIZE], &s_fileHeader_Arr_as[v_LoopIdx_fileHeader_u8], D_FILEHEADER_INFO_UUID_SIZE);
          /*295A : Copied LB 6 and 7 Uuid*/
          VStdLib_MemCpy(&v_295A_datafileHeaderUuid_u8[(v_LoopIdx_fileHeader_u8-(uint8)e_ONE)*D_FILEHEADER_UUID_SIZE], &s_fileHeader_Arr_as[v_LoopIdx_fileHeader_u8].fileHeaderUuid_au8, D_FILEHEADER_UUID_SIZE);
        }
        else if ( v_LoopIdx_fileHeader_u8 == ((uint8)e_THREE))
        {
          /*295F : Copied LB 8 Info and uuid */
          VStdLib_MemCpy(&v_295F_secfileHeaderInfo_u8[(v_LoopIdx_fileHeader_u8-(uint8)e_THREE)], &s_fileHeader_Arr_as[v_LoopIdx_fileHeader_u8], D_FILEHEADER_INFO_UUID_SIZE);
          /*2951: Copied LB 8 Uuid*/
          VStdLib_MemCpy(&v_2951_secfileHeaderUuid_u8[(v_LoopIdx_fileHeader_u8-(uint8)e_THREE)], &s_fileHeader_Arr_as[v_LoopIdx_fileHeader_u8].fileHeaderUuid_au8, D_FILEHEADER_UUID_SIZE);
           /*295E : Copied LB 8 Uuid*/
          VStdLib_MemCpy(&v_295E_secfileHeaderUuid_u8[(v_LoopIdx_fileHeader_u8-(uint8)e_THREE)], &s_fileHeader_Arr_as[v_LoopIdx_fileHeader_u8].fileHeaderUuid_au8, D_FILEHEADER_UUID_SIZE);
        }
        else
        {
          /*2957 : Copied LB 1 to 5 Info and uuid*/
          VStdLib_MemCpy(&v_2957_swfileHeaderInfo_u8[(v_LoopIdx_fileHeader_u8-(uint8)e_THREE)*(uint8)D_FILEHEADER_INFO_UUID_SIZE], &s_fileHeader_Arr_as[v_LoopIdx_fileHeader_u8], D_FILEHEADER_INFO_UUID_SIZE);
          /*2958 : Copied LB 1 to 5 Uuid*/
          VStdLib_MemCpy(&v_2958_swfileHeaderUuid_u8[(v_LoopIdx_fileHeader_u8-(uint8)e_THREE)*(uint8)D_FILEHEADER_UUID_SIZE], &s_fileHeader_Arr_as[v_LoopIdx_fileHeader_u8].fileHeaderUuid_au8, D_FILEHEADER_UUID_SIZE);
        }
      }
    }
  }
  else
  {
	  /* Do Nothing */
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  f_logEvent_v
 * 
 * 
 ***********************************************************************************************************************/
static void f_logEvent_v(const EventType Event, const EventSubType SubEvent, const uint8* EventData)
{
  /* DD-ID: {9637E886-0BBC-4536-AA13-C2A38A2340D2}*/
	uint32 VerifyMacLen = D_CMAC_LEN;
	SecureLogRecord_t *group;
	uint32 const TimeStamp = getTimeStamp();
	uint8 GroupID = 0u;
	/* Check if event to be logged is in range */
	if((AUTHNTICATION_FAILURE == Event) || (FAILED_AUTHORIZATION_ATTEMPTS == Event) ||
			(UNAUTHORIZED_ACCESS == Event) || (CYBERSEC_FAILURE == Event))
	{
		group = getEventGroup(Event,&GroupID);

		group->RecordEntry[group->RecId][D_SEC_NUM_POS] = (uint8)RIGHTSHIFT_BIT(group->SecId,BIT_SHIFT_EIGHT_BIT);
		group->RecordEntry[group->RecId][D_SEC_NUM_POS+1u] = (uint8)group->SecId;

		group->RecordEntry[group->RecId][D_TIMESTAMP_POS] = (uint8)RIGHTSHIFT_BIT(TimeStamp,BIT_SHIFT_TWENTYFOUR_BIT);
		group->RecordEntry[group->RecId][D_TIMESTAMP_POS+FIRST_BYTE] = (uint8)RIGHTSHIFT_BIT(TimeStamp,BIT_SHIFT_SIXTEEN_BIT);
		group->RecordEntry[group->RecId][D_TIMESTAMP_POS+SECOND_BYTE] = (uint8)RIGHTSHIFT_BIT(TimeStamp,BIT_SHIFT_EIGHT_BIT);
		group->RecordEntry[group->RecId][D_TIMESTAMP_POS+THIRD_BYTE] = (uint8)TimeStamp;

		group->RecordEntry[group->RecId][D_EVENT_TYPE_POS] = (uint8)Event;

		group->RecordEntry[group->RecId][D_SUB_TYPE_POS] = (uint8)SubEvent;
		/*Log Certificate Serial Number*/
		(void)VStdLib_MemCpy(&(group->RecordEntry[group->RecId][D_EVENT_DATA_POS]),EventData,D_EVENT_DATA_SIZE);

		(void)Csm_MacGenerate(CsmConf_CsmJob_CsmJob_SecureLog_MacGen,CRYPTO_OPERATIONMODE_SINGLECALL, (uint8*)&(group->RecordEntry[group->RecId][0]), D_RECORD_DATA_SIZE, &(group->RecordEntry[group->RecId][D_RECORD_DATA_SIZE]),&VerifyMacLen);
		(void)Csm_MacVerify(CsmConf_CsmJob_CsmJob_SecureLog_MacVerify,CRYPTO_OPERATIONMODE_SINGLECALL, (uint8*)&(group->RecordEntry[group->RecId][0]), D_RECORD_DATA_SIZE, &(group->RecordEntry[group->RecId][D_RECORD_DATA_SIZE]),VerifyMacLen,  (uint8*)&(group->RecordEntry[group->RecId][D_REC_STORAGE_SIZE-1u]));

		/*Increment variables for nexe event logging*/
		group->GroupCnt++;
		group->SecId++;
		group->RecId++;
		if(group->RecId == (uint8)D_RECORD_PER_GRP)
		{
			group->RecId = 0u;
		}
		else
		{
			/* Do Nothing */
		}

		if((uint8)e_ONE==GroupID)
		{
			VStdLib_MemCpy(&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_Mirror_Copy,&SecureLogRecord_Group1,sizeof(SecureLogRecord_Group1));
			(void)Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup1_SetRamBlockStatus(TRUE);
		}
		else if((uint8)e_TWO==GroupID)
		{
			VStdLib_MemCpy(&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_Mirror_Copy,&SecureLogRecord_Group2,sizeof(SecureLogRecord_Group2));
			(void)Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup2_SetRamBlockStatus(TRUE);
		}
		else
		{
			/* Do Nothing */
		}

	}
	else
	{
		/* Event Value is invalid Do Nothing */
	}
	/* Clear Failed event value */
	FailedEvent = NO_FAILED_EVENT;
}

static SecureLogRecord_t * getEventGroup(const EventType Event, uint8* GrpId)
{
  /* DD-ID: {A49D6AE7-B027-46cb-A4DE-1C691DAB887D}*/
	SecureLogRecord_t *EventGroup = NULL_PTR;
	switch (Event)
	{
		case AUTHNTICATION_FAILURE:
	  	case FAILED_AUTHORIZATION_ATTEMPTS:
	  		EventGroup = &SecureLogRecord_Group1;
	  		*GrpId=(uint8)e_ONE;
		break;

	  	case UNAUTHORIZED_ACCESS:
	  	case CYBERSEC_FAILURE:
	  		EventGroup = &SecureLogRecord_Group2;
	  		*GrpId=(uint8)e_TWO;
		break;

	  	default:
	  		/* Do Nothing */
		break;
	}

	return EventGroup;
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
static Std_ReturnType ParseUTCGeneralizedTime(P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) timeElementPtr,
                                       uint16 timeElementDataLength,
                                       P2VAR(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) parsedTimePtr)
{
  /* DD-ID: {C84D2CAC-2E21-4707-BF34-524F03840035}*/
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
  else
  {
	  /* Do Nothing */
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
  else
  {
	  /* Do Nothing */
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
  else
  {
	  /* Do Nothing */
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
static Std_ReturnType ConvertDateToUnixTime(
  P2CONST(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) date,
  P2VAR(uint32, AUTOMATIC, AUTOMATIC) unixTime)
{
   /* DD-ID: {F67A0796-6753-4354-9322-74C577846E7B}*/
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
  else
  {
	  /* Do Nothing */
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
static uint32 getTimeStamp(void)
{
  /* DD-ID: {D8E43B62-E00F-40f1-A5DD-0AA4C8743298}*/
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
static Std_ReturnType getEpochTime(const uint8* LocSystemTime, uint32* LocTimestampCounter)
{
  /* DD-ID: {2F911F5E-7F2D-423e-9174-5FBA9331515E}*/
    Std_ReturnType retVal = E_NOT_OK;
    CertDateTimeType_t UTCGenTime = {0};

    if (LocSystemTime != NULL_PTR)
    {
        retVal = ParseUTCGeneralizedTime(LocSystemTime, D_SYSTEM_TIME_LENGTH, &UTCGenTime);
        if(retVal == E_OK)
        {
            retVal = ConvertDateToUnixTime(&UTCGenTime, LocTimestampCounter);
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
static void TimeStampIncrement(void)
{
  /* DD-ID: {4A8642C1-2CCC-4a0c-AE06-666219988099}*/

	static boolean flag = FALSE;
	static uint32 IncCounter = 0u;
    if(IsSystemTimeSet != FALSE)
    {
        IncCounter += 1U;

        /* % by 100m because IncCounter is incremented once every 10ms */
        if((IncCounter % 100U) == 0U)
        {
            /* Increment seconds passed */
        	SecondCounter += 1U;
            *Rte_Pim_NvMBlockDescriptor_SecondCounter_MirrorBlock() = SecondCounter;
            if(SecDiagCurrentRole != SEC_DIAG_DEFAULT_ROLE)
            {
                /* Increment seconds passed in current extended session */
                SessionSecondCounter += 1U;
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

        /* Set status of RAM block to true */
        if ((flag != TRUE) && (SecondCounter != 0u))
        {
            (void)NvM_SetRamBlockStatus((NvM_BlockIdType)NvMConf_NvMBlockDescriptor_CDD_CryptoMgrNvMBlockDescriptor_SecondCounter, TRUE);
            flag = TRUE;
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
static void CheckAuthCertiValidity(void)
{
  /* DD-ID: {DC6CB0A8-396C-4ab1-994A-2A9516A14EB9}*/
    uint32 LatestTimeStamp;

    /* Get latest timestamp value */
    LatestTimeStamp = TimestampCounter + SessionSecondCounter;
    /* Check if received certificate is already expired OR if latest timestamp is greater than not-after time of certificate */
    if(LatestTimeStamp > NotAfterEpochFormat)
    {
        /* Reset flag to stop check certificate session validity on seconds passed */
        CheckCertSessionValid = FALSE;
        /* Exit current session */
        (void)Dcm_ResetToDefaultSession();
        /* Set certificate expired flag */
        CertificateExpired = TRUE;
        (void)NvM_WriteBlock((NvM_BlockIdType)NvMConf_NvMBlockDescriptor_CDD_CryptoMgrNvMBlockDescriptor_CertificateExpired, &CertificateExpired);
    }
	else
	{
		/* Do Nothing */
	}
}

/***********************************************************************************************************************
 *  f_UpdateTesterCertElements_v
 *
 *
 ***********************************************************************************************************************/
static void f_UpdateTesterCertElements_v(void)
{
  /* DD-ID: {877E7E0D-6B29-4151-BFE5-911B2ED0A758}*/
	uint8 v_LoopIdx_u8;
	CertAccessInfo_t v_CertAccessInfo_Arr_as[e_TEN] = {0};
	v_CertAccessInfoCounter_u8= (uint8)e_ZERO;

	/*Extract Issuer Name*/
	KeyElementID[e_ZERO] =  (uint8)e_ZERO;
	KeyElementID[e_ONE] = (uint8)e_THREE ;  /* Assign Issuer Name key Element id from certificate */
	(void)Csm_AEADEncrypt(CsmConf_CsmJob_CsmJob_GetRoleFromTesterCertificate,CRYPTO_OPERATIONMODE_SINGLECALL,&KeyElementID[e_ZERO],(uint8)e_TWO,NULL_PTR,(uint8)e_ZERO,&IssuerName[e_ZERO],&IssuerNameLen,NULL_PTR,NULL_PTR);
	/*Extract Serial Number*/
	KeyElementID[e_ZERO] =  (uint8)e_ZERO;
	KeyElementID[e_ONE] = (uint8)e_ONE ;  /* Assign Serial No. key Element id from certificate */
	(void)Csm_AEADEncrypt(CsmConf_CsmJob_CsmJob_GetRoleFromTesterCertificate,CRYPTO_OPERATIONMODE_SINGLECALL,&KeyElementID[e_ZERO],(uint8)e_TWO,NULL_PTR,(uint8)e_ZERO,&SerialNum[e_ZERO],&SerialNumLen,NULL_PTR,NULL_PTR);

	/* shift CertAccessInfo by one using local variable to vacant index zero*/
    for (v_LoopIdx_u8= (uint8)e_ZERO ; v_LoopIdx_u8 < (uint8)e_NINE; v_LoopIdx_u8++)
    {
         /*2030: Issuer Name */
        (void)VStdLib_MemCpy(&v_CertAccessInfo_Arr_as[v_LoopIdx_u8 + (uint8)e_ONE].IssuerName_au8, &s_CertAccessInfo_Arr_as[v_LoopIdx_u8].IssuerName_au8, D_ISSUER_NAME_SIZE);
        (void)VStdLib_MemCpy(&v_2030_CertAccess_issuer_u8[(uint8)D_ISSUER_NAME_SIZE * (v_LoopIdx_u8 + (uint8)e_ONE)], &s_CertAccessInfo_Arr_as[v_LoopIdx_u8].IssuerName_au8, D_ISSUER_NAME_SIZE);
        /*2030: Serial Number */
        (void)VStdLib_MemCpy(&v_CertAccessInfo_Arr_as[v_LoopIdx_u8 + (uint8)e_ONE].SerialNumber_au8, &s_CertAccessInfo_Arr_as[v_LoopIdx_u8].SerialNumber_au8, D_SERIAL_NUMBER_SIZE);
        (void)VStdLib_MemCpy(&v_2030_CertAccess_SerialNo_u8[(uint8)D_SERIAL_NUMBER_SIZE * (v_LoopIdx_u8 + (uint8)e_ONE)], &s_CertAccessInfo_Arr_as[v_LoopIdx_u8].SerialNumber_au8, D_SERIAL_NUMBER_SIZE);
    }
    /*Copy shifted local var into CertAccessInfo and write latest info in index zero*/
    (void) VStdLib_MemCpy(&s_CertAccessInfo_Arr_as,&v_CertAccessInfo_Arr_as, D_CERTACCESSINFO_SIZE);
    (void)VStdLib_MemCpy(&s_CertAccessInfo_Arr_as[e_ZERO].IssuerName_au8,&IssuerName[e_ZERO], D_ISSUER_NAME_SIZE);
    (void)VStdLib_MemCpy(&s_CertAccessInfo_Arr_as[e_ZERO].SerialNumber_au8,&SerialNum[e_ZERO], D_SERIAL_NUMBER_SIZE);
    (void)VStdLib_MemCpy(&v_2030_CertAccess_issuer_u8[e_ZERO],&IssuerName[e_ZERO], D_ISSUER_NAME_SIZE);
    (void)VStdLib_MemCpy(&v_2030_CertAccess_SerialNo_u8[e_ZERO],&SerialNum[e_ZERO], D_SERIAL_NUMBER_SIZE);

    /* Clear buffer and reset length to 20 */
    SerialNumLen = (uint32)D_SERIAL_NUMBER_SIZE;
    (void)VStdLib_MemSet(&SerialNum[e_ZERO], (uint8)0, D_SERIAL_NUMBER_SIZE);

	/*Store Serial No and Issuer Name to NvM*/
	(void)Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_SetDataIndex(v_CertAccessInfoCounter_u8);
	(void)Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_WriteBlock(&s_CertAccessInfo_Arr_as[v_CertAccessInfoCounter_u8]);
}
/***********************************************************************************************************************
 *  f_UpdateADAFailedAttempt_v
 *
 *
 ***********************************************************************************************************************/
static void f_UpdateADAFailedAttempt_v(void)
{
  /* DD-ID: {13AC4086-3FAA-45bd-AD86-52F0337168B8}*/
	if((uint8)MAX_SEC_INVALID_COUNT > Invalid_Count)
	{
		INCREMENT_VALUE_BYONE(Invalid_Count);
		InvalidCount_NvMWrite_Flag = TRUE;
	}
	else
	{
		Invalid_Count = MAX_SEC_INVALID_COUNT;
	}
	Delay_Flag = SEC_DELAY_ACTIVE; /*update Delay Flag in NvM Ram Mirror*/
	DelayFlag_NvMWrite_Flag = TRUE;
	Secure_Delay_Timer = CRYPTO_SEC_DELAY_TIMEOUT(Invalid_Count); /* Calculate delay timer */
	Secure_Delay_Timer_Flag = TRUE;  /*Start Delay Timer*/
	Security_Status_Flag = FALSE;
}
/***********************************************************************************************************************
 *  DcmCalloutStub_CompareKey()
 ***********************************************************************************************************************/
/*! \brief         Compares key.
 *  \details       This function is a request from the DCM to the application to verify the requested security access
 *                 level specific key. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspSecurity/DcmDspSecurityRow/DcmDspSecurityCompareKeyFnc.
 *  \param[in]     Key                       Key data
 *  \param[in]     OpStatus                  The operation status
 *  \param[out]    ErrorCode                 Negative response code
 *  \return        E_OK                      The operation is finished
 *  \return        E_NOT_OK                  The operation has failed
 *  \return        DCM_E_PENDING             The operation is not yet finished
 *  \return        DCM_E_COMPARE_KEY_FAILED  The received key is not valid
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmCalloutStub_CompareKey(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode)
{
  /* DD-ID: {D22F2AE8-C227-4a2c-A43B-D0D82F78F48B}*/
	Std_ReturnType RetVal;
	Std_ReturnType Key_OpStatus;
	sint8 CompResult;
#if (SECURITY_ACCESS == TRUE)
	/* check Key via vDiagSecAcc */
	Key_OpStatus = vDiagSecAcc_CompareKey_L0x000B(Key, OpStatus, ErrorCode);
	if(Key_OpStatus == (Std_ReturnType)E_OK)
	{
	    RetVal = E_OK;
	    Invalid_Count=(uint8)e_ZERO;/*Clear failed attempt count from NvM Ram Mirror*/
	    Delay_Flag=SEC_DELAY_INACTIVE;/*Clear Delay Flag from NvM Ram Mirror*/
	    Secure_Delay_Timer_Flag = FALSE; /* Clear Delay timer flag */
	    InvalidCount_NvMWrite_Flag=TRUE;
	    DelayFlag_NvMWrite_Flag=TRUE;
	    Security_Status_Flag = TRUE;
	    SecDiagCurrentRole =(uint32)((uint32)1<<(uint32)CurrentRole[e_ZERO]);	/* set Role provided from HSM */
	    f_UpdateTesterCertElements_v(); /* Extract Issuer Name and Serial Number from Tester Cert*/

        KeyElementID[e_ZERO] =  (uint8)e_ZERO;
        KeyElementID[e_ONE] = (uint8)e_NINE ;  /* Assign not after time Element id from certificate */
        (void)Csm_AEADEncrypt(CsmConf_CsmJob_CsmJob_GetRoleFromTesterCertificate,CRYPTO_OPERATIONMODE_SINGLECALL,&KeyElementID[e_ZERO],(uint8)e_TWO,NULL_PTR,(uint8)e_ZERO,&NotAfterTime[e_ZERO],&NotAfterTimeLen,NULL_PTR,NULL_PTR);

        /* Store latest not after time in epoch format in TimestampCounter */
        (void)getEpochTime(&NotAfterTime[e_ZERO], &NotAfterEpochFormat);

        KeyElementID[e_ZERO] =  (uint8)e_ZERO;
        KeyElementID[e_ONE] = (uint8)e_EIGHT ;  /* Assign not before time Element id from certificate */
        (void)Csm_AEADEncrypt(CsmConf_CsmJob_CsmJob_GetRoleFromTesterCertificate,CRYPTO_OPERATIONMODE_SINGLECALL,&KeyElementID[e_ZERO],(uint8)e_TWO,NULL_PTR,(uint8)e_ZERO,&NotBeforeTime[e_ZERO],&NotBeforeTimeLen,NULL_PTR,NULL_PTR);
        /* Compare not-before time of latest certificate with the last stored not-before time */
        CompResult = VStdLib_MemCmpLarge(&NotBeforeTime[e_ZERO], &SystemTime[e_ZERO], D_SYSTEM_TIME_LENGTH);

        if(CompResult > 0)
        {
            /* Set flag to check certificate session validity on seconds passed */
            CheckCertSessionValid = TRUE;

            /* Reset certificate expired flag for new certificate */
            CertificateExpired = FALSE;
            (void)NvM_WriteBlock((NvM_BlockIdType)NvMConf_NvMBlockDescriptor_CDD_CryptoMgrNvMBlockDescriptor_CertificateExpired, &CertificateExpired);

            /* Save latest System time in NvM if latest retrieved system time from certificate is not equal to stored system time */
            VStdLib_MemCpyLarge(&SystemTime[e_ZERO],&NotBeforeTime[e_ZERO], D_SYSTEM_TIME_LENGTH);
            VStdLib_MemCpyLarge(&Rte_CDD_CryptoMgr_NvMBlockDescriptor_SystemTimestamp_MirrorBlock[e_ZERO],&NotBeforeTime[e_ZERO], D_SYSTEM_TIME_LENGTH);
            (void)NvM_WriteBlock((NvM_BlockIdType)NvMConf_NvMBlockDescriptor_CDD_CryptoMgrNvMBlockDescriptor_SystemTimestamp, &SystemTime[e_ZERO]);
            IsSystemTimeSet = TRUE;

            /* Reset Second counter to 0 */
            SecondCounter = (uint32)e_ZERO;
            SessionSecondCounter = (uint32)e_ZERO;
            *Rte_Pim_NvMBlockDescriptor_SecondCounter_MirrorBlock() = SecondCounter;
            /* Save value 0 to NvM immediately */
            (void)NvM_WriteBlock((NvM_BlockIdType)NvMConf_NvMBlockDescriptor_CDD_CryptoMgrNvMBlockDescriptor_SecondCounter, &SecondCounter);
            /* Set Ram block status to TRUE to save incremented seconds counter value at shut down */
            (void)NvM_SetRamBlockStatus((NvM_BlockIdType)NvMConf_NvMBlockDescriptor_CDD_CryptoMgrNvMBlockDescriptor_SecondCounter, TRUE);

            /* Store latest system time in epoch format in TimestampCounter */
            (void)getEpochTime(&SystemTime[e_ZERO], &TimestampCounter);
            /* Set Latest timestamp in HSM */
            (void)Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_CurrentTimeStamp,CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_CryptoKeyElement_CurrentTimeStamp,SystemTime,D_SYSTEM_TIME_LENGTH);
            (void)Csm_KeySetValid(CsmConf_CsmKey_CsmKey_CurrentTimeStamp);
            (void)Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_SecondCounter,CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_CryptoKeyElement_SecondCounter,(uint8*)&SecondCounter,SECOND_COUNTER_LENGTH);
            (void)Csm_KeySetValid(CsmConf_CsmKey_CsmKey_SecondCounter);
        }
        else if((CompResult == 0) && (CertificateExpired == (boolean)TRUE))
        {
        	RetVal = E_NOT_OK;
        }
        else
        {
            /* Set flag to check certificate session validity on seconds passed */
            CheckCertSessionValid = TRUE;
        }
	}
	else
	{
        FailedEvent=AUTHNTICATION_FAILURE;              /*Log Event*/
        *ErrorCode = DCM_E_INVALIDKEY;			/* ConditionNotCorrect */
        RetVal = E_NOT_OK;
        f_UpdateADAFailedAttempt_v(); 			/*Update Invalid Count and Delay Flag*/
    }
	return RetVal;
#else
	return E_OK;
#endif
}

/***********************************************************************************************************************
 *  DcmCalloutStub_GetSeed()
 ***********************************************************************************************************************/
/*! \brief         Gets seed.
 *  \details       This function is a request from the DCM to the application to provide a security level specific seed.
 *                 The concrete name of the callout is defined by the configuration parameter
 *                 /DcmDsp/DcmDspSecurity/DcmDspSecurityRow/DcmDspSecurityGetSeedFnc.
 *  \param[in]     SecurityAccessDataRecord  Security access data record
 *  \param[in]     OpStatus                  The operation status
 *  \param[out]    Seed                      Seed data
 *  \param[out]    ErrorCode                 Negative response code
 *  \return        E_OK                      The operation is finished
 *  \return        E_NOT_OK                  The operation has failed
 *  \return        DCM_E_PENDING             The operation is not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmCalloutStub_GetSeed(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) SecurityAccessDataRecord,Dcm_OpStatusType OpStatus,P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Seed,P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode)
{
  /* DD-ID: {B7C99705-1984-4853-BC46-F1648687829D}*/
	Std_ReturnType RetVal;
	Std_ReturnType Csm_OpStatus;
	uint8 CertStatus = KEYM_E_CERTIFICATE_INVALID_TYPE;
	uint32 CertStatusLen = 1u;
	static boolean CertKeySet = FALSE;
#if (SECURITY_ACCESS  == TRUE)
	if((boolean)TRUE==Secure_Delay_Timer_Flag)
	{
		*ErrorCode = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;			/* Delay timer not expired */
		RetVal = E_NOT_OK;
	}
	else
	{
		if((boolean)FALSE==CertKeySet)
		{
			/* Set Current time and second counter in HSM */
			(void)Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_CurrentTimeStamp,CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_CryptoKeyElement_CurrentTimeStamp,SystemTime,D_SYSTEM_TIME_LENGTH);
			(void)Csm_KeySetValid(CsmConf_CsmKey_CsmKey_CurrentTimeStamp);
			(void)Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_SecondCounter,CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_CryptoKeyElement_SecondCounter,(uint8*)&SecondCounter,D_TIMESTAMP_SIZE);
			(void)Csm_KeySetValid(CsmConf_CsmKey_CsmKey_SecondCounter);

			/* Verify a certification received from tool */
			(void)Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_KeyMCertificate_ADA_L4, CryptoConf_CryptoKeyElement_Crypto_30_vHsm_KeyM_KeyM_Certificate, SecurityAccessDataRecord, ADA_CERTIFICATE_LENGTH);
			(void)Csm_KeySetValid(CsmConf_CsmKey_CsmKey_KeyMCertificate_ADA_L4);
			CertKeySet=TRUE;
			RetVal = DCM_E_PENDING;
		}
		else
		{
			CertKeySet=FALSE;
			/* Check verification result */
			Csm_OpStatus = Csm_KeyElementGet(CsmConf_CsmKey_CsmKey_KeyMCertificate_ADA_L4, CryptoConf_CryptoKeyElement_Crypto_30_vHsm_KeyM_KeyM_GetStatus, &CertStatus, &CertStatusLen);
			if(Csm_OpStatus == (Std_ReturnType)E_OK)
			{
				/* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        switch( CertStatus )
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
				{
				case KEYM_CERTIFICATE_VALID:		/* Verify?FOK */
					/* generate Seed via vDiagSecAcc */
					RetVal = vDiagSecAcc_GetSeed_L0x000B(OpStatus, Seed, ErrorCode);
          /* VCAST Jenkins requirement - do not modify */
          /* VCAST Jenkins requirement - do not modify */
					if(RetVal == (Std_ReturnType)E_OK)
          /* VCAST Jenkins requirement - do not modify */
          /* VCAST Jenkins requirement - do not modify */
					{
						KeyElementID[(uint8)e_ZERO] =  (uint8)e_ZERO;
						KeyElementID[(uint8)e_ONE] = (uint8)e_FIFTEEN ;  /* Assign actual role key Element id from certificate */
						(void)Csm_AEADEncrypt(CsmConf_CsmJob_CsmJob_GetRoleFromTesterCertificate,CRYPTO_OPERATIONMODE_SINGLECALL,&KeyElementID[e_ZERO],(uint8)e_TWO,NULL_PTR,(uint8)e_ZERO,&CurrentRole[e_ZERO],&CurrentRoleLen,NULL_PTR,NULL_PTR);
					}
					else
					{
						/* Do Nothing */
					}
					break;

				case KEYM_E_CERTIFICATE_REVOKED:
					*ErrorCode = DCM_E_REVOKED_KEY;			/* RevokedKey */
					RetVal = E_NOT_OK;
					FailedEvent=AUTHNTICATION_FAILURE;      /*Log Event*/
					f_UpdateADAFailedAttempt_v(); 			/*Update Invalid Count and Delay Flag*/
					break;

				case KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL:
					*ErrorCode = DCM_E_EXPIRED_KEY;			/* ExpiredKey */
					RetVal = E_NOT_OK;
					FailedEvent=AUTHNTICATION_FAILURE;      /*Log Event*/
					f_UpdateADAFailedAttempt_v(); 			/*Update Invalid Count and Delay Flag*/
					break;

				default:
					*ErrorCode = DCM_E_INVALIDKEY;			/* InvalidKey */
					RetVal = E_NOT_OK;
					FailedEvent=AUTHNTICATION_FAILURE;		/*Log Event*/
					f_UpdateADAFailedAttempt_v(); 			/*Update Invalid Count and Delay Flag*/
					break;
				}
			}
			else
			{
				*ErrorCode = DCM_E_INVALIDKEY;				/* ConditionNotCorrect */
				RetVal = E_NOT_OK;
			}
		}
	}
	return RetVal;
#else
	return E_OK;
#endif
}
/***********************************************************************************************************************
 *  CsmCallbackFunc_CsmCallback()
 ***********************************************************************************************************************/
/*! \brief         Callback for CSM jobcd
 *  \details       
 *                 
 *                 
 *                 
 *  \param[in]     
 *  \param[in]     
 *  \return        
 *  \return        
 *  \return        
 *  \context       
 *  \reentrant     
 *  \synchronous   
 *  \pre           -
 ***********************************************************************************************************************/

FUNC(void, CSM_APPL_CODE) CsmCallbackFunc_CsmCallback(const uint32 jobID, Csm_ResultType result)
{
  /* DD-ID: {D00BC636-C4EC-4322-AEF9-DDFC36ADBEE0}*/
	(void)jobID;
	(void)result;
}

/***********************************************************************************************************************
 *  CsmPostJobCalloutFunc_CsmCallout_ADASigVerify()
 ***********************************************************************************************************************/
/*! \brief         Callout for CSM job
 *  \details
 *
 *
 *
 *  \param[in]
 *  \param[in]
 *  \return
 *  \return
 *  \return
 *  \context
 *  \reentrant
 *  \synchronous
 *  \pre           -
 ***********************************************************************************************************************/
Std_ReturnType CsmPostJobCalloutFunc_CsmCallout_ADASigVerify(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state, P2VAR(Std_ReturnType, AUTOMATIC, CSM_APPL_VAR) jobReturnValue)
{
  /* DD-ID: {4D507AC6-E86C-4920-BA1D-BD5222183CBC}*/
	(void)job;
	(void)state;
	(void)jobReturnValue;
	return E_OK;
}

/***********************************************************************************************************************
 *  CsmPreJobCalloutFunc_CsmCallout_ADASigVerify()
 ***********************************************************************************************************************/
/*! \brief         Callout for CSM job
 *  \details
 *
 *
 *
 *  \param[in]
 *  \param[in]
 *  \return
 *  \return
 *  \return
 *  \context
 *  \reentrant
 *  \synchronous
 *  \pre           -
 ***********************************************************************************************************************/
Std_ReturnType CsmPreJobCalloutFunc_CsmCallout_ADASigVerify(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state)
{
  /* DD-ID: {841F6652-9008-4dd1-BD7E-C4D8A336331D}*/
	uint8 Cnt;
	(void)state;
	/* Copy Nonce to a new buffer from SecondaryInputBuffer */
	for(Cnt = 0u; Cnt < (uint8)D_SIGN_LENGTH; Cnt++ )
	{
		Csm_InputData_ADASigVeri[Cnt] = job->jobPrimitiveInputOutput.secondaryInputPtr[Cnt];
	}
	/* Copy Seed to a new buffer from InputBuffer */
	for(; Cnt < (uint8)CSM_SIGNATURE_LENGTH; Cnt++ )
	{
		Csm_InputData_ADASigVeri[Cnt] = job->jobPrimitiveInputOutput.inputPtr[Cnt - (uint8)D_SIGN_LENGTH];
	}

	/* replace buffers and lengths keep in job to new buffers and new lengths */
	job->jobPrimitiveInputOutput.inputPtr = &Csm_InputData_ADASigVeri[ZEROTH_BYTE];
	job->jobPrimitiveInputOutput.inputLength = CSM_SIGNATURE_LENGTH;
	job->jobPrimitiveInputOutput.secondaryInputPtr = &(job->jobPrimitiveInputOutput.secondaryInputPtr[D_SIGN_LENGTH]);
	job->jobPrimitiveInputOutput.secondaryInputLength = D_SIGNATURE_INPUT_LENGTH;

	return E_OK;
}

/**********************************************************************************************************************
 *  Appl_vDamUserRoleCalloutFunc
 *********************************************************************************************************************/
/*!
 * \fn          Appl_vDamUserRoleCalloutFunc
 * \brief       Provide current user Role
 * \param[in]   TesterSourceAddress  source address of the tester.
 * \param[out]  userRole             Current user role.
 * \return      E_OK      Operation successful
 * \return      E_NOT_OK  Operation failed
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VDAM_CALLOUT_CODE) Appl_vDamUserRoleCalloutFunc( uint16 TesterSourceAddress, P2VAR(uint32, AUTOMATIC, AUTOMATIC) userRole )
{
  /* DD-ID: {BFA64FB9-4409-45e3-9B35-C4ECA3B177D9}*/

	(void)TesterSourceAddress;
#if (SECURITY_ACCESS  == TRUE)
	*userRole = SecDiagCurrentRole;
#else
	*userRole = 1u; /* If security access is bypassed set default role as engineering */
#endif
	return E_OK ;
}
/**********************************************************************************************************************
 *  Appl_vDamRemapNrcCalloutFunc
 *********************************************************************************************************************/
/*!
 * \fn          nrcRemappingCalloutFunc
 * \brief       Callout to remap vDam NRC
 * \param[in]
 * \param[out]
 * \return
 * \return
 * \pre
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VDAM_CALLOUT_CODE) Appl_vDamRemapNrcCalloutFunc(uint8 SID, uint8 intErrorCode, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDAM_DCM_VAR) errorCode)
{
  /* DD-ID: {9607A33B-4E47-43b8-950F-10432D4E1401}*/

	(void)SID;
	(void)errorCode;
	if((E_OK!=intErrorCode)&&((Dcm_NegativeResponseCodeType)DCM_E_REQUESTOUTOFRANGE== *errorCode))
	{
		FailedEvent = FAILED_AUTHORIZATION_ATTEMPTS;
	}
	else
	{
		/* Do Nothing */
	}
}

/***********************************************************************************************************************
 *  DcmCalloutStub_SessionCallback
 ***********************************************************************************************************************/
/*! \brief         Callback from DCM Session Control
 *  \details
 *
 *
 *
 *  \param[in]
 *  \param[in]
 *  \return
 *  \return
 *  \return
 *  \context
 *  \reentrant
 *  \synchronous
 *  \pre           -
 ***********************************************************************************************************************/
void DcmCalloutStub_SessionCallback(uint8 formerSession, uint8 newSession)
{
  /* DD-ID: {B3DF01F2-7A4D-4a67-947E-8B6917F03C7C}*/
	(void)formerSession;
	/*Check for default session due to S3 Timeout*/
	if((DCM_DEFAULT_SESSION==newSession))
	{
		Session_Timeout_Flag=TRUE;
		Security_Status_Flag=FALSE;
	}
	else
	{
		Session_Timeout_Flag=FALSE;
	}
}
#define CDD_CryptoMgr_STOP_SEC_CODE
#include "CDD_CryptoMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
