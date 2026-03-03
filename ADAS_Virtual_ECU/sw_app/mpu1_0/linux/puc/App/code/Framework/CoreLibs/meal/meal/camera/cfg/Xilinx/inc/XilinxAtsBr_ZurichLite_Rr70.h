#ifndef XILINX_CAMERA_CFG_H
#define XILINX_CAMERA_CFG_H

#include "CameraCfg.h"

class XilinxCamConfigOCFront : public ICameraCfg
{
public:
	XilinxCamConfigOCFront() {}
	~XilinxCamConfigOCFront() {}

	void loadCameraCfg() override
			{
		m_CameraCfg =
		{
				{
						'F',
						'r',
						'o',
						'n',
						't',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0'
				},
				{
						'A',
						't',
						's',
						'B',
						'r',
						'_',
						'C',
						'y',
						'l',
						'i',
						'n',
						'd',
						'e',
						'r',
						'_',
						'R',
						'r',
						'6',
						'0',
						'_',
						'V',
						'2',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0'
				},
				/*axisX =*/ 639.5f,
				/*axisY =*/ 399.5f,
				/*ang_alpha =*/ 76.54f,
				/*ang_beta =*/ 0.0,
				/*ang_gamma =*/ 0.0,
				/*ang_preroll =*/ 90.0000000f,
				/*deltaX =*/ -836.510986f,
				/*deltaY =*/ 0.0,
				/*deltaZ =*/ 727.817993f,
				/*pixelsize =*/ 0.003f,
				/*focallength =*/ 1.019f,
				/*m_CameraType =*/ Camera::MECL_Radial,
				/*m_LensSignature =*/ Camera::LSI_None,
				/*cylaxisX =*/ 639.5,
				/*cylaxisY =*/ 399.5,
				/*cylZoomRatioX =*/ 0.0225f,
				/*cylZoomRatioY =*/ 0.0225f,
				/*orig_x0=*/ 0.0,
				/*origin_y0*/ 0.0,
				/*orig_x =*/ 1280.0,
				/*orig_y =*/ 800.0,
				/*m_ConvertToCylinder =*/ //false,
				/*m_MECLParameterLoaded =*/ true,
				{
						{
								0.0f,
								0.979559777010553F,
								0.279356833570018F,
								-0.426373287393975F,
								0.348236163585701F,
								-0.0976234784800146F,
						},
						{
								0.0f,
								1.03807266986569F,
								-0.342661127877259F,
								0.486867182151686F,
								-0.332326887675378F,
								0.0790944973845599F,
						},
						/*elevationMaxCfg_x =*/ 90.0f
				},
				/*Virtualang_alpha =*/ 90.0000000f,
				/*Virtualang_beta =*/ 0.000000000f,
				/*Virtualang_gamma =*/ 0.000000000f,
				/*Virtualang_preroll =*/ 90.000000f,
				/*VirtualdeltaX =*/ -5500.00000f,
				/*VirtualdeltaY =*/ 0.000000000f,
				/*VirtualdeltaZ =*/ 6691.00000f,
				/*Virtualfocallength =*/ 0.895f
		};

			}

