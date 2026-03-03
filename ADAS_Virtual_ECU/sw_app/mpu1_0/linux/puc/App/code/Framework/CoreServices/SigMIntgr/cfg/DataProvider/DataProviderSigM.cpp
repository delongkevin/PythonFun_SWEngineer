//--------------------------------------------------------------------------
/// @file DataProviderSigM.cpp
/// @brief Contains implementation of SigM DataProvider
///
/// DataProvider is an interface between SigM module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------


#include "DataProviderSigM.h"

#include <cfg/CamShm.h>

namespace sigm
{

DataProviderSigM::DataProviderSigM(container::IDataProvider& b_DataProvider_ro)
    		: IDataProviderSigM()
			  , dataProvider_ro(b_DataProvider_ro)
			  {
	memset(&requestEOLCmd_t, 0, sizeof(requestEOLCmd_t));
	memset(&responseEOLCmd_t, 0, sizeof(responseEOLCmd_t));
	memset(&requestOCCmd_t, 0, sizeof(requestOCCmd_t));
	memset(&responseOCCmd_t, 0, sizeof(responseOCCmd_t));
	memset(&requestSCCmd_t, 0, sizeof(requestSCCmd_t));
	memset(&responseSCCmd_t, 0, sizeof(responseSCCmd_t));
	CamDeserSerState_u8 = 0;
			  }

DataProviderSigM::~DataProviderSigM()
{
	// nothing to do here
}


//----------------------------------------------------------------------------------------
// // Data Input (only getter)
//---------------------------------------------------------------------------------------

uint32_t DataProviderSigM::getFrameID_u32() const
{
	return dataProvider_ro.getAppMData_po()->getFrameID_u32();
}

uint8_t DataProviderSigM::getBootState_u8() const
{
	return dataProvider_ro.getAppMData_po()->getBootState_u8();
}


uint8_t DataProviderSigM::getCameraShutdownState_u8() const
{
	return CamDeserSerState_u8;
}

MCU_TRAGateway1Request_t DataProviderSigM::getMCUTRAGateway1_t() const
{
	return dataProvider_ro.getSigMData_po()->getMCUTRAGateway1_t();
}

MCU_TRAGateway2Request_t DataProviderSigM::getMCUTRAGateway2_t() const
{
	return dataProvider_ro.getSigMData_po()->getMCUTRAGateway2_t();
}

MCU_TRAGateway3Request_t DataProviderSigM::getMCUTRAGateway3_t() const
{
	return dataProvider_ro.getSigMData_po()->getMCUTRAGateway3_t();
}

MCU_TRAGateway4Request_t DataProviderSigM::getMCUTRAGateway4_t() const
{
	return dataProvider_ro.getSigMData_po()->getMCUTRAGateway4_t();
}
MiscRequest_t DataProviderSigM::getMiscRequest_t() const
{
	return dataProvider_ro.getSigMData_po()->getMiscRequest_t();
}
#ifdef USE_REQUEST_AND_RESPONSE  
ScreenRequest_t DataProviderSigM::getScreenRequest_t() const
{
	return dataProvider_ro.getSigMData_po()->getScreenRequest_t();
}
#else
ScreenRequest_t DataProviderSigM::getScreenRequest_t(bool_t* o_receive_status_b_p ) const
{
	return dataProvider_ro.getSigMData_po()->getScreenRequest_t(o_receive_status_b_p);
}
#endif

TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t DataProviderSigM::getTbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(bool_t* o_receive_status_b_p ) const
{
	return dataProvider_ro.getSigMData_po()->getTbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(o_receive_status_b_p );
}

ScreenResponse_t DataProviderSigM::getScreenResponse_t() const
{
	return dataProvider_ro.getSigMData_po()->getScreenResponse_t();
}


TbSVS_e_SVSOutputToDiagMgrCamCalib_t DataProviderSigM::getTbSVS_e_SVSOutputToDiagMgrCamCalib_t() const
{
	return dataProvider_ro.getSigMData_po()->getTbSVS_e_SVSOutputToDiagMgrCamCalib_t();
}

MessageStatus_t DataProviderSigM::getMessageStatus_t(uint8_t i_index_u8) const
{
	return dataProvider_ro.getSigMData_po()->getMessageStatus_t(i_index_u8);
}


TRA_Data_Request_t DataProviderSigM::getTRAData_t() const
{
	return dataProvider_ro.getSigMData_po()->getTRAData_t();
}

TRA_Data_Response_t DataProviderSigM::getTRAresponse_t() const
{
	return dataProvider_ro.getSigMData_po()->getTRAResponse_t();
}

uint8_t DataProviderSigM::getTRAconfidence() const{
	return 0;
}

uint16_t DataProviderSigM::getTRAframeNumber() const{
	return 0;
}

uint8_t DataProviderSigM::getTRAState() const{
	return 0;
}

MCU_TRAGateway4Response_t DataProviderSigM::getMCU_TRAGateway4Response_t() const
{
	static MCU_TRAGateway4Response_t v_MCU_TRAResponse4;
	return v_MCU_TRAResponse4;
}

VehicleStateRequest_t DataProviderSigM::getVehicleState_s() const
{
	return dataProvider_ro.getSigMData_po()->getVehicleState_s();
}

const float32_t DataProviderSigM::getSoCTemperature_f32() const
{
	return dataProvider_ro.getSysMonData_po()->getCurrentSoCTemperature_f32();
}

ApplyConfigRequest_t DataProviderSigM::getApplyConfig_t() const
{
	return dataProvider_ro.getSigMData_po()->getApplyConfig_t();
}

sensor::CameraBase& DataProviderSigM::getCamera_ro(variants::Camera_t i_CameraId_t)
{
#if 0
	static sensor::CamShm v_Camera_s;
	return v_Camera_s;
#endif
    return dataProvider_ro.getCamMData_po()->getCamera_ro(i_CameraId_t);
}
bool_t DataProviderSigM::getCamDataInitStatus()
{
	return dataProvider_ro.getCamMData_po()->getCamDataInitStatus();
}

//----------------------------------------------------------------------------------------
// Data Output (only setter)
//----------------------------------------------------------------------------------------

void DataProviderSigM::setMCUTRAGateway1Request_v(const MCU_TRAGateway1Request_t& i_MCUTRAGateway1_rt)
{
	dataProvider_ro.getSigMData_po()->setMCUTRAGateway1Request_v(i_MCUTRAGateway1_rt);
}

void  DataProviderSigM::setMCUTRAGateway2Request_v(const MCU_TRAGateway2Request_t& i_MCUTRAGateway2_rt)
{
	dataProvider_ro.getSigMData_po()->setMCUTRAGateway2Request_v(i_MCUTRAGateway2_rt);
}

void  DataProviderSigM::setMCUTRAGateway3Request_v(const MCU_TRAGateway3Request_t& i_MCUTRAGateway3_rt)
{
	dataProvider_ro.getSigMData_po()->setMCUTRAGateway3Request_v(i_MCUTRAGateway3_rt);
}

void  DataProviderSigM::setMCUTRAGateway4Request_v(const MCU_TRAGateway4Request_t& i_MCUTRAGateway4_rt)
{
	dataProvider_ro.getSigMData_po()->setMCUTRAGateway4Request_v(i_MCUTRAGateway4_rt);
}

void  DataProviderSigM::setMiscRequest_v(const MiscRequest_t& i_MiscRequest_rt)
{
	dataProvider_ro.getSigMData_po()->setMiscRequest_v(i_MiscRequest_rt);
}

void DataProviderSigM::setScreenRequest_v(const ScreenRequest_t& i_Screen_s)
{
	dataProvider_ro.getSigMData_po()->setScreenRequest_v(i_Screen_s);
}

void DataProviderSigM::setScreenResponse_v(const ScreenResponse_t& i_ScreenResponse_rt)
{
	dataProvider_ro.getSigMData_po()->setScreenResponse_v(i_ScreenResponse_rt);
}

Svs_CamEepromDataArray_t DataProviderSigM::getSvs_CamEepromDataArray_t() const
{
  return dataProvider_ro.getSigMData_po()->getSvs_CamEepromDataArray_t();
}

void DataProviderSigM::setSvs_CamEepromDataArray_v(const Svs_CamEepromDataArray_t& i_Svs_CamEepromDataArray_t_rt)
{
   dataProvider_ro.getSigMData_po()->setSvs_CamEepromDataArray_v(i_Svs_CamEepromDataArray_t_rt);
}

void  DataProviderSigM::setTRARequest_v(const TRA_Data_Request_s& i_TRA_s)
{
	dataProvider_ro.getSigMData_po()->setTRARequest_v(i_TRA_s);
}

void DataProviderSigM::setVehicleState_s(const VehicleStateRequest_t& i_VehicleState_s)
{
	dataProvider_ro.getSigMData_po()->setVehicleState_v(i_VehicleState_s);
}

void DataProviderSigM::setApplyConfig_v(const ApplyConfigRequest_t& i_ApplyConfig_t)
{
	dataProvider_ro.getSigMData_po()->setApplyConfig_v(i_ApplyConfig_t);
}

sensor::CameraErrorData_t DataProviderSigM::getCameraErrorData_t(variants::Camera_t i_Cam_t)
{
	sensor::CameraBase& v_Camera_ro = getCamera_ro(i_Cam_t);

	return v_Camera_ro.getCameraErrorData_rt();
}

variants::Camera_t DataProviderSigM::getCalibrationCamera_t(void) const
{
	variants::Camera_t v_CalibrationCamera_t = variants::e_CameraInvalid;

	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		v_CalibrationCamera_t = v_SigMData_pt->getCalibrationCamera_t();
	}
	return v_CalibrationCamera_t;
}


