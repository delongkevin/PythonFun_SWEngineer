#include "kcftrackerC.h"

#if THA_TRACKER_UT
#include "JobTHA.h"
extern volatile uint16_t u16FrameNo;
#endif
namespace tha
{
// Constructor
KCFTrackerC::KCFTrackerC() :
    m_Lambda_f32( 0.0001 ),
    m_PaddingFac_f32( 2.5 ),
    m_InterpFac_f32( 0.075 ),
    m_Sigma_f32( 0.2 ),
    m_TmplSize_s32( windowSize ),
    m_PeakValue_f32( 1.0f ),
    m_InitHann_b( false )
{
    m_Lambda_f32 = 0.0001;
    m_PaddingFac_f32 = 2.5;
    m_InterpFac_f32 = 0.075;
    m_Sigma_f32 = 0.2;
    m_TmplSize_s32 = windowSize;
        this->m_PeakValue_f32 = 1.0f;
    m_InitHann_b = false;
}

// Initialize tracker
#if THA_TRACKER_UT
void KCFTrackerC::init_c( const Recti& i_ROI_rs32, mecl::core::Matrix<uint8_t, 400, 640, e_Default>& i_Img_ru8 )
#else
void KCFTrackerC::init_c( const Recti& i_ROI_rs32, const mecl::core::Matrix<uint8_t, 400, 640, e_Default>& i_Img_ru8 )
#endif
{
    if( m_InitHann_b == false )
    {
        createHanningMats_c();
        createGaussianPeak_c();
        m_InitHann_b = true;
    }

    m_Lambda_f32 = 0.0001;
    m_PaddingFac_f32 = 1.0f;
    m_InterpFac_f32 = 0.075;
    m_Sigma_f32 = 0.2;
    m_TmplSize_s32 = windowSize;
    m_ROI_f32 = RectToolsC::Recti2Rectf_c(i_ROI_rs32);
    #if THA_TRACKER_UT
    if ((146 == u16FrameNo) || (159 == u16FrameNo))
    {
        char Buffer[100];
        sprintf(Buffer, "/ti_fs/vision_apps/i_Img_ru8_%d.bin", u16FrameNo);
        // printf("Opening file [%s]\n", Buffer);
        FILE *fptr = NULL;
        fptr = fopen(Buffer, "r");

        if (NULL != fptr)
        {
            // printf("Reading file [%s]\n", Buffer);
            for (uint16_t i = 0; i < 400; i++)
            {
                for (uint16_t j = 0; j < 640; j++)
                {
                    uint8_t byte;
                    fread(&byte, 1, 1, fptr);
                    i_Img_ru8(i, j) = byte;
                }
            }
        }
        else
        {
            printf("Failed to open file [%s]\n", Buffer);
        }
        fclose(fptr);
        fptr = NULL;
    }
    #endif //THA_TRACKER_UT
    getFeatures_c(i_Img_ru8, m_TrainedTmpl_f32);
    train_c( m_TrainedTmpl_f32, 1.0 ); // train with initial frame
}


// Uninitialize tracker
void KCFTrackerC::uninit_c()
{
    m_ROI_f32.x = 0.0f;
    m_ROI_f32.y = 0.0f;
    m_ROI_f32.width = 0.0f;
    m_ROI_f32.height = 0.0f;
    m_Lambda_f32 = 0.0001;
    m_PaddingFac_f32 = 2.5;
    m_InterpFac_f32 = 0.075;
    m_Sigma_f32 = 0.2;
    m_TmplSize_s32 = windowSize;
        this->m_PeakValue_f32 = 1.0f;
    m_InitHann_b = false;
}
#if THA_TRACKER_UT
// Update position based on the new frame
void KCFTrackerC::update_c(mecl::core::Matrix<uint8_t, 400, 640, e_Default>& i_Image_ru8, Recti& o_UpdateROI_rs32, const float32_t& i_PeakValueThresh_f32 )
#else
// Update position based on the new frame
void KCFTrackerC::update_c( const mecl::core::Matrix<uint8_t, 400, 640, e_Default>& i_Image_ru8, Recti& o_UpdateROI_rs32, const float32_t& i_PeakValueThresh_f32 )
#endif
{
    float32_t v_TrkdPntX_f32 = m_ROI_f32.x + m_ROI_f32.width / 2.0f;
    float32_t v_TrkdPntY_f32 = m_ROI_f32.y + m_ROI_f32.height / 2.0f;
    float32_t v_peakValue_f32;
    mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> v_CurrFeatures_f32;
    #if THA_TRACKER_UT
    char Buffer[100];
    sprintf( Buffer, "/ti_fs/vision_apps/i_Image_ru8_%d.bin", u16FrameNo );
    // printf("Opening file [%s]\n", Buffer);
    FILE* fptr = NULL;
    fptr = fopen( Buffer, "r" );

    if( NULL != fptr )
    {
        // printf("Reading file [%s]\n", Buffer);
        for( uint16_t i = 0; i < 400; i++ )
        {
            for( uint16_t j = 0; j < 640; j++ )
            {
                uint8_t byte;
                fread( &byte, 1, 1, fptr );
                i_Image_ru8( i, j ) = byte;
            }
        }
    }
    else
    {
        printf("Failed to open file [%s]\n", Buffer);
    }
    fclose( fptr );
    fptr = NULL;
    #endif // THA_TRACKER_UT
    getFeatures_c( i_Image_ru8, v_CurrFeatures_f32 );
    Point2f v_Res_f32 = detect_c( m_TrainedTmpl_f32, v_CurrFeatures_f32, v_peakValue_f32 );

    // Peak value threshold check
    if( v_peakValue_f32 < i_PeakValueThresh_f32 )
    {
        this->m_PeakValue_f32 = v_peakValue_f32;
        o_UpdateROI_rs32 = RectToolsC::Rectf2Recti_c( m_ROI_f32 );
    }
    else
    {
        // Adjust ROI by results from sub-pixel peak
        this->m_PeakValue_f32 = v_peakValue_f32;
        m_ROI_f32.x = v_TrkdPntX_f32 - ( m_ROI_f32.width / 2.0f ) + v_Res_f32.x;
        m_ROI_f32.y = v_TrkdPntY_f32 - ( m_ROI_f32.height / 2.0f ) + v_Res_f32.y;
        getFeatures_c( i_Image_ru8, v_CurrFeatures_f32 );
        train_c( v_CurrFeatures_f32, m_InterpFac_f32 );
        o_UpdateROI_rs32 = RectToolsC::Rectf2Recti_c( m_ROI_f32 );
    }
}

