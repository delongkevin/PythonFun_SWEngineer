// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [05-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "EdgeDetector.h"

/*
* Perform Canny edge detection on an image.
*
* Will calculate the values for the input images which are not NULL.
*/
TAD2::Canny::Canny( image::Image<uint8_t> i_image, image::Image<uint16_t> i_thresh_low, image::Image<uint16_t> i_thresh_high, image::Image<uint8_t> o_edges, image::Image<uint16_t> o_gradMag, image::Image<uint8_t> o_gradDir ) \
:
initOK()
{
    // --- Check which output images are null to determine which algorithms to run
    if( o_edges.getData() == NULL )
    {
        if( ( ( o_gradDir.getData() == NULL ) && ( o_gradMag.getData() == NULL ) ) || ( ( o_gradDir.getData() != NULL ) && ( o_gradMag.getData() == NULL ) ) )
        {
        }
        else if( ( o_gradDir.getData() == NULL ) && ( o_gradMag.getData() != NULL ) )
        {
            _CalculateGradientMagnitude( i_image, o_gradMag );
        }
        else if( ( o_gradDir.getData() != NULL ) && ( o_gradMag.getData() != NULL ) )
        {
            _CalculateGradientMagnitudeAndDirection( i_image, o_gradMag, o_gradDir );
        }
        else
        {
        }
    }
    else // o_edges.getData() != NULL
    {
        bool_t outputGradMag = true;
        bool_t outputGradDir = true;

        if( o_gradMag.getData() == NULL )
        {
            o_gradMag = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
            o_gradMag.get_dimensions_from( i_image );
            outputGradMag = false;

            if( o_gradMag.getSize() < i_image.getSize() )
            {
                assert( 0 );
            }
        }

        if( o_gradDir.getData() == NULL )
        {
            o_gradDir = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
            o_gradDir.get_dimensions_from( i_image );
            outputGradDir = false;

            if( o_gradDir.getSize() < i_image.getSize() )
            {
                assert( 0 );
            }
        }

        // --- Run Canny
        processing::ImageProcessing::Clear( o_edges );
        _CannyEdges( i_image, i_thresh_low, i_thresh_high, o_gradMag, o_gradDir, o_edges );

        if( !outputGradMag )
        {
            memory::MemoryPool::ReleaseImage( o_gradMag );
        }

        if( !outputGradDir )
        {
            memory::MemoryPool::ReleaseImage( o_gradDir );
        }
    }

    return;
}

/*
* Called on destruction.
*/
TAD2::Canny::~Canny()
{
}

