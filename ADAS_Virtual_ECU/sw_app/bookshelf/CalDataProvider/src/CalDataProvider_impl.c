#if defined( BUILD_MCU1_0 )
#include <string.h>
#include "Rte_CalDataProvider.h"
#include "NvM.h"
#include "Rte_Type.h"
#include "CalDataProvider.h"
#endif
#include "SSM_Master_app.h"
#include "ipc_manager.h"
#include "CalDataProvider_defs.h"
#include "USS_Inputs_Outputs.h"
#include "boot_feature_calib.h"
#include "Os_Lcfg.h"




#if defined( BUILD_MCU1_0 )
#define CalDataProvider_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "CalDataProvider_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CalDataProvider_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "CalDataProvider_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define MAX_SEND_CNT 3
#define UINT32_MAX_VAL                      4294967295
/* Enum for CalDataProvider State machine */
typedef enum
{
    STATE_NONE,
    STATE_INIT,
    STATE_RUN,
    STATE_PREPARE_SLEEP,
    STATE_DEINIT
}CalDataProviderState_t;

static void CDP_F_CalData_update_to_allCores_v(void);



#if defined( BUILD_MCU1_0 )
#define CalDataProvider_START_SEC_VAR_INIT_UNSPECIFIED
#include "CalDataProvider_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CalDataProvider_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CalDataProvider_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CalDataProvider_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "CalDataProvider_MemMap.h"
#endif
/* CalDataProvider broadcast data */
static CalDataProvider_MPU_1_0_Def v_CalData_mpu1_0;
static CalDataProvider_MCU_1_0_Def v_CalData_mcu1_0;
static CalDataProvider_MCU_2_1_Def v_CalData_mcu2_1;
static CalDataProvider_MCU_2_0_Def v_CalData_mcu2_0;

static USS_Calibration_Data_t  USS_Cal_Data;
static USS_Calibration_data_2_t  USS_Cal_Data_2;
static THA_Calibration_data_MCU2_1_t THA_Cal_MCU2_1_Data;
static THA_Calibration_data_MPU1_0_t THA_Cal_MPU1_0_Data;
static TRSC_Calibration_data_MCU2_1_t TRSC_Cal_MCU2_1_Data;
static TRSC_Calibration_data_MPU1_0_t TRSC_Cal_MPU1_0_Data;
static APA_Calibration_data_MPU1_0_t APA_Cal_MPU1_0_Data;
static APA_Calibration_data_MCU2_1_t APA_Cal_MCU2_1_Data;
static SVS_Calibration_data_t  SVS_Cal_Data;
static FOD_Calibration_data_t  FOD_Cal_Data;
static LMD_Calibration_data_t  LMD_Cal_Data;


/*Core status to keep track of data sent and resend */
static uint8 v_calDataSendStatus_au8[SSM_CORE_MAX];
#if defined( BUILD_MCU1_0 )
#define CalDataProvider_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "CalDataProvider_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CalDataProvider_START_SEC_CODE
#include "CalDataProvider_MemMap.h"
#endif
/* Read core status for Mpu1_0 */
static SSM_CoreSlaveCoreStateDef f_getMpu1_0_core_Status_e(void)
{
	/* DD-ID: {A411B44A-2AAE-4143-B38D-B7F43653A53B}*/  
  SSM_QNX_CoreStatus data;
    (void)Rte_Read_R_SSM_QNXState_State_QNX(&data);
    return data.CoreStatus;
}

/* Read core status for Mcu1_0 */
static SSM_CoreSlaveCoreStateDef f_getMcu1_0_core_Status_e(void)
{
	/* DD-ID: {326E751E-E780-4a76-BF48-A2E9688BF93C}*/
	SSM_1_0_CoreStatus data;
    (void)Rte_Read_R_SSM_1_0_State_State_1_0(&data);
    return data.CoreStatus;
}

