//--------------------------------------------------------------------------
/// @file TIOVXHost.cpp
/// @brief Implementation of TIOVX host interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
//  --------------------------------------------------------------------------


#include <platform/PlatformAPI.h>

#include <bsp/io/tiovx/TIOVXHost.h>

#include <logging/Logger.h>
#include <TI/tivx_obj_desc.h>
#include <screen/screen.h>
#include <stdarg.h>

extern "C" {

#include <app_init.h>
#include <TI/j7_imaging_aewb.h>

// Private TI API that allows to get access to storage buffer
extern uint16_t ownReferenceGetObjDescId(vx_reference ref);

// internal TIOVX function
extern vx_status ownReferenceAllocMem(vx_reference ref);
}

namespace bsp
{

/// @brief  Logging function
static bool_t log_b(logging::LogLevel_e i_level_e, const char* i_format_pc, ...)
{
    char        v_buffer_ac[256];
    va_list     v_args_pt;

    va_start(v_args_pt, i_format_pc);

    vsnprintf(v_buffer_ac, sizeof(v_buffer_ac) - 1, i_format_pc, v_args_pt);

    return logging::Logger::log_b(i_level_e, logging::e_LogModeMaskPrintf, "tiovx: %s", v_buffer_ac);
}

/// @brief  Video input graph constructor
TIOVXHost::TIOVXHost()
    : context_pv(NULL)
    , videoInput_o()
    , videoOutput_o()
{
}

/// @brief  TIOVX host destructor
TIOVXHost::~TIOVXHost()
{

}

/// @brief  TIOVX host initialization
bool_t TIOVXHost::init_b()
{
    bool_t      v_result_b = true;
    vx_status   v_status_t;

    // Common runtime initialization
    if ((v_status_t = appCommonInit()) != 0)
    {
        log_b(logging::e_LogLvlError, "failed to initialize common runtime: %d", v_status_t);
        v_result_b = false;
    }

    if (v_result_b == true)
    {
        tivxInit();
        tivxHostInit();

		//tivx_set_debug_zone((int32_t)VX_ZONE_INFO);

        // create OVX context
        context_pv = vxCreateContext();
        if ((v_status_t = vxGetStatus((vx_reference)context_pv)) != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to create context: %X", v_status_t);
            v_result_b = false;
        }
        else
        {
            // load all kernels
            tivxHwaLoadKernels(context_pv);
            tivxImagingLoadKernels(context_pv);
        }
    }

    // video input initialization
    v_result_b &= videoInput_o.initVideoInput_b(context_pv);

    // video output initialization
    v_result_b &= videoOutput_o.initVideoOutput_b(context_pv);
        
    if (v_result_b == true)
    {
        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                               "TIOVX host initialized\n");
    }
    else
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "TIOVX host initialization failed\n");
    }

    return v_result_b;
}

/// @brief  Video input interface accessor
TIOVXVideoInput& TIOVXHost::getVideoInput_ro()
{
  return videoInput_o;
}

/// @brief  Video output interface accessor
TIOVXVideoOutput& TIOVXHost::getVideoOutput_ro()
{
  return videoOutput_o;
}

