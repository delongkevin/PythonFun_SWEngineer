//--------------------------------------------------------------------------                                                                                                           
/// @file VertexBufferGL.h                                                                         
/// @brief OpenGL VertexBuffer implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef VERTEXBUFFER_GL
#define VERTEXBUFFER_GL

#include "Common/Resources/VertexBuffer.h"
#include "OpenGL/GLIncludes.h"

// PRQA S 2101 EOF // protected members used here by design.
// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.

namespace me3d
{

class VertexBufferGL : public VertexBuffer
{
public:
  VertexBufferGL();
  virtual ~VertexBufferGL();

  virtual bool create_b(RenderEngine* b_RenderEngine_po, const VertexBufferDesc_s& i_Desc_rs, const void* i_InitialData_pv = NULL);

  virtual void release_v();

  virtual void bind_v() const;

  virtual uint32_t getID_u32() const;

  virtual void updateSubData_v(uint32_t i_Offset_u32, uint32_t i_Size_u32, const void* i_Data_pv);

private:
  uint32_t bufferID_u32;
};

} // namespace me3d

#endif