/* Read core status for Mcu2_1 */
static SSM_CoreSlaveCoreStateDef f_getMcu2_1_core_Status_e(void)
{
  /* DD-ID: {38CD8FB2-66A8-4aba-88CC-801388076B67}*/
    SSM_2_1_CoreStatus data;
     (void)Rte_Read_R_SSM_2_State_State_2_1(&data);
    return data.CoreStatus;
}

/* Read core status for Mcu2_0 */
static SSM_CoreSlaveCoreStateDef f_getMcu2_0_core_Status_e(void)
{
  /* DD-ID: {CBD641D7-E3A9-464a-98A5-6F6214CA436B}*/
    SSM_2_0_CoreStatus data;
     (void)Rte_Read_R_SSM_2_State_State_2_0(&data);
    return data.CoreStatus;
}


/* Read core status for any core */
static SSM_CoreSlaveCoreStateDef f_getCoreStatus_e(SSM_CORE_Defs i_coreid)
{
	/* DD-ID: {EBD5EE10-B977-4521-AAD9-0E8FE08EEA02}*/
	SSM_CoreSlaveCoreStateDef v_coreState_e = SSM_SlaveCore_State_Unknown;

    switch(i_coreid)
    {
    case SSM_CORE_QNX :
        v_coreState_e = f_getMpu1_0_core_Status_e();
        break;
    case SSM_CORE_1_0 :
        v_coreState_e = f_getMcu1_0_core_Status_e();
        break;
    case SSM_CORE_2_1 :
        v_coreState_e = f_getMcu2_1_core_Status_e();
        break;
    case SSM_CORE_2_0 :
        v_coreState_e = f_getMcu2_0_core_Status_e();
        break;
    default :
    	/* Do Nothing */
        break;
    }
    return v_coreState_e;
}

/* Send Cal data to mpu1_0 */
static void f_send_CalData_mpu1_0_v(void)
{
/* DD-ID: {AC47CDBC-6EA0-49ac-8C0F-5D91A6FD0711}*/
   if(UINT32_MAX_VAL > v_CalData_mpu1_0.FreshnessCount)
     { 
          v_CalData_mpu1_0.FreshnessCount++;
       }
   else
    {
       v_CalData_mpu1_0.FreshnessCount = 0;
    }

    v_CalData_mpu1_0.bValid = TRUE;
    (void)Os_Call_RE_IpcTxData(&v_CalData_mpu1_0, (uint16)e_IpcMsgId_Data_CalDataProvider_MPU_1_0_Def, sizeof(CalDataProvider_MPU_1_0_Def));

    (void)Os_Call_RE_IpcTxData(&LMD_Cal_Data, (uint16)e_IpcMsgId_Data_LMD_Calibration_data_t, sizeof(LMD_Calibration_data_t));

    (void)Os_Call_RE_IpcTxData(&SVS_Cal_Data, (uint16)e_IpcMsgId_Data_SVS_Calibration_data_t, sizeof(SVS_Calibration_data_t));
    (void)Os_Call_RE_IpcTxData(&TRSC_Cal_MPU1_0_Data,(uint16)e_IpcMsgId_Data_TRSC_Calibration_data_MPU1_0_t, sizeof(TRSC_Calibration_data_MPU1_0_t));
    (void)Os_Call_RE_IpcTxData(&APA_Cal_MPU1_0_Data, (uint16)e_IpcMsgId_Data_APA_Calibration_data_MPU1_0_t, sizeof(APA_Calibration_data_MPU1_0_t));
    (void)Os_Call_RE_IpcTxData(&THA_Cal_MPU1_0_Data,(uint16) e_IpcMsgId_Data_THA_Calibration_data_MPU1_0_t, sizeof(THA_Calibration_data_MPU1_0_t));
}

