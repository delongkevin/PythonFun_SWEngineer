// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [05-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "PreProcessing.h"
#include "WarpLUT.h"
#include "FeatureExtraction.h"
#include "TemplateWeightMask.h"

#ifdef WIN_2015_CODE
    #ifdef DIAGNOSTICS
        #include "global.h"
        #include "db.h"
        #include "fo.h"
    #endif
#endif
/*
* Constructor.
*/
namespace TAD2
{
    PreProcessing::PreProcessing() :
        m_initOK( false ),
        m_isRunning( false ),
        m_lastFrameRun( 0 ),
        m_high( 0 ),
        m_low( 0 )
    {
    }

    /*
    * Destructor.
    */
    PreProcessing::~PreProcessing()
    {
    }

    /*
    * Initialize this module.
    *
    * Called once at the beginning of the program, before any other functions.
    */
    bool_t PreProcessing::Init()
    {
        m_warpedTopViewParams = TAD2::getWarpedTopViewParams();
        m_warpXLUT_s16.setData( TAD2::getWarpXLUT() );
        m_warpYLUT_s16.setData( TAD2::getWarpYLUT() );
        m_warpXLUT_s16.setWidth( m_warpedTopViewParams.width );
        m_warpXLUT_s16.setHeight( m_warpedTopViewParams.height );
        m_warpYLUT_s16.setHeight( m_warpedTopViewParams.height );
        m_warpXLUT_s16.setNumChannels( 1 );
        m_warpYLUT_s16.setNumChannels( 1 );
        m_warpXLUT_s16.setStep( m_warpedTopViewParams.width );
        m_warpXLUT_s16.setSize( m_warpedTopViewParams.width * m_warpedTopViewParams.height );
        m_warpYLUT_s16.setSize( m_warpXLUT_s16.getSize() );
        m_initOK = true;
        return true;
    }

    /*
    * Signifies the beginning of a period of execution. Allocates any necessary
    * memory and sets any input parameters needed at runtime.
    */
    bool_t PreProcessing::Start()
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

            m_high = 255;
            m_low = 0;
            m_topView_u8 = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
            memset( m_topView_u8.getData(), 0, sizeof( uint8_t )* m_topView_u8.getHeight() * m_topView_u8.getWidth() );
            //
            m_isRunning = true;
            ret_val = true;
        }

        return ret_val;
    }

    /*
    * Signifies the end of a period of execution. Deallocates any memory used.
    */
    void PreProcessing::Finish()
    {
        memory::MemoryPool::ReleaseImage( m_warpXLUT_s16 );
        memory::MemoryPool::ReleaseImage( m_warpYLUT_s16 );
        memory::MemoryPool::ReleaseImage( m_topView_u8 );
        m_isRunning = false;
    }

    /*
    * Run this module.
    *
    * Will only run if called between a call to Start() and a call to Finish(), respectively.
    * Records the given frame so as to not run the same frame multiple times.
    */
    void PreProcessing::Run( int32_t i_frame, image::Image<uint8_t>& i_topView, _roi::ROI& i_roi )
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
            diag::start( "PreProcessing" );
#endif
            // exp
            /*cv::Mat img = processing::ImageProcessing::ConvertToCV( i_topView );
            _binarization( i_topView, 100 );
            buffer::CircularBuffer<detectedEllipseBoundary_t, c_bufSize> m_trailerAngleBuf;
            _ContourDetection( i_topView, m_trailerAngleBuf );*/
            //
            image::Image<uint8_t> blurredTopView = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
            image::Image<uint8_t> blurredTopViewROI = blurredTopView.subImage( i_roi );
            image::Image<uint8_t> inputTopViewROI = i_topView.subImage( i_roi );
            image::Image<uint8_t> outputTopViewROI = m_topView_u8.subImage( i_roi );
            //_Blur5x5_Opt( inputTopViewROI.getWidth(), inputTopViewROI.getHeight(), inputTopViewROI.getData(), blurredTopViewROI.getData(), inputTopViewROI.getStep(), blurredTopViewROI.getStep() );
            _Blur7x7( inputTopViewROI, blurredTopViewROI );
            _Normalize( blurredTopViewROI, outputTopViewROI );
            //_Blur5x5_NormalizeOpt( inputTopViewROI, outputTopViewROI );
            //
            memory::MemoryPool::ReleaseImage( blurredTopView );
            m_lastFrameRun = i_frame;
#ifdef DIAGNOSTICS
            diag::stop();
            db::imshow( "(Pre-1) Working TopView", m_topView_u8 );
#endif
        }

        return;
    }

    /**
    * Warp image around the given hitch-point, using pre-calculated LUTs.
    */
    template<typename T>
    void PreProcessing::WarpImage( const image::Image<T>& i_image, TAD2::WarpedImage<T>& o_image, Point2i i_hitchPoint )const
    {
        bool_t ret_val = true;

        if( !WarpLUTsValid() )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            // --- Check that the input image holds enough memory
            if( ( i_image.getWidth() < global::TOPVIEW_IMAGE_WIDTH ) || ( i_image.getHeight() < global::TOPVIEW_IMAGE_HEIGHT ) )
            {
#ifdef WIN_2015_CODE
                assert( 0 );
#else
                Assert( 0 );
#endif
            }

            // --- Check that the size of the destination images fits with the LUT's
            if( ( o_image.getWidth() < m_warpedTopViewParams.width ) || ( o_image.getHeight() < m_warpedTopViewParams.height ) )
            {
#ifdef WIN_2015_CODE
                assert( 0 );
#else
                Assert( 0 );
#endif
            }
            else
            {
                o_image.setWidth( m_warpedTopViewParams.width );
                o_image.setHeight( m_warpedTopViewParams.height );
            }

#ifdef DIAGNOSTICS
            diag::start( "WarpImage (1)" );
#endif
            typename image::Image<T>::iterator dst_end = o_image.end();
            image::Image<sint16_t>::iterator x_it = m_warpXLUT_s16.begin();
            image::Image<sint16_t>::iterator y_it = m_warpYLUT_s16.begin();
            int32_t hx = i_hitchPoint.x;
            int32_t hy = i_hitchPoint.y;
            T default_value = T();

            for( typename image::Image<T>::iterator dst_it = o_image.begin(); dst_it != dst_end; ++dst_it ) // PRQA S 4244
            {
                int32_t x = *x_it + hx;
                int32_t y = *y_it + hy;

                if( ( x >= 0 ) && ( x < static_cast <int32_t>( i_image.getWidth() ) ) && ( y >= 0 ) && ( y <= static_cast <int32_t>( i_image.getHeight() ) ) )
                {
                    *dst_it = *i_image.at( x, y );
                }
                else
                {
                    *dst_it = default_value;
                }

                ++x_it;
                ++y_it;
            }

            o_image.setStart_Deg( m_warpedTopViewParams.start_deg );
            o_image.setRange_Deg( m_warpedTopViewParams.range_deg );
            o_image.setDegreesPixel( m_warpedTopViewParams.degreesPerPixel );
#ifdef DIAGNOSTICS
            diag::stop();
#endif
        }

        return;
    }

    /**
    * Warp image around the given hitch-point, using the given input parameters.
    *
    * Much slower than first version which uses a look-up table.
    */
    template<typename T>
    void PreProcessing::WarpImage( const image::Image<T>& i_image, TAD2::WarpedImage<T>& o_image, TAD2::WarpedTopViewParameters i_topViewParams, Point2i i_hitchPoint )const
    {
        bool_t ret_val = true;

        // --- If we already have LUT's for this transformation, use those
        if( WarpLUTsValid() && i_topViewParams == m_warpedTopViewParams )
        {
            WarpImage( i_image, o_image, i_hitchPoint );
            ret_val = false;
        }

        if( ret_val )
        {
            // --- Check that thw input image is at least 400 x 640
            if( ( i_image.getWidth() < global::TOPVIEW_IMAGE_WIDTH ) || ( i_image.getHeight() < global::TOPVIEW_IMAGE_HEIGHT ) )
            {
#ifdef WIN_2015_CODE
                assert( 0 );
#else
                Assert( 0 );
#endif
            }

            // --- Check that the size of the destination images fits with the parameters
            if( ( o_image.getWidth() < i_topViewParams.width ) || ( o_image.getHeight() < i_topViewParams.height ) )
            {
#ifdef WIN_2015_CODE
                assert( 0 );
#else
                Assert( 0 );
#endif
            }
            else
            {
                o_image.setWidth( m_warpedTopViewParams.width );
                o_image.setHeight( m_warpedTopViewParams.height );
            }

#ifdef DIAGNOSTICS
            diag::start( "WarpImage (2)" );
#endif
            uint32_t start_radius = i_topViewParams.yOffset;
            uint32_t end_radius = i_topViewParams.yOffset + i_topViewParams.height;
            float32_t start_deg = i_topViewParams.start_deg;
            float32_t end_deg = i_topViewParams.start_deg + i_topViewParams.range_deg;
            float32_t inc_deg = i_topViewParams.degreesPerPixel;
            //
            _iterator::RowIterator<T> dst_row = o_image.row( 0 );
            _iterator::ColumnIterator<T> dst_col = o_image.col( 0 );

            for( uint32_t r = start_radius; r < end_radius; r++ )
            {
                dst_col = 0;
                float32_t angle = start_deg;
                bool_t angleGreaterThanEnd = ( angle > end_deg );

                while( angleGreaterThanEnd )
                {
                    float32_t angle_rad = static_cast<float32_t>( mecl::math::toRadians_x( angle ) );
                    int32_t x = i_hitchPoint.x + static_cast <int32_t>( static_cast <float32_t>( r ) * cos( angle_rad ) + 0.5f );
                    int32_t y = i_hitchPoint.y + static_cast <int32_t>( static_cast <float32_t>( r ) * sin( angle_rad ) + 0.5f );

                    if( ( 0 <= x ) && ( x < static_cast <int32_t>( i_image.getWidth() ) ) && ( 0 <= y ) && ( y < static_cast <int32_t>( i_image.getHeight() ) ) )
                    {
                        *o_image.at( dst_row, dst_col ) = *i_image.at( x, y );
                    }
                    else
                    {
                        *o_image.at( dst_row, dst_col ) = T();
                    }

                    angle -= inc_deg;
                    ++dst_col;
                    angleGreaterThanEnd = ( angle > end_deg );
                }

                ++dst_row;
            }

            o_image.setStart_Deg( i_topViewParams.start_deg );
            o_image.setRange_Deg( i_topViewParams.range_deg );
            o_image.setDegreesPixel( i_topViewParams.degreesPerPixel );
#ifdef DIAGNOSTICS
            diag::stop();
#endif
        }

        return;
    }

    /*
    * Create a header file containing the LUT required to warp an image around any given hitchpoint.
    *
    * Used to create 'WarpLUT.h'.
    */
    void PreProcessing::CreateWarpLUTHeader()
    {
#ifdef DIAGNOSTICS
        diag::start( "CreateWarpLUTs" );
#endif
        //
        TAD2::WarpedTopViewParameters warpedTopViewParams;
        warpedTopViewParams.width = 320;
        warpedTopViewParams.height = 75;
        warpedTopViewParams.yOffset = 10;
        warpedTopViewParams.range_deg = -220.0f;
        warpedTopViewParams.start_deg = 90.0f - warpedTopViewParams.range_deg / 2.0f;
        warpedTopViewParams.degreesPerPixel = mecl::math::abs_x( warpedTopViewParams.range_deg ) / static_cast <float32_t>( warpedTopViewParams.width );
        //
#ifdef DIAGNOSTICS
        // --- LUT's
        std::string xString = "int32_t g__warpXLUT[" + std::to_string( warpedTopViewParams.height ) + "][" + std::to_string( static_cast <int32_t>( abs( warpedTopViewParams.range_deg / warpedTopViewParams.degreesPerPixel ) ) ) + "] = { ";
        std::string yString = "int32_t g__warpYLUT[" + std::to_string( warpedTopViewParams.height ) + "][" + std::to_string( static_cast <int32_t>( abs( warpedTopViewParams.range_deg / warpedTopViewParams.degreesPerPixel ) ) ) + "] = { ";
        uint32_t start_radius = warpedTopViewParams.yOffset;
        uint32_t end_radius = warpedTopViewParams.yOffset + warpedTopViewParams.height;
        float32_t start_deg = warpedTopViewParams.start_deg;
        float32_t end_deg = warpedTopViewParams.start_deg + warpedTopViewParams.range_deg;
        float32_t inc_deg = warpedTopViewParams.degreesPerPixel;
        int32_t i = 0;
        int32_t j = 0;

        for( uint32_t r = start_radius; r < end_radius; r++, i++ )
        {
            if( r != start_radius )
            {
                xString += ", ";
                yString += ", ";
            }

            xString += "{ ";
            yString += "{ ";
            j = 0;

            for( float32_t angle = start_deg; angle > end_deg; angle -= inc_deg, j++ )
            {
                float32_t angle_rad = static_cast <float32_t>( mecl::math::toRadians_x( angle ) );
                int32_t x = static_cast <int32_t>( r * cos( angle_rad ) + 0.5f );
                int32_t y = static_cast <int32_t>( r * sin( angle_rad ) + 0.5f );

                if( angle != start_deg )
                {
                    xString += ", ";
                    yString += ", ";
                }

                xString += std::to_string( x );
                yString += std::to_string( y );
            }

            xString += " }";
            yString += " }";
        }

        xString += " };";
        yString += " };";
        //
        // --- Warped topview parameters
        std::string paramsStr = "WarpedTopViewParams g__warpedTopViewParams = { "
                                + std::to_string( warpedTopViewParams.width ) + ", " \
                                + std::to_string( warpedTopViewParams.height ) + ", " \
                                + std::to_string( warpedTopViewParams.yOffset ) + ", " \
                                + std::to_string( warpedTopViewParams.start_deg ) + "f, " \
                                + std::to_string( warpedTopViewParams.range_deg ) + "f, " \
                                + std::to_string( warpedTopViewParams.degreesPerPixel ) + "f };";
        fo::filestream f = fo::getFileStream( "TAD\\WarpLUT.h" );
        f << xString << '\n';
        f << yString << '\n';
        f << paramsStr << '\n';
        f.close();
#ifdef DIAGNOSTICS
        diag::stop();
#endif
#endif
    }

    /*
    * Create an LUT to warp an image around the given hitchpoint.
    */


    /*
    * Return whether or not the currently stored LUTs are valid.
    */
    bool_t PreProcessing::WarpLUTsValid()const
    {
        return ( ( m_warpXLUT_s16.getData() != NULL ) && ( m_warpYLUT_s16.getData() != NULL ) );
    }

    /*
    * Get the pre-processed topview created by calling 'Run()'.
    */
    image::Image<uint8_t> PreProcessing::GetWorkingTopView()const
    {
        return m_topView_u8;
    }
    /*
    * Perform a 3x3 Average on the given image.
    */
    void PreProcessing::_Average3x3( image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView )

    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _Blur3x3" );
