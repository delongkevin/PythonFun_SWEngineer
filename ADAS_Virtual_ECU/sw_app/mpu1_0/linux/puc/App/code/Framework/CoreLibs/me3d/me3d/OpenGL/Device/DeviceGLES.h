//--------------------------------------------------------------------------                                                                                                           
/// @file DeviceGLES.h                                                                         
/// @brief EGL/OpenGL ES implementation for Device3D
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef DEVICEGLES_H
#define DEVICEGLES_H

#include "Common/Device/Device3D.h"
#include "OpenGL/GLIncludes.h"

// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.

namespace me3d
{

class DeviceGLES : public Device3D
{
public:
  DeviceGLES();
  virtual ~DeviceGLES();

  virtual bool create_b(RenderEngine* i_RenderEngine_po, const Device3DDesc_s& i_Desc_rs) ME_OVERRIDE;
  virtual void release_v() ME_OVERRIDE;

  virtual void beginFrame_v() ME_OVERRIDE;
  virtual void endFrame_v() ME_OVERRIDE;

  virtual bool setViewPort_b(const ViewPortDesc_s& i_ViewPort_rs) ME_OVERRIDE;
  virtual bool getViewPort_b(ViewPortDesc_s& o_ViewPort_rs) ME_OVERRIDE;

  // PRQA S 2121 1 // intended to override clearScreen_v from base class.
  virtual void clearScreen_v(uint32_t i_ClearFlags_u32, const Color& i_ClearColor_ro, float32_t i_ClearDepth_f32, uint32_t i_ClearStencil_u32, uint32_t i_Index_u32) ME_OVERRIDE;

  virtual void draw_v(PrimitiveType_e i_PrimitiveType_e, uint32_t i_VertexCnt_u32, uint32_t i_VertexOffset_u32) ME_OVERRIDE;
  virtual void drawIndexed_v(PrimitiveType_e i_PrimitiveType_e, uint32_t i_IndexCnt_u32, uint32_t i_IndexOffset_u32) ME_OVERRIDE;

  virtual bool setVertexBuffer_b(const VertexBuffer* i_Buffer_po, uint32_t i_Slot_u32, uint32_t i_Offset_u32) ME_OVERRIDE;
  virtual bool setVertexBuffer_b(const VertexBuffer* i_Buffer_po, uint32_t i_Slot_u32, uint32_t i_Offset_u32, uint32_t i_Stride_u32) ME_OVERRIDE;

  EGLDisplay getDisplay_t() const { return eglDisplay_pv; }

private:
  EGLDisplay eglDisplay_pv;
  EGLSurface eglSurface_pv;
  EGLContext eglContext_pv;
};

} // namespace me3d

#endif // DEVICEGLES_H
