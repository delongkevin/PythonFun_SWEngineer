/*
Author: Christian Bailer
Contact address: Christian.Bailer@dfki.de
Department Augmented Vision DFKI

                          License Agreement
               For Open Source Computer Vision Library
                       (3-clause BSD License)

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  * Neither the names of the copyright holders nor the names of the contributors
    may be used to endorse or promote products derived from this software
    without specific prior written permission.

This software is provided by the copyright holders and contributors "as is" and
any express or implied warranties, including, but not limited to, the implied
warranties of merchantability and fitness for a particular purpose are disclaimed.
In no event shall copyright holders or contributors be liable for any direct,
indirect, incidental, special, exemplary, or consequential damages
(including, but not limited to, procurement of substitute goods or services;
loss of use, data, or profits; or business interruption) however caused
and on any theory of liability, whether in contract, strict liability,
or tort (including negligence or otherwise) arising in any way out of
the use of this software, even if advised of the possibility of such damage.
*/
#include "ffttoolsC.h"
namespace FFTToolsC
{
    static float32_t Re_P[tha::windowSize][tha::windowSize] = {};
    static float32_t Im_P[tha::windowSize][tha::windowSize] = {};
    static float32_t Re_F[tha::windowSize][tha::windowSize] = {};
    static float32_t Im_F[tha::windowSize][tha::windowSize] = {};
    static float32_t s[tha::windowSize][tha::windowSize] = {};

    /*
    * DFT calculation
    */
    void fftd_c( const mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img,
                 mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_Re,
                 mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_Imag )
    {
        const int32_t N = tha::windowSize;
        memcpy( &s, &i_Img( 0, 0 ), 4 * tha::windowSize * tha::windowSize );
        float32_t v_SumReal = 0;
        float32_t v_SumImag = 0;

        // Discrete Fourier Transform - Precomputation
        for( size_t v = 0; v < N; v++ )
        {
            for( size_t u = 0; u < N; u++ )
            {
                v_SumReal = 0.0;
                v_SumImag = 0.0;

                for( size_t x = 0; x < N; x++ )
                {
                    v_SumReal += s[v][x] * sin_table[( u * x + N / 4 ) % N];
                    v_SumImag -= s[v][x] * sin_table[u * x % N];
                }

                Re_P[v][u] = v_SumReal;
                Im_P[v][u] = v_SumImag;
            }
        }

        // Discrete Fourier Transform - Computation
        for( size_t u = 0; u < N; u++ )
        {
            for( size_t v = 0; v < N; v++ )
            {
                v_SumReal = 0.0;
                v_SumImag = 0.0;

                for( size_t y = 0; y < N; y++ )
                {
                    float32_t v_cosAngle = sin_table[( v * y + N / 4 ) % N];
                    float32_t v_sinAngle = sin_table[v * y % N];
                    v_SumReal += Re_P[y][u] * v_cosAngle + Im_P[y][u] * v_sinAngle;
                    v_SumImag += Im_P[y][u] * v_cosAngle - Re_P[y][u] * v_sinAngle;
                }

                Re_F[v][u] = v_SumReal;
                Im_F[v][u] = v_SumImag;
            }
        }

        memcpy( &o_Re( 0, 0 ), &Re_F, 4 * tha::windowSize * tha::windowSize );
        memcpy( &o_Imag( 0, 0 ), &Im_F, 4 * tha::windowSize * tha::windowSize );
    }
    /*
    * IDFT calculation
    */
    void idft_c( mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Re,
                 mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Im,
                 mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_idft )
    {
        const int32_t N = tha::windowSize;
        float32_t v_InputRe[tha::windowSize][tha::windowSize];
        float32_t v_InputIm[tha::windowSize][tha::windowSize];
        float32_t v_IDFT[N][N];
        memcpy( &v_InputRe, &i_Re( 0, 0 ), 4 * tha::windowSize * tha::windowSize );
        memcpy( &v_InputIm, &i_Im( 0, 0 ), 4 * tha::windowSize * tha::windowSize );
        float32_t v_SumReal = 0;
        float32_t v_SumImag = 0;

        // Inverse Discrete Fourier Transform - Precomputation
        for( size_t v = 0; v < N; v++ )
        {
            for( size_t u = 0; u < N; u++ )
            {
                v_SumReal = 0.0;
                v_SumImag = 0.0;

                for( size_t x = 0; x < N; x++ )
                {
                    float32_t cos_angle = sin_table[( u * x + N / 4 ) % N];
                    float32_t sin_angle = sin_table[u * x % N];
                    v_SumReal += v_InputRe[v][x] * cos_angle - v_InputIm[v][x] * sin_angle;
                    v_SumImag += v_InputIm[v][x] * cos_angle + v_InputRe[v][x] * sin_angle;
                }

                Re_P[v][u] = v_SumReal / static_cast<float32_t>( N );
                Im_P[v][u] = v_SumImag / static_cast<float32_t>( N );
            }
        }

        // Inverse Discrete Fourier Transform - Computation
        for( size_t u = 0; u < N; u++ )
        {
            for( size_t v = 0; v < N; v++ )
            {
                v_SumReal = 0.0;

                for( size_t y = 0; y < N; y++ )
                {
                    float32_t cos_angle = sin_table[( v * y + N / 4 ) % N];
                    float32_t sin_angle = sin_table[v * y % N];
                    v_SumReal += Re_P[y][u] * cos_angle - Im_P[y][u] * sin_angle;
                }

                v_IDFT[v][u] = v_SumReal / static_cast<float32_t>( N );
            }
        }

        memcpy( &o_idft( 0, 0 ), &v_IDFT, 4 * tha::windowSize * tha::windowSize );
    }
    /*
    * Multiply spectrums - Real part
    */
    void mulSpectrumsRe_c( mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real1,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real2,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img1,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img2,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_real )
    {
        o_real = i_Real1.mul( i_Real2 ) - i_Img1.mul( i_Img2 );
    }

