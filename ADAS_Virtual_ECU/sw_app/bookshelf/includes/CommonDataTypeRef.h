#ifndef CommonDataTypeRef_H_INCGUARD
#define CommonDataTypeRef_H_INCGUARD

#include "PlatformDataTypes.h" 
#if !defined(BUILD_MCUQNX) 
#include "MRR_IPC_Signal_Grouping.h"   
#endif
#include  "VehicleInputAdapterDataTypes.h"
#include "ProxiMgrIpcDataTypes.h"

#include  "HMI_SVS.h"

#if defined(BUILD_MCUQNX) 
//#include  "LwSpd_EnvOD.h"
//#include "LwSpd_DataTypes.h"
#include  "ME_CalibSVS.h"
#include "MOT_Input_Output.h"
#include "SSM_Defs.h"
#include "THAFeatureOutputs.h"
#include "US_Interface_Output.h"
#include "TRSC_SM_VC_Int_types.h"
#include "ErrorManagerDef.h"
#include "TRSC_Inputs_Outputs.h"
#include "THAData.h"
#include "JobTHAOutput.h"
#include "CalDataProvider_defs.h"
#include "NFCD_Input_Output.h"
#include "LMD_Input_Output.h"
#include "TRSC_Inputs_Outputs.h"
#include "SM_ModelOutput.h"
#include "THA_SM_VC_Inputs_Outputs.h"
#include "ProxiParameters.h"
#include "DLD_Input_Output.h"
#include "RunTimeStatsIpc.h"
//#include "CamTypes.h"
#endif

#if !defined(BUILD_MCUQNX)
#include "DmsIpcInterfaceMcu21.h"
/* Error Manager Definitions */

#include "FCM_IPC_Data.h"


#include  "fusion_output.h"
#include  "CD_output.h"
#include  "RootModel_Fisker_HSFeatures_Embd_Output.h"
#endif //!defined(BUILD_MCUQNX)

//#include "APA_USSOM_FPA_Input_Output.h"
#ifdef ME_PLATFORM_FISKER
#include "SSM_Defs.h"
#endif
#if !defined(BUILD_MCUQNX) 
#include  "../magna_apps/KM/algo/include/Kinematic.h"
#include  "AutoPark_StateMachine_Inputs.h"
#include  "AutoPark_StateMachine_Outputs.h"
#include  "RootModel_Fisker_LSFeatures_Embd.h"


#include  "./../../mcu3_0/source/App/USS/US_Includes/US_Interface_Output.h"



//Magna base software Common includes

#include "CalDataProvider_defs.h"
#include "ErrorManagerDef.h"
#include "SignalDef.h"
#include "WdgGlobal.h"

#endif //!defined(BUILD_MCUQNX)


//End :: Magna base software Common includes







#endif //CommonDataTypeRef_H_INCGUARD
