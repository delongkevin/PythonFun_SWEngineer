// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [05-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __EDGE_DETECTOR__H_
#define __EDGE_DETECTOR__H_

#include "Image.h"

namespace angles
{
    static const float32_t c_tanN67 = -2.414213562f;
    static const float32_t c_tanN22 = -0.414213562f;
    static const float32_t c_tan22 = 0.414213562f;
    static const float32_t c_tan67 = 2.414213562f;
}
namespace TAD2
{
    /**
    * Canny edge Detector.
    */
    class Canny
    {
    public:
        explicit Canny( image::Image<uint8_t> i_image, image::Image<uint16_t> i_thresh_low, image::Image<uint16_t> i_thresh_high, image::Image<uint8_t> o_edges, image::Image<uint16_t> o_gradMag = image::NullImage<uint16_t>(), image::Image<uint8_t> o_gradDir = image::NullImage<uint8_t>() );
        ~Canny();

        // --- Edge direction constants
        static const uint8_t c_0deg = 0;
        static const uint8_t c_45deg = 1;
        static const uint8_t c_90deg = 2;
        static const uint8_t c_135deg = 3;

    private:
        bool_t initOK;



        // --- Helper functions
        static void _CannyEdges( image::Image<uint8_t>& i_image, image::Image<uint16_t> i_thresh_low, image::Image<uint16_t> i_thresh_high, image::Image<uint16_t>& o_gradientMag, image::Image<uint8_t>& o_gradientDir, image::Image<uint8_t>& o_edges );
        static void _CalculateGradientMagnitude( image::Image<uint8_t>& i_image, image::Image<uint16_t>& o_gradientMag );
        static void _CalculateGradientMagnitudeAndDirection( image::Image<uint8_t>& i_image, image::Image<uint16_t>& o_gradientMag, image::Image<uint8_t>& o_gradientDir );

    };
}

/**
* Edge tracker class for working with edges over time. (Not used.)
*/
namespace edge
{
    class EdgeTracker
    {
    public:
        explicit EdgeTracker( image::Image<uint8_t>& et_image );
        ~EdgeTracker();

        bool_t Init();
        bool_t Uninit();
        void Reset();
        void Run( image::Image<uint8_t>& i_edges ) const;

        void CalculateEdgeHitRate( image::Image<uint8_t>& dst, uint8_t sample ) const;

    private:
        image::Image<uint8_t>& m_image;
        image::Image<uint16_t> m_hitBuffer_u32;

        void UpdateHitBuffer( image::Image<uint8_t>& edges ) const;

    };
}

#endif // !__EDGE_DETECTOR__H_
