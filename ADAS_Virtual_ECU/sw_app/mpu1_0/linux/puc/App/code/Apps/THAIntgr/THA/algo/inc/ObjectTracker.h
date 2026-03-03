/// --------------------------------------------------------------------------
/// @file ObjectTracker.h
/// @brief Contains coupler tracker functionality
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Jignesh Vasoya (jignesh.vasoya@magna.com)
/// --------------------------------------------------------------------------
#ifndef OBJECT_TRACKER_H
#define OBJECT_TRACKER_H

#ifdef _WIN32
    #include "Point.h"
#else
    #include "meal/camera/core/inc/CameraPoint.h"
#endif // _WIN32

#include "../common/THAConfig.h"
#include "../common/THAParams.h"
#include "MatrixUtils.h"
#include "../Tracker/kcftrackerC.h"

namespace tha
{
    struct TrackedObjectInfo_s
    {
    private:
        /*
         *Tracked object info
         */
        Point2i m_TrkdPix_s32;
        Point3f m_TrkdObjLoc_f32; // Not updated currently

    public:
        void Init()
        {
            m_TrkdObjLoc_f32 = Point3f( 0.0f, 0.0f, 0.0f );
            m_TrkdPix_s32 = Point2i( 0, 0 );
        }

        Point2i getTrkdPix_s32() const
        {
            return m_TrkdPix_s32;
        }

        void setTrkdPix_s32( Point2i i_trkdPix_s32 )
        {
            m_TrkdPix_s32 = i_trkdPix_s32;
        }
    };

    class ObjectTracker
    {
    public:
        explicit ObjectTracker( const TrailerTrackCfg& i_config );
        ~ObjectTracker();

        TrackedObjectInfo_s m_pTrackedInfoObj; //PRQA S 2100
        KCFTrackerC m_kcfTrackerCObj; //PRQA S 2100

        /*
        * Tracker Functions
        */
        void Init();
        bool_t StartTrack( Point2i pixel );
        bool_t ResetTrack( Point2i pixel );
        void Close();
        void GetTrackedPoint( int32_t& i_TrkdPntX_s32, int32_t& i_TrkdPntY_s32 ) const;
        bool_t UpdateTrackedObjectInfo();
        bool_t ValidateInputPix( const Point2i i_Pix_s32 ) const;
        uint16_t getImgWidth() const;
        void setImgWidth( uint16_t i_ImgWidth_u16 );
        uint16_t getImgHeight() const;
        void setImgHeight( uint16_t i_ImgHeight_u16 );
        uint8_t* getInputImage() const;
        void setInputImage( uint8_t* i_InputImage_pu8 );

    private:
        mecl::core::Matrix<uint8_t, 400, 640, e_Default> m_Image;

        const TrailerTrackCfg& m_TrailerTrackConfig;

        /*
        * Tracker Parameters - Configurable
        */
        float32_t m_KCFMinPeakValue_f32;
        int32_t m_BlockWidth_s32;
        int32_t m_BlockHeight_s32;

        /*
        * Tracker Parameters
        */
        mecl::core::ArrayList <Recti, 2> m_RectTrace_s32;
        uint16_t m_ImgWidth_u16;
        uint16_t m_ImgHeight_u16;
        uint8_t* m_pInputImage_pu8;
    };
} // namespcae tha
#endif // ! OBJECT_TRACKER_H