#endif
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + 1;  //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + 1;  //PRQA S 3705
        uint8_t* dst_ptr;
        uint8_t* src_ptr0;
        uint8_t* src_ptr1;
        uint8_t* src_ptr2;
        uint8_t* src_ptr3;
        uint8_t* src_ptr4;
        uint8_t* src_ptr5;
        uint8_t* src_ptr6;
        uint8_t* src_ptr7;
        uint8_t* src_ptr8;
        uint32_t sum;

        for( uint32_t y = 2; y < ( i_topView.getHeight() - 1 ); ++y )
        {
            dst_ptr = dst_row;
            src_ptr0 = src_row - src_step - 1;  /* PRQA S 3705*/
            src_ptr1 = src_row - src_step;  /* PRQA S 3705*/
            src_ptr2 = src_row - src_step + 1;  /* PRQA S 3705*/
            src_ptr3 = src_row - 1; /* PRQA S 3705*/
            src_ptr4 = src_row;
            src_ptr5 = src_row + 1; /* PRQA S 3705*/
            src_ptr6 = src_row + src_step - 1;  /* PRQA S 3705*/
            src_ptr7 = src_row + src_step;  /* PRQA S 3705*/
            src_ptr8 = src_row + src_step + 1;  /* PRQA S 3705*/

            for( uint32_t x = 2; x < ( i_topView.getWidth() - 1 ); ++x )
            {
                sum = ( *src_ptr0 ) + \
                      ( *src_ptr1 ) + \
                      ( *src_ptr2 ) + \
                      ( *src_ptr3 ) + \
                      ( *src_ptr4 ) + \
                      ( *src_ptr5 ) + \
                      ( *src_ptr6 ) + \
                      ( *src_ptr7 ) + \
                      ( *src_ptr8 );
                *dst_ptr = static_cast <uint8_t>( sum / 9 );
                ++dst_ptr;
                ++src_ptr0;
                ++src_ptr1;
                ++src_ptr2;
                ++src_ptr3;
                ++src_ptr4;
                ++src_ptr5;
                ++src_ptr6;
                ++src_ptr7;
                ++src_ptr8;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Perform a 5x5 Average on the given image.
    */
    void PreProcessing::_Average5x5( image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _Blur3x3" );
#endif
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + dst_step + 2;   //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + src_step + 2;   //PRQA S 3705
        uint8_t* dst_ptr;
        uint8_t* src_ptr0;
        uint8_t* src_ptr1;
        uint8_t* src_ptr2;
        uint8_t* src_ptr3;
        uint8_t* src_ptr4;
        uint8_t* src_ptr5;
        uint8_t* src_ptr6;
        uint8_t* src_ptr7;
        uint8_t* src_ptr8;
        uint8_t* src_ptr9;
        uint8_t* src_ptr10;
        uint8_t* src_ptr11;
        uint8_t* src_ptr12;
        uint8_t* src_ptr13;
        uint8_t* src_ptr14;
        uint8_t* src_ptr15;
        uint8_t* src_ptr16;
        uint8_t* src_ptr17;
        uint8_t* src_ptr18;
        uint8_t* src_ptr19;
        uint8_t* src_ptr20;
        uint8_t* src_ptr21;
        uint8_t* src_ptr22;
        uint8_t* src_ptr23;
        uint8_t* src_ptr24;
        uint32_t sum;

        for( uint32_t y = 2; y < ( i_topView.getHeight() - 1 ); ++y )
        {
            dst_ptr = dst_row;
            src_ptr0 = src_row - src_step - src_step - 2;   //PRQA S 3705
            src_ptr1 = src_row - src_step - src_step - 1;   //PRQA S 3705
            src_ptr2 = src_row - src_step - src_step;       //PRQA S 3705
            src_ptr3 = src_row - src_step - src_step + 1;   //PRQA S 3705
            src_ptr4 = src_row - src_step - src_step + 2;   //PRQA S 3705
            src_ptr5 = src_row - src_step - 2;  //PRQA S 3705
            src_ptr6 = src_row - src_step - 1;  //PRQA S 3705
            src_ptr7 = src_row - src_step;      //PRQA S 3705
            src_ptr8 = src_row - src_step + 1;  //PRQA S 3705
            src_ptr9 = src_row - src_step + 2;  //PRQA S 3705
            src_ptr10 = src_row - 2;            //PRQA S 3705
            src_ptr11 = src_row - 1;            //PRQA S 3705
            src_ptr12 = src_row;
            src_ptr13 = src_row + 1;            //PRQA S 3705
            src_ptr14 = src_row + 2;            //PRQA S 3705
            src_ptr15 = src_row + src_step - 2; //PRQA S 3705
            src_ptr16 = src_row + src_step - 1; //PRQA S 3705
            src_ptr17 = src_row + src_step;     //PRQA S 3705
            src_ptr18 = src_row + src_step + 1; //PRQA S 3705
            src_ptr19 = src_row + src_step + 2; //PRQA S 3705
            src_ptr20 = src_row + src_step + src_step - 2;  //PRQA S 3705
            src_ptr21 = src_row + src_step + src_step - 1;  //PRQA S 3705
            src_ptr22 = src_row + src_step + src_step;      //PRQA S 3705
            src_ptr23 = src_row + src_step + src_step + 1;  //PRQA S 3705
            src_ptr24 = src_row + src_step + src_step + 2;  //PRQA S 3705

            for( uint32_t x = 2; x < ( i_topView.getWidth() - 1 ); ++x )
            {
                sum = ( *src_ptr0 ) + \
                      ( *src_ptr1 ) + \
                      ( *src_ptr2 ) + \
                      ( *src_ptr3 ) + \
                      ( *src_ptr4 ) + \
                      ( *src_ptr5 ) + \
                      ( *src_ptr6 ) + \
                      ( *src_ptr7 ) + \
                      ( *src_ptr8 ) + \
                      ( *src_ptr9 ) + \
                      ( *src_ptr10 ) + \
                      ( *src_ptr11 ) + \
                      ( *src_ptr12 ) + \
                      ( *src_ptr13 ) + \
                      ( *src_ptr14 ) + \
                      ( *src_ptr15 ) + \
                      ( *src_ptr16 ) + \
                      ( *src_ptr17 ) + \
                      ( *src_ptr18 ) + \
                      ( *src_ptr19 ) + \
                      ( *src_ptr20 ) + \
                      ( *src_ptr21 ) + \
                      ( *src_ptr22 ) + \
                      ( *src_ptr23 ) + \
                      ( *src_ptr24 );
                *dst_ptr = static_cast <uint8_t>( sum / 25 );
                ++dst_ptr;
                ++src_ptr0;
                ++src_ptr1;
                ++src_ptr2;
                ++src_ptr3;
                ++src_ptr4;
                ++src_ptr5;
                ++src_ptr6;
                ++src_ptr7;
                ++src_ptr8;
                ++src_ptr9;
                ++src_ptr10;
                ++src_ptr11;
                ++src_ptr12;
                ++src_ptr13;
                ++src_ptr14;
                ++src_ptr15;
                ++src_ptr16;
                ++src_ptr17;
                ++src_ptr18;
                ++src_ptr19;
                ++src_ptr20;
                ++src_ptr21;
                ++src_ptr22;
                ++src_ptr23;
                ++src_ptr24;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Perform a 3x3 Gaussian blur on the given image.
    */
    void PreProcessing::_Blur3x3( const image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _Blur3x3" );
#endif
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + 1;  //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + 1;  //PRQA S 3705
        uint8_t* dst_ptr;
        uint8_t* src_ptr0;
        uint8_t* src_ptr1;
        uint8_t* src_ptr2;
        uint8_t* src_ptr3;
        uint8_t* src_ptr4;
        uint8_t* src_ptr5;
        uint8_t* src_ptr6;
        uint8_t* src_ptr7;
        uint8_t* src_ptr8;
        uint32_t sum;

        for( uint32_t y = 2; y < ( i_topView.getHeight() - 1 ); ++y )
        {
            dst_ptr = dst_row;
            src_ptr0 = src_row - src_step - 1;  /* PRQA S 3705*/
            src_ptr1 = src_row - src_step;  /* PRQA S 3705*/
            src_ptr2 = src_row - src_step + 1;  /* PRQA S 3705*/
            src_ptr3 = src_row - 1; /* PRQA S 3705*/
            src_ptr4 = src_row;
            src_ptr5 = src_row + 1; /* PRQA S 3705*/
            src_ptr6 = src_row + src_step - 1;  /* PRQA S 3705*/
            src_ptr7 = src_row + src_step;  /* PRQA S 3705*/
            src_ptr8 = src_row + src_step + 1;  /* PRQA S 3705*/

            for( uint32_t x = 2; x < ( i_topView.getWidth() - 1 ); ++x )
            {
                sum = ( *src_ptr0 ) + \
                      2 * ( *src_ptr1 ) + \
                      ( *src_ptr2 ) + \
                      2 * ( *src_ptr3 ) + \
                      4 * ( *src_ptr4 ) + \
                      2 * ( *src_ptr5 ) + \
                      ( *src_ptr6 ) + \
                      2 * ( *src_ptr7 ) + \
                      ( *src_ptr8 );
                *dst_ptr = static_cast <uint8_t>( sum / 16 );
                ++dst_ptr;
                ++src_ptr0;
                ++src_ptr1;
                ++src_ptr2;
                ++src_ptr3;
                ++src_ptr4;
                ++src_ptr5;
                ++src_ptr6;
                ++src_ptr7;
                ++src_ptr8;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }

    /*
    * Perform a 5x5 Gaussian blur on the given image.
    */
    void PreProcessing::_Blur5x5( const image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _Blur5x5" );
#endif
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + dst_step + 2;   //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + src_step + 2;   //PRQA S 3705
        uint8_t* dst_ptr;
        uint8_t* src_ptr0;
        uint8_t* src_ptr1;
        uint8_t* src_ptr2;
        uint8_t* src_ptr3;
        uint8_t* src_ptr4;
        uint8_t* src_ptr5;
        uint8_t* src_ptr6;
        uint8_t* src_ptr7;
        uint8_t* src_ptr8;
        uint8_t* src_ptr9;
        uint8_t* src_ptr10;
        uint8_t* src_ptr11;
        uint8_t* src_ptr12;
        uint8_t* src_ptr13;
        uint8_t* src_ptr14;
        uint8_t* src_ptr15;
        uint8_t* src_ptr16;
        uint8_t* src_ptr17;
        uint8_t* src_ptr18;
        uint8_t* src_ptr19;
        uint8_t* src_ptr20;
        uint8_t* src_ptr21;
        uint8_t* src_ptr22;
        uint8_t* src_ptr23;
        uint8_t* src_ptr24;
        uint32_t sum;

        for( uint32_t y = 2; y < ( i_topView.getHeight() - 2 ); ++y )
        {
            dst_ptr = dst_row;
            src_ptr0 = src_row - src_step - src_step - 2;   //PRQA S 3705
            src_ptr1 = src_row - src_step - src_step - 1;   //PRQA S 3705
            src_ptr2 = src_row - src_step - src_step;       //PRQA S 3705
            src_ptr3 = src_row - src_step - src_step + 1;   //PRQA S 3705
            src_ptr4 = src_row - src_step - src_step + 2;   //PRQA S 3705
            src_ptr5 = src_row - src_step - 2;  //PRQA S 3705
            src_ptr6 = src_row - src_step - 1;  //PRQA S 3705
            src_ptr7 = src_row - src_step;      //PRQA S 3705
            src_ptr8 = src_row - src_step + 1;  //PRQA S 3705
            src_ptr9 = src_row - src_step + 2;  //PRQA S 3705
            src_ptr10 = src_row - 2;            //PRQA S 3705
            src_ptr11 = src_row - 1;            //PRQA S 3705
            src_ptr12 = src_row;
            src_ptr13 = src_row + 1;            //PRQA S 3705
            src_ptr14 = src_row + 2;            //PRQA S 3705
            src_ptr15 = src_row + src_step - 2; //PRQA S 3705
            src_ptr16 = src_row + src_step - 1; //PRQA S 3705
            src_ptr17 = src_row + src_step;     //PRQA S 3705
            src_ptr18 = src_row + src_step + 1; //PRQA S 3705
            src_ptr19 = src_row + src_step + 2; //PRQA S 3705
            src_ptr20 = src_row + src_step + src_step - 2;  //PRQA S 3705
            src_ptr21 = src_row + src_step + src_step - 1;  //PRQA S 3705
            src_ptr22 = src_row + src_step + src_step;      //PRQA S 3705
            src_ptr23 = src_row + src_step + src_step + 1;  //PRQA S 3705
            src_ptr24 = src_row + src_step + src_step + 2;  //PRQA S 3705

            for( uint32_t x = 2; x < ( i_topView.getWidth() - 2 ); ++x )
            {
                sum = ( *src_ptr0 ) + \
                      4 * ( *src_ptr1 ) + \
                      7 * ( *src_ptr2 ) + \
                      4 * ( *src_ptr3 ) + \
                      ( *src_ptr4 ) + \
                      4 * ( *src_ptr5 ) + \
                      16 * ( *src_ptr6 ) + \
                      26 * ( *src_ptr7 ) + \
                      16 * ( *src_ptr8 ) + \
                      4 * ( *src_ptr9 ) + \
                      7 * ( *src_ptr10 ) + \
                      26 * ( *src_ptr11 ) + \
                      41 * ( *src_ptr12 ) + \
                      26 * ( *src_ptr13 ) + \
                      7 * ( *src_ptr14 ) + \
                      4 * ( *src_ptr15 ) + \
                      16 * ( *src_ptr16 ) + \
                      26 * ( *src_ptr17 ) + \
                      16 * ( *src_ptr18 ) + \
                      4 * ( *src_ptr19 ) + \
                      ( *src_ptr20 ) + \
                      4 * ( *src_ptr21 ) + \
                      7 * ( *src_ptr22 ) + \
                      4 * ( *src_ptr23 ) + \
                      ( *src_ptr24 );
                *dst_ptr = static_cast <uint8_t>( sum / 273 );
                ++dst_ptr;
                ++src_ptr0;
                ++src_ptr1;
                ++src_ptr2;
                ++src_ptr3;
                ++src_ptr4;
                ++src_ptr5;
                ++src_ptr6;
                ++src_ptr7;
                ++src_ptr8;
                ++src_ptr9;
                ++src_ptr10;
                ++src_ptr11;
                ++src_ptr12;
                ++src_ptr13;
                ++src_ptr14;
                ++src_ptr15;
                ++src_ptr16;
                ++src_ptr17;
                ++src_ptr18;
                ++src_ptr19;
                ++src_ptr20;
                ++src_ptr21;
                ++src_ptr22;
                ++src_ptr23;
                ++src_ptr24;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Perform a 3x3 Dilation on the given image.
    */
    void PreProcessing::_ROI3x3( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _ROI3x3" );
#endif
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + 1;  //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + 1;  //PRQA S 3705
        uint8_t* dst_ptr0;
        uint8_t* dst_ptr1;
        uint8_t* dst_ptr2;
        uint8_t* dst_ptr3;
        uint8_t* dst_ptr4;
        uint8_t* dst_ptr5;
        uint8_t* dst_ptr6;
        uint8_t* dst_ptr7;
        uint8_t* dst_ptr8;
        uint8_t* src_ptr;
        uint32_t sum;

        for( uint32_t y = 1; y < ( i_topView.getHeight() - 1 ); ++y )
        {
            src_ptr = src_row;
            dst_ptr0 = dst_row - dst_step - 1;  /* PRQA S 3705*/
            dst_ptr1 = dst_row - dst_step;  /* PRQA S 3705*/
            dst_ptr2 = dst_row - dst_step + 1;  /* PRQA S 3705*/
            dst_ptr3 = dst_row - 1; /* PRQA S 3705*/
            dst_ptr4 = dst_row;
            dst_ptr5 = dst_row + 1; /* PRQA S 3705*/
            dst_ptr6 = dst_row + dst_step - 1;  /* PRQA S 3705*/
            dst_ptr7 = dst_row + dst_step;  /* PRQA S 3705*/
            dst_ptr8 = dst_row + dst_step + 1;  /* PRQA S 3705*/

            for( uint32_t x = 1; x < ( i_topView.getWidth() - 1 ); ++x )
            {
                if( *src_ptr > 0 /*&& mask::TemplateWeightMask[y][x] > 0*/ )
                {
                    int val = *src_ptr;
                    *dst_ptr0 = static_cast <uint8_t>( 255 );
                    *dst_ptr1 = static_cast <uint8_t>( 255 );
                    *dst_ptr2 = static_cast <uint8_t>( 255 );
                    *dst_ptr3 = static_cast <uint8_t>( 255 );
                    *dst_ptr4 = static_cast <uint8_t>( 255 );
                    *dst_ptr5 = static_cast <uint8_t>( 255 );
                    *dst_ptr6 = static_cast <uint8_t>( 255 );
                    *dst_ptr7 = static_cast <uint8_t>( 255 );
                    *dst_ptr8 = static_cast <uint8_t>( 255 );
                }

                ++src_ptr;
                ++dst_ptr0;
                ++dst_ptr1;
                ++dst_ptr2;
                ++dst_ptr3;
                ++dst_ptr4;
                ++dst_ptr5;
                ++dst_ptr6;
                ++dst_ptr7;
                ++dst_ptr8;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Perform a 3x3 Dilation on the given image.
    */
    void PreProcessing::_ROI5x5( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _ROI3x3" );
#endif
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + dst_step + 2;  //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + src_step + 2;  //PRQA S 3705
        //uint8_t* dst_ptr0;
        //uint8_t* dst_ptr1;
        uint8_t* dst_ptr2;
        //uint8_t* dst_ptr3;
        //uint8_t* dst_ptr4;
        //uint8_t* dst_ptr5;
        //uint8_t* dst_ptr6;
        uint8_t* dst_ptr7;
        //uint8_t* dst_ptr8;
        //uint8_t* dst_ptr9;
        uint8_t* dst_ptr10;
        uint8_t* dst_ptr11;
        uint8_t* dst_ptr12;
        uint8_t* dst_ptr13;
        uint8_t* dst_ptr14;
        //uint8_t* dst_ptr15;
        //uint8_t* dst_ptr16;
        uint8_t* dst_ptr17;
        //uint8_t* dst_ptr18;
        //uint8_t* dst_ptr19;
        //uint8_t* dst_ptr20;
        //uint8_t* dst_ptr21;
        uint8_t* dst_ptr22;
        //uint8_t* dst_ptr23;
        //uint8_t* dst_ptr24;
        uint8_t* src_ptr;
        uint32_t sum;

        for( uint32_t y = 2; y < ( i_topView.getHeight() - 2 ); ++y )
        {
            src_ptr = src_row;
            //dst_ptr0 = dst_row - dst_step - dst_step - 2;   //PRQA S 3705
            //dst_ptr1 = dst_row - dst_step - dst_step - 1;   //PRQA S 3705
            dst_ptr2 = dst_row - dst_step - dst_step;       //PRQA S 3705
            //dst_ptr3 = dst_row - dst_step - dst_step + 1;   //PRQA S 3705
            //dst_ptr4 = dst_row - dst_step - dst_step + 2;   //PRQA S 3705
            //dst_ptr5 = dst_row - dst_step - 2;  //PRQA S 3705
            //dst_ptr6 = dst_row - dst_step - 1;  //PRQA S 3705
            dst_ptr7 = dst_row - dst_step;      //PRQA S 3705
            //dst_ptr8 = dst_row - dst_step + 1;  //PRQA S 3705
            //dst_ptr9 = dst_row - dst_step + 2;  //PRQA S 3705
            dst_ptr10 = dst_row - 2;            //PRQA S 3705
            dst_ptr11 = dst_row - 1;            //PRQA S 3705
            dst_ptr12 = dst_row;
            dst_ptr13 = dst_row + 1;            //PRQA S 3705
            dst_ptr14 = dst_row + 2;            //PRQA S 3705
            //dst_ptr15 = dst_row + dst_step - 2; //PRQA S 3705
            //dst_ptr16 = dst_row + dst_step - 1; //PRQA S 3705
            dst_ptr17 = dst_row + dst_step;     //PRQA S 3705
            //dst_ptr18 = dst_row + dst_step + 1; //PRQA S 3705
            //dst_ptr19 = dst_row + dst_step + 2; //PRQA S 3705
            //dst_ptr20 = dst_row + dst_step + dst_step - 2;  //PRQA S 3705
            //dst_ptr21 = dst_row + dst_step + dst_step - 1;  //PRQA S 3705
            dst_ptr22 = dst_row + dst_step + dst_step;      //PRQA S 3705
            //dst_ptr23 = dst_row + dst_step + dst_step + 1;  //PRQA S 3705
            //dst_ptr24 = dst_row + dst_step + dst_step + 2;  //PRQA S 3705

            for( uint32_t x = 1; x < ( i_topView.getWidth() - 1 ); ++x )
            {
                if( *src_ptr > 0 && mask::TemplateWeightMask[y][x] > 0 )
                {
                    int val = *src_ptr;
                    //*dst_ptr0 = static_cast <uint8_t>( 255 );
                    //*dst_ptr1 = static_cast <uint8_t>( 255 );
                    *dst_ptr2 = static_cast <uint8_t>( 255 );
                    //*dst_ptr3 = static_cast <uint8_t>( 255 );
                    //*dst_ptr4 = static_cast <uint8_t>( 255 );
                    //*dst_ptr5 = static_cast <uint8_t>( 255 );
                    //*dst_ptr6 = static_cast <uint8_t>( 255 );
                    *dst_ptr7 = static_cast <uint8_t>( 255 );
                    //*dst_ptr8 = static_cast <uint8_t>( 255 );
                    //*dst_ptr9 = static_cast <uint8_t>( 255 );
                    *dst_ptr10 = static_cast <uint8_t>( 255 );
                    *dst_ptr11 = static_cast <uint8_t>( 255 );
                    *dst_ptr12 = static_cast <uint8_t>( 255 );
                    *dst_ptr13 = static_cast <uint8_t>( 255 );
                    *dst_ptr14 = static_cast <uint8_t>( 255 );
                    //*dst_ptr15 = static_cast <uint8_t>( 255 );
                    //*dst_ptr16 = static_cast <uint8_t>( 255 );
                    *dst_ptr17 = static_cast <uint8_t>( 255 );
                    //*dst_ptr18 = static_cast <uint8_t>( 255 );
                    //*dst_ptr19 = static_cast <uint8_t>( 255 );
                    //*dst_ptr20 = static_cast <uint8_t>( 255 );
                    //*dst_ptr21 = static_cast <uint8_t>( 255 );
                    *dst_ptr22 = static_cast <uint8_t>( 255 );
                    //*dst_ptr23 = static_cast <uint8_t>( 255 );
                    //*dst_ptr24 = static_cast <uint8_t>( 255 );
                }

                ++src_ptr;
                //++dst_ptr0;
                //++dst_ptr1;
                ++dst_ptr2;
                //++dst_ptr3;
                //++dst_ptr4;
                //++dst_ptr5;
                //++dst_ptr6;
                ++dst_ptr7;
                //++dst_ptr8;
                //++dst_ptr9;
                //++dst_ptr10;
                ++dst_ptr11;
                ++dst_ptr12;
                ++dst_ptr13;
                //++dst_ptr14;
                //++dst_ptr15;
                //++dst_ptr16;
                ++dst_ptr17;
                //++dst_ptr18;
                //++dst_ptr19;
                //++dst_ptr20;
                //++dst_ptr21;
                //++dst_ptr22;
                //++dst_ptr23;
                //++dst_ptr24;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Perform a 3x3 Dilation on the given image.
    */
    void PreProcessing::_AvgImg( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _ROI3x3" );
#endif
        float32_t sum = 0;

        for( uint32_t x = 0; x < i_topView.getWidth(); x++ )
        {
            for( uint32_t y = 0; y < i_topView.getHeight(); y++ )
            {
                *o_topView.at( x, y ) = ( *i_topView.at( x, y ) + *o_topView.at( x, y ) ) / 2;
            }
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Perform a 3x3 Erosion on the given image.
    */
    void PreProcessing::_linking3x3( image::Image<uint8_t>& i_topView, uint16_t othsu_thresh )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _erosiom3x3" );
#endif
        //cv::Mat im8 = processing::ImageProcessing::ConvertToCV( i_topView );
        uint32_t src_step = i_topView.getStep();
        uint8_t* src_row = i_topView.getData() + src_step + 1;  //PRQA S 3705
        uint8_t* src_ptr0;
        uint8_t* src_ptr1;
        uint8_t* src_ptr2;
        uint8_t* src_ptr3;
        uint8_t* src_ptr4;
        uint8_t* src_ptr5;
        uint8_t* src_ptr6;
        uint8_t* src_ptr7;
        uint8_t* src_ptr8;
        uint8_t* src_ptr9;
        uint8_t* src_ptr10;
        uint8_t* src_ptr11;
        uint32_t sum;

        for( uint32_t y = 1; y < ( i_topView.getHeight() - 1 ); ++y )
        {
            src_ptr0 = src_row - src_step - 1;  /* PRQA S 3705*/
            src_ptr1 = src_row - src_step;  /* PRQA S 3705*/
            src_ptr2 = src_row - src_step + 1;  /* PRQA S 3705*/
            src_ptr3 = src_row - 1; /* PRQA S 3705*/
            src_ptr4 = src_row;
            src_ptr5 = src_row + 1; /* PRQA S 3705*/
            src_ptr6 = src_row + src_step - 1;  /* PRQA S 3705*/
            src_ptr7 = src_row + src_step;  /* PRQA S 3705*/
            src_ptr8 = src_row + src_step + 1;  /* PRQA S 3705*/
            src_ptr9 = src_row + src_step + src_step - 1;  /* PRQA S 3705*/
            src_ptr10 = src_row + src_step + src_step;  /* PRQA S 3705*/
            src_ptr11 = src_row + src_step + src_step + 1;  /* PRQA S 3705*/

            for( uint32_t x = 1; x < ( i_topView.getWidth() - 1 ); ++x )
            {
                if( *src_ptr4 == 0 )
                {
                    uint8_t top_row = ( *src_ptr0 > 0 ) + ( *src_ptr1 > 0 ) + ( *src_ptr2 > 0 );
                    uint8_t down_row = ( *src_ptr6 > 0 ) + ( *src_ptr7 > 0 ) + ( *src_ptr8 > 0 );
                    uint8_t left_col = ( *src_ptr0 > 0 ) + ( *src_ptr3 > 0 ) + ( *src_ptr6 > 0 );
                    uint8_t right_col = ( *src_ptr2 > 0 ) + ( *src_ptr5 > 0 ) + ( *src_ptr8 > 0 );
                    uint8_t sum = ( *src_ptr0 > 0 ) + ( *src_ptr1 > 0 ) + ( *src_ptr2 > 0 ) + ( *src_ptr3 > 0 ) + ( *src_ptr5 > 0 ) + ( *src_ptr6 > 0 ) + ( *src_ptr7 > 0 ) + ( *src_ptr8 > 0 );

                    if( ( ( ( ( top_row == 1 ) || ( top_row == 2 ) ) && ( ( down_row == 1 ) || ( down_row == 2 ) ) ) && ( ( left_col != 3 ) && ( right_col != 3 ) ) ) ||
                        ( ( ( ( left_col == 1 ) || ( left_col == 2 ) ) && ( ( right_col == 1 ) || ( right_col == 2 ) ) ) && ( ( top_row != 3 ) && ( down_row != 3 ) ) ) ||
                        ( ( ( top_row == 2 ) && ( down_row == 3 ) ) ) || ( ( ( top_row == 3 ) && ( down_row == 2 ) ) )
                        /*|| ( *src_ptr0 > 0 && *src_ptr0 != 255 && sum == 1 ) || ( *src_ptr2 > 0 && *src_ptr2 != 255 && sum == 1 )*/ )
                    {
                        /*uint32_t sum_val = *src_ptr0 + *src_ptr1 + *src_ptr2 + *src_ptr3 + *src_ptr4 + *src_ptr5 + *src_ptr6 + *src_ptr7 + *src_ptr8;
                        *src_ptr4 = static_cast <uint8_t>( sum_val / 9 );*/
                        *src_ptr4 = static_cast <uint8_t>( 255 );
                    }
                }

                /*if( *src_ptr4 == 0 && *src_ptr7 == 0 )
                {
                    if( ( ( *src_ptr0 > 0 ) && ( *src_ptr11 > 0 ) ) || ( ( *src_ptr2 > 0 ) && ( *src_ptr9 > 0 ) ) )
                    {
                        *src_ptr4 = static_cast <uint8_t>( 255 );
                        *src_ptr7 = static_cast <uint8_t>( 255 );
                    }
                }*/
                ++src_ptr0;
                ++src_ptr1;
                ++src_ptr2;
                ++src_ptr3;
                ++src_ptr4;
                ++src_ptr5;
                ++src_ptr6;
                ++src_ptr7;
                ++src_ptr8;
                ++src_ptr9;
                ++src_ptr10;
                ++src_ptr11;
            }

            src_row += src_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Perform a 3x3 Erosion on the given image.
    */
    void PreProcessing::_erosiom3x3( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _erosiom3x3" );
#endif
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + 1;  //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + 1;  //PRQA S 3705
        uint8_t* dst_ptr;
        uint8_t* src_ptr0;
        uint8_t* src_ptr1;
        uint8_t* src_ptr2;
        uint8_t* src_ptr3;
        uint8_t* src_ptr4;
        uint8_t* src_ptr5;
        uint8_t* src_ptr6;
        uint8_t* src_ptr7;
        uint8_t* src_ptr8;
        uint32_t sum;

        for( uint32_t y = 2; y < ( i_topView.getHeight() - 1 ); ++y )
        {
            dst_ptr = dst_row;
            src_ptr0 = src_row - src_step - 1;  /* PRQA S 3705*/
            src_ptr1 = src_row - src_step;  /* PRQA S 3705*/
            src_ptr2 = src_row - src_step + 1;  /* PRQA S 3705*/
            src_ptr3 = src_row - 1; /* PRQA S 3705*/
            src_ptr4 = src_row;
            src_ptr5 = src_row + 1; /* PRQA S 3705*/
            src_ptr6 = src_row + src_step - 1;  /* PRQA S 3705*/
            src_ptr7 = src_row + src_step;  /* PRQA S 3705*/
            src_ptr8 = src_row + src_step + 1;  /* PRQA S 3705*/

            for( uint32_t x = 1; x < ( i_topView.getWidth() - 1 ); ++x )
            {
                if( ( *src_ptr0 > 0 ) && ( *src_ptr1 > 0 ) && ( *src_ptr2 > 0 ) && ( *src_ptr3 > 0 ) && ( *src_ptr4 > 0 ) && ( *src_ptr5 > 0 )
                    && ( *src_ptr6 > 0 ) && ( *src_ptr7 > 0 ) && ( *src_ptr8 > 0 ) )
                {
                    *dst_ptr = static_cast <uint8_t>( 255 );
                }

                ++dst_ptr;
                ++src_ptr0;
                ++src_ptr1;
                ++src_ptr2;
                ++src_ptr3;
                ++src_ptr4;
                ++src_ptr5;
                ++src_ptr6;
                ++src_ptr7;
                ++src_ptr8;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Perform a 3x3 Dilation on the given image.
    */
    void PreProcessing::_dilation3x3( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _dilation3x3" );
#endif
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + 1;  //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + 1;  //PRQA S 3705
        uint8_t* src_ptr;
        uint8_t* dst_ptr0;
        uint8_t* dst_ptr1;
        uint8_t* dst_ptr2;
        uint8_t* dst_ptr3;
        uint8_t* dst_ptr4;
        uint8_t* dst_ptr5;
        uint8_t* dst_ptr6;
        uint8_t* dst_ptr7;
        uint8_t* dst_ptr8;
        uint32_t sum;

        for( uint32_t y = 1; y < ( i_topView.getHeight() - 1 ); ++y )
        {
            src_ptr = src_row;
            dst_ptr0 = dst_row - dst_step - 1;  /* PRQA S 3705*/
            dst_ptr1 = dst_row - dst_step;  /* PRQA S 3705*/
            dst_ptr2 = dst_row - dst_step + 1;  /* PRQA S 3705*/
            dst_ptr3 = dst_row - 1; /* PRQA S 3705*/
            dst_ptr4 = dst_row;
            dst_ptr5 = dst_row + 1; /* PRQA S 3705*/
            dst_ptr6 = dst_row + dst_step - 1;  /* PRQA S 3705*/
            dst_ptr7 = dst_row + dst_step;  /* PRQA S 3705*/
            dst_ptr8 = dst_row + dst_step + 1;  /* PRQA S 3705*/

            for( uint32_t x = 1; x < ( i_topView.getWidth() - 1 ); ++x )
            {
                if( *src_ptr > 0 )
                {
                    *dst_ptr0 = static_cast <uint8_t>( 255 );
                    *dst_ptr1 = static_cast <uint8_t>( 255 );
                    *dst_ptr2 = static_cast <uint8_t>( 255 );
                    *dst_ptr3 = static_cast <uint8_t>( 255 );
                    *dst_ptr4 = static_cast <uint8_t>( 255 );
                    *dst_ptr5 = static_cast <uint8_t>( 255 );
                    *dst_ptr6 = static_cast <uint8_t>( 255 );
                    *dst_ptr7 = static_cast <uint8_t>( 255 );
                    *dst_ptr8 = static_cast <uint8_t>( 255 );
                }

                ++src_ptr;
                ++dst_ptr0;
                ++dst_ptr1;
                ++dst_ptr2;
                ++dst_ptr3;
                ++dst_ptr4;
                ++dst_ptr5;
                ++dst_ptr6;
                ++dst_ptr7;
                ++dst_ptr8;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * '_dilation5x5()'.
    */
    void PreProcessing::_dilation5x5( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _dilation" );
#endif
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + dst_step + 2;   //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + src_step + 2;   //PRQA S 3705
        uint8_t* dst_ptr;
        uint8_t* src_ptr0;
        uint8_t* src_ptr1;
        uint8_t* src_ptr2;
        uint8_t* src_ptr3;
        uint8_t* src_ptr4;
        uint8_t* src_ptr5;
        uint8_t* src_ptr6;
        uint8_t* src_ptr7;
        uint8_t* src_ptr8;
        uint8_t* src_ptr9;
        uint8_t* src_ptr10;
        uint8_t* src_ptr11;
        uint8_t* src_ptr12;
        uint8_t* src_ptr13;
        uint8_t* src_ptr14;
        uint8_t* src_ptr15;
        uint8_t* src_ptr16;
        uint8_t* src_ptr17;
        uint8_t* src_ptr18;
        uint8_t* src_ptr19;
        uint8_t* src_ptr20;
        uint8_t* src_ptr21;
        uint8_t* src_ptr22;
        uint8_t* src_ptr23;
        uint8_t* src_ptr24;
        uint32_t sum;

        for( uint32_t y = 2; y < ( i_topView.getHeight() - 2 ); ++y )
        {
            dst_ptr = dst_row;
            src_ptr0 = src_row - src_step - src_step - 2;   //PRQA S 3705
            src_ptr1 = src_row - src_step - src_step - 1;   //PRQA S 3705
            src_ptr2 = src_row - src_step - src_step;       //PRQA S 3705
            src_ptr3 = src_row - src_step - src_step + 1;   //PRQA S 3705
            src_ptr4 = src_row - src_step - src_step + 2;   //PRQA S 3705
            src_ptr5 = src_row - src_step - 2;  //PRQA S 3705
            src_ptr6 = src_row - src_step - 1;  //PRQA S 3705
            src_ptr7 = src_row - src_step;      //PRQA S 3705
            src_ptr8 = src_row - src_step + 1;  //PRQA S 3705
            src_ptr9 = src_row - src_step + 2;  //PRQA S 3705
            src_ptr10 = src_row - 2;            //PRQA S 3705
            src_ptr11 = src_row - 1;            //PRQA S 3705
            src_ptr12 = src_row;
            src_ptr13 = src_row + 1;            //PRQA S 3705
            src_ptr14 = src_row + 2;            //PRQA S 3705
            src_ptr15 = src_row + src_step - 2; //PRQA S 3705
            src_ptr16 = src_row + src_step - 1; //PRQA S 3705
            src_ptr17 = src_row + src_step;     //PRQA S 3705
            src_ptr18 = src_row + src_step + 1; //PRQA S 3705
            src_ptr19 = src_row + src_step + 2; //PRQA S 3705
            src_ptr20 = src_row + src_step + src_step - 2;  //PRQA S 3705
            src_ptr21 = src_row + src_step + src_step - 1;  //PRQA S 3705
            src_ptr22 = src_row + src_step + src_step;      //PRQA S 3705
            src_ptr23 = src_row + src_step + src_step + 1;  //PRQA S 3705
            src_ptr24 = src_row + src_step + src_step + 2;  //PRQA S 3705

            for( uint32_t x = 2; x < ( i_topView.getWidth() - 2 ); ++x )
            {
                if( ( *src_ptr0 > 0 ) || ( *src_ptr1 > 0 ) || ( *src_ptr2 > 0 ) || ( *src_ptr3 > 0 ) || ( *src_ptr4 > 0 ) || ( *src_ptr5 > 0 )
                    || ( *src_ptr6 > 0 ) || ( *src_ptr7 > 0 ) || ( *src_ptr8 > 0 ) || ( *src_ptr9 > 0 ) || ( *src_ptr10 > 0 ) || ( *src_ptr11 > 0 )
                    || ( *src_ptr12 > 0 ) || ( *src_ptr13 > 0 ) || ( *src_ptr14 > 0 ) || ( *src_ptr15 > 0 ) || ( *src_ptr16 > 0 ) || ( *src_ptr17 > 0 )
                    || ( *src_ptr18 > 0 ) || ( *src_ptr19 > 0 ) || ( *src_ptr20 > 0 ) || ( *src_ptr21 > 0 ) || ( *src_ptr22 > 0 ) || ( *src_ptr23 > 0 ) || ( *src_ptr24 > 0 ) )
                {
                    *dst_ptr = static_cast <uint8_t>( 255 );
                }

                ++dst_ptr;
                ++src_ptr0;
                ++src_ptr1;
                ++src_ptr2;
                ++src_ptr3;
                ++src_ptr4;
                ++src_ptr5;
                ++src_ptr6;
                ++src_ptr7;
                ++src_ptr8;
                ++src_ptr9;
                ++src_ptr10;
                ++src_ptr11;
                ++src_ptr12;
                ++src_ptr13;
                ++src_ptr14;
                ++src_ptr15;
                ++src_ptr16;
                ++src_ptr17;
                ++src_ptr18;
                ++src_ptr19;
                ++src_ptr20;
                ++src_ptr21;
                ++src_ptr22;
                ++src_ptr23;
                ++src_ptr24;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * '_dilation5x5()'.
    */
    void PreProcessing::_erosion5x5( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _erosion" );
#endif
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + dst_step + 2;   //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + src_step + 2;   //PRQA S 3705
        uint8_t* dst_ptr;
        uint8_t* src_ptr0;
        uint8_t* src_ptr1;
        uint8_t* src_ptr2;
        uint8_t* src_ptr3;
        uint8_t* src_ptr4;
        uint8_t* src_ptr5;
        uint8_t* src_ptr6;
        uint8_t* src_ptr7;
        uint8_t* src_ptr8;
        uint8_t* src_ptr9;
        uint8_t* src_ptr10;
        uint8_t* src_ptr11;
        uint8_t* src_ptr12;
        uint8_t* src_ptr13;
        uint8_t* src_ptr14;
        uint8_t* src_ptr15;
        uint8_t* src_ptr16;
        uint8_t* src_ptr17;
        uint8_t* src_ptr18;
        uint8_t* src_ptr19;
        uint8_t* src_ptr20;
        uint8_t* src_ptr21;
        uint8_t* src_ptr22;
        uint8_t* src_ptr23;
        uint8_t* src_ptr24;
        uint32_t sum;

        for( uint32_t y = 2; y < ( i_topView.getHeight() - 2 ); ++y )
        {
            dst_ptr = dst_row;
            src_ptr0 = src_row - src_step - src_step - 2;   //PRQA S 3705
            src_ptr1 = src_row - src_step - src_step - 1;   //PRQA S 3705
            src_ptr2 = src_row - src_step - src_step;       //PRQA S 3705
            src_ptr3 = src_row - src_step - src_step + 1;   //PRQA S 3705
            src_ptr4 = src_row - src_step - src_step + 2;   //PRQA S 3705
            src_ptr5 = src_row - src_step - 2;  //PRQA S 3705
            src_ptr6 = src_row - src_step - 1;  //PRQA S 3705
            src_ptr7 = src_row - src_step;      //PRQA S 3705
            src_ptr8 = src_row - src_step + 1;  //PRQA S 3705
            src_ptr9 = src_row - src_step + 2;  //PRQA S 3705
            src_ptr10 = src_row - 2;            //PRQA S 3705
            src_ptr11 = src_row - 1;            //PRQA S 3705
            src_ptr12 = src_row;
            src_ptr13 = src_row + 1;            //PRQA S 3705
            src_ptr14 = src_row + 2;            //PRQA S 3705
            src_ptr15 = src_row + src_step - 2; //PRQA S 3705
            src_ptr16 = src_row + src_step - 1; //PRQA S 3705
            src_ptr17 = src_row + src_step;     //PRQA S 3705
            src_ptr18 = src_row + src_step + 1; //PRQA S 3705
            src_ptr19 = src_row + src_step + 2; //PRQA S 3705
            src_ptr20 = src_row + src_step + src_step - 2;  //PRQA S 3705
            src_ptr21 = src_row + src_step + src_step - 1;  //PRQA S 3705
            src_ptr22 = src_row + src_step + src_step;      //PRQA S 3705
            src_ptr23 = src_row + src_step + src_step + 1;  //PRQA S 3705
            src_ptr24 = src_row + src_step + src_step + 2;  //PRQA S 3705

            for( uint32_t x = 2; x < ( i_topView.getWidth() - 2 ); ++x )
            {
                if( ( *src_ptr0 > 0 ) && ( *src_ptr1 > 0 ) && ( *src_ptr2 > 0 ) && ( *src_ptr3 > 0 ) && ( *src_ptr4 > 0 ) && ( *src_ptr5 > 0 )
                    && ( *src_ptr6 > 0 ) && ( *src_ptr7 > 0 ) && ( *src_ptr8 > 0 ) && ( *src_ptr9 > 0 ) && ( *src_ptr10 > 0 ) && ( *src_ptr11 > 0 )
                    && ( *src_ptr12 > 0 ) && ( *src_ptr13 > 0 ) && ( *src_ptr14 > 0 ) && ( *src_ptr15 > 0 ) && ( *src_ptr16 > 0 ) && ( *src_ptr17 > 0 )
                    && ( *src_ptr18 > 0 ) && ( *src_ptr19 > 0 ) && ( *src_ptr20 > 0 ) && ( *src_ptr21 > 0 ) && ( *src_ptr22 > 0 ) && ( *src_ptr23 > 0 ) && ( *src_ptr24 > 0 ) )
                {
                    *dst_ptr = static_cast <uint8_t>( 255 );
                }

                ++dst_ptr;
                ++src_ptr0;
                ++src_ptr1;
                ++src_ptr2;
                ++src_ptr3;
                ++src_ptr4;
                ++src_ptr5;
                ++src_ptr6;
                ++src_ptr7;
                ++src_ptr8;
                ++src_ptr9;
                ++src_ptr10;
                ++src_ptr11;
                ++src_ptr12;
                ++src_ptr13;
                ++src_ptr14;
                ++src_ptr15;
                ++src_ptr16;
                ++src_ptr17;
                ++src_ptr18;
                ++src_ptr19;
                ++src_ptr20;
                ++src_ptr21;
                ++src_ptr22;
                ++src_ptr23;
                ++src_ptr24;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * '_binarization()'.
    */
    void PreProcessing::_binarization( const image::Image<uint8_t> i_topView, uint8_t threshold )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _binarization" );
#endif

        for( uint32_t y = 0; y < ( i_topView.getHeight() ); y++ )
        {
            for( uint32_t x = 0; x < ( i_topView.getWidth() ); x++ )
            {
                if( *i_topView.at( x, y ) > threshold )
                {
                    *i_topView.at( x, y ) = 255;
                }
                else
                {
                    *i_topView.at( x, y ) = 0;
                }
            }
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * '_ContourDetection()'.
    */
    void PreProcessing::_ContourDetection( const image::Image<uint8_t> i_topView, buffer::CircularBuffer<detectedEllipseBoundary_t, c_bufSize>& o_ContourPoints )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _ContourDetection" );
#endif
        image::Image<uint8_t> strLabelImage = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
        image::Image<bool_t> is_labeled = memory::MemoryPool::GetImage<bool_t>( itype::IMTP_TopView_U8C1 );
        memset( strLabelImage.getData(), 0, sizeof( uint8_t )* strLabelImage.getHeight() * strLabelImage.getWidth() );
        memset( is_labeled.getData(), false, sizeof( bool )* is_labeled.getHeight() * is_labeled.getWidth() );
        // converting binary image in to edge image
        image::Image<uint8_t> strInputImage = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
        memset( strInputImage.getData(), 0, sizeof( uint8_t )* strInputImage.getHeight() * strInputImage.getWidth() );

        for( uint32_t y = 1; y < ( i_topView.getHeight() - 1 ); y++ )
        {
            for( uint32_t x = 1; x < ( i_topView.getWidth() - 1 ); x++ )
            {
                if( *i_topView.at( x, y ) == 0 )
                {
                    if( ( ( *i_topView.at( x - 1, y - 1 ) == 255 ) && ( *i_topView.at( x + 1, y + 1 ) == 0 ) ) ||
                        ( ( *i_topView.at( x - 1, y + 1 ) == 255 ) && ( *i_topView.at( x + 1, y - 1 ) == 0 ) ) ||
                        ( ( *i_topView.at( x - 1, y ) == 255 ) && ( *i_topView.at( x + 1, y ) == 0 ) ) ||
                        ( ( *i_topView.at( x, y - 1 ) == 255 ) && ( *i_topView.at( x, y + 1 ) == 0 ) ) )
                    {
                        *strInputImage.at( x, y ) = 255;
                    }
                }
            }
        }

        //cv::Mat edgeimgcv = processing::ImageProcessing::ConvertToCV( strInputImage );
        // applying connected components to determine contour region
        uint8_t label_u8 = 0;
        //cv::Mat im1 = processing::ImageProcessing::ConvertToCV( strLabelImage );
        //cv::Mat im = processing::ImageProcessing::ConvertToCV( strInputImage );
        _roi::ROI r1;
        r1.setX( 0 );
        r1.setY( 0 );
        r1.setHeight( strInputImage.getHeight() );
        r1.setWidth( strInputImage.getWidth() );

        //for all pixels in the roi
        for( uint16_t i = r1.getY(); i < ( r1.getY() + r1.getHeight() ); i++ )
        {
            for( uint16_t j = r1.getX(); j < ( r1.getX() + r1.getWidth() ); j++ )
            {
                //if it is black, set as checked
                if( *( strInputImage.getData() + i * strInputImage.getWidth() + j ) == 0 )
                {
                    *( is_labeled.getData() + i * strInputImage.getWidth() + j ) = true;
                }

                //if it is white, set to unchecked
                if( *( strInputImage.getData() + i * strInputImage.getWidth() + j ) > 0 )
                {
                    *( is_labeled.getData() + i * strInputImage.getWidth() + j ) = false;
                }
            }
        }

        uint16_t pixelCount_u16 = 0;
        Point2i loc, temp, startPoint;
        detectedEllipseBoundary_s v_queuePoints;
        v_queuePoints.col_size = 0;
        uint16_t blobArea_u16 = 0;
        uint32_t max_height = strInputImage.getHeight() - ( r1.getY() * 2 );

        for( uint16_t i = r1.getY(); i < ( r1.getY() + r1.getHeight() ); i++ )
        {
            for( uint16_t j = r1.getX(); j < ( r1.getX() + r1.getWidth() ); j++ )
            {
                //check if pixel is unchecked
                if( *( is_labeled.getData() + i * strInputImage.getWidth() + j ) == false && *( strInputImage.getData() + i * strInputImage.getWidth() + j ) > 0 )
                {
                    loc.x = i;
                    loc.y = j;
                    //add current pixel in queue
                    v_queuePoints.col[v_queuePoints.col_size] = loc;
                    v_queuePoints.flag[v_queuePoints.col_size] = true;
                    v_queuePoints.col_size++;
                    pixelCount_u16++;
                    //set this pixel as checked
                    *( is_labeled.getData() + i * strInputImage.getWidth() + j ) = true;
                    //increase the label
                    label_u8++;
                    //set current pixel to current label
                    *( strLabelImage.getData() + i * strInputImage.getWidth() + j ) = ( uint8_t )label_u8;
                    blobArea_u16++;
                    startPoint = loc;
                }
                else
                    //skip all
                {
                    continue;
                }

                while( pixelCount_u16 )
                {
                    loc = v_queuePoints.col[v_queuePoints.front()];
                    pixelCount_u16--;

                    //search right
                    if( ( loc.y + 1 ) < static_cast<int32_t>( strInputImage.getWidth() ) && *( strInputImage.getData() + loc.x * strInputImage.getWidth() + ( loc.y + 1 ) ) > 2
                        && *( is_labeled.getData() + loc.x * strInputImage.getWidth() + ( loc.y + 1 ) ) == false )
                    {
                        *( is_labeled.getData() + loc.x * strInputImage.getWidth() + ( loc.y + 1 ) ) = true;
                        temp.x = loc.x;
                        temp.y = loc.y + 1;
                        *( strLabelImage.getData() + temp.x * strInputImage.getWidth() + temp.y ) = label_u8;
                        blobArea_u16++;
                        v_queuePoints.col[v_queuePoints.col_size] = temp;
                        v_queuePoints.flag[v_queuePoints.col_size] = true;
                        v_queuePoints.col_size++;
                        pixelCount_u16++;
                    }

                    //right-down corner
                    if( ( loc.y + 1 ) < static_cast<int32_t>( strInputImage.getWidth() ) && ( loc.x + 1 ) < static_cast<int32_t>( strInputImage.getHeight() ) &&
                        *( strInputImage.getData() + ( loc.x + 1 ) * strInputImage.getWidth() + ( loc.y + 1 ) ) > 2
                        && *( is_labeled.getData() + ( loc.x + 1 ) * strInputImage.getWidth() + ( loc.y + 1 ) ) == false )
                    {
                        *( is_labeled.getData() + ( loc.x + 1 ) * strInputImage.getWidth() + ( loc.y + 1 ) ) = true;
                        temp.x = loc.x + 1;
                        temp.y = loc.y + 1;
                        *( strLabelImage.getData() + temp.x * strInputImage.getWidth() + temp.y ) = label_u8;
                        blobArea_u16++;
                        v_queuePoints.col[v_queuePoints.col_size] = temp;
                        v_queuePoints.flag[v_queuePoints.col_size] = true;
                        v_queuePoints.col_size++;
                        pixelCount_u16++;
                    }

                    //down
                    if( ( loc.x + 1 ) < static_cast<int32_t>( strInputImage.getHeight() ) && *( strInputImage.getData() + ( loc.x + 1 )*strInputImage.getWidth() + loc.y ) > 2
                        && *( is_labeled.getData() + ( loc.x + 1 )*strInputImage.getWidth() + ( loc.y ) ) == false )
                    {
                        *( is_labeled.getData() + ( loc.x + 1 )*strInputImage.getWidth() + ( loc.y ) ) = true;
                        temp.x = loc.x + 1;
                        temp.y = loc.y;
                        *( strLabelImage.getData() + temp.x * strInputImage.getWidth() + temp.y ) = label_u8;
                        blobArea_u16++;
                        v_queuePoints.col[v_queuePoints.col_size] = temp;
                        v_queuePoints.flag[v_queuePoints.col_size] = true;
                        v_queuePoints.col_size++;
                        pixelCount_u16++;
                    }

                    //left-down corner
                    if( ( loc.x + 1 ) < static_cast<int32_t>( strInputImage.getHeight() ) && ( loc.y - 1 ) > 0
                        && *( strInputImage.getData() + ( loc.x + 1 )*strInputImage.getWidth() + ( loc.y - 1 ) ) > 2
                        && *( is_labeled.getData() + ( loc.x + 1 )*strInputImage.getWidth() + ( loc.y - 1 ) ) == false )
                    {
                        *( is_labeled.getData() + ( loc.x + 1 )*strInputImage.getWidth() + ( loc.y - 1 ) ) = true;
                        temp.x = loc.x + 1;
                        temp.y = loc.y - 1;
                        *( strLabelImage.getData() + temp.x * strInputImage.getWidth() + temp.y ) = label_u8;
                        blobArea_u16++;
                        v_queuePoints.col[v_queuePoints.col_size] = temp;
                        v_queuePoints.flag[v_queuePoints.col_size] = true;
                        v_queuePoints.col_size++;
                        pixelCount_u16++;
                    }

                    //left
                    if( ( loc.y - 1 ) > 0 && *( strInputImage.getData() + loc.x * strInputImage.getWidth() + ( loc.y - 1 ) ) > 2
                        && *( is_labeled.getData() + ( loc.x )*strInputImage.getWidth() + ( loc.y - 1 ) ) == false )
                    {
                        *( is_labeled.getData() + ( loc.x )*strInputImage.getWidth() + ( loc.y - 1 ) ) = true;
                        temp.x = loc.x;
                        temp.y = loc.y - 1;
                        *( strLabelImage.getData() + temp.x * strInputImage.getWidth() + temp.y ) = label_u8;
                        blobArea_u16++;
                        v_queuePoints.col[v_queuePoints.col_size] = temp;
                        v_queuePoints.flag[v_queuePoints.col_size] = true;
                        v_queuePoints.col_size++;
                        pixelCount_u16++;
                    }

                    //left-up corner
                    if( ( loc.y - 1 ) > 0 && ( loc.x - 1 ) > 0
                        && *( strInputImage.getData() + ( loc.x - 1 ) * strInputImage.getWidth() + ( loc.y - 1 ) ) > 2
                        && *( is_labeled.getData() + ( loc.x - 1 )*strInputImage.getWidth() + ( loc.y - 1 ) ) == false )
                    {
                        *( is_labeled.getData() + ( loc.x - 1 )*strInputImage.getWidth() + ( loc.y - 1 ) ) = true;
                        temp.x = loc.x - 1;
                        temp.y = loc.y - 1;
                        *( strLabelImage.getData() + temp.x * strInputImage.getWidth() + temp.y ) = label_u8;
                        blobArea_u16++;
                        v_queuePoints.col[v_queuePoints.col_size] = temp;
                        v_queuePoints.flag[v_queuePoints.col_size] = true;
                        v_queuePoints.col_size++;
                        pixelCount_u16++;
                    }

                    //up
                    if( ( loc.x ) - 1 > 0 && *( strInputImage.getData() + ( loc.x - 1 )*strInputImage.getWidth() + loc.y ) > 2
                        && *( is_labeled.getData() + ( loc.x - 1 )*strInputImage.getWidth() + ( loc.y ) ) == false )
                    {
                        *( is_labeled.getData() + ( loc.x - 1 )*strInputImage.getWidth() + loc.y ) = true;
                        temp.x = loc.x - 1;
                        temp.y = loc.y;
                        *( strLabelImage.getData() + temp.x * strInputImage.getWidth() + temp.y ) = label_u8;
                        blobArea_u16++;
                        v_queuePoints.col[v_queuePoints.col_size] = temp;
                        v_queuePoints.flag[v_queuePoints.col_size] = true;
                        v_queuePoints.col_size++;
                        pixelCount_u16++;
                    }

                    //
                    //right-up corner
                    if( loc.x - 1 > 0 && loc.y + 1 < static_cast<int32_t>( strInputImage.getWidth() )
                        && *( strInputImage.getData() + ( loc.x - 1 )*strInputImage.getWidth() + ( loc.y + 1 ) ) > 2
                        && *( is_labeled.getData() + ( loc.x - 1 )*strInputImage.getWidth() + ( loc.y + 1 ) ) == false )
                    {
                        *( is_labeled.getData() + ( loc.x - 1 )*strInputImage.getWidth() + ( loc.y + 1 ) ) = true;
                        temp.x = loc.x - 1;
                        temp.y = loc.y + 1;
                        *( strLabelImage.getData() + temp.x * strInputImage.getWidth() + temp.y ) = label_u8;
                        blobArea_u16++;
                        v_queuePoints.col[v_queuePoints.col_size] = temp;
                        v_queuePoints.flag[v_queuePoints.col_size] = true;
                        v_queuePoints.col_size++;
                        pixelCount_u16++;
                    }
                }

                o_ContourPoints.push( v_queuePoints );
                v_queuePoints.col_size = 0;
                pixelCount_u16 = 0;
                blobArea_u16 = 0;
            }
        }

        memory::MemoryPool::ReleaseImage( strInputImage );
        memory::MemoryPool::ReleaseImage( strLabelImage );
        memory::MemoryPool::ReleaseImage( is_labeled );
        // v_queuePoints - return contour points
#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Optimized version of '_Blur5x5()'.
    */
    void PreProcessing::_Blur5x5_Opt( int32_t width, int32_t height, uint8_t* i_topView, uint8_t* o_topView, int32_t inStep, int32_t outStep )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _Blur5x5_Opt" );
#endif
        uint32_t dst_step = outStep;
        uint32_t src_step = inStep;
        uint8_t* dst_row = o_topView + dst_step + dst_step + 2; /*PRQA S 3705*/
        uint8_t* src_row = i_topView + src_step + src_step + 2; /*PRQA S 3705*/
        uint8_t* dst_ptr;
        uint8_t* src_ptr0;
        uint8_t* src_ptr5;
        uint8_t* src_ptr10;
        uint8_t* src_ptr15;
        uint8_t* src_ptr20;
        uint32_t sum;
        uint8_t coeffs2[5] = { 4, 7, 16, 26, 41 };
        uint8_t increments[2] = { 2, 1 };
        uint32_t sum_divisor = 273;

        for( int32_t y = 2; y < ( height - 2 ); ++y )
        {
            dst_ptr = dst_row;
            src_ptr0 = src_row - src_step - src_step - increments[0];   //PRQA S 3705
            src_ptr5 = src_ptr0 + src_step;     //PRQA S 3705
            src_ptr10 = src_ptr5 + src_step;    //PRQA S 3705
            src_ptr15 = src_ptr10 + src_step;   //PRQA S 3705
            src_ptr20 = src_ptr15 + src_step;   //PRQA S 3705

            for( int32_t x = 2; x < ( width - 2 ); ++x )
            {
                /*PRQA S 3706 30 */
                sum =
                    ( *src_ptr0 ) + \
                    ( src_ptr0[4] ) + \
                    ( *src_ptr20 ) + \
                    ( src_ptr20[4] ) + \
                    coeffs2[0] * ( src_ptr0[1] ) + \
                    coeffs2[0] * ( src_ptr0[3] ) + \
                    coeffs2[0] * ( *src_ptr5 ) + \
                    coeffs2[0] * ( src_ptr5[4] ) + \
                    coeffs2[0] * ( *src_ptr15 ) + \
                    coeffs2[0] * ( src_ptr15[4] ) + \
                    coeffs2[0] * ( src_ptr20[1] ) + \
                    coeffs2[0] * ( src_ptr20[3] ) + \
                    coeffs2[1] * ( src_ptr0[2] ) + \
                    coeffs2[1] * ( *src_ptr10 ) + \
                    coeffs2[1] * ( src_ptr10[4] ) + \
                    coeffs2[1] * ( src_ptr20[2] ) + \
                    coeffs2[2] * ( src_ptr5[1] ) + \
                    coeffs2[2] * ( src_ptr5[3] ) + \
                    coeffs2[2] * ( src_ptr15[1] ) + \
                    coeffs2[2] * ( src_ptr15[3] ) + \
                    coeffs2[3] * ( src_ptr5[2] ) + \
                    coeffs2[3] * ( src_ptr10[1] ) + \
                    coeffs2[3] * ( src_ptr10[3] ) + \
                    coeffs2[3] * ( src_ptr15[2] ) + \
                    coeffs2[4] * ( src_ptr10[2] );
                *dst_ptr = static_cast <uint8_t>( sum / sum_divisor );
                dst_ptr++;
                src_ptr0++;
                src_ptr5++;
                src_ptr10++;
                src_ptr15++;
                src_ptr20++;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Optimized version of '_Blur7x7()'.
    */
    void PreProcessing::_Blur7x7( const image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView )
    {
#ifdef _WIN32
        diag::start( "PreProcessing: _Blur7x7" );
#endif
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + dst_step + dst_step + 3;
        uint8_t* src_row = i_topView.getData() + src_step + src_step + src_step + 3;
        uint8_t* dst_ptr;
        uint8_t* src_ptr0, *src_ptr1, *src_ptr2, *src_ptr3, *src_ptr4, *src_ptr5, *src_ptr6, *src_ptr7, *src_ptr8, *src_ptr9;
        uint8_t* src_ptr10, *src_ptr11, *src_ptr12, *src_ptr13, *src_ptr14, *src_ptr15, *src_ptr16, *src_ptr17, *src_ptr18, *src_ptr19;
        uint8_t* src_ptr20, *src_ptr21, *src_ptr22, *src_ptr23, *src_ptr24, *src_ptr25, *src_ptr26, *src_ptr27, *src_ptr28, *src_ptr29;
        uint8_t* src_ptr30, *src_ptr31, *src_ptr32, *src_ptr33, *src_ptr34, *src_ptr35, *src_ptr36, *src_ptr37, *src_ptr38, *src_ptr39;
        uint8_t* src_ptr40, *src_ptr41, *src_ptr42, *src_ptr43, *src_ptr44, *src_ptr45, *src_ptr46, *src_ptr47, *src_ptr48;
        uint32_t sum;

        for( uint32_t y = 3; y < i_topView.getHeight() - 3; ++y )
        {
            dst_ptr = dst_row;
            src_ptr0 = src_row - src_step - src_step - src_step - 3;
            src_ptr1 = src_row - src_step - src_step - src_step - 2;
            src_ptr2 = src_row - src_step - src_step - src_step - 1;
            src_ptr3 = src_row - src_step - src_step - src_step;
            src_ptr4 = src_row - src_step - src_step - src_step + 1;
            src_ptr5 = src_row - src_step - src_step - src_step + 2;
            src_ptr6 = src_row - src_step - src_step - src_step + 3;
            src_ptr7 = src_row - src_step - src_step - 3;
            src_ptr8 = src_row - src_step - src_step - 2;
            src_ptr9 = src_row - src_step - src_step - 1;
            src_ptr10 = src_row - src_step - src_step;
            src_ptr11 = src_row - src_step - src_step + 1;
            src_ptr12 = src_row - src_step - src_step + 2;
            src_ptr13 = src_row - src_step - src_step + 3;
            src_ptr14 = src_row - src_step - 3;
            src_ptr15 = src_row - src_step - 2;
            src_ptr16 = src_row - src_step - 1;
            src_ptr17 = src_row - src_step;
            src_ptr18 = src_row - src_step + 1;
            src_ptr19 = src_row - src_step + 2;
            src_ptr20 = src_row - src_step + 3;
            src_ptr21 = src_row - 3;
            src_ptr22 = src_row - 2;
            src_ptr23 = src_row - 1;
            src_ptr24 = src_row;
            src_ptr25 = src_row + 1;
            src_ptr26 = src_row + 2;
            src_ptr27 = src_row + 3;
            src_ptr28 = src_row + src_step - 3;
            src_ptr29 = src_row + src_step - 2;
            src_ptr30 = src_row + src_step - 1;
            src_ptr31 = src_row + src_step;
            src_ptr32 = src_row + src_step + 1;
            src_ptr33 = src_row + src_step + 2;
            src_ptr34 = src_row + src_step + 3;
            src_ptr35 = src_row + src_step + src_step - 3;
            src_ptr36 = src_row + src_step + src_step - 2;
            src_ptr37 = src_row + src_step + src_step - 1;
            src_ptr38 = src_row + src_step + src_step;
            src_ptr39 = src_row + src_step + src_step + 1;
            src_ptr40 = src_row + src_step + src_step + 2;
            src_ptr41 = src_row + src_step + src_step + 3;
            src_ptr42 = src_row + src_step + src_step + src_step - 3;
            src_ptr43 = src_row + src_step + src_step + src_step - 2;
            src_ptr44 = src_row + src_step + src_step + src_step - 1;
            src_ptr45 = src_row + src_step + src_step + src_step;
            src_ptr46 = src_row + src_step + src_step + src_step + 1;
            src_ptr47 = src_row + src_step + src_step + src_step + 2;
            src_ptr48 = src_row + src_step + src_step + src_step + 3;

            for( uint32_t x = 3; x < i_topView.getWidth() - 3; ++x )
            {
                sum = ( *src_ptr0 ) + \
                      4 * ( *src_ptr1 ) + \
                      6 * ( *src_ptr2 ) + \
                      8 * ( *src_ptr3 ) + \
                      6 * ( *src_ptr4 ) + \
                      4 * ( *src_ptr5 ) + \
                      ( *src_ptr6 ) + \
                      4 * ( *src_ptr7 ) + \
                      16 * ( *src_ptr8 ) + \
                      24 * ( *src_ptr9 ) + \
                      32 * ( *src_ptr10 ) + \
                      24 * ( *src_ptr11 ) + \
                      16 * ( *src_ptr12 ) + \
                      4 * ( *src_ptr13 ) + \
                      6 * ( *src_ptr14 ) + \
                      24 * ( *src_ptr15 ) + \
                      36 * ( *src_ptr16 ) + \
                      48 * ( *src_ptr17 ) + \
                      36 * ( *src_ptr18 ) + \
                      24 * ( *src_ptr19 ) + \
                      6 * ( *src_ptr20 ) + \
                      8 * ( *src_ptr21 ) + \
                      32 * ( *src_ptr22 ) + \
                      48 * ( *src_ptr23 ) + \
                      64 * ( *src_ptr24 ) + \
                      48 * ( *src_ptr25 ) + \
                      32 * ( *src_ptr26 ) + \
                      8 * ( *src_ptr27 ) + \
                      6 * ( *src_ptr28 ) + \
                      24 * ( *src_ptr29 ) + \
                      36 * ( *src_ptr30 ) + \
                      48 * ( *src_ptr31 ) + \
                      36 * ( *src_ptr32 ) + \
                      24 * ( *src_ptr33 ) + \
                      6 * ( *src_ptr34 ) + \
                      4 * ( *src_ptr35 ) + \
                      16 * ( *src_ptr36 ) + \
                      24 * ( *src_ptr37 ) + \
                      32 * ( *src_ptr38 ) + \
                      24 * ( *src_ptr39 ) + \
                      16 * ( *src_ptr40 ) + \
                      4 * ( *src_ptr41 ) + \
                      ( *src_ptr42 ) + \
                      4 * ( *src_ptr43 ) + \
                      6 * ( *src_ptr44 ) + \
                      8 * ( *src_ptr45 ) + \
                      6 * ( *src_ptr46 ) + \
                      4 * ( *src_ptr47 ) + \
                      ( *src_ptr48 );
                *dst_ptr = static_cast <uint8_t>( sum / 900 );
                ++dst_ptr;
                ++src_ptr0;
                ++src_ptr1;
                ++src_ptr2;
                ++src_ptr3;
                ++src_ptr4;
                ++src_ptr5;
                ++src_ptr6;
                ++src_ptr7;
                ++src_ptr8;
                ++src_ptr9;
                ++src_ptr10;
                ++src_ptr11;
                ++src_ptr12;
                ++src_ptr13;
                ++src_ptr14;
                ++src_ptr15;
                ++src_ptr16;
                ++src_ptr17;
                ++src_ptr18;
                ++src_ptr19;
                ++src_ptr20;
                ++src_ptr21;
                ++src_ptr22;
                ++src_ptr23;
                ++src_ptr24;
                ++src_ptr25;
                ++src_ptr26;
                ++src_ptr27;
                ++src_ptr28;
                ++src_ptr29;
                ++src_ptr30;
                ++src_ptr31;
                ++src_ptr32;
                ++src_ptr33;
                ++src_ptr34;
                ++src_ptr35;
                ++src_ptr36;
                ++src_ptr37;
                ++src_ptr38;
                ++src_ptr39;
                ++src_ptr40;
                ++src_ptr41;
                ++src_ptr42;
                ++src_ptr43;
                ++src_ptr44;
                ++src_ptr45;
                ++src_ptr46;
                ++src_ptr47;
                ++src_ptr48;
            }

            dst_row += dst_step;
            src_row += src_step;
        }
#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Normalize the given image, using the stored min and max values from the previous frame.
    */
    void PreProcessing::_Normalize( image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _Normalize" );
#endif
        image::Image<uint8_t>::iterator src_end = i_topView.end();
        image::Image<uint8_t>::iterator dst_it = o_topView.begin();
        uint8_t new_low = 255;
        uint8_t new_high = 0;
        float32_t norm_factor = ( 255.0f / static_cast <float32_t>( m_high - m_low ) );

        for( image::Image<uint8_t>::iterator src_it = i_topView.begin(); src_it != src_end; ++src_it ) // PRQA S 4244
        {
            if( *src_it > new_high )
            {
                new_high = *src_it;
            }

            if( *src_it < new_low )
            {
                new_low = *src_it;
            }

            if( *src_it > m_high )
            {
                *dst_it = 255;
            }
            else if( *src_it < m_low )
            {
                *dst_it = 0;
            }
            else
            {
                *dst_it = static_cast <uint8_t>( static_cast <float32_t>( *src_it - m_low ) * norm_factor );
            }

            ++dst_it;
        }

        m_high = new_high;
        m_low = new_low;
#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Optimized version of '_Blur5x5_NormalizeOpt()'.
    */
    void PreProcessing::_Blur5x5_NormalizeOpt( const image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _Blur7x7" );
#endif
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + dst_step + dst_step + 3;
        uint8_t* src_row = i_topView.getData() + src_step + src_step + src_step + 3;
        uint8_t* dst_ptr;
        uint8_t* src_ptr0, *src_ptr1, *src_ptr2, *src_ptr3, *src_ptr4, *src_ptr5, *src_ptr6, *src_ptr7, *src_ptr8, *src_ptr9;
        uint8_t* src_ptr10, *src_ptr11, *src_ptr12, *src_ptr13, *src_ptr14, *src_ptr15, *src_ptr16, *src_ptr17, *src_ptr18, *src_ptr19;
        uint8_t* src_ptr20, *src_ptr21, *src_ptr22, *src_ptr23, *src_ptr24, *src_ptr25, *src_ptr26, *src_ptr27, *src_ptr28, *src_ptr29;
        uint8_t* src_ptr30, *src_ptr31, *src_ptr32, *src_ptr33, *src_ptr34, *src_ptr35, *src_ptr36, *src_ptr37, *src_ptr38, *src_ptr39;
        uint8_t* src_ptr40, *src_ptr41, *src_ptr42, *src_ptr43, *src_ptr44, *src_ptr45, *src_ptr46, *src_ptr47, *src_ptr48;
        uint32_t sum;
        //
        uint8_t new_low = 255;
        uint8_t new_high = 0;
        float32_t norm_factor = ( 255.0f / static_cast <float32_t>( m_high - m_low ) );

        for( uint32_t y = 3; y < i_topView.getHeight() - 3; ++y )
        {
            dst_ptr = dst_row;
            src_ptr0 = src_row - src_step - src_step - src_step - 3;
            src_ptr1 = src_row - src_step - src_step - src_step - 2;
            src_ptr2 = src_row - src_step - src_step - src_step - 1;
            src_ptr3 = src_row - src_step - src_step - src_step;
            src_ptr4 = src_row - src_step - src_step - src_step + 1;
            src_ptr5 = src_row - src_step - src_step - src_step + 2;
            src_ptr6 = src_row - src_step - src_step - src_step + 3;
            src_ptr7 = src_row - src_step - src_step - 3;
            src_ptr8 = src_row - src_step - src_step - 2;
            src_ptr9 = src_row - src_step - src_step - 1;
            src_ptr10 = src_row - src_step - src_step;
            src_ptr11 = src_row - src_step - src_step + 1;
            src_ptr12 = src_row - src_step - src_step + 2;
            src_ptr13 = src_row - src_step - src_step + 3;
            src_ptr14 = src_row - src_step - 3;
            src_ptr15 = src_row - src_step - 2;
            src_ptr16 = src_row - src_step - 1;
            src_ptr17 = src_row - src_step;
            src_ptr18 = src_row - src_step + 1;
            src_ptr19 = src_row - src_step + 2;
            src_ptr20 = src_row - src_step + 3;
            src_ptr21 = src_row - 3;
            src_ptr22 = src_row - 2;
            src_ptr23 = src_row - 1;
            src_ptr24 = src_row;
            src_ptr25 = src_row + 1;
            src_ptr26 = src_row + 2;
            src_ptr27 = src_row + 3;
            src_ptr28 = src_row + src_step - 3;
            src_ptr29 = src_row + src_step - 2;
            src_ptr30 = src_row + src_step - 1;
            src_ptr31 = src_row + src_step;
            src_ptr32 = src_row + src_step + 1;
            src_ptr33 = src_row + src_step + 2;
            src_ptr34 = src_row + src_step + 3;
            src_ptr35 = src_row + src_step + src_step - 3;
            src_ptr36 = src_row + src_step + src_step - 2;
            src_ptr37 = src_row + src_step + src_step - 1;
            src_ptr38 = src_row + src_step + src_step;
            src_ptr39 = src_row + src_step + src_step + 1;
            src_ptr40 = src_row + src_step + src_step + 2;
            src_ptr41 = src_row + src_step + src_step + 3;
            src_ptr42 = src_row + src_step + src_step + src_step - 3;
            src_ptr43 = src_row + src_step + src_step + src_step - 2;
            src_ptr44 = src_row + src_step + src_step + src_step - 1;
            src_ptr45 = src_row + src_step + src_step + src_step;
            src_ptr46 = src_row + src_step + src_step + src_step + 1;
            src_ptr47 = src_row + src_step + src_step + src_step + 2;
            src_ptr48 = src_row + src_step + src_step + src_step + 3;

            for( uint32_t x = 3; x < i_topView.getWidth() - 3; ++x )
            {
                sum = ( *src_ptr0 ) + \
                      4 * ( *src_ptr1 ) + \
                      6 * ( *src_ptr2 ) + \
                      8 * ( *src_ptr3 ) + \
                      6 * ( *src_ptr4 ) + \
                      4 * ( *src_ptr5 ) + \
                      ( *src_ptr6 ) + \
                      4 * ( *src_ptr7 ) + \
                      16 * ( *src_ptr8 ) + \
                      24 * ( *src_ptr9 ) + \
                      32 * ( *src_ptr10 ) + \
                      24 * ( *src_ptr11 ) + \
                      16 * ( *src_ptr12 ) + \
                      4 * ( *src_ptr13 ) + \
                      6 * ( *src_ptr14 ) + \
                      24 * ( *src_ptr15 ) + \
                      36 * ( *src_ptr16 ) + \
                      48 * ( *src_ptr17 ) + \
                      36 * ( *src_ptr18 ) + \
                      24 * ( *src_ptr19 ) + \
                      6 * ( *src_ptr20 ) + \
                      8 * ( *src_ptr21 ) + \
                      32 * ( *src_ptr22 ) + \
                      48 * ( *src_ptr23 ) + \
                      64 * ( *src_ptr24 ) + \
                      48 * ( *src_ptr25 ) + \
                      32 * ( *src_ptr26 ) + \
                      8 * ( *src_ptr27 ) + \
                      6 * ( *src_ptr28 ) + \
                      24 * ( *src_ptr29 ) + \
                      36 * ( *src_ptr30 ) + \
                      48 * ( *src_ptr31 ) + \
                      36 * ( *src_ptr32 ) + \
                      24 * ( *src_ptr33 ) + \
                      6 * ( *src_ptr34 ) + \
                      4 * ( *src_ptr35 ) + \
                      16 * ( *src_ptr36 ) + \
                      24 * ( *src_ptr37 ) + \
                      32 * ( *src_ptr38 ) + \
                      24 * ( *src_ptr39 ) + \
                      16 * ( *src_ptr40 ) + \
                      4 * ( *src_ptr41 ) + \
                      ( *src_ptr42 ) + \
                      4 * ( *src_ptr43 ) + \
                      6 * ( *src_ptr44 ) + \
                      8 * ( *src_ptr45 ) + \
                      6 * ( *src_ptr46 ) + \
                      4 * ( *src_ptr47 ) + \
                      ( *src_ptr48 );
                *dst_ptr = static_cast <uint8_t>( sum / 900 );

                // Normalize
                if( *dst_ptr > new_high )
                {
                    new_high = *dst_ptr;
                }

                if( *dst_ptr < new_low )
                {
                    new_low = *dst_ptr;
                }

                if( *dst_ptr > m_high )
                {
                    *dst_ptr = 255;
                }
                else if( *dst_ptr < m_low )
                {
                    *dst_ptr = 0;
                }
                else
                {
                    *dst_ptr = static_cast <uint8_t>( static_cast <float32_t>( *dst_ptr - m_low ) * norm_factor );
                }

                //
                ++dst_ptr;
                ++src_ptr0;
                ++src_ptr1;
                ++src_ptr2;
                ++src_ptr3;
                ++src_ptr4;
                ++src_ptr5;
                ++src_ptr6;
                ++src_ptr7;
                ++src_ptr8;
                ++src_ptr9;
                ++src_ptr10;
                ++src_ptr11;
                ++src_ptr12;
                ++src_ptr13;
                ++src_ptr14;
                ++src_ptr15;
                ++src_ptr16;
                ++src_ptr17;
                ++src_ptr18;
                ++src_ptr19;
                ++src_ptr20;
                ++src_ptr21;
                ++src_ptr22;
                ++src_ptr23;
                ++src_ptr24;
                ++src_ptr25;
                ++src_ptr26;
                ++src_ptr27;
                ++src_ptr28;
                ++src_ptr29;
                ++src_ptr30;
                ++src_ptr31;
                ++src_ptr32;
                ++src_ptr33;
                ++src_ptr34;
                ++src_ptr35;
                ++src_ptr36;
                ++src_ptr37;
                ++src_ptr38;
                ++src_ptr39;
                ++src_ptr40;
                ++src_ptr41;
                ++src_ptr42;
                ++src_ptr43;
                ++src_ptr44;
                ++src_ptr45;
                ++src_ptr46;
                ++src_ptr47;
                ++src_ptr48;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

        m_high = new_high;
        m_low = new_low;
#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }

    template
    void PreProcessing::WarpImage( const image::Image<uint8_t>& i_image, TAD2::WarpedImage<uint8_t>& o_image, Point2i i_hitchpoint )const;
    template
    void PreProcessing::WarpImage( const image::Image<TAD2::FeatureExtraction::Feature>& i_image, TAD2::WarpedImage<TAD2::FeatureExtraction::Feature>& o_image, Point2i i_hitchpoint )const;
    template
    void PreProcessing::WarpImage( const image::Image<uint8_t>& i_image, TAD2::WarpedImage<uint8_t>& o_image, TAD2::WarpedTopViewParameters i_topViewParams, Point2i i_hitchpoint )const;
}
