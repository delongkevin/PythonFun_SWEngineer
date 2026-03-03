// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [25-Jul-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __JOB_TAD_INPUT__H_
#define __JOB_TAD_INPUT__H_

#ifdef __QNX__
    #include "meal/camera/core/inc/CameraPoint.h"
    #include "../common/Image.h"
    #include "../common/TADStateTypes.h"
    #include "../common/TADStructures.h"
#else
    #include "Point.h"
    #include "common/Image.h"
    #include "common/TADStateTypes.h"
    #include "common/TADStructures.h"
    #include "common/TRSC_Inputs_Outputs.h"

#endif

namespace TAD2
{
    typedef struct Detection_Inputs_from_DLD_s
    {
        bool_t CamBlockStatus;
        bool_t LowLightStatus;
    } Detection_Inputs_from_DLD_t;

    typedef struct Detection_Inputs_from_NVM_s
    {
        TAD2::TrailerFeatures trailerFeatures;
        bool_t calibrateNewTrailer;
        bool_t calibrateHitchPoint;
        bool_t calibrateCollisionAngle;
        bool_t trailerLoadedSuccessfully;
        int32_t InputTrailerID;
        int32_t ConfigTrailerID;
    } Detection_Inputs_from_NVM_t;

    /** TAD algo input. **/
    struct JobTADInput
    {
        Detection_Inputs_from_NVM_t NVMInput;
        Detection_Inputs_from_TRSC_t StatemachineInput;
        Detection_Inputs_from_DLD_t DLDInput;
        TRSC_Tunable_Param_t tunableParams;
    };
}

#endif // __JOB_TAD_INPUT__H_

