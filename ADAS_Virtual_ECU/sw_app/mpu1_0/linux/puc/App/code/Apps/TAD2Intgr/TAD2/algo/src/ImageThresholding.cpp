// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [05-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "EdgeDetector.h"
#include "ImageThresholding.h"
#ifdef DIAGNOSTICS
    #include "global.h"
    #include "common/db.h"
    #include "fo.h"
#endif

namespace TAD2
{
    /*
    * Constructor.
    */
    ImageThresholding::ImageThresholding() :
        m_initOK( false ),
        m_isRunning( false ),
        m_lastFrameRun( 0 ),
        c_roiRadius( 0 ),
        c_roiWidth( 0 ),
        c_roiHeight( 0 ),
        c_blurWidth( 0 ),
        c_blurHeight( 0 ),
        hitch_thresh_low( 0 ),
        hitch_thresh_high( 0 )

    {
    }

    /*
    * Destructor.
    */
    ImageThresholding::~ImageThresholding()
    {
    }

    /*
    * Initialize this module.
    *
    * Called once at the beginning of the program, before any other functions.
    */
    bool_t ImageThresholding::Init()
    {
        c_roiWidth = global::TOPVIEW_IMAGE_WIDTH / 8;
        c_roiHeight = global::TOPVIEW_IMAGE_HEIGHT / 4;
        c_roiRadius = c_roiHeight / 4;
        c_blurWidth = global::TOPVIEW_IMAGE_WIDTH / 32;
        c_blurHeight = static_cast <uint32_t>( static_cast <float32_t>( global::TOPVIEW_IMAGE_HEIGHT ) * 0.035f ); //  (/)28.6
        m_initOK = true;
        return true;
    }

    /*
    * Signifies the beginning of a period of execution. Allocates any necessary
    * memory and sets any input parameters needed at runtime.
    */
    bool_t ImageThresholding::Start()
    {
        bool_t returnValue = false;

        if( m_initOK )
        {
            if( m_isRunning )
            {
                Finish();
            }

            m_isRunning = true;
            returnValue = true;
        }

        return returnValue;
    }

    /*
    * Signifies the end of a period of execution. Deallocates any memory used.
    */
    void ImageThresholding::Finish()
    {
        m_isRunning = false;
    }

    /*
    * Run this module.
    *
    * Will only run if called between a call to Start() and a call to Finish(), respectively.
    * Records the given frame so as to not run the same frame multiple times.
    */
    void ImageThresholding::Run( int32_t i_frame, image::Image<uint8_t>& i_topView, _roi::ROI& i_roi, Point2i i_hitchPoint, float32_t i_trailerAngle, bool_t i_trailerAngleValid
                                 , image::Image<uint16_t>& o_lowThresh, image::Image<uint16_t>& o_highThresh
                                 , image::Image<uint16_t>& o_gradMag, image::Image<uint8_t>& o_gradDir, bool_t highedge, bool_t i_warpedimage )
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

