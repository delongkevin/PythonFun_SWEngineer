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
 *             File:  CDD_Safety.c
 *           Config:  D:/git/L2H4060_Software_develop/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  CDD_Safety
 *  Generation Time:  2024-02-14 17:44:47
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <CDD_Safety>
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
 * ErrorMgr_enErrorNo
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ErrorMgr_enErrorNo
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ErrorMgr_enErrorStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ErrorMgr_enErrorStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * SSM_DegradedState
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * SSM_SystemStateDef
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 *********************************************************************************************************************/

#include "Rte_CDD_Safety.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "fusa_application.h"
#include "vtm.h"
#include "pmic.h"
#include "NvM.h"
#include "app_log.h"
#include "app_log_Boot.h"
#include "vstdlib.h"
#include "SSM_Defs.h"

extern void SSM_Master_SetThermalShutDownRequest(void);
extern void SW_ResetMainDomainCores(void);

__attribute__ ((section("QMRAM"))) VAR(Arr_2Byte, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

/*#define UART_PRINT_ENABLED*/

static volatile uint8 gSdlCddInitExecuted = FALSE;
static volatile bool cdd_safety_BistSSEn = false;
/* Thermal-Shutdown status */
static volatile uint16_t gSdlTSDStatus = SDL_VTM_TSD_NOT_REQ;

static void Cdd_Safety_SS_ShutDownTest(void);
static void Cdd_Safety_ShutRemotecores(void);

#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

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
 * ErrorMgr_enErrorNo: Integer in interval [0...4294967295]
 * ErrorMgr_enErrorNo: Integer in interval [0...4294967295]
 * ErrorMgr_enErrorStatus: Integer in interval [0...4294967295]
 * ErrorMgr_enErrorStatus: Integer in interval [0...4294967295]
 * SSM_DegradedState: Integer in interval [0...4294967295]
 * SSM_SystemStateDef: Integer in interval [0...4294967295]
 * dtRef_const_VOID: DataReference
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * Arr_2Byte: Array with 2 element(s) of type uint8
 * MpuFltSts: Array with 2 element(s) of type uint8
 * Status: Array with 14 element(s) of type uint8
 *
 * Record Types:
 * =============
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 * SSM_SystemState: Record with elements
 *   SystemState of type SSM_SystemStateDef
 *   DegradedState of type SSM_DegradedState
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_CDD_PMICLastResetReason_BISTStatus_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Arr_2Byte
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 *Rte_CData_CDD_PMICLastResetReason_BISTStatus_DefaultValue(void)
 *     Returnvalue: uint8* is of type Arr_2Byte
 *
 *********************************************************************************************************************/


#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDD_Safety_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_Safety_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Safety_CODE) CDD_Safety_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_Safety_Init
 *********************************************************************************************************************/
  /* DD-ID: {25CE7C13-C183-4049-846C-EA3395865DCA}*/
    VStdLib_MemCpy(Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock, Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock_copy, sizeof(Arr_2Byte));
    Cdd_Safety_SetTSDStatus(SDL_VTM_TSD_NOT_REQ);
	gSdlCddInitExecuted = FALSE;
	Fusa_Application_Init();
	Fusa_Application_RunSelfTest();
	gSdlCddInitExecuted = TRUE;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDD_Safety_MainFunction
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
 *   Std_ReturnType Rte_Read_R_SystemState_SystemState(SSM_SystemState *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpMPUFaultStatus_Sts(const uint8 *data)
 *     Argument data: uint8* is of type MpuFltSts
 *   Std_ReturnType Rte_Write_PpSDLFaultstatus_Sts(const uint8 *data)
 *     Argument data: uint8* is of type Status
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, const ErrorMgr_stAddData *addData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_P_Error_CS_E_NOK
 *   Std_ReturnType Rte_Call_R_Error_QM_ReportErrorStatus1_0_QM(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, const ErrorMgr_stAddData *addData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_P_Error_CS_E_NOK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_CDD_PMICLastResetReason_BISTStatus_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_Safety_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Safety_CODE) CDD_Safety_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_Safety_MainFunction
 *********************************************************************************************************************/
  /* DD-ID: {8A352FE1-2FD7-468b-9188-4027706BD2A6}*/
    /* DD-ID: {8A352FE1-2FD7-468b-9188-4027706BD2A6}*/	/* DD-ID: {7C57CF8E-D0F6-4f1c-AA99-6C9468F1872B}*/	/* DD-ID: {C0C4C0CA-0796-474a-8C0B-0C770F3A6F55}*/	/* DD-ID: {43ED808E-3E44-45da-9772-7E0DDDD56170}*/	/* DD-ID: {435A661A-438B-4975-9DFC-4D3DF5B51A8C}*/	/* DD-ID: {135DA6E6-8E5F-431e-AE74-F7923F9122C0}*/																	
	/* DD-ID: {FED0F473-A3AC-4ae7-948E-D750D6F5E739}*/	/* DD-ID: {887D3D68-3184-40c5-911E-922CC7293886}*/	/* DD-ID: {A9D6E445-3EE3-470f-9071-393F9D655A76}*/	/* DD-ID: {791FFA01-925B-429b-AA82-E557236E4CA0}*/	/* DD-ID: {4DE8BA95-5590-43b2-B570-F0C9242C875E}*/	/* DD-ID: {BF8E4703-47D6-4bf0-818D-E18DF9512E85}*/																	
	/* DD-ID: {7AC7AD45-251C-414d-8E14-A0E0029AC631}*/	/* DD-ID: {ACE8C2D3-2DD0-4333-AD7E-C56C8AE12AA3}*/	/* DD-ID: {11F2889B-A988-4bbe-8D71-650FC6E09EBD}*/	/* DD-ID: {8024ACB3-F50F-4d5e-8C52-352C7FA530D4}*/	/* DD-ID: {35C3577F-7D82-4de9-98C4-D26F4C26ACEA}*/	/* DD-ID: {9217A471-525D-483a-BF45-776F78CB6891}*/															
	/* DD-ID: {7C56AA03-137A-493a-B538-ACE9A696DCDE}*/	/* DD-ID: {F1593186-CC5E-4719-832B-37C16574D584}*/	/* DD-ID: {9AA76CC9-9E62-4cd2-AC23-348F3CD3D575}*/	/* DD-ID: {EFDFFF3A-EC52-4806-A7B0-3E713049FA8D}*/	/* DD-ID: {7F1531CE-7AC1-4f0a-845C-96C99AB905CC}*/	/* DD-ID: {19434516-FA3A-4f11-A7A8-BC49675F1075}*/																	
	/* DD-ID: {CD24AAED-25BC-4a49-9319-C8AC0358663B}*/	/* DD-ID: {26CB1BDB-D49C-4475-B77B-F17C5C7A4328}*/	/* DD-ID: {FA38F930-86FA-4a3b-ACDB-D0A47A31E65A}*/	/* DD-ID: {F0E5490C-7F89-4e29-A339-832E14DBC30C}*/	/* DD-ID: {D3AFC1DC-9982-4f38-956A-7A4336A69CE4}*/	/* DD-ID: {AEAFB3D8-3079-42de-86A5-07F11367CC7B}*/																	
	/* DD-ID: {98BC7D1B-A827-4584-92B8-0F6CF6C28D8F}*/	/* DD-ID: {03600C4C-9FF8-4f3f-A889-B6719EC33605}*/	/* DD-ID: {C4D03B5C-B4D6-4d81-91EA-1390BEC1C844}*/	/* DD-ID: {DD8159CB-20AA-4a10-B476-11284BA99842}*/	/* DD-ID: {07961B94-71D2-4fb1-84DD-C78C4171CA1E}*/	/* DD-ID: {7903702C-5414-4250-A009-78D613EE6F85}*/															
	/* DD-ID: {905010AA-CE5E-432e-811E-F6CF7CA9B084}*/	/* DD-ID: {20BC2AA8-1256-4f49-83D9-B36004EE7756}*/	/* DD-ID: {E4E0F2C9-24F9-4f06-AF5C-0ED3CE27D6C9}*/	/* DD-ID: {C1819778-DA2E-4987-A48E-9335EA8B3D5B}*/	/* DD-ID: {A0F29A56-4FCD-48f1-990A-9E5D0BC36434}*/	/* DD-ID: {A6FAF4B8-939B-4f5b-BFA8-89AD47423C25}*/																	
	/* DD-ID: {6844E64F-7E26-4ff3-850F-0110EC53B4B3}*/	/* DD-ID: {0385C6D1-451F-4886-9788-08B6448FA7D3}*/	/* DD-ID: {A32B021D-64D4-4ef0-B977-4B5B861B5099}*/	/* DD-ID: {BC4BF30C-C92E-42cd-824B-16CCFE94C2E7}*/	/* DD-ID: {507CDE82-FD85-4869-9F9F-5B0353203C3A}*/	/* DD-ID: {73B24F6E-2FAC-4935-93C5-31E1F7E13A6D}*/																	
	/* DD-ID: {626042D5-9EE2-4787-8F62-71D6945BFEC8}*/	/* DD-ID: {5F68EBC0-D2BE-429d-889E-7B543FC6B45C}*/	/* DD-ID: {B46FDA47-355E-49c7-B18A-7BA3C5749DB7}*/	/* DD-ID: {07C5D8D5-1BCA-4b01-92F5-A52D6B35E178}*/	/* DD-ID: {95972E1E-1BDB-4460-8CC0-9AF25EC33EA4}*/	/* DD-ID: {887BBCC3-D236-44cd-A976-65E8541388CD}*/															
	/* DD-ID: {E46DDC14-BCAE-4002-9A25-40E21CC9A237}*/	/* DD-ID: {E04736ED-A4BA-4900-A682-2FCC9377DBE9}*/	/* DD-ID: {03A33EC6-5856-4232-BDFE-ADF91BEB8294}*/	/* DD-ID: {48619A84-B55F-4fbc-B7D2-0D0D014BBCF7}*/	/* DD-ID: {1EC63D2C-57FE-4466-B9AC-44AFAB9CC037}*/	/* DD-ID: {35718FD7-1AD9-41aa-9A1B-33494EDDA7CA}*/																	
	/* DD-ID: {E7745DD0-BB4E-4fc7-8EB6-D064E2248541}*/	/* DD-ID: {2D288FBD-C752-4aab-AD31-EB49408EDD8A}*/	/* DD-ID: {C0616524-84CC-4e07-B370-5753E56240A1}*/	/* DD-ID: {3FCB831B-3431-44c2-A97D-472048310478}*/	/* DD-ID: {0F5D9FFF-4C63-4c10-91B5-E69E5D743111}*/	/* DD-ID: {037621EE-791E-4063-B432-14F07F5A7587}*/																	
	/* DD-ID: {82A01098-2C1B-4ffd-9EF2-7E91BBF62BC7}*/	/* DD-ID: {C1CC9432-AB1F-4331-9FF0-754F05C94827}*/	/* DD-ID: {2D836FA5-6695-47fc-B822-63D2B3080F3E}*/	/* DD-ID: {EAE9C895-DF15-4a6c-84C0-0EBB3014D3CC}*/	/* DD-ID: {17E1C321-3668-4b8c-A0EE-00530248BBA2}*/	/* DD-ID: {F8A19847-1F18-4eb1-AD97-08438F616AF2}*/																
	/* DD-ID: {D1757EC0-DDD1-465d-BC3D-935A5721231B}*/	/* DD-ID: {84C40C66-7858-4e99-A258-E18E1D6B35AD}*/	/* DD-ID: {1EB5CC1C-E7CB-465a-AF61-9BBEEB9ACD04}*/	/* DD-ID: {0458A721-0A4F-4b2d-8A90-D9D77C87EB2A}*/	/* DD-ID: {CF0D38B3-672D-4a28-A577-A8217E6F1E5B}*/	/* DD-ID: {BABABE9A-65E1-4e15-A25E-68F7438092B9}*/																	
	/* DD-ID: {C238CB36-E96C-49c2-957C-AC8D23620ACC}*/	/* DD-ID: {929C811D-96AB-43f3-98AA-6529447C38D3}*/	/* DD-ID: {C2F6015A-60DC-4358-837A-866B86A90AE9}*/	/* DD-ID: {29A7C356-DC69-4a03-B66A-135CAFC51924}*/	/* DD-ID: {CA04C7C1-FE6C-48a7-8D8C-A66BEDE4BF67}*/	/* DD-ID: {6230AE22-E4D3-4c03-B948-FBAE441141C8}*/																	
	/* DD-ID: {9F4A4663-8CEE-4291-B76E-31E976E26A12}*/	/* DD-ID: {CEFF9E1B-BD44-4b02-88F7-4123DD964F2F}*/	/* DD-ID: {3328B28B-09D5-4076-B643-02348A808A49}*/	/* DD-ID: {F9471BF2-6709-463d-A3E9-856A342C3530}*/	/* DD-ID: {D2925469-E783-400e-8D11-D4DE7C7C7C29}*/	/* DD-ID: {0EAA4EDA-15C4-45b8-8EAC-A78816404BED}*/	  
	/* DD-ID: {9E6E2120-0CDD-4cff-8C3A-B3167B775824}*/	/* DD-ID: {B8165CA8-22E7-4025-9906-EC83B15951E2}*/	/* DD-ID: {8F3853CA-FF9B-450c-B38E-6AB379099FF6}*/  /* DD-ID: {87C5A4EB-A5F9-4b2d-9D68-8C8A775F8E2B}*/	/* DD-ID: {81D2AF48-75F3-42bb-9897-56AAFA26FBD3}*/	/* DD-ID: {F27F8858-563E-410b-AAAA-EA66D2BB0B40}*/    
	/* DD-ID: {708DE9FF-0525-48a1-B79C-6091838EE0E3}*/	/* DD-ID: {EC1E010D-0468-4361-9351-A4A44009B6C8}*/	/* DD-ID: {DDBE6820-7976-4586-88C1-5ED52AD00EFC}*/  /* DD-ID: {89F4F226-DAD8-4567-93EF-F0AE07E9799F}*/	/* DD-ID: {9D397850-36A5-4787-80B1-4997EC61939F}*/	/* DD-ID: {525D34FA-F762-4eac-A420-E48005436F89}*/  
	/* DD-ID: {31BD56D4-EC58-4c1b-BCA5-634EE0051450}*/	/* DD-ID: {7C9D86BE-2B0B-42e9-8446-06751437EB61}*/	/* DD-ID: {442FBB8C-C477-4d53-8474-E1FA34E9C732}*/	/* DD-ID: {F912084E-DF1D-4cf3-A286-9D8BFEBE9A76}*/	/* DD-ID: {36F09078-7464-4fc4-B84F-0DF9ABB65B98}*/	/* DD-ID: {E8758B6C-93A8-48e2-9B4E-5759F0C3596E}*/
	/* DD-ID: {EC30F036-A662-4f7d-B781-FF00A3984A18}*/	/* DD-ID: {32ACE727-E1E8-4d70-B68C-2290981A3143}*/	/* DD-ID: {DFA08EB3-0EB5-4116-B09A-0C960D8744E9}*/	/* DD-ID: {3B4710DB-BDF5-4edd-A62B-567A810E5579}*/	/* DD-ID: {6066D266-4350-4fea-AF90-346BB9835118}*/	/* DD-ID: {1A72D07D-6CED-47d7-A7BC-0D06DF5F36F9}*/
	/* DD-ID: {F2CDD6C1-D00B-4f41-8BF6-EB0D8D6E5B21}*/	/* DD-ID: {40E2368A-917A-43dd-B0F6-FE3650E56C53}*/	/* DD-ID: {8B47CB07-C915-4d68-8269-EA442E3EFC9F}*/	/* DD-ID: {929029AE-8C0D-49e6-B23F-BD559F8EA6EE}*/	/* DD-ID: {EF978070-68B7-4722-AA97-2DF02D9F0296}*/	/* DD-ID: {2629A7A1-8E98-4c75-96FF-0FB0510CDB6C}*/
	/* DD-ID: {58965DCC-F3BD-427a-8B3E-3036C0F10609}*/	/* DD-ID: {C2B68998-BD5C-406c-B281-05EB36C97F47}*/	/* DD-ID: {E8C69348-ADE0-4f2e-946E-F3EE812E2184}*/	/* DD-ID: {38D1770D-81E2-4db4-938F-FA4918318DB1}*/	/* DD-ID: {7B5EE680-3E0E-4fdb-9FE8-7FF7D8882B33}*/	/* DD-ID: {5B41FE4E-28FF-4667-9C59-6604380153F0}*/
	/* DD-ID: {663D91CE-61BA-4ca5-9FA8-4C168E2117D7}*/	/* DD-ID: {C98D000F-3B18-4f11-B85A-30CC5956124D}*/	/* DD-ID: {0097047C-7503-4a3d-BA0B-2CB31B02F877}*/	/* DD-ID: {9BEE4DDF-2138-4d71-9364-FF1DDF7348E7}*/	/* DD-ID: {D36F4293-F4DE-4583-BFED-9E57EE0093F5}*/	/* DD-ID: {F615AEA6-74D5-4015-90A1-E7E08C8E1E47}*/
	/* DD-ID: {86AD616A-62EA-428e-902A-7666934F088D}*/	/* DD-ID: {41D21589-C26A-4dc8-8D2E-B7F8D06F9F43}*/	/* DD-ID: {F2735F9A-9B64-4d0c-BA47-87FA0098887C}*/	/* DD-ID: {7DEE5CE1-9868-435e-A4D6-84C221A2665D}*/	/* DD-ID: {B65804F8-EEB8-44ba-B0BB-2583C7345C3D}*/	/* DD-ID: {B064BFD1-51FB-4c5f-9E74-4E4EDC0650CE}*/
	/* DD-ID: {DB977AC9-6F12-426d-B758-AAF791314828}*/	/* DD-ID: {977781F8-8DE2-479c-AE69-FFBB7751EF44}*/	/* DD-ID: {693CE487-BCFE-4dc8-9354-7A509A27EE14}*/	/* DD-ID: {368FB65D-8366-48bc-A49D-C10125884885}*/	/* DD-ID: {766201B7-1EF3-4b63-9409-41E9C5B356B0}*/	/* DD-ID: {70256EBC-BFBE-4c46-BB85-C347906903AD}*/
	/* DD-ID: {47D1E138-FBA6-408d-ADE1-B494C87EE8BF}*/	/* DD-ID: {0A2B25C6-2EA3-43b4-BC30-4BE17D4EAAB0}*/	/* DD-ID: {6277CAFE-0E28-4bf8-B40D-62CC6195D5B8}*/	/* DD-ID: {942334DD-DD0B-4fdf-AF7B-D5244BECC79A}*/	/* DD-ID: {05B172C0-AC1C-4b50-9B93-0D48F6249D63}*/	/* DD-ID: {FAB137F4-18E2-4789-BE70-DD80155D8ECF}*/
	/* DD-ID: {8767FA97-483F-4645-8C8E-A84CA87C452F}*/	/* DD-ID: {76E7969F-93A1-473b-9C20-1D15BF0E340F}*/	/* DD-ID: {6DA05701-3B8E-451e-BD3B-C2CFED6412B7}*/	/* DD-ID: {19251E70-FA36-439f-AB29-A7031AC86676}*/	/* DD-ID: {DF68AA4A-9646-45f6-9F4F-427E9B67090D}*/	/* DD-ID: {12A3B8BE-6CD1-4cb0-AFCA-110461BD3ABB}*/
	/* DD-ID: {DC496BE5-3362-409f-BD20-20A25F713164}*/	/* DD-ID: {8DCAB825-6F97-48ed-8518-0D49E1241B19}*/	/* DD-ID: {E107D75E-DF3F-4cc5-BC42-21B771926EBC}*/	/* DD-ID: {FB0DB5FB-048F-4e04-B5B7-9ECB2C82047C}*/	/* DD-ID: {240AEA28-6971-43ff-A889-78D149EA7E14}*/	/* DD-ID: {BC8DF973-50D5-4176-B39E-6DD5EF16B5F0}*/
	/* DD-ID: {4737DB4D-122A-4aaa-BA3D-94E840811196}*/	/* DD-ID: {9EA662A0-B236-407b-8EA5-B01F023CE981}*/	/* DD-ID: {8F15D85F-3839-4f9c-80EC-DD7EA11D0F35}*/	/* DD-ID: {1EA12850-6AF4-446c-8CA5-35CDF0259B74}*/	/* DD-ID: {AACD1AF1-BD2F-4f40-9C8E-69360AAAE1FA}*/	/* DD-ID: {022721EE-8E23-48a3-8D4E-CD49E6675EA2}*/
	/* DD-ID: {4FB05CA4-4981-4250-8C4D-FCE44A9864C9}*/	/* DD-ID: {80D2B27D-6D7C-4fc4-971B-7FC81776FED0}*/	/* DD-ID: {EE42B71B-7E95-43be-8623-F21F5F5C3164}*/	/* DD-ID: {A7236887-7EEF-4e7b-96EE-67CE73E44AB9}*/	/* DD-ID: {2B687366-B9D1-4825-A79D-90F23A97F7E0}*/	/* DD-ID: {4F5C9B2C-C351-4dec-B836-AC4E9875CED8}*/
	/* DD-ID: {8EDB4633-1E9C-44e6-8365-F99FD2E3FDED}*/	/* DD-ID: {3BED064B-4E3E-4914-982E-936D241376B9}*/	/* DD-ID: {B5103FC0-AA8A-4ba6-85DA-02C423A9AB48}*/	/* DD-ID: {8FF59EA8-C52E-4c08-8188-C65EDF75E75E}*/	/* DD-ID: {03E6531F-CFA4-44ba-BF75-195F29A8AB1A}*/	/* DD-ID: {153EA0D3-D49F-4f91-8876-8D46810237DB}*/
	/* DD-ID: {CA1BA8BD-23ED-4488-A6EF-09EE40A5C36F}*/	/* DD-ID: {925D3874-725B-4433-BDD8-B3E6272DC46D}*/	/* DD-ID: {68881CC6-ACA3-4c3a-B716-ACF32B4D6B66}*/	/* DD-ID: {BCC72319-8C85-4e4d-B2C5-5EE70912F957}*/	/* DD-ID: {BBAC7126-C90D-4da0-BABC-6A527CDEF686}*/	/* DD-ID: {81D612C5-A48F-4439-94D6-2454C8D34036}*/
	/* DD-ID: {6531B23C-CBC2-447a-93B0-CC89C1D1F3B6}*/	/* DD-ID: {BC0C7DF3-AD88-4d86-9665-03274E8ACE69}*/	/* DD-ID: {C9FC4CE6-293A-44d5-B488-AACB179115E8}*/  /* DD-ID: {1A35B21E-27C4-4de5-8226-298C04D33421}*/	/* DD-ID: {7282165D-ACAC-47e8-BE78-FC4DC9B71D50}*/	/* DD-ID: {016F4BAB-FA9E-491d-9A2D-9718ACD69B07}*/
	/* DD-ID: {54588FC1-7FC5-42c8-AA55-B698B72EB435}*/	/* DD-ID: {00F2786B-4876-46de-8EC7-C1409E16A3D6}*/	/* DD-ID: {C891A0BE-6D34-43dc-B8D2-1301DAEBA8E8}*/  /* DD-ID: {02611E1A-DF6C-4420-8348-A23FE0C40043}*/	/* DD-ID: {0BC570B8-DFE1-499f-A245-1B8C84EAE635}*/	/* DD-ID: {E4822A6F-398A-4984-98E4-5C193D0B0DA3}*/
	/* DD-ID: {CACC6814-CB38-435d-8C76-66295743E614}*/	/* DD-ID: {7C700AF7-792D-4a09-B617-FCC670F81BD5}*/	/* DD-ID: {422FECA1-77C7-4632-B233-AE6B44F9AAA7}*/  /* DD-ID: {540E6448-F7DE-46b1-BA37-E811C354ACED}*/	/* DD-ID: {B7BA8A88-3897-46d1-BB54-F0FEBC742B2C}*/	/* DD-ID: {53F3413E-A1FF-41e4-9709-127E1799E412}*/
	/* DD-ID: {B9A04090-CC03-483c-8FD9-CD1221882A46}*/	/* DD-ID: {4AC2575C-B3FF-46bb-9871-20E1984B4309}*/	/* DD-ID: {2B5BC41D-A470-4c46-917B-7F73FBC0F225}*/  /* DD-ID: {433801B4-1630-49bf-98DC-D606458B1156}*/	/* DD-ID: {C77617D8-971E-4974-95A8-1CE0040AF6F3}*/	/* DD-ID: {9BF08311-B7DE-4712-9C6E-70E941F162C9}*/
	/* DD-ID: {6555FA27-07B6-4f90-8694-72D4D99966AF}*/	/* DD-ID: {4F6BFDC3-2D95-453e-9855-4B755C315FC4}*/	/* DD-ID: {1FCF1FA8-C63C-48b3-800D-83EFA3867EEF}*/  /* DD-ID: {7F0CAFD8-B0F7-4a9c-BA8C-036EA29635A7}*/	/* DD-ID: {CFC36045-4317-414b-AE7D-63FE40F69C26}*/	/* DD-ID: {1ADE3F7E-4E1E-4932-A0E9-8A3F0ECAC66D}*/
	/* DD-ID: {54FFFA82-CEBF-4cbc-B5D3-631B6030BCB8}*/	/* DD-ID: {4A1E796B-6B9D-468f-AEF5-7FE92D983636}*/	/* DD-ID: {E0DF504F-BC07-47a9-8C26-7CDBEB61952D}*/  /* DD-ID: {AD618828-6443-4ce2-A49A-DC1BA91909D8}*/	/* DD-ID: {4E62F409-BA4A-404a-964C-DC09B3244953}*/	/* DD-ID: {43BAD899-8CE3-4bb7-8F12-431661B1A2B7}*/
	/* DD-ID: {9097707D-87B7-48ea-A1CC-F9F09604809C}*/	/* DD-ID: {D0E7C017-29ED-4743-A020-2D76D6D5226A}*/	/* DD-ID: {D6CC9574-100C-43bb-8DB1-0287885A7A82}*/  /* DD-ID: {6C0E2F9D-7C0C-4f2d-A7F3-3DD956870C5D}*/	/* DD-ID: {C69605DB-9455-4c56-8219-D33207B7E549}*/	/* DD-ID: {0837A40C-C063-45d1-96A2-1DF9934871EB}*/
	/* DD-ID: {5BEFA57F-D2E1-408c-B98A-9BD38399BF76}*/	/* DD-ID: {ECF0F829-CE3F-4268-991A-53D269FAF5A2}*/	/* DD-ID: {F655E974-0D79-41f2-98FA-072E88AF7701}*/  /* DD-ID: {46BD2287-91DA-4300-9350-7651836BEFB6}*/	/* DD-ID: {0835413C-CE27-43de-9C32-D5752D8773A2}*/	/* DD-ID: {C26F6C65-B727-4c9f-81A9-4929C4459BB3}*/
	/* DD-ID: {A6DBACFD-C2DC-4241-94A6-3162929325A6}*/	/* DD-ID: {CA225D66-9356-4d84-9B95-AA72300E93BB}*/	/* DD-ID: {A213806E-25ED-4251-8C27-96CCEB34776A}*/  /* DD-ID: {E473A648-75E3-4863-9C65-110309849987}*/	/* DD-ID: {9F7EB776-1492-4e10-B490-37F607F416C4}*/	/* DD-ID: {C98AD3BD-89B1-4861-86C3-CB14E630581A}*/
	/* DD-ID: {B3114D60-D986-4d0a-99AC-1117DA21EF0E}*/	/* DD-ID: {0FF0E6F3-B0F4-4f2f-BBAB-2E2E562DC8AE}*/	/* DD-ID: {9FB9D39A-DD2A-4714-92FA-4847F7ABFC0F}*/  /* DD-ID: {09A89A68-2DEF-43d0-AA74-A5CF3503C368}*/	/* DD-ID: {5632F1CB-6A85-480e-AEAD-5006C705EA76}*/	/* DD-ID: {7EC0BB99-ED8E-46d0-ACB6-6A110A13C2C4}*/
	/* DD-ID: {60B8542A-BAEB-4728-9501-5AC7CE04100C}*/	/* DD-ID: {641D6709-990D-412e-B87D-2967A2543737}*/	/* DD-ID: {FF0349D0-524A-4c65-B313-9E88E79CF478}*/  


	ErrorMgr_stAddData SDL_AddtionalData_au8 = {0u};
	uint8_t PLLreadbackErrorFlag = 0x00u;
	uint8_t DccErrorFlag = 0x00u;
	static uint8_t cdd_safety_ErrorLog[e_errLog_Max] = {0u};
	static uint8_t cdd_safety_ErrorADC = 0u;
	static uint8_t cdd_safety_ErrorGPIO = 0u;
	static uint8_t cdd_safety_ErrorRESET = 0u;
	static uint8_t cdd_safety_ErrorMMR = 0u;
	static uint8 gSdlCddMainFunctionCounter = 0u;
	static uint8_t faultStatus  = 0u;

	if(gSdlCddInitExecuted == TRUE)
	{
		/* Monitor for TSD */
		Cdd_Safety_ShutRemotecores();
		if(false == cdd_safety_BistSSEn)
		{
			Cdd_Safety_SS_ShutDownTest();
		}
		Fusa_Application_MainFunction();

		if(gSdlCddMainFunctionCounter >= SDL_CDD_ERROR_MANAGER_REPORT_TIME_EXPIRED)
		{
			faultStatus = Fusa_Application_GetCcmErrorFlag();
			if(FAULT_STATUS_OK != faultStatus)
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_MCU_R5F_Failure_reported_Lockstep_core, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
				Fusa_Application_ClearCcmErrorFlag();
				/* Report error to CAN msg */
				f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_MCU_R5F_Failure_reported_Lockstep_core);

			}

			faultStatus = Fusa_Application_GetCcmSafetyCriticalConfigFailFlag();
			if(FAULT_STATUS_OK != faultStatus)
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_MCU_R5F_CPU_Configuration_registers_readback_error, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
				Fusa_Application_ClearCcmSafetyCriticalConfigFailFlag();
				/* Report error to CAN msg */
				f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_MCU_R5F_CPU_Configuration_registers_readback_error);
				/* Report error to CAN msg */
				f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_MCU_R5F_CPU_Configuration_registers_readback_error);
			}

			faultStatus = Fusa_Application_GetAdcSafetyCriticalConfigFailFlag();
			if(FAULT_STATUS_OK != faultStatus)
			{
				Fusa_Application_ClearAdcSafetyCriticalConfigFailFlag();
				cdd_safety_ErrorADC = TRUE;
			}

			faultStatus = Sdl_Application_GetDDRSafetyCriticalConfigFailFlag();
			if(FAULT_STATUS_OK != faultStatus)
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_DDRSS0_DDRSS_registers_readback_error,ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
				Sdl_Application_ClearDDRSafetyCriticalConfigFailFlag();

				/* Report error to CAN msg */
  				f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_Main_DDRSS0_DDRSS_registers_readback_error);

			}

			faultStatus = Fusa_Application_GetCbassSafetyCriticalConfigFailFlag();
			if(FAULT_STATUS_OK != faultStatus)
			{
				faultStatus = Fusa_Application_GetCbassSafetyCriticalConfigFailFlag();
				if(FAULT_STATUS_NOK == faultStatus)
				{
					(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_CBASS_Mismatch_registers, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
					Fusa_Application_ClearCbassSafetyCriticalConfigFailFlag();
					/* Report error to CAN msg */
					f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_Main_CBASS_Mismatch_registers);

				}
				else
				{
					(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_MCU_CBASS_Mismatch_registers, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
					Fusa_Application_ClearCbassSafetyCriticalConfigFailFlag();
					/* Report error to CAN msg */
  					f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_MCU_CBASS_Mismatch_registers);

				}
			}
			
			faultStatus = Fusa_Application_GetResetSafetyCriticalConfigFailFlag();
			if(FAULT_STATUS_OK != faultStatus)
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_MCU_Reset_Reset_Configuration_registers_error, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
				Fusa_Application_ClearResetSafetyCriticalConfigFailFlag();
				cdd_safety_ErrorRESET = TRUE;
				/* Report error to CAN msg */
		  		f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_MCU_Reset_Reset_Configuration_registers_error);

			}

			faultStatus = Fusa_Application_GetGpioSafetyCriticalConfigFailFlag();
			if(FAULT_STATUS_OK != faultStatus)
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_MCU_GPIO_ConfigReg_Mismatch, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
				Fusa_Application_ClearGpioSafetyCriticalConfigFailFlag();
				cdd_safety_ErrorGPIO = TRUE;
				/* Report error to CAN msg */
				f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_MCU_GPIO_ConfigReg_Mismatch);

			}

			faultStatus = Fusa_Application_GetMcuWkupMMRSafetyCriticalConfigFailFlag();
			if(FAULT_STATUS_OK != faultStatus)
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_MCU_MMR_MCUCtrl_WKUPCtrl_Mismatch, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
				Fusa_Application_ClearMcuWkupMMRSafetyCriticalConfigFailFlag();
				cdd_safety_ErrorMMR = TRUE;
				/* Report error to CAN msg */
				f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_MCU_MMR_MCUCtrl_WKUPCtrl_Mismatch);

			}

			faultStatus = Fusa_Application_GetMainMMRSafetyCriticalConfigFailFlag();
			if(FAULT_STATUS_OK != faultStatus)
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_MMR_CTRL_MMR0_Mismatch, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
				Fusa_Application_ClearMainMMRSafetyCriticalConfigFailFlag();
				cdd_safety_ErrorMMR = TRUE;
				/* Report error to CAN msg */
				f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_Main_MMR_CTRL_MMR0_Mismatch);

			}

			faultStatus = Fusa_Application_GetEsmSafetyCriticalConfigFailFlag((uint8)0);
			if(FAULT_STATUS_OK != faultStatus)
			{
				/*(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_MCU_ESM_Mismatich_WKUP_ESM0_configuration_registers, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);*/
				Fusa_Application_ClearEsmSafetyCriticalConfigFailFlag((uint8)0);
				f_Send_Dbg_SDLFault_CanTx((uint16)ERR_SAFESTATE_REASON_SDL_ESM_WKUP_REG);
				Pmic_F_SafeState2_v(SAFESTATE_REASON_SDL_ESM_WKUP_REG);
			}

			faultStatus = Fusa_Application_GetEsmSafetyCriticalConfigFailFlag((uint8)1);
			if(FAULT_STATUS_OK != faultStatus)
			{
				/*(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_MCU_ESM_Mismatich_MCU_ESM0_configuration_registers, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);*/
				Fusa_Application_ClearEsmSafetyCriticalConfigFailFlag((uint8)1);
				f_Send_Dbg_SDLFault_CanTx((uint16)ERR_SAFESTATE_REASON_SDL_ESM_MCU_REG);
				Pmic_F_SafeState2_v(SAFESTATE_REASON_SDL_ESM_MCU_REG);
			}

			faultStatus = Fusa_Application_GetEsmSafetyCriticalConfigFailFlag((uint8)2);
			if(FAULT_STATUS_OK != faultStatus)
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_ESM_Mismatich_ESM0_configuration_registers, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
				Fusa_Application_ClearEsmSafetyCriticalConfigFailFlag((uint8)2);

				/* Report error to CAN msg */
				f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_Main_ESM_Mismatich_ESM0_configuration_registers);

			}

