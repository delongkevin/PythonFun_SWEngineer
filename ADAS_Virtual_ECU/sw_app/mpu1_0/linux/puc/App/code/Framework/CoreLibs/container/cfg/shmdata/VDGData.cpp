//--------------------------------------------------------------------------
/// @file VDGData.cpp
/// @brief Contains the view descriptions
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Hagen Marczok (Hagen.Marczok@magna.com)
///
//  --------------------------------------------------------------------------

#include "VDGData.h"

#include <variants/VariantHelper.h>


namespace container
{

VDGData::VDGData()
  : DataContainer()
  , singleView_o()
  , zoomValue_f32(1.0F)
  , viewId_t(variants::e_ViewIdInvalid)
{
}

VDGData::~VDGData()
{
}

uint32_t VDGData::getScreenWidth_u32()
{
  return screenWidth_u32;
}

uint32_t VDGData::getScreenHeight_u32()
{
  return screenHeight_u32;
}

uint32_t VDGData::getAlphaBufferWidth_u32()
{
  return alphaBufferWidth_u32;
}

uint32_t VDGData::getAlphaBufferHeight_u32()
{
  return alphaBufferHeight_u32;
}

variants::Camera_t VDGData::getRealCameraId_t(variants::SingleViews_t i_SingleViewId_t)
{
  variants::Camera_t v_RealCameraId_t = variants::e_CameraInvalid;

  const variants::SingleViewComponent* c_SingleViewComponent_po = getSingleViewComponent_po(i_SingleViewId_t);

  if (NULL != c_SingleViewComponent_po)
  {
    const uint32_t c_RealCameraGUID_u32 = c_SingleViewComponent_po->getRealCameraLink_u32();

    if (variants::c_InvalidGUID_u32 != c_RealCameraGUID_u32)
    {
      if (c_RealCameraGUID_u32 == variants::c_CameraFrontVariant0_u32) {v_RealCameraId_t = variants::e_CameraFront;}
      if (c_RealCameraGUID_u32 == variants::c_CameraLeftVariant0_u32 ) {v_RealCameraId_t = variants::e_CameraLeft ;}
      if (c_RealCameraGUID_u32 == variants::c_CameraRearVariant0_u32 ) {v_RealCameraId_t = variants::e_CameraRear ;}
      if (c_RealCameraGUID_u32 == variants::c_CameraRightVariant0_u32) {v_RealCameraId_t = variants::e_CameraRight;}
      if (c_RealCameraGUID_u32 == variants::c_CameraChmslVariant0_u32) {v_RealCameraId_t = variants::e_CameraChmsl;}
      if (c_RealCameraGUID_u32 == variants::c_CameraAuxVariant0_u32  ) {v_RealCameraId_t = variants::e_CameraChmsl;} // TODO: remove AUX camera from system
    }
  }

  return v_RealCameraId_t;
}

mecl::Camera_t& VDGData::accessVirtualCamera_rt(variants::SingleViews_t i_SingleViewId_t)
{
  uint32_t v_VirtualCameraGUID_u32 = variants::c_InvalidGUID_u32;

  const variants::SingleViewComponent* c_SingleViewComponent_po = getSingleViewComponent_po(i_SingleViewId_t);

  if (NULL != c_SingleViewComponent_po)
  {
    v_VirtualCameraGUID_u32 = c_SingleViewComponent_po->getVirtualCameraLink_u32();

    // set values for no zoom
    float32_t v_ZoomValue_f32 = 1.0F;
    mecl::Point2D_t v_ZoomReference_o;

    // update zoom if virtual camera is part of current combined view
    const variants::CombinedViewComponent* c_CombinedViewComponent_po = getCombinedViewComponent_po();

    if (NULL != c_CombinedViewComponent_po)
    {
      // for all single views of a combined view
      for (uint32_t v_SingleViewIndex_u32 = 0U; v_SingleViewIndex_u32 < c_CombinedViewComponent_po->getSingleViewsCount_u32(); ++v_SingleViewIndex_u32)
      {
        if (c_SingleViewComponent_po == getSingleViewComponent_po(static_cast<variants::SingleViewLinks_t>(v_SingleViewIndex_u32)))
        {
          if (variants::e_ZoomableYes == c_SingleViewComponent_po->getZoomable_e())
          {
            v_ZoomValue_f32 = zoomValue_f32;

            v_ZoomReference_o(0) = c_SingleViewComponent_po->getZoomReferencePoint_rs().pixelPosX_f32;
            v_ZoomReference_o(1) = c_SingleViewComponent_po->getZoomReferencePoint_rs().pixelPosY_f32;
          }
        }
      }
    }

    const variants::SingleViews_t c_SingleViewId_t = c_SingleViewComponent_po->getEnumId_e();

    // update zoom parameter for virtual camera
    adapterCameraVirtual_ao[i_SingleViewId_t].setZoomValue_v(v_ZoomValue_f32);
    adapterCameraVirtual_ao[i_SingleViewId_t].setZoomReference_v(v_ZoomReference_o);
  }

  adapterCameraVirtual_ao[i_SingleViewId_t].updateCamera_v(v_VirtualCameraGUID_u32);

  updateVirtualSensorArea_b(c_SingleViewComponent_po, adapterCameraVirtual_ao[i_SingleViewId_t].accessCamera_rt());

  return adapterCameraVirtual_ao[i_SingleViewId_t].accessCamera_rt();
}

mecl::core::Rectangle<uint16_t> VDGData::getPixelArea_o(variants::SingleViews_t i_SingleViewId_t)
{
  mecl::core::Rectangle<uint16_t> v_PixelArea_o;

  const variants::SingleViewComponent* c_SingleViewComponent_po = c_SingleViewComponent_po = getSingleViewComponent_po(i_SingleViewId_t);

  if (NULL != c_SingleViewComponent_po)
  {
    const variants::PixelAreaComponent* c_PixelAreaComponent_po = getPixelAreaComponent_po(c_SingleViewComponent_po);

    if (NULL != c_PixelAreaComponent_po)
    {
      v_PixelArea_o.tLX_x = static_cast<uint16_t>(c_PixelAreaComponent_po->getTopLeft_rs().pixelPosX_s32);
      v_PixelArea_o.tLY_x = static_cast<uint16_t>(c_PixelAreaComponent_po->getTopLeft_rs().pixelPosY_s32);

      v_PixelArea_o.bRX_x = static_cast<uint16_t>(c_PixelAreaComponent_po->getBottomRight_rs().pixelPosX_s32);
      v_PixelArea_o.bRY_x = static_cast<uint16_t>(c_PixelAreaComponent_po->getBottomRight_rs().pixelPosY_s32);
    }
  }

  return v_PixelArea_o;
}

const variants::StitchParamsComponent* VDGData::getStitchComponent_o(variants::ViewId_t i_ViewId_t,variants::StitchParamsLinks_t i_StitchParamsLink_t)
{
  const variants::StitchParamsComponent* c_StitchParamsComponent_po = NULL;
  const variants::CombinedViewComponent* v_CombinedViewComponent_po =  getCombinedViewComponent_po(i_ViewId_t);
  
  if (NULL != v_CombinedViewComponent_po)
  {
    if(variants::e_StitchParamsLinksCount > i_StitchParamsLink_t)
    {
      const uint32_t c_StitchParamsGUID_u32 = v_CombinedViewComponent_po->getStitchParams_ps()[i_StitchParamsLink_t].stitchParamsLink_u32; // PRQA S 3706

      if (variants::c_InvalidGUID_u32 != c_StitchParamsGUID_u32)
      {
        const variants::StitchParams* c_StitchParams_po = variants::StitchParams::get_po(c_StitchParamsGUID_u32);
        if (NULL != c_StitchParams_po)
        {
          c_StitchParamsComponent_po = c_StitchParams_po->getStitchParamsComponent_po();
        }
      }
    }
  }

  return c_StitchParamsComponent_po;
}

mecl::SingleView_t& VDGData::accessSingleView_rt(const variants::SingleViewComponent* i_SingleViewComponent_po, mecl::Camera_t& i_RealCamera_rt)
{
  if (NULL != i_SingleViewComponent_po)
  {
    singleView_o.setRealCam_v(i_RealCamera_rt);
    singleView_o.setRealCorrectionLvl_v(0.0F);

    // set values for no zoom
    float32_t v_ZoomValue_f32 = 1.0F;
    mecl::Point2D_t v_ZoomReference_o;

    if (variants::e_ZoomableYes == i_SingleViewComponent_po->getZoomable_e())
    {
      v_ZoomValue_f32 = zoomValue_f32;

      v_ZoomReference_o(0) = i_SingleViewComponent_po->getZoomReferencePoint_rs().pixelPosX_f32;
      v_ZoomReference_o(1) = i_SingleViewComponent_po->getZoomReferencePoint_rs().pixelPosY_f32;
    }

    const variants::SingleViews_t c_SingleViewId_t = i_SingleViewComponent_po->getEnumId_e();

    // update zoom parameter for virtual camera
    adapterCameraVirtual_ao[c_SingleViewId_t].setZoomValue_v(v_ZoomValue_f32);
    adapterCameraVirtual_ao[c_SingleViewId_t].setZoomReference_v(v_ZoomReference_o);
    adapterCameraVirtual_ao[c_SingleViewId_t].updateCamera_v(i_SingleViewComponent_po->getVirtualCameraLink_u32());

    mecl::Camera_t& v_VirtualCamera_rt = adapterCameraVirtual_ao[c_SingleViewId_t].accessCamera_rt();

    updateVirtualSensorArea_b(i_SingleViewComponent_po, v_VirtualCamera_rt);

    singleView_o.setSyntCam_v(v_VirtualCamera_rt);
    singleView_o.setSyntheticCorrectionLvl_v(0.0F);
  }

  return singleView_o;
}

bool_t VDGData::getSingleViewList_b(variants::ViewId_t i_ViewId_t, SingleViewList_t& o_SingleViewList_rt)
{
  bool_t v_Success = false;

  for (uint32_t v_ListIndex_u32 = 0U; v_ListIndex_u32 < variants::e_SingleViewLinksCount; ++v_ListIndex_u32)
  {
    o_SingleViewList_rt[v_ListIndex_u32] = variants::e_SingleViewsInvalid;
  }

  const variants::CombinedViewComponent* c_CombinedViewComponent_po = getCombinedViewComponent_po(i_ViewId_t);

  if (NULL != c_CombinedViewComponent_po)
  {
    v_Success = updateSingleViewList_b(c_CombinedViewComponent_po, o_SingleViewList_rt);
  }

  return v_Success;
}

void VDGData::setZoomValue_v(float32_t i_ZoomValue_f32)
{
  zoomValue_f32 = i_ZoomValue_f32;
}

void VDGData::setViewId_v(variants::ViewId_t i_ViewId_t)
{
  viewId_t = i_ViewId_t;
}

const variants::CombinedViewComponent* VDGData::getCombinedViewComponent_po() const
{
  return getCombinedViewComponent_po(viewId_t);
}

const variants::CombinedViewComponent* VDGData::getCombinedViewComponent_po(variants::ViewId_t i_ViewId_t) const
{
  const variants::CombinedViewComponent* c_CombinedViewComponent_po = NULL;

  if (variants::e_ViewIdCount > i_ViewId_t)
  {
    const variants::ViewsMap* c_ViewsMap_po = variants::ViewsMap::get_po(variants::c_ViewsMap_u32);

    if (NULL != c_ViewsMap_po)
    {
      const uint32_t c_CombinedViewGUID_u32 = c_ViewsMap_po->getViewsMapComponent_po()->getViewsMap_ps()[i_ViewId_t].combinedViewLink_u32;

      if (variants::c_InvalidGUID_u32 != c_CombinedViewGUID_u32)
      {
        const variants::CombinedView* c_CombinedView_po = variants::CombinedView::get_po(c_CombinedViewGUID_u32);

        if (NULL != c_CombinedView_po)
        {
          c_CombinedViewComponent_po = c_CombinedView_po->getCombinedViewComponent_po();
        }
      }
    }
  }

  return c_CombinedViewComponent_po;
}

const variants::SingleViewComponent* VDGData::getSingleViewComponent_po(uint32_t i_SingleViewGUID_u32) const
{
  const variants::SingleViewComponent* c_SingleViewComponent_po = NULL;

  if (variants::c_InvalidGUID_u32 != i_SingleViewGUID_u32)
  {
    const variants::SingleView* c_SingleView_po = variants::SingleView::get_po(i_SingleViewGUID_u32);

    if (NULL != c_SingleView_po)
    {
      c_SingleViewComponent_po = c_SingleView_po->getSingleViewComponent_po();
    }
  }

  return c_SingleViewComponent_po;
}

const variants::SingleViewComponent* VDGData::getSingleViewComponent_po(variants::SingleViews_t i_SingleViewId_t) const
{
  const variants::SingleViewComponent* c_SingleViewComponent_po = NULL;

  if (variants::e_SingleViewsCount > i_SingleViewId_t)
  {
    const variants::SingleViewsMap* c_SingleViewsMap_po = variants::SingleViewsMap::get_po(variants::c_SingleViewsMap_u32);

    if (NULL != c_SingleViewsMap_po)
    {
      const uint32_t c_SingleViewGUID_u32 = c_SingleViewsMap_po->getSingleViewsMapComponent_po()->getSingleViewsMap_ps()[i_SingleViewId_t].singleViewLink_u32;

      if (variants::c_InvalidGUID_u32 != c_SingleViewGUID_u32)
      {
        c_SingleViewComponent_po = getSingleViewComponent_po(c_SingleViewGUID_u32);
      }
    }
  }

  return c_SingleViewComponent_po;
}

const variants::SingleViewComponent* VDGData::getSingleViewComponent_po(variants::SingleViewLinks_t i_SingleViewLink_t) const
{
  const variants::SingleViewComponent* c_SingleViewComponent_po = NULL;

  if (variants::e_SingleViewLinksCount > i_SingleViewLink_t)
  {
    const variants::CombinedViewComponent* c_CombinedViewComponent_po = getCombinedViewComponent_po();

    if (NULL != c_CombinedViewComponent_po)
    {
      const uint32_t c_SingleViewGUID_u32 = c_CombinedViewComponent_po->getSingleViews_ps()[i_SingleViewLink_t].singleViewsLink_u32;

      if (variants::c_InvalidGUID_u32 != c_SingleViewGUID_u32)
      {
        c_SingleViewComponent_po = getSingleViewComponent_po(c_SingleViewGUID_u32);
      }
    }
  }

  return c_SingleViewComponent_po;
}

const variants::PixelAreaComponent* VDGData::getPixelAreaComponent_po(const variants::SingleViewComponent* i_SingleViewComponent_po) const
{
  const variants::PixelAreaComponent* c_PixelAreaComponent_po = NULL;

  if (NULL != i_SingleViewComponent_po)
  {
    const uint32_t c_PixelAreaGUID_u32 = i_SingleViewComponent_po->getPixelAreaLink_u32();

    if (variants::c_InvalidGUID_u32 != c_PixelAreaGUID_u32)
    {
      const variants::PixelArea* c_PixelArea_po = variants::PixelArea::get_po(c_PixelAreaGUID_u32);

      if (NULL != c_PixelArea_po)
      {
        c_PixelAreaComponent_po = c_PixelArea_po->getPixelAreaComponent_po();
      }
    }
  }

  return c_PixelAreaComponent_po;
}

bool_t VDGData::updateVirtualSensorArea_b(const variants::SingleViewComponent* i_SingleViewComponent_po, mecl::Camera_t& b_VirtualCamera_rt) const
{
  bool_t v_Success = false;

  if (NULL != i_SingleViewComponent_po)
  {
    mecl::Point2D_t v_UpperLeft_o ( 10000.0F,  10000.0F);
    mecl::Point2D_t v_LowerRight_o(-10000.0F, -10000.0F);

    const uint32_t c_VirtualCameraGUID_u32 = i_SingleViewComponent_po->getVirtualCameraLink_u32();

    if (variants::c_InvalidGUID_u32 != c_VirtualCameraGUID_u32)
    {
      const variants::CombinedViewComponent* c_CombinedViewComponent_po = getCombinedViewComponent_po();

      if (NULL != c_CombinedViewComponent_po)
      {
        // for all single views of a combined view
        for (uint32_t v_SingleViewIndex_u32 = 0U; v_SingleViewIndex_u32 < c_CombinedViewComponent_po->getSingleViewsCount_u32(); ++v_SingleViewIndex_u32)
        {
          const variants::SingleViewComponent* c_SingleViewComponent_po = getSingleViewComponent_po(static_cast<variants::SingleViewLinks_t>(v_SingleViewIndex_u32));

          if (NULL != c_SingleViewComponent_po)
          {
            if (c_VirtualCameraGUID_u32 == c_SingleViewComponent_po->getVirtualCameraLink_u32())
            {
              const variants::PixelAreaComponent* c_PixelAreaComponent_po = getPixelAreaComponent_po(c_SingleViewComponent_po);

              if (NULL != c_PixelAreaComponent_po)
              {
                v_UpperLeft_o(0)  = mecl::math::min_x<float32_t>(v_UpperLeft_o(0), static_cast<float32_t>(c_PixelAreaComponent_po->getTopLeft_rs().pixelPosX_s32));
                v_UpperLeft_o(1)  = mecl::math::min_x<float32_t>(v_UpperLeft_o(1), static_cast<float32_t>(c_PixelAreaComponent_po->getTopLeft_rs().pixelPosY_s32));

                v_LowerRight_o(0) = mecl::math::max_x<float32_t>(v_LowerRight_o(0), static_cast<float32_t>(c_PixelAreaComponent_po->getBottomRight_rs().pixelPosX_s32));
                v_LowerRight_o(1) = mecl::math::max_x<float32_t>(v_LowerRight_o(1), static_cast<float32_t>(c_PixelAreaComponent_po->getBottomRight_rs().pixelPosY_s32));

                v_Success = true;
              }
            }
          }
        }

        if (true == v_Success)
        {
          mecl::Sensor_t* v_Sensor_px = dynamic_cast<mecl::Sensor_t*>(&b_VirtualCamera_rt.getSensor_rx());

          v_Sensor_px->setUpperLeft_v (v_UpperLeft_o , false);
          v_Sensor_px->setLowerRight_v(v_LowerRight_o, false);
        }
      }
    }
  }

  return v_Success;
}

bool_t VDGData::updateSingleViewList_b(const variants::CombinedViewComponent* i_CombinedViewComponent_po, SingleViewList_t& o_SingleViewList_rt) const
{
  bool_t v_Success = false;

  // for all single views of a combined view
  for (uint32_t v_SingleViewIndex_u32 = 0U; v_SingleViewIndex_u32 < i_CombinedViewComponent_po->getSingleViewsCount_u32(); ++v_SingleViewIndex_u32)
  {
    const variants::SingleViewLinks_t c_SingleViewLink_t = static_cast<variants::SingleViewLinks_t>(v_SingleViewIndex_u32);

    if (variants::e_SingleViewLinksCount > c_SingleViewLink_t)
    {
      const variants::SingleViewComponent* c_SingleViewComponent_po = getSingleViewComponent_po(c_SingleViewLink_t);

      if (NULL != c_SingleViewComponent_po)
      {
        o_SingleViewList_rt[v_SingleViewIndex_u32] = c_SingleViewComponent_po->getEnumId_e();
        v_Success = true;
      }
      else
      {
        v_Success = false;
      }
    }
  }

  return v_Success;
}


AdapterCamera::AdapterCamera()
  : pinhole_o()
  , lensRadial_o()
  , lensCylinder_o()
  , lensStretchVertical_o()
  , sensor_o()
  , camera_o(pinhole_o, sensor_o)
  , zoomReference_o()
  , zoomValue_f32(1.0F)
{
}

AdapterCamera::~AdapterCamera()
{
}

void AdapterCamera::updateCamera_v(uint32_t i_CameraGUID_u32)
{
  if (variants::c_InvalidGUID_u32 != i_CameraGUID_u32)
  {
    updateRealCameraRadialLens_b     (variants::CameraRadialLens::get_po(i_CameraGUID_u32));

    updateVirtualCameraNoLens_b      (variants::VirtualCameraNoLens::get_po(i_CameraGUID_u32));
    updateVirtualCameraRadialLens_b  (variants::VirtualCameraRadialLens::get_po(i_CameraGUID_u32));
    updateVirtualCameraCylinderLens_b(variants::VirtualCameraCylinderLens::get_po(i_CameraGUID_u32));
    updateVirtualCameraStretchLens_b (variants::VirtualCameraStretchLens::get_po(i_CameraGUID_u32));
  }
}

mecl::Camera_t& AdapterCamera::accessCamera_rt()
{
  return camera_o;
}

void AdapterCamera::setZoomValue_v(float32_t i_ZoomValue_f32)
{
  zoomValue_f32 = i_ZoomValue_f32;
}

void AdapterCamera::setZoomReference_v(mecl::Point2D_t i_ZoomReference_o)
{
  zoomReference_o = i_ZoomReference_o;
}

bool_t AdapterCamera::updateRealCameraRadialLens_b(const variants::CameraRadialLens* i_RealCameraRadialLens_po)
{
  bool_t v_Success_b = true;

  if (NULL != i_RealCameraRadialLens_po)
  {
    const variants::PinholeComponent* c_RealPinholeComponent_po = i_RealCameraRadialLens_po->getPinholeComponent_po();

    v_Success_b = updateImager_b(c_RealPinholeComponent_po) && v_Success_b;
    v_Success_b = updateSensor_b(c_RealPinholeComponent_po) && v_Success_b;

    v_Success_b = updateRadialLens_b(i_RealCameraRadialLens_po->getLensRadialComponent_po()) && v_Success_b;
  }
  else
  {
    v_Success_b = false;
  }

  return v_Success_b;
}

bool_t AdapterCamera::updateVirtualCameraRadialLens_b(const variants::VirtualCameraRadialLens* i_VirtualCameraRadialLens_po)
{
  bool_t v_Success_b = true;

  if (NULL != i_VirtualCameraRadialLens_po)
  {
    const variants::PinholeComponent* c_VirtualPinholeComponent_po = i_VirtualCameraRadialLens_po->getPinholeComponent_po();

    v_Success_b = updateImager_b(c_VirtualPinholeComponent_po) && v_Success_b;
    v_Success_b = updateSensor_b(c_VirtualPinholeComponent_po) && v_Success_b;

    v_Success_b = updateRadialLens_b(i_VirtualCameraRadialLens_po->getLensRadialComponent_po()) && v_Success_b;
  }
  else
  {
    v_Success_b = false;
  }

  return v_Success_b;
}

bool_t AdapterCamera::updateVirtualCameraCylinderLens_b(const variants::VirtualCameraCylinderLens* i_VirtualCameraCylinderLens_po)
{
  bool_t v_Success_b = true;

  if (NULL != i_VirtualCameraCylinderLens_po)
  {
    const variants::PinholeComponent* c_VirtualPinholeComponent_po = i_VirtualCameraCylinderLens_po->getPinholeComponent_po();

    v_Success_b = updateImager_b(c_VirtualPinholeComponent_po) && v_Success_b;
    v_Success_b = updateSensor_b(c_VirtualPinholeComponent_po) && v_Success_b;

    v_Success_b = updateCylinderLens_b(i_VirtualCameraCylinderLens_po->getLensCylinderComponent_po()) && v_Success_b;
  }
  else
  {
    v_Success_b = false;
  }

  return v_Success_b;
}

bool_t AdapterCamera::updateVirtualCameraStretchLens_b(const variants::VirtualCameraStretchLens* i_VirtualCameraStretchLens_po)
{
  bool_t v_Success_b = true;

  if (NULL != i_VirtualCameraStretchLens_po)
  {
    const variants::PinholeComponent* c_VirtualPinholeComponent_po = i_VirtualCameraStretchLens_po->getPinholeComponent_po();

    v_Success_b = updateImager_b(c_VirtualPinholeComponent_po) && v_Success_b;
    v_Success_b = updateSensor_b(c_VirtualPinholeComponent_po) && v_Success_b;

    v_Success_b = updateStretchLens_b(i_VirtualCameraStretchLens_po->getLensRadialComponent_po(),
                                      i_VirtualCameraStretchLens_po->getLensStretchVerticalComponent_po()) && v_Success_b;
  }
  else
  {
    v_Success_b = false;
  }

  return v_Success_b;
}

bool_t AdapterCamera::updateVirtualCameraNoLens_b(const variants::VirtualCameraNoLens* i_VirtualCameraNoLens_po)
{
  bool_t v_Success_b = true;

  if (NULL != i_VirtualCameraNoLens_po)
  {
    const variants::PinholeComponent* c_VirtualPinholeComponent_po = i_VirtualCameraNoLens_po->getPinholeComponent_po();

    v_Success_b = updateImager_b(c_VirtualPinholeComponent_po) && v_Success_b;
    v_Success_b = updateSensor_b(c_VirtualPinholeComponent_po) && v_Success_b;

    camera_o.setNoLens_v();
  }
  else
  {
    v_Success_b = false;
  }

  return v_Success_b;
}

bool_t AdapterCamera::updateImager_b(const variants::PinholeComponent* i_PinholeComponent_po)
{
  bool_t v_Success_b = false;

  if (NULL != i_PinholeComponent_po)
  {
    mecl::Pinhole_t::Config_s v_PinholeCfg_s;

    v_PinholeCfg_s.extrinsic_s.eulerAngles_s.pitch_x = mecl::math::toRadians_x(i_PinholeComponent_po->getExtrinsic_rs().pitch_f32);
    v_PinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x   = mecl::math::toRadians_x(i_PinholeComponent_po->getExtrinsic_rs().yaw_f32  );
    v_PinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x  = mecl::math::toRadians_x(i_PinholeComponent_po->getExtrinsic_rs().roll_f32 );

    v_PinholeCfg_s.extrinsic_s.pos_x.cVal_ax[0]      = i_PinholeComponent_po->getExtrinsic_rs().posX_f32;
    v_PinholeCfg_s.extrinsic_s.pos_x.cVal_ax[1]      = i_PinholeComponent_po->getExtrinsic_rs().posY_f32;
    v_PinholeCfg_s.extrinsic_s.pos_x.cVal_ax[2]      = i_PinholeComponent_po->getExtrinsic_rs().posZ_f32;

    v_PinholeCfg_s.extrinsic_s.preRoll_e             = static_cast<mecl::model::PreRoll_e     >(i_PinholeComponent_po->getExtrinsic_rs().preRoll_e     );
    v_PinholeCfg_s.extrinsic_s.rotationType_e        = static_cast<mecl::model::RotationType_e>(i_PinholeComponent_po->getExtrinsic_rs().rotationType_e);

    v_PinholeCfg_s.intrinsic_s.foclX_x               = i_PinholeComponent_po->getIntrinsic_rs().focalLengthX_f32;
    v_PinholeCfg_s.intrinsic_s.foclY_x               = i_PinholeComponent_po->getIntrinsic_rs().focalLengthY_f32;

    v_PinholeCfg_s.intrinsic_s.pppCfg_x.cVal_ax[0]   = 0.0F;
    v_PinholeCfg_s.intrinsic_s.pppCfg_x.cVal_ax[1]   = 0.0F;

    pinhole_o.updateConfig_v(v_PinholeCfg_s);

    camera_o.setImager_v(pinhole_o);

    v_Success_b = true;
  }

  return v_Success_b;
}

bool_t AdapterCamera::updateSensor_b(const variants::PinholeComponent* i_PinholeComponent_po)
{
  bool_t v_Success_b = false;

  if (NULL != i_PinholeComponent_po)
  {
    float32_t v_PrincipalPointX_f32        = zoomValue_f32 * (i_PinholeComponent_po->getIntrinsic_rs().principalPointX_f32 - zoomReference_o(0)) + zoomReference_o(0);
    float32_t v_PrincipalPointY_f32        = zoomValue_f32 * (i_PinholeComponent_po->getIntrinsic_rs().principalPointY_f32 - zoomReference_o(1)) + zoomReference_o(1);

    mecl::Sensor_t::Config_s v_SensorCfg_s;

    v_SensorCfg_s.pppCfg_x.cVal_ax[0]      = (0.0F > v_PrincipalPointX_f32) ? 0.0F : v_PrincipalPointX_f32;
    v_SensorCfg_s.pppCfg_x.cVal_ax[1]      = (0.0F > v_PrincipalPointY_f32) ? 0.0F : v_PrincipalPointY_f32;

    v_SensorCfg_s.pszCfg_x.cVal_ax[0]      = i_PinholeComponent_po->getIntrinsic_rs().pixelSizeX_f32 / zoomValue_f32;
    v_SensorCfg_s.pszCfg_x.cVal_ax[1]      = i_PinholeComponent_po->getIntrinsic_rs().pixelSizeY_f32 / zoomValue_f32;

    v_SensorCfg_s.imageOriginPositionCfg_e = static_cast<mecl::model::ImageOriginPosition_e>(i_PinholeComponent_po->getIntrinsic_rs().imageOrigin_e);

    v_SensorCfg_s.pos1Cfg_x.cVal_ax[0]     = i_PinholeComponent_po->getIntrinsic_rs().sensorAreaTopLeftX_f32;
    v_SensorCfg_s.pos1Cfg_x.cVal_ax[1]     = i_PinholeComponent_po->getIntrinsic_rs().sensorAreaTopLeftY_f32;

    v_SensorCfg_s.pos2Cfg_x.cVal_ax[0]     = i_PinholeComponent_po->getIntrinsic_rs().sensorAreaBottomRightX_f32;
    v_SensorCfg_s.pos2Cfg_x.cVal_ax[1]     = i_PinholeComponent_po->getIntrinsic_rs().sensorAreaBottomRightY_f32;

    sensor_o.updateConfig_v(v_SensorCfg_s);

    camera_o.setSensor_v(sensor_o);

    v_Success_b = true;
  }

  return v_Success_b;
}

bool_t AdapterCamera::updateRadialLens_b(const variants::LensRadialComponent* i_LensRadialComponent_po)
{
  bool_t v_Success_b = false;

  if (NULL != i_LensRadialComponent_po)
  {
    mecl::LensRadial_t::Config_s v_LensRadialCfg_s;

    v_LensRadialCfg_s.world2image_x[variants::e_Coeff0] = i_LensRadialComponent_po->getWorld2Image_ps()[variants::e_Coeff0].coeff_f32;
    v_LensRadialCfg_s.world2image_x[variants::e_Coeff1] = i_LensRadialComponent_po->getWorld2Image_ps()[variants::e_Coeff1].coeff_f32;
    v_LensRadialCfg_s.world2image_x[variants::e_Coeff2] = i_LensRadialComponent_po->getWorld2Image_ps()[variants::e_Coeff2].coeff_f32;
    v_LensRadialCfg_s.world2image_x[variants::e_Coeff3] = i_LensRadialComponent_po->getWorld2Image_ps()[variants::e_Coeff3].coeff_f32;
    v_LensRadialCfg_s.world2image_x[variants::e_Coeff4] = i_LensRadialComponent_po->getWorld2Image_ps()[variants::e_Coeff4].coeff_f32;
    v_LensRadialCfg_s.world2image_x[variants::e_Coeff5] = i_LensRadialComponent_po->getWorld2Image_ps()[variants::e_Coeff5].coeff_f32;

    v_LensRadialCfg_s.image2world_x[variants::e_Coeff0] = i_LensRadialComponent_po->getImage2World_ps()[variants::e_Coeff0].coeff_f32;
    v_LensRadialCfg_s.image2world_x[variants::e_Coeff1] = i_LensRadialComponent_po->getImage2World_ps()[variants::e_Coeff1].coeff_f32;
    v_LensRadialCfg_s.image2world_x[variants::e_Coeff2] = i_LensRadialComponent_po->getImage2World_ps()[variants::e_Coeff2].coeff_f32;
    v_LensRadialCfg_s.image2world_x[variants::e_Coeff3] = i_LensRadialComponent_po->getImage2World_ps()[variants::e_Coeff3].coeff_f32;
    v_LensRadialCfg_s.image2world_x[variants::e_Coeff4] = i_LensRadialComponent_po->getImage2World_ps()[variants::e_Coeff4].coeff_f32;
    v_LensRadialCfg_s.image2world_x[variants::e_Coeff5] = i_LensRadialComponent_po->getImage2World_ps()[variants::e_Coeff5].coeff_f32;

    if (mecl::math::equal_x(0.0F, i_LensRadialComponent_po->getElevationMax_f32()))
    {
      v_LensRadialCfg_s.elevationMaxCfg_x = 110.0F;
    }
    else
    {
      v_LensRadialCfg_s.elevationMaxCfg_x = i_LensRadialComponent_po->getElevationMax_f32();
    }

    lensRadial_o.updateConfig_v(v_LensRadialCfg_s);

    camera_o.setLens_v(lensRadial_o);

    v_Success_b = true;
  }
  else
  {
    camera_o.setNoLens_v();
  }

  return v_Success_b;
}

bool_t AdapterCamera::updateCylinderLens_b(const variants::LensCylinderComponent* i_LensCylinderComponent_po)
{
  bool_t v_Success_b = false;

  if (NULL != i_LensCylinderComponent_po)
  {
    mecl::LensCylinder_t::Config_s v_LensCylinderCfg_s;

    if (mecl::math::numeric_limits<float32_t>::epsilon_x() < i_LensCylinderComponent_po->getExcentricity_f32())
    {
      v_LensCylinderCfg_s.excentricity_x = i_LensCylinderComponent_po->getExcentricity_f32();
    }
    else
    {
      v_LensCylinderCfg_s.excentricity_x = 1.0F;
    }

    lensCylinder_o.updateConfig_v(v_LensCylinderCfg_s);

    camera_o.setLens_v(lensCylinder_o);

    v_Success_b = true;
  }
  else
  {
    camera_o.setNoLens_v();
  }

  return v_Success_b;
}

bool_t AdapterCamera::updateStretchLens_b(const variants::LensRadialComponent*          i_LensRadialComponent_po,
                                          const variants::LensStretchVerticalComponent* i_LensStretchComponent_po)
{
  bool_t v_Success_b = false;

  if (    (NULL != i_LensRadialComponent_po )
       && (NULL != i_LensStretchComponent_po))
  {
    mecl::LensStretchVertical_t::Config_s v_LensStretchCfg_s;

    v_LensStretchCfg_s.world2image_x[variants::e_Coeff0] = i_LensRadialComponent_po->getWorld2Image_ps()[variants::e_Coeff0].coeff_f32;
    v_LensStretchCfg_s.world2image_x[variants::e_Coeff1] = i_LensRadialComponent_po->getWorld2Image_ps()[variants::e_Coeff1].coeff_f32;
    v_LensStretchCfg_s.world2image_x[variants::e_Coeff2] = i_LensRadialComponent_po->getWorld2Image_ps()[variants::e_Coeff2].coeff_f32;
    v_LensStretchCfg_s.world2image_x[variants::e_Coeff3] = i_LensRadialComponent_po->getWorld2Image_ps()[variants::e_Coeff3].coeff_f32;
    v_LensStretchCfg_s.world2image_x[variants::e_Coeff4] = i_LensRadialComponent_po->getWorld2Image_ps()[variants::e_Coeff4].coeff_f32;
    v_LensStretchCfg_s.world2image_x[variants::e_Coeff5] = i_LensRadialComponent_po->getWorld2Image_ps()[variants::e_Coeff5].coeff_f32;

    v_LensStretchCfg_s.image2world_x[variants::e_Coeff0] = i_LensRadialComponent_po->getImage2World_ps()[variants::e_Coeff0].coeff_f32;
    v_LensStretchCfg_s.image2world_x[variants::e_Coeff1] = i_LensRadialComponent_po->getImage2World_ps()[variants::e_Coeff1].coeff_f32;
    v_LensStretchCfg_s.image2world_x[variants::e_Coeff2] = i_LensRadialComponent_po->getImage2World_ps()[variants::e_Coeff2].coeff_f32;
    v_LensStretchCfg_s.image2world_x[variants::e_Coeff3] = i_LensRadialComponent_po->getImage2World_ps()[variants::e_Coeff3].coeff_f32;
    v_LensStretchCfg_s.image2world_x[variants::e_Coeff4] = i_LensRadialComponent_po->getImage2World_ps()[variants::e_Coeff4].coeff_f32;
    v_LensStretchCfg_s.image2world_x[variants::e_Coeff5] = i_LensRadialComponent_po->getImage2World_ps()[variants::e_Coeff5].coeff_f32;

    if (mecl::math::equal_x(0.0F, i_LensRadialComponent_po->getElevationMax_f32()))
    {
      v_LensStretchCfg_s.elevationMaxCfg_x = 110.0F;
    }
    else
    {
      v_LensStretchCfg_s.elevationMaxCfg_x = i_LensRadialComponent_po->getElevationMax_f32();
    }

    v_LensStretchCfg_s.stretchFactor_x[variants::e_LensStretchCoeff0] = i_LensStretchComponent_po->getStretchFactor_ps()[variants::e_LensStretchCoeff0].coeff_f32;
    v_LensStretchCfg_s.stretchFactor_x[variants::e_LensStretchCoeff1] = i_LensStretchComponent_po->getStretchFactor_ps()[variants::e_LensStretchCoeff1].coeff_f32;
    v_LensStretchCfg_s.stretchFactor_x[variants::e_LensStretchCoeff2] = i_LensStretchComponent_po->getStretchFactor_ps()[variants::e_LensStretchCoeff2].coeff_f32;
    v_LensStretchCfg_s.stretchFactor_x[variants::e_LensStretchCoeff3] = i_LensStretchComponent_po->getStretchFactor_ps()[variants::e_LensStretchCoeff3].coeff_f32;
    v_LensStretchCfg_s.stretchFactor_x[variants::e_LensStretchCoeff4] = i_LensStretchComponent_po->getStretchFactor_ps()[variants::e_LensStretchCoeff4].coeff_f32;
    v_LensStretchCfg_s.stretchFactor_x[variants::e_LensStretchCoeff5] = i_LensStretchComponent_po->getStretchFactor_ps()[variants::e_LensStretchCoeff5].coeff_f32;
    v_LensStretchCfg_s.stretchFactor_x[variants::e_LensStretchCoeff6] = i_LensStretchComponent_po->getStretchFactor_ps()[variants::e_LensStretchCoeff6].coeff_f32;

    v_LensStretchCfg_s.stretchBase_x[variants::e_LensStretchCoeff0] = i_LensStretchComponent_po->getStretchBase_ps()[variants::e_LensStretchCoeff0].coeff_f32;
    v_LensStretchCfg_s.stretchBase_x[variants::e_LensStretchCoeff1] = i_LensStretchComponent_po->getStretchBase_ps()[variants::e_LensStretchCoeff1].coeff_f32;
    v_LensStretchCfg_s.stretchBase_x[variants::e_LensStretchCoeff2] = i_LensStretchComponent_po->getStretchBase_ps()[variants::e_LensStretchCoeff2].coeff_f32;
    v_LensStretchCfg_s.stretchBase_x[variants::e_LensStretchCoeff3] = i_LensStretchComponent_po->getStretchBase_ps()[variants::e_LensStretchCoeff3].coeff_f32;
    v_LensStretchCfg_s.stretchBase_x[variants::e_LensStretchCoeff4] = i_LensStretchComponent_po->getStretchBase_ps()[variants::e_LensStretchCoeff4].coeff_f32;
    v_LensStretchCfg_s.stretchBase_x[variants::e_LensStretchCoeff5] = i_LensStretchComponent_po->getStretchBase_ps()[variants::e_LensStretchCoeff5].coeff_f32;
    v_LensStretchCfg_s.stretchBase_x[variants::e_LensStretchCoeff6] = i_LensStretchComponent_po->getStretchBase_ps()[variants::e_LensStretchCoeff6].coeff_f32;

    lensStretchVertical_o.updateConfig_v(v_LensStretchCfg_s);

    camera_o.setLens_v(lensStretchVertical_o);

    v_Success_b = true;
  }
  else
  {
    camera_o.setNoLens_v();
  }

  return v_Success_b;
}

} // namespace container
