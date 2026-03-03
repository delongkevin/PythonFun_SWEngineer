//--------------------------------------------------------------------------
/// @file Config.h
//--------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author HAROLD JOSEPH (harold.joseph@magna.com)
///
//--------------------------------------------------------------------------

#ifndef __CONFIG_H__
#define __CONFIG_H__
#include "Defines.h"
#include <mecl/core/MeclTypes.h>
#ifdef __QNX__
    #include "meal/camera/core/inc/CameraPoint.h"
#endif

#define MAX_PATH_LEN 200


#define TAD_MAX_PATH_LEN 200


namespace tad2config
{
    /*
    * Config regarding CAN inputs and vehicle parameters.
    */
    struct CANAndVehicleConfigData
    {
    private:
        bool_t kinematicsEnabled;
        bool_t simulateTimeStamp;
        bool_t vehicleWheelAngleClockwise;
        float32_t rearBumper2hitch_mm;
        float32_t trailerBeamLengthRange_mm[2];
    public:
        CANAndVehicleConfigData();
        //Getters
        inline bool_t getKinematics() const
        {
            return kinematicsEnabled;
        }
        inline float32_t getBumper2Hitch_mm()
        {
            return rearBumper2hitch_mm;
        }
        inline bool_t getTime() const
        {
            return simulateTimeStamp;
        }
        inline bool_t getAngleCW() const
        {
            return vehicleWheelAngleClockwise;
        }

        inline float32_t* getBumper2Hitch_mmRef()
        {
            return &rearBumper2hitch_mm;
        }
        inline float32_t* getBeamLengthRange_mmRef()
        {
            return &trailerBeamLengthRange_mm[0];
        }
        //Setters
        inline void setKinematics( bool_t kinematics_val )
        {
            kinematicsEnabled = kinematics_val;
        }
        inline void setTime( bool_t time_val )
        {
            simulateTimeStamp = time_val;
        }
        inline void setAngleCW( bool_t angleCW_val )
        {
            vehicleWheelAngleClockwise = angleCW_val;
        }
    };

    /*
    * Config regarding "Trailer Presence Detection."
    */
    struct TrailerPresenceDetectionConfigData
    {
    private:
        bool_t enabled;
        uint32_t thresholdpoints;
        uint32_t NoOfRetry;
    public:
        TrailerPresenceDetectionConfigData();

        //Setters
        inline void setEnabled( bool_t enabled_val )
        {
            enabled = enabled_val;
        }
        inline void setthresholdpoints( int32_t i_thresholdpoints )
        {
            thresholdpoints = i_thresholdpoints;
        }
        inline void setNoOfRetry( int32_t i_NoOfRetry )
        {
            NoOfRetry = i_NoOfRetry;
        }
        //Getters
        inline bool_t getEnabled() const
        {
            return enabled;
        }
        inline uint32_t getthresholdpoints() const
        {
            return thresholdpoints;
        }
        inline uint32_t getNoOfRetry() const
        {
            return NoOfRetry;
        }
    };
    /*
    * Config regarding "Trailer Recognition."
    */
    struct TrailerRecognitionConfigData
    {
    private:
        bool_t enabled;
        float32_t threshold;
        uint32_t NoOfRetry;
    public:
        TrailerRecognitionConfigData();

        //Setters
        inline void setEnabled( bool_t enabled_val )
        {
            enabled = enabled_val;
        }
        inline void setthreshold( float32_t threshold_val )
        {
            threshold = threshold_val;
        }
        inline void setNoOfRetry( uint32_t i_NoOfRetry )
        {
            NoOfRetry = i_NoOfRetry;
        }

        //Getters
        inline bool_t getEnabled() const
        {
            return enabled;
        }
        inline float32_t getthreshold() const
        {
            return threshold;
        }
        inline uint32_t getNoOfRetry() const
        {
            return NoOfRetry;
        }

    };

    /*
    * Config regarding "Collision Angle Detection."
    */
    struct CollisionAngleDetectionConfigData
    {
    private:
        bool_t enabled;
    public:
        CollisionAngleDetectionConfigData();
        //Getter & Setter
        inline bool_t getEnabled() const
        {
            return enabled;
        }
        inline void setEnabled( bool_t enabled_val )
        {
            enabled = enabled_val;
        }
    };

    /*
    * Config regarding "Trailer Angle Calibration."
    */
    struct TrailerAngleCalibrationConfigData
    {
    private:
        bool_t enabled;
        float32_t assumedInitialAngle;
        float32_t angleTolerance_deg;
    public:
        TrailerAngleCalibrationConfigData();
        inline void setEnabled( bool_t enabled_val )
        {
            enabled = enabled_val;
        }
        inline bool_t getEnabled() const
        {
            return enabled;
        }
        inline float32_t getInitialAngle() const
        {
            return assumedInitialAngle;
        }
        inline float32_t getToleranceDeg() const
        {
            return angleTolerance_deg;
        }
        inline const float32_t* getInitialAngleRef() const
        {
            return &assumedInitialAngle;
        }
        inline const float32_t* getToleranceDegRef() const
        {
            return &angleTolerance_deg;
        }
    };

