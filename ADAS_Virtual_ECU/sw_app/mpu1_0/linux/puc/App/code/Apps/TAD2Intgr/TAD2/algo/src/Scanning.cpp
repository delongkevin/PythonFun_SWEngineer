// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "Scanning.h"
#include "Image.h"
#ifdef DIAGNOSTICS
    #include "global.h"
    #include "common/db.h"
    #include "fo.h"
#endif
//#include "../../TAD2Defines.h"

namespace Scan
{
    /*
    * Constructor.
    */
    Scanning::Scanning() : TemplateMatching(),
        m_initOK( false ),
        m_isRunning( false ),
        m_lastFrameRun( 0 ),
        m_scanningComplete( false )

    {
    }

    /*
    * Destructor.
    */
    Scanning::~Scanning()
    {
    }

    /*
    * Initialize this module.
    *
    * Called once at the beginning of the program, before any other functions.
    */
    bool_t Scanning::Init( const TAD2::WarpedTopViewParameters& i_warpedTopviewParams, TAD2::PreProcessing* i_pPreProcessing )
    {
        m_warpedTopviewParams = i_warpedTopviewParams;
        m_pPreProcessing = i_pPreProcessing;
        //
        m_initOK = true;
        return true;
    }

    /*
    * Signifies the beginning of a period of execution. Allocates any necessary
    * memory and sets any input parameters needed at runtime.
    */
    bool_t Scanning::Start( TAD2::TrailerTemplate i_trailerTemplate )
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

            m_trailerTemplate = i_trailerTemplate;
            ScanInd = 1;
            ImageROI.setX( 3 );
            ImageROI.setY( 5 );
            ImageROI.setHeight( global::TEMPLATE_IMAGE_HEIGHT - ( ImageROI.getX() * 2 ) );
            ImageROI.setWidth( global::TEMPLATE_IMAGE_WIDTH - ( ImageROI.getY() * 2 ) );
            TemplateCount = 0.0f;
            //TemplateCount = CountPixel( m_trailerTemplate );
            m_DilatedtrailerTemplate = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
            LabelImage = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
            islabeledImage = memory::MemoryPool::GetImage<bool_t>( itype::IMTP_Template_U8C1 );
            /*cv::Mat im = processing::ImageProcessing::ConvertToCV( m_trailerTemplate );
            cv::Mat im1 = processing::ImageProcessing::ConvertToCV( LabelImage );
            cv::Mat im2 = processing::ImageProcessing::ConvertToCV( islabeledImage );*/
#if 0 // Pravin
            FILE* fp;
            static int32_t first = 1;

            if( 1 == first )
            {
                fp = fopen( "/ti_sd/m_trailerTemplate.bin", "wb" );
                fwrite( ( void* )m_trailerTemplate.getData(), 1, 203 * 150, fp );
                fclose( fp );
                first = 0;
            }

#endif
            LabelComponent( &m_trailerTemplate, &LabelImage, ImageROI, &islabeledImage, true );
            _ROI3x3( m_trailerTemplate, m_DilatedtrailerTemplate, TemplateCount );
            //_ROI3x3_UP( m_trailerTemplate, m_DilatedtrailerTemplate );
            //cv::Mat im2 = processing::ImageProcessing::ConvertToCV( m_DilatedtrailerTemplate );
            memset( reinterpret_cast<uint8_t*>( m_scores ), 0, c_numFullScans * global::WARPED_TOPVIEW_IMAGE_WIDTH * sizeof( float32_t ) );
            m_curScan = 0;
            m_curOffset = 0;
            m_scanningComplete = false;
            m_trailerAngleFound = false;
            m_initial_pos_found = false;
            m_bestTrailerAngle = 0.0f;
            c_scanInc = 1;
            initial_start_Pos = 240;
            final_end_Pos = m_warpedTopviewParams.width - 240;
            m_scanningScore = 0.0f;
#ifdef DIAGNOSTICS
            db::clearPlot( "(SCN-2) Scores" );
#endif

            if( ( m_trailerTemplate.getWidth() * m_trailerTemplate.getHeight() ) > global::TEMPLATE_IMAGE_SIZE )
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
    void Scanning::Finish()
    {
        m_initial_pos_found = false;
        m_isRunning = false;
        TemplateCount = 0.0f;
        memory::MemoryPool::ReleaseImage( m_DilatedtrailerTemplate );
        memory::MemoryPool::ReleaseImage( LabelImage );
        memory::MemoryPool::ReleaseImage( islabeledImage );
    }

