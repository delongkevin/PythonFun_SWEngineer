#ifndef ME3D_MATERIAL_H
#define ME3D_MATERIAL_H

#include "Common/Materials/MaterialTypes.h"
#include "Common/Effect/EffectFileTypes.h"

namespace me3d
{
  class RenderEngine;
}

namespace me3d
{
  // A Material defines  Which shader to use for rendering this material.
  // The specific values for the shader’s parameters - such as which texture maps, the colour and numeric values to use.
  class Material
  {
  public:
    Material();
    virtual ~Material();

    bool_t create_b(RenderEngine* b_RenderEngine_po, const MaterialDesc_s& i_Desc_rs);
    bool_t release_b();

    // adds to reference counter
    void addRef_v();

    void setShaderType_v(Shaders_e i_ShaderType_e);
    Shaders_e getShaderType_e() const;

    void setName_v(const MEString& i_Name_ro);
    const MEString& getName_ro() const;

    // updates constants based on shader type
    static void updateConstants_v();

    const MaterialDesc_s& getDesc_rs() const;
    void setDesc_v(const MaterialDesc_s& i_Desc_rs);

  protected:
    RenderEngine*  renderEngine_po; ///< Render Engine pointer
    MaterialDesc_s desc_s;          ///< Material Descriptor
    uint32_t       refCount_u32;

  };

} // namespace me3d

#endif
