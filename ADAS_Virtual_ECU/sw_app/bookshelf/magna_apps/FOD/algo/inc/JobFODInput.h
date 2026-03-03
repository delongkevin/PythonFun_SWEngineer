//--------------------------------------------------------------------------
/// @file JobFODInput.h
/// @brief FOD input structures are defined
// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Nisheegandha Bhookan (nisheegandha.bhookan@magna.com)
//--------------------------------------------------------------------------

#ifndef JOB_FOD_INPUT_H
#define JOB_FOD_INPUT_H

#include<mecl/mecl.h>
#include "../algo/common/FODDef.h"
#include "../algo/common/VehicleData.h"
#include "../algo/common/KinematicData.h"


namespace fod
{
    // From Proxi Manager
    typedef struct FOD_Inputs_ProxiM_s
    {
        ProxiAutonomyLevel_t MePRX_e_AutonomyLvl;

        FOD_Inputs_ProxiM_s()
        {
            Reset();
        }

        void Reset()
        {
            MePRX_e_AutonomyLvl = ProxiAutonomyLevel_t::NoneOrLevel1;
        }
    } FOD_Inputs_ProxiM_t;


    // From Degradation Manager
    typedef struct FOD_Inputs_DegradationM_s
    {
        FODFID_t m_A_FID_FOD_DISABLED;
        FODFID_t m_A_FID_FOD_LIMITED;
        FODFID_t m_A_FID_FOD_DISABLED_SensorBlockage;
        FODFID_t m_A_FID_FOD_LIMITED_SensorBlockage;

        FOD_Inputs_DegradationM_s()
        {
            Reset();
        }

        void Reset()
        {
            m_A_FID_FOD_DISABLED = FODFID_t::FID_NotActive;
            m_A_FID_FOD_LIMITED = FODFID_t::FID_NotActive;
            m_A_FID_FOD_DISABLED_SensorBlockage = FODFID_t::FID_NotActive;
            m_A_FID_FOD_LIMITED_SensorBlockage = FODFID_t::FID_NotActive;
        }
    } FOD_Inputs_DegradationM_t;


    struct Job_Inputs_t
    {
        FOD_Inputs_ProxiM_t FOD_Inputs_ProxiM_s;
        FOD_Inputs_DegradationM_t FOD_Inputs_DegradationM_s;
        //--- Vehicle info
        VehicleDataFOD m_VehicleData;
#if WINDOWS_NOTINUSE_CODE
        //--- Vehicle Kinematic info
        KinematicDataFOD m_KinematicData;
#endif

        Job_Inputs_t()
        {
            Reset();
        }

        void Reset()
        {
            FOD_Inputs_ProxiM_s.Reset();
            FOD_Inputs_DegradationM_s.Reset();
            // --- Reset vehicle parameters
            m_VehicleData.Reset();
#if WINDOWS_NOTINUSE_CODE
            // --- Reset kinematic parameters
            m_KinematicData.Reset();
#endif
        }
    };
}

#endif // !JOB_FOD_INPUT_H
