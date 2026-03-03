#include "stdint.h"

#include "Compiler.h"
# define DTCManager_CODE
#include "Com_Types.h"
#include "Os.h"

typedef uint8_t uint8;
typedef uint16_t uint16;


  /* call runnable */
void VehicleAdapterTx_Main_10ms(){}

  /* call runnable */
void Runnable_CDD_NmMgmt_Main(){} 

void TerminateTask(){}


void Coding_Main_10ms(void) {}


  /* call runnable */
//void RE_CalDataProvider_Init(){}



  /* call runnable */
void NvM_MainFunction(){}
  
//void AdcApp_Runnable(){}
  
//void EEP_Statemachine(){}


  /* call runnable */
void BswM_MainFunction(){}

  /* call schedulable entity */
void CanTrcv_30_Tja1043_MainFunction(){}

  /* call schedulable entity */
void Can_30_Mcan_MainFunction_Wakeup(){}

  /* call schedulable entity */
void Can_30_Mcan_MainFunction_Mode(){}

  /* call schedulable entity */
void Can_30_Mcan_MainFunction_BusOff(){}

  /* call schedulable entity */
void Can_30_Mcan_MainFunction_Write(){}

  /* call schedulable entity */
//void Rte_ComSendSignalProxyPeriodic(){}

  /* call schedulable entity */
void Com_MainFunctionTx(){}

  /* call schedulable entity */
void CanTp_MainFunctionTx(){}

//void PM_Executeperiodic(){}


  /* call schedulable entity */
void Can_30_Mcan_MainFunction_Read(){}

  /* call schedulable entity */
void CanTp_MainFunctionRx(){}

  /* call schedulable entity */
void Com_MainFunctionRx(){}

  /* call schedulable entity */
void CanNm_MainFunction(){}

  /* call schedulable entity */
void CanSM_MainFunction(){}

//void DIAG_EnbCond_ExecutePeriodic(){}

  /* call runnable */
void Dem_MasterMainFunction(){}

  /* call runnable */
void Dem_SatelliteMainFunction(){}


  /* call runnable */
void ComM_MainFunction_0(){}

  /* call runnable */
void Dcm_MainFunction(){}

  /* call runnable */
void EcuM_MainFunction(){}

  /* call schedulable entity */
void Ea_MainFunction(){}

  /* call schedulable entity */
void Eep_30_XXi2c01_MainFunction(){}

  /* call schedulable entity */
void I2c_MainFunction(){}


  /* call runnable */
void VehicleAdapterRx_Main_10ms(){}

  /* call runnable */
void CDD_IPCDataHndlrPeriodic_10ms(){}

  /* call runnable */
void DIDManager_Main(){}

  /* call runnable */
void DTCManager_Main(){}

  /* call runnable */
void RIDManager_Main(){}

unsigned char Com_ReceiveSignal(unsigned short id, void * SignalDataPtr) 
{
	return 0;
}

unsigned char Com_SendSignal(unsigned short SignalId, void * SignalDataPtr)
{
	return 0;
}

void Os_DisableLevelKM (void)
{
}

void Os_EnableLevelKM (void)
{
}

void SuspendOSInterrupts (void)
{
}

void ResumeOSInterrupts (void)
{
}

void RADAS1(unsigned char activationVector)
{

}

void StartUpShutDownMain_10ms (void)
{
}