void DataProviderSigM:: setCalibrationCamera_v(const variants::Camera_t i_CalibrationCamera_t)
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		v_SigMData_pt->setCalibrationCamera_v(i_CalibrationCamera_t);
	}
}



variants::CalibrationTypeE_t DataProviderSigM:: getCalibrationType_t(void) const
{
	variants::CalibrationTypeE_t i_CalibrationTypeE_t = variants::e_CalibTypeNONE;

	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		i_CalibrationTypeE_t = v_SigMData_pt->getCalibrationType_t();
	}
	return i_CalibrationTypeE_t;
}


void DataProviderSigM:: setCalibrationType_v(const variants::CalibrationTypeE_t i_CalibrationTypeE_t)
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		v_SigMData_pt->setCalibrationType_v(i_CalibrationTypeE_t);
	}
}

void DataProviderSigM:: setEOLRequest_v(const container::RequestEOLCmd_t& i_RequestEOLCmd_t)
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		v_SigMData_pt->setRequestEOLCmd_v(i_RequestEOLCmd_t);
	}
}

const container::RequestEOLCmd_t&  DataProviderSigM:: getEOLRequest_rt(void) const
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	const container::RequestEOLCmd_t& c_RequestEOLCmd_rt = ( v_SigMData_pt != NULL ) ? v_SigMData_pt->getRequestEOLCmd_rt() : requestEOLCmd_t;
	return c_RequestEOLCmd_rt;
}

void DataProviderSigM:: setEOLResponse_v(const container::ResponseEOLCmd_t* i_ResponseEOLCmd_t)
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		v_SigMData_pt->setResponseEOLCmd_v(i_ResponseEOLCmd_t);
	}
}

const bool_t DataProviderSigM::isEolAlgoTriggered_b(void) const
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	return v_SigMData_pt->isEolAlgoTriggered_b();
}

void DataProviderSigM:: setEolAlgoFinishedCmd_v(bool_t flag_b)
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		v_SigMData_pt->setEolAlgoFinishedCmd_v(flag_b);
	}
}

bool_t DataProviderSigM:: getEolAlgoFinishedCmd_b()
{
	bool_t flag_b = 0;
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		flag_b = v_SigMData_pt->getEolAlgoFinishedCmd_b();
	}
	return flag_b;
}


const container::ResponseEOLCmd_t*  DataProviderSigM:: getEOLResponse_rt(void) const
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	const container::ResponseEOLCmd_t* c_ResponseEOLCmd_rt = v_SigMData_pt->getResponseEOLCmd_rt();
	return c_ResponseEOLCmd_rt;
}

