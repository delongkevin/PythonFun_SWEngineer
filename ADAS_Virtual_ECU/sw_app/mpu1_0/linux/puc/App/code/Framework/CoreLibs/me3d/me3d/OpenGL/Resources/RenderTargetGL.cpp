#include "OpenGL/Resources/RenderTargetGL.h"

#include "OpenGL/GLIncludes.h"
#include "OpenGL/Device/DeviceGLTypes.h"
#include "OpenGL/Manager/TextureManagerGL.h"
#include "Common/RenderEngine.h"

// PRQA S 3054 EOF // flag handling
// PRQA S 3710 EOF // flag handling
// PRQA S 1051 EOF // TODO: Sampler States
// PRQA S 3076 EOF // by design

namespace me3d
{
  RenderTargetGL::RenderTargetGL()
    : RenderTarget()
    , colorBufferId_u32(0U)
    , depthBufferId_u32(0U)
  {

  }

  RenderTargetGL::~RenderTargetGL()
  {
    // PRQA S 4261 2 // fine here
    // PRQA S 4631 1 // no exception
    delete_v();
  }

  uint32_t RenderTargetGL::getColorBufferId_u32() const
  {
    return colorBufferId_u32;
  }

  uint32_t RenderTargetGL::getDepthBufferId_u32() const
  {
    return depthBufferId_u32;
  }

  bool_t RenderTargetGL::create_b(RenderEngine* i_RenEng_po, const RenderTargetDesc_s& i_Desc_rs)
  {
    return createOrResize_b(i_RenEng_po, i_Desc_rs);
  }

  void RenderTargetGL::delete_v()
  {
    if (0U != colorBufferId_u32)
    {
      glDeleteTextures(1, &colorBufferId_u32);
      Assert(getGLError_b() == false);
    
      colorBufferId_u32 = 0U;
    }

    if (0U != depthBufferId_u32)
    {
      glDeleteTextures(1, &depthBufferId_u32);
      Assert(getGLError_b() == false);

      depthBufferId_u32 = 0U;
    }
  }

  void RenderTargetGL::onLostDevice_v()
  {
     // Create already takes care of deleting old resources
  }

  void RenderTargetGL::onResetDevice_v()
  {
    if ((desc_s.flags_u32 & e_RtrColorUseCurrent) ||
        (desc_s.flags_u32 & e_RtrDepthUseCurrent) ||
        (desc_s.flags_u32 & e_RtrBackBufferSize)   )
    {
      createOrResize_b(renderEngine_po, desc_s);
    }
  }

  void RenderTargetGL::resolve_v(uint32_t i_ResolveFlag_u32 /*= e_RtfResolveAll*/, uint32_t i_Index_u32 /*= 0U*/, sint32_t i_Face_s32 /*= 0*/)
  {
    RenderTarget::resolve_v(i_ResolveFlag_u32, i_Index_u32, i_Face_s32);
  }

  void RenderTargetGL::copyColorRenderTarget_v(RenderTarget* i_TargetRT_po)
  {
    if (colorBufferId_u32 != 0)
    {
      Assert(false);
      // TODO
    }
  }

  void RenderTargetGL::generateMipMaps_v()
  {
    if (colorBufferId_u32 != 0U)
    {
      GLenum v_TypeGL = getGLTextureType_e(desc_s.type_e);
      
      glBindTexture(v_TypeGL, colorBufferId_u32);
      Assert(getGLError_b() == false);

      glGenerateMipmap(v_TypeGL);
      Assert(getGLError_b() == false);

      glBindTexture(v_TypeGL, 0);
      Assert(getGLError_b() == false);
    }
  }

  void* RenderTargetGL::getTexture_pv(TextureConstantBufferType_e i_BufferType_e)
  {
    void* v_ReturnId_pv = NULL;

    switch (i_BufferType_e)
    {
    case e_TcbColor:
		{
			v_ReturnId_pv = reinterpret_cast<void*>(&colorBufferId_u32);
			break;
		}
    case e_TcbDepth:
		{
			v_ReturnId_pv = reinterpret_cast<void*>(&depthBufferId_u32);
			break;
		}
    case e_TcbStencil:
		{
			Assert(false); // Implement reading stencil buffers
			break;
		}
    default:
		{
			break;
		}
    }

    Assert(NULL != v_ReturnId_pv);
    return v_ReturnId_pv;
  }

  bool_t RenderTargetGL::createOrResize_b(RenderEngine* i_RenEng_po, const RenderTargetDesc_s& i_Desc_rs)
  {
    // classes not supporting this yet.
    Assert(((i_Desc_rs.flags_u32 & e_RtrColorUseCurrent) == 0) && ((i_Desc_rs.flags_u32 & e_RtrDepthUseCurrent) == 0));

    bool_t v_Created_b = RenderTarget::create_b(i_RenEng_po, i_Desc_rs);

    if (true == v_Created_b)
    {
      GLenum v_ColorFormatGL = getGLTextureResourceFormat_e(desc_s.colorFormat_e);
      GLenum v_DepthFormatGL = getGLTextureResourceFormat_e(desc_s.depthFormat_e);

      v_Created_b = ((v_ColorFormatGL != GL_FALSE) || (v_DepthFormatGL != GL_FALSE));

      if (true == v_Created_b)
      {
        // 1.) create Color buffer object
        if ((v_ColorFormatGL != GL_FALSE) && (!(desc_s.flags_u32 & e_RtrColorUseCurrent) ))
        {
          v_Created_b = createColorBuffer_b();
          Assert(true == v_Created_b);
        }

        // 2.) create Depth buffer object
        if ((v_DepthFormatGL != GL_FALSE) && (!(desc_s.flags_u32 & e_RtrDepthUseCurrent)) && (!(desc_s.flags_u32 & e_RtrColorUseCurrent) ))
        {
          v_Created_b = createDepthBuffer_b();
          Assert(true == v_Created_b);
        }

      }
    }

    return v_Created_b;
  }