    /*
    * Run this module.
    *
    * Will only run if called between a call to Start() and a call to Finish(), respectively.
    * Records the given frame so as to not run the same frame multiple times.
    */
    void Scanning::Run( uint32_t i_frame, TAD2::WarpedImage<uint8_t>& i_warpedTopview, uint16_t othsu_thresh, float32_t i_averageIllumination )
    {
#if DUMP_TRAILER_TEMPLATE
        FILE* fp, *fp1;
        static bool_t fileDumped = false;

        if( false == fileDumped )
        {
            fp = fopen( "/ti_sd/i_warpedTopview.csv", "a+" );
            fp1 = fopen( "/ti_sd/i_warpedTopview.bin", "a+" );
            fwrite( ( void* )i_warpedTopview.getData(), 1, 203 * 150, fp1 );

            for( uint32_t y = 0; y < i_warpedTopview.getHeight(); y++ )
            {
                for( uint32_t x = 0; x < i_warpedTopview.getWidth(); x++ )
                {
                    int val = *i_warpedTopview.at( x, y );
                    fprintf( fp, "%d,", val );
                }

                fprintf( fp, "\n" );
            }

            fclose( fp );
            fileDumped = true;
        }

#endif
        bool_t ret_val = true;

        if( !m_initOK )
        {
            ret_val = false;
        }

        if( ( !m_isRunning ) || ( i_frame == m_lastFrameRun ) )
        {
            ret_val = false;
        }

        if( m_scanningComplete )
        {
            ret_val = false;
        }

        if( ret_val )
        {
#ifdef DIAGNOSTICS
            diag::start( "Scanning" );
#endif
            uint8_t data[global::TEMPLATE_IMAGE_SIZE];
            image::Image<uint8_t> t = image::Image<uint8_t>( m_trailerTemplate.getWidth(), m_trailerTemplate.getHeight(), &data[0], 1, m_trailerTemplate.getWidth() );
            //cv::Mat im8 = processing::ImageProcessing::ConvertToCV( i_warpedTopview );
            float32_t otsu_offset = ( i_averageIllumination / 255.0f ) * 10.0f;

            // --- Perform scan with offset
            for( uint32_t x = initial_start_Pos; x < final_end_Pos; x += c_scanInc )
            {
                //cv::Mat im6 = processing::ImageProcessing::ConvertToCV( m_trailerTemplate );
                //cv::Mat im = processing::ImageProcessing::ConvertToCV( t );
                //cv::Mat im1 = processing::ImageProcessing::ConvertToCV( i_warpedTopview );
                //cv::Mat im2 = processing::ImageProcessing::ConvertToCV( m_DilatedtrailerTemplate );
                float32_t score;
                float32_t zero_score = 0.0f;
                float32_t zeroEdgeCount = 0.0f;

                if( !m_initial_pos_found )
                {
                    score = TemplateMatching::GaussianSimilarityWeighted3x3_7( m_DilatedtrailerTemplate, i_warpedTopview, x - static_cast<int32_t>( m_trailerTemplate.getWidth() ) / 2, 0, 0 );
                }
                else
                {
                    ExtractTemplate( i_warpedTopview, t, x - static_cast <int32_t>( m_trailerTemplate.getWidth() ) / 2, 0 );
                    ROILabelComponent( &m_DilatedtrailerTemplate, &t, &LabelImage, ImageROI, &islabeledImage, false, zeroEdgeCount, TemplateCount, othsu_thresh * otsu_offset );
                    ExtractTemplateDotProduct( m_DilatedtrailerTemplate, t, zero_score, ImageROI );
                    score = TemplateMatching::Similarity4( m_trailerTemplate, t, m_DilatedtrailerTemplate, TemplateCount, 0.0f, zero_score, zeroEdgeCount, ImageROI );
                }

                //
                m_scores[m_curScan][x] = score;
            }

            if( !m_initial_pos_found )
            {
                find_initial_trailer_pos();
                m_initial_pos_found = true;
            }

            m_curScan++;

            if( m_curScan == 1 )
            {
                //cv::Mat im6 = processing::ImageProcessing::ConvertToCV( m_DilatedtrailerTemplate );
                //_ROI3x3( m_trailerTemplate, m_DilatedtrailerTemplate );
                _ROI3x3( m_trailerTemplate, m_DilatedtrailerTemplate, TemplateCount );
            }

            if( m_curScan == 2 )
            {
                //cv::Mat im6 = processing::ImageProcessing::ConvertToCV( m_DilatedtrailerTemplate );
                //_ROI3x3( m_trailerTemplate, m_DilatedtrailerTemplate );
                _ROI3x3_3UP( m_trailerTemplate, m_DilatedtrailerTemplate, TemplateCount );
            }

            if( m_curScan == 3 )
            {
                //cv::Mat im6 = processing::ImageProcessing::ConvertToCV( m_DilatedtrailerTemplate );
                //_ROI3x3( m_trailerTemplate, m_DilatedtrailerTemplate );
                _ROI3x3_5UP( m_trailerTemplate, m_DilatedtrailerTemplate, TemplateCount );
            }

            if( m_curScan == 4 )
            {
                //cv::Mat im6 = processing::ImageProcessing::ConvertToCV( m_DilatedtrailerTemplate );
                //_ROI3x3( m_trailerTemplate, m_DilatedtrailerTemplate );
                _ROI3x3_7UP( m_trailerTemplate, m_DilatedtrailerTemplate, TemplateCount );
            }

            if( m_curScan == 5 )
            {
                //cv::Mat im6 = processing::ImageProcessing::ConvertToCV( m_DilatedtrailerTemplate );
                //_ROI3x3( m_trailerTemplate, m_DilatedtrailerTemplate );
                _ROI3x3_9UP( m_trailerTemplate, m_DilatedtrailerTemplate, TemplateCount );
            }

            if( m_curScan == c_numFullScans )
            {
                _CalculateTrailerAngle();
#ifdef DIAGNOSTICS

                // --- Debugging
                if( 1 )
                {
                    uint32_t bestX = TAD2::WarpedImage<uint8_t>( m_warpedTopviewParams ).Angle2XPos( m_bestTrailerAngle );
                    ExtractTemplate( i_warpedTopview, t, bestX - ( int32_t )m_trailerTemplate.getWidth() / 2, 0 );
                    /*cv::Mat im6 = processing::ImageProcessing::ConvertToCV( m_trailerTemplate );
                    cv::Mat im3 = processing::ImageProcessing::ConvertToCV( t );
                    cv::Mat im5 = processing::ImageProcessing::ConvertToCV( m_DilatedtrailerTemplate );*/

                    if( ScanInd == 1 )
                    {
                        _ROI3x3( m_trailerTemplate, m_DilatedtrailerTemplate, TemplateCount );
                    }
                    else if( ScanInd == 2 )
                    {
                        _ROI3x3_3UP( m_trailerTemplate, m_DilatedtrailerTemplate, TemplateCount );
                    }
                    else if( ScanInd == 3 )
                    {
                        _ROI3x3_5UP( m_trailerTemplate, m_DilatedtrailerTemplate, TemplateCount );
                    }
                    else if( ScanInd == 4 )
                    {
                        _ROI3x3_7UP( m_trailerTemplate, m_DilatedtrailerTemplate, TemplateCount );
                    }
                    else if( ScanInd == 5 )
                    {
                        _ROI3x3_9UP( m_trailerTemplate, m_DilatedtrailerTemplate, TemplateCount );
                    }

                    float32_t zero_score = 0.0f;
                    float32_t zeroEdgeCount = 0.0f;
                    ROILabelComponent( &m_DilatedtrailerTemplate, &t, &LabelImage, ImageROI, &islabeledImage, false, zeroEdgeCount, TemplateCount, othsu_thresh * otsu_offset );
                    ExtractTemplateDotProduct( m_DilatedtrailerTemplate, t, zero_score, ImageROI );
                    //cv::Mat im2 = processing::ImageProcessing::ConvertToCV( LabelImage );
                    float32_t score = TemplateMatching::Similarity4( m_trailerTemplate, t, m_DilatedtrailerTemplate, TemplateCount, 0.0f, zero_score, zeroEdgeCount, ImageROI );
#ifdef DIAGNOSTICS
                    db::imshow_templateOverlap( "(SCN-2) Final Matching Template", m_trailerTemplate, t, 1.0f );
#endif
                }

#endif
            }

            m_lastFrameRun = i_frame;
#ifdef DIAGNOSTICS
            diag::stop();
#endif
        }

        return;
    }
    uint8_t Scanning::ROILabelComponent( image::Image<uint8_t>* dilatedImage, image::Image<uint8_t>* strInputImage, image::Image<uint8_t>*  strLabelImage, const _roi::ROI r1, image::Image<bool_t>* is_labeled, bool_t templateprocess, float32_t& zeroEdgecount, float32_t TemplateEdgeCount, uint16_t othsu_thresh )
    {
        memset( strLabelImage->getData(), 0, sizeof( uint8_t )* strInputImage->getHeight() * strInputImage->getWidth() );
        memset( is_labeled->getData(), false, sizeof( bool )* strInputImage->getHeight() * strInputImage->getWidth() );
        uint8_t label_u8 = 0;
        //cv::Mat im1 = processing::ImageProcessing::ConvertToCV( *strLabelImage );
        //cv::Mat im = processing::ImageProcessing::ConvertToCV( *strInputImage );
        float32_t total_edges = 0.0f;
        float32_t total_pixel = 0.0f;
        float32_t Template_edges = 0.0f;
        float32_t thresh = 0.0f;
        uint32_t Image_Width = strInputImage->getWidth();

        //for all pixels in the roi
        for( uint16_t i = r1.getY(); i < r1.getHeight(); i++ )
        {
            for( uint16_t j = r1.getX(); j < r1.getWidth(); j++ )
            {
                total_pixel++;

                //if it is black, set as checked
                if( *( strInputImage->getData() + i * Image_Width + j ) == 0 )
                {
                    *( is_labeled->getData() + i * Image_Width + j ) = true;
                }
                //if it is white, set to unchecked
                else
                {
                    total_edges++;
                    *( is_labeled->getData() + i * Image_Width + j ) = false;
                }
            }
        }

        float32_t TemplateThresh = TemplateEdgeCount / 1000.0f;

        if( templateprocess )
        {
            thresh = ( ( total_edges / total_pixel ) * 100.0f );
        }
        else
        {
            thresh = ( ( total_edges / total_pixel ) * 100.0f ) * ( 1.5f + TemplateThresh );
        }

        //float32_t Template_thresh = ( ( Template_edges / total_pixel ) * 100.0f ) * 4.0f;
        uint16_t pixelCount_u16 = 0;
        Point2i loc, temp, startPoint;
        detectedEllipseBoundary_s v_queuePoints;
        v_queuePoints.col_size = 0;
        float32_t blobArea_u16 = 0;
        uint32_t max_height = strInputImage->getHeight() - ( r1.getY() * 2 );

        for( uint16_t i = r1.getY(); i < r1.getHeight(); i++ )
        {
            for( uint16_t j = r1.getX(); j < r1.getWidth(); j++ )
            {
                float32_t ROIEdges = 0.0f;

                //check if pixel is unchecked
                if( *( is_labeled->getData() + i * Image_Width + j ) == false && *( strInputImage->getData() + i * Image_Width + j ) > 0U )
                {
                    loc.x = i;
                    loc.y = j;
                    //add current pixel in queue
                    v_queuePoints.col[v_queuePoints.col_size] = loc;
                    v_queuePoints.flag[v_queuePoints.col_size] = true;
                    v_queuePoints.col_size++;
                    pixelCount_u16++;
                    //set this pixel as checked
                    *( is_labeled->getData() + i * Image_Width + j ) = true;
                    //increase the label
                    label_u8++;
                    //set current pixel to current label
                    *( strLabelImage->getData() + i * Image_Width + j ) = ( uint8_t )label_u8;
                    blobArea_u16++;
                    startPoint = loc;

                    if( *( dilatedImage->getData() + i * Image_Width + j ) > 0 )
                    {
                        ROIEdges++;
                    }
                }
                else
                    //skip all
                {
                    continue;
                }

                while( pixelCount_u16 )
                {
                    if( ( v_queuePoints.col_size < 1 ) || ( v_queuePoints.col_size > 1950 ) )
                    {
                        break;
                    }

                    loc = v_queuePoints.col[v_queuePoints.front()];
                    pixelCount_u16--;

                    //search right
                    if( ( loc.y + 1 ) < static_cast<int32_t>( Image_Width - 1U ) )
                    {
                        if( *( strInputImage->getData() + loc.x * Image_Width + ( loc.y + 1 ) ) > 2
                            && *( is_labeled->getData() + loc.x * Image_Width + ( loc.y + 1 ) ) == false )
                        {
                            *( is_labeled->getData() + loc.x * Image_Width + ( loc.y + 1 ) ) = true;
                            temp.x = loc.x;
                            temp.y = loc.y + 1;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;

                            if( *( dilatedImage->getData() + temp.x * Image_Width + temp.y ) > 0 )
                            {
                                ROIEdges++;
                            }
                        }
                    }

                    //right-down corner
                    if( ( ( loc.y + 1 ) < static_cast<int32_t>( Image_Width - 1U ) ) && ( ( loc.x + 1 ) < static_cast<int32_t>(max_height) ) )
                    {
                        if( *( strInputImage->getData() + ( loc.x + 1 ) * Image_Width + ( loc.y + 1 ) ) > 2
                            && *( is_labeled->getData() + ( loc.x + 1 ) * Image_Width + ( loc.y + 1 ) ) == false )
                        {
                            *( is_labeled->getData() + ( loc.x + 1 ) * Image_Width + ( loc.y + 1 ) ) = true;
                            temp.x = loc.x + 1;
                            temp.y = loc.y + 1;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;

                            if( *( dilatedImage->getData() + temp.x * Image_Width + temp.y ) > 0 )
                            {
                                ROIEdges++;
                            }
                        }
                    }

                    //down
                    if( ( loc.x + 1 ) < static_cast<int32_t>( max_height ) )
                    {
                        if( *( strInputImage->getData() + ( loc.x + 1 )*Image_Width + loc.y ) > 2
                            && *( is_labeled->getData() + ( loc.x + 1 )*Image_Width + loc.y ) == false )
                        {
                            *( is_labeled->getData() + ( loc.x + 1 )*Image_Width + ( loc.y ) ) = true;
                            temp.x = loc.x + 1;
                            temp.y = loc.y;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;

                            if( *( dilatedImage->getData() + temp.x * Image_Width + temp.y ) > 0 )
                            {
                                ROIEdges++;
                            }
                        }
                    }

                    //left-down corner
                    if( ( ( loc.x + 1 ) < static_cast<int32_t>( max_height ) ) && ( ( loc.y - 1 ) > 0 ) )
                    {
                        if( *( strInputImage->getData() + ( loc.x + 1 )*strInputImage->getWidth() + ( loc.y - 1 ) ) > 2
                            && *( is_labeled->getData() + ( loc.x + 1 )*strInputImage->getWidth() + ( loc.y - 1 ) ) == false )
                        {
                            *( is_labeled->getData() + ( loc.x + 1 )*Image_Width + ( loc.y - 1 ) ) = true;
                            temp.x = loc.x + 1;
                            temp.y = loc.y - 1;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;

                            if( *( dilatedImage->getData() + temp.x * Image_Width + temp.y ) > 0 )
                            {
                                ROIEdges++;
                            }
                        }
                    }

                    //left
                    if( ( loc.y - 1 ) > 0 )
                    {
                        if( *( strInputImage->getData() + loc.x * Image_Width + ( loc.y - 1 ) ) > 2
                            && *( is_labeled->getData() + ( loc.x )*Image_Width + ( loc.y - 1 ) ) == false )
                        {
                            *( is_labeled->getData() + ( loc.x )*Image_Width + ( loc.y - 1 ) ) = true;
                            temp.x = loc.x;
                            temp.y = loc.y - 1;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;

                            if( *( dilatedImage->getData() + temp.x * Image_Width + temp.y ) > 0 )
                            {
                                ROIEdges++;
                            }
                        }
                    }

                    //left-up corner
                    if( ( ( loc.y - 1 ) > 0 ) && ( ( loc.x - 1 ) > 2 ) )
                    {
                        if( *( strInputImage->getData() + ( loc.x - 1 ) * Image_Width + ( loc.y - 1 ) ) > 2
                            && *( is_labeled->getData() + ( loc.x - 1 )*Image_Width + ( loc.y - 1 ) ) == false )
                        {
                            *( is_labeled->getData() + ( loc.x - 1 )*Image_Width + ( loc.y - 1 ) ) = true;
                            temp.x = loc.x - 1;
                            temp.y = loc.y - 1;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;

                            if( *( dilatedImage->getData() + temp.x * Image_Width + temp.y ) > 0 )
                            {
                                ROIEdges++;
                            }
                        }
                    }

                    //up
                    if( ( loc.x  - 1 ) > 2 )
                    {
                        if( *( strInputImage->getData() + ( loc.x - 1 )*Image_Width + loc.y ) > 2
                            && *( is_labeled->getData() + ( loc.x - 1 )*Image_Width + ( loc.y ) ) == false )
                        {
                            *( is_labeled->getData() + ( loc.x - 1 )*Image_Width + ( loc.y ) ) = true;
                            temp.x = loc.x - 1;
                            temp.y = loc.y;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;

                            if( *( dilatedImage->getData() + temp.x * Image_Width + temp.y ) > 0 )
                            {
                                ROIEdges++;
                            }
                        }
                    }

                    //
                    //right-up corner
                    if( ( ( loc.x - 1 ) > 2 ) && ( ( loc.y + 1 ) < static_cast<int32_t>( Image_Width - 1U ) ) )
                    {
                        if( *( strInputImage->getData() + ( loc.x - 1 )*Image_Width + ( loc.y + 1 ) ) > 2
                            && *( is_labeled->getData() + ( loc.x - 1 )*Image_Width + ( loc.y + 1 ) ) == false )
                        {
                            *( is_labeled->getData() + ( loc.x - 1 )*Image_Width + ( loc.y + 1 ) ) = true;
                            temp.x = loc.x - 1;
                            temp.y = loc.y + 1;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;

                            if( *( dilatedImage->getData() + temp.x * Image_Width + temp.y ) > 0 )
                            {
                                ROIEdges++;
                            }
                        }
                    }
                }

                float32_t AreaEdge = ( ROIEdges / blobArea_u16 ) * 100.0f;

                //if( blobArea_u16 < minBlobSizeThresh )
                if( ( blobArea_u16 < ( thresh / 2.0f ) ) || ( ( ( AreaEdge < thresh ) ) && ( AreaEdge < 50.0f ) ) || ( AreaEdge < 30.0f ) )
                {
                    for( uint16_t ii = 0; ii < v_queuePoints.col_size; ii++ )
                    {
                        if( *( dilatedImage->getData() + v_queuePoints.col[ii].x * Image_Width + v_queuePoints.col[ii].y ) == 0 )
                        {
                            if( ( ( *( strInputImage->getData() + v_queuePoints.col[ii].x * Image_Width + v_queuePoints.col[ii].y ) > othsu_thresh ) &&
                                  ( mask::TemplateWeightMask[v_queuePoints.col[ii].x][v_queuePoints.col[ii].y] > -0.10f ) && ( ( AreaEdge > thresh ) || ( blobArea_u16 > ( 2.0f * thresh ) ) ) ) ||
                                ( *( strInputImage->getData() + v_queuePoints.col[ii].x * Image_Width + v_queuePoints.col[ii].y ) > 250 ) )
                            {
                                zeroEdgecount++;
                            }
                        }

                        *( strInputImage->getData() + v_queuePoints.col[ii].x * strInputImage->getWidth() + v_queuePoints.col[ii].y ) = 0;
                        *( strLabelImage->getData() + v_queuePoints.col[ii].x * strInputImage->getWidth() + v_queuePoints.col[ii].y ) = 0;
                    }

                    label_u8--;
                }

                v_queuePoints.col_size = 0;
                pixelCount_u16 = 0;
                blobArea_u16 = 0;
            }
        }

        return label_u8;
    }
    uint8_t Scanning::LabelComponent( image::Image<uint8_t>* strInputImage, image::Image<uint8_t>*  strLabelImage, const _roi::ROI r1, image::Image<bool_t>* is_labeled, bool_t templateprocess )
    {
        memset( strLabelImage->getData(), 0, sizeof( uint8_t )* strInputImage->getHeight() * strInputImage->getWidth() );
        memset( is_labeled->getData(), false, sizeof( bool )* strInputImage->getHeight() * strInputImage->getWidth() );
        uint8_t label_u8 = 0;
        //cv::Mat im1 = processing::ImageProcessing::ConvertToCV( *strLabelImage );
        //cv::Mat im = processing::ImageProcessing::ConvertToCV( *strInputImage );
        float32_t total_edges = 0;
        float32_t total_pixel = 0;
        float32_t thresh = 0;
        uint32_t Image_Width = strInputImage->getWidth();

        //for all pixels in the roi
        for( uint16_t i = r1.getY(); i < r1.getHeight(); i++ )
        {
            for( uint16_t j = r1.getX(); j < r1.getWidth(); j++ )
            {
                total_pixel++;

                //if it is black, set as checked
                if( *( strInputImage->getData() + i * Image_Width + j ) == 0 )
                {
                    *( is_labeled->getData() + i * Image_Width + j ) = true;
                }
                //if it is white, set to unchecked
                else
                {
                    total_edges++;
                    *( is_labeled->getData() + i * Image_Width + j ) = false;
                }
            }
        }

        if( templateprocess )
        {
            thresh = ( ( total_edges / total_pixel ) * 100 );
        }
        else
        {
            thresh = ( ( total_edges / total_pixel ) * 100 ) * 2;
        }

        uint16_t pixelCount_u16 = 0;
        Point2i loc, temp, startPoint;
        detectedEllipseBoundary_s v_queuePoints;
        v_queuePoints.col_size = 0;
        uint16_t blobArea_u16 = 0;
        uint32_t max_height = strInputImage->getHeight() - ( r1.getY() * 2 );

        for( uint16_t i = r1.getY(); i < r1.getHeight(); i++ )
        {
            for( uint16_t j = r1.getX(); j < r1.getWidth(); j++ )
            {
                //check if pixel is unchecked
                if( ( *( is_labeled->getData() + i * Image_Width + j ) == false ) && ( *( strInputImage->getData() + i * Image_Width + j ) > 0 ) )
                {
                    loc.x = i;
                    loc.y = j;
                    //add current pixel in queue
                    v_queuePoints.col[v_queuePoints.col_size] = loc;
                    v_queuePoints.flag[v_queuePoints.col_size] = true;
                    v_queuePoints.col_size++;
                    pixelCount_u16++;
                    //set this pixel as checked
                    *( is_labeled->getData() + i * Image_Width + j ) = true;
                    //increase the label
                    label_u8++;
                    //set current pixel to current label
                    *( strLabelImage->getData() + i * Image_Width + j ) = ( uint8_t )label_u8;
                    blobArea_u16++;
                    startPoint = loc;
                }
                else
                    //skip all
                {
                    continue;
                }

                while( pixelCount_u16 )
                {
                    if( ( v_queuePoints.col_size < 1 ) || ( v_queuePoints.col_size > 1500 ) )
                    {
                        break;
                    }

                    loc = v_queuePoints.col[v_queuePoints.front()];
                    pixelCount_u16--;

                    //search right
                    if( ( loc.y + 1 ) < static_cast<int32_t>( Image_Width - 1 ) )
                    {
                        if( ( *( strInputImage->getData() + loc.x * Image_Width + ( loc.y + 1 ) ) > 2 )
                            && ( *( is_labeled->getData() + loc.x * Image_Width + ( loc.y + 1 ) ) == false ) )
                        {
                            *( is_labeled->getData() + loc.x * Image_Width + ( loc.y + 1 ) ) = true;
                            temp.x = loc.x;
                            temp.y = loc.y + 1;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;
                        }
                    }

                    //right-down corner
                    if( ( ( loc.y + 1 ) < static_cast<int32_t>( Image_Width - 1 ) ) && ( ( loc.x + 1 ) < static_cast<int32_t>( max_height ) ) )
                    {
                        if( ( *( strInputImage->getData() + ( loc.x + 1 ) * Image_Width + ( loc.y + 1 ) ) > 2 )
                            && ( *( is_labeled->getData() + ( loc.x + 1 ) * Image_Width + ( loc.y + 1 ) ) == false ) )
                        {
                            *( is_labeled->getData() + ( loc.x + 1 ) * Image_Width + ( loc.y + 1 ) ) = true;
                            temp.x = loc.x + 1;
                            temp.y = loc.y + 1;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;
                        }
                    }

                    //down
                    if( ( loc.x + 1 ) < static_cast<int32_t>( max_height ) )
                    {
                        if( ( *( strInputImage->getData() + ( loc.x + 1 )*Image_Width + loc.y ) > 2 )
                            && ( *( is_labeled->getData() + ( loc.x + 1 )*Image_Width + ( loc.y ) ) == false ) )
                        {
                            *( is_labeled->getData() + ( loc.x + 1 )*Image_Width + ( loc.y ) ) = true;
                            temp.x = loc.x + 1;
                            temp.y = loc.y;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;
                        }
                    }

                    //left-down corner
                    if( ( ( loc.x + 1 ) < static_cast<int32_t>( max_height ) ) && ( ( loc.y - 1 ) > 0 ) )
                    {
                        if( ( *( strInputImage->getData() + ( loc.x + 1 )*Image_Width + ( loc.y - 1 ) ) > 2 )
                            && ( *( is_labeled->getData() + ( loc.x + 1 )*Image_Width + ( loc.y - 1 ) ) == false ) )
                        {
                            *( is_labeled->getData() + ( loc.x + 1 )*Image_Width + ( loc.y - 1 ) ) = true;
                            temp.x = loc.x + 1;
                            temp.y = loc.y - 1;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;
                        }
                    }

                    //left
                    if( ( loc.y - 1 ) > 0 )
                    {
                        if( ( *( strInputImage->getData() + loc.x * Image_Width + ( loc.y - 1 ) ) > 2 )
                            && ( *( is_labeled->getData() + ( loc.x )*Image_Width + ( loc.y - 1 ) ) == false ) )
                        {
                            *( is_labeled->getData() + ( loc.x )*Image_Width + ( loc.y - 1 ) ) = true;
                            temp.x = loc.x;
                            temp.y = loc.y - 1;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;
                        }
                    }

                    //left-up corner
                    if( ( ( loc.y - 1 ) > 0 ) && ( ( loc.x - 1 ) > 2 ) )
                    {
                        if( ( *( strInputImage->getData() + ( loc.x - 1 ) * Image_Width + ( loc.y - 1 ) ) > 2 )
                            && ( *( is_labeled->getData() + ( loc.x - 1 )*Image_Width + ( loc.y - 1 ) ) == false ) )
                        {
                            *( is_labeled->getData() + ( loc.x - 1 )*Image_Width + ( loc.y - 1 ) ) = true;
                            temp.x = loc.x - 1;
                            temp.y = loc.y - 1;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;
                        }
                    }

                    //up
                    if( ( loc.x - 1 ) > 2 )
                    {
                        if( ( *( strInputImage->getData() + ( loc.x - 1 )*Image_Width + loc.y ) > 2 )
                            && ( *( is_labeled->getData() + ( loc.x - 1 )*Image_Width + ( loc.y ) ) == false ) )
                        {
                            *( is_labeled->getData() + ( loc.x - 1 )*Image_Width + loc.y ) = true;
                            temp.x = loc.x - 1;
                            temp.y = loc.y;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;
                        }
                    }

                    //
                    //right-up corner
                    if( ( ( loc.x - 1 ) > 2 ) && ( ( loc.y + 1 ) < static_cast<int32_t>( Image_Width - 1 ) ) )
                    {
                        if( ( *( strInputImage->getData() + ( loc.x - 1 )*Image_Width + ( loc.y + 1 ) ) > 2 )
                            && ( *( is_labeled->getData() + ( loc.x - 1 )*Image_Width + ( loc.y + 1 ) ) == false ) )
                        {
                            *( is_labeled->getData() + ( loc.x - 1 )*Image_Width + ( loc.y + 1 ) ) = true;
                            temp.x = loc.x - 1;
                            temp.y = loc.y + 1;
                            *( strLabelImage->getData() + temp.x * Image_Width + temp.y ) = label_u8;
                            blobArea_u16++;
                            v_queuePoints.col[v_queuePoints.col_size] = temp;
                            v_queuePoints.flag[v_queuePoints.col_size] = true;
                            v_queuePoints.col_size++;
                            pixelCount_u16++;
                        }
                    }
                }

                //if( blobArea_u16 < minBlobSizeThresh )
                if( blobArea_u16 < thresh )
                {
                    for( uint16_t ii = 0; ii < v_queuePoints.col_size; ii++ )
                    {
                        *( strInputImage->getData() + v_queuePoints.col[ii].x * Image_Width + v_queuePoints.col[ii].y ) = 0;
                        *( strLabelImage->getData() + v_queuePoints.col[ii].x * Image_Width + v_queuePoints.col[ii].y ) = 0;
                    }

                    label_u8--;
                }

                v_queuePoints.col_size = 0;
                pixelCount_u16 = 0;
                blobArea_u16 = 0;
            }
        }

        return thresh;
    }

