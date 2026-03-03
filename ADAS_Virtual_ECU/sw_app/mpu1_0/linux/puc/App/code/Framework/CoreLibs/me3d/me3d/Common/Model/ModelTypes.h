//--------------------------------------------------------------------------                                                                                                           
/// @file ModelTypes.h                                                                         
/// @brief Defines structures used by Model class
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef MODEL_TYPES_H
#define MODEL_TYPES_H

#include "Common/Resources/VertexDeclarationTypes.h"

#include <platform/PlatformAPI.h>
#include <string.h>

#include "RenderEngineCfg.h"
#include "Utilities/InOut.h"
#include "MeclTypeDefs.h"

#include "Common/Model/Animation.h"
#include "Common/ResourceHandler/ResourceTypes.h"
#include "Common/Materials/MaterialTypes.h"

// PRQA S 2100 EOF // public members used here by design.
// PRQA S 5118 EOF // Autosar c++14 standard allows usage of dynamic memory allocation, makes sense to use here, 3D has lots of data...
// PRQA S 3706 EOF // subscript operator intended here for model data

namespace me3d
{

class VertexBuffer;
class IndexBuffer;
class Texture;

enum MeshDataType_e
{
  e_MdtPosTexNorm = 0,
  e_MdtPosTexNormTangent,
  e_MdtCount
};

struct MeshData_s
{
  uint32_t            indexCount_u32;
  uint16_t*           indices_pu16;
  uint32_t            vertexCount_u32;
  uint32_t            materialIndex_u32;

  MeshData_s()
    : indexCount_u32(0U)
    , indices_pu16(NULL)
    , vertexCount_u32(0U)
    , materialIndex_u32(0U)
  {

  }

  void serialize_v(InOut& b_IO_ro)
  {
    // indices
    b_IO_ro.serialize_v(indexCount_u32);
    if (b_IO_ro.isLoading_b())
    {
      indices_pu16 = new uint16_t[indexCount_u32];
      Assert(NULL != indices_pu16);
    }
    b_IO_ro.serializeFixedArray_v(reinterpret_cast<uint8_t*>(indices_pu16), indexCount_u32 * sizeof(uint16_t));

    // material index
    b_IO_ro.serialize_v(materialIndex_u32);

    // vertex count 
    b_IO_ro.serialize_v(vertexCount_u32);

    // virtual vertex serialization
    onSerialize_v(b_IO_ro);
  }

  virtual void onSerialize_v(InOut& b_IO_ro) = 0;
  virtual void allocateVertexData_v() = 0;
  virtual Vector3f getPosition_o(uint32_t i_Index_u32) const = 0;
  virtual void setPosition_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32) = 0;
  virtual void setNormals_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32) = 0;
  virtual void setTexCoords_v(uint32_t i_Index_u32, float32_t i_U_f32, float32_t i_V_f32) = 0;
  virtual void setTangent_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32) = 0;
  virtual void setBitangent_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32) = 0;
  virtual const void* getVertices_pv() const = 0;
  virtual uint32_t getStride_u32() const = 0;
  virtual const char* getLayout_pc() const = 0;
};

struct MeshDataPosTexNorm_s : public MeshData_s
{
  VertexPosTexNorm_s* vertices_ps;

  MeshDataPosTexNorm_s()
    : MeshData_s()
    , vertices_ps(NULL)
  {
  }

  virtual void onSerialize_v(InOut& b_IO_ro)
  {
    // vertices
    if (b_IO_ro.isLoading_b())
    {
      vertices_ps = new VertexPosTexNorm_s[vertexCount_u32];
      Assert(NULL != vertices_ps);
    }
    b_IO_ro.serializeFixedArray_v(reinterpret_cast<uint8_t*>(vertices_ps), vertexCount_u32 * sizeof(VertexPosTexNorm_s));
  }


  virtual void allocateVertexData_v()
  {
    vertices_ps = new VertexPosTexNorm_s[vertexCount_u32];
  }

  virtual void setPosition_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
  {
    VertexPosTexNorm_s* v_Vertex_ps = &vertices_ps[i_Index_u32];

    v_Vertex_ps->position_af32[0] = i_X_f32;
    v_Vertex_ps->position_af32[1] = i_Y_f32;
    v_Vertex_ps->position_af32[2] = i_Z_f32;
  }

