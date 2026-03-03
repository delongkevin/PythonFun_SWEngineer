#include "MaterialManager.h"
#include "Common/Materials/Material.h"
#include "Common/ResourceHandler/ResourceHandler.h"

// PRQA S 1051 EOF // Work in Progress, leave the code for now
// PRQA S 3222 EOF // Work in Progress, leave the code for now
// PRQA S 5118 EOF // Work in Progress, leave the code for now
// PRQA S 4327 EOF // Work in Progress, leave the code for now
// PRQA S 4212 EOF // Work in Progress, leave the code for now

namespace me3d
{

MaterialManager::MaterialManager()
  : IManager()
{
}

MaterialManager::~MaterialManager()
{
}

bool MaterialManager::create_b(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;

  return (NULL != renderEngine_po);
}

bool_t MaterialManager::isEnabled_b()
{
  return true;
}

void MaterialManager::release_v()
{

}

void MaterialManager::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{

}

void MaterialManager::beginFrame_v()
{

}

void MaterialManager::preRender_v()
{

}


// Material* MaterialManager::getMaterial_po(MaterialID_t i_ID_t)
// {
//   Material* v_FoundMaterial_po = NULL;
// 
//   size_t v_NumMaterials_t = materials_t.size();
//   for (size_t v_I_t = 0U; v_I_t < v_NumMaterials_t; ++v_I_t)
//   {
//     Material* v_Current_po = materials_t[v_I_t];
//     if (NULL != v_Current_po)
//     {
//       if (v_Current_po->getId_t() == i_ID_t)
//       {
//         v_FoundMaterial_po = v_Current_po;
//         break;
//       }
//     }
//   }
// 
//   Assert(NULL != v_FoundMaterial_po);
//   return v_FoundMaterial_po;
// }
// 
// 
// Material* MaterialManager::getMaterial_po(const MEString& i_Name_ro)
// {
//   Material* v_FoundMaterial_po = NULL;
// 
//   size_t v_NumMaterials_t = materials_t.size();
//   for (size_t v_I_t = 0U; v_I_t < v_NumMaterials_t; ++v_I_t)
//   {
//     Material* v_Current_po = materials_t[v_I_t];
// 
//     if (NULL != v_Current_po)
//     {
//       bool v_HasFileName_b  = (false == v_Current_po->getName_ro().isEmpty_b());
//       bool v_SameFileName_b = (i_Name_ro == v_Current_po->getName_ro());
// 
//       if (v_HasFileName_b && v_SameFileName_b)
//       {
//         v_FoundMaterial_po = v_Current_po;
//         break;
//       }
//     }
//   }
// 
//   return v_FoundMaterial_po;
// }

Material* MaterialManager::createMaterial_po(const MaterialDesc_s& i_Desc_rs)
{
  // make sure we have not yet created the texture, use find texture instead
  Material* v_Material_po = NULL; //getMaterial_po(i_Desc_rs.name_o);

//   if (NULL == v_Material_po)
//   {
//     v_Material_po = new Material();
// 
//     if (true == v_Material_po->create_b(renderEngine_po, i_Desc_rs))
//     {
//       materials_t.push_back(v_Material_po);
//     }
//   }
// 
//   Assert(NULL != v_Material_po);
// 
//   // add reference counter
//   v_Material_po->addRef_v();

  return v_Material_po;
}

Material* MaterialManager::createMaterial_po(const MEString& i_Name_ro)
{
  MaterialResource_s* v_MatRes_ps = me3d::ResourceHandler::get_po()->findResourceByName_po<MaterialResource_s>(i_Name_ro);

  Assert(NULL != v_MatRes_ps);

  return createMaterial_po(v_MatRes_ps->desc_s);
}


void MaterialManager::releaseMaterial_v(Material* b_Material_po)
{
  // TODO: Refcount
  size_t v_NumMaterials_t = materials_t.size();
  for (uint32_t v_Material_t = 0U; v_Material_t < v_NumMaterials_t; ++v_Material_t)
  {
    Material* v_Current_po = materials_t[v_Material_t];

    if (materials_t[v_Material_t] == b_Material_po)
    {
      if (true == v_Current_po->release_b())
      {
        // Erase from the list (replace with last list element)
        materials_t[v_Material_t] = materials_t.back();
        materials_t.pop_back();

        delete b_Material_po;
      }

      break;
    }
  }
}

} // namspace me3d