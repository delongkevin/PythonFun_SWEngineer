// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [07-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "TemplateMatching.h"
#include "TemplateWeightMask.h"
#include <cmath>

/*
* Constructor.
*/
t_m::TemplateMatching::TemplateMatching()
{
}

/*
* Destructor.
*/
t_m::TemplateMatching::~TemplateMatching()
{
}

/*
* Extract template from input image, performing a deep copy of the region in the image.
* The size of the template determines the extracted template size.
*/
void t_m::TemplateMatching::ExtractTemplate( const image::Image<uint8_t>& i_image, image::Image<uint8_t>& o_template, int32_t i_x, int32_t i_y )
{
#ifdef DIAGNOSTICS
    diag::start( "ExtractTrailerTemplate" );
#endif
    memset( o_template.getData(), 0, o_template.getSize() );
    int32_t start_x = 0;
    int32_t end_x = o_template.getWidth();
    int32_t start_y = 0;
    int32_t end_y = o_template.getHeight();

    if( i_x < 0 )
    {
        start_x = mms::minimum( -i_x, static_cast<int32_t>( o_template.getWidth() ) );
    }

    if( ( i_x + o_template.getWidth() ) > i_image.getWidth() )
    {
        end_x = mms::maximum( static_cast<int32_t>( i_image.getWidth() ) - i_x , 0 );
    }

    if( i_y < 0 )
    {
        start_y = mms::minimum( -i_y, static_cast<int32_t>( o_template.getHeight() ) );
    }

    if( ( i_y + static_cast<int32_t>( o_template.getHeight() ) ) > static_cast<int32_t>( i_image.getHeight() ) )
    {
        end_y = mms::maximum( static_cast<int32_t>( i_image.getHeight() ) - i_y , 0 );
    }

    for( int32_t x = start_x; x < end_x; x++ )
    {
        for( int32_t y = start_y; y < end_y; y++ )
        {
            *o_template.at( x, y ) = *i_image.at( i_x + x, i_y + y );
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}
/*
* Extract template from input image, performing a deep copy of the region in the image.
* The size of the template determines the extracted template size.
*/
void t_m::TemplateMatching::ExtractTemplateDotProduct( image::Image<uint8_t>& i_image, image::Image<uint8_t>& o_template, float32_t& zeroscore, const _roi::ROI r1 )
{
#ifdef DIAGNOSTICS
    diag::start( "ExtractTemplateDotProduct" );
#endif
    float32_t sum = 0;
    float32_t zero_count = 0.0f;
    float32_t zero_roi_count = 0.0f;

    for( uint32_t x = 0; x < o_template.getWidth(); x++ )
    {
        for( uint32_t y = r1.getY(); y < r1.getHeight(); y++ )
        {
            if( *i_image.at( x, y ) == 0 )
            {
                if( mask::TemplateWeightMask[y][x] > 0.0f )
                {
                    zero_count++;

                    if( ( *o_template.at( x, y ) == 0 ) )
                    {
                        zero_roi_count++;
                    }
                }

                *o_template.at( x, y ) = 0;
            }
        }
    }

    //zeroEdgecount = zero_edge_count;
    zeroscore = 1.0f - ( zero_roi_count / zero_count );
#ifdef DIAGNOSTICS
    diag::stop();
#endif
}

/*
* Optimized version of 'ExtractTemplate()'.
*/
void t_m::TemplateMatching::ExtractTemplate_2( const uint8_t* i_image, int32_t i_image_width, int32_t i_image_height, int32_t i_image_step, int32_t i_image_numChannels, uint8_t* o_template, int32_t o_template_width, int32_t o_template_height, int32_t o_template_step, int32_t o_template_numChannels, int32_t o_template_size, int32_t i_x, int32_t i_y )
{
#ifdef DIAGNOSTICS
    diag::start( "ExtractTrailerTemplate" );
#endif
    memset( o_template, 0, static_cast<uint32_t>( o_template_size ) );
    int32_t start_x = 0;
    int32_t end_x = o_template_width;
    int32_t start_y = 0;
    int32_t end_y = o_template_height;

    if( i_x < 0 )
    {
        start_x = mms::minimum( -i_x, o_template_width );
    }

    if( ( i_x + o_template_width ) > i_image_width )
    {
        end_x = mms::maximum( i_image_width - i_x, 0 );
    }

    if( i_y < 0 )
    {
        start_y = mms::minimum( -i_y, o_template_height );
    }

    if( ( i_y + o_template_height ) > i_image_height )
    {
        end_y = mms::maximum( i_image_height - i_y, 0 );
    }

    for( int32_t x = start_x; x < end_x; x++ )
    {
        for( int32_t y = start_y; y < end_y; y++ )
        {
            *( o_template + ( y * o_template_step ) + ( x * o_template_numChannels ) ) = *( i_image + ( ( i_y + y ) * i_image_step ) + ( ( i_x + x ) * i_image_numChannels ) ); /* PRQA S 3705*/
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}

/*
* Extract template from input image, performing a shallow copy of the region in the image.
* The size of the template determines the extracted template size.
*/
void t_m::TemplateMatching::ExtractTemplateShallow( image::Image<uint8_t>& i_image, image::Image<uint8_t>& o_template, int32_t i_x, int32_t i_y )
{
    o_template = i_image.subImage( i_x, i_y, o_template.getWidth(), o_template.getHeight() );
}
/*
* Same as 'Similarity3()' except using the weight mask defined in 'TemplateWeightMask.h'.
*/
float32_t t_m::TemplateMatching::Similarity3Weighted_1( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi )
{
#ifdef DIAGNOSTICS
    diag::start( "TemplateMatching::SimilarityWeighted" );
#endif
    float32_t score = 0;
    int32_t sum;
    float32_t total_weight = 0.0f;
    float32_t weight;

    for( uint32_t y = 1; y < ( i_template.getHeight() - 1 ); y++ )
    {
        for( uint32_t x = 1; x < ( i_template.getWidth() - 1 ); x++ )
        {
            weight = ( mms::maximum( 1.0f + mask::TemplateWeightMask[y][x], 0.0f ) );

            if( *i_template.at( x, y ) > 0 )
            {
                sum = static_cast<int32_t>( *i_roi.at( x - 1, y - 1 ) );
                sum += 2 * static_cast<int32_t>( *i_roi.at( x, y - 1 ) );
                sum += static_cast<int32_t>( *i_roi.at( x + 1, y - 1 ) );
                sum += 2 * static_cast<int32_t>( *i_roi.at( x - 1, y ) );
                sum += 4 * static_cast<int32_t>( *i_roi.at( x, y ) );
                sum += 2 * static_cast<int32_t>( *i_roi.at( x + 1, y ) );
                sum += static_cast<int32_t>( *i_roi.at( x - 1, y + 1 ) );
                sum += 2 * static_cast<int32_t>( *i_roi.at( x, y + 1 ) );
                sum += static_cast<int32_t>( *i_roi.at( x + 1, y + 1 ) );
                score += static_cast<float32_t>( sum );
            }

            total_weight += weight;
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    return score / ( ( total_weight > 0. ) ? ( total_weight * 16. ) : 16. );
}
/*
* Same as 'Similarity3()' except using the weight mask defined in 'TemplateWeightMask.h'.
*/
float32_t t_m::TemplateMatching::Similarity4( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi, image::Image<uint8_t>& i_dilatetemplate, float32_t TemplateCount, uint16_t othsu_thresh, float32_t zeroscore, float32_t zeroEdgecount, const _roi::ROI r1 )
{
#ifdef DIAGNOSTICS
    diag::start( "TemplateMatching::Similarity4" );
#endif
    float32_t template_count = 0.0f;
    float32_t roi_count = 0.0f;
    float32_t score = 0.0f;

    // calculating threshold
    for( uint32_t y = r1.getY(); y < r1.getHeight(); y++ )
    {
        for( uint32_t x = 0; x < i_template.getWidth(); x++ )
        {
            if( *i_dilatetemplate.at( x, y ) > 0 && mask::TemplateWeightMask[y][x] > -0.0f )
            {
                if( *i_roi.at( x, y ) > othsu_thresh )
                {
                    roi_count++;
                }
            }
        }
    }

    score = ( roi_count - zeroEdgecount ) / TemplateCount;

    if( zeroscore > 0.05f )
    {
        score = score - zeroscore;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    return score;
}
/*
* Calculates the similarity bewteen two images by counting the number of edges (pixels above 0)
* that they share.
*/
float32_t t_m::TemplateMatching::Similarity1( image::Image<uint8_t>& i_image1, image::Image<uint8_t>& i_image2 )
{
#ifdef DIAGNOSTICS
    diag::start( "TemplateMatching::Similarity" );
#endif
    int32_t img1_step = i_image1.getStep();
    int32_t img2_step = i_image2.getStep();
    uint8_t* img1_ptr;
    uint8_t* img1_row = i_image1.getData();
    uint8_t* img2_ptr;
    uint8_t* img2_row = i_image2.getData();
    float32_t score = 0;

    for( uint32_t y = 0; y < i_image1.getWidth(); y++ )
    {
        img1_ptr = img1_row;
        img2_ptr = img2_row;

        for( uint32_t x = 0; x < i_image1.getHeight(); x++ )
        {
            if( ( *img1_ptr > 0 ) == ( *img2_ptr > 0 ) )
            {
                score++;
            }

            ++img1_ptr;
            ++img2_ptr;
        }

        img1_row += img1_step;
        img2_row += img2_step;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    return score / static_cast<float32_t>( ( i_image1.getWidth() * i_image1.getHeight() ) );
}

/*
* Same as 'Similarity1()' except using the weight mask defined in 'TemplateWeightMask.h'.
*/
float32_t t_m::TemplateMatching::Similarity1Weighted( image::Image<uint8_t>& i_image1, image::Image<uint8_t>& i_image2 )
{
#ifdef DIAGNOSTICS
    diag::start( "TemplateMatching::SimilarityWeighted" );
#endif
    int32_t img1_step = i_image1.getStep();
    int32_t img2_step = i_image2.getStep();
    uint8_t* img1_ptr;
    uint8_t* img1_row = i_image1.getData();
    uint8_t* img2_ptr;
    uint8_t* img2_row = i_image2.getData();
    float32_t score = 0;

    for( uint32_t y = 0; y < i_image1.getHeight(); y++ )
    {
        img1_ptr = img1_row;
        img2_ptr = img2_row;

        for( uint32_t x = 0; x < i_image1.getWidth(); x++ )
        {
            if( ( *img1_ptr > 0 ) == ( *img2_ptr > 0 ) )
            {
                score += ( mms::maximum( 1.0f + mask::TemplateWeightMask[y][x], 0.0f ) );
            }

            ++img1_ptr;
            ++img2_ptr;
        }

        img1_row += img1_step;
        img2_row += img2_step;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    return score / static_cast<float32_t>( ( i_image1.getWidth() * i_image1.getHeight() ) );
}

/*
* Calculates the similarity between a template and some region of interest by counting
* the number of template edges in the ROI.
*
* Note: the order of the input images matters.
*/
float32_t t_m::TemplateMatching::Similarity2( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi )
{
#ifdef DIAGNOSTICS
    diag::start( "TemplateMatching::Similarity" );
#endif
    int32_t tmp_step = i_template.getStep();
    int32_t roi_step = i_roi.getStep();
    uint8_t* tmp_ptr;
    uint8_t* tmp_row = i_template.getData();
    uint8_t* roi_ptr;
    uint8_t* roi_row = i_roi.getData();
    uint32_t template_count = 0;
    float32_t score = 0;

    for( uint32_t y = 1; y < ( i_template.getHeight() - 1 ); y++ )
    {
        tmp_ptr = tmp_row;
        roi_ptr = roi_row;

        for( uint32_t x = 1;  x < ( i_template.getWidth() - 1 ); x++ )
        {
            if( *tmp_ptr > 0 )
            {
                ++template_count;
                score = score + ( static_cast<float32_t>( ( *roi_ptr ) > 0 ) );
            }

            ++tmp_ptr;
            ++roi_ptr;
        }

        tmp_row += tmp_step;
        roi_row += roi_step;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    return score / static_cast<float32_t>( template_count );
}

/*
* Same as 'Similarity2()' except using the weight mask defined in 'TemplateWeightMask.h'.
*/
float32_t t_m::TemplateMatching::Similarity2Weighted( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi )
{
#ifdef DIAGNOSTICS
    diag::start( "TemplateMatching::SimilarityWeighted" );
#endif
    int32_t tmp_step = i_template.getStep();
    int32_t roi_step = i_roi.getStep();
    uint8_t* tmp_ptr;
    uint8_t* tmp_row = i_template.getData();
    uint8_t* roi_ptr;
    uint8_t* roi_row = i_roi.getData();
    uint32_t template_count = 0;
    float32_t score = 0;

    for( uint32_t y = 1; y < ( i_template.getHeight() - 1 ); y++ )
    {
        tmp_ptr = tmp_row;
        roi_ptr = roi_row;

        for( uint32_t x = 1; x < ( i_template.getWidth() - 1 ); x++ )
        {
            if( *tmp_ptr > 0 )
            {
                ++template_count;
                score = score + ( static_cast<float32_t>( ( *roi_ptr ) > 0 ) ) * ( mms::maximum( 1.0f + mask::TemplateWeightMask[y][x], 0.0f ) );
            }

            ++tmp_ptr;
            ++roi_ptr;
        }

        tmp_row += tmp_step;
        roi_row += roi_step;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    return score / static_cast<float32_t>( template_count );
}

/*
* Calculates the similarity between two images by counting the number of pixels
* which are the same (assuming they can be either an edge or not an edge).
*
* Uses a Gaussian filter and gives more weight to edge pixels
*/
float32_t t_m::TemplateMatching::Similarity3( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi )
{
#ifdef DIAGNOSTICS
    diag::start( "TemplateMatching::SimilarityWeighted" );
#endif
    float32_t score = 0;
    int32_t sum;
    float32_t total_weight = 0.0f;
    float32_t weight;

    for( uint32_t y = 1; y < ( i_template.getHeight() - 1 ); y++ )
    {
        for( uint32_t x = 1; x < ( i_template.getWidth() - 1 ); x++ )
        {
            weight = 1.0f;

            if( *i_template.at( x, y ) > 0 )
            {
                sum = ( static_cast<int32_t>( ( *i_roi.at( x - 1, y - 1 ) ) > 0 ) ); // +
                sum += 2 * static_cast<int32_t>( ( ( *i_roi.at( x, y - 1 ) ) > 0 ) ); // +
                sum += static_cast<int32_t>( ( ( *i_roi.at( x + 1, y - 1 ) ) > 0 ) ); // +
                sum += 2 * static_cast<int32_t>( ( ( *i_roi.at( x - 1, y ) ) > 0 ) ); // +
                sum += 4 * static_cast<int32_t>( ( ( *i_roi.at( x, y ) ) > 0 ) ); // +
                sum += 2 * static_cast<int32_t>( ( ( *i_roi.at( x + 1, y ) ) > 0 ) ); // +
                sum += static_cast<int32_t>( ( ( *i_roi.at( x - 1, y + 1 ) ) > 0 ) ); // +
                sum += 2 * static_cast<int32_t>( ( ( *i_roi.at( x, y + 1 ) ) > 0 ) ); // +
                sum += static_cast<int32_t>( ( ( *i_roi.at( x + 1, y + 1 ) ) > 0 ) );
                weight *= 3.;
            }
            else
            {
                sum = static_cast<int32_t>( ( ( *i_roi.at( x - 1, y - 1 ) ) == 0 ) );
                sum += 2 * static_cast<int32_t>( ( ( *i_roi.at( x, y - 1 ) ) == 0 ) );
                sum += static_cast<int32_t>( ( ( *i_roi.at( x + 1, y - 1 ) ) == 0 ) );
                sum += 2 * static_cast<int32_t>( ( ( *i_roi.at( x - 1, y ) ) == 0 ) );
                sum += 4 * static_cast<int32_t>( ( ( *i_roi.at( x, y ) ) == 0 ) );
                sum += 2 * static_cast<int32_t>( ( ( *i_roi.at( x + 1, y ) ) == 0 ) );
                sum += static_cast<int32_t>( ( ( *i_roi.at( x - 1, y + 1 ) ) == 0 ) );
                sum += 2 * static_cast<int32_t>( ( ( *i_roi.at( x, y + 1 ) ) == 0 ) );
                sum += static_cast<int32_t>( ( ( *i_roi.at( x + 1, y + 1 ) ) == 0 ) );
            }

            score += static_cast<float32_t>( sum ) * weight;
            total_weight += weight;
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    return score / ( ( total_weight > 0 ) ? total_weight * 16.0f : 16.0f );
}

/*
* Same as 'Similarity3()' except using the weight mask defined in 'TemplateWeightMask.h'.
*/
float32_t t_m::TemplateMatching::Similarity3Weighted( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi )
{
#ifdef DIAGNOSTICS
    diag::start( "TemplateMatching::SimilarityWeighted" );
#endif
    float32_t score = 0;
    int32_t sum;
    float32_t total_weight = 0.0f;
    float32_t weight;

    for( uint32_t y = 1; y < ( i_template.getHeight() - 1 ); y++ )
    {
        for( uint32_t x = 1; x < ( i_template.getWidth() - 1 ); x++ )
        {
            weight = ( mms::maximum( 1.0f + mask::TemplateWeightMask[y][x], 0.0f ) );

            if( *i_template.at( x, y ) > 0 )
            {
                sum = static_cast<int32_t>( ( *i_roi.at( x - 1, y - 1 ) ) > 0 );
                sum += 2 * static_cast<int32_t>( ( *i_roi.at( x, y - 1 ) ) > 0 );
                sum += static_cast<int32_t>( ( *i_roi.at( x + 1, y - 1 ) ) > 0 );
                sum += 2 * static_cast<int32_t>( ( *i_roi.at( x - 1, y ) ) > 0 );
                sum += 4 * static_cast<int32_t>( ( *i_roi.at( x, y ) ) > 0 );
                sum += 2 * static_cast<int32_t>( ( *i_roi.at( x + 1, y ) ) > 0 );
                sum += static_cast<int32_t>( ( *i_roi.at( x - 1, y + 1 ) ) > 0 );
                sum += 2 * static_cast<int32_t>( ( *i_roi.at( x, y + 1 ) ) > 0 );
                sum += static_cast<int32_t>( ( *i_roi.at( x + 1, y + 1 ) ) > 0 );
                weight *= 10.;
            }
            else
            {
                sum = static_cast<int32_t>( ( *i_roi.at( x - 1, y - 1 ) ) == 0 );
                sum += 2 * static_cast<int32_t>( ( *i_roi.at( x, y - 1 ) ) == 0 );
                sum += static_cast<int32_t>( ( *i_roi.at( x + 1, y - 1 ) ) == 0 );
                sum += 2 * static_cast<int32_t>( ( *i_roi.at( x - 1, y ) ) == 0 );
                sum += 4 * static_cast<int32_t>( ( *i_roi.at( x, y ) ) == 0 );
                sum += 2 * static_cast<int32_t>( ( *i_roi.at( x + 1, y ) ) == 0 );
                sum += static_cast<int32_t>( ( *i_roi.at( x - 1, y + 1 ) ) == 0 );
                sum += 2 * static_cast<int32_t>( ( *i_roi.at( x, y + 1 ) ) == 0 );
                sum += static_cast<int32_t>( ( *i_roi.at( x + 1, y + 1 ) ) == 0 );
            }

            score += static_cast<float32_t>( sum ) * weight;
            total_weight += weight;
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    return score / ( ( total_weight > 0. ) ? ( total_weight * 16. ) : 16. );
}

/**
* Generic gaussian filter similarity score.
*/
float32_t t_m::TemplateMatching::GaussianSimilarity( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi, uint32_t i_kernelSize )
{
    float32_t ret_val;

    switch( i_kernelSize )
    {
        case 3:
        {
            ret_val = GaussianSimilarity3x3( i_template, i_roi );
            break;
        }

        default:
        {
            ret_val = -1.0f;
            break;
        }
    }

    return ret_val;
}

/**
* 3x3 Gaussian filter similarity score.
*/
float32_t t_m::TemplateMatching::GaussianSimilarity3x3( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi )
{
#ifdef DIAGNOSTICS
    diag::start( "GaussianSimilarity" );
#endif
    int32_t tmp_step = i_template.getStep();
    int32_t roi_step = i_roi.getStep();
    uint8_t* tmp_ptr;
    uint8_t* tmp_row = i_template.getData() + tmp_step + 1;/* PRQA S 3705*/
    uint8_t* roi_ptr[9];
    uint8_t* roi_row = i_roi.getData() + roi_step + 1;/* PRQA S 3705*/
    uint32_t template_count = 0;
    float32_t score = 0;

    for( uint32_t y = 1; y < ( i_template.getHeight() - 1 ); y++ )
    {
        tmp_ptr = tmp_row;
        roi_ptr[0] = roi_row - roi_step - 1;/* PRQA S 3705*/
        roi_ptr[1] = roi_row - roi_step;/* PRQA S 3705*/
        roi_ptr[2] = roi_row - roi_step + 1;/* PRQA S 3705*/
        roi_ptr[3] = roi_row - 1;/* PRQA S 3705*/
        roi_ptr[4] = roi_row;
        roi_ptr[5] = roi_row + 1;/* PRQA S 3705*/
        roi_ptr[6] = roi_row + roi_step - 1;/* PRQA S 3705*/
        roi_ptr[7] = roi_row + roi_step;/* PRQA S 3705*/
        roi_ptr[8] = roi_row + roi_step + 1;/* PRQA S 3705*/

        for( uint32_t x = 1; x < ( i_template.getWidth() - 1 ); x++ )
        {
            if( *tmp_ptr > 0 )
            {
                ++template_count;
                score +=         static_cast<float32_t>( ( *roi_ptr[0] ) > 0 ) + \
                                 2. * static_cast<float32_t>( ( *roi_ptr[1] ) > 0 ) + \
                                 static_cast<float32_t>( ( *roi_ptr[2] ) > 0 ) + \
                                 2. * static_cast<float32_t>( ( *roi_ptr[3] ) > 0 ) + \
                                 4. * static_cast<float32_t>( ( *roi_ptr[4] ) > 0 ) + \
                                 2. * static_cast<float32_t>( ( *roi_ptr[5] ) > 0 ) + \
                                 static_cast<float32_t>( ( *roi_ptr[6] ) > 0 ) + \
                                 2. * static_cast<float32_t>( ( *roi_ptr[7] ) > 0 ) + \
                                 static_cast<float32_t>( ( *roi_ptr[8] ) > 0 );
            }

            ++tmp_ptr;
            ++roi_ptr[0];
            ++roi_ptr[1];
            ++roi_ptr[2];
            ++roi_ptr[3];
            ++roi_ptr[4];
            ++roi_ptr[5];
            ++roi_ptr[6];
            ++roi_ptr[7];
            ++roi_ptr[8];
        }

        tmp_row += tmp_step;
        roi_row += roi_step;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    float32_t ret_val;

    if( template_count == 0 )
    {
        ret_val = 0.0f;
    }
    else
    {
        ret_val = score / static_cast<float32_t>( 16 * template_count );
    }

    return ret_val;
}

/**
* 3x3 Gaussian filter similarity score, weighted using weight mask.
*/
float32_t t_m::TemplateMatching::GaussianSimilarityWeighted3x3( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_roi, float32_t i_factor )
{
    float32_t ret_val;
    bool_t isReturned = true;

    if( ( mask::TemplateWeightMaskSize[0] != i_template.getHeight() ) || ( mask::TemplateWeightMaskSize[1] != i_template.getWidth() ) )
    {
        ret_val = 0.0f;
        isReturned = false;
    }

    if( isReturned )
    {
#ifdef DIAGNOSTICS
        diag::start( "GaussianSimilarity" );
#endif
        //
        // --- Loop
        int32_t tmp_step = i_template.getStep();
        int32_t roi_step = i_roi.getStep();
        uint8_t* tmp_ptr;
        uint8_t* tmp_row = i_template.getData() + tmp_step + 1;/* PRQA S 3705*/
        uint8_t* roi_ptr[9];
        uint8_t* roi_row = i_roi.getData() + roi_step + 1;/* PRQA S 3705*/
        uint32_t template_count = 0;
        float32_t score = 0;
        int32_t sum;

        for( uint32_t y = 1; y < ( i_template.getHeight() - 1 ); y++ )
        {
            tmp_ptr = tmp_row;
            roi_ptr[0] = roi_row - roi_step - 1;/* PRQA S 3705*/
            roi_ptr[1] = roi_row - roi_step;/* PRQA S 3705*/
            roi_ptr[2] = roi_row - roi_step + 1;/* PRQA S 3705*/
            roi_ptr[3] = roi_row - 1;/* PRQA S 3705*/
            roi_ptr[4] = roi_row;
            roi_ptr[5] = roi_row + 1;/* PRQA S 3705*/
            roi_ptr[6] = roi_row + roi_step - 1;/* PRQA S 3705*/
            roi_ptr[7] = roi_row + roi_step;/* PRQA S 3705*/
            roi_ptr[8] = roi_row + roi_step + 1;/* PRQA S 3705*/

            for( uint32_t x = 1; x < ( i_template.getWidth() - 1 ); x++ )
            {
                if( *tmp_ptr > 0 )
                {
                    ++template_count;
                    sum = static_cast<int32_t>( ( *roi_ptr[0] ) > 0 ) + \
                          2 * static_cast<int32_t>( ( *roi_ptr[1] ) > 0 ) + \
                          static_cast<int32_t>( ( *roi_ptr[2] ) > 0 ) + \
                          2 * static_cast<int32_t>( ( *roi_ptr[3] ) > 0 ) + \
                          4 * static_cast<int32_t>( ( *roi_ptr[4] ) > 0 ) + \
                          2 * static_cast<int32_t>( ( *roi_ptr[5] ) > 0 ) + \
                          static_cast<int32_t>( ( *roi_ptr[6] ) > 0 ) + \
                          2 * static_cast<int32_t>( ( *roi_ptr[7] ) > 0 ) + \
                          static_cast<int32_t>( ( *roi_ptr[8] ) > 0 );
                    score += static_cast<float32_t>( sum ) * ( mms::maximum( 1.0f + mask::TemplateWeightMask[y][x] * i_factor, 0.0f ) );
                }

                ++tmp_ptr;
                ++roi_ptr[0];
                ++roi_ptr[1];
                ++roi_ptr[2];
                ++roi_ptr[3];
                ++roi_ptr[4];
                ++roi_ptr[5];
                ++roi_ptr[6];
                ++roi_ptr[7];
                ++roi_ptr[8];
            }

            tmp_row += tmp_step;
            roi_row += roi_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif

        if( template_count == 0 )
        {
            ret_val = 0.0f;
        }
        else
        {
            ret_val = score / static_cast<float32_t>( 16 * template_count );
        }
    }

    return ret_val;
}
/*
* Experimental of new method of scoring algorithm
*/
float32_t t_m::TemplateMatching::GaussianSimilarityWeighted3x3_6( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, float32_t i_factor, uint16_t othsuthresh )
{
    i_factor = i_factor;
#ifdef DIAGNOSTICS
    diag::start( "GaussianSimilarityWeighted3x3_2" );
#endif
    int32_t start_x = 0;
    int32_t end_x = i_template.getWidth();
    int32_t start_y = 0;
    int32_t end_y = i_template.getHeight();
    uint32_t template_count = 0;
    float32_t score = 0;
    int32_t sum;

    if( i_x < 0 )
    {
        start_x = mms::minimum( -i_x, static_cast<int32_t>( i_template.getWidth() ) );
    }

    if( ( i_x + static_cast<int32_t>( i_template.getWidth() ) ) > static_cast<int32_t>( warped_Img.getWidth() ) )
    {
        end_x = mms::maximum( static_cast<int32_t>( warped_Img.getWidth() ) - i_x , 0 );
    }

    if( i_y < 0 )
    {
        start_y = mms::minimum( -i_y, static_cast<int32_t>( i_template.getHeight() ) );
    }

    if( ( i_y + static_cast<int32_t>( i_template.getHeight() ) ) > static_cast<int32_t>( warped_Img.getHeight() ) )
    {
        end_y = mms::maximum( static_cast<int32_t>( warped_Img.getHeight() ) - i_y, 0 );
    }

    for( int32_t x = ( start_x + 1 ); x < ( end_x - 1 ); x++ )
    {
        for( int32_t y = ( start_y + 1 ); y < ( end_y - 1 ); y++ )
        {
            if( *i_template.at( x, y ) > 0 )
            {
                ++template_count;
                sum = ( 4 * static_cast<int32_t>( ( ( *warped_Img.at( i_x + x, i_y + y ) ) > othsuthresh ) ) );
                score += static_cast<float32_t>( sum );
            }
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    float32_t ret_val;

    if( template_count == 0 )
    {
        ret_val = 0;
    }
    else
    {
        ret_val = score / static_cast<float32_t>( 16 * template_count );
    }

    return ret_val;
}
/*
* Experimental of new method of scoring algorithm
*/
float32_t t_m::TemplateMatching::GaussianSimilarityWeighted3x3_4( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, float32_t i_factor, uint16_t othsuthresh )
{
#ifdef DIAGNOSTICS
    diag::start( "GaussianSimilarityWeighted3x3_2" );
#endif
    int32_t start_x = 0;
    int32_t end_x = i_template.getWidth();
    int32_t start_y = 0;
    int32_t end_y = i_template.getHeight();
    uint32_t template_count = 0;
    float32_t score = 0.0f;
    int32_t sum = 0;

    if( i_x < 0 )
    {
        start_x = mms::minimum( -i_x, static_cast<int32_t>( i_template.getWidth() ) );
    }

    if( ( i_x + static_cast<int32_t>( i_template.getWidth() ) ) > static_cast<int32_t>( warped_Img.getWidth() ) )
    {
        end_x = mms::maximum( static_cast<int32_t>( warped_Img.getWidth() ) - i_x, 0 );
    }

    if( i_y < 0 )
    {
        start_y = mms::minimum( -i_y, static_cast<int32_t>( i_template.getHeight() ) );
    }

    if( ( i_y + static_cast<int32_t>( i_template.getHeight() ) ) > static_cast<int32_t>( warped_Img.getHeight() ) )
    {
        end_y = mms::maximum( static_cast<int32_t>( warped_Img.getHeight() ) - i_y, 0 );
    }

    for( int32_t x = ( start_x + 1 ); x < ( end_x - 1 ); x++ )
    {
        for( int32_t y = ( start_y + 1 ); y < ( end_y - 1 ); y++ )
        {
            if( ( *i_template.at( x, y ) > 0 ) && ( mask::TemplateWeightMask[y][x] > 0.0f ) )
            {
                ++template_count;
                sum = static_cast<int32_t>( ( ( *warped_Img.at( i_x + x - 1, i_y + y - 1 ) ) > othsuthresh ) );
                sum += ( static_cast<int32_t>( ( ( *warped_Img.at( i_x + x, i_y + y - 1 ) ) > othsuthresh ) ) );
                sum += static_cast<int32_t>( ( ( *warped_Img.at( i_x + x + 1, i_y + y - 1 ) ) > othsuthresh ) );
                sum += ( static_cast<int32_t>( ( ( *warped_Img.at( i_x + x - 1, i_y + y ) ) > othsuthresh ) ) );
                sum += ( static_cast<int32_t>( ( ( *warped_Img.at( i_x + x, i_y + y ) ) > othsuthresh ) ) );
                sum += ( static_cast<int32_t>( ( ( *warped_Img.at( i_x + x + 1, i_y + y ) ) > othsuthresh ) ) );
                sum += static_cast<int32_t>( ( ( ( *warped_Img.at( i_x + x - 1, i_y + y + 1 ) ) > othsuthresh ) ) );
                sum += ( static_cast<int32_t>( ( ( *warped_Img.at( i_x + x, i_y + y + 1 ) ) > othsuthresh ) ) );
                sum += static_cast<int32_t>( ( ( ( *warped_Img.at( i_x + x + 1, i_y + y + 1 ) ) > othsuthresh ) ) );

                //score += static_cast<float32_t>( sum ) * ( mms::maximum( 1.0f + mask::TemplateWeightMask[y][x] * i_factor, 0.0f ) );
                //score += static_cast<float32_t>( sum ) * ( mms::maximum( 1.0f + mask::TemplateWeightMask[( i_template.getHeight() - 1 ) - y][( i_template.getWidth() - 1 ) - x] * i_factor, 0.0f ) );
                if( score == 0.0f )
                {
                    score -= static_cast<float32_t>( 10.0f );
                }
                else
                {
                    score += static_cast<float32_t>( sum );
                }
            }
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    float32_t ret_val;

    if( template_count == 0 )
    {
        ret_val = 0;
    }
    else
    {
        ret_val = score / static_cast<float32_t>( 16 * template_count );
    }

    return ret_val;
}
/*
* First optimized version of 'GaussianSimilarityWeighted3x3()'.
*/
float32_t t_m::TemplateMatching::GaussianSimilarityWeighted3x3_2( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, float32_t i_factor, uint16_t othsuthresh )
{
#ifdef DIAGNOSTICS
    diag::start( "GaussianSimilarityWeighted3x3_2" );
#endif
    int32_t start_x = 0;
    int32_t end_x = i_template.getWidth();
    int32_t start_y = 0;
    int32_t end_y = i_template.getHeight();
    uint32_t template_count = 0;
    float32_t score = 0;
    int32_t sum;

    if( i_x < 0 )
    {
        start_x = mms::minimum( -i_x, static_cast<int32_t>( i_template.getWidth() ) );
    }

    if( ( i_x + static_cast<int32_t>( i_template.getWidth() ) ) > static_cast<int32_t>( warped_Img.getWidth() ) )
    {
        end_x = mms::maximum( static_cast<int32_t>( warped_Img.getWidth() ) - i_x , 0 );
    }

    if( i_y < 0 )
    {
        start_y = mms::minimum( -i_y, static_cast<int32_t>( i_template.getHeight() ) );
    }

    if( ( i_y + static_cast<int32_t>( i_template.getHeight() ) ) > static_cast<int32_t>( warped_Img.getHeight() ) )
    {
        end_y = mms::maximum( static_cast<int32_t>( warped_Img.getHeight() ) - i_y, 0 );
    }

    for( int32_t x = start_x + 1; x < ( end_x - 1 ); x++ )
    {
        for( int32_t y = start_y + 1; y < ( end_y - 1 ); y++ )
        {
            if( *i_template.at( x, y ) > 0 )
            {
                ++template_count;
                sum = static_cast<int32_t>( ( *warped_Img.at( i_x + x - 1, i_y + y - 1 ) ) > othsuthresh );
                sum += 2 * static_cast<int32_t>( ( *warped_Img.at( i_x + x, i_y + y - 1 ) ) > othsuthresh );
                sum += static_cast<int32_t>( ( *warped_Img.at( i_x + x + 1, i_y + y - 1 ) ) > othsuthresh );
                sum += 2 * static_cast<int32_t>( ( *warped_Img.at( i_x + x - 1, i_y + y ) ) > othsuthresh );
                sum += 4 * static_cast<int32_t>( ( *warped_Img.at( i_x + x, i_y + y ) ) > othsuthresh );
                sum += 2 * static_cast<int32_t>( ( *warped_Img.at( i_x + x + 1, i_y + y ) ) > othsuthresh );
                sum += static_cast<int32_t>( ( *warped_Img.at( i_x + x - 1, i_y + y + 1 ) ) > othsuthresh );
                sum += 2 * static_cast<int32_t>( ( *warped_Img.at( i_x + x, i_y + y + 1 ) ) > othsuthresh );
                sum += static_cast<int32_t>( ( *warped_Img.at( i_x + x + 1, i_y + y + 1 ) ) > othsuthresh );
                score += static_cast<float32_t>( sum ) * ( mms::maximum( 1.0f + mask::TemplateWeightMask[y][x] * i_factor, 0.0f ) );
            }
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    float32_t ret_val;

    if( template_count == 0 )
    {
        ret_val = 0;
    }
    else
    {
        ret_val = score / static_cast<float32_t>( 16 * template_count );
    }

    return ret_val;
}

/*
* Second optimized version of 'GaussianSimilarityWeighted3x3()'.
*/
float32_t t_m::TemplateMatching::GaussianSimilarityWeighted3x3_3( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, float32_t i_factor )
{
#ifdef DIAGNOSTICS
    diag::start( "GaussianSimilarityWeighted3x3_3" );
#endif
    int32_t start_x = 0;
    int32_t end_x = i_template.getWidth();
    int32_t start_y = 0;
    int32_t end_y = i_template.getHeight();
    uint32_t template_count = 0;
    float32_t score = 0;
    int32_t sum;
    int32_t indx;
    int32_t indy;

    if( i_x < 0 )
    {
        start_x = mms::minimum( -i_x, static_cast<int32_t>( i_template.getWidth() ) );
    }

    if( ( i_x + static_cast<int32_t>( i_template.getWidth() ) ) > static_cast<int32_t>( warped_Img.getWidth() ) )
    {
        end_x = mms::maximum( static_cast<int32_t>( warped_Img.getWidth() ) - i_x, 0 );
    }

    if( i_y < 0 )
    {
        start_y = mms::minimum( -i_y, static_cast<int32_t>( i_template.getHeight() ) );
    }

    if( ( i_y + static_cast<int32_t>( i_template.getHeight() ) ) > static_cast<int32_t>( warped_Img.getHeight() ) )
    {
        end_y = mms::maximum( static_cast<int32_t>( warped_Img.getHeight() ) - i_y, 0 );
    }

    for( int32_t y = start_y + 1; y < ( end_y - 1 ); y++ )
    {
        indy = i_y + y - 1;

        for( int32_t x = start_x + 1; x < ( end_x - 1 ); x++ )
        {
            indx = i_x + x - 1;

            if( *i_template.at( x, y ) > 0 )
            {
                ++template_count;
                sum = ( ( ( *warped_Img.at( indx, indy ) ) > 0 ) ? 1 : 0 );
                sum += ( ( ( *warped_Img.at( indx + 1, indy ) ) > 0 ) ? 2 : 0 );
                sum += ( ( ( *warped_Img.at( indx + 2, indy ) ) > 0 ) ? 1 : 0 );
                sum += ( ( ( *warped_Img.at( indx, indy + 1 ) ) > 0 ) ? 2 : 0 );
                sum += ( ( ( *warped_Img.at( indx + 1, indy + 1 ) ) > 0 ) ? 4 : 0 );
                sum += ( ( ( *warped_Img.at( indx + 2, indy + 1 ) ) > 0 ) ? 2 : 0 );
                sum += ( ( ( *warped_Img.at( indx, indy + 2 ) ) > 0 ) ? 1 : 0 );
                sum += ( ( ( *warped_Img.at( indx + 1, indy + 2 ) ) > 0 ) ? 2 : 0 );
                sum += ( ( ( *warped_Img.at( indx + 2, indy + 2 ) ) > 0 ) ? 1 : 0 );
                score += static_cast<float32_t>( sum ) * ( mms::maximum( 1.0f + mask::TemplateWeightMask[y][x] * i_factor, 0.0f ) );
            }
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    float32_t ret_val;

    if( template_count == 0 )
    {
        ret_val = 0;
    }
    else
    {
        ret_val = score / static_cast<float32_t>( 16 * template_count );
    }

    return ret_val;
}
/*
* experimental 'GaussianSimilarityWeighted3x3()'.
*/
float32_t t_m::TemplateMatching::GaussianSimilarityWeighted3x3_5( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, float32_t i_factor, uint16_t othsuthresh )
{
#ifdef DIAGNOSTICS
    diag::start( "GaussianSimilarityWeighted3x3_3" );
#endif
    int32_t start_x = 0;
    int32_t end_x = i_template.getWidth();
    int32_t start_y = 0;
    int32_t end_y = i_template.getHeight();
    uint32_t template_count = 0;
    uint32_t zero_count = 0;
    float32_t score = 0.0f;
    float32_t zero_score = 0.0f;
    int32_t sum = 0;
    int32_t indx = 0;
    int32_t indy = 0;

    if( i_x < 0 )
    {
        start_x = mms::minimum( -i_x, static_cast<int32_t>( i_template.getWidth() ) );
    }

    if( ( i_x + static_cast<int32_t>( i_template.getWidth() ) ) > ( static_cast<int32_t>( warped_Img.getWidth() ) ) )
    {
        end_x = mms::maximum( static_cast<int32_t>( warped_Img.getWidth() ) - i_x, 0 );
    }

    if( i_y < 0 )
    {
        start_y = mms::minimum( -i_y, static_cast<int32_t>( i_template.getHeight() ) );
    }

    if( ( i_y + static_cast<int32_t>( i_template.getHeight() ) ) > ( static_cast<int32_t>( warped_Img.getHeight() ) ) )
    {
        end_y = mms::maximum( static_cast<int32_t>( warped_Img.getHeight() ) - i_y, 0 );
    }

    for( int32_t y = start_y + 5; y < ( end_y - 5 ); y++ )
    {
        indy = i_y + y - 1;

        for( int32_t x = start_x + 5; x < ( end_x - 5 ); x++ )
        {
            indx = i_x + x - 1;

            if( *i_template.at( x, y ) > 0 )
            {
                ++template_count;
                sum = ( ( ( *warped_Img.at( indx, indy ) ) > othsuthresh ) ? 1 : 0 );
                sum += ( ( ( *warped_Img.at( indx + 1, indy ) ) > othsuthresh ) ? 2 : 0 );
                sum += ( ( ( *warped_Img.at( indx + 2, indy ) ) > othsuthresh ) ? 1 : 0 );
                sum += ( ( ( *warped_Img.at( indx, indy + 1 ) ) > othsuthresh ) ? 2 : 0 );
                sum += ( ( ( *warped_Img.at( indx + 1, indy + 1 ) ) > othsuthresh ) ? 4 : 0 );
                sum += ( ( ( *warped_Img.at( indx + 2, indy + 1 ) ) > othsuthresh ) ? 2 : 0 );
                sum += ( ( ( *warped_Img.at( indx, indy + 2 ) ) > othsuthresh ) ? 1 : 0 );
                sum += ( ( ( *warped_Img.at( indx + 1, indy + 2 ) ) > othsuthresh ) ? 2 : 0 );
                sum += ( ( ( *warped_Img.at( indx + 2, indy + 2 ) ) > othsuthresh ) ? 1 : 0 );
                score += static_cast<float32_t>( sum ) * ( mms::maximum( 1.0f + mask::TemplateWeightMask[y][x] * i_factor, 0.0f ) );
            }

            if( *i_template.at( x, y ) == 0 )
            {
                ++zero_count;
                zero_score += static_cast<float32_t>( ( ( ( *warped_Img.at( indx, indy ) ) < othsuthresh ) ? 1 : 0 ) );
            }
        }
    }

    if( ( zero_score / static_cast<float32_t>( zero_count ) ) > 0.80f )
    {
        zero_score = 1.0f;
    }
    else
    {
        zero_score = 0.10f;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    float32_t ret_val;

    if( template_count == 0 )
    {
        ret_val = 0;
    }
    else
    {
        ret_val = ( ( score / static_cast<float32_t>( 10 * template_count ) ) *  zero_score );
		//ret_val = ((score / static_cast<float32_t>(16 * template_count)) *  zero_score); // this was the default value. it was reduced to tackle tracking lost
    }

    return ret_val;
}
/*
* experimental 'GaussianSimilarityWeighted3x3()'.
*/
float32_t t_m::TemplateMatching::GaussianSimilarityWeighted3x3_7( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, uint16_t othsuthresh )
{
#ifdef DIAGNOSTICS
    diag::start( "GaussianSimilarityWeighted3x3_7" );
#endif
    int32_t start_x = 0;
    int32_t end_x = i_template.getWidth();
    int32_t start_y = 0;
    int32_t end_y = i_template.getHeight();
    uint32_t template_count = 0;
    uint32_t zero_count = 0;
    float32_t score = 0.0f;
    float32_t zero_score = 0.0f;
    int32_t sum = 0;
    int32_t indx = 0;
    int32_t indy = 0;

    if( i_x < 0 )
    {
        start_x = mms::minimum( -i_x, static_cast<int32_t>( i_template.getWidth() ) );
    }

    if( ( i_x + static_cast<int32_t>( i_template.getWidth() ) ) > ( static_cast<int32_t>( warped_Img.getWidth() ) ) )
    {
        end_x = mms::maximum( static_cast<int32_t>( warped_Img.getWidth() ) - i_x, 0 );
    }

    if( i_y < 0 )
    {
        start_y = mms::minimum( -i_y, static_cast<int32_t>( i_template.getHeight() ) );
    }

    if( ( i_y + static_cast<int32_t>( i_template.getHeight() ) ) > ( static_cast<int32_t>( warped_Img.getHeight() ) ) )
    {
        end_y = mms::maximum( static_cast<int32_t>( warped_Img.getHeight() ) - i_y, 0 );
    }

    for( int32_t y = start_y + 1; y < ( end_y - 1 ); y++ )
    {
        indy = i_y + y - 1;

        for( int32_t x = start_x + 1; x < ( end_x - 1 ); x++ )
        {
            indx = i_x + x - 1;

            if( *i_template.at( x, y ) > 0 )
            {
                score += ( *warped_Img.at( indx, indy ) );
            }
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    return score;
}
/**
* 3x3 Gaussian filter similarity score, weighted using weight mask, using edge direction.
*
* Not tested.
*/
float32_t t_m::TemplateMatching::GaussianSimilarityWeighted3x3_WithEdgeDir( image::Image<uint8_t>& i_template, image::Image<uint8_t>& i_templateDir, image::Image<uint8_t>& i_roi, image::Image<uint8_t>& i_roiDir, float32_t i_factor )
{
#ifdef DIAGNOSTICS
    diag::start( "GaussianSimilarity" );
#endif
    //
    const float32_t dir_map[4][4] = { { 1.0f, 0.5f, 0.0f, 0.5f },
        { 0.5f, 1.0f, 0.5f, 0.0f },
        { 0.0f, 0.5f, 1.0f, 0.5f },
        { 0.5f, 0.0f, 0.5f, 1.0f }
    };
    //
    // --- Loop
    int32_t tmp_step = i_template.getStep();
    int32_t tmpDir_step = i_templateDir.getStep();
    int32_t roi_step = i_roiDir.getStep();
    int32_t roiDir_step = i_roi.getStep();
    uint8_t* tmp_ptr;
    uint8_t* tmp_row = i_template.getData() + tmp_step + 1;/* PRQA S 3705*/
    uint8_t* tmpDir_ptr;
    uint8_t* tmpDir_row = i_templateDir.getData() + tmpDir_step + 1;/* PRQA S 3705*/
    uint8_t* roi_ptr[3];
    uint8_t* roi_row = i_roi.getData() + roi_step + 1;/* PRQA S 3705*/
    uint8_t* roiDir_ptr[3];
    uint8_t* roiDir_row = i_roiDir.getData() + roiDir_step + 1;/* PRQA S 3705*/
    uint32_t template_count = 0;
    float32_t score = 0;
    float32_t sum;

    for( uint32_t y = 1; y < ( i_template.getHeight() - 1 ); y++ )
    {
        tmp_ptr = tmp_row;
        tmpDir_ptr = tmpDir_row;
        roi_ptr[0] = roi_row - roi_step;/* PRQA S 3705*/
        roi_ptr[1] = roi_row;
        roi_ptr[2] = roi_row + roi_step;/* PRQA S 3705*/
        roiDir_ptr[0] = roiDir_row - roiDir_step;/* PRQA S 3705*/
        roiDir_ptr[1] = roiDir_row;
        roiDir_ptr[2] = roiDir_row + roiDir_step;/* PRQA S 3705*/

        for( uint32_t x = 1; x < ( i_template.getWidth() - 1 ); x++ )
        {
            if( *tmp_ptr > 0 )
            {
                ++template_count;
                /* PRQA S 3705*/sum = static_cast<float32_t>( *( roi_ptr[0] - 1 ) > 0 ) * ( dir_map[*( roiDir_ptr[0] - 1 )][*tmpDir_ptr] ) + \
                                      2. * static_cast<float32_t>( *( roi_ptr[0] ) > 0 ) * ( dir_map[*( roiDir_ptr[0] )][*tmpDir_ptr] ) + \
                                      /* PRQA S 3705*/    static_cast<float32_t>( *( roi_ptr[0] + 1 ) > 0 ) * ( dir_map[*( roiDir_ptr[0] + 1 )][*tmpDir_ptr] ) + \
                                      /* PRQA S 3705*/    2. * static_cast<float32_t>( *( roi_ptr[1] - 1 ) > 0 ) * ( dir_map[*( roiDir_ptr[1] - 1 )][*tmpDir_ptr] ) + \
                                      4. * static_cast<float32_t>( *( roi_ptr[1] ) > 0 ) * ( dir_map[*( roiDir_ptr[1] )][*tmpDir_ptr] ) + \
                                      /* PRQA S 3705*/    2. * static_cast<float32_t>( *( roi_ptr[1] + 1 ) > 0 ) * ( dir_map[*( roiDir_ptr[1] + 1 )][*tmpDir_ptr] ) + \
                                      /* PRQA S 3705*/    static_cast<float32_t>( *( roi_ptr[2] - 1 ) > 0 ) * ( dir_map[*( roiDir_ptr[2] - 1 )][*tmpDir_ptr] ) + \
                                      2. * static_cast<float32_t>( *( roi_ptr[2] ) > 0 ) * ( dir_map[*( roiDir_ptr[2] )][*tmpDir_ptr] ) + \
                                      /* PRQA S 3705*/    static_cast<float32_t>( *( roi_ptr[2] + 1 ) > 0 ) * ( dir_map[*( roiDir_ptr[2] + 1 )][*tmpDir_ptr] );
                score += sum * ( mms::maximum( 1.0f + mask::TemplateWeightMask[y][x] * i_factor, 0.0f ) );
            }

            ++tmp_ptr;
            ++tmpDir_ptr;
            ++roi_ptr[0];
            ++roi_ptr[1];
            ++roi_ptr[2];
            ++roiDir_ptr[0];
            ++roiDir_ptr[1];
            ++roiDir_ptr[2];
        }

        tmp_row += tmp_step;
        tmpDir_row += tmpDir_step;
        roi_row += roi_step;
        roiDir_row += roiDir_step;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    return  score / static_cast<float32_t>( 16 * template_count );
}

/**
* 3x3 Gaussian filter similarity score, weighted using weight mask. Normalized using
* the total amount of weight of each edge in the template rather than using the number
* of template edges.
*/
float32_t t_m::TemplateMatching::GaussianSimilarityWeighted3x3_CorrectedNormalization( image::Image<uint8_t>& i_template, image::Image<uint8_t>& warped_Img, int32_t i_x, int32_t i_y, float32_t i_factor )
{
#ifdef DIAGNOSTICS
    diag::start( "GaussianSimilarityWeighted3x3_2" );
#endif
    int32_t start_x = 0;
    int32_t end_x = i_template.getWidth();
    int32_t start_y = 0;
    int32_t end_y = i_template.getHeight();
    float32_t total_weight = 0.0f;
    float32_t score = 0;
    int32_t sum;

    if( i_x < 0 )
    {
        start_x = mms::minimum( -i_x, static_cast<int32_t>( i_template.getWidth() ) );
    }

    if( ( i_x + static_cast<int32_t>( i_template.getWidth() ) ) > static_cast<int32_t>( warped_Img.getWidth() ) )
    {
        end_x = mms::maximum( static_cast<int32_t>( warped_Img.getWidth() ) - i_x, 0 );
    }

    if( i_y < 0 )
    {
        start_y = mms::minimum( -i_y, static_cast<int32_t>( i_template.getHeight() ) );
    }

    if( ( i_y + static_cast<int32_t>( i_template.getHeight() ) ) > static_cast<int32_t>( warped_Img.getHeight() ) )
    {
        end_y = mms::maximum( static_cast<int32_t>( warped_Img.getHeight() ) - i_y, 0 );
    }

    for( int32_t x = start_x + 1; x < ( end_x - 1 ); x++ )
    {
        for( int32_t y = start_y + 1; y < ( end_y - 1 ); y++ )
        {
            if( *i_template.at( x, y ) > 0 )
            {
                sum = static_cast<int32_t>( ( *warped_Img.at( i_x + x - 1, i_y + y - 1 ) ) > 0 );
                sum += 2 * static_cast<int32_t>( ( *warped_Img.at( i_x + x, i_y + y - 1 ) ) > 0 );
                sum += static_cast<int32_t>( ( *warped_Img.at( i_x + x + 1, i_y + y - 1 ) ) > 0 );
                sum += 2 * static_cast<int32_t>( ( *warped_Img.at( i_x + x - 1, i_y + y ) ) > 0 );
                sum += 4 * static_cast<int32_t>( ( *warped_Img.at( i_x + x, i_y + y ) ) > 0 );
                sum += 2 * static_cast<int32_t>( ( *warped_Img.at( i_x + x + 1, i_y + y ) ) > 0 );
                sum += static_cast<int32_t>( ( *warped_Img.at( i_x + x - 1, i_y + y + 1 ) ) > 0 );
                sum += 2 * static_cast<int32_t>( ( *warped_Img.at( i_x + x, i_y + y + 1 ) ) > 0 );
                sum += static_cast<int32_t>( ( *warped_Img.at( i_x + x + 1, i_y + y + 1 ) ) > 0 );
                score += static_cast<float32_t>( sum ) * ( mms::maximum( 1.0f + mask::TemplateWeightMask[y][x] * i_factor, 0.0f ) );
                total_weight += ( mms::maximum( 1.0f + mask::TemplateWeightMask[y][x] * i_factor, 0.0f ) );
            }
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    float32_t ret_val;
    float64_t epsilon = std::numeric_limits<float64_t>::epsilon();
    float64_t scale = ( std::fabs( static_cast<float64_t>( total_weight ) ) + std::fabs( static_cast<float64_t>( 0 ) ) ) / 2.0f;
    float64_t result = std::fabs( static_cast<float64_t>( total_weight - 0.0f ) ) <= ( epsilon * scale );

    if( static_cast<bool>( result ) )
    {
        ret_val = 0.0f;
    }
    else
    {
        ret_val = score / static_cast<float32_t>( 16.0f * total_weight );
    }

    return ret_val;
}
