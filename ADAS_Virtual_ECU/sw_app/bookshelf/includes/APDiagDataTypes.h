//--------------------------------------------------------------------------
/// @file APDiagDataTypes.h
/// @brief Contains Interfaces for APFusion input and output structs
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
///
//  --------------------------------------------------------------------------

#ifndef APDIAGDATATYPES_H_INCGUARD
#define APDIAGDATATYPES_H_INCGUARD

#include "PlatformDataTypes.h"
#ifdef BUILD_MCU1_0
#include "Rte_Type.h"

typedef struct TbNVM_ReadParam_s
{
    TeAP_e_PAMOffStatus2BT IeNVM_e_FrntRearParkSts;
    boolean IeNVM_b_PAMRearCtrlSts;
    uint8_t Dtc_B12852A_Status;
} TbNVM_ReadParam;

#endif

/* mcu1_0(DiagMgr) to mcu2_1(AutoPark) */
typedef struct DiagToParkAssist_s
{
    boolean IeDiag_b_ParkAssistSts;
    boolean MbDiag_PlantModeOn;
    boolean MbDiag_SensorTestMode; 
} DiagToParkAssist_t;

/* mcu1_0(DiagMgr) to mcu2_1(USS) */
typedef struct USS_SensorFunctionalTestFlag_s
{
    boolean USS_SnsrFuncTestFalg_b;
}USS_SensorFunctionalTestFlag_t;

typedef struct Activate_Screen_s
{
  uint8_t Camera_View;
  uint8_t Overlay_Activation_Field[7];
} Activate_Screen_t;

/* MCU_1_0 to MCU_2_1 */
typedef struct UssTunningData_mcu1_0_s
{
    uint8 UssTunningDataIn[3072];
}UssTunningData_mcu1_0_t;

#endif
