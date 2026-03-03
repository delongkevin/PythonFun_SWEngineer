#include "OpenGL/Effect/EffectFileShaderGL.h"

namespace me3d
{



EffectFileShaderGL::EffectFileShaderGL()
  : EffectFileShader()
  , shaderID_u32(0U)
{

}

EffectFileShaderGL::~EffectFileShaderGL()
{
  // PRQA S 4261 2 // This function doesn't throw any exceptions.
  // PRQA S 4631 1 // This function doesn't throw any exceptions.
  release_v();
}

void EffectFileShaderGL::release_v()
{
  if (shaderID_u32 != 0U)
  {
    glDeleteShader(shaderID_u32);
    Assert(getGLError_b() == false);

    shaderID_u32 = 0U;
  }

  EffectFileShader::release_v();
}

bool EffectFileShaderGL::compile_b(const char* i_ShaderSource_pc, EffectFileType_e i_EffectFileType_e)
{
  bool v_Success_b = EffectFileShader::compile_b(i_ShaderSource_pc, i_EffectFileType_e);

  // create the shader depending on type
  GLenum glShaderType = ((i_EffectFileType_e == e_EftVertex) ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
  shaderID_u32 = glCreateShader(glShaderType);
  Assert(getGLError_b() == false);
  
  // Load the source code
  glShaderSource(shaderID_u32, 1, &i_ShaderSource_pc, NULL);
  Assert(getGLError_b() == false);

  // Compile shader source code
  glCompileShader(shaderID_u32);
  Assert(getGLError_b() == false);

  // Check shader compilation status
  GLint shaderCompiled;
  glGetShaderiv(shaderID_u32, GL_COMPILE_STATUS, &shaderCompiled);
  Assert(getGLError_b() == false);

  if (false == shaderCompiled)
  {
    // retrieve the length of the error msg
    sint32_t errorLength_s32 = 0;
    glGetShaderiv(shaderID_u32, GL_INFO_LOG_LENGTH, &errorLength_s32);
    Assert(getGLError_b() == false);

    const uint32_t c_ErrorMsgLength_u32 = 512U;
    char_t v_ErrorMsg_ac[c_ErrorMsgLength_u32];
    sint32_t v_CharsWritten_s32 = 0;
    glGetShaderInfoLog(shaderID_u32, c_ErrorMsgLength_u32, &v_CharsWritten_s32, &v_ErrorMsg_ac[0]);
    Assert(getGLError_b() == false);

#ifdef __WINDOWS
    OutputDebugString(v_ErrorMsg_ac);
#else
    ME_Debugger_F_Printf_v("%s", &v_ErrorMsg_ac[0]);
#endif

    v_Success_b = false;
    Assert(false);
  }

  return v_Success_b;
}

GLuint EffectFileShaderGL::getShaderID_u32() const
{
  return shaderID_u32;
}

} // namespace me3d
