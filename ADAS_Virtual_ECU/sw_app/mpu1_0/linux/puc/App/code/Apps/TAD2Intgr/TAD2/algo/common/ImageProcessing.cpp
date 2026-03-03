// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [18-Dec-2018]
// --- Last Modified by Joshua Teichroeb [18-Dec-2018]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "ImageProcessing.h"

#ifdef ENABLE_OPENCV
    #include "cv.h"
    #include "highgui/highgui.hpp"
    #include "core/core.hpp"
    #include "imgcodecs.hpp"
#endif
namespace gauss
{
    static uint32_t g_gauss3[9] =
    {

        1, 2, 1,
        2, 4, 2,
        1, 2, 1
    };




    static uint32_t g_gauss5[25] =
    {
        1, 4, 7, 4, 1,
        4, 16, 26, 16, 4,
        7, 26, 41, 26, 7,
        4, 16, 26, 16, 4,
        1, 4, 7, 4, 1
    };


    static uint32_t g_gauss7[49] =
    {
        0, 0, 1, 2, 1, 0, 0,
        0, 3, 13, 22, 13, 3, 0,
        1, 13, 59, 97, 59, 13, 1,
        2, 22, 97, 159, 97, 22, 2,
        1, 13, 59, 97, 59, 13, 1,
        0, 3, 13, 22, 13, 3, 0,
        0, 0, 1, 2, 1, 0, 0
    };
}

const image::Kernel<uint32_t, 3, 3> processing::ImageProcessing::c_gauss3( 1, 1, gauss::g_gauss3 );
const image::Kernel<uint32_t, 5, 5> processing::ImageProcessing::c_gauss5( 2, 2, gauss::g_gauss5 );
const image::Kernel<uint32_t, 7, 7> processing::ImageProcessing::c_gauss7( 3, 3, gauss::g_gauss7 );

const uint32_t processing::ImageProcessing::c_gauss3_sum = 16;
const uint32_t processing::ImageProcessing::c_gauss5_sum = 273;
const uint32_t processing::ImageProcessing::c_gauss7_sum = 1003;

