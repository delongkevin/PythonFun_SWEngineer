//--------------------------------------------------------------------------
/// @file VDGData.h
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

#ifndef CONTAINER_VDG_DATA_H
#define CONTAINER_VDG_DATA_H

#include <mecl/meclcfg.h>
#include <mecl/core/Rectangle.h>

#include "container/DataContainer.h"

#include "variants/Components.h"
#include "variants/Assets.h"

namespace container
{

class AdapterCamera
{
public:

  AdapterCamera();
  virtual ~AdapterCamera();

  void updateCamera_v(uint32_t i_CameraGUID_u32);

  mecl::Camera_t& accessCamera_rt();

  void setZoomValue_v(float32_t i_ZoomValue_f32);
  void setZoomReference_v(mecl::Point2D_t i_ZoomReference_o);

private:

  bool_t updateRealCameraRadialLens_b     (const variants::CameraRadialLens*          i_RealCameraRadialLens_po     );
  bool_t updateVirtualCameraRadialLens_b  (const variants::VirtualCameraRadialLens*   i_VirtualCameraRadialLens_po  );
  bool_t updateVirtualCameraCylinderLens_b(const variants::VirtualCameraCylinderLens* i_VirtualCameraCylinderLens_po);
  bool_t updateVirtualCameraStretchLens_b (const variants::VirtualCameraStretchLens*  i_VirtualCameraStretchLens_po );
  bool_t updateVirtualCameraNoLens_b      (const variants::VirtualCameraNoLens*       i_VirtualCameraNoLens_po      );

  bool_t updateImager_b      (const variants::PinholeComponent*             i_PinholeComponent_po     );
  bool_t updateSensor_b      (const variants::PinholeComponent*             i_PinholeComponent_po     );
  bool_t updateRadialLens_b  (const variants::LensRadialComponent*          i_LensRadialComponent_po  );
  bool_t updateCylinderLens_b(const variants::LensCylinderComponent*        i_LensCylinderComponent_po);
  bool_t updateStretchLens_b (const variants::LensRadialComponent*          i_LensRadialComponent_po,
                              const variants::LensStretchVerticalComponent* i_LensStretchComponent_po );

  mecl::Pinhole_t                pinhole_o;
  mecl::LensRadial_t             lensRadial_o;
  mecl::LensCylinder_t           lensCylinder_o;
  mecl::LensStretchVertical_t    lensStretchVertical_o;
  mecl::Sensor_t                 sensor_o;
  mecl::Camera_t                 camera_o;

  mecl::Point2D_t                zoomReference_o;

  float32_t                      zoomValue_f32;
};

class VDGData : public DataContainer
{
public:
  VDGData();
  virtual ~VDGData();

  typedef variants::SingleViews_t SingleViewList_t[variants::e_SingleViewLinksCount];

  uint32_t getScreenWidth_u32();
  uint32_t getScreenHeight_u32();

  uint32_t getAlphaBufferWidth_u32();
  uint32_t getAlphaBufferHeight_u32();

  variants::Camera_t getRealCameraId_t(variants::SingleViews_t i_SingleViewId_t);

  mecl::Camera_t& accessVirtualCamera_rt(variants::SingleViews_t i_SingleViewId_t);

  mecl::core::Rectangle<uint16_t> getPixelArea_o(variants::SingleViews_t i_SingleViewId_t);

  const variants::StitchParamsComponent* getStitchComponent_o(variants::ViewId_t i_ViewId_t,variants::StitchParamsLinks_t i_StitchParamsLink_t);

  mecl::SingleView_t& accessSingleView_rt(const variants::SingleViewComponent* i_SingleViewComponent_po, mecl::Camera_t& i_RealCamera_rt);

  bool_t getSingleViewList_b(variants::ViewId_t i_ViewId_t, SingleViewList_t& o_SingleViewList_rt);

  void setZoomValue_v(float32_t i_ZoomValue_f32);

  void setViewId_v(variants::ViewId_t i_ViewId_t);

private:

  const variants::CombinedViewComponent* getCombinedViewComponent_po() const;
  const variants::CombinedViewComponent* getCombinedViewComponent_po(variants::ViewId_t i_ViewId_t) const;

  const variants::SingleViewComponent* getSingleViewComponent_po(uint32_t i_SingleViewGUID_u32) const;
  const variants::SingleViewComponent* getSingleViewComponent_po(variants::SingleViews_t i_SingleViewId_t) const;
  const variants::SingleViewComponent* getSingleViewComponent_po(variants::SingleViewLinks_t i_SingleViewLink_t) const;

  const variants::PixelAreaComponent* getPixelAreaComponent_po(const variants::SingleViewComponent* i_SingleViewComponent_po) const;

  bool_t updateVirtualSensorArea_b(const variants::SingleViewComponent* i_SingleViewComponent_po, mecl::Camera_t& b_VirtualCamera_rt) const;

  bool_t updateSingleViewList_b(const variants::CombinedViewComponent* i_CombinedViewComponent_po, SingleViewList_t& o_SingleViewList_rt) const;

  static const uint32_t screenWidth_u32       = 1280U;
  static const uint32_t screenHeight_u32      =  720U;

  static const uint32_t alphaBufferWidth_u32  = 2048U;
  static const uint32_t alphaBufferHeight_u32 =  720U;

  AdapterCamera adapterCameraVirtual_ao[variants::e_SingleViewsCount];

  mecl::SingleView_t singleView_o;

  float32_t zoomValue_f32;

  variants::ViewId_t viewId_t;
};

} // namespace container

#endif // CONTAINER_VDG_DATA_H
