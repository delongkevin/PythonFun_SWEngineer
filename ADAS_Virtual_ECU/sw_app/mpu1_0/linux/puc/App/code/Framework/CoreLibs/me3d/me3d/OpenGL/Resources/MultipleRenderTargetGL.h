
// PRQA S 2128 EOF // c++ 14 Autosar standard permits

#ifndef MULTITPLE_RENDER_TARGET_GL
#define MULTITPLE_RENDER_TARGET_GL

#include "Common/Resources/MultipleRenderTarget.h"

#include "OpenGL/GLIncludes.h"

namespace me3d
{

class MultipleRenderTargetGL : public MultipleRenderTarget
{
public:
  MultipleRenderTargetGL();
  virtual ~MultipleRenderTargetGL();

  virtual bool_t create_b(RenderEngine* i_RenEng_po, RenderTargetDesc_s** i_ColorDesc_pps, RenderTargetDesc_s* i_DepthDesc_ps);

  virtual void release_v();

  virtual void createBackBufferMRT_v(Device3D* i_Device_po);

  virtual bool_t setMRTResources_b(uint32_t i_Face_u32, uint32_t i_Level_u32, DepthBufferSetMode_e i_Mode_e = e_DbsSetDepthBuffer);

private:
  // Color buffer and depth-stencil buffer are attached to the frame buffer object Cube maps use 6 different fame buffer objects
  GLuint frameBufferGLIDs_au32[6];                
  
  // Specifies which buffers are used as render targets
  GLenum drawBufferValues_au32[MAX_MRT_COLOR_RTS];    

  // Number of used entries in the draw buffer values array (see above)
  uint32_t drawBufferCount_u32;       

  // True if the MRT represents the back buffer
  bool_t   backBuffer_b;                            
};

} // namespace me3d

#endif