    float32_t Scanning::CountPixel( image::Image<uint8_t>& i_image )
    {
        float32_t sum = 0;

        for( uint32_t x = 1; x < i_image.getWidth() - 1; x++ )
        {
            for( uint32_t y = 1; y < i_image.getHeight() - 1; y++ )
            {
                if( *i_image.at( x, y ) > 0 )
                {
                    sum++;
                }
            }
        }

        return sum;
    }
    /*
    * find initial trailer angle during first scan
    */
    void Scanning::find_initial_trailer_pos()
    {
        uint16_t max_pos = 0;
        float32_t max_val = 0.0f;

        for( uint16_t i = 0; i < m_warpedTopviewParams.width; i++ )
        {
            if( max_val < m_scores[0][i] )
            {
                max_val = m_scores[0][i];
                max_pos = i;
            }
        }

        initial_start_Pos = max_pos - 15;
        final_end_Pos = max_pos + 15;
        c_scanInc = 1;
    }
    /*
    * Perform a 5x5 Dilation on the given image.
    */
    void Scanning::_ROI5x5( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView, float32_t& template_count )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _ROI3x3" );
#endif
        float32_t TemplateCount = 0.0f;
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + dst_step + dst_step + 2;  //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + src_step + src_step + 2;  //PRQA S 3705
        //uint8_t* dst_ptr0;
        //uint8_t* dst_ptr1;
        uint8_t* dst_ptr2;
        //uint8_t* dst_ptr3;
        //uint8_t* dst_ptr4;
        //uint8_t* dst_ptr5;
        //uint8_t* dst_ptr6;
        uint8_t* dst_ptr7;
        //uint8_t* dst_ptr8;
        //uint8_t* dst_ptr9;
        uint8_t* dst_ptr10;
        uint8_t* dst_ptr11;
        uint8_t* dst_ptr12;
        uint8_t* dst_ptr13;
        uint8_t* dst_ptr14;
        //uint8_t* dst_ptr15;
        //uint8_t* dst_ptr16;
        uint8_t* dst_ptr17;
        //uint8_t* dst_ptr18;
        //uint8_t* dst_ptr19;
        //uint8_t* dst_ptr20;
        //uint8_t* dst_ptr21;
        uint8_t* dst_ptr22;
        //uint8_t* dst_ptr23;
        //uint8_t* dst_ptr24;
        uint8_t* src_ptr;
        uint32_t sum;

