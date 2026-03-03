// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [05-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TAD_ALGO_OBJECT__H_
#define __TAD_ALGO_OBJECT__H_

#include "TADStateMachine.h"
#ifdef __QNX__
    #include "../common/config.h"
#else
    #include "common/config.h"
#endif
#include "JobTADOutput.h"

#include "ImplicitCalibrationObject.h"
#include "VehicleKinematics.h"
#include "PreProcessing.h"
#include "ImageThresholding.h"
#include "FeatureExtraction.h"
#include "HitchDetection.h"
#include "CollisionAngleDetection.h"
#ifdef __QNX__
    #include "../common/Image.h"
    #include "JobTADInput.h"
#else
    #include "common/Image.h"
    #include <JobTADinput.h>
    #include "common/TRSC_Inputs_Outputs.h"
#endif
/*@@ SUB_STRUCTURE = tadOutput
@@ STRUCTURE = JobTADOutput
@@ DATA_TYPE = STRUCTURE TrailerDetection_Output_NVM_t
@@ END
*/
extern TAD2::JobTADOutput tadOutput;
namespace TAD2
{
    /** The TAD algo object. Wrapper for all TAD algo. Resides below the job level. **/
    class TADAlgoObject
    {
    public:
        TADAlgoObject();
        virtual ~TADAlgoObject();

        // --- Exposed functions
        bool_t Init( tad2config::TADConfigData i_config, TAD2::VehicleParameters i_vehParams );
        bool_t Uninit();
        bool_t Start( TAD2::JobTADInput& i_jobinput );
        void Stop();
        void Reset( TAD2::JobTADInput& i_jobinput );
        void Run( int32_t i_frame, uint8_t* i_topViewPtr, const TAD2::RawVehicleData& i_VehData, const TAD2::RawKinematicData& i_KMData, Detection_Inputs_from_TRSC_t StatemachineInput, bool_t camBlockStatus );

        // --- Getters / Setters
        void GetOutput( TAD2::JobTADOutput& o_output ) const;
        void GetDebugOutput( JobTADDebugOutput& o_Debugoutput ) const;

        JobTADDebugOutput GetDebugOutput() const;
        TAD2::JobTADOutput GetOutput() const;
        TeTRSC_e_TADState getTADStateMachineState() const;
        TAD2::calibration::State::Enum getTADStateMachineSubState() const;
        _roi::ROI getROI() const;
        void SetError( int32_t i_error, const char* i_errorMessage );

    private:
        bool_t initOK;
        bool_t m_isRunning;

        // --- Input/output variables
        tad2config::TADConfigData m_config;
        TAD2::WarpedTopViewParameters m_warpedTopViewParams;
        TAD2::VehicleParameters m_vehicleParams;
        TAD2::JobTADOutput m_jobOutput;
        JobTADDebugOutput m_jobDebugOutput;

        // --- Modules
        TAD2::VehicleKinematics m_vehicleKinematicsObj;
        TAD2::PreProcessing m_preProcessingObj;
        TAD2::ImageThresholding m_imageThresholdingObj;
        TAD2::FeatureExtraction m_featureExtractionObj;
        cAngleDetection::CollisionAngleDetection m_collisionAngleDetectionObj;

        // --- State machines
        TADStateMachine m_stateMachine;
        ImplicitCalibration::ImplicitCalibrationObject m_implicitCalibrationObj;
        _roi::ROI m_processingROI;
        float32_t PreviousTrailerAngle_f32;

        // --- Private functions
        bool_t SanityCheck();
        void InitJobOutput();
        _roi::ROI GetProcessingROI();
        static float32_t FindAverageIllumination( const uint8_t* i_topViewPtr );

        // the previous state
        TeTRSC_e_TADState PreviousState;
    };

}

#endif // !__TAD_ALGO_OBJECT__H_