#if ( SDL_APP_MSMC_ENABLED == SDL_APP_ON )
			faultStatus = Sdl_Application_GetMSMCCfgErrorFlag();
			/* Periodically check for MSMC register configurations Error Flag */
			if(FAULT_STATUS_OK != faultStatus)
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_MSMC_Config_Register_Mismatch,ErrorMgr_ErrorActive,(const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
				Sdl_Application_ClearMSMCCfgErrorFlag();

				 /* Report error to CAN msg */
				f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_Main_MSMC_Config_Register_Mismatch);

			}
#endif

			faultStatus = Fusa_Application_Get_Overtemperature_detected();
			if( SDL_VTM_TSD_DETECTED == faultStatus)
			{
				/*VTM detected SoC over maximum temp threshold*/
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_VTM_OverTemp_Interrupt,
						ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
				/* Report error to CAN msg */
				f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_Main_VTM_OverTemp_Interrupt);

			}

			faultStatus = Fusa_Application_Get_Configuration_readback_error_VTM_registers();
			if ( (uint8)0xFF == faultStatus )
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_VTM_Registers_Mismatch, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
				/* Report error to CAN msg */
				f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_Main_VTM_Registers_Mismatch);
			}
			else
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_VTM_Registers_Mismatch, ErrorMgr_ErrorInactive, (const ErrorMgr_stAddData*)&SDL_AddtionalData_au8);
			}

			faultStatus = Sdl_Application_GetClkDetErrorFlag();
			if (FAULT_STATUS_OK != faultStatus)
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_MCU_Clock_Loss_input_detected, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData *)&SDL_AddtionalData_au8);
				/* Report error to CAN msg */
  				f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_MCU_Clock_Loss_input_detected);

				Sdl_Application_ClearClkDetErrorFlag();
			}

			faultStatus = Sdl_Application_GetPllSlipMcuErrorFlag();
			if (FAULT_STATUS_OK != faultStatus)
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_MCU_Clock_PLL_slip_detected, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData *)&SDL_AddtionalData_au8);
				Sdl_Application_ClearPllSlipMcuErrorFlag();
				 /* Report error to CAN msg */
			  f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_MCU_Clock_PLL_slip_detected);

			}

			faultStatus = Sdl_Application_GetPllSlipMainErrorFlag();
			if (FAULT_STATUS_OK != faultStatus)
			{
				(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_Clock_PLL_slip_detected, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData *)&SDL_AddtionalData_au8);
				Sdl_Application_ClearPllSlipMainErrorFlag();
				 /* Report error to CAN msg */
  			f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_Main_Clock_PLL_slip_detected);

			}

			faultStatus = Sdl_Application_GetMcuDCCErrorFlag();
			if(FAULT_STATUS_OK != faultStatus)
    		{
    		    (void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_MCU_Clock_reference_error, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData *)&SDL_AddtionalData_au8);
    		    Sdl_Application_ClearMcuDCCErrorFlag();
						 /* Report error to CAN msg */
  				f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_MCU_Clock_reference_error);

    		}

			faultStatus = Sdl_Application_GetMainDCCErrorFlag();
    		if(FAULT_STATUS_OK != faultStatus)
    		{
    		    (void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_Domain_clock_reference_error, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData *)&SDL_AddtionalData_au8);
    		    Sdl_Application_ClearMainDCCErrorFlag();
						 /* Report error to CAN msg */
  f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_Main_Domain_clock_reference_error);

    		}

    		PLLreadbackErrorFlag = Sdl_Application_GetPLLreadbackErrorFlag();
    		DccErrorFlag = Sdl_Application_GetDccErrorFlag();
    		if((FAULT_STATUS_OK != PLLreadbackErrorFlag) ||
    		   (FAULT_STATUS_OK != DccErrorFlag))
    		{
    			(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_Configuration_registers_of_CLK_CTRL_and_PLL_readback_error, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData *)&SDL_AddtionalData_au8);
    			Sdl_Application_ClearPLLreadbackErrorFlag();
    			Sdl_Application_ClearDccErrorFlag();
    			/* Report error to CAN msg */
    			f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_Main_Configuration_registers_of_CLK_CTRL_and_PLL_readback_error);

    		}

			Fusa_Application_GetLogErrorForDID((uint8_t *)&cdd_safety_ErrorLog[0]);
			cdd_safety_ErrorLog[e_errLog_MCRC] = cdd_safety_ErrorADC;
			cdd_safety_ErrorLog[e_errLog_Reserved1] = cdd_safety_ErrorRESET;
			cdd_safety_ErrorLog[e_errLog_Reserved2] = cdd_safety_ErrorGPIO;
			/* cdd_safety_ErrorLog[e_errLog_MMR] = cdd_safety_ErrorMMR;  
			   * Enable after DID spec update ***/
			(void)Rte_Write_PpSDLFaultstatus_Sts((uint8_t *)&cdd_safety_ErrorLog[0]);

			gSdlCddMainFunctionCounter = (uint8_t)0;
		}
		else
		{
			gSdlCddMainFunctionCounter += (uint8_t)SDL_CDD_MAIN_TASK_RATE;
		}
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}




