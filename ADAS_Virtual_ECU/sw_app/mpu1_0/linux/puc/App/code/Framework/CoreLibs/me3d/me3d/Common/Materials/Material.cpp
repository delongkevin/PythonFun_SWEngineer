#include "Material.h"
#include "Common/RenderEngine.h"

namespace me3d
{
  Material::Material()
    : renderEngine_po(NULL)
    , desc_s()
    , refCount_u32(0U)
  {
  }

  Material::~Material()
  {
    renderEngine_po = NULL;
    refCount_u32 = 0;
  }

  bool_t Material::create_b(RenderEngine* b_RenderEngine_po, const MaterialDesc_s& i_Desc_rs)
  {
    renderEngine_po = b_RenderEngine_po;
    desc_s = i_Desc_rs;

    return true;
  }

  bool_t Material::release_b()
  {
    --refCount_u32;

    bool_t v_ReadyToDelete_b = false;

    if (refCount_u32 == 0)
    {
      // No other references exist, so ready to delete
      v_ReadyToDelete_b = true;
    }
    else
    {
      // Also other references exist
      v_ReadyToDelete_b = false;
    }

    return v_ReadyToDelete_b;
  }

  void Material::addRef_v()
  {
    ++refCount_u32;
  }

  Shaders_e Material::getShaderType_e() const
  {
    return desc_s.shaderType_e;
  }

  void Material::setShaderType_v(Shaders_e i_ShaderType_e)
  {
    desc_s.shaderType_e = i_ShaderType_e;
  }

  void Material::setName_v(const MEString& i_Name_ro)
  {
    desc_s.name_o = i_Name_ro;
  }

  const MEString& Material::getName_ro() const
  {
    return desc_s.name_o;
  }

  void Material::updateConstants_v()
  {
  }

  const MaterialDesc_s& Material::getDesc_rs() const
  {
    return desc_s;
  }

  void Material::setDesc_v(const MaterialDesc_s& i_Desc_rs)
  {
    Assert(desc_s.name_o == i_Desc_rs.name_o);
    desc_s = i_Desc_rs;
  }

} // namespace me3d