//--------------------------------------------------------------------------                                                                                                           
/// @file ModelManager.h                                                                         
/// @brief Contains all the created models
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 


// PRQA S 2128 EOF // C++14 Autosar Standard permits

#ifndef MODEL_MANAGER_H
#define MODEL_MANAGER_H

#include "Common/Manager/IManager.h"

#include "RenderEngineCfg.h"
#include "Common/Model/Model.h"

namespace me3d
{

class ModelManager : public IManager
{
public:
  ModelManager();
  virtual ~ModelManager();

  // IManager
  virtual bool_t isEnabled_b(); 
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   preRender_v();
  virtual void   reset_v();

  void releaseModel_v(uint32_t i_Id_u32);
  static void releaseModel_v(Model* i_Model_po);
  Model* getModel_po(uint32_t i_Id_u32);
  Model* createModel_po(const MEString& i_FileName_ro);
  Model* createModel_po(const ModelDesc_s& i_Desc_rs);
  void renderModel_v(Model* i_Model_po);

  inline Model* getModels_po() { return &models_ao[0]; }
  inline Model** getRenderList_po() { return &renderList_apo[0]; }
  inline uint32_t getNumModelsToRender_u32() const { return numModelsToRender_u32; }

protected:
  uint32_t getFreeModelIndex_u32() const;

private:
  RenderEngine* renderEngine_po;
  uint32_t      numModelsToRender_u32;
  Model*        renderList_apo[c_MaxModels_u32];
  Model         models_ao[c_MaxModels_u32];
};

} // namespace me3d

#endif
