// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [05-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TAD2_FEATURE_EXTRACTION__H_
#define __TAD2_FEATURE_EXTRACTION__H_

#ifdef __QNX__
    #include "../common/Image.h"
#else
    #include "common/Image.h"
#endif
namespace TAD2
{
    /*
    * Feature extraction module used to extract edges from the topview.
    */
    class FeatureExtraction
    {
    public:
        /** Feature struct. (Not used.) **/
        struct Feature
        {
            bool_t isEdge;
            uint16_t edgeStrength;
            uint8_t edgeDirection;
            uint8_t rawPixelValue;
        };

        FeatureExtraction();
        ~FeatureExtraction();

        // --- Exposed functions
        bool_t Init();
        bool_t Start();
        void Finish();

        void Run( int32_t i_frame, image::Image<uint8_t>& i_topView, image::Image<uint16_t> i_lowThresh, image::Image<uint16_t> i_highThresh, _roi::ROI& i_roi, image::Image<uint16_t>& o_gradMag, image::Image<uint8_t>& o_gradDir );
        void ExtractAllFeatures( image::Image<uint8_t>& i_topView, image::Image<uint8_t>& i_edges )const;
        void setlastframe( uint32_t frame_no );

        // --- Getters
        image::Image<uint8_t>& GetEdges();
        image::Image<Feature>& GetFeatureImage();

    private:
        bool_t m_initOK;
        bool_t m_isRunning;
        int32_t m_lastFrameRun;

        // --- Module specific variables
        image::Image<uint8_t> m_edges;
        image::Image<Feature> m_features;

    };
}
#endif // !__TAD2_FEATURE_EXTRACTION__H_