#if 0
// B-004
void DataProviderSigM::setHMIWrtDataScreen(uint8_t progFactor)
{
#ifndef _WINDOWS
const float32_t displayFactor = 1.0F;
// Color definition
const uint32_t v_ColGreen_u32 = 0x008000FFU;
const uint32_t v_ColWhite_u32 = 0xFFFFFFFFU;
const uint32_t v_ColBlack_u32 = 0x000000FFU;
const uint32_t v_ColBlue_u32 =  0x0000FFFFU;

//ScrFactor 1920:1080 -> 1280:720 = 1,5
		//Layout
		container::OvlDebugData::RectDscr_s v_TitleBar_s(18.0F/displayFactor,18.0F/displayFactor,1884.0F,150.0F/displayFactor,v_ColGreen_u32,0U,0U);
		container::OvlDebugData::RectDscr_s v_MainBar_s(18.0F/displayFactor,168.0F/displayFactor,1884.0F/displayFactor, 894.0F/displayFactor,v_ColWhite_u32,0U,0U);
		container::OvlDebugData::RectDscr_s v_Border_s(9.0F/displayFactor,9.0F/displayFactor,1902.0F/displayFactor,1062.0F/displayFactor,0U,v_ColBlack_u32,12U);

		//Progress Bar
		container::OvlDebugData::RectDscr_s v_VerBar_s(260.0F/displayFactor,850.0F/displayFactor,1400.0F/displayFactor,100.0F/displayFactor,v_ColWhite_u32,v_ColBlack_u32,2U);
		container::OvlDebugData::RectDscr_s v_ProgBar_s(260.0F/displayFactor,850.0F/displayFactor,(static_cast<float32_t>(progFactor))*(350.0F/displayFactor),100.0F/displayFactor,v_ColBlue_u32,0U,0U);

		// Text Heading
		uint8_t v_TitleTxt_au8[] = "View Data Writing(*)";
		container::OvlDebugData::TextDescr_s v_TitleText_s(v_TitleTxt_au8, 72.0F/displayFactor,72.0F/displayFactor,63.0F/displayFactor,sizeof(v_TitleTxt_au8),v_ColWhite_u32);

		// No definition for text dimensions
		uint8_t v_DetMarkStartTxt_au8[] = "Writing the view data.";
		container::OvlDebugData::TextDescr_s v_DetMarkStartTxt_s(v_DetMarkStartTxt_au8,580.0F/displayFactor, 242.0F/displayFactor,90.0F/displayFactor,sizeof(v_DetMarkStartTxt_au8),v_ColBlack_u32);
		uint8_t v_DetMarkStartTxt1_au8[] = "Do not turn off IG";
		container::OvlDebugData::TextDescr_s v_DetMarkStartTxt1_s(v_DetMarkStartTxt1_au8,632.0F/displayFactor, 489.0F/displayFactor,90.0F/displayFactor,sizeof(v_DetMarkStartTxt1_au8),v_ColBlack_u32);
		uint8_t v_DetMarkStartTxt2_au8[] = "until the view data writing is completed.";
		container::OvlDebugData::TextDescr_s v_DetMarkStartTxt2_s(v_DetMarkStartTxt2_au8,133.0F/displayFactor, 604.0F/displayFactor,90.0F/displayFactor,sizeof(v_DetMarkStartTxt2_au8),v_ColBlack_u32);
#endif
}
#endif
void DataProviderSigM:: setOCRequest_v(const container::RequestOCCmd_t& i_RequestOCCmd_t)
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		v_SigMData_pt->setRequestOCCmd_v(i_RequestOCCmd_t);
	}
}

const container::RequestOCCmd_t&  DataProviderSigM:: getOCRequest_rt(void) const
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	const container::RequestOCCmd_t& c_RequestOCCmd_rt = ( v_SigMData_pt != NULL ) ? v_SigMData_pt->getRequestOCCmd_rt() : requestOCCmd_t;
	return c_RequestOCCmd_rt;
}

void DataProviderSigM:: setOCResponse_v(const container::ResponseOCCmd_t& i_ResponseOCCmd_t)
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		v_SigMData_pt->setResponseOCCmd_v(i_ResponseOCCmd_t);
	}
}

const container::ResponseOCCmd_t&  DataProviderSigM:: getOCResponse_rt(void) const
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	const container::ResponseOCCmd_t& c_ResponseOCCmd_rt = ( v_SigMData_pt != NULL ) ? v_SigMData_pt->getResponseOCCmd_rt() : responseOCCmd_t;
	return c_ResponseOCCmd_rt;
}


void DataProviderSigM:: setSCRequest_v(const container::RequestSCCmd_t& i_RequestSCCmd_t)
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		v_SigMData_pt->setRequestEOLCmd_v(i_RequestSCCmd_t);
	}
}

const container::RequestSCCmd_t&  DataProviderSigM:: getSCRequest_rt(void) const
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	const container::RequestSCCmd_t& c_RequestSCCmd_rt = ( v_SigMData_pt != NULL ) ? v_SigMData_pt->getRequestEOLCmd_rt() : requestSCCmd_t;
	return c_RequestSCCmd_rt;
}

void DataProviderSigM:: setSCResponse_v(const container::ResponseSCCmd_t& i_ResponseSCCmd_t)
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		//v_SigMData_pt->setResponseEOLCmd_v(i_ResponseSCCmd_t);
	}
}

#if 0
const container::ResponseSCCmd_t&  DataProviderSigM:: getSCResponse_rt(void) const
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	//const container::ResponseSCCmd_t& c_ResponseSCCmd_rt = ( v_SigMData_pt != NULL ) ? v_SigMData_pt->getResponseEOLCmd_rt() : responseSCCmd_t;

	//return c_ResponseSCCmd_rt;
	return c_ResponseSCCmd_rt;
}
#endif

void DataProviderSigM:: setTEOLRequest_v(const container::RequestTEOLCmd_t& i_RequestTEOLCmd_t)
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		v_SigMData_pt->setRequestTEOLCmd_v(i_RequestTEOLCmd_t);
	}
}

const container::RequestTEOLCmd_t& DataProviderSigM::getTEOLRequest_rt(void) const
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	const container::RequestTEOLCmd_t& c_RequestTEOLCmd_rt = ( v_SigMData_pt != NULL ) ? v_SigMData_pt->getRequestTEOLCmd_rt() : requestTEOLCmd_t;
	return c_RequestTEOLCmd_rt;
}

void DataProviderSigM::setTEOLResponse_v(const container::ResponseTEOLCmd_t& i_ResponseTEOLCmd_t)
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	if ( v_SigMData_pt != NULL )
	{
		v_SigMData_pt->setResponseTEOLCmd_v(i_ResponseTEOLCmd_t);
	}
}

const container::ResponseTEOLCmd_t& DataProviderSigM::getTEOLResponse_rt(void) const
{
	container::SigMData_t* v_SigMData_pt = dataProvider_ro.getSigMData_po();
	Assert(v_SigMData_pt != NULL );
	const container::ResponseTEOLCmd_t& c_ResponseTEOLCmd_rt = ( v_SigMData_pt != NULL ) ? v_SigMData_pt->getResponseTEOLCmd_rt() : responseTEOLCmd_t;
	return c_ResponseTEOLCmd_rt;
}

void DataProviderSigM::setCameraCalibrationData_v(variants::Camera_t i_CameraId_t, const sensor::CalibrationData_t& i_CamCalibrationData_rt)
{
}

void DataProviderSigM::setCameraTestPattern_v(variants::Camera_t i_CameraId_t, variants::CamTestPattern_t i_PatternId_t)
{
}

