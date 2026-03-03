/// --------------------------------------------------------------------------
/// @file ObjectTracker.cpp
/// @brief Contains coupler tracker functionality
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Jignesh Vasoya (jignesh.vasoya@magna.com)
/// --------------------------------------------------------------------------

#include "ObjectTracker.h"

namespace tha
{
    ObjectTracker::ObjectTracker( const TrailerTrackCfg& i_config ) :
        m_kcfTrackerCObj(), m_TrailerTrackConfig( i_config )
    {
        /*
        * Tracker Parameters
        */
        m_ImgWidth_u16 = 640;
        m_ImgHeight_u16 = 400;
        m_pInputImage_pu8 = &m_Image( 0, 0 );
        m_BlockWidth_s32 = m_TrailerTrackConfig.getTrackBlockWidth();
        m_BlockHeight_s32 = m_TrailerTrackConfig.getTrackBlockHeight();
        m_KCFMinPeakValue_f32 = m_TrailerTrackConfig.getkcfMinPeakValue();
    }

    ObjectTracker::~ObjectTracker()
    {
        m_pInputImage_pu8 = NULL;
    }
    /*
    * Name: Init
    * Remarks: DD-ID: {A5378114-A017-40bf-A5D8-6402AD3C1308}
    * Remarks: DD-ID: {A9AE1C60-1F43-4023-A2C0-A688DC1C6603}
    */
    void ObjectTracker::Init()
    {
        /*
        * Init config parameters
        */
        m_ImgWidth_u16 = 640;
        m_ImgHeight_u16 = 400;
        m_pInputImage_pu8 = &m_Image( 0, 0 );
        m_BlockWidth_s32 = m_TrailerTrackConfig.getTrackBlockWidth();
        m_BlockHeight_s32 = m_TrailerTrackConfig.getTrackBlockHeight();
        m_KCFMinPeakValue_f32 = m_TrailerTrackConfig.getkcfMinPeakValue();
        m_RectTrace_s32.clear_v();
        m_pTrackedInfoObj.Init();
    }
    /*
    * Name: UpdateTrackedObjectInfo
    * Remarks: DD-ID: {FA3C775B-3027-4b75-9333-7752620FC750}
    * Remarks: DD-ID: {3B96EDB6-F432-45e5-8F4B-9691D37274E4}
    */
    bool_t ObjectTracker::UpdateTrackedObjectInfo()
    {
        bool_t v_trackSuccess_b = false;
        uint32_t v_currLastRectIndex_u32 = m_RectTrace_s32.size_u32() - 1;
        Point2i v_CurrTrackedPnt_s32;
        // Validate last tracked point
        Point2i v_PrevTrkdPnt_s32;
        v_PrevTrkdPnt_s32.x = ( m_RectTrace_s32[v_currLastRectIndex_u32].x + windowSize / 2 );
        v_PrevTrkdPnt_s32.y = ( m_RectTrace_s32[v_currLastRectIndex_u32].y + windowSize / 2 );
        bool_t IsPrevPntValid = ValidateInputPix( v_PrevTrkdPnt_s32 );

        if( IsPrevPntValid == true )
        {
            // Update the KCF tracker and get the new tracking window
            Recti v_RectPred_s32;
            m_kcfTrackerCObj.update_c( m_Image, v_RectPred_s32, m_TrailerTrackConfig.getkcfMinPeakValue() );

            if( m_kcfTrackerCObj.getPeakValue_c() > m_TrailerTrackConfig.getkcfMinPeakValue() )
            {
                if( m_RectTrace_s32.size_u32() == 2 )
                {
                    m_RectTrace_s32.clear_v();
                }

                m_RectTrace_s32.pushBack_v( v_RectPred_s32 );
                // Get the current KCF bounding box
                v_currLastRectIndex_u32 = m_RectTrace_s32.size_u32() - 1;
                v_CurrTrackedPnt_s32.x = ( m_RectTrace_s32[v_currLastRectIndex_u32].x + windowSize / 2 );
                v_CurrTrackedPnt_s32.y = ( m_RectTrace_s32[v_currLastRectIndex_u32].y + windowSize / 2 );
                // Register the tracked position to tracked obj info
                m_pTrackedInfoObj.setTrkdPix_s32( v_CurrTrackedPnt_s32 ); //PRQA S 3706
                v_trackSuccess_b = true;
            }
            else
            {
                // Do Nothing
            }
        }

        return v_trackSuccess_b;
    }
    /*
    * Name: StartTrack
    * Remarks: DD-ID: {DE48E1F3-C62A-4984-BD89-50A22CBE84E1}
    * Remarks: DD-ID: {AE76E79B-382C-403f-BBC4-FBDF69E758FD}
    */
    bool_t ObjectTracker::StartTrack( Point2i pixel )
    {
        bool_t v_success_b = false;
        bool_t v_isValidInput_b = ValidateInputPix( pixel );

        if( v_isValidInput_b == true )
        {
            int32_t v_leftX_s32;
            int32_t v_leftY_s32;
            v_leftX_s32 = pixel.x - ( m_BlockWidth_s32 / 2 );
            v_leftY_s32 = pixel.y - ( m_BlockHeight_s32 / 2 );
            Recti v_ROI_s32( v_leftX_s32, v_leftY_s32, m_BlockWidth_s32, m_BlockHeight_s32 );
            m_RectTrace_s32.clear_v();
            m_RectTrace_s32.pushBack_v( v_ROI_s32 );
            m_kcfTrackerCObj.init_c( v_ROI_s32, m_Image );
            m_kcfTrackerCObj.setPeakValue_c( 1.0f );
            v_success_b = true;
        }
        else
        {
            // Do Nothing
        }

        return v_success_b;
    }
    /*
    * Name: ResetTrack
    * Remarks: DD-ID: {8932B058-9289-4753-A254-5CB7EB7C40A6}
    * Remarks: DD-ID: {48D6446B-680D-4c21-B557-BA464CA63AFA}
    */
    bool_t ObjectTracker::ResetTrack( Point2i pixel )
    {
        bool_t v_success_b = false;
        bool_t v_isValidInput_b = ValidateInputPix( pixel );

        if( v_isValidInput_b == true )
        {
            int32_t v_leftX_s32;
            int32_t v_leftY_s32;
            v_leftX_s32 = pixel.x - ( m_BlockWidth_s32 / 2 );
            v_leftY_s32 = pixel.y - ( m_BlockHeight_s32 / 2 );
            Recti v_ROI_s32( v_leftX_s32, v_leftY_s32, m_BlockWidth_s32, m_BlockHeight_s32 );
            m_RectTrace_s32.clear_v();
            m_RectTrace_s32.pushBack_v( v_ROI_s32 );
            m_kcfTrackerCObj.init_c( v_ROI_s32, m_Image );
            m_kcfTrackerCObj.setPeakValue_c( 1.0f );
            v_success_b = true;
        }
        else
        {
            //Do Nothing
        }

        return v_success_b;
    }
    /*
    * Name: Close
    * Remarks: DD-ID: {AEEB7D21-4E70-4790-876A-E0D616ECAEFA}
    * Remarks: DD-ID: {9430C871-00FF-4a7f-ACA4-BA278210C864}
    */
    void ObjectTracker::Close()
    {
        m_pTrackedInfoObj.Init();
        m_RectTrace_s32.clear_v();
        m_kcfTrackerCObj.uninit_c();
    }