/*
* Actual Canny algorithm.
*/
void TAD2::Canny::_CannyEdges( image::Image<uint8_t>& i_image, image::Image<uint16_t> i_thresh_low, image::Image<uint16_t> i_thresh_high, image::Image<uint16_t>& o_gradientMag, image::Image<uint8_t>& o_gradientDir, image::Image<uint8_t>& o_edges )
{
    i_image = i_image;
#ifdef DIAGNOSTICS
    diag::start( "_CannyEdges (new)" );
#endif
    // --- Queue of pixels that are edges
    struct Pixel
    {
        uint16_t x;
        uint16_t y;
    };
    image::Image<uint32_t> heapData = memory::MemoryPool::GetImage<uint32_t>( itype::IMTP_TopView_U32C1 );
    Pixel* queue = reinterpret_cast<Pixel*>( heapData.getData() );
    Pixel* end = &queue[0]; /*PRQA S 3706*/
    const sint32_t mag_step = o_gradientMag.getStep();
    const uint32_t dir_step = o_gradientDir.getStep();
    const uint32_t edg_step = o_edges.getStep();
    const uint32_t lo_step = i_thresh_low.getStep();
    const uint32_t hi_step = i_thresh_high.getStep();
    //
    // --- Non-maxima suppression
#ifdef DIAGNOSTICS
    diag::start( "_CannyEdges: Non-maxima suppression (new)" );
#endif
    uint16_t* mag_row = o_gradientMag.getData() + mag_step + 1; /*PRQA S 3705*/
    uint16_t* mag_ptr;
    uint8_t* dir_row = o_gradientDir.getData() + dir_step + 1;/*PRQA S 3705*/
    uint8_t* dir_ptr;
    uint8_t* edg_row = o_edges.getData() + edg_step + 1;/*PRQA S 3705*/
    uint8_t* edg_ptr;
    uint16_t* lo_row = i_thresh_low.getData() + lo_step + 1;/*PRQA S 3705*/
    uint16_t* lo_ptr;
    uint16_t* hi_row = i_thresh_high.getData() + hi_step + 1;/*PRQA S 3705*/
    uint16_t* hi_ptr;
    sint32_t offset_array[] = { -1, -mag_step - 1, -mag_step, +static_cast<sint32_t>( mag_step ) - 1};

    for( uint16_t y = 2; y < ( o_gradientMag.getHeight() - 2 ); ++y )
    {
        mag_ptr = mag_row;
        dir_ptr = dir_row;
        edg_ptr = edg_row;
        lo_ptr = lo_row;
        hi_ptr = hi_row;

        for( uint16_t x = 2; x < ( o_gradientMag.getWidth() - 2 ); ++x )
        {
            uint16_t m1 = *( mag_ptr + offset_array[*dir_ptr] );/*PRQA S 3705*/
            uint16_t m2 = *( mag_ptr - offset_array[*dir_ptr] );/*PRQA S 3705*/

            if( ( m1 >= *mag_ptr ) || ( m2 >= *mag_ptr ) )
            {
                // suppression
                //
                // this solution results in double edges
                // new temporary solution to keep this pixel from being added as edge while not
                // changing magnitude image (this solution doesn't account for grad values > 255)
                *lo_ptr = 400; // modifies threshold image!
            }
            else if( *mag_ptr > *hi_ptr )
            {
                // strong edges for hysteresis
                *edg_ptr = ( static_cast<float32_t>( *mag_ptr ) > 255.0f ) ? 255 : static_cast<uint8_t>( * mag_ptr );
                end->x = x;
                end->y = y;
                ++end;
            }
            else
            {
            }

            ++mag_ptr;
            ++dir_ptr;
            ++edg_ptr;
            ++lo_ptr;
            ++hi_ptr;
        }

        mag_row += mag_step;
        dir_row += dir_step;
        edg_row += edg_step;
        lo_row += lo_step;
        hi_row += hi_step;
    }

#ifdef DIAGNOSTICS
    diag::stop(); //  Non-Maxima Suppression
#endif
    // --- Hysteresis
#ifdef DIAGNOSTICS
    diag::start( "_CannyEdges: Hysteresis (new)" );
#endif
    Pixel* cur = &queue[0]; /*PRQA S 3706*/
    uint16_t x1;
    uint16_t  x2;
    uint16_t y1_ce;
    uint16_t y2;
    uint16_t m1;
    uint16_t  m2;
    uint16_t lo1;
    uint16_t lo2;
    uint8_t* edg_ptr1;
    uint8_t* edg_ptr2;
    bool_t condition = ( cur != end );

    while( condition )
    {
        uint8_t dir = *o_gradientDir.at( cur->x, cur->y );

        // get pixels along edge
        if( dir == c_0deg )
        {
            x1 = cur->x;
            x2 = cur->x;
            y1_ce = cur->y - 1;
            y2 = cur->y + 1;
        }
        else if( dir == c_45deg )
        {
            x1 = cur->x - 1;
            x2 = cur->x + 1;
            y1_ce = cur->y + 1;
            y2 = cur->y - 1;
        }
        else if( dir == c_90deg )
        {
            x1 = cur->x - 1;
            x2 = cur->x + 1;
            y1_ce = cur->y;
            y2 = cur->y;
        }
        else
        {
            x1 = cur->x - 1;
            x2 = cur->x + 1;
            y1_ce = cur->y - 1;
            y2 = cur->y + 1;
        }

        m1 = *o_gradientMag.at( x1, y1_ce );
        m2 = *o_gradientMag.at( x2, y2 );
        lo1 = *i_thresh_low.at( x1, y1_ce );
        lo2 = *i_thresh_low.at( x2, y2 );
        edg_ptr1 = o_edges.at( x1, y1_ce );
        edg_ptr2 = o_edges.at( x2, y2 );

        // add medium strength edges
        if( ( m1 > lo1 ) && ( *edg_ptr1 == 0 ) )
        {
            *edg_ptr1 = ( static_cast<float32_t>( m1 ) > 255.0f ) ? 255 : static_cast<uint8_t>( m1 );

            if( *edg_ptr1 == 0 )
            {
                *edg_ptr1 = 1;
            }

            end->x = x1;
            end->y = y1_ce;
            ++end;
        }

        if( ( m2 > lo2 ) && ( *edg_ptr2 == 0 ) )
        {
            *edg_ptr2 = ( static_cast<float32_t>( m2 ) > 255.0f ) ? 255 : static_cast<uint8_t>( m2 );

            if( *edg_ptr2 == 0 )
            {
                *edg_ptr2 = 1;
            }

            end->x = x2;
            end->y = y2;
            ++end;
        }

        ++cur;
        condition = ( cur != end );
    }

    memory::MemoryPool::ReleaseImage( heapData );
#ifdef DIAGNOSTICS
    diag::stop(); // Hysteresis
    diag::stop(); // _Canny
#endif
}