/* Copy Nvm Ram data to mpu1_0 */
static void f_copy_NvMData_mpu1_0_v(void)
{
  /* DD-ID: {A497B911-47DA-451d-9485-46178F24F0AC}*/
    v_CalData_mpu1_0.CalData_SVSCamCurrentCalibData = Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.data;
    v_CalData_mpu1_0.CalData_SVSCamEOLCalibData = Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.data;
    v_CalData_mpu1_0.CalData_SVSCamOCCalibData = Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.data;
    v_CalData_mpu1_0.CalData_SVSCamSCCalibData = Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.data;
    Get_LMD_Calibration_Data(&LMD_Cal_Data);
    Get_SVS_Calibration_Data(&SVS_Cal_Data);
    Get_TRSC_Calibration_Data_MPU1_0(&TRSC_Cal_MPU1_0_Data);
    Get_APA_Calibration_Data_MPU1_0(&APA_Cal_MPU1_0_Data);
    Get_THA_Calibration_Data_MPU1_0(&THA_Cal_MPU1_0_Data);
}

/* Send Cal data to mcu1_0 */
static void f_send_CalData_mcu1_0_v(void)
{
	/* DD-ID: {A7A5ED93-8758-430b-90F0-9B5B11C19A9C}*/
     if(UINT32_MAX_VAL >  v_CalData_mcu1_0.FreshnessCount)
    {
         v_CalData_mcu1_0.FreshnessCount++;
     }
    else
    {
          v_CalData_mcu1_0.FreshnessCount = 0;
     }

    v_CalData_mcu1_0.bValid = TRUE;
    (void)Rte_Write_P_CalDataProvider_MCU1_0_Nvm_Data_CalData_mcu1_0(&v_CalData_mcu1_0);
}

/* Copy Nvm Ram data to mpu1_0 */
static void f_copy_NvMData_mcu1_0_v(void)
{
  /* DD-ID: {58681E14-E433-4a35-BC58-12CBDA6B634D}*/
    v_CalData_mcu1_0.CalData_SVSCamCurrentCalibData = Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.data;
    v_CalData_mcu1_0.CalData_PrevOdoValue = Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.PrevOdoValue;
    v_CalData_mcu1_0.CalData_SVSCamEOLCalibData = Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.data;
    v_CalData_mcu1_0.CalData_PlantOdoValue = Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.PlantOdoValue;
    v_CalData_mcu1_0.CalData_SVSCamOCCalibData = Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.data;
    v_CalData_mcu1_0.CalData_SVSCamSCCalibData = Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.data;
}
/* Send Cal data to mcu2_1 */
static void f_send_CalData_mcu2_1_v(void)
{
	/* DD-ID: {17BB8A0F-FB20-4e08-849C-E4574C176963}*/
    if(UINT32_MAX_VAL >  v_CalData_mcu2_1.FreshnessCount)	
   {
        v_CalData_mcu2_1.FreshnessCount++;
    }
  else
  {
     v_CalData_mcu2_1.FreshnessCount = 0 ;
   }
    v_CalData_mcu2_1.bValid = TRUE;
    (void)Os_Call_RE_IpcTxData(&v_CalData_mcu2_1, (uint16)e_IpcMsgId_Data_CalDataProvider_MCU_2_1_Def, sizeof(CalDataProvider_MCU_2_1_Def));
    (void)Os_Call_RE_IpcTxData(&USS_Cal_Data,(uint16) e_IpcMsgId_Data_USS_Calibration_Data_t, sizeof(USS_Calibration_Data_t));
    (void)Os_Call_RE_IpcTxData(&USS_Cal_Data_2, (uint16)e_IpcMsgId_Data_USS_Calibration_data_2_t , sizeof(USS_Calibration_data_2_t));
    (void)Os_Call_RE_IpcTxData(&THA_Cal_MCU2_1_Data, (uint16)e_IpcMsgId_Data_THA_Calibration_data_MCU2_1_t, sizeof(THA_Calibration_data_MCU2_1_t));
    (void)Os_Call_RE_IpcTxData(&APA_Cal_MCU2_1_Data,(uint16) e_IpcMsgId_Data_APA_Calibration_data_MCU2_1_t, sizeof(APA_Calibration_data_MCU2_1_t));
    (void)Os_Call_RE_IpcTxData(&FOD_Cal_Data, (uint16)e_IpcMsgId_Data_FOD_Calibration_data_t, sizeof(FOD_Calibration_data_t));
    (void)Rte_Write_PpAPVarTunParam_TbAP_VrntTunParam_t(&APA_Cal_MCU2_1_Data.CalData1);
}

