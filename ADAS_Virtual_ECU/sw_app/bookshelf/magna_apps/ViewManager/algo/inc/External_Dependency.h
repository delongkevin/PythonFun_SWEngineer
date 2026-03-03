#ifndef EXTERNAL_DEPENDENCY_H_
#define EXTERNAL_DEPENDENCY_H_


// Added Typedefinitions for multiple datatypes Porting
#include <string.h>
#include "HMI_Structures.h"
#include "SignalDef.h"
#define ME_HYDRA2DEFS_D_CAMERACOUNT 






// Include Private H code

typedef struct SignalTypes_Private_S_SignalStruct
{
  BOOL TimeoutFlag;
  BOOL IndicationFlag;
} SignalTypes_Private_S_SignalStruct_t;


typedef struct SignalTypes_Private_S_Rx_Current_View
{
  u8 v_Value;
  SignalTypes_Private_S_SignalStruct_t SignalTypes_v_SignalStruct;
}SignalTypes_Private_S_Rx_Current_View_t;

typedef struct SignalTypes_Private_S_Rx_Current_OverlayGroups
{
  ME_Hydra2defs_S_OverlayGroups_t v_Value;
  SignalTypes_Private_S_SignalStruct_t SignalTypes_v_SignalStruct;
}SignalTypes_Private_S_Rx_Current_OverlayGroups_t;


typedef struct SignalTypes_Private_S_Tx_Screen
{
  ME_Hydra2defs_S_Screen_t v_Value;
  BOOL v_UpdateFlag;
} SignalTypes_Private_S_Tx_Screen_t;



// ZYNQM C Code



typedef enum aZynqM_E_MetadataState_e
{
  aZynqM_E_MetadataState_Idle = 0u,
  aZynqM_E_MetadataState_Pending,
  aZynqM_E_MetadataState_Updated,
  aZynqM_E_MetadataState_Timeout
} aZynqM_E_MetadataState_t;


typedef enum aZynqM_E_ItemType_e
{
  aZynqM_E_ItemType_None = 0u,
  aZynqM_E_ItemType_ZynqErrorState,
  aZynqM_E_ItemType_Information,
  aZynqM_E_ItemType_VehicleState,
  aZynqM_E_ItemType_AlgoControl,
  aZynqM_E_ItemType_Screen,
  aZynqM_E_ItemType_RequestControl,
  aZynqM_E_ItemType_RequestControlDebugFunctions,
  aZynqM_E_ItemType_RequestControl_ErrorState,
  aZynqM_E_ItemType_Count
} aZynqM_E_ItemType_t;




typedef enum aZynqM_E_ModuleState_e
{
  aZynqM_E_ModuleState_NotInit = 0u,
  aZynqM_E_ModuleState_Init,
  aZynqM_E_ModuleState_FirstRunDone,
  aZynqM_E_ModuleState_WaitForZynqBootComplete,
  aZynqM_E_ModuleState_BootComplete,
  aZynqM_E_ModuleState_NormalOperation,
  aZynqM_E_ModuleState_BootError,
  aZynqM_E_ModuleState_ShutDownZynq,
  aZynqM_E_ModuleState_NumStates
} aZynqM_E_ModuleState_t;



// SIGM ZYNQ H Code


typedef enum aSigM_Zynq_E_ModuleState_e
{
  aSigM_Zynq_E_NotInit = 0u,
  aSigM_Zynq_E_InitComplete,
  aSigM_Zynq_E_FirstRunDone
} aSigM_Zynq_E_ModuleState_t;





// Include Vehicle H Code


typedef struct SignalTypes_S_Rx_LRW
{
  u8 v_LRW1;
  u8 v_LRW0;
} SignalTypes_S_Rx_LRW_t;

typedef struct SignalTypes_S_Rx_LRWS_ST
{
  u8 v_Value;
} SignalTypes_S_Rx_LRWS_ST_t;



void aZynqM_F_SetZoomFactor_v(u8 zoomFactor_u8);
Std_E_ReturnType_t aSigM_Zynq_F_GetValue_Current_View_e(SignalTypes_Private_S_Rx_Current_View_t* Current_View);
static aZynqM_E_ModuleState_t aZynqM_v_ModuleState_e = aZynqM_E_ModuleState_NotInit;
static aSigConverter_E_ModuleState_t aSigConverter_v_ModuleState = aSigConverter_E_NotInit;
static BOOL aZynqM_v_CurrentStateVideoOutput_b;
BOOL aZynqM_F_GetCurrentStateVideoOutput_b(void);
Std_E_ReturnType_t aSigM_Zynq_F_GetValue_Current_OverlayGroups_e(SignalTypes_Private_S_Rx_Current_OverlayGroups_t* Current_OverlayGroups);
void aZynqM_F_GetScreen_v(aZynqM_S_ScreenType_t *screen);
void aZynqM_F_SetScreen_v(const aZynqM_S_ScreenType_t *screen);
Std_E_ReturnType_t aSigConverter_F_UpdateHmiMRelatedSignals_e(aSigConverterTypes_S_Tx_HmiMRelatedData_t Tx_HmiRelatedData);
Std_E_ReturnType_t aSigConverter_F_GetHmiMRelatedSignals_e(aSigConverterTypes_S_Rx_HmiMRelatedData_t* Rx_HmiRelatedData);
static BOOL aZynqM_v_CurrentStateCams_b ;
static ME_Hydra2defs_E_MCUDebug0_t aZynqM_v_MCUDebug0;
BOOL aZynqM_F_GetCurrentStateCams_b(void);



#endif