	const CameraCfg& getCameraCfg() override
			{
		return m_CameraCfg;
			}
	void setCameraCfg(mecl::Pinhole_t::Config_s *i_DesignPinHoleCfg,sensor::Pinhole_t::Config_s *i_PinholeCfg, sensor::LensRadial_t::Config_s  *i_LensRadialCfg_rs,
			sensor::Sensor_t::Config_s *i_SensorCfg_rs, variants::CalibrationTypeE_t i_calibrationType_e)
	{
		if(i_calibrationType_e == variants::e_CalibTypeOC)
		{
			m_CameraCfg.ang_alpha = mecl::math::toDegrees_x(i_DesignPinHoleCfg->extrinsic_s.eulerAngles_s.pitch_x);
			m_CameraCfg.ang_beta = mecl::math::toDegrees_x(i_DesignPinHoleCfg->extrinsic_s.eulerAngles_s.yaw_x);
			m_CameraCfg.ang_gamma = mecl::math::toDegrees_x(i_DesignPinHoleCfg->extrinsic_s.eulerAngles_s.roll_x);

			m_CameraCfg.deltaX = i_DesignPinHoleCfg->extrinsic_s.pos_x.cVal_ax[0];
			m_CameraCfg.deltaY = i_DesignPinHoleCfg->extrinsic_s.pos_x.cVal_ax[1];
			m_CameraCfg.deltaZ = i_DesignPinHoleCfg->extrinsic_s.pos_x.cVal_ax[2];

			if(i_DesignPinHoleCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll90){
				m_CameraCfg.ang_preroll = 90.0f;
			}
			else if (i_DesignPinHoleCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll180)
			{
				m_CameraCfg.ang_preroll = 180.0f;
			} else if(i_DesignPinHoleCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll270)
			{
				m_CameraCfg.ang_preroll = 270.0f;
			} else
			{
				m_CameraCfg.ang_preroll = 0.0f;
			}
			m_CameraCfg.axisX =i_SensorCfg_rs->pppCfg_x.cVal_ax[0];
			m_CameraCfg.axisY=i_SensorCfg_rs->pppCfg_x.cVal_ax[1];
			m_CameraCfg.focallength = i_PinholeCfg->intrinsic_s.foclX_x;
			m_CameraCfg.pixelsize =i_SensorCfg_rs->pszCfg_x.cVal_ax[0];
			memcpy(&m_CameraCfg.m_realLensCfg, i_LensRadialCfg_rs, sizeof(sensor::LensRadial_t::Config_s));
			m_CameraCfg.m_LensSignature = Camera::LSI_4063;
			m_CameraCfg.orig_x0 = 0;
			m_CameraCfg.orig_y0 = 0;
			m_CameraCfg.orig_x =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[0];
			m_CameraCfg.orig_y =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[1];
		}
      #if 0
		else if (i_calibrationType_e == variants::e_CalibTypeOC)
		{
			m_CameraCfg.ang_alpha = mecl::math::toDegrees_x(i_PinholeCfg->extrinsic_s.eulerAngles_s.pitch_x);
			m_CameraCfg.ang_beta = mecl::math::toDegrees_x(i_PinholeCfg->extrinsic_s.eulerAngles_s.yaw_x);
			m_CameraCfg.ang_gamma = mecl::math::toDegrees_x(i_PinholeCfg->extrinsic_s.eulerAngles_s.roll_x);

			m_CameraCfg.deltaX = i_PinholeCfg->extrinsic_s.pos_x.cVal_ax[0];
			m_CameraCfg.deltaY = i_PinholeCfg->extrinsic_s.pos_x.cVal_ax[1];
			m_CameraCfg.deltaZ = i_PinholeCfg->extrinsic_s.pos_x.cVal_ax[2];

			if(i_PinholeCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll90){
				m_CameraCfg.ang_preroll = 90.0f;
			}
			else if (i_PinholeCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll180)
			{
				m_CameraCfg.ang_preroll = 180.0f;
			} else if(i_PinholeCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll270)
			{
				m_CameraCfg.ang_preroll = 270.0f;
			} else
			{
				m_CameraCfg.ang_preroll = 0.0f;
			}
			m_CameraCfg.axisX =i_SensorCfg_rs->pppCfg_x.cVal_ax[0];
			m_CameraCfg.axisY=i_SensorCfg_rs->pppCfg_x.cVal_ax[1];
			m_CameraCfg.focallength = i_PinholeCfg->intrinsic_s.foclX_x;
			m_CameraCfg.pixelsize =i_SensorCfg_rs->pszCfg_x.cVal_ax[0];
			memcpy(&m_CameraCfg.m_realLensCfg, i_LensRadialCfg_rs, sizeof(sensor::LensRadial_t::Config_s));
			m_CameraCfg.m_LensSignature = Camera::LSI_4063;
			m_CameraCfg.orig_x0 = 0;
			m_CameraCfg.orig_y0 = 0;
			m_CameraCfg.orig_x =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[0];
			m_CameraCfg.orig_y =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[1];

		}
      #endif
	}
private:
	CameraCfg m_CameraCfg;
};

