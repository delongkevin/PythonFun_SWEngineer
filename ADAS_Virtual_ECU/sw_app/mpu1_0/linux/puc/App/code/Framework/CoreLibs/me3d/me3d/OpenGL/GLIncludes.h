//--------------------------------------------------------------------------                                                                                                           
/// @file GLIncludes.h                                                                         
/// @brief OpenGL ES 2 and EGL includes. Provides Error checks
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef GL_INCLUDES_H
#define GL_INCLUDES_H

#if defined RE_USE_OPENGLES30
  #include <GLES3/gl3.h>
#else
  #include <GLES2/gl2.h>
#endif

#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES
#endif
#include <GLES2/gl2ext.h>



#include <EGL/egl.h>
#include <EGL/eglext.h>

 

namespace me3d
{

  inline const char_t* getGLErrorMsg_pc(GLenum i_ErrorCode_e)
  {
    const char_t* c_Error_pc = "No Error";

    switch (i_ErrorCode_e)
    {
    case GL_NO_ERROR:
      {
        c_Error_pc = "No Error";
        break;
      }
    case GL_INVALID_ENUM:
      {
        c_Error_pc = "Invalid Enum";
        break;
      }
    case GL_INVALID_OPERATION:
      {
        c_Error_pc = "Invalid Operation";
        break;
      }
    case GL_INVALID_VALUE:
      {
        c_Error_pc = "Invalid Value - Numeric argument is out of range";
        break;
      }
    case GL_STACK_OVERFLOW_KHR:
      {
        c_Error_pc = "Stack Overflow";
        break;
      }
    case GL_STACK_UNDERFLOW_KHR:
      {
        c_Error_pc = "Stack Underflow";
        break;
      }
    case GL_OUT_OF_MEMORY:
      {
        c_Error_pc = "Out of Memory";
        break;
      }
    default:
      {
        Assert(false);
        c_Error_pc = "Error code Unknown";
        break;
      }
    }

    return c_Error_pc;
  }

  inline const char_t* getFBOStatus_pc(GLenum i_ErrorCode_e)
  {
    const char_t* c_FboStatus_pc = "No Error";

    switch (i_ErrorCode_e)
    {
    case GL_FRAMEBUFFER_COMPLETE:
      {
        c_FboStatus_pc = "FrameBuffer complete";
        break;
      }
    case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
      {
        c_FboStatus_pc = "Incomplete Attachment";
        break;
      }
    case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
      {
        c_FboStatus_pc = "Incomplete Missing Attachment";
        break;
      }
    case GL_FRAMEBUFFER_UNSUPPORTED:
      {
        c_FboStatus_pc = "Not Supported";
        break;
      }
    default:
      {
        Assert(false);
        c_FboStatus_pc = "Unknown Error";
        break;
      }
    }

    return c_FboStatus_pc;
  }

  inline bool_t getGLError_b()
  {
    bool_t v_Result_b = false;
#ifdef _DEBUG

    GLenum v_ErrorIndex = glGetError();
    while(v_ErrorIndex != GL_NO_ERROR)
    {
#ifdef _WINDOWS
      OutputDebugString(getGLErrorMsg_pc(v_ErrorIndex));
#else
      printf("%s", getGLErrorMsg_pc(v_ErrorIndex));
#endif

      v_ErrorIndex = glGetError();
      v_Result_b = true;
    }
#endif

    return v_Result_b;
  }


} // namespace me3d

#endif
