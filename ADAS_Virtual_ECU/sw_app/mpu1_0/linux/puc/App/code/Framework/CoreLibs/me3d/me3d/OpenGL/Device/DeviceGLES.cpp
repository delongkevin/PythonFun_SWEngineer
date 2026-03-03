#include "DeviceGLES.h"

 

#include "Common/RenderEngineTypes.h"
#include "DeviceGLTypes.h"

#include "OpenGL/Resources/VertexBufferGL.h"
#include "OpenGL/Resources/MultipleRenderTargetGL.h"

// PRQA S 3080 EOF // old style cast used in EGL API
// PRQA S 3054 EOF // Flag handling, I'm aware of it
// PRQA S 3710 EOF // Flag handling, I'm aware of it
// PRQA S 3003 EOF // bitwise operator for flags is fine in this case
// PRQA S 3122 EOF // OpenGL API needs this kind of pointer handling
// PRQA S 3705 EOF // OpenGL API needs this kind of pointer handling

namespace me3d
{

DeviceGLES::DeviceGLES()
  : Device3D()
  , eglDisplay_pv(NULL)
  , eglSurface_pv(NULL)
  , eglContext_pv(NULL)
{

}

DeviceGLES::~DeviceGLES()
{

}

bool DeviceGLES::create_b(RenderEngine* i_RenderEngine_po, const Device3DDesc_s& i_Desc_rs)
{
  bool v_Success_b = Device3D::create_b(i_RenderEngine_po, i_Desc_rs);

  // 1) Create and Initialize an EGLDisplay from the native display
  EGLint v_Major_s32 = 0;
  EGLint v_Minor_s32 = 0;

  // PRQA S 3042 1 //  Using pointer cast to stay graphics API independent
  //EGLNativeDisplayType v_EglDeviceHandle_px = reinterpret_cast<EGLNativeDisplayType>(i_Desc_rs.deviceHandle_pv);
  EGLNativeDisplayType v_EglDeviceHandle_px = 0u;
  eglDisplay_pv = eglGetDisplay(v_EglDeviceHandle_px);

  if (EGL_NO_DISPLAY == eglDisplay_pv)
  {
	  eglDisplay_pv = eglGetDisplay(EGL_DEFAULT_DISPLAY);

	  if (EGL_NO_DISPLAY == eglDisplay_pv)
	  {
		  EGLint v_Error_s32 = eglGetError();
      ME_Debugger_F_Printf_v("eglGetDisplay failed: %i (0x%.4x)\n", v_Error_s32, v_Error_s32);
      v_Success_b = false;
	  }
  }


  if (EGL_FALSE == eglInitialize(eglDisplay_pv, &v_Major_s32, &v_Minor_s32))
  {
	  EGLint v_Error_s32 = eglGetError();
    ME_Debugger_F_Printf_v("eglInitialize failed: %i (0x%.4x)\n", v_Error_s32, v_Error_s32);
    v_Success_b = false;
  }

  // 2) Choose an EGLConfig for the application, used when setting up the rendering surface and EGLContext
  //    http://www.khronos.org/registry/egl/sdk/docs/man/xhtml/eglChooseConfig.html
  //    http://malideveloper.arm.com/resources/sample-code/selecting-the-correct-eglconfig/
  const EGLint c_EglConfigAttributes_as32[] = 
  {
    EGL_ALPHA_SIZE,      8,
    EGL_RED_SIZE,        8,
    EGL_GREEN_SIZE,      8,
    EGL_BLUE_SIZE,       8,
    EGL_BUFFER_SIZE,    32,
    EGL_COLOR_BUFFER_TYPE, EGL_RGB_BUFFER,
    EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,  // Define ES 2 version
    EGL_STENCIL_SIZE,    0,
    EGL_DEPTH_SIZE,      16,                  // Define depth buffer size
    EGL_SAMPLE_BUFFERS,  1,                   // Anti aliasing support
    EGL_SAMPLES,         2,                   // 2xAA
    EGL_SURFACE_TYPE,    EGL_WINDOW_BIT,
    EGL_NONE
  };


  EGLint    v_EglNumConfigs_s32;
  EGLConfig v_EglConfig_pv;

  if ((EGL_FALSE == eglChooseConfig(eglDisplay_pv, &c_EglConfigAttributes_as32[0], &v_EglConfig_pv, 1, &v_EglNumConfigs_s32)) || 
      (v_EglNumConfigs_s32 != 1))
  {
	  EGLint v_Error_s32 = eglGetError();
    ME_Debugger_F_Printf_v("eglChooseConfig failed: %i (0x%.4x)\n", v_Error_s32, v_Error_s32);
  }

  // 3 ) Create the EGL Surface
  EGLNativeWindowType  v_EglWindowHandle_px = reinterpret_cast<EGLNativeWindowType>(i_Desc_rs.windowHandle_pv);
  eglSurface_pv = eglCreateWindowSurface(eglDisplay_pv, v_EglConfig_pv, v_EglWindowHandle_px, NULL);
  if (EGL_NO_SURFACE == eglSurface_pv)
  {
    EGLint v_Error_s32 = eglGetError();
    ME_Debugger_F_Printf_v("eglCreateWindowSurface failed: %i (0x%.4x)\n", v_Error_s32, v_Error_s32);
  }

  // 4) Setup the EGL Context from the other EGL constructs created so far, 
  //    so that the application is ready to submit OpenGL ES commands



  // Make OpenGL ES the current API.
  if (false == eglBindAPI(EGL_OPENGL_ES_API))
  {
    ME_Debugger_F_Printf_v("eglBindAPI failed");
  }

  // Create the context
  EGLint v_ContextAttributes_as32[] =
  {
    EGL_CONTEXT_CLIENT_VERSION, 2,
    EGL_NONE
  };

  eglContext_pv = eglCreateContext(eglDisplay_pv, v_EglConfig_pv, NULL, &v_ContextAttributes_as32[0]);

  if (NULL == eglContext_pv)
  {
    ME_Debugger_F_Printf_v("eglCreateContext failed\n");
    ME_Debugger_F_Printf_v("EGL Error: %i", eglGetError());
  }

  // Bind the context to the current thread
  if (false == eglMakeCurrent(eglDisplay_pv, eglSurface_pv, eglSurface_pv, eglContext_pv))
  {
    ME_Debugger_F_Printf_v("eglMakeCurrent failed\n");
    ME_Debugger_F_Printf_v("EGL Error: %i", eglGetError());
  }

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE); 
  glCullFace(GL_BACK); 
  glFrontFace(GL_CCW);

