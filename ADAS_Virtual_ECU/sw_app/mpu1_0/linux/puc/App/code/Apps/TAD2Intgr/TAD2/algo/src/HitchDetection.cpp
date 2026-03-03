// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Jun-2019]
// --- Last Modified by Joshua Teichroeb [06-Jun-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "HitchDetection.h"
#include "TemplateMatching.h"
#include "PreProcessing.h"
#include "WarpLUT.h"

#ifdef __QNX__
    #include "mecl/math/Math.h"
#else
    #include "MECL/math/math.h"
#endif

#ifdef DIAGNOSTICS
    #include "global.h"
    #include "common/db.h"
    #include "fo.h"
#endif
namespace Hitch
{
    /*
    * Constructor.
    */
    HitchDetection::HitchDetection() :
        m_initOK( false ),
        m_isRunning( false ),
        m_lastFrameRun( 0 )
    {
        c_minHitchY = 15;
        c_maxHitchY = 70;
        half_hitch_range = 8;
    }

    /*
    * Destructor.
    */
    HitchDetection::~HitchDetection()
    {
    }

    /*
    * Initialize this module.
    *
    * Called once at the beginning of the program, before any other functions.
    */
    bool_t HitchDetection::Init( tad2config::HitchDetectionConfigData i_config, const TAD2::PreProcessing* i_pPreProcessing, uint32_t hitch_X_Pos, const uint32_t i_hitchYRange[2] )
    {
        bool_t ret_val = true;
        c_minHitchY = i_hitchYRange[0]; //PRQA S 3706
        c_maxHitchY = i_hitchYRange[1]; //PRQA S 3706
        m_pPreProcessing = i_pPreProcessing;

        if( ( c_maxHitchY > c_maxHitchYRange ) || ( c_minHitchY > c_maxHitchY ) )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            uint32_t m_dummyangle_hitchPoint = static_cast <uint32_t>( ( c_minHitchY + c_maxHitchY ) / 2 );
            half_hitch_range = m_dummyangle_hitchPoint - ( c_minHitchY + ( ( m_dummyangle_hitchPoint - c_minHitchY ) / 2 ) );

            if( hitch_X_Pos > global::TOPVIEW_IMAGE_WIDTH )
            {
                ret_val = false;
            }

            if( ret_val )
            {
                m_calibratedHitchPoint = Point2i( hitch_X_Pos, c_minHitchY ); //PRQA S 3706
                m_hitchXPos = hitch_X_Pos;
                //
                m_isDebugging = true;
                m_initOK = true;
                ret_val = true;
            }
        }

