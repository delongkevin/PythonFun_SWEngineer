//--------------------------------------------------------------------------                                                                                                           
/// @file ViewManager.h                                                                         
/// @brief manages the one and only view (for now)
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

// PRQA S 2128 EOF // we are using c++14 autsoar standard, overriding non pure base class virtual fuinctions is allowed

#ifndef VIEW_MANAGER_H
#define VIEW_MANAGER_H

#include "Common/Manager/IManager.h"
#include "MeclTypeDefs.h"


namespace me3d
{

  class  BaseView;
  struct BowlViewDesc_s;
  struct SingleViewDesc_s;
  class EffectFileRenderStateBlock;

  class MultipleRenderTarget;

  typedef mepl::vector<BaseView*> ViewList_t;

  class ViewManager : public IManager
  {
  public:
    ViewManager();
    virtual ~ViewManager();

    // IManager
    virtual bool_t                 isEnabled_b();
    virtual bool_t                 create_b(RenderEngine* b_RenderEngine_po);
    virtual void                   release_v();
    virtual void                   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
    virtual void                   beginFrame_v();
    virtual void                   preRender_v();
    virtual bool_t                 beginScene_b();
    virtual void                   endScene_v();
                                   
    virtual void                   reset_v();

    BaseView*                      createBowlView_po(const BowlViewDesc_s& i_Desc_rs);
    BaseView*                      createSingleView_po(const SingleViewDesc_s& i_Desc_rs);

    void                           releaseView_v(BaseView* i_View_po);


    const ViewList_t&              getViewList_ro() const;

    bool                           intersectRay_b(const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro, Vector3f& o_Intersection_ro);

    void                           modifyHeight_v(float32_t i_X_f32, float32_t i_Z_f32, float32_t i_Height_f32, float32_t i_Radius_f32);

    void                           setRender_v(BaseView* i_View_po);

    ME_INLINE const ViewList_t&    getRenderList_t() const { return renderList_apo; } 

private:
    EffectFileRenderStateBlock* renderStateAlphaBlend_po;
    EffectFileRenderStateBlock* renderStateDisableDepth_po;
    RenderEngine* renderEngine_po;
    ViewList_t viewList_apo;
    ViewList_t renderList_apo;
};

} // namespace me3d

#endif
