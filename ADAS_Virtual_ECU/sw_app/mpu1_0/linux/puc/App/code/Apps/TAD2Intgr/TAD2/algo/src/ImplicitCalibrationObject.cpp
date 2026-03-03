// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [12-Aug-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "ImplicitCalibrationObject.h"
#include "common/config.h"
#include "TADAlgoObject.h"
#include "WarpLUT.h"

#include "VehicleKinematics.h"
#include "PreProcessing.h"
#include "ImageThresholding.h"
#include "FeatureExtraction.h"

namespace pointF
{
    static Point2i project( Point2i p, int32_t r, float32_t theta_deg )
    {
        float32_t theta_rad = mecl::math::toRadians_x( theta_deg );
        int32_t x = static_cast <int32_t>( static_cast <float32_t>( p.x ) + static_cast <float32_t>( r ) * mecl::math::trigonometry<float32_t>::cos_x( theta_rad ) );
        int32_t y = static_cast <int32_t>( static_cast <float32_t>( p.y ) + static_cast <float32_t>( r ) * mecl::math::trigonometry<float32_t>::sin_x( theta_rad ) );
        return Point2i( x, y );
    };
}
namespace ImplicitCalibration
{
    /**
    * Constructor.
    */
    ImplicitCalibrationObject::ImplicitCalibrationObject( tad2config::TADConfigData& i_config, tad2config::CANAndVehicleConfigData i_CANconfig, const TAD2::VehicleParameters& i_vehicleParams, TAD2::TADAlgoObject* i_pAlgoObj, TAD2::VehicleKinematics* i_pVehicleKinematics, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction ) :

        m_initialized( false ),
        m_isRunning( false ),
        m_isCalibrating( false ),
        m_trailerCalibrated( false ),
        m_isTrailerStraight( false ),
        m_config( i_config ),
        m_calibrationConfig( i_config.getCalibrationConfigParamsRef() ),
        m_implicitCalibrationConfig( i_config.getImplicitCalibrationConfigParamsRef() ),
        m_CANAndVehicleConfig( i_CANconfig ),
        m_vehicleParams( i_vehicleParams ),
        m_warpedTopViewParams( TAD2::getWarpedTopViewParams() ),
        m_pVehicle( i_pVehicleKinematics ),
        m_pPreProcessing( i_preProcessing ),
        m_pImageThresholding( i_pImageThresholding ),
        m_pFeatureExtraction( i_pFeatureExtraction ),
        m_pAlgoObj( i_pAlgoObj )


    {
    }

    /**
    * Destructor.
    */
    ImplicitCalibrationObject::~ImplicitCalibrationObject()
    {
    }

    /**
    * Start object.
    */
    void ImplicitCalibrationObject::Start( bool_t i_wait, uint32_t i_hichPos )
    {
        m_isRunning = true;
        m_isCalibrating = !i_wait;
        m_trailerCalibrated = false;
        m_isTrailerStraight = false;
        TemplategenerationRunning = false;

        // --- Initialize modules
        if( !m_initialized )
        {
            uint32_t hitchYOffset[2];
            hitchYOffset[0] = 0;
            hitchYOffset[1] = i_hichPos;
            m_initialized = true;
            m_initialized = m_initialized && m_trailerAngleCalibrationObj.Init( m_vehicleParams, m_CANAndVehicleConfig );
            m_initialized = m_initialized && m_templateBuildUpObj.Init( m_calibrationConfig.getHitchDetectionConfigData().getHitchX(), reinterpret_cast<uint32_t*>( hitchYOffset ) );

            if( !m_initialized )
            {
                m_pAlgoObj->SetError( 2, "Couldn't initialize Implicit Calibration." );
            }
        }

        // --- Start modules
        bool_t result = true;
        result = result && m_trailerAngleCalibrationObj.Start( mecl::math::abs_x( m_warpedTopViewParams.start_deg - 90.0f ), m_calibrationConfig.getTrailerAngleCalConfigParams().getToleranceDeg() );
        result = result && m_templateBuildUpObj.Start();

        if( !result )
        {
            m_pAlgoObj->SetError( 1, "Couldn't start Implicit Calibration." );
        }
    }

