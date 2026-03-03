// ----------------------------------------------------------------------------
// --- written by X.Phan [28-JUN-2012]
// --- Copyright (c) Magna Vectrics (MEVC) 2012
// ----------------------------------------------------------------------------
// --- Camera.cpp - camera class methods + utility functions
// ----------------------------------------------------------------------------
#include "../inc/Camera.h"
#include "CrossplatformCommon.h"
#include "CrossplatformCommon.hpp"


#include "mecl/mecl.h"
#include "mecl/model/Model.h"

#ifdef _MSC_VER
#include "WinCameraCfg.h"
#include <fstream> 
#else
#include "../inc/CameraCfg.h"
#include <cstdlib>
#endif

#include "../inc/VarScales.h"
#include <exception>

#if _WIN32
	#include <windows.h> 
#endif

namespace cameranew {
	void Degree2Radian(float32_t &a)
	{
		((((static_cast<float32_t>((a)*(PI32))) / 180.0F)));
	}
}

Camera::~Camera()
{
}
float32_t Camera::getPitch(bool_t inDegrees) const
{
	float32_t ret1 = (static_cast<float32_t>(PI64) / 2.0F - m_realPinhole.getExtrinsic_rs().eulerAngles_s.pitch_x);
	// apply 90 - degrees to flip to AppCtrl Coordinate system
	if (inDegrees)
	{
		ret1 = (90.0F-mecl::math::toDegrees_x<float32_t>(m_realPinhole.getExtrinsic_rs().eulerAngles_s.pitch_x));
	}
	else
	{
		ret1 = (static_cast<float32_t>(PI64)/2.0F - m_realPinhole.getExtrinsic_rs().eulerAngles_s.pitch_x);
	}
	return ret1;
}

float32_t Camera::getYaw(bool_t inDegrees) const
{
	float32_t ret2 = -m_realPinhole.getExtrinsic_rs().eulerAngles_s.yaw_x;
	if (inDegrees)
	{
		ret2 =  mecl::math::toDegrees_x<float32_t>(-m_realPinhole.getExtrinsic_rs().eulerAngles_s.yaw_x);
	}
	else
	{
		ret2 = -m_realPinhole.getExtrinsic_rs().eulerAngles_s.yaw_x;
	}
	return ret2;
}

float32_t Camera::getRoll(bool_t inDegrees) const
{ 
	float32_t ret = -m_realPinhole.getExtrinsic_rs().eulerAngles_s.roll_x;
	if (inDegrees)
	{
		ret = mecl::math::toDegrees_x<float32_t>(-m_realPinhole.getExtrinsic_rs().eulerAngles_s.roll_x);
	}
	else
	{
		ret = -m_realPinhole.getExtrinsic_rs().eulerAngles_s.roll_x;
	}
	return ret;
}

float32_t Camera::getPreRoll(bool_t inDegrees) const
{
	float32_t preroll = 0.0F;

	float32_t ret;

	switch (m_realPinhole.getExtrinsic_rs().preRoll_e)
	{
	case mecl::model::e_PreRoll0:	///<   0 degrees pre-rotation about z-axis ( left camera)
	{
		preroll = 0.0F;
		break;
	}
	case mecl::model::e_PreRoll90:	///<  90 degrees pre-rotation about z-axis (front camera)
	{
		preroll = 90.0F;
		break;
	}
	case mecl::model::e_PreRoll180:	///< 180 degrees pre-rotation about z-axis (right camera)
	{
		preroll = 180.0F;
		break;
	}
	case mecl::model::e_PreRoll270:	///< 270 degrees pre-rotation about z-axis ( rear camera)
	{	preroll = 270.0F;
		break;
	}
	}

	if (inDegrees)
	{
		ret = preroll;
	}
	else
	{
		ret = mecl::math::toRadians_x<float32_t>(preroll);
	}
	return ret;
}

bool_t Camera::isRollIn14Quadrants(void) const
{
return ((getRoll() >= -90.0F) && (getRoll() < 90.0F));
}

bool_t Camera::isRollIn23Quadrants(void) const
{
return(((getRoll() >= 90.0F) && (getRoll() < 270.0F)) || ((getRoll() >= -270.0F) && (getRoll() < -90.0F)));
}


Point2f Camera::World2CamDisPt(Point2f worldPt)const
{
	Point2f camPt;
	switch (getOrientation())
	{
	case Front:
	{
		camPt.x = -worldPt.x + getDeltaX();
		camPt.y = -worldPt.y + getDeltaY();
		break;
	}

	case Right:
	{
		camPt.y = -worldPt.x + (getDeltaX());
		camPt.x = worldPt.y - getDeltaY();
		break;
	}

	case Left:
	{
		camPt.y = worldPt.x - (getDeltaX());
		camPt.x = -worldPt.y + (getDeltaY());
		break;
	}

	case Rear:
	default:
	{
		camPt.x = worldPt.x - (getDeltaX());
		camPt.y = worldPt.y - (getDeltaY());
		break;
	}

	}

	return camPt;
}
Point2f Camera::Cam2WorldDisPt(Point2f worldPt)const
{
	Point2f worldPt_1;
	switch (getOrientation())
	{
	case Front:
	{
		worldPt_1.x = -worldPt.x + getDeltaX();
		worldPt_1.y = -worldPt.y + (getDeltaY());
		break;
	}

	case Right:
	{
		worldPt_1.x = -worldPt.y + getDeltaX();
		worldPt_1.y = worldPt.x + getDeltaY();
		break;
	}

	case Left:
	{
		worldPt_1.x = worldPt.y + (getDeltaX());
		worldPt_1.y = -worldPt.x + (getDeltaY());
		break;
	}

	case Rear:
	default:
	{
		worldPt_1.x = worldPt.x + (getDeltaX());
		worldPt_1.y = worldPt.y + (getDeltaY());
		break;
	}

	}

	return worldPt_1;
}



 
void Camera::ApplyDistortion_MECL(float32_t *b_X_pf32, float32_t *b_Y_pf32)const
{
    mecl::core::Point3D<float32_t> i_Pos_rx;
    mecl::core::Point2D<float32_t> o_Pos_rx;
    mecl::core::Point2D<float32_t> i_Pos_rx_pixel;

    i_Pos_rx_pixel.setPosX(reinterpret_cast<const float32_t&>(*b_X_pf32));
    i_Pos_rx_pixel.setPosY(reinterpret_cast<const float32_t&>(*b_Y_pf32));
    mecl::core::Point2D<float32_t> o_Pos_rx_pixel;
    m_realCam.pixelToMetric_v(i_Pos_rx_pixel, o_Pos_rx_pixel);
    i_Pos_rx.setPosX(o_Pos_rx_pixel.getPosX());
    i_Pos_rx.setPosY(o_Pos_rx_pixel.getPosY());
    i_Pos_rx.setPosZ(static_cast<float32_t>(1));
      
    m_realCam.applyDistortion_v(i_Pos_rx, o_Pos_rx);

    m_realCam.metricToPixel_v(o_Pos_rx, o_Pos_rx_pixel);

    *b_X_pf32 =  o_Pos_rx_pixel.getPosX();
    *b_Y_pf32 =  o_Pos_rx_pixel.getPosY();

}

