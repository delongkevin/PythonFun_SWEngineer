//--------------------------------------------------------------------------
/// @file DataProviderCALSM.h
/// @brief Contains
///
/// DataProvider is an interface between calsm module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Ananda kavrady(ananda.kavrady@magna.com)
//  --------------------------------------------------------------------------
#ifndef DATA_PROVIDER_CALSM_H_
#define DATA_PROVIDER_CALSM_H_

#include "calsm/IDataProviderCALSM.h"
#include <cfg/DataProvider.h>

namespace calsm
{

typedef struct ME_Hydra3defs_E_EraseBlockReq_s
{
  boolean isCalibResetRoutineEraseRequested;
  boolean EraseFront_b;
  boolean EraseLeft_b;
  boolean EraseRear_b;
  boolean EraseRight_b;
  boolean EraseAllCamera_b;
}ME_Hydra3defs_E_EraseBlockReq_t;

typedef struct ME_Hydra3defs_E_EraseCalibNVMBlock_s
{
  ME_Hydra3defs_E_EraseBlockReq_t EOLBlock;
  ME_Hydra3defs_E_EraseBlockReq_t SCBlock;
  ME_Hydra3defs_E_EraseBlockReq_t OCBlock;
  ME_Hydra3defs_E_EraseBlockReq_t CurrentBlock;
  boolean isCalibNVMEraseRequested_b;
}ME_Hydra3defs_E_EraseCalibNVMBlock_t;


class DataProviderCALSM : public IDataProviderCALSM
{
public:
  explicit DataProviderCALSM(container::IDataProvider& b_DataProvider_ro);
  virtual ~DataProviderCALSM();

    void get_calib_vehicle_signal_input(void);
    void get_shutdown_input();
    void get_calib_diagmgr_input();
    void get_calib_nvmmgr_input();
    void get_calib_algo_input();
    void set_calib_algo_input();
    void set_NVM_CalibData();
    void set_DiagMgr_CalibData();
    void Get_EOLSM_CalibData();
    void Get_SCSM_CalibData();
    void Get_OCSM_CalibData();
    void Get_Calib_FIDs();
    void Get_FunctionalSettings();
    void Get_EraseCalibration_info(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t DiagData);

    void get_HmiScreen();
    void set_TscScreen();
    void setCALSMRuntime(uint32_t u_CALSMRuntime_u32);
    void setCALSMThreadRuntime(uint32_t u_CALSMRuntime_u32);
    virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) ME_OVERRIDE;

    ME_Hydra3defs_E_EraseCalibNVMBlock_t EraseBlockInfo;
  private:

    container::IDataProvider&    dataProvider_ro;

};

} // namespace calsm

#endif // DATA_PROVIDER_CALSM_H_