/*
* Calculate only the gradient magnitude of an image.
*/
void TAD2::Canny::_CalculateGradientMagnitude( image::Image<uint8_t>& i_image, image::Image<uint16_t>& o_gradientMag )
{
#ifdef DIAGNOSTICS
    diag::start( "_CalculateGradientMagnitude (new)" );
#endif
    const uint32_t img_step = i_image.getStep();
    const uint32_t grad_step = o_gradientMag.getStep();
    uint8_t* img_row = i_image.getData() + img_step + 1;/*PRQA S 3705*/
    uint8_t* img_ptr0;
    uint8_t* img_ptr1;
    uint8_t* img_ptr2;
    uint8_t* img_ptr3;
    uint8_t* img_ptr4;
    uint8_t* img_ptr5;
    uint8_t* img_ptr6;
    uint8_t* img_ptr7;
    uint8_t* img_ptr8;
    uint16_t* grad_row = o_gradientMag.getData() + grad_step + 1;/*PRQA S 3705*/
    uint16_t* grad_ptr;

    for( uint32_t y = 2; y < ( i_image.getHeight() - 2 ); ++y )
    {
        img_ptr0 = img_row - img_step - 1;/*PRQA S 3705*/
        img_ptr1 = img_row - img_step;/*PRQA S 3705*/
        img_ptr2 = img_row - img_step + 1;/*PRQA S 3705*/
        img_ptr3 = img_row - 1;/*PRQA S 3705*/
        img_ptr4 = img_row;
        img_ptr5 = img_row + 1;/*PRQA S 3705*/
        img_ptr6 = img_row + img_step - 1;/*PRQA S 3705*/
        img_ptr7 = img_row + img_step;/*PRQA S 3705*/
        img_ptr8 = img_row + img_step + 1;/*PRQA S 3705*/
        grad_ptr = grad_row;

        for( uint32_t x = 2; x < ( i_image.getWidth() - 2 ); ++x )
        {
            int32_t gx = ( -1 ) * static_cast<int32_t>( *img_ptr0 ) + \
                         1 * static_cast<int32_t>( *img_ptr2 ) + \
                         ( -2 ) * static_cast<int32_t>( *img_ptr3 ) + \
                         2 * static_cast<int32_t>( *img_ptr5 ) + \
                         ( -1 ) * static_cast<int32_t>( *img_ptr6 ) + \
                         1 * static_cast<int32_t>( *img_ptr8 );
            int32_t gy = ( -1 ) * static_cast<int32_t>( *img_ptr0 ) + \
                         ( -2 ) * static_cast<int32_t>( *img_ptr1 ) + \
                         ( -1 ) * static_cast<int32_t>( *img_ptr2 ) + \
                         1 * static_cast<int32_t>( *img_ptr6 ) + \
                         2 * static_cast<int32_t>( *img_ptr7 ) + \
                         1 * static_cast<int32_t>( *img_ptr8 );
            *grad_ptr = static_cast<uint16_t>( sqrt( static_cast<float64_t>( ( gx ) * ( gx ) + ( gy ) * ( gy ) ) ) );
            ++grad_ptr;
            ++img_ptr0;
            ++img_ptr1;
            ++img_ptr2;
            ++img_ptr3;
            ++img_ptr4;
            ++img_ptr5;
            ++img_ptr6;
            ++img_ptr7;
            ++img_ptr8;
        }

        img_row += img_step;
        grad_row += grad_step;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}

/*
* Calculate the gradient of an image with its orientation.
*/
void TAD2::Canny::_CalculateGradientMagnitudeAndDirection( image::Image<uint8_t>& i_image, image::Image<uint16_t>& o_gradientMag, image::Image<uint8_t>& o_gradientDir )
{
#ifdef DIAGNOSTICS
    diag::start( "_CalculateGradientMagnitudeAndDirection (new)" );
#endif
    const uint32_t img_step = i_image.getStep();
    const uint32_t grad_step = o_gradientMag.getStep();
    uint32_t dir_step = o_gradientDir.getStep();
    uint8_t* img_row = i_image.getData() + img_step + 1;/*PRQA S 3705*/
    uint8_t* img_ptr0;
    uint8_t* img_ptr1;
    uint8_t* img_ptr2;
    uint8_t* img_ptr3;
    uint8_t* img_ptr4;
    uint8_t* img_ptr5;
    uint8_t* img_ptr6;
    uint8_t* img_ptr7;
    uint8_t* img_ptr8;
    uint16_t* grad_row = o_gradientMag.getData() + grad_step + 1;/*PRQA S 3705*/
    uint16_t* grad_ptr;
    uint8_t* dir_row = o_gradientDir.getData() + dir_step + 1;/*PRQA S 3705*/
    uint8_t* dir_ptr;
    //
    const uint32_t img_width = i_image.getWidth();
    const uint32_t start = 1;
    const uint32_t end = ( img_width - 2 ) * ( i_image.getHeight() - 2 );
    uint32_t count = 0;
    //
    img_ptr0 = img_row - img_step - 1;/*PRQA S 3705*/
    img_ptr1 = img_row - img_step;/*PRQA S 3705*/
    img_ptr2 = img_row - img_step + 1;/*PRQA S 3705*/
    img_ptr3 = img_row - 1;/*PRQA S 3705*/
    img_ptr4 = img_row;
    img_ptr5 = img_row + 1;/*PRQA S 3705*/
    img_ptr6 = img_row + img_step - 1;/*PRQA S 3705*/
    img_ptr7 = img_row + img_step;/*PRQA S 3705*/
    img_ptr8 = img_row + img_step + 1;/*PRQA S 3705*/
    grad_ptr = grad_row;
    dir_ptr = dir_row;

    for( uint32_t i = start; i < end; ++i )
    {
        if( count < ( img_width - 2 ) )
        {
            int32_t gx = ( -1 ) * static_cast<int32_t>( *img_ptr0 ) + \
                         1 * static_cast<int32_t>( *img_ptr2 ) + \
                         ( -2 ) * static_cast<int32_t>( *img_ptr3 ) + \
                         2 * static_cast<int32_t>( *img_ptr5 ) + \
                         ( -1 ) * static_cast<int32_t>( *img_ptr6 ) + \
                         1 * static_cast<int32_t>( *img_ptr8 );
            int32_t gy = ( -1 ) * static_cast<int32_t>( *img_ptr0 ) + \
                         ( -2 ) * static_cast<int32_t>( *img_ptr1 ) + \
                         ( -1 ) * static_cast<int32_t>( *img_ptr2 ) + \
                         1 * static_cast<int32_t>( *img_ptr6 ) + \
                         2 * static_cast<int32_t>( *img_ptr7 ) + \
                         1 * static_cast<int32_t>( *img_ptr8 );
            *grad_ptr = static_cast<uint16_t>( mecl::math::algebra<float32_t>::sqrt_x( static_cast<float32_t>( ( gx ) * ( gx ) + ( gy ) * ( gy ) ) ) );

            if( gx == 0 )
            {
                *dir_ptr = c_90deg;
            }
            else
            {
                float32_t tangent = static_cast<float32_t>( gy ) / static_cast<float32_t>( gx );

                if( tangent < angles::c_tanN67 )
                {
                    *dir_ptr = c_90deg;
                }
                else if( tangent < angles::c_tanN22 )
                {
                    *dir_ptr = c_135deg;
                }
                else if( tangent < angles::c_tan22 )
                {
                    *dir_ptr = c_0deg;
                }
                else if( tangent < angles::c_tan67 )
                {
                    *dir_ptr = c_45deg;
                }
                else
                {
                    *dir_ptr = c_90deg;
                }
            }

            count++;
            ++img_ptr0;
            ++img_ptr1;
            ++img_ptr2;
            ++img_ptr3;
            ++img_ptr4;
            ++img_ptr5;
            ++img_ptr6;
            ++img_ptr7;
            ++img_ptr8;
            ++grad_ptr;
            ++dir_ptr;
        }
        else
        {
            img_row += img_step;
            grad_row += grad_step;
            dir_row += dir_step;
            count = 0;
            img_ptr0 = img_row - img_step - 1;/*PRQA S 3705*/
            img_ptr1 = img_row - img_step;/*PRQA S 3705*/
            img_ptr2 = img_row - img_step + 1;/*PRQA S 3705*/
            img_ptr3 = img_row - 1;/*PRQA S 3705*/
            img_ptr4 = img_row;
            img_ptr5 = img_row + 1;/*PRQA S 3705*/
            img_ptr6 = img_row + img_step - 1;/*PRQA S 3705*/
            img_ptr7 = img_row + img_step;/*PRQA S 3705*/
            img_ptr8 = img_row + img_step + 1;/*PRQA S 3705*/
            grad_ptr = grad_row;
            dir_ptr = dir_row;
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}

//------------------------------------------------------------------------------
// EdgeTracker function definitions.
//------------------------------------------------------------------------------

edge::EdgeTracker::EdgeTracker( image::Image<uint8_t>& et_image ) :
    m_image( et_image )
{
}

edge::EdgeTracker::~EdgeTracker()
{
}

bool_t edge::EdgeTracker::Init()
{
    bool_t ret_val;
    m_hitBuffer_u32 = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );

    if( m_hitBuffer_u32.getData() == NULL )
    {
        ret_val = false;
    }
    else
    {
        ret_val = true;
    }

    return ret_val;
}

bool_t edge::EdgeTracker::Uninit()
{
    memory::MemoryPool::ReleaseImage( m_hitBuffer_u32 );
    return true;
}

void edge::EdgeTracker::Reset()
{
    processing::ImageProcessing::Clear( m_hitBuffer_u32 );
}

void edge::EdgeTracker::Run( image::Image<uint8_t>& i_edges ) const
{
    UpdateHitBuffer( i_edges );
}

void edge::EdgeTracker::CalculateEdgeHitRate( image::Image<uint8_t>& dst, uint8_t sample ) const
{
#ifdef DIAGNOSTICS
    diag::start( "CalculateEdgeHitRate" );
#endif
    image::Image<uint8_t>::iterator dst_it = dst.begin();
    image::Image<uint16_t>::iterator buf_it = m_hitBuffer_u32.begin();
    image::Image<uint16_t>::iterator buf_end = m_hitBuffer_u32.end();

    while( buf_it != buf_end )// PRQA S 4244
    {
        uint16_t buf = *buf_it;
        uint8_t sum = 0;

        for( uint8_t i = 0; i < sample; i++ )
        {
            if( static_cast<bool>( buf ) && static_cast<bool>( 1 ) )
            {
                ++sum;
            }

            buf >>= 1;
        }

        *dst_it = sum;
        ++dst_it;
        ++buf_it;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}

void edge::EdgeTracker::UpdateHitBuffer( image::Image<uint8_t>& edges ) const
{
#ifdef DIAGNOSTICS
    diag::start( "UpdateHitBuffer" );
#endif
    image::Image<uint8_t>::iterator edg_it = edges.begin();
    image::Image<uint16_t>::iterator buf_it = m_hitBuffer_u32.begin();
    image::Image<uint16_t>::iterator buf_end = m_hitBuffer_u32.end();

    while( buf_it != buf_end )// PRQA S 4244
    {
        *buf_it <<= 1;

        if( *edg_it > 0 )
        {
            *buf_it |= 1;
        }
        else
        {
            *buf_it &= ( ~1 );
        }

        ++edg_it;
        ++buf_it;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}
