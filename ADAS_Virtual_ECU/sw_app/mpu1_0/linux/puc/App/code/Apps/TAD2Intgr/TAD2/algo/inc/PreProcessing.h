// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [05-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __PRE_PROCESSING__H_
#define __PRE_PROCESSING__H_

#ifdef __QNX__
    #include "../common/TADStructures.h"
    #include "../common/Image.h"
    #include "../common/TADStructures.h"
    #include "../common/CircularBuffer.h"
#else
    #include "common/TADStructures.h"
    #include "common/Image.h"
    #include "common/TADStructures.h"
    #include "common/CircularBuffer.h"
#endif

#include <mecl/core/MeclTypes.h>

/*
* Pre-processing module.
*
* Performs all pre-processing of the topview that is necessary for Canny edge detection.
*/
namespace TAD2
{
    typedef struct detectedEllipseBoundary_s
    {
        Point2i col[150];
        bool flag[150];
        uint16_t col_size;
        uint16_t front()
        {
            uint16_t returnIndex = 0;

            for( uint16_t index = 0; index < col_size; index++ )
            {
                if( flag[index] == true )
                {
                    flag[index] = false;
                    //col_size--;
                    returnIndex = index;
                    break;
                }
            }

            return returnIndex;
        };
    } detectedEllipseBoundary_t;
    class PreProcessing
    {
    public:
        PreProcessing();
        ~PreProcessing();

        // --- Exposed functions
        bool_t Init();
        bool_t Start();
        void Finish();

        void Run( int32_t i_frame, image::Image<uint8_t>& i_topView, _roi::ROI& i_roi );


        template<typename T>
        void WarpImage( const image::Image<T>& i_image, TAD2::WarpedImage<T>& o_image, Point2i i_hitchPoint ) const;
        template<typename T>
        void WarpImage( const image::Image<T>& i_image, TAD2::WarpedImage<T>& o_image, TAD2::WarpedTopViewParameters i_topViewParams, Point2i i_hitchPoint )const;
        static void CreateWarpLUTHeader();
        void _Normalize( image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView );
        static void _AvgImg( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView );
        static void _ROI3x3( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView );
        static void _ROI5x5( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView );
        static void _Blur5x5_Opt( int32_t width, int32_t height, uint8_t* i_topView, uint8_t* o_topView, int32_t inStep, int32_t outStep );
        static void _dilation3x3( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView );
        static void _erosiom3x3( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView );
        static void _linking3x3( image::Image<uint8_t>& i_topView, uint16_t othsu_thresh );
        static void _dilation5x5( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView );
        static void _erosion5x5( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView );
        static void _binarization( const image::Image<uint8_t> i_topView, uint8_t threshold );
        static void _Blur7x7( const image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView );
        static void _Average3x3( image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView );
        static void _Average5x5( image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView );
        void _Blur5x5_NormalizeOpt( const image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView );


        // --- Getters
        bool_t WarpLUTsValid()const;
        image::Image<uint8_t> GetWorkingTopView()const;

    private:
        bool_t m_initOK;
        bool_t m_isRunning;
        int32_t m_lastFrameRun;

        // --- Module specific variables
        uint8_t m_high;
        uint8_t m_low;

        TAD2::WarpedTopViewParameters m_warpedTopViewParams;
        image::Image<sint16_t> m_warpXLUT_s16;
        image::Image<sint16_t> m_warpYLUT_s16;
        image::Image<uint8_t> m_topView_u8;
        static const uint32_t c_bufSize = 400;


        // --- Private functions
        static void _Blur3x3( const image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView );
        static void _Blur5x5( const image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView );

        static void _ContourDetection( const image::Image<uint8_t> i_topView, buffer::CircularBuffer<detectedEllipseBoundary_t, c_bufSize>& o_ContourPoints );

    };
}
#endif //!__PRE_PROCESSING__H_