    /*
    * Config regarding "Hitch Detection."
    */
    struct HitchDetectionConfigData
    {
    private:
        bool_t enabled;
        bool_t hitchMaskEnabled;
        bool_t PreprocessingEnabled;
        uint32_t hitchXPos;
        uint32_t hitchYOffset[2];
        float32_t topViewPixelInfo;
    public:

        HitchDetectionConfigData();
        inline uint32_t getHitchX() const
        {
            return hitchXPos;
        }
        inline const uint32_t* getHitchYOffsetRef() const
        {
            return hitchYOffset;
        }
        inline bool_t getHitchMaskEnabled() const
        {
            return hitchMaskEnabled;
        }
        inline bool_t getPreprocessingEnabled() const
        {
            return PreprocessingEnabled;
        }
        inline float32_t getTopViewPixelInfo() const
        {
            return topViewPixelInfo;
        }
        inline void setHitchYOffset_bumperRef( uint32_t val )
        {
            hitchYOffset[0] = val;
        }
        inline void setPreprocessingEnabled( bool_t PreprocessingEnabled_val )
        {
            PreprocessingEnabled = PreprocessingEnabled_val;
        }
        inline void setHitchMaskEnabled( bool_t hitchMaskEnabled_val )
        {
            hitchMaskEnabled = hitchMaskEnabled_val;
        }
        inline void setHitchX( uint32_t hitchXPos_val )
        {
            hitchXPos = hitchXPos_val;
        }
        inline void setTopViewPixelInfo( float32_t topViewPixelInfo_val )
        {
            topViewPixelInfo = topViewPixelInfo_val;
        }
        inline bool_t getEnabled() const
        {
            return enabled;
        }
        inline void setEnabled( bool_t enabled_val )
        {
            enabled = enabled_val;
        }
    };

    /*
    * Config regarding "Turnaround."
    */
    struct TurnaroundConfigData
    {
    private:
        bool_t enabled;
    public:

        inline bool_t getEnabled() const
        {
            return enabled;
        }

        inline void setEnabled( bool_t enabled_val )
        {
            enabled = enabled_val;
        }

        TurnaroundConfigData();
    };

    /*
    * Config regarding Trailer Angle Detection.
    */
    struct TrailerAngleDetectionConfigData
    {
    private:
        bool_t stopMatchingWhenVehicleStopped;
        float32_t weightFactor;
        uint32_t outputFilterSize;
        bool_t TrackingLost;
        uint32_t TrackingLostTimeOut;
        float32_t TrackingLostThreshold;
        bool_t DynamicWindowSize;
        bool_t AngleFilerEnable;
    public:
        TrailerAngleDetectionConfigData();

        inline bool_t getAngleFilerEnable() const
        {
            return AngleFilerEnable;
        }

        inline void setAngleFilerEnable( bool_t AngleFilerEnable_val )
        {
            AngleFilerEnable = AngleFilerEnable_val;
        }

        inline bool_t getDynamicWindowSize() const
        {
            return DynamicWindowSize;
        }

        inline void setDynamicWindowSize( bool_t DynamicWindowSize_val )
        {
            DynamicWindowSize = DynamicWindowSize_val;
        }

        inline float32_t getTrackingLostThreshold() const
        {
            return TrackingLostThreshold;
        }

        inline const float32_t* getTrackingLostThresholdRef() const
        {
            return &TrackingLostThreshold;
        }

        inline bool_t getTrackingLost() const
        {
            return TrackingLost;
        }

        inline uint32_t getTrackingLostTimeOut() const
        {
            return TrackingLostTimeOut;
        }

        inline const uint32_t* setTrackingLostTimeOutRef() const
        {
            return &TrackingLostTimeOut;
        }

        inline void setTrackingLost( bool_t TrackingLost_val )
        {
            TrackingLost = TrackingLost_val;
        }

        inline uint32_t getOutputFilterSize() const
        {
            return outputFilterSize;
        }

        inline const uint32_t* getOutputFilterSizeRef() const
        {
            return &outputFilterSize;
        }

        inline float32_t getWeightFactor() const
        {
            return weightFactor;
        }

        inline const float32_t* getWeightFactorRef() const
        {
            return &weightFactor;
        }

        inline bool_t getStopMatchingWhenVehicleStopped() const
        {
            return stopMatchingWhenVehicleStopped;
        }

