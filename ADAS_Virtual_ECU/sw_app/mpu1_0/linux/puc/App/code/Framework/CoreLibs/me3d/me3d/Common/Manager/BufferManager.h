//--------------------------------------------------------------------------                                                                                                           
/// @file BufferManager.h                                                                         
/// @brief Manages Vertex and Index Buffer creation and deletion
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef ME3D_BUFFER_MANAGER_H
#define ME3D_BUFFER_MANAGER_H

#include "IManager.h"

#include "Common/Resources/VertexBuffer.h"
#include "Common/Resources/IndexBuffer.h"

#include "RenderEngineCfg.h"

namespace me3d
{

class BufferManager : public IManager
{
public:
  BufferManager();
  virtual ~BufferManager();

  // IManager interface
  virtual bool create_b(RenderEngine* b_RenderEngine_po);
  virtual bool_t isEnabled_b();

  VertexBuffer* createVertexBuffer_po(const VertexBufferDesc_s& i_Desc_rs, const void* i_InitialData_pv = NULL);
  IndexBuffer*  createIndexBuffer_po( const IndexBufferDesc_s& i_Desc_rs, const void* i_InititalData_pv = NULL);

  static void releaseVertexBuffer_v(VertexBuffer* b_VertexBuffer_po);
  static void releaseIndexBuffer_v(IndexBuffer* b_IndexBuffer_po);

  // Interface for creating Vertex and Index Buffer API specific objects
protected:
  virtual VertexBuffer* getNewVertexBuffer_po() = 0;
  virtual IndexBuffer*  getNewIndexBuffer_po()  = 0;

protected:
  RenderEngine*  renderEngine_po;

};

} // namespace me3d

#endif // BUFFERMANAGER_H