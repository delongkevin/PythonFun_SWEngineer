#ifndef MATRIXUTIL
#define MATRIXUTIL

#ifdef _WIN32
    #include <MECL/mecl.h>
#else
    #include "mecl/mecl.h"
#endif // _WIN32

namespace matrixUtil
{
    void transpose( const float32_t* src, float32_t* dst, const uint16_t N, const uint16_t M );
    void f32_MM( const float32_t* a, const float32_t* b, float32_t* dest, const uint16_t m, const uint16_t n, const uint16_t p );
    void f32_MV( const float32_t* a, const float32_t* b, float32_t* dest, uint16_t m, uint16_t n );
    float32_t correlationCoefficient( const  uint8_t* X, const uint8_t* Y, uint16_t x_step, uint16_t y_step, uint16_t width, uint16_t height );
    void CrossCorrValid_NormLevel_8u32f( const uint8_t* pSrc, uint16_t srcStep, uint16_t srcWidth, uint16_t srcHeight,
                                         const uint8_t* pTpl, uint16_t tplStep, uint16_t tplWidth, uint16_t tplHeight,
                                         float32_t* pDst, uint16_t dstStep );

    void getCofactor( const float32_t* A, float32_t* temp, const uint16_t p, const uint16_t q, const uint16_t n );
    void iCopy_8u_C1R( const  uint8_t* src, uint16_t srcStep,
                       uint8_t* dest,
                       uint16_t dstStep,
                       uint16_t width,
                       uint16_t height );
    void cropRGBplanar( const uint8_t* i_inputImage_u8, const uint16_t i_inputHeight_u16, const uint16_t i_inputWidth_u16,
                        uint8_t* o_cropImage_u8, const uint16_t i_cropHeight_u16, const uint16_t i_cropWidth_u16,
                        const uint16_t i_cropStartX_u16, const uint16_t i_cropStartY_u16 );
    void cropRGBinterleave( const uint8_t* i_inputImage_u8, const uint16_t i_inputWidth_u16,
                            uint8_t* o_cropImage_u8, const uint16_t i_cropHeight_u16, const uint16_t i_cropWidth_u16,
                            const uint16_t i_cropStartX_u16, const uint16_t i_cropStartY_u16 );
    void GrayBiLinearResize( const uint8_t* i_inputImg_u8,
                             const uint16_t i_inputwidth_u16,
                             const uint16_t i_inputHeight_u16,
                             uint8_t* o_outputImg_u8,
                             const uint16_t i_outputWidth_u16,
                             const uint16_t i_outputHeight_u16 );
    void RGBPlanartoGray( const uint8_t* i_inputImage_pu8,
                          const uint16_t i_inputWidth_u16,
                          const uint16_t i_inputHeight_u16,
                          uint8_t* o_image_pu8 );
    void RGBInterleavedtoGray( const uint8_t* i_inputImage_pu8,
                               const uint16_t i_inputWidth_u16,
                               const uint16_t i_inputHeight_u16,
                               uint8_t* o_image_pu8 );
    void FlipHorizontal( uint8_t* b_inputImage_pu8, const uint16_t i_inputWidth_u16, const uint16_t i_inputHeight_u16 );
    void FlipVertical( uint8_t* b_inputImage_pu8, const uint16_t i_inputWidth_u16, const uint16_t i_inputHeight_u16 );
    void FlipHorizontalPlanarW640H640( uint8_t* b_inputImage_pu8, const uint16_t i_inputWidth_u16, const uint16_t i_inputHeight_u16 );
    void FlipHorizontalGrayW640H400( uint8_t* i_inputImage_pu8, const uint16_t i_inputWidth_u16, const uint16_t i_inputHeight_u16, uint8_t* o_outputImage_pu8 );
    void FlipDiagGray( uint8_t* b_InputImg_pu8, uint16_t i_InputWidth_u16, uint16_t i_inputHeight_u16 );
    void FlipDiagRGBPlanar( uint8_t* b_InputImg_pu8, uint16_t i_InputWidth_u16, uint16_t i_inputHeight_u16 );
    void RGBInterleavedBiLinearResize( const uint8_t* i_InputImg_pu8, const int16_t i_inputwidth_u16, const int16_t i_inputHeight_u16, uint8_t* o_OutputImg_pu8, const int16_t i_outputWidth_u16, const int16_t i_outputHeight_u16 );
    void RGBPlanarBiLinearResize( uint8_t* i_InputImg_pu8, const uint32_t i_inputwidth_u16, const uint32_t i_inputHeight_u16, uint8_t* o_OutputImg_pu8, const uint32_t i_outputWidth_u16, const uint32_t i_outputHeight_u16 );
    void ConvertPlanar2Interleaved( const uint8_t* i_InputImgColor_pu8, uint8_t* o_OutImg_pu8, const uint16_t i_ImgWidth, const uint16_t i_ImgHeight );
    void ConvertInterleaved2Planar( const uint8_t* i_InputImgColor_pu8, uint8_t* o_OutImg_pu8, const uint16_t i_ImgWidth, const uint16_t i_ImgHeight );
	void vid_copyRearMirrorImageInPlace(uint8_t* vid_image);
}
#endif

