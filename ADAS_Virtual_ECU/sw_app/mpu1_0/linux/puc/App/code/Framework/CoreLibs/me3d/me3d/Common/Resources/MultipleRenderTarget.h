
// PRQA S 2127 EOF // see c++14 autosar standard

#ifndef MULTIPLE_RENDER_TARGET_H
#define MULTIPLE_RENDER_TARGET_H

#include <platform/PlatformAPI.h>

#include "Common/Device/Device3DTypes.h"
#include "Math/Color.h"

namespace me3d
{

const uint32_t MAX_MRT_COLOR_RTS  = 6;

class RenderEngine;
class Device3D;
class RenderTarget;


class MultipleRenderTarget
{
public:
  MultipleRenderTarget();
  virtual ~MultipleRenderTarget();

  // Initialize the MRT and create the RTS
  virtual bool_t create_b(RenderEngine* i_RenEng_po, RenderTargetDesc_s** i_ColorDesc_pps, RenderTargetDesc_s* i_DepthDesc_ps);

  // Release the MRT resources.
  virtual void release_v();

  // Create a MRT with the back buffer resources
  virtual void createBackBufferMRT_v(Device3D* i_Device_po) = 0;

  // Release back buffer surcfaces
  virtual void releaseBackBufferMRT_v();

  // Is called before Device3D is reset
  virtual void onLostDevice_v();

  // Is called after Device3D was reset
  virtual void onResetDevice_v();

  // Override this method to set the MRT-Resources/Surfaces
  virtual bool_t setMRTResources_b(uint32_t i_Face_u32, uint32_t i_Level_u32, DepthBufferSetMode_e i_Mode_e = e_DbsSetDepthBuffer);

  // Set the MRTs as new destination buffers
  bool_t setMultipleRenderTargets_b(uint32_t i_ClearFlags_u32 = 0U, 
                                    Color i_ClearColor_o = Color(0.0F, 0.0F, 0.0F, 0.0F), 
                                    float32_t i_ClearDepth_f32 = 1.0F, 
                                    uint32_t i_ClearStencil_u32 = 0U,
                                    uint32_t i_Face_u32 = 0U, 
                                    uint32_t i_Level_u32 = 0U, 
                                    const ViewPortDesc_s* i_ViewPort_ps = NULL, 
                                    DepthBufferSetMode_e i_DepthBufferSetMode_e = e_DbsSetDepthBuffer);

  // Restore and maybe resolve the MRTs
  void restoreMultipleRenderTargets_v(uint32_t i_ResolveFlags_u32 = e_RtfResolveNone)const;

  // Resolve the MRTs
  void resolve_v(uint32_t i_ResolveFlags_u32)const;

  /// Generate the mip maps for all render targets
  void generateMipMaps_v()const;

  /// Get a color-RT from a specific stage
  RenderTarget* getColorRenderTarget_po(uint32_t i_index_u32 = 0U)const;

  /// Get the depth-RT
  RenderTarget* getDepthRenderTarget_po()const;

  /// Return the main description (with it the color render target desc, if the color render target
  /// exist, else the depth render target desc)
  const RenderTargetDesc_s* getMainDesc_ps() const;

  /// Returns the current or last set face index
  uint32_t GetFace_u32()const;

  /// Returns the current or last set mip map level index
  uint32_t getLevel_u32()const;

  // Returns true if depth buffer is set
  DepthBufferSetMode_e getDepthBufferSetMode_e()const;

  // Returns the width and height of the multiple render target
  // returns either actual (reserved) size oder used viewport size
  // in most cases used size == actual size, except when e_RtrUseCroppedViewport flag is set
  void getSize_v(uint32_t& o_Width_u32, uint32_t& o_Height_u32, bool_t i_UsedViewport_b)const;
  

protected:
  // Access to render engine
  RenderEngine*         renderEngine_po;

  // Pointer to the color render targets
  RenderTarget*         colorRenderTargets_apo[MAX_MRT_COLOR_RTS];

  // Pointer to the depth-stencil render target
  RenderTarget*         depthRenderTarget_po;

  // Last or currently set face of the multiple render target
  uint32_t              face_u32; 

  // Last or currently set level of the multiple render target
  uint32_t              level_u32;

  // Describes if the depth render target is used during SetMultipleRenderTargets
  DepthBufferSetMode_e  depthBufferSetMode_e;
};

} // namespace me3d

#endif
