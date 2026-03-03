#pragma once
// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [03-Apr-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#include "stdint.h"

#ifndef __DEFINES__H_
#define __DEFINES__H_

#ifdef __QNX__
    #include "meal/camera/core/inc/CameraPoint.h"
    #include "PlatformDataTypes.h"
#else
    #include "point.h"
#endif

#define WIN_2015_CODE

#ifdef _WINDOWS_
    #define DIAGNOSTICS
    //#define QACPP_TAD_BRAMPTON
    #ifndef QACPP_TAD_BRAMPTON
        #define ENABLE_OPENCV                   // define to enable use of opencv in some libraries
    #endif
    #define ENABLE_DEBUGGING                // define to enable debugging library
    #define ENABLE_DIAGNOSTICS              // define to enable diagnostics library
    #ifndef QACPP_TAD_BRAMPTON
        //    #define DIAGNOSTICS
    #endif
    #define ENABLE_FILE_OUTPUT              // define to enable file output library

    #ifdef ENABLE_DEBUGGING
        #define WINDOWS_DEBUGGING           // define to enable windows implementation of debugging library which uses opencv
    #endif

    #ifdef ENABLE_DIAGNOSTICS
        #ifndef QACPP_TAD_BRAMPTON
            #define WINDOWS_DIAGNOSTICS         // define to enable windows implementation of diagnostics library which uses standard library functions
        #endif
    #endif

    #ifdef _WINDOWS
        #include <math.h>
    #endif
#endif

enum
{
    APP_OPTFLOW_USE_INITIAL_FLOW = 4,
    APP_OPTFLOW_LK_GET_MIN_EIGENVALS = 8,
    APP_OPTFLOW_FARNEBACK_GAUSSIAN = 256
};

enum BorderTypes
{
    APP_BORDER_CONSTANT = 0, //!< `iiiiii|abcdefgh|iiiiiii`  with some specified `i`
    APP_BORDER_REPLICATE = 1, //!< `aaaaaa|abcdefgh|hhhhhhh`
    APP_BORDER_REFLECT = 2, //!< `fedcba|abcdefgh|hgfedcb`
    APP_BORDER_WRAP = 3, //!< `cdefgh|abcdefgh|abcdefg`
    APP_BORDER_REFLECT_101 = 4, //!< `gfedcb|abcdefgh|gfedcba`
    APP_BORDER_TRANSPARENT = 5, //!< `uvwxyz|abcdefgh|ijklmno`

    APP_BORDER_REFLECT101 = APP_BORDER_REFLECT_101, //!< same as BORDER_REFLECT_101
    APP_BORDER_DEFAULT = APP_BORDER_REFLECT_101, //!< same as BORDER_REFLECT_101
    APP_BORDER_ISOLATED = 16 //!< do not look outside of ROI
};
// --- Image and template parameters
namespace global
{
    const int32_t TEMPLATE_IMAGE_WIDTH = 203;
    const int32_t TEMPLATE_IMAGE_HEIGHT = 150;
    const int32_t TEMPLATE_IMAGE_SIZE = ( TEMPLATE_IMAGE_WIDTH* TEMPLATE_IMAGE_HEIGHT );

    const int32_t TOPVIEW_IMAGE_WIDTH = 640;
    const int32_t TOPVIEW_IMAGE_HEIGHT = 400;
    const int32_t TOPVIEW_IMAGE_SIZE = ( TOPVIEW_IMAGE_WIDTH* TOPVIEW_IMAGE_HEIGHT );

    const int32_t REARVIEW_IMAGE_WIDTH = 640;
    const int32_t REARVIEW_IMAGE_HEIGHT = 400;

    const int32_t REARVIEW_IMAGE_SIZE = ( REARVIEW_IMAGE_WIDTH* REARVIEW_IMAGE_HEIGHT );

    const int32_t WARPED_TOPVIEW_Y_OFFSET = 20;
    const int32_t WARPED_TOPVIEW_IMAGE_HEIGHT = ( TEMPLATE_IMAGE_HEIGHT );
    const int32_t WARPED_TOPVIEW_IMAGE_WIDTH = 640;
};
#endif // !__DEFINES__H_