void DataProviderSigM::setCameraDeviceRegister_v(variants::Camera_t i_CameraId_t, variants::CameraDevice_t i_CameraDevice_t, uint16_t i_RegisterAddress_u16, uint16_t i_RegisterValue_u16)
{
	sensor::CameraBase& v_Camera_ro = getCamera_ro(i_CameraId_t);
	if(v_Camera_ro.getCameraState_e() > sensor::e_CameraStateNotInitialized)
	{
		v_Camera_ro.getDevice_po(i_CameraDevice_t)->write_b(static_cast<uint32_t>(i_RegisterAddress_u16), reinterpret_cast<uint32_t*>(&i_RegisterValue_u16), 1);
	}
}

uint16_t DataProviderSigM::getCameraDeviceRegister_v(variants::Camera_t i_CameraId_t, variants::CameraDevice_t i_CameraDevice_t, uint16_t i_RegisterAddress_u16)
{
	uint16_t v_RegisterValue_u16 = 0;

	sensor::CameraBase& v_Camera_ro = getCamera_ro(i_CameraId_t);

	if(v_Camera_ro.getCameraState_e() > sensor::e_CameraStateNotInitialized)
	{
		switch(i_CameraDevice_t)
		{
		case variants::e_ImagerAS0149AT:
		{
			v_Camera_ro.getDevice_po(i_CameraDevice_t)->read_b(static_cast<uint32_t>(i_RegisterAddress_u16), reinterpret_cast<uint32_t*>(&v_RegisterValue_u16), sizeof(uint16_t));
			break;
		}
		case variants::e_DeserializerCXD4960ER:
		case variants::e_SerializerCXD4963ER:
		{
			uint8_t  v_RegisterValue_u8 = 0;
			v_Camera_ro.getDevice_po(i_CameraDevice_t)->read_b(static_cast<uint32_t>(i_RegisterAddress_u16), reinterpret_cast<uint32_t*>(&v_RegisterValue_u8), 1);
			v_RegisterValue_u16 = v_RegisterValue_u8;
			break;
		}
		default:
		{
			// do nothing
			break;
		}
		}
	}
	return v_RegisterValue_u16;
}

bool_t DataProviderSigM::setCameraPowerMode_b(variants::Camera_t i_CameraID_t, variants::CameraPowerMode_t i_CameraPowerMode_t)
{
	return getCamera_ro(i_CameraID_t).setPowerMode_b(i_CameraPowerMode_t);
}

void DataProviderSigM::setCameraShutdownState_u8(uint8_t i_Staus_t)
{
	CamDeserSerState_u8 = i_Staus_t;
}

void DataProviderSigM::setCameraSerializerPowerMode_v(variants::CameraPowerMode_t i_CameraPowerMode_t)
{
	switch(i_CameraPowerMode_t)
	{
	case variants::e_CameraPowerModeOn:
	{
		setCameraShutdownState_u8(0x00U); //Correct this nomenclature
		break;
	}
	case variants::e_CameraPowerModeOff:
	{
		setCameraShutdownState_u8(0x01U); // Correct this nomenclature
		break;
	}
	default:
		break;
	}
}

bsp::FpgaVersion_s DataProviderSigM::getPlVersion_s()
{
	return bsp::FpgaVersion_s();
}

void DataProviderSigM::setHmiSoftButtonStatus_v(variants::HmiSoftButton_t i_SoftButton_e,variants::HmiSoftButtonStatus_t i_Status_e)
{
	dataProvider_ro.getSigMData_po()->setHmiSoftButtonStatus_v(i_SoftButton_e,i_Status_e);
}

IKinematicData_t DataProviderSigM::getIKinematicData_t()
{
	return dataProvider_ro.getSigMData_po()->getIKinematicData_t();
}
void DataProviderSigM::setIKinematicData_v(const IKinematicData_t& i_IKinematicData_t)
{
	dataProvider_ro.getSigMData_po()->setIKinematicData_v(i_IKinematicData_t);
}

IJobPLDOutput_t DataProviderSigM::getIJobPLDOutput_t()
{
	return dataProvider_ro.getSigMData_po()->getIJobPLDOutput_t();
}
void DataProviderSigM::setIJobPLDOutput_v(const IJobPLDOutput_t& i_IJobPLDOutput_t)
{
	dataProvider_ro.getSigMData_po()->setIJobPLDOutput_v(i_IJobPLDOutput_t);
}

IParkingSlotInformation_t DataProviderSigM::getIParkingSlotInformation_t()
{
	return dataProvider_ro.getSigMData_po()->getIParkingSlotInformation_t();
}
void DataProviderSigM::setIParkingSlotInformation_v(const IParkingSlotInformation_t& i_IParkingSlotInformation_t)
{
	dataProvider_ro.getSigMData_po()->setIParkingSlotInformation_v(i_IParkingSlotInformation_t);
}

IFPAInfoToPLD_t DataProviderSigM::getIFPAInfoToPLD_t()
{
	return dataProvider_ro.getSigMData_po()->getIFPAInfoToPLD_t();
}
void DataProviderSigM::setIFPAInfoToPLD_v(const IFPAInfoToPLD_t& i_IFPAInfoToPLD_t)
{
	dataProvider_ro.getSigMData_po()->setIFPAInfoToPLD_v(i_IFPAInfoToPLD_t);
}

TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t DataProviderSigM::getTbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(bool_t *o_receive_status_b_p )
{
	return dataProvider_ro.getSigMData_po()->getTbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(o_receive_status_b_p);
}
void DataProviderSigM::setTbSVS_e_DiagMgrOutputToSVSCamCalibSM_v(const TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t& i_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_rt)
{
	dataProvider_ro.getSigMData_po()->setTbSVS_e_DiagMgrOutputToSVSCamCalibSM_v(i_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_rt);
}
TbSVS_e_SVSOutputToDiagMgrCamCalib_t DataProviderSigM::getTbSVS_e_SVSOutputToDiagMgrCamCalib_t()
{
	return dataProvider_ro.getSigMData_po()->getTbSVS_e_SVSOutputToDiagMgrCamCalib_t();
}
void DataProviderSigM::setTbSVS_e_SVSOutputToDiagMgrCamCalib_v(const TbSVS_e_SVSOutputToDiagMgrCamCalib_t& i_TbSVS_e_SVSOutputToDiagMgrCamCalib_rt)
{
	dataProvider_ro.getSigMData_po()->setTbSVS_e_SVSOutputToDiagMgrCamCalib_v(i_TbSVS_e_SVSOutputToDiagMgrCamCalib_rt);
}

MOT_Output DataProviderSigM::getMOT_Output_t()
{
	return dataProvider_ro.getSigMData_po()->getMOT_Output_t();
}
void DataProviderSigM::setMOT_Output_v(const MOT_Output& i_MOT_Output_rt)
{
	dataProvider_ro.getSigMData_po()->setMOT_Output_v(i_MOT_Output_rt);
}


