/// --------------------------------------------------------------------------
/// @file DLDStateMachine.cpp
/// @brief Contains state machine for DLD camera selection
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
/// --------------------------------------------------------------------------
#include "../inc/DLDStateMachine.h"

namespace dld 
{
DLDStateMachine::DLDStateMachine(uint32_t maxCyclesPerCamera) :
  m_currentCamId(DLD_Camera_ID::DLD_Rear),
  m_maxCyclesPerCamera(maxCyclesPerCamera),
  m_cyclesInCurCam(0u)
{
		uint8_t numCams = DLD_Camera_ID::DLD_NUM_CAMS;
		for (uint8_t i = 0; i < numCams; i++) 
		{
    m_participants[i] = false;
  }
}

DLDStateMachine::~DLDStateMachine()
{
}
	/*
	*	Name: updateParticipation
	*	Remarks: DD-ID: {48E13187-766E-4822-ADD0-3E49A934D9FD}
	*	Remarks: DD-ID: {1067F212-4CC4-4167-9431-E82910B21177}
	*	Remarks: DD-ID: {D4933F94-6B3B-4193-B82C-5A6CF47C963D}
	*/
	void DLDStateMachine::updateParticipation(DLD_Camera_ID camId, bool_t isParticipating) 
	{
		if (camId < DLD_Camera_ID::DLD_NUM_CAMS) 
		{
			m_participants[camId] = isParticipating;
		}
	}
	/*
	*	Name: getCameraID
	*	Remarks: DD-ID: {8A89BC6D-6E65-470c-8EB3-CB7D67288F62}
	*	Remarks: DD-ID: {809F0A40-D10D-4063-AD13-78ECC128F97F}
	*	Remarks: DD-ID: {02E8A5CE-BAE3-49aa-997C-9312B3C245FA}
	*/
	DLD_Camera_ID DLDStateMachine::getCameraID() 
	{
		if ((m_cyclesInCurCam >= m_maxCyclesPerCamera) || !isCameraParticipating(m_currentCamId)) 
		{
			DLD_Camera_ID nextCamId = getNextCameraId();
			if (nextCamId != m_currentCamId) 
			{
				m_currentCamId = nextCamId;
				m_cyclesInCurCam = 0;
			}
		}
		m_cyclesInCurCam++;

		return m_currentCamId;
	}
	/*
	*	Name: isCameraParticipating
	*	Remarks: DD-ID: {54888A16-F401-4ebe-BA97-80D9AA133F0A}
	*	Remarks: DD-ID: {32C2C2DB-58ED-4e99-BFE6-89FCEE85F514}
	*	Remarks: DD-ID: {2EC8F93E-88E9-4da8-9432-BEA22562B0CA}
	*/
	bool_t DLDStateMachine::isCameraParticipating(DLD_Camera_ID camId) const 
	{
		return (camId < DLD_Camera_ID::DLD_NUM_CAMS) && m_participants[camId];
	}
	/*
	*	Name: getNextCameraId
	*	Remarks: DD-ID: {C7BB19BC-3F45-4f18-83E6-DAE446E6312C}
	*	Remarks: DD-ID: {F78F0D4F-84CD-4ecb-8876-67CDA4DF5CD1}
	*	Remarks: DD-ID: {DAAAB9A8-4D1F-42bc-A5FE-4E3CE6AF2C4D}
	*/
DLD_Camera_ID DLDStateMachine::getNextCameraId() const {
  DLD_Camera_ID nextCamId = DLD_Camera_ID::DLD_NUM_CAMS;
		DLD_Camera_ID newCamId;
		uint8_t m_IPlusOne;
		uint8_t numCams = DLD_Camera_ID::DLD_NUM_CAMS;
for (uint8_t i = 0; i < numCams; i++) 
{
	m_IPlusOne = static_cast<uint8_t>(m_currentCamId) + i + static_cast<uint8_t>(1);
	m_IPlusOne = m_IPlusOne % static_cast<uint8_t>(DLD_Camera_ID::DLD_NUM_CAMS);
	newCamId = static_cast<DLD_Camera_ID>(m_IPlusOne);
			if (isCameraParticipating(newCamId)) 
			{
				nextCamId = newCamId;
				break;
			}
		}

  return nextCamId;
}

} // namespace dld