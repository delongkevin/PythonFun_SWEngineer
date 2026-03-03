// ----------------------------------------------------------------------------
// --- Written by Pune Team
// --- Last Modified by Joshua Teichroeb [08-Jul-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "TrailerPresenceDetection.h"
#include "TADStructures.h"
#include "TemplateMatching.h"
#include "PreProcessing.h"
#include "VehicleKinematics.h"
#include "ImageThresholding.h"
#include "FeatureExtraction.h"
#include "EdgeDetector.h"
#include "OpticalFlow.h"

namespace TrailerPresence
{
    /*
    * Constructor.
    */
    TrailerPresenceDetection::TrailerPresenceDetection( TAD2::PreProcessing* i_preProcessing, TAD2::VehicleKinematics* i_kinematic ) :
        m_pPreProcessing( i_preProcessing ),
        m_pVehicle( i_kinematic ),
        m_initOK( false ),
        m_isRunning( false ),
        m_lastFrameRun( 0 )
    {
    }

    /*
    * Destructor.
    */
    TrailerPresenceDetection::~TrailerPresenceDetection()
    {
    }

    /*
    * Initialize this module.
    *
    * Called once at the beginning of the program, before any other functions.
    */
    bool_t TrailerPresenceDetection::Init( tad2config::TrailerPresenceDetectionConfigData i_config, const TAD2::WarpedTopViewParameters i_warpedTopViewParams_st )
    {
        Point_Y = i_config.getthresholdpoints();
        Point_X = ( global::TOPVIEW_IMAGE_WIDTH - ( 84 * 3 ) ) / 2;
        warpedTopViewParams_st = i_warpedTopViewParams_st;
        m_initOK = true;
        m_isRunning = false;
        return true;
    }

    /*
    * Signifies the beginning of a period of execution. Allocates any necessary
    * memory and sets any input parameters needed at runtime.
    */
    bool_t TrailerPresenceDetection::Start()
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

            m_InitialDistanceTravelled = 0.0f;
            m_InitialPointsDetected = false;
            b_DetectionDone = false;
            b_trailerPresent = false;
            m_lastFrameRun = 0;
            m_isRunning = true;
            ret_val = true;
            prev_gray_img = TAD2::WarpedImage<uint8_t>( warpedTopViewParams_st, memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        }