class XilinxCamConfigOCRear : public ICameraCfg
{
public:
	XilinxCamConfigOCRear() {}
	~XilinxCamConfigOCRear() {}

	void loadCameraCfg() override
			{
		m_CameraCfg =
		{
				{
						'R',
						'e',
						'a',
						'r',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0'
				},
				{
						'A',
						't',
						's',
						'B',
						'r',
						'_',
						'C',
						'y',
						'l',
						'i',
						'n',
						'd',
						'e',
						'r',
						'_',
						'R',
						'r',
						'6',
						'0',
						'_',
						'V',
						'2',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0'
				},
				/*axisX =*/ 638.700012f,
				/*axisY =*/ 393.200012f,
				/*ang_alpha =*/ 55.458f,
				/*ang_beta =*/ 0.0f,
				/*ang_gamma =*/ 0.0f,
				/*ang_preroll =*/ 270.0f,
				/*deltaX =*/ 3842.750977f,
				/*deltaY =*/ 76.199997f,
				/*deltaZ =*/ 1001.229004f,
				/*pixelsize =*/ 0.003f,
				/*focallength =*/ 1.019f,
				/*m_CameraType =*/ Camera::MECL_Radial,
				/*m_LensSignature =*/ Camera::LSI_None,
				/*cylaxisX =*/ 639.5,
				/*cylaxisY =*/ 299.5,
				/*cylZoomRatioX =*/ 0.00245f,
				/*cylZoomRatioY =*/ 0.00245f,
				/*orig_x0=*/ 0.0,
				/*origin_y0*/ 0.0,
				/*orig_x =*/ 1280.0,
				/*orig_y =*/ 800.0,
				/*m_ConvertToCylinder =*/ //false,
				/*m_MECLParameterLoaded =*/ true,
				{
						{
								0.000000000f,
								0.979559777010553,
								0.279356833570018,
								-0.426373287393975,
								0.348236163585701,
								-0.0976234784800146,
						},
						{
								0.000000000f,
								1.03807266986569,
								-0.342661127877259,
								0.486867182151686,
								-0.332326887675378,
								0.0790944973845599,
						},
						/*elevationMaxCfg_x =*/ 90.0f
				},
				/*Virtualang_alpha =*/ 90.0000000f,
				/*Virtualang_beta =*/ 0.000000000f,
				/*Virtualang_gamma =*/ 0.000000000f,
				/*Virtualang_preroll =*/ 270.000000f,
				/*VirtualdeltaX =*/ 8400.00000f,
				/*VirtualdeltaY =*/ 0.000000000f,
				/*VirtualdeltaZ =*/ 6691.00000f,
				/*Virtualfocallength =*/ 0.895f
		};

			}

	const CameraCfg& getCameraCfg() override
			{
		return m_CameraCfg;
			}

