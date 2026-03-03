#include "Common/Manager/ViewManager.h"

#include "Common/RenderEngine.h"
#include "Common/ResourceHandler/ResourceHandler.h"
#include "Common/Resources/MultipleRenderTarget.h"
#include "Common/Effect/EffectFileRenderStateBlock.h"
#include "Common/Manager/TextureManager.h"
#include "Common/Manager/GUIManager.h"

#include "Common/View/BowlView.h"
#include "Common/View/BowlViewCPU.h"
#include "Common/View/BowlView.h"
#include "Common/View/SingleView.h"



#include <algorithm>


// PRQA S 5118 EOF // C++ 14 Autosar standard permits
// PRQA S 3223 EOF // stl design
// PRQA S 3077 EOF // by design

namespace me3d
{

ViewManager::ViewManager()
  : IManager()
  , renderStateAlphaBlend_po(NULL)
  , renderStateDisableDepth_po(NULL)
  , renderEngine_po(NULL)
{
  viewList_apo.clear();
}

  ViewManager::~ViewManager()
  {

  }

  bool_t ViewManager::isEnabled_b()
  {
    return renderEngine_po->isEnabled_b(e_EftBowlView);
  }

  bool ViewManager::create_b(RenderEngine* b_RenderEngine_po)
  {
    renderEngine_po = b_RenderEngine_po;

    renderStateAlphaBlend_po = renderEngine_po->getShaderManager_po()->createRenderStateBlock_po();
    renderStateAlphaBlend_po->addState_b(EffectFileRenderState_s(e_EfstAlphaBlendEnable,          EffectFileStateValue_s(e_EfsvTrue),             0));
    renderStateAlphaBlend_po->addState_b(EffectFileRenderState_s(e_EfstSrcBlend,                  EffectFileStateValue_s(e_EfsvSrcAlpha),         0));
    renderStateAlphaBlend_po->addState_b(EffectFileRenderState_s(e_EfstDestBlend,                 EffectFileStateValue_s(e_EfsvOneMinusSrcAlpha), 0));
    renderStateAlphaBlend_po->addState_b(EffectFileRenderState_s(e_EfstZFunc,                     EffectFileStateValue_s(e_EfsvLEqual),           0));

    // Blend Func for alpha must be equal to 1, because we don't want to write alpha values into the FrameBuffer (FPGA may blend this with its background color)
    renderStateAlphaBlend_po->addState_b(EffectFileRenderState_s(e_EfstSeparateAlphaBlendEnable,  EffectFileStateValue_s(e_EfsvTrue),             0));
    renderStateAlphaBlend_po->addState_b(EffectFileRenderState_s(e_EfstBlendOp,                   EffectFileStateValue_s(e_EfsvAdd),      0));
    renderStateAlphaBlend_po->addState_b(EffectFileRenderState_s(e_EfstBlendOpAlpha,              EffectFileStateValue_s(e_EfsvMax),      0));


    // no depth for obscuration zone
    renderStateDisableDepth_po = renderEngine_po->getShaderManager_po()->createRenderStateBlock_po();
    renderStateDisableDepth_po->addState_b(EffectFileRenderState_s(e_EfstZFunc, EffectFileStateValue_s(e_EfsvLEqual), 0));



    return true;
  }

  void ViewManager::release_v()
  {

  }

  void ViewManager::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
  {
	size_t v_size = viewList_apo.size();
    for (size_t v_I_t = 0; v_I_t < v_size; ++v_I_t)
    {
      BaseView* v_View_po = viewList_apo[v_I_t];
      Assert(v_View_po != NULL);

      v_View_po->onResize_v();
    }
  }

  void ViewManager::beginFrame_v()
  {

  }

