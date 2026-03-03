#ifndef __WORD2IMAGETYPES1_H_
#define __WORD2IMAGETYPES1_H_
#ifdef _WINDOWS
#include "core/MeclTypes.h"
#else
# include "mecl/core/MeclTypes.h"
#endif
namespace W2Image
{
typedef struct __SetupIntrinsicCfg
{
    float32_t IntrWidth;                      // 			= 1280
    float32_t IntrHeight;                     //  		= 800
    float32_t IntrPpX;                       // 			= 396.0204
    float32_t IntrPpY; 		                 //          = 640.3
    float32_t IntrPolyImage2World_0;         // 0.0000000000000000e+00
    float32_t IntrPolyImage2World_1;         // 1.10906
    float32_t IntrPolyImage2World_2;         // 0.01095954
    float32_t IntrPolyImage2World_3;         // -0.2175145
    float32_t IntrPolyImage2World_4;         // 0.1103843
    float32_t IntrPolyImage2World_5;         // -0.01472126
    float32_t IntrPolyWorld2Image_0;         // 0.0000000000000000e+00
    float32_t IntrPolyWorld2Image_1;         // 0.8977472 
    float32_t IntrPolyWorld2Image_2;         // 0.02905079
    float32_t IntrPolyWorld2Image_3;         // 0.0246421
    float32_t IntrPolyWorld2Image_4;         // 0.1014968
    float32_t IntrPolyWorld2Image_5;         // -0.05071492
    float32_t IntrPixelSizeX;                // 0.003
    float32_t IntrPixelSizeY;                // 0.003
    float32_t IntrFieldOfView;               // 3.8397243543875250e+00
    float32_t IntrFocalLength;                // 1.000000
} SetupIntrinsicCfg_s;

typedef struct __SetupExtrinsicCfg
{
    float32_t Camera_X;         //  = 1000
    float32_t Camera_Y;         // = 10
    float32_t Camera_Z;         //  = 400
    float32_t Camera_Roll;      //  = 0
    float32_t Camera_Pitch;     //  = 30
    float32_t Camera_Yaw;       //  = 0
} SetupExtrinsicCfg_s;
}
#endif // __WORD2IMAGETYPES1_H_