    /*
    * Multiply spectrums - imag part
    */
    void mulSpectrumsIm_c( mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real1,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real2,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img1,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img2,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_Im )
    {
        o_Im = i_Real1.mul( i_Img2 ) + i_Img1.mul( i_Real2 );
    }

    /*
    * Complex Division - Real part
    */
    void complexDivisionRe_c( mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real1,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real2,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img1,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img2,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_Re )
    {
        o_Re = ( ( i_Real1.mul( i_Real2 ) + i_Img1.mul( i_Img2 ) ) / ( i_Real2.mul( i_Real2 ) + i_Img2.mul( i_Img2 ) ) );
    }

    /*
    * Complex Division - Imag part
    */
    void complexDivisionIm_c( mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real1,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real2,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img1,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img2,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_Im )
    {
        o_Im = ( ( i_Img1.mul( i_Real2 ) - i_Real1.mul( i_Img2 ) ) / ( i_Real2.mul( i_Real2 ) + i_Img2.mul( i_Img2 ) ) );
    }

    /*
    * Swap quadrants of image
    */
    void SwapQuadrants( mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_img )
    {
        float32_t v_temp = 0.0f;
        float32_t v_temp2 = 0.0f;

        for( uint16_t v_RowIndx = 0; v_RowIndx < ( tha::windowSize / 2 ); v_RowIndx++ )
        {
            for( uint16_t v_ColIndx = 0; v_ColIndx < ( tha::windowSize / 2 ); v_ColIndx++ )
            {
                // Swap 1st and 4th quadrant
                v_temp = i_img( v_RowIndx, v_ColIndx );
                v_temp2 = i_img( v_RowIndx + ( tha::windowSize / 2 ), v_ColIndx + ( tha::windowSize / 2 ) );
                i_img( v_RowIndx, v_ColIndx ) = v_temp2;
                i_img( v_RowIndx + ( tha::windowSize / 2 ), v_ColIndx + ( tha::windowSize / 2 ) ) = v_temp;
                // Swap 2nd and 3rd quadrant
                v_temp = i_img( v_RowIndx, v_ColIndx + ( tha::windowSize / 2 ) );
                v_temp2 = i_img( v_RowIndx + ( tha::windowSize / 2 ), v_ColIndx );
                i_img( v_RowIndx, v_ColIndx + ( tha::windowSize / 2 ) ) = v_temp2;
                i_img( v_RowIndx + ( tha::windowSize / 2 ), v_ColIndx ) = v_temp;
            }
        }
    }
}