/// @brief	Video buffer allocation
///
/// @param  i_width_u32[in]         Image width
/// @param  i_height_u32[in]        Image height
/// @param  i_format_u32[in]        Image format (from screen.h)
/// @param  i_num_u32[in]           Number of buffers to allocate
/// @param  o_bufferDesc_ro[out]    Video buffers descriptor
/// @param  o_priv_apv[out]         Optional array of image references
///
/// @return                         True if successful
bool_t TIOVXHost::allocVideoBuffer_b(uint32_t i_width_u32, uint32_t i_height_u32, uint32_t i_format_u32, uint32_t i_num_u32, VideoInputBufferDesc2_t& o_bufferDesc_ro, void** o_priv_apv)
{
    bool_t      v_result_b = true;
    vx_status   v_status_t;
    uint32_t    v_format_u32;

    switch (i_format_u32)
    {
    case SCREEN_FORMAT_NV12:
        v_format_u32 = VX_DF_IMAGE_NV12;
        break;
    case SCREEN_FORMAT_UYVY:
        v_format_u32 = VX_DF_IMAGE_UYVY;
        break;
    case SCREEN_FORMAT_BYTE:
        v_format_u32 = VX_DF_IMAGE_U8;
        break;
    case SCREEN_FORMAT_RGBA8888:
        v_format_u32 = VX_DF_IMAGE_RGBX;
        break;
    default:
        log_b(logging::e_LogLvlError, "invalid buffer format: %u", i_format_u32);
        v_result_b = false;
    }

    if (i_num_u32 == 0 || i_num_u32 > c_MaxBuffer2_u32)
    {
        log_b(logging::e_LogLvlError, "invalid number of buffers: %u", i_num_u32);
        v_result_b = false;
    }

    for (uint32_t v_idx_u32 = 0U; v_result_b == true && v_idx_u32 < i_num_u32; v_idx_u32++)
    {
        vx_image    v_image_pv;

        v_image_pv = vxCreateImage(context_pv, i_width_u32, i_height_u32, v_format_u32);
        if ((v_status_t = vxGetStatus((vx_reference)v_image_pv)) != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to create image %u*%u@%u: %x", i_width_u32, i_height_u32, v_format_u32, v_status_t);
            v_result_b = false;
        }
        else
        {
            // store image reference if needed
            o_priv_apv ? *o_priv_apv++ = static_cast<void*>(v_image_pv) : 0;

            // force memory allocation
            v_status_t = ownReferenceAllocMem((vx_reference)v_image_pv);
            if (v_status_t != VX_SUCCESS)
            {
                log_b(logging::e_LogLvlError, "failed to allocate image memory %u*%u@%u: %x", i_width_u32, i_height_u32, v_format_u32, v_status_t);
                v_result_b = false;
            }
        }

        if (v_result_b == true)
        {
            uint16_t                v_objID_u16 = ownReferenceGetObjDescId((vx_reference)v_image_pv);
            tivx_obj_desc_image_t*  v_image_po;
            tivxGetObjDescList(&v_objID_u16, (tivx_obj_desc_t **)&v_image_po, 1);

            tivx_shared_mem_ptr_t*  v_mem_apo = v_image_po->mem_ptr;
            uint8_t*                v_addr_apu8[3] = {
                (uint8_t*)tivxMemShared2TargetPtr(&v_mem_apo[0]),
                (uint8_t*)tivxMemShared2TargetPtr(&v_mem_apo[1]),
                (uint8_t*)tivxMemShared2TargetPtr(&v_mem_apo[2]),
            };

            if (v_idx_u32 == 0)
            {
                o_bufferDesc_ro.size_au32[0] = v_image_po->width;
                o_bufferDesc_ro.size_au32[1] = v_image_po->height;
                o_bufferDesc_ro.stride_au32[0] = v_image_po->imagepatch_addr[0].stride_y;
                o_bufferDesc_ro.stride_au32[1] = v_image_po->imagepatch_addr[1].stride_y;
                o_bufferDesc_ro.stride_au32[2] = v_image_po->imagepatch_addr[2].stride_y;
                o_bufferDesc_ro.bufsize_au32[0] = v_image_po->mem_size[0];
                o_bufferDesc_ro.bufsize_au32[1] = v_image_po->mem_size[1];
                o_bufferDesc_ro.bufsize_au32[2] = v_image_po->mem_size[2];
                o_bufferDesc_ro.format_u32 = i_format_u32;
                o_bufferDesc_ro.numOfBuffer_u32 = i_num_u32;
            }

            o_bufferDesc_ro.buffers_apv[v_idx_u32] = v_addr_apu8[0];
            o_bufferDesc_ro.offset_aau32[v_idx_u32][0] = 0;
            o_bufferDesc_ro.offset_aau32[v_idx_u32][1] = (v_addr_apu8[1] ? (uint32_t)(v_addr_apu8[1] - v_addr_apu8[0]) : 0U);
            o_bufferDesc_ro.offset_aau32[v_idx_u32][2] = (v_addr_apu8[2] ? (uint32_t)(v_addr_apu8[2] - v_addr_apu8[0]) : 0U);

            log_b(logging::e_LogLvlInfo, "allocate %u*%u@%u buffer-%u: %p",
                  i_width_u32, i_height_u32, i_format_u32, v_idx_u32,
                  o_bufferDesc_ro.buffers_apv[v_idx_u32]);
        }
    }

    return v_result_b;
}

/// @brief	Video buffer release
///
/// @param  i_bufferDesc_ro[in]     Video buffers descriptor
/// @param  i_priv_apv[out]         Array of image references
void TIOVXHost::releaseVideoBuffer_v(VideoInputBufferDesc2_t& i_bufferDesc_ro, void** i_priv_apv)
{
    for (uint32_t v_idx_u32 = 0U; v_idx_u32 < i_bufferDesc_ro.numOfBuffer_u32; v_idx_u32++)
    {
        vxReleaseImage((vx_image*)i_priv_apv++);
    }
}

