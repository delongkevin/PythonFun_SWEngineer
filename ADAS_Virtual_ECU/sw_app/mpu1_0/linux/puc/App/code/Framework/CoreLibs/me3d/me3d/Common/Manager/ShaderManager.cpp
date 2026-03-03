#include "ShaderManager.h"

#include <osal/io/File.h>

#include "OpenGL/Shaders/Shaders.h"

#include "Utilities/Directory.h"
#include "Utilities/FileUtils.h"
#include "RenderEngineCfg.h"


// PRQA S 3710 EOF // flag handling
// PRQA S 5029 EOF // fine here

namespace me3d
{

ShaderManager::ShaderManager()
  : IManager()
  , renderEngine_po(NULL)
  , loadFromFiles_b(true)
{
}

ShaderManager::~ShaderManager()
{
}

bool_t ShaderManager::isEnabled_b()
{
  return true;
}

bool ShaderManager::create_b(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;


  MEString v_ShaderPath_o = Directory::getShadersPath_pc();
  v_ShaderPath_o += c_PathSeparator_c;

  // load all shader includes
  if (true == loadFromFiles_b)
  {
    includes_as[e_SiConstants].fileName_o = v_ShaderPath_o + "Constants.vp";
    includes_as[e_SiFunctions].fileName_o = v_ShaderPath_o + "Functions.vp";
    includes_as[e_SiDefines].fileName_o   = v_ShaderPath_o + "Defines.vp";

    loadShaderDefine_b(includes_as[e_SiDefines]);
    loadShaderInclude_b(includes_as[e_SiConstants]);
    loadShaderInclude_b(includes_as[e_SiFunctions]);
  }
  else
  {
    strcpy(&includes_as[e_SiConstants].sourceCode_ac[0], S_Constants_pc);
    strcpy(&includes_as[e_SiFunctions].sourceCode_ac[0], S_Functions_pc);
  }


  // create all shader files (these may use the includes files)
  effects_as[e_ShaderDebug].fileName_o                      = v_ShaderPath_o + "DebugShader";
  effects_as[e_ShaderDebug].c_VertexShaderSrc_pc            = S_DebugVS_pc;
  effects_as[e_ShaderDebug].c_PixelShaderSrc_pc             = S_DebugPS_pc;
  effects_as[e_ShaderDebug].state_e                         = e_SsInvalid;

  effects_as[e_ShaderGui].fileName_o                        = v_ShaderPath_o + "GuiShader";
  effects_as[e_ShaderGui].c_VertexShaderSrc_pc              = S_GuiVS_pc;
  effects_as[e_ShaderGui].c_PixelShaderSrc_pc               = S_GuiPS_pc;
  effects_as[e_ShaderGui].state_e                           = e_SsInvalid;

  effects_as[e_ShaderGuideLine].fileName_o                  = v_ShaderPath_o + "GuideLineShader";
  effects_as[e_ShaderGuideLine].c_VertexShaderSrc_pc        = S_GuideLineVS_pc;
  effects_as[e_ShaderGuideLine].c_PixelShaderSrc_pc         = S_guideLinePS_pc;
  effects_as[e_ShaderGuideLine].state_e                     = e_SsInvalid;
  
  effects_as[e_ShaderText].fileName_o                       = v_ShaderPath_o + "TextShader";
  effects_as[e_ShaderText].c_VertexShaderSrc_pc             = S_TextVS_pc;
  effects_as[e_ShaderText].c_PixelShaderSrc_pc              = S_TextPS_pc;
  effects_as[e_ShaderText].state_e                          = e_SsInvalid;

  effects_as[e_ShaderPhongSolid].fileName_o                 = v_ShaderPath_o + "PhongSolid";
  effects_as[e_ShaderPhongSolid].state_e                    = e_SsInvalid;

  effects_as[e_ShaderPhongTextured].fileName_o              = v_ShaderPath_o + "PhongTextured";
  effects_as[e_ShaderPhongTextured].state_e                 = e_SsInvalid;

  effects_as[e_ShaderGoraudSolid].fileName_o                = v_ShaderPath_o + "GoraudSolid";
  effects_as[e_ShaderGoraudSolid].state_e                   = e_SsNeedsCreation;

  effects_as[e_ShaderGoraudTextured].fileName_o             = v_ShaderPath_o + "GoraudTextured";
  effects_as[e_ShaderGoraudTextured].state_e                = e_SsNeedsCreation;

  effects_as[e_ShaderPBRSolid].fileName_o                   = v_ShaderPath_o + "PBRSolid";
  effects_as[e_ShaderPBRSolid].state_e                      = e_SsInvalid;

  effects_as[e_ShaderPBRTextured].fileName_o                = v_ShaderPath_o + "PBRTextured";
  effects_as[e_ShaderPBRTextured].state_e                   = e_SsInvalid;

  effects_as[e_ShaderModelAnimated].fileName_o              = v_ShaderPath_o + "AnimatedModelShader";
  effects_as[e_ShaderModelAnimated].c_VertexShaderSrc_pc    = S_ModelVS_pc;
  effects_as[e_ShaderModelAnimated].c_PixelShaderSrc_pc     = S_ModelPS_pc;
  effects_as[e_ShaderModelAnimated].state_e                 = e_SsInvalid;

  effects_as[e_ShaderBowlView].fileName_o                   = v_ShaderPath_o + "BowlViewShader";
  effects_as[e_ShaderBowlView].c_VertexShaderSrc_pc         = S_BowlViewVS_pc;
  effects_as[e_ShaderBowlView].c_PixelShaderSrc_pc          = S_BowlViewPS_pc;
  effects_as[e_ShaderBowlView].state_e                      = e_SsInvalid;

  effects_as[e_ShaderBowlViewCPU].fileName_o                = v_ShaderPath_o + "BowlViewShaderCPU";
  effects_as[e_ShaderBowlViewCPU].c_VertexShaderSrc_pc      = S_BowlViewVS_pc;
  effects_as[e_ShaderBowlViewCPU].c_PixelShaderSrc_pc       = S_BowlViewPS_pc;
  effects_as[e_ShaderBowlViewCPU].state_e                   = e_SsInvalid;

  effects_as[e_ShaderSingleView].fileName_o                 = v_ShaderPath_o + "SingleViewShader";
  effects_as[e_ShaderSingleView].c_VertexShaderSrc_pc       = S_BowlViewVS_pc;
  effects_as[e_ShaderSingleView].c_PixelShaderSrc_pc        = S_BowlViewPS_pc;
  effects_as[e_ShaderSingleView].state_e                    = e_SsInvalid;

  effects_as[e_ShaderCubeMap].fileName_o                    = v_ShaderPath_o + "CubeMapShader";
  effects_as[e_ShaderCubeMap].c_VertexShaderSrc_pc          = S_CubeMapVS_pc;
  effects_as[e_ShaderCubeMap].c_PixelShaderSrc_pc           = S_CubeMapPS_pc;
  effects_as[e_ShaderCubeMap].state_e                       = e_SsInvalid;


#ifdef USE_DIRECTORY_WATCHER
  InitializeCriticalSection(&criticalSection_o);
  directoryWatcher.watchDirectory_v(Directory::getShadersPath_pc());
#endif

  return true;
}

void ShaderManager::release_v()
{
  for (uint32_t v_I_u32 = 0; v_I_u32 < e_ShaderCount; ++v_I_u32)
  {
    effects_as[v_I_u32].effectFile_o.release_v();
  }
}

void ShaderManager::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{

}

void ShaderManager::beginFrame_v()
{
#ifdef USE_DIRECTORY_WATCHER
  EnterCriticalSection(&criticalSection_o);

  const char* v_File_pc = directoryWatcher.getChangedFile();
  if (v_File_pc[0] != '\0')
  {
    bool v_ReloadAllShaders_b = false;

    // get the modified include file and recreate shaders depending on these includes
    for (uint32_t v_I_u32 = 0U; v_I_u32 < e_SiCount; ++v_I_u32)
    {
      ShaderInclude_s* v_Include_ps = &includes_as[v_I_u32];

      if (strncmp(v_File_pc, v_Include_ps->fileName_o.getString_pc(), strlen(v_File_pc) - 3) == 0)
      {
        loadShaderInclude_b(includes_as[v_I_u32]);
        v_ReloadAllShaders_b = true;
      }
      
    }

    // get the modified shader file and recreate it
    for (uint32_t v_I_u32 = 0U; v_I_u32 < e_ShaderCount; ++v_I_u32)
    {
      EffectInfo_s* v_EffectInfo_ps = &effects_as[v_I_u32];

      if ((strncmp(v_File_pc, v_EffectInfo_ps->fileName_o.getString_pc(), strlen(v_File_pc) - 3) == 0) || v_ReloadAllShaders_b)
      {
        v_EffectInfo_ps->state_e = e_SsNeedsCreation;
      }
    }
  }

  directoryWatcher.consumeChangedFile();

  LeaveCriticalSection(&criticalSection_o);
#endif


#ifdef RE_USE_VULKAN
  return;
#endif

  // check for (re-)creation
  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_ShaderCount; ++v_I_u32)
  {
    EffectInfo_s* v_EffectInfo_ps = &effects_as[v_I_u32];

    if (e_SsNeedsCreation == v_EffectInfo_ps->state_e)
    {
      MEP_BEGIN("ShaderManager", "CreateShader");
      if (loadFromFiles_b)
      {
        v_EffectInfo_ps->effectFile_o.create_b(renderEngine_po, v_EffectInfo_ps->fileName_o);
      }
      else
      {
        Assert(v_EffectInfo_ps->c_VertexShaderSrc_pc);
        Assert(v_EffectInfo_ps->c_PixelShaderSrc_pc);
        v_EffectInfo_ps->effectFile_o.create_b(renderEngine_po, v_EffectInfo_ps->c_VertexShaderSrc_pc, v_EffectInfo_ps->c_PixelShaderSrc_pc);
      }

      v_EffectInfo_ps->state_e = e_SsReady;


      MEP_END("ShaderManager", "CreateShader");
    }
  }
}

