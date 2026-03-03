#include "OpenGL/Resources/MultipleRenderTargetGL.h"

#include "Common/RenderEngine.h"
#include "Common/Manager/TextureManager.h"

#include "OpenGL/Resources/RenderTargetGL.h"
#include "OpenGL/Device/DeviceGLTypes.h"
#include "mecl/math/Math.h"
#include "OpenGL/GLIncludes.h"


// PRQA S 3706 EOF // performance
// PRQA S 3076 EOF // by design
// PRQA S 4020 EOF // multiple exit points makes code more readable.
// PRQA S 3054 EOF // makes code more readable.
// PRQA S 1051 EOF // This is a TODO



namespace me3d
{
  MultipleRenderTargetGL::MultipleRenderTargetGL()
    : MultipleRenderTarget()
  {
    renderEngine_po = NULL;
    backBuffer_b = false;
    drawBufferCount_u32 = 0U;

    memset(frameBufferGLIDs_au32, 0, sizeof(frameBufferGLIDs_au32));

    for (uint8_t i = 0; i < MAX_MRT_COLOR_RTS; ++i)
    {
      drawBufferValues_au32[i] = GL_NONE;
    }
  }

  MultipleRenderTargetGL::~MultipleRenderTargetGL()
  {

  }

  bool_t MultipleRenderTargetGL::create_b(RenderEngine* i_RenEng_po, RenderTargetDesc_s** i_ColorDesc_pps, RenderTargetDesc_s* i_DepthDesc_ps)
  {
    MultipleRenderTarget::create_b(i_RenEng_po, i_ColorDesc_pps, i_DepthDesc_ps);

    release_v();

    sint32_t v_FaceCount_s32 = 1;

    // 1) create Color Render Targets
    for (uint32_t v_I_u32 = 0U; v_I_u32 < MAX_MRT_COLOR_RTS; ++v_I_u32)
    {
      if (NULL != i_ColorDesc_pps[v_I_u32])
      {
        colorRenderTargets_apo[v_I_u32] = renderEngine_po->getTextureManager_po()->createRenderTarget_po(*i_ColorDesc_pps[v_I_u32]);

        if ((NULL == colorRenderTargets_apo[v_I_u32]) || 
            (static_cast<RenderTargetGL*>(colorRenderTargets_apo[v_I_u32])->getColorBufferId_u32() == 0))
        {
          // Failed creating color render target!
          Assert(false);

          return false;
        }

        if (i_ColorDesc_pps[v_I_u32]->type_e == e_TtCube)
        {
          v_FaceCount_s32 = 6;
        }
      }
      else 
      {
        // The multiple render target must continuously set color buffers!
        break;
      }
    } // for each color rt

    // 2. Create depth-stencil render target
    if (i_DepthDesc_ps)
    {
      depthRenderTarget_po = renderEngine_po->getTextureManager_po()->createRenderTarget_po(*i_DepthDesc_ps);

      if ((NULL == depthRenderTarget_po) || 
         (static_cast<RenderTargetGL*>(depthRenderTarget_po)->getDepthBufferId_u32() == 0))
      {
        // Failed creating depth-stencil render target!
        Assert(false);

        return false;
      }
    }


    // 3. Create frame buffer objects and attach color and depth-stencil buffers
    for (sint32_t v_I_s32 = 0; v_I_s32 < MAX_MRT_COLOR_RTS; ++v_I_s32)
    {
      drawBufferValues_au32[v_I_s32] = GL_NONE;
    }

    drawBufferCount_u32 = 0U;

    // Step through all faces of an cube map if one or more of the color render targets are cube maps
    for (sint32_t v_Face_s32 = 0; v_Face_s32 < v_FaceCount_s32; ++v_Face_s32)
    {
      // 3.1 Create a frame buffer object for each cube map face
      glGenFramebuffers(1, &frameBufferGLIDs_au32[v_Face_s32]);
      Assert(getGLError_b() == false);

      glBindFramebuffer(GL_FRAMEBUFFER, frameBufferGLIDs_au32[v_Face_s32]);
      Assert(getGLError_b() == false);

      // 3.2  Attach each color buffer to the frame buffer object
      for (uint8_t v_I_s32 = 0; v_I_s32 < MAX_MRT_COLOR_RTS; ++v_I_s32)
      {           
        RenderTargetGL* v_ColorTarget_po = static_cast<RenderTargetGL*>(colorRenderTargets_apo[v_I_s32]);

        if (NULL == v_ColorTarget_po)
        {
          // The multiple render target must continuously set color buffers!
          break;
        }

        if ((v_ColorTarget_po->getDesc_rs().type_e == e_Tt2D)            ||
            (v_ColorTarget_po->getDesc_rs().type_e == e_Tt2DMultisample) ||
            (v_ColorTarget_po->getDesc_rs().type_e == e_Tt3D)            ||
            (v_ColorTarget_po->getDesc_rs().type_e == e_TtCube))
        {
          
          GLenum type   = getGLTextureType_e(v_ColorTarget_po->getDesc_rs().type_e);
          GLenum target = (v_ColorTarget_po->getDesc_rs().type_e == e_TtCube) ? GL_TEXTURE_CUBE_MAP_POSITIVE_X + v_Face_s32 : type;    // Specify the texture type or in case of an
          // cube map the cube map face
          if (v_ColorTarget_po->getDesc_rs().type_e == e_Tt3D)
          {
            Assert(false);        
            //TODO: 3D texture, how to handle the "layer" parameter (last parameter) properly?!
            //for (int n = 0; n < pColorTarget->GetDesc().Depth; ++n)
            //{
            //  glFramebufferTexture3D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + v_I_s32, target, pColorTarget->GetColorBufferGLID(), 0, 0/*n*/);
            //}
          }
          else
          {
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + v_I_s32, target, v_ColorTarget_po->getColorBufferId_u32(), 0);
            Assert(getGLError_b() == false);
          }
          

          drawBufferValues_au32[v_I_s32] = GL_COLOR_ATTACHMENT0 + v_I_s32;
          drawBufferCount_u32      = mecl::math::max_x(drawBufferCount_u32, static_cast<uint32_t>(v_I_s32 + 1));
        }
        else
        {
          // 1D render targets are currently not supported
          Assert(false);

          return false;
        }
      }

      // 3.3 Attach the depth-stencil buffer
      RenderTargetGL* pDepthTarget = static_cast<RenderTargetGL*>(depthRenderTarget_po);
      if (pDepthTarget)
      {
        //GLenum attachment = (getGLPixelFormat_e(pDepthTarget->getDesc_rs().depthFormat_e) == GL_DEPTH_STENCIL) ? GL_DEPTH_STENCIL_ATTACHMENT : GL_DEPTH_ATTACHMENT;

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, pDepthTarget->getDepthBufferId_u32(), 0);
        Assert(getGLError_b() == false);
      }

