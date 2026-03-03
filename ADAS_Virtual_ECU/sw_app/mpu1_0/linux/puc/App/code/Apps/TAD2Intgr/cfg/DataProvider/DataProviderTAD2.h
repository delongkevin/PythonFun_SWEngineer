//--------------------------------------------------------------------------
/// @file DataProviderTAD2.h
/// @brief Contains interface for TAD2 Dataprovider
///
/// DataProvider is an interface between TAD module and the shared memory.
/// It implements the pure virtual interface definition to adapt the
/// module/component to the framework by specifying where the data comes form
/// or goes to. This means, this file contains all the interfaces required
/// to access input and output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef DATAPROVIDERTAD_H_
#define DATAPROVIDERTAD_H_

#include "IDataProviderTAD2.h"
#include <cfg/IDataProvider.h>
#include "CrossplatformCommon.h"
#include "CrossplatformCommon.hpp"
#include <bsp/io/tiovx/TIOVXConsumer.h>
//#include "TAD2/algo/common/IAVMoveData.h"

namespace TAD2
{
typedef m_GearValues_t eVehicleGear_t;

class DataProviderTAD2 : public IDataProviderTAD2
{
  public:
    explicit DataProviderTAD2(container::IDataProvider& b_DataProvider_ro);
    virtual ~DataProviderTAD2();
    
    // get job input
     virtual TAD2::JobTADInput* get_input();

    // Get vehicle kinematic data.
     virtual TAD2::RawKinematicData get_kinematic_data() const ;

     // Get vehicle CAN data.
     virtual TAD2::RawVehicleData get_Vehicle_data()  ;

     // Get topview image
     virtual const uint8_t* get_topview_u8c1() const ;
     virtual int read_topview_gray();

#if DUMP_REAR_FISHEYE_ALGO_VIEW
     void dump_Fisheye_rear();
#endif

#if !(TAD2_SIGM_TESTING)
     virtual void readSanityTestData (TAD2::RawVehicleData &vehData, TAD2::RawKinematicData &KMData) ME_OVERRIDE;
#endif

     virtual void set_vehicle_params( TAD2::VehicleParameters& vehicleParams );
     virtual TAD2::VehicleParameters get_vehicle_params() ;
     virtual void put_output( const TAD2::JobTADOutput& i_jobTADOutput );
     virtual void set_config( tad2config::TADConfigData& i_config );
     // Check whether feature is allowed to run
     virtual bool_t isTADFeatureAllowedToRun(TeTRSC_e_TrlrPrsntInfo &TrlrPrsntInfo) ME_OVERRIDE;

     // --- Pointers and references to changing data
     tad2config::TADConfigData m_ConfigData;
     //const iav::MoveData m_curMovData;
     uint8_t* m_topView;
     const uint8_t* m_rearView;
     TAD2::JobTADOutput m_jobOutput;
     TAD2::JobTADInput m_jobInput;
     int first = 1;
     ME_ProxiToMPU1_0_Def_t v_Proxy_st;
     // -- Trailer Features
#if TAD2_NVM_ACCESS_ENABLED	 
	 TAD2::TrailerFeatures m_loadedFeatures;
	 // --- Trailer template
	 int m_curTrailerID;
	 int m_loadedTrailerID;
	 int m_trailerIDOfMostRecent;
	 bool m_bTrailerTemplateOutput;
	 tad2config::TAD_ConfigData m_config;
#endif	 

    virtual void getVehicleData() const ME_OVERRIDE;
    virtual IKinematicData_t getKMData() const ME_OVERRIDE;
    virtual float32_t getVehicleSpeed() const ME_OVERRIDE;
    virtual int8_t getVehicleGear() const ME_OVERRIDE;
    virtual float32_t getVehicleSteeringWheelAng() const ME_OVERRIDE;
    virtual uint8_t getTailgateStatus() const ME_OVERRIDE;
    virtual ME_ProxiToMPU1_0_Def_t* getProxyData() ME_OVERRIDE;
    virtual TAD2::VehicleControlData get_VehicleControl_data() const ME_OVERRIDE;
    virtual Detection_Inputs_from_TRSC_t getDetection_Inputs_from_TRSC() const ME_OVERRIDE;
    virtual void setTRSC_Inputs_from_TrailerDetection(TRSC_Inputs_from_TrailerDetection_t& TRSC_Inputs_from_TrailerDetection) const ME_OVERRIDE;
    virtual void setTrailerDetection_DID(TrailerDetection_Output_DID_t& TrailerDetection_Output_DID) ME_OVERRIDE;
    virtual TeTRSC_e_TrailerCalibMemClearResponse_t calibrationMemClear() ME_OVERRIDE;
    virtual void mapNewSignalsForDID(TrailerDetection_Output_DID_t& TrailerDetection_Output_DID_mapping) ME_OVERRIDE;
    
    virtual bsp::TIOVXHost& getTIOVX_ro() ME_OVERRIDE;
    virtual container::OVL3DData* getOVL3DData_po() ME_OVERRIDE;
    void FlipHorizontalPlanarW640H640( uint8_t* i_inputImage_pu8, const uint16_t i_inputWidth_u16, const uint16_t i_inputHeight_u16 );
    virtual void setTADRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
    virtual void setTADThreadRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
    virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) ME_OVERRIDE;
#if TAD2_NVM_ACCESS_ENABLED
    virtual void SaveTrailerFeatures( TAD2::TrailerFeatures& trailerfeatures ) ME_OVERRIDE;
    virtual void InitJobInput() ME_OVERRIDE;
    virtual void InitTrailerTemplate() ME_OVERRIDE;
    virtual bool LoadFeatures() ME_OVERRIDE;
#endif	

  private:
    bsp::TIOVXConsumer tiovxConsumer;
    container::IDataProvider&   dataProvider_ro;
}; // namespace TAD2

}

#endif /* DATAPROVIDERTAD_H_ */
