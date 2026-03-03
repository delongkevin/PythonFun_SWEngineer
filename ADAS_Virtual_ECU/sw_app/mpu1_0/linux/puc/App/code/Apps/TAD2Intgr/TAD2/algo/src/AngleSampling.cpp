// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Jun-2019]
// --- Last Modified by Joshua Teichroeb [06-Jun-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include <math.h>
#include "AngleSampling.h"
#include "TADStructures.h"
#include "TemplateMatching.h"
#include "PreProcessing.h"



#ifdef DIAGNOSTICS
    #include "global.h"
    #include "common/db.h"
    #include "fo.h"
#endif

/*
* Constructor.
*/
sampling::AngleSampling::AngleSampling() :
    m_initOK( false ),
    m_isRunning( false ),
    m_lastFrameRun( 0 )
{
    for( uint8_t Itr_u8 = 0; Itr_u8 < 3; ++Itr_u8 )
    {
        dummy_angle[Itr_u8] = 0;
    }
}

/*
* Destructor.
*/
sampling::AngleSampling::~AngleSampling()
{
}

/*
* Initialize this module.
*
* Called once at the beginning of the program, before any other functions.
*/
bool_t sampling::AngleSampling::Init( const TAD2::VehicleParameters& i_vehicleParams, const TAD2::PreProcessing* i_pPreProcessing, const float32_t i_trailerBeamLengthRange[2], uint32_t hitch_xpos, uint32_t i_hitch_start, uint32_t i_hitch_stop, uint32_t i_hitch_diff )
{
    float32_t avg_beamlength = ( i_trailerBeamLengthRange[0] + i_trailerBeamLengthRange[1] ) / 2.0f;                        /* PRQA S 3706*/
    m_biasTrailerModel.Init( i_vehicleParams, i_trailerBeamLengthRange[0], i_trailerBeamLengthRange[1], 200.0f, -20.0f );   /* PRQA S 3706*/
    m_avgTrailerModel.Init( i_vehicleParams, avg_beamlength, avg_beamlength, 200.0f, -20.0f );
    m_hitch_Xpos = hitch_xpos;
    m_hitch_start_pos = i_hitch_start;
    m_hitch_stop_pos = i_hitch_stop;
    m_hitch_diff = i_hitch_diff;
    m_pPreProcessing = i_pPreProcessing;
    //
    m_initOK = true;
    return true;
}

/*
* Signifies the beginning of a period of execution. Allocates any necessary
* memory and sets any input parameters needed at runtime.
*/
bool_t sampling::AngleSampling::Start()
{
    bool_t returnVal_b = true;

    if( !m_initOK )
    {
        returnVal_b = false;
    }
    else
    {
        if( m_isRunning )
        {
            Finish();
        }

        m_biasTrailerModel.Start( 90.0f );
        m_avgTrailerModel.Start( 90.0f );
        m_largestAngle_deg = 0.0f;
        m_prevAngleSet_deg = 0.0f;
        m_curAngleDif_deg = 1.0f;
        m_curWaitTime = 0;
        hitch_range_pos = 0;
        m_bAngleRangeReached = false;
        m_angleImgList.clear();
        scores[0][1] = static_cast <float32_t>( m_hitch_start_pos + ( 1 * ( m_hitch_diff / 5 ) ) );
        scores[1][1] = static_cast <float32_t>( m_hitch_start_pos + ( 2 * ( m_hitch_diff / 5 ) ) );
        scores[2][1] = static_cast <float32_t>( m_hitch_start_pos + ( 3 * ( m_hitch_diff / 5 ) ) );
        scores[3][1] = static_cast <float32_t>( m_hitch_start_pos + ( 4 * ( m_hitch_diff / 5 ) ) );
        scores[0][0] = 0.0f;
        scores[1][0] = 0.0f;
        scores[2][0] = 0.0f;
        scores[3][0] = 0.0f;
        dummy_angle[0] = 0.0f;
        dummy_angle[1] = 0.0f;
        dummy_angle[2] = 0.0f;
        dummy_angle[3] = 0.0f;
        //
#ifdef DIAGNOSTICS
        // --- Debugging
        db::createWindow( m_debugWindowName1, global::TOPVIEW_IMAGE_WIDTH * 3, global::TOPVIEW_IMAGE_HEIGHT * 3 );
        char panelname[260];

        for( uint32_t i = 0; i < c_numImages; i++ )
        {
            sprintf( panelname, "(HD-1) Angle Image %d", i );
            db::createView( panelname );
            db::addViewToWindow( m_debugWindowName1, panelname, i / 3, i % 3 );
        }

#endif
        m_lastFrameRun = 0;
        m_isRunning = true;
    }

    return returnVal_b;
}

/*
* Signifies the end of a period of execution. Deallocates any memory used.
*/
void sampling::AngleSampling::Finish()
{
    ReleaseImages();
    m_biasTrailerModel.Finish();
    m_avgTrailerModel.Finish();
    m_isRunning = false;
}

/*
* Run this module.
*
* Will only run if called between a call to Start() and a call to Finish(), respectively.
* Records the given frame so as to not run the same frame multiple times.
*/
void sampling::AngleSampling::Run( uint32_t i_frame, image::Image<uint8_t>& i_edges, const TAD2::VehicleKinematics* i_pVehicle, uint16_t i_otsu_thresh, float32_t i_dummy_angle, image::Image<uint8_t> dynamic_img_1, image::Image<uint8_t> dynamic_img_2, image::Image<uint8_t> dynamic_img_3, image::Image<uint8_t> dynamic_img_4, image::Image<uint8_t>& i_trailerTemplate, uint32_t& hitch_range, bool_t kinematic_ON )
{
    bool_t ret_val = true;

    if( !m_initOK )
    {
        ret_val = false;
    }

    if( ( !m_isRunning ) || ( i_frame == m_lastFrameRun ) )
    {
        ret_val = false;
    }

    if( m_bAngleRangeReached )
    {
        ret_val = false;
    }

    if( ret_val || kinematic_ON )
    {
        // --- Run kinematic models
        m_biasTrailerModel.Run( i_frame, *i_pVehicle, false );
        m_avgTrailerModel.Run( i_frame, *i_pVehicle, false );
        float32_t minCurAngle_deg = mecl::math::abs_x( 90.0f - m_biasTrailerModel.getAngle_deg() );
        float32_t curAngle_deg = mecl::math::abs_x( 90.0f - m_avgTrailerModel.getAngle_deg() );
        bool_t curSideLeft = ( m_avgTrailerModel.getAngle_deg() > 90.0f );

        if( !kinematic_ON )
        {
            // --- Check for change of side
            if( ( curSideLeft != m_bTakingLeftSide ) && ( m_largestAngle_deg <= static_cast <float32_t>( c_largestAngleThresh_deg ) ) )
            {
                ReleaseImages();
                m_angleImgList.clear();
                m_largestAngle_deg = 0.0f;
                m_prevAngleSet_deg = 0.0f;
                m_curAngleDif_deg = 1.0f;
                m_curWaitTime = 0;
                m_bTakingLeftSide = curSideLeft;
            }

            // --- Keep track of current angle step size and save edges every time we reach that step size
            if( ( curSideLeft == m_bTakingLeftSide ) && ( ( curAngle_deg - m_prevAngleSet_deg ) >= m_curAngleDif_deg ) )
            {
                m_prevAngleSet_deg = curAngle_deg;
                ImageNode* curNode = m_angleImgList.next_node();

                if( curNode->getAngleImg().getData() == NULL )
                {
                    curNode->setAngleImage( memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
                }

                curNode->setOtsu_Thresh( i_otsu_thresh );
                curNode->setDummy_Angle( i_dummy_angle );
                image::Image<uint8_t> angImage = curNode->getAngleImg();
                processing::ImageProcessing::Copy( i_edges, angImage );
                curNode->setMinAngle_deg( minCurAngle_deg );
                bool_t increase_gap = m_angleImgList.insert( *curNode );
                m_bTakingLeftSide = ( m_avgTrailerModel.getAngle_deg() > 90.0f );

                if( increase_gap )
                {
                    m_curAngleDif_deg *= 2.0f;
                }
            }

            // --- Track the largest angle
            if( minCurAngle_deg > m_largestAngle_deg )
            {
                m_largestAngle_deg = minCurAngle_deg;
                m_curWaitTime = 0;
            }

            // --- Check if angle range stopped increasing and is large enough
            if( ( curAngle_deg > static_cast <float32_t>( c_largestAngleThresh_deg ) ) && m_angleImgList.is_full() )
            {
                // ++ hitch range finder ++ //
                hitch_range_finder( i_trailerTemplate, dynamic_img_1, dynamic_img_2, dynamic_img_3, dynamic_img_4, hitch_range, i_otsu_thresh );
                // -- hitch range finder -- //
                m_bAngleRangeReached = true;
            }

            m_curWaitTime++;
#ifdef QACPP_TAD_BRAMPTON
            // --- Debugging
            ImageNode* curNode = m_angleImgList.head();
            char panelname[260];

            for( uint32_t i = 0; i < c_numImages; i++ )
            {
                sprintf( panelname, "(HD-1) Angle Image %d", i );

                if( curNode )
                {
                    db::imshow( panelname, curNode->angleImg );
                    db::addViewToWindow( m_debugWindowName1, panelname, i / 3, i % 3 );
                    curNode = curNode->next;
                }
            }

#endif
            m_lastFrameRun = i_frame;
        }
    }

    return;
}
/*
* hitch range finder
*/
void sampling::AngleSampling::hitch_range_finder( image::Image<uint8_t>& i_trailerTemplate, image::Image<uint8_t> dynamic_img_1, image::Image<uint8_t> dynamic_img_2, image::Image<uint8_t> dynamic_img_3, image::Image<uint8_t> dynamic_img_4, uint32_t& hitch_range, uint16_t i_otsu_thresh )
{
    float32_t angle_threshold = mecl::math::abs_x( 90.0 - dummy_angle[0] ) - 1.0;
    float32_t max_thresh = angle_threshold;
    float32_t largest_angle_thresh = static_cast <float32_t>( c_largestAngleThresh_deg ) + 2.0f;

    for( uint32_t i = 0; i < 4; i++ )
    {
        bool_t return_val = false;

        if( mecl::math::abs_x( 90.0f - dummy_angle[i] ) < static_cast <float32_t>( static_cast <float32_t>( c_largestAngleThresh_deg ) - ( static_cast <float32_t>( c_largestAngleThresh_deg ) * 0.20f ) ) )
        {
            float32_t temp_thresh = mecl::math::abs_x( 90.0 - dummy_angle[i] ) - 1.0;

            if( temp_thresh > max_thresh )
            {
                angle_threshold = temp_thresh;
                max_thresh = angle_threshold;
            }
        }
        else if( ceil( mecl::math::abs_x( 90.0f - dummy_angle[i] ) ) < static_cast <float32_t>( static_cast <float32_t>( c_largestAngleThresh_deg ) ) )
        {
            angle_threshold = static_cast <float32_t>( static_cast <float32_t>( c_largestAngleThresh_deg ) - ( static_cast <float32_t>( c_largestAngleThresh_deg ) * 0.20f ) );
            return_val = true;
        }
        else
        {
            angle_threshold = mecl::math::abs_x( 90.0 - dummy_angle[i] ) - 1.0;
            largest_angle_thresh = angle_threshold + 2.0f;
            return_val = true;
        }

        if( return_val )
        {
            break;
        }
    }

    // -- angle threshold
    image::Image<uint8_t> m_calibration_u8 = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
    TAD2::WarpedImage<uint8_t> m_curWarpedCalibrationImg = TAD2::WarpedImage<uint8_t>( memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
    // -- angle threshold
    image::Image<uint8_t> m_curCalibratedTrailerTemplate = image::Image<uint8_t>( global::TEMPLATE_IMAGE_WIDTH, global::TEMPLATE_IMAGE_HEIGHT, NULL, 1 );
    // calculate score for 1st hitch position
    processing::ImageProcessing::Copy( i_trailerTemplate, m_calibration_u8 );
    m_pPreProcessing->WarpImage( m_calibration_u8, m_curWarpedCalibrationImg, Point2i( m_hitch_Xpos, m_hitch_start_pos + ( 1 * ( m_hitch_diff / 5 ) ) ) );
    int32_t xAt90 = m_curWarpedCalibrationImg.Angle2XPos( 90.0f );
    t_m::TemplateMatching::ExtractTemplateShallow( m_curWarpedCalibrationImg, m_curCalibratedTrailerTemplate, xAt90 - m_curCalibratedTrailerTemplate.getWidth() / 2, 0 );
    bool_t section_found = false;
    float32_t dummy_anlge1 = mecl::math::abs_x( 90.0 - dummy_angle[0] );
    float32_t dummy_anlge2 = mecl::math::abs_x( 90.0 - dummy_angle[1] );
    float32_t dummy_anlge3 = mecl::math::abs_x( 90.0 - dummy_angle[2] );
    float32_t dummy_anlge4 = mecl::math::abs_x( 90.0 - dummy_angle[3] );

    while( true )
    {
        bool_t is_ok = true;

        if( ( ( dummy_anlge1 ) >= angle_threshold ) && ( ceil( dummy_anlge1 ) < static_cast<float32_t>( largest_angle_thresh ) ) )
        {
            scores[0][0] = t_m::TemplateMatching::GaussianSimilarityWeighted3x3_4( m_curCalibratedTrailerTemplate, dynamic_img_1, 0, 0, 1.0, i_otsu_thresh );
            section_found = true;
        }

        if( section_found && ( dummy_anlge2 <= ( dummy_anlge1 + 0.25f ) ) )
        {
            is_ok = is_ok && false;
        }

        // calculate score for 2nd hitch position
        processing::ImageProcessing::Copy( i_trailerTemplate, m_calibration_u8 );
        m_pPreProcessing->WarpImage( m_calibration_u8, m_curWarpedCalibrationImg, Point2i( m_hitch_Xpos, m_hitch_start_pos + ( 2 * ( m_hitch_diff / 5 ) ) ) );
        t_m::TemplateMatching::ExtractTemplateShallow( m_curWarpedCalibrationImg, m_curCalibratedTrailerTemplate, xAt90 - m_curCalibratedTrailerTemplate.getWidth() / 2, 0 );

        if( ( ( dummy_anlge2 ) >= angle_threshold ) && ( ceil( dummy_anlge2 ) < static_cast<float32_t>( largest_angle_thresh ) ) && is_ok )
        {
            scores[1][0] = t_m::TemplateMatching::GaussianSimilarityWeighted3x3_4( m_curCalibratedTrailerTemplate, dynamic_img_2, 0, 0, 1.0, i_otsu_thresh );
            section_found = true;
        }

        if( section_found && ( dummy_anlge3 <= ( dummy_anlge2 + 0.25f ) ) )
        {
            is_ok = is_ok && false;
        }

        // calculate score for 3rd hitch position
        processing::ImageProcessing::Copy( i_trailerTemplate, m_calibration_u8 );
        m_pPreProcessing->WarpImage( m_calibration_u8, m_curWarpedCalibrationImg, Point2i( m_hitch_Xpos, m_hitch_start_pos + ( 3 * ( m_hitch_diff / 5 ) ) ) );
        t_m::TemplateMatching::ExtractTemplateShallow( m_curWarpedCalibrationImg, m_curCalibratedTrailerTemplate, xAt90 - m_curCalibratedTrailerTemplate.getWidth() / 2, 0 );

        if( ( ( dummy_anlge3 ) >= angle_threshold ) && ( ceil( dummy_anlge3 ) < static_cast<float32_t>( largest_angle_thresh ) ) && is_ok )
        {
            scores[2][0] = t_m::TemplateMatching::GaussianSimilarityWeighted3x3_4( m_curCalibratedTrailerTemplate, dynamic_img_3, 0, 0, 1.0, i_otsu_thresh );
            section_found = true;
        }

        // calculate score for 4rd hitch position
        processing::ImageProcessing::Copy( i_trailerTemplate, m_calibration_u8 );
        m_pPreProcessing->WarpImage( m_calibration_u8, m_curWarpedCalibrationImg, Point2i( m_hitch_Xpos, m_hitch_start_pos + ( 4 * ( m_hitch_diff / 5 ) ) ) );
        t_m::TemplateMatching::ExtractTemplateShallow( m_curWarpedCalibrationImg, m_curCalibratedTrailerTemplate, xAt90 - m_curCalibratedTrailerTemplate.getWidth() / 2, 0 );

        if( section_found && ( dummy_anlge4 <= ( dummy_anlge3 + 0.25f ) ) )
        {
            is_ok = is_ok && false;
        }

        if( ( ( dummy_anlge4 ) >= angle_threshold ) && ( ceil( dummy_anlge4 ) < static_cast<float32_t>( largest_angle_thresh ) ) && is_ok )
        {
            scores[3][0] = t_m::TemplateMatching::GaussianSimilarityWeighted3x3_4( m_curCalibratedTrailerTemplate, dynamic_img_4, 0, 0, 1.0, i_otsu_thresh );
            section_found = true;
        }

        break;
    }

    // Release image
    float32_t max_score = scores[0][0];
    hitch_range = static_cast <uint32_t>( scores[0][1] );
#if DEBUG_HITCH_POINT
    static bool firstTime = true;

    if( true == firstTime )
    {
        printf( "================TAD Debug Prints=====================\n" );
        printf( "TAD2: Positions: %f, %f, %f, %f\n", scores[0][1], scores[1][1], scores[2][1], scores[3][1] );
        printf( "TAD2: Angles: %f, %f, %f, %f\n", scores[0][0], scores[1][0], scores[2][0], scores[3][0] );
        printf( "TAD2: dummy_angle: %f, %f, %f, %f\n", dummy_anlge1, dummy_anlge2, dummy_anlge3, dummy_anlge4 );
        printf( "TAD2: angle_threshold: %f\n", angle_threshold );
        firstTime = false;
    }

#endif
    hitch_range_pos = 1;
    bool_t max_found = false;

    for( uint8_t i = 0; i < 4; i++ )
    {
        if( max_score < scores[i][0] )
        {
            max_score = scores[i][0];
            hitch_range = static_cast <uint32_t>( scores[i][1] );
            hitch_range_pos = i + 1;
        }

        if( scores[i][0] > 0 )
        {
            max_found = true;
        }

        if( max_found )
        {
            if( scores[i][0] < 0.0001f )
            {
                break;
            }
        }
    }

    memory::MemoryPool::ReleaseImage( m_calibration_u8 );
    memory::MemoryPool::ReleaseImage( m_curWarpedCalibrationImg );
}
/*
* Check if sampling is complete.
*/
uint8_t sampling::AngleSampling::GetHitchPos()  const
{
    return hitch_range_pos;
}
/*
* Check if sampling is complete.
*/
uint32_t sampling::AngleSampling::GetRangeDiff()  const
{
    return static_cast <uint32_t>( scores[2][1] - scores[1][1] );
}
/*
* Check if sampling is complete.
*/
bool_t sampling::AngleSampling::IsComplete() const//m_AngleSamplingDone
{
    return m_bAngleRangeReached;
}

/*
* Return 'true' if the samples were taken while the trailer was on the left side of the
* vehicle.
*/
bool_t sampling::AngleSampling::IsLeftSide() const
{
    return m_bTakingLeftSide;
}

/*
* Will populate the given array with the sampled images, from the image with the trailer
* at its least deviation from the centre (0 degrees or straight) to the image where the
* trailer is at its highest degree.
*
* Once this function is called, it is the responsibility of the caller to deallocate the
* memory taken by the images.
*/
void sampling::AngleSampling::GetSampleImages( image::Image<uint8_t> o_angleImages[c_numImages] )
{
    ImageNode* curNode = m_angleImgList.head();
    uint32_t i = 0;

    while( curNode != NULL )
    {
        thresh[i] = curNode->getOtsu_Thresh();
        Dummy_angle[i] = curNode->getDummy_Angle();
        Dummy_Confidence1[i] = curNode->getDummy_Confidence1();
        Dummy_Confidence2[i] = curNode->getDummy_Confidence2();
        Dummy_Confidence3[i] = curNode->getDummy_Confidence3();
        Dummy_Confidence4[i] = curNode->getDummy_Confidence4();
        o_angleImages[i] = curNode->getAngleImg();  //PRQA S 3706
        i = i + 1;
        image::Image<uint8_t> angleImg = curNode->getAngleImg();
        angleImg.setData( NULL );
        curNode = curNode->getNext();
    }
}

const uint16_t* sampling::AngleSampling::GetThresholdVal()
{
    return reinterpret_cast<uint16_t*>( thresh );
}
const float32_t* sampling::AngleSampling::GetDummyAngle()
{
    return reinterpret_cast<float32_t*>( Dummy_angle );
}
const float32_t* sampling::AngleSampling::GetDummyConfidence1()
{
    return reinterpret_cast<float32_t*>( Dummy_Confidence1 );
}
const float32_t* sampling::AngleSampling::GetDummyConfidence2()
{
    return reinterpret_cast<float32_t*>( Dummy_Confidence2 );
}
const float32_t* sampling::AngleSampling::GetDummyConfidence3()
{
    return reinterpret_cast<float32_t*>( Dummy_Confidence3 );
}
const float32_t* sampling::AngleSampling::GetDummyConfidence4()
{
    return reinterpret_cast<float32_t*>( Dummy_Confidence4 );
}
/*
* Sets the dummy angles for dynamic mask
*/
void sampling::AngleSampling::Set_Dummy_angles( float32_t angle_1, float32_t angle_2, float32_t angle_3, float32_t angle_4 )
{
    dummy_angle[0] = angle_1;
    dummy_angle[1] = angle_2;
    dummy_angle[2] = angle_3;
    dummy_angle[3] = angle_4;
}
/*
* Return the angle of the kinematic model used to determine if the angle of the actual trailer
* is increasing or decreasing.
*/
float32_t sampling::AngleSampling::GetCalibrationAngle() const
{
    return m_biasTrailerModel.getAngle_deg();
}

/*
* Release all images held in the linked list.
*/
void sampling::AngleSampling::ReleaseImages()
{
    ImageNode* curNode = m_angleImgList.head();

    while( curNode != NULL )
    {
        if( curNode->getAngleImg().getData() != NULL )
        {
            image::Image<uint8_t> angImage = curNode->getAngleImg();
            memory::MemoryPool::ReleaseImage( angImage );
        }

        image::Image<uint8_t> angleImg = curNode->getAngleImg();
        angleImg.setData( NULL );
        curNode = curNode->getNext();
    }
}
