//--------------------------------------------------------------------------
/// @file DataMcu.h
/// @brief Contains 
///
/// 
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Andrej Wagner (andrej.wagner@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef DATAMCU_H_
#define DATAMCU_H_

#include <string.h> // for memcpy
#include <mecl/core/MeclTypes.h>
#include <variants/Enums.h>

// PRQA S 2100 EOF // public members used here by design. All structs here should be considered POD

namespace shmdata
{

	enum ChmslCamReady_e
	{
		ChmslCam_Unavailable,
		ChmslCam_Syncing,
		ChmslCam_Ready
	};

	enum ResponseState_e
	{
		e_ResponsePositive = 1,
		e_ResponseDelayed = 0xFC,
		e_ResponseUndefError = 0xFD,
		e_ResponseNotSupportedParam = 0xFE,
		e_ResponseNotSupportedCANId = 0xFF
	};

	struct SendReceiveCntrl_s
	{
		SendReceiveCntrl_s()
			: requestedAt_u32(0)
			, respondedAt_u32(0)
			, responseState_e(e_ResponsePositive)
		{}

		uint32_t requestedAt_u32;
		uint32_t respondedAt_u32;
		ResponseState_e responseState_e;

		SendReceiveCntrl_s & operator=(const SendReceiveCntrl_s &i_data_rs)
		{
			if (this != &i_data_rs)
			{
				requestedAt_u32 = i_data_rs.requestedAt_u32;
				respondedAt_u32 = i_data_rs.respondedAt_u32;
				responseState_e = i_data_rs.responseState_e;
			}
			return *this;
		}

	private:
		SendReceiveCntrl_s(const SendReceiveCntrl_s& i_data_rs);
	};

	enum BistReqResp_e
	{
		e_StartBistRoutine = 0U,
		e_GetBistResults
	};

	struct McuBistControl_s
	{
		McuBistControl_s()
			: cntrl_s()
			, mcuCamId_u8(0U)
			, bistReqResp_u8(0U)
			, bistExecTime_u8(0U)
		{
		}

		SendReceiveCntrl_s cntrl_s;

		McuBistControl_s & operator=(const McuBistControl_s &i_data_rs)
		{
			if (this != &i_data_rs)
			{
				cntrl_s = i_data_rs.cntrl_s;
				mcuCamId_u8 = i_data_rs.mcuCamId_u8;
				bistReqResp_u8 = i_data_rs.bistReqResp_u8;
				bistExecTime_u8 = i_data_rs.bistExecTime_u8;
			}
			return *this;
		}

		uint8_t mcuCamId_u8;
		uint8_t bistReqResp_u8;
		uint8_t bistExecTime_u8;

	private:
		McuBistControl_s(const McuBistControl_s& i_data_rs);
	};

	struct McuScreen_s
	{
		McuScreen_s()
			: cntrl_s()
			, patternCntrl_s()
			, viewId_e(variants::e_ServiceHelper_E_HMIView_FRONT_TOP_ALL)
			, requestedPattern_CameraId_u8(0xFFU)
			, requestedPattern_PatternId_u8(0xFFU)
			, zoomFactor_u8(100U)
			, overlayGroupsSize_u8(0U)
		{
			memset(overlayData_au8, 0U, sizeof(overlayData_au8));
			memset(overlayGroups_au8, 0U, sizeof(overlayGroups_au8));
		}

		SendReceiveCntrl_s cntrl_s;
		SendReceiveCntrl_s patternCntrl_s;
		variants::ViewId_e viewId_e;
		static const uint32_t MaxNumCameras_u32 = 8U;
		uint8_t requestedPattern_CameraId_u8;
		uint8_t requestedPattern_PatternId_u8;

		uint8_t zoomFactor_u8;
		static const uint32_t MaxOverlayData_u32 = 8U;
		uint8_t overlayData_au8[MaxOverlayData_u32];
		static const uint32_t MaxByteOvlGrps_u32 = 32U;
		uint8_t overlayGroups_au8[MaxByteOvlGrps_u32];
		uint8_t overlayGroupsSize_u8;

		McuScreen_s & operator=(const McuScreen_s &i_data_rs)
		{
			if (this != &i_data_rs)
			{
				cntrl_s = i_data_rs.cntrl_s;
				patternCntrl_s = i_data_rs.patternCntrl_s;
				viewId_e = i_data_rs.viewId_e;
				overlayGroupsSize_u8 = i_data_rs.overlayGroupsSize_u8;
				requestedPattern_CameraId_u8 = i_data_rs.requestedPattern_CameraId_u8;
				requestedPattern_PatternId_u8 = i_data_rs.requestedPattern_PatternId_u8;
				zoomFactor_u8 = i_data_rs.zoomFactor_u8;

				memcpy(overlayData_au8, i_data_rs.overlayData_au8, sizeof(overlayData_au8));
				memcpy(overlayGroups_au8, i_data_rs.overlayGroups_au8, sizeof(overlayGroups_au8));
			}
			return *this;
		}

	private:
		McuScreen_s(const McuScreen_s& i_data_rs);
	};

	enum VersionId_e
	{
		e_VersionPs = 0,
		e_VersionPl,
		e_VersionCamera,
		e_VersionOsType,
		e_VersionOs,
		e_VersionUnknown
	};

	enum RequestControl_e
	{
		e_RequestCameras = 0,
		e_RequestVideoOut,
		e_RequestUnknown
	};

	enum ControlCameras_e
	{
		e_CamerasOff = 0,
		e_CamerasOn,
		e_CamerasUnkownControl
	};

	enum ControlVideoOut_e
	{
		e_VideoOff = 0,
		e_VideoOn,
		e_VideoUnknownControl
	};

	//Door and mirrors status flags
	enum DoorStatus_e
	{
		e_DoorFLStatus = 0x80,
		e_DoorFRStatus = 0x40,
		e_DoorRLStatus = 0x20,
		e_DoorRRStatus = 0x10,
		e_MirrorLStatus = 0x08,
		e_MirrorRStatus = 0x04,
		e_HoodStatus = 0x02,
		e_TrunklidStatus = 0x01
	};

	struct McuDLDStatus_s
	{
		McuDLDStatus_s()
			: cntrl_s()
			, DldStatus_u8()
		{}

		SendReceiveCntrl_s cntrl_s;
		uint8_t DldStatus_u8;
	};

	struct McuControl_s
	{
		McuControl_s()
			: cntrl_s()
			, cntrlErrorState_s()
			, cameraState_e(e_CamerasUnkownControl)
			, videoState_e(e_VideoUnknownControl)
		{}

		SendReceiveCntrl_s cntrl_s;
		SendReceiveCntrl_s cntrlErrorState_s;
		ControlCameras_e cameraState_e;
		ControlVideoOut_e videoState_e;
	};

	struct McuPlVersion_s
	{
		McuPlVersion_s()
			: cntrl_s()
			, Version_u32(0)
		{}

		SendReceiveCntrl_s cntrl_s;
		uint32_t Version_u32;

		McuPlVersion_s & operator=(const McuPlVersion_s &i_data_rs)
		{
			if (this != &i_data_rs)
			{
				cntrl_s = i_data_rs.cntrl_s;
				Version_u32 = i_data_rs.Version_u32;
			}
			return *this;
		}

	private:
		McuPlVersion_s(const McuPlVersion_s& i_data_rs);
	};

	struct McuPsVersion_s
	{
		McuPsVersion_s()
			: cntrl_s()
			, Version_u32(0)
		{}

		SendReceiveCntrl_s cntrl_s;
		uint32_t Version_u32;

		McuPsVersion_s & operator=(const McuPsVersion_s &i_data_rs)
		{
			if (this != &i_data_rs)
			{
				cntrl_s = i_data_rs.cntrl_s;
				Version_u32 = i_data_rs.Version_u32;
			}
			return *this;
		}
	private:
		McuPsVersion_s(const McuPsVersion_s &i_data_rs);

	};

	struct McuCameraVersion_s
	{
		McuCameraVersion_s()
			: cntrl_s()
			, Version_u32(0)
		{}

		SendReceiveCntrl_s cntrl_s;
		uint32_t Version_u32;

		McuCameraVersion_s & operator=(const McuCameraVersion_s &i_data_rs)
		{
			if (this != &i_data_rs)
			{
				cntrl_s = i_data_rs.cntrl_s;
				Version_u32 = i_data_rs.Version_u32;
			}
			return *this;
		}
	private:
		McuCameraVersion_s(const McuCameraVersion_s &i_data_rs);
	};

	struct McuOsVersion_s
	{
		McuOsVersion_s()
			: cntrl_s()
			, Version_u32(0)
		{}

		SendReceiveCntrl_s cntrl_s;
		uint32_t Version_u32;

		McuOsVersion_s & operator=(const McuOsVersion_s &i_data_rs)
		{
			if (this != &i_data_rs)
			{
				cntrl_s = i_data_rs.cntrl_s;
				Version_u32 = i_data_rs.Version_u32;
			}
			return *this;
		}
	private:
		McuOsVersion_s(const McuOsVersion_s &i_data_rs);
	};

	struct McuOsTypeVersion_s
	{
		McuOsTypeVersion_s()
			: cntrl_s()
			, Version_u32(0)
		{}

		SendReceiveCntrl_s cntrl_s;
		uint32_t Version_u32;

		McuOsTypeVersion_s & operator=(const McuOsTypeVersion_s &i_data_rs)
		{
			if (this != &i_data_rs)
			{
				cntrl_s = i_data_rs.cntrl_s;
				Version_u32 = i_data_rs.Version_u32;
			}
			return *this;
		}
	private:
		McuOsTypeVersion_s(const McuOsTypeVersion_s &i_data_rs);
	};


	struct McuVehicleState_s
	{
		McuVehicleState_s()
			: cntrl_s()
			, vehicleLevel_f32(0)
			, steeringAngle_f32(0)
			, dayNightStatus_u8(0U)
			, gearInfo_u8(0U)
			, reserved2_u8(0U)
			, doorStatus_u8(0U)
			, pdcStatus_u32(0U)
			, vehicleSpeed_f32(0U)
			, trlAidEnable_b(false)
			, trlAidEnablePscm_b(false)
			, fifthWheelOrGooseneck_b(false)
			, trlrAnTrgtCalc_u8(0U)
			, trlrAnMxCalc_u8(0U)
			, trlrAnWarnCalc_u8(0U)
			, trlrHtchYawAn_u16(0U)
			, zeroOffsetAngle_s16(0U)
			, HtchToVehAxleL_Arbt_u16(0U)
			, HtchToTrlrAxleL_Arbt_u16(0U)
		{}

		SendReceiveCntrl_s cntrl_s;
		float32_t vehicleLevel_f32;
		float32_t steeringAngle_f32;
		uint8_t dayNightStatus_u8;
		uint8_t gearInfo_u8;
		uint8_t reserved2_u8;
		uint8_t doorStatus_u8; //incl. doors, mirrors, trunklids and hoods (DoorStatus_e)
		uint32_t pdcStatus_u32;
		float32_t vehicleSpeed_f32;
		bool_t trlAidEnable_b;
		bool_t trlAidEnablePscm_b;
		bool_t fifthWheelOrGooseneck_b;
		uint8_t trlrAnTrgtCalc_u8;
		uint8_t trlrAnMxCalc_u8;
		uint8_t trlrAnWarnCalc_u8;
		uint16_t trlrHtchYawAn_u16;
		sint16_t zeroOffsetAngle_s16;
		uint16_t HtchToVehAxleL_Arbt_u16;
		uint16_t HtchToTrlrAxleL_Arbt_u16;

		McuVehicleState_s& operator=(const McuVehicleState_s& i_Other_ro)
		{
			if (this != &i_Other_ro)
			{
				cntrl_s = i_Other_ro.cntrl_s;
				vehicleLevel_f32 = i_Other_ro.vehicleLevel_f32;
				steeringAngle_f32 = i_Other_ro.steeringAngle_f32;
				dayNightStatus_u8 = i_Other_ro.dayNightStatus_u8;
				gearInfo_u8 = i_Other_ro.gearInfo_u8;
				reserved2_u8 = i_Other_ro.reserved2_u8;
				doorStatus_u8 = i_Other_ro.doorStatus_u8;
				pdcStatus_u32 = i_Other_ro.pdcStatus_u32;
				vehicleSpeed_f32 = i_Other_ro.vehicleSpeed_f32;
				trlAidEnable_b = i_Other_ro.trlAidEnable_b;
				trlAidEnablePscm_b = i_Other_ro.trlAidEnablePscm_b;
				fifthWheelOrGooseneck_b = i_Other_ro.fifthWheelOrGooseneck_b;
				trlrAnTrgtCalc_u8 = i_Other_ro.trlrAnTrgtCalc_u8;
				trlrAnMxCalc_u8 = i_Other_ro.trlrAnMxCalc_u8;
				trlrAnWarnCalc_u8 = i_Other_ro.trlrAnWarnCalc_u8;
				trlrHtchYawAn_u16 = i_Other_ro.trlrHtchYawAn_u16;
				zeroOffsetAngle_s16 = i_Other_ro.zeroOffsetAngle_s16;
				HtchToVehAxleL_Arbt_u16 = i_Other_ro.HtchToVehAxleL_Arbt_u16;
				HtchToTrlrAxleL_Arbt_u16 = i_Other_ro.HtchToTrlrAxleL_Arbt_u16;
			}
			return *this;
		}
	private:
		McuVehicleState_s(const McuVehicleState_s&);
	};

	enum McuLanguage_e
	{
		e_Lang_German,
		e_Lang_USEnglish,
		e_Lang_French,
		e_Lang_Italian,
		e_Lang_Spanish,
		e_Lang_Japenese,
		e_Lang_Portugese,
		e_Lang_Dutch,
		e_Lang_UKEnglish,
		e_Lang_Mandarin,
		e_Lang_Russian,
		e_Lang_Korean,
		e_Lang_Arabic,
		e_Lang_Brazilian,
		e_Lang_Mandarin_T,
		e_Lang_Hindi,
		e_Lang_Turkish,
		e_Lang_Polish,
		e_Lang_NoChg,
		e_Lang_Count
	};


	enum McuOutputResolution_e
	{
		e_OutputResolution720x480 = 0,
		e_OutputResolution640x480,
		e_OutputResolution1024x768,
		e_OutputResolution1280x800,
		e_OutputResolutionUnknown,
		e_OutputResolutionNotInitialized
	};

	struct McuDisplayConfig_s
	{
		McuDisplayConfig_s()
			: reserved7_b(false)
			, reserved6_b(false)
			, reserved5_b(false)
			, digitalOutput_b(false)
			, outputResolution_e(e_OutputResolutionUnknown) // 4 bits for output resolution
		{}

		bool_t reserved7_b;
		bool_t reserved6_b;
		bool_t reserved5_b;
		bool_t digitalOutput_b;
		McuOutputResolution_e outputResolution_e;
	};


	struct McuVariantCodingConfigBits_s
	{
		McuVariantCodingConfigBits_s()
			: reserved7_b(false)
			, reserved6_b(false)
			, reserved5_b(false)
			, reserved4_b(false)
			, reserved3_b(false)
			, armFailsafe_b(true)      // SAI_RoBer: ARM-Failsafe shall be activated by default (0x04U) according to task 1683349
			, debugFacilities_b(false)
			, driverPosition_b(false)
		{}

		bool_t reserved7_b;
		bool_t reserved6_b;
		bool_t reserved5_b;
		bool_t reserved4_b;
		bool_t reserved3_b;
		bool_t armFailsafe_b;
		bool_t debugFacilities_b;
		bool_t driverPosition_b;
	};

	struct McuVariantCodingData_s
	{
		McuVariantCodingData_s()
			: language_e(e_Lang_USEnglish),
			frameRate_u8(30U),
			flickerFrequency_u8(60U),
			displayConfig_s(),
			configBits_s()
		{}

		McuLanguage_e language_e;
		uint8_t frameRate_u8;
		uint8_t flickerFrequency_u8;
		McuDisplayConfig_s displayConfig_s;
		McuVariantCodingConfigBits_s configBits_s;
	};


	struct McuVariantCodingCntrl_s
	{
		SendReceiveCntrl_s cntrl_s;
		McuVariantCodingData_s data_s;
	};

	enum AlgoType_e
	{
		e_EndOfLineCalibration = 0,
		e_ObjectDetection,
		e_OnlineCalibration,
		e_Camera,
		e_ApplyCalibrationData,
		e_TrailerAngleDetection,
		e_ViewDataGeneration,
		e_ColorControlFunction,
		e_CameraDescriptorGenerator,
		e_EndOfLineCalibrationChmsl,
		e_AlgoCount
	};

	enum AlgoCommand_e
	{
		e_Start = 0,
		e_Stop,
		e_Pause,
		e_Status,
		e_Sync,
		e_GetResult,
		e_Resume,
		e_Set,
		e_Debug,
		e_Unknown                   // this must be the last entry ('VALID_COMMAND' < e_Unknown)
	};

	enum CamViewBlankStatus_e
	{
		e_CamViewNotBlanked = 0,
		e_CamViewBlanked,
		e_CamViewBlankedUndefined
	};

	struct VdgDebugParameters_s
	{
		VdgDebugParameters_s()
			: posGridX_s16(0)
			, posGridY_s16(0)
			, posGridZ_s16(0)
			, nColums_u8(0U)
			, nRows_u8(0U)
			, rectWidth_s16(0)
			, rectHeight_s16(0)
			, vdgDelay_u8(0U)
		{}

		sint16_t posGridX_s16;
		sint16_t posGridY_s16;
		sint16_t posGridZ_s16;
		uint8_t  nColums_u8;
		uint8_t  nRows_u8;
		sint16_t rectWidth_s16;
		sint16_t rectHeight_s16;
		uint8_t vdgDelay_u8;
	};

	/*struct ViewDataGenerationData_s
	{
		ViewDataGenerationData_s& operator=(const ViewDataGenerationData_s& i_data_rs)
		{
			if (this != &i_data_rs)
			{
				memcpy(camViewBlank_e, i_data_rs.camViewBlank_e, sizeof(camViewBlank_e));
			}
			return *this;
		}

		CamViewBlankStatus_e camViewBlank_e[prjcontainer::e_Fifth];
	}; */


	enum AlgoDebugMode_e
	{
		/*
		   COMMENT:
			  Added by Roman Berngardt (SAI_RoBer).
			  At the moment [2015-07-28 15:45] in the spec. it is defined as 0=ON and 1=OFF.
			  But after arrangement with Andres Knirsch it should be like that: 1=ON, 0=OFF
		*/
		e_AlgoDebugMode_Off = 0,
		e_AlgoDebugMode_On
	};

	enum AlgoDebugTypeCcf_e
	{
		AlgoDebugTypeCcf_Histogram = 0,
		AlgoDebugTypeCcf_GraystepsLinear,
		AlgoDebugTypeCcf_GraystepsGamma,
		AlgoDebugTypeCcf_ColourCheckerLinear,
		AlgoDebugTypeCcf_ColourCheckerGamma,
		AlgoDebugTypeCcf_ImageBorderCheck,
		AlgoDebugTypeCcf_Cnt // must be last element - only to check validity
	};

	enum AlgoDebugTypeVdg_e
	{
		AlgoDebugTypeVdg_Grid = 0,
		AlgoDebugTypeVdg_SetDelay,
		AlgoDebugTypeVdg_AnalyzeFOV,
		AlgoDebugTypeVdg_Cnt // must be last element - only to check validity
	};

	enum AlgoDebugTypeTad_e
	{
		AlgoDebugTypeTad_TargetWindow = 0,
		AlgoDebugTypeTad_InputImage,
		AlgoDebugTypeTad_InputImageWithBV,
		AlgoDebugTypeTad_Cnt // must be last element - only to check validity
	};

	enum AlgoDebugTypeEol_e
	{
		AlgoDebugTypeEOL_InputImageShownOnScreen = 0,
		AlgoDebugTypeEOL_ROIsShownOnScreen,
		AlgoDebugTypeEOL_InputImageSendOverPrivateCan,
		AlgoDebugTypeEol_Cnt // must be last element - only to check validity
	};

	enum AlgoDebugTypeEolCh_e
	{
		AlgoDebugTypeEolCh_InputImageShownOnScreen = 0,
		AlgoDebugTypeEolCh_BlobImageShownOnScreen,
		AlgoDebugTypeEolCh_Cnt // must be last element - only to check validity
	};

	enum AlgoDebugView_e
	{
		e_AlgoDebugViewNone = 0,
		e_AlgoDebugViewEol,
		e_AlgoDebugViewOd,
		e_AlgoDebugViewOc,
		e_AlgoDebugViewTad,
		e_AlgoDebugViewCcf,
		e_AlgoDebugViewVdg,
		e_AlgoDebugViewCam,
		e_AlgoDebugViewEolCh
	};

	enum ConfiguredCams_e
	{
		e_ConfiguredCams_AllCams = 0x1FU,
		e_ConfiguredCams_Fifth = 0x10U,
		e_ConfiguredCams_Right = 0x08U,
		e_ConfiguredCams_Rear = 0x04U,
		e_ConfiguredCams_Left = 0x02U,
		e_ConfiguredCams_Front = 0x01U,
		e_ConfiguredCams_NoCamera = 0x00U
	};

	struct AlgoManagerData_s
	{
		AlgoManagerData_s()
			: algoDebugView_e(e_AlgoDebugViewNone)
			, algoDebugTypeCcf_e(AlgoDebugTypeCcf_Histogram)
			, algoDebugTypeTad_e(AlgoDebugTypeTad_TargetWindow)
			, algoDebugTypeVdg_e(AlgoDebugTypeVdg_Grid)
			, algoDebugTypeEol_e(AlgoDebugTypeEOL_InputImageShownOnScreen)
			, algoDebugTypeEolCh_e()
		{
		}

		AlgoManagerData_s& operator=(const AlgoManagerData_s& i_data_rs)
		{
			if (this != &i_data_rs)
			{
				algoDebugView_e = i_data_rs.algoDebugView_e;
				algoDebugTypeCcf_e = i_data_rs.algoDebugTypeCcf_e;
				algoDebugTypeTad_e = i_data_rs.algoDebugTypeTad_e;
				algoDebugTypeVdg_e = i_data_rs.algoDebugTypeVdg_e;
				algoDebugTypeEol_e = i_data_rs.algoDebugTypeEol_e;
			}
			return *this;
		}

		AlgoDebugView_e algoDebugView_e;
		AlgoDebugTypeCcf_e algoDebugTypeCcf_e;
		AlgoDebugTypeTad_e algoDebugTypeTad_e;
		AlgoDebugTypeVdg_e algoDebugTypeVdg_e;
		AlgoDebugTypeEol_e algoDebugTypeEol_e;
		AlgoDebugTypeEolCh_e algoDebugTypeEolCh_e;
	};


	struct CalibrationData_s
	{
		CalibrationData_s& operator=(const CalibrationData_s& i_data_rs)
		{
			if (this != &i_data_rs)
			{
				Pitch_f32 = i_data_rs.Pitch_f32;
				Yaw_f32 = i_data_rs.Yaw_f32;
				Roll_f32 = i_data_rs.Roll_f32;
				X_f32 = i_data_rs.X_f32;
				Y_f32 = i_data_rs.Y_f32;
				Z_f32 = i_data_rs.Z_f32;
			}
			return *this;
		}

		float32_t Pitch_f32; //in degrees
		float32_t Yaw_f32; //in degrees
		float32_t Roll_f32; //in degrees
		float32_t X_f32; //in mm
		float32_t Y_f32; //in mm
		float32_t Z_f32; //in mm
	};

	struct TadInData_s
	{
		uint8_t   RequestedMode_u8;         //Requested Tad_Mode from MCU 1=Setup, 2=Tracking, (0=Off) -> corresponds to RequestedMode_t in TadTypesInternal.h
		uint8_t   maxPNRAngle_u8;           //Max PNR angle [degree]    //Needed for UTT only
		uint8_t   templatePatternID_u8;     //Stored Template PatternID -> Needed for Tracking
		uint8_t   unused0_u8;
		float32_t aPlate2Ballmm_f32;        //A-UserMeasurement         //Needed for TAD&UTT
		float32_t bBall2Trgtmm_f32;         //B-UserMeasurement
		float32_t cCam2Trgtmm_f32;          //C-UserMeasurement
		float32_t dBmpr2TrlrAxlemm_f32;     //D-UserMeasurement         //Needed for UTT only
		float32_t zeroOffsetAngle_f32;      //Stored Zero Offset Angle  //Needed for TAD&UTT
		uint8_t   acquisitionThreshold_u8;  //Threshold at which the Algo acquires the Target
		uint8_t   trackingThreshold_u8;     //Threshold where target gets dropped if confidence falls below (should be <= acquisitionThreshold)
		uint8_t   unused1_u8;
		uint8_t   unused2_u8;
		float32_t offsetPercCfg_f32;        //Method3 Parameter used by UTT coming from MCU
		float32_t warningAngleCfg_f32;      //Method3 Parameter used by UTT coming from MCU
		uint32_t  trailerLimitCfg_u32;      //Method3 Parameter used by UTT coming from MCU
	};

	struct CamMDebug_s
	{
		CamMDebug_s()
			: valid_b(false)
			, disableCheckCamToMemStatus_b(false)
			, disableCheckInitAndPower_b(false)
			, disableRestart_b(false)
			, unused0_u8(0U)
			, unused1_u8(0U)
			, unused2_u8(0U)
			, camToMemStatusThreshold_u32(0xFFFFFFFFU)
			, camMinRestartInterval_u32(0xFFFFFFFFU)
		{
		}
		bool_t valid_b;
		bool_t disableCheckCamToMemStatus_b;
		bool_t disableCheckInitAndPower_b;
		bool_t disableRestart_b;
		uint8_t unused0_u8;
		uint8_t unused1_u8;
		uint8_t unused2_u8;
		uint32_t camToMemStatusThreshold_u32;
		uint32_t camMinRestartInterval_u32;
	};

	/*struct McuAlgoControl_s
	{
		McuAlgoControl_s()
			: cntrl_s()
			, AlgoType_u8(0)
			, AlgoCommand_u8(0)
			, MCUCameraID_u8(0)
			, VirtualCameraId_u8(0)
			, ConfiguredCams_u8(static_cast<uint8_t>(shmdata::e_ConfiguredCams_AllCams))
			, targetDistance_u16(0U)
			, targetId_u16(0U)
			, algMData_s()
			, ispCcfCustomerDefinition_s()
			, ispCcfRunningStatusData_s()
			, cdgVirtualCameraParameters_s()
			, eolCameraMask_u8(0U)
			, cameraRegisterData_s()
			, cameraDebug_s()
		{
			memset(deltaCalibrationData_s, 0, sizeof(deltaCalibrationData_s));
			memset(deltaCalibrationDataUpdateFrameId_as, 0, sizeof(deltaCalibrationDataUpdateFrameId_as));
			memset(static_cast<void*>(&tadInData_s), 0, sizeof(tadInData_s));
			memset(static_cast<void*>(&vdgData_s), 0, sizeof(vdgData_s));
			memset(static_cast<void*>(&vdgDebugParams_s), 0, sizeof(vdgDebugParams_s));
		}

		McuAlgoControl_s& operator=(const McuAlgoControl_s& i_Other_ro)
		{
			if (this != &i_Other_ro)
			{
				cntrl_s = i_Other_ro.cntrl_s;
				AlgoType_u8 = i_Other_ro.AlgoType_u8;
				AlgoCommand_u8 = i_Other_ro.AlgoCommand_u8;
				MCUCameraID_u8 = i_Other_ro.MCUCameraID_u8;
				VirtualCameraId_u8 = i_Other_ro.VirtualCameraId_u8;
				ConfiguredCams_u8 = i_Other_ro.ConfiguredCams_u8;
				targetDistance_u16 = i_Other_ro.targetDistance_u16;
				targetId_u16 = i_Other_ro.targetId_u16;
				// TODO: why memcpy - structs have assignment operator defined
				memcpy(deltaCalibrationData_s, i_Other_ro.deltaCalibrationData_s, sizeof(deltaCalibrationData_s));
				memcpy(static_cast<void*>(&tadInData_s), static_cast<const void*>(&i_Other_ro.tadInData_s), sizeof(tadInData_s));
				memcpy(static_cast<void*>(&vdgData_s), static_cast<const void*>(&i_Other_ro.vdgData_s), sizeof(vdgData_s));
				memcpy(static_cast<void*>(&deltaCalibrationDataUpdateFrameId_as[0]), static_cast<const void*>(&i_Other_ro.deltaCalibrationDataUpdateFrameId_as[0]), sizeof(deltaCalibrationDataUpdateFrameId_as));
				vdgDebugParams_s = i_Other_ro.vdgDebugParams_s;
				algMData_s = i_Other_ro.algMData_s;
				ispCcfCustomerDefinition_s = i_Other_ro.ispCcfCustomerDefinition_s;
				ispCcfRunningStatusData_s = i_Other_ro.ispCcfRunningStatusData_s;
				cdgVirtualCameraParameters_s = i_Other_ro.cdgVirtualCameraParameters_s;
				cameraRegisterData_s = i_Other_ro.cameraRegisterData_s;
				cameraDebug_s = i_Other_ro.cameraDebug_s;
				eolCameraMask_u8 = i_Other_ro.eolCameraMask_u8;
			}
			return *this;
		}

		SendReceiveCntrl_s cntrl_s;
		uint8_t AlgoType_u8;    ///<    AlgoType......0: EOL, 1: OD, 2: OC, 3: Camera
		uint8_t AlgoCommand_u8; ///<    AlgoCommand...0: Start, 1: Stop, 2: Pause, 3: Status, 4: Sync, 5: GetResult
		uint8_t MCUCameraID_u8; ///<    MCU Camera ID.....0: None, 1: Front, 2: Left, 3: Rear, 4: Right, 5: 5th
		uint8_t VirtualCameraId_u8;
		uint8_t ConfiguredCams_u8;
		CalibrationData_s deltaCalibrationData_s[C_CameraCount_u32];
		uint32_t deltaCalibrationDataUpdateFrameId_as[C_CameraCount_u32];
		uint16_t targetDistance_u16;
		uint16_t targetId_u16;
		TadInData_s tadInData_s;
		ViewDataGenerationData_s vdgData_s;
		VdgDebugParameters_s vdgDebugParams_s;
		AlgoManagerData_s algMData_s;
		IspCcfCustomerDefinition_s ispCcfCustomerDefinition_s;
		IspCcfRunningStatusData_s ispCcfRunningStatusData_s;
		CdgVirtualCameraParameters_s cdgVirtualCameraParameters_s;
		uint8_t eolCameraMask_u8;
		CameraRegisterData_s cameraRegisterData_s;
		CamMDebug_s cameraDebug_s;
	private:
		McuAlgoControl_s(const McuAlgoControl_s&);
	};
	*/
#if (CALIBRATION_DATA == CALIBRATION_FORD_P558) && defined(CALIBRATION_DATA)
	const CalibrationData_s designCalibrationData_s[C_CameraCount_u32] = {
																				 {62.90F, 0.0F, 0.0F, -922.28F, 0.0F, 907.16F}, //Front camera
																				 {47.40F, 26.10F, -174.92F, 974.40F, -1422.98F, 1444.86F}, //Left camera
																				 {59.10F, 0.0F, 0.0F, 4842.33F, 0.0F, 1417.32F}, //Rear camera
																				 {42.79F, -23.05F, -6.91F, 880.65F, 1034.04F, 1296.96F}, //Right camera
																				 {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F} //5th camera
	};
#elif (CALIBRATION_DATA == CALIBRATION_CHRYSLER_RU) && defined(CALIBRATION_DATA)
	const CalibrationData_s designCalibrationData_s[C_CameraCount_u32] = {
																				 {66.75F, 0.0F, 0.0F, -886.46F, 0.0F, 768.96F}, //Front camera
																				 {30.0F, 0.46F, -0.27F, 804.59F, -1125.89F, 1095.82F}, //Left camera
																				 {55.76F, 0.0F, 0.0F, 4156.29F, 0.0F, 988.17F}, //Rear camera
																				 {30.0F, -0.46F, -179.73F, 804.59F, 1125.89F, 1095.82F}, //Right camera
																				 {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F} //5th camera
	};
#else
//#error "undefined calibration data settings"
#endif

	struct McuBootState_s
	{
		McuBootState_s()
			: cntrl_s()
		{
		}

		McuBootState_s& operator=(const McuBootState_s& i_Other_ro)
		{
			if (this != &i_Other_ro)
			{
				cntrl_s = i_Other_ro.cntrl_s;
			}
			return *this;
		}

		SendReceiveCntrl_s cntrl_s;
	};

	struct McuDltState_s
	{
		McuDltState_s()
			: cntrl_s()
		{
		}

		McuDltState_s& operator=(const McuDltState_s& i_Other_ro)
		{
			if (this != &i_Other_ro)
			{
				cntrl_s = i_Other_ro.cntrl_s;
			}
			return *this;
		}

		SendReceiveCntrl_s cntrl_s;
	};

	enum ErrorCategory_e
	{
		e_ErrCamera = 0,
		e_ErrOthers,
		e_ErrorCategoryCount
	};

	struct ZynqErrorState_s
	{
		ZynqErrorState_s()
			: cntrl_s()
			, ErrorCategory_u8(0U)
		{
		}

		ZynqErrorState_s& operator = (const ZynqErrorState_s& i_Other_ro)
		{
			if (this != &i_Other_ro)
			{
				cntrl_s = i_Other_ro.cntrl_s;
				ErrorCategory_u8 = i_Other_ro.ErrorCategory_u8;
			}
			return *this;
		}

		SendReceiveCntrl_s cntrl_s;

		uint8_t ErrorCategory_u8;   ///<    ErrorCategory......0: Camera, 1: Others
	};


	struct ErrorMgrDebugState_s
	{
		ErrorMgrDebugState_s()
			: lastErrorGuid_u32(0U) {}

		uint32_t lastErrorGuid_u32;
	};


	struct McuNotSupportedCanId_s
	{
		McuNotSupportedCanId_s()
			: cntrl_s()
			, canId_u32(0)
		{}

		McuNotSupportedCanId_s& operator=(const McuNotSupportedCanId_s& i_Other_ro)
		{
			if (this != &i_Other_ro)
			{
				cntrl_s = i_Other_ro.cntrl_s;
				canId_u32 = i_Other_ro.canId_u32;
			}
			return *this;
		}
		SendReceiveCntrl_s cntrl_s;
		uint32_t canId_u32;
	};

	enum GpioState_e
	{
		e_GpioStateNotSet = 0,
		e_GpioStateSet,
		e_GpioStateUndefined
	};

	struct GpioData_s
	{
		GpioData_s() : v_Mio9(e_GpioStateUndefined)
		{}

		GpioData_s& operator = (const GpioData_s& i_Other_ro)
		{
			if (this != &i_Other_ro)
			{
				v_Mio9 = i_Other_ro.v_Mio9;
			}
			return *this;
		}

		GpioState_e v_Mio9;
	};

	struct CanErrorState_s
	{
		CanErrorState_s()
			: sendFailureCounter_u32(0U) {}
		uint32_t sendFailureCounter_u32;
	};

/*	struct CtrlErrorState_s
	{
		CtrlErrorState_s()
			: holdTime_u16(0U)
			, updateCounter_u16(0U)
		{
			memset(errDataCam_au8, 0U, sizeof(errDataCam_au8));
		}

		CtrlErrorState_s& operator=(const CtrlErrorState_s& i_Other_ro)
		{
			if (this != &i_Other_ro)
			{
				memcpy(errDataCam_au8, i_Other_ro.errDataCam_au8, sizeof(errDataCam_au8));
				holdTime_u16 = i_Other_ro.holdTime_u16;
				updateCounter_u16 = i_Other_ro.updateCounter_u16;
			}
			return *this;
		}

		uint8_t  errDataCam_au8[shmdata::C_CameraCount_u32];
		uint16_t holdTime_u16;
		uint16_t updateCounter_u16;

	private:
		CtrlErrorState_s(const CtrlErrorState_s&);
	};
	*/
	/// Function type used in debug functions
	enum CtrlDbgFunType_e
	{
		e_CtrlDbgNoOperation = 0U, ///< No debug function active
		/// Partition control: stops and restarts a partition
		/// Parameters:
		/// - u8: CtrlDbgFunPartCtrl_e
		/// - u8: prjcontainer::AppId_e
		e_CtrlDbgPartitionControl,
		e_CtrlDbgNumFunctionTypes       ///< Number of available functions
	};

	/// Sub-Functions available for partition control
	enum CtrlDbgFunPartCtrl_e
	{
		e_CtrlDbgAppStop = 0U,   ///< Stops a partition
		e_CtrlDbgAppRestart,     ///< Restarts a partition
		e_CtrlDbgAppNumCommands  ///< Number of available functions for partition control
	};

	/// Contains a debug function call
	struct CtrlDbgFunctions_s
	{
		CtrlDbgFunctions_s()
			: functionsType_e(e_CtrlDbgNoOperation)
			, sendReceiveCntrl_s()
		{
			memset(functionParams_u8, 0U, sizeof(functionParams_u8));
		}
		static const uint32_t c_MaxNumFunctionParams_u32 = 2UL;
		CtrlDbgFunType_e functionsType_e; ///< Defines the debug function type
		uint8_t          functionParams_u8[c_MaxNumFunctionParams_u32]; ///< Function parameters
		SendReceiveCntrl_s sendReceiveCntrl_s;
	};

	struct CamExpGainInduce_s
	{
		CamExpGainInduce_s()
			: 
			 holdTime_u16(0U)
			, updateCounter_u16(0U)
		{
		}

		uint16_t holdTime_u16;
		uint16_t updateCounter_u16;

	private:
		CamExpGainInduce_s(const CamExpGainInduce_s& i_Data_rs);
	};

	struct SigMStats_s
	{
		SigMStats_s() :
			lastMessageReceivedFrame_u32(0UL),
			lastMessageSentFrame_u32(0UL),
			loggingThreadExited_b(false),
			loggingThreadBusy_b(false)
		{
		}
		uint32_t lastMessageReceivedFrame_u32;
		uint32_t lastMessageSentFrame_u32;
		bool_t   loggingThreadExited_b;
		bool_t   loggingThreadBusy_b;
	};

	struct McuBbCanControl_s
	{
		static const uint32_t rtxsize = 1U;

		union RawData_s
		{
			uint8_t  rawData_au8[8];
			uint64_t rawData_u64;
		};

		struct McuBbCanMessage_s
		{
			uint32_t bbCanSig_au32[2];
			SendReceiveCntrl_s srCtrl_s;
			//0x91
			uint32_t TBAStat_u32;
			uint32_t TBAStatComStatus_u32;
			uint32_t SteeringWhlAngle_u32;
			uint32_t SteeringWhlAngleComStatus_u32;
			uint32_t VehYaw_u32;
			uint32_t VehYawComStatus_u32;
			uint32_t TrlrType_u32;
			uint32_t TrlrTypeComStatus_u32;
			uint32_t TrlrHtchYawAn_u32;
			uint32_t TrlrHtchYawAnComStatus_u32;
			//0x92
			uint32_t TrlrHtchYawStatComStatus_u32;
			uint32_t TrlrHtchYawStat_u32;
			uint32_t HtchToTrlrAxleL_u32;
			uint32_t HtchToTrlrAxleLComStatus_u32;
			uint32_t TrlrHtchYawAnRate_u32;
			uint32_t TrlrHtchYawAnRateComStatus_u32;
			uint32_t TrlrYawRate_u32;
			uint32_t TrlrYawWActlQf_u32;
			uint32_t TrlrYawRateComStatus_u32;
			uint32_t TmpltNoRq_u32;
			uint32_t TmpltNoRqComStatus_u32;
			uint32_t TrailerIdNo_u32;
			uint32_t TrailerIdNoComStatus_u32;
			//0x93
			uint32_t VehSpeedABS_u32;
			uint32_t VehSpeedABSComStatus_u32;
			uint32_t VehYawCompRate_u32;
			uint32_t VehYawCompRateComStatus_u32;
			uint32_t ExtVehDirStatLeft_u32;
			uint32_t ExtVehDirStatLeftComStatus_u32;
			uint32_t ExtVehDirStatRight_u32;
			uint32_t ExtVehDirStatRightComStatus_u32;
			//0x94
			uint32_t WheeltickFr_u32;
			uint32_t WheeltickRl_u32;
			uint32_t WheeltickRr_u32;
			uint32_t WheeltickFl_u32;
			uint32_t WheeltickFlComStatus_u32;
			uint32_t WheeltickRlComStatus_u32;
			uint32_t WheeltickFrComStatus_u32;
			uint32_t WheeltickRrComStatus_u32;
			uint32_t TrlrAnOffsetDirMemComStatus_u32;
			uint32_t TrlrAnOffsetDirMem_u32;
			uint32_t GearPosDActlInternal_u32;
			uint32_t GearPosDActlComStatus_u32;
			uint32_t FactoryCameraAlignmentComplete_u32;
			//0x95
			uint64_t TrlrSnsIdNo_u64;
			uint32_t TrlrSnsIdNoComStatus_u32;
			uint32_t TrailerAidEnableRawPSCM_u32;
			uint32_t TrlrAidEnblRawPSCMComStatus_u32;
			uint32_t FihSaveDtle_u32;
			uint32_t FihSaveTle_u32;
			uint32_t FihCalibrationModeFihTad_u32;
			uint32_t FihCalibrationModeYrTad_u32;

			McuBbCanMessage_s()
				: srCtrl_s()
				//0x91
				, TBAStat_u32(0U)
				, TBAStatComStatus_u32(0U)
				, SteeringWhlAngle_u32(0U)
				, SteeringWhlAngleComStatus_u32(0U)
				, VehYaw_u32(0U)
				, VehYawComStatus_u32(0U)
				, TrlrType_u32(0U)
				, TrlrTypeComStatus_u32(0U)
				, TrlrHtchYawAn_u32(0U)
				, TrlrHtchYawAnComStatus_u32(0U)
				//0x92
				, TrlrHtchYawStatComStatus_u32(0U)
				, TrlrHtchYawStat_u32(0U)
				, HtchToTrlrAxleL_u32(0U)
				, HtchToTrlrAxleLComStatus_u32(0U)
				, TrlrHtchYawAnRate_u32(0U)
				, TrlrHtchYawAnRateComStatus_u32(0U)
				, TrlrYawRate_u32(0U)
				, TrlrYawWActlQf_u32(0U)
				, TrlrYawRateComStatus_u32(0U)
				, TmpltNoRq_u32(0U)
				, TmpltNoRqComStatus_u32(0U)
				, TrailerIdNo_u32(0U)
				, TrailerIdNoComStatus_u32(0U)
				//0x93
				, VehSpeedABS_u32(0U)
				, VehSpeedABSComStatus_u32(0U)
				, VehYawCompRate_u32(0U)
				, VehYawCompRateComStatus_u32(0U)
				, ExtVehDirStatLeft_u32(0U)
				, ExtVehDirStatLeftComStatus_u32(0U)
				, ExtVehDirStatRight_u32(0U)
				, ExtVehDirStatRightComStatus_u32(0U)
				//0x94
				, WheeltickFr_u32(0U)
				, WheeltickRl_u32(0U)
				, WheeltickRr_u32(0U)
				, WheeltickFl_u32(0U)
				, WheeltickFlComStatus_u32(0U)
				, WheeltickRlComStatus_u32(0U)
				, WheeltickFrComStatus_u32(0U)
				, WheeltickRrComStatus_u32(0U)
				, TrlrAnOffsetDirMemComStatus_u32(0U)
				, TrlrAnOffsetDirMem_u32(0U)
				, GearPosDActlInternal_u32(0U)
				, GearPosDActlComStatus_u32(0U)
				, FactoryCameraAlignmentComplete_u32(0U)
				//0x95
				, TrlrSnsIdNo_u64(0U)
				, TrlrSnsIdNoComStatus_u32(0U)
				, TrailerAidEnableRawPSCM_u32(0U)
				, TrlrAidEnblRawPSCMComStatus_u32(0U)
				, FihSaveDtle_u32(0U)
				, FihSaveTle_u32(0U)
				, FihCalibrationModeFihTad_u32(0U)
				, FihCalibrationModeYrTad_u32(0U)
			{
				memset(bbCanSig_au32, 0, sizeof(bbCanSig_au32));
			}

		private:
			McuBbCanMessage_s(const McuBbCanMessage_s& aS_s);

		};

		struct McuBbCanFlags_s
		{
			union Flags_s
			{
				uint8_t  flags_au8[4];
				uint32_t flags_u32;
			};

			Flags_s            f_s;
			SendReceiveCntrl_s srCtrl_s;

			McuBbCanFlags_s() : srCtrl_s()
			{
				f_s.flags_u32 = 0;
			}

		private:
			McuBbCanFlags_s(const McuBbCanFlags_s& aS_s);
		};


		McuBbCanControl_s() : frt_s()
		{}

		McuBbCanMessage_s mrt_as[rtxsize];
		// For Flags
		McuBbCanFlags_s   frt_s;

	private:
		McuBbCanControl_s(const McuBbCanControl_s&);
	};

	struct McuCtrlDeserializer_s
	{
		McuCtrlDeserializer_s()
			:enFontCamDeserializer_u8(1U)
			, enLeftCamDeserializer_u8(1U)
			, enRearCamDeserializer_u8(1U)
			, enRightCamDeserializer_u8(1U)
		{
		}

		uint8_t          enFontCamDeserializer_u8;
		uint8_t          enLeftCamDeserializer_u8;
		uint8_t          enRearCamDeserializer_u8;
		uint8_t          enRightCamDeserializer_u8;

		SendReceiveCntrl_s sendReceiveCntrl_s;
	private:
		McuCtrlDeserializer_s(const McuCtrlDeserializer_s& i_Data_rs);
	};

	struct McuData_s
	{
		McuData_s()
			: screen_s()
			, vehicleState_s()
			, variantCoding_s()
			, plVersion_s()
			, psVersion_s()
			, cameraVersion_s()
			, osTypeVersion_s()
			, osVersion_s()
			, bootState_s()
			, dltState_s()
			, zynqErrorState_s()
			, errorMgrDebugState_s()
			, notSupportedCanId_s()
			, gpioData_s()
			, requestControl_s()
			, canErrorState_s()
			, ctrlDbgFunctions_s()
			, camExpGainInduce_s()
			, sigMStats_s()
			, ctrlDeserializer_s()
			, pbCanControl_s()
			, mcuBistControl_s()
			, DldStatus_s()
		{}

		McuScreen_s screen_s;
		McuVehicleState_s vehicleState_s;
		McuVariantCodingCntrl_s variantCoding_s;
		McuPlVersion_s plVersion_s;
		McuPsVersion_s psVersion_s;
		McuCameraVersion_s cameraVersion_s;
		McuOsTypeVersion_s osTypeVersion_s;
		McuOsVersion_s osVersion_s;
		McuBootState_s bootState_s;
		McuDltState_s dltState_s;
		ZynqErrorState_s zynqErrorState_s;
		ErrorMgrDebugState_s errorMgrDebugState_s;
		McuNotSupportedCanId_s notSupportedCanId_s;
		GpioData_s gpioData_s;
		McuControl_s requestControl_s;
		CanErrorState_s canErrorState_s;
		CtrlDbgFunctions_s ctrlDbgFunctions_s;
		CamExpGainInduce_s camExpGainInduce_s;
		SigMStats_s sigMStats_s;
		McuCtrlDeserializer_s ctrlDeserializer_s;
		McuBbCanControl_s pbCanControl_s;
		McuBistControl_s mcuBistControl_s;
		McuDLDStatus_s DldStatus_s;

	private:
		McuData_s(const McuData_s& i_data_rs);
	};

}

#endif /* DATAMCU_H_ */
