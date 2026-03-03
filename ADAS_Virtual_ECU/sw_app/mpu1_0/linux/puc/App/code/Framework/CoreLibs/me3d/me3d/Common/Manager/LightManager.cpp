#include "Common/Manager/LightManager.h"
#include "Common/RenderEngine.h"
#include "Common/Manager/ConstantsManager.h"

// PRQA S 3103 EOF // works as designed, constats store a void ptr, cast is needed

namespace me3d
{

LightManager::LightManager()
  : IManager()
  , renderEngine_po(NULL)
  , lightConstants_s()
{

}

LightManager::~LightManager()
{

}

bool_t LightManager::isEnabled_b()
{
  return true;
}

bool LightManager::create_b(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;

  lightConstants_s.ambient_po   = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cLight.Ambient",  e_CtFloat3, 1));
  lightConstants_s.diffuse_po   = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cLight.Diffuse",  e_CtFloat3, 1));
  lightConstants_s.specular_po  = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cLight.Specular", e_CtFloat3, 1));
  lightConstants_s.position_po  = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cLight.Position", e_CtFloat3, 1));

  // set default values
  setAmbientColor_v(Color::White);
  setDiffuseColor_v(Color::White);
  setSpecularColor_v(Color::White);
  setLightPos_v(Vector3f(100.0F, 150.0F, 150.0F));

  return true;
}

void LightManager::release_v()
{

}

void LightManager::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{

}

void LightManager::beginFrame_v()
{

}

void LightManager::preRender_v()
{

}

void LightManager::setAmbientColor_v(const Color& i_Color_ro) const
{
  Vector3f v_Col_o = i_Color_ro.toVec3_o();
  lightConstants_s.ambient_po->setData_v(&v_Col_o);
}

void LightManager::setDiffuseColor_v(const Color& i_Color_ro) const
{
  Vector3f v_Col_o = i_Color_ro.toVec3_o();
  lightConstants_s.diffuse_po->setData_v(&v_Col_o);
}

void LightManager::setSpecularColor_v(const Color& i_Color_ro) const
{
  Vector3f v_Col_o = i_Color_ro.toVec3_o();
  lightConstants_s.specular_po->setData_v(&v_Col_o);
}

void LightManager::setLightPos_v(const Vector3f& i_LightPos_ro) const
{
  lightConstants_s.position_po->setData_v(&i_LightPos_ro);
}

Color LightManager::getAmbientColor_o() const
{
  const Vector3f* v_ColorData_o = reinterpret_cast<const Vector3f*>(lightConstants_s.ambient_po->getData_pv());

  return Color(v_ColorData_o->getPosX(), v_ColorData_o->getPosY(), v_ColorData_o->getPosZ(), 1.0F);
}

Color LightManager::getDiffuseColor_o() const
{
  const Vector3f* v_ColorData_o = reinterpret_cast<const Vector3f*>(lightConstants_s.diffuse_po->getData_pv());

  return Color(v_ColorData_o->getPosX(), v_ColorData_o->getPosY(), v_ColorData_o->getPosZ(), 1.0F);
}

Color LightManager::getSpecularColor_o() const
{
  const Vector3f* v_ColorData_o = reinterpret_cast<const Vector3f*>(lightConstants_s.specular_po->getData_pv());

  return Color(v_ColorData_o->getPosX(), v_ColorData_o->getPosY(), v_ColorData_o->getPosZ(), 1.0F);
}

} // namespace me3d
