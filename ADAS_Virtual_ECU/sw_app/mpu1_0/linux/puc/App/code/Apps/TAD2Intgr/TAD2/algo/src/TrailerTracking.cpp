// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [28-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "TrailerTracking.h"
#include "TemplateMatching.h"

#ifdef DIAGNOSTICS
    #include "global.h"
    #include "fo.h"
#endif
#include "common/db.h"

namespace TAD2
{

    /*
    * Constructor.
    */
    TrailerTracking::TrailerTracking() :
        m_initOK( false ),
        m_isRunning( false ),
        m_isDummy( false ),
        m_lastFrameRun( 0 )
    {
    }

    /*
    * Destructor.
    */
    TrailerTracking::~TrailerTracking()
    {
    }

    /*
    * Initialize this module.
    *
    * Called once at the beginning of the program, before any other functions.
    */
    bool_t TrailerTracking::Init( const TAD2::WarpedTopViewParameters& i_warpedTopviewParams, float32_t i_templateMatchingWeightFactor )
    {
        m_warpedTopviewParams = i_warpedTopviewParams;
        m_templateMatchingWeightFactor = i_templateMatchingWeightFactor;
        //
        m_initOK = true;
        return true;
    }

    /*
    * Signifies the beginning of a period of execution. Allocates any necessary
    * memory and sets any input parameters needed at runtime.
    */
    bool_t TrailerTracking::Start( TAD2::TrailerTemplate i_trailerTemplate, float32_t i_initialTrailerAngle )
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

            m_baseTrailerTemplate = i_trailerTemplate;
            m_curTrailerAngle_deg = i_initialTrailerAngle;
            m_currentTrailerXPos = TAD2::WarpedImage<uint8_t>( m_warpedTopviewParams ).Angle2XPos( i_initialTrailerAngle );
            m_confidence = 0.0f;
            m_angleTemplateLastUpdated_deg = m_curTrailerAngle_deg;
            m_prevTemplateMatchingScore = 0.0f;
            previous_slide_pos = trailer::c_dynamic_numTemplates / 2;
            //
            // --- Initialize dynamic template
            m_dynamicTrailerTemplate = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
            processing::ImageProcessing::Copy( i_trailerTemplate, m_dynamicTrailerTemplate );
            m_dynamicTemplateNumPixels = _CountPixels( m_dynamicTrailerTemplate );
            initial_dynamic_template_updated = false;

            if( ( i_trailerTemplate.getWidth() * i_trailerTemplate.getHeight() ) != global::TEMPLATE_IMAGE_SIZE )
            {
                ret_val = false;
            }

            if( ret_val )
            {
#ifdef DIAGNOSTICS
                db::imshow( "(TAD-1) Base Template", m_baseTrailerTemplate, db::ImShow_Binary );
                db::resetPlot( "(TAD-3) Template Matching Score" );
                db::resetPlot( "(TAD-3) Confidence" );
                db::resetPlot( "(TAD-3) Best Angle" );
                db::setPlotYLim( "(TAD-3) Best Angle", -90.0f, 90.0f );
#endif
                //
                m_isRunning = true;
                ret_val = true;
            }
        }

        return ret_val;
    }

    /*
    * Signifies the end of a period of execution. Deallocates any memory used.
    */
    void TrailerTracking::Finish()
    {
        memory::MemoryPool::ReleaseImage( m_dynamicTrailerTemplate );
        m_isRunning = false;
        initial_dynamic_template_updated = false;
    }

    /*
    * Run this module.
    *
    * Will only run if called between a call to Start() and a call to Finish(), respectively.
    * Records the given frame so as to not run the same frame multiple times.
    */
    void TrailerTracking::Run( uint32_t i_frame, TAD2::WarpedImage<uint8_t>& i_warpedTopview, uint16_t othsuthresh, bool_t dummy_angle_enabled, bool_t dynamci_window_enable )
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
            if( ( !initial_dynamic_template_updated ) && ( !dummy_angle_enabled ) )
            {
                _update_initial_dynamic_template( i_warpedTopview, othsuthresh );
                initial_dynamic_template_updated = true;
            }

#ifdef DIAGNOSTICS
            diag::start( "Trailer Tracking" );
