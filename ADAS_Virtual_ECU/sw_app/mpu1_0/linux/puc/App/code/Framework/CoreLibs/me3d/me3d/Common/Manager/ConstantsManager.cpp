#include "Common/Manager/ConstantsManager.h"

// PRQA S 5118 EOF // C++14 Autosar Standard permits

namespace me3d
{

ConstantsManager::ConstantsManager()
  : IManager()
{

}

ConstantsManager::~ConstantsManager()
{

}

bool_t ConstantsManager::isEnabled_b()
{
  return true;
}

bool ConstantsManager::create_b(RenderEngine* b_RenderEngine_po)
{
  return true;
}

void ConstantsManager::release_v()
{
  // Clear all constants
	size_t sizeVal = sharedConstants_t.size();
  for (size_t i = 0; i < sizeVal; ++i)
  {
    delete sharedConstants_t[i];
  }

  sharedConstants_t.clear();
}

void ConstantsManager::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{

}

void ConstantsManager::beginFrame_v()
{

}

void ConstantsManager::preRender_v()
{

}

} // namespace me3d
