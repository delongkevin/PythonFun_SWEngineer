//--------------------------------------------------------------------------
/// @file FODConfig.h
/// @brief Contains the config paramaters for the FOD
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Dhananjay Sharma (dhananjay.sharma@magna.com) [23-12-2022]
/// --------------------------------------------------------------------------

#ifndef FOD_CONFIG_H
#define FOD_CONFIG_H

#include "FODDef.h"


namespace fod
{
    //**************** FOD Parameters **********************/

    struct FODConfigParams
    {
        //private:
        float32_t FOD_SPEEDLIM_MIN_F32;               //KPH
        float32_t FOD_SPEEDLIM_MAX_F32;               //KPH
        float32_t ROI_ZONE;                           //mm
    };


    // --- Structure for FOD Tunning Parameters   
    typedef struct TbFOD_VrntTunParam_t
    {
        //private:
        float32_t WHEEL_BASE;               // mm
        float32_t VEHICLE_LENGTH;           // mm
        float32_t VEHICLE_WIDTH;            // mm
        float32_t FRONT_OVERHANG;           // mm
        float32_t KeFOD_mm_LongiDistThd;    // Longitudinal Distance = 2000 mm
        float32_t KeFOD_mm_LatiDistThd;     // Latitudinal Distance = [ 300 mm (left side) + VEHICLE_WIDTH + 300 mm (right side) ] mm
        float32_t KeFOD_mm_DistY1Thd;       // Vehicle pos 1 = - (KeFOD_mm_LatiDistThd/2) mm
        float32_t KeFOD_mm_DistY2Thd;       // Vehicle pos 2 = (KeFOD_mm_LatiDistThd/2) mm
        float32_t KeFOD_cm_ObjDetctXThd;    // 0.1 cm
    } TbFOD_VrntTunParam_t;


    typedef struct FODKPIConfigData
    {
        //private:
        bool_t KpiEnable;

        FODKPIConfigData()
        {
            Reset();
        }

        void Reset()
        {
            KpiEnable = true;
        }
    } FODKPIConfigData_t;


    typedef struct FODCONFIGData
    {
        //private:
        FODConfigParams ConfigParams;
        TbFOD_VrntTunParam_t FODCalibrationParams;
        FODKPIConfigData KPIConfigParams;
    } _FODCONFIGData_t;
}

#endif // FOD_CONFIG_H
