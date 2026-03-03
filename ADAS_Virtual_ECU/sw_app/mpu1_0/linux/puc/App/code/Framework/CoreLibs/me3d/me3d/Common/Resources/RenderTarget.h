//--------------------------------------------------------------------------                                                                                                           
/// @file RenderTarget.h                                                                         
/// @brief maybe we need this in future
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

// PRQA S 2127 EOF // c++ 14 autosar standard permits

#ifndef RENDER_TARGET_H
#define RENDER_TARGET_H

#include "Common/Resources/ITextureConstantData.h"

namespace me3d
{

class RenderEngine;

class RenderTarget : public ITextureConstantData
{
public:
  RenderTarget();
  virtual ~RenderTarget();

  inline const RenderTargetDesc_s& getDesc_rs() const 
  { 
    return desc_s; 
  }

  // Inherited from ITextureConstantData
  virtual bool isValid_b() const;

  // Inherited from ITextureConstantData
  virtual TextureType_e getTextureType_e() const;

  // Inherited from ITextureConstantData
  virtual TextureConstantDataType_e getDataType_e() const;

  // Inherited from ITextureConstantData
  virtual uint32_t getWidth_u32() const;

  // Inherited from ITextureConstantData
  virtual uint32_t getHeight_u32() const;

  // Inherited from ITextureConstantData
  virtual const MEString& getFilename_ro() const;


  virtual bool_t create_b(RenderEngine* i_RenEng_po, const RenderTargetDesc_s& i_Desc_rs);
  
  // Delete all resources and initialize member variables
  virtual void delete_v();

  // decrease the reference counter and return true if ready to delete (refcount is zero)
  virtual bool_t release_b();

  // increase reference counter by one
  virtual void addRef_v();

  // called before device3D is reset
  virtual void onLostDevice_v();

  // called after device3D is reset
  virtual void onResetDevice_v();

  // called on every beginFrame
  void onBeginFrame_v();

  // prepare e_RtrColorUseCurrent or e_RtrDepthUseCurrent surfaces
  virtual bool_t prepareSet_b();

  // Resolve render target and maybe depth-stencil buffer (Face is only used by cube-map render targets)
  virtual void resolve_v(uint32_t i_ResolveFlag_u32 = e_RtfResolveAll, uint32_t i_Index_u32 = 0U, sint32_t i_Face_s32 = 0);

  // Copies this render-target to the target RT, will automatically resolve the sub-resources if multi-sampling 
  // is enabled for the source but not for the target RT
  virtual void copyColorRenderTarget_v(RenderTarget* i_TargetRT_po);

  // Generates / Updates all mip map levels of render target
  virtual void generateMipMaps_v();

  // returns the size according to e_RtrClampedFinalTargetSize
  void getClampedFinalTargetSize_v(uint32_t& o_Width_u32, uint32_t& o_Height_u32)const;

protected:
  RenderEngine*       renderEngine_po;
  RenderTargetDesc_s  desc_s;           // describes the render targets properties
  uint32_t            referenceCount_u32;
};

} // namespace me3d

#endif