    /**
    * Stop object.
    */
    void ImplicitCalibrationObject::Stop()
    {
        memory::MemoryPool::ReleaseImage( m_calibratedTrailerTemplate );
        m_trailerAngleCalibrationObj.Finish();
        m_templateBuildUpObj.Finish();
        m_isRunning = false;
    }

    /**
    * Reset object. If 'i_wait' is true, calibration will wait until the angle threshold
    * is reached, otherwise, calibrating will begin immediately.
    *
    * Will also reset the calibrated flag.
    */
    void ImplicitCalibrationObject::Reset( bool_t i_wait, uint32_t i_hichPos )
    {
        Stop();
        Start( i_wait, i_hichPos );
    }

    /**
    * Run object.
    *
    * Once calibration is complete, the object will wait until the angle reaches the threshold
    * defined in the config before restarting.
    */
    void ImplicitCalibrationObject::Run( int32_t i_frame, image::Image<uint8_t>& i_topView,
#ifdef WIN_2015_CODE
    _roi::ROI& i_roi,
#endif
                                         float32_t i_trailerAngel_deg, bool_t i_trailerAngleKnown, uint32_t i_hichPos )
    {
        bool_t ret_val = true;

        if( ( !m_initialized ) || ( !m_isRunning ) )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            if( m_isCalibrating )
            {
                // --- Calibrate
                RunCalibration( i_frame, i_topView,
#ifdef WIN_2015_CODE
                                i_roi,
#endif
                                i_trailerAngel_deg, i_trailerAngleKnown );
            }
            else
            {
                // --- Wait
                m_isTrailerStraight = false;

                if( i_trailerAngleKnown && ( mecl::math::abs_x( 90.0f - i_trailerAngel_deg ) >= m_implicitCalibrationConfig.getAngleToReachBeforeRecalibrating() ) )
                {
                    Reset( false, i_hichPos );
                }
            }
        }
    }

    /**
    * Return whether implicit calibration is currently running.
    */
    bool_t ImplicitCalibrationObject::IsRunning()const
    {
        return m_isRunning;
    }

    /**
    * Return whether or not we are actually calibrating currently.
    */
    bool_t ImplicitCalibrationObject::IsCalibrating()const
    {
        return m_isRunning && m_isCalibrating;
    }

    /**
    * Return whether the implicit calibration has completed.
    */
    bool_t ImplicitCalibrationObject::IsTrailerCalibrated()const
    {
        return m_trailerCalibrated;
    }

    /**
    * Return whether the trailer is assumed to be straight, as given by the kinematic models.
    */
    bool_t ImplicitCalibrationObject::IsTrailerStraight()const
    {
        return m_isTrailerStraight;
    }

    /**
    * Get the calibrated template image. Only valid after 'IsTrailerCalibrated()' returns true.
    */
    image::Image<uint8_t> ImplicitCalibrationObject::GetCalibratedImage()const
    {
        return m_calibratedTrailerTemplate;
    }

    /**
    * Get the current angles of the kinematic models used.
    */
    void ImplicitCalibrationObject::GetCalibrationAngles( float32_t& o_left, float32_t& o_right ) const
    {
        m_trailerAngleCalibrationObj.GetCalibrationAngles( o_left, o_right );
    }

    /**
    * Set the hitchpoint used in ImageThresholding.
    */
    void ImplicitCalibrationObject::SetHitchPoint( Point2i i_hitchPoint )
    {
        m_hitchPoint = i_hitchPoint;
    }

    /*
    * Calculate the necessary region where all processing will be done, depending
    * on the current state, hitchpoint, and angle of the state machine.
    */
    _roi::ROI ImplicitCalibrationObject::GetProcessingROI()const
    {
        // --- Get the hitch and angle range
        Point2i hitch_range[2] = { m_hitchPoint , m_hitchPoint };
        float32_t trailer_angle_range_deg[2] = { 90.0f, 90.0f };
        // --- Get the boundaries of the roi
        int32_t margin = 3;
        int32_t template_radius = global::TEMPLATE_IMAGE_HEIGHT + m_warpedTopViewParams.yOffset;
        float32_t template_range_deg = static_cast<float32_t>( global::TEMPLATE_IMAGE_WIDTH ) * m_warpedTopViewParams.degreesPerPixel;
        float32_t total_angle_range_deg[2] = { trailer_angle_range_deg[0] - template_range_deg / 2.0f , trailer_angle_range_deg[1] + template_range_deg / 2.0f };
        int32_t top;
        int32_t bottom;
        int32_t left;
        int32_t right;
        Point2i p1 = pointF::project( hitch_range[0], template_radius, total_angle_range_deg[0] );
        Point2i p2 = pointF::project( hitch_range[0], template_radius, total_angle_range_deg[1] );
        Point2i p3 = pointF::project( hitch_range[1], template_radius, total_angle_range_deg[0] );
        Point2i p4 = pointF::project( hitch_range[1], template_radius, total_angle_range_deg[1] );

        // top
        if( ( total_angle_range_deg[0] <= 270.0f ) && ( 270.0f <= total_angle_range_deg[1] ) )
        {
            top = hitch_range[0].y - template_radius;
        }
        else
        {
            top = mms::minimum( p1.y, p2.y );
        }

        // bottom
        if( ( total_angle_range_deg[0] <= 90.0f ) && ( 90.0f <= total_angle_range_deg[1] ) )
        {
            bottom = hitch_range[1].y + template_radius;
        }
        else
        {
            bottom = mms::maximum( p3.y, p4.y );
        }

        // left
        if( ( total_angle_range_deg[0] <= 180.0f ) && ( 180.0f <= total_angle_range_deg[1] ) )
        {
            left = hitch_range[0].x - template_radius;
        }
        else
        {
            left = mms::minimum( p1.x, p2.x );
        }

        // right
        if( ( total_angle_range_deg[0] <= 0.0f ) && ( 0.0f <= total_angle_range_deg[1] ) )
        {
            right = hitch_range[0].x + template_radius;
        }
        else
        {
            right = mms::maximum( p1.x, p2.x );
        }

        int32_t w = global::TOPVIEW_IMAGE_WIDTH;
        int32_t h = global::TOPVIEW_IMAGE_HEIGHT;
        top = mms::maximum( 0, mms::minimum( top, hitch_range[0].y ) - margin );
        bottom = mms::minimum( h, mms::maximum( bottom, hitch_range[1].y ) + margin );
        left = mms::maximum( 0, mms::minimum( left, hitch_range[0].x ) - margin );
        right = mms::minimum( w, mms::maximum( right, hitch_range[1].x ) + margin );
        return _roi::ROI( left, top, right - left, bottom - top );
    }

    /*
    * Calibrate.
    */
    void ImplicitCalibrationObject::RunCalibration( int32_t i_frame, image::Image<uint8_t>& i_topView,
#ifdef WIN_2015_CODE
    _roi::ROI& i_roi,
#endif
            float32_t i_trailerAngel_deg, bool_t i_trailerAngleKnown )
    {
        bool_t speedAboveThreshold = true;
        m_isTrailerStraight = true;

        // --- Calibrate trailer angle
        if( m_calibrationConfig.getTrailerAngleCalConfigParams().getEnabled() && m_config.getCanAndVehicleConfigParams().getKinematics() )
        {
            m_trailerAngleCalibrationObj.Run( i_frame, m_pVehicle, false );

            // check if calibration can be sped up due to TAD having recieved some angle
            if( m_implicitCalibrationConfig.getAllowQuickCalibration() && i_trailerAngleKnown )
            {
                m_trailerAngleCalibrationObj.QuickCalibrate( i_trailerAngel_deg, m_implicitCalibrationConfig.getMaxAngleOffset() );
            }

            if( !m_trailerAngleCalibrationObj.TrailerAngleCalibrated() )
            {
                m_isTrailerStraight = false;
            }
        }

        // --- Check kinematics
        if( m_config.getCanAndVehicleConfigParams().getKinematics() && ( m_pVehicle->currentSpeed_mps() < vehspeed::c_minVehSpeedDuringTemplateBuildUp ) )
        {
            speedAboveThreshold = false;
        }

        if( m_config.getCanAndVehicleConfigParams().getKinematics() && !m_pVehicle->speed_valid() )
        {
            speedAboveThreshold = false;
        }

        // --- Check if calibration is set only for when the angle is off
        bool_t checkAngle = true;

        if( m_implicitCalibrationConfig.getOnlyCalibrateWhenAngleIsOff() )
        {
            if( mecl::math::abs_x( 90.0f - i_trailerAngel_deg ) > m_implicitCalibrationConfig.getAngleTolerance() )
            {
                checkAngle = true;
            }
            else
            {
                checkAngle = false;
            }
        }

        if( m_pVehicle->gearDir() == TAD2::GearReverse )
        {
            m_isTrailerStraight = false;
        }

        // --- Perform template build up only if all checks are good
        if( m_isTrailerStraight && speedAboveThreshold && !m_templateBuildUpObj.IsTemplateFound() && checkAngle )
        {
            TemplategenerationRunning = true;
#ifdef WIN_2015_CODE
            Point2i hitchPoint = m_hitchPoint;
            TAD2::WarpedImage<uint8_t> warpedEdges = TAD2::WarpedImage<uint8_t>( m_warpedTopViewParams, memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
            // --- Warp edges
            m_pPreProcessing->WarpImage( i_topView, warpedEdges, hitchPoint );
            //cv::Mat im2 = processing::ImageProcessing::ConvertToCV( warpedEdges );
            // --- Pre-processing
            m_pPreProcessing->Run( i_frame, warpedEdges, i_roi );
            image::Image<uint8_t> topView = m_pPreProcessing->GetWorkingTopView();
            //cv::Mat im3 = processing::ImageProcessing::ConvertToCV( topView );
            //
            // --- Edge Detection
            image::Image<uint16_t> lowThresh = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
            image::Image<uint16_t> highThresh = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
            image::Image<uint16_t> gradMag = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
            image::Image<uint8_t> gradDir = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
            //
            bool_t warpedimg = true;
            m_pImageThresholding->Run( i_frame, topView, i_roi, hitchPoint, 90.0f, true, lowThresh, highThresh, gradMag, gradDir, false, warpedimg );
            m_pFeatureExtraction->Run( i_frame, topView, lowThresh, highThresh, i_roi, gradMag, gradDir );
            image::Image<uint8_t>& edges = m_pFeatureExtraction->GetEdges();
            //cv::Mat im4 = processing::ImageProcessing::ConvertToCV( edges );
            memcpy( warpedEdges.getData(), edges.getData(), global::WARPED_TOPVIEW_IMAGE_HEIGHT * global::WARPED_TOPVIEW_IMAGE_WIDTH );
            //
            memory::MemoryPool::ReleaseImage( lowThresh );
            memory::MemoryPool::ReleaseImage( highThresh );
            memory::MemoryPool::ReleaseImage( gradMag );
            memory::MemoryPool::ReleaseImage( gradDir );
            //
#ifdef DIAGNOSTICS
            db::imshow( "(TAD 1) Warped Edges", edges, db::ImShow_Binary );
#endif
#else  // EMBD - TBD
            image::Image<uint8_t> topView = e.topView;
            //
            // --- Edge Detection
            point::Point2i hitchPoint = super->GetHitchPoint();
            image::Image<uint8_t>& edges = m_pFeatureExtraction->GetEdges();
            //
            // --- Warp edges
            TAD2::WarpedImage<uint8_t> warpedEdges = TAD2::WarpedImage<uint8_t>( m_warpedTopViewParams, memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
            m_pPreProcessing->WarpImage( edges, warpedEdges, hitchPoint );
#endif
            // --- Build trailer template
            m_templateBuildUpObj.Run( i_frame, warpedEdges );

            // --- Check if finished
            if( m_templateBuildUpObj.IsTemplateFound() )
            {
                // --- Create trailer template image
                m_templateBuildUpObj.CreateInitialTemplate( warpedEdges );
                m_calibratedTrailerTemplate = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
                int32_t xAt90 = warpedEdges.Angle2XPos( 90.0f );
                t_m::TemplateMatching::ExtractTemplate( warpedEdges, m_calibratedTrailerTemplate, xAt90 - m_calibratedTrailerTemplate.getWidth() / 2, 0 );
                //cv::Mat im5 = processing::ImageProcessing::ConvertToCV( m_calibratedTrailerTemplate );
                //
                m_trailerAngleCalibrationObj.Finish();
                m_templateBuildUpObj.Finish();
                m_isCalibrating = false;
                m_trailerCalibrated = true;
            }

            memory::MemoryPool::ReleaseImage( warpedEdges );
        }
        else
        {
            // Resetting data in Template generation
            if( TemplategenerationRunning )
            {
                m_templateBuildUpObj.Finish();
                m_templateBuildUpObj.Start();
            }

            TemplategenerationRunning = false;
        }
    }
}
