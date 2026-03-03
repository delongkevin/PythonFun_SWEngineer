/*
 * XilinxAtsBr_Convert2Cylinder_Rr60_V2.h
 *
 *  Created on: Jul 4, 2017
 *      Author: Clayton.Bagnall
 *
 *  Last updated on: Mar. 09, 2018
 *  By: Yifan Wu
 *  Update: - update rear camera parameters
 *  		- added three other camera classes
 */

#ifndef XILINXATSBR_CONVERT2CYLINDER_RR60_V2_H_
#define XILINXATSBR_CONVERT2CYLINDER_RR60_V2_H_

#include "CameraCfg.h"

class XilinxCamConfigFront : public ICameraCfg
{
public:
	XilinxCamConfigFront() {}
	~XilinxCamConfigFront() {}

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
			/*axisX =*/ 641.42902f,
			/*axisY =*/ 400.96080f,
			/*ang_alpha =*/ 76.65f,
			/*ang_beta =*/ 4.f,
			/*ang_gamma =*/ 0.f,
			/*ang_preroll =*/ 90.0000000f,
			/*deltaX =*/ -736.f,
			/*deltaY =*/ -85.f,
			/*deltaZ =*/ 699.f,
			/*pixelsize =*/ 0.00300000003f,
			/*focallength =*/ 1.0f,
			/*m_CameraType =*/ Camera::MECL_Cylinder,
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
						0,
						1.0,
						0.42950873270609097,
						-0.6143106128893913,
						0.4548238082384679,
						-0.11969346030754849,
				},
				{
						0,
						0.983364762130637,
						-0.268905909222297,
						0.306996320959921,
						-0.185064956172137,
						0.0404273754063320,
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
	void setCameraCfg(sensor::Pinhole_t::Config_s *i_PinholeCfg, sensor::LensRadial_t::Config_s  *i_LensRadialCfg_rs,
			sensor::Sensor_t::Config_s *i_SensorCfg_rs)
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
private:
	CameraCfg m_CameraCfg;
};

class XilinxCamConfigRear : public ICameraCfg
{
public:
	XilinxCamConfigRear() {}
	~XilinxCamConfigRear() {}

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
			/*axisX =*/ 638.7f,
			/*axisY =*/ 393.2f,
			/*ang_alpha =*/ 52.9835f,
			/*ang_beta =*/ 0.16182f,
			/*ang_gamma =*/ -1.2052f,
			/*ang_preroll =*/ 270.0f,
			/*deltaX =*/ 3827.5117f,
			/*deltaY =*/ 84.6333f,
			/*deltaZ =*/ 1025.716f,
			/*pixelsize =*/ 0.003f,
			/*focallength =*/ 1.00f,
			/*m_CameraType =*/ Camera::MECL_Cylinder,
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
							0,
							0.979559777010553,
							0.279356833570018,
							-0.426373287393975,
							0.348236163585701,
							-0.0976234784800146

					},
					{
							0,
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

	void setCameraCfg(sensor::Pinhole_t::Config_s *i_PinholeCfg, sensor::LensRadial_t::Config_s  *i_LensRadialCfg_rs,
			sensor::Sensor_t::Config_s *i_SensorCfg_rs)
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
private:
	CameraCfg m_CameraCfg;
};

class XilinxCamConfigLeft : public ICameraCfg
{
public:
	XilinxCamConfigLeft() {}
	~XilinxCamConfigLeft() {}

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
			/*axisX =*/ 646.712524f,
			/*axisY =*/ 403.630188f,
			/*ang_alpha =*/ 44.0196062f,
			/*ang_beta =*/ 0.2745991f,
			/*ang_gamma =*/ 1.03916547f,
			/*ang_preroll =*/ 180.0000000f,
			/*deltaX =*/ 920.750000f,
			/*deltaY =*/ -1039.62500f,
			/*deltaZ =*/ 920.750000f,
			/*pixelsize =*/ 0.00300000003f,
			/*focallength =*/ 0.894999981f,
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
						1.04490995f,
						0.0749809965f,
						-0.148220003f,
						0.303386986f,
						-0.132219002f
				},
				{
						0.000000000f,
						0.949959993f,
						-0.00137399998f,
						-0.0634140000f,
						-0.0140869999f,
						0.0179110002f
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
			/*Virtualfocallength =*/ 0.894999981f
		};

	}

	const CameraCfg& getCameraCfg() override
	{
		return m_CameraCfg;
	}

private:
	CameraCfg m_CameraCfg;
};

class XilinxCamConfigRight: public ICameraCfg
{
public:
	XilinxCamConfigRight() {}
	~XilinxCamConfigRight() {}

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
			/*axisX =*/ 642.071594f,
			/*axisY =*/ 404.993286f,
			/*ang_alpha =*/ 44.22432398f,
			/*ang_beta =*/ -1.2589622f,
			/*ang_gamma =*/ -2.9152963f,
			/*ang_preroll =*/ 0.0000000f,
			/*deltaX =*/ 920.750000f,
			/*deltaY =*/ 1039.62500f,
			/*deltaZ =*/ 920.750000f,
			/*pixelsize =*/ 0.00300000003f,
			/*focallength =*/ 0.894999981f,
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
							1.04490995f,
							0.0749809965f,
							-0.148220003f,
							0.303386986f,
							-0.132219002f
					},
					{
							0.000000000f,
							0.949959993f,
							-0.00137399998f,
							-0.0634140000f,
							-0.0140869999f,
							0.0179110002f
					},
				/*elevationMaxCfg_x =*/ 90.0f
			},
			/*Virtualang_alpha =*/ 90.0000000f,
			/*Virtualang_beta =*/ 0.000000000f,
			/*Virtualang_gamma =*/ 0.000000000f,
			/*Virtualang_preroll =*/ 0.000000f,
			/*VirtualdeltaX =*/ 799.000000f,
			/*VirtualdeltaY =*/ 5100.00000f,
			/*VirtualdeltaZ =*/ 6691.00000f,
			/*Virtualfocallength =*/ 0.894999981f
		};

	}

	const CameraCfg& getCameraCfg() override
	{
		return m_CameraCfg;
	}

private:
	CameraCfg m_CameraCfg;
};

#endif /* XILINXATSBR_CONVERT2CYLINDER_RR60_V2_H_ */
