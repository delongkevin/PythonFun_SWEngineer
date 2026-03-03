#include "Common/Interfaces/DeviceInterface.h"

#include "Common/RenderInterface.h"
#include "Common/Device/Device3D.h"

namespace me3d
{
  DeviceInterface::DeviceInterface()
    : device_po(NULL)
  {

  }

  DeviceInterface::~DeviceInterface()
  {

  }

  void DeviceInterface::create_v(Device3D* b_Device_po)
  {
    device_po = b_Device_po;
  }

  bool DeviceInterface::msgGetViewPort_b(ViewPortDesc_s& b_ViewPortDesc_rs) const
  {
	return device_po->getViewPort_b(b_ViewPortDesc_rs);
  }

  bool DeviceInterface::msgSetViewPort_b(const ViewPortDesc_s& i_ViewPortDesc_rs) const
  {
    return device_po->setViewPort_b(i_ViewPortDesc_rs);
  }

  void DeviceInterface::msgClearScreen_v(uint32_t i_ClearFlags_u32 /*= me3d::e_RtfClearAll*/, float32_t i_ClearDepth_f32 /*= 1.0F*/, uint32_t i_ClearStencil_u32 /*= 1*/, uint32_t i_Index_u32 /*= 0*/) const
  {
    device_po->clearScreen_v(i_ClearFlags_u32, i_ClearDepth_f32, i_ClearStencil_u32, i_Index_u32);
  }

  void DeviceInterface::msgSwapBuffers_v()const
  {
    device_po->endFrame_v();
  }

  void DeviceInterface::msgGetBackBufferSize_v(uint32_t& o_Width_u32, uint32_t& o_Height_u32)const
  {
    device_po->getBackBufferSize_v(o_Width_u32,o_Height_u32);
  }



} // namespace me3d