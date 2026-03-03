#ifndef DEVICE_INTERFACE_H
#define DEVICE_INTERFACE_H

#include "MeclTypeDefs.h"
#include "Common/Device/Device3DTypes.h"

namespace me3d
{
  class Device3D;
  struct ViewPortDesc_s;

  class DeviceInterface
  {
  public:
    DeviceInterface();
    ~DeviceInterface();

    void create_v(Device3D* b_Device_po);

    bool msgGetViewPort_b(ViewPortDesc_s& b_ViewPortDesc_rs)const;
    bool msgSetViewPort_b(const ViewPortDesc_s& i_ViewPortDesc_rs)const;

    void msgClearScreen_v(uint32_t i_ClearFlags_u32 = me3d::e_RtfClearAll, float32_t i_ClearDepth_f32 = 1.0F, uint32_t i_ClearStencil_u32 = 1, uint32_t i_Index_u32 = 0)const;
    void msgSwapBuffers_v()const;

    void msgGetBackBufferSize_v(uint32_t& o_Width_u32, uint32_t& o_Height_u32) const;
    void msgSetBackBufferSize_v(const uint32_t i_Width_u32, const uint32_t i_Height_u32);

  private:
    Device3D* device_po;
  };

} // namespace me3d

#endif
