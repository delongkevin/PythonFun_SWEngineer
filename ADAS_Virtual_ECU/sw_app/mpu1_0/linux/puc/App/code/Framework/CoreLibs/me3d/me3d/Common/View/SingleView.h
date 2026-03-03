#ifndef SINGLE_VIEW_H
#define SINGLE_VIEW_H

#include "Common/View/BaseView.h"
#include "Common/RenderEngine.h"
#include "Common/Resources/VertexBuffer.h"
#include "Common/Resources/IndexBuffer.h"
#include "Common/Resources/VertexDeclarationTypes.h"
#include "Common/Manager/ShaderManager.h"
#include "Common/Resources/Constant.h"

namespace me3d
{

  class SingleView : public BaseView
  {
  public:
    
    SingleView();
    virtual ~SingleView();

    void                          updateSingleView_v();

    bool_t                        create_b(const SingleViewDesc_s& i_Desc_rs, RenderEngine* b_RenderEngine_po);
    virtual void                  release_v() ME_OVERRIDE;


    SingleViewDesc_s*             getDesc_ps();
    virtual void                  setTransform_v(const Transform& i_Transform_ro) ME_OVERRIDE;

    // project position to view (GL to Mecl conversion, including scale, etc)
    virtual Vector3f              project_o(const Vector3f& i_GLPosition_ro) ME_OVERRIDE;
    virtual Vector4f              project4_o(const Vector3f& i_GLPosition_ro) ME_OVERRIDE;

    // unproject position from view (Mecl to GL conversion, including scale, etc)
    virtual Vector3f              unProject_o(const Vector3f& i_MeclPosition_ro) ME_OVERRIDE;

    virtual void                  update_v(uint32_t i_Flags_u32) ME_OVERRIDE;
    virtual void                  createBuffers_v(bool i_Indices_b, bool i_ResizeBuffers_b) ME_OVERRIDE;
                                  
    virtual bool_t                intersectRay_b(const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro, Vector3f& o_Intersection_ro) ME_OVERRIDE;
    virtual bool_t                setHeight_b(float32_t i_X_f32, float32_t i_Z_f32, float32_t i_Height_f32) ME_OVERRIDE;
                                  
    virtual void                  render_v() ME_OVERRIDE;
                                  
    virtual void                  onResize_v() ME_OVERRIDE;

  protected:

    static Shaders_e                     getShader_e();

  private:

    void                          createIndices_v();
                                  
    void                          createVertices_v();
                                  
    void                          updateConstants_v()const;

    void                          updateRatios_v();

  private:

    EffectFile*                   effect_po;

    VertexBuffer*                 vertexBuffer_po;

    IndexBuffer*                  indexBuffer_po;

    VertexSingleView_s*           vertices_as;

    uint16_t*                     indices_au16;

    uint32_t                      indexCount_u32;

    SingleViewDesc_s              singleViewDesc_s;

    RenderEngine*                 renderEngine_po;

    SingleViewf                   singleView_o;

    Constant*                     constantTex_po;

    Vector2f                      fullResolutionRatio_o;
    Vector2f                      viewSizeRatio_o;

  };


}; // namespace me3d



#endif
