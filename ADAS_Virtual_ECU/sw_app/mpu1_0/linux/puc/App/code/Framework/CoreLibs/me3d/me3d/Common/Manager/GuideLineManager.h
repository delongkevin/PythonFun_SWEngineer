//--------------------------------------------------------------------------                                                                                                           
/// @file SvgManager.h                                                                         
/// @brief Manages GuideLine Objects
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

#ifndef ME3D_GUIDE_LINE_MANAGER_H
#define ME3D_GUIDE_LINE_MANAGER_H

#include "Common/Manager/IManager.h"

#include "RenderEngineCfg.h"

#include "Common/GuideLine/GuideLineObject.h"

#include "MeclTypeDefs.h"
#include "Math/Color.h"

// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{

class VertexBuffer;
class Texture;


typedef mepl::vector<GuideLineObject*> GuideLineList_t;

class GuideLineManager : public IManager
{
public:
  GuideLineManager();
  virtual ~GuideLineManager();

  // IManager
  virtual bool_t isEnabled_b();
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   preRender_v();
  virtual void   reset_v();

  GuideLineObject* createGuideLine_po(const GuideLineObjectDesc_s& i_Desc_ro);
  void releaseGuideLine_v(GuideLineObject* i_GuideLine_po);
  void setRender_v(GuideLineObject* i_GuideLine_po);

  ME_INLINE const GuideLineList_t& getRenderList_t() const { return renderList_apo; } 


private:
  RenderEngine*   renderEngine_po;
  GuideLineList_t guideLineList_apo;
  GuideLineList_t renderList_apo;
  
};

} // namespace me3d

#endif // ME3D_GUIDE_LINE_MANAGER_H
