// ----------------------------------------------------------------------------
// --- Written by Pune Team [2019]
// --- Last Modified by Joshua Teichroeb [08-Jul-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TRAILER_PRESENCE_DETECTION__H_
#define __TRAILER_PRESENCE_DETECTION__H_

#ifdef __QNX__
    #include "../common/Image.h"
    #include "../common/config.h"
#else
    #include "common/Image.h"
    #include "common/config.h"
#endif
#include "VehicleKinematics.h"
#include "PreProcessing.h"
#include "ImageThresholding.h"
#include "FeatureExtraction.h"

#ifdef _WIN32
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#endif // _WIN32
#include "OpticalFlow.h"

#define PI      (3.1415926535897)

namespace TrailerPresence
{
    /*
    * Trailer presence detection module.
    */
    class TrailerPresenceDetection
    {
    public:
        TrailerPresenceDetection( TAD2::PreProcessing* i_preProcessing, TAD2::VehicleKinematics* i_kinematic );
        ~TrailerPresenceDetection();

        // --- Exposed functions
        bool_t Init( tad2config::TrailerPresenceDetectionConfigData i_config, const TAD2::WarpedTopViewParameters i_warpedTopViewParams_st );
        bool_t Start();
        void Finish();

        void Run( uint32_t i_frame, image::Image<uint8_t>& i_topView, Point2i hitch_point, _roi::ROI& i_roi );


        // --- Getters
        bool_t IsComplete() const;
        bool_t IsTrailerPresent() const;

        //
        bool_t FeaturePointDetection( image::Image<uint8_t> i_image, _roi::ROI& i_roi );
        OpticalFlow m_opt;

    private:
        // --- Top-level modules required by this state
        TAD2::PreProcessing* m_pPreProcessing;
        TAD2::VehicleKinematics* m_pVehicle;        


        bool_t m_initOK;
        bool_t m_isRunning;
        uint32_t m_lastFrameRun;
        int32_t Point_X;                                                                                            // Top left point of ROI in x
        int32_t Point_Y;                                                                                            // Top left point of ROI in y

        // --- Module specific variables
        TAD2::WarpedTopViewParameters warpedTopViewParams_st;


        bool_t b_DetectionDone;                                     // Trailer Absence Presence Detection Flag
        bool_t b_trailerPresent;                                    // Trailer present or not
        bool_t m_InitialPointsDetected;
        float32_t m_InitialDistanceTravelled;

        uint32_t features_prev_size = 0;
        Point2f features_prev[NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID];
        bool_t PointValid[NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID];
        uint32_t feature_next_size = 0;
        Point2f* features_next;
        uint8_t* status;
        float* err;
        image::Image<uint8_t> prev_gray_img;

        // funtions

        static uint32_t find_avg_img( image::Image<uint8_t> input_image );
        static uint16_t find_mag_avg_img( image::Image<uint16_t> input_image );
        static float32_t find_std_img( image::Image<uint8_t> input_image );
        void GradientOrientationDetection( image::Image<uint8_t> i_image, image::Image<uint16_t> o_gradMag, image::Image<uint8_t> o_gradDir );
        bool_t FeaturePointTracking( image::Image<uint8_t> i_image, _roi::ROI& i_roi );
        float32_t find_std_Points( float32_t i_points[0] );
        void ClusterFiltering();
        uint32_t FindGap();
        float32_t EuclideanDistance( Point2f P1, Point2f P2 );

    };
}
#endif // !__TRAILER_PRESENCE_DETECTION__H_

