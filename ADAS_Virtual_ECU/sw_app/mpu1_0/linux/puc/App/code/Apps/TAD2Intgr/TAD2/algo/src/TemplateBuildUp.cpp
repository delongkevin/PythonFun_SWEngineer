// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "TemplateBuildUp.h"
#include "WarpLUT.h"
#include "common/db.h"

namespace pointtemplate
{
    static Point2i project( Point2i p, int32_t r, float32_t theta_deg )
    {
        float32_t theta_rad = mecl::math::toRadians_x( theta_deg );
        int32_t x = static_cast <int32_t>( static_cast <float32_t>( p.x ) + static_cast <float32_t>( r ) * mecl::math::trigonometry<float32_t>::cos_x( theta_rad ) );
        int32_t y = static_cast <int32_t>( static_cast <float32_t>( p.y ) + static_cast <float32_t>( r ) * mecl::math::trigonometry<float32_t>::sin_x( theta_rad ) );
        return Point2i( x, y );
    }
}
namespace TemplateBuild
{
    /*
    * Constructor.
    */
    TemplateBuildUp::TemplateBuildUp() :
        m_initOK( false ),
        m_isRunning( false ),
        m_lastFrameRun( 0 ),
        m_bHighPotentialHit( false )
    {
    }

    /*
    * Destructor.
    */
    TemplateBuildUp::~TemplateBuildUp()
    {
    }

    /*
    * Initialize this module.
    *
    * Called once at the beginning of the program, before any other functions.
    */
    bool_t TemplateBuildUp::Init( uint32_t i_hitchX, const uint32_t i_hitchYRange[2] )
    {
        c_potential_max = 255;
        c_potential_thresh_low = 20;
        c_potential_thresh_high = 255;
        c_potential_inc = 6;
        c_hitRateSampleSize = 20;
        c_hitRateThreshold = static_cast <uint8_t>( static_cast <float32_t>( c_hitRateSampleSize ) * 0.4f ); // 80
        m_roi = _GetProcessingROI( i_hitchX, i_hitchYRange );
        m_initOK = true;
        return true;
    }

    /*
    * Signifies the beginning of a period of execution. Allocates any necessary
    * memory and sets any input parameters needed at runtime.
    */
    bool_t TemplateBuildUp::Start()
    {
        bool_t ret_val = true;

        if( !m_initOK )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            if( m_isRunning )
            {
                Finish();
            }

            m_potential_u8 = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
            m_hitBuffer_u32 = memory::MemoryPool::GetImage<uint32_t>( itype::IMTP_TopView_U32C1 );
            m_hitRate_u8 = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
            processing::ImageProcessing::Clear( m_potential_u8 );
            processing::ImageProcessing::Clear( m_hitBuffer_u32 );
            processing::ImageProcessing::Clear( m_hitRate_u8 );
            m_bHighPotentialHit = false;

            if( ( m_potential_u8.getData() == NULL ) || ( m_hitBuffer_u32.getData() == NULL ) || ( m_hitRate_u8.getData() == NULL ) )
            {
                ret_val = false;
            }

            if( ret_val )
            {
                m_isRunning = true;
                ret_val = true;
            }
        }

