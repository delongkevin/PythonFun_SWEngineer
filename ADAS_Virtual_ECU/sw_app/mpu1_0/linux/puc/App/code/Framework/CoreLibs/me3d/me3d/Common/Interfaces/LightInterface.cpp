#include "Common/Interfaces/LightInterface.h"
#include "Common/RenderInterface.h"
#include "Common/Manager/LightManager.h"

namespace me3d
{
  LightInterface::LightInterface()
    : lightManager_po(NULL)
  {

  }

  LightInterface::~LightInterface()
  {

  }

  void LightInterface::create_v(LightManager* b_RenderInterface_po)
  {
    lightManager_po = b_RenderInterface_po;
  }

  void LightInterface::msgSetAmbientColor_v(const Color& i_Color_ro)const
  {
    lightManager_po->setAmbientColor_v(i_Color_ro);
  }

  void LightInterface::msgSetDiffuseColor_v(const Color& i_Color_ro)const
  {
    lightManager_po->setDiffuseColor_v(i_Color_ro);
  }

  void LightInterface::msgSetSpecularColor_v(const Color& i_Color_ro)const
  {
    lightManager_po->setSpecularColor_v(i_Color_ro);
  }

  void LightInterface::msgSetPos_v(const Vector3f& i_LightPos_ro)const
  {
    lightManager_po->setLightPos_v(i_LightPos_ro);
  }

  Color LightInterface::msgGetAmbientColor_o() const
  {
    return lightManager_po->getAmbientColor_o();
  }

  Color LightInterface::msgGetDiffuseColor_o() const
  {
    return lightManager_po->getDiffuseColor_o();
  }

  Color LightInterface::msgGetSpecularColor_o() const
  {
    return lightManager_po->getSpecularColor_o();
  }

} // namespace me3d