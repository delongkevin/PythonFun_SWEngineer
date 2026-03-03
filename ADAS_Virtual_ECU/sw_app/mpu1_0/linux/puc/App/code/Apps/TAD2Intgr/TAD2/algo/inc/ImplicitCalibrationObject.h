// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [12-Aug-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __IMPLICIT_CALIBRATION_OBJECT_H
#define __IMPLICIT_CALIBRATION_OBJECT_H

#ifdef __QNX__
    #include "../common/Image.h"
#else
    #include "common/Image.h"
#endif
#include "CollisionAngleDetection.h"
#include "TemplateBuildUp.h"
#include "HitchDetection.h"
#include "AngleSampling.h"
#include "FeatureExtraction.h"
#include "ImageThresholding.h"
#include "VehicleKinematics.h"
#include "PreProcessing.h"

namespace TAD2
{

    class TADAlgoObject;
}

namespace tad2config
{
    struct TADConfigData;
}

namespace ImplicitCalibration
{

    /*
    * Implicit calibration object which runs continuously alongside the state machine.
    */
    class ImplicitCalibrationObject
    {
    public:
        ImplicitCalibrationObject( tad2config::TADConfigData& i_config, tad2config::CANAndVehicleConfigData i_CANconfig, const TAD2::VehicleParameters& i_vehicleParams, TAD2::TADAlgoObject* i_pAlgoObj, TAD2::VehicleKinematics* i_pVehicleKinematics, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction );
        ~ImplicitCalibrationObject();

        // --- Exposed functions
        void Start( bool_t i_wait, uint32_t i_hichPos );
        void Stop();
        void Reset( bool_t i_wait, uint32_t i_hichPos );
        void Run( int32_t i_frame, image::Image<uint8_t>& i_topView,
                  _roi::ROI& i_roi,
                  float32_t i_trailerAngel_deg, bool_t i_trailerAngleKnown, uint32_t i_hichPos );

        // --- Getters / Setters
        bool_t IsRunning()const;
        bool_t IsCalibrating()const;
        bool_t IsTrailerCalibrated()const;
        bool_t IsTrailerStraight()const;
        image::Image<uint8_t> GetCalibratedImage()const;
        void GetCalibrationAngles( float32_t& o_left, float32_t& o_right ) const;
        void SetHitchPoint( Point2i i_hitchPoint );

        _roi::ROI GetProcessingROI()const;

    private:
        bool_t m_initialized;
        bool_t m_isRunning;
        bool_t m_isCalibrating;
        bool_t m_trailerCalibrated;
        bool_t m_isTrailerStraight;
        bool_t TemplategenerationRunning;

        // --- Config params
        tad2config::TADConfigData& m_config;
        const tad2config::CalibrationConfigData& m_calibrationConfig;
        const tad2config::ImplicitCalibrationConfigData& m_implicitCalibrationConfig;
        tad2config::CANAndVehicleConfigData m_CANAndVehicleConfig;
        const TAD2::VehicleParameters& m_vehicleParams;
        TAD2::WarpedTopViewParameters m_warpedTopViewParams;

        // --- Other
        image::Image<uint8_t> m_calibratedTrailerTemplate;
        Point2i m_hitchPoint;



        // --- Top-level modules required by this state
        TAD2::VehicleKinematics* m_pVehicle;
        TAD2::PreProcessing* m_pPreProcessing;
        TAD2::ImageThresholding* m_pImageThresholding;
        TAD2::FeatureExtraction* m_pFeatureExtraction;

        // --- Calibration modules
        TAD2::TrailerAngleCalibration m_trailerAngleCalibrationObj;
        TemplateBuild::TemplateBuildUp m_templateBuildUpObj;

        // --- Algo object
        TAD2::TADAlgoObject* m_pAlgoObj;

        void RunCalibration( int32_t i_frame, image::Image<uint8_t>& i_topView,
                             _roi::ROI& i_roi,
                             float32_t i_trailerAngel_deg, bool_t i_trailerAngleKnown );

    };
}

#endif // !__IMPLICIT_CALIBRATION_OBJECT_H