        if( ret_val )
        {
#ifdef DIAGNOSTICS
            diag::start( "ImageThresholding" );
#endif
            //
            // --- Create an ROI around the hitch-point and trailer, because we know there are edges there
            _roi::ROI hitchBounds;

            if( i_trailerAngleValid )
            {
                hitchBounds = _CreateROIAtOffset( i_roi, i_hitchPoint, i_trailerAngle, static_cast <float32_t>( c_roiRadius ), c_roiWidth, c_roiHeight );
            }
            else
            {
                hitchBounds = _CreateROIAtOffset( i_roi, i_hitchPoint, 0.0f, 0.0f, c_roiWidth, c_roiHeight );
            }

            if( i_warpedimage )
            {
                hitchBounds.setX( i_roi.getX() + 5 );
                hitchBounds.setY( i_roi.getY() + 5 );
                hitchBounds.setWidth( i_roi.getWidth() - 10 );
                hitchBounds.setHeight( i_roi.getHeight() - 10 );
            }

            // --- Extract gradient from hitch roi
            image::Image<uint8_t> InputROI = i_topView.subImage( i_roi );
            image::Image<uint16_t> gradMag = o_gradMag.subImage( i_roi );
            image::Image<uint8_t> gradDir = o_gradDir.subImage( i_roi );
            TAD2::Canny( InputROI, image::NullImage<uint16_t>(), image::NullImage<uint16_t>(), image::NullImage<uint8_t>(), gradMag, gradDir );
            //
            image::Image<uint16_t> gradROI = o_gradMag.subImage( hitchBounds );
            // --- Perform Otsu on gradient
            _CalculateRoiThresholds( gradROI, hitch_thresh_low, hitch_thresh_high, highedge );
#ifdef DIAGNOSTICS
            db::imshow_segmented( "(IT-3) ROI Segmented", gradROI, hitch_thresh_low, hitch_thresh_high );
#endif
            // --- Create threshold images
            image::Image<uint8_t> topViewROI = i_topView.subImage( i_roi );
            //
            // --- Take mean of roi
            image::Image<uint8_t> hitchROI = i_topView.subImage( hitchBounds );
            float32_t roi_mean = processing::ImageProcessing::Mean<float32_t>( hitchROI );
            image::Image<uint16_t> lowThreshROI = o_lowThresh.subImage( i_roi );
            image::Image<uint16_t> highThreshROI = o_highThresh.subImage( i_roi );
            _CreateThresholdImages( topViewROI, c_blurWidth, c_blurHeight, roi_mean, hitch_thresh_low, hitch_thresh_high, lowThreshROI, highThreshROI );
#ifdef DIAGNOSTICS

            if( 0 )
            {
                fo::csvstream file = fo::getCSVStream( "TAD2/thresholds.csv" );
                file << global::getFrameNum() << ( int )hitch_thresh_low << ( int )hitch_thresh_high << '\n';
            }

            db::imshow( "(IT-3) Image Thresholding ROI", i_topView );
            db::rect( "(IT-3) Image Thresholding ROI", hitchBounds, db::Colour( 255, 0, 0 ), 1 );
            db::rect( "(IT-3) Image Thresholding ROI", i_roi, db::Colour( 255, 0, 0 ), 1 );
            db::imshow( "(IT-2) Low Threshold", o_lowThresh );
            db::imshow( "(IT-2) High Threshold", o_highThresh );
            db::imshow_segmented( "(IT-3) ROI Segmented", gradROI, hitch_thresh_low, hitch_thresh_high );
            db::imshow_segmented( "(IT-3) ROI Segmented 2", gradROI, o_lowThresh.subImage( hitchBounds ), o_highThresh.subImage( hitchBounds ) );
#endif
            //
            m_lastFrameRun = i_frame;
#ifdef DIAGNOSTICS
            diag::stop();
#endif
        }
    }
    /*
    * Get feature image. Not currently used.
    */
    void ImageThresholding::setlastframe( uint32_t frame_no )
    {
        m_lastFrameRun = frame_no;
    }
    //---------------------------------------------------------------------------
    //Fn_Name  : _getotsuthresh
    //Fn_Work :  returns otsu threshold with double value
    //Fn_Return : threshold
    //Fn_Input :
    // --------------------------------------------------------------------------
    uint16_t ImageThresholding::_getotsuthresh()const
    {
        return hitch_thresh_low;
    }
    /*
    * Finds the point on the circle of centre 'i_centre' and radius 'i_radius'
    * at the angle 'i_angle' and creates an ROI around this point with the given
    * width and height. Ensures that the output ROI is within a 3 pixel margin of
    * the input bounding ROI.
    */
    _roi::ROI ImageThresholding::_CreateROIAtOffset( _roi::ROI& i_boundingROI, Point2i i_centre, float32_t i_angle, float32_t i_radius, uint32_t i_roiWidth, uint32_t i_roiHeight )
    {
        int32_t margin = 3;
        int32_t minX = i_boundingROI.getX() + margin;
        int32_t maxX = i_boundingROI.getX() + i_boundingROI.getWidth() - margin - i_roiWidth;
        int32_t minY = i_boundingROI.getY() + margin;
        int32_t maxY = i_boundingROI.getY() + i_boundingROI.getHeight() - margin - i_roiHeight;
        int32_t x;
        int32_t y;
        int32_t w;
        int32_t h;
        _roi::ROI returnValue;

        if( maxX >= minX )
        {
            x = i_centre.x + static_cast <int32_t>( i_radius * mecl::math::trigonometry<float32_t>::cos_x( mecl::math::toRadians_x( i_angle ) ) ) - i_roiWidth / 2;
            x = mms::squeeze( x, minX, maxX );
            w = i_roiWidth;
        }
        else
        {
            x = i_boundingROI.getX() + margin;
            w = i_boundingROI.getWidth() - 2 * margin;
        }

        if( maxY >= minY )
        {
            y = i_centre.y + static_cast <int32_t>( i_radius * mecl::math::trigonometry<float32_t>::sin_x( mecl::math::toRadians_x( i_angle ) ) ) - i_roiHeight / 2;
            y = mms::squeeze( y, minY, maxY );
            h = i_roiHeight;
        }
        else
        {
            y = i_boundingROI.getY() + margin;
            h = i_boundingROI.getHeight() - 2 * margin;
        }

        if( ( w < 0 ) || ( h < 0 ) )
        {
            returnValue = _roi::ROI( x, y, 0, 0 );
        }
        else
        {
            returnValue = _roi::ROI( x, y, w, h );
        }

        return returnValue;
    }

    /*
    * Calculate the thresholds for the hitch ROI.
    */
    void ImageThresholding::_CalculateRoiThresholds( image::Image<uint16_t>& i_image, uint16_t& o_thresh_low, uint16_t& o_thresh_high, bool_t highedge )
    {
        uint16_t otsu_thresh;
        _OtsuSingleThreshold( i_image, otsu_thresh );

        if( highedge )
        {
            o_thresh_high = otsu_thresh * 2;
        }
        else
        {
            o_thresh_high = otsu_thresh / 2;
        }

        o_thresh_low = o_thresh_high / 2;
    }

    image::Image<uint16_t>& ImageThresholding::GetLowThreshold()
    {
        return m_lowThresh;
    }

    image::Image<uint16_t>& ImageThresholding::GetHighThreshold()
    {
        return m_highThresh;
    }
    /*
    * Perform Otsu thresholding on a gradient image. Double thresholds.
    */
    void ImageThresholding::_OtsuDoubleThreshold( image::Image<uint16_t>& i_image, uint16_t& o_thresh_low, uint16_t& o_thresh_high )
    {
#ifdef DIAGNOSTICS
        diag::start( "ImageThresholding: OtsuDoubleThreshold" );
#endif
        const int32_t NGREY = 360;
        int32_t hist[NGREY];
        memset( reinterpret_cast<uint8_t*>( hist ), 0, sizeof( int32_t ) * NGREY );
        int32_t total_w = i_image.getSize();
        int32_t height = i_image.getHeight();
        int32_t width = i_image.getWidth();

        for( int32_t y = 0; y < height; y++ )
        {
            for( int32_t x = 0; x < width; x++ )
            {
                if( *( i_image.at( x, y ) ) >= NGREY )
                {
                    total_w--; // this pixel is not counted towards weight
                }
                else
                {
                    hist[static_cast <int32_t>( *( i_image.at( x, y ) ) )]++;
                }
            }
        }

        hist[0] += 250000;
        total_w += 250000;
        // --- Sum used in calculation of means
        int32_t total_sum = 0;

        for( uint32_t i = 0; i < NGREY; ++i )
        {
            total_sum += i * hist[i];
        }

        int32_t total_m = total_sum / total_w;
        // ---
        int32_t w[3] = { 0 }; // number of pixels in class 0, 1, 2
        float32_t m[3] = { 0 };  // mean of class 0, 1, 2
        int32_t sum[3] = { 0 };  // sum of (i * hist[i]) for class 0, 1, 2
        float32_t max_var = 0;

        for( uint32_t i = 0; i < NGREY; ++i )
        {
            w[0] += hist[i];
            w[1] = 0;
            sum[0] += i * hist[i];
            sum[1] = 0;

            if( w[0] == 0 )
            {
                continue;
            }

            for( uint32_t j = i + 1; j < NGREY; ++j )
            {
                w[1] += hist[j];
                w[2] = total_w - w[1] - w[0];
                sum[1] += j * hist[j];
                sum[2] = total_sum - sum[1] - sum[0];

                if( w[1] == 0 )
                {
                    continue;
                }

                if( w[2] == 0 )
                {
                    break;
                }

                //
                m[0] = static_cast <float32_t>( sum[0] ) / static_cast <float32_t>( w[0] );
                m[1] = static_cast <float32_t>( sum[1] ) / static_cast <float32_t>( w[1] );
                m[2] = static_cast <float32_t>( sum[2] ) / static_cast <float32_t>( w[2] );
                float32_t dif0 = ( m[0] - static_cast <float32_t>( total_m ) ) * ( m[0] - static_cast <float32_t>( total_m ) );
                float32_t dif1 = ( m[1] - static_cast <float32_t>( total_m ) ) * ( m[1] - static_cast <float32_t>( total_m ) );
                float32_t dif2 = ( m[2] - static_cast <float32_t>( total_m ) ) * ( m[2] - static_cast <float32_t>( total_m ) );
                float32_t var = ( static_cast <float32_t>( w[0] ) / static_cast <float32_t>( total_w ) ) * dif0 + ( static_cast <float32_t>( w[1] ) / static_cast <float32_t>( total_w ) ) * dif1 + ( static_cast <float32_t>( w[2] ) / static_cast <float32_t>( total_w ) ) * dif2;

                if( var > max_var )
                {
                    max_var = var;
                    o_thresh_low = static_cast <uint8_t>( i );
                    o_thresh_high = static_cast <uint8_t>( j );
                }
            }
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }

    /*
    * Perform Otsu thresholding on a gradient image. Single threshold.
    */
    void ImageThresholding::_OtsuSingleThreshold( image::Image<uint16_t>& i_image, uint16_t& o_thresh )
    {
#ifdef DIAGNOSTICS
        diag::start( "ImageThresholding: OtsuSingleThreshold" );
#endif
        const int32_t NGREY = 360;
        int32_t hist[NGREY];
        memset( reinterpret_cast<uint8_t*>( hist ), 0, sizeof( int32_t ) * NGREY );
        //
        // --- Build histogram
        int32_t total_w = i_image.getSize();
        int32_t height = i_image.getHeight();
        int32_t width = i_image.getWidth();

        for( int32_t y = 0; y < height; y++ )
        {
            for( int32_t x = 0; x < width; x++ )
            {
                if( *( i_image.at( x, y ) ) >= NGREY )
                {
                    hist[NGREY - 1]++;
                }
                else
                {
                    hist[static_cast <int32_t>( *( i_image.at( x, y ) ) )]++;
                }
            }
        }

        // --- Sum used in calculation of means
        int32_t total_sum = 0;

        for( uint32_t i = 0; i < NGREY; ++i )
        {
            total_sum += i * hist[i];
        }

        // --- Variance calculation
        int32_t w1 = 0;
        int32_t w2 = 0; // number of pixels (weight) in each class
        float32_t m1 = 0;
        float32_t m2 = 0;  // mean of each class
        int32_t sum1 = 0;
        int32_t sum2 = 0;  // sum of (i * hist[i]) for each class
        float32_t max_var = 0;

        for( uint32_t i = 0; i < NGREY; ++i )
        {
            w1 += hist[i];
            w2 = total_w - w1;
            sum1 += i * hist[i];
            sum2 = total_sum - sum1;

            if( ( w1 == 0 ) || ( w2 == 0 ) )
            {
                continue;
            }

            m1 = static_cast <float32_t>( sum1 ) / static_cast <float32_t>( w1 );
            m2 = static_cast <float32_t>( sum2 ) / static_cast <float32_t>( w2 );
            //
            // calculate the between class variance
            float32_t var = static_cast <float32_t>( w1 * w2 ) * ( m1 - m2 ) * ( m1 - m2 );

            if( var > max_var )
            {
                max_var = var;
                o_thresh = static_cast <uint8_t>( i );
            }
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }

    /**
    * Calculate mean around each pixel where the size of the square used is
    * ('i_subWidth' x 'i_subHeight') with the pixel in the centre. The threshold
    * for this pixel is then calculated using this mean.
    *
    * The formula for each threshold value is,
    *
    *           //thresh(i) = otsu_thresh(roi) * (mean(i) / mean(roi))
    *
    * For reference, the labeled sections of the image are calculated in the loop
    * where the corresponding letter is in comment. The distance between the
    * borders and the dotted lines is ('i_subWidth' / 2) or ('i_subHeight' / 2)
    * respectively.
    *
    *        _______________________________________________________________
    *       | A :                          B                            : E |
    *       |...:.......................................................:...|
    *       |   :                                                       :   |
    *       |   :                                                       :   |
    *       |   :                                                       :   |
    *       |   :                                                       :   |
    *       |   :                                                       :   |
    *       |   :                                                       :   |
    *       |   :                                                       :   |
    *       | C :                          D                            : F |
    *       |   :                                                       :   |
    *       |   :                                                       :   |
    *       |   :                                                       :   |
    *       |   :                                                       :   |
    *       |   :                                                       :   |
    *       |   :                                                       :   |
    *       |...:.......................................................:...|
    *       | G :                          H                            : I |
    *       |___:_______________________________________________________:___|
    */

    void ImageThresholding::_CreateThresholdImages( image::Image<uint8_t>& i_topView, uint32_t i_subWidth, uint32_t i_subHeight, float32_t i_roiMean, uint16_t roi_thresh_low, uint16_t roi_thresh_high, image::Image<uint16_t>& o_thresh_low, image::Image<uint16_t>& o_thresh_high )
    {
#ifdef DIAGNOSTICS
        diag::start( "ImageThresholding: _CreateThresholdImages" );
        diag::start( "IT: _CreateThresholdImages: 1(I)" );
#endif
        // --- Sum in X-direction, up to 'subWidth' pixels
        image::Image<uint16_t> sumXImg = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
        processing::ImageProcessing::Clear( sumXImg );
        uint16_t sumX;
        uint8_t* img_ptr1 = i_topView.getData();
        uint8_t* img_ptr2 = i_topView.getData();
        uint8_t* img_row = i_topView.getData();
        uint16_t* sumX_ptr = sumXImg.getData();
        uint16_t* sumX_row = sumXImg.getData();

        for( uint32_t y = 0; y < i_topView.getHeight(); ++y )
        {
            sumX = 0;
            img_ptr1 = img_row;
            img_ptr2 = img_row;
            sumX_ptr = sumX_row + i_subWidth / 2;   //PRQA S 3705

            for( uint32_t x = 0; x < ( i_subWidth / 2 ); ++x )
            {
                sumX += *img_ptr1;
                ++img_ptr1;
            }

            for( uint32_t x = i_subWidth / 2; x < i_subWidth; ++x )
            {
                sumX += *img_ptr1;
                *sumX_ptr = sumX;
                ++img_ptr1;
                ++sumX_ptr;
            }

            for( uint32_t x = i_subWidth; x < i_topView.getWidth(); ++x )
            {
                sumX += *img_ptr1;
                sumX -= *img_ptr2;
                *sumX_ptr = sumX;
                ++img_ptr1;
                ++img_ptr2;
                ++sumX_ptr;
            }

            // wrap around to store right edge sums
            sumX_ptr = sumX_row;

            for( uint32_t x = 0; x < ( i_subWidth / 2 ); ++x )
            {
                sumX -= *img_ptr2;
                *sumX_ptr = sumX;
                ++img_ptr2;
                ++sumX_ptr;
            }

            img_row += i_topView.getStep();
            sumX_row += sumXImg.getStep();
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
        // --- Sum in Y-direction, up to 'subHeight' from previous sums
        uint16_t* sumX_ptr1 = sumXImg.getData(); // pointer to current X-sum
        uint16_t* sumX_ptr2 = sumXImg.getData(); // pointer to last X-sum
        uint16_t* sumX_row1 = sumXImg.getData();
        uint16_t* sumX_row2 = sumXImg.getData();
        uint32_t sumYArr[1280];
        memset( reinterpret_cast<uint8_t*>( sumYArr ) , 0, sizeof( uint32_t ) * sumXImg.getWidth() );
        uint32_t* sumY_ptr = sumYArr; // pointer to entire sum
        uint16_t* lo_ptr = o_thresh_low.getData(); // pointer to current low output threshold
        uint16_t* lo_row = o_thresh_low.getData();
        uint16_t* hi_ptr = o_thresh_high.getData(); // pointer to current high output threshold
        uint16_t* hi_row = o_thresh_high.getData();
        const uint32_t MAX_VAL = 360;
        float32_t mean_factor_low = ( 1.0f / i_roiMean ) * static_cast <float32_t>( roi_thresh_low );
        float32_t mean_factor_high = ( 1.0f / i_roiMean ) * static_cast <float32_t>( roi_thresh_high );
        float32_t sum_factor_low = ( 1.0f / static_cast <float32_t>( i_subWidth * i_subHeight ) ) * mean_factor_low;
        float32_t sum_factor_high = ( 1.0f / static_cast <float32_t>( i_subWidth * i_subHeight ) ) * mean_factor_high;
        uint32_t max_mean_low = static_cast <uint32_t>( static_cast <float32_t>( MAX_VAL ) / mean_factor_low );
        uint32_t max_mean_high = static_cast <uint32_t>( static_cast <float32_t>( MAX_VAL ) / mean_factor_high );
        uint32_t max_sum_low = static_cast <uint32_t>( static_cast <float32_t>( MAX_VAL ) / sum_factor_low );
        uint32_t max_sum_high = static_cast <uint32_t>( static_cast <float32_t>( MAX_VAL ) / sum_factor_high );
        uint32_t mean;
#ifdef DIAGNOSTICS
        diag::start( "IT: _CreateThresholdImages: 2" );
#endif

        // start adding X-sums and moving 'sumX_ptr1'
        for( uint32_t y = 0; y < ( i_subHeight / 2 ); ++y )
        {
            sumY_ptr = sumYArr;
            sumX_ptr1 = sumX_row1;

            for( uint32_t x = 0; x < sumXImg.getWidth(); ++x )
            {
                *sumY_ptr += *sumX_ptr1;
                ++sumX_ptr1;
                ++sumY_ptr;
            }

            sumX_row1 += sumXImg.getStep();
        }

        // calculate thresholds where y < subHeight / 2, start moving 'out_ptr'
        for( uint32_t y = i_subHeight / 2; y < i_subHeight; ++y )
        {
            sumX_ptr1 = sumX_row1 + i_subWidth / 2; //PRQA S 3705
            sumY_ptr = sumYArr + i_subWidth / 2;    //PRQA S 3705
            lo_ptr = lo_row;
            hi_ptr = hi_row;

            // A
            for( uint32_t x = i_subWidth / 2; x < i_subWidth; ++x )
            {
                *sumY_ptr += *sumX_ptr1;
                mean = ( *sumY_ptr / ( x * y ) );
                *lo_ptr = ( mean >= max_mean_low ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean ) * mean_factor_low );
                *hi_ptr = ( mean >= max_mean_high ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean ) * mean_factor_high );
                ++sumX_ptr1;
                ++sumY_ptr;
                ++lo_ptr;
                ++hi_ptr;
            }

            // B
            for( uint32_t x = i_subWidth; x < sumXImg.getWidth(); ++x )
            {
                *sumY_ptr += *sumX_ptr1;
                mean = ( *sumY_ptr / ( i_subWidth * y ) );
                *lo_ptr = ( mean >= max_mean_low ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean ) * mean_factor_low );
                *hi_ptr = ( mean >= max_mean_high ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean ) * mean_factor_high );
                ++sumX_ptr1;
                ++sumY_ptr;
                ++lo_ptr;
                ++hi_ptr;
            }

            // E
            sumX_ptr1 = sumX_row1;
            sumY_ptr = sumYArr;

            for( uint32_t x = i_subWidth - 1; x >= ( i_subWidth / 2 ); --x )
            {
                *sumY_ptr += *sumX_ptr1;
                mean = ( *sumY_ptr / ( x * y ) );
                *lo_ptr = ( mean >= max_mean_low ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean ) * mean_factor_low );
                *hi_ptr = ( mean >= max_mean_high ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean ) * mean_factor_high );
                ++sumX_ptr1;
                ++sumY_ptr;
                ++lo_ptr;
                ++hi_ptr;
            }

            sumX_row1 += sumXImg.getStep();
            lo_row += o_thresh_low.getStep();
            hi_row += o_thresh_high.getStep();
        }

