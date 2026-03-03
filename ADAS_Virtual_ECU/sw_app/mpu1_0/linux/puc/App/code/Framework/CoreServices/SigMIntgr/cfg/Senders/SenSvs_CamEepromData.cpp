//--------------------------------------------------------------------------
/// @file SenSvs_CamEepromData.cpp
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
//  --------------------------------------------------------------------------

#include "SenSvs_CamEepromData.h"

namespace sigm
{

SenSvs_CamEepromData::SenSvs_CamEepromData()
 : BaseSender(e_IpcMsgId_PpCamEepromData_Svs_CamEepromDataArray_t, 50)
{
}

SenSvs_CamEepromData::~SenSvs_CamEepromData()
{
}

bool_t SenSvs_CamEepromData::handleSpecificSender_b()
{
  if (true == handle_Svs_CamEepromDataSender_b())
  {
    // receive is done

  }
  // always respond
  return true;
}

bool_t SenSvs_CamEepromData::handle_Svs_CamEepromDataSender_b()
{
  uint8_t 	crcResBytes[c_EepromCRCResbytesSize_u32]= {0};

  uint32_t MSgToRespond_size = 0;

  uint32_t SVSEepromData_t_size = sizeof(SVSEepromData_t); //196 bytes

  //Get the main eeprom_data structure it has  array  of size 4 camera information(784 bytes.
  Svs_CamEepromDataArray_t v_NewMsgSend_t = dataProvider_po->getSvs_CamEepromDataArray_t();
  
  //Get the 4 eeproms data one bye one , consider  2 bytes header in the beginning.

  MSgToRespond_size = 2 + SVSEepromData_t_size ;

  uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_PpCamEepromData_Svs_CamEepromDataArray_t); //Generally 2 bytes  header

  bool_t v_RequestOk_b = writeSvs_CamEepromDataArray_b(&msgToRespond_s.data_t[v_Index_u32], SVSEepromData_t_size, &(v_NewMsgSend_t.CameraEepromData[0]));

  v_Index_u32 = v_Index_u32 + SVSEepromData_t_size;

  //copy the CRC bytes
  v_RequestOk_b = writeSvs_CamEepromReservedCRCBytes_b(&msgToRespond_s.data_t[v_Index_u32], c_EepromCRCResbytesSize_u32, &crcResBytes[0]); //256 bytes

  MSgToRespond_size = MSgToRespond_size + c_EepromCRCResbytesSize_u32;
  //array[0] Eeprom data done.


  v_Index_u32 = v_Index_u32 + c_EepromCRCResbytesSize_u32;

  v_RequestOk_b = writeSvs_CamEepromDataArray_b(&msgToRespond_s.data_t[v_Index_u32], SVSEepromData_t_size, &(v_NewMsgSend_t.CameraEepromData[1]));

  v_Index_u32 = v_Index_u32 + SVSEepromData_t_size;

  v_RequestOk_b = writeSvs_CamEepromReservedCRCBytes_b(&msgToRespond_s.data_t[v_Index_u32], c_EepromCRCResbytesSize_u32, &crcResBytes[0]); //256 bytes

  MSgToRespond_size = MSgToRespond_size + SVSEepromData_t_size + c_EepromCRCResbytesSize_u32;

  v_Index_u32 = v_Index_u32 + c_EepromCRCResbytesSize_u32;
  //array[1] Eeprom data done

  v_RequestOk_b = writeSvs_CamEepromDataArray_b(&msgToRespond_s.data_t[v_Index_u32], SVSEepromData_t_size, &(v_NewMsgSend_t.CameraEepromData[2]));

  v_Index_u32 = v_Index_u32 + SVSEepromData_t_size;

  v_RequestOk_b = writeSvs_CamEepromReservedCRCBytes_b(&msgToRespond_s.data_t[v_Index_u32], c_EepromCRCResbytesSize_u32, &crcResBytes[0]); //256 bytes

  MSgToRespond_size = MSgToRespond_size + SVSEepromData_t_size + c_EepromCRCResbytesSize_u32;

  v_Index_u32 = v_Index_u32 + c_EepromCRCResbytesSize_u32;
  //array[2] Eeprom data done

  v_RequestOk_b = writeSvs_CamEepromDataArray_b(&msgToRespond_s.data_t[v_Index_u32], SVSEepromData_t_size, &(v_NewMsgSend_t.CameraEepromData[3]));

  v_Index_u32 = v_Index_u32 + SVSEepromData_t_size;

  v_RequestOk_b = writeSvs_CamEepromReservedCRCBytes_b(&msgToRespond_s.data_t[v_Index_u32], c_EepromCRCResbytesSize_u32, &crcResBytes[0]); //256 bytes

  MSgToRespond_size = MSgToRespond_size + SVSEepromData_t_size + c_EepromCRCResbytesSize_u32;

  //array[3] Eeprom data done

  msgToRespond_s.msgSize_u32  = MSgToRespond_size;

  logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " Svs_CamEepromDatas total bytes  %d \n",
		   msgToRespond_s.msgSize_u32);

/*  uint32_t crc = 0;
  memcpy( &crc, &msgToRespond_s.data_t[194],4);

  logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, " Svs_CamEepromData1 crc_u32  %u \n", crc);

  memcpy( &crc, &msgToRespond_s.data_t[450],4);

  logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, " Svs_CamEepromData2 crc_u32  %u \n", crc);

  memcpy( &crc, &msgToRespond_s.data_t[706],4);

  logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, " Svs_CamEepromData3 crc_u32  %u \n", crc);

  memcpy( &crc, &msgToRespond_s.data_t[962],4);

  logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, " Svs_CamEepromData4 crc_u32  %u \n", crc);*/

  return v_RequestOk_b;

}

} /* namespace sigm */