//--------------------------------------------------------------------------
/// @file JobFODOutput.h
/// @brief FOD output structures are defined
// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Nisheegandha Bhookan (nisheegandha.bhookan@magna.com)
//--------------------------------------------------------------------------

#ifndef JOB_FOD_OUTPUT_H
#define JOB_FOD_OUTPUT_H

#include "../algo/common/FODDef.h"


namespace fod
{
    // Structure to define Front Object Detection output signals
    typedef struct FOD_Outputs_ADASFDLANES1_t
    {
        //------------FOD Health-------------
        FODHealth_t IeFOD_e_FODHealth;
        //------------FOD Confidence-------------
        FODConfidence_t IeFOD_e_FODConfidence;

        FOD_Outputs_ADASFDLANES1_t()
        {
            Reset();
        }

        void Reset()
        {
            IeFOD_e_FODHealth = FODHealth_t::Faulted;
            IeFOD_e_FODConfidence = FODConfidence_t::Not_Detected;
        }
    } FOD_Outputs_ADASFDLANES1_t;

    
    // Structure for FOD Debug Signals
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

        //Initialize all signals with DBC init value
        Debug_FODObject_t()
        {
            Reset();
        }

        void Reset()
        {
            obj_Pos_Lat = 0.0f;
            obj_Pos_Longi = 0.0f;
            macCvpamFdData1_u64 = 0;
            cntrCvpamFdData1_u16 = 0;
            msgcntrCvpamFdData1_u8 = 0;
            crcCvpamFdData1_u8 = 0;
            FrontSensorDetHealth_e = FODHealth_t::Faulted;
            objConf_e = FODConfidence_t::Not_Detected;
        }
    } Debug_FODObject_t;


    //Structure to define FOD Output and Debug Signals
    struct JobFODOutput_t
    {
        FOD_Outputs_ADASFDLANES1_t FOD_Outputs_ADASFDLANES1_s;
        Debug_FODObject_t Debug_FODObject_s; //--- Not FOD output, debugging purpose only

        JobFODOutput_t()
        {
            Reset();
        }

        void Reset()
        {
            FOD_Outputs_ADASFDLANES1_s.Reset();
            Debug_FODObject_s.Reset();
        }
    };
}

#endif // !JOB_FOD_OUTPUT_H