#ifdef DIAGNOSTICS
        diag::stop();
        diag::start( "IT: _CreateThresholdImages: 3(M)" );
#endif

        // calculate thresholds where entire subHeight is in the image, start moving 'sumX_ptr2'
        for( uint32_t y = i_subHeight; y < sumXImg.getHeight(); ++y )
        {
            sumX_ptr1 = sumX_row1 + i_subWidth / 2; //PRQA S 3705
            sumX_ptr2 = sumX_row2 + i_subWidth / 2; //PRQA S 3705
            sumY_ptr = sumYArr + i_subWidth / 2;    //PRQA S 3705
            lo_ptr = lo_row;
            hi_ptr = hi_row;

            // C
            for( uint32_t x = i_subWidth / 2; x < i_subWidth; ++x )
            {
                *sumY_ptr += *sumX_ptr1;
                *sumY_ptr -= *sumX_ptr2;
                mean = ( *sumY_ptr / ( x * i_subHeight ) );
                *lo_ptr = ( mean >= max_mean_low ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean ) * mean_factor_low );
                *hi_ptr = ( mean >= max_mean_high ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean ) * mean_factor_high );
                ++sumX_ptr1;
                ++sumX_ptr2;
                ++sumY_ptr;
                ++lo_ptr;
                ++hi_ptr;
            }

            // D
            for( uint32_t x = i_subWidth; x < sumXImg.getWidth(); ++x )
            {
                *sumY_ptr += *sumX_ptr1;
                *sumY_ptr -= *sumX_ptr2;
                *lo_ptr = ( *sumY_ptr >= max_sum_low ) ? MAX_VAL : static_cast<uint16_t>( ( static_cast<float32_t>( *sumY_ptr ) * sum_factor_low ) );
                *hi_ptr = ( *sumY_ptr >= max_sum_high ) ? MAX_VAL : static_cast<uint16_t>( ( static_cast<float32_t>( *sumY_ptr ) * sum_factor_high ) );
                ++sumX_ptr1;
                ++sumX_ptr2;
                ++sumY_ptr;
                ++lo_ptr;
                ++hi_ptr;
            }

            // F
            sumX_ptr1 = sumX_row1;
            sumX_ptr2 = sumX_row2;
            sumY_ptr = sumYArr;

            for( uint32_t x = i_subWidth - 1; x >= ( i_subWidth / 2 ); --x )
            {
                *sumY_ptr += *sumX_ptr1;
                *sumY_ptr -= *sumX_ptr2;
                mean = ( *sumY_ptr / ( x * i_subHeight ) );
                *lo_ptr = ( mean >= max_mean_low ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean )  * mean_factor_low );
                *hi_ptr = ( mean >= max_mean_high ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean )  * mean_factor_high );
                ++sumX_ptr1;
                ++sumX_ptr2;
                ++sumY_ptr;
                ++lo_ptr;
                ++hi_ptr;
            }

            sumX_row1 += sumXImg.getStep();
            sumX_row2 += sumXImg.getStep();
            lo_row += o_thresh_low.getStep();
            hi_row += o_thresh_high.getStep();
        }

