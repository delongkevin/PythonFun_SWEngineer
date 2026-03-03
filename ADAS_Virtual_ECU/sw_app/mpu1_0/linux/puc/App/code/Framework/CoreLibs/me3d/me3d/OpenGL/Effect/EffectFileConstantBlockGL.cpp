#include "OpenGL/Effect/EffectFileConstantBlockGL.h"

#include "OpenGL/Effect/EffectFilePassGL.h"

#include "Common/Resources/Constant.h"
#include "Common/RenderEngine.h"
#include "Common/Manager/ConstantsManager.h"
#include "OpenGL/Device/DeviceGLTypes.h"

namespace me3d
{

EffectFileConstantBlockGL::EffectFileConstantBlockGL()
  : EffectFileConstantBlock()
  , programID_u32(0U)
{

}

EffectFileConstantBlockGL::~EffectFileConstantBlockGL()
{

}

void EffectFileConstantBlockGL::release_v()
{
}



bool EffectFileConstantBlockGL::initialize_b(EffectFilePass* b_Pass_po, EffectFile* b_EffectFile_po)
{

  // PRQA S 3076 1 // Ok here, virtual function is no option here, because other graphics API's like directx don't depend on IDs
  EffectFilePassGL* v_PassGL_po = static_cast<EffectFilePassGL*>(b_Pass_po);
  Assert(v_PassGL_po);

  programID_u32 = v_PassGL_po->getProgramID_u32();
  Assert(programID_u32 != 0U);

  return programID_u32 != 0U;
}

void EffectFileConstantBlockGL::commit_v()
{
  Assert(programID_u32 != 0U);
  glUseProgram(programID_u32);

  GLint v_ActiveUniforms_s32 = 0;
  glGetProgramiv(programID_u32, GL_ACTIVE_UNIFORMS, &v_ActiveUniforms_s32);

  uint32_t v_TextureCount_u32 = 0U;

  const uint32_t c_MaxNameLength_u32 = 64;
  char v_UniformName_ac[c_MaxNameLength_u32 ];
  for (sint32_t v_Uniform_s32 = 0; v_Uniform_s32 < v_ActiveUniforms_s32; ++v_Uniform_s32)
  {
    GLint arraySize       = 0;
    GLenum type           = 0;
    GLsizei actualLength  = 0;
    glGetActiveUniform(programID_u32, v_Uniform_s32, c_MaxNameLength_u32, &actualLength, &arraySize, &type, &v_UniformName_ac[0]);
    Assert(getGLError_b() == false);

    GLint v_Location_s32 = glGetUniformLocation(programID_u32, &v_UniformName_ac[0]);
    Assert(getGLError_b() == false);
    Assert(v_Location_s32 != -1);

    Constant* v_Constant_po = findLocalOrGlobalConstant_po(&v_UniformName_ac[0]);

    if ((NULL == v_Constant_po) ||
        (NULL == v_Constant_po->getData_pv()))
    {
      continue;
    }


    uint32_t v_Count_u32 = v_Constant_po->getDesc_rs().count_u32;
    switch (type)
    {
    case GL_FLOAT_MAT4:
      {
        Assert(v_Constant_po->getType_e() == e_CtMatrix4);
        glUniformMatrix4fv(v_Location_s32, v_Count_u32, GL_FALSE, reinterpret_cast<const GLfloat*>(v_Constant_po->getData_pv()));
        break;
      }
    case GL_FLOAT_MAT3:
      {
        Assert(v_Constant_po->getType_e() == e_CtMatrix3);
        glUniformMatrix3fv(v_Location_s32, v_Count_u32, GL_FALSE, reinterpret_cast<const GLfloat*>(v_Constant_po->getData_pv()));
        break;
      }
    case GL_FLOAT:
      {
        Assert(v_Constant_po->getType_e() == e_CtFloat1);
        glUniform1fv(v_Location_s32, v_Count_u32, reinterpret_cast<const GLfloat*>(v_Constant_po->getData_pv()));
        break;
      }
    case GL_FLOAT_VEC2:
      {
        Assert(v_Constant_po->getType_e() == e_CtFloat2);
        glUniform2fv(v_Location_s32, v_Count_u32, reinterpret_cast<const GLfloat*>(v_Constant_po->getData_pv()));
        break;
      }
    case GL_FLOAT_VEC3:
      {
        Assert(v_Constant_po->getType_e() == e_CtFloat3);
        glUniform3fv(v_Location_s32, v_Count_u32, reinterpret_cast<const GLfloat*>(v_Constant_po->getData_pv()));
        break;
      }
    case GL_FLOAT_VEC4:
      {
        Assert(v_Constant_po->getType_e() == e_CtFloat4);
        glUniform4fv(v_Location_s32, v_Count_u32, reinterpret_cast<const GLfloat*>(v_Constant_po->getData_pv()));
        break;
      }
    case GL_BOOL:
      {
        Assert(v_Constant_po->getType_e() == e_CtInt1);
        bool_t v_HasTex_b = *reinterpret_cast<const bool_t*>(v_Constant_po->getData_pv());
        GLint v_BoolVal_s32 = v_HasTex_b ? 1 : 0;


        glUniform1iv(v_Location_s32, v_Count_u32, &v_BoolVal_s32);
        break;
      }
    case GL_SAMPLER_2D:   // fall through
    case GL_SAMPLER_CUBE:
    case GL_SAMPLER_EXTERNAL_OES:
      {
        Assert(v_Constant_po->getType_e() == e_CtTexture);
        const TextureConstant_s* v_TextureConstant_po = reinterpret_cast<const TextureConstant_s*>(v_Constant_po->getData_pv());
        if (NULL != v_TextureConstant_po)
        {
          ITextureConstantData* v_TexConstData_po = v_TextureConstant_po->object_po;
          if (NULL != v_TexConstData_po)
          {
            glActiveTexture(GL_TEXTURE0 + v_TextureCount_u32);
            Assert(getGLError_b() == false);

            GLuint* v_TextureID_pu32 = reinterpret_cast<GLuint*>(v_TexConstData_po->getTexture_pv(v_TextureConstant_po->bufferType_e));

            glBindTexture(getGLTextureType_e(v_TexConstData_po->getTextureType_e()), *v_TextureID_pu32);
            Assert(getGLError_b() == false);

            glUniform1i(v_Location_s32, v_TextureCount_u32);
            Assert(getGLError_b() == false);
          }
        }
        else
        {

          glActiveTexture(GL_TEXTURE0 + v_TextureCount_u32);
          Assert(getGLError_b() == false);

          // Reset all texture types
          for (uint8_t i = 0; i < e_TtUnknown; ++i)
          {
            glBindTexture(getGLTextureType_e(static_cast<TextureType_e>(i)), 0);
          }

        }

        ++v_TextureCount_u32;

        break;
      }

    default:
      {
        Assert(false);
        break;
      }

    } // switch
    Assert(getGLError_b() == false);

  } // for

}

} // namespace me3d
