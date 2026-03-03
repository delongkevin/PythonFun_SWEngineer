// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Jun-2019]
// --- Last Modified by Joshua Teichroeb [06-Jun-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __HITCH_DETECTION__H_
#define __HITCH_DETECTION__H_

#ifdef __QNX__
    #include "../common/Image.h"
    #include "../common/config.h"
#else
    #include "common/Image.h"
    #include "common/config.h"
#endif
#include "AngleSampling.h"
#include "PreProcessing.h"

/*
* Hitch detection module.
*/
namespace Hitch
{
    class HitchDetection
    {
    public:
        HitchDetection();
        ~HitchDetection();

        // --- Exposed functions
        bool_t Init( tad2config::HitchDetectionConfigData i_config, const TAD2::PreProcessing* i_pPreProcessing, uint32_t hitch_X_Pos, const uint32_t i_hitchYRange[2] );
        bool_t Start( image::Image<uint8_t>& i_trailerCalibration, const image::Image<uint8_t> i_angleImages[sampling::AngleSampling::c_numImages], bool_t i_leftSide, const uint16_t thresh[sampling::AngleSampling::c_numImages], const float32_t dummy_angle[sampling::AngleSampling::c_numImages], uint32_t i_hitch_range, uint32_t hitch_range_diff, uint8_t hitchrange_pos );
        void Finish();

        void Run( uint32_t i_frame );
        // --- Getters
        Point2i GetHitchPoint()const;
        Point2i GetROICentrePoint()const;
        bool_t IsHitchPointFound()const;
        bool_t IsHitchRangeFound()const;
        void SethitchPoint( Point2i hitchDetected );

    private:

        const TAD2::PreProcessing* m_pPreProcessing;

        bool_t m_initOK;
        bool_t m_isRunning;
        uint32_t m_lastFrameRun;
        uint8_t hitch_range_pos;

        // --- Constants
        uint32_t c_minHitchY;
        uint32_t c_maxHitchY;
        static const uint32_t c_maxHitchYRange = global::TOPVIEW_IMAGE_HEIGHT;
        static const uint32_t c_templateWidth = global::TEMPLATE_IMAGE_WIDTH;
        static const uint32_t c_templateHeight = global::TEMPLATE_IMAGE_HEIGHT;
        static const uint32_t c_scanLengthPerFrame = 200;
        static const uint32_t c_numImages = sampling::AngleSampling::c_numImages;
        static const uint32_t c_debugPanelNameLength = 260;

        // --- Module specific variables
        bool_t m_hitchrangefound;
        bool_t m_hitchCalibrated;
        bool_t m_bLeftSide;
        uint32_t m_hitchXPos;
        Point2i m_calibratedHitchPoint;
        image::Image<uint8_t> m_calibration_u8;
        image::Image<uint8_t> m_angleImages[c_numImages];
        image::Image<uint8_t> m_Confidence1[c_numImages];
        image::Image<uint8_t> m_Confidence2[c_numImages];
        image::Image<uint8_t> m_Confidnece3[c_numImages];
        image::Image<uint8_t> m_Confidence4[c_numImages];
        image::Image<uint8_t> m_hitchROIImages[c_numImages];

        float32_t m_matchingScores[c_maxHitchYRange];
        float32_t m_hitchscores[c_maxHitchYRange];
        float32_t m_angleScores[c_maxHitchYRange];
        uint32_t m_curY;
        uint32_t m_curX;
        uint32_t m_curImgInd;
        uint32_t m_curBestX;
        float32_t m_curBestScore;
        TAD2::WarpedImage<uint8_t> m_curWarpedCalibrationImg;
        TAD2::WarpedImage<uint8_t> m_curWarpedAngleImg;
        uint32_t half_hitch_range;
        image::Image<uint8_t> m_curCalibratedTrailerTemplate;
        uint16_t current_othsuthresh;
        uint16_t otsu_thresh[9];
        float32_t Dummy_angle[9];
        // --- Debugging
        bool_t m_isDebugging;
        char m_debugWindowName1[c_debugPanelNameLength] = "(HD-3) Warped Angle Images";
        char m_debugWindowName2[c_debugPanelNameLength] = "(HD-3) Template Matching";
        char m_debugWindowName3[c_debugPanelNameLength] = "(HD-3) Scanning Scores";
        float32_t m_matchingScores2[c_maxHitchYRange][c_numImages];
        float32_t m_matchinghitchrangescores[c_maxHitchYRange][c_numImages];
        float32_t m_angleScores2[c_maxHitchYRange][c_numImages];

        // --- Helper functions
        void CalculateBestHitchPoint();
#ifndef DIAGNOSTICS
        static uint32_t ScanImage( image::Image<uint8_t>& i_warpedImage, image::Image<uint8_t>& i_template, uint32_t i_start_x, uint32_t i_end_x, float32_t* o_score, uint16_t othsuthresh );
#else
        uint32_t ScanImage( image::Image<uint8_t>& i_warpedImage, image::Image<uint8_t>& i_template, uint32_t i_start_x, uint32_t i_end_x, float32_t* o_score, uint16_t othsuthresh );
#endif

        static void CreateDistImage( image::Image<uint8_t>& i_image, image::Image<uint32_t>& o_distImage );
#ifndef DIAGNOSTICS
        static uint32_t ScanUsingDistImage( image::Image<uint32_t>& i_distImage, image::Image<uint8_t>& i_template, uint32_t i_start_x, uint32_t i_end_x, float32_t* o_score );
#else
        uint32_t ScanUsingDistImage( image::Image<uint32_t>& i_distImage, image::Image<uint8_t>& i_template, uint32_t i_start_x, uint32_t i_end_x, float32_t* o_score );
#endif
        static void OutputScoresToFile();
    };
}

#endif // !__HITCH_DETECTION__H_