#ifdef DIAGNOSTICS
        diag::stop();
        diag::start( "IT: _CreateThresholdImages: 4" );
#endif

        // calculate thresholds where y > height - subHeight / 2
        for( uint32_t y = i_subHeight - 1; y >= ( i_subHeight / 2 ); --y )
        {
            sumX_ptr2 = sumX_row2 + i_subWidth / 2; //PRQA S 3705
            sumY_ptr = sumYArr + i_subWidth / 2;    //PRQA S 3705
            lo_ptr = lo_row;
            hi_ptr = hi_row;

            // G
            for( uint32_t x = i_subWidth / 2; x < i_subWidth; ++x )
            {
                *sumY_ptr -= *sumX_ptr2;
                mean = ( *sumY_ptr / ( x * y ) );
                *lo_ptr = ( mean >= max_mean_low ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean )  * mean_factor_low );
                *hi_ptr = ( mean >= max_mean_high ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean )  * mean_factor_high );
                ++sumX_ptr2;
                ++sumY_ptr;
                ++lo_ptr;
                ++hi_ptr;
            }

            // H
            for( uint32_t x = i_subWidth; x < sumXImg.getWidth(); ++x )
            {
                *sumY_ptr -= *sumX_ptr2;
                mean = ( *sumY_ptr / ( i_subWidth * y ) );
                *lo_ptr = ( mean >= max_mean_low ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean )  * mean_factor_low );
                *hi_ptr = ( mean >= max_mean_high ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean )  * mean_factor_high );
                ++sumX_ptr2;
                ++sumY_ptr;
                ++lo_ptr;
                ++hi_ptr;
            }

            // I
            sumX_ptr2 = sumX_row2;
            sumY_ptr = sumYArr;

            for( uint32_t x = i_subWidth - 1; x >= ( i_subWidth / 2 ); --x )
            {
                *sumY_ptr -= *sumX_ptr2;
                mean = ( *sumY_ptr / ( x * y ) );
                *lo_ptr = ( mean >= max_mean_low ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean )  * mean_factor_low );
                *hi_ptr = ( mean >= max_mean_high ) ? MAX_VAL : static_cast <uint16_t>( static_cast <float32_t>( mean )  * mean_factor_high );
                ++sumX_ptr1;
                ++sumX_ptr2;
                ++sumY_ptr;
                ++lo_ptr;
                ++hi_ptr;
            }

            sumX_row2 += sumXImg.getStep();
            lo_row += o_thresh_low.getStep();
            hi_row += o_thresh_high.getStep();
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
        memory::MemoryPool::ReleaseImage( sumXImg );
#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
}