  bool_t RenderTargetGL::createColorBuffer_b()
  {
    GLenum v_ColorFormatGL = getGLTextureResourceFormat_e(desc_s.colorFormat_e);
    GLenum v_TypeGL        = getGLTextureType_e(desc_s.type_e);

    if (0 == colorBufferId_u32)
    {
      // no old texture to resize, generate new one
      glGenTextures(1, &colorBufferId_u32);
      Assert(getGLError_b() == false);
    }

    bool_t v_Created_b = (colorBufferId_u32 != 0);

    if (true == v_Created_b)
    {
      glBindTexture(v_TypeGL, colorBufferId_u32);
      Assert(getGLError_b() == false);


      //TextureManagerGL* v_TexManGL_po = static_cast<TextureManagerGL*>(renderEngine_po->getTextureManager_po());
      //v_TexManGL_po->commitDefaultSamplerStates_v(v_TypeGL, colorBufferId_u32);

      // TODO: Set default sampler states 
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

      // RenderTargets do not allocate space for mip map levels
     // glTexParameteri(v_TypeGL, GL_TEXTURE_MAX_LEVEL, 0);

      for (uint32_t v_Level_u32 = 0U; v_Level_u32 < desc_s.levels_u32; ++v_Level_u32)
      {
        switch (desc_s.type_e)
        {
        case e_Tt2D:
			{
          glTexImage2D(v_TypeGL, 
                       v_Level_u32, 
                       v_ColorFormatGL, 
                       desc_s.width_u32, 
                       desc_s.height_u32, 
                       0, 
                       getGLPixelFormat_e(desc_s.colorFormat_e),
                       getGLPixelType_e(desc_s.colorFormat_e), 
                       NULL);
          Assert(getGLError_b() == false);
          break;
			}
        case e_TtCube:
			{
          // Create all six faces of the cube map
          for (uint32_t v_Face_u32 = 0; v_Face_u32 < 6U; ++v_Face_u32)
          {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + v_Face_u32, 
                         v_Level_u32, 
                         v_ColorFormatGL, 
                         desc_s.width_u32, 
                         desc_s.height_u32, 
                         0,
                         getGLPixelFormat_e(desc_s.colorFormat_e),
                         getGLPixelType_e(desc_s.colorFormat_e), 
                         NULL);
             Assert(getGLError_b() == false);
          } // for each face
          break;
			}
		case e_Tt1D: {}// Not supported in OpenGL ES 2.0
        case e_Tt3D: {}            // Not supported in OpenGL ES 2.0
        case e_Tt2DMultisample: {} // Not supported in OpenGL ES 2.0
        case e_TtUnknown: {}       // fall through
        default:
			{// fall through
			// Unknown stuff not supported
			Assert(false);
			v_Created_b = false;
			break;
			}
        }

      } // for each level

      glBindTexture(v_TypeGL, 0);
    }
    Assert(true == v_Created_b);
    return v_Created_b;
  }

  bool_t RenderTargetGL::createDepthBuffer_b()
  {
    GLenum v_DepthFormatGL = getGLTextureResourceFormat_e(desc_s.depthFormat_e);
    GLenum v_TypeGL        = getGLTextureType_e(desc_s.type_e);

    if (0 == depthBufferId_u32)
    {
      // No old tex to resize: generate new one
      glGenTextures(1, &depthBufferId_u32);
      Assert(getGLError_b() == false);
    }

    bool_t v_Created_b = (depthBufferId_u32 != 0);
    if (true == v_Created_b)
    {
      glBindTexture(v_TypeGL, depthBufferId_u32);
      Assert(getGLError_b() == false);


      TextureManagerGL* v_TexManGL_po = static_cast<TextureManagerGL*>(renderEngine_po->getTextureManager_po());
      v_TexManGL_po->commitDefaultSamplerStates_v(v_TypeGL, depthBufferId_u32);

      // TODO: Set default sampler states
      //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

      // Rendertargets do not allocate space for mip-map-levels
      //glTexParameteri(v_TypeGL, GL_TEXTURE_MAX_LEVEL, 0);

      switch (desc_s.type_e)
      {
      case e_Tt2D:
      {
        glTexImage2D(v_TypeGL,
          0,
          v_DepthFormatGL, //GL_DEPTH_COMPONENT, 
          desc_s.width_u32,
          desc_s.height_u32,
          0,
          getGLPixelFormat_e(desc_s.depthFormat_e),
          getGLPixelType_e(desc_s.depthFormat_e),
          NULL);
        Assert(getGLError_b() == false);
        break;
      }
      case e_TtCube:  {}         // does not make sense for depth-buffer??
      case e_Tt1D:    {}        // does not make sense for depth-buffer??
      case e_Tt3D:    {}       // does not make sense for depth-buffer??
      case e_Tt2DMultisample: {} // Not supported in OpenGL ES 2.0
      case e_TtUnknown: {}      // fall through
	  default:
			{              // fall through
			Assert(false);
			v_Created_b = false;
			break;
			}
      }

      glBindTexture(v_TypeGL, 0);
    }

    return v_Created_b;
  }

} // namespace me3d