void ShaderManager::preRender_v()
{

}

EffectFile* ShaderManager::createShader_po(Shaders_e i_Shader_e)
{
  return getShader_po(i_Shader_e);
}

EffectFile* ShaderManager::getShader_po(Shaders_e i_Shader_e)
{
  if (effects_as[i_Shader_e].state_e != e_SsReady)
  {
    effects_as[i_Shader_e].state_e = e_SsNeedsCreation;
  }

  return &effects_as[i_Shader_e].effectFile_o;
}

ShaderInclude_s* ShaderManager::getShaderInclude_ps(ShaderInclude_e i_Type_e)
{
  return &includes_as[i_Type_e];
}

ShaderInclude_s* ShaderManager::findShaderInclude_ps(const MEString& i_Name_ro)
{
  ShaderInclude_s* v_FoundInclude_ps = NULL;

  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_SiCount; ++v_I_u32)
  {
    ShaderInclude_s* v_Si_ps = &includes_as[v_I_u32];
    if (NULL != v_Si_ps)
    {
      MEString v_CurrentIncludeName_o = FileUtils::getFileName_o(v_Si_ps->fileName_o, true, c_PathSeparator_c);
      MEString v_InputIncludeName_o   = FileUtils::getFileName_o(i_Name_ro, true, c_PathSeparator_c);

      if (v_CurrentIncludeName_o == v_InputIncludeName_o)
      {
        v_FoundInclude_ps = v_Si_ps;

        // no more reason to loop
        break;
      }
    }
  }


  return v_FoundInclude_ps;
}

