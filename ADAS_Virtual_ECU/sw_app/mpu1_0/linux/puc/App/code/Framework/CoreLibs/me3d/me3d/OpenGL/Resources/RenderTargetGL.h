
// PRQA S 2100 EOF // we use override keyword.
// PRQA S 2128 EOF // we use override keyword.

#ifndef RENDER_TARGET_GL_H
#define RENDER_TARGET_GL_H

#include "Common/Resources/RenderTarget.h"

namespace me3d
{
  class RenderTargetGL : public RenderTarget
  {
  public:
    RenderTargetGL();
    virtual ~RenderTargetGL();

    uint32_t getColorBufferId_u32() const;
    uint32_t getDepthBufferId_u32() const;

    virtual bool_t create_b(RenderEngine* i_RenEng_po, const RenderTargetDesc_s& i_Desc_rs) ME_OVERRIDE;

    virtual void delete_v() ME_OVERRIDE;

    virtual void onLostDevice_v() ME_OVERRIDE;

    virtual void onResetDevice_v() ME_OVERRIDE;

    virtual void resolve_v(uint32_t i_ResolveFlag_u32 = e_RtfResolveAll, uint32_t i_Index_u32 = 0U, sint32_t i_Face_s32 = 0) ME_OVERRIDE;

    virtual void copyColorRenderTarget_v(RenderTarget* i_TargetRT_po) ME_OVERRIDE;

    virtual void generateMipMaps_v() ME_OVERRIDE;

    virtual void* getTexture_pv(TextureConstantBufferType_e i_BufferType_e) ME_OVERRIDE;

  protected:
    // Can be used for creating or resizing
    // If a buffer should be created, but GLID is != 0, it is resized instead of newly created.
    // This way, you dont have to recreate the MultipleRenderTargets, as they can keep on
    // referencing the old GLID
    bool_t createOrResize_b(RenderEngine* i_RenEng_po, const RenderTargetDesc_s& i_Desc_rs);

    bool_t createColorBuffer_b();
    bool_t createDepthBuffer_b();


  protected:
    // color texture
    uint32_t colorBufferId_u32;

    // for packed depth-stencil formats, the GLIDs for depth and stencil buffers are the same.
    uint32_t depthBufferId_u32;
  };

} // namespace me3d

#endif

