//--------------------------------------------------------------------------
/// @file IDataProviderTAD2.h
/// @brief Contains interface for TAD2 Dataprovider
///
/// IDataProvider is an interface used by the algorithm to define what data
/// is actually needed. Implementation is delegated to a derived data provider
/// that is component/module specific and belongs to the framework implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef I_DATA_PROVIDER_TAD2_H_
#define I_DATA_PROVIDER_TAD2_H_

// Files to be included here
#include "mecl/mecl.h"
#include "../../TAD2/algo/inc/JobTADOutput.h"
#include "../../TAD2/algo/inc/JobTADInput.h"
#include "../../TAD2/algo/common/CANData.h"
#include "../../TAD2/algo/common/TADStructures.h"

#include "CrossplatformCommon.h"
#include "CrossplatformCommon.hpp"
#include "TRSC_Inputs_Outputs.h"

#include <cfg/BspTypes.h>
#include <cfg/IDataProvider.h>
#include "../../TAD2/TAD2Defines.h"
#include "../../TAD2/algo/common/config.h"


namespace TAD2
{

class IDataProviderTAD2
{
public:
  explicit IDataProviderTAD2()
  {
  }

  virtual ~IDataProviderTAD2()
  {
  }
  
  // get job input
  virtual TAD2::JobTADInput* get_input() = 0;

  // Get vehicle CAN data.
  virtual TAD2::RawVehicleData get_Vehicle_data()  = 0;

  // Get vehicle kinematic data.
  virtual TAD2::RawKinematicData get_kinematic_data() const = 0;

  // Get topview image
  virtual const uint8_t* get_topview_u8c1() const = 0;

#if !(TAD2_SIGM_TESTING)
  virtual void readSanityTestData (TAD2::RawVehicleData &vehData, TAD2::RawKinematicData &KMData) = 0;
#endif

  // read topview image
  virtual int read_topview_gray() = 0;
  virtual void set_vehicle_params( TAD2::VehicleParameters& vehicleParams )=0;
  virtual void put_output( const TAD2::JobTADOutput& i_jobTADOutput )=0;
  virtual TAD2::VehicleParameters get_vehicle_params() =0;
  virtual void set_config(tad2config::TADConfigData& i_config )=0;

  virtual void getVehicleData() const = 0;
  virtual IKinematicData_t getKMData() const = 0;
  virtual float32_t getVehicleSpeed() const = 0;
  virtual int8_t getVehicleGear() const = 0;
  virtual float32_t getVehicleSteeringWheelAng() const = 0;
  virtual uint8_t getTailgateStatus() const = 0;
  virtual ME_ProxiToMPU1_0_Def_t* getProxyData() = 0;
  virtual TAD2::VehicleControlData get_VehicleControl_data() const = 0;
  virtual Detection_Inputs_from_TRSC_t getDetection_Inputs_from_TRSC() const = 0;
  virtual void setTRSC_Inputs_from_TrailerDetection(TRSC_Inputs_from_TrailerDetection_t& TRSC_Inputs_from_TrailerDetection) const = 0;
  virtual void setTrailerDetection_DID(TrailerDetection_Output_DID_t& TrailerDetection_Output_DID) = 0;
  virtual TeTRSC_e_TrailerCalibMemClearResponse_t calibrationMemClear() = 0;
  virtual void mapNewSignalsForDID(TrailerDetection_Output_DID_t& TrailerDetection_Output_DID_mapping) = 0; 

  // Check whether feature is allowed to run
  virtual bool_t isTADFeatureAllowedToRun(TeTRSC_e_TrlrPrsntInfo &TrlrPrsntInfo) = 0;

  virtual bsp::TIOVXHost& getTIOVX_ro() = 0;
  virtual container::OVL3DData* getOVL3DData_po() = 0;
  virtual void setTADRuntime(uint32_t u_Runtime_u32) = 0;
  virtual void setTADThreadRuntime(uint32_t u_Runtime_u32) = 0;
  virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) = 0;
#if TAD2_NVM_ACCESS_ENABLED	  
  virtual void SaveTrailerFeatures( TAD2::TrailerFeatures& trailerfeatures ) = 0;
  virtual void InitJobInput() = 0;
  virtual void InitTrailerTemplate() = 0;
  virtual bool LoadFeatures() = 0;
#endif  
};

} // namespace TAD2

#endif /* I_DATA_PROVIDER_TAD2_H_ */