  virtual void setNormals_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
  {
    VertexPosTexNorm_s* v_Vertex_ps = &vertices_ps[i_Index_u32];

    v_Vertex_ps->normals_af32[0] = i_X_f32;
    v_Vertex_ps->normals_af32[1] = i_Y_f32;
    v_Vertex_ps->normals_af32[2] = i_Z_f32;
  }

  virtual void setTexCoords_v(uint32_t i_Index_u32, float32_t i_U_f32, float32_t i_V_f32)
  {
    VertexPosTexNorm_s* v_Vertex_ps = &vertices_ps[i_Index_u32];

    v_Vertex_ps->texCoords_af32[0] = i_U_f32;
    v_Vertex_ps->texCoords_af32[1] = i_V_f32;
  }

  virtual void setTangent_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
  {
  }

  virtual void setBitangent_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
  {
  }

  virtual const void* getVertices_pv() const
  {
    return &vertices_ps[0];
  }

  virtual Vector3f getPosition_o(uint32_t i_Index_u32) const
  {
    VertexPosTexNorm_s* v_Vertex_ps = &vertices_ps[i_Index_u32];
    return Vector3f(v_Vertex_ps->position_af32[0], v_Vertex_ps->position_af32[1], v_Vertex_ps->position_af32[2]);
  }


  virtual uint32_t getStride_u32() const
  {
    return sizeof(VertexPosTexNorm_s);
  }


  virtual const char* getLayout_pc() const
  {
    static const char* s_Layout_pc = "P3f_T2f_N3f";
    return s_Layout_pc;
  }

};

struct MeshDataPosTexNormTangent_s : public MeshData_s
{
  VertexPosTexNormTangent_s* vertices_ps;

  MeshDataPosTexNormTangent_s()
    : MeshData_s()
    , vertices_ps(NULL)
  {
  }

  virtual void onSerialize_v(InOut& b_IO_ro)
  {
    // vertices
    if (b_IO_ro.isLoading_b())
    {
      vertices_ps = new VertexPosTexNormTangent_s[vertexCount_u32];
      Assert(NULL != vertices_ps);
    }

    for (uint32_t v_I_u32 = 0U; v_I_u32 < vertexCount_u32; ++v_I_u32)
    {
      vertices_ps[v_I_u32].serialize_v(b_IO_ro);
    }
  }


  virtual void allocateVertexData_v()
  {
    vertices_ps = new VertexPosTexNormTangent_s[vertexCount_u32];
  }

  virtual void setPosition_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
  {
    VertexPosTexNormTangent_s* v_Vertex_ps = &vertices_ps[i_Index_u32];

    v_Vertex_ps->position_af32[0] = i_X_f32;
    v_Vertex_ps->position_af32[1] = i_Y_f32;
    v_Vertex_ps->position_af32[2] = i_Z_f32;
  }

  virtual void setNormals_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
  {
    VertexPosTexNormTangent_s* v_Vertex_ps = &vertices_ps[i_Index_u32];

    v_Vertex_ps->normals_af32[0] = i_X_f32;
    v_Vertex_ps->normals_af32[1] = i_Y_f32;
    v_Vertex_ps->normals_af32[2] = i_Z_f32;
  }

  virtual void setTexCoords_v(uint32_t i_Index_u32, float32_t i_U_f32, float32_t i_V_f32)
  {
    VertexPosTexNormTangent_s* v_Vertex_ps = &vertices_ps[i_Index_u32];

    v_Vertex_ps->texCoords_af32[0] = i_U_f32;
    v_Vertex_ps->texCoords_af32[1] = i_V_f32;
  }

  virtual void setTangent_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
  {
    VertexPosTexNormTangent_s* v_Vertex_ps = &vertices_ps[i_Index_u32];

    v_Vertex_ps->tangent_af32[0] = i_X_f32;
    v_Vertex_ps->tangent_af32[1] = i_Y_f32;
    v_Vertex_ps->tangent_af32[2] = i_Z_f32;
  }

  virtual void setBitangent_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
  {
    VertexPosTexNormTangent_s* v_Vertex_ps = &vertices_ps[i_Index_u32];

    v_Vertex_ps->biTangent_af32[0] = i_X_f32;
    v_Vertex_ps->biTangent_af32[1] = i_Y_f32;
    v_Vertex_ps->biTangent_af32[2] = i_Z_f32;
  }

  virtual const void* getVertices_pv() const
  {
    return &vertices_ps[0];
  }

