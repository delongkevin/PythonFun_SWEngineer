//--------------------------------------------------------------------------
/// @file TIOVXVideoConsumer.h
/// @brief Implementation of TIOVX consumer interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Daniel Cuomo
//  --------------------------------------------------------------------------
#ifndef TIOVX_CONSUMER_H_
#define TIOVX_CONSUMER_H_
#include "TIOVXVideoInput.h"

namespace bsp{

/**
 * @brief TIOVXConsumer is an interface for end users to access TIOVX buffers. This
 * will not guarantee every buffer is recieved, but only provide an accessor with a new
 * buffer when available. 
 * 
 */
class TIOVXConsumer
{
    public:
        TIOVXConsumer();

        /**
         * @brief Wrapper function for TIOVXVideoInput waitSvsVideoBuffer_b. This function will wait 
         * until a new buffer is available.
         * 
         * @param i_tiovx_vi - TiovxVideoInput object to get buffer from.
         * @param o_bufferIdx_u32 - Output buffer index value.
         * @return bool_t - True if successful.
         */
        bool_t waitSvsVideoBuffer_b(TIOVXVideoInput& i_tiovx_vi, uint32_t& o_bufferIdx_u32);

        /**
         * @brief Wrapper function for TIOVXVideoInput getSvsVideoBuffer_b. This function will return
         * true if a new buffer is available and update the o_bufferIdx value, or false if no new buffer
         * is avaialble.
         * 
         * @param i_tiovx_vi - TiovxVideoInput object to get buffer from.
         * @param o_bufferIdx_u32 - Output buffer index value.
         * @return bool_t - True if successful.
         */
        bool_t getSvsVideoBuffer_b(TIOVXVideoInput& i_tiovx_vi, uint32_t& o_bufferIdx_u32);

        /**
         * @brief Wrapper function for TIOVXVideoInput getDmcVideoBuffer_b. This function will wait 
         * until a new buffer is available.
         * 
         * @param i_tiovx_vi - TiovxVideoInput object to get buffer from.
         * @param o_bufferIdx_u32 - Output buffer index value.
         * @return bool_t - True if successful.
         */
        bool_t waitDmcVideoBuffer_b(TIOVXVideoInput& i_tiovx_vi, uint32_t& o_bufferIdx_u32);

        /**
         * @brief  Wrapper function for TIOVXVideoInput getDmcVideoBuffer_b. This function will return
         * true if a new buffer is available and update the o_bufferIdx value, or false if no new buffer
         * is avaialble.
         * 
         * @param i_tiovx_vi - TiovxVideoInput object to get buffer from.
         * @param o_bufferIdx_u32 - Output buffer index value.
         * @return bool_t - True if successful.
         */
        bool_t getDmcVideoBuffer_b(TIOVXVideoInput& i_tiovx_vi, uint32_t& o_bufferIdx_u32);

        /**
         * @brief Wrapper function for TIOVXVideoInput getVideoInputBuffer_b. This function will provide
         * the user with a video buffer for a certain camera.
         * 
         * @param i_tiovx_vi - TiovxVideoInput object to get buffer from.
         * @param i_CameraID_t - ID of camera to get buffer from.
         * @param o_VideoInputBufferDesc_rt - Output video buffer.
         * @return bool_t - True if successful.
         */
        bool_t getVideoInputBuffer_b(TIOVXVideoInput& i_tiovx_vi, variants::Camera_t i_CameraID_t, VideoInputBufferDesc2_t& o_VideoInputBufferDesc_rt);

        // TODO (PTC-1654241 : danicuom) Finish encapsulation and investigation into TIOVX release and consumer class.

    private:
        /// @brief	Last read svs buffer.
        uint32_t lastSvsReadBufferIdx;

        /// @brief	Last read dmc buffer.
        uint32_t lastDmcReadBufferIdx;
};


} //namespace bsp

#endif