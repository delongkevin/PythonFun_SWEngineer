// ----------------------------------------------------------------------------
// --- Written by Pune Team
// --- Last Modified by Joshua Teichroeb [23-Jul-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __COLLISION_ANGLE_DETECTION_H
#define __COLLISION_ANGLE_DETECTION_H

#ifdef __QNX__
    #include "../common/Image.h"
    #include "mecl/mecl.h"
    #include "../common/TADStructures.h"
#else
    #include "common/Image.h"
    #include "MECL/mecl.h"
    #include "common/TADStructures.h"
#endif

/*
* Collision angle detection module.
*
* Finds the approximate angle at which the trailer will collide with the vehicle.
*/
namespace cAngleDetection
{
    class CollisionAngleDetection
    {
    public:
        CollisionAngleDetection();
        ~CollisionAngleDetection();

        // --- Exposed functions
        bool_t Init( const TAD2::WarpedTopViewParameters& i_warpedTopviewParams );
        bool_t Start();
        void Finish();

        void Run( uint32_t i_frame, image::Image<uint8_t>& i_edges, uint16_t othsuthresh, Point2i hitch_point );

        // --- Getters
        bool_t IsRunning()const;
        bool_t IsCollisionAngleFound()const;
        float32_t GetCollisionAngle()const;
        float32_t GetLeftCollisionAngle()const;
        float32_t GetRightCollisionAngle()const;

    private:
        bool_t m_initOK;
        bool_t m_isRunning;
        uint32_t m_lastFrameRun;
        float32_t m_collisionangle;
        float32_t m_leftcollisionangle;
        float32_t m_rightcollisionangle;
        Point2i hitch_pos;
        bool_t collision_angle_estimatin_done;
        uint32_t nCountOfImage;
        uint32_t vertical_profile[640];
        TAD2::WarpedTopViewParameters m_warpedTopviewParams;

        TAD2::WarpedImage<uint8_t> final_edge_img;


        // --- Private functions
        static void add_image( image::Image<uint8_t>& inputArr, image::Image<uint8_t>& outputArr, uint16_t othsuthresh );
        static void binarization( image::Image<uint8_t>& outputArr, uint32_t thresh );
        void binarization_new( image::Image<uint8_t>& outputArr, uint32_t thresh )const;
        static void initializeBuffer( image::Image<uint8_t>& input_image, uint8_t val );
        static void max_value_in_a_image( image::Image<uint8_t>& inputArr, uint32_t& max_value );
        void vertical_edge_profile( image::Image<uint8_t> inputArr );
        float32_t find_collision_point();


    };
}


#endif // __COLLISION_ANGLE_DETECTION_H