/*void Rte_MemCpy32(void * destination, void * source, unsigned int num)
{
  unsigned int * asrc = (unsigned int *)  source; 
  unsigned int *  adst = (unsigned int *)  destination; 
  unsigned char * src = (unsigned char *) source; 
  unsigned char * dst = (unsigned char *) destination; 
  unsigned int i = 0;

  if (num >= 16U)
  {
    if (((((unsigned int)src) & RTE_MEMCPY32ALIGN) == 0U) && ((((unsigned int)dst) & RTE_MEMCPY32ALIGN) == 0U)) 
    {
       unsigned int asize = num / sizeof(uint32);
       unsigned int rem = num & RTE_MEMCPY32ALIGN;
      for (i = 0; i < (asize - 3U); i += 4U)
      {
        adst[i] = asrc[i];
        adst[i+1U] = asrc[i+1U];
        adst[i+2U] = asrc[i+2U];
        adst[i+3U] = asrc[i+3U];
      }

      while (i < asize)
      {
        adst[i] = asrc[i];
        ++i;
      }
      i = num - rem;
    }
    else
    {
      for (i = 0; (i + 15U) < num; i += 16U)
      {
        dst[i] = src[i];
        dst[i+1U] = src[i+1U];
        dst[i+2U] = src[i+2U];
        dst[i+3U] = src[i+3U];
        dst[i+4U] = src[i+4U];
        dst[i+5U] = src[i+5U];
        dst[i+6U] = src[i+6U];
        dst[i+7U] = src[i+7U];
        dst[i+8U] = src[i+8U];
        dst[i+9U] = src[i+9U];
        dst[i+10U] = src[i+10U];
        dst[i+11U] = src[i+11U];
        dst[i+12U] = src[i+12U];
        dst[i+13U] = src[i+13U];
        dst[i+14U] = src[i+14U];
        dst[i+15U] = src[i+15U];
      }
    }

  }
  while (i < num)
  {
    dst[i] = src[i];
    ++i;
  }
}
*/

void ActivateTask(unsigned int TaskId)
{

}

void CancelAlarm(unsigned int Alalrm)
{

}

void SetRelAlarm(unsigned int Alalrm,unsigned int x, unsigned int y)
{

}

void P_CDD_IPCDataHndlr_TxData_CS(void * b_TxData_pv, unsigned short i_IpcMsgId_u16,unsigned short i_IpcMsgSize_u16) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{

}

void Com_MainFunctionRx_ComMainFunctionRx()
{
}

void   ComM_MainFunction_1()
{
}

void WaitEvent(unsigned int val)
{
}




      /* call runnable */
void RE_Periodic_SSM_Slave(){}; /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */


      /* call runnable */
void  RE_Periodic_SSM_Master(){}; /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */


      /* call runnable */
void RE_Periodic_CalDataProvider(){}; /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */


      /* call runnable */
void CDD_EHRCDD_EHR_Periodic_Update_IPC_Data(){}; /* PRQA S 2987 */ /* MD_Rte_2987 */


void Com_MainFunctionTx_ComMainFunctionTx(){};

      /* call schedulable entity */


      /* call runnable */
void SecOC_MainFunctionTx(){}; /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
void SecOC_MainFunctionRx(){}; /* PRQA S 2987 */ /* MD_Rte_2987 */




      /* call schedulable entity */
void Crypto_30_vHsm_MainFunction(){};

      /* call runnable */
void  Csm_MainFunction(){}; /* PRQA S 2987 */ /* MD_Rte_2987 */
      /* call schedulable entity */

void App_SecureAccess_10ms(){};

void CDD_EHRCDD_EHR_Periodic_Input(){};

void Swc_Ehr_OnCyclic(){};
void Swc_Ehr_OnCyclicRead(){};
void CDD_EHRCDD_EHR_Perioadic_Read_Result(){};


void  RE_SSM_Master_Init(){}; /* PRQA S 2987 */ /* MD_Rte_2987 */
      /* call schedulable entity */


void RE_CalDataProvider_Init(){};
void Swc_Ehr_Init(){};


void vehicle_communication_managervehicle_communication_manager_Periodic(){};
void RE_SSM_Slave_Init(){};

void ClearEvent(){};
void GetEvent(uint32_t RteTask, uint32_t *ev){};



