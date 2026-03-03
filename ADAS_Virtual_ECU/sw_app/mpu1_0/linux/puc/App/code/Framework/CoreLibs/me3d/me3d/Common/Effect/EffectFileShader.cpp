#include "EffectFileShader.h"

 

namespace me3d
{


EffectFileShader::EffectFileShader()
  : effectFileType_e(e_EftInvalid)
{
}

EffectFileShader::~EffectFileShader()
{

}

void EffectFileShader::release_v()
{
}

bool EffectFileShader::compile_b(const char* i_ShaderSource_pc, EffectFileType_e i_EffectFileType_e)
{
  effectFileType_e = i_EffectFileType_e;
  Assert(effectFileType_e != e_EftInvalid);

  return effectFileType_e != e_EftInvalid;
}

} // namespace me3d