    void ObjectTracker::GetTrackedPoint( int32_t& i_TrkdPntX_s32, int32_t& i_TrkdPntY_s32 ) const
    {
        Point2i v_TrkdPix_s32 = m_pTrackedInfoObj.getTrkdPix_s32();
        i_TrkdPntX_s32 = v_TrkdPix_s32.x;//PRQA S 3706
        i_TrkdPntY_s32 = v_TrkdPix_s32.y;//PRQA S 3706
    }
    /*
    * Name: ValidateInputPix
    * Remarks: DD-ID: {6B84DC41-380F-427a-BBCC-F3043BB3D6E8}
    * Remarks: DD-ID: {F139C85B-650B-4fd2-BAF3-EC53C637CC1E}
    */
    bool_t ObjectTracker::ValidateInputPix( const Point2i i_Pix_s32 ) const
    {
        bool_t v_ValidInput_b = false;
        int32_t v_ScaleWindowSizeHalf_s32 = ( ScaleWindowSize / 2 );

        if( ( i_Pix_s32.x >= v_ScaleWindowSizeHalf_s32 ) &&
            ( i_Pix_s32.y >= v_ScaleWindowSizeHalf_s32 ) &&
            ( ( i_Pix_s32.x + v_ScaleWindowSizeHalf_s32 ) < static_cast<int32_t>( m_ImgWidth_u16 ) ) &&
            ( ( i_Pix_s32.y + v_ScaleWindowSizeHalf_s32 ) < static_cast<int32_t>( m_ImgHeight_u16 ) ) )
        {
            v_ValidInput_b = true;
        }

        return v_ValidInput_b;
    }

    uint16_t ObjectTracker::getImgWidth() const
    {
        return m_ImgWidth_u16;
    }

    void ObjectTracker::setImgWidth( uint16_t i_ImgWidth_u16 )
    {
        m_ImgWidth_u16 = i_ImgWidth_u16;
    }

    uint16_t ObjectTracker::getImgHeight() const
    {
        return m_ImgHeight_u16;
    }

    void ObjectTracker::setImgHeight( uint16_t i_ImgHeight_u16 )
    {
        m_ImgHeight_u16 = i_ImgHeight_u16;
    }

    uint8_t* ObjectTracker::getInputImage() const
    {
        return m_pInputImage_pu8;
    }

    void ObjectTracker::setInputImage( uint8_t* i_InputImage_pu8 )
    {
        m_pInputImage_pu8 = i_InputImage_pu8;
    }
}
