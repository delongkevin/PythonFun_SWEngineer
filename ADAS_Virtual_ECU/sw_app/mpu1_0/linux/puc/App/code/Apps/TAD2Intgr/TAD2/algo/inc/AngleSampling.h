// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Jun-2019]
// --- Last Modified by Joshua Teichroeb [06-Jun-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __ANGLE_SAMPLING__H_
#define __ANGLE_SAMPLING__H_

#ifdef __QNX__
    #include "../common/Image.h"
    #include "../common/EqualSeparationLinkedList.h"
    #include "../common/TemplateMatching.h"
#else
    #include "common/Image.h"
    #include "common/EqualSeparationLinkedList.h"
    #include "common/templateMatching.h"
#endif
#include "TrailerAngleCalibration.h"
#include "PreProcessing.h"
#include "VehicleKinematics.h"

namespace sampling
{
    /*
    * Node used to store an angle sample.
    */
    class ImageNode : public LL::LinkedListNode
    {
    public:
        ImageNode() : LL::LinkedListNode()
        {
        }

        inline float32_t getMinAngle_deg() const
        {
            return minAngle_deg;
        };
        inline float32_t getDummy_Angle() const
        {
            return dummy_angle;
        };
        inline float32_t getDummy_Confidence1() const
        {
            return confidence1;
        };
        inline float32_t getDummy_Confidence2() const
        {
            return confidence2;
        };
        inline float32_t getDummy_Confidence3() const
        {
            return confidence3;
        };
        inline float32_t getDummy_Confidence4() const
        {
            return confidence4;
        };
        inline uint16_t getOtsu_Thresh() const
        {
            return otsu_thresh;
        };
        inline image::Image<uint8_t> getAngleImg() const
        {
            return angleImg;
        };
        inline struct ImageNode* getNext() const
        {
            return next;
        };
        inline struct ImageNode* getPrev() const
        {
            return prev;
        };
        inline void setMinAngle_deg( float32_t angle )
        {
            minAngle_deg = angle;
        };
        inline void setDummy_Angle( float32_t angle )
        {
            dummy_angle = angle;
        };
        inline void setOtsu_Thresh( uint16_t thresh )
        {
            otsu_thresh = thresh;
        };
        inline void setAngleImage( image::Image<uint8_t> aImage )
        {
            angleImg = aImage;
        };
        inline void setNext( struct ImageNode* nextNode )
        {
            next = nextNode;
        };
        inline void setPrev( struct ImageNode* prevNode )
        {
            prev = prevNode;
        };
    private:
        float32_t minAngle_deg;
        float32_t dummy_angle;
        uint16_t otsu_thresh;
        float32_t confidence1;
        float32_t confidence2;
        float32_t confidence3;
        float32_t confidence4;
        image::Image<uint8_t> angleImg;
        struct ImageNode* next;
        struct ImageNode* prev;
    };


    /*
    * Angle sampling module used for hitch detection.
    */
    class AngleSampling
    {
    public:
        // --- Constants
        static const uint32_t c_numImages = 9;
        static const uint32_t c_largestAngleThresh_deg = 25;
        static const uint32_t c_waitTimeToFinish = 30 * 5;
        static const uint32_t c_debugPanelNameLength = 260;

        // --- Constructor / Destructor
        AngleSampling();
        ~AngleSampling();

        // --- Exposed functions
        bool_t Init( const TAD2::VehicleParameters& i_vehicleParams, const TAD2::PreProcessing* i_pPreProcessing, const float32_t i_trailerBeamLengthRange[2], uint32_t hitch_xpos, uint32_t i_hitch_start, uint32_t i_hitch_stop, uint32_t i_hitch_diff );
        bool_t Start();
        void Finish();

        void Run( uint32_t i_frame, image::Image<uint8_t>& i_edges, const TAD2::VehicleKinematics* i_pVehicle, uint16_t i_otsu_thresh, float32_t i_dummy_angle, image::Image<uint8_t> dynamic_img_1, image::Image<uint8_t> dynamic_img_2, image::Image<uint8_t> dynamic_img_3, image::Image<uint8_t> dynamic_img_4, image::Image<uint8_t>& i_trailerTemplate, uint32_t& hitch_range, bool_t kinematic_ON );

        // -- Getters
        bool_t IsComplete()const;
        bool_t IsLeftSide()const;
        void GetSampleImages( image::Image<uint8_t> o_angleImages[c_numImages] );
        float32_t GetCalibrationAngle() const;
        const uint16_t* GetThresholdVal() ;
        const float32_t* GetDummyAngle() ;
        const float32_t* GetDummyConfidence1();
        const float32_t* GetDummyConfidence2();
        const float32_t* GetDummyConfidence3();
        const float32_t* GetDummyConfidence4();
        uint8_t GetHitchPos()  const;
        uint32_t GetRangeDiff() const;
        // -- Setters
        void Set_Dummy_angles( float32_t angle_1, float32_t angle_2, float32_t angle_3, float32_t angle_4 );

    private:


        bool_t m_initOK;
        bool_t m_isRunning;
        uint32_t m_lastFrameRun;

        // --- Module specific variables
        LL::EqualSeparationLinkedList<ImageNode, c_numImages> m_angleImgList;
        float32_t m_largestAngle_deg;
        float32_t m_prevAngleSet_deg;
        float32_t m_curAngleDif_deg;
        uint32_t m_hitch_Xpos;
        uint32_t m_hitch_start_pos;
        uint32_t m_hitch_stop_pos;
        uint32_t m_hitch_diff;
        uint32_t m_curWaitTime;
        bool_t m_bAngleRangeReached;
        bool_t m_bTakingLeftSide;
        float32_t scores[4][2];
        uint8_t hitch_range_pos;
        uint16_t thresh[9];
        float32_t Dummy_angle[9];
        float32_t Dummy_Confidence1[9];
        float32_t Dummy_Confidence2[9];
        float32_t Dummy_Confidence3[9];
        float32_t Dummy_Confidence4[9];

        TAD2::TrailerCalibrationModel m_biasTrailerModel;
        TAD2::TrailerCalibrationModel m_avgTrailerModel;
        const TAD2::PreProcessing* m_pPreProcessing;

        // -- Dummy angles
        float32_t dummy_angle[4];

        // --- Debugging
#ifdef DIAGNOSTICS
        char m_debugWindowName1[c_debugPanelNameLength] = "(HD-1) Angle Images";
#endif

        // --- Private functions
        void ReleaseImages();
        void hitch_range_finder( image::Image<uint8_t>& i_trailerTemplate, image::Image<uint8_t> dynamic_img_1, image::Image<uint8_t> dynamic_img_2, image::Image<uint8_t> dynamic_img_3, image::Image<uint8_t> dynamic_img_4, uint32_t& hitch_range, uint16_t i_otsu_thresh );
    };
}

#ifdef __QNX__
    #include "../common/EqualSeparationLinkedList.hpp"
#else
    #include "common/EqualSeparationLinkedList.hpp"
#endif

#endif // !__ANGLE_SAMPLING__H_
