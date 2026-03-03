/*

Tracker based on Kernelized Correlation Filter (KCF) [1] and Circulant Structure with Kernels (CSK) [2].
CSK is implemented by using raw gray level features, since it is a single-channel filter.
KCF is implemented by using HOG features (the default), since it extends CSK to multiple channels.

[1] J. F. Henriques, R. Caseiro, P. Martins, J. Batista,
"High-Speed Tracking with Kernelized Correlation Filters", TPAMI 2015.

[2] J. F. Henriques, R. Caseiro, P. Martins, J. Batista,
"Exploiting the Circulant Structure of Tracking-by-detection with Kernels", ECCV 2012.

Authors: Joao Faro, Christian Bailer, Joao F. Henriques
Contacts: joaopfaro@gmail.com, Christian.Bailer@dfki.de, henriques@isr.uc.pt
Institute of Systems and Robotics - University of Coimbra / Department Augmented Vision DFKI


Constructor parameters, all boolean:
    hog: use HOG features (default), otherwise use raw pixels
    fixed_window: fix window size (default), otherwise use ROI size (slower but more accurate)
    multiscale: use multi-scale tracking (default; cannot be used with fixed_window = true)

Default values are set for all properties of the tracker depending on the above choices.
Their values can be customized further before calling init():
    interp_factor: linear interpolation factor for adaptation
    sigma: gaussian kernel bandwidth
    lambda: regularization
    cell_size: HOG cell size
    padding: horizontal area surrounding the target, relative to its size
    output_sigma_factor: bandwidth of gaussian target
    template_size: template size in pixels, 0 to use ROI size
    scale_step: scale step for multi-scale estimation, 1 to disable it
    scale_weight: to downweight detection scores of other scales for added stability

For speed, the value (template_size/cell_size) should be a power of 2 or a product of small prime numbers.

Inputs to init():
   image is the initial frame.
   roi is a Recti with the target positions in the initial frame

Inputs to update():
   image is the current frame.

Outputs of update():
   Recti with target positions for the current frame


By downloading, copying, installing or using the software you agree to this license.
If you do not agree to this license, do not download, install,
copy or use the software.


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

#ifndef KCFTRACKERC_H
#define KCFTRACKERC_H

#ifdef _WIN32
    #include <MECL/mecl.h>
    #include "Point.h"
#else
    #include "mecl/mecl.h"
    #include "meal/camera/core/inc/CameraPoint.h"
#endif // _WIN32
#include "ffttoolsC.h"
#include "recttoolsC.h"
namespace tha
{
class KCFTrackerC
{
public:
    // Constructor
    KCFTrackerC();
#if THA_TRACKER_UT
    // Initialize tracker
    void init_c( const Recti& i_ROI_rs32, mecl::core::Matrix<uint8_t, 400, 640, e_Default>& i_Img_ru8 );
#else
    // Initialize tracker
    void init_c( const Recti& i_ROI_rs32, const mecl::core::Matrix<uint8_t, 400, 640, e_Default>& i_Img_ru8 );
#endif

    // Uninitialize tracker
    void uninit_c();
#if THA_TRACKER_UT
    // Update position based on the new frame
    void update_c( mecl::core::Matrix<uint8_t, 400, 640, e_Default>& i_Image_ru8, Recti& o_UpdateROI_rs32, const float32_t& i_PeakValueThresh_f32 );
#else
    // Update position based on the new frame
    void update_c( const mecl::core::Matrix<uint8_t, 400, 640, e_Default>& i_Image_ru8, Recti& o_UpdateROI_rs32, const float32_t& i_PeakValueThresh_f32 );
#endif
        // Get Peak value of response
        float32_t getPeakValue_c() const;

        // Set Peak value of response
        void setPeakValue_c( float32_t i_peakValue_f32 );

protected:
    // Evaluates a Gaussian kernel with bandwidth SIGMA for all relative shifts between input images X and Y, which must both be MxN. They must    also be periodic (ie., pre-processed with a cosine window).
    void gaussianCorrelation_c( const mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& i_X1_rf32, const mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& i_X2_rf32, mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& o_GaussCorr_rf32 );
    void gaussianAutoCorrelation_c( const mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& i_X1_rf32, mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& o_GaussCorr_rf32 );
    // Create Gaussian Peak. Function called only in the first frame.
    void createGaussianPeak_c();

    // Calculate sub-pixel peak for one dimension
    static float32_t subPixelPeak( const float32_t i_left_f32,
                                   const float32_t i_center_f32,
                                   const float32_t i_right_f32 );

    // Obtain sub-window from image, with replication-padding and extract features
    void getFeatures_c( const mecl::core::Matrix<uint8_t, 400, 640, e_Default>& i_Image_ru8,
                            mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& o_CurrFeatures_rf32 ) const;

    // Train tracker with a single image
    void train_c( const mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& i_CurrTmpl_rf32,
                  float32_t i_TrainInterpFac_f32 );

    // Detect object in the current frame.
    Point2f detect_c( const mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& i_TrainedPatch_rf32,
                      const mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& i_CurrFeatures_rf32,
                      float32_t& o_peakvalue_rf32 );

    // Initialize Hanning window. Function called only in the first frame.
    void createHanningMats_c();

    private:
        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_HannMat_f32;

        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_X2DFTRe_f32;
        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_X2DFTIm_f32;
        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_CorrResp_f32;
        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_DistMat_f32;
        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_MulSpecDivRe_f32;
        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_MulSpecDivIm_f32;
        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_ConfMap_f32;
        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_RespDFTRe_f32;
        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_RespDFTIm_f32;

        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_AlphaRe_f32;
        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_AlphaIm_f32;
        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_RegTargetRe_f32;
        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_RegTargetIm_f32;
        mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> m_TrainedTmpl_f32;

        float32_t m_Lambda_f32; // regularization        
        float32_t m_PaddingFac_f32; // extra area surrounding the target
        float32_t m_InterpFac_f32; // linear interpolation factor for adaptation
        float32_t m_Sigma_f32; // gaussian kernel bandwidth
        int32_t m_TmplSize_s32; // template size
        float32_t m_PeakValue_f32; // Peak value of response
        bool_t m_InitHann_b;
        Rectf m_ROI_f32 = {};

    };
} // namespace tha
#endif // !KCFTRACKERC_H
