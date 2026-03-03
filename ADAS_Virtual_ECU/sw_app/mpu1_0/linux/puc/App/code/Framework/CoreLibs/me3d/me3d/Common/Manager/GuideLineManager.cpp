#include "Common/Manager/GuideLineManager.h"

#include "Common/RenderEngine.h"
#include "Common/Manager/BufferManager.h"

#include "Common/Resources/VertexDeclarationTypes.h"
#include "Common/Resources/VertexBuffer.h"

// PRQA S 5118 EOF // C++ 14 Autosar standard permits.
// PRQA S 3223 EOF // no modification

namespace me3d
{


GuideLineManager::GuideLineManager()
  : IManager()
  , renderEngine_po(NULL)
{
  guideLineList_apo.clear();
}

GuideLineManager::~GuideLineManager()
{
}

bool_t GuideLineManager::isEnabled_b()
{
  return renderEngine_po->isEnabled_b(e_EftGuideLine);
}

bool GuideLineManager::create_b(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;

  return true;
}

void GuideLineManager::release_v()
{

}

void GuideLineManager::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{
}

void GuideLineManager::beginFrame_v()
{

}

void GuideLineManager::preRender_v()
{
}

void GuideLineManager::reset_v()
{
  // reset render list 
	
  size_t v_size = renderList_apo.size();
  for (size_t i = 0; i < v_size; ++i)
  {
    renderList_apo[i] = NULL;
  }

  renderList_apo.clear();
}

GuideLineObject* GuideLineManager::createGuideLine_po(const GuideLineObjectDesc_s& i_Desc_ro)
{
  GuideLineObject* v_GuideLineObject_po = new GuideLineObject();
  Assert(NULL != v_GuideLineObject_po);

  v_GuideLineObject_po->create_b(renderEngine_po, i_Desc_ro);

  guideLineList_apo.push_back(v_GuideLineObject_po);

  return v_GuideLineObject_po;
}

void GuideLineManager::releaseGuideLine_v(GuideLineObject* i_GuideLine_po)
{
  GuideLineList_t::iterator v_It_o = std::find(guideLineList_apo.begin(), guideLineList_apo.end(), i_GuideLine_po);
  if (v_It_o != guideLineList_apo.end())
  {
    GuideLineObject* v_GuideLine_po = (*v_It_o);

    guideLineList_apo.erase(v_It_o); 

    v_GuideLine_po->release_v();

    delete v_GuideLine_po;
  }
  else
  {
    // Trying to release view not in list
    Assert(false);
  }
}

void GuideLineManager::setRender_v(GuideLineObject* i_GuideLine_po)
{
  GuideLineList_t::iterator v_It_o = std::find(renderList_apo.begin(), renderList_apo.end(), i_GuideLine_po);
  if (v_It_o == renderList_apo.end())
  {
    renderList_apo.push_back(i_GuideLine_po);
  }
}

} // namespace me3d


