#include "Common/RenderInterface.h"

#include "Common/Renderer/CubeMapRenderer.h"
#include "Common/Manager/ViewManager.h"

namespace me3d
{
  RenderInterface::RenderInterface()
    : guidGenerator_o()
    , modelInterface_o()
    , debugInterface_o()
    , cameraInterface_o()
    , guiInterface_o()
    , guideLineInterface_o()
    , deviceInterface_o()
    , lightInterface_o()
    , bowlViewInterface_o()
    , singleViewInterface_o()
    , renderEngine_o()
  {
    for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxLutSize_u32; ++v_I_u32)
    {
      objectLut_apv[v_I_u32] = NULL;
      Assert(objectLut_apv[v_I_u32] == NULL);
      typeLut_apu8[v_I_u32]  = e_OtInvalid;
    }
  }

  RenderInterface::~RenderInterface()
  {

  }

  bool RenderInterface::create_b(const RenderEngineDesc_s& i_Desc_rs)
  {
    renderEngine_o.create_b(i_Desc_rs);

    modelInterface_o.create_v(this);
    debugInterface_o.create_v(renderEngine_o.getDebugRenderer_po());
    cameraInterface_o.create_v(renderEngine_o.getCameraManager_po());
    guiInterface_o.create_v(this);
    guideLineInterface_o.create_v(this);
    deviceInterface_o.create_v(renderEngine_o.getDevice_po());
    lightInterface_o.create_v(renderEngine_o.getLightManager_po());
    bowlViewInterface_o.create_v(this);
    singleViewInterface_o.create_v(this);
    textureInterface_o.create_v(this);
    materialInterface_o.create_v(this);

    return true;
  }

  void RenderInterface::release_v()
  {
    renderEngine_o.release_v();
  }

  void RenderInterface::msgBeginFrame_v(uint32_t i_RenderTargetId_u32 /* = c_InvalidGUID_u32 */)
  {
    MultipleRenderTarget* v_MRT_po = NULL;

    if (i_RenderTargetId_u32 != c_InvalidGUID_u32)
    {
      v_MRT_po = reinterpret_cast<MultipleRenderTarget*>(getAtID_pv(i_RenderTargetId_u32, e_OtRenderTarget));
      Assert(NULL != v_MRT_po);
    }

    renderEngine_o.beginFrame_v(v_MRT_po);
  }

  void RenderInterface::msgEndFrame_v()
  {
    renderEngine_o.endFrame_v();
  }

  void RenderInterface::msgResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
  {
    renderEngine_o.onResize_v(i_Width_u32, i_Height_u32);
  }

  bool RenderInterface::createCubeMap_b(const MEString& i_FileName_ro)
  {
    return renderEngine_o.getCubeMapRenderer_po()->createCubeMap_b(i_FileName_ro);
  }

  void RenderInterface::BowlViewModifyHeight_v(float32_t i_X_f32, float32_t i_Z_f32, float32_t i_Height_f32, float32_t i_Radius_f32)
  {
    renderEngine_o.getViewManager_po()->modifyHeight_v(i_X_f32, i_Z_f32, i_Height_f32, i_Radius_f32);
  }

  void RenderInterface::setAtID_v(uint32_t i_ID_u32, void* i_Object_pv, uint8_t i_Type_u8)
  {
    if ((i_ID_u32 + 1U) > (c_MaxLutSize_u32))
    {
      // not enough space
      Assert(false);
    }
    else
    {
      // Check if id is already used
      Assert(objectLut_apv[i_ID_u32] == NULL);

      // Set object and type
      objectLut_apv[i_ID_u32] = i_Object_pv;
      typeLut_apu8[i_ID_u32]  = i_Type_u8;
    }
  }

  void* RenderInterface::getAtID_pv(uint32_t i_ID_u32, uint8_t i_Type_e)const
  {
    void* v_Object_pv = NULL;

    if (i_ID_u32 < c_MaxLutSize_u32)
    {
      // Check if object is valid
      Assert(objectLut_apv[i_ID_u32] != NULL);

      // Check if type is correct
      Assert(typeLut_apu8[i_ID_u32] == i_Type_e);

      if (objectLut_apv[i_ID_u32] != NULL)
      {
        v_Object_pv = objectLut_apv[i_ID_u32];
      }
    }

    return v_Object_pv;
  }

  void* RenderInterface::clearID_pv(uint32_t i_ID_u32, uint8_t i_Type_e)
  {
    void* v_Object_pv = NULL;

    if ((i_ID_u32 < c_MaxLutSize_u32) && 
        (i_ID_u32 != c_InvalidGUID_u32))
    {
      // Check if object is valid
      Assert(objectLut_apv[i_ID_u32] != NULL);

      // Check if type is correct
      Assert(typeLut_apu8[i_ID_u32] == i_Type_e);

      // Save the pointer
      v_Object_pv = objectLut_apv[i_ID_u32];

      // Null lut content
      objectLut_apv[i_ID_u32] = NULL;

      // Reset type
      typeLut_apu8[i_ID_u32]  = e_OtInvalid;

      // Release the unique id
      guidGenerator_o.releaseID_v(i_ID_u32);

    }

    // Return pointer to object
    return v_Object_pv;
  }

} // namespace me3d