void Camera::ApplyDistortion_MECL_Virtual(float32_t *b_X_pf32, float32_t *b_Y_pf32)const
{
    mecl::core::Point3D<float32_t> i_Pos_rx;
    mecl::core::Point2D<float32_t> o_Pos_rx;
    mecl::core::Point2D<float32_t> i_Pos_rx_pixel;

    i_Pos_rx_pixel.setPosX(reinterpret_cast<const float32_t&>(*b_X_pf32));
    i_Pos_rx_pixel.setPosY(reinterpret_cast<const float32_t&>( *b_Y_pf32));
    mecl::core::Point2D<float32_t> o_Pos_rx_pixel;
    m_virtualCam.pixelToMetric_v(i_Pos_rx_pixel, o_Pos_rx_pixel);
    i_Pos_rx.setPosX(o_Pos_rx_pixel.getPosX());
    i_Pos_rx.setPosY(o_Pos_rx_pixel.getPosY());
    i_Pos_rx.setPosZ(static_cast<float32_t>(1));

    m_virtualCam.applyDistortion_v(i_Pos_rx, o_Pos_rx);

    m_virtualCam.metricToPixel_v(o_Pos_rx, o_Pos_rx_pixel);

    *b_X_pf32 =  o_Pos_rx_pixel.getPosX();
    *b_Y_pf32 =  o_Pos_rx_pixel.getPosY();

}

//-------------------------------------------------------------------------
//used by ctracker 
void Camera::Radial2CylinderConversion(float32_t *b_X_pf32, float32_t *b_Y_pf32)
{

    mecl::core::Point2D<float32_t> v_PointOutput_f32;

    // define some point coordinates
    mecl::core::Point2D<float32_t> v_PointInput_f32(reinterpret_cast<const float32_t&>(*b_X_pf32), reinterpret_cast<const float32_t&>(*b_Y_pf32));

    m_singleView.applyRealToSyntheticProjection_v(v_PointInput_f32, v_PointOutput_f32);

    *b_X_pf32 =  v_PointOutput_f32.getPosX();
    *b_Y_pf32 =  v_PointOutput_f32.getPosY();

}

void Camera::ApplyTransformation( float32_t *io_x, float32_t *io_y, bool direction )
{
	float32_t x;
	float32_t y;

    x =  *io_x;
    y =  *io_y;
    if( direction )
    {
		switch (m_CameraType)
		{
		case MECL_Radial:
		{
			ApplyDistortion_MECL(&x, &y);
			break;
		}
		case MECL_Cylinder:
		case Cylinder_VarScale:
		case Top_View:
		case MECL_Normal:
		case Cylinder:
		{
			ApplyDistortion_MECL(&x, &y);
			Radial2CylinderConversion(&x, &y);
/*
 *	ApplyDistortion_MECL_Virtual(&x, &y);
 */
			break;
		}
		default:
		{
			ApplyDistortion_MECL(&x, &y);
			break;
		}
        }
        *io_x = x;
        *io_y = y;
    }
    else
    {
        switch (m_CameraType)
        {
        case MECL_Radial:
		{
			ApplyUndistortion_MECL(&x, &y);
			break;
		}
		case Cylinder:
		case Top_View:
        case MECL_Cylinder:
		case MECL_Normal:
        case Cylinder_VarScale:
		{
			Virtual2RadialConversion(&x, &y);
			ApplyUndistortion_MECL(&x, &y);
/*
 *	ApplyUndistortion_MECL_Virtual(&x, &y);
 */
			break;
		}
        default:
		{
			ApplyUndistortion_MECL(&x, &y);
			break;
		}
        }
        *io_x = x;
        *io_y = y;
    }
}

//-------------------------------------------------------------------------

void Camera::Virtual2RadialConversion(float32_t *b_X_pf32, float32_t *b_Y_pf32)
{

    mecl::core::Point2D<float32_t> v_PointOutput_f32;

    // define some point coordinates
    mecl::core::Point2D<float32_t> v_PointInput_f32(reinterpret_cast<const float32_t&>(*b_X_pf32), reinterpret_cast<const float32_t&>(*b_Y_pf32));

    m_singleView.applySyntheticToRealProjection_v(v_PointInput_f32, v_PointOutput_f32);

    *b_X_pf32 = v_PointOutput_f32.getPosX();
    *b_Y_pf32 = v_PointOutput_f32.getPosY();

}

void Camera::ApplyUndistortion_MECL(float32_t *b_X_pf32, float32_t *b_Y_pf32)const
{
    mecl::core::Point2D<float32_t> i_Pos_rx;
    mecl::core::Point2D<float32_t> i_Pos_rx_pixel;
    mecl::core::Point2D<float32_t> o_Pos_rx_pixel;
	mecl::core::Point2D<float32_t> o_Pos_rx_metric;
    mecl::core::Point3D<float32_t> o_Pos_rx;

    i_Pos_rx.setPosX(reinterpret_cast<const float32_t&>( *b_X_pf32));
    i_Pos_rx.setPosY(reinterpret_cast<const float32_t&>( *b_Y_pf32));
 
    m_realCam.pixelToMetric_v( i_Pos_rx, o_Pos_rx_metric);
     
    m_realCam.applyUndistortion_v(o_Pos_rx_metric, o_Pos_rx);
	o_Pos_rx.setPosZ(  mecl::math::abs_x(o_Pos_rx.getPosZ()));

    m_realCam.applyNormalization_v(o_Pos_rx, 1.0, i_Pos_rx_pixel);

    m_realCam.metricToPixel_v(i_Pos_rx_pixel, o_Pos_rx_pixel);

    *b_X_pf32 = o_Pos_rx_pixel.getPosX();
    *b_Y_pf32 = o_Pos_rx_pixel.getPosY();
}

void Camera::ApplyUndistortion_MECL_Virtual(float32_t *b_X_pf32, float32_t *b_Y_pf32)const
{
    mecl::core::Point2D<float32_t> i_Pos_rx;
    mecl::core::Point2D<float32_t> i_Pos_rx_pixel;
    mecl::core::Point2D<float32_t> o_Pos_rx_pixel;
    mecl::core::Point3D<float32_t> o_Pos_rx;

    i_Pos_rx.setPosX(reinterpret_cast<const float32_t&>( *b_X_pf32));
    i_Pos_rx.setPosY(reinterpret_cast<const float32_t&>( *b_Y_pf32));

    m_virtualCam.pixelToMetric_v(i_Pos_rx, o_Pos_rx_pixel);

    m_virtualCam.applyUndistortion_v(o_Pos_rx_pixel, o_Pos_rx);

    m_virtualCam.applyNormalization_v(o_Pos_rx, 1.0, i_Pos_rx_pixel);

    m_virtualCam.metricToPixel_v(i_Pos_rx_pixel, o_Pos_rx_pixel);

    *b_X_pf32 = o_Pos_rx_pixel.getPosX();
    *b_Y_pf32 = o_Pos_rx_pixel.getPosY();
}

//-------------------------------------------------------------------------