bool ShaderManager::loadShaderInclude_b(ShaderInclude_s& b_Include_s)
{
  bool v_Success_b = false;

  osal::File v_IncludeFile_o;
  v_Success_b = v_IncludeFile_o.open_b(b_Include_s.fileName_o.getString_pc(), e_FomRead | e_FomBinary);
  Assert(true == v_Success_b);
  if (true == v_Success_b)
  {
    uint32_t v_FileLength_u32 = static_cast<uint32_t>(v_IncludeFile_o.getSize_u64());
    v_IncludeFile_o.read_u64(b_Include_s.sourceCode_ac, v_FileLength_u32);
    b_Include_s.sourceCode_ac[v_FileLength_u32] = '\0';
  }

  v_IncludeFile_o.close_b();

  return v_Success_b;
}

bool ShaderManager::loadShaderDefine_b(ShaderInclude_s& b_Include_s)
{
  uint32_t v_DefinesLength_u32 = 0; 

  
  // this is project specific
#ifdef ME_USE_EXTERNAL_IMAGE_EXTENSION
  const char* v_ExternalImageExtension_pc = "#define USE_EXTERNAL_IMAGE_EXTENSION \n\0";
  strncpy(&b_Include_s.sourceCode_ac[v_DefinesLength_u32], v_ExternalImageExtension_pc, strlen(v_ExternalImageExtension_pc));
  v_DefinesLength_u32 += strlen(v_ExternalImageExtension_pc);


#else
  // nothing to do

#endif


  Assert(v_DefinesLength_u32 < c_MaxEffectFileLength_u32);
  b_Include_s.sourceCode_ac[v_DefinesLength_u32] = '\0';

  return true;
}

} // namespace me3d
