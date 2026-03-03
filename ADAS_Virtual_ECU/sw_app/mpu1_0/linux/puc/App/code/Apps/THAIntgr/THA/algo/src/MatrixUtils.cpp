#include "MatrixUtils.h"

#define THA_IMG_WIDTH	1920
#define THA_IMG_HEIGHT	1280
#define THA_G_OFFSET	(2 * THA_IMG_HEIGHT) - 1
#define THA_B_OFFSET	(3 * THA_IMG_HEIGHT) - 1
#define THA_IMG_SIZE	(THA_IMG_WIDTH * THA_IMG_HEIGHT)
 

namespace matrixUtil
{
    void transpose( const float32_t* src, float32_t* dst, const uint16_t N, const uint16_t M )
    {
        for( uint16_t n = 0; n < ( N * M ); n++ )
        {
            uint16_t i = n / N;
            uint16_t j = n % N;
            dst[n] = src[static_cast<uint16_t>( ( M * j ) + i )]; //PRQA S 3706
        }
    }

    void f32_MM( const float32_t* a, const float32_t* b, float32_t* dest, const uint16_t m, const uint16_t n, const uint16_t p )
    {
        for( uint16_t i = 0; i < m; i++ )
        {
            for( uint16_t j = 0; j < p; j++ )
            {
                *( dest + ( i * m ) + j ) = 0; //PRQA S 3705

                for( uint16_t k = 0; k < n; k++ )
                {
                    *( dest + ( i * p ) + j ) = ( *( dest + ( i * p ) + j ) ) + ( *( a + ( i * n ) + k ) ) * ( *( b + ( k * p ) + j ) ); //PRQA S 3705
                }
            }
        }
    }

    void f32_MV( const float32_t* a, const float32_t* b, float32_t* dest, uint16_t m, uint16_t n )
    {
        for( uint16_t i = 0; i < m; i++ )
        {
            *( dest + i ) = 0; //PRQA S 3705

            for( uint16_t j = 0; j < n; j++ )
            {
                *( dest + i ) = ( *( dest + i ) ) + ( *( a + ( i * n ) + j ) ) * ( *( b + j ) ); //PRQA S 3705
            }
        }
    }

    float32_t correlationCoefficient( const uint8_t* X, const uint8_t* Y, uint16_t x_step, uint16_t y_step, uint16_t width, uint16_t height )
    {
        float32_t sum_X = 0.0f;
        float32_t sum_Y = 0.0f;
        float32_t Mean_x;
        float32_t Mean_y;
        float32_t std_x;
        float32_t std_y;
        float32_t squareSum_X = 0.0f;
        float32_t squareSum_Y = 0.0f;
        float32_t result = 0.0f;

        for( uint16_t i = 0; i < height; i++ )
        {
            for( uint16_t j = 0; j < width; j++ )
            {
                // sum of elements of array X.
                sum_X = sum_X + static_cast<float32_t>( *( X + ( i * x_step ) + j ) ); //PRQA S 3705
                // sum of elements of array y.
                sum_Y = sum_Y + static_cast<float32_t>( *( Y + ( i * y_step ) + j ) ); //PRQA S 3705
            }
        }

        Mean_x = sum_X / static_cast<float32_t>( width * height );
        Mean_y = sum_Y / static_cast<float32_t>( width * height );

        for( uint16_t i = 0; i < height; i++ )
        {
            for( uint16_t j = 0; j < width; j++ )
            {
                // sum of elements of array X.
                squareSum_X = squareSum_X + ( static_cast<float32_t>( *( X + ( i * x_step ) + j ) ) - Mean_x ) * ( static_cast<float32_t>( *( X + ( i * x_step ) + j ) ) - Mean_x ); //PRQA S 3705
                // sum of elements of array X.
                squareSum_Y = squareSum_Y + ( static_cast<float32_t>( *( Y + ( i * y_step ) + j ) ) - Mean_y ) * ( static_cast<float32_t>( *( Y + ( i * y_step ) + j ) ) - Mean_y ); //PRQA S 3705
            }
        }

        std_x = sqrt( squareSum_X / static_cast<float32_t>( height * width ) );
        std_y = sqrt( squareSum_Y / static_cast<float32_t>( height * width ) );

        for( uint16_t i = 0; i < height; i++ )
        {
            for( uint16_t j = 0; j < width; j++ )
            {
                result = result + ( ( static_cast<float32_t>( *( X + ( i * x_step ) + j ) ) - Mean_x ) / std_x ) * ( ( static_cast<float32_t>( *( Y + ( i * y_step ) + j ) ) - Mean_y ) / std_y ); //PRQA S 3705
            }
        }

        // use formula for calculating correlation coefficient.
        float32_t corr = result / ( static_cast<float32_t>( height * width ) - 1.0f );
        return corr;
    }

    void CrossCorrValid_NormLevel_8u32f( const uint8_t* pSrc, uint16_t srcStep, uint16_t srcWidth, uint16_t srcHeight,
                                         const uint8_t* pTpl, uint16_t tplStep, uint16_t tplWidth, uint16_t tplHeight,
                                         float32_t* pDst, uint16_t dstStep )
    {
        uint16_t k = 0;

        for( uint16_t i = 0; ( i + tplHeight - 1 ) < srcHeight; i++ )
        {
            k = k + dstStep;
            pDst = pDst + k; //PRQA S 3705

            for( uint16_t j = 0; ( j + tplWidth - 1 ) < srcWidth; j++ )
            {
                *pDst = correlationCoefficient( pSrc + ( i * srcWidth ) + j, pTpl, srcStep, tplStep, tplWidth, tplHeight ); //PRQA S 3705
                k = k + 1;
                pDst = pDst + k; //PRQA S 3705
            }
        }
    }