#endif
            // --- Allocate template images, etc.
            float32_t angles[trailer::c_dynamic_numTemplates] = { 0.0f };
            float32_t scores1[trailer::c_dynamic_numTemplates] = { 0.0f };
            float32_t scores2[trailer::c_dynamic_numTemplates] = { 0.0f };
            float32_t scores3[trailer::c_dynamic_numTemplates] = { 0.0f };
            // --- Extract templates and calculate scores
            float32_t max_score1 = -1.0f;
            float32_t max_score2 = -1.0f;
            float32_t max_score3 = -1.0f;
            float32_t score1 = 0.0f;
            float32_t score2 = 0.0f;
            float32_t score3 = 0.0f;
            int32_t ind1 = 0;
            int32_t ind2 = 0;
            int32_t ind3 = 0;
            int32_t trailer_pos[21] = { 0 };
            uint32_t max_offset = 16;

            if( previous_slide_pos > max_offset )
            {
                previous_slide_pos = max_offset;
            }

            uint32_t min_offset = 4;

            if( previous_slide_pos < min_offset )
            {
                previous_slide_pos = min_offset;
            }

            int32_t start_ind = previous_slide_pos - 4;
            int32_t end_ind = previous_slide_pos + 5;

            for( int32_t i = start_ind; i < end_ind; i++ )
            {
                int32_t x = m_currentTrailerXPos + trailer::c_dynamic_templateOffsets[i];
                trailer_pos[i] = x;
                score2 = _CalculateSimilarityScore_2( m_dynamicTrailerTemplate, i_warpedTopview, x - static_cast<int32_t>( m_dynamicTrailerTemplate.getWidth() ) / 2, othsuthresh );
                score1 = _CalculateSimilarityScore_2( m_baseTrailerTemplate, i_warpedTopview, x - static_cast<int32_t>( m_baseTrailerTemplate.getWidth() ) / 2, othsuthresh );
                score3 = 3.0f * score1 + score2;

                if( ( score1 > max_score1 ) || ( max_score1 < 0 ) )
                {
                    max_score1 = score1;
                    ind1 = i;
                }

                if( ( score2 > max_score2 ) || ( max_score2 < 0 ) )
                {
                    max_score2 = score2;
                    ind2 = i;
                }

                if( ( score3 > max_score3 ) || ( max_score3 < 0 ) )
                {
                    max_score3 = score3;
                    ind3 = i;
                }

                scores1[i] = score1;
                scores2[i] = score2;
                scores3[i] = score3;
                angles[i] = i_warpedTopview.XPos2Angle( static_cast<float32_t>( x ) );
            }

            if( dynamci_window_enable )
            {
                previous_slide_pos = ind3;
            }
            else
            {
                previous_slide_pos = trailer::c_dynamic_numTemplates / 2;
            }

            // --- Calculate confidence level
            float32_t score_sum = 0.0f;

            for( uint32_t i = 0; i < static_cast<uint32_t>( trailer::c_dynamic_numTemplates ); i++ )
            {
                if( static_cast<int32_t>( i ) != ind3 )
                {
                    score_sum += scores3[i];
                }
            }

            m_confidence = max_score3 - score_sum / static_cast<float32_t>( ( trailer::c_steady_numTemplates - 1 ) );
            // If dummy angle is active:
            uint8_t data[global::TEMPLATE_IMAGE_SIZE];
            memset( reinterpret_cast<uint8_t*>( data ), 0, sizeof( uint8_t ) * global::TEMPLATE_IMAGE_SIZE );
            image::Image<uint8_t> crop_template = image::Image<uint8_t>( m_dynamicTrailerTemplate.getWidth(), m_dynamicTrailerTemplate.getHeight(), data, 1 );
            t_m::TemplateMatching::ExtractTemplate_2( i_warpedTopview.getData(), i_warpedTopview.getWidth(), i_warpedTopview.getHeight(), i_warpedTopview.getStep(), i_warpedTopview.getNumChannels(), crop_template.getData(), crop_template.getWidth(), crop_template.getHeight(), crop_template.getStep(), crop_template.getNumChannels(), crop_template.getSize(), trailer_pos[ind3] - ( m_baseTrailerTemplate.getWidth() / 2 ), 0 );

            // --- Determine angle
            if( max_score3 > trailer::c_minTemplateMatchingScore )
            {
                m_prevTemplateMatchingScore = max_score3;
                m_curTrailerAngle_deg = angles[ind3];
                m_currentTrailerXPos = i_warpedTopview.Angle2XPos( m_curTrailerAngle_deg );

                // --- Reset dynamic template
                if( ( mecl::math::abs_x( 90.0f - m_curTrailerAngle_deg ) < trailer::c_angleOffsetToResetTemplate_deg ) && ( mecl::math::abs_x( 90.0f - m_angleTemplateLastUpdated_deg ) > trailer::c_angleOffsetToResetTemplate_deg ) )
                {
                    processing::ImageProcessing::Copy( m_baseTrailerTemplate, m_dynamicTrailerTemplate );

                    if( !dummy_angle_enabled )
                    {
                        _UpdateDynamicTemplate_1( crop_template, othsuthresh );
                    }
                    else
                    {
                        _UpdateDynamicTemplate( crop_template );
                    }

                    m_angleTemplateLastUpdated_deg = m_curTrailerAngle_deg;
                }

                // --- Update dynamic template
                if( ( ( mecl::math::abs_x( m_curTrailerAngle_deg - m_angleTemplateLastUpdated_deg ) > ( trailer::c_angleOffsetToUpdateTemplate_deg ) ) && ( m_confidence > trailer::c_minConfidenceLevel ) ) )
                {
                    bool_t templateUpdated;

                    if( !dummy_angle_enabled )
                    {
                        templateUpdated = _UpdateDynamicTemplate_1( crop_template, othsuthresh );
                    }
                    else
                    {
                        templateUpdated = _UpdateDynamicTemplate( crop_template );
                    }

                    if( templateUpdated )
                    {
                        m_angleTemplateLastUpdated_deg = m_curTrailerAngle_deg;
                    }
                }
            }

