#include "Common/Effect/EffectFileParser.h"
#include "Common/ResourceHandler/ResourceHandler.h"
#include "Common/RenderEngine.h"
#include "Common/Manager/ShaderManager.h"

// PRQA S 3706 EOF // Ok here, v_I_u32 will never exceed v_Length_u32 for parsing shader files

namespace me3d
{

const char     c_IncludeName_ac[]      = "#include \"";
const uint32_t c_IncludeNameSize_u32   = (sizeof(c_IncludeName_ac)) - 1; // -1 skips '\0'



  EffectFileParser::EffectFileParser()
    : attributes_s()
    , renderEngine_po(NULL)
  {
    for (uint32_t v_I_u32 = 0U; v_I_u32 < e_SiCount; ++v_I_u32)
    {
      vertexIncludes_aps[v_I_u32] = NULL;
      pixelIncludes_aps[v_I_u32]  = NULL;
    }
  }

  EffectFileParser::~EffectFileParser()
  {

  }

  bool EffectFileParser::create_b(RenderEngine* b_RenderEngine_po, const char* i_VertexShaderSrc_pc, const char* i_PixelShaderSrc_pc)
  {
    renderEngine_po = b_RenderEngine_po;


    // First, parse all the files this shader may include
    parseIncludes_b(i_VertexShaderSrc_pc, i_PixelShaderSrc_pc);

    // call parse attributes for derived classes
    onParseAttributes_b();

    return true;
  }

  const ShaderInput_s* EffectFileParser::getAttributes_ps() const
  {
    return &attributes_s;
  }

  const char* EffectFileParser::getSourceCode_pc(EffectFileType_e i_EffectFileType_e) const
  {
    const char* c_SourceCode_pc = NULL;

    switch (i_EffectFileType_e)
    {
    case e_EftVertex:
	{
      c_SourceCode_pc = &vertexShaderSrc_ac[0];
      break;
	  }
    case e_EftPixel:
	{
      c_SourceCode_pc = &pixelShaderSrc_ac[0];
      break;
	  }
    case e_EftCount:
	{
      Assert(false);
      break;
	  }
    case e_EftInvalid:
	{
      Assert(false);
      break;
	  }
    default:
	{
      Assert(false);
      break;
	  }
    }

    return c_SourceCode_pc;
  }

  bool EffectFileParser::parseIncludes_b(const char* i_VertexShaderSrc_pc, const char* i_PixelShaderSrc_pc)

  {

    char v_VertexShaderSrc_ac[c_MaxEffectFileLength_u32];
    char v_PixelShaderSrc_ac[c_MaxEffectFileLength_u32];

    strncpy(&v_VertexShaderSrc_ac[0], i_VertexShaderSrc_pc, c_MaxEffectFileLength_u32);
    strncpy(&v_PixelShaderSrc_ac[0], i_PixelShaderSrc_pc, c_MaxEffectFileLength_u32);


    for (uint32_t v_I_u32 = 0U; v_I_u32 < e_SiCount; ++v_I_u32)
    {
      vertexIncludes_aps[v_I_u32] = NULL;
      pixelIncludes_aps[v_I_u32]  = NULL;
    }

    parseIncludes_b(&v_VertexShaderSrc_ac[0], &vertexIncludes_aps[0]);
    parseIncludes_b(&v_PixelShaderSrc_ac[0], &pixelIncludes_aps[0]);


    // combine final source code
    vertexShaderSrc_ac[0] = '\0';
    pixelShaderSrc_ac[0]  = '\0';

    //concatenate all include files
    
    for (uint32_t v_I_u32 = 0U; v_I_u32 < e_SiCount; ++v_I_u32)
    {
      if (NULL != vertexIncludes_aps[v_I_u32])
      {
        strncat(&vertexShaderSrc_ac[0], &vertexIncludes_aps[v_I_u32]->sourceCode_ac[0], c_MaxEffectFileLength_u32);
      }
    
      if (NULL != pixelIncludes_aps[v_I_u32])
      {
        strncat(&pixelShaderSrc_ac[0], &pixelIncludes_aps[v_I_u32]->sourceCode_ac[0], c_MaxEffectFileLength_u32);
      }
    }

    strncat(&vertexShaderSrc_ac[0], &v_VertexShaderSrc_ac[0], c_MaxEffectFileLength_u32);
    strncat(&pixelShaderSrc_ac[0], &v_PixelShaderSrc_ac[0], c_MaxEffectFileLength_u32);

    uint32_t v_VertexLen_u32 = strnlen(&vertexShaderSrc_ac[0], c_MaxEffectFileLength_u32);
    uint32_t v_PixelLen_u32 = strnlen(&pixelShaderSrc_ac[0], c_MaxEffectFileLength_u32);

    vertexShaderSrc_ac[v_VertexLen_u32] = '\0'; 
    pixelShaderSrc_ac[v_PixelLen_u32]   = '\0';

    return true;
  }

