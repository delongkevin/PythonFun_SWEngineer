#ifndef EFFECT_FILE_CONSTANT_BLOCK_H
#define EFFECT_FILE_CONSTANT_BLOCK_H

//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFileConstantBlock.h                                                                         
/// @brief Checks for constants in the shader and sends the values to GPU
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#include "Common/Effect/EffectFile.h"
#include "Common/RenderEngine.h"
#include "Common/Resources/Constant.h"
#include "Common/Manager/ConstantsManager.h"

// PRQA S 2101 EOF // protected members used here by design.
// PRQA S 2127 EOF // virtual function overload used here by design.

namespace me3d
{

class EffectFilePass;

class EffectFileConstantBlock
{
public:
  EffectFileConstantBlock();
  virtual ~EffectFileConstantBlock();

  virtual void release_v() = 0;

  virtual bool create_v(EffectFilePass* b_Pass_po, EffectFile* b_EffectFile_po);
  
  virtual bool initialize_b(EffectFilePass* i_Pass_po, EffectFile* i_EffectFile_po) = 0;

  virtual void commit_v() = 0;

protected:
  Constant* findLocalOrGlobalConstant_po(const char* i_Name_pc) const
  {
    Constant* v_Constant_po = effectFile_po->getRenderEngine_po()->getConstantsManager_po()->findConstant_po(i_Name_pc);
    
    if (NULL == v_Constant_po)
    {

    }

    return v_Constant_po;
  }




protected:
  EffectFile* effectFile_po;

};

} // namespace me3d

#endif
