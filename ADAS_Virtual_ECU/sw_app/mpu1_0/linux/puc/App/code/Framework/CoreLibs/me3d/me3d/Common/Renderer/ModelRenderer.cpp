#include "Common/Renderer/ModelRenderer.h"

#include "Common/RenderEngine.h"
#include "Common/Device/Device3D.h"
#include "Common/Manager/ModelManager.h"
#include "Common/Manager/CameraManager.h"
#include "Common/Manager/ConstantsManager.h"
#include "Common/Manager/ShaderManager.h"
#include "Common/Manager/MaterialManager.h"
#include "Common/Model/ModelTypes.h"
#include "Common/Model/Mesh.h"

#include "Math/Transform.h"
#include "Math/MathLib.h"

#include "Common/Resources/Texture.h"

#include "Common/Resources/VertexBuffer.h"
#include "Common/Resources/IndexBuffer.h"
#include "Common/Effect/EffectFileRenderStateBlock.h"
#include "Common/ResourceHandler/ResourceHandler.h"
#include "Common/Manager/TextureManager.h"

// PRQA S 3706 EOF // performance

namespace me3d
{

ModelRenderer::ModelRenderer()
  : IRenderer()
  , renderEngine_po(NULL)
  , renderStateBlock_po(NULL)
  , constantWVP_po(NULL)
  , constantWorld_po(NULL)
  , constantWorldInverse_po(NULL)
  , materialAmbient_po(NULL)
  , materialDiffuse_po(NULL)
  , materialSpecular_po(NULL)
  , materialOpacity_po(NULL)
  , materialShininess_po(NULL)
  , materialMetallic_po(NULL)
  , materialAlbedoTex_po(NULL)
  , materialNormalex_po(NULL)
  , materialMetallicTex_po(NULL)
  , materialRoughnessTex_po(NULL)
  , materialAoTex_po(NULL)
  , constantBones_po(NULL)
{

}

ModelRenderer::~ModelRenderer()
{

}

bool_t ModelRenderer::isEnabled_b()
{
  return renderEngine_po->isEnabled_b(e_EftModel);
}

bool ModelRenderer::create_b(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;

  constantWVP_po              = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cWVPMatrix", e_CtMatrix4, 1U));
  constantWorld_po            = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cWorldMatrix", e_CtMatrix4, 1U));
  constantWorldInverse_po     = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cWorldInvMatrix", e_CtMatrix4, 1U));

  materialAlbedoTex_po        = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMaterial.AlbedoTex", e_CtTexture, 1U));
  materialNormalex_po         = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMaterial.NormalTex", e_CtTexture, 1U));
  materialMetallicTex_po      = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMaterial.MetallicTex", e_CtTexture, 1U));
  materialRoughnessTex_po     = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMaterial.RoughnessTex", e_CtTexture, 1U));
  materialAoTex_po   = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMaterial.AmbientOcclusionTex", e_CtTexture, 1U));

  materialAmbient_po          = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMaterial.Ambient", e_CtFloat3, 1U));
  materialDiffuse_po          = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMaterial.Diffuse", e_CtFloat3, 1U));
  materialSpecular_po         = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMaterial.Specular", e_CtFloat3, 1U));
  materialOpacity_po          = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMaterial.Opacity", e_CtFloat1, 1U));
  materialShininess_po        = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMaterial.Shininess", e_CtFloat1, 1U));
  materialMetallic_po         = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMaterial.Metallic", e_CtFloat1, 1U));

  constantBones_po            = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cBoneMatrices[0]", e_CtMatrix4, 128U));


  // Enable alpha blending for this effect and disable depth write
  renderStateBlock_po = renderEngine_po->getShaderManager_po()->createRenderStateBlock_po();
  renderStateBlock_po->addState_b(EffectFileRenderState_s(e_EfstAlphaBlendEnable, EffectFileStateValue_s(e_EfsvTrue), 0));    
  renderStateBlock_po->addState_b(EffectFileRenderState_s(e_EfstSrcBlend, EffectFileStateValue_s(e_EfsvSrcAlpha), 0));
  renderStateBlock_po->addState_b(EffectFileRenderState_s(e_EfstDestBlend, EffectFileStateValue_s(e_EfsvOneMinusSrcAlpha), 0));
  
  return true;
}

void ModelRenderer::release_v()
{

}

void ModelRenderer::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{

}

void ModelRenderer::beginFrame_v()
{

}

void ModelRenderer::reset_v()
{
}

void ModelRenderer::renderDefault_v()const
{
  // render opaque models
  renderModels_v(false);
}

void ModelRenderer::renderTransparent_v()const
{
  // render all transparent models
  renderModels_v(true);
}

void ModelRenderer::renderModels_v(bool i_Transparent_b) const
{
  Model** v_RenderList_po = renderEngine_po->getModelManager_po()->getRenderList_po();

  for (uint32_t v_I_u32 = 0U; v_I_u32 < renderEngine_po->getModelManager_po()->getNumModelsToRender_u32(); ++v_I_u32)
  {
    // PRQA S 3706 1 // subscript operator range ensured by c_MaxModels_u32
    Model* v_Current_po = v_RenderList_po[v_I_u32];
    if (true == v_Current_po->isInitialized_b())
    {    
      // commit World View Projection Matrix
      const Matrix4f& c_VP_ro = renderEngine_po->getCameraManager_po()->getCamera_ro().getViewProjMat_ro();
      Matrix4f v_WVP_o = v_Current_po->getWorldMatrix_ro().mmulFast(c_VP_ro);
      constantWVP_po->setData_v(&v_WVP_o);

      const Matrix4f& c_World_ro = v_Current_po->getWorldMatrix_ro();
      constantWorld_po->setData_v(&c_World_ro);
      Matrix4f v_WorldInverse_o = matrixInvert_o(c_World_ro);
      constantWorldInverse_po->setData_v(&v_WorldInverse_o);

      // draw each mesh
      const ModelDesc_s& c_ModelDesc_rs = v_Current_po->getDesc_ro();

      // update bone matrices
      if (true == v_Current_po->isAnimated_b())
      {
        // update bone matrices
        me3d::Matrix4f bonMats[me3d::c_MaxBoneMatrices_u32];
        v_Current_po->boneTransform_v(&bonMats[0], me3d::c_MaxBoneMatrices_u32);

        // PRQA S 3103 1 // fine here, Matrix is designed for contiguous memory
        constantBones_po->setData_v(reinterpret_cast<const Matrix4f*>(&bonMats), me3d::c_MaxBoneMatrices_u32);
      }

      for (uint32_t v_MeshIdx_u32 = 0U; v_MeshIdx_u32 < c_ModelDesc_rs.numMeshes_u32; ++v_MeshIdx_u32)
      {
        // PRQA S 3706 3 // subscript operator range ensured by numMeshes_u32
        MeshData_s* v_MeshData_ps     = c_ModelDesc_rs.meshData_ps[v_MeshIdx_u32];
        Mesh* v_Mesh_po = v_Current_po->getMesh_po(v_MeshIdx_u32);

        MaterialResource_s* v_Resource_ps = ResourceHandler::get_po()->findResourceByID_po<MaterialResource_s>(c_ModelDesc_rs.materials_ao[v_MeshData_ps->materialIndex_u32]);
        if (NULL != v_Resource_ps)
        {
          MaterialDesc_s* v_Material_ps = &v_Resource_ps->desc_s;
          // skip transparent models
          bool v_IsTransparent_b = mecl::math::unequal_x(v_Material_ps->opacity_f32, 1.0F); //    1 opacity means transparent
          if (i_Transparent_b == v_IsTransparent_b)
          {
            // set vertex and index buffer
            v_Mesh_po->set_v();

            // commit texture
            Texture* texture_po = renderEngine_po->getTextureManager_po()->createTexture_po(v_Material_ps->albedoTex_o);
            if (NULL != texture_po)
            {
              materialAlbedoTex_po->setData_v(texture_po);
            }
            else
            {
              materialAlbedoTex_po->setData_v(NULL, e_TcbColor);
            }

            texture_po = renderEngine_po->getTextureManager_po()->createTexture_po(v_Material_ps->normalTex_o);
            if (NULL != texture_po)
            {
              materialNormalex_po->setData_v(texture_po);
            }
            else
            {
              materialNormalex_po->setData_v(NULL, e_TcbColor);
            }

            texture_po = renderEngine_po->getTextureManager_po()->createTexture_po(v_Material_ps->metallicTex_o);
            if (NULL != texture_po)
            {
              materialMetallicTex_po->setData_v(texture_po);
            }
            else
            {
              materialMetallicTex_po->setData_v(NULL, e_TcbColor);
            }

            texture_po = renderEngine_po->getTextureManager_po()->createTexture_po(v_Material_ps->roughnessTex_o);
            if (NULL != texture_po)
            {
              materialRoughnessTex_po->setData_v(texture_po);
            }
            else
            {
              materialRoughnessTex_po->setData_v(NULL, e_TcbColor);
            }

            texture_po = renderEngine_po->getTextureManager_po()->createTexture_po(v_Material_ps->aoTex_o);
            if (NULL != texture_po)
            {
              materialAoTex_po->setData_v(texture_po);
            }
            else
            {
              materialAoTex_po->setData_v(NULL, e_TcbColor);
            }

            // Set Material Uniforms
            Vector3f v_Spec_o(v_Material_ps->specular_o.toVec3_o());
            materialSpecular_po->setData_v(&v_Spec_o);

            Vector3f v_Diffuse_o(v_Material_ps->albedo_o.toVec3_o());
            materialDiffuse_po->setData_v(&v_Diffuse_o);

            Vector3f v_Ambient_o(v_Material_ps->ambient_o.toVec3_o());
            materialAmbient_po->setData_v(&v_Ambient_o);

            materialOpacity_po->setData_v(&v_Material_ps->opacity_f32);
            materialShininess_po->setData_v(&v_Material_ps->shininess_f32);
            materialMetallic_po->setData_v(&v_Material_ps->metallic_f32);


            EffectFile* v_CurrentEffect_po = renderEngine_po->getShaderManager_po()->createShader_po(v_Material_ps->shaderType_e);
            if (true == i_Transparent_b)
            {
              v_CurrentEffect_po->setRenderStateBlock_v(renderStateBlock_po);
            }
            else
            {
              v_CurrentEffect_po->setRenderStateBlock_v(NULL);
            }

            // Begin Rendering
            v_CurrentEffect_po->beginPass_b();

            // Draws a non-indexed triangle array
            // PRQA S 3706 1 // subscript operator range ensured by numMeshes_u32
            renderEngine_po->getDevice_po()->drawIndexed_v(e_PtTriangleList, v_Mesh_po->getIndicesCount_u32(), 0U);

            // end Rendering
            v_CurrentEffect_po->endPass_v();

          } // if transparent
        }


      } // for mesh
    } // if initialized
  } // for model
}

} // namespace me3d