      // 3.4 Set draw buffer to check the frame buffer object status under complete conditions
      // https://stackoverflow.com/questions/54826074/gldrawbuffers-in-opengl-es-2-0-c
      //glDrawBuffers(drawBufferCount_u32, drawBufferValues_au32);
      //Assert(getGLError_b() == false);

      // 3.5 Check the frame buffer status
      GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

      if (status != GL_FRAMEBUFFER_COMPLETE)
      {
        ME_Debugger_F_Printf_v("Frame buffer object validation failed: %s (0x%x)\n", getFBOStatus_pc(status), status);
        Assert(false);
        return false;
      }
    }

    // 4. Reset the frame buffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    Assert(getGLError_b() == false);

    // 5. Reset to draw buffers to the default values
    //glDrawBuffer(GL_BACK);
    //Assert(getGLError_b() == false);


    generateMipMaps_v();

    return true;

  }

  void MultipleRenderTargetGL::release_v()
  {
    // Step through all possible cube map faces
    for (uint8_t i = 0; i < 6; ++i)
    {
      if (frameBufferGLIDs_au32[i])
      {
        glDeleteFramebuffers(1, &frameBufferGLIDs_au32[i]);

        Assert(getGLError_b() == false);

        frameBufferGLIDs_au32[i] = 0;
      }
    }

    for (uint8_t i = 0; i < MAX_MRT_COLOR_RTS; ++i)
    {
      drawBufferValues_au32[i] = GL_NONE;
    }

    drawBufferCount_u32 = 0U;
    backBuffer_b        = false;
  }

  void MultipleRenderTargetGL::createBackBufferMRT_v(Device3D* i_Device_po)
  {
    release_v();

    backBuffer_b = true;
  }

  bool_t MultipleRenderTargetGL::setMRTResources_b(uint32_t i_Face_u32, uint32_t i_Level_u32, DepthBufferSetMode_e i_Mode_e /*= e_DbsSetDepthBuffer*/)
  {
    if (!MultipleRenderTarget::setMRTResources_b(i_Face_u32, i_Level_u32, i_Mode_e))
    {
      return false;
    }

    if (true == backBuffer_b)
    {
      glBindFramebuffer(GL_FRAMEBUFFER, 0);
      Assert(getGLError_b() == false);

    }
    else
    {
      if ((i_Face_u32 >= 6) || (frameBufferGLIDs_au32[i_Face_u32] == 0))
      {
        Assert(false);
        return false;
      }

      // Set the all multiple render targets at the same time (combined in a frame buffer object)
      glBindFramebuffer(GL_FRAMEBUFFER, frameBufferGLIDs_au32[i_Face_u32]);
      Assert(getGLError_b() == false);

      RenderTargetGL* pDepthTarget = static_cast<RenderTargetGL*>(depthRenderTarget_po);

      if (pDepthTarget)
      {
        
        GLenum attachment = GL_DEPTH_ATTACHMENT; 

        if (i_Mode_e == e_DbsNoDepthBuffer)
        {
          glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, 0, 0);
          Assert(getGLError_b() == false);
        }
        else if (i_Mode_e == e_DbsSetDepthBuffer)
        {
          glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, pDepthTarget->getDepthBufferId_u32(), 0);
          Assert(getGLError_b() == false);
        }
        else if (i_Mode_e == e_DbsSetReadOnlyDepthBuffer)
        {
          glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, pDepthTarget->getDepthBufferId_u32(), 0);
          Assert(getGLError_b() == false);

          // Want to read from a texture that is still bound as target?
          // Due to https://www.opengl.org/discussion_boards/showthread.php/173408-Depth-texture-bound-to-FBO-and-texture-unit
          // The specification (Chapter "Feedback Loops") does not allow that, even if you disable write-to-depth-states via glDepthMask()
          // However in https://code.google.com/p/chromium/issues/detail?id=260064#c30
          // It is suggested to use the NV_TEXTURE_BARRIER extension to enforce the driver to make all previous writes to the depth-buffer readable
          // Though being an NVidea extension, it should be available on most AMD graphic cards as well
          //if (GLEW_NV_texture_barrier)
          //{
          //  glTextureBarrierNV();
          //}
          //else
          //{
          //  Assert_function(!"OpenGL Extension for Texture Barriers not supported. This could result in undefined behaviour when using read-only-depth-buffers");
          //}
        }
        else
        {
          // misra else
        }
      }

      //glBindRenderbuffer(GL_FRAMEBUFFER, drawBufferValues_au32);
      //glDrawBuffers(drawBufferCount_u32, drawBufferValues_au32);
      Assert(getGLError_b() == false);
    }

    return true;
  }

} // namespace me3d