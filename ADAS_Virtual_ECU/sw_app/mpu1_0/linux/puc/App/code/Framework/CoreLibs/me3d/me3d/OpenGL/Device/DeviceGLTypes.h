//--------------------------------------------------------------------------                                                                                                           
/// @file DeviceGLTypes.h                                                                         
/// @brief Maps OpenGL specific enumerations to me3d enumerations
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef DEVICE_GL_TYPES_H
#define DEVICE_GL_TYPES_H

#include "Common/Device/Device3DTypes.h"
#include "OpenGL/GLIncludes.h"

namespace me3d
{


static GLenum getGLTextureType_e(TextureType_e i_TextureType_e)
{
  GLenum v_GLTextureType_e = GL_FALSE;

  switch (i_TextureType_e)
  {
  case e_Tt1D:
    {
      // Not supported
      Assert(false);
      v_GLTextureType_e = GL_FALSE;
      break;
    }
  case e_Tt2D:
    {
      v_GLTextureType_e = GL_TEXTURE_2D;
      break;
    }
  case e_Tt3D:
    {
      // Not supported
      Assert(false);
      v_GLTextureType_e = GL_FALSE;
      break;
    }
  case e_TtCube:
    {
      v_GLTextureType_e = GL_TEXTURE_CUBE_MAP;
      break;
    }
  case e_Tt2DMultisample:
    {
      v_GLTextureType_e = GL_TEXTURE_2D_MULTISAMPLE;
      break;
    }
  case e_TtExternal:
    {
      v_GLTextureType_e = GL_TEXTURE_EXTERNAL_OES;
      break;
    }
  default:
    {
      Assert(false);
      break;
    }
  }

  Assert(GL_FALSE != v_GLTextureType_e);
  return v_GLTextureType_e;
}

static GLenum getGLPixelType_e(mepl::PixelFormat_e i_ResourceFormat_e)
{
  using namespace mepl;

  GLenum v_GLPixelType_e = GL_FALSE;

  switch (i_ResourceFormat_e)
  {
  case e_RfR8G8B8:
    {
      v_GLPixelType_e = GL_UNSIGNED_BYTE;
      break;
    }
  case e_RfR8G8B8A8:
    {
      v_GLPixelType_e = GL_UNSIGNED_BYTE;
      break;
    }
  case e_RfR8:
    {
      v_GLPixelType_e = GL_UNSIGNED_BYTE;
      break;
    }
  case e_RfEtc1:
    {
      v_GLPixelType_e = GL_UNSIGNED_BYTE;
      break;
    }
  case e_RfD16:
    {
      v_GLPixelType_e = GL_UNSIGNED_SHORT;
      break;
    }
  case e_RfR16F:
    {
      v_GLPixelType_e = GL_HALF_FLOAT_OES;
      break;
    }
  case e_RfUnknown: // fall through
  default:
    {
      Assert(false);
      break;
    }
    break;
  }

  Assert(GL_FALSE != v_GLPixelType_e);
  return v_GLPixelType_e;
}


static GLenum getGLPixelFormat_e(mepl::PixelFormat_e i_ResourceFormat_e)
{
  using namespace mepl;

  GLenum v_GLPixelFormat_e = GL_FALSE;

  switch (i_ResourceFormat_e)
  {
  case e_RfR8G8B8:
    {
      v_GLPixelFormat_e = GL_RGB;
      break;
    }
  case e_RfR8G8B8A8:
    {
      v_GLPixelFormat_e = GL_RGBA;
      break;
    }
  case e_RfR8:
    {
      v_GLPixelFormat_e = GL_ALPHA;
      break;
    }
  case e_RfEtc1:
    {
      v_GLPixelFormat_e = GL_RGB;
      break;
    }
  case e_RfD16:
    {
      v_GLPixelFormat_e = GL_DEPTH_COMPONENT;
      break;
    }
  case e_RfR16F:
    {
      v_GLPixelFormat_e = GL_RED_EXT;
      break;
    }
  case e_RfUnknown: // fall through
  default:
    {
      Assert(false);
      break;
    }
    break;
  }

  Assert(GL_FALSE != v_GLPixelFormat_e);
  return v_GLPixelFormat_e;
}

static GLenum getGLTextureResourceFormat_e(mepl::PixelFormat_e i_ResourceFormat_e)
{
  using namespace mepl;

  GLenum v_GLResourceFormat_e = GL_FALSE;

  switch (i_ResourceFormat_e)
  {
  case e_RfR8G8B8:
    {
      v_GLResourceFormat_e = GL_RGB;
      break;
    }
  case e_RfR8G8B8A8:
    {
      v_GLResourceFormat_e = GL_RGBA;
      break;
    }
  case e_RfR8:
    {
      v_GLResourceFormat_e = GL_ALPHA;
      break;
    }
  case e_RfEtc1:
    {
      v_GLResourceFormat_e = GL_ETC1_RGB8_OES;
      break;
    }
  case e_RfD16:
    {
      v_GLResourceFormat_e = GL_DEPTH_COMPONENT;
      break;
    }
  case e_RfUnknown: // fall through
  default:
    {
      v_GLResourceFormat_e = GL_FALSE;
       break;
    }
    break;
  }

  return v_GLResourceFormat_e;
}

static GLenum getGLPrimitiveType_e(PrimitiveType_e i_Type_e)
{
  GLenum v_GlType_e = GL_FALSE; 
  switch (i_Type_e)
  {
  case e_PtPointList:
    {
      v_GlType_e = GL_POINTS;
      break;
    }
  case e_PtLines:
    {
      v_GlType_e = GL_LINES;
      break;
    }
  case e_PtLineStrip:
    {
      v_GlType_e = GL_LINE_STRIP;
      break;
    }
  case e_PtTriangleList:
    {
      v_GlType_e = GL_TRIANGLES;
      break;
    }
  case e_PtTriangleStrip:
    {
      v_GlType_e = GL_TRIANGLE_STRIP;
      break;
    }
  case e_PtLineListAdj:     // fall through
  case e_PtTriangleListAdj: // fall through
  default:
    {
      Assert(false);
      break;
    }
  }

  Assert(GL_FALSE != v_GlType_e);
  return v_GlType_e;
}

static GLenum getGLResourceUsage_e(ResourceUsage_e i_Usage_e)
{
  GLenum v_GlType_e = GL_FALSE; 
  switch (i_Usage_e)
  {
  case e_RuStatic:
    {
      v_GlType_e = GL_STATIC_DRAW;
      break;
    }
  case e_RuDynamic:
    {
      v_GlType_e = GL_DYNAMIC_DRAW;
      break;
    }
  case e_RuStream:
    {
      v_GlType_e = GL_STREAM_DRAW;
      break;
    }
  case e_RuCount: // fall through
  default:
    {
      Assert(false);
      break;
    }
  }

  Assert(GL_FALSE != v_GlType_e);
  return v_GlType_e;
}


}


#endif
