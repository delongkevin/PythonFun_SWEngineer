#include "Common/Renderer/ViewRenderer.h"

#include "Common/RenderEngine.h"
#include "Common/Manager/ViewManager.h"

#include "Common/ResourceHandler/ResourceHandler.h"
#include "Common/Device/Device3DTypes.h"

namespace me3d
{

  ViewRenderer::ViewRenderer()
    : IRenderer()
    , renderEngine_po(NULL)
  {

  }

  ViewRenderer::~ViewRenderer()
  {

  }

  bool_t ViewRenderer::isEnabled_b()
  {
    return renderEngine_po->isEnabled_b(e_EftBowlView);
  }

  bool ViewRenderer::create_b(RenderEngine* b_RenderEngine_po)
  {
    renderEngine_po = b_RenderEngine_po;

    return true;
  }

  void ViewRenderer::release_v()
  {

  }

  void ViewRenderer::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
  {

  }

  void ViewRenderer::beginFrame_v()
  {

  }

  void ViewRenderer::reset_v()
  {

  }

  void ViewRenderer::renderAll_v()const
  {
    const ViewList_t& c_List_ro = renderEngine_po->getViewManager_po()->getRenderList_t();

    for (size_t v_I_t = 0; v_I_t < c_List_ro.size(); ++v_I_t)
    {
      BaseView* v_View_po = c_List_ro[v_I_t];
      Assert(v_View_po != NULL);
      v_View_po->render_v();
    }
  }

} // namespace me3d