	void setCameraCfg(mecl::Pinhole_t::Config_s *i_DesignPinHoleCfg,sensor::Pinhole_t::Config_s *i_PinholeCfg, sensor::LensRadial_t::Config_s  *i_LensRadialCfg_rs,
			sensor::Sensor_t::Config_s *i_SensorCfg_rs, variants::CalibrationTypeE_t i_calibrationType_e)
	{
		if(i_calibrationType_e == variants::e_CalibTypeOC)
		{
			m_CameraCfg.ang_alpha = mecl::math::toDegrees_x(i_DesignPinHoleCfg->extrinsic_s.eulerAngles_s.pitch_x);
			m_CameraCfg.ang_beta = mecl::math::toDegrees_x(i_DesignPinHoleCfg->extrinsic_s.eulerAngles_s.yaw_x);
			m_CameraCfg.ang_gamma = mecl::math::toDegrees_x(i_DesignPinHoleCfg->extrinsic_s.eulerAngles_s.roll_x);

			m_CameraCfg.deltaX = i_DesignPinHoleCfg->extrinsic_s.pos_x.cVal_ax[0];
			m_CameraCfg.deltaY = i_DesignPinHoleCfg->extrinsic_s.pos_x.cVal_ax[1];
			m_CameraCfg.deltaZ = i_DesignPinHoleCfg->extrinsic_s.pos_x.cVal_ax[2];

			if(i_DesignPinHoleCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll90){
				m_CameraCfg.ang_preroll = 90.0f;
			}
			else if (i_DesignPinHoleCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll180)
			{
				m_CameraCfg.ang_preroll = 180.0f;
			} else if(i_DesignPinHoleCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll270)
			{
				m_CameraCfg.ang_preroll = 270.0f;
			} else
			{
				m_CameraCfg.ang_preroll = 0.0f;
			}
			m_CameraCfg.axisX =i_SensorCfg_rs->pppCfg_x.cVal_ax[0];
			m_CameraCfg.axisY=i_SensorCfg_rs->pppCfg_x.cVal_ax[1];
			m_CameraCfg.focallength = i_PinholeCfg->intrinsic_s.foclX_x;
			m_CameraCfg.pixelsize =i_SensorCfg_rs->pszCfg_x.cVal_ax[0];
			memcpy(&m_CameraCfg.m_realLensCfg, i_LensRadialCfg_rs, sizeof(sensor::LensRadial_t::Config_s));
			m_CameraCfg.m_LensSignature = Camera::LSI_4063;
			m_CameraCfg.orig_x0 = 0;
			m_CameraCfg.orig_y0 = 0;
			m_CameraCfg.orig_x =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[0];
			m_CameraCfg.orig_y =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[1];
		}
      #if 0
		else if(i_calibrationType_e == variants::e_CalibTypeOC)
		{
			m_CameraCfg.ang_alpha = mecl::math::toDegrees_x(i_PinholeCfg->extrinsic_s.eulerAngles_s.pitch_x);
			m_CameraCfg.ang_beta = mecl::math::toDegrees_x(i_PinholeCfg->extrinsic_s.eulerAngles_s.yaw_x);
			m_CameraCfg.ang_gamma = mecl::math::toDegrees_x(i_PinholeCfg->extrinsic_s.eulerAngles_s.roll_x);

			m_CameraCfg.deltaX = i_PinholeCfg->extrinsic_s.pos_x.cVal_ax[0];
			m_CameraCfg.deltaY = i_PinholeCfg->extrinsic_s.pos_x.cVal_ax[1];
			m_CameraCfg.deltaZ = i_PinholeCfg->extrinsic_s.pos_x.cVal_ax[2];

			if(i_PinholeCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll90){
				m_CameraCfg.ang_preroll = 90.0f;
			}
			else if (i_PinholeCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll180)
			{
				m_CameraCfg.ang_preroll = 180.0f;
			} else if(i_PinholeCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll270)
			{
				m_CameraCfg.ang_preroll = 270.0f;
			} else
			{
				m_CameraCfg.ang_preroll = 0.0f;
			}
			m_CameraCfg.axisX =i_SensorCfg_rs->pppCfg_x.cVal_ax[0];
			m_CameraCfg.axisY=i_SensorCfg_rs->pppCfg_x.cVal_ax[1];
			m_CameraCfg.focallength = i_PinholeCfg->intrinsic_s.foclX_x;
			m_CameraCfg.pixelsize =i_SensorCfg_rs->pszCfg_x.cVal_ax[0];
			memcpy(&m_CameraCfg.m_realLensCfg, i_LensRadialCfg_rs, sizeof(sensor::LensRadial_t::Config_s));
			m_CameraCfg.m_LensSignature = Camera::LSI_4063;
			m_CameraCfg.orig_x0 = 0;
			m_CameraCfg.orig_y0 = 0;
			m_CameraCfg.orig_x =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[0];
			m_CameraCfg.orig_y =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[1];

		}
      #endif
	}
private:
	CameraCfg m_CameraCfg;
};

