//--------------------------------------------------------------------------
/// @file TIOVXHost.h
/// @brief Implementation of TIOVX Host interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
//  --------------------------------------------------------------------------

#ifndef TIOVX_HOST_H_
#define TIOVX_HOST_H_

#include <platform/PlatformAPI.h>

#include <variants/Enums.h>

#include "TIOVXVideoInput.h"
#include "TIOVXVideoOutput.h"
#include <TI/tivx.h>

namespace bsp
{

class TIOVXHost
{
public:
    TIOVXHost();

    ~TIOVXHost();

    /// @brief    OVX host initialization
    bool_t    init_b();

public:

    /// @brief    Video input interface accessor
    TIOVXVideoInput&     getVideoInput_ro();

    /// @brief    Video output interface accessor
    TIOVXVideoOutput&     getVideoOutput_ro();

    /// @brief	Video buffer allocation
    bool_t 			    allocVideoBuffer_b(uint32_t i_width_u32, uint32_t i_height_u32, uint32_t i_format_u32, uint32_t i_num_u32, VideoInputBufferDesc2_t& o_bufferDesc_ro, void** i_priv_apv = NULL);

    /// @brief	Video buffer release
    void                releaseVideoBuffer_v(VideoInputBufferDesc2_t& i_bufferDesc_ro, void** i_priv_apv);

private:
    // OVX context
    vx_context            context_pv;

    // video input interface
    TIOVXVideoInput       videoInput_o;

    // video output interface
    TIOVXVideoOutput      videoOutput_o;

};

/// @brief  Create pixmap out of video buffer
///
/// @param  i_context_po[in]    Screen context pointer
/// @param  i_desc_po[in]       Video buffer descriptor
/// @param  o_pixmap_apo[out]   Array of pixmaps
///
/// @return                     False on failure
bool_t  CreateVideoBufferPixmap_b(screen_context_t i_context_po, VideoInputBufferDesc2_t& i_desc_po, screen_pixmap_t* o_pixmap_apo);

/// @brief  Destroy pixmaps built of video buffers
///
/// @param  i_desc_po[in]       Video buffer descriptor
/// @param  i_pixmap_apo[in]    Array of pixmaps
void    DestroyVideoBufferPixmap_v(VideoInputBufferDesc2_t& i_desc_po, screen_pixmap_t* i_pixmap_apo);

} // namespace bsp

#endif // TIOVX_HOST_H_

