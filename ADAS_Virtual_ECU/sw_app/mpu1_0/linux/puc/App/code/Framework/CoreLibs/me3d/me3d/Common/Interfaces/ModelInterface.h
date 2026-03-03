#ifndef MODEL_INTERFACE_H
#define MODEL_INTERFACE_H

#include "MeclTypeDefs.h"
#include "Common/Model/ModelTypes.h"
#include "Math/BBox3D.h"
#include "Math/Color.h"

namespace me3d
{
  class RenderInterface;

  class ModelInterface
  {
  public:
    ModelInterface();
    ~ModelInterface();

    void create_v(RenderInterface* b_RenderInterface_po);

    // Create Model via Filename
    uint32_t msgCreate_u32(const MEString& i_FileName_ro)const;
    // Create Model via Descriptor
    uint32_t msgCreate_u32(const ModelDesc_s& i_Desc_rs)const;
    // Release model 
    void msgRelease_v(uint32_t i_Id_u32)const;
    // Render Model
    void msgRender_v(uint32_t i_Id_u32)const;
    // Set Model Transformation
    void msgSetTransform_v(uint32_t i_Id_u32, const Matrix4f& i_World_ro)const;
    // Get the Number of materials for a given model id
    void msgGetNumMaterials_v(uint32_t i_Id_u32, uint32_t& o_NumMaterials_u32)const;
    void msgSetMaterial_v(uint32_t i_Id_u32, uint32_t i_MaterialIndex_u32, ResourceID_t i_MaterialID_t)const;
    void msgGetMaterial_v(uint32_t i_Id_u32, uint32_t i_MaterialIndex_u32, ResourceID_t& i_MaterialID_rt)const;

    // Get Model Bounding Box
    void msgGetBoundingBox_v(uint32_t i_Id_u32, BBox3D_s& o_Bounds_ro)const;
    // Get Model description
    void msgGetDesc_v(uint32_t i_Id_u32, ModelDesc_s& o_Desc_rs)const;

  private:
    RenderInterface* renderInterface_po;
  };

} // namespace me3d

#endif