/// @brief  Create pixmap out of video buffer
///
/// @param  i_context_po[in]    Screen context pointer
/// @param  i_desc_po[in]       Video buffer descriptor
/// @param  o_pixmap_apo[out]   Array of pixmaps
///
/// @return                     False on failure
bool_t CreateVideoBufferPixmap_b(screen_context_t i_context_po, VideoInputBufferDesc2_t& i_desc_po, screen_pixmap_t *o_pixmap_apo)
{
    sint32_t    v_bufsize_s32 = i_desc_po.bufsize_au32[0] + i_desc_po.bufsize_au32[1] + i_desc_po.bufsize_au32[2];
    bool_t      v_result_b = true;

    for (uint32_t v_index_u32 = 0; v_result_b == true && v_index_u32 < i_desc_po.numOfBuffer_u32; v_index_u32++)
    {
        screen_buffer_t     v_buffer_t;

        ME_Debugger_F_Printf_v("create screen-buffer: %u*%u@%u, stride=%u/%u/%u, a=%p, o=%u/%u/%u\n",
                               i_desc_po.size_au32[0], i_desc_po.size_au32[1], i_desc_po.format_u32,
                               i_desc_po.stride_au32[0], i_desc_po.stride_au32[1], i_desc_po.stride_au32[2],
                               i_desc_po.buffers_apv[v_index_u32],
                               i_desc_po.offset_aau32[v_index_u32][0], i_desc_po.offset_aau32[v_index_u32][1], i_desc_po.offset_aau32[v_index_u32][2]);

        v_result_b = (EOK == screen_create_buffer(&v_buffer_t));
        Assert(v_result_b);
        v_result_b &= (EOK == screen_set_buffer_property_iv(v_buffer_t, SCREEN_PROPERTY_SIZE, (const int*)&v_bufsize_s32));
        Assert(v_result_b);
        v_result_b &= (EOK == screen_set_buffer_property_iv(v_buffer_t, SCREEN_PROPERTY_BUFFER_SIZE, (const int*)i_desc_po.size_au32));
        Assert(v_result_b);
        v_result_b &= (EOK == screen_set_buffer_property_iv(v_buffer_t, SCREEN_PROPERTY_FORMAT, (const int*)&i_desc_po.format_u32));
        Assert(v_result_b);
        v_result_b &= (EOK == screen_set_buffer_property_iv(v_buffer_t, SCREEN_PROPERTY_STRIDE, (const int*)&i_desc_po.stride_au32[0]));
        Assert(v_result_b);

        sint32_t            v_val_s32 = 1;
        v_result_b &= (EOK == screen_set_buffer_property_iv(v_buffer_t, SCREEN_PROPERTY_PHYSICALLY_CONTIGUOUS, &v_val_s32));
        Assert(v_result_b);
        v_result_b &= (EOK == screen_set_buffer_property_iv(v_buffer_t, SCREEN_PROPERTY_PLANAR_OFFSETS, (const int*)i_desc_po.offset_aau32[v_index_u32]));
        Assert(v_result_b);
        v_result_b &= (EOK == screen_set_buffer_property_pv(v_buffer_t, SCREEN_PROPERTY_POINTER, &i_desc_po.buffers_apv[v_index_u32]));
        Assert(v_result_b);

        screen_pixmap_t     v_pixmap_t;

        v_result_b &= (EOK == screen_create_pixmap(&v_pixmap_t, i_context_po));
        Assert(v_result_b);
        sint32_t v_usage_s32 = SCREEN_USAGE_WRITE | SCREEN_USAGE_READ | SCREEN_USAGE_NATIVE | SCREEN_USAGE_OPENGL_ES3;
        v_result_b &= (EOK == screen_set_pixmap_property_iv(v_pixmap_t, SCREEN_PROPERTY_USAGE, &v_usage_s32));
        Assert(v_result_b);
        v_result_b &= (EOK == screen_set_pixmap_property_iv(v_pixmap_t, SCREEN_PROPERTY_FORMAT, (const int*)&i_desc_po.format_u32));
        Assert(v_result_b);
        v_result_b &= (EOK == screen_set_pixmap_property_iv(v_pixmap_t, SCREEN_PROPERTY_BUFFER_SIZE, (const int*)i_desc_po.size_au32));
        Assert(v_result_b);
        v_result_b &= (EOK == screen_attach_pixmap_buffer(v_pixmap_t, v_buffer_t));
        Assert(v_result_b);

        if (v_result_b == true)
        {
            *o_pixmap_apo++ = v_pixmap_t;
        }
        else
        {
            ME_Debugger_F_Printf_v("failed to create pixmap");
        }
    }

    return v_result_b;
}

/// @brief  Destroy pixmaps built of video buffers
///
/// @param  i_desc_po[in]       Video buffer descriptor
/// @param  i_pixmap_apo[in]    Array of pixmaps
void    DestroyVideoBufferPixmap_v(VideoInputBufferDesc2_t& i_desc_po, screen_pixmap_t* i_pixmap_apo)
{
    for (uint32_t v_idx_u32 = 0U; v_idx_u32 < i_desc_po.numOfBuffer_u32; v_idx_u32++)
    {
        screen_destroy_pixmap(*i_pixmap_apo++);
    }
}

} // namespace bsp