        return ret_val;
    }

    /*
    * Signifies the end of a period of execution. Deallocates any memory used.
    */
    void TemplateBuildUp::Finish()
    {
        memory::MemoryPool::ReleaseImage( m_potential_u8 );
        memory::MemoryPool::ReleaseImage( m_hitBuffer_u32 );
        memory::MemoryPool::ReleaseImage( m_hitRate_u8 );
        m_isRunning = false;
    }

    /*
    * Run this module.
    *
    * Will only run if called between a call to Start() and a call to Finish(), respectively.
    * Records the given frame so as to not run the same frame multiple times.
    */
    void TemplateBuildUp::Run( uint32_t i_frame, image::Image<uint8_t>& i_edges )
    {
        bool_t ret_val = true;

        if( !m_initOK )
        {
            ret_val = false;
        }

        if( ( !m_isRunning ) || ( i_frame == m_lastFrameRun ) )
        {
            ret_val = false;
        }

        if( m_bHighPotentialHit )
        {
            ret_val = false;
        }

        if( ret_val )
        {
#ifdef DIAGNOSTICS
            diag::start( "Template Build Up" );
#endif
            image::Image<float32_t> filteredHitRate_f32 = memory::MemoryPool::GetImage<float32_t>( itype::IMTP_TopView_U32C1 );
            //
            image::Image<uint8_t> edgeROI = i_edges.subImage( m_roi );
            image::Image<uint32_t> hitBufROI = m_hitBuffer_u32.subImage( m_roi );
            image::Image<uint8_t> hitRateROI = m_hitRate_u8.subImage( m_roi );
            image::Image<uint8_t> potentialROI = m_potential_u8.subImage( m_roi );
            image::Image<float32_t> filteredHitRateROI = filteredHitRate_f32.subImage( m_roi );
            //
            _CalculateEdgeHitRate( edgeROI, hitBufROI, hitRateROI );
            _FilterEdgeHitRate( hitRateROI, filteredHitRateROI );
            _BuildPotential_BasedOnFilteredHitRate( filteredHitRateROI, potentialROI );
            //
#ifdef DIAGNOSTICS
            db::imshow( "(TBU-2) Filtered Hit Rate", filteredHitRate_f32, db::ImShow_Grey, ( float32_t )c_hitRateSampleSize );
            db::imshow( "(TBU-2) Potential", m_potential_u8 );
#endif
            memory::MemoryPool::ReleaseImage( filteredHitRate_f32 );
            m_lastFrameRun = i_frame;
#ifdef DIAGNOSTICS
            diag::stop();
#endif
        }
    }

    /*
    * Exosed function to create the template. Must only be called after template
    * has been found.
    */
    void TemplateBuildUp::CreateInitialTemplate( image::Image<uint8_t>& o_template )
    {
        processing::ImageProcessing::Clear( o_template );
        _CreateMask( m_potential_u8, o_template, c_potential_thresh_low, 0 );
#ifdef DIAGNOSTICS
        db::imshow( "(TBU-1) Calibrated Template", o_template );
#endif
    }

    /*
    * Return whether or not the build up is complete and the template is ready to be created.
    */
    bool_t TemplateBuildUp::IsTemplateFound() const
    {
        return m_bHighPotentialHit;
    }

    /*
    * Update the hit rate of each pixel where the value in each position of the result image
    * is the number of times that pixel has been an edge in the last 'c_hitRateSampleSize'
    * frames.
    *
    * Must be called every frame for accuracy.
    */
    void TemplateBuildUp::_CalculateEdgeHitRate( image::Image<uint8_t>& i_edges, image::Image<uint32_t> io_hitBuffer, image::Image<uint8_t> io_hitRate ) const
    {
        image::Image<uint8_t>::iterator edg_end = i_edges.end();
        image::Image<uint32_t>::iterator buf_it = io_hitBuffer.begin();
        image::Image<uint8_t>::iterator rt_it = io_hitRate.begin();
        uint32_t last_bit_mask = ( 1 << ( static_cast<uint32_t>( c_hitRateSampleSize ) - 1 ) );

        for( image::Image<uint8_t>::iterator edg_it = i_edges.begin(); edg_it != edg_end; ++edg_it ) // PRQA S 4244
        {
            if( static_cast<bool_t>( *buf_it & last_bit_mask ) )
            {
                ( *rt_it )--;
            }

            *buf_it <<= 1;

            if( *edg_it > 0 )
            {
                *buf_it |= 1;
                ( *rt_it )++;
            }
            else
            {
                *buf_it &= ( ~1 );
            }

            ++buf_it;
            ++rt_it;
        }
    }

    /*
    * Apply filter to hit rate image.
    */
    void TemplateBuildUp::_FilterEdgeHitRate( image::Image<uint8_t> i_hitRate, image::Image<float32_t> o_filteredHitRate )
    {
#ifdef DIAGNOSTICS
        diag::start( "TBU: _FilterEdgeHitRate" );
#endif
        float32_t* dst_row = o_filteredHitRate.getData();
        uint8_t* src_row = i_hitRate.getData();
        int32_t dst_step = o_filteredHitRate.getStep();
        int32_t src_step = i_hitRate.getStep();
        //
        dst_row += dst_step + 1;
        src_row += src_step + 1;
        float32_t* dst_ptr;
        uint8_t* src_ptr0;
        uint8_t* src_ptr1;
        uint8_t* src_ptr2;
        uint8_t* src_ptr3;
        uint8_t* src_ptr4;
        uint8_t* src_ptr5;
        uint8_t* src_ptr6;
        uint8_t* src_ptr7;
        uint8_t* src_ptr8;
        //
        uint32_t sum;
        uint32_t kernel_sum = 13;
        uint32_t h = i_hitRate.getHeight();
        uint32_t w = i_hitRate.getWidth();

        for( uint32_t y = 1; y < ( h - 1 ); ++y )
        {
            dst_ptr = dst_row;
            src_ptr0 = src_row - src_step - 1;  /*PRQA S 3705*/
            src_ptr1 = src_row - src_step;      /*PRQA S 3705*/
            src_ptr2 = src_row - src_step + 1;  /*PRQA S 3705*/
            src_ptr3 = src_row - 1;             /*PRQA S 3705*/
            src_ptr4 = src_row;
            src_ptr5 = src_row + 1;             /*PRQA S 3705*/
            src_ptr6 = src_row + src_step - 1;  /*PRQA S 3705*/
            src_ptr7 = src_row + src_step;      /*PRQA S 3705*/
            src_ptr8 = src_row + src_step + 1;  /*PRQA S 3705*/

            for( uint32_t x = 1; x < ( w - 1 ); ++x )
            {
                sum = ( *src_ptr0 ) + \
                      ( *src_ptr1 ) + \
                      ( *src_ptr2 ) + \
                      ( *src_ptr3 ) + \
                      5 * ( *src_ptr4 ) + \
                      ( *src_ptr5 ) + \
                      ( *src_ptr6 ) + \
                      ( *src_ptr7 ) + \
                      ( *src_ptr8 );
                *dst_ptr = static_cast <float32_t>( sum ) / static_cast <float32_t>( kernel_sum );
                ++dst_ptr;
                ++src_ptr0;
                ++src_ptr1;
                ++src_ptr2;
                ++src_ptr3;
                ++src_ptr4;
                ++src_ptr5;
                ++src_ptr6;
                ++src_ptr7;
                ++src_ptr8;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }

    /*
    * Build up the potential image using a filtered hit rate image.
    */
    void TemplateBuildUp::_BuildPotential_BasedOnFilteredHitRate( image::Image<float32_t> i_filteredHitRate, image::Image<uint8_t> io_potential )
    {
#ifdef DIAGNOSTICS
        diag::start( "BuildPotential_BasedOnFilteredHitRate" );
#endif
        image::Image<uint8_t>::iterator pot_end = io_potential.end();
        image::Image<float32_t>::iterator fhr_it = i_filteredHitRate.begin();
        uint32_t count = 0;

        for( image::Image<uint8_t>::iterator pot_it = io_potential.begin(); pot_it != pot_end; ++pot_it ) // PRQA S 4244
        {
            if( *fhr_it >= static_cast<float32_t>( c_hitRateThreshold ) )
            {
                count++;

                if( *pot_it < ( c_potential_max - c_potential_inc ) )
                {
                    ( *pot_it ) += c_potential_inc;
                }
                else
                {
                    ( *pot_it ) = c_potential_max;
                }

                if( *pot_it >= c_potential_thresh_high )
                {
                    m_bHighPotentialHit = true;
                }
            }

            ++fhr_it;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }

    /*
    * Build up the potential image using a non-filtered hit rate image.
    */
    void TemplateBuildUp::_BuildPotential_BasedOnRawHitRate( image::Image<uint8_t> i_hitRate, image::Image<uint8_t> io_potential )
    {
#ifdef DIAGNOSTICS
        diag::start( "BuildPotential_BasedOnRawHitRate" );
#endif
        image::Image<uint8_t>::iterator pot_end = io_potential.end();
        image::Image<uint8_t>::iterator fhr_it = i_hitRate.begin();
        uint32_t count = 0;

        for( image::Image<uint8_t>::iterator pot_it = io_potential.begin(); pot_it != pot_end; ++pot_it ) // PRQA S 4244
        {
            if( *fhr_it >= c_hitRateThreshold )
            {
                count++;

                if( *pot_it < ( c_potential_max - c_potential_inc ) )
                {
                    ( *pot_it ) += c_potential_inc;
                }
                else
                {
                    ( *pot_it ) = c_potential_max;
                }

                if( *pot_it >= c_potential_thresh_high )
                {
                    m_bHighPotentialHit = true;
                }
            }

            ++fhr_it;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }

    /*
    * Threshold the potential image and create a mask where each edge has a thickness of 'i_radius'.
    */
    void TemplateBuildUp::_CreateMask( image::Image<uint8_t>& i_potential, image::Image<uint8_t>& o_mask, uint8_t i_thresh, uint8_t i_radius )
    {
#ifdef DIAGNOSTICS
        diag::start( "CreateMask" );
#endif
        image::Image<uint8_t>::col_iterator msk_col = o_mask.col( 0 );
        image::Image<uint8_t>::row_iterator msk_row = o_mask.row( 0 );
        image::Image<uint8_t>::iterator pot_it = i_potential.begin();
        uint32_t height = o_mask.getHeight();
        uint32_t width = o_mask.getWidth();

        for( msk_row = 0; msk_row < height; ++msk_row ) // PRQA S 4244
        {
            for( msk_col = 0; msk_col < width; ++msk_col )
            {
                if( *pot_it > i_thresh )
                {
                    sint32_t i_Radius = static_cast<sint32_t>( i_radius );

                    for( sint32_t i = -i_Radius; i <= static_cast<sint32_t>( i_radius ); i++ )
                    {
                        for( sint32_t j = -i_Radius; j <= static_cast<sint32_t>( i_radius ); j++ )
                        {
                            if( static_cast <uint8_t>( sqrt( static_cast <float64_t>( ( i ) * ( i ) + ( j ) * ( j ) ) ) ) <= i_radius )
                            {
                                if( ( 0 <= ( *msk_col + j ) ) && ( ( *msk_col + j ) < static_cast <int32_t>( o_mask.getWidth() ) ) && ( 0 <= ( *msk_row + i ) ) && ( ( *msk_row + i ) < static_cast <int32_t>( o_mask.getHeight() ) ) )
                                {
                                    *o_mask.at( msk_row + j, msk_col + i ) = 255;
                                }
                            }
                        }
                    }
                }

                ++pot_it;
            }
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }

    /*
    * Calculate the necessary region where all processing will be done.
    */
    _roi::ROI TemplateBuildUp::_GetProcessingROI( uint32_t i_hitchX, const uint32_t i_hitchYRange[2] )
    {
        // --- Get the hitch and angle range
        Point2i hitch_range[2] = { Point2i( i_hitchX, i_hitchYRange[0] ), Point2i( i_hitchX, i_hitchYRange[1] ) }; /*PRQA S 3706*/
        //
        // --- Get the boundaries of the roi
        int32_t margin = 3;
        int32_t template_radius = global::TEMPLATE_IMAGE_HEIGHT + TAD2::getWarpedTopViewParams().yOffset;
        float32_t templateRange_deg = static_cast<float32_t>( global::TEMPLATE_IMAGE_WIDTH ) * TAD2::getWarpedTopViewParams().degreesPerPixel;
        Point2i p1 = pointtemplate::project( hitch_range[0], template_radius, 90.0f - templateRange_deg / 2.0f );
        Point2i p2 = pointtemplate::project( hitch_range[0], template_radius, 90.0f + templateRange_deg / 2.0f );
        //
        int32_t top = hitch_range[0].y - margin;
        int32_t bottom = hitch_range[1].y + template_radius + margin;
        int32_t left = p2.x - margin;
        int32_t right = p1.x + margin;
        //
        int32_t w = global::TOPVIEW_IMAGE_WIDTH;
        int32_t h = global::TOPVIEW_IMAGE_HEIGHT;
        top = mecl::math::max_x( 0, top );
        bottom = mecl::math::min_x( h, bottom );
        left = mecl::math::max_x( 0, left );
        right = mecl::math::min_x( w, right );
        return _roi::ROI( left, top, right - left, bottom - top );
    }
}
