// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [18-Jul-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __JOB_TAD_OUTPUT__H_
#define __JOB_TAD_OUTPUT__H_

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
    #include"common/TRSC_Inputs_Outputs.h"
#endif
const uint32_t v_MessageLenght_u32 = 260;
#ifndef RTW_HEADER_JobTADDebugOutput
#define RTW_HEADER_JobTADDebugOutput
struct JobTADDebugOutput
{
    // will contain calibrated template when 'trailerCalibrated' is 'true' and
    // will contain new found hitch-point when 'hitchCalibrated' is 'true'
    TAD2::TrailerFeatures::Trailers trailerCalibration;
    // angle used only for testing (deg)
    float32_t trailerAngle2;
    // 'true' iff the current angle output is valid
    bool_t trailerAngleValid;
    // the current template matching score (percentage)
    float32_t trackingScore;
    // hitch range valid
    bool_t hitchrangevalid;
    // the result score from scanning (percentage)
    float32_t scanningScore;
    // the detected collision angle of the trailer
    float32_t collisionAngle;
    float32_t leftcollisionangle;
    float32_t rightcollisionangle;
    // trailer calibration angle (deg) on the left side of 90 deg
    float32_t leftCalibrationAngle;
    // trailer calibration angle (deg) on the right side of 90 deg
    float32_t rightCalibrationAngle;
    // hitch calibration angle (deg) used for sampling
    float32_t hitchCalibrationAngle;
    // hitch range pos
    uint8_t hitch_range_pos;
    // bumper pos
    uint32_t bumper_pos;
    // hitch end range pos
    uint32_t hitch_end_range_pos;
    // hitch range calculation done;
    bool_t hitch_range_calculation_done;
    // dummy angles
    float32_t dummy_angle_1;
    float32_t dummy_angle_2;
    float32_t dummy_angle_3;
    float32_t dummy_angle_4;
    float32_t averageIllumination;
    // --- Other flags
    // tells whether or not the trailer is currently being calibrated (does NOT include implicit calibration)
    bool_t isTrailerCalibrating;
    // tells whether or not the hitch-point is currently being calibrated
    bool_t isHitchCalibrating;
    // indicates whether or not implicit calibration of the trailer is currently being performed
    bool_t isImplicitlyCalibrating;
    // tells whether or not a NEW trailer template has been created (implicit or direct)
    bool_t trailerRecalibrated;
    // tells whether or not trailer detection has run and is completed
    bool_t trailerDetectionComplete;
    // tells whether or not trailer presence has been detected
    bool_t trailerDetected;
    // tells trailer is present or not during trailer recognition
    bool_t trailerDetectedRecognitionState;
    // tells whether or not turnaround state has run and is completed
    bool_t turnaroundComplete;
    // tells whether or not beam length estimation done or not
    bool_t beamLengthEstimationDone;
    // tells whether Tracking Lost is running or not
    bool_t isTrackingLostRunning;
    // tells whether turn is compledted during turn around state
    bool_t isTurnCompletedinTurnAround;
    // tells whether Trailer Prediction Completed
    bool_t isTrailerPredictionCompleted;
    // the previous state
    TeTRSC_e_TADState prevState;

    // the previous sub-state
    int32_t prevSubState;
    // indicates a change in state
    bool_t stateChanged;
    // indicates a change in sub-state
    bool_t subStateChanged;
    // --- Other
    // calculated trailer parameters
    TAD2::TrailerParameters trailerParams;

    // --- Error
    // error level
    int32_t error;
    // error message
    char errorMessage[v_MessageLenght_u32];
    /*NVM debug flags*/
    // tells whether or not the input trailer was loaded properly and is being used
    bool_t trailerLoadedSuccessfully;
    // tells whether or not the collision angle is loaded successfully or not
    bool_t collisionangleLoadedSuccessfully;
    // tells whether or not the inputhitch was loaded properly and is being used
    bool_t hitchLoadedSuccessfully;
    // tells whether or not a NEW trailer template has been created (implicit or direct)
    bool_t trailerCalibrated;
    // tells whether or not a NEW hitch-point has been found
    bool_t hitchCalibrated;
    // 'true' iff the collision angle output is valid
    bool_t collisionAngleValid;
};
#endif

namespace TAD2
{






    typedef struct TrailerDetection_Output_NVM_s
    {
        // will contain calibrated template when 'trailerCalibrated' is 'true' and
        // will contain new found hitch-point when 'hitchCalibrated' is 'true'
        // will contain the Trailer Features
        TAD2::TrailerFeatures trailerFeatures;

    } TrailerDetection_Output_NVM_t;


    /** TAD algo output. **/
    struct JobTADOutput
    {
        TRSC_Inputs_from_TrailerDetection_t TRSC_TAD_output;
        TRSC_Output_from_VehicleControl_t TRSC_VC_Output;
        TrailerDetection_Output_NVM_t TRSC_NVM_Output;
        TrailerDetection_Output_DID_t TRSC_DIDOutput;
        TrailerDetection_Output_HMI_t HMIOutput;
    };
}

#endif // __JOB_TAD_OUTPUT__H_
