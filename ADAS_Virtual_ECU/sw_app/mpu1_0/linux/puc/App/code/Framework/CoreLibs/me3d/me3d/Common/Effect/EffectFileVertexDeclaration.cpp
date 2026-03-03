#include "Common/Effect/EffectFileVertexDeclaration.h"

#include <platform/PlatformAPI.h>

namespace me3d
{

EffectFileVertexDeclaration::EffectFileVertexDeclaration()
  : effectFile_po(NULL)
{

}

EffectFileVertexDeclaration::~EffectFileVertexDeclaration()
{

}

void EffectFileVertexDeclaration::release_v()
{

}

bool EffectFileVertexDeclaration::create_b(EffectFilePass* b_Pass_po, EffectFile* b_Effect_po)
{
  effectFile_po = b_Effect_po;

  return true;
}

} // namespace me3d