        for( uint32_t y = 8; y < ( i_topView.getHeight() - 6 ); ++y )
        {
            src_ptr = src_row;
            //dst_ptr0 = dst_row - dst_step - dst_step - 2;   //PRQA S 3705
            //dst_ptr1 = dst_row - dst_step - dst_step - 1;   //PRQA S 3705
            dst_ptr2 = dst_row - dst_step - dst_step;       //PRQA S 3705
            //dst_ptr3 = dst_row - dst_step - dst_step + 1;   //PRQA S 3705
            //dst_ptr4 = dst_row - dst_step - dst_step + 2;   //PRQA S 3705
            //dst_ptr5 = dst_row - dst_step - 2;  //PRQA S 3705
            //dst_ptr6 = dst_row - dst_step - 1;  //PRQA S 3705
            dst_ptr7 = dst_row - dst_step;      //PRQA S 3705
            //dst_ptr8 = dst_row - dst_step + 1;  //PRQA S 3705
            //dst_ptr9 = dst_row - dst_step + 2;  //PRQA S 3705
            dst_ptr10 = dst_row - 2;            //PRQA S 3705
            dst_ptr11 = dst_row - 1;            //PRQA S 3705
            dst_ptr12 = dst_row;
            dst_ptr13 = dst_row + 1;            //PRQA S 3705
            dst_ptr14 = dst_row + 2;            //PRQA S 3705
            //dst_ptr15 = dst_row + dst_step - 2; //PRQA S 3705
            //dst_ptr16 = dst_row + dst_step - 1; //PRQA S 3705
            dst_ptr17 = dst_row + dst_step;     //PRQA S 3705
            //dst_ptr18 = dst_row + dst_step + 1; //PRQA S 3705
            //dst_ptr19 = dst_row + dst_step + 2; //PRQA S 3705
            //dst_ptr20 = dst_row + dst_step + dst_step - 2;  //PRQA S 3705
            //dst_ptr21 = dst_row + dst_step + dst_step - 1;  //PRQA S 3705
            dst_ptr22 = dst_row + dst_step + dst_step;      //PRQA S 3705
            //dst_ptr23 = dst_row + dst_step + dst_step + 1;  //PRQA S 3705
            //dst_ptr24 = dst_row + dst_step + dst_step + 2;  //PRQA S 3705

            for( uint32_t x = 1; x < ( i_topView.getWidth() - 1 ); ++x )
            {
                if( *src_ptr > 0 && mask::TemplateWeightMask[y][x] > 0 )
                {
                    TemplateCount++;
                    int val = *src_ptr;
                    //*dst_ptr0 = static_cast <uint8_t>( 255 );
                    //*dst_ptr1 = static_cast <uint8_t>( 255 );
                    *dst_ptr2 = static_cast <uint8_t>( 255 );
                    //*dst_ptr3 = static_cast <uint8_t>( 255 );
                    //*dst_ptr4 = static_cast <uint8_t>( 255 );
                    //*dst_ptr5 = static_cast <uint8_t>( 255 );
                    //*dst_ptr6 = static_cast <uint8_t>( 255 );
                    *dst_ptr7 = static_cast <uint8_t>( 255 );
                    //*dst_ptr8 = static_cast <uint8_t>( 255 );
                    //*dst_ptr9 = static_cast <uint8_t>( 255 );
                    *dst_ptr10 = static_cast <uint8_t>( 255 );
                    *dst_ptr11 = static_cast <uint8_t>( 255 );
                    *dst_ptr12 = static_cast <uint8_t>( 255 );
                    *dst_ptr13 = static_cast <uint8_t>( 255 );
                    *dst_ptr14 = static_cast <uint8_t>( 255 );
                    //*dst_ptr15 = static_cast <uint8_t>( 255 );
                    //*dst_ptr16 = static_cast <uint8_t>( 255 );
                    *dst_ptr17 = static_cast <uint8_t>( 255 );
                    //*dst_ptr18 = static_cast <uint8_t>( 255 );
                    //*dst_ptr19 = static_cast <uint8_t>( 255 );
                    //*dst_ptr20 = static_cast <uint8_t>( 255 );
                    //*dst_ptr21 = static_cast <uint8_t>( 255 );
                    *dst_ptr22 = static_cast <uint8_t>( 255 );
                    //*dst_ptr23 = static_cast <uint8_t>( 255 );
                    //*dst_ptr24 = static_cast <uint8_t>( 255 );
                }

                ++src_ptr;
                //++dst_ptr0;
                //++dst_ptr1;
                ++dst_ptr2;
                //++dst_ptr3;
                //++dst_ptr4;
                //++dst_ptr5;
                //++dst_ptr6;
                ++dst_ptr7;
                //++dst_ptr8;
                //++dst_ptr9;
                //++dst_ptr10;
                ++dst_ptr11;
                ++dst_ptr12;
                ++dst_ptr13;
                //++dst_ptr14;
                //++dst_ptr15;
                //++dst_ptr16;
                ++dst_ptr17;
                //++dst_ptr18;
                //++dst_ptr19;
                //++dst_ptr20;
                //++dst_ptr21;
                //++dst_ptr22;
                //++dst_ptr23;
                //++dst_ptr24;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

        template_count = TemplateCount;
#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }


    /*
    * Perform a 3x3 Dilation on the given image.
    */
    void Scanning::_ROI3x3_9UP( image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView, float32_t& template_count )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _ROI3x3 9UP" );
#endif
        float32_t TemplateCount = 0.0f;
        //cv::Mat im6 = processing::ImageProcessing::ConvertToCV( o_topView );
        memset( o_topView.getData(), 0, global::TEMPLATE_IMAGE_SIZE );
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + dst_step + dst_step + 1;  //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + src_step + src_step + src_step + src_step + src_step + src_step + src_step + src_step + src_step + src_step + src_step + 1;  //PRQA S 3705
        //uint8_t* dst_ptr0;
        uint8_t* dst_ptr1;
        //uint8_t* dst_ptr2;
        uint8_t* dst_ptr3;
        uint8_t* dst_ptr4;
        uint8_t* dst_ptr5;
        //uint8_t* dst_ptr6;
        uint8_t* dst_ptr7;
        //uint8_t* dst_ptr8;
        uint8_t* src_ptr;
        uint32_t sum;

        for( uint32_t y = 12; y < ( i_topView.getHeight() - 15 ); ++y )
        {
            src_ptr = src_row;
            //dst_ptr0 = dst_row - dst_step - 1;  /* PRQA S 3705*/
            dst_ptr1 = dst_row - dst_step;  /* PRQA S 3705*/
            //dst_ptr2 = dst_row - dst_step + 1;  /* PRQA S 3705*/
            dst_ptr3 = dst_row - 1; /* PRQA S 3705*/
            dst_ptr4 = dst_row;
            dst_ptr5 = dst_row + 1; /* PRQA S 3705*/
            //dst_ptr6 = dst_row + dst_step - 1;  /* PRQA S 3705*/
            dst_ptr7 = dst_row + dst_step;  /* PRQA S 3705*/
            //dst_ptr8 = dst_row + dst_step + 1;  /* PRQA S 3705*/

            for( uint32_t x = 1; x < ( i_topView.getWidth() - 1 ); ++x )
            {
                if( *src_ptr > 0 /*&& mask::TemplateWeightMask[y][x] > 0*/ )
                {
                    if( mask::TemplateWeightMask[y][x] > -0.0f )
                    {
                        TemplateCount++;
                    }

                    int val = *src_ptr;
                    //*dst_ptr0 = static_cast <uint8_t>( 255 );
                    *dst_ptr1 = static_cast <uint8_t>( 255 );
                    //*dst_ptr2 = static_cast <uint8_t>( 255 );
                    *dst_ptr3 = static_cast <uint8_t>( 255 );
                    *dst_ptr4 = static_cast <uint8_t>( 255 );
                    *dst_ptr5 = static_cast <uint8_t>( 255 );
                    //*dst_ptr6 = static_cast <uint8_t>( 255 );
                    *dst_ptr7 = static_cast <uint8_t>( 255 );
                    //*dst_ptr8 = static_cast <uint8_t>( 255 );
                }

                ++src_ptr;
                //++dst_ptr0;
                ++dst_ptr1;
                //++dst_ptr2;
                ++dst_ptr3;
                ++dst_ptr4;
                ++dst_ptr5;
                //++dst_ptr6;
                ++dst_ptr7;
                //++dst_ptr8;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

        template_count = TemplateCount;
#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Perform a 3x3 Dilation on the given image.
    */
    void Scanning::_ROI3x3_7UP( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView, float32_t& template_count )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _ROI3x3 7UP" );
#endif
        float32_t TemplateCount = 0.0f;
        //cv::Mat im6 = processing::ImageProcessing::ConvertToCV( o_topView );
        memset( o_topView.getData(), 0, global::TEMPLATE_IMAGE_SIZE );
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + dst_step + dst_step + 1;  //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + src_step + src_step + src_step + src_step + src_step + src_step + src_step + src_step + src_step + 1;  //PRQA S 3705
        //uint8_t* dst_ptr0;
        uint8_t* dst_ptr1;
        //uint8_t* dst_ptr2;
        uint8_t* dst_ptr3;
        uint8_t* dst_ptr4;
        uint8_t* dst_ptr5;
        //uint8_t* dst_ptr6;
        uint8_t* dst_ptr7;
        //uint8_t* dst_ptr8;
        uint8_t* src_ptr;
        uint32_t sum;

        for( uint32_t y = 10; y < ( i_topView.getHeight() - 13 ); ++y )
        {
            src_ptr = src_row;
            //dst_ptr0 = dst_row - dst_step - 1;  /* PRQA S 3705*/
            dst_ptr1 = dst_row - dst_step;  /* PRQA S 3705*/
            //dst_ptr2 = dst_row - dst_step + 1;  /* PRQA S 3705*/
            dst_ptr3 = dst_row - 1; /* PRQA S 3705*/
            dst_ptr4 = dst_row;
            dst_ptr5 = dst_row + 1; /* PRQA S 3705*/
            //dst_ptr6 = dst_row + dst_step - 1;  /* PRQA S 3705*/
            dst_ptr7 = dst_row + dst_step;  /* PRQA S 3705*/
            //dst_ptr8 = dst_row + dst_step + 1;  /* PRQA S 3705*/

            for( uint32_t x = 1; x < ( i_topView.getWidth() - 1 ); ++x )
            {
                if( *src_ptr > 0 /*&& mask::TemplateWeightMask[y][x] > 0*/ )
                {
                    if( mask::TemplateWeightMask[y][x] > -0.0f )
                    {
                        TemplateCount++;
                    }

                    int val = *src_ptr;
                    //*dst_ptr0 = static_cast <uint8_t>( 255 );
                    *dst_ptr1 = static_cast <uint8_t>( 255 );
                    //*dst_ptr2 = static_cast <uint8_t>( 255 );
                    *dst_ptr3 = static_cast <uint8_t>( 255 );
                    *dst_ptr4 = static_cast <uint8_t>( 255 );
                    *dst_ptr5 = static_cast <uint8_t>( 255 );
                    //*dst_ptr6 = static_cast <uint8_t>( 255 );
                    *dst_ptr7 = static_cast <uint8_t>( 255 );
                    //*dst_ptr8 = static_cast <uint8_t>( 255 );
                }

                ++src_ptr;
                //++dst_ptr0;
                ++dst_ptr1;
                //++dst_ptr2;
                ++dst_ptr3;
                ++dst_ptr4;
                ++dst_ptr5;
                //++dst_ptr6;
                ++dst_ptr7;
                //++dst_ptr8;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

        template_count = TemplateCount;
#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Perform a 3x3 Dilation on the given image.
    */
    void Scanning::_ROI3x3_5UP( image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView, float32_t& template_count )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _ROI3x3 5UP" );
#endif
        float32_t TemplateCount = 0.0f;
        //cv::Mat im6 = processing::ImageProcessing::ConvertToCV( o_topView );
        //cv::Mat im = processing::ImageProcessing::ConvertToCV( i_topView );
        memset( o_topView.getData(), 0, global::TEMPLATE_IMAGE_SIZE );
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + dst_step + dst_step + 1;  //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + src_step + src_step + src_step + src_step + src_step + src_step + src_step + 1;  //PRQA S 3705
        //uint8_t* dst_ptr0;
        uint8_t* dst_ptr1;
        //uint8_t* dst_ptr2;
        uint8_t* dst_ptr3;
        uint8_t* dst_ptr4;
        uint8_t* dst_ptr5;
        //uint8_t* dst_ptr6;
        uint8_t* dst_ptr7;
        //uint8_t* dst_ptr8;
        uint8_t* src_ptr;
        uint32_t sum;

        for( uint32_t y = 8; y < ( i_topView.getHeight() - 11 ); ++y )
        {
            src_ptr = src_row;
            //dst_ptr0 = dst_row - dst_step - 1;  /* PRQA S 3705*/
            dst_ptr1 = dst_row - dst_step;  /* PRQA S 3705*/
            //dst_ptr2 = dst_row - dst_step + 1;  /* PRQA S 3705*/
            dst_ptr3 = dst_row - 1; /* PRQA S 3705*/
            dst_ptr4 = dst_row;
            dst_ptr5 = dst_row + 1; /* PRQA S 3705*/
            //dst_ptr6 = dst_row + dst_step - 1;  /* PRQA S 3705*/
            dst_ptr7 = dst_row + dst_step;  /* PRQA S 3705*/
            //dst_ptr8 = dst_row + dst_step + 1;  /* PRQA S 3705*/

            for( uint32_t x = 1; x < ( i_topView.getWidth() - 1 ); ++x )
            {
                if( *src_ptr > 0 /*&& mask::TemplateWeightMask[y][x] > 0*/ )
                {
                    if( mask::TemplateWeightMask[y][x] > -0.0f )
                    {
                        TemplateCount++;
                    }

                    int val = *src_ptr;
                    //*dst_ptr0 = static_cast <uint8_t>( 255 );
                    *dst_ptr1 = static_cast <uint8_t>( 255 );
                    //*dst_ptr2 = static_cast <uint8_t>( 255 );
                    *dst_ptr3 = static_cast <uint8_t>( 255 );
                    *dst_ptr4 = static_cast <uint8_t>( 255 );
                    *dst_ptr5 = static_cast <uint8_t>( 255 );
                    //*dst_ptr6 = static_cast <uint8_t>( 255 );
                    *dst_ptr7 = static_cast <uint8_t>( 255 );
                    //*dst_ptr8 = static_cast <uint8_t>( 255 );
                }

                ++src_ptr;
                //++dst_ptr0;
                ++dst_ptr1;
                //++dst_ptr2;
                ++dst_ptr3;
                ++dst_ptr4;
                ++dst_ptr5;
                //++dst_ptr6;
                ++dst_ptr7;
                //++dst_ptr8;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

        template_count = TemplateCount;
#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Perform a 3x3 Dilation on the given image.
    */
    void Scanning::_ROI3x3_3UP( image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView, float32_t& template_count )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _ROI3x3 UP" );
#endif
        float32_t TemplateCount = 0.0f;
        //cv::Mat im6 = processing::ImageProcessing::ConvertToCV( o_topView );
        //cv::Mat im = processing::ImageProcessing::ConvertToCV( i_topView );
        memset( o_topView.getData(), 0, global::TEMPLATE_IMAGE_SIZE );
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + dst_step + dst_step + 1;  //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + src_step + src_step + src_step + src_step + src_step + 1;  //PRQA S 3705
        //uint8_t* dst_ptr0;
        uint8_t* dst_ptr1;
        //uint8_t* dst_ptr2;
        uint8_t* dst_ptr3;
        uint8_t* dst_ptr4;
        uint8_t* dst_ptr5;
        //uint8_t* dst_ptr6;
        uint8_t* dst_ptr7;
        //uint8_t* dst_ptr8;
        uint8_t* src_ptr;
        uint32_t sum;

        for( uint32_t y = 6; y < ( i_topView.getHeight() - 9 ); ++y )
        {
            src_ptr = src_row;
            //dst_ptr0 = dst_row - dst_step - 1;  /* PRQA S 3705*/
            dst_ptr1 = dst_row - dst_step;  /* PRQA S 3705*/
            //dst_ptr2 = dst_row - dst_step + 1;  /* PRQA S 3705*/
            dst_ptr3 = dst_row - 1; /* PRQA S 3705*/
            dst_ptr4 = dst_row;
            dst_ptr5 = dst_row + 1; /* PRQA S 3705*/
            //dst_ptr6 = dst_row + dst_step - 1;  /* PRQA S 3705*/
            dst_ptr7 = dst_row + dst_step;  /* PRQA S 3705*/
            //dst_ptr8 = dst_row + dst_step + 1;  /* PRQA S 3705*/

            for( uint32_t x = 1; x < ( i_topView.getWidth() - 2 ); ++x )
            {
                if( *src_ptr > 0 /*&& mask::TemplateWeightMask[y][x] > 0*/ )
                {
                    if( mask::TemplateWeightMask[y][x] > -0.0f )
                    {
                        TemplateCount++;
                    }

                    int val = *src_ptr;
                    //*dst_ptr0 = static_cast <uint8_t>( 255 );
                    *dst_ptr1 = static_cast <uint8_t>( 255 );
                    //*dst_ptr2 = static_cast <uint8_t>( 255 );
                    *dst_ptr3 = static_cast <uint8_t>( 255 );
                    *dst_ptr4 = static_cast <uint8_t>( 255 );
                    *dst_ptr5 = static_cast <uint8_t>( 255 );
                    //*dst_ptr6 = static_cast <uint8_t>( 255 );
                    *dst_ptr7 = static_cast <uint8_t>( 255 );
                    //*dst_ptr8 = static_cast <uint8_t>( 255 );
                }

                ++src_ptr;
                //++dst_ptr0;
                ++dst_ptr1;
                //++dst_ptr2;
                ++dst_ptr3;
                ++dst_ptr4;
                ++dst_ptr5;
                //++dst_ptr6;
                ++dst_ptr7;
                //++dst_ptr8;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

        template_count = TemplateCount;
#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }
    /*
    * Perform a 3x3 Dilation on the given image.
    */
    void Scanning::_ROI3x3( image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView, float32_t& template_count )
    {
#ifdef DIAGNOSTICS
        diag::start( "PreProcessing: _ROI3x3" );
#endif
        float32_t TemplateCount = 0.0f;
        memset( o_topView.getData(), 0, global::TEMPLATE_IMAGE_SIZE );
        uint32_t dst_step = o_topView.getStep();
        uint32_t src_step = i_topView.getStep();
        uint8_t* dst_row = o_topView.getData() + dst_step + dst_step + dst_step + 1;  //PRQA S 3705
        uint8_t* src_row = i_topView.getData() + src_step + src_step + src_step + 1;  //PRQA S 3705
        //uint8_t* dst_ptr0;
        uint8_t* dst_ptr1;
        //uint8_t* dst_ptr2;
        uint8_t* dst_ptr3;
        uint8_t* dst_ptr4;
        uint8_t* dst_ptr5;
        //uint8_t* dst_ptr6;
        uint8_t* dst_ptr7;
        //uint8_t* dst_ptr8;
        uint8_t* src_ptr;
        uint32_t sum;

        for( uint32_t y = 3; y < ( i_topView.getHeight() - 6 ); ++y )
        {
            src_ptr = src_row;
            //dst_ptr0 = dst_row - dst_step - 1;  /* PRQA S 3705*/
            dst_ptr1 = dst_row - dst_step;  /* PRQA S 3705*/
            //dst_ptr2 = dst_row - dst_step + 1;  /* PRQA S 3705*/
            dst_ptr3 = dst_row - 1; /* PRQA S 3705*/
            dst_ptr4 = dst_row;
            dst_ptr5 = dst_row + 1; /* PRQA S 3705*/
            //dst_ptr6 = dst_row + dst_step - 1;  /* PRQA S 3705*/
            dst_ptr7 = dst_row + dst_step;  /* PRQA S 3705*/
            //dst_ptr8 = dst_row + dst_step + 1;  /* PRQA S 3705*/

            for( uint32_t x = 1; x < ( i_topView.getWidth() - 2 ); ++x )
            {
                if( *src_ptr > 0 /*&& mask::TemplateWeightMask[y][x] > 0*/ )
                {
                    if( mask::TemplateWeightMask[y][x] > -0.0f )
                    {
                        TemplateCount++;
                    }

                    int val = *src_ptr;
                    //*dst_ptr0 = static_cast <uint8_t>( 255 );
                    *dst_ptr1 = static_cast <uint8_t>( 255 );
                    //*dst_ptr2 = static_cast <uint8_t>( 255 );
                    *dst_ptr3 = static_cast <uint8_t>( 255 );
                    *dst_ptr4 = static_cast <uint8_t>( 255 );
                    *dst_ptr5 = static_cast <uint8_t>( 255 );
                    //*dst_ptr6 = static_cast <uint8_t>( 255 );
                    *dst_ptr7 = static_cast <uint8_t>( 255 );
                    //*dst_ptr8 = static_cast <uint8_t>( 255 );
                }

                ++src_ptr;
                //++dst_ptr0;
                ++dst_ptr1;
                //++dst_ptr2;
                ++dst_ptr3;
                ++dst_ptr4;
                ++dst_ptr5;
                //++dst_ptr6;
                ++dst_ptr7;
                //++dst_ptr8;
            }

            dst_row += dst_step;
            src_row += src_step;
        }

        template_count = TemplateCount;
#ifdef DIAGNOSTICS
        diag::stop();
#endif
    }

    /*
    * Return whether or not the trailer angle has been found and scanning has been completed.
    */
    bool_t Scanning::IsTrailerAngleFound()const
    {
        return m_trailerAngleFound;
    }

    /*
    * Get the previously found trailer angle. Should only be called after 'IsTrailerAngleFound()'
    * returns 'true'.
    */
    float32_t Scanning::GetTrailerAngle()const
    {
        return m_bestTrailerAngle;
    }
    /*
    * is scanning complete
    */
    bool_t Scanning::IsScanningComplete()const
    {
        return m_scanningComplete;
    }

    /*
    * Get the score from the previously found trailer angle. Should only be called after
    * 'IsTrailerAngleFound()' returns 'true'.
    */
    float32_t Scanning::GetScore()const
    {
        return m_scanningScore;
    }

    /*
    * Calculate the current trailer angle based on the scores received from scanning.
    */
    float32_t Scanning::_CalculateTrailerAngle()
    {
        bool_t isReturned = true;
        float32_t ret_val;
#ifdef DIAGNOSTICS
        diag::start( "SCN: CalculateTrailerAngle" );
#endif
        float32_t weightedScores[global::WARPED_TOPVIEW_IMAGE_WIDTH] = { 0.0f };
        float32_t w = 2.0f;
        float32_t total_w = w;
        float32_t max_val = -100.0f;
        float32_t max_ind[c_numFullScans] = { 0 };

        // --- Calculate weighted scores
        for( uint32_t i = 1; i < c_numFullScans; i++ )
        {
            w += 2.0f;
            total_w = total_w + w;
            max_ind[i] = TAD2::WarpedImage<uint8_t>( m_warpedTopviewParams ).XPos2Angle( 0.0 );

            for( uint32_t j = initial_start_Pos; j < final_end_Pos; j++ )
            {
                if( max_val < m_scores[i][j] )
                {
                    ScanInd = i;
                    max_val = m_scores[i][j];
                    max_ind[i] = TAD2::WarpedImage<uint8_t>( m_warpedTopviewParams ).XPos2Angle( static_cast<float32_t>( j ) );
                }

                weightedScores[j] += w * m_scores[i][j];
            }
        }

        // ++ finding standard deviation
        float32_t sum_val = 0.0;
        float32_t standard_deviation = 0.0;
        float32_t count = 0.0;

        for( uint32_t i = 1; i < c_numFullScans; i++ )
        {
            sum_val += max_ind[i];
            count++;
        }

        float32_t mean_val = sum_val / count;

        for( uint32_t i = 1; i < c_numFullScans; i++ )
        {
            standard_deviation += pow( max_ind[i] - mean_val, 2.0f );
        }

        standard_deviation = sqrt( standard_deviation / count );
        // -- finding standard deviation
#ifdef DIAGNOSTICS
        diag::stop();
#endif
        m_scanningComplete = true;

        //if( /*( standard_deviation > 1.5f ) ||*/ ( mecl::math::abs_x( 90.0f - max_ind[1] ) > 30.0f ) && scanningstate )
        //{
        //    Start( m_trailerTemplate );
        //    ret_val = 0.0f;
        //    isReturned = false;
        //}

        if( isReturned ) //PRQA S 4113 1
        {
            // --- Find max weighted score
            float32_t bestScore = -1.0f;
            uint32_t bestX = 0;

            for( uint32_t i = initial_start_Pos; i < final_end_Pos; i++ )
            {
                if( m_scores[ScanInd][i] > bestScore )
                {
                    bestX = i;
                    bestScore = m_scores[ScanInd][i];
                }
            }

            m_bestTrailerAngle = TAD2::WarpedImage<uint8_t>( m_warpedTopviewParams ).XPos2Angle( static_cast<float32_t>( bestX ) );
            m_scanningScore = max_val;
            m_trailerAngleFound = true;
#ifdef DIAGNOSTICS
            //
            // --- File output
            fo::csvstream tmScoreOutput = fo::getCSVStream( "TAD2/Scores/Scanning/tm_scores.csv" );
            fo::csvstream scScoreOutput = fo::getCSVStream( "TAD2/Scores/Scanning/sc_scores.csv" );
            scScoreOutput << global::getVidName() << global::getFrameNum() << m_scanningScore << '\n';

            for( uint32_t i = 0; i < 640; i++ )
            {
                tmScoreOutput << ( weightedScores[i] );
            }

            tmScoreOutput << '\n';
            //
#ifdef DIAGNOSTICS
            diag::stop();
#endif
#endif
            ret_val = m_bestTrailerAngle;
        }

        return ret_val;
    }

    /*
    * Create an image which stores, at each pixel, the distance from that pixel to the
    * nearest edge in that row of the given image. Assumes that the pixels just outside
    * the border are edges.
    *
    * Not currently used.
    */
    void Scanning::CreateDistImage( image::Image<uint8_t>& i_image, image::Image<uint32_t>& o_distImage )
    {
        uint32_t w = i_image.getWidth();
        uint32_t h = i_image.getHeight();
        uint32_t cur_dist;
        const uint32_t border_dist = mecl::math::max_x( w, h );

        // --- Set distance to nearest edge on left side
        for( uint32_t y = 0; y < h; y++ )
        {
            cur_dist = border_dist;

            for( uint32_t x = 0; x < w; x++ )
            {
                if( *i_image.at( x, y ) > 0 )
                {
                    cur_dist = 0;
                }

                *o_distImage.at( x, y ) = cur_dist;
                cur_dist++;
            }
        }

#ifdef DIAGNOSTICS
        db::imshow( "(SCN-3) Left Dist Image", o_distImage, db::ImShow_Grey, 0U, 0U );
#endif

        // --- Check against dist to right side
        for( uint32_t y = 0; y < h; y++ )
        {
            cur_dist = border_dist;

            for( int32_t x = w - 1; x >= 0; x-- )
            {
                if( *i_image.at( x, y ) > 0 )
                {
                    cur_dist = 0;
                }

                uint32_t ImageVal_u32 = *o_distImage.at( x, y );
                *o_distImage.at( x, y ) = mecl::math::min_x( ImageVal_u32, cur_dist );
                cur_dist++;
            }
        }

#ifdef DIAGNOSTICS
        db::imshow_range( "(SCN-3) Dist Image", o_distImage, 50U, 0U );
#endif
    }

    float32_t Scanning::SimilarityUsingDistImage( image::Image<uint8_t>& i_template, image::Image<uint32_t>& i_distImage, int32_t i_x, int32_t i_y )
    {
        float32_t ret_val;
#ifdef DIAGNOSTICS
        diag::start( "GaussianSimilarityWeighted3x3_2" );
#endif
        int32_t start_x = 0;
        int32_t end_x = i_template.getWidth();
        int32_t start_y = 0;
        int32_t end_y = i_template.getHeight();
        uint32_t template_count = 0;
        uint32_t total_dist = 0;

        if( i_x < 0 )
        {
            start_x = mecl::math::min_x( -i_x, static_cast <int32_t>( i_template.getWidth() ) );
        }

        if( ( i_x + static_cast <int32_t>( i_template.getWidth() ) ) > static_cast <int32_t>( i_distImage.getWidth() ) )
        {
            end_x = mecl::math::max_x( static_cast <int32_t>( i_distImage.getWidth() ) - i_x, 0 );
        }

        if( i_y < 0 )
        {
            start_y = mecl::math::min_x( -i_y, static_cast <int32_t>( i_template.getHeight() ) );
        }

        if( ( i_y + static_cast <int32_t>( i_template.getHeight() ) ) > static_cast <int32_t>( i_distImage.getHeight() ) )
        {
            end_y = mecl::math::max_x( static_cast <int32_t>( i_distImage.getHeight() ) - i_y, 0 );
        }

        for( int32_t x = ( start_x + 1 ); x < ( end_x - 1 ); x++ )
        {
            for( int32_t y = ( start_y + 1 ); y < ( end_y - 1 ); y++ )
            {
                if( *i_template.at( x, y ) > 0 )
                {
                    template_count++;
                    total_dist += *i_distImage.at( i_x + x, i_y + y );
                }
            }
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif

        if( template_count == 0 )
        {
            ret_val = 0;
        }
        else  //PRQA S 4113 1
        {
            ret_val = static_cast<float32_t>( total_dist ) / static_cast<float32_t>( template_count );
        }

        return ret_val;
    }
}