class XilinxCamConfigOCLeft : public ICameraCfg
{
public:
	XilinxCamConfigOCLeft() {}
	~XilinxCamConfigOCLeft() {}

	void loadCameraCfg() override
			{
		m_CameraCfg =
		{
				{
						'L',
						'e',
						'f',
						't',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0'
				},
				{
						'A',
						't',
						's',
						'B',
						'r',
						'_',
						'C',
						'y',
						'l',
						'i',
						'n',
						'd',
						'e',
						'r',
						'_',
						'R',
						'r',
						'6',
						'0',
						'_',
						'V',
						'2',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0'
				},
				/*axisX =*/ 637.9f,
				/*axisY =*/ 394.0f,
				/*ang_alpha =*/ 21.093998f,
				/*ang_beta =*/ -6.081000f,
				/*ang_gamma =*/ -10.246001f,
				/*ang_preroll =*/ 180.0000000f,
				/*deltaX =*/ 1119.098999f,
				/*deltaY =*/ -1009.643982f,
				/*deltaZ =*/ 1135.845947f,
				/*pixelsize =*/ 0.003f,
				/*focallength =*/ 1.0f,
				/*m_CameraType =*/ Camera::MECL_Radial,
				/*m_LensSignature =*/ Camera::LSI_None,
				/*cylaxisX =*/ 639.50,
				/*cylaxisY =*/ 159.50,
				/*cylZoomRatioX =*/ 0.0425f,
				/*cylZoomRatioY =*/ 0.0425f,
				/*orig_x0=*/ 0.0,
				/*origin_y0*/ 0.0,
				/*orig_x =*/ 1280.0,
				/*orig_y =*/ 800.0,
				/*m_ConvertToCylinder =*/ //false,
				/*m_MECLParameterLoaded =*/ true,
				{
						{
								0.000000000f,
								0.979559777010553,
								0.279356833570018,
								-0.426373287393975,
								0.348236163585701,
								-0.0976234784800146,
						},
						{
								0.000000000f,
								1.03807266986569,
								-0.342661127877259,
								0.486867182151686,
								-0.332326887675378,
								0.0790944973845599
						},
						/*elevationMaxCfg_x =*/ 90.0f
				},
				/*Virtualang_alpha =*/ 90.0000000f,
				/*Virtualang_beta =*/ 0.000000000f,
				/*Virtualang_gamma =*/ 0.000000000f,
				/*Virtualang_preroll =*/ 180.000000f,
				/*VirtualdeltaX =*/ 0.00000f,
				/*VirtualdeltaY =*/ -5250.00000f,
				/*VirtualdeltaZ =*/ 6691.00000f,
				/*Virtualfocallength =*/ 0.895f
		};

			}

