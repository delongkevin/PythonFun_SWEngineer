// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [17-Jul-2018]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "common/config.h"

/*
* Default config constructor.
*/
tad2config::CANAndVehicleConfigData::CANAndVehicleConfigData() :
    kinematicsEnabled( true ),
#if _WIN32
    simulateTimeStamp( true ),
#else
	simulateTimeStamp( false ),
#endif
    vehicleWheelAngleClockwise( true ), //Pankaj: Make it false for jeep vehicle unit testing
    rearBumper2hitch_mm( 285.0f )
{
    trailerBeamLengthRange_mm[0] = 800.0f;
    trailerBeamLengthRange_mm[1] = 6000.0f;
}

/*
* Default config constructor.
*/
tad2config::TrailerPresenceDetectionConfigData::TrailerPresenceDetectionConfigData() :
    enabled( true ),
    thresholdpoints( 50 ),
    NoOfRetry( 5 )
{
}

/*
* Default config constructor.
*/
tad2config::TrailerRecognitionConfigData::TrailerRecognitionConfigData() :
    enabled( true ),
    threshold( 0.25f ),
    NoOfRetry( 5 )
{
}

/*
* Default config constructor.
*/
tad2config::CollisionAngleDetectionConfigData::CollisionAngleDetectionConfigData() :
    enabled( false )
{
}

/*
* Default config constructor.
*/
tad2config::TrailerAngleCalibrationConfigData::TrailerAngleCalibrationConfigData() :
    enabled( true ),
    assumedInitialAngle( 4.0f ),
    angleTolerance_deg( 1.0f )
{
}

/*
* Default config constructor.
*/
tad2config::HitchDetectionConfigData::HitchDetectionConfigData() :
    enabled( true ),
    hitchMaskEnabled( true ),
    PreprocessingEnabled( true ),
    hitchXPos( 320 ),
    topViewPixelInfo( 1.33 )
{
    hitchYOffset[0] = 16;
    hitchYOffset[1] = 100;
}

/*
* Default config constructor.
*/
tad2config::TurnaroundConfigData::TurnaroundConfigData() :
    enabled( false )
{}

/*
* Default config constructor.
*/
tad2config::CalibrationConfigData::CalibrationConfigData() : trailerAngleCalConfigParams()
{
}

/*
* Default config constructor.
*/
tad2config::ImplicitCalibrationConfigData::ImplicitCalibrationConfigData() :
    enableContinuousCalibration( true ),
    angleToReachBeforeRecalibrating( 20.0f ),
    onlyCalibrateWhenAngleIsOff( false ),
    angleTolerance( 1.0f ),
    allowQuickCalibration( true ),
    maxAngleOffset( 5.0f )
{
}

/*
* Default config constructor.
*/
tad2config::TrailerAngleDetectionConfigData::TrailerAngleDetectionConfigData() :
    stopMatchingWhenVehicleStopped( false ),
    weightFactor( 1.0f ),
    outputFilterSize( 3 ),
    TrackingLost( true ),
    TrackingLostTimeOut( 200 ),
    TrackingLostThreshold( 0.15f ),
    DynamicWindowSize( false ),
    AngleFilerEnable( false )
{
}

/*
* Default config constructor.
*/
tad2config::TADConfigData::TADConfigData() :
    defaultHitchPoint( 322, 59 )
{
}
/*
* Default config constructor.
*/
tad2config::TADInputConfigData::TADInputConfigData() :
    calibrateNewTrailer( false ),
    calibrateHitchPoint( false ),
    calibrateCollisionAngle( false ),
    trailerID( -1 ),
    templateFolder( "TAD2/Templates/" )
{
}

/*
* Default config constructor.
*/
tad2config::DisplayConfigData::DisplayConfigData() :
    showSecondAngle( false ),
    showCalibrationAngles( true ),
    rateOfAngleChangeBufSize( 5 )
{
}

/*
* Default config constructor.
*/
tad2config::KPIConfigData::KPIConfigData() :
    enabled( false ),
    simulateOneTimeTrailerCalibration( false ),
    simulateOneTimeHitchCalibration( false ),
    useMostRecentTemplateWheneverPossible( false ),
    outputKPIResults2CSV( false ),
    outputKPIImages( false ),
    outputHitchBall( false ),
    outputCollisionAngle( false ),
    outputRecognition( false ),
    outputBeamLength( false ),
    beamlengthDataDump( false ),
    outputAbsencePresence( false ),
    showGTAngle( false )
{
}


/*
* Default config constructor.
*/
tad2config::TAD_ConfigData::TAD_ConfigData()
{
}