  Assert(getGLError_b() == false);

  return v_Success_b;
}

void DeviceGLES::release_v()
{
  eglMakeCurrent(eglDisplay_pv, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
  eglDestroyContext(eglDisplay_pv, eglSurface_pv);
  eglDestroyContext(eglDisplay_pv, eglContext_pv);
  eglTerminate(eglDisplay_pv);

  eglSurface_pv = EGL_NO_SURFACE;
  eglContext_pv = EGL_NO_CONTEXT;
  eglDisplay_pv = EGL_NO_DISPLAY;
}

void DeviceGLES::beginFrame_v()
{
  Device3D::beginFrame_v();
}

void DeviceGLES::endFrame_v()
{
  if (EGL_FALSE == eglSwapBuffers(eglDisplay_pv, eglSurface_pv))
  {
    ME_Debugger_F_Printf_v("eglSwapBuffers failed\n");
    ME_Debugger_F_Printf_v("EGL Error: %i", eglGetError());
  }
}

bool DeviceGLES::setViewPort_b(const ViewPortDesc_s& i_ViewPort_rs)
{
  glViewport(i_ViewPort_rs.topLeftX_u32, i_ViewPort_rs.topLeftY_u32, i_ViewPort_rs.width_u32, i_ViewPort_rs.height_u32);
  Assert(getGLError_b() == false);

  glDepthRangef(i_ViewPort_rs.minDepth_f32, i_ViewPort_rs.maxDepth_f32);
  Assert(getGLError_b() == false);

  return Device3D::setViewPort_b(i_ViewPort_rs);
}

bool DeviceGLES::getViewPort_b(ViewPortDesc_s& o_ViewPort_rs)
{
  // get x, y, width, height
  GLint v_ViewPort_ai[4];
  glGetIntegerv(GL_VIEWPORT, &v_ViewPort_ai[0]);
  Assert(getGLError_b() == false);

  o_ViewPort_rs.topLeftX_u32 = v_ViewPort_ai[0];
  o_ViewPort_rs.topLeftY_u32 = v_ViewPort_ai[1];
  o_ViewPort_rs.width_u32    = v_ViewPort_ai[2];
  o_ViewPort_rs.height_u32   = v_ViewPort_ai[3];

  // get depth range
  GLfloat v_DepthRange_af32[2];
  glGetFloatv(GL_DEPTH_RANGE, &v_DepthRange_af32[0]);
  Assert(getGLError_b() == false);

  o_ViewPort_rs.minDepth_f32 = v_DepthRange_af32[0];
  o_ViewPort_rs.maxDepth_f32 = v_DepthRange_af32[1];

  return true;
}

void DeviceGLES::clearScreen_v(uint32_t i_ClearFlags_u32, const Color& i_ClearColor_ro, float32_t i_ClearDepth_f32, uint32_t i_ClearStencil_u32, uint32_t i_Index_u32)
{
  uint32_t v_Flags_u32  = (e_RtfClearDepth   & i_ClearFlags_u32) ? GL_DEPTH_BUFFER_BIT   : 0;
           v_Flags_u32 |= (e_RtfClearStencil & i_ClearFlags_u32) ? GL_STENCIL_BUFFER_BIT : 0;
           v_Flags_u32 |= (e_RtfClearColor   & i_ClearFlags_u32) ? GL_COLOR_BUFFER_BIT   : 0;

  if (v_Flags_u32)
  {
    if (GL_COLOR_BUFFER_BIT & v_Flags_u32)
    {
      glClearColor(i_ClearColor_ro[0], i_ClearColor_ro[1], i_ClearColor_ro[2], i_ClearColor_ro[3]);
      Assert(getGLError_b() == false);
    }

    if (GL_STENCIL_BUFFER_BIT & v_Flags_u32)
    {
      glClearStencil(i_ClearStencil_u32);
      Assert(getGLError_b() == false);
    }

    if (GL_DEPTH_BUFFER_BIT & v_Flags_u32)
    {
      glClearDepthf(i_ClearDepth_f32);
      Assert(getGLError_b() == false);
    }

    glClear(v_Flags_u32);
    Assert(getGLError_b() == false);
  }
}

void DeviceGLES::draw_v(PrimitiveType_e i_PrimitiveType_e, uint32_t i_VertexCnt_u32, uint32_t i_VertexOffset_u32)
{
  Device3D::draw_v(i_PrimitiveType_e, i_VertexCnt_u32, i_VertexOffset_u32);

  glDrawArrays(getGLPrimitiveType_e(i_PrimitiveType_e), i_VertexOffset_u32, i_VertexCnt_u32);
   Assert(getGLError_b() == false);
}

void DeviceGLES::drawIndexed_v(PrimitiveType_e i_PrimitiveType_e, uint32_t i_IndexCnt_u32, uint32_t i_IndexOffset_u32)
{
  Device3D::drawIndexed_v(i_PrimitiveType_e, i_IndexCnt_u32, i_IndexOffset_u32);

  // unsigned short stride is hardcoded atm
  uint32_t v_IndexOffsetBytes_u32 = 2 * i_IndexOffset_u32;

  glDrawElements(getGLPrimitiveType_e(i_PrimitiveType_e), i_IndexCnt_u32, GL_UNSIGNED_SHORT, (char*)NULL + v_IndexOffsetBytes_u32);
  Assert(getGLError_b() == false);
}

bool DeviceGLES::setVertexBuffer_b(const VertexBuffer* i_Buffer_po, uint32_t i_Slot_u32, uint32_t i_Offset_u32)
{
  bool v_Success_b = Device3D::setVertexBuffer_b(i_Buffer_po, i_Slot_u32, i_Offset_u32);

  if (NULL != i_Buffer_po)
  {
    glBindBuffer(GL_ARRAY_BUFFER, i_Buffer_po->getID_u32());
    Assert(getGLError_b() == false);
  }
  else
  {
    glBindBuffer(GL_ARRAY_BUFFER, 0U);
  }

  return v_Success_b;
}

bool DeviceGLES::setVertexBuffer_b(const VertexBuffer* i_Buffer_po, uint32_t i_Slot_u32, uint32_t i_Offset_u32, uint32_t i_Stride_u32)
{
  bool v_Success_b = Device3D::setVertexBuffer_b(i_Buffer_po, i_Slot_u32, i_Offset_u32, i_Stride_u32);

  if (NULL != i_Buffer_po)
  {
    glBindBuffer(GL_ARRAY_BUFFER, i_Buffer_po->getID_u32());
    Assert(getGLError_b() == false);
  }
  else
  {
    glBindBuffer(GL_ARRAY_BUFFER, 0U);
  }

  return v_Success_b;
}

} // namespace me3d
