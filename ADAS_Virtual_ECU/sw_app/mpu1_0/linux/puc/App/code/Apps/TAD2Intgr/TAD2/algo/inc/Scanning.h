// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __SCANNING_H
#define __SCANNING_H

#ifdef __QNX__
    #include "../common/TemplateMatching.h"
    #include "../common/TemplateWeightMask.h"
    #include "../common/TADStructures.h"
    #include "../common/Defines.h"
#else
    #include "common/TemplateMatching.h"
    #include "common/TADStructures.h"
    #include "common/Defines.h"
#endif
#include "PreProcessing.h"

namespace Scan
{
    typedef struct detectedEllipseBoundary_s
    {
        static const uint32_t BufferSize = 2000;
        Point2i col[BufferSize];
        bool_t flag[BufferSize];
        uint16_t col_size = 0 ;
        uint16_t front()
        {
            uint16_t returnIndex = 0;

            for( uint16_t index = 0; index < col_size; index++ )
            {
                if( flag[index] == true )
                {
                    flag[index] = false;
                    //col_size--;
                    returnIndex = index;
                    break;
                }
            }

            return returnIndex;
        };
    } detectedEllipseBoundary_t;
    /*
    * Scanning module.
    *
    * Scans the warped topview to find the angle of the trailer when it was previously unknown.
    */
    class Scanning : public t_m::TemplateMatching
    {
    public:
        Scanning();
        ~Scanning();

        // --- Exposed functions
        bool_t Init( const TAD2::WarpedTopViewParameters& i_warpedTopviewParams, TAD2::PreProcessing* i_pPreProcessing );
        bool_t Start( TAD2::TrailerTemplate i_trailerTemplate );
        void Finish();

        void Run( uint32_t i_frame, TAD2::WarpedImage<uint8_t>& i_warpedTopview, uint16_t othsu_thresh, float32_t i_averageIllumination );

        uint8_t LabelComponent( image::Image<uint8_t>* strInputImage, image::Image<uint8_t>*  strLabelImage, const _roi::ROI r1, image::Image<bool_t>* is_labeled, bool_t templateprocess );
        uint8_t ROILabelComponent( image::Image<uint8_t>* dilatedImage, image::Image<uint8_t>* strInputImage, image::Image<uint8_t>*  strLabelImage, const _roi::ROI r1, image::Image<bool_t>* is_labeled, bool_t templateprocess, float32_t& zeroEdgecount, float32_t TemplateEdgeCount, uint16_t othsu_thresh );

        // --- Getters
        bool_t IsTrailerAngleFound()const;
        float32_t GetTrailerAngle()const;
        bool_t IsScanningComplete()const;
        float32_t GetScore()const;

    private:
        bool_t m_initOK;
        bool_t m_isRunning;
        uint32_t m_lastFrameRun;

        TAD2::PreProcessing* m_pPreProcessing;

        // --- Constants
        static const uint32_t c_numFullScans = 5;
        uint32_t c_scanInc;

        // --- Module specific varaibles
        TAD2::WarpedTopViewParameters m_warpedTopviewParams;
        TAD2::TrailerTemplate m_trailerTemplate;
        TAD2::TrailerTemplate m_DilatedtrailerTemplate;
        image::Image<uint8_t> LabelImage;
        image::Image<bool_t> islabeledImage;

        float32_t m_scores[c_numFullScans][global::WARPED_TOPVIEW_IMAGE_WIDTH];
        uint32_t m_curScan;
        uint32_t m_curOffset;
        bool_t m_scanningComplete;
        bool_t m_initial_pos_found;
        uint32_t initial_start_Pos;
        uint32_t final_end_Pos;
        float32_t TemplateCount;
        uint32_t ScanInd;
        _roi::ROI ImageROI;

        float32_t m_bestTrailerAngle;
        float32_t m_scanningScore;
        bool_t m_trailerAngleFound;

        // --- Private functions
        float32_t _CalculateTrailerAngle();
        static void CreateDistImage( image::Image<uint8_t>& i_image, image::Image<uint32_t>& o_distImage );
        static float32_t SimilarityUsingDistImage( image::Image<uint8_t>& i_template, image::Image<uint32_t>& i_distImage, int32_t i_x, int32_t i_y );
        void find_initial_trailer_pos();
        void _ROI3x3_3UP( image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView, float32_t& template_count );
        void _ROI3x3_5UP( image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView, float32_t& template_count );
        void _ROI3x3_7UP( image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView, float32_t& template_count );
        void _ROI3x3_9UP( image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView, float32_t& template_count );
        void _ROI3x3( image::Image<uint8_t>& i_topView, image::Image<uint8_t>& o_topView, float32_t& template_count );
        void _ROI5x5( const image::Image<uint8_t> i_topView, image::Image<uint8_t>& o_topView, float32_t& template_count );
        float32_t CountPixel( image::Image<uint8_t>& i_image );

    };
}
#endif // !__SCANNING_H