    float32_t KCFTrackerC::getPeakValue_c() const
    {
        return m_PeakValue_f32;
    }
    void KCFTrackerC::setPeakValue_c( float32_t i_peakValue_f32 )
    {
        m_PeakValue_f32 = i_peakValue_f32;
    }
// Detect object in the current frame.
Point2f KCFTrackerC::detect_c( const mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& i_TrainedPatch_rf32,
                               const mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& i_CurrFeatures_rf32,
                               float32_t& o_peakvalue_rf32 )
{
    gaussianCorrelation_c( i_CurrFeatures_rf32, i_TrainedPatch_rf32, m_ConfMap_f32 );
    FFTToolsC::fftd_c( m_ConfMap_f32, m_RespDFTRe_f32, m_RespDFTIm_f32 );
    FFTToolsC::mulSpectrumsRe_c( m_AlphaRe_f32, m_RespDFTRe_f32, m_AlphaIm_f32, m_RespDFTIm_f32, m_MulSpecDivRe_f32 );
    FFTToolsC::mulSpectrumsIm_c( m_AlphaRe_f32, m_RespDFTRe_f32, m_AlphaIm_f32, m_RespDFTIm_f32, m_MulSpecDivIm_f32 );
    FFTToolsC::idft_c( m_MulSpecDivRe_f32, m_MulSpecDivIm_f32, m_ConfMap_f32 );
    Point2i v_MatchedLoc_s32;
    uint32_t v_TempMatchX_u32;
    uint32_t v_TempMatchY_u32;
    o_peakvalue_rf32 = m_ConfMap_f32.maximum( v_TempMatchY_u32, v_TempMatchX_u32 );
    v_MatchedLoc_s32.x = v_TempMatchX_u32;
    v_MatchedLoc_s32.y = v_TempMatchY_u32;
    //subpixel peak estimation, coordinates will be non-integer
    Point2f v_MatchedLoc_f32( static_cast<float32_t>( v_MatchedLoc_s32.x ), static_cast<float32_t>( v_MatchedLoc_s32.y ) );

    if( ( v_MatchedLoc_s32.x > 0 ) && ( v_MatchedLoc_s32.x < ( static_cast<int32_t>( m_ConfMap_f32.cols ) - 1 ) ) )
    {
        float32_t v_leftPx_f32 = m_ConfMap_f32( v_MatchedLoc_s32.y, v_MatchedLoc_s32.x - 1 );
        float32_t v_rightPx_f32 = m_ConfMap_f32( v_MatchedLoc_s32.y, v_MatchedLoc_s32.x + 1 );
        v_MatchedLoc_f32.x += subPixelPeak( v_leftPx_f32, o_peakvalue_rf32, v_rightPx_f32 );
    }

    if( ( v_MatchedLoc_s32.y > 0 ) && ( v_MatchedLoc_s32.y < ( static_cast<int32_t>( m_ConfMap_f32.rows ) - 1 ) ) )
    {
        float32_t v_TopPx_f32 = m_ConfMap_f32( v_MatchedLoc_s32.y - 1, v_MatchedLoc_s32.x );
        float32_t v_BottomPx_f32 = m_ConfMap_f32( v_MatchedLoc_s32.y + 1, v_MatchedLoc_s32.x );
        v_MatchedLoc_f32.y += subPixelPeak( v_TopPx_f32, o_peakvalue_rf32, v_BottomPx_f32 );
    }

    v_MatchedLoc_f32.x -= ( static_cast<float32_t>( m_ConfMap_f32.cols ) ) / 2.0;
    v_MatchedLoc_f32.y -= ( static_cast<float32_t>( m_ConfMap_f32.rows ) ) / 2.0;
    return v_MatchedLoc_f32;
}

// train tracker with a single image
void KCFTrackerC::train_c( const mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& i_CurrTmpl_rf32, float32_t i_TrainInterpFac_f32 )
{
    gaussianAutoCorrelation_c( i_CurrTmpl_rf32, m_ConfMap_f32 );
    FFTToolsC::fftd_c( m_ConfMap_f32, m_RespDFTRe_f32, m_RespDFTIm_f32 );
    m_RespDFTRe_f32 = m_RespDFTRe_f32.add( m_Lambda_f32 );
    m_RespDFTIm_f32 = m_RespDFTIm_f32.add( m_Lambda_f32 );
    FFTToolsC::complexDivisionRe_c( m_RegTargetRe_f32, m_RespDFTRe_f32, m_RegTargetIm_f32, m_RespDFTIm_f32, m_MulSpecDivRe_f32 );
    FFTToolsC::complexDivisionIm_c( m_RegTargetRe_f32, m_RespDFTRe_f32, m_RegTargetIm_f32, m_RespDFTIm_f32, m_MulSpecDivIm_f32 );

        if( mecl::math::isZero_b( i_TrainInterpFac_f32 - 1.0f ) )
    {
        m_TrainedTmpl_f32 = i_CurrTmpl_rf32;
        m_AlphaRe_f32 = m_MulSpecDivRe_f32;
        m_AlphaIm_f32 = m_MulSpecDivIm_f32;
    }
    else
    {
        m_TrainedTmpl_f32 = m_TrainedTmpl_f32.mul( 1.0 - i_TrainInterpFac_f32 ).add( i_CurrTmpl_rf32.mul( i_TrainInterpFac_f32 ) );
        m_AlphaRe_f32 = m_AlphaRe_f32.mul( 1.0 - i_TrainInterpFac_f32 ).add( m_MulSpecDivRe_f32.mul( i_TrainInterpFac_f32 ) );
        m_AlphaIm_f32 = m_AlphaIm_f32.mul( 1.0 - i_TrainInterpFac_f32 ).add( m_MulSpecDivIm_f32.mul( i_TrainInterpFac_f32 ) );
    }
}

// Evaluates a Gaussian kernel with bandwidth SIGMA for all relative shifts between input images X and Y, which must both be MxN. They must also be periodic (ie., pre-processed with a cosine window).
void KCFTrackerC::gaussianCorrelation_c( const mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& i_X1_rf32, const mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& i_X2_rf32, mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& o_GaussCorr_rf32 )
{
    FFTToolsC::fftd_c( i_X1_rf32, m_RespDFTRe_f32, m_RespDFTIm_f32 );
    FFTToolsC::fftd_c( i_X2_rf32, m_X2DFTRe_f32, m_X2DFTIm_f32 );
    mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> v_X2ImConj_f32;
    v_X2ImConj_f32 = m_X2DFTIm_f32.minus();
    FFTToolsC::mulSpectrumsRe_c( m_RespDFTRe_f32, m_X2DFTRe_f32, m_RespDFTIm_f32, v_X2ImConj_f32, m_MulSpecDivRe_f32 );
    FFTToolsC::mulSpectrumsIm_c( m_RespDFTRe_f32, m_X2DFTRe_f32, m_RespDFTIm_f32, v_X2ImConj_f32, m_MulSpecDivIm_f32 );
    FFTToolsC::idft_c( m_MulSpecDivRe_f32, m_MulSpecDivIm_f32, m_CorrResp_f32 );
    FFTToolsC::SwapQuadrants( m_CorrResp_f32 );
    float32_t v_SumX1_f32 = 0;
    float32_t v_SumX2_f32 = 0;
    v_SumX1_f32 = i_X1_rf32.mul( i_X1_rf32 ).sum();
    v_SumX2_f32 = i_X2_rf32.mul( i_X2_rf32 ).sum();
    float32_t v_Sum_f32 = ( v_SumX1_f32 + v_SumX2_f32 );
    float32_t v_SigmaSqr_f32 = ( m_Sigma_f32 * m_Sigma_f32 );
    float32_t v_Den_f32 = static_cast<float32_t>( windowSize * windowSize );

    for( uint32_t v_RowIndx_u32 = 0; v_RowIndx_u32 < o_GaussCorr_rf32.rows; v_RowIndx_u32++ )
    {
        for( uint32_t v_ColIndx_u32 = 0; v_ColIndx_u32 < o_GaussCorr_rf32.cols; v_ColIndx_u32++ )
        {
            float32_t d_cal = ( v_Sum_f32 - ( 2.0 * m_CorrResp_f32( v_RowIndx_u32, v_ColIndx_u32 ) ) ) / v_Den_f32;

            if( d_cal > 0 )
            {
                m_DistMat_f32( v_RowIndx_u32, v_ColIndx_u32 ) = d_cal;
            }
            else
            {
                m_DistMat_f32( v_RowIndx_u32, v_ColIndx_u32 ) = 0;
            }

            o_GaussCorr_rf32( v_RowIndx_u32, v_ColIndx_u32 ) = std::exp( -m_DistMat_f32( v_RowIndx_u32, v_ColIndx_u32 ) / v_SigmaSqr_f32 );
        }
    }
}

void KCFTrackerC::gaussianAutoCorrelation_c( const mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& i_X1_rf32, mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& o_GaussCorr_rf32 )
{
    FFTToolsC::fftd_c( i_X1_rf32, m_RespDFTRe_f32, m_RespDFTIm_f32 );
    mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> v_X2ImConj_f32;
    v_X2ImConj_f32 = m_RespDFTIm_f32.minus();
    FFTToolsC::mulSpectrumsRe_c( m_RespDFTRe_f32, m_RespDFTRe_f32, m_RespDFTIm_f32, v_X2ImConj_f32, m_MulSpecDivRe_f32 );
    FFTToolsC::mulSpectrumsIm_c( m_RespDFTRe_f32, m_RespDFTRe_f32, m_RespDFTIm_f32, v_X2ImConj_f32, m_MulSpecDivIm_f32 );
    FFTToolsC::idft_c( m_MulSpecDivRe_f32, m_MulSpecDivIm_f32, m_CorrResp_f32 );
    FFTToolsC::SwapQuadrants( m_CorrResp_f32 );
    float32_t v_SumX1_f32 = 0;
    v_SumX1_f32 = i_X1_rf32.mul( i_X1_rf32 ).sum();
    float32_t v_Sum_f32 = ( v_SumX1_f32 + v_SumX1_f32 );
    float32_t v_SigmaSqr_f32 = ( m_Sigma_f32 * m_Sigma_f32 );
    float32_t v_Den_f32 = static_cast<float32_t>( windowSize * windowSize );

    for( uint32_t v_RowIndx_u32 = 0; v_RowIndx_u32 < o_GaussCorr_rf32.rows; v_RowIndx_u32++ )
    {
        for( uint32_t v_ColIndx_u32 = 0; v_ColIndx_u32 < o_GaussCorr_rf32.cols; v_ColIndx_u32++ )
        {
            float32_t d_cal = ( v_Sum_f32 - ( 2.0 * m_CorrResp_f32( v_RowIndx_u32, v_ColIndx_u32 ) ) ) / v_Den_f32;

            if( d_cal > 0 )
            {
                m_DistMat_f32( v_RowIndx_u32, v_ColIndx_u32 ) = d_cal;
            }
            else
            {
                m_DistMat_f32( v_RowIndx_u32, v_ColIndx_u32 ) = 0;
            }

            o_GaussCorr_rf32( v_RowIndx_u32, v_ColIndx_u32 ) = std::exp( -m_DistMat_f32( v_RowIndx_u32, v_ColIndx_u32 ) / v_SigmaSqr_f32 );
        }
    }
}

// Create Gaussian Peak. Function called only in the first frame.
void KCFTrackerC::createGaussianPeak_c()
{
    mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> v_res_f32;
    int32_t v_Mid_s32 = ( windowSize ) / 2;
    float32_t v_StdDev_f32 = 0.2; // Standard deviation of gaussian peak
    float32_t v_Multfac_f32 = ( -0.5 / ( v_StdDev_f32 * v_StdDev_f32 ) );

    for( int32_t v_Row_s32 = 0; v_Row_s32 < windowSize; v_Row_s32++ )
    {
        for( int32_t v_Col_s32 = 0; v_Col_s32 < windowSize; v_Col_s32++ )
        {
            int32_t v_DiffX = v_Row_s32 - v_Mid_s32;
            int32_t v_DiffY = v_Col_s32 - v_Mid_s32;
            v_res_f32( v_Row_s32, v_Col_s32 ) = std::exp( v_Multfac_f32 * static_cast<float32_t>( v_DiffX * v_DiffX + v_DiffY * v_DiffY ) );
        }
    }

    FFTToolsC::fftd_c( v_res_f32, m_RegTargetRe_f32, m_RegTargetIm_f32 );
}

// Obtain sub-window from image, with replication-padding and extract features
    void KCFTrackerC::getFeatures_c( const mecl::core::Matrix<uint8_t, 400, 640, e_Default>& i_Image_ru8, mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default>& o_CurrFeatures_rf32 ) const
{
    Recti v_ExtractROI_s32;
    float32_t v_TrkdPntX_f32 = m_ROI_f32.x + m_ROI_f32.width / 2.f;
    float32_t v_TrkdPntY_f32 = m_ROI_f32.y + m_ROI_f32.height / 2.f;
    v_ExtractROI_s32.width = windowSize;
    v_ExtractROI_s32.height = windowSize;
    v_ExtractROI_s32.x = static_cast<int32_t>( v_TrkdPntX_f32 ) - ( v_ExtractROI_s32.width / 2 );
    v_ExtractROI_s32.y = static_cast<int32_t>( v_TrkdPntY_f32 ) - ( v_ExtractROI_s32.height / 2 );
    mecl::core::Matrix<float32_t, windowSize, windowSize, e_Default> v_FeatureMap_f32;
    // Extract ROI for current frame
    v_FeatureMap_f32 = i_Image_ru8.subMatrix<ScaleWindowSize, ScaleWindowSize>( v_ExtractROI_s32.y, v_ExtractROI_s32.x );
    v_FeatureMap_f32 = v_FeatureMap_f32.mul( 1.f / 255.f );
    v_FeatureMap_f32 = m_HannMat_f32.mul( v_FeatureMap_f32 );
    o_CurrFeatures_rf32 = v_FeatureMap_f32;
}

// Initialize Hanning window. Function called only in the first frame.
void KCFTrackerC::createHanningMats_c()
{
    mecl::core::Matrix<float32_t, 1, windowSize, e_Default> v_Hann1t_f32;
    mecl::core::Matrix<float32_t, windowSize, 1, e_Default> v_Hann2t_f32;
    float32_t v_PI_f32 = mecl::math::constants<float32_t>::pi_x();
    float32_t v_numCol_f32 = v_Hann1t_f32.cols;
    float32_t v_numRow_f32 = v_Hann2t_f32.rows;

    for( uint32_t v_Indx_u32 = 0; v_Indx_u32 < v_Hann1t_f32.cols; v_Indx_u32++ )
    {
        v_Hann1t_f32( 0, v_Indx_u32 ) = ( 0.5 * ( 1.0 - mecl::math::trigonometry<float32_t>::cos_x( 2.f * v_PI_f32 * static_cast<float32_t>( v_Indx_u32 ) / ( v_numCol_f32 - 1.f ) ) ) );
        v_Hann2t_f32( v_Indx_u32, 0 ) = ( 0.5 * ( 1.0 - mecl::math::trigonometry<float32_t>::cos_x( 2.f * v_PI_f32 * static_cast<float32_t>( v_Indx_u32 ) / ( v_numRow_f32 - 1.f ) ) ) );
    }

    m_HannMat_f32 = v_Hann2t_f32.mmulFast( v_Hann1t_f32 );
}

// Calculate sub-pixel peak for one dimension
float32_t KCFTrackerC::subPixelPeak( const float32_t i_left_f32, const float32_t i_center_f32, const float32_t i_right_f32 )
{
    float32_t v_Divisor_f32 = 2.0 * i_center_f32 - i_right_f32 - i_left_f32;
    float32_t v_returnValue_f32;

    if( mecl::math::isZero_b( v_Divisor_f32 ) == false )
    {
        v_returnValue_f32 = ( 0.5 * ( i_right_f32 - i_left_f32 ) / v_Divisor_f32 );
    }
    else
    {
        v_returnValue_f32 = 0;
    }

    return v_returnValue_f32;
}
}