  bool EffectFileParser::parseIncludes_b(char* b_SourceCode_pc, ShaderInclude_s* b_Includes_aps[e_SiCount])const
  {
    enum IncludeParseState_e
    {
      e_IpsInclude,  // try parse #include"
      e_IpsFileName // try parse filename e.g. Functions.vp plus ending quotation mark "
    };

    uint32_t v_Length_u32         = strnlen(b_SourceCode_pc, c_MaxEffectFileLength_u32);
    uint32_t v_I_u32              = 0U;
    IncludeParseState_e v_State_e = e_IpsInclude;

    uint32_t v_NumIncludes_u32 = 0U;

    while (v_I_u32 < v_Length_u32)
    {
      // skip whitespace
      // PRQA S 3706 1 // Ok here, v_I_u32 will never exceed v_Length_u32
      if (b_SourceCode_pc[v_I_u32] == ' ')
      {
        ++v_I_u32;
        continue;
      }

      switch (v_State_e)
      {
      case e_IpsInclude:
        {
          // PRQA S 3705 1 // Pointer arithmetic ok here, v_I_u32 will never exceed v_Length_u32
          const char* c_SubStr_pc = b_SourceCode_pc + v_I_u32; 
          if (0 == strncmp(c_SubStr_pc, &c_IncludeName_ac[0], c_IncludeNameSize_u32))
          {
            // replace the #include" with whitespace
            uint32_t v_EndIdx = v_I_u32 + c_IncludeNameSize_u32;
            for (uint32_t v_StartIdx_u32 = v_I_u32; v_StartIdx_u32 < v_EndIdx; ++v_StartIdx_u32)
            {
              // PRQA S 3706 1 // Ok here, v_I_u32 will never exceed v_Length_u32
              b_SourceCode_pc[v_I_u32] = ' ';
              ++v_I_u32;
            }

            v_State_e = e_IpsFileName;
          }
          else
          {
            ++v_I_u32;
          }

        }
        break;
      case e_IpsFileName:
        {
          MEString v_IncludeFileName_o;
          uint32_t v_Cnt_u32 = 0U;

          // PRQA S 4232 1 // while no closing " was found...
          while ((b_SourceCode_pc[v_I_u32] != '\"'))
          {
            // PRQA S 3706 1 // Ok here, v_I_u32 will never exceed v_Length_u32
            v_IncludeFileName_o.setAt_v(v_Cnt_u32, b_SourceCode_pc[v_I_u32]);

            // delete the include
            // PRQA S 3706 1 // Ok here, v_I_u32 will never exceed v_Length_u32
            b_SourceCode_pc[v_I_u32] = ' ';

            ++v_Cnt_u32;
            ++v_I_u32;
          }

          // delete the closing quotation mark
          b_SourceCode_pc[v_I_u32] = ' ';

          // find the corresponding shader include
          ShaderInclude_s* v_Si_ps = renderEngine_po->getShaderManager_po()->findShaderInclude_ps(v_IncludeFileName_o);
          
          Assert(NULL != v_Si_ps);
          Assert(v_NumIncludes_u32 < e_SiCount);

          b_Includes_aps[v_NumIncludes_u32] = v_Si_ps;
          ++v_NumIncludes_u32;

          v_State_e = e_IpsInclude;
        }
        break;
      default:
		  {
        break;
		  }
      } // switch

    } // while


    return true;
  }


} // namespace me3d