	const CameraCfg& getCameraCfg() override
			{
		return m_CameraCfg;
			}
	void setCameraCfg(mecl::Pinhole_t::Config_s *i_DesignPinHoleCfg,sensor::Pinhole_t::Config_s *i_PinholeCfg, sensor::LensRadial_t::Config_s  *i_LensRadialCfg_rs,
			sensor::Sensor_t::Config_s *i_SensorCfg_rs, variants::CalibrationTypeE_t i_calibrationType_e)
	{
		if(i_calibrationType_e == variants::e_CalibTypeOC)
		{
			m_CameraCfg.ang_alpha = mecl::math::toDegrees_x(i_DesignPinHoleCfg->extrinsic_s.eulerAngles_s.pitch_x);
			m_CameraCfg.ang_beta = mecl::math::toDegrees_x(i_DesignPinHoleCfg->extrinsic_s.eulerAngles_s.yaw_x);
			m_CameraCfg.ang_gamma = mecl::math::toDegrees_x(i_DesignPinHoleCfg->extrinsic_s.eulerAngles_s.roll_x);

			m_CameraCfg.deltaX = i_DesignPinHoleCfg->extrinsic_s.pos_x.cVal_ax[0];
			m_CameraCfg.deltaY = i_DesignPinHoleCfg->extrinsic_s.pos_x.cVal_ax[1];
			m_CameraCfg.deltaZ = i_DesignPinHoleCfg->extrinsic_s.pos_x.cVal_ax[2];

			if(i_DesignPinHoleCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll90){
				m_CameraCfg.ang_preroll = 90.0f;
			}
			else if (i_DesignPinHoleCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll180)
			{
				m_CameraCfg.ang_preroll = 180.0f;
			} else if(i_DesignPinHoleCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll270)
			{
				m_CameraCfg.ang_preroll = 270.0f;
			} else
			{
				m_CameraCfg.ang_preroll = 0.0f;
			}
			m_CameraCfg.axisX =i_SensorCfg_rs->pppCfg_x.cVal_ax[0];
			m_CameraCfg.axisY=i_SensorCfg_rs->pppCfg_x.cVal_ax[1];
			m_CameraCfg.focallength = i_PinholeCfg->intrinsic_s.foclX_x;
			m_CameraCfg.pixelsize =i_SensorCfg_rs->pszCfg_x.cVal_ax[0];
			memcpy(&m_CameraCfg.m_realLensCfg, i_LensRadialCfg_rs, sizeof(sensor::LensRadial_t::Config_s));
			m_CameraCfg.m_LensSignature = Camera::LSI_4063;
			m_CameraCfg.orig_x0 = 0;
			m_CameraCfg.orig_y0 = 0;
			m_CameraCfg.orig_x =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[0];
			m_CameraCfg.orig_y =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[1];
		}
      #if 0
		else if(i_calibrationType_e == variants::e_CalibTypeOC)
		{
			m_CameraCfg.ang_alpha = mecl::math::toDegrees_x(i_PinholeCfg->extrinsic_s.eulerAngles_s.pitch_x);
			m_CameraCfg.ang_beta = mecl::math::toDegrees_x(i_PinholeCfg->extrinsic_s.eulerAngles_s.yaw_x);
			m_CameraCfg.ang_gamma = mecl::math::toDegrees_x(i_PinholeCfg->extrinsic_s.eulerAngles_s.roll_x);

			m_CameraCfg.deltaX = i_PinholeCfg->extrinsic_s.pos_x.cVal_ax[0];
			m_CameraCfg.deltaY = i_PinholeCfg->extrinsic_s.pos_x.cVal_ax[1];
			m_CameraCfg.deltaZ = i_PinholeCfg->extrinsic_s.pos_x.cVal_ax[2];

			if(i_PinholeCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll90){
				m_CameraCfg.ang_preroll = 90.0f;
			}
			else if (i_PinholeCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll180)
			{
				m_CameraCfg.ang_preroll = 180.0f;
			} else if(i_PinholeCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll270)
			{
				m_CameraCfg.ang_preroll = 270.0f;
			} else
			{
				m_CameraCfg.ang_preroll = 0.0f;
			}
			m_CameraCfg.axisX =i_SensorCfg_rs->pppCfg_x.cVal_ax[0];
			m_CameraCfg.axisY=i_SensorCfg_rs->pppCfg_x.cVal_ax[1];
			m_CameraCfg.focallength = i_PinholeCfg->intrinsic_s.foclX_x;
			m_CameraCfg.pixelsize =i_SensorCfg_rs->pszCfg_x.cVal_ax[0];
			memcpy(&m_CameraCfg.m_realLensCfg, i_LensRadialCfg_rs, sizeof(sensor::LensRadial_t::Config_s));
			m_CameraCfg.m_LensSignature = Camera::LSI_4063;
			m_CameraCfg.orig_x0 = 0;
			m_CameraCfg.orig_y0 = 0;
			m_CameraCfg.orig_x =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[0];
			m_CameraCfg.orig_y =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[1];
		}
      #endif
	}
private:
	CameraCfg m_CameraCfg;
};

