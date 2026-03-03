#include "Common/Manager/ModelManager.h"

 
#include "Common/RenderEngine.h"

namespace me3d
{

ModelManager::ModelManager()
  : IManager()
  , renderEngine_po(NULL)
  , numModelsToRender_u32(0U)
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxModels_u32; ++v_I_u32)
  {
    renderList_apo[v_I_u32] = NULL;
  }

}

ModelManager::~ModelManager()
{

}

bool_t ModelManager::isEnabled_b()
{
  return renderEngine_po->isEnabled_b(e_EftModel);
}

bool ModelManager::create_b(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;

  return true;
}

void ModelManager::release_v()
{

}

void ModelManager::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{

}

void ModelManager::beginFrame_v()
{

}

void ModelManager::preRender_v()
{

}

void ModelManager::reset_v()
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < numModelsToRender_u32; ++v_I_u32)
  {
    renderList_apo[v_I_u32] = NULL;
  }
  numModelsToRender_u32 = 0U;
}

void ModelManager::releaseModel_v(uint32_t i_Id_u32)
{
  Assert(i_Id_u32 < c_MaxModels_u32);

  models_ao[i_Id_u32].release_v();
}

void ModelManager::releaseModel_v(Model* i_Model_po)
{
  Assert(NULL != i_Model_po);
  i_Model_po->release_v();
}

Model* ModelManager::getModel_po(uint32_t i_Id_u32)
{
   Model* v_FoundModel_po = NULL;

   if (i_Id_u32 < c_MaxModels_u32)
   {
     v_FoundModel_po = &models_ao[i_Id_u32];
   }
   else
   {
     Assert(false);
   }

   return  v_FoundModel_po;
}

Model* ModelManager::createModel_po(const MEString& i_FileName_ro)
{
  uint32_t v_Index_u32 = getFreeModelIndex_u32();

  Model* v_Current_po = &models_ao[v_Index_u32];

  v_Current_po->init_v(renderEngine_po, i_FileName_ro);

  return v_Current_po;
}

Model* ModelManager::createModel_po(const ModelDesc_s& i_Desc_rs)
{
  uint32_t v_Index_u32 = getFreeModelIndex_u32();

  Model* v_Current_po = &models_ao[v_Index_u32];

  v_Current_po->init_v(renderEngine_po, i_Desc_rs);

  return v_Current_po;
}

void ModelManager::renderModel_v(Model* i_Model_po)
{
  Assert(numModelsToRender_u32 < c_MaxModels_u32);

  renderList_apo[numModelsToRender_u32] = i_Model_po;

  ++numModelsToRender_u32;
}

uint32_t ModelManager::getFreeModelIndex_u32() const
{
  uint32_t v_FreeIndex_u32 = c_MaxModels_u32;

  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxModels_u32; ++v_I_u32)
  {
    if (false == models_ao[v_I_u32].isInitialized_b())
    {
      v_FreeIndex_u32 = v_I_u32;
      break;
    }
  }

  Assert(v_FreeIndex_u32 != c_MaxModels_u32);
  return v_FreeIndex_u32;
}

} // namespace me3d