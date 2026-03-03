//--------------------------------------------------------------------------                                                                                                           
/// @file Constant.h                                                                         
/// @brief Constant holds a name, data type and the value.
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef CONSTANT_BUFFER_H
#define CONSTANT_BUFFER_H

#include "Common/Resources/Constant.h"

namespace me3d
{
  class ConstantBuffer
  {
  public:
    ConstantBuffer();
    ~ConstantBuffer();

    /// Signalizes that the Constant buffer has to be uploaded when it is needed next
    void signalCommitNeeded_v();

  private:
    bool_t commitNeeded_b; ///< Was a constant changed since last buffer upload?  Should be ignored by ES

  };


} // namespace me3d

#endif