class XilinxCamConfigOCRight: public ICameraCfg
{
public:
	XilinxCamConfigOCRight() {}
	~XilinxCamConfigOCRight() {}

	void loadCameraCfg() override
			{
		m_CameraCfg =
		{
				{
						'R',
						'i',
						'g',
						'h',
						't',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0'
				},
				{
						'A',
						't',
						's',
						'B',
						'r',
						'_',
						'C',
						'y',
						'l',
						'i',
						'n',
						'd',
						'e',
						'r',
						'_',
						'R',
						'r',
						'6',
						'0',
						'_',
						'V',
						'2',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0',
						'\0'
				},
				/*axisX =*/ 		641.499878f,
				/*axisY =*/ 		404.100006f,
				/*ang_alpha =*/		21.817001f,
				/*ang_beta =*/		2.046000f,
				/*ang_gamma =*/		-0.015000f,
				/*ang_preroll =*/	0.000000000f,
				/*deltaX =*/		1135.808960f,
				/*deltaY =*/		998.853027f,
				/*deltaZ =*/		1135.833984f,
				/*pixelsize =*/		0.003000000f,
				/*focallength =*/	1.0f,
				/*m_CameraType =*/ Camera::MECL_Radial,
				/*m_LensSignature =*/ Camera::LSI_None,
				/*cylaxisX =*/ 639.50,
				/*cylaxisY =*/ 159.50,
				/*cylZoomRatioX =*/ 0.0425f,
				/*cylZoomRatioY =*/ 0.0425f,
				/*orig_x0=*/ 0.0,
				/*origin_y0*/ 0.0,
				/*orig_x =*/ 1280.0,
				/*orig_y =*/ 800.0,
				/*m_ConvertToCylinder =*/ //false,
				/*m_MECLParameterLoaded =*/ true,
				{
						{
								0.000000000f,
								0.979559777010553,
								0.279356833570018,
								-0.426373287393975,
								0.348236163585701,
								-0.0976234784800146
						},
						{
								0.000000000f,
								1.03807266986569,
								-0.342661127877259,
								0.486867182151686,
								-0.332326887675378,
								0.0790944973845599
						},
						/*elevationMaxCfg_x =*/ 90.0f
				},
				/*Virtualang_alpha =*/ 90.0000000f,
				/*Virtualang_beta =*/ 0.000000000f,
				/*Virtualang_gamma =*/ 0.000000000f,
				/*Virtualang_preroll =*/ 0.000000f,
				/*VirtualdeltaX =*/ 799.000000f,
				/*VirtualdeltaY =*/		 5100.00000f,
				/*VirtualdeltaZ =*/		6691.00000f,
				/*Virtualfocallength =*/ 0.8950000f
		};

			}

