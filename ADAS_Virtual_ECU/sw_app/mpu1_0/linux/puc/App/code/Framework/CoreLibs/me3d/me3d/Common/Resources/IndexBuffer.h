//--------------------------------------------------------------------------                                                                                                           
/// @file IndexBuffer.h                                                                         
/// @brief Indices sent to GPU
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 


#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include "Common/Device/Device3DTypes.h"

// PRQA S 2127 EOF // virtual function without pure specifier used here by design.
// PRQA S 2101 EOF // protected members used here by design.

namespace me3d
{

class IndexBuffer
{
public:
  IndexBuffer();
  virtual ~IndexBuffer();

  virtual bool_t create_b(const IndexBufferDesc_s& i_Desc_rs, const void* i_InitialData_pv = NULL);

  virtual void release_v();

  virtual void set_v();

  virtual void updateSubData_v(uint32_t i_Offset_u32, uint32_t i_Size_u32, const void* i_Data_pv) = 0;

protected:
  IndexBufferDesc_s desc_s;
};

} // namespace me3d

#endif