/* Copy Nvm Ram data to mcu2_1 */
static void f_copy_NvMData_mcu2_1_v(void)
{
  /* DD-ID: {295F9667-D96D-424a-BD39-973D91B4AC40}*/
    v_CalData_mcu2_1.CalData_SVSCamCurrentCalibData = Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.data;
    v_CalData_mcu2_1.CalData_SVSCamEOLCalibData = Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.data;
    v_CalData_mcu2_1.CalData_SVSCamOCCalibData = Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.data;
    v_CalData_mcu2_1.CalData_SVSCamSCCalibData = Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.data;
	Get_USS_Calibration_Data(&USS_Cal_Data, &USS_Cal_Data_2);
	Get_THA_Calibration_Data_MCU2_1(&THA_Cal_MCU2_1_Data);
    Get_APA_Calibration_Data_MCU2_1(&APA_Cal_MCU2_1_Data);
    Get_FOD_Calibration_Data(&FOD_Cal_Data);
}

/* Send Cal data to mcu2_0 */
static void f_send_CalData_mcu2_0_v(void)
{
  /* DD-ID: {2D609F64-2CF3-49bd-8BEF-3847FA33D364}*/
    if(UINT32_MAX_VAL >  v_CalData_mcu2_0.FreshnessCount)	
   {
      v_CalData_mcu2_0.FreshnessCount++;
    }
  else
  {
     v_CalData_mcu2_0.FreshnessCount = 0 ;
   }
    v_CalData_mcu2_0.bValid = TRUE;
    (void)Os_Call_RE_IpcTxData(&v_CalData_mcu2_0,  (uint16)e_IpcMsgId_Data_CalDataProvider_MCU_2_0_Def, sizeof(CalDataProvider_MCU_2_0_Def));
    (void)Os_Call_RE_IpcTxData(&TRSC_Cal_MCU2_1_Data,  (uint16)e_IpcMsgId_Data_TRSC_Calibration_data_MCU2_1_t, sizeof(TRSC_Calibration_data_MCU2_1_t));
}

/* Copy Nvm Ram data to mcu2_0 */
static void f_copy_NvMData_mcu2_0_v(void)
{
  /* DD-ID: {5AB9FC67-BF2C-451a-A06F-8E4653176C58}*/
    v_CalData_mcu2_0.CalData_SVSCamCurrentCalibData = Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.data;
    v_CalData_mcu2_0.CalData_SVSCamEOLCalibData = Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.data;
    v_CalData_mcu2_0.CalData_SVSCamOCCalibData = Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.data;
    v_CalData_mcu2_0.CalData_SVSCamSCCalibData = Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.data;
	 Get_TRSC_Calibration_Data_MCU2_1(&TRSC_Cal_MCU2_1_Data);
}