Point2f Camera::pixel_warp( Point2f& pt )
{
    Point2f returnedPt;
	returnedPt.x = pt.x;
	returnedPt.y = pt.y;
	ApplyTransformation(&returnedPt.x, &returnedPt.y, true);
	returnedPt.x = returnedPt.x / downsamp_sensor.x;
	returnedPt.y = returnedPt.y / downsamp_sensor.y;
    return returnedPt;
}

Point2f Camera::pixel_unwarp(const Point2f *pPtInput)
{
	float32_t x_f32;
	float32_t y_f32;
	Point2f PtOutput;
	x_f32 = pPtInput->x*downsamp_sensor.x;
	y_f32 = pPtInput->y*downsamp_sensor.y;
	ApplyTransformation(&x_f32, &y_f32, false);
	PtOutput.x = x_f32;
	PtOutput.y = y_f32;
	return PtOutput;
}

//-------------------------------------------------------------------------
Point2f Camera::unwarped_distance(const Point2f& unwarpedPt, const float32_t i_P[3][4])
{
	Point2f world;
	mecl::core::Point3D<float32_t> Pt_Pixel(unwarpedPt.x, unwarpedPt.y, static_cast<float32_t>(1));
	mecl::core::Point3D<float32_t> Pt_World;

	// convert P Matrix to 3x3 and invert
	mecl::core::Matrix<float32_t, 3, 4> tmpP(&i_P[0][0], 12);

	mecl::core::Matrix3x3<float32_t> v_ZPlaneHomography_x;
	v_ZPlaneHomography_x.setCol(0, tmpP.col(0));
	v_ZPlaneHomography_x.setCol(1, tmpP.col(1));
	v_ZPlaneHomography_x.setCol(2, tmpP.col(3));

	Pt_World = v_ZPlaneHomography_x.inverse().mmul(Pt_Pixel);
	world.x = Pt_World.getPosX() / Pt_World.getPosZ();
	world.y = Pt_World.getPosY() / Pt_World.getPosZ();

	return world;
}

//-------------------------------------------------------------------------
Point2f Camera::unwarped_distance(const Point2f& unwarpedPt, bool unwarp)
{
	Point2f v_unwarpedPt;
	Point2f world;
	Point2f warpedPt;
	mecl::core::Point2D<float32_t> i_Pos_rx;
	mecl::core::Point3D<float32_t> o_Pos_rx;
	if (unwarp == false)
	{
		v_unwarpedPt = unwarpedPt;
		warpedPt = pixel_warp(static_cast<Point2f&>(v_unwarpedPt));
		warpedPt.x *= downsamp_sensor.x;
		warpedPt.y *= downsamp_sensor.y;
	}
	else
	{
		warpedPt.x = unwarpedPt.x*downsamp_sensor.x;
		warpedPt.y = unwarpedPt.y*downsamp_sensor.y;
	}

	i_Pos_rx.setPosX(warpedPt.x);
	i_Pos_rx.setPosY(warpedPt.y);
	mecl::core::Point4D<float32_t> v_PlaneCoord_f32;

	if ((m_CameraType == MECL_Cylinder) || (m_CameraType == Cylinder_VarScale) || (m_CameraType == Top_View) || (m_CameraType == MECL_Normal ))
	{
		m_virtualCam.applyZPlaneBackProjection_v(i_Pos_rx, v_PlaneCoord_f32);
	}
	else if (m_CameraType == MECL_Radial)
	{
		m_realCam.applyZPlaneBackProjection_v(i_Pos_rx, v_PlaneCoord_f32);
	}
	else
	{
		Assert("Invalid Camera option for meclImageToWorld function");
	}
	world.x = v_PlaneCoord_f32.getPosX();
	world.y = v_PlaneCoord_f32.getPosY();
	return world;
}

Point2f Camera::unwarped_distanceVirtual(const Point2f& unwarpedPt)const
{
	Point2f world;
	mecl::core::Point2D<float32_t> i_Pos_rx;
	mecl::core::Point4D<float32_t> o_Pos_rx;
	
	i_Pos_rx.setPosX(unwarpedPt.x);
	i_Pos_rx.setPosY(unwarpedPt.y);

	m_virtualCam.applyZPlaneBackProjection_v(i_Pos_rx, o_Pos_rx);

	world.x = o_Pos_rx.getPosX();
	world.y = o_Pos_rx.getPosY();
	return world;
}

