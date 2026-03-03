#include "EffectFileConstantBlock.h"

namespace me3d
{

EffectFileConstantBlock::EffectFileConstantBlock()
  : effectFile_po(NULL)
{

}

EffectFileConstantBlock::~EffectFileConstantBlock()
{

}

bool EffectFileConstantBlock::create_v(EffectFilePass* b_Pass_po, EffectFile* b_EffectFile_po)
{
  effectFile_po = b_EffectFile_po;

  return true;
}

} // namespace me3d
