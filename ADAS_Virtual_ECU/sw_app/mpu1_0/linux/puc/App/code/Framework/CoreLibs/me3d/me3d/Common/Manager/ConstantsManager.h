//--------------------------------------------------------------------------                                                                                                           
/// @file ConstantsManager.h                                                                         
/// @brief Contains all the Shared Constants in a Pool
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef CONSTANTS_MANAGER_H
#define CONSTANTS_MANAGER_H

#include "RenderEngineCfg.h"

#include "Common/Manager/IManager.h"
#include "Common/Resources/Constant.h"

namespace me3d
{

// This is a default constant manager implementation.
// The interface implementation of IManager is currently unused.
class ConstantsManager : public IManager
{
public:
  ConstantsManager();
  virtual ~ConstantsManager();

  // IManager
  virtual bool_t isEnabled_b(); 
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   preRender_v();


  static Constant* createConstant_po()
  {
    // PRQA S 5118 1 // C++14 Autosar Standard permits
    return new Constant();
  }

  Constant* findConstant_po(const MEString& i_Name_ro)
  {
    Constant* v_FoundConstant_po = NULL;

    // 1.) Find in constant buffer
    // Todo


    // 2.) Try to find the constant in the global/shared constant list
    size_t constantsCount = sharedConstants_t.size();

    for (size_t i = 0; i < constantsCount; ++i)
    {
      if (sharedConstants_t[i]->getName_ro() == i_Name_ro)
      {
        v_FoundConstant_po =  sharedConstants_t[i];
        break;
      }
    }

    return v_FoundConstant_po;
  }

  // find or create new shared constant
  Constant* getSharedConstant_po(const MEString& i_Name_ro, const ConstantDesc_s* b_Desc_ps = NULL)
  {
    // Create new constant
    Constant* v_Constant_po = findConstant_po(i_Name_ro);

    if ((NULL == v_Constant_po) && (NULL != b_Desc_ps))
    {
      v_Constant_po = createConstant_po();

      v_Constant_po->create_v(*b_Desc_ps, NULL);

      sharedConstants_t.push_back(v_Constant_po);
    }

    return v_Constant_po;
  }

  Constant* getSharedConstant_po(const ConstantDesc_s& i_Desc_ro)
  {
    return getSharedConstant_po(i_Desc_ro.name_o, &i_Desc_ro);
  }

private:
  mepl::vector<Constant*> sharedConstants_t;


};

} // namespace me3d

#endif
