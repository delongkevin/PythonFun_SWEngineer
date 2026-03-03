//--------------------------------------------------------------------------
/// @file DataContainer.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#include "ODData.h"

namespace container
{

ODData::ODData()
  : DataContainer()
  , mutex_o(true, true)

{

}

ODData::~ODData()
{

}

DNN_Output ODData::getDNNOutput_v()
{
  DNN_Output v_DataCopy_s32 = {0};
  mutex_o.take_b();
  v_DataCopy_s32 = m_DNNOutput_s;
  mutex_o.give_v();

  return v_DataCopy_s32;
}

void ODData::setDNNOutput_v(DNN_Output i_DNNOutput_s)
{
  mutex_o.take_b();
  m_DNNOutput_s.DNNModelStatus = i_DNNOutput_s.DNNModelStatus;
  m_DNNOutput_s.DetectionTimestamp = i_DNNOutput_s.DetectionTimestamp;
  m_DNNOutput_s.IeVBII_cnt_currDetection = i_DNNOutput_s.IeVBII_cnt_currDetection;
  memcpy(m_DNNOutput_s.DNN_EnvSignals,i_DNNOutput_s.DNN_EnvSignals,sizeof(IaDNN_e_EnvObjList)*20);
  mutex_o.give_v();
}

} // namespace container
