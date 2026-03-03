#include "Common/Renderer/GuideLineRenderer.h"

#include "Common/RenderEngine.h"
#include "Common/Device/Device3D.h"
#include "Common/Manager/GuideLineManager.h"
#include "Common/Manager/ShaderManager.h"
#include "Common/Manager/ConstantsManager.h"
#include "Common/Manager/CameraManager.h"
#include "Common/Resources/VertexBuffer.h"
#include "Common/Resources/IndexBuffer.h"
#include "Common/Effect/EffectFileRenderStateBlock.h"


namespace me3d
{

GuideLineRenderer::GuideLineRenderer()
  : IRenderer()
  , renderEngine_po(NULL)
  , effect_po(NULL)
  , renderStateBlock_po(NULL)
  , constantGuideLineWVP_po(NULL)
  , constantColor_po(NULL)
{
}

GuideLineRenderer::~GuideLineRenderer()
{
}

bool_t GuideLineRenderer::isEnabled_b()
{
  return renderEngine_po->isEnabled_b(e_EftGuideLine);
}

bool GuideLineRenderer::create_b(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;

  // create effect and set constants
  effect_po                = renderEngine_po->getShaderManager_po()->createShader_po(e_ShaderGuideLine);
  constantColor_po         = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cGuideLineColor", e_CtFloat4, 1U));
  constantGuideLineWVP_po  = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cGuideLineWVP", e_CtMatrix4, 1U));

  renderStateBlock_po = renderEngine_po->getShaderManager_po()->createRenderStateBlock_po();
  renderStateBlock_po->addState_b(EffectFileRenderState_s(e_EfstAlphaBlendEnable, EffectFileStateValue_s(e_EfsvTrue), 0));    
  renderStateBlock_po->addState_b(EffectFileRenderState_s(e_EfstSrcBlend, EffectFileStateValue_s(e_EfsvSrcAlpha), 0));
  renderStateBlock_po->addState_b(EffectFileRenderState_s(e_EfstDestBlend, EffectFileStateValue_s(e_EfsvOneMinusSrcAlpha), 0));
  renderStateBlock_po->addState_b(EffectFileRenderState_s(e_EfstZEnable, EffectFileStateValue_s(e_EfsvFalse), 0));


  return true;
}

void GuideLineRenderer::release_v()
{
  effect_po                      = NULL;
  renderStateBlock_po            = NULL;
  constantGuideLineWVP_po        = NULL;
  constantColor_po               = NULL;
}

void GuideLineRenderer::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{

}

void GuideLineRenderer::beginFrame_v()
{

}

void GuideLineRenderer::reset_v()
{

}

void GuideLineRenderer::renderAll_v() const
{
  const GuideLineList_t& c_List_ro = renderEngine_po->getGuideLineManager_po()->getRenderList_t();

  for (size_t v_I_t = 0; v_I_t < c_List_ro.size(); ++v_I_t)
  {
    GuideLineObject* v_GuideLine_po = c_List_ro[v_I_t];
    Assert(v_GuideLine_po != NULL);

    VertexBuffer* v_VertexBuffer_po = v_GuideLine_po->getVertexBuffer_po();
    IndexBuffer* v_IndexBuffer_po = v_GuideLine_po->getIndexBuffer_po();

    if ((NULL != v_VertexBuffer_po) &&
        (NULL != v_IndexBuffer_po))
    {
      // Update Constants 
      if(v_GuideLine_po->getUseOrthoProj_b() == false)
      {
        Matrix4f v_WVP_o;
        const Matrix4f& c_VP_ro = renderEngine_po->getCameraManager_po()->getCamera_ro().getViewProjMat_ro();
        v_WVP_o = v_GuideLine_po->getWorldMatrix_ro().mmulFast(c_VP_ro);
        constantGuideLineWVP_po->setData_v(&v_WVP_o);
      }
      else
      {
        ViewPortDesc_s v_ViewPortDesc_s;
        renderEngine_po->getDevice_po()->getViewPort_b(v_ViewPortDesc_s);
        const Matrix4f c_VP_ro = Matrix4f::createOrtho(1.0F, static_cast<float32_t>(v_ViewPortDesc_s.width_u32), 
                                                        0.0F, static_cast<float32_t>(v_ViewPortDesc_s.height_u32), 
                                                        -100.0F, 100.0F);
        constantGuideLineWVP_po->setData_v(&c_VP_ro);
      }

      const Color& c_Color_ro = v_GuideLine_po->getColor_ro();
      constantColor_po->setData_v(&c_Color_ro);

      v_VertexBuffer_po->set_v(0);
      v_IndexBuffer_po->set_v();

      // begin rendering
      effect_po->setRenderStateBlock_v(renderStateBlock_po);
      effect_po->beginPass_b();

      renderEngine_po->getDevice_po()->drawIndexed_v(e_PtTriangleStrip, v_GuideLine_po->getIndexCount_u32(), 0U);

      // end rendering
      effect_po->endPass_v();
    }


  }
}

} // namespace me3d