FUNC(void, DTCManager_CODE) P_C2193_01_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C2194_01_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C2195_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C2196_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C2197_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C2198_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C2199_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C219A_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C219B_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C219C_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C219D_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C219E_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C219F_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A0_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A1_0_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A1_10_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A1_9_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A2_10_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A2_9_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A3_10_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A3_9_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A4_10_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A4_9_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A5_31_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A6_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A7_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A7_10_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A8_55_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A8_56_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21A9_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21AA_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21AB_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21AC_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21AD_09_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21AE_0_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21B0_0_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21B2_0_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21B3_0_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C2208_0_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15AC_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15AC_87_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15AD_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15AD_87_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15AE_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15AE_87_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15AF_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15AF_87_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15B0_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15B0_87_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15B1_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15B2_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15B3_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15B4_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15B5_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15B6_16_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15B6_17_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15B7_88_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15B8_96_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15B9_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15BA_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15BA_87_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15BB_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15BB_87_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15BC_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15BC_87_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15BD_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15BD_87_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15BE_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15BF_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15BF_87_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15C0_86_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U15C0_87_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U2001_96_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U2002_16_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U2003_17_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_U2005_88_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8){}; /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DTCManager_CODE) P_C21B1_42_DTCInfo_v(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, P2VAR(uint8, AUTOMATIC, RTE_DTCMANAGER_APPL_VAR) i_AdditionalData_pu8) {};


int VStdLib_MemCpy(void *pDst, void *pSrc, int nCnt)
{
    memcpy((pDst), (pSrc), (nCnt));
};


FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup(Com_SignalGroupIdType SignalGroupId) {};

FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupArray(Com_SignalGroupIdType SignalGroupId, P2VAR(uint8, AUTOMATIC, COM_APPL_VAR) SignalGroupArrayPtr) {};

FUNC(uint8, COM_CODE) Com_SendSignalGroup(Com_SignalGroupIdType SignalGroupId) {};

FUNC(uint8, COM_CODE) Com_SendSignalGroupArray(Com_SignalGroupIdType SignalGroupId, P2CONST(uint8, AUTOMATIC, COM_APPL_VAR) SignalGroupArrayPtr) {};


FUNC(Std_ReturnType, DET_CODE) Det_ReportError(
    VAR(uint16, AUTOMATIC) ModuleId,
    VAR(uint8, AUTOMATIC) InstanceId,
    VAR(uint8, AUTOMATIC) ApiId,
    VAR(uint8, AUTOMATIC) ErrorId) {
    
}

void WdgM_MainFunction() {};
void VehicleAdapterTx_50ms() {};
void VehicleAdapterTx_10ms() {};
void VehicleAdapterTx_20ms() {};
void VehicleAdapterTx_40ms() {};
void VehicleAdapterTx_100ms() {};
void VehicleAdapterTx_1000ms() {};
void VehicleAdapterRx_50ms() {};
void VehicleAdapterRx_10ms() {};
void VehicleAdapterRx_100ms() {};
void VehicleAdapterRx_5000ms() {};
void VehicleAdapterRx_200ms() {};
void VehicleAdapterRx_1000ms() {};
void VehicleAdapterRx_20ms() {};


void SWC_WdgFwWdgFw_10ms() {};
void DIAG_EnbCond_Initialize() {};
void App_Safety_Main() {};


void Os_DisableLevelUM() {};
void Os_EnableLevelUM() {};

void PreConditionChk_OTA_50ms_Runnable() {};

FUNC(StatusType, OS_CODE) Os_SetEvent
(
    TaskType TaskID,
    EventMaskType Mask
) {};


void CDD_AdcApp_Runnable() {};
void CDD_PM_Executeperiodic() {};
void CDD_I2c_MainFunction() {};
void DIAG_EnbCond_ExecutePeriodic() {};


void FvM_MainFunction() {};
void RE_PM_TM_Handler_Periodic() {};
void SafeVehicleAdapterRx_100ms() {};
void SafeVehicleAdapterRx_10ms() {};
void SafeVehicleAdapterRx_200ms() {};
void SafeVehicleAdapterRx_20ms() {};
void SafeVehicleAdapterRx_50ms() {};
void SafeVehicleAdapterTx_10ms() {};
void SafeVehicleAdapterTx_20ms() {};
void SafeVehicleAdapterTx_40ms() {};
void SafeVehicleAdapterTx_50ms() {};


void SafetyGuardSafetyGuard_Main() {};
void Safety_CDD_MainFunction() {};
void WarningMgrWarningMgr_Main() {};
void SafeVehicleAdapterTx_HighPriority() {};

void AdditionalRuntimeStats_Start_Function() {};
void AdditionalRuntimeStats_Stop_Function() {};