  void ViewManager::preRender_v()
  {
  }

bool_t ViewManager::beginScene_b()
{
  return false;
}

void ViewManager::endScene_v()
{
}

void ViewManager::reset_v()
{
  // reset render list 
  size_t v_size = renderList_apo.size();
  for (size_t i = 0; i < v_size; ++i)
  {
    renderList_apo[i] = NULL;
  }

  renderList_apo.clear();
}

BaseView* ViewManager::createBowlView_po(const BowlViewDesc_s& i_Desc_rs)
{
    BaseView* v_View_po = NULL;
    
     if (i_Desc_rs.type_e == e_BvtBowlCPU)
     {
      BowlViewCPU* v_BowlViewCPU_po = new BowlViewCPU();
      v_BowlViewCPU_po->create_b(i_Desc_rs, renderEngine_po, renderStateAlphaBlend_po, renderStateDisableDepth_po);
      v_View_po = v_BowlViewCPU_po;
     }
     else
     {
       BowlView* v_BowlView_po = new BowlView();
       v_BowlView_po->create_b(i_Desc_rs, renderEngine_po);
       v_View_po = v_BowlView_po;
     }

    Assert(NULL != v_View_po);
    viewList_apo.push_back(v_View_po);
    

    return v_View_po;
  }

  BaseView* ViewManager::createSingleView_po(const SingleViewDesc_s& i_Desc_rs)
  {
    SingleView* v_SingleView_po = new SingleView();

    if(NULL != v_SingleView_po)
    {
      v_SingleView_po->create_b(i_Desc_rs, renderEngine_po);

      viewList_apo.push_back(v_SingleView_po);
    }

    return v_SingleView_po;
  }

  void ViewManager::releaseView_v(BaseView* i_View_po)
  {
    ViewList_t::iterator v_It_o = std::find(viewList_apo.begin(), viewList_apo.end(), i_View_po);
    if (v_It_o != viewList_apo.end())
    {
      BaseView* v_View_po = (*v_It_o);

      viewList_apo.erase(v_It_o); 

      v_View_po->release_v();

      delete v_View_po;
    }
    else
    {
      // Trying to release view not in list
      Assert(false);
    }

  }

  const ViewList_t& ViewManager::getViewList_ro() const
  {
    return viewList_apo;
  }

  bool ViewManager::intersectRay_b(const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro, Vector3f& o_Intersection_ro)
  {
    return viewList_apo[0]->intersectRay_b(i_RayOrigin_ro, i_RayDir_ro, o_Intersection_ro);
  }

  void ViewManager::modifyHeight_v(float32_t i_X_f32, float32_t i_Z_f32, float32_t i_Height_f32, float32_t i_Radius_f32)
  {
    // PRQA S 4234 1 // this is just editor functionality
    for (float32_t v_Z_f32 = i_Z_f32 - i_Radius_f32; v_Z_f32 < (i_Z_f32 + i_Radius_f32); ++v_Z_f32)
    {
      // PRQA S 4234 1 // this is just editor functionality
      for (float32_t v_X_f32 = i_X_f32 - i_Radius_f32; v_X_f32 < (i_X_f32 + i_Radius_f32); ++v_X_f32)
      {
        float32_t v_Xdist_f32 = v_X_f32 - i_X_f32;
        float32_t v_Zdist_f32 = v_Z_f32 - i_Z_f32;

        v_Xdist_f32 *= v_Xdist_f32;
        v_Zdist_f32 *= v_Zdist_f32;

        if ((v_Xdist_f32 + v_Zdist_f32) <= (i_Radius_f32 * i_Radius_f32))
        {
          viewList_apo[0]->setHeight_b(v_X_f32, v_Z_f32, i_Height_f32);
        }
      }
    }

    BowlViewCPU* v_BowlViewCPU_po = dynamic_cast<BowlViewCPU*>(viewList_apo[0]);
    if (v_BowlViewCPU_po)
    {
      viewList_apo[0]->update_v(e_VufConstants);
    }
    else
    {
      viewList_apo[0]->update_v(e_VufAll);
    }


    viewList_apo[0]->createBuffers_v(false, false);
  }

void ViewManager::setRender_v(BaseView* i_View_po)
{
  ViewList_t::iterator v_It_o = std::find(renderList_apo.begin(), renderList_apo.end(), i_View_po);
  if (v_It_o == renderList_apo.end())
  {
    renderList_apo.push_back(i_View_po);
  }
}

} // namespace me3d
