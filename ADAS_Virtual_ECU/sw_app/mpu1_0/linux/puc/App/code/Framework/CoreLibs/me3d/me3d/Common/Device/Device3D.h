//--------------------------------------------------------------------------                                                                                                           
/// @file Device3D.h                                                                         
/// @brief class for basic GPU Device functionality
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef DEVICE3D_H
#define DEVICE3D_H

#include "RenderEngineCfg.h"

#include "Common/RenderEngineTypes.h"
#include "Common/Device/Device3DTypes.h"

// PRQA S 2101 EOF // protected members used here by design.
// PRQA S 2127 EOF // virtual function without pure specifier used here by design.

namespace me3d
{

class RenderEngine;
class MultipleRenderTarget;
class Constant;

class Device3D
{
public:
  Device3D();
  virtual ~Device3D();

  // Creates the Device and the back buffer viewport desc
  virtual bool create_b(RenderEngine* i_RenderEngine_po, const Device3DDesc_s& i_Desc_rs);

  // releases the device
  virtual void release_v();

  virtual void onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);

  virtual void beginFrame_v();

  // Swap buffers
  virtual void endFrame_v();

  // -- Viewport handling --
  // Push the current view port on a stack
  bool_t       pushViewPort_b();

  // Pop the view port from stack and set it as current
  bool_t       popViewPort_b();

  // Set a new view port
  virtual bool setViewPort_b(const ViewPortDesc_s& i_ViewPort_rs);

  // Set a new view port based on the current view port's parameters
  virtual bool setViewPort_b(uint32_t i_Width_u32, uint32_t i_Height_u32, uint32_t i_TopLeftX_u32 = 0U, uint32_t i_TopLeftY_u32 = 0U);
  
  // Return the current view port
  virtual bool getViewPort_b(ViewPortDesc_s& o_ViewPort_rs);

  // Returns the back buffer size
  virtual void getBackBufferSize_v(uint32_t& o_Width_u32, uint32_t& o_Height_u32);
  

  // --- Clear Screen ---
  void clearScreen_v(uint32_t i_ClearFlags_u32);

  void clearScreen_v(uint32_t i_ClearFlags_u32, float32_t i_ClearDepth_f32, uint32_t i_ClearStencil_u32, uint32_t i_Index_u32);

  virtual void clearScreen_v(uint32_t i_ClearFlags_u32, const Color& i_ClearColor_ro, float32_t i_ClearDepth_f32, uint32_t i_ClearStencil_u32, uint32_t i_Index_u32) = 0;


  // -- Render Target Handling --

  // Push the current MRT on a stack
  bool_t pushMultipleRenderTarget_b(MultipleRenderTarget* i_MRT_po);

  // Pop the current MRT from the stack and set the previous MRT as new render destination
  void popMultipleRenderTarget_v();

  /// Create back buffer Multiple Render Target
  virtual void createBackBufferMRT_v();

  /// Release back buffer Multiple Render Target
  virtual void releaseBackBufferMRT_v();

  // -- Draw Methods ---
  virtual void draw_v(PrimitiveType_e i_PrimitiveType_e, uint32_t i_VertexCnt_u32, uint32_t i_VertexOffset_u32);
  virtual void drawIndexed_v(PrimitiveType_e i_PrimitiveType_e, uint32_t i_IndexCnt_u32, uint32_t i_IndexOffset_u32);

  virtual bool setVertexBuffer_b(const VertexBuffer* i_Buffer_po, uint32_t i_Slot_u32, uint32_t i_Offset_u32);
  virtual bool setVertexBuffer_b(const VertexBuffer* i_Buffer_po, uint32_t i_Slot_u32, uint32_t i_Offset_u32, uint32_t i_Stride_u32);
  virtual void resetVertexBuffer_v(uint32_t i_Slot_u32);

  inline const VertexBuffer* getBoundVertexBuffer_po(uint32_t i_Slot_u32) const
  {
    Assert(i_Slot_u32 < c_MaxBoundVertexBuffers_u32);
    return vertexBuffers_as[i_Slot_u32].c_Buffer_po;
  }

protected:
  // Access to render engine
  RenderEngine*                       renderEngine_po;

  // device creation parameters
  Device3DDesc_s                      device3DDesc_s;

  // contains the back buffer's viewport
  ViewPortDesc_s                      backBufferviewPort_s;

  // contains the ortho WVP based on viewport updates
  Constant*                           constantOrthoWVP_po;

  // device can push view ports to this stack and restore them from the stack
  mepl::stack<ViewPortDesc_s>         viewPortStack;

  // Every time a new render target is set to the device, it will also be pushed to this stack
  // So the stack minimum contain the first entry for the starting back buffer (color and may depth surface depending on GL version)
  mepl::stack<MultipleRenderTarget*>  mrtStack;

  //< Contains the currently set/bound vertex buffers
  BoundVertexBuffer_s                 vertexBuffers_as[c_MaxBoundVertexBuffers_u32];
};

} // namespace me3d

#endif // DEVICE3D_H
