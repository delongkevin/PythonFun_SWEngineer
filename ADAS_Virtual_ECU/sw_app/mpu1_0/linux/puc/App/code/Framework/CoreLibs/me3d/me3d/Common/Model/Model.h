//--------------------------------------------------------------------------                                                                                                           
/// @file Model.h                                                                         
/// @brief Contains Model Data and functions to render the model. Calculates Bounding box
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef MODEL_H
#define MODEL_H

#include "Common/Model/ModelTypes.h"
#include "Common/Resources/Constant.h"
#include "Common/Device/Device3DTypes.h"
#include "MeclTypeDefs.h"
#include "Math/BBox3D.h"
#include "Math/Transform.h"

namespace me3d
{

class RenderEngine;
class Mesh;

class Model
{
public:
  Model();
  ~Model();

  void init_v(RenderEngine* b_RenderEngine_po, const MEString& i_FileName_ro);
  void init_v(RenderEngine* b_RenderEngine_po, const ModelDesc_s& i_Desc_rs);

  void release_v();

  bool intersectRay_b(const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro)const;

  ME_INLINE const BBox3D_s& getBoundingBox_ro() const            { return boundingBox_s;                   }
  ME_INLINE const Matrix4f& getWorldMatrix_ro() const            { return transform_o;                     }
  ME_INLINE const ModelDesc_s& getDesc_ro()     const            { return desc_s;                          }
  ME_INLINE bool isInitialized_b()              const            { return initialized_b;                   }
  ME_INLINE void setTransform_v(const Matrix4f& i_Transform_ro)  { transform_o = i_Transform_ro;           }
  ME_INLINE bool isAnimated_b()                 const            { return NULL != desc_s.animationData_ps; }
  ME_INLINE uint32_t getNumMeshes_u32()         const            { return numMeshes_u32;                   }
  Mesh* getMesh_po(uint32_t i_Index_u32)const;

  void boneTransform_v(me3d::Matrix4f* o_Transforms_po, uint32_t i_MaxTransforms_u32);

private:
  void readNodeHierarchy_v(uint32_t i_AnimationIndex_u32, float32_t i_AnimationTime_f32, uint32_t pNode, const Matrix4f& ParentTransform);
  uint32_t findBoneIndex_u32(const MEString& i_Name_ro)const;

private:
  RenderEngine* renderEngine_po;
  ModelDesc_s   desc_s;
  Mesh*         meshes_ao;
  uint32_t      numMeshes_u32;
  Matrix4f      transform_o;
  BBox3D_s      boundingBox_s;
  bool          initialized_b;
  uint32_t      animationIndex_u32;
  float32_t     runningTimeSeconds_f32;
};

} // namespace me3d

#endif