#ifdef DIAGNOSTICS
            float32_t factor = m_templateMatchingWeightFactor;
            db::plot( "(TAD-3) Template Matching Score", max_score1, db::Colour( 255, 0, 0 ) );
            db::plot( "(TAD-3) Template Matching Score", max_score2, db::Colour( 0, 255, 0 ) );
            db::plot( "(TAD-3) Template Matching Score", max_score3, db::Colour( 255, 255, 0 ) );
            db::plot( "(TAD-3) Confidence", m_confidence, db::Colour( 255, 0, 0 ) );
            db::plot( "(TAD-3) Best Angle", 90.0f - angles[ind1], db::Colour( 255, 0, 0 ) );
            db::plot( "(TAD-3) Best Angle", 90.0f - angles[ind2], db::Colour( 0, 255, 0 ) );
            db::plot( "(TAD-3) Best Angle", 90.0f - angles[ind3], db::Colour( 255, 255, 0 ) );
            db::showAngleDetection( i_warpedTopview, m_baseTrailerTemplate, m_dynamicTrailerTemplate, crop_template, m_curTrailerAngle_deg, m_currentTrailerXPos, 0, factor );
            //
            // --- Writing to file
            char filename[260] = { '\0' };
            strncat( &filename[0], "TAD2/Scores/", 259 );
            strncat( &filename[0], global::getVidName(), 260 - strlen( filename ) - 1 );
            strncat( &filename[0], ".csv", 260 - strlen( filename ) - 1 );
            fo::csvstream scoreOutput = fo::getCSVStream( filename );

            if( scoreOutput.isopen() )
            {
                scoreOutput << global::getFrameNum() << ( 90.0f - m_curTrailerAngle_deg );

                for( int i = 0; i < trailer::c_dynamic_numTemplates; i++ )
                {
                    scoreOutput << scores1[i];
                }

                for( int i = 0; i < trailer::c_dynamic_numTemplates; i++ )
                {
                    scoreOutput << scores2[i];
                }

                for( int i = 0; i < trailer::c_dynamic_numTemplates; i++ )
                {
                    scoreOutput << scores3[i];
                }

                scoreOutput << '\n';
            }

            filename[0] = '\0';
            strncat( &filename[0], "TAD2/Conf/", 259 );
            strncat( &filename[0], global::getVidName(), 260 - strlen( filename ) - 1 );
            strncat( &filename[0], ".csv", 260 - strlen( filename ) - 1 );
            fo::csvstream confOutput = fo::getCSVStream( filename );

            if( confOutput.isopen() )
            {
                confOutput << global::getFrameNum() << ( 90.0f - m_curTrailerAngle_deg ) << m_confidence << '\n';
            }