ME_VehInp_to_IpcSignals_t DataProviderSigM::getME_VehInp_to_IpcSignals_t()
{
	return dataProvider_ro.getSigMData_po()->getME_VehInp_to_IpcSignals_t();
}
void DataProviderSigM::setME_VehInp_to_IpcSignals_v(const ME_VehInp_to_IpcSignals_t& i_ME_VehInp_to_IpcSignals_t_rt)
{
	dataProvider_ro.getSigMData_po()->setME_VehInp_to_IpcSignals_v(i_ME_VehInp_to_IpcSignals_t_rt);
}
ME_ProxiToMPU1_0_Def_t DataProviderSigM::getME_Proxi_to_IpcSignals_t()
{
	return dataProvider_ro.getSigMData_po()->getME_Proxi_to_IpcSignals_t();
}
void DataProviderSigM::setME_Proxi_to_IpcSignals_v(const ME_ProxiToMPU1_0_Def_t& i_ME_Proxi_to_IpcSignals_t_rt)
{
	dataProvider_ro.getSigMData_po()->setME_Proxi_to_IpcSignals_v(i_ME_Proxi_to_IpcSignals_t_rt);
}
SvsToTHADet_t DataProviderSigM::getSvsToTHADet_t()
{
	return dataProvider_ro.getSigMData_po()->getSvsToTHADet_t();
}
void DataProviderSigM::setSvsToTHADet_v(const SvsToTHADet_t& i_SvsToTHADet_t_rt)
{
	dataProvider_ro.getSigMData_po()->setSvsToTHADet_v(i_SvsToTHADet_t_rt);
}

SSM_2_0_CoreStatus DataProviderSigM::getSSM_2_0_CoreStatus()
{
	return dataProvider_ro.getSigMData_po()->getSSM_2_0_CoreStatus();
}
void DataProviderSigM::setSSM_2_0_CoreStatus_v(const SSM_2_0_CoreStatus& i_SSM_2_0_CoreStatus_rt)
{
	dataProvider_ro.getSigMData_po()->setSSM_2_0_CoreStatus_v(i_SSM_2_0_CoreStatus_rt);
}
SSM_2_1_CoreStatus DataProviderSigM::getSSM_2_1_CoreStatus()
{
	return dataProvider_ro.getSigMData_po()->getSSM_2_1_CoreStatus();
}
void DataProviderSigM::setSSM_2_1_CoreStatus_v(const SSM_2_1_CoreStatus& i_SSM_2_1_CoreStatus_rt)
{
	dataProvider_ro.getSigMData_po()->setSSM_2_1_CoreStatus_v(i_SSM_2_1_CoreStatus_rt);
}
TbTHASmVc_FeatureOutputs_t DataProviderSigM::getTbTHASmVc_FeatureOutputs_t()
{
	return dataProvider_ro.getSigMData_po()->getTbTHASmVc_FeatureOutputs_t();
}
void DataProviderSigM::setTbTHASmVc_FeatureOutputs_v(const TbTHASmVc_FeatureOutputs_t& i_TbTHASmVc_FeatureOutputs_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTbTHASmVc_FeatureOutputs_v(i_TbTHASmVc_FeatureOutputs_t_rt);
}
Detection_Inputs_from_TRSC_t DataProviderSigM::getDetection_Inputs_from_TRSC_t()
{
	return dataProvider_ro.getSigMData_po()->getDetection_Inputs_from_TRSC_t();
}
void DataProviderSigM::setDetection_Inputs_from_TRSC_v(const Detection_Inputs_from_TRSC_t& i_Detection_Inputs_from_TRSC_t_rt)
{
	dataProvider_ro.getSigMData_po()->setDetection_Inputs_from_TRSC_v(i_Detection_Inputs_from_TRSC_t_rt);
}
US_S_BlockageBit_t DataProviderSigM::getUS_S_BlockageBit_t()
{
	return dataProvider_ro.getSigMData_po()->getUS_S_BlockageBit_t();
}
void DataProviderSigM::setUS_S_BlockageBit_v(const US_S_BlockageBit_t& i_US_S_BlockageBit_t_rt)
{
	dataProvider_ro.getSigMData_po()->setUS_S_BlockageBit_v(i_US_S_BlockageBit_t_rt);
}
US_S_USSErrorDiagData_t DataProviderSigM::getUS_S_USSErrorDiagData_t()
{
	return dataProvider_ro.getSigMData_po()->getUS_S_USSErrorDiagData_t();
}
void DataProviderSigM::setUS_S_USSErrorDiagData_v(const US_S_USSErrorDiagData_t& i_US_S_USSErrorDiagData_t_rt)
{
	dataProvider_ro.getSigMData_po()->setUS_S_USSErrorDiagData_v(i_US_S_USSErrorDiagData_t_rt);
}
THARelated_ScreenReq_t DataProviderSigM::getTHARelated_ScreenReq_t()
{
	return dataProvider_ro.getSigMData_po()->getTHARelated_ScreenReq_t();
}
void DataProviderSigM::setTHARelated_ScreenReq_v(const THARelated_ScreenReq_t& i_THARelated_ScreenReq_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTHARelated_ScreenReq_v(i_THARelated_ScreenReq_t_rt);
}
ErrorMgr_ErrorCommPack_QNX_QM DataProviderSigM::getErrorMgr_ErrorCommPack_QNX_QM()
{
	return dataProvider_ro.getSigMData_po()->getErrorMgr_ErrorCommPack_QNX_QM();
}
void DataProviderSigM::setErrorMgr_ErrorCommPack_QNX_QM_v(const ErrorMgr_ErrorCommPack_QNX_QM& i_ErrorMgr_ErrorCommPack_QNX_QM_rt)
{
	dataProvider_ro.getSigMData_po()->setErrorMgr_ErrorCommPack_QNX_QM_v(i_ErrorMgr_ErrorCommPack_QNX_QM_rt);
}
TRSC_Inputs_from_TrailerDetection_t DataProviderSigM::getTRSC_Inputs_from_TrailerDetection_t()
{
	return dataProvider_ro.getSigMData_po()->getTRSC_Inputs_from_TrailerDetection_t();
}
void DataProviderSigM::setTRSC_Inputs_from_TrailerDetection_v(const TRSC_Inputs_from_TrailerDetection_t& i_TRSC_Inputs_from_TrailerDetection_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTRSC_Inputs_from_TrailerDetection_v(i_TRSC_Inputs_from_TrailerDetection_t_rt);
}
MeDLD_e_RrCamSts_t DataProviderSigM::getMeDLD_e_RrCamSts_t()
{
	return dataProvider_ro.getSigMData_po()->getMeDLD_e_RrCamSts_t();
}
void DataProviderSigM::setMeDLD_e_RrCamSts_v(const MeDLD_e_RrCamSts_t& i_MeDLD_e_RrCamSts_t_rt)
{
	dataProvider_ro.getSigMData_po()->setMeDLD_e_RrCamSts_v(i_MeDLD_e_RrCamSts_t_rt);
}

