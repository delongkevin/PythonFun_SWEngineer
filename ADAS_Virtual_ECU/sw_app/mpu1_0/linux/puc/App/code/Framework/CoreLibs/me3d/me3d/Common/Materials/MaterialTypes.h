#ifndef ME3D_MATERIAL_TYPES_H
#define ME3D_MATERIAL_TYPES_H

#include "MeclTypeDefs.h"
#include "Utilities/InOut.h"
#include "Common/Effect/EffectFileTypes.h"
#include "Math/Color.h"


// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{
  struct MaterialDesc_s
  {
    Shaders_e shaderType_e;             ///< Shader type defines how to render this material
    MEString name_o;                    ///< identifier for each material
    MEString albedoTex_o;               ///< Name of diffuse texture
    MEString normalTex_o;               ///< Name of normal texture
    MEString metallicTex_o;             ///< Name of metallic texture
    MEString roughnessTex_o;            ///< Name of roughness texture
    MEString aoTex_o;                   ///< Name of Ambient Occlusion texture
    Color ambient_o;                    ///< Ka
    Color albedo_o;                     ///< Kd
    Color specular_o;                   ///< ks  
    float32_t roughness_f32;            ///< roughness value taken if roughness texture was not set
    float32_t metallic_f32;             ///< metallic value taken if no metallic texture was set
    float32_t shininess_f32;            ///< only used in phong
    float32_t opacity_f32;              ///< opacity value

    MaterialDesc_s()
      : shaderType_e(e_ShaderPhongSolid)
      , name_o("Default")
      , albedoTex_o("")
      , normalTex_o("")
      , metallicTex_o("")
      , roughnessTex_o("")
      , aoTex_o("")
      , ambient_o(0.8F, 0.8F, 0.8F, 1.0F)
      , albedo_o(0.8F, 0.8F, 0.8F, 1.0F)
      , specular_o(0.8F, 0.8F, 0.8F, 1.0F)
      , roughness_f32(1.0F)
      , metallic_f32(1.0F)
      , shininess_f32(10.0F)
      , opacity_f32(1.0F)
    {
    }

    void serialize_v(InOut& b_IO_ro)
    {
      b_IO_ro.serializeEnum_v(shaderType_e);
      b_IO_ro.serialize_v(name_o);
      b_IO_ro.serialize_v(albedoTex_o);
      b_IO_ro.serialize_v(normalTex_o);
      b_IO_ro.serialize_v(metallicTex_o);
      b_IO_ro.serialize_v(roughnessTex_o);
      b_IO_ro.serialize_v(aoTex_o);
      b_IO_ro.serialize_v(ambient_o);
      b_IO_ro.serialize_v(albedo_o);
      b_IO_ro.serialize_v(specular_o);
      b_IO_ro.serialize_v(roughness_f32);
      b_IO_ro.serialize_v(metallic_f32);
      b_IO_ro.serialize_v(shininess_f32);
      b_IO_ro.serialize_v(opacity_f32);
    }
  };

} // namespace me3d

#endif
