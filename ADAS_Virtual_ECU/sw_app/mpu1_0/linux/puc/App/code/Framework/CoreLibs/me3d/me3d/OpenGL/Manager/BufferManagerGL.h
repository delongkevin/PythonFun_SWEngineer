//--------------------------------------------------------------------------                                                                                                           
/// @file BufferManagerGL.h                                                                         
/// @brief OpenGL BufferManager implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef BUFFERMANAGER_GL_H
#define BUFFERMANAGER_GL_H

#include "Common/Manager/BufferManager.h"

#include "OpenGL/Resources/VertexBufferGL.h"
#include "OpenGL/Resources/IndexBufferGL.h"

namespace me3d
{

class BufferManagerGL : public BufferManager
{
public:
  BufferManagerGL();
  virtual ~BufferManagerGL();

  // IManager
  virtual void release_v();
  virtual void onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void beginFrame_v();
  virtual void preRender_v();

protected:
  virtual VertexBuffer* getNewVertexBuffer_po() ME_OVERRIDE;
  virtual IndexBuffer*  getNewIndexBuffer_po() ME_OVERRIDE;

private:
  VertexBufferGL vertexBufferPool_ao[c_MaxVertexBuffers_u32];
  IndexBufferGL  indexBufferPool_ao [c_MaxIndexBuffers_u32];
};


} // namespace me3d

#endif