TbSVS_e_SVSCalibSMToAlgoCamCalib_t DataProviderSigM::getTbSVS_e_SVSCalibSMToAlgoCamCalib_t()
{
	return dataProvider_ro.getSigMData_po()->getTbSVS_e_SVSCalibSMToAlgoCamCalib_t();
}
void DataProviderSigM::setTbSVS_e_SVSCalibSMToAlgoCamCalib_v(const TbSVS_e_SVSCalibSMToAlgoCamCalib_t& i_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTbSVS_e_SVSCalibSMToAlgoCamCalib_v(i_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_rt);
}
TbSVS_e_SVSCalibAlgoToSMCamCalib_t DataProviderSigM::getTbSVS_e_SVSCalibAlgoToSMCamCalib_t()
{
	return dataProvider_ro.getSigMData_po()->getTbSVS_e_SVSCalibAlgoToSMCamCalib_t();
}
void DataProviderSigM::setTbSVS_e_SVSCalibAlgoToSMCamCalib_v(const TbSVS_e_SVSCalibAlgoToSMCamCalib_t& i_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTbSVS_e_SVSCalibAlgoToSMCamCalib_v(i_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_rt);
}
TbSVS_S_SVSCamCurrentCalibDataToNVM_t DataProviderSigM::getTbSVS_S_SVSCamCurrentCalibDataToNVM_t()
{
	return dataProvider_ro.getSigMData_po()->getTbSVS_S_SVSCamCurrentCalibDataToNVM_t();
}
void DataProviderSigM::setTbSVS_S_SVSCamCurrentCalibDataToNVM_v(const TbSVS_S_SVSCamCurrentCalibDataToNVM_t& i_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTbSVS_S_SVSCamCurrentCalibDataToNVM_v(i_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_rt);
}
TbSVS_S_SVSCamOCCalibDataToNVM_t DataProviderSigM::getTbSVS_S_SVSCamOCCalibDataToNVM_t()
{
	return dataProvider_ro.getSigMData_po()->getTbSVS_S_SVSCamOCCalibDataToNVM_t();
}
void DataProviderSigM::setTbSVS_S_SVSCamOCCalibDataToNVM_v(const TbSVS_S_SVSCamOCCalibDataToNVM_t& i_TbSVS_S_SVSCamOCCalibDataToNVM_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTbSVS_S_SVSCamOCCalibDataToNVM_v(i_TbSVS_S_SVSCamOCCalibDataToNVM_t_rt);
}
TbSVS_S_SVSCamSCCalibDataToNVM_t DataProviderSigM::getTbSVS_S_SVSCamSCCalibDataToNVM_t()
{
	return dataProvider_ro.getSigMData_po()->getTbSVS_S_SVSCamSCCalibDataToNVM_t();
}
void DataProviderSigM::setTbSVS_S_SVSCamSCCalibDataToNVM_v(const TbSVS_S_SVSCamSCCalibDataToNVM_t& i_TbSVS_S_SVSCamSCCalibDataToNVM_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTbSVS_S_SVSCamSCCalibDataToNVM_v(i_TbSVS_S_SVSCamSCCalibDataToNVM_t_rt);
}
TbSVS_S_SVSCamEOLCalibDataToNVM_t DataProviderSigM::getTbSVS_S_SVSCamEOLCalibDataToNVM_t()
{
	return dataProvider_ro.getSigMData_po()->getTbSVS_S_SVSCamEOLCalibDataToNVM_t();
}
void DataProviderSigM::setTbSVS_S_SVSCamEOLCalibDataToNVM_v(const TbSVS_S_SVSCamEOLCalibDataToNVM_t& i_TbSVS_S_SVSCamEOLCalibDataToNVM_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTbSVS_S_SVSCamEOLCalibDataToNVM_v(i_TbSVS_S_SVSCamEOLCalibDataToNVM_t_rt);
}

JobTHADetOutput_t DataProviderSigM::getJobTHADetOutput_t()
{
	return dataProvider_ro.getSigMData_po()->getJobTHADetOutput_t();
}
void DataProviderSigM::setJobTHADetOutput_v(const JobTHADetOutput_t& i_JobTHADetOutput_t_rt)
{
	dataProvider_ro.getSigMData_po()->setJobTHADetOutput_v(i_JobTHADetOutput_t_rt);
}

CalDataProvider_MPU_1_0_Def DataProviderSigM::getCalDataProvider_MPU_1_0_Def()
{
	return dataProvider_ro.getSigMData_po()->getCalDataProvider_MPU_1_0_Def();
}
void DataProviderSigM::setCalDataProvider_MPU_1_0_Def_v(const CalDataProvider_MPU_1_0_Def& i_CalDataProvider_MPU_1_0_Def_rt)
{
	dataProvider_ro.getSigMData_po()->setCalDataProvider_MPU_1_0_Def_v(i_CalDataProvider_MPU_1_0_Def_rt);
}
SSM_SystemState DataProviderSigM::getSSM_SystemState()
{
	return dataProvider_ro.getSigMData_po()->getSSM_SystemState();
}
void DataProviderSigM::setSSM_SystemState_v(const SSM_SystemState& i_SSM_SystemState_rt)
{
	dataProvider_ro.getSigMData_po()->setSSM_SystemState_v(i_SSM_SystemState_rt);
}

ErrorMgr_ErrorCommPack_QNX_B DataProviderSigM::getErrorMgr_ErrorCommPack_QNX_B()
{
	return dataProvider_ro.getSigMData_po()->getErrorMgr_ErrorCommPack_QNX_B();
}
void DataProviderSigM::setErrorMgr_ErrorCommPack_QNX_B_v(const ErrorMgr_ErrorCommPack_QNX_B& i_ErrorMgr_ErrorCommPack_QNX_B_rt)
{
	dataProvider_ro.getSigMData_po()->setErrorMgr_ErrorCommPack_QNX_B_v(i_ErrorMgr_ErrorCommPack_QNX_B_rt);
}

SSM_QNX_CoreStatus DataProviderSigM::getSSM_QNX_CoreStatus()
{
	return dataProvider_ro.getSigMData_po()->getSSM_QNX_CoreStatus();
}
void DataProviderSigM::setSSM_QNX_CoreStatus_v(const SSM_QNX_CoreStatus& i_SSM_QNX_CoreStatus_rt)
{
	dataProvider_ro.getSigMData_po()->setSSM_QNX_CoreStatus_v(i_SSM_QNX_CoreStatus_rt);
}