        return ret_val;
    }

    /*
    * Signifies the beginning of a period of execution. Allocates any necessary
    * memory and sets any input parameters needed at runtime.
    */
    bool_t HitchDetection::Start( image::Image<uint8_t>& i_trailerCalibration, const image::Image<uint8_t> i_angleImages[sampling::AngleSampling::c_numImages], bool_t i_leftSide, const uint16_t thresh[sampling::AngleSampling::c_numImages], const float32_t dummy_angle[sampling::AngleSampling::c_numImages], uint32_t i_hitch_range, uint32_t hitch_range_diff, uint8_t hitchrange_pos )
    {
        bool_t ret_val = true;

        if( !m_initOK )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            if( m_isRunning )
            {
                Finish();
            }

            // --- Get inputs
            m_hitchrangefound = false;
            m_hitchCalibrated = false;
            m_bLeftSide = i_leftSide;
            m_calibratedHitchPoint = Point2i( m_calibratedHitchPoint.x, 0 );
            m_calibration_u8 = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
            processing::ImageProcessing::Copy( i_trailerCalibration, m_calibration_u8 );
            _roi::ROI hitch_roi = _roi::ROI( i_angleImages[0].getWidth() / 2 - 10, c_minHitchY, 20, c_maxHitchY - c_minHitchY ); //PRQA S 3706
            c_minHitchY = i_hitch_range - ( hitch_range_diff / 3 );
            c_maxHitchY = i_hitch_range + ( hitch_range_diff - ( hitch_range_diff / 4 ) );
            hitch_range_pos = hitchrange_pos;

            for( uint32_t i = 0; i < c_numImages; i++ )
            {
                if( i_angleImages[i].getData() == NULL ) //PRQA S 3706
                {
                    ret_val = false;
                }

                if( ret_val )
                {
                    otsu_thresh[i] = thresh[i];             //PRQA S 3706
                    m_angleImages[i] = i_angleImages[i];    //PRQA S 3706
                    Dummy_angle[i] = dummy_angle[i];        //PRQA S 3706
                    //
                }
            }

            if( ret_val )
            {
                // --- Initialize variables/images
                m_curX = 0;
                m_curY = c_minHitchY;
                m_curImgInd = 3;
                m_curBestX = 0;
                m_curBestScore = 0.0f;
                m_curWarpedCalibrationImg = TAD2::WarpedImage<uint8_t>( memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
                m_curWarpedAngleImg = TAD2::WarpedImage<uint8_t>( memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
                m_curCalibratedTrailerTemplate = image::Image<uint8_t>( c_templateWidth, c_templateHeight, NULL, 1 );
                memset( &m_matchingScores[0], 0, ( sizeof( m_matchingScores[0] ) ) * c_maxHitchYRange );
                memset( &m_angleScores[0], 0, ( sizeof( m_angleScores[0] ) )  * c_maxHitchYRange );
                memset( &m_hitchscores[0], 0, ( sizeof( m_hitchscores[0] ) ) * c_maxHitchYRange );
                memset( &m_matchinghitchrangescores[0], 0, ( sizeof( m_matchinghitchrangescores[0][0] ) ) * c_numImages * c_maxHitchYRange );
                memset( &m_matchingScores2[0][0], 0, ( sizeof( m_matchingScores2[0][0] ) ) * c_numImages * c_maxHitchYRange );
                memset( &m_angleScores2[0][0], 0, ( sizeof( m_angleScores2[0][0] ) ) * c_numImages * c_maxHitchYRange );
                //
                m_pPreProcessing->WarpImage( m_calibration_u8, m_curWarpedCalibrationImg, Point2i( m_hitchXPos, m_curY ) );
                int32_t xAt90 = m_curWarpedCalibrationImg.Angle2XPos( 90.0f );
                t_m::TemplateMatching::ExtractTemplateShallow( m_curWarpedCalibrationImg, m_curCalibratedTrailerTemplate, xAt90 - m_curCalibratedTrailerTemplate.getWidth() / 2, 0 );
                m_pPreProcessing->WarpImage( m_angleImages[m_curImgInd], m_curWarpedAngleImg, Point2i( m_hitchXPos, m_curY ) );
                current_othsuthresh = otsu_thresh[m_curImgInd];
                //
#ifdef DIAGNOSTICS
                // --- Debugging
                db::createWindow( m_debugWindowName1, global::TOPVIEW_IMAGE_WIDTH * 3, global::WARPED_TOPVIEW_IMAGE_HEIGHT * 3 );
                db::createWindow( m_debugWindowName2, global::TEMPLATE_IMAGE_WIDTH * 3, global::TEMPLATE_IMAGE_HEIGHT * 3 );
                db::createWindow( m_debugWindowName3, 640 * 3, 400 * 3 );
                char panelname[c_debugPanelNameLength];

                for( uint32_t i = 0; i < c_numImages; i++ )
                {
                    sprintf( panelname, "(HD-3) Warped Angle Image %d", i );
                    db::createView( panelname, global::TOPVIEW_IMAGE_WIDTH, global::WARPED_TOPVIEW_IMAGE_HEIGHT );
                    db::addViewToWindow( m_debugWindowName1, panelname, i / 3, i % 3 );
                    sprintf( panelname, "(HD-3) Template Matching %d", i );
                    db::createView( panelname, global::TEMPLATE_IMAGE_WIDTH, global::TEMPLATE_IMAGE_HEIGHT );
                    db::addViewToWindow( m_debugWindowName2, panelname, i / 3, i % 3 );
                    sprintf( panelname, "(HD-3) Scanning Scores %d", i );
                    db::createView( panelname, global::TEMPLATE_IMAGE_WIDTH, global::TEMPLATE_IMAGE_HEIGHT );
                    db::addViewToWindow( m_debugWindowName3, panelname, i / 3, i % 3 );
                }

#endif
                m_lastFrameRun = 0;
                m_isRunning = true;
                ret_val = true;
            }
        }

        return ret_val;
    }

    /*
    * Signifies the end of a period of execution. Deallocates any memory used.
    */
    void HitchDetection::Finish()
    {
        memory::MemoryPool::ReleaseImage( m_calibration_u8 );
        memory::MemoryPool::ReleaseImage( m_curWarpedCalibrationImg );
        memory::MemoryPool::ReleaseImage( m_curWarpedAngleImg );
        current_othsuthresh = 0;

        for( uint32_t i = 0; i < c_numImages; i++ )
        {
            otsu_thresh[i] = 0;
            memory::MemoryPool::ReleaseImage( m_angleImages[i] );
        }

        m_isRunning = false;
    }

    /*
    * Run this module.
    *
    * Will only run if called between a call to Start() and a call to Finish(), respectively.
    * Records the given frame so as to not run the same frame multiple times.
    */
    void HitchDetection::Run( uint32_t i_frame )
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

        if( m_hitchCalibrated )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            float32_t score;
            uint32_t angle_x;
            m_curX = 0;
            uint32_t end_x = 320;
            uint32_t half_width = m_curWarpedAngleImg.getWidth() / 2;

            if( end_x > half_width )
            {
                end_x = half_width;
            }

            for( uint32_t i = m_curImgInd; i < c_numImages; i++ )
            {
                int32_t xAt95 = m_curWarpedCalibrationImg.Angle2XPos( Dummy_angle[i] );
                //cv::Mat img = processing::ImageProcessing::ConvertToCV( m_curWarpedAngleImg );

                // --- Scan
                if( m_bLeftSide )
                {
                    angle_x = ScanImage( m_curWarpedAngleImg, m_curCalibratedTrailerTemplate, xAt95 - 100, xAt95 + 100, &score, 0 );
                }
                else
                {
                    angle_x = ScanImage( m_curWarpedAngleImg, m_curCalibratedTrailerTemplate, xAt95 - 100, xAt95 + 100, &score, 0 );
                }

#ifdef DIAGNOSTICS

                // --- Debugging
                if( m_isDebugging )
                {
                    char panelname[c_debugPanelNameLength];
                    sprintf( panelname, "(HD-3) Warped Angle Image %d", m_curImgInd );
                    db::imshow( panelname, m_curWarpedAngleImg );
                    db::line( panelname, Point2i( m_curBestX, 0 ), Point2i( m_curBestX, m_curWarpedAngleImg.getStep() ), db::Colour( 255, 0, 0 ), 1 );
                    image::Image<uint8_t> found_template = image::Image<uint8_t>( global::TEMPLATE_IMAGE_WIDTH, global::TEMPLATE_IMAGE_HEIGHT, NULL, 1 );
                    t_m::TemplateMatching::ExtractTemplateShallow( m_curWarpedAngleImg, found_template, angle_x - found_template.getWidth() / 2, 0 );
                    sprintf( panelname, "(HD-3) Template Matching %d", m_curImgInd );
                    db::imshow_templateOverlap( panelname, m_curCalibratedTrailerTemplate, found_template, 1.0f );
                }

#endif
                // --- Update scores
                float32_t w = static_cast <float32_t>( m_curImgInd + 1 );
                m_matchingScores[m_curY] += w * score;
                m_angleScores[m_curY] += mecl::math::abs_x( 90.0f - m_curWarpedAngleImg.XPos2Angle( static_cast <float32_t>( angle_x ) ) );
                m_matchingScores2[m_curY][m_curImgInd] = score;
                m_angleScores2[m_curY][m_curImgInd] = mecl::math::abs_x( 90.0f - m_curWarpedAngleImg.XPos2Angle( static_cast <float32_t>( angle_x ) ) );
                //
                // --- Update variables
                m_curImgInd++;

                // --- Check for Y score completion
                if( m_curImgInd == c_numImages )
                {
                    break;
                }

                // --- Warp next image
                m_pPreProcessing->WarpImage( m_angleImages[m_curImgInd], m_curWarpedAngleImg, Point2i( m_hitchXPos, m_curY ) );
                current_othsuthresh = otsu_thresh[m_curImgInd];
            }

#ifdef DIAGNOSTICS

            // --- Debugging
            if( m_isDebugging )
            {
                db::run();
            }

#endif
            // --- Update variables
            m_curY++;
            m_curX = 0;
            m_curImgInd = 3;

            // --- Check for hitch detection completion
            if( m_curY > c_maxHitchY )
            {
                m_hitchCalibrated = true;
            }

            // --- Warp calibration image to this Y position
            m_pPreProcessing->WarpImage( m_calibration_u8, m_curWarpedCalibrationImg, Point2i( m_hitchXPos, m_curY ) );
            //
            // --- Get calibrated template for this Y
            int32_t xAt90 = m_curWarpedCalibrationImg.Angle2XPos( 90.0f );
            t_m::TemplateMatching::ExtractTemplateShallow( m_curWarpedCalibrationImg, m_curCalibratedTrailerTemplate, xAt90 - m_curCalibratedTrailerTemplate.getWidth() / 2, 0 );
            // --- Warp next image
            m_pPreProcessing->WarpImage( m_angleImages[m_curImgInd], m_curWarpedAngleImg, Point2i( m_hitchXPos, m_curY ) );
            current_othsuthresh = otsu_thresh[m_curImgInd];
        }

        // --- Check if finished
        if( m_hitchCalibrated )
        {
            CalculateBestHitchPoint();
        }

        m_lastFrameRun = i_frame;
    }

    /*
    * Get the calculated hitchpoint. Will be set to the lowest valid value until the
    * hitchpoint is actually found.
    */
    Point2i HitchDetection::GetHitchPoint()const
    {
        return m_calibratedHitchPoint;
    }

    /*
    * Get the centre point of the possible range of values considered to be the htichpoint.
    */
    Point2i HitchDetection::GetROICentrePoint()const
    {
        return Point2i( m_hitchXPos, ( c_minHitchY + c_maxHitchY ) / 2 );
    }
    /*
    * Return whether or not the hitch range calculation is complete.
    */
    bool_t HitchDetection::IsHitchRangeFound()const
    {
        return m_hitchrangefound;
    }
    /*
    * Return whether or not the hitchpoint calculation is complete.
    */
    bool_t HitchDetection::IsHitchPointFound()const
    {
        return m_hitchCalibrated;
    }
    /*
    * sets hitch point
    */
    void HitchDetection::SethitchPoint( Point2i hitchDetected )
    {
        m_calibratedHitchPoint = hitchDetected;
    }
    /*
    * Perform the actual calculation of the hitchpoint, based on the accumulated scores.
    */
    void HitchDetection::CalculateBestHitchPoint()
    {
        float32_t best_score = 0.0f;
        uint32_t best_y = c_minHitchY;

        for( uint32_t y = c_minHitchY; y < c_maxHitchY; y++ )
        {
            if( m_matchingScores[y] > best_score )
            {
                best_score = m_matchingScores[y];
                best_y = y;
            }
        }

#ifdef DIAGNOSTICS

        // --- Debugging
        if( m_isDebugging )
        {
            db::Range<float32_t, 400> xArr = db::Range<float32_t, 400>( ( float32_t )c_minHitchY, ( float32_t )c_maxHitchY );
            db::plot( "(HD-3) Y Scores", xArr.ptr(), &m_matchingScores[c_minHitchY], c_maxHitchY - c_minHitchY, db::Colour( 0, 0, 0 ) );
            OutputScoresToFile();
        }

#endif
        m_calibratedHitchPoint.y = best_y;
    }
    /*
    * Scan the given warped image for the given template, returning the column in the
    * warped image which gave the highest template matching score.
    */
    uint32_t HitchDetection::ScanImage( image::Image<uint8_t>& i_warpedImage, image::Image<uint8_t>& i_template, uint32_t i_start_x, uint32_t i_end_x, float32_t* o_score, uint16_t othsuthresh )
    {
        float32_t max_score = 0.0f;
        uint32_t best_x = 0;
#ifdef DIAGNOSTICS
        float32_t scores[global::TOPVIEW_IMAGE_WIDTH] = { 0.0f };
#endif
        //
        uint8_t data[global::TEMPLATE_IMAGE_SIZE];
        image::Image<uint8_t> roiImage = image::Image<uint8_t>( i_template.getWidth(), i_template.getHeight(), &data[0], 1, i_template.getWidth() );
        image::Image<uint8_t> roi;

        for( uint32_t x = i_start_x; x < i_end_x; x += 2 )
        {
            // --- V1
            float32_t score = t_m::TemplateMatching::GaussianSimilarityWeighted3x3_4( i_template, i_warpedImage, x - static_cast <int32_t>( i_template.getWidth() ) / 2, 0, 1.0, othsuthresh );
#ifdef DIAGNOSTICS
            scores[x] = score;
#endif

            if( score > max_score )
            {
                max_score = score;
                best_x = x;
            }
        }

        if( o_score != NULL )
        {
            *o_score = max_score;
        }

#ifdef DIAGNOSTICS

        // --- Debugging
        if( m_isDebugging )
        {
            static uint32_t prev_plot_ind = m_curImgInd;
            static uint32_t colour_ind = 0;
            char plotname[c_debugPanelNameLength];
            sprintf( plotname, "(HD-3) Scanning Scores %d", m_curImgInd );

            if( prev_plot_ind != m_curImgInd )
            {
                db::clearPlot( plotname );
                prev_plot_ind = m_curImgInd;
                colour_ind = 0;
            }

            db::Range<float32_t, 640> xArr = db::Range<float32_t, 640>( ( float32_t )i_start_x, ( float32_t )i_end_x );
            db::setPlotYLim( plotname, -0.1f, 1.3f );
            db::setPlotXLim( plotname, 0.0f, 640.0f );
            db::plot( plotname, xArr.ptr(), &scores[i_start_x], i_end_x - i_start_x, db::Colour( colour_ind, colour_ind, colour_ind ) );
            colour_ind++;
        }

#endif
        return best_x;
    }

    /*
    * Create an image which stores, at each pixel, the distance from that pixel to the
    * nearest edge in that row of the given image. Assumes that the pixels just outside
    * the border are edges.
    *
    * Not currently used.
    */
    void HitchDetection::CreateDistImage( image::Image<uint8_t>& i_image, image::Image<uint32_t>& o_distImage )
    {
        uint32_t w = i_image.getWidth();
        uint32_t h = i_image.getHeight();
        uint32_t cur_dist;

        // --- Set distance to nearest edge on left side
        for( uint32_t y = 0; y < h; y++ )
        {
            cur_dist = 0;

            for( uint32_t x = 0; x < w; x++ )
            {
                if( *i_image.at( x, y ) > 0 )
                {
                    cur_dist = 0;
                }

                *o_distImage.at( x, y ) = cur_dist;
                cur_dist++;
            }
        }

#ifdef DIAGNOSTICS
        db::imshow( "(HD-3) Left Dist Image", o_distImage, db::ImShow_Grey, 0U, 0U );
#endif

        // --- Set distance to min of nearest edge on left and right side
        for( uint32_t y = 0; y < h; y++ )
        {
            cur_dist = 0;

            for( int32_t x = w - 1; x >= 0; x-- )
            {
                if( *i_image.at( x, y ) > 0 )
                {
                    cur_dist = 0;
                }

                uint32_t distImage_u8 = *o_distImage.at( x, y );
                *o_distImage.at( x, y ) = mecl::math::min_x( distImage_u8, cur_dist );
                cur_dist++;
            }
        }
    }

    /*
    * Scan the given warped image for the given template, using an image created by
    * 'CreateDistImage()' to calculate the best match.
    *
    * Assumes template is at y = 0 and has same height as distance image.
    *
    * Not currently used.
    */
    uint32_t HitchDetection::ScanUsingDistImage( image::Image<uint32_t>& i_distImage, image::Image<uint8_t>& i_template, uint32_t i_start_x, uint32_t i_end_x, float32_t* o_score )
    {
        int32_t w = static_cast <int32_t>( i_distImage.getWidth() );
        int32_t tw = static_cast <int32_t>( i_template.getWidth() );
        int32_t th = static_cast <int32_t>( i_template.getHeight() );
        float32_t min_score = -1.0f;
        uint32_t best_x = 0;
#ifdef DIAGNOSTICS
        float32_t scores[global::TOPVIEW_IMAGE_WIDTH] = { 0 };
#endif

        for( uint32_t x = i_start_x; x < i_end_x; x++ )
        {
            uint32_t total_dist = 0;
            uint32_t tmp_count = 0;

            for( int32_t j = 0; j < th; j++ )
            {
                for( int32_t i = 0; i < tw; i++ )
                {
                    if( *i_template.at( i, j ) > 0 )
                    {
                        int32_t ind_x = x - tw / 2 + i;

                        if( ( 0 <= ind_x ) && ( ind_x < w ) )
                        {
                            tmp_count++;
                            total_dist += *i_distImage.at( ind_x, j );
                        }
                    }
                }
            }

            float32_t score = static_cast <float32_t>( static_cast <float64_t>( total_dist ) / static_cast <float64_t>( tmp_count ) );
#ifdef DIAGNOSTICS
            scores[x] = score;
#endif

            if( ( score < min_score ) || ( min_score < 0.0f ) )
            {
                min_score = score;
                best_x = x;
            }
        }

        if( o_score != NULL )
        {
            *o_score = min_score;
        }

#ifdef DIAGNOSTICS
        char plotname[c_debugPanelNameLength];
        sprintf( plotname, "(HD-3) Scanning Scores %d", m_curImgInd );
        db::Range<float32_t, global::TOPVIEW_IMAGE_WIDTH> xArr = db::Range<float32_t, global::TOPVIEW_IMAGE_WIDTH>( 0, global::TOPVIEW_IMAGE_WIDTH );
        db::clearPlot( plotname );
        db::plot( plotname, xArr.ptr(), &scores[0], global::TOPVIEW_IMAGE_WIDTH, db::Colour( 0, 0, 0 ) );
#endif
        //
        return best_x;
    }
    /*
    * Output all scores to a file.
    */
    void HitchDetection::OutputScoresToFile()
    {
#ifdef DIAGNOSTICS
        /*char filename1[560];
        char filename2[560];
        sprintf( &filename1[0], "TAD\\HDScores\\Matching\\%s.csv", global::getVidName() );
        sprintf( &filename2[0], "TAD\\HDScores\\Angles\\%s.csv", global::getVidName() );
        fo::filestream file1 = fo::getFileStream( filename1 );
        fo::filestream file2 = fo::getFileStream( filename2 );

        for( uint32_t y = c_minHitchY; y < c_maxHitchY; y++ )
        {
            file1 << y << ',';
            file2 << y << ',';

            for( int32_t i = 0; i < c_numImages; i++ )
            {
                file1 << m_matchingScores2[y][i] << ',';
                file2 << m_angleScores2[y][i] << ',';
            }

            file1 << '\n';
            file2 << '\n';
        }

        file1.close();
        file2.close();*/
#endif
    }

}
