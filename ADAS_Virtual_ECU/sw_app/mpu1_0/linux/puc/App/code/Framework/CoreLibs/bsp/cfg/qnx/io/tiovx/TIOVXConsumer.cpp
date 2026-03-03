#include <platform/PlatformAPI.h>

#include <bsp/io/tiovx/TIOVXConsumer.h>

#include <logging/Logger.h>

namespace bsp{

TIOVXConsumer::TIOVXConsumer()
{
    // Note, these need to be set to an invalid value to read the first frame.
    // If both are 0, no frames are read or freed for the writing thread.
    lastSvsReadBufferIdx = 255;
    lastDmcReadBufferIdx = 255;
}

bool_t TIOVXConsumer::waitSvsVideoBuffer_b(TIOVXVideoInput& i_tiovx_vi, uint32_t& o_bufferIdx_u32)
{
    bool_t res = i_tiovx_vi.waitSvsVideoBuffer_b(o_bufferIdx_u32, lastSvsReadBufferIdx);
    lastSvsReadBufferIdx = o_bufferIdx_u32;
    return res;
}

bool_t TIOVXConsumer::getSvsVideoBuffer_b(TIOVXVideoInput& i_tiovx_vi, uint32_t& o_bufferIdx_u32)
{
    bool_t res = i_tiovx_vi.getSvsVideoBuffer_b(o_bufferIdx_u32);
    lastSvsReadBufferIdx = o_bufferIdx_u32;
    return res;
}

bool_t TIOVXConsumer::getVideoInputBuffer_b(TIOVXVideoInput& i_tiovx_vi, variants::Camera_t i_CameraID_t, VideoInputBufferDesc2_t& o_VideoInputBufferDesc_rt)
{
    return i_tiovx_vi.getVideoInputBuffer_b(i_CameraID_t, o_VideoInputBufferDesc_rt);
}

} //namespace bsp
