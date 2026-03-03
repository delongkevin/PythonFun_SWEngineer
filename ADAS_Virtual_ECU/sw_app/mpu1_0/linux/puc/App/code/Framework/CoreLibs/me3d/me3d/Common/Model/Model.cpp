#include "Common/Model/Model.h"

#include "Common/Model/ModelTypes.h"
#include "Common/Model/Animation.h"
#include "Common/Model/Mesh.h"
#include "Common/RenderEngine.h"
#include "Common/Manager/BufferManager.h"
#include "Common/Manager/TextureManager.h"
#include "Common/Manager/MaterialManager.h"
#include "Common/Resources/VertexBuffer.h"
#include "Common/Resources/IndexBuffer.h"
#include "Common/Resources/ITextureConstantData.h"
#include "Common/Resources/Constant.h"
#include "Common/Effect/EffectFile.h"
#include "Common/ResourceHandler/ResourceHandler.h"
#include "Math/MathLib.h"

// PRQA S 5118 EOF // C++14 autosar standard permits.
// PRQA S 3706 EOF // performance

namespace me3d
{

Model::Model()
  : renderEngine_po(NULL)
  , desc_s()
  , transform_o()
  , boundingBox_s()
  , initialized_b(false)
  , animationIndex_u32(0U)
  , runningTimeSeconds_f32(0.0F)
{

}

Model::~Model()
{

}

void Model::init_v(RenderEngine* b_RenderEngine_po, const ModelDesc_s& i_Desc_rs)
{
  renderEngine_po = b_RenderEngine_po;

  // flat copy is ok here
  desc_s = i_Desc_rs;

  // reset bounding box
  boundingBox_s.init_v();
  transform_o = Matrix4f();

  numMeshes_u32 = desc_s.numMeshes_u32;
  meshes_ao = new Mesh[numMeshes_u32];

  for (uint32_t v_I_u32 = 0U; v_I_u32 < numMeshes_u32; ++v_I_u32)
  {
    // create vertex and index buffers
    // PRQA S 3706 2 // subscript operator ok here due to numMeshes
    MeshData_s* v_MeshData_ps = desc_s.meshData_ps[v_I_u32];

    meshes_ao[v_I_u32].init_v(renderEngine_po, *v_MeshData_ps);

    // update bounding box
    boundingBox_s = BBox3D_s::union_s(boundingBox_s, meshes_ao[v_I_u32].getBounds_ro());
  }

  // ready for rendering
  initialized_b = true;
}

void Model::init_v(RenderEngine* b_RenderEngine_po, const MEString& i_FileName_ro)
{
  ModelResource_s* v_ModelRes_ps = me3d::ResourceHandler::get_po()->findResourceByName_po<ModelResource_s>(i_FileName_ro);

  if (NULL != v_ModelRes_ps)
  {
    init_v(b_RenderEngine_po, v_ModelRes_ps->desc_s);
  }
  else
  {
    ME_Debugger_F_Printf_v("Model::init_v -- Model Resource not found %s \n", i_FileName_ro.getString_pc());
  }
}

void Model::release_v()
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < numMeshes_u32; ++v_I_u32)
  {
    meshes_ao[v_I_u32].release_v();
  }

  delete[] meshes_ao;
  meshes_ao = NULL;

  initialized_b = false;
}

bool Model::intersectRay_b(const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro)const
{
  float32_t v_Distance_f32;
  Vector3f  v_Intersection_o;

  // compute transformed aabb
  BBox3D_s v_TransformedBB_s = boundingBox_s.transform_s(transform_o);

  return intersectRayAABB_b(i_RayOrigin_ro, i_RayDir_ro, v_TransformedBB_s.min_o, v_TransformedBB_s.max_o, &v_Distance_f32, &v_Intersection_o);
}

Mesh* Model::getMesh_po(uint32_t i_Index_u32)const
{
  // PRQA S 4623 2 // intended here
  // PRQA S 3706 1 // intended here
  return &meshes_ao[i_Index_u32];
}

