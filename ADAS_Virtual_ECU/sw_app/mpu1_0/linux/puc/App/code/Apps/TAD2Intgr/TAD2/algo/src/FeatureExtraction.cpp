// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [05-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "FeatureExtraction.h"
#include "EdgeDetector.h"


#ifdef DIAGNOSTICS
    #include "global.h"
    #include "db.h"
    #include "fo.h"
#endif

namespace TAD2
{
    /*
    * Constructor.
    */
    FeatureExtraction::FeatureExtraction() :
        m_initOK( false ),
        m_isRunning( false ),
        m_lastFrameRun( 0 )
    {
    }

    /*
    * Destructor.
    */
    FeatureExtraction::~FeatureExtraction()
    {
    }

    /*
    * Initialize this module.
    *
    * Called once at the beginning of the program, before any other functions.
    */
    bool_t FeatureExtraction::Init()
    {
        m_initOK = true;
        m_features = image::Image<Feature>( global::TOPVIEW_IMAGE_WIDTH, global::TOPVIEW_IMAGE_HEIGHT, NULL, 1 );
        return true;
    }

    /*
    * Signifies the beginning of a period of execution. Allocates any necessary
    * memory and sets any input parameters needed at runtime.
    */
    bool_t FeatureExtraction::Start()
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

            m_edges = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
            m_isRunning = true;
            ret_val = true;
        }

        return ret_val;
    }

    /*
    * Signifies the end of a period of execution. Deallocates any memory used.
    */
    void FeatureExtraction::Finish()
    {
        memory::MemoryPool::ReleaseImage( m_edges );
        m_isRunning = false;
    }

    /*
    * Run this module.
    *
    * Will only run if called between a call to Start() and a call to Finish(), respectively.
    * Records the given frame so as to not run the same frame multiple times.
    */
    void FeatureExtraction::Run( int32_t i_frame, image::Image<uint8_t>& i_topView, image::Image<uint16_t> i_lowThresh, image::Image<uint16_t> i_highThresh, _roi::ROI& i_roi, image::Image<uint16_t>& o_gradMag, image::Image<uint8_t>& o_gradDir )
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

        if( ret_val )
        {
            // --- Run Canny
            image::Image<uint8_t> topViewROI = i_topView.subImage( i_roi );
            image::Image<uint16_t> lowThreshROI = i_lowThresh.subImage( i_roi );
            image::Image<uint16_t> highThreshROI = i_highThresh.subImage( i_roi );
            image::Image<uint8_t> edgeROI = m_edges.subImage( i_roi );
            image::Image<uint8_t> edgeDirROI = o_gradDir.subImage( i_roi );
            image::Image<uint16_t> gradMagROI = o_gradMag.subImage( i_roi );
            //
            processing::ImageProcessing::Clear( m_edges );
            TAD2::Canny( topViewROI, lowThreshROI, highThreshROI, edgeROI, gradMagROI, edgeDirROI );
            //
#ifdef DIAGNOSTICS
            // --- Debugging
            db::imshow( "(FE-1) Canny Edges", m_edges, db::ImShow_Binary );
            db::imshow( "(FE-2) Edge Gradient", o_gradMag, db::ImShow_Grey2Colour );
            db::imshow_segmented( "(FE-3) Edge Gradient - Segmented", o_gradMag, i_lowThresh, i_highThresh );

            if( 0 )
            {
                char filename[260] = { '\0' };
                sprintf( filename, "TAD2/Edges/%d.png", i_frame );
                fo::outputImage( filename, m_edges );
            }

#endif
            m_lastFrameRun = i_frame;
        }

        return;
    }

    /*
    * Get edge image.
    */
    image::Image<uint8_t>& FeatureExtraction::GetEdges()
    {
        return m_edges;
    }


    /*
    * Get feature image. Not currently used.
    */
    image::Image<FeatureExtraction::Feature>& FeatureExtraction::GetFeatureImage()
    {
        return m_features;
    }

    /*
    * Get feature image. Not currently used.
    */
    void FeatureExtraction::setlastframe( uint32_t frame_no )
    {
        m_lastFrameRun = frame_no;
    }

    /*
    * Extract all features from an image, including gradient magnitude and edge direction.
    *
    * Only used for experimentation, and is not practical otherwise.
    */
    void FeatureExtraction::ExtractAllFeatures( image::Image<uint8_t>& i_topView, image::Image<uint8_t>& i_edges )const
    {
#ifdef DIAGNOSTICS
        diag::start( "FE: ExtractAllFeatures" );
#endif
        const uint32_t img_step = i_topView.getStep();
        const uint32_t edg_step = i_edges.getStep();
        const uint32_t ftr_step = m_features.getStep();
        uint8_t* img_row = i_topView.getData() + img_step + 1;  //PRQA S 3705
        uint8_t* edg_row = i_edges.getData() + edg_step + 1;    //PRQA S 3705
        uint8_t* img_ptr0;
        uint8_t* img_ptr1;
        uint8_t* img_ptr2;
        uint8_t* img_ptr3;
        uint8_t* img_ptr4;
        uint8_t* img_ptr5;
        uint8_t* img_ptr6;
        uint8_t* img_ptr7;
        uint8_t* img_ptr8;
        uint8_t* edg_ptr;
        Feature* ftr_row = m_features.getData() + ftr_step + 1; //PRQA S 3705
        Feature* ftr_ptr;

        for( uint32_t y = 1; y < ( i_topView.getHeight() - 1 ); ++y )
        {
            img_ptr0 = img_row - img_step - 1;  //PRQA S 3705
            img_ptr1 = img_row - img_step;      //PRQA S 3705
            img_ptr2 = img_row - img_step + 1;  //PRQA S 3705
            img_ptr3 = img_row - 1;             //PRQA S 3705
            img_ptr4 = img_row;
            img_ptr5 = img_row + 1;             //PRQA S 3705
            img_ptr6 = img_row + img_step - 1;  //PRQA S 3705
            img_ptr7 = img_row + img_step;      //PRQA S 3705
            img_ptr8 = img_row + img_step + 1;  //PRQA S 3705
            edg_ptr = edg_row;
            ftr_ptr = ftr_row;

            for( uint32_t x = 1; x < ( i_topView.getWidth() - 1 ); ++x )
            {
                int32_t gx = ( -1 ) * static_cast <int32_t>( *img_ptr0 ) + \
                             1 * static_cast <int32_t>( *img_ptr2 ) + \
                             ( -2 ) * static_cast <int32_t>( *img_ptr3 ) + \
                             2 * static_cast <int32_t>( *img_ptr5 ) + \
                             ( -1 ) * static_cast <int32_t>( *img_ptr6 ) + \
                             1 * static_cast <int32_t>( *img_ptr8 );
                int32_t gy = ( -1 ) * static_cast <int32_t>( *img_ptr0 ) + \
                             ( -2 ) * static_cast <int32_t>( *img_ptr1 ) + \
                             ( -1 ) * static_cast <int32_t>( *img_ptr2 ) + \
                             1 * static_cast <int32_t>( *img_ptr6 ) + \
                             2 * static_cast <int32_t>( *img_ptr7 ) + \
                             1 * static_cast <int32_t>( *img_ptr8 );
                ftr_ptr->edgeStrength = static_cast <uint16_t>( sqrt( static_cast <float32_t>( ( gx ) * ( gx ) + ( gy ) * ( gy ) ) ) );

                if( gy < 0 )
                {
                    gy = -gy;
                    gx = -gx;
                }

                ftr_ptr->edgeDirection = static_cast <uint8_t>( mecl::math::toDegrees_x( atan2( static_cast <float32_t>( gy ), static_cast <float32_t>( gx ) ) ) );
                ftr_ptr->rawPixelValue = *img_ptr4;
                ftr_ptr->isEdge = ( *edg_ptr > 0 );
                ++img_ptr0;
                ++img_ptr1;
                ++img_ptr2;
                ++img_ptr3;
                ++img_ptr4;
                ++img_ptr5;
                ++img_ptr6;
                ++img_ptr7;
                ++img_ptr8;
                ++edg_ptr;
                ++ftr_ptr;
            }

            img_row += img_step;
            edg_row += edg_step;
            ftr_row += ftr_step;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
}