	const CameraCfg& getCameraCfg() override
			{
		return m_CameraCfg;
			}
	void setCameraCfg(mecl::Pinhole_t::Config_s *i_DesignPinHoleCfg,sensor::Pinhole_t::Config_s *i_PinholeCfg, sensor::LensRadial_t::Config_s  *i_LensRadialCfg_rs,
			sensor::Sensor_t::Config_s *i_SensorCfg_rs, variants::CalibrationTypeE_t i_calibrationType_e)
	{
		if(i_calibrationType_e == variants::e_CalibTypeOC)
		{
			m_CameraCfg.ang_alpha = mecl::math::toDegrees_x(i_DesignPinHoleCfg->extrinsic_s.eulerAngles_s.pitch_x);
			m_CameraCfg.ang_beta = mecl::math::toDegrees_x(i_DesignPinHoleCfg->extrinsic_s.eulerAngles_s.yaw_x);
			m_CameraCfg.ang_gamma = mecl::math::toDegrees_x(i_DesignPinHoleCfg->extrinsic_s.eulerAngles_s.roll_x);

			m_CameraCfg.deltaX = i_DesignPinHoleCfg->extrinsic_s.pos_x.cVal_ax[0];
			m_CameraCfg.deltaY = i_DesignPinHoleCfg->extrinsic_s.pos_x.cVal_ax[1];
			m_CameraCfg.deltaZ = i_DesignPinHoleCfg->extrinsic_s.pos_x.cVal_ax[2];

			if(i_DesignPinHoleCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll90){
				m_CameraCfg.ang_preroll = 90.0f;
			}
			else if (i_DesignPinHoleCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll180)
			{
				m_CameraCfg.ang_preroll = 180.0f;
			} else if(i_DesignPinHoleCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll270)
			{
				m_CameraCfg.ang_preroll = 270.0f;
			} else
			{
				m_CameraCfg.ang_preroll = 0.0f;
			}
			m_CameraCfg.axisX =i_SensorCfg_rs->pppCfg_x.cVal_ax[0];
			m_CameraCfg.axisY=i_SensorCfg_rs->pppCfg_x.cVal_ax[1];
			m_CameraCfg.focallength = i_PinholeCfg->intrinsic_s.foclX_x;
			m_CameraCfg.pixelsize =i_SensorCfg_rs->pszCfg_x.cVal_ax[0];
			memcpy(&m_CameraCfg.m_realLensCfg, i_LensRadialCfg_rs, sizeof(sensor::LensRadial_t::Config_s));
			m_CameraCfg.m_LensSignature = Camera::LSI_4063;
			m_CameraCfg.orig_x0 = 0;
			m_CameraCfg.orig_y0 = 0;
			m_CameraCfg.orig_x =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[0];
			m_CameraCfg.orig_y =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[1];
		}
      #if 0
		else if(i_calibrationType_e == variants::e_CalibTypeOC)
		{
			m_CameraCfg.ang_alpha = mecl::math::toDegrees_x(i_PinholeCfg->extrinsic_s.eulerAngles_s.pitch_x);
			m_CameraCfg.ang_beta = mecl::math::toDegrees_x(i_PinholeCfg->extrinsic_s.eulerAngles_s.yaw_x);
			m_CameraCfg.ang_gamma = mecl::math::toDegrees_x(i_PinholeCfg->extrinsic_s.eulerAngles_s.roll_x);

			m_CameraCfg.deltaX = i_PinholeCfg->extrinsic_s.pos_x.cVal_ax[0];
			m_CameraCfg.deltaY = i_PinholeCfg->extrinsic_s.pos_x.cVal_ax[1];
			m_CameraCfg.deltaZ = i_PinholeCfg->extrinsic_s.pos_x.cVal_ax[2];

			if(i_PinholeCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll90){
				m_CameraCfg.ang_preroll = 90.0f;
			}
			else if (i_PinholeCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll180)
			{
				m_CameraCfg.ang_preroll = 180.0f;
			} else if(i_PinholeCfg->extrinsic_s.preRoll_e == mecl::model::e_PreRoll270)
			{
				m_CameraCfg.ang_preroll = 270.0f;
			} else
			{
				m_CameraCfg.ang_preroll = 0.0f;
			}
			m_CameraCfg.axisX =i_SensorCfg_rs->pppCfg_x.cVal_ax[0];
			m_CameraCfg.axisY=i_SensorCfg_rs->pppCfg_x.cVal_ax[1];
			m_CameraCfg.focallength = i_PinholeCfg->intrinsic_s.foclX_x;
			m_CameraCfg.pixelsize =i_SensorCfg_rs->pszCfg_x.cVal_ax[0];
			memcpy(&m_CameraCfg.m_realLensCfg, i_LensRadialCfg_rs, sizeof(sensor::LensRadial_t::Config_s));
			m_CameraCfg.m_LensSignature = Camera::LSI_4063;
			m_CameraCfg.orig_x0 = 0;
			m_CameraCfg.orig_y0 = 0;
			m_CameraCfg.orig_x =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[0];
			m_CameraCfg.orig_y =i_SensorCfg_rs->pos2Cfg_x.cVal_ax[1];
		}
      #endif
	}
private:
	CameraCfg m_CameraCfg;
};

#endif // ! XILINX_CAMERA_CFG_H