// ----------------------------------------------------------------------------
#if 0
bool Camera::Init(unsigned int imgW, unsigned imgH, do_CameraParam& CamIfo, const CameraCfg* camCfg, char *pCameraName, const char *pCamProfileName, unsigned long hTracer, 
	float ppX, float ppY, float zoomX, float zoomY, CameraType_t cameratypeID, int converttovirtual)
{
#ifdef _MSC_VER
	if (camCfg == NULL) {																	//|   WINDOWS ONLY CODE
		WindowsCameraConfig winCamCfg(pCameraName, hTracer, imgW, imgH, pCamProfileName);	//|
		try {																				//|
			winCamCfg.loadCameraCfg();														//|
		}																					//|
		catch (std::exception e) {															//|
			return false;																	//|
		}																					//|
		if (zoomX > 0.0F && zoomY > 0.0F)
		{
			winCamCfg.resetCylinderZoom(zoomX, zoomY);
		}
		if (ppX > 0.0F && ppY > 0.0F)
		{
			winCamCfg.resetCylinderPrincipalPoint(ppX, ppY);
		}
		camCfg = &winCamCfg.getCameraCfg();													//|
	}
#endif


	memcpy(m_CameraNameStr, camCfg->m_CameraNameStr, sizeof(m_CameraNameStr));
	memcpy(m_ProfileName, camCfg->m_ProfileName, sizeof(m_ProfileName));
	// assigned value to control rotation to be modified based on configuration parameter
	sensorOrientation = mecl::model::e_UpperLeft;  // normal orientation
/*
 *	m_sensorOrientation = mecl::model::e_LowerRight; 
 *	rotated orientation to be added when varaible added to configuration
 */

	memcpy(CamIfo.m_ViewingPolygon, camCfg->m_ViewingPolygon, sizeof(CamIfo.m_ViewingPolygon));
	CamIfo.m_NumViewingPolygonPts = camCfg->m_NumViewingPolygonPts;
	//Camera Type type is no defined by initialization routine
	if (cameratypeID == MAX_CameraType_ID)
	{
		m_CameraType = camCfg->m_CameraType;
	}
	else
	{
		m_CameraType = cameratypeID;
	}
	if (m_CameraType == MECL_Cylinder || m_CameraType == MECL_Normal)
	{
		m_ConvertToCylinder = true;
	}

	m_LensSignature = camCfg->m_LensSignature;
	m_MECLParameterLoaded = camCfg->m_MECLParameterLoaded;

	// for now case only controls pre-roll (we may need to reference it from configuration but needs to be confirmed first)
	mecl::model::PreRoll_e cameraPreRoll;
	float32_t PreRoll_f32 = camCfg->ang_preroll;
	if (PreRoll_f32 < 0)
	{
		PreRoll_f32 += 360.0F;
	}
	if (PreRoll_f32 == 90.0F)
	{
		cameraPreRoll = mecl::model::e_PreRoll90; // Front Camera
		m_CamOrientation = Front;
	}
	else if (PreRoll_f32 == 0)
	{
		cameraPreRoll = mecl::model::e_PreRoll0; //Right Camera
		m_CamOrientation = Right;
	}
	else if (PreRoll_f32 == 180.0F)
	{
		cameraPreRoll = mecl::model::e_PreRoll180; //left Camera
		m_CamOrientation = Left;
	}
	else
	{
		cameraPreRoll = mecl::model::e_PreRoll270; // if Pre_Roll is not defined assume it is facing to the Rear
		m_CamOrientation = Rear;
	}

	downsamp_sensor.x = camCfg->orig_x / (float32_t) imgW;
	downsamp_sensor.y = camCfg->orig_y / (float32_t) imgH;

	// --- initialize the processed image
	{
		unsigned short w, h;

		w = (unsigned short)ceil(camCfg->orig_x / downsamp_sensor.x);
		h = (unsigned short)floor(camCfg->orig_y / downsamp_sensor.y);

		// --- some sanity checks
		if ((imgW != w) || (imgH != h))
		{
			return (false);
		}
	}

	// Instantiate lens object
	if (!m_MECLParameterLoaded)
	{ // Default Chrysler Lens parameters if no other lens parameters provided
		m_realLens.updateConfig_v(
		{
			{ // world to image (distortion parameters)
				0.000000f,
				0.898294510928492f,
				0.048179422f,
				-0.003451951f,
				0.121857715f,
				-0.056961112f
			},
			{ // image to world (undistortion parameters)
				0.000000f,
				1.109194244f,
				-0.018944607f,
				-0.166467826f,
				0.075762609f,
				-0.006105017f
			},
			90.0F // elevation angle
		});
	}
	else
	{
		m_realLens.updateConfig_v(camCfg->m_realLensCfg);
	}
	// create model instances for real camera and components
	m_realSensor.updateConfig_v({
		// Pull Parameter from Configuration
		{ camCfg->axisX, camCfg->axisY },                    // principal point position [px]
		{ camCfg->pixelsize, camCfg->pixelsize },                   // sensor resolution horiz./vert. [mm/px]
		sensorOrientation,           // Sensor orientation
									 // define valid sensor area in pixels (upper left, lower right point)
		{ 0.0F, 0.0F },
		{ camCfg->orig_x, camCfg->orig_y }
	});
	m_realPinhole.updateConfig_v({ {
		{ camCfg->deltaX  , camCfg->deltaY, camCfg->deltaZ },   // X Y and Z setup from configuration file
																		 // Euler angles
		{ mecl::math::toRadians_x(camCfg->ang_alpha), // Pitch  check the 90.0F -
		mecl::math::toRadians_x(-camCfg->ang_beta),  // Yaw
		mecl::math::toRadians_x(-camCfg->ang_gamma) // Roll
		},
		cameraPreRoll, // Front camera position pre-roll needs to be fixed for all 4 cameras
		mecl::model::e_WorldToCamera
		},
		{ 1.0F, 1.0F,{ 0.0 , 0.0 } } });
	m_realCam.setImager_v(m_realPinhole);
	m_realCam.setLens_v(m_realLens);
	m_realCam.setSensor_v(m_realSensor);

	// create instances for Virtual camera and components (types are top View Cylinder and Scaled Cylinder
	if (m_CameraType == MECL_Cylinder || m_CameraType == MECL_Normal )
	{
		m_VirtualSensor.updateConfig_v({
		// Cylindrical View camera
		{ camCfg->cylaxisX, camCfg->cylaxisY },                    // principal point position [px]
		{ camCfg->cylZoomRatioX, camCfg->cylZoomRatioY },
			sensorOrientation,           // Sensor orientation
											// define valid sensor area in pixels (upper left, lower right point)
			{ camCfg->orig_x0, camCfg->orig_y0 },
			{ camCfg->orig_x, camCfg->orig_y }
		});
	}
    m_CylinderLens.updateConfig_v({ 1.0F });
	if (m_CameraType == MECL_Normal )
	{
		m_VirtualSensor.updateConfig_v({
			// Top View camera
			{ 639.5f, 399.5f },                    // principal point position [px]
			{ 0.003f, 0.003f },                   // sensor resolution horiz./vert. [mm/px]
			sensorOrientation,           // Sensor orientation
										 // define valid sensor area in pixels (upper left, lower right point)
			{ 0.0F, 0.0F },
			{ camCfg->orig_x, camCfg->orig_y }
		});
		m_VirtualPinhole.updateConfig_v({ {
				// Top View Camera position in world coordinates
			{ camCfg->deltaX  , camCfg->deltaY, camCfg->deltaZ },   // X Y and Z setup from configuration file
																	// Euler angles Cylinder View always has hard coded orientation
			{
				mecl::math::toRadians_x(camCfg->ang_alpha), // -> this makes your topView virtically aligned!
				mecl::math::toRadians_x(0.0F),
				mecl::math::toRadians_x(0.0F) },

				cameraPreRoll,
				mecl::model::e_WorldToCamera
			},
			{ 1.0F, 1.0F,{ 0.0 , 0.0 } } });


	}

	else if (m_CameraType == Top_View)
	{
		m_VirtualSensor.updateConfig_v({
			// Top View camera
			{ 639.5f, 399.5f },                    // principal point position [px]
			{ 0.003f, 0.003f },                   // sensor resolution horiz./vert. [mm/px]
			sensorOrientation,           // Sensor orientation
										 // define valid sensor area in pixels (upper left, lower right point)
			{ 0.0F, 0.0F },
			{ camCfg->orig_x, camCfg->orig_y }
		});
		m_VirtualPinhole.updateConfig_v({ {
				// Top View Camera position in world coordinates
			{ (float32_t)camCfg->VirtualdeltaX  , (float32_t)camCfg->VirtualdeltaY, (float32_t)camCfg->VirtualdeltaZ },   // X Y and Z setup from configuration file
																									 // Euler angles Cylinder View always has hard coded orientation
			{
				mecl::math::toRadians_x(camCfg->Virtualang_alpha-90.0F), // -> this makes your topView virtically aligned!
				mecl::math::toRadians_x(camCfg->Virtualang_beta),
				mecl::math::toRadians_x(camCfg->Virtualang_gamma) },

				cameraPreRoll,
				mecl::model::e_WorldToCamera
			},
			{ 1.0F, 1.0F,{ 0.0 , 0.0 } } });
	}
	else { // default is Cylinder View even if Fish eye
		m_VirtualPinhole.updateConfig_v({ {
				// Camera position in world coordinates
				{ camCfg->deltaX  , camCfg->deltaY, camCfg->deltaZ },   // X Y and Z setup from configuration file
				 // Euler angles Cylinder View always has hard coded orientation
				{
					mecl::math::toRadians_x(90.0F), // -> this makes your cylinder lens horizontally aligned!
					mecl::math::toRadians_x(0.0F),
					mecl::math::toRadians_x(0.0F) },

					cameraPreRoll,
					mecl::model::e_WorldToCamera
				},
				{ 1.0F, 1.0F,{ 0.0 , 0.0 } } });
	}
    m_virtualCam.setImager_v(m_VirtualPinhole);
    
    if (m_CameraType == Cylinder_VarScale)
    {
		mecl::model::SensorVarScale<float32_t>::Config_s m_sensorVarCfg_s;            /* MECL var scale sensor configuration */
		m_virtualCam.setLens_v(m_CylinderLens);
		// Update sensor object with new sensor parameters.
		// Move out to Configuration TBD
		m_sensorVarCfg_s.sensorUniform_s =
		{
			// Pull Parameter from Configuration
			{ camCfg->cylaxisX, camCfg->cylaxisY },                    // principal point position [px]
			{ camCfg->cylZoomRatioX, camCfg->cylZoomRatioY },
/*
 *	{ 0.00274f , 0.00292f },  
 *	sensor resolution horiz./vert. [mm/px]
 */
			sensorOrientation,           // first pixel in upper left corner
	       // define valid sensor area in pixels (upper left, lower right point)
		   { 0.0F, 0.0F },
		   { camCfg->orig_x, camCfg->orig_y }
		};

		// load the containing the variable
		loadRearScale();
		m_sensorVarCfg_s.varScaleBufferSize_u32 = REAR_SCALE_SIZE1;
		m_sensorVarCfg_s.varScaleBuffer_px = g__Rear_Scale;
		m_VarScaleCylinderLens.updateConfig_v(m_sensorVarCfg_s);
		m_VarScaleCylinderLens.init_v();
		m_virtualCam.setSensor_v(m_VarScaleCylinderLens);
    }
	else if (m_CameraType == Top_View)
	{
		m_virtualCam.setNoLens_v();
		m_virtualCam.setSensor_v(m_VirtualSensor);
	}
	else // default for (m_CameraType == MECL_Cylinder) and Fisheye
	{
		m_virtualCam.setLens_v(m_CylinderLens);
		m_virtualCam.setSensor_v(m_VirtualSensor);
	}

	if (m_CameraType == MECL_Normal)
	{
#if 0
		m_VirtualSensor.updateConfig_v({
			// Top View camera
			{ 639.5f, 399.5f },                    // principal point position [px]
			{ 0.003f, 0.003f },                   // sensor resolution horiz./vert. [mm/px]
			sensorOrientation,           // Sensor orientation
										 // define valid sensor area in pixels (upper left, lower right point)
			{ 0.0F, 0.0F },
			{ camCfg->orig_x, camCfg->orig_y }
		});
		m_VirtualPinhole.updateConfig_v({ {
				// Top View Camera position in world coordinates
			{ (float32_t)camCfg->VirtualdeltaX  , (float32_t)camCfg->VirtualdeltaY, (float32_t)camCfg->VirtualdeltaZ },   // X Y and Z setup from configuration file
																														  // Euler angles Cylinder View always has hard coded orientation
			{
				mecl::math::toRadians_x(camCfg->Virtualang_alpha - 90.0F), // -> this makes your topView virtically aligned!
				mecl::math::toRadians_x(camCfg->Virtualang_beta),
				mecl::math::toRadians_x(camCfg->Virtualang_gamma) },

				cameraPreRoll,
				mecl::model::e_WorldToCamera
			},
			{ 1.0F, 1.0F,{ 0.0 , 0.0 } } });
/*
 *	m_virtualCam.setLens_v(m_CylinderLens);
 */
		m_virtualCam.setNoLens_v();
		m_virtualCam.setSensor_v(m_VirtualSensor);
#else
		m_VirtualSensor.updateConfig_v({
			// Top View camera
			{ 639.5f, 399.5f },                    // principal point position [px]
			{ 0.003f, 0.003f },                   // sensor resolution horiz./vert. [mm/px]
			sensorOrientation,           // Sensor orientation
										 // define valid sensor area in pixels (upper left, lower right point)
			{ 0.0F, 0.0F },
			{ camCfg->orig_x, camCfg->orig_y }
		});
		m_VirtualPinhole.updateConfig_v({ {
				// Top View Camera position in world coordinates
			{ camCfg->deltaX  , camCfg->deltaY, camCfg->deltaZ },   // X Y and Z setup from configuration file
																	// Euler angles Cylinder View always has hard coded orientation
			{
				mecl::math::toRadians_x(70.0F),
/*
 *	mecl::math::toRadians_x(camCfg->ang_alpha),
 */
				mecl::math::toRadians_x(0.0F),
				mecl::math::toRadians_x(0.0F) },

				cameraPreRoll,
				mecl::model::e_WorldToCamera
			},
			{ 1.0F, 1.0F,{ 0.0 , 0.0 } } });
/*
 *	m_virtualCam.setLens_v(m_CylinderLens);
 */
		m_virtualCam.setNoLens_v();
        m_virtualCam.setSensor_v(m_VirtualSensor);
#endif
	}
    // create Single view instance yielding the projective model
    m_singleView.setRealCam_v(m_realCam);
    m_singleView.setSyntCam_v(m_virtualCam);

	CreateCameraMatricesMECL(CamIfo.P_MECL); // copy the P Matrix over to Global variable
	// setup of virtual Camera Parameters to be removed once MECL TopView working
	{
		CamIfo.VirtualImageX = imgW;
		CamIfo.VirtualImageY = imgH;
		CamIfo.VirtualaxisX = ((float32_t)(CamIfo.VirtualImageX - 1) / 2);
		CamIfo.VirtualaxisY = ((float32_t)(CamIfo.VirtualImageY - 1) / 2);
		CamIfo.Virtualang_alpha = camCfg->Virtualang_alpha;
		CamIfo.Virtualang_beta = camCfg->Virtualang_beta;
		CamIfo.Virtualang_gamma = camCfg->Virtualang_gamma;
		CamIfo.Virtualang_preroll = camCfg->Virtualang_preroll;
		CamIfo.VirtualdeltaX = camCfg->VirtualdeltaX;
		CamIfo.VirtualdeltaY = camCfg->VirtualdeltaY;
		CamIfo.VirtualdeltaZ = camCfg->VirtualdeltaZ;
		CamIfo.Virtualpixelsize = 0.003f;
		CamIfo.Virtualfocallength = camCfg->Virtualfocallength;
	}

	CamIfo.AdjustEnvironmentParams(imgW, imgH);
    return ( true );
}
#endif
// ----------------------------------------------------------------------------