/* Update cal data to cores during startup and during change */
static void f_process_CalData_update_to_Cores_v(void)
{
  	/* DD-ID: {B1ECC7F1-AC51-43f4-AAC0-BB085E0BCCAE}*/
uint8 v_coreid = (uint8)SSM_CORE_1_0;
   SSM_CoreSlaveCoreStateDef v_coreState_e = SSM_SlaveCore_State_Unknown;

    for(v_coreid = (uint8)SSM_CORE_1_0; v_coreid < (uint8)SSM_CORE_MAX; v_coreid++)
    {
        if(0x0U != v_calDataSendStatus_au8[v_coreid]) 
        {
           v_coreState_e = f_getCoreStatus_e((SSM_CORE_Defs)v_coreid);
          if (SSM_SlaveCore_State_BSP_Init_Done <= v_coreState_e)    
          { 
            switch(v_coreid)
            {
            case (uint8)SSM_CORE_QNX :
                f_copy_NvMData_mpu1_0_v();
                f_send_CalData_mpu1_0_v();
                break;
            case  (uint8)SSM_CORE_1_0 :
                f_copy_NvMData_mcu1_0_v();
                f_send_CalData_mcu1_0_v();
                break;
            case (uint8) SSM_CORE_2_1 :
                f_copy_NvMData_mcu2_1_v();
                f_send_CalData_mcu2_1_v();
                break;
            case (uint8)SSM_CORE_2_0 :
                f_copy_NvMData_mcu2_0_v();
                f_send_CalData_mcu2_0_v();
                break;
            default :
            	/* Do Nothing */
                break;
            }
            v_calDataSendStatus_au8[v_coreid]--;
          }
          else{/*do nothing*/}
        }
        else{/*do nothing*/}
    }
}

/* Resend Cal Data update incase of change in data */
void CDP_F_CalData_update_to_core_v(SSM_CORE_Defs i_coreid)
{
  /* DD-ID: {382A38D0-147A-41a8-B8B0-6E3DC1BBC73F}*/
    v_calDataSendStatus_au8[i_coreid] = MAX_SEND_CNT;
}

/* Resend Cal Data update to all cores */
static  void CDP_F_CalData_update_to_allCores_v(void)
{
    /* DD-ID :{F39FE0F7-9219-44e6-93AB-89E7AF61A8F3}*/

	uint8 v_coreid; 
	/* Update status to send Cal data to all cores */
	for(v_coreid = (uint8)SSM_CORE_1_0; v_coreid <  (uint8)SSM_CORE_MAX; v_coreid++)
     {
		CDP_F_CalData_update_to_core_v((SSM_CORE_Defs)v_coreid);
	}
}

void CDP_Cal_DataProvider_Init_v(void)
{
	/* DD-ID: {AAD44EB9-2F13-48b0-BE1D-302E0BAE7740}*/
	v_CalData_mpu1_0.FreshnessCount = (uint32_t)1;
    v_CalData_mpu1_0.bValid = FALSE;

    v_CalData_mcu1_0.FreshnessCount = (uint32_t) 1;
    v_CalData_mcu1_0.bValid = FALSE;

    v_CalData_mcu2_1.FreshnessCount =  (uint32_t)1;
    v_CalData_mcu2_1.bValid = FALSE;

    v_CalData_mcu2_0.FreshnessCount =  (uint32_t)1;
    v_CalData_mcu2_0.bValid = FALSE;

	/* Update status to send Cal data to all cores */
	CDP_F_CalData_update_to_allCores_v();
}

/* function to change Cal data provider state and perform required operation */
void CalDataProvider_Run_v(void)
{
  	/* DD-ID: {46DDD93E-5A42-476e-BEA5-08027B66FD3E}*/
    /* CalDataProvider state holder */
     static CalDataProviderState_t e_state = STATE_NONE;
    switch(e_state)
    {
    case STATE_NONE :
        e_state = STATE_INIT;
        break;
    case STATE_INIT :
        CDP_Cal_DataProvider_Init_v();
        e_state = STATE_RUN;
        break;
    case STATE_RUN :
        f_process_CalData_update_to_Cores_v();
        break;
    case STATE_PREPARE_SLEEP :
        e_state = STATE_DEINIT;
        break;
    case STATE_DEINIT :
        break;
    default :
    	/* Do Nothing */
        break;
    }
}

#if defined( BUILD_MCU1_0 )
#define CalDataProvider_STOP_SEC_CODE
#include "CalDataProvider_MemMap.h"
#endif

#endif

