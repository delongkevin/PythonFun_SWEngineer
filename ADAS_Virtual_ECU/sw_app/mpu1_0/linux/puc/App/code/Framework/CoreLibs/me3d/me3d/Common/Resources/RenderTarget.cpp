#include "Common/Resources/RenderTarget.h"

#include "Common/RenderEngine.h"
#include "Common/Device/Device3D.h"
#include "Common/Textures/TextureInfo.h"


// PRQA S 3054 EOF // flag handling
// PRQA S 3710 EOF // flag handling
// PRQA S 4211 EOF // non const member function modifies data in derived classes, hence makes sense to use here
// PRQA S 1021 EOF // macro is fine here
// PRQA S 1051 EOF // TODO: Check for mipmap generation render target performance on hardware

namespace me3d
{
  RenderTarget::RenderTarget()
    : ITextureConstantData()
    , renderEngine_po(NULL)
    , desc_s()
    , referenceCount_u32(0U)
  {

  }

  RenderTarget::~RenderTarget()
  {
    renderEngine_po = NULL;
  }

  bool RenderTarget::isValid_b() const
  {
    return true;
  }

  TextureType_e RenderTarget::getTextureType_e() const
  {
    return desc_s.type_e;
  }

  TextureConstantDataType_e RenderTarget::getDataType_e() const
  {
    return e_TcdtRenderTarget;
  }

  uint32_t RenderTarget::getWidth_u32() const
  {
    return desc_s.width_u32;
  }

  uint32_t RenderTarget::getHeight_u32() const
  {
    return desc_s.height_u32;
  }

  const MEString& RenderTarget::getFilename_ro() const
  {
    return desc_s.name_o;
  }

  bool_t RenderTarget::create_b(RenderEngine* i_RenEng_po, const RenderTargetDesc_s& i_Desc_rs)
  {
    desc_s          = i_Desc_rs;
    renderEngine_po = i_RenEng_po;

    bool_t v_Success_b = true;

    if ((desc_s.type_e != e_Tt2D)   && (desc_s.type_e != e_Tt2DMultisample) &&
        (desc_s.type_e != e_TtCube) && (desc_s.type_e != e_Tt3D))
    {
      Assert(false);
      v_Success_b = false;
    }

    if (true == v_Success_b)
    {
      if (desc_s.flags_u32 & e_RtrBackBufferSize)
      {
        renderEngine_po->getDevice_po()->getBackBufferSize_v(desc_s.width_u32, desc_s.height_u32);
      }

      if (desc_s.type_e == e_TtCube)
      {
        desc_s.height_u32 = desc_s.width_u32;

        desc_s.flags_u32 = desc_s.flags_u32 & e_RtrAllowedCubeMap;
      }

      if (desc_s.flags_u32 & e_RtrColorUseCurrent)
      {
        desc_s.width_u32  = 0U;
        desc_s.height_u32 = 0U;
        desc_s.levels_u32 = 1U;
      }
      else
      {
        // TODO: Mark Reichert
        // only one mipmap level for GLES2.0
        TextureInfo::computeMipMapLevelCount_v(desc_s.levels_u32, ONE_MIPMAP_LEVEL, desc_s.width_u32, desc_s.height_u32);
      }


    }


    return v_Success_b;
  }

  void RenderTarget::delete_v()
  {

  }

  bool_t RenderTarget::release_b()
  {
    Assert(referenceCount_u32 > 0U);

    --referenceCount_u32;

    // if ref count is zero, no other references exist, so ready to delete
    return (referenceCount_u32 == 0U);
  }

  void RenderTarget::addRef_v()
  {
    ++referenceCount_u32;
  }

  void RenderTarget::onLostDevice_v()
  {

  }

  void RenderTarget::onResetDevice_v()
  {

  }

  void RenderTarget::onBeginFrame_v()
  {
    if (desc_s.flags_u32 & e_RtrClampedFinalTargetSize)
    {
      // don't do anything
    }
    else
    {
      uint32_t v_RequiredWidth_u32;
      uint32_t v_RequiredHeight_u32;
      getClampedFinalTargetSize_v(v_RequiredWidth_u32, v_RequiredHeight_u32);


      if ((v_RequiredWidth_u32  != desc_s.width_u32) || 
          (v_RequiredHeight_u32 != desc_s.height_u32))
      {

        //desc_s.width_u32 = v_RequiredWidth_u32;
        //desc_s.height_u32 = v_RequiredHeight_u32;

        //delete_v();
        //create_b(renderEngine_po, desc_s);
      }
    }

    // always generate mip maps
    //generateMipMaps_v();
  }

  bool_t RenderTarget::prepareSet_b()
  {
    return true;
  }

  void RenderTarget::resolve_v(uint32_t i_ResolveFlag_u32 /*= e_RtfResolveAll*/, uint32_t i_Index_u32 /*= 0U*/, sint32_t i_Face_s32 /*= 0*/)
  {

  }

  void RenderTarget::copyColorRenderTarget_v(RenderTarget* i_TargetRT_po)
  {

  }

  void RenderTarget::generateMipMaps_v()
  {

  }

  void RenderTarget::getClampedFinalTargetSize_v(uint32_t& o_Width_u32, uint32_t& o_Height_u32)const
  {
    uint32_t v_BackBufferWidth_u32;
    uint32_t v_BackBufferHeight_u32;
    renderEngine_po->getDevice_po()->getBackBufferSize_v(v_BackBufferWidth_u32, v_BackBufferHeight_u32);

    o_Width_u32  = v_BackBufferWidth_u32;
    o_Height_u32 = v_BackBufferHeight_u32;
  }

} // namespace me3d