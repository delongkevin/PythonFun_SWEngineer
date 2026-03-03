//--------------------------------------------------------------------------                                                                                                           
/// @file TextureManager.h                                                                         
/// @brief Provides functionality to create, release and find textures by name. 
/// Automatically reloads and Textures if USE_DIRECTORY_WATCHER is defined
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "RenderEngineCfg.h" 

#include "Common/Manager/IManager.h"
#include "Common/Device/Device3DTypes.h"

#ifdef USE_DIRECTORY_WATCHER
#include "Utilities/DirectoryWatcher.h"
#endif

 

// PRQA S 2128 EOF // we are using c++14 autsoar standard, overriding non pure base class virtual fuinctions is allowed
// PRQA S 2101 EOF // protected members used here by design
// PRQA S 2127 EOF // c++ 14 Autosar Standard permits

namespace me3d
{

class Texture;
class RenderTarget;
class MultipleRenderTarget;

class TextureManager : public IManager
{
public:
  TextureManager();
  virtual ~TextureManager();

  // IManager Interface
  virtual bool_t isEnabled_b();
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   preRender_v();

  // Texture Management
  Texture* createTexture_po(const MEString& i_Name_ro);
  Texture* createTexture_po(const TextureDesc_s& i_Desc_rs, const uint8_t* i_InitalData_pu8);
  void     releaseTexture_v(Texture* b_Texture_po);
  Texture* findTexture_po(const MEString& i_Name_ro);

  // Render Target Management
  RenderTarget* createRenderTarget_po(const RenderTargetDesc_s& i_Desc_rs);
  void releaseRenderTarget_v(RenderTarget* i_RenderTarget_po);
  RenderTarget* findRenderTarget_po(const MEString& i_Name_ro);

  // multiple Render Target Management

  // Returns a multiple render target to the given name (maybe use already existing target)
  MultipleRenderTarget* createMultipleRenderTarget_po(RenderTargetDesc_s** i_ColorDescs_pps, RenderTargetDesc_s* i_DepthDesc_ps);

  // Use this method to create a MRT with a single RT.
  MultipleRenderTarget* createMultipleRenderTarget_po(RenderTargetDesc_s* i_ColorDesc_ps, RenderTargetDesc_s* i_DepthDesc_ps);

  // Use this method if your to lazy to build a array for a MRT-description.
  MultipleRenderTarget* createMultipleRenderTarget_po(RenderTargetDesc_s* i_ColorDesc0_ps, 
    RenderTargetDesc_s* i_ColorDesc1_ps, RenderTargetDesc_s* i_ColorDesc2_ps,
    RenderTargetDesc_s* i_ColorDesc3_ps, RenderTargetDesc_s* i_DepthDesc_ps);

  // Release and maybe delete render target (if no other references of the render target exist)
  virtual void releaseMultipleRenderTarget_v(MultipleRenderTarget* i_MultipleRenderTarget_po);


  virtual MultipleRenderTarget* createMultipleRenderTarget_po() = 0;
protected:
  // pure virtual function to create a new platform specific Texture
  virtual Texture* createTexture_po() = 0;

  // pure virtual function to create a new platform specific Render Target
  virtual RenderTarget* createRenderTarget_po() = 0;


protected:
  // pointer to render engine
  RenderEngine* renderEngine_po;

  // List of all textures loaded from file
  mepl::vector<Texture*>      textures;

  // List of all render targets
  mepl::vector<RenderTarget*> renderTargets;

  mepl::vector<MultipleRenderTarget*> multipleRenderTargets;

private:
#ifdef USE_DIRECTORY_WATCHER
  DirectoryWatcher directoryWatcher;
  CRITICAL_SECTION criticalSection_o;
#endif

};

} // namespace me3d

#endif // TEXTURE_MANAGER_H