bool Camera::Init(uint32_t imgW, uint32_t imgH, do_CameraParam& CamIfo, CameraType_t cameratypeID, const CameraCfg* camCfg)
{
	// assigned value to control rotation to be modified based on configuration parameter
	sensorOrientation = mecl::model::e_UpperLeft;  // normal orientation
/*
 *	m_sensorOrientation = mecl::model::e_LowerRight; 
 *	rotated orientation to be added when varaible added to configuration
 */
	//Camera Type type is no defined by initialization routine

	bool_t ret = true;

	if (cameratypeID == MAX_CameraType_ID)
	{
		m_CameraType = camCfg->m_CameraType;
	}
	else
	{
		m_CameraType = cameratypeID;
	}
	if ((m_CameraType == MECL_Cylinder) || (m_CameraType == MECL_Normal))
	{
		m_ConvertToCylinder = true;
	}

	m_LensSignature = camCfg->m_LensSignature;
	m_MECLParameterLoaded = camCfg->m_MECLParameterLoaded;

	// for now case only controls pre-roll (we may need to reference it from configuration but needs to be confirmed first)
	mecl::model::PreRoll_e cameraPreRoll;
	float32_t PreRoll_f32 = camCfg->ang_preroll;
	if (PreRoll_f32 < 0)
	{
		PreRoll_f32 += 360.0F;
	}
	if (mecl::math::isAboutZero_b(PreRoll_f32 - 90.0F))
	{
		cameraPreRoll = mecl::model::e_PreRoll90; // Front Camera
		m_CamOrientation = Front;
	}
	else if (mecl::math::isAboutZero_b(PreRoll_f32 - 0))
	{
		cameraPreRoll = mecl::model::e_PreRoll0; //Right Camera
		m_CamOrientation = Right;
	}
	else if (mecl::math::isAboutZero_b(PreRoll_f32 - 180.0F))
	{
		cameraPreRoll = mecl::model::e_PreRoll180; //left Camera
		m_CamOrientation = Left;
	}
	else
	{
		cameraPreRoll = mecl::model::e_PreRoll270; // if Pre_Roll is not defined assume it is facing to the Rear
		m_CamOrientation = Rear;
	}

	downsamp_sensor.x = camCfg->orig_x / static_cast<float32_t>(imgW);
	downsamp_sensor.y = camCfg->orig_y / static_cast<float32_t>(imgH);

	// --- initialize the processed image
	{
		uint16_t w;
		uint16_t h;

		w = static_cast<uint16_t>(ceil(camCfg->orig_x / downsamp_sensor.x));
		h = static_cast<uint16_t>(floor(camCfg->orig_y / downsamp_sensor.y));

		// --- some sanity checks
		if ((imgW != w) || (imgH != h))
		{
			ret = (false);
		}
	}

	// Instantiate lens object
	if (!m_MECLParameterLoaded)
	{ // Default Chrysler Lens parameters if no other lens parameters provided
		m_realLens.updateConfig_v(
		{
			{ // world to image (distortion parameters)
				0.000000F,
				0.898294510928492F,
				0.048179422F,
				-0.003451951F,
				0.121857715F,
				-0.056961112F
			},
			{ // image to world (undistortion parameters)
				0.000000F,
				1.109194244F,
				-0.018944607F,
				-0.166467826F,
				0.075762609F,
				-0.006105017F
			},
			90.0F // elevation angle
		});
	}
	else
	{
		m_realLens.updateConfig_v(camCfg->m_realLensCfg);
	}
	// create model instances for real camera and components
	m_realSensor.updateConfig_v({
		// Pull Parameter from Configuration
		{ camCfg->axisX, camCfg->axisY },                    // principal point position [px]
		{ camCfg->pixelsize, camCfg->pixelsize },                   // sensor resolution horiz./vert. [mm/px]
		sensorOrientation,           // Sensor orientation
									 // define valid sensor area in pixels (upper left, lower right point)
		{ 0.0F, 0.0F },
		{ camCfg->orig_x, camCfg->orig_y }
	});
	m_realPinhole.updateConfig_v({ {
		{ camCfg->deltaX  , camCfg->deltaY, camCfg->deltaZ },   // X Y and Z setup from configuration file
																// Euler angles
		{ mecl::math::toRadians_x(camCfg->ang_alpha), // Pitch  check the 90.0F -
		mecl::math::toRadians_x(-camCfg->ang_beta),  // Yaw
		mecl::math::toRadians_x(-camCfg->ang_gamma) // Roll
		},
		cameraPreRoll, // Front camera position pre-roll needs to be fixed for all 4 cameras
		mecl::model::e_WorldToCamera
		},
#if 1 
		{ camCfg->focallength, camCfg->focallength,{ 0.0F , 0.0F }
#else
		{ 1.0F, 1.0F,{ 0.0 , 0.0 }
#endif
		} });
	m_realCam.setImager_v(m_realPinhole);
	m_realCam.setLens_v(m_realLens);
	m_realCam.setSensor_v(m_realSensor);

	// create instances for Virtual camera and components (types are top View Cylinder and Scaled Cylinder
	if ((m_CameraType == MECL_Cylinder) || (m_CameraType == MECL_Normal))
	{
		m_VirtualSensor.updateConfig_v({
			// Cylindrical View camera
			{ camCfg->cylaxisX, camCfg->cylaxisY },                    // principal point position [px]
			{ camCfg->cylZoomRatioX, camCfg->cylZoomRatioY },
			sensorOrientation,           // Sensor orientation
										 // define valid sensor area in pixels (upper left, lower right point)
			{ camCfg->orig_x0, camCfg->orig_y0 },
			{ camCfg->orig_x, camCfg->orig_y }
		});
	}
	m_CylinderLens.updateConfig_v({ 1.0F });
	if (m_CameraType == MECL_Normal)
	{
		m_VirtualSensor.updateConfig_v({
			// Top View camera
			{ 639.5F, 399.5F },                    // principal point position [px]
			{ 0.003F, 0.003F },                   // sensor resolution horiz./vert. [mm/px]
			sensorOrientation,           // Sensor orientation
										 // define valid sensor area in pixels (upper left, lower right point)
			{ 0.0F, 0.0F },
			{ camCfg->orig_x, camCfg->orig_y }
		});
		m_VirtualPinhole.updateConfig_v({ {
				// Top View Camera position in world coordinates
			{ camCfg->deltaX  , camCfg->deltaY, camCfg->deltaZ },   // X Y and Z setup from configuration file
																	// Euler angles Cylinder View always has hard coded orientation
			{
				mecl::math::toRadians_x(camCfg->ang_alpha), // -> this makes your topView virtically aligned!
				mecl::math::toRadians_x(0.0F),
				mecl::math::toRadians_x(0.0F) },

				cameraPreRoll,
				mecl::model::e_WorldToCamera
			},
			{ 1.0F, 1.0F,{ 0.0F , 0.0F } } });


	}

	else if (m_CameraType == Top_View)
	{
		m_VirtualSensor.updateConfig_v({
			// Top View camera
			{ 639.5F, 399.5F },                    // principal point position [px]
			{ 0.003F, 0.003F },                   // sensor resolution horiz./vert. [mm/px]
			sensorOrientation,           // Sensor orientation
										 // define valid sensor area in pixels (upper left, lower right point)
			{ 0.0F, 0.0F },
			{ camCfg->orig_x, camCfg->orig_y }
		});
		m_VirtualPinhole.updateConfig_v({ {
				// Top View Camera position in world coordinates
			{ static_cast<float32_t>(camCfg->VirtualdeltaX)  , static_cast<float32_t>(camCfg->VirtualdeltaY), static_cast<float32_t>(camCfg->VirtualdeltaZ) },   // X Y and Z setup from configuration file
																														  // Euler angles Cylinder View always has hard coded orientation
			{
				mecl::math::toRadians_x(camCfg->Virtualang_alpha - 90.0F), // -> this makes your topView virtically aligned!
				mecl::math::toRadians_x(camCfg->Virtualang_beta),
				mecl::math::toRadians_x(camCfg->Virtualang_gamma) },

				cameraPreRoll,
				mecl::model::e_WorldToCamera
			},
			{ 1.0F, 1.0F,{ 0.0 , 0.0 } } });
	}
	else { // default is Cylinder View even if Fish eye
		m_VirtualPinhole.updateConfig_v({ {
				// Camera position in world coordinates
			{ camCfg->deltaX  , camCfg->deltaY, camCfg->deltaZ },   // X Y and Z setup from configuration file
																	// Euler angles Cylinder View always has hard coded orientation
			{
				mecl::math::toRadians_x(90.0F), // -> this makes your cylinder lens horizontally aligned!
				mecl::math::toRadians_x(0.0F),
				mecl::math::toRadians_x(0.0F) },

				cameraPreRoll,
				mecl::model::e_WorldToCamera
			},
			{ 1.0F, 1.0F,{ 0.0 , 0.0 } } });
	}
	m_virtualCam.setImager_v(m_VirtualPinhole);

	if (m_CameraType == Cylinder_VarScale)
	{
//		mecl::model::SensorVarScale<float32_t>::Config_s m_sensorVarCfg_s;            /* MECL var scale sensor configuration */
//		m_virtualCam.setLens_v(m_CylinderLens);
//		// Update sensor object with new sensor parameters.
//		// Move out to Configuration TBD
//		m_sensorVarCfg_s.sensorUniform_s =
//		{
//			// Pull Parameter from Configuration
//			{ camCfg->cylaxisX, camCfg->cylaxisY },                    // principal point position [px]
//			{ camCfg->cylZoomRatioX, camCfg->cylZoomRatioY },
///*
// *	{ 0.00274f , 0.00292f },
// *	sensor resolution horiz./vert. [mm/px]
// */
//			sensorOrientation,           // first pixel in upper left corner
//										 // define valid sensor area in pixels (upper left, lower right point)
//			{ 0.0F, 0.0F },
//			{ camCfg->orig_x, camCfg->orig_y }
//		};
//
//		// load the containing the variable
//		loadRearScale();
//		m_sensorVarCfg_s.varScaleBufferSize_u32 = REAR_SCALE_SIZE1;
//		m_sensorVarCfg_s.varScaleBuffer_px = g__Rear_Scale;
//		m_VarScaleCylinderLens.updateConfig_v(m_sensorVarCfg_s);
//		m_VarScaleCylinderLens.init_v();
//		m_virtualCam.setSensor_v(m_VarScaleCylinderLens);
	}
	else if (m_CameraType == Top_View)
	{
		m_virtualCam.setNoLens_v();
		m_virtualCam.setSensor_v(m_VirtualSensor);
	}
	else // default for (m_CameraType == MECL_Cylinder) and Fisheye
	{
		m_virtualCam.setLens_v(m_CylinderLens);
		m_virtualCam.setSensor_v(m_VirtualSensor);
	}

	if (m_CameraType == MECL_Normal)
	{
#if 1
		m_VirtualSensor.updateConfig_v({
			// Top View camera
			{ 639.5F, 399.5F },                    // principal point position [px]
			{ 0.003F, 0.003F },                   // sensor resolution horiz./vert. [mm/px]
			sensorOrientation,           // Sensor orientation
										 // define valid sensor area in pixels (upper left, lower right point)
			{ 0.0F, 0.0F },
			{ camCfg->orig_x, camCfg->orig_y }
		});
		float32_t x = camCfg->deltaX;
		float32_t y = camCfg->deltaY;
		float32_t z = camCfg->deltaZ;
#if 0//test
		if (abs(pSetting->norm.x) > 0.0F || abs(pSetting->norm.y) > 0.0F)
		{
			x = pSetting->norm.x;
			y = pSetting->norm.y;
			z = pSetting->norm.z;
/*
 *	float alpha_deg_temp = 0;
 */
		}
#endif //test		
		m_VirtualPinhole.updateConfig_v({ {
				// Top View Camera position in world coordinates
			{ x  , y, z},
			{
				mecl::math::toRadians_x(0.0F),//test
				mecl::math::toRadians_x(0.0F), // beta
				mecl::math::toRadians_x(0.0F) }, // gamma

				cameraPreRoll,
				mecl::model::e_WorldToCamera
			},
			{ 1.0F, 1.0F,{ 0.0 , 0.0 } } });
		
/*
 *	m_virtualCam.setLens_v(m_CylinderLens);
 */
		m_virtualCam.setNoLens_v();
		m_virtualCam.setSensor_v(m_VirtualSensor);
#else
		m_VirtualSensor.updateConfig_v({
			// Top View camera
			{ 639.5f, 399.5f },                    // principal point position [px]
			{ 0.003f, 0.003f },                   // sensor resolution horiz./vert. [mm/px]
			sensorOrientation,           // Sensor orientation
										 // define valid sensor area in pixels (upper left, lower right point)
			{ 0.0F, 0.0F },
			{ camCfg->orig_x, camCfg->orig_y }
		});
		m_VirtualPinhole.updateConfig_v({ {
				// Top View Camera position in world coordinates
			{ camCfg->deltaX  , camCfg->deltaY, camCfg->deltaZ },   // X Y and Z setup from configuration file
																	// Euler angles Cylinder View always has hard coded orientation
			{
				mecl::math::toRadians_x(70.0F),
/*
 *	mecl::math::toRadians_x(camCfg->ang_alpha),
 */
				mecl::math::toRadians_x(0.0F),
				mecl::math::toRadians_x(0.0F) },

				cameraPreRoll,
				mecl::model::e_WorldToCamera
			},
			{ 1.0F, 1.0F,{ 0.0 , 0.0 } } });
/*
 *	m_virtualCam.setLens_v(m_CylinderLens);
 */
		m_virtualCam.setNoLens_v();
		m_virtualCam.setSensor_v(m_VirtualSensor);
#endif
	}
	// create Single view instance yielding the projective model
	m_singleView.setRealCam_v(m_realCam);
	m_singleView.setSyntCam_v(m_virtualCam);

	CreateCameraMatricesMECL(CamIfo.P_MECL);			//PRQA S 3840
/*
 *	copy the P Matrix over to Global variable
 */
											 // setup of virtual Camera Parameters to be removed once MECL TopView working
	{
		CamIfo.VirtualImageX = imgW;
		CamIfo.VirtualImageY = imgH;
		CamIfo.VirtualaxisX = (static_cast<float32_t>(CamIfo.VirtualImageX - 1) / static_cast<float32_t>(2));
		CamIfo.VirtualaxisY = (static_cast<float32_t>(CamIfo.VirtualImageY - 1) / static_cast<float32_t>(2));
		CamIfo.Virtualang_alpha = camCfg->Virtualang_alpha;
		CamIfo.Virtualang_beta = camCfg->Virtualang_beta;
		CamIfo.Virtualang_gamma = camCfg->Virtualang_gamma;
		CamIfo.Virtualang_preroll = camCfg->Virtualang_preroll;
		CamIfo.VirtualdeltaX = camCfg->VirtualdeltaX;
		CamIfo.VirtualdeltaY = camCfg->VirtualdeltaY;
		CamIfo.VirtualdeltaZ = camCfg->VirtualdeltaZ;
		CamIfo.Virtualpixelsize = 0.003F;
		CamIfo.Virtualfocallength = camCfg->Virtualfocallength;
	}

	ret = (true);
	return ret;
}

void do_CameraParam::MatrixMultiple( const float32_t *pKernel, const float32_t *pKarmaVector, float32_t *pOutput )
{
    for( unsigned char r = 0; r < 3U; r++ )
    {
        float32_t sum = 0;
        for( unsigned char c = 0; c < 4U; c++ )
        {
            sum +=  pKernel[ r *4U + c ] *pKarmaVector[ c ];		//PRQA S 3706
        } /*Column loop*/
        pOutput[ r ] = sum;											//PRQA S 3706	
    } /*Row loop*/

}

void Camera::CreateCameraMatricesMECL(float32_t P_MECL[3][4])const
{
	// this code is used to extract the P Matrix
	// Add to functions
	m_realCam.getImager_rx().init_v();
	mecl::core::Matrix<float32_t, 3, 4> P(m_realCam.getImager_rx().getProjectionMatrix_rx());
	mecl::core::Matrix3x3<float32_t> KK;
	mecl::core::Matrix3x3<float32_t> KK1(m_realCam.getImager_rx().getKMatrix_x());
	KK.setZeros();

	mecl::core::Matrix3x3<float32_t> KK_1;

	KK(0, 0) = (1.0F / getPixelSize());
	KK(0, 2) = getAxisX();
	KK_1(0,0) = KK(0, 0);
	KK(1, 1) = KK_1(0, 0);
	KK(1, 2) = getAxisY();
	KK(2, 2) = 1.0F;

	P = KK.mmul(P);
	for (int32_t i = 0; i < 4; i++)
	{
		for (int32_t j = 0; j < 3; j++)
		{
			P_MECL[j][i] = P(j, i);
		}
	}
	//return;
}

//---------------------------------------------------------
// Project a 3D point from world coordinates to 2D image coordinates

Point2f do_CameraParam::ProjectTo2D( const Point3f& pt, bool warp, bool *warpError )
{
	Point2f Pt2D;
	Point2f Pt2Dtemp;

	Point2f ret = Pt2D;

	if (warpError)
	{
		*warpError = false;
	}

	mecl::core::Point4D<float32_t> i_WorldPos_rx;
	mecl::core::Point2D<float32_t> o_ImagePos_rx;

	i_WorldPos_rx.setPosX(pt.x);
	i_WorldPos_rx.setPosY(pt.y);
	i_WorldPos_rx.setPosZ(pt.z);
	i_WorldPos_rx.setW(1.0);
	if ((camera_param.m_CameraType == Camera::MECL_Cylinder) || 
		(camera_param.m_CameraType == Camera::Cylinder_VarScale) || 
		(camera_param.m_CameraType == Camera::Top_View )|| 
		(camera_param.m_CameraType == Camera::MECL_Normal ))
	{
		camera_param.m_virtualCam.applyFullProjection_v(i_WorldPos_rx, o_ImagePos_rx);
	}
	else if (camera_param.m_CameraType == Camera::MECL_Radial)
	{
		camera_param.m_realCam.applyFullProjection_v(i_WorldPos_rx, o_ImagePos_rx);
	}
	else
	{
		Assert("Invalid Camera option for meclWorldToImage function");
	}
	Pt2Dtemp.x = o_ImagePos_rx.getPosX();
	Pt2Dtemp.y = o_ImagePos_rx.getPosY();
    if (warp == false)
    {
		Pt2Dtemp.x = Pt2Dtemp.x / camera_param.downsamp_sensor.x;
		Pt2Dtemp.y = Pt2Dtemp.y / camera_param.downsamp_sensor.y;
		Pt2D = camera_param.pixel_unwarp( &Pt2Dtemp);
    }
    else 
	{
		Pt2D.x = Pt2Dtemp.x / camera_param.downsamp_sensor.x;
		Pt2D.y = Pt2Dtemp.y / camera_param.downsamp_sensor.y;
    }
	if (camera_param.m_CameraType == Camera::MECL_Normal)
	{
		if (warpError)
		{
			Point2d ax;
			ax.x = camera_param.m_VirtualSensor.getPpp_rx().getPosX();
			ax.y = camera_param.m_VirtualSensor.getPpp_rx().getPosY();
			if ((abs(Pt2Dtemp.x - ax.x) < 0.5f ) && (abs(Pt2Dtemp.y - ax.y) < 0.5f))
			{
				int32_t a = 0;
				a = a;
				*warpError = true;
				ret = Pt2D;
			}
#if 0
			switch (camera_id)
			{
			default:
				break;
			case Front:
				break;
			case Rear:
				if (abs(Pt2Dtemp.x - ax.x) < 1.0F || abs(Pt2Dtemp.y - ax.y) < 1.0F)
				{
					int a = 0;
					*warpError = true;
					return Pt2D;
				}
				break;
			case Left:
				if (abs(Pt2Dtemp.x - ax.x) < 1.0F || abs(Pt2Dtemp.y - ax.y) < 1.0F)
				{
					int a = 0;
					*warpError = true;
					return Pt2D;
				}
				break;
			case Right:
				if (abs(Pt2Dtemp.x - ax.x) < 1.0F || abs(Pt2Dtemp.y - ax.y) < 1.0F)
				{
					int a = 0;
					*warpError = true;
					return Pt2D;
				}
				break;
			}
#endif
		}

	}

	ret = Pt2D;
	return ret;
}

Point2f do_CameraParam::ProjectTo2DVirtual(const Point3f& pt)const
{
	Point2f Pt2D;
	mecl::core::Point4D<float32_t> i_WorldPos_rx;

	i_WorldPos_rx.setPosX(pt.x);
	i_WorldPos_rx.setPosY(pt.y);
	i_WorldPos_rx.setPosZ(pt.z);
	i_WorldPos_rx.setW(1.0);

	mecl::core::Point2D<float32_t> Image_pts;
	camera_param.m_virtualCam.applyFullProjection_v(i_WorldPos_rx, Image_pts);

	Pt2D.x = Image_pts.getPosX()/ camera_param.downsamp_sensor.x;
	Pt2D.y = Image_pts.getPosY()/ camera_param.downsamp_sensor.y;
	return Pt2D;
}

Point2f do_CameraParam::ProjectTo2D(const Point3f& pt, const float32_t i_P[3][4], bool warp)
{
	Point2f Pt2D;
	float32_t dist_vect[4] =
	{
		pt.x, pt.y, pt.z, 1.0F
	};
	float32_t temp_unwarp[3];
	MatrixMultiple(&i_P[0][0], dist_vect, temp_unwarp);									//PRQA S 3840
	Pt2D = Point2f(temp_unwarp[0] / temp_unwarp[2], temp_unwarp[1] / temp_unwarp[2]);

	if (warp == true)
	{
		Pt2D = camera_param.pixel_warp(Pt2D);
	}

	return Pt2D;
}

Point3f do_CameraParam::BackProjectTo3D(const Point2f& pt, bool unwarp)
{
	Point3f Pt3D;
	Point2f WorldPt = camera_param.unwarped_distance(pt, unwarp);
	Pt3D.x = WorldPt.x;
	Pt3D.y = WorldPt.y;
	Pt3D.z = 0;
	return Pt3D;
}
