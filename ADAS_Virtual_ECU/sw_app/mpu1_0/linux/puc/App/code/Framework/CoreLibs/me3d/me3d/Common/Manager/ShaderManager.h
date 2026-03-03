//--------------------------------------------------------------------------                                                                                                           
/// @file ShaderManager.h                                                                         
/// @brief Contains all the used Shaders. 
/// Automatically reloads and recompiles Shaders if USE_DIRECTORY_WATCHER and loadFromFiles_b is active
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include "IManager.h"

#include "RenderEngineCfg.h"
#include "Common/Effect/EffectFile.h"

#include "Utilities/Directory.h"

#ifdef USE_DIRECTORY_WATCHER
#include "Utilities/DirectoryWatcher.h"
#endif

// PRQA S 2100 EOF // public members used here by design.
// PRQA S 2101 EOF // protected members used here by design.

namespace me3d
{

enum ShaderInclude_e
{
  e_SiConstants = 0,
  e_SiFunctions,
  e_SiDefines,
  e_SiCount
};

struct ShaderInclude_s
{
  char sourceCode_ac[c_MaxEffectFileLength_u32];
  MEString fileName_o;
};

enum ShaderState_e
{
  e_SsInvalid = 0,
  e_SsNeedsCreation,
  e_SsReady
};

struct EffectInfo_s
{
  ShaderState_e state_e;
  const char*   c_VertexShaderSrc_pc;
  const char*   c_PixelShaderSrc_pc;
  MEString      fileName_o;
  EffectFile    effectFile_o;

  EffectInfo_s()
    : state_e(e_SsInvalid)
    , c_VertexShaderSrc_pc(NULL)
    , c_PixelShaderSrc_pc(NULL)
    , fileName_o("")
  {
  }
};

class EffectFilePass;
class EffectFileShader;
class EffectFileVertexDeclaration;
class EffectFileConstantBlock;
class EffectFileParser;
class EffectFileRenderStateBlock;

class ShaderManager : public IManager
{
public:
  ShaderManager();
  virtual ~ShaderManager();

  // IManager
  virtual bool_t isEnabled_b();
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   preRender_v();

  virtual EffectFilePass*               createPass_po() = 0;
  virtual EffectFileShader*             createEffectFileShader_po() = 0;
  virtual EffectFileVertexDeclaration*  createVertexDeclaration_po() = 0;
  virtual EffectFileConstantBlock*      createConstantBlock_po() = 0;
  virtual EffectFileParser*             createParser_po() = 0;
  virtual EffectFileRenderStateBlock*   createRenderStateBlock_po() = 0;

  EffectFile* createShader_po(Shaders_e i_Shader_e);
  EffectFile* getShader_po(Shaders_e i_Shader_e);
  ShaderInclude_s* getShaderInclude_ps(ShaderInclude_e i_Type_e);
  ShaderInclude_s* findShaderInclude_ps(const MEString& i_Name_ro);

private:
  // load include shader file
  static bool loadShaderInclude_b(ShaderInclude_s& b_Include_s);

  // define includes by hand for each project, set different settings
  static bool loadShaderDefine_b(ShaderInclude_s& b_Include_s);


protected:
  RenderEngine*   renderEngine_po;
  bool            loadFromFiles_b;
  EffectInfo_s    effects_as[e_ShaderCount];
  ShaderInclude_s includes_as[e_SiCount];


#ifdef USE_DIRECTORY_WATCHER
  DirectoryWatcher directoryWatcher;
  CRITICAL_SECTION criticalSection_o;
#endif
};

} // namespace me3d

#endif // SHADER_MANAGER_H