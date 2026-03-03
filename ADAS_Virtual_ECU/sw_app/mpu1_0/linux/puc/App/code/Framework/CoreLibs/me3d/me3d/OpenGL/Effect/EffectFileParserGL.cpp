#include "OpenGL/Effect/EffectFileParserGL.h"

#include <string.h> // strlen

namespace me3d
{

const char     c_AttributeName_ac[]  = "attribute";
const uint32_t c_AttributeSize_u32   = (sizeof(c_AttributeName_ac)) - 1; // -1 skips '\0'

const char     c_HighPName_ac[]      = "highp";
const uint32_t c_HighPSize_u32       = (sizeof(c_HighPName_ac))     - 1;

const char     c_MediumPName_ac[]    = "mediump";
const uint32_t c_MediumPSize_u32     = (sizeof(c_MediumPName_ac))   - 1;

const char     c_LowPName_ac[]       = "lowp";
const uint32_t c_LowPSize_u32        = (sizeof(c_LowPName_ac))      - 1;

const char     c_DataVec2Name_ac[]   = "vec2";
const uint32_t c_DataVec2Size_u32    = (sizeof(c_DataVec2Name_ac))  - 1;

const char     c_DataVec3Name_ac[]   = "vec3";
const uint32_t c_DataVec3Size_u32    = (sizeof(c_DataVec3Name_ac))  - 1;

const char     c_DataVec4Name_ac[]   = "vec4";
const uint32_t c_DataVec4Size_u32    = (sizeof(c_DataVec4Name_ac))  - 1;

EffectFileParserGL::EffectFileParserGL()
  : EffectFileParser() 
{

}

EffectFileParserGL::~EffectFileParserGL()
{

}




bool EffectFileParserGL::onParseAttributes_b()
{
  const char* shaderSrc_pc = &vertexShaderSrc_ac[0];

  attributes_s.numElements_u32 = 0U;

  // Try to parse: attribute mediump vec3	Pos;
  // we can't write this: layout(location = 0) attribute mediump vec3	Pos;
  // so we need to manually parse all the attributes from the source
  enum AttribParseState_e
  {
    e_ApsAttribute, // attribute
    e_ApsPrecision, // mediump, highp, lowp
    e_ApsDataType,  // vec2, vec3, vec4
    e_ApsName       // Pos
  };

  uint32_t v_Length_u32         = strnlen(shaderSrc_pc, c_MaxEffectFileLength_u32);
  uint32_t v_I_u32              = 0U;
  AttribParseState_e v_State_e  = e_ApsAttribute;

  ShaderInputElement_s v_Elem_s;

  while (v_I_u32 < v_Length_u32)
  {
    // skip whitespace
    // PRQA S 3706 1 // Ok here, v_I_u32 will never exceed v_Length_u32
    if (shaderSrc_pc[v_I_u32] == ' ')
    {
      ++v_I_u32;
      continue;
    }
    
    switch (v_State_e)
    {
    case e_ApsAttribute:
      {
        // PRQA S 3705 1 // Pointer arithmetic ok here, v_I_u32 will never exceed v_Length_u32
        const char* c_SubStr_pc = shaderSrc_pc + v_I_u32; 
        if (0 == strncmp(c_SubStr_pc, &c_AttributeName_ac[0], c_AttributeSize_u32))
        {
          v_I_u32 += c_AttributeSize_u32;
          v_State_e = e_ApsPrecision;
        }
        break;
      }
    case e_ApsPrecision:
      {
        // PRQA S 3705 1 // Pointer arithmetic ok here, v_I_u32 will never exceed v_Length_u32
        const char* c_SubStr_pc = shaderSrc_pc + v_I_u32; 
        if (0 == strncmp(c_SubStr_pc, &c_HighPName_ac[0], c_HighPSize_u32))
        {
          v_I_u32 += c_HighPSize_u32;
          v_State_e = e_ApsDataType;
        }
        else if (0 == strncmp(c_SubStr_pc, &c_MediumPName_ac[0], c_MediumPSize_u32))
        {
          v_I_u32 += c_MediumPSize_u32;
          v_State_e = e_ApsDataType;
        }
        else if (0 == strncmp(c_SubStr_pc, &c_LowPName_ac[0], c_LowPSize_u32)) 
        {
          v_I_u32 += c_LowPSize_u32;
          v_State_e = e_ApsDataType;
        }
        else
        {
          // no matching data type found
        }
        break;
      }
    case e_ApsDataType:
      {
        // PRQA S 3705 1 // Pointer arithmetic ok here, v_I_u32 will never exceed v_Length_u32
        const char* c_SubStr_pc = shaderSrc_pc + v_I_u32; 
        if (0 == strncmp(c_SubStr_pc, &c_DataVec2Name_ac[0], c_DataVec2Size_u32))
        {
          v_I_u32 += c_DataVec2Size_u32;
          v_Elem_s.format_e = e_SsfFloat2;
          v_State_e = e_ApsName;
        } 
        else if (0 == strncmp(c_SubStr_pc, &c_DataVec3Name_ac[0], c_DataVec3Size_u32))
        {
          v_I_u32 += c_DataVec3Size_u32;
          v_Elem_s.format_e = e_SsfFloat3;
          v_State_e = e_ApsName;
        }
        else if (0 == strncmp(c_SubStr_pc, &c_DataVec4Name_ac[0], c_DataVec4Size_u32))
        {
          v_I_u32 += c_DataVec4Size_u32;
          v_Elem_s.format_e = e_SsfFloat4;
          v_State_e = e_ApsName;
        }
        else
        {
          // not found
        }
        break;
      }
    case e_ApsName:
      {
        char v_AttribName_ac[32];

        uint32_t v_Cnt_u32 = 0U;

        // PRQA S 3706 2 // Ok here, v_I_u32 will never exceed v_Length_u32
        while ((shaderSrc_pc[v_I_u32] != ';') &&
               (shaderSrc_pc[v_I_u32] != ' '))
        {
          // PRQA S 3706 1 // Ok here, v_I_u32 will never exceed v_Length_u32
          v_AttribName_ac[v_Cnt_u32] = shaderSrc_pc[v_I_u32];
          ++v_Cnt_u32;
          ++v_I_u32;
        }

        // set name
        v_AttribName_ac[v_Cnt_u32] = '\0';
        v_Elem_s.setName_v(&v_AttribName_ac[0]);

        // add element
        attributes_s.addElement_v(v_Elem_s);
        v_State_e = e_ApsAttribute;

        break;
      }

      break;
    default:
      {

        break;
      }

    } // switch


    ++v_I_u32;
  } // while


  return true;
}


} // namespace me3d

