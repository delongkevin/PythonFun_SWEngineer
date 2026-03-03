// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [07-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TEMPLATE_MATCHING_H
#define __TEMPLATE_MATCHING_H

#include "Image.h"

namespace t_m
{
    /*
    * Stores the template matching functions used.
    */
    class TemplateMatching
    {
    public:
        TemplateMatching();
        ~TemplateMatching();

        static void ExtractTemplateDotProduct( image::Image<uint8_t>& i_image, image::Image<uint8_t>& o_template, float32_t& zeroscore, const _roi::ROI r1 );
        static void ExtractTemplate( const image::Image<uint8_t>& i_image, image::Image<uint8_t>& o_template, int32_t i_x, int32_t i_y );
        static void ExtractTemplate_2( const uint8_t* i_image, int32_t i_image_width, int32_t i_image_height, int32_t i_image_step, int32_t i_image_numChannels, uint8_t* o_template, int32_t o_template_width, int32_t o_template_height, int32_t o_template_step, int32_t o_template_numChannels, int32_t o_template_size, int32_t i_x, int32_t i_y );
        static void ExtractTemplateShallow( image::Image<uint8_t>& i_image, image::Image<uint8_t>& o_template, int32_t i_x, int32_t i_y );

        static float32_t Similarity1( image::Image<uint8_t>& i_image1, image::Image<uint8_t>& i_image2 );
        static float32_t Similarity1Weighted( image::Image<uint8_t>& i_image1, image::Image<uint8_t>& i_image2 );

        static float32_t Similarity2( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi );
        static float32_t Similarity2Weighted( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi );

        static float32_t Similarity3( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi );
        static float32_t Similarity4( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi, image::Image<uint8_t>& i_dilatetemplate, float32_t TemplateCount, uint16_t othsu_thresh, float32_t zeroscore, float32_t zeroEdgecount, const _roi::ROI r1 );
        static float32_t Similarity3Weighted( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi );
        static float32_t Similarity3Weighted_1( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi );

        static float32_t GaussianSimilarity( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi, uint32_t i_kernelSize );
        static float32_t GaussianSimilarity3x3( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi );
        static float32_t GaussianSimilarityWeighted3x3( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi, float32_t i_factor );
        static float32_t GaussianSimilarityWeighted3x3_2( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, float32_t i_factor, uint16_t othsuthresh );
        static float32_t GaussianSimilarityWeighted3x3_3( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, float32_t i_factor );
        static float32_t GaussianSimilarityWeighted3x3_4( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, float32_t i_factor, uint16_t othsuthresh );
        static float32_t GaussianSimilarityWeighted3x3_5( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, float32_t i_factor, uint16_t othsuthresh );
        static float32_t GaussianSimilarityWeighted3x3_6( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, float32_t i_factor, uint16_t othsuthresh );
        static float32_t GaussianSimilarityWeighted3x3_7( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, uint16_t othsuthresh );
        static float32_t GaussianSimilarityWeighted3x3_WithEdgeDir( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_templateDir, image::Image<uint8_t>& i_roi, image::Image<uint8_t>& i_roiDir, float32_t i_factor );
        static float32_t GaussianSimilarityWeighted3x3_CorrectedNormalization( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, float32_t i_factor );
        template<uint32_t kW, uint32_t kH>
        static float32_t FilterSimilarity( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi, const image::Kernel<float32_t, kW, kH>& i_kernel );

    };

    ///------------------------------------------------------------------------------
    /// TemplateMatching template function definitions.
    ///------------------------------------------------------------------------------

    /**
    * Filter based similarity score.
    */
    template<uint32_t kW, uint32_t kH>
    inline float32_t TemplateMatching::FilterSimilarity( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi, const image::Kernel<float32_t, kW, kH>& i_kernel )
    {
#ifdef DIAGNOSTICS
        diag::start( "FilterSimilarity" );
#endif
        uint32_t start_x = i_kernel.anchor.x;
        uint32_t start_y = i_kernel.anchor.y;
        uint32_t end_x = i_template.width - ( i_kernel.width - i_kernel.anchor.x - 1 );
        uint32_t end_y = i_template.height - ( i_kernel.height - i_kernel.anchor.y - 1 );
        uint8_t* tmp_ptr = i_template.data;
        uint32_t template_count = 0;
        float32_t score = 0;
        float32_t sum;

        for( uint32_t y = start_y; y < end_y; y++ )
        {
            for( uint32_t x = start_x; x < end_x; x++ )
            {
                if( *tmp_ptr > 0 )
                {
                    sum = 0;
                    template_count++;

                    for( uint32_t i = 0; i < kH; i++ )
                    {
                        for( uint32_t j = 0; j < kW; j++ )
                        {
                            uint32_t new_x = x - ( i_kernel.anchor.x - j );
                            uint32_t new_y = y - ( i_kernel.anchor.y - i );

                            if( *( i_roi.at( new_x, new_y ) ) > 0 )
                            {
                                sum += i_kernel.at( j, i );
                            }
                        }
                    }

                    score += sum;
                }

                ++tmp_ptr;
            }
        }

        float32_t filter_sum = i_kernel.sum();
#ifdef DIAGNOSTICS
        diag::stop();
#endif
        return score / ( filter_sum * template_count );
    }
}
#endif // !__TEMPLATE_MATCHING_H