  virtual Vector3f getPosition_o(uint32_t i_Index_u32) const
  {
    VertexPosTexNormTangent_s* v_Vertex_ps = &vertices_ps[i_Index_u32];
    return Vector3f(v_Vertex_ps->position_af32[0], v_Vertex_ps->position_af32[1], v_Vertex_ps->position_af32[2]);
  }

  virtual uint32_t getStride_u32() const
  {
    return sizeof(VertexPosTexNormTangent_s);
  }

  virtual const char* getLayout_pc() const
  {
    static const char* s_Layout_pc = "P3f_T2f_N3f_G3f_B3f";
    return s_Layout_pc;
  }
};


struct MeshDataAnimated_s : public MeshData_s
{
  VertexAnimated_s* vertices_ps;

  MeshDataAnimated_s()
    : MeshData_s()
    , vertices_ps(NULL)
  {
  }

  virtual void onSerialize_v(InOut& b_IO_ro)
  {
    // vertices
    if (b_IO_ro.isLoading_b())
    {
      vertices_ps = new VertexAnimated_s[vertexCount_u32];
      Assert(NULL != vertices_ps);
    }

    for (uint32_t v_I_u32 = 0U; v_I_u32 < vertexCount_u32; ++v_I_u32)
    {
      vertices_ps[v_I_u32].serialize_v(b_IO_ro);
    }
  }

  virtual void allocateVertexData_v()
  {
    vertices_ps = new VertexAnimated_s[vertexCount_u32];
  }

  virtual void setPosition_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
  {
    VertexAnimated_s* v_Vertex_ps = &vertices_ps[i_Index_u32];

    v_Vertex_ps->position_af32[0] = i_X_f32;
    v_Vertex_ps->position_af32[1] = i_Y_f32;
    v_Vertex_ps->position_af32[2] = i_Z_f32;
  }

  virtual void setNormals_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
  {
    VertexAnimated_s* v_Vertex_ps = &vertices_ps[i_Index_u32];

    v_Vertex_ps->normals_af32[0] = i_X_f32;
    v_Vertex_ps->normals_af32[1] = i_Y_f32;
    v_Vertex_ps->normals_af32[2] = i_Z_f32;
  }

  virtual void setTexCoords_v(uint32_t i_Index_u32, float32_t i_U_f32, float32_t i_V_f32)
  {
    VertexAnimated_s* v_Vertex_ps = &vertices_ps[i_Index_u32];

    v_Vertex_ps->texCoords_af32[0] = i_U_f32;
    v_Vertex_ps->texCoords_af32[1] = i_V_f32;
  }

  virtual const void* getVertices_pv() const
  {
    return &vertices_ps[0];
  }

  virtual void setTangent_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
  {
  }

  virtual void setBitangent_v(uint32_t i_Index_u32, float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
  {
  }

  virtual Vector3f getPosition_o(uint32_t i_Index_u32) const
  {
    VertexAnimated_s* v_Vertex_ps = &vertices_ps[i_Index_u32];
    return Vector3f(v_Vertex_ps->position_af32[0], v_Vertex_ps->position_af32[1], v_Vertex_ps->position_af32[2]);
  }

  virtual uint32_t getStride_u32() const
  {
    return sizeof(VertexAnimated_s);
  }

  virtual const char* getLayout_pc() const
  {
    static const char* s_Layout_pc = "P3f_T2f_N3f_W4f_P4f";
    return s_Layout_pc;
  }
};


struct Bone_s
{
  Matrix4f boneOffset_o;
  Matrix4f finalTransformation_o;
  MEString name_o;

  void serialize_v(InOut& b_IO_ro)
  {
    b_IO_ro.serialize_v(boneOffset_o);
    // we don't need to serialize finalTransformation. this is just a helper matrix to compute the final transformation
    b_IO_ro.serialize_v(name_o);
  }
};

struct Node_s
{
  Matrix4f transformation_o;

  uint32_t numChildren_u32;
  uint32_t children_au32[c_MaxNodeChildren_u32];
  MEString name_o;