void Model::boneTransform_v(me3d::Matrix4f* o_Transforms_po, uint32_t i_MaxTransforms_u32)
{
  if (NULL != desc_s.animationData_ps)
  {
    // TODO: get elapsed time in seconds, update runningTime in separate function in ModelManager
    runningTimeSeconds_f32 += 0.005F;

    Animation* v_Animation_ps     = desc_s.animationData_ps->animations_apo[animationIndex_u32];
    float32_t v_TicksPerSec       = static_cast<float32_t>(v_Animation_ps->getTicksPerSec_f64());
    float32_t v_TimeInTicks       = runningTimeSeconds_f32 * v_TicksPerSec;
    float32_t v_AnimationTime_f32 = fmod(v_TimeInTicks, static_cast<float32_t>(v_Animation_ps->getDuration_f64()));

    me3d::Matrix4f v_Identity_o;
    readNodeHierarchy_v(animationIndex_u32, v_AnimationTime_f32, 0U, v_Identity_o);

    Assert(desc_s.animationData_ps->numBones_u32 < i_MaxTransforms_u32);
    for (uint32_t v_BoneIndex_u32 = 0U; v_BoneIndex_u32 < desc_s.animationData_ps->numBones_u32; ++v_BoneIndex_u32) 
    {
      o_Transforms_po[v_BoneIndex_u32] = desc_s.animationData_ps->boneInfos_as[v_BoneIndex_u32].finalTransformation_o;
    }
  }
}

void Model::readNodeHierarchy_v(uint32_t i_AnimationIndex_u32, float32_t i_AnimationTime_f32, uint32_t pNode, const Matrix4f& ParentTransform)
{
  Assert(pNode < me3d::c_MaxNodes_u32);
  me3d::Node_s* v_CurrentNode_ps = &desc_s.animationData_ps->nodes_as[pNode];

  const MEString& c_NodeName_ro = v_CurrentNode_ps->name_o;

  Animation* c_Animation_po = desc_s.animationData_ps->animations_apo[i_AnimationIndex_u32];

  Matrix4f v_NodeTransformation_o = v_CurrentNode_ps->transformation_o;

  const AnimationChannel* c_AnimationChannel_ps = c_Animation_po->findAnimationChannel_ps(c_NodeName_ro);

  if (NULL != c_AnimationChannel_ps) 
  {
    c_AnimationChannel_ps->getTransformMatrix_v(v_NodeTransformation_o, i_AnimationTime_f32);
  }

  me3d::Matrix4f v_GlobalTransformation_o = v_NodeTransformation_o.mmulFast(ParentTransform);

  uint32_t v_BoneIndex_u32 = findBoneIndex_u32(c_NodeName_ro);
  if (me3d::c_MaxBones_u32 != v_BoneIndex_u32)
  {
    me3d::Matrix4f v_FinalTransformMat_o = desc_s.animationData_ps->boneInfos_as[v_BoneIndex_u32].boneOffset_o.mmulFast(v_GlobalTransformation_o);
    v_FinalTransformMat_o = v_FinalTransformMat_o.mmulFast(desc_s.animationData_ps->globalInverseTransform_o);
    desc_s.animationData_ps->boneInfos_as[v_BoneIndex_u32].finalTransformation_o = v_FinalTransformMat_o;
  }

  for (uint32_t v_Child_u32 = 0 ; v_Child_u32 < v_CurrentNode_ps->numChildren_u32; v_Child_u32++) 
  {
    readNodeHierarchy_v(i_AnimationIndex_u32, i_AnimationTime_f32, v_CurrentNode_ps->children_au32[v_Child_u32], v_GlobalTransformation_o);
  }
}

uint32_t Model::findBoneIndex_u32(const MEString& i_Name_ro)const
{
  uint32_t v_BoneIndex_u32 = me3d::c_MaxBones_u32;

  for (uint32_t v_Bone_u32 = 0U; v_Bone_u32 < desc_s.animationData_ps->numBones_u32; ++v_Bone_u32)
  {
    if (desc_s.animationData_ps->boneInfos_as[v_Bone_u32].name_o == i_Name_ro)
    {
      v_BoneIndex_u32 = v_Bone_u32;
      break;
    }
  }

  return v_BoneIndex_u32;
}

} // namespace me3d