        m_opt.Init();
        m_opt.Start();
        return ret_val;
    }

    /*
    * Signifies the end of a period of execution. Deallocates any memory used.
    */
    void TrailerPresenceDetection::Finish()
    {
        memory::MemoryPool::ReleaseImage( prev_gray_img );
        m_isRunning = false;
    }

    /*
    * Run this module.
    *
    * Will only run if called between a call to Start() and a call to Finish(), respectively.
    * Records the given frame so as to not run the same frame multiple times.
    */
    void TrailerPresenceDetection::Run( uint32_t i_frame, image::Image<uint8_t>& i_topView, Point2i hitch_point, _roi::ROI& i_roi )
    {
        bool_t ret_val = true;
        m_isRunning = true;

        if( ( !m_initOK ) || ( i_frame == m_lastFrameRun ) )
        {
            ret_val = false;
        }

        if( ( i_frame - 1 ) != m_lastFrameRun )
        {
            m_InitialPointsDetected = false;
        }

        if( ret_val )
        {
            // --- Warp edges
            Point2i hitchPoint;
            TAD2::WarpedImage<uint8_t> warpedEdges1 = TAD2::WarpedImage<uint8_t>( warpedTopViewParams_st, memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
            hitchPoint.x = hitch_point.x;
            hitchPoint.y = hitch_point.y;
            // -- warping the image
            m_pPreProcessing->WarpImage( i_topView, warpedEdges1, hitchPoint );

            if( !m_InitialPointsDetected )
            {
                FeaturePointDetection( warpedEdges1, i_roi );
            }
            else
            {
                if( features_prev_size > 10 )
                {
                    FeaturePointTracking( warpedEdges1, i_roi );
                }
                else
                {
                    b_trailerPresent = false;
                    b_DetectionDone = true;
                }
            }

            memory::MemoryPool::ReleaseImage( warpedEdges1 );
            m_lastFrameRun = i_frame;
        }

        return;
    }
    /*
    * Return whether or not the trailer is present. Valid only after detection is complete.
    */
    bool_t TrailerPresenceDetection::IsTrailerPresent() const
    {
        return b_trailerPresent;
    }
    /*
    * Return whether or not the detection is complete.
    */
    bool_t TrailerPresenceDetection::IsComplete() const
    {
        return b_DetectionDone;
    }
    /*
    * Run Absence Presence Algo
    */
    bool_t TrailerPresenceDetection::FeaturePointTracking( image::Image<uint8_t> i_image, _roi::ROI& i_roi )
    {
        //cv::Mat curr_gray = processing::ImageProcessing::ConvertToCV( i_image );
        //cv::calcOpticalFlowPyrLK( prev_gray, curr_gray, features_prev, features_next, status, err );
        //lkopticalFlowCalc( prev_gray, curr_gray, features_prev, features_next, status, err );
        m_opt.Run( prev_gray_img, i_image, features_prev, features_next, features_prev_size, status, err );
        //lkopticalFlowCalc( prev_gray_img, i_image, features_prev.data(), features_next, features_prev.size(), status, err );
        memcpy( prev_gray_img.getData(), i_image.getData(), 150 * 640 );
        //
        Point2f good_new[NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID];
        uint32_t good_new_size = 0;

        for( uint32_t i = 0; i < features_prev_size; i++ )
        {
            float32_t Distance = mecl::math::abs_x( features_next[i].x - features_prev[i].x );
            // Select good points
            if( ( status[i] == 1 ) && ( Distance < 3.0f ) )
            {
                good_new[good_new_size] =  features_next[i] ;
                good_new_size = good_new_size + 1;
            }
        }

        /*for( uint i = 0; i < good_new_size; i++ )
        {
            cv::circle( curr_gray, cv::Point2f( good_new[i].x, good_new[i].y ), 2, cv::Scalar( 255, 0, 0 ), -1, 8, 0 );
        }*/
        features_prev_size = 0;
        memset( PointValid, 1, sizeof( PointValid ) );

        for( uint32_t i = 0; i < good_new_size; i++ )
        {
            PointValid[features_prev_size] = false;
            features_prev[features_prev_size] = good_new[i];
            features_prev_size = features_prev_size + 1;
        }

        /*cv::imshow( "image", curr_gray );
        cv::waitKey( 1 );*/
        m_InitialDistanceTravelled += m_pVehicle->distanceTravelled_m();

        if( m_InitialDistanceTravelled > 3.0f )
        {
            ClusterFiltering();
            uint32_t MaxGap = FindGap();

            if( ( features_prev_size > 20 ) && ( MaxGap < 30 ) ) // check if there is gap between points to classify GN and conventional trailer
            {
                b_trailerPresent = true;
            }
            else
            {
                b_trailerPresent = false;
            }

            b_DetectionDone = true;
        }

        return true;
    }
    void TrailerPresenceDetection::ClusterFiltering()
    {
        Point2f clustertemp[NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID];
        uint32_t clusterInd[NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID];
        memset( clustertemp, 0, sizeof( clustertemp ) );
        memset( clusterInd, 0, sizeof( clusterInd ) );
        uint32_t i = 0;

        while( true )
        {
            uint32_t TempPoints = 0;
            bool_t initialPointAdded = false;
            bool_t PointsRemoved = false;

            if( !PointValid[i] )
            {
                if( !initialPointAdded )
                {
                    PointValid[i] = true;
                    clustertemp[TempPoints] = features_prev[i];
                    clusterInd[TempPoints] = i;
                    TempPoints++;
                }

                for( uint32_t ii = 0; ii < TempPoints; ii++ )
                {
                    for( uint32_t j = 0; j < features_prev_size; j++ )
                    {
                        float32_t dist = EuclideanDistance( clustertemp[ii], features_prev[j] );

                        if( ( dist < 15.0f ) && ( dist > 0.1f ) && !PointValid[j] )
                        {
                            PointValid[j] = true;
                            clusterInd[TempPoints] = j;
                            clustertemp[TempPoints] = features_prev[j];
                            TempPoints++;
                        }
                    }
                }

                // reorder the index
                uint32_t clusterReorderedInd[NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID];
                memset( clusterReorderedInd, 0, sizeof( clusterReorderedInd ) );

                // Sorting elements in ascending order
                for( uint32_t ii = 0; ii < ( TempPoints - 1 ) ; ii++ )
                {
                    for( uint32_t jj = ii; jj < ( TempPoints - 1 ); jj++ )
                    {
                        if( clusterInd[ii] > clusterInd[jj + 1] )
                        {
                            uint32_t temp = clusterInd[ii];
                            clusterInd[ii] = clusterInd[jj + 1];
                            clusterInd[jj + 1] = temp;
                        }
                    }
                }

                // Removing small cluster
                if( TempPoints < 5 )
                {
                    for( uint32_t ii = 0; ii < TempPoints; ii++ )
                    {
                        for( uint32_t jj = clusterInd[ii]; jj < NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID - 1; jj++ )
                        {
                            PointValid[jj - ii] = PointValid[jj + 1 - ii];
                            features_prev[jj - ii] = features_prev[jj + 1 - ii];
                        }

                        features_prev_size--;
                    }

                    PointsRemoved = true;
                    i = 0;
                }
            }

            memset( clustertemp, 0, sizeof( clustertemp ) );
            memset( clusterInd, 0, sizeof( clusterInd ) );

            if( i >= features_prev_size )
            {
                break;
            }
            else if( !PointsRemoved )
            {
                i++;
            }
        }
    }
    float32_t TrailerPresenceDetection::EuclideanDistance( Point2f P1, Point2f P2 )
    {
        float32_t dist = mecl::math::algebra<float32_t>::sqrt_x( ( P1.x - P2.x ) * ( P1.x - P2.x ) + ( P1.y - P2.y ) * ( P1.y - P2.y ) );
        return dist;
    }
    /*
    * Run Absence Presence Algo
    */
    bool_t TrailerPresenceDetection::FeaturePointDetection( image::Image<uint8_t> i_image, _roi::ROI& i_roi )
    {
        bool_t TrailerPresent = false;
        // HOG
        image::Image<uint16_t> gradMag = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
        image::Image<uint8_t> gradDir = TAD2::WarpedImage<uint8_t>( warpedTopViewParams_st, memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        image::Image<uint16_t> gradMag_crop = gradMag.subImage( i_roi );
        image::Image<uint8_t> gradDir_crop = gradDir.subImage( i_roi );
        // Gradient and Orientation Extraction
        GradientOrientationDetection( i_image, gradMag_crop, gradDir_crop );
        uint32_t mag_avg_val = find_mag_avg_img( gradMag_crop );
        //cv::Mat orient = processing::ImageProcessing::ConvertToCV( gradDir_crop );
        // Binning
        uint32_t CELL_SIZE = 16;
        uint32_t WINDOW_SIZE = 8;
        uint32_t startPos = 150;
        //cv::Mat input_img1 = processing::ImageProcessing::ConvertToCV( i_image );
        //prev_gray_img = i_image;
        memcpy( prev_gray_img.getData(), i_image.getData(), 150 * 640 );
        // cell cropping
        features_prev_size = 0;

        for( uint32_t y = 5; y < ( i_image.getHeight() - ( CELL_SIZE + 10 ) ); y = ( y + CELL_SIZE ) )
        {
            for( uint32_t x = startPos; x < ( i_image.getWidth() - ( CELL_SIZE + startPos ) ); x = ( x + CELL_SIZE ) )
            {
                _roi::ROI i_roi = _roi::ROI( x, y, CELL_SIZE, CELL_SIZE );
                // --- CELL ROI Extraction
                image::Image<uint8_t> gradDirROI = gradDir_crop.subImage( i_roi );
                image::Image<uint16_t> graMagROI = gradMag_crop.subImage( i_roi );
                //cv::Mat orient1 = processing::ImageProcessing::ConvertToCV( gradDirROI );
                // finding average pixel
                image::Image<uint8_t> Cropimg = i_image.subImage( i_roi );

                // window cropping
                for( uint32_t yy = 0; yy < gradDirROI.getHeight(); yy = ( yy + WINDOW_SIZE ) )
                {
                    for( uint32_t xx = 0; xx < gradDirROI.getWidth(); xx = ( xx + WINDOW_SIZE ) )
                    {
                        _roi::ROI i_roi1 = _roi::ROI( xx, yy, WINDOW_SIZE, WINDOW_SIZE );
                        // --- Window ROI Extraction
                        image::Image<uint8_t> WindowgradDirROI = gradDirROI.subImage( i_roi1 );
                        image::Image<uint16_t> WindowgradMagROI = graMagROI.subImage( i_roi1 );
                        //cv::Mat orient2 = processing::ImageProcessing::ConvertToCV( WindowgradDirROI );
                        float32_t features[9] = { 0 };

                        for( uint32_t yind = 0; yind < WINDOW_SIZE; yind++ )
                        {
                            for( uint32_t xind = 0; xind < WINDOW_SIZE; xind++ )
                            {
                                uint32_t Ind = *WindowgradDirROI.at( xind, yind );
                                features[Ind] += *WindowgradMagROI.at( xind, yind );
                            }
                        }

                        // find max feature
                        float32_t max_val = 0.0f;
                        uint32_t max_ind = 0;

                        for( uint32_t i = 0; i < 9; i++ )
                        {
                            if( max_val < features[i] )
                            {
                                max_ind = i;
                                max_val = features[i];
                            }
                        }

                        uint32_t avg_val = find_avg_img( Cropimg );

                        if( ( ( max_ind == 3 ) || ( max_ind == 4 ) || ( max_ind == 5 ) ) && ( max_val > mag_avg_val ) && ( avg_val < 180 ) /*&& floor( std_val ) > std_thresh */ )
                        {
                            features_prev[features_prev_size] = Point2f( x + xx, y + yy );
                            features_prev_size = features_prev_size + 1;
                            //cv::circle( input_img1, cv::Point2f( x + xx, y + yy ), 2, cv::Scalar( 255, 0, 0 ), -1, 8, 0 );
                        }

                        int a = 1;
                    }
                }
            }
        }

        m_InitialDistanceTravelled = 0.0f;
        m_InitialDistanceTravelled += m_pVehicle->distanceTravelled_m();
        m_InitialPointsDetected = true;
        //cv::Mat input_img1 = processing::ImageProcessing::ConvertToCV( i_image );
        //cv::imshow( "image", input_img1 );
        //cv::waitKey( 1 );
        memory::MemoryPool::ReleaseImage( gradMag );
        memory::MemoryPool::ReleaseImage( gradDir );
        return TrailerPresent;
    }
    uint32_t TrailerPresenceDetection::FindGap()
    {
        uint32_t PointHistogram[global::TEMPLATE_IMAGE_HEIGHT];
        memset( PointHistogram, 0, sizeof( PointHistogram ) );
        uint32_t MaxGapPixel = 0;

        for( uint32_t i = 0; i < features_prev_size; i++ )
        {
            if( features_prev[i].y > 0 )
            {
                PointHistogram[static_cast<uint32_t>( features_prev[i].y )] = PointHistogram[static_cast<uint32_t>( features_prev[i].y )] + 1;
            }
        }

        // checking for gap in trailer
        for( uint32_t i = 0; i < ( global::TEMPLATE_IMAGE_HEIGHT - 20 ); i++ )
        {
            uint32_t gap = 0;

            if( PointHistogram[i] == 0 )
            {
                for( uint32_t j = i; j < ( global::TEMPLATE_IMAGE_HEIGHT - 20 ); j++ )
                {
                    if( PointHistogram[j] == 0 )
                    {
                        gap++;
                    }
                    else
                    {
                        i = j;
                        break;
                    }
                }
            }

            if( MaxGapPixel < gap )
            {
                MaxGapPixel = gap;
            }
        }

        return MaxGapPixel;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Fn_Name  : find_std_Points
    //Fn_Work : find the std of points
    //Fn_Return : standard deviation
    //Fn_Input : input array
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    float32_t TrailerPresenceDetection::find_std_Points( float32_t* i_points )
    {
        float32_t sum_val = 0.0;
        float32_t count1 = 0.0;
        float32_t std_dev = 0.0;

        for( uint32_t x = 0; x < global::WARPED_TOPVIEW_IMAGE_WIDTH; x++ )
        {
            for( uint32_t i = 0; i < i_points[x]; i++ )
            {
                sum_val += static_cast<float32_t>( i_points[x] );
                count1++;
            }
        }

        float32_t mean_val = sum_val / count1;

        for( uint32_t x = 0; x < global::WARPED_TOPVIEW_IMAGE_WIDTH; x++ )
        {
            for( uint32_t i = 0; i < i_points[x]; i++ )
            {
                std_dev += pow( static_cast<float32_t>( i_points[x] ) - mean_val, 2.0f );
            }
        }

        std_dev = sqrt( std_dev / count1 );
        return std_dev;
    }
    /*
    * Extract magnitude and orientation
    */
    void TrailerPresenceDetection::GradientOrientationDetection( image::Image<uint8_t> i_image, image::Image<uint16_t> o_gradMag, image::Image<uint8_t> o_gradDir )
    {
        const uint32_t img_step = i_image.getStep();
        const uint32_t grad_step = o_gradMag.getStep();
        uint32_t dir_step = o_gradDir.getStep();
        uint8_t* img_row = i_image.getData() + img_step + 1;/*PRQA S 3705*/
        uint8_t* img_ptr0;
        uint8_t* img_ptr1;
        uint8_t* img_ptr2;
        uint8_t* img_ptr3;
        uint8_t* img_ptr4;
        uint8_t* img_ptr5;
        uint8_t* img_ptr6;
        uint8_t* img_ptr7;
        uint8_t* img_ptr8;
        uint16_t* grad_row = o_gradMag.getData() + grad_step + 1;/*PRQA S 3705*/
        uint16_t* grad_ptr;
        uint8_t* dir_row = o_gradDir.getData() + dir_step + 1;/*PRQA S 3705*/
        uint8_t* dir_ptr;
        //
        const uint32_t img_width = i_image.getWidth();
        const uint32_t start = 1;
        const uint32_t end = ( img_width - 2 ) * ( i_image.getHeight() - 2 );
        uint32_t count = 0;
        float32_t Total_Bin = 9.0f;
        //
        img_ptr0 = img_row - img_step - 1;/*PRQA S 3705*/
        img_ptr1 = img_row - img_step;/*PRQA S 3705*/
        img_ptr2 = img_row - img_step + 1;/*PRQA S 3705*/
        img_ptr3 = img_row - 1;/*PRQA S 3705*/
        img_ptr4 = img_row;
        img_ptr5 = img_row + 1;/*PRQA S 3705*/
        img_ptr6 = img_row + img_step - 1;/*PRQA S 3705*/
        img_ptr7 = img_row + img_step;/*PRQA S 3705*/
        img_ptr8 = img_row + img_step + 1;/*PRQA S 3705*/
        grad_ptr = grad_row;
        dir_ptr = dir_row;

        for( uint32_t i = start; i < end; ++i )
        {
            if( count < ( img_width - 2 ) )
            {
                int32_t gx = ( -1 ) * static_cast<int32_t>( *img_ptr0 ) + \
                             1 * static_cast<int32_t>( *img_ptr2 ) + \
                             ( -2 ) * static_cast<int32_t>( *img_ptr3 ) + \
                             2 * static_cast<int32_t>( *img_ptr5 ) + \
                             ( -1 ) * static_cast<int32_t>( *img_ptr6 ) + \
                             1 * static_cast<int32_t>( *img_ptr8 );
                int32_t gy = ( -1 ) * static_cast<int32_t>( *img_ptr0 ) + \
                             ( -2 ) * static_cast<int32_t>( *img_ptr1 ) + \
                             ( -1 ) * static_cast<int32_t>( *img_ptr2 ) + \
                             1 * static_cast<int32_t>( *img_ptr6 ) + \
                             2 * static_cast<int32_t>( *img_ptr7 ) + \
                             1 * static_cast<int32_t>( *img_ptr8 );
                *grad_ptr = static_cast<uint16_t>( mecl::math::algebra<float32_t>::sqrt_x( static_cast<float32_t>( ( gx ) * ( gx ) + ( gy ) * ( gy ) ) ) );
                //float32_t tangent = static_cast<float32_t>( gy ) / static_cast<float32_t>( gx );
                float32_t Orientation = mecl::math::trigonometry<float32_t>::atan2_x( static_cast<float32_t>( gy ), static_cast<float32_t>( gx ) );
                //float32_t tangent = static_cast<float32_t>( gy ) / static_cast<float32_t>( gx );
                uint8_t Bin_count = 0;

                if( gx == 0 )
                {
                    *dir_ptr = 5;
                }
                else
                {
                    float32_t deg_val = Orientation * ( 180.0 / PI );

                    if( deg_val < -180.0f )
                    {
                        deg_val += 360.0f;
                    }
                    else if( deg_val > 180.0f )
                    {
                        deg_val -= 360.0f;
                    }

                    //
                    if( ( deg_val > -180.0f ) && ( deg_val < -140.0f ) )
                    {
                        *dir_ptr = 4;
                    }
                    else if( ( deg_val > -140.0f ) && ( deg_val < -100.0f ) )
                    {
                        *dir_ptr = 5;
                    }
                    else if( ( deg_val > -100.0f ) && ( deg_val < -60.0f ) )
                    {
                        *dir_ptr = 2;
                    }
                    else if( ( deg_val > -60.0f ) && ( deg_val < -20.0f ) )
                    {
                        *dir_ptr = 3;
                    }
                    else if( ( deg_val > -20.0f ) && ( deg_val < 20.0f ) )
                    {
                        *dir_ptr = 4;
                    }
                    else if( ( deg_val > 20.0f ) && ( deg_val < 60.0f ) )
                    {
                        *dir_ptr = 5;
                    }
                    else if( ( deg_val > 60.0f ) && ( deg_val < 100.0f ) )
                    {
                        *dir_ptr = 2;
                    }
                    else if( ( deg_val > 100.0f ) && ( deg_val < 140.0f ) )
                    {
                        *dir_ptr = 3;
                    }
                    else if( ( deg_val > 140.0f ) && ( deg_val < 180.0f ) )
                    {
                        *dir_ptr = 4;
                    }
                }

                count++;
                ++img_ptr0;
                ++img_ptr1;
                ++img_ptr2;
                ++img_ptr3;
                ++img_ptr4;
                ++img_ptr5;
                ++img_ptr6;
                ++img_ptr7;
                ++img_ptr8;
                ++grad_ptr;
                ++dir_ptr;
            }
            else
            {
                img_row += img_step;
                grad_row += grad_step;
                dir_row += dir_step;
                count = 0;
                img_ptr0 = img_row - img_step - 1;/*PRQA S 3705*/
                img_ptr1 = img_row - img_step;/*PRQA S 3705*/
                img_ptr2 = img_row - img_step + 1;/*PRQA S 3705*/
                img_ptr3 = img_row - 1;/*PRQA S 3705*/
                img_ptr4 = img_row;
                img_ptr5 = img_row + 1;/*PRQA S 3705*/
                img_ptr6 = img_row + img_step - 1;/*PRQA S 3705*/
                img_ptr7 = img_row + img_step;/*PRQA S 3705*/
                img_ptr8 = img_row + img_step + 1;/*PRQA S 3705*/
                grad_ptr = grad_row;
                dir_ptr = dir_row;
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Fn_Name  : find_std_img
    //Fn_Work : find the std of matrix
    //Fn_Return : average value
    //Fn_Input : input array
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    float32_t TrailerPresenceDetection::find_std_img( image::Image<uint8_t> input_image )
    {
        float32_t sum_val = 0.0;
        float32_t count1 = 0.0;
        float32_t std_dev = 0.0;

        for( uint32_t x = 0; x < input_image.getHeight(); x++ )
        {
            for( uint32_t y = 0; y < input_image.getWidth(); y++ )
            {
                sum_val += static_cast<float32_t>( *input_image.at( y, x ) );
                count1++;
            }
        }

        float32_t mean_val = sum_val / count1;

        for( uint32_t x = 0; x < input_image.getHeight(); x++ )
        {
            for( uint32_t y = 0; y < input_image.getWidth(); y++ )
            {
                std_dev += pow( static_cast<float32_t>( *input_image.at( y, x ) ) - mean_val, 2.0f );
            }
        }

        std_dev = sqrt( std_dev / count1 );
        return std_dev;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Fn_Name  : find_mag_avg_img
    //Fn_Work : find the avg of matrix
    //Fn_Return : average value
    //Fn_Input : input array
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    uint16_t TrailerPresenceDetection::find_mag_avg_img( image::Image<uint16_t> input_image )
    {
        uint16_t max_val = 0;
        uint32_t count1 = 0;

        for( uint32_t x = 0; x < input_image.getHeight(); x++ )
        {
            for( uint32_t y = 0; y < input_image.getWidth(); y++ )
            {
                if( *input_image.at( y, x ) > max_val )
                {
                    max_val = static_cast<uint16_t>( *input_image.at( y, x ) );
                    count1++;
                }
            }
        }

        return max_val;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Fn_Name  : find_avg_img
    //Fn_Work : find the avg of matrix
    //Fn_Return : average value
    //Fn_Input : input array
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    uint32_t TrailerPresenceDetection::find_avg_img( image::Image<uint8_t> input_image )
    {
        uint32_t avg_val = 0;
        uint32_t count1 = 0;

        for( uint32_t x = 0; x < input_image.getHeight(); x++ )
        {
            for( uint32_t y = 0; y < input_image.getWidth(); y++ )
            {
                avg_val += static_cast<uint8_t>( *input_image.at( y, x ) );
                count1++;
            }
        }

        return avg_val / count1;
    }
}
