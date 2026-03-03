/// @file   AutoPark_Inputs_Outputs.h
/// @brief  FOD IPC Interface Data Structure definition
///
///  FOD IPC Interface Data Structure definition
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author  Kedar Naphad (kedar.naphad@magna.com)
///

#ifndef _FOD_INPUT_OUTPU_H_
#define _FOD_INPUT_OUTPU_H_

#include "PlatformDataTypes.h"
#include "JobKM.h"
#include "MOT_Input_Output.h"
#include "ProxiMgrIpcDataTypes.h"
#include "USS_Inputs_Outputs.h"

/* ################# Inputs to FOD #############################*/
/*MCU1_0(VCAN) to MCU2_1(FOD)*/
/*ME_VehInp_to_IpcSignals_t*/

/*MCU1_0(KM) to MCU2_1(FOD)*/
/*IKinematicData_t*/

/*Proxi to MCU2_1(FOD)*/
/*ME_Proxi_to_IpcSignals_t*/

/*MCU2_1(USS) to MCU2_1(FOD)*/
/*US_S_USSErrorDiagData_t*/
/*US_S_BlockageBit_t*/

/*MCU2_1(NFCD) to MCU2_1(FOD)*/
/*NFCD_Output*/

/*CalDataProvider(MCU1_0) to MCU2_1(FOD)*/
// --- Structure for FOD Tunning Parameters
typedef struct ITbFOD_VrntTunParam_s
{
    float32_t KeFOD_mm_LongiDistThd;    // Longitudinal Distance = 2000 mm
    float32_t KeFOD_mm_LatiDistThd;     // Latitudinal Distance = [ 300 mm (left side) + VEHICLE_WIDTH + 300 mm (right side) ] mm
    float32_t KeFOD_mm_DistY1Thd;       // Vehicle pos 1 = - (KeFOD_mm_LatiDistThd/2) mm
    float32_t KeFOD_mm_DistY2Thd;       // Vehicle pos 2 = (KeFOD_mm_LatiDistThd/2) mm
    float32_t KeFOD_cm_ObjDetctXThd;    // 0.1 cm
}ITbFOD_VrntTunParam_s;
/* #####################################################################*/

/* ################# Outputs from FOD #############################*/

    // For the health of Front Object Detection system
    typedef enum FODHealth_e
    {
        Faulted = 0,
        Blocked,
        Unknown,
        Healthy
    } FODHealth_t;


    // For FOD confidence
    typedef enum FODConfidence_e
    {
        Not_Detected = 0,
        Detected_Low_Confidence,
        Detected_Medium_Confidence,
        Detected_High_Confidence
    } FODConfidence_t;
/*MCU2_1(FOD) to MCU1_0(VCAN)*/
typedef struct FOD_Outputs_ADASFDLANES1_s
{
    uint32 IeFOD_e_FODHealth;
    uint32 IeFOD_e_FODConfidence;
} IFOD_Outputs_CVPAMFDData_t;

/*MCU2_1(FOD) to MCU2_1(NFCD)*/
/*MCU2_1(FOD) to MCU1_0(KM and VCAN)*/
typedef struct FOD_Outputs_Arbitration_s
{
    uint8_t IeFOD_e_FODStatus;
    uint8_t MeFOD_e_USSFiringMode;
    bool_t IeFOD_b_ResetKM;
}IFOD_Outputs_Arbitration_t;

/*MCU2_1(FOD) to MCU1_0(VCAN)*/
typedef struct Debug_FODObject_t
{
    float32_t obj_Pos_Lat;
    float32_t obj_Pos_Longi;
    uint64_t macCvpamFdData1_u64;
    uint16_t cntrCvpamFdData1_u16;
    uint8_t msgcntrCvpamFdData1_u8;
    uint8_t crcCvpamFdData1_u8;
    FODHealth_t FrontSensorDetHealth_e;
    FODConfidence_t objConf_e;
}IDebug_FODObject_t;

/* #####################################################################*/

#endif //_FOD_INPUT_OUTPU_H_
