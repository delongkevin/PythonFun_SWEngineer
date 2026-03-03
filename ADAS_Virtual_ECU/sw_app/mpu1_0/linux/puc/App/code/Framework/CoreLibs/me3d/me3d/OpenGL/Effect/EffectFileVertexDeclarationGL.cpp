#include "OpenGL/Effect/EffectFileVertexDeclarationGL.h"

#include "Common/RenderEngine.h"
#include "Common/Device/Device3D.h"
#include "Common/Resources/VertexBuffer.h"
#include "Common/Effect/EffectFileParser.h"

#include "OpenGL/Effect/EffectFilePassGL.h"
#include "OpenGL/Resources/ShaderTypesGL.h"

namespace me3d
{

EffectFileVertexDeclarationGL::EffectFileVertexDeclarationGL()
  : EffectFileVertexDeclaration()
  , pass_po(NULL)
{

}

EffectFileVertexDeclarationGL::~EffectFileVertexDeclarationGL()
{
  // PRQA S 4261 2 // This function doesn't throw any exceptions.
  // PRQA S 4631 1 // This function doesn't throw any exceptions.
  release_v();
}

void EffectFileVertexDeclarationGL::release_v()
{
  pass_po = NULL;

  EffectFileVertexDeclaration::release_v();
}

bool EffectFileVertexDeclarationGL::create_b(EffectFilePass* b_Pass_po, EffectFile* b_Effect_po)
{
  EffectFileVertexDeclaration::create_b(b_Pass_po, b_Effect_po);


  // PRQA S 3076 1 // Ok here, virtual function is no option here
  pass_po = static_cast<EffectFilePassGL*>(b_Pass_po);
  Assert(NULL != pass_po);

  return true;
}

bool EffectFileVertexDeclarationGL::set_b()
{
  // TODO: support multiple slots
  const VertexBuffer* c_VertexBuffer_po = effectFile_po->getRenderEngine_po()->getDevice_po()->getBoundVertexBuffer_po(0U);
  
  // Always make sure a buffer is bound to the device
  Assert(NULL != c_VertexBuffer_po);

  // Get the Buffer layout
  const BufferLayout_s& c_BufferLayout_rs = c_VertexBuffer_po->getBufferLayout_rs();
  
  c_VertexBuffer_po->bind_v();


  const ShaderInput_s* c_Attributes_ps = effectFile_po->getParser_po()->getAttributes_ps();

  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_BufferLayout_rs.usedElements_u32; ++v_I_u32)
  {
    const BufferLayoutElement_s& c_Element_rs = c_BufferLayout_rs.elements_as[v_I_u32];

    glEnableVertexAttribArray(v_I_u32);
    Assert(getGLError_b() == false);
    
    // Get Attribute GL Id from element name. Attention: Order must be the same (e.g. layout P3F_T2F must match with attribute definition in shader file: attribute vec3 pos, attribute vec2 texCoord)
    if (v_I_u32 < c_Attributes_ps->numElements_u32)
    {
      GLint attributeGLID = glGetAttribLocation(pass_po->getProgramID_u32(), &c_Attributes_ps->elements_as[v_I_u32].name_ac[0]);
      Assert(getGLError_b() == false);

      glVertexAttribPointer(
        attributeGLID, 
        c_Element_rs.componentCount_u32,
        getFormatGLType_e(c_Element_rs.semanticFormat_e),
        getFormatGLNormalized_b(c_Element_rs.semanticFormat_e),
        c_VertexBuffer_po->getDesc_rs().stride_u32,
        reinterpret_cast<void*>(c_Element_rs.alignedByteOffset_u32)
        );
      Assert(getGLError_b() == false);
    }

  }

  return true;
}

void EffectFileVertexDeclarationGL::reset_v()
{
  const VertexBuffer* c_VertexBuffer_po = effectFile_po->getRenderEngine_po()->getDevice_po()->getBoundVertexBuffer_po(0U);

  // Always make sure a buffer is bound to the device
  Assert(NULL != c_VertexBuffer_po);

  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_VertexBuffer_po->getBufferLayout_rs().usedElements_u32; ++v_I_u32)
  {
    glDisableVertexAttribArray(v_I_u32);
  }
}

} // namespace me3d