  void serialize_v(InOut& b_IO_ro)
  {
    b_IO_ro.serialize_v(transformation_o);
    b_IO_ro.serialize_v(numChildren_u32);
    b_IO_ro.serializeArray_v(&children_au32[0], numChildren_u32);
    b_IO_ro.serialize_v(name_o);
  }

};

struct AnimationData_s
{
  uint32_t        numBones_u32;  
  uint32_t        numAnimations_u32;
  uint32_t        numNodes_u32;
  Bone_s          boneInfos_as[c_MaxBones_u32];
  Animation*      animations_apo[c_MaxAnimations_u32];
  Node_s          nodes_as[c_MaxNodes_u32];
  Matrix4f        globalInverseTransform_o;

  AnimationData_s()
    : numBones_u32(0U)
    , numAnimations_u32(0U)
    , numNodes_u32(0U)
  {
  }

  void serialize_v(InOut& b_IO_ro) 
  {
    b_IO_ro.serialize_v(numBones_u32);
    b_IO_ro.serialize_v(numAnimations_u32);
    b_IO_ro.serialize_v(numNodes_u32);

    // bones
    for (uint32_t v_I_u32 = 0U; v_I_u32 < numBones_u32; ++v_I_u32)
    {
      boneInfos_as[v_I_u32].serialize_v(b_IO_ro);
    }

    // animations
    for (uint32_t v_I_u32 = 0U; v_I_u32 < numAnimations_u32; ++v_I_u32)
    {
      if (true == b_IO_ro.isLoading_b())
      {
        animations_apo[v_I_u32] = new Animation();
        Assert(NULL != animations_apo[v_I_u32]);
      }

      animations_apo[v_I_u32]->serialize_v(b_IO_ro);
    }

    // nodes
    for (uint32_t v_I_u32 = 0U; v_I_u32 < numNodes_u32; ++v_I_u32)
    {
      nodes_as[v_I_u32].serialize_v(b_IO_ro);
    }
    
    b_IO_ro.serialize_v(globalInverseTransform_o);
  }
};

struct ModelDesc_s
{
  bool                  hasTangents_b;
  MeshData_s**          meshData_ps;
  uint32_t              numMeshes_u32;
  ResourceID_t*         materials_ao;
  uint32_t              numMaterials_u32;
  AnimationData_s*      animationData_ps;
  MEString              fileName_o;

  ModelDesc_s()
    : hasTangents_b(false)
    , meshData_ps(NULL)
    , numMeshes_u32(0U)
    , materials_ao(NULL)
    , numMaterials_u32(0U)
    , animationData_ps(NULL)
    , fileName_o("")
  {

  }

  void serialize_v(InOut& b_IO_ro)
  {
    b_IO_ro.serialize_v(fileName_o);

    b_IO_ro.serialize_v(hasTangents_b);

    // try to serialize animation
    bool v_IsAnimated_b = (NULL != animationData_ps);
    b_IO_ro.serialize_v(v_IsAnimated_b);

    if (true == v_IsAnimated_b)
    {
      if (true == b_IO_ro.isLoading_b())
      {
        animationData_ps = new AnimationData_s();
        Assert(NULL != animationData_ps);
      }

      animationData_ps->serialize_v(b_IO_ro);
    }


    // serialize meshes
    b_IO_ro.serialize_v(numMeshes_u32);

    if (b_IO_ro.isLoading_b())
    {
      meshData_ps = new me3d::MeshData_s*[numMeshes_u32];
      Assert(NULL != meshData_ps);
    }

    for (uint32_t v_I_u32 = 0U; v_I_u32 < numMeshes_u32; ++v_I_u32)
    {

      if (b_IO_ro.isLoading_b())
      {
        if (true == v_IsAnimated_b)
        {
          meshData_ps[v_I_u32] = new MeshDataAnimated_s[numMeshes_u32];
        }
        else
        {
          if (true == hasTangents_b)
          {
            meshData_ps[v_I_u32] = new MeshDataPosTexNormTangent_s[numMeshes_u32];
          }
          else
          {
            meshData_ps[v_I_u32] = new MeshDataPosTexNorm_s[numMeshes_u32];
          }
        }
        Assert(NULL != meshData_ps[v_I_u32]);
      }

      meshData_ps[v_I_u32]->serialize_v(b_IO_ro);
    }

    // serialize material ids
    b_IO_ro.serialize_v(numMaterials_u32);

    if (b_IO_ro.isLoading_b())
    {
      materials_ao = new ResourceID_t[numMaterials_u32];
      Assert(NULL != materials_ao);
    }

    b_IO_ro.serializeArray_v(materials_ao, numMaterials_u32);

  }
};


} // namespace me3d

#endif