        inline void setStopMatchingWhenVehicleStopped( bool_t stopMatchingWhenVehicleStopped_val )
        {
            stopMatchingWhenVehicleStopped = stopMatchingWhenVehicleStopped_val;
        }

    };

    /*
    * Config regarding Calibration.
    */
    struct CalibrationConfigData
    {
    private:
        TrailerAngleCalibrationConfigData trailerAngleCalConfigParams;
        HitchDetectionConfigData hitchDetectionConfigData;
        TurnaroundConfigData turnaroundConfigData;
        TrailerAngleDetectionConfigData trailerAngleDetectionConfigData;
    public:
        CalibrationConfigData();

        inline TrailerAngleCalibrationConfigData getTrailerAngleCalConfigParams() const
        {
            return trailerAngleCalConfigParams;
        }

        inline TrailerAngleCalibrationConfigData& getTrailerAngleCalConfigRef()
        {
            return trailerAngleCalConfigParams;
        }

        inline void setTrailerAngleCalConfigParams( TrailerAngleCalibrationConfigData trailerAngleCalConfigParams_val )
        {
            trailerAngleCalConfigParams = trailerAngleCalConfigParams_val;
        }


        inline HitchDetectionConfigData getHitchDetectionConfigData() const
        {
            return hitchDetectionConfigData;
        }

        inline HitchDetectionConfigData& getHitchDetectionConfigDataRef()
        {
            return hitchDetectionConfigData;
        }

        inline void setHitchDetectionConfigData( HitchDetectionConfigData hitchDetectionConfigData_val )
        {
            hitchDetectionConfigData = hitchDetectionConfigData_val;
        }

        inline TurnaroundConfigData getTurnaroundConfigData() const
        {
            return turnaroundConfigData;
        }

        inline TurnaroundConfigData& getTurnaroundConfigDataRef()
        {
            return turnaroundConfigData;
        }

        inline void setTurnaroundConfigData( TurnaroundConfigData turnaroundConfigdata_val )
        {
            turnaroundConfigData = turnaroundConfigdata_val;
        }

        inline TrailerAngleDetectionConfigData getTrailerAngleDetectionConfigData() const
        {
            return trailerAngleDetectionConfigData;
        }

        inline const TrailerAngleDetectionConfigData& getTrailerAngleDetectionConfigDataRef() const
        {
            return trailerAngleDetectionConfigData;
        }

        inline void setTrailerAngleDetectionConfigData( TrailerAngleDetectionConfigData trailerAngleDetectionConfigData_val )
        {
            trailerAngleDetectionConfigData = trailerAngleDetectionConfigData_val;
        }


    };

    /*
    * Extra calibration configs needed for Implicit Calibration.
    */
    struct ImplicitCalibrationConfigData
    {
    private:
        bool_t enableContinuousCalibration;
        float32_t angleToReachBeforeRecalibrating;
        bool_t onlyCalibrateWhenAngleIsOff;
        float32_t angleTolerance;
        bool_t allowQuickCalibration;
        float32_t maxAngleOffset;
    public:
        ImplicitCalibrationConfigData();

        inline const float32_t* getMaxAngleOffsetRef() const
        {
            return &maxAngleOffset;
        }
        inline const float32_t* getAngleToleranceRef() const
        {
            return &angleTolerance;
        }
        inline const float32_t* getAngleToReachBeforeRecalibratingRef() const
        {
            return &angleToReachBeforeRecalibrating;
        }
        inline bool_t getAllowQuickCalibration() const
        {
            return allowQuickCalibration;
        }
        inline float32_t getMaxAngleOffset() const
        {
            return maxAngleOffset;
        }
        inline float32_t getAngleTolerance() const
        {
            return angleTolerance;
        }
        inline bool_t getOnlyCalibrateWhenAngleIsOff() const
        {
            return onlyCalibrateWhenAngleIsOff;
        }
        inline float32_t getAngleToReachBeforeRecalibrating() const
        {
            return angleToReachBeforeRecalibrating;
        }
        inline bool_t getEnableContinuousCalibration() const
        {
            return enableContinuousCalibration;
        }

        inline void setAllowQuickCalibration( bool_t allowQuickCalibration_val )
        {
            allowQuickCalibration = allowQuickCalibration_val;
        }
        inline void setOnlyCalibrateWhenAngleIsOff( bool_t onlyCalibrateWhenAngleIsOff_val )
        {
            onlyCalibrateWhenAngleIsOff = onlyCalibrateWhenAngleIsOff_val;
        }
        inline void setEnableContiniousCalibration( bool_t enableContinuousCalibration_val )
        {
            enableContinuousCalibration = enableContinuousCalibration_val;
        }
    };


