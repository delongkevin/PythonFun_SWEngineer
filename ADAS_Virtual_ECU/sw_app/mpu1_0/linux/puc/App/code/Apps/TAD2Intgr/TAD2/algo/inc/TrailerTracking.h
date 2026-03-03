// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TRAILER_TRACKING_H
#define __TRAILER_TRACKING_H

#ifdef __QNX__
    #include "../common/TADStructures.h"
    #include "../common/Image.h"
#else
    #include "common/TADStructures.h"
    #include "common/Image.h"
#endif

namespace trailer
{
    // --- Constants
    static const uint32_t c_steady_numTemplates = 9;
    static const int32_t c_steady_templateOffsets[c_steady_numTemplates] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };
    static const uint32_t c_dynamic_numTemplates = 21;
    static const int32_t c_dynamic_templateOffsets[c_dynamic_numTemplates] = { -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    static const float32_t c_minTemplateMatchingScore = 0.0f;
    static const float32_t c_minConfidenceLevel = 0.0f;
    static const float32_t c_angleOffsetToUpdateTemplate_deg = 5.0f;
    static const float32_t c_angleOffsetToResetTemplate_deg = 5.0f;
    static const float32_t c_dynTempMinPixelAmount = 100.0f;
}
namespace TAD2
{
    class TrailerTracking
    {
    public:
        TrailerTracking();
        ~TrailerTracking();

        // --- Exposed functions
        bool_t Init( const TAD2::WarpedTopViewParameters& i_warpedTopviewParams, float32_t i_templateMatchingWeightFactor );
        bool_t Start( TAD2::TrailerTemplate i_trailerTemplate, float32_t i_initialTrailerAngle );
        void Finish();

        void Run( uint32_t i_frame, TAD2::WarpedImage<uint8_t>& i_warpedTopview, uint16_t othsuthresh, bool_t dummy_angle_enabled, bool_t dynamci_window_enable );


        // --- Getters
        float32_t GetTrailerAngle() const;
        float32_t GetTrackingScore() const;

        // --- Setter
        void SetTrailerAngle( float32_t trailerAngle );
        void Set_IsDummy( bool_t dummy );
        image::Image<uint8_t> _Getdynamictemplate();
        void SetCurrentTrailerAngle( float32_t trailer_angle );



    private:
        bool_t m_initOK;
        bool_t m_isRunning;
        bool_t m_isDummy;
        uint32_t m_lastFrameRun;

        // --- Module specific variables
        TAD2::WarpedTopViewParameters m_warpedTopviewParams;
        TAD2::TrailerTemplate m_baseTrailerTemplate;
        TAD2::TrailerTemplate m_dynamicTrailerTemplate;
        uint32_t m_dynamicTemplateNumPixels;
        float32_t m_curDummyAngle_deg;
        float32_t m_curTrailerAngle_deg;
        uint32_t m_currentTrailerXPos;
        float32_t m_confidence;
        float32_t m_templateMatchingWeightFactor;
        float32_t m_prevTemplateMatchingScore;
        float32_t m_angleTemplateLastUpdated_deg;
        bool_t initial_dynamic_template_updated;
        uint32_t previous_slide_pos = 0;

        // --- Private functions
        float32_t _CalculateSimilarityScore( image::Image<uint8_t>& i_trailerTemplate, TAD2::WarpedImage<uint8_t>& i_warpedTopview, int32_t i_x ) const;
        float32_t _CalculateSimilarityScore_2( image::Image<uint8_t>& i_trailerTemplate, TAD2::WarpedImage<uint8_t>& i_warpedTopview, int32_t i_x, uint16_t othsuthresh ) const;
        bool_t _UpdateDynamicTemplate( image::Image<uint8_t>& i_bestRoi );
        bool_t _UpdateDynamicTemplate_1( image::Image<uint8_t>& i_bestRoi, uint16_t othsuthresh );
        void _update_initial_dynamic_template( TAD2::WarpedImage<uint8_t>& i_warpedTopview, uint16_t othsuthresh );
        bool_t _Update_Full_New_DynamicTemplate( image::Image<uint8_t>& i_bestRoi, uint16_t othsuthresh );
        static uint32_t _CountPixels( image::Image<uint8_t>& i_image );

    };
}
#endif // !__TRAILER_TRACKING_H
