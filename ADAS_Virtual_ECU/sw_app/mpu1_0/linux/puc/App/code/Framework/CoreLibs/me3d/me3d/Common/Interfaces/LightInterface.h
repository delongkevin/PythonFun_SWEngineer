#ifndef ME3D_LIGHT_INTERFACE_H
#define ME3D_LIGHT_INTERFACE_H

#include "Math/Color.h"

namespace me3d
{
  class LightManager;

  class LightInterface
  {
  public:
    LightInterface();
    ~LightInterface();

    void create_v(LightManager* b_RenderInterface_po);

    // TODO: GUids, more lights
    void msgSetAmbientColor_v(const Color& i_Color_ro)const;
    void msgSetDiffuseColor_v(const Color& i_Color_ro)const;
    void msgSetSpecularColor_v(const Color& i_Color_ro)const;
    void msgSetPos_v(const Vector3f& i_LightPos_ro)const;
    Color msgGetAmbientColor_o() const;
    Color msgGetDiffuseColor_o() const;
    Color msgGetSpecularColor_o() const;

  private:
    LightManager* lightManager_po;
  };


} // namespace me3d

#endif