LMD_Outputs_CVPAMFDData2_t DataProviderSigM::getCVPAMFDData2_LMD_Outputs_CVPAMFDData()
{
	return dataProvider_ro.getSigMData_po()->getCVPAMFDData2_LMD_Outputs_CVPAMFDData();
}
void DataProviderSigM::setCVPAMFDData2_LMD_Outputs_CVPAMFDData_v(const LMD_Outputs_CVPAMFDData2_t& i_LMD_Outputs_CVPAMFDData2_t_rt)
{
	dataProvider_ro.getSigMData_po()->setCVPAMFDData2_LMD_Outputs_CVPAMFDData_v(i_LMD_Outputs_CVPAMFDData2_t_rt);
}

TrailerDetection_Output_DID_t DataProviderSigM::getTrailerDet_Output_DID()
{
	return dataProvider_ro.getSigMData_po()->getTrailerDet_Output_DID();
}
void DataProviderSigM::setTrailerDet_Output_DID_v(const TrailerDetection_Output_DID_t& i_TrailerDetection_Output_DID_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTrailerDet_Output_DID_v(i_TrailerDetection_Output_DID_t_rt);
}

TbAP_DriveAssistStatOut_t DataProviderSigM::getTbAP_DriveAssistStatOut()
{
	return dataProvider_ro.getSigMData_po()->getTbAP_DriveAssistStatOut();
}
void DataProviderSigM::setTbAP_DriveAssistStatOut_v(const TbAP_DriveAssistStatOut_t& i_TbAP_DriveAssistStatOut_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTbAP_DriveAssistStatOut_v(i_TbAP_DriveAssistStatOut_t_rt);
}

FID_STRUCT_B DataProviderSigM::getfid_struct() 
{ 
	return dataProvider_ro.getSigMData_po()->getfid_struct(); 
} 
void DataProviderSigM::setfid_struct_v(const FID_STRUCT_B& i_FID_STRUCT_B_rt) 
{ 
	dataProvider_ro.getSigMData_po()->setfid_struct_v(i_FID_STRUCT_B_rt); 
}

LMD_Lane_Outputs_s DataProviderSigM::getLMD_Lane_Outputs()
{
	return dataProvider_ro.getSigMData_po()->getLMD_Lane_Outputs();
}
void DataProviderSigM::setLMD_Lane_Outputs_v(const LMD_Lane_Outputs_s& i_LMD_Lane_Outputs_s_rt)
{
	dataProvider_ro.getSigMData_po()->setLMD_Lane_Outputs_v(i_LMD_Lane_Outputs_s_rt);
}

THA_Calibration_data_MPU1_0_t DataProviderSigM::getTHA_Calibration_data_MPU1_0()
{
	return dataProvider_ro.getSigMData_po()->getTHA_Calibration_data_MPU1_0();
}
void DataProviderSigM::setTHA_Calibration_data_MPU1_0_v(const THA_Calibration_data_MPU1_0_t& i_THA_Calibration_data_MPU1_0_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTHA_Calibration_data_MPU1_0_v(i_THA_Calibration_data_MPU1_0_t_rt);
}

APA_Calibration_data_MPU1_0_t DataProviderSigM::getAPA_Calibration_data_MPU1_0()
{
	return dataProvider_ro.getSigMData_po()->getAPA_Calibration_data_MPU1_0();
}
void DataProviderSigM::setAPA_Calibration_data_MPU1_0_v(const APA_Calibration_data_MPU1_0_t& i_APA_Calibration_data_MPU1_0_t_rt)
{
	dataProvider_ro.getSigMData_po()->setAPA_Calibration_data_MPU1_0_v(i_APA_Calibration_data_MPU1_0_t_rt);
}

LMD_Calibration_data_t DataProviderSigM::getLMD_Calibration_data()
{
	return dataProvider_ro.getSigMData_po()->getLMD_Calibration_data();
}
void DataProviderSigM::setLMD_Calibration_data_v(const LMD_Calibration_data_t& i_LMD_Calibration_data_t_rt)
{
	dataProvider_ro.getSigMData_po()->setLMD_Calibration_data_v(i_LMD_Calibration_data_t_rt);
}

TRSC_Calibration_data_MPU1_0_t DataProviderSigM::getTRSC_Calibration_data_MPU1_0()
{
	return dataProvider_ro.getSigMData_po()->getTRSC_Calibration_data_MPU1_0();
}
void DataProviderSigM::setTRSC_Calibration_data_MPU1_0_v(const TRSC_Calibration_data_MPU1_0_t& i_TRSC_Calibration_data_MPU1_0_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTRSC_Calibration_data_MPU1_0_v(i_TRSC_Calibration_data_MPU1_0_t_rt);
}

TbSVS_e_SVSCalibSMToHmi_t DataProviderSigM::getTbSVS_e_SVSCalibSMToHmi()
{
	return dataProvider_ro.getSigMData_po()->getTbSVS_e_SVSCalibSMToHmi();
}
void DataProviderSigM::setTbSVS_e_SVSCalibSMToHmi_v(const TbSVS_e_SVSCalibSMToHmi_t& i_TbSVS_e_SVSCalibSMToHmi_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTbSVS_e_SVSCalibSMToHmi_v(i_TbSVS_e_SVSCalibSMToHmi_t_rt);
}

ME_Proxi_MPU1_0_to_MCU1_0_t DataProviderSigM::getME_Proxi_MPU1_0_to_MCU1_0()
{
	return dataProvider_ro.getSigMData_po()->getME_Proxi_MPU1_0_to_MCU1_0();
}
void DataProviderSigM::setME_Proxi_MPU1_0_to_MCU1_0_v(const ME_Proxi_MPU1_0_to_MCU1_0_t& i_ME_Proxi_MPU1_0_to_MCU1_0_t_rt)
{
	dataProvider_ro.getSigMData_po()->setME_Proxi_MPU1_0_to_MCU1_0_v(i_ME_Proxi_MPU1_0_to_MCU1_0_t_rt);
}

uint8_t DataProviderSigM::getVariantID()
{
	return dataProvider_ro.getSigMData_po()->getVariantID();
}
void DataProviderSigM::setVariantID(const uint8_t var_id)
{
	dataProvider_ro.getSigMData_po()->setVariantID(var_id);
}


uint32_t DataProviderSigM::getRenderFrameID()
{
	return dataProvider_ro.getSigMData_po()->getRenderFrameID();
}
void DataProviderSigM::setRenderFrameID(const uint32_t i_render_frameNum)
{
	dataProvider_ro.getSigMData_po()->setRenderFrameID(i_render_frameNum);
}

