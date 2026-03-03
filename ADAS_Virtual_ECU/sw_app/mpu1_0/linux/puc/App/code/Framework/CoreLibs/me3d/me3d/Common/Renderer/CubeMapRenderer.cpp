
#include "Common/Renderer/CubeMapRenderer.h"

#include "Common/RenderEngine.h"
#include "Common/Device/Device3D.h"
#include "Common/Manager/CameraManager.h"
#include "Common/Manager/BufferManager.h"
#include "Common/Manager/ConstantsManager.h"
#include "Common/Manager/ShaderManager.h"
#include "Common/Manager/TextureManager.h"
#include "Common/Resources/Texture.h"
#include "Common/Resources/VertexBuffer.h"
#include "Common/Resources/VertexDeclarationTypes.h"
#include "Common/Effect/EffectFile.h"
#include "Common/ResourceHandler/ResourceHandler.h"


namespace me3d
{

CubeMapRenderer::CubeMapRenderer()
  : IRenderer()
  , renderEngine_po(NULL)
  , constantCubeMapWVP_po(NULL)
  , constantCubeMap_po(NULL)
  , cubeMapEffect_po(NULL)
  , cubeMap_po(NULL)
  , vertexBuffer_po(NULL)
{

}

CubeMapRenderer::~CubeMapRenderer()
{

}

bool_t CubeMapRenderer::isEnabled_b()
{
  return renderEngine_po->isEnabled_b(e_EftCubeMap);
}

bool CubeMapRenderer::create_b(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;

  constantCubeMap_po = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cCubeMap", e_CtTexture, 1U));
  constantCubeMapWVP_po = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cWVPMatrix", e_CtMatrix4, 1U));

  return true;
}

void CubeMapRenderer::release_v()
{
  if (NULL != cubeMap_po)
  {
    renderEngine_po->getTextureManager_po()->releaseTexture_v(cubeMap_po);
    cubeMap_po = NULL;
  }

  if (NULL != vertexBuffer_po)
  {
    renderEngine_po->getBufferManager_po()->releaseVertexBuffer_v(vertexBuffer_po);
    vertexBuffer_po = NULL;
  }
}

void CubeMapRenderer::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{

}

void CubeMapRenderer::beginFrame_v()
{

}

void CubeMapRenderer::reset_v()
{

}

// PRQA S 4020 1 // intended, leave this until CubeMapManager is implemented
void CubeMapRenderer::render_v() const
{
  return;
  
  if (NULL != vertexBuffer_po)
  {
    vertexBuffer_po->set_v(0);
  }

  if (NULL != constantCubeMapWVP_po)
  {
    const Matrix4f& c_VP_ro = renderEngine_po->getCameraManager_po()->getCamera_ro().getViewProjMat_ro();

    Matrix4f v_World_o;
    v_World_o = Matrix4f::createScale_o(500.0F);
    const Vector3f& c_CamPos_ro = renderEngine_po->getCameraManager_po()->getCamera_ro().getPos_ro();
    v_World_o = v_World_o.mmulFast(Matrix4f::createTranslation_o(c_CamPos_ro(0), c_CamPos_ro(1), c_CamPos_ro(2)));
    v_World_o = v_World_o.mmulFast(c_VP_ro);
    constantCubeMapWVP_po->setData_v(&v_World_o);
  }

  if (NULL != cubeMapEffect_po)
  {
    cubeMapEffect_po->beginPass_b();

    renderEngine_po->getDevice_po()->draw_v(e_PtTriangleList, c_NumCubeMapPrimitives_u32, 0);

    cubeMapEffect_po->endPass_v();
  }
}

bool CubeMapRenderer::createCubeMap_b(const MEString& i_FileName_ro)
{
  release_v();

  TextureResource_s* v_Res_po = ResourceHandler::get_po()->findResourceByName_po<TextureResource_s>(i_FileName_ro);
  if (NULL != v_Res_po)
  {
    cubeMap_po = renderEngine_po->getTextureManager_po()->createTexture_po(v_Res_po->texDesc_s, v_Res_po->data_pu8);


    constantCubeMap_po->setData_v(cubeMap_po);


    cubeMapEffect_po = renderEngine_po->getShaderManager_po()->getShader_po(e_ShaderCubeMap);

    // Create Vertices and its buffer
    VertexBufferDesc_s v_BufferDesc_s;
    v_BufferDesc_s.size_u32 = c_NumCubeMapPrimitives_u32 * sizeof(VertexPos_s);
    v_BufferDesc_s.stride_u32 = sizeof(VertexPos_s);
    v_BufferDesc_s.c_Layout_pc = "P3f";

    VertexPos_s v_Vertices_as[c_NumCubeMapPrimitives_u32];

    createCube_v(&v_Vertices_as[0], 0.5F);

    vertexBuffer_po = renderEngine_po->getBufferManager_po()->createVertexBuffer_po(v_BufferDesc_s, &v_Vertices_as[0]);
  }



  return true;
}

// PRQA S 3706 EOF // subscript operator to a pointer value. size is defined by c_NumCubeMapPrimitives_u32. filling 36 VertexPos structs in this function

void CubeMapRenderer::createCube_v(VertexPos_s* b_Vertices_ps, float32_t i_Extents_f32)
{
  // back face
  b_Vertices_ps[0U]  = VertexPos_s(-i_Extents_f32, -i_Extents_f32, -i_Extents_f32); // bottom-left
  b_Vertices_ps[1U]  = VertexPos_s( i_Extents_f32,  i_Extents_f32, -i_Extents_f32); // top-right
  b_Vertices_ps[2U]  = VertexPos_s(-i_Extents_f32,  i_Extents_f32, -i_Extents_f32); // top-left
  b_Vertices_ps[3U]  = VertexPos_s(-i_Extents_f32, -i_Extents_f32, -i_Extents_f32); // bottom-left
  b_Vertices_ps[4U]  = VertexPos_s( i_Extents_f32, -i_Extents_f32, -i_Extents_f32); // bottom-right 
  b_Vertices_ps[5U]  = VertexPos_s( i_Extents_f32,  i_Extents_f32, -i_Extents_f32); // top-right

  // front face
  b_Vertices_ps[6U]  = VertexPos_s( i_Extents_f32,  i_Extents_f32,  i_Extents_f32); // top-right
  b_Vertices_ps[7U]  = VertexPos_s( i_Extents_f32, -i_Extents_f32,  i_Extents_f32); // bottom-right
  b_Vertices_ps[8U]  = VertexPos_s(-i_Extents_f32, -i_Extents_f32,  i_Extents_f32); // bottom-left
  b_Vertices_ps[9U]  = VertexPos_s(-i_Extents_f32, -i_Extents_f32,  i_Extents_f32); // bottom-left
  b_Vertices_ps[10U] = VertexPos_s(-i_Extents_f32,  i_Extents_f32,  i_Extents_f32); // top-left
  b_Vertices_ps[11U] = VertexPos_s( i_Extents_f32,  i_Extents_f32,  i_Extents_f32); // top-right

  // left face
  b_Vertices_ps[12U] = VertexPos_s(-i_Extents_f32,  i_Extents_f32, -i_Extents_f32); // top-left
  b_Vertices_ps[13U] = VertexPos_s(-i_Extents_f32,  i_Extents_f32,  i_Extents_f32); // top-right
  b_Vertices_ps[14U] = VertexPos_s(-i_Extents_f32, -i_Extents_f32, -i_Extents_f32); // bottom-left
  b_Vertices_ps[15U] = VertexPos_s(-i_Extents_f32,  i_Extents_f32,  i_Extents_f32); // top-right
  b_Vertices_ps[16U] = VertexPos_s(-i_Extents_f32, -i_Extents_f32,  i_Extents_f32); // bottom-right
  b_Vertices_ps[17U] = VertexPos_s(-i_Extents_f32, -i_Extents_f32, -i_Extents_f32); // bottom-left

  // right face
  b_Vertices_ps[18U] = VertexPos_s( i_Extents_f32,  i_Extents_f32,  i_Extents_f32); // top-left
  b_Vertices_ps[19U] = VertexPos_s( i_Extents_f32,  i_Extents_f32, -i_Extents_f32); // top-right    
  b_Vertices_ps[20U] = VertexPos_s( i_Extents_f32, -i_Extents_f32, -i_Extents_f32); // bottom-right
  b_Vertices_ps[21U] = VertexPos_s( i_Extents_f32, -i_Extents_f32,  i_Extents_f32); // bottom-left   
  b_Vertices_ps[22U] = VertexPos_s( i_Extents_f32,  i_Extents_f32,  i_Extents_f32); // top-left
  b_Vertices_ps[23U] = VertexPos_s( i_Extents_f32, -i_Extents_f32, -i_Extents_f32); // bottom-right

  // bottom face
  b_Vertices_ps[24U] = VertexPos_s( i_Extents_f32, -i_Extents_f32, -i_Extents_f32); // top-left
  b_Vertices_ps[25U] = VertexPos_s(-i_Extents_f32, -i_Extents_f32, -i_Extents_f32); // top-right
  b_Vertices_ps[26U] = VertexPos_s( i_Extents_f32, -i_Extents_f32,  i_Extents_f32); // bottom-left
  b_Vertices_ps[27U] = VertexPos_s(-i_Extents_f32, -i_Extents_f32,  i_Extents_f32); // bottom-right
  b_Vertices_ps[28U] = VertexPos_s( i_Extents_f32, -i_Extents_f32,  i_Extents_f32); // bottom-left
  b_Vertices_ps[29U] = VertexPos_s(-i_Extents_f32, -i_Extents_f32, -i_Extents_f32); // top-right

  // top face
  b_Vertices_ps[30U] = VertexPos_s( i_Extents_f32,  i_Extents_f32,  i_Extents_f32); // bottom-right
  b_Vertices_ps[31U] = VertexPos_s(-i_Extents_f32,  i_Extents_f32, -i_Extents_f32); // top-left
  b_Vertices_ps[32U] = VertexPos_s( i_Extents_f32,  i_Extents_f32, -i_Extents_f32); // top-right    
  b_Vertices_ps[33U] = VertexPos_s(-i_Extents_f32,  i_Extents_f32, -i_Extents_f32); // top-left 
  b_Vertices_ps[34U] = VertexPos_s( i_Extents_f32,  i_Extents_f32,  i_Extents_f32); // bottom-right
  b_Vertices_ps[35U] = VertexPos_s(-i_Extents_f32,  i_Extents_f32,  i_Extents_f32); // bottom-left  
}

} // namespace me3d
