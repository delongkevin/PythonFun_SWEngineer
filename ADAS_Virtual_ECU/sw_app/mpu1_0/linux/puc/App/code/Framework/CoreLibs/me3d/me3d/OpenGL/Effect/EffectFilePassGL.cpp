#include "OpenGL/Effect/EffectFilePassGL.h"

#include "OpenGL/Effect/EffectFileShaderGL.h"
#include "Common/Effect/EffectFileConstantBlock.h"
#include "Common/Effect/EffectFile.h"
#include "Common/Effect/EffectFileParser.h"


namespace me3d
{

EffectFilePassGL::EffectFilePassGL()
  : EffectFilePass()
  , programID_u32(0U)
{

}

EffectFilePassGL::~EffectFilePassGL()
{

}

void EffectFilePassGL::release_v()
{
  if (programID_u32 != 0U)
  {
    glDeleteProgram(programID_u32);
    Assert(getGLError_b() == false);

    programID_u32 = 0;
  }

  EffectFilePass::release_v();
}

bool EffectFilePassGL::create_b(EffectFileShader* i_Shaders_ap[/*e_EFT_Count*/], EffectFile* b_EffectFile_po)
{
  bool v_Success_b = EffectFilePass::create_b(i_Shaders_ap, b_EffectFile_po);

  // create shader program
  programID_u32 = glCreateProgram();
  Assert(getGLError_b() == false);

  // attach Vertex and Pixel shader
  // PRQA S 3076 3 // Ok here, virtual function is no option here, because other graphics API's like directx don't depend on IDs
  // PRQA S 3706 2 // Ok here, subscript operator is always in enum range
  EffectFileShaderGL* v_VertexShader_po = static_cast<EffectFileShaderGL*>(i_Shaders_ap[e_EftVertex]);
  EffectFileShaderGL* v_PixelShader_po  = static_cast<EffectFileShaderGL*>(i_Shaders_ap[e_EftPixel]);

  glAttachShader(programID_u32, v_VertexShader_po->getShaderID_u32());
  Assert(getGLError_b() == false);

  glAttachShader(programID_u32, v_PixelShader_po->getShaderID_u32());
  Assert(getGLError_b() == false);

  // Bind Shader Attribute location
  const ShaderInput_s* c_Attributes_ps = b_EffectFile_po->getParser_po()->getAttributes_ps();
  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_Attributes_ps->numElements_u32; ++v_I_u32)
  {
    glBindAttribLocation(programID_u32, v_I_u32, &c_Attributes_ps->elements_as[v_I_u32].name_ac[0]);
    Assert(getGLError_b() == false);
  }

  // Link the program
  glLinkProgram(programID_u32);
  Assert(getGLError_b() == false);

  // Check link status
  GLint v_linked_s32;
  glGetProgramiv(programID_u32, GL_LINK_STATUS, &v_linked_s32);
  Assert(getGLError_b() == false);

  if (0 == v_linked_s32)
  {
    const GLsizei v_BufSize_s32 = 1024;
    GLchar  v_ErrorBuffer_ac[v_BufSize_s32];
    GLsizei v_ErrorLength_s32;
    glGetProgramInfoLog(programID_u32, v_BufSize_s32, &v_ErrorLength_s32, &v_ErrorBuffer_ac[0]);

#ifdef __WINDOWS
    OutputDebugString(v_ErrorBuffer_ac);
#else
    ME_Debugger_F_Printf_v("%s", &v_ErrorBuffer_ac[0]);
#endif

    Assert(false);
    v_Success_b = false;
  }

  glUseProgram(programID_u32);
  Assert(getGLError_b() == false);

  constantBlock_po->initialize_b(this, b_EffectFile_po);

  return v_Success_b;
}

bool EffectFilePassGL::begin_b()
{
  bool v_Success_b = 0 != programID_u32;
  Assert(v_Success_b);

  glUseProgram(programID_u32);
  Assert(getGLError_b() == false);

  if (v_Success_b)
  {
    v_Success_b = EffectFilePass::begin_b();
  }


  return v_Success_b;
}

void EffectFilePassGL::end_v()
{
  EffectFilePass::end_v();
}

uint32_t EffectFilePassGL::getProgramID_u32() const
{
  return programID_u32;
}

} // namepsace me3D
