#include "VertexBuffer.h"

#include "Common/Effect/EffectFileTypes.h"

#include "Common/RenderEngine.h"
#include "Common/Device/Device3D.h"

 

namespace me3d
{

VertexBuffer::VertexBuffer()
  : renderEngine_po(NULL)
  , desc_s()
  , layout_s()
{

}

VertexBuffer::~VertexBuffer()
{
  // PRQA S 4261 2 // This function doesn't throw exceptions
  // PRQA S 4631 1 // This function doesn't throw exceptions
  release_v();
}

bool VertexBuffer::create_b(RenderEngine* b_RenderEngine_po, const VertexBufferDesc_s& i_Desc_rs, const void* i_InitialData_pv /*= NULL*/)
{
  release_v();
  renderEngine_po = b_RenderEngine_po;

  desc_s    = i_Desc_rs;

  return createBufferLayout_b();
}

void VertexBuffer::release_v()
{
  // release map buffer
}

void VertexBuffer::set_v(uint32_t i_Slot_u32, uint32_t i_Offset_u32 /*= 0U*/) const
{
  renderEngine_po->getDevice_po()->setVertexBuffer_b(this, i_Slot_u32, i_Offset_u32);
}

void VertexBuffer::set_v(uint32_t i_Slot_u32, uint32_t i_Offset_u32, uint32_t i_Stride_u32) const
{
  renderEngine_po->getDevice_po()->setVertexBuffer_b(this, i_Slot_u32, i_Offset_u32, i_Stride_u32);
}

const BufferLayout_s& VertexBuffer::getBufferLayout_rs() const
{
  return layout_s;
}

const VertexBufferDesc_s& VertexBuffer::getDesc_rs() const
{
  return desc_s;
}

bool VertexBuffer::createBufferLayout_b()
{
  layout_s.usedElements_u32 = 0U;
  memset(layout_s.elements_as, 0, sizeof(layout_s.elements_as));


  uint32_t v_Offset_u32     = 0U;
  uint32_t v_I_u32          = 0U;
  uint32_t v_LayoutIdx_u32  = 0U;
  uint32_t v_Length_u32     = strnlen(desc_s.c_Layout_pc, 1024U);
  Assert(v_Length_u32 > 2);


  while (v_I_u32 < (v_Length_u32 - 2))
  {
    // skip underscores
    // PRQA S 3706 1 // Subscript operator is safe. length ensures valid memory location
    if (desc_s.c_Layout_pc[v_I_u32]  == '_')
    {
      ++v_I_u32;
      continue;
    }

    // New stream
    // PRQA S 3706 1 // Subscript operator is safe. length ensures valid memory location
    if (desc_s.c_Layout_pc[v_I_u32] == ',')
    {
      ++v_I_u32;
      v_Offset_u32 = 0U;

      continue;
    }

    // get next three input characters (e.g. P3f)
    // PRQA S 3706 1 // Subscript operator is safe. length ensures valid memory location
    char v_C0_c = desc_s.c_Layout_pc[v_I_u32];
    ++v_I_u32;
    // PRQA S 3706 1 // Subscript operator is safe. length ensures valid memory location
    char v_C1_c = desc_s.c_Layout_pc[v_I_u32];
    ++v_I_u32;
    // PRQA S 3706 1 // Subscript operator is safe. length ensures valid memory location
    char v_C2_c = desc_s.c_Layout_pc[v_I_u32];
    ++v_I_u32;

    // Get Values for current buffer layout element
    Assert(v_LayoutIdx_u32 < c_MaxBufferLayoutElements_u32);
    BufferLayoutElement_s* v_Element_ps = &layout_s.elements_as[v_LayoutIdx_u32];
    v_Element_ps->classification_e      = e_ScPerVertexData;
    v_Element_ps->semanticType_e        = getSemanticType_e(v_C0_c);
    v_Element_ps->semanticFormat_e      = getSemanticFormat_e(v_C1_c, v_C2_c);
    v_Element_ps->alignedByteOffset_u32 = v_Offset_u32;
    v_Element_ps->size_u32              = getSemanticFormatStride_u32(v_C1_c, v_C2_c);
    v_Element_ps->componentCount_u32    = getSemanticComponentCount_u32(v_C1_c);


    // add offset and increment the layoutIndex
    v_Offset_u32 += v_Element_ps->size_u32;
    ++v_LayoutIdx_u32;
  }

  layout_s.usedElements_u32 = v_LayoutIdx_u32;

  Assert(v_I_u32 == v_Length_u32);

  return true;
}

ShaderSemanticType_e VertexBuffer::getSemanticType_e(char i_C0_c)
{
  ShaderSemanticType_e v_SST_e = e_SstPosition;

  switch (i_C0_c)
  {
  case 'P': { v_SST_e = e_SstPosition; break; }
  case 'N': { v_SST_e = e_SstNormal;   break; }
  case 'G': { v_SST_e = e_SstTangent;  break; }
  case 'B': { v_SST_e = e_SstBinormal; break; }
  case 'T': { v_SST_e = e_SstTexCoord; break; }
  case 'C': { v_SST_e = e_SstColor;    break; }
  case 'W': { v_SST_e = e_SstWeights;  break; }
  case 'I': { v_SST_e = e_SstIndices;  break; }
  default : { Assert(false);           break; }
  }

  return v_SST_e;
}

ShaderSemanticFormat_e VertexBuffer::getSemanticFormat_e(char i_C1_c, char i_C2_c)
{
  ShaderSemanticFormat_e v_SSF_e = e_SsfFloat1;

  switch (i_C2_c)
  {
  case 'f':
    {
      switch (i_C1_c)
      {
      case '1': { v_SSF_e = e_SsfFloat1; break; }
      case '2': { v_SSF_e = e_SsfFloat2; break; }
      case '3': { v_SSF_e = e_SsfFloat3; break; }
      case '4': { v_SSF_e = e_SsfFloat4; break; }
      default : { Assert(false);         break; }
      } // switch 1

      break;
    } // f
  case 'c': 
    { 
      v_SSF_e = e_SsfUint; 
      break; 
    } // char
  case 'b': 
    { 
      v_SSF_e = e_SsfUint; 
      break; 
    } // byte
  default: 
    { 
      Assert(false);        
      break; 
    }
  } // switch 2

  return v_SSF_e;
}

uint32_t VertexBuffer::getSemanticFormatStride_u32(char i_C1_c, char i_C2_c)
{
  uint32_t v_Stride_u32 = 0U;

  switch (i_C2_c)
  {
  case 'f':
    {
      switch(i_C1_c)
      {
      case '1': { v_Stride_u32 = 1U * sizeof(float32_t); break; }
      case '2': { v_Stride_u32 = 2U * sizeof(float32_t); break; }
      case '3': { v_Stride_u32 = 3U * sizeof(float32_t); break; }
      case '4': { v_Stride_u32 = 4U * sizeof(float32_t); break; }
      default : { Assert(false); break; }
      }

      break;
    } // float

  case 'c': 
  case 'b': // fall through
    { 
      v_Stride_u32 = 4U * sizeof(uint8_t);
      break; 
    } // char or byte

  default:
    {
      Assert(false);
      break;
    }
  }

  Assert(0U != v_Stride_u32);
  return v_Stride_u32;
}

uint32_t VertexBuffer::getSemanticComponentCount_u32(char i_C1_c)
{
  uint32_t v_Cnt_u32 = 0U;

  switch (i_C1_c)
  {
  case '1': { v_Cnt_u32 = 1U; break; }
  case '2': { v_Cnt_u32 = 2U; break; }
  case '3': { v_Cnt_u32 = 3U; break; }
  case '4': { v_Cnt_u32 = 4U; break; }
  default : { Assert(false);  break; }
  }

  Assert(0U != v_Cnt_u32);
  return v_Cnt_u32;
}

} // namespace me3d