    /*
    * Algo config.
    */
    struct TADConfigData
    {
    private:
        CANAndVehicleConfigData canAndVehicleConfigParams;
        CollisionAngleDetectionConfigData collisionAngleDetectionConfigParams;
        CalibrationConfigData calibrationConfigParams;
        TrailerRecognitionConfigData trailerRecognitionParms;
        TrailerPresenceDetectionConfigData trailerDetectionConfigParams;
        ImplicitCalibrationConfigData implicitCalibrationConfigParams;
        TrailerAngleDetectionConfigData tadConfigParams;
        Point2i defaultHitchPoint;
    public:


        TADConfigData();

        inline CANAndVehicleConfigData getCanAndVehicleConfigParams()
        {
            return canAndVehicleConfigParams;
        }

        inline const CalibrationConfigData& getCalibrationConfigParamsRef() const
        {
            return calibrationConfigParams;
        }

        inline const CollisionAngleDetectionConfigData& getCollisionAngleDetectionConfigParamsRef() const
        {
            return collisionAngleDetectionConfigParams;
        }

        inline const Point2i& getDefaultHitchPointRef() const
        {
            return defaultHitchPoint;
        }

        inline const ImplicitCalibrationConfigData& getImplicitCalibrationConfigParamsRef() const
        {
            return implicitCalibrationConfigParams;
        }

        inline const TrailerAngleDetectionConfigData& getTadConfigParamsRef() const
        {
            return tadConfigParams;
        }

        inline const TrailerRecognitionConfigData& getTrailerRecognitionConfigParamsRef() const
        {
            return trailerRecognitionParms;
        }
        inline const TrailerPresenceDetectionConfigData& getTrailerDetectionConfigParamsRef() const
        {
            return trailerDetectionConfigParams;
        }

        //Setters
        inline void setCANAndVehicleConfigParams( CANAndVehicleConfigData CANAndVehicleConfigParams_val )
        {
            canAndVehicleConfigParams = CANAndVehicleConfigParams_val;
        }
        inline void setCollisionAngleDetectionConfigParams( CollisionAngleDetectionConfigData collisionAngleDetectionConfigParams_val )
        {
            collisionAngleDetectionConfigParams = collisionAngleDetectionConfigParams_val;
        }
        inline void setTrailerRecognitionConfigParams( TrailerRecognitionConfigData val )
        {
            trailerRecognitionParms = val;
        }
        inline void setTrailerDetectionConfigParams( TrailerPresenceDetectionConfigData val )
        {
            trailerDetectionConfigParams = val;
        }
        inline void setImplicitCalibrationConfigParams( ImplicitCalibrationConfigData calibration_val )
        {
            implicitCalibrationConfigParams = calibration_val;
        }
        inline void setTadConfigParams( TrailerAngleDetectionConfigData tadConfigParams_val )
        {
            tadConfigParams = tadConfigParams_val;
        }
        inline void setCalibrationConfigParams( CalibrationConfigData calibrationConfigParams_val )
        {
            calibrationConfigParams = calibrationConfigParams_val;
        }
    };
    /*
    * Config for TAD input.
    */
    struct TADInputConfigData
    {
        bool_t calibrateNewTrailer;
        bool_t calibrateHitchPoint;
        bool_t calibrateCollisionAngle;
        int32_t trailerID;

        char templateFolder[TAD_MAX_PATH_LEN];

        TADInputConfigData();
    };

    /*
    * Config for display.
    */
    struct DisplayConfigData
    {
        bool_t showSecondAngle;
        int32_t showCalibrationAngles;
        uint32_t rateOfAngleChangeBufSize;

        DisplayConfigData();
    };

    /*
    * Config for KPI.
    */
    struct KPIConfigData
    {
        bool_t enabled;
        bool_t simulateOneTimeTrailerCalibration;
        bool_t simulateOneTimeHitchCalibration;
        bool_t useMostRecentTemplateWheneverPossible;
        bool_t outputKPIResults2CSV;
        bool_t outputKPIImages;
        bool_t outputHitchBall;
        bool_t outputCollisionAngle;
        bool_t outputRecognition;
        bool_t outputBeamLength;
        bool_t beamlengthDataDump;
        bool_t outputAbsencePresence;
        bool_t showGTAngle = false;
        char KPIGroundTruthFolder[MAX_PATH_LEN];
        char KPIResultsFolder[MAX_PATH_LEN];
        char KPIImagesFolder[MAX_PATH_LEN];
        char KPIHitchFolder[MAX_PATH_LEN];
        char KPICollisionAngleFolder[MAX_PATH_LEN];

        KPIConfigData();
    };

    /*
    * Config wrapper.
    */
    struct TAD_ConfigData
    {

        TADInputConfigData inputConfigParams;
        DisplayConfigData displayConfigParams;
        KPIConfigData kpiConfigParams;
        TADConfigData tadConfigParams;
        TAD_ConfigData();
    };
}

#endif // !__CONFIG_H__
