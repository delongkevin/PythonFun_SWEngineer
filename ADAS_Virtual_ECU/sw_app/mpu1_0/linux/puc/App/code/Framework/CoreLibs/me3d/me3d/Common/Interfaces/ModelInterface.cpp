#include "Common/Interfaces/ModelInterface.h"
#include "Common/RenderInterface.h"
#include "Common/Manager/ModelManager.h"
#include "Common/ResourceHandler/ResourceHandler.h"


// PRQA S 3706 EOF // performance

namespace me3d
{

  ModelInterface::ModelInterface()
    : renderInterface_po(NULL)
  {

  }

  ModelInterface::~ModelInterface()
  {

  }

  void ModelInterface::create_v(RenderInterface* b_RenderInterface_po)
  {
    renderInterface_po = b_RenderInterface_po;
    Assert(NULL != renderInterface_po);
  }

  uint32_t ModelInterface::msgCreate_u32(const MEString& i_FileName_ro)const
  {
    // return invalid id on failure
    uint32_t v_ID_u32 = RenderInterface::c_InvalidGUID_u32;

    Model* v_Model_po = renderInterface_po->renderEngine_o.getModelManager_po()->createModel_po(i_FileName_ro);

    if (NULL != v_Model_po)
    {
      v_ID_u32 = renderInterface_po->guidGenerator_o.getFreeID_u32();

      renderInterface_po->setAtID_v(v_ID_u32, reinterpret_cast<void*>(v_Model_po), e_OtModel);
    }

    Assert(v_ID_u32 != RenderInterface::c_InvalidGUID_u32);

    return v_ID_u32;
  }

  uint32_t ModelInterface::msgCreate_u32(const ModelDesc_s& i_Desc_rs)const
  {
    // return invalid id on failure
    uint32_t v_ID_u32 = RenderInterface::c_InvalidGUID_u32;

    Model* v_Model_po = renderInterface_po->renderEngine_o.getModelManager_po()->createModel_po(i_Desc_rs);

    if (NULL != v_Model_po)
    {
      v_ID_u32 = renderInterface_po->guidGenerator_o.getFreeID_u32();

      renderInterface_po->setAtID_v(v_ID_u32, reinterpret_cast<void*>(v_Model_po), e_OtModel);
    }

    return v_ID_u32;
  }

  void ModelInterface::msgRelease_v(uint32_t i_Id_u32)const
  {
    Model* v_Model_po = reinterpret_cast<Model*>(renderInterface_po->clearID_pv(i_Id_u32, e_OtModel));

    Assert(NULL != v_Model_po);

    renderInterface_po->renderEngine_o.getModelManager_po()->releaseModel_v(v_Model_po);
  }

  void ModelInterface::msgRender_v(uint32_t i_Id_u32)const
  {
    Model* v_Model_po = reinterpret_cast<Model*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtModel));

    Assert(NULL != v_Model_po);

    renderInterface_po->renderEngine_o.getModelManager_po()->renderModel_v(v_Model_po);
  }

  void ModelInterface::msgSetTransform_v(uint32_t i_Id_u32, const Matrix4f& i_World_ro)const
  {
    Model* v_Model_po = reinterpret_cast<Model*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtModel));

    Assert(NULL != v_Model_po);

    v_Model_po->setTransform_v(i_World_ro);
  }

  void ModelInterface::msgGetNumMaterials_v(uint32_t i_Id_u32, uint32_t& o_NumMaterials_u32)const
  {
    Model* v_Model_po = reinterpret_cast<Model*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtModel));

    Assert(NULL != v_Model_po);

    o_NumMaterials_u32 = v_Model_po->getDesc_ro().numMaterials_u32;
  }


  void ModelInterface::msgSetMaterial_v(uint32_t i_Id_u32, uint32_t i_MaterialIndex_u32, ResourceID_t i_MaterialID_t)const
  {
    Model* v_Model_po = reinterpret_cast<Model*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtModel));

    Assert(NULL != v_Model_po);

    Assert(i_MaterialIndex_u32 < v_Model_po->getDesc_ro().numMaterials_u32);

    MaterialResource_s* v_Resource_ps = ResourceHandler::get_po()->findResourceByID_po<MaterialResource_s>(i_MaterialID_t);

    if (NULL != v_Resource_ps)
    {
      v_Model_po->getDesc_ro().materials_ao[i_MaterialIndex_u32] = i_MaterialID_t;
    }

  }

  void ModelInterface::msgGetMaterial_v(uint32_t i_Id_u32, uint32_t i_MaterialIndex_u32, ResourceID_t& i_MaterialID_rt)const
  {
    Model* v_Model_po = reinterpret_cast<Model*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtModel));

    Assert(NULL != v_Model_po);

    Assert(i_MaterialIndex_u32 < v_Model_po->getDesc_ro().numMaterials_u32);

    MaterialResource_s* v_Resource_ps = ResourceHandler::get_po()->findResourceByID_po<MaterialResource_s>(v_Model_po->getDesc_ro().materials_ao[i_MaterialIndex_u32]);

    if (NULL != v_Resource_ps)
    {
      i_MaterialID_rt = v_Resource_ps->resourceID_t;
    }
  }

  void ModelInterface::msgGetBoundingBox_v(uint32_t i_Id_u32, BBox3D_s& o_Bounds_ro)const
  {
    Model* v_Model_po = reinterpret_cast<Model*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtModel));

    Assert(NULL != v_Model_po);

    o_Bounds_ro = v_Model_po->getBoundingBox_ro();
  }

  void ModelInterface::msgGetDesc_v(uint32_t i_Id_u32, ModelDesc_s& o_Desc_rs)const
  {
    Model* v_Model_po = reinterpret_cast<Model*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtModel));

    Assert(NULL != v_Model_po);

    o_Desc_rs = v_Model_po->getDesc_ro();
  }


} // namespace me3d