/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
void Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus(uint8_t index, uint8_t Data, uint8_t storeAtShut)
{
  /* DD-ID: {919A470F-5787-41f3-9E1C-3E3299F98B92}*/
	Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock[index] = Data; /* 0: PMIC Last Reset Reason, 1:  BIST Status */
	VStdLib_MemCpy(Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock_copy, Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock, sizeof(Arr_2Byte));
	if(TRUE == storeAtShut)
	{
		(void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_CDD_SafetyCDD_PMICLastResetReason_BISTStatus, TRUE);
	}
	else
	{
		(void)Rte_Call_NvMService_AC3_SRBS_CDD_PMICLastResetReason_BISTStatus_WriteBlock(Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock_copy);
	}
}

void Cdd_Safety_NVM_Read_PMICLastResetReason_BISTStatus(uint8_t index, uint8_t *Data)
{
 /* DD-ID:{56C9C6E0-1FD1-4a5a-9B43-253E8DED6312}*/
 /* DD-ID:{70FDF7E4-0930-4857-A53D-CAB0A9708121}*/
	*Data = Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock_copy[index];
}

int8_t Cdd_Safety_Wait_for_NVM_Write_Status(void)
{
  /* DD-ID: {FF149A10-86DA-4b0c-9B36-19E321E2C83D}*/
	NvM_RequestResultType PMIC_BIST_Status = NVM_REQ_NOT_OK;
	int8_t ret = NVM_WR_PENDING;

	(void)NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_CDD_SafetyCDD_PMICLastResetReason_BISTStatus, &PMIC_BIST_Status);

	if(NVM_REQ_OK == PMIC_BIST_Status)
	{
		ret = NVM_WR_DONE;
	}
	else if(NVM_REQ_PENDING != PMIC_BIST_Status)
	{
		ret = NVM_WR_FAILED;
	}
	else{
		ret = NVM_WR_PENDING;
	}

	return ret;
}

static void Cdd_Safety_SS_ShutDownTest(void)
{
  /* DD-ID: {935D799F-444D-446d-B208-7637579A30BB}*/
    ErrorMgr_stAddData SDL_AddtionalData_au8 = {0u};
    static volatile uint8_t cdd_safety_SM = 0u;

	switch(cdd_safety_SM)
	{
	case 0u:
		if(0x55u == Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock[1])
		{
			Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus(1u, 0x0u, FALSE);
			cdd_safety_SM += 1U;
		}
		else
		{
			/* Do not enter Cdd_Safety_SS_ShutDownTest again */
			cdd_safety_BistSSEn = true;
		}
		break;

	case 1u:
		if(NVM_WR_DONE == Cdd_Safety_Wait_for_NVM_Write_Status())
		{
#ifdef UART_PRINT_ENABLED
			APP_log(APP_LOG_ERR,"\n PBIST NAVSS ShutDown Test Failed during last shutdown\n");
#endif
			cdd_safety_SM = 0u;
			/* Do not enter Cdd_Safety_SS_ShutDownTest again */
			cdd_safety_BistSSEn = true;

			(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_MCU_NAVSS_PBIST_Check_Fail, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData *)&SDL_AddtionalData_au8);
			(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_NAVSS_PBIST_Check_Fail, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData *)&SDL_AddtionalData_au8);
			(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_PBIST_Memory_Err, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData *)&SDL_AddtionalData_au8);
			(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_PBIST_error, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData *)&SDL_AddtionalData_au8);
			(void)Rte_Call_R_Error_B_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_Main_UDMA_PBIST_error, ErrorMgr_ErrorActive, (const ErrorMgr_stAddData *)&SDL_AddtionalData_au8);

			/*Report first error to CAN Debug*/
			f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_MCU_NAVSS_PBIST_Check_Fail);
		}
		break;

	default:
		/* Do Nothing */
		break;
	}
}

void Update_Cdd_Safety_MirrorBlock(boolean Cdd_Safety_Erase_block)
{
  /* DD-ID: {85AE66CE-486D-4e9b-9FB3-7C3E1FA97F3F}*/
  if(TRUE == Cdd_Safety_Erase_block)
  {
    VStdLib_MemCpy(Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock, Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock_copy, sizeof(Arr_2Byte));
  }
  else
  {
    VStdLib_MemCpy(Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock_copy, Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock, sizeof(Arr_2Byte));
  }
}

void Cdd_Safety_SetTSDStatus(uint16_t TSDStatus)
{
  /* DD-ID: {53984BAB-C81C-4d27-A712-56EE39F26C9E}*/
	gSdlTSDStatus = TSDStatus;
}

uint16_t Cdd_Safety_GetTSDStatus(void)
{
  /* DD-ID: {2F738EAA-8D9E-4ad5-A723-D4D56583AB30}*/
	return gSdlTSDStatus;
}

static void Cdd_Safety_ShutRemotecores(void)
{
  /* DD-ID: {F458FD8A-C373-4462-8309-D17FE27AEA39}*/
	SSM_SystemState SSMSystemState;
	uint16_t tsdStatus =  Cdd_Safety_GetTSDStatus();

	/* check if Thermal-shutdown required ?*/
	if(SDL_VTM_TSD_REQ  == tsdStatus)
	{
		/* Read SSM state */
		Rte_Read_R_SystemState_SystemState(&SSMSystemState);
		if(SSMSystemState.SystemState >= (SSM_SystemStateDef)SSM_STATE_RUNNING_i)
		{
			/* Shutdown remote cores through SSM */
			SSM_Master_SetThermalShutDownRequest();
			/* Do not come here again */
			Cdd_Safety_SetTSDStatus(SDL_VTM_TSD_DONE);
		}
	}
}
#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