    void getCofactor( const float32_t* A, float32_t* temp, const uint16_t p, const uint16_t q, const uint16_t n )
    {
        uint16_t i = 0;
        uint16_t j = 0;

        // Looping for each element of the matrix
        for( uint16_t row = 0; row < n; row++ )
        {
            for( uint16_t col = 0; col < n; col++ )
            {
                //  Copying uint16_to temporary matrix only those
                //  element which are not in given row and
                //  column
                if( ( row != p ) && ( col != q ) )
                {
                    *( temp + ( i * ( n - 1 ) ) + j ) = *( A + ( row * n ) + col ); //PRQA S 3705
                    j = j + 1;

                    // Row is filled, so increase row index and
                    // reset col index
                    if( j == ( n - 1 ) )
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }

    void iCopy_8u_C1R( const  uint8_t* src, uint16_t srcStep,
                       uint8_t* dest,
                       uint16_t dstStep,
                       uint16_t width,
                       uint16_t height )
    {
        for( uint16_t i = 0; i < height; i++ )
        {
            memcpy( dest + i * dstStep, src + i * srcStep, sizeof( uint8_t )*width ); //PRQA S 3705
        }
    }

    // takes input pointer of image to be cropped, cropped image pointer to be filled, and other details
    void cropRGBplanar( const uint8_t* i_inputImage_u8, const uint16_t i_inputHeight_u16, const uint16_t i_inputWidth_u16,
                        uint8_t* o_cropImage_u8, const uint16_t i_cropHeight_u16, const uint16_t i_cropWidth_u16,
                        const uint16_t i_cropStartX_u16, const uint16_t i_cropStartY_u16 )
    {
        uint32_t v_row_u32;
        uint32_t v_col_u32;
        uint32_t v_img_row_u32;
        uint32_t v_img_col_u32;
        uint32_t v_crop_index_u32; // iterator variables
        uint32_t v_cropOffset_u32 = ( i_cropWidth_u16 * i_cropHeight_u16 );
        uint32_t v_imgOffset_u32 = ( i_inputWidth_u16 * i_inputHeight_u16 );
        v_img_row_u32 = i_cropStartY_u16;

        for( v_row_u32 = 0; v_row_u32 < i_cropHeight_u16; v_row_u32++ )
        {
            v_img_col_u32 = i_cropStartX_u16;

            for( v_col_u32 = 0; v_col_u32 < i_cropWidth_u16; v_col_u32++ )
            {
                v_crop_index_u32 = ( ( v_row_u32 * static_cast<uint32_t>( i_cropWidth_u16 ) ) + v_col_u32 );
                o_cropImage_u8[v_crop_index_u32] = i_inputImage_u8[( v_img_row_u32 * ( i_inputWidth_u16 ) ) + v_img_col_u32]; //PRQA S 3706
                o_cropImage_u8[( v_cropOffset_u32 + v_crop_index_u32 )] = i_inputImage_u8[( v_imgOffset_u32 + ( v_img_row_u32 * static_cast<uint32_t>( i_inputWidth_u16 ) ) + v_img_col_u32 )]; //PRQA S 3706
                o_cropImage_u8[( ( 2 * v_cropOffset_u32 ) + v_crop_index_u32 )] = i_inputImage_u8[( ( 2 * v_imgOffset_u32 ) + ( v_img_row_u32 * static_cast<uint32_t>( i_inputWidth_u16 ) ) + v_img_col_u32 )]; //PRQA S 3706
                v_img_col_u32++;
            }

            v_img_row_u32++;
        }
    }

    void cropRGBinterleave( const uint8_t* i_inputImage_u8, const uint16_t i_inputWidth_u16,
                            uint8_t* o_cropImage_u8, const uint16_t i_cropHeight_u16, const uint16_t i_cropWidth_u16,
                            const uint16_t i_cropStartX_u16, const uint16_t i_cropStartY_u16 )
    {
        uint32_t v_row_u32;
        uint32_t v_col_u32;
        uint32_t v_img_row_u32;
        uint32_t v_img_col_u32;
        uint32_t v_crop_index_u32;
        uint32_t v_orig_img_index_u32; // iterator variables
        v_img_row_u32 = i_cropStartY_u16;

        for( v_row_u32 = 0; v_row_u32 < i_cropHeight_u16; v_row_u32++ )
        {
            v_img_col_u32 = i_cropStartX_u16;

            for( v_col_u32 = 0; v_col_u32 < i_cropWidth_u16; v_col_u32++ )
            {
                v_crop_index_u32 = ( ( v_row_u32 * ( static_cast<uint32_t>( i_cropWidth_u16 ) ) * 3 ) + ( v_col_u32 * 3 ) );
                v_orig_img_index_u32 = ( ( v_img_row_u32 * ( static_cast<uint32_t>( i_inputWidth_u16 ) ) * 3 ) + ( v_img_col_u32 * 3 ) );
                o_cropImage_u8[v_crop_index_u32] = i_inputImage_u8[v_orig_img_index_u32]; //PRQA S 3706
                o_cropImage_u8[v_crop_index_u32 + 1] = i_inputImage_u8[v_orig_img_index_u32 + 1]; //PRQA S 3706
                o_cropImage_u8[v_crop_index_u32 + 2] = i_inputImage_u8[v_orig_img_index_u32 + 2]; //PRQA S 3706
                v_img_col_u32++;
            }

            v_img_row_u32++;
        }
    }

    void GrayBiLinearResize( const uint8_t* i_inputImg_u8,
                             const uint16_t i_inputwidth_u16,
                             const uint16_t i_inputHeight_u16,
                             uint8_t* o_outputImg_u8,
                             const uint16_t i_outputWidth_u16,
                             const uint16_t i_outputHeight_u16 )
    {
        int32_t v_A_s32 = 0;
        int32_t v_B_s32 = 0;
        int32_t v_C_s32 = 0;
        int32_t v_D_s32 = 0;
        int32_t v_x_s32 = 0;
        int32_t v_y_s32 = 0;
        uint32_t v_index_u32 = 0;
        uint8_t v_gray_u8 = 0;
        float32_t v_xRatio_f32 = ( static_cast<float32_t>( i_inputwidth_u16 - 1 ) ) / static_cast<float32_t>( i_outputWidth_u16 );
        float32_t v_yRatio_f32 = ( static_cast<float32_t>( i_inputHeight_u16 - 1 ) ) / static_cast<float32_t>( i_outputHeight_u16 );
        float32_t v_xDiff_f32 = 0.0f;
        float32_t v_yDiff_f32 = 0.0f;
        uint32_t v_pixPosition_u32 = 0;

        /* Check whether the image sizes are equal */
        if( ( i_inputwidth_u16 == i_outputWidth_u16 ) && ( i_inputHeight_u16 == i_outputHeight_u16 ) )
        {
            memcpy( o_outputImg_u8, i_inputImg_u8, i_inputwidth_u16 * i_inputHeight_u16 );
        }

        for( uint16_t iIndex = 0; iIndex < i_outputHeight_u16; iIndex++ )
        {
            for( uint16_t jIndex = 0; jIndex < i_outputWidth_u16; jIndex++ )
            {
                v_pixPosition_u32 = iIndex * i_outputWidth_u16 + jIndex;
                v_x_s32 = static_cast<int32_t>( ( v_xRatio_f32 * static_cast<float32_t>( jIndex ) ) + 0.5f );
                v_y_s32 = static_cast<int32_t>( ( v_yRatio_f32 * static_cast<float32_t>( iIndex ) ) + 0.5f );
                // Assign data from Source image
                v_xDiff_f32 = ( v_xRatio_f32 * static_cast<float32_t>( jIndex ) ) - static_cast<float32_t>( v_x_s32 );
                v_yDiff_f32 = ( v_yRatio_f32 * static_cast<float32_t>( iIndex ) ) - static_cast<float32_t>( v_y_s32 );
                v_index_u32 = v_y_s32 * static_cast<int32_t>( i_inputwidth_u16 ) + v_x_s32;
                // range is 0 to 255 thus bitwise AND with 0xff
                v_A_s32 = static_cast<uint32_t>( i_inputImg_u8[v_index_u32]  & static_cast<uint8_t>( 0xff ) ) ; //PRQA S 3706
                v_B_s32 = static_cast<uint32_t>( i_inputImg_u8[v_index_u32 + static_cast<uint32_t>( 1 )] & static_cast<uint8_t>( 0xff ) ); //PRQA S 3706
                v_C_s32 = static_cast<uint32_t>( i_inputImg_u8[v_index_u32 + i_inputwidth_u16] & static_cast<uint8_t>( 0xff ) ); //PRQA S 3706
                v_D_s32 = static_cast<uint32_t>( i_inputImg_u8[v_index_u32 + i_inputwidth_u16 + 1] & static_cast<uint8_t>( 0xff ) ); //PRQA S 3706
                uint8_t v_A_mult_u8 = static_cast<uint8_t>( v_A_s32 ) * ( 1 - static_cast<uint8_t>( v_xDiff_f32 ) ) * ( 1 - static_cast<uint8_t>( v_yDiff_f32 ) );
                uint8_t v_B_mult_u8 = static_cast<uint8_t>( v_B_s32 ) * static_cast<uint8_t>( v_xDiff_f32 ) * ( 1 - static_cast<uint8_t>( v_yDiff_f32 ) );
                uint8_t v_C_mult_u8 = static_cast<uint8_t>( v_C_s32 ) * static_cast<uint8_t>( v_yDiff_f32 ) * ( 1 - static_cast<uint8_t>( v_xDiff_f32 ) );
                uint8_t v_D_mult_u8 = static_cast<uint8_t>( v_D_s32 ) * ( static_cast<uint8_t>( v_xDiff_f32 ) * static_cast<uint8_t>( v_yDiff_f32 ) );
                v_gray_u8 = v_A_mult_u8 + v_B_mult_u8 + v_C_mult_u8 + v_D_mult_u8;
                o_outputImg_u8[static_cast<uint32_t>( iIndex *  i_outputWidth_u16 + jIndex )] = v_gray_u8; //PRQA S 3706
                o_outputImg_u8[v_pixPosition_u32] = v_gray_u8; //PRQA S 3706
            }
        }
    }

    void RGBPlanartoGray( const uint8_t* i_inputImage_pu8, const uint16_t i_inputWidth_u16, const uint16_t i_inputHeight_u16, uint8_t* o_image_pu8 )
    {
        uint32_t v_imgOffset_u32 = ( i_inputWidth_u16 * i_inputHeight_u16 );

        for( uint16_t v_img_row_u16 = 0; v_img_row_u16 < i_inputHeight_u16; v_img_row_u16++ )
        {
            for( uint16_t v_img_col_u16 = 0; v_img_col_u16 < i_inputWidth_u16; v_img_col_u16++ )
            {
                uint8_t v_PixR = i_inputImage_pu8[static_cast<uint32_t>( ( v_img_row_u16 * ( i_inputWidth_u16 ) ) + v_img_col_u16 )]; //PRQA S 3706
                uint8_t v_PixG = i_inputImage_pu8[( v_imgOffset_u32 + ( v_img_row_u16 * static_cast<uint32_t>( i_inputWidth_u16 ) ) + v_img_col_u16 )]; //PRQA S 3706
                uint8_t v_PixB = i_inputImage_pu8[( ( 2 * v_imgOffset_u32 ) + ( v_img_row_u16 * static_cast<uint32_t>( i_inputWidth_u16 ) ) + v_img_col_u16 )]; //PRQA S 3706
                // Converting RGB to grayscale using [ grayscale = ((0.3 * R) + (0.59 * G) + (0.11 * B)) ]
                o_image_pu8[static_cast<uint32_t>( ( v_img_row_u16 * i_inputWidth_u16 ) + v_img_col_u16 )] = static_cast<uint8_t>( ( 0.3 * static_cast<float32_t>( v_PixR ) ) + ( 0.59 * static_cast<float32_t>( v_PixG ) ) + ( 0.11 * static_cast<float32_t>( v_PixB ) ) ); //PRQA S 3706
            }
        }
    }

    void RGBInterleavedtoGray( const uint8_t* i_inputImage_pu8, const uint16_t i_inputWidth_u16, const uint16_t i_inputHeight_u16, uint8_t* o_image_pu8 )
    {
        uint8_t v_PixR = 0;
        uint8_t v_PixG = 0;
        uint8_t v_PixB = 0;

        for( uint16_t v_img_row_u16 = 0; v_img_row_u16 < i_inputHeight_u16; v_img_row_u16++ )
        {
            for( uint16_t v_img_col_u16 = 0; v_img_col_u16 < i_inputWidth_u16; v_img_col_u16++ )
            {
                v_PixR = i_inputImage_pu8[static_cast<uint32_t>( ( v_img_row_u16 * i_inputWidth_u16 * static_cast<uint16_t>( 3 ) ) + ( v_img_col_u16 * static_cast<uint16_t>( 3 ) ) + static_cast<uint16_t>( 0 ) )]; //PRQA S 3706
                v_PixG = i_inputImage_pu8[static_cast<uint32_t>( ( v_img_row_u16 * i_inputWidth_u16 * static_cast<uint16_t>( 3 ) ) + ( v_img_col_u16 * static_cast<uint16_t>( 3 ) ) + static_cast<uint16_t>( 1 ) )]; //PRQA S 3706
                v_PixB = i_inputImage_pu8[static_cast<uint32_t>( ( v_img_row_u16 * i_inputWidth_u16 * static_cast<uint16_t>( 3 ) ) + ( v_img_col_u16 * static_cast<uint16_t>( 3 ) ) + static_cast<uint16_t>( 2 ) )]; //PRQA S 3706
                // Converting RGB to grayscale using [ grayscale = ((0.3 * R) + (0.59 * G) + (0.11 * B)) ]
                o_image_pu8[static_cast<uint32_t>( ( v_img_row_u16 * i_inputWidth_u16 ) + v_img_col_u16 )] = static_cast<uint8_t>( ( 0.3 * static_cast<float32_t>( v_PixR ) ) + ( 0.59 * static_cast<float32_t>( v_PixG ) ) + ( 0.11 * static_cast<float32_t>( v_PixB ) ) ); //PRQA S 3706
            }
        }
    }

    void FlipHorizontal( uint8_t* b_inputImage_pu8, const uint16_t i_inputWidth_u16, const uint16_t i_inputHeight_u16 )
    {
        uint8_t v_temp[3] = { 0 };
        uint8_t* v_PxL;
        uint8_t* v_PxR;
        uint16_t v_noChannels = 3;

        for( uint16_t v_col_u16 = 0; v_col_u16 < i_inputHeight_u16; ++v_col_u16 )
        {
            for( uint16_t v_row_u16 = 0; v_row_u16 < ( i_inputWidth_u16 / 2 ); ++v_row_u16 )
            {
                v_PxL = &b_inputImage_pu8[static_cast<uint32_t>( ( v_row_u16 + v_col_u16 * i_inputWidth_u16 ) * v_noChannels )]; //PRQA S 3706
                v_PxR = &b_inputImage_pu8[static_cast<uint32_t>( ( ( i_inputWidth_u16 - 1 - v_row_u16 ) + v_col_u16 * i_inputWidth_u16 ) * v_noChannels )]; //PRQA S 3706
                memcpy( v_temp, v_PxL, v_noChannels ); //PRQA S 3840
                memcpy( v_PxL, v_PxR, v_noChannels );
                memcpy( v_PxR, v_temp, v_noChannels ); //PRQA S 3840
            }
        }
    }

    void FlipVertical( uint8_t* b_inputImage_pu8, const uint16_t i_inputWidth_u16, const uint16_t i_inputHeight_u16 )
    {
        uint8_t v_temp[3] = { 0 };
        uint8_t* v_PxT;
        uint8_t* v_PxB;
        uint16_t v_noChannels = 3;

        for( uint16_t v_row_u16 = 0; v_row_u16 < i_inputWidth_u16; ++v_row_u16 )
        {
            for( uint16_t v_col_u16 = 0; v_col_u16 < ( i_inputHeight_u16 / 2 ); ++v_col_u16 )
            {
                v_PxT = &b_inputImage_pu8[static_cast<uint32_t>( ( v_row_u16 + v_col_u16 * i_inputWidth_u16 ) * v_noChannels )]; //PRQA S 3706
                v_PxB = &b_inputImage_pu8[static_cast<uint32_t>( ( v_row_u16 + ( i_inputHeight_u16 - static_cast<uint16_t>( 1 ) - v_col_u16 ) * i_inputWidth_u16 ) * v_noChannels )]; //PRQA S 3706
                memcpy( v_temp, v_PxT, v_noChannels ); //PRQA S 3840
                memcpy( v_PxT, v_PxB, v_noChannels );
                memcpy( v_PxB, v_temp, v_noChannels ); //PRQA S 3840
            }
        }
    }
    void FlipHorizontalGrayW640H400( uint8_t* i_inputImage_pu8, const uint16_t i_inputWidth_u16, const uint16_t i_inputHeight_u16, uint8_t* o_outputImage_pu8 )
    {
        uint8_t* v_PxT;
        uint8_t* v_PxB;
        uint8_t* v_temp = o_outputImage_pu8;
        uint16_t v_inputHeightLast_u16 = i_inputHeight_u16 - 1;

        for( uint16_t v_img_row_u32 = 0; v_img_row_u32 < ( i_inputHeight_u16 / 2 ); v_img_row_u32++ )
        {
            v_temp = o_outputImage_pu8 + ( v_img_row_u32 * i_inputWidth_u16 ); // PRQA S 3705
            v_PxT = &i_inputImage_pu8[static_cast<uint32_t>( v_img_row_u32 * ( i_inputWidth_u16 ) )]; //PRQA S 3706
            v_PxB = &i_inputImage_pu8[static_cast<uint32_t>( ( v_inputHeightLast_u16 - v_img_row_u32 ) * ( i_inputWidth_u16 ) )]; //PRQA S 3706
            memcpy( v_temp, v_PxB, 640 );
            v_temp = o_outputImage_pu8 + ( v_inputHeightLast_u16 - v_img_row_u32 ) * ( i_inputWidth_u16 ); // PRQA S 3705
            memcpy( v_temp, v_PxT, 640 ); //PRQA S 3840
        }
    }

    void FlipHorizontalPlanarW640H640( uint8_t* b_inputImage_pu8, const uint16_t i_inputWidth_u16, const uint16_t i_inputHeight_u16 )
    {
        uint8_t v_temp[640] = { 0 };
        uint8_t* v_PxT;
        uint8_t* v_PxB;
        uint16_t v_inputHeightLast_u16 = i_inputHeight_u16 - 1;
        uint32_t v_imgOffset_u32 = ( i_inputWidth_u16 * i_inputHeight_u16 );

        for( uint16_t v_img_row_u32 = 0; v_img_row_u32 < ( i_inputHeight_u16 / 2 ); v_img_row_u32++ )
        {
            v_PxT = &b_inputImage_pu8[static_cast<uint32_t>( v_img_row_u32 * ( i_inputWidth_u16 ) )]; //PRQA S 3706
            v_PxB = &b_inputImage_pu8[static_cast<uint32_t>( ( v_inputHeightLast_u16 - v_img_row_u32 ) * ( i_inputWidth_u16 ) )]; //PRQA S 3706
            memcpy( v_temp, v_PxT, 640 ); //PRQA S 3840
            memcpy( v_PxT, v_PxB, 640 );
            memcpy( v_PxB, v_temp, 640 ); //PRQA S 3840
            v_PxT = &b_inputImage_pu8[( v_imgOffset_u32 + ( v_img_row_u32 * static_cast<uint32_t>( i_inputWidth_u16 ) ) )]; //PRQA S 3706
            v_PxB = &b_inputImage_pu8[( v_imgOffset_u32 + ( ( v_inputHeightLast_u16 - v_img_row_u32 ) * static_cast<uint32_t>( i_inputWidth_u16 ) ) )]; //PRQA S 3706
            memcpy( v_temp, v_PxT, 640 ); //PRQA S 3840
            memcpy( v_PxT, v_PxB, 640 );
            memcpy( v_PxB, v_temp, 640 );//PRQA S 3840
            v_PxT = &b_inputImage_pu8[( ( 2 * v_imgOffset_u32 ) + ( v_img_row_u32 * static_cast<uint32_t>( i_inputWidth_u16 ) ) )]; //PRQA S 3706
            v_PxB = &b_inputImage_pu8[( ( 2 * v_imgOffset_u32 ) + ( ( v_inputHeightLast_u16 - v_img_row_u32 ) * static_cast<uint32_t>( i_inputWidth_u16 ) ) )]; //PRQA S 3706
            memcpy( v_temp, v_PxT, 640 ); //PRQA S 3840
            memcpy( v_PxT, v_PxB, 640 );
            memcpy( v_PxB, v_temp, 640 ); //PRQA S 3840
        }
    }

    void RGBInterleavedBiLinearResize( const uint8_t* i_InputImg_pu8, const int16_t i_inputwidth_u16, const int16_t i_inputHeight_u16, uint8_t* o_OutputImg_pu8, const int16_t i_outputWidth_u16, const int16_t i_outputHeight_u16 )
    {
        float64_t v_XRatio = static_cast<float64_t>( i_outputWidth_u16 ) / static_cast<float64_t>( i_inputwidth_u16 );
        float64_t v_YRatio = static_cast<float64_t>( i_outputHeight_u16 ) / static_cast<float64_t>( i_inputHeight_u16 );

        for( int16_t iIndex = 0; iIndex < i_outputHeight_u16; iIndex++ )
        {
            for( int16_t jIndex = 0; jIndex < i_outputWidth_u16; jIndex++ )
            {
                int32_t v_PixelPos = ( iIndex * ( i_outputWidth_u16 * 3 ) ) + ( jIndex * 3 );
                int32_t v_NearestMatch = ( ( static_cast<int32_t>( static_cast<float64_t>( iIndex ) / v_YRatio ) * ( i_inputwidth_u16 * 3 ) ) + ( static_cast<int32_t>( static_cast<float64_t>( jIndex ) / v_XRatio ) * 3 ) );
                o_OutputImg_pu8[v_PixelPos] = i_InputImg_pu8[v_NearestMatch]; //PRQA S 3706
                o_OutputImg_pu8[v_PixelPos + 1] = i_InputImg_pu8[v_NearestMatch + 1]; //PRQA S 3706
                o_OutputImg_pu8[v_PixelPos + 2] = i_InputImg_pu8[v_NearestMatch + 2]; //PRQA S 3706
            }
        }
    }

    void RGBPlanarBiLinearResize( uint8_t* i_InputImg_pu8, const uint32_t i_inputwidth_u16, const uint32_t i_inputHeight_u16, uint8_t* o_OutputImg_pu8, const uint32_t i_outputWidth_u16, const uint32_t i_outputHeight_u16 )
    {
        int32_t v_A = 0;
        int32_t v_B = 0;
        int32_t v_C = 0;
        int32_t v_D = 0;
        int32_t v_x = 0;
        int32_t v_y = 0;
        uint32_t v_index_u32 = 0;
        uint8_t v_gray1 = 0;
        uint8_t v_gray2 = 0;
        uint8_t v_gray3 = 0;
        float32_t v_XRatio = ( static_cast<float32_t>( i_inputwidth_u16 - 1 ) ) / i_outputWidth_u16;
        float32_t v_YRatio = ( static_cast<int32_t>( i_inputHeight_u16 - 1 ) ) / i_outputHeight_u16;
        float32_t v_XDiff = 0.0f;
        float32_t v_YDiff = 0.0f;
        int32_t v_StrideU = i_outputWidth_u16 * i_outputWidth_u16;
        int32_t v_StrideV = 2 * i_outputWidth_u16 * i_outputWidth_u16;
        uint32_t v_PixPosition;

        /* Check whether the files sizes are equal */
        if( ( i_inputwidth_u16 == i_outputWidth_u16 ) && ( i_inputHeight_u16 == i_outputHeight_u16 ) )
        {
            o_OutputImg_pu8 = i_InputImg_pu8;
        }
        else
        {
            for( uint32_t iIndex = 0; iIndex < i_outputHeight_u16; iIndex++ )
            {
                for( uint32_t jIndex = 0; jIndex < i_outputWidth_u16; jIndex++ )
                {
                    v_PixPosition = iIndex * i_outputWidth_u16 + jIndex;
                    v_x = static_cast<int32_t>( v_XRatio * jIndex );
                    v_y = static_cast<int32_t>( v_YRatio * iIndex );
                    /* Just assign data from Source image here that is it */
                    v_XDiff = ( v_XRatio * jIndex ) - v_x;
                    v_YDiff = ( v_YRatio * iIndex ) - v_y;
                    v_index_u32 = v_y * i_inputwidth_u16 + v_x;
                    // range is 0 to 255 thus bitwise AND with 0xff
                    v_A = i_InputImg_pu8[v_index_u32] & 0xff; //PRQA S 3706
                    v_B = i_InputImg_pu8[v_index_u32 + 1] & 0xff; //PRQA S 3706
                    v_C = i_InputImg_pu8[v_index_u32 + i_inputwidth_u16] & 0xff; //PRQA S 3706
                    v_D = i_InputImg_pu8[v_index_u32 + i_inputwidth_u16 + 1] & 0xff; //PRQA S 3706
                    v_gray1 = static_cast<uint8_t>(
                                  v_A * ( 1 - v_XDiff ) * ( 1 - v_YDiff ) + v_B * ( v_XDiff ) * ( 1 - v_YDiff ) +
                                  v_C * ( v_YDiff ) * ( 1 - v_XDiff ) + v_D * ( v_XDiff * v_YDiff )
                              );
                    o_OutputImg_pu8[iIndex * i_outputWidth_u16 + jIndex] = v_gray1; //PRQA S 3706
                    v_index_u32 = v_y * i_inputwidth_u16 + v_x + ( i_inputwidth_u16 * i_inputHeight_u16 );
                    v_A = i_InputImg_pu8[v_index_u32] & 0xff; //PRQA S 3706
                    v_B = i_InputImg_pu8[v_index_u32 + 1] & 0xff; //PRQA S 3706
                    v_C = i_InputImg_pu8[v_index_u32 + i_inputwidth_u16] & 0xff; //PRQA S 3706
                    v_D = i_InputImg_pu8[v_index_u32 + i_inputwidth_u16 + 1] & 0xff; //PRQA S 3706
                    v_gray2 = static_cast<uint8_t>(
                                  v_A * ( 1 - v_XDiff ) * ( 1 - v_YDiff ) + v_B * ( v_XDiff ) * ( 1 - v_YDiff ) +
                                  v_C * ( v_YDiff ) * ( 1 - v_XDiff ) + v_D * ( v_XDiff * v_YDiff )
                              );
                    o_OutputImg_pu8[v_PixPosition + v_StrideU] = v_gray2; //PRQA S 3706
                    v_index_u32 = v_y * i_inputwidth_u16 + v_x + ( 2 * i_inputwidth_u16 * i_inputHeight_u16 );
                    v_A = i_InputImg_pu8[v_index_u32] & 0xff; //PRQA S 3706
                    v_B = i_InputImg_pu8[v_index_u32 + 1] & 0xff; //PRQA S 3706
                    v_C = i_InputImg_pu8[v_index_u32 + i_inputwidth_u16] & 0xff; //PRQA S 3706
                    v_D = i_InputImg_pu8[v_index_u32 + i_inputwidth_u16 + 1] & 0xff; //PRQA S 3706
                    v_gray3 = static_cast<uint8_t>(
                                  v_A * ( 1 - v_XDiff ) * ( 1 - v_YDiff ) + v_B * ( v_XDiff ) * ( 1 - v_YDiff ) +
                                  v_C * ( v_YDiff ) * ( 1 - v_XDiff ) + v_D * ( v_XDiff * v_YDiff )
                              );
                    o_OutputImg_pu8[v_PixPosition + v_StrideV] = v_gray3; //PRQA S 3706
                    o_OutputImg_pu8[v_PixPosition] = static_cast<uint8_t>( v_gray1 ); //PRQA S 3706
                }
            }
        }
    }

    void ConvertPlanar2Interleaved( const uint8_t* i_InputImgColor_pu8, uint8_t* o_OutImg_pu8, const uint16_t i_ImgWidth, const uint16_t i_ImgHeight )
    {
        uint32_t bufsize = i_ImgWidth * i_ImgHeight;
        uint64_t j = 0;

        for( uint64_t i = 0; ( i < ( bufsize * 3 ) ) && ( j < bufsize ); j++ )
        {
            o_OutImg_pu8[i] = i_InputImgColor_pu8[j + ( bufsize * 2 )]; //PRQA S 3706
            o_OutImg_pu8[i + 1] = i_InputImgColor_pu8[j + bufsize];//PRQA S 3706
            o_OutImg_pu8[i + 2] = i_InputImgColor_pu8[j];//PRQA S 3706
            i = i + 3;
        }
    }

    void ConvertInterleaved2Planar( const uint8_t* i_InputImgColor_pu8, uint8_t* o_OutImg_pu8, const uint16_t i_ImgWidth, const uint16_t i_ImgHeight )
    {
        uint32_t bufsize = i_ImgWidth * i_ImgHeight;
        uint64_t j = 0;

        for( uint64_t i = 0; ( i < bufsize ) && ( j < ( bufsize * 3 ) ); i++ )
        {
            o_OutImg_pu8[i] = i_InputImgColor_pu8[j]; //PRQA S 3706
            o_OutImg_pu8[i + bufsize] = i_InputImgColor_pu8[j + 1];//PRQA S 3706
            o_OutImg_pu8[i + ( bufsize * 2 )] = i_InputImgColor_pu8[j + 2];//PRQA S 3706
            j = j + 3;
        }
    }

    void FlipDiagGray( uint8_t* b_InputImg_pu8, uint16_t i_InputWidth_u16, uint16_t i_inputHeight_u16 )
    {
        uint8_t v_temp_u8;
        uint16_t v_InputWidthLast_u16 = i_InputWidth_u16 - 1;
        uint16_t v_InputHeightLast_u16 = i_inputHeight_u16 - 1;

        for( uint16_t v_row_u16 = 0; v_row_u16 < ( i_inputHeight_u16 / 2 ); v_row_u16++ )
        {
            uint32_t v_InRowIndx_u32 = v_row_u16 * i_InputWidth_u16;
            uint32_t v_InRowIndxFlip_u32 = ( ( v_InputHeightLast_u16 - v_row_u16 ) * i_InputWidth_u16 );

            for( uint16_t v_col_u16 = 0; v_col_u16 < i_InputWidth_u16; v_col_u16++ )
            {
                v_temp_u8 = b_InputImg_pu8[v_InRowIndx_u32 + v_col_u16];//PRQA S 3706
                b_InputImg_pu8[v_InRowIndx_u32 + v_col_u16] = b_InputImg_pu8[v_InRowIndxFlip_u32 + ( v_InputWidthLast_u16 - v_col_u16 )];//PRQA S 3706
                b_InputImg_pu8[v_InRowIndxFlip_u32 + ( v_InputWidthLast_u16 - v_col_u16 )] = v_temp_u8;//PRQA S 3706
            }
        }
    }

    void FlipDiagRGBPlanar( uint8_t* b_InputImg_pu8, uint16_t i_InputWidth_u16, uint16_t i_inputHeight_u16 )
    {
        uint8_t v_temp_u8;
        uint16_t v_InputWidthLast_u16 = i_InputWidth_u16 - 1;
        uint16_t v_InputHeightLast_u16 = i_inputHeight_u16 - 1;
        uint32_t v_imgOffset_u32 = i_InputWidth_u16 * i_inputHeight_u16;

        for( uint16_t v_row_u16 = 0; v_row_u16 < ( i_inputHeight_u16 / 2 ); v_row_u16++ )
        {
            uint32_t v_InRowIndxR_u32 = v_row_u16 * ( i_InputWidth_u16 );
            uint32_t v_InRowIndxFlipR_u32 = ( ( v_InputHeightLast_u16 - v_row_u16 ) * ( i_InputWidth_u16 ) );
            uint32_t v_InRowIndxG_u32 = v_row_u16 * ( i_InputWidth_u16 ) + ( 1 * v_imgOffset_u32 );
            uint32_t v_InRowIndxFlipG_u32 = ( ( v_InputHeightLast_u16 - v_row_u16 ) * ( i_InputWidth_u16 ) ) + ( 1 * v_imgOffset_u32 );
            uint32_t v_InRowIndxB_u32 = v_row_u16 * ( i_InputWidth_u16 ) + ( 2 * v_imgOffset_u32 );
            uint32_t v_InRowIndxFlipB_u32 = ( ( v_InputHeightLast_u16 - v_row_u16 ) * ( i_InputWidth_u16 ) ) + ( 2 * v_imgOffset_u32 );

            for( uint16_t v_col_u16 = 0; v_col_u16 < i_InputWidth_u16; v_col_u16++ )
            {
                v_temp_u8 = b_InputImg_pu8[v_InRowIndxR_u32 + v_col_u16];//PRQA S 3706
                b_InputImg_pu8[v_InRowIndxR_u32 + v_col_u16] = b_InputImg_pu8[v_InRowIndxFlipR_u32 + ( v_InputWidthLast_u16 - v_col_u16 )];//PRQA S 3706
                b_InputImg_pu8[v_InRowIndxFlipR_u32 + ( v_InputWidthLast_u16 - v_col_u16 )] = v_temp_u8;//PRQA S 3706
                v_temp_u8 = b_InputImg_pu8[v_InRowIndxG_u32 + v_col_u16];//PRQA S 3706
                b_InputImg_pu8[v_InRowIndxG_u32 + v_col_u16] = b_InputImg_pu8[v_InRowIndxFlipG_u32 + ( v_InputWidthLast_u16 - v_col_u16 )];//PRQA S 3706
                b_InputImg_pu8[v_InRowIndxFlipG_u32 + ( v_InputWidthLast_u16 - v_col_u16 )] = v_temp_u8;//PRQA S 3706
                v_temp_u8 = b_InputImg_pu8[v_InRowIndxB_u32 + v_col_u16];//PRQA S 3706
                b_InputImg_pu8[v_InRowIndxB_u32 + v_col_u16] = b_InputImg_pu8[v_InRowIndxFlipB_u32 + ( v_InputWidthLast_u16 - v_col_u16 )];//PRQA S 3706
                b_InputImg_pu8[v_InRowIndxFlipB_u32 + ( v_InputWidthLast_u16 - v_col_u16 )] = v_temp_u8;//PRQA S 3706
            }
        }
    }


//Function from sala for left to right flip v2 - 23/11
void vid_copyRearMirrorImageInPlace(uint8_t* vid_image)
{
    uint16_t vid_FileHeader_ImageHeight_u16 = 1920; //640*3
    uint16_t vid_FileHeader_ImageWidth_u16 = 640;
    uint32_t height_offset = 0 * vid_FileHeader_ImageWidth_u16; //starting from line 0
    uint32_t width_offset = vid_FileHeader_ImageWidth_u16 - 1; //639
    uint32_t half_width = vid_FileHeader_ImageWidth_u16 / 2; //320
    uint8_t  temp;
    for (uint32_t j = 0; j < vid_FileHeader_ImageHeight_u16; j++) //1920 = 640 * 3 for R, G, B planes
    {
        for (uint32_t i = 0; i < half_width; i++)
        {
            temp = vid_image[height_offset + i];
            vid_image[height_offset + i] = vid_image[height_offset + (width_offset - i)];
            vid_image[height_offset + (width_offset - i)] = temp;
        }
        height_offset += vid_FileHeader_ImageWidth_u16;
    }
}

}

