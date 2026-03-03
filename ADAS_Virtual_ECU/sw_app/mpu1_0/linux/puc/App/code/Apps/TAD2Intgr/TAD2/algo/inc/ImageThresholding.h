// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [05-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __IMAGE_THRESHOLDING__H_
#define __IMAGE_THRESHOLDING__H_

#ifdef __QNX__
    #include "../common/Image.h"
#else
    #include "common/Image.h"
#endif

/*
* Image thresholding module used to find the thresholds for Canny edge detection for
* each individual pixel.
*/
namespace TAD2
{
    class ImageThresholding
    {
    public:
        ImageThresholding();
        ~ImageThresholding();

        // --- Exposed functions
        bool_t Init();
        bool_t Start();
        void Finish();
        uint16_t _getotsuthresh()const;
        void _setotsuthresh( uint16_t val )
        {
            hitch_thresh_low = val;
        }
        void Run( int32_t i_frame, image::Image<uint8_t>& i_topView, _roi::ROI& i_roi, Point2i i_hitchPoint, float32_t i_trailerAngle, bool_t i_trailerAngleValid

                  , image::Image<uint16_t>& o_lowThresh, image::Image<uint16_t>& o_highThresh
                  , image::Image<uint16_t>& o_gradMag, image::Image<uint8_t>& o_gradDir, bool_t highedge, bool_t i_warpedimage );
        image::Image<uint16_t>& GetLowThreshold();
        image::Image<uint16_t>& GetHighThreshold();
        void setlastframe( uint32_t frame_no );
    private:
        bool_t m_initOK;
        bool_t m_isRunning;
        int32_t m_lastFrameRun;

        // --- Constants
        uint32_t c_roiRadius;
        uint32_t c_roiWidth;
        uint32_t c_roiHeight;
        uint32_t c_blurWidth;
        uint32_t c_blurHeight;
        uint16_t hitch_thresh_low;
        uint16_t hitch_thresh_high;

        image::Image<uint16_t> m_lowThresh;
        image::Image<uint16_t> m_highThresh;
        // --- Private functions
        static _roi::ROI _CreateROIAtOffset( _roi::ROI& i_boundingROI, Point2i i_centre, float32_t i_angle, float32_t i_radius, uint32_t i_roiWidth, uint32_t i_roiHeight );
        static void _CalculateRoiThresholds( image::Image<uint16_t>& i_image, uint16_t& o_thresh_low, uint16_t& o_thresh_high, bool_t highedge );
        static void _OtsuDoubleThreshold( image::Image<uint16_t>& i_image, uint16_t& o_thresh_low, uint16_t& o_thresh_high );
        static void _OtsuSingleThreshold( image::Image<uint16_t>& i_image, uint16_t& o_thresh );
        static void _CreateThresholdImages( image::Image<uint8_t>& i_topView, uint32_t i_subWidth, uint32_t i_subHeight, float32_t i_roiMean, uint16_t roi_thresh_low, uint16_t roi_thresh_high, image::Image<uint16_t>& o_thresh_low, image::Image<uint16_t>& o_thresh_high );
        void _CreateThresholdImages_Opt( image::Image<uint8_t>& i_topView, uint32_t i_subWidth, uint32_t i_subHeight, float32_t i_roiMean, uint16_t roi_thresh_low, uint16_t roi_thresh_high, image::Image<uint16_t>& o_thresh_low, image::Image<uint16_t>& o_thresh_high );

    };
}
#endif // !__IMAGE_THRESHOLDING__H_
