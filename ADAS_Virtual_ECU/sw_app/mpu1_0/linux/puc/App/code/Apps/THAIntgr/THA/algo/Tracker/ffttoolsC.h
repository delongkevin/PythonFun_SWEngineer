#ifndef FFTTOOLSC_H
#define FFTTOOLSC_H

#ifdef _WIN32
    #include <MECL/mecl.h>
#else
    #include "mecl/mecl.h"
#endif // _WIN32
#include "../common/THAParams.h"

namespace FFTToolsC
{
    static float32_t sin_table[64] =
    {
        0, 0.0980171, 0.19509, 0.290285, 0.382683, 0.471397, 0.55557, 0.634393,
        0.707107, 0.77301, 0.83147, 0.881921, 0.92388, 0.95694, 0.980785, 0.995185,
        1.0f, 0.995185, 0.980785, 0.95694, 0.92388, 0.881921, 0.83147, 0.77301,
        0.707107, 0.634393, 0.55557, 0.471397, 0.382683, 0.290285, 0.19509, 0.0980171,
        1.22465e-16, -0.0980171, -0.19509, -0.290285, -0.382683, -0.471397, -0.55557, -0.634393,
        -0.707107, -0.77301, -0.83147, -0.881921, -0.92388, -0.95694, -0.980785, -0.995185,
        -1.0f, -0.995185, -0.980785, -0.95694, -0.92388, -0.881921, -0.83147, -0.77301,
        -0.707107, -0.634393, -0.55557, -0.471397, -0.382683, -0.290285, -0.19509, -0.0980171
    };

    /*
    * DFT calculation
    */
    void fftd_c( const mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img,
                 mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_Re,
                 mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_Imag );
    /*
    * IDFT calculation
    */
    void idft_c( mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Re,
                 mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Im,
                 mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_idft );
    /*
    * Multiply spectrums - Real part
    */
    void mulSpectrumsRe_c( mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real1,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real2,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img1,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img2,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_real );
    /*
    * Multiply spectrums - imag part
    */
    void mulSpectrumsIm_c( mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real1,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real2,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img1,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img2,
                           mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_Im );
    /*
    * Complex Division - Real part
    */
    void complexDivisionRe_c( mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real1,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real2,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img1,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img2,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_Re );
    /*
    * Complex Division - Imag part
    */
    void complexDivisionIm_c( mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real1,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Real2,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img1,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_Img2,
                              mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& o_Im );
    /*
    * Swap quadrants of image
    */
    void SwapQuadrants( mecl::core::Matrix<float32_t, tha::windowSize, tha::windowSize, e_Default>& i_img );
}
#endif // !FFTTOOLSC_H