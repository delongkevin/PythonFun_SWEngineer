// Added Typedefinitions for multiple datatypes Porting
#include <string.h>
#include "HMI_Structures.h"
#define ME_HYDRA2DEFS_D_CAMERACOUNT 
#include "External_Dependency.h"

#if 0
ME_Hydra2defs_E_MCUDebug0_t aZynqM_F_GetMCUDebug0_e(void)
{
  return aZynqM_v_MCUDebug0;
}




BOOL aZynqM_F_GetCurrentStateCams_b(void)
{
  return aZynqM_v_CurrentStateCams_b;
}
#endif 
void aZynqM_F_SetMCUDebug0_v(ME_Hydra2defs_E_MCUDebug0_t MCUDebug0)
{
  /* DD-ID: {7B34E614-E134-4643-BF3F-A7D3225A1BE9}*/
  
  return;
}

void aZynqM_F_GetScreen_v(aZynqM_S_ScreenType_t *screen)
{
  /* DD-ID: {70EF7219-3949-4590-B75A-E365BC5C1291}*/
  SignalTypes_Private_S_Rx_Current_OverlayGroups_t currentOverlayGroups;
  SignalTypes_Private_S_Rx_Current_View_t currentView;

  if (NULL != screen)
  {
    /* initialize screen */
    (void)memset(screen, 0x00, sizeof(aZynqM_S_ScreenType_t));  /* be sure there is no garbage in passed structure */
    screen->view = ME_Hydra2defs_OEM_E_NonViewRequested;

    if(aZynqM_E_ModuleState_NormalOperation == aZynqM_v_ModuleState_e)
    {
      Std_E_ReturnType_t ret;
      ret = aSigM_Zynq_F_GetValue_Current_OverlayGroups_e(&currentOverlayGroups);

      if(Std_E_RetType_Successful == ret)
      {
        ret = aSigM_Zynq_F_GetValue_Current_View_e(&currentView);

        if(Std_E_RetType_Successful == ret)
        {
          (void)memcpy(&screen->overlays, &currentOverlayGroups.v_Value, sizeof(screen->overlays));
          if(ME_Hydra2defs_OEM_E_ViewCount > currentView.v_Value) /* Range Check */
          {
            screen->view = (ME_Hydra2defs_E_ViewType_t)currentView.v_Value; /* PRQA S 1482 ++*/ /* Range Check is done above */
          }
          else
          {
            /* do nothing */
          }
        }
        else
        {
          /*do nothing*/
        }
      }
      else
      {
        /*do nothing*/
      }
    }
    else
    {
      /*do nothing*/
    }
  }
  else
  {
    /* do nothing */
  }
  return;
}


int aZynqM_F_RequestStateCams_v(BOOL onoff)
{
  /* DD-ID: {E721F74E-AC86-4c63-8B1B-C15778C3BB15}*/
  

  return 1;
}

int aZynqM_F_RequestStateVideoOutput_v(BOOL onoff)
{
  /* DD-ID: {7CF16CBC-6B58-4012-92E9-C1B658650E43}*/
  return 1;
}


BOOL aZynqM_F_GetCurrentStateVideoOutput_b(void)
{
  /* DD-ID: {F1DFD2B1-E701-4da0-BD5B-9EFDAB96A880}*/
  return aZynqM_v_CurrentStateVideoOutput_b;
}




//Signal Converter C Code

#if 0
Std_E_ReturnType_t aSigConverter_F_UpdateHmiMRelatedSignals_e(aSigConverterTypes_S_Tx_HmiMRelatedData_t Tx_HmiRelatedData)
{
  Std_E_ReturnType_t retVal = Std_E_RetType_Successful;
  if(aSigConverter_E_FirstRunDone == aSigConverter_v_ModuleState)
  {
    /* Module is initialized and first run done */
    //aSigConverter_v_Tx_HmiRelatedData = Tx_HmiRelatedData;
  }
  else
  {
    /* First 10msec Task run is not done yet */
    retVal = Std_E_RetType_Failed;
  }
  return retVal;
}
#endif

Std_E_ReturnType_t aSigConverter_F_GetHmiMRelatedSignals_e(aSigConverterTypes_S_Rx_HmiMRelatedData_t* Rx_HmiRelatedData)
{
  /* DD-ID: {A4976A8B-6ECE-4b44-8210-87F3F666B8C7}*/
  Std_E_ReturnType_t retVal;  
  return retVal;
}

void aZynqM_F_SetScreen_v(const aZynqM_S_ScreenType_t *screen)
{
  /* DD-ID: {9D18DC7C-2D9B-4fbc-BCB8-0C9492AAE7D8}*/
  return;
}