uint8_t DataProviderSigM::getRadioDisp()
{
	return dataProvider_ro.getSigMData_po()->getRadioDisp();
}
void DataProviderSigM::setRadioDisp(const uint8_t radio_id)
{
	dataProvider_ro.getSigMData_po()->setRadioDisp(radio_id);
}

uint8_t DataProviderSigM::getETFS_mount_status(void)
{
	return dataProvider_ro.getSigMData_po()->getETFS_mount_status();
}
void DataProviderSigM::setETFS_mount_status(const uint8_t etfs_status)
{
	dataProvider_ro.getSigMData_po()->setETFS_mount_status(etfs_status);
}


FID_STRUCT_QM DataProviderSigM::getFID_STRUCT_QM()
{
	return dataProvider_ro.getSigMData_po()->getFID_STRUCT_QM();
}
void DataProviderSigM::setFID_STRUCT_QM_v(const FID_STRUCT_QM& i_FID_STRUCT_QM_rt)
{
	dataProvider_ro.getSigMData_po()->setFID_STRUCT_QM_v(i_FID_STRUCT_QM_rt);
}
TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t DataProviderSigM::getTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t(bool_t *o_ReceiveStatus_pb )
{
	return dataProvider_ro.getSigMData_po()->getTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t(o_ReceiveStatus_pb);
}
void DataProviderSigM::setTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_v(const TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t& i_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_rt)
{
	dataProvider_ro.getSigMData_po()->setTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_v(i_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_rt);
}
TrailerDetection_Output_HMI_t DataProviderSigM::getTrailerDetection_Output_HMI()
{
	return dataProvider_ro.getSigMData_po()->getTrailerDetection_Output_HMI();
}
void DataProviderSigM::setTrailerDetection_Output_HMI_v(const TrailerDetection_Output_HMI_t& i_TrailerDetection_Output_HMI_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTrailerDetection_Output_HMI_v(i_TrailerDetection_Output_HMI_t_rt);
}
JobDLDOutput_t DataProviderSigM::getJobDLDOutput()
{
	return dataProvider_ro.getSigMData_po()->getJobDLDOutput();
}
void DataProviderSigM::setJobDLDOutput_v(const JobDLDOutput_t& i_JobDLDOutput_rt)
{
	dataProvider_ro.getSigMData_po()->setJobDLDOutput_v(i_JobDLDOutput_rt);
}
Error_Fault_MPU1_0_t DataProviderSigM::getError_Fault_MPU1_0()
{
	return dataProvider_ro.getSigMData_po()->getError_Fault_MPU1_0();
}
void DataProviderSigM::setError_Fault_MPU1_0_v(const Error_Fault_MPU1_0_t& i_Error_Fault_MPU1_0_rt)
{
	dataProvider_ro.getSigMData_po()->setError_Fault_MPU1_0_v(i_Error_Fault_MPU1_0_rt);
}

TRSC_CalibrationClear_t DataProviderSigM::getTRSC_CalibrationClear_t()
{
	return dataProvider_ro.getSigMData_po()->getTRSC_CalibrationClear_t();
}
void DataProviderSigM::setTRSC_CalibrationClear_v(const TRSC_CalibrationClear_t& i_TRSC_CalibrationClear_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTRSC_CalibrationClear_v(i_TRSC_CalibrationClear_t_rt);
}

PerformanceStatsEnable_t DataProviderSigM::getPerformanceStatsEnable_t()
{
	return dataProvider_ro.getSigMData_po()->getPerformanceStatsEnable_t();
}
void DataProviderSigM::setPerformanceStatsEnable_v(const PerformanceStatsEnable_t& i_PerformanceStatsEnable_t_rt)
{
	dataProvider_ro.getSigMData_po()->setPerformanceStatsEnable_v(i_PerformanceStatsEnable_t_rt);
}

CamHotplugStatus_t DataProviderSigM::getCamHotplugStatus_t()
{
	return dataProvider_ro.getSigMData_po()->getCamHotplugStatus_t();
}
void DataProviderSigM::setCamHotplugStatus_v(const CamHotplugStatus_t& i_CamHotplugStatus_t_rt)
{
	dataProvider_ro.getSigMData_po()->setCamHotplugStatus_v(i_CamHotplugStatus_t_rt);
}

RunTimeStats_MPU1_0_t DataProviderSigM::getRunTimeStats_MPU1_0_t()
{
	return dataProvider_ro.getSigMData_po()->getRunTimeStats_MPU1_0_t();
}
void DataProviderSigM::setRunTimeStats_MPU1_0_v(const RunTimeStats_MPU1_0_t& i_RunTimeStats_MPU1_0_rt)
{
	dataProvider_ro.getSigMData_po()->setRunTimeStats_MPU1_0_v(i_RunTimeStats_MPU1_0_rt);
}
TRSCDebug_ScrReq_t DataProviderSigM::getTRSCDebug_ScrReq()
{
	return dataProvider_ro.getSigMData_po()->getTRSCDebug_ScrReq();
}
void DataProviderSigM::setTRSCDebug_ScrReq_v(const TRSCDebug_ScrReq_t& i_TRSCDebug_ScrReq_t_rt)
{
	dataProvider_ro.getSigMData_po()->setTRSCDebug_ScrReq_v(i_TRSCDebug_ScrReq_t_rt);
}
ME_CanDebugRIDStatus_t DataProviderSigM::getCanDebugRIDStatus()
{
	return dataProvider_ro.getSigMData_po()->getCanDebugRIDStatus();
}
void DataProviderSigM::setCanDebugRIDStatus_v(const ME_CanDebugRIDStatus_t& i_ME_CanDebugRIDStatus_t_rt)
{
	dataProvider_ro.getSigMData_po()->setCanDebugRIDStatus_v(i_ME_CanDebugRIDStatus_t_rt);
}
void DataProviderSigM::setSigMRuntime(uint32_t u_Runtime_u32)
{
	dataProvider_ro.getSigMData_po()->setSigMRuntime(u_Runtime_u32);
}
void DataProviderSigM::setThSigMRuntime(uint32_t u_Runtime_u32)
{
	dataProvider_ro.getSigMData_po()->setThSigMRuntime(u_Runtime_u32);
}
void  DataProviderSigM::setKeepAliveRuntime(uint32_t u_Runtime_u32)
{
	dataProvider_ro.getSigMData_po()->setKeepAliveRuntime(u_Runtime_u32);
}
void DataProviderSigM::setMsgSndrRuntime(uint32_t u_Runtime_u32)
{
	dataProvider_ro.getSigMData_po()->setMsgSndrRuntime(u_Runtime_u32);
}
PerformanceStatsEnable_t DataProviderSigM::get_PerformanceStatsEnable(void)
{
	return dataProvider_ro.getSigMData_po()->getPerformanceStatsEnable_t();
}
} // namespace sigm
