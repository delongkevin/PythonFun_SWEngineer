//--------------------------------------------------------------------------                                                                                                           
/// @file Device3DTypes.h                                                                         
/// @brief Provides structures used by Device
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef DEVICE3D_TYPES_H
#define DEVICE3D_TYPES_H

#include <platform/PlatformAPI.h>

#include "MeclTypeDefs.h"
#include "RenderEngineCfg.h"
#include "Utilities/InOut.h"

#include "platform/stdlib/PixelFormatTypes.h"

// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{

enum TextureType_e
{
  e_Tt1D = 0,
  e_Tt2D,
  e_Tt3D,
  e_TtCube,
  e_Tt2DMultisample,
  e_TtExternal,
  e_TtUnknown
};

struct TextureDesc_s
{
  MEString              fileName_o;
  TextureType_e         type_e;
  mepl::PixelFormat_e   format_e;
  uint32_t              width_u32;
  uint32_t              height_u32;
  uint32_t              depth_u32;
  uint32_t              numFaces_u32;
  uint32_t              numMipMaps_u32;

  TextureDesc_s()
    : fileName_o("")
    , type_e(e_TtUnknown)
    , format_e(mepl::e_RfUnknown)
    , width_u32(0U)
    , height_u32(0U)
    , depth_u32(0U)
    , numFaces_u32(1U)
    , numMipMaps_u32(1U)
  {
    
  }

  void serialize_v(InOut& b_IO_ro)
  {
    b_IO_ro.serialize_v(fileName_o);
    b_IO_ro.serializeEnum_v(type_e);
    b_IO_ro.serializeEnum_v(format_e);
    b_IO_ro.serialize_v(width_u32);
    b_IO_ro.serialize_v(height_u32);
    b_IO_ro.serialize_v(depth_u32);
    b_IO_ro.serialize_v(numFaces_u32);
    b_IO_ro.serialize_v(numMipMaps_u32);
  }
};

enum RenderTargetResource_e
{
  e_RtrDefault                = 0x00000000,  // No flag enabled
  e_RtrDepthTexture           = 0x00000001,  // If set, create a depth-stencil texture and surface. If not set, create only depth
  e_RtrColorUseCurrent        = 0x00000002,  // Use the current set color target as surface and create a suitable texture to this surface
  e_RtrDepthUseCurrent        = 0x00000004,  // Use the current set depth target as surface and create a suitable texture to this surface, Is only active if also the e_RtrDepthTexture flag is set (see above)
  e_RtrBackBufferSize         = 0x00000008,  // Automatically assigns the Backbuffer size when creating the render target or on Resize
  e_RtrUseCroppedViewport     = 0x00000010,  // 
  e_RtrClampedFinalTargetSize = 0x00000020,
  e_RtrCreateReadonlyView     = 0x00000040,
  e_RtrAllowedCubeMap         = e_RtrDefault | e_RtrDepthTexture
};

enum RenderTargetFlag_e
{
  e_RtfResolveNone  = 0x00000000,         // disable resolve
  e_RtfResolveColor = 0x00000001,         // copy / resolve color buffer
  e_RtfResolveDepth = 0x00000002,         // copy / resolve depth buffer
  e_RtfClearColor   = 0x00000004,         // clear color buffer
  e_RtfClearDepth   = 0x00000008,         // clear depth buffer
  e_RtfClearStencil = 0x00000010,         // clear stencil buffer

  e_RtfResolveAll   = e_RtfResolveColor | // copy / resolve all buffers
                      e_RtfResolveDepth,

  e_RtfClearAll     = e_RtfClearColor   | // clear all buffers
                      e_RtfClearDepth   |
                      e_RtfClearStencil
};

struct RenderTargetDesc_s
{
  MEString            name_o;
  uint32_t            width_u32;             // width of the render target
  uint32_t            height_u32;            // height of the render target
  uint32_t            depth_u32;             // depth of the render target (volume textures)
  uint32_t            levels_u32;            // mip map levels
  TextureType_e       type_e;
  mepl::PixelFormat_e colorFormat_e;
  mepl::PixelFormat_e depthFormat_e;
  uint32_t            flags_u32;

  RenderTargetDesc_s()
    : name_o("")
    , width_u32(0U)
    , height_u32(0U)
    , depth_u32(0U)
    , levels_u32(0U)
    , type_e(e_Tt2D)
    , colorFormat_e(mepl::e_RfUnknown)
    , depthFormat_e(mepl::e_RfUnknown)
    , flags_u32(e_RtrDefault)
  {
  }
};


enum DepthBufferSetMode_e
{
  e_DbsNoDepthBuffer,
  e_DbsSetDepthBuffer,
  e_DbsSetReadOnlyDepthBuffer
};

enum ResourceUsage_e
{
  e_RuStatic,   // Static Draw
  e_RuDynamic,  // Dynamic draw
  e_RuStream,   // Stream Draw

  e_RuCount
};

struct VertexBufferDesc_s
{
  ResourceUsage_e resourceUsage_e;  // Static or dynamic draw?
  uint32_t        size_u32;         // size in bytes (e.g. 3 * sizeof(float32_t)
  uint32_t        stride_u32;       // e.g. sizeof(float32_t)
  const char*     c_Layout_pc;      // describing the VertexBuffer layout

  VertexBufferDesc_s()
    : resourceUsage_e(e_RuStatic)
    , size_u32(0U)
    , stride_u32(0U)
    , c_Layout_pc(NULL)
  {
  }
};

class VertexBuffer;

struct BoundVertexBuffer_s
{
  const VertexBuffer* c_Buffer_po;
  uint32_t            offset_u32;
  uint32_t            stride_u32;

  BoundVertexBuffer_s()
    : c_Buffer_po(NULL)
    , offset_u32(0U)
    , stride_u32(0U)
  {
  }
};

struct IndexBufferDesc_s
{
  ResourceUsage_e resourceUsage_e;  // Static or dynamic draw?
  uint32_t        size_u32;    // size in bytes

  IndexBufferDesc_s()
    : resourceUsage_e(e_RuStatic)
    , size_u32(0U)
  {
  }
};

struct ViewPortDesc_s
{
  uint32_t topLeftX_u32;
  uint32_t topLeftY_u32;
  uint32_t width_u32;
  uint32_t height_u32;
  float32_t minDepth_f32;
  float32_t maxDepth_f32;

  ViewPortDesc_s()
    : topLeftX_u32(0U)
    , topLeftY_u32(0U)
    , width_u32(0U)
    , height_u32(0U)
    , minDepth_f32(-100.0F)
    , maxDepth_f32(100.0F)
  {
  }

  void serialize_v(InOut& b_IO_ro)
  {
    b_IO_ro.serialize_v(topLeftX_u32);
    b_IO_ro.serialize_v(topLeftY_u32);
    b_IO_ro.serialize_v(width_u32);
    b_IO_ro.serialize_v(height_u32);
    b_IO_ro.serialize_v(minDepth_f32);
    b_IO_ro.serialize_v(maxDepth_f32);
  }
};

enum PrimitiveType_e
{
  e_PtPointList = 0,   // GL_POINTS
  e_PtLines,           // GL_LINELIST/GL_LINES TODO: check
  e_PtLineStrip,       // GL_LINESTRIP
  e_PtTriangleList,    // GL_TRIANGLES
  e_PtTriangleStrip,   // GL_TRIANGLESTRIP
  e_PtLineListAdj,     // GL_LINES_ADJACENCY_EXT
  e_PtTriangleListAdj, // GL_TRIANGLES_ADJACENCY_EXT
  e_PtCount
};


} // namespace me3d

#endif