#endif
            m_lastFrameRun = i_frame;
#ifdef DIAGNOSTICS
            diag::stop();
#endif
        }
    }
    /**
    * Update the dynamic template.
    */
    void TrailerTracking::_update_initial_dynamic_template( TAD2::WarpedImage<uint8_t>& i_warpedTopview, uint16_t othsuthresh )
    {
        image::Image<uint8_t> temp_img;
        uint8_t data[global::TEMPLATE_IMAGE_SIZE];
        temp_img.setWidth( m_baseTrailerTemplate.getWidth() );
        temp_img.setHeight( m_baseTrailerTemplate.getHeight() );
        temp_img.setStep( m_baseTrailerTemplate.getWidth() );
        temp_img.setNumChannels( 1 );
        temp_img.setSize( temp_img.getWidth() * temp_img.getHeight() );
        temp_img.setData( reinterpret_cast<uint8_t*>( data ) );
        int32_t x = m_currentTrailerXPos;
        t_m::TemplateMatching::ExtractTemplate_2( i_warpedTopview.getData(), i_warpedTopview.getWidth(), i_warpedTopview.getHeight(), i_warpedTopview.getStep(), i_warpedTopview.getNumChannels(), temp_img.getData(), temp_img.getWidth(), temp_img.getHeight(), temp_img.getStep(), temp_img.getNumChannels(), temp_img.getSize(), x - static_cast<int32_t>( m_baseTrailerTemplate.getWidth() ) / 2, 0 );
        float32_t score1 = _CalculateSimilarityScore_2( m_baseTrailerTemplate, i_warpedTopview, x - static_cast<int32_t>( m_baseTrailerTemplate.getWidth() ) / 2, othsuthresh );

        if( score1 > 0.1 )
        {
            _UpdateDynamicTemplate_1( temp_img, othsuthresh );
        }
    }
    /**
    * Update the dynamic template.
    */
    bool_t TrailerTracking::_Update_Full_New_DynamicTemplate( image::Image<uint8_t>& i_bestRoi, uint16_t othsuthresh )
    {
#ifdef DIAGNOSTICS
        diag::start( "_UpdateDynamicTemplate" );
#endif
        uint8_t data[global::TEMPLATE_IMAGE_SIZE];
        memset( reinterpret_cast<uint8_t*>( data ), 0, sizeof( uint8_t ) * global::TEMPLATE_IMAGE_SIZE );
        image::Image<uint8_t> newTemplate = image::Image<uint8_t>( m_dynamicTrailerTemplate.getWidth(), m_dynamicTrailerTemplate.getHeight(), data, 1 );

        for( uint32_t y = 3; y < ( m_dynamicTrailerTemplate.getHeight() - 6 ); y++ )
        {
            for( uint32_t x = 3; x < ( m_dynamicTrailerTemplate.getWidth() - 6 ); x++ )
            {
                if( *i_bestRoi.at( x, y ) > othsuthresh )
                {
                    *newTemplate.at( x, y ) = 255;
                }
            }
        }

        bool_t templateUpdated = false;
        uint32_t newTemplateNumPixels = _CountPixels( newTemplate );

        if( ( static_cast<float32_t>( newTemplateNumPixels ) > trailer::c_dynTempMinPixelAmount ) || ( newTemplateNumPixels > m_dynamicTemplateNumPixels ) )
        {
            processing::ImageProcessing::Copy( newTemplate, m_dynamicTrailerTemplate );
            templateUpdated = true;
            m_angleTemplateLastUpdated_deg = m_curTrailerAngle_deg;
            m_dynamicTemplateNumPixels = newTemplateNumPixels;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
        return templateUpdated;
    }
    /*
    * set current trailer position
    */
    void TrailerTracking::SetCurrentTrailerAngle( float32_t trailer_angle )
    {
        m_currentTrailerXPos = TAD2::WarpedImage<uint8_t>( m_warpedTopviewParams ).Angle2XPos( trailer_angle );
    }
    /*
    * Get the current trailer angle, in degrees.
    */
    float32_t TrailerTracking::GetTrailerAngle() const
    {
        return m_curTrailerAngle_deg;
    }


    /*
    * Set the current trailer angle from outside, in degrees.
    */
    void TrailerTracking::SetTrailerAngle( float32_t trailerAngle )
    {
        m_curTrailerAngle_deg = trailerAngle;
    }


    /*
    * Get the normalized template matching score from the most recent angle found.
    */
    float32_t TrailerTracking::GetTrackingScore() const
    {
        return m_prevTemplateMatchingScore / 4.0f;
    }
    // Set m_isDummy
    void TrailerTracking::Set_IsDummy( bool_t dummy )
    {
        m_isDummy = dummy;
    }
    /**
    * Calculate the similarity between the given trailer template and
    * a new region of interest.
    */
    float32_t TrailerTracking::_CalculateSimilarityScore( image::Image<uint8_t>& i_trailerTemplate, TAD2::WarpedImage<uint8_t>& i_warpedTopview, int32_t i_x ) const
    {
        float32_t factor = m_templateMatchingWeightFactor;
        return  t_m::TemplateMatching::GaussianSimilarityWeighted3x3_2( i_trailerTemplate, i_warpedTopview, i_x, 0, factor, 0 );
    }


    float32_t TrailerTracking::_CalculateSimilarityScore_2( image::Image<uint8_t>& i_trailerTemplate, TAD2::WarpedImage<uint8_t>& i_warpedTopview, int32_t i_x, uint16_t othsuthresh ) const
    {
        float32_t factor = m_templateMatchingWeightFactor;
        return  t_m::TemplateMatching::GaussianSimilarityWeighted3x3_5( i_trailerTemplate, i_warpedTopview, i_x, 0, factor, othsuthresh );
    }
    /**
    * Update the dynamic template.
    */
    bool_t TrailerTracking::_UpdateDynamicTemplate_1( image::Image<uint8_t>& i_bestRoi, uint16_t othsuthresh )
    {
#ifdef DIAGNOSTICS
        diag::start( "_UpdateDynamicTemplate" );
#endif
        uint8_t data[global::TEMPLATE_IMAGE_SIZE];
        memset( reinterpret_cast<uint8_t*>( data ), 0, sizeof( uint8_t ) * global::TEMPLATE_IMAGE_SIZE );
        image::Image<uint8_t> newTemplate = image::Image<uint8_t>( m_dynamicTrailerTemplate.getWidth(), m_dynamicTrailerTemplate.getHeight(), data, 1 );
        uint8_t* roi_ptr[25];
        int32_t roi_step = newTemplate.getStep();
        uint8_t* roi_row = m_baseTrailerTemplate.getData() + roi_step + roi_step + roi_step + 3;//PRQA S 3705

        for( uint32_t y = 3; y < ( m_dynamicTrailerTemplate.getHeight() - 3 ); y++ )
        {
            roi_ptr[0] = roi_row - roi_step - roi_step - 2;   //PRQA S 3705
            roi_ptr[1] = roi_row - roi_step - roi_step - 1;   //PRQA S 3705
            roi_ptr[2] = roi_row - roi_step - roi_step;       //PRQA S 3705
            roi_ptr[3] = roi_row - roi_step - roi_step + 1;   //PRQA S 3705
            roi_ptr[4] = roi_row - roi_step - roi_step + 2;   //PRQA S 3705
            roi_ptr[5] = roi_row - roi_step - 2;  //PRQA S 3705
            roi_ptr[6] = roi_row - roi_step - 1;  //PRQA S 3705
            roi_ptr[7] = roi_row - roi_step;      //PRQA S 3705
            roi_ptr[8] = roi_row - roi_step + 1;  //PRQA S 3705
            roi_ptr[9] = roi_row - roi_step + 2;  //PRQA S 3705
            roi_ptr[10] = roi_row - 2;            //PRQA S 3705
            roi_ptr[11] = roi_row - 1;            //PRQA S 3705
            roi_ptr[12] = roi_row;
            roi_ptr[13] = roi_row + 1;            //PRQA S 3705
            roi_ptr[14] = roi_row + 2;            //PRQA S 3705
            roi_ptr[15] = roi_row + roi_step - 2; //PRQA S 3705
            roi_ptr[16] = roi_row + roi_step - 1; //PRQA S 3705
            roi_ptr[17] = roi_row + roi_step;     //PRQA S 3705
            roi_ptr[18] = roi_row + roi_step + 1; //PRQA S 3705
            roi_ptr[19] = roi_row + roi_step + 2; //PRQA S 3705
            roi_ptr[20] = roi_row + roi_step + roi_step - 2;  //PRQA S 3705
            roi_ptr[21] = roi_row + roi_step + roi_step - 1;  //PRQA S 3705
            roi_ptr[22] = roi_row + roi_step + roi_step;      //PRQA S 3705
            roi_ptr[23] = roi_row + roi_step + roi_step + 1;  //PRQA S 3705
            roi_ptr[24] = roi_row + roi_step + roi_step + 2;  //PRQA S 3705

            for( uint32_t x = 3; x < ( m_dynamicTrailerTemplate.getWidth() - 6 ); x++ )
            {
                if( *roi_ptr[0] > 0 || *roi_ptr[1] > 0 || *roi_ptr[2] > 0 || *roi_ptr[3] > 0 || *roi_ptr[4] > 0 || *roi_ptr[5] > 0 || *roi_ptr[6] > 0
                    || *roi_ptr[7] > 0 || *roi_ptr[8] > 0 || *roi_ptr[7] > 0 || *roi_ptr[8] > 0 || *roi_ptr[9] > 0 || *roi_ptr[10] > 0
                    || *roi_ptr[11] > 0 || *roi_ptr[12] > 0 || *roi_ptr[13] > 0 || *roi_ptr[14] > 0 || *roi_ptr[15] > 0 || *roi_ptr[16] > 0
                    || *roi_ptr[17] > 0 || *roi_ptr[18] > 0 || *roi_ptr[19] > 0 || *roi_ptr[20] > 0 || *roi_ptr[21] > 0 || *roi_ptr[22] > 0
                    || *roi_ptr[23] > 0 || *roi_ptr[24] > 0 )
                {
                    if( *i_bestRoi.at( x, y ) > othsuthresh )
                    {
                        *newTemplate.at( x, y ) = 255;
                    }
                }

                ++roi_ptr[0];
                ++roi_ptr[1];
                ++roi_ptr[2];
                ++roi_ptr[3];
                ++roi_ptr[4];
                ++roi_ptr[5];
                ++roi_ptr[6];
                ++roi_ptr[7];
                ++roi_ptr[8];
                ++roi_ptr[9];
                ++roi_ptr[10];
                ++roi_ptr[11];
                ++roi_ptr[12];
                ++roi_ptr[13];
                ++roi_ptr[14];
                ++roi_ptr[15];
                ++roi_ptr[16];
                ++roi_ptr[17];
                ++roi_ptr[18];
                ++roi_ptr[19];
                ++roi_ptr[20];
                ++roi_ptr[21];
                ++roi_ptr[22];
                ++roi_ptr[23];
                ++roi_ptr[24];
            }

            roi_row += roi_step;
        }

        bool_t templateUpdated = false;
        uint32_t newTemplateNumPixels = _CountPixels( newTemplate );

        if( ( static_cast<float32_t>( newTemplateNumPixels ) > trailer::c_dynTempMinPixelAmount ) || ( newTemplateNumPixels > m_dynamicTemplateNumPixels ) )
        {
            processing::ImageProcessing::Copy( newTemplate, m_dynamicTrailerTemplate );
            templateUpdated = true;
            m_angleTemplateLastUpdated_deg = m_curTrailerAngle_deg;
            m_dynamicTemplateNumPixels = newTemplateNumPixels;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
        return templateUpdated;
    }
    /**
    * Update the dynamic template.
    */
    bool_t TrailerTracking::_UpdateDynamicTemplate( image::Image<uint8_t>& i_bestRoi )
    {
#ifdef DIAGNOSTICS
        diag::start( "_UpdateDynamicTemplate" );
#endif
        uint8_t data[global::TEMPLATE_IMAGE_SIZE];
        memset( reinterpret_cast<uint8_t*>( data ), 0, sizeof( uint8_t ) * global::TEMPLATE_IMAGE_SIZE );
        image::Image<uint8_t> newTemplate = image::Image<uint8_t>( m_dynamicTrailerTemplate.getWidth(), m_dynamicTrailerTemplate.getHeight(), data, 1 );
        // --- Create new template around previous template
        int32_t tmp_step = m_dynamicTrailerTemplate.getStep();
        int32_t roi_step = newTemplate.getStep();
        uint8_t* tmp_ptr;
        uint8_t* tmp_row = m_dynamicTrailerTemplate.getData() + tmp_step + 1;//PRQA S 3705
        uint8_t* roi_ptr[9];
        uint8_t* roi_row = i_bestRoi.getData() + roi_step + 1;//PRQA S 3705

        for( uint32_t y = 1; y < ( m_dynamicTrailerTemplate.getHeight() - 1 ); y++ )
        {
            tmp_ptr = tmp_row;
            roi_ptr[0] = roi_row - roi_step - 1;//PRQA S 3705
            roi_ptr[1] = roi_row - roi_step;//PRQA S 3705
            roi_ptr[2] = roi_row - roi_step + 1;//PRQA S 3705
            roi_ptr[3] = roi_row - 1;//PRQA S 3705
            roi_ptr[4] = roi_row;
            roi_ptr[5] = roi_row + 1;//PRQA S 3705
            roi_ptr[6] = roi_row + roi_step - 1;//PRQA S 3705
            roi_ptr[7] = roi_row + roi_step;//PRQA S 3705
            roi_ptr[8] = roi_row + roi_step + 1;//PRQA S 3705

            for( uint32_t x = 1; x < ( m_dynamicTrailerTemplate.getWidth() - 1 ); x++ )
            {
                if( *tmp_ptr > 0 )
                {
                    if( *roi_ptr[0] > 0 )
                    {
                        *newTemplate.at( x - 1, y - 1 ) = 255;
                    }

                    if( *roi_ptr[1] > 0 )
                    {
                        *newTemplate.at( x, y - 1 ) = 255;
                    }

                    if( *roi_ptr[2] > 0 )
                    {
                        *newTemplate.at( x + 1, y - 1 ) = 255;
                    }

                    if( *roi_ptr[3] > 0 )
                    {
                        *newTemplate.at( x - 1, y ) = 255;
                    }

                    if( *roi_ptr[4] > 0 )
                    {
                        *newTemplate.at( x, y ) = 255;
                    }

                    if( *roi_ptr[5] > 0 )
                    {
                        *newTemplate.at( x + 1, y ) = 255;
                    }

                    if( *roi_ptr[6] > 0 )
                    {
                        *newTemplate.at( x - 1, y + 1 ) = 255;
                    }

                    if( *roi_ptr[7] > 0 )
                    {
                        *newTemplate.at( x, y + 1 ) = 255;
                    }

                    if( *roi_ptr[8] > 0 )
                    {
                        *newTemplate.at( x + 1, y + 1 ) = 255;
                    }
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

        bool_t templateUpdated = false;
        uint32_t newTemplateNumPixels = _CountPixels( newTemplate );

        if( ( static_cast<float32_t>( newTemplateNumPixels ) > trailer::c_dynTempMinPixelAmount ) || ( newTemplateNumPixels > m_dynamicTemplateNumPixels ) )
        {
            processing::ImageProcessing::Copy( newTemplate, m_dynamicTrailerTemplate );
            templateUpdated = true;
            m_angleTemplateLastUpdated_deg = m_curTrailerAngle_deg;
            m_dynamicTemplateNumPixels = newTemplateNumPixels;
        }

#ifdef DIAGNOSTICS
        diag::stop();
#endif
        return templateUpdated;
    }
    /*
    * get the dynamic template
    */
    image::Image<uint8_t> TrailerTracking::_Getdynamictemplate()
    {
        return m_dynamicTrailerTemplate;
    }

    /*
    * Count the number of non-zero pixels in the given image.
    */
    uint32_t TrailerTracking::_CountPixels( image::Image<uint8_t>& i_image )
    {
        image::Image<uint8_t>::iterator img_end = i_image.end();
        uint32_t count = 0;

        for( image::Image<uint8_t>::iterator img_it = i_image.begin(); img_it < img_end; ++img_it ) // PRQA S 4244
        {
            if( *img_it > 0 )
            {
                count++;
            }
        }

        return count;
    }
}
