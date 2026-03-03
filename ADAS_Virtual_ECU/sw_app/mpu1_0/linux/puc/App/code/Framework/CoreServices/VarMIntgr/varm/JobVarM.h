//--------------------------------------------------------------------------
/// @file JobVarM.h
/// @brief Contains the job definition for the signal manager.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Marcel Engelhardt (Marcel.Engelhardt@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef JOB_VARM_H
#define JOB_VARM_H

#include <platform/PlatformAPI.h>

#include <container/JobBase.h>
#include "IDataProviderVarM.h"

/// Variant-Manager
namespace varm
{
class JobVarM : public container::JobBase<IDataProviderVarM>

{
public:
  JobVarM(container::JobDesc_s& b_JobDesc_rs, IDataProviderVarM& b_DataProvider_ro);
  virtual ~JobVarM();

  static bool_t loadVariantData_b();


  static bool_t loadVariantDataFromID_b(uint32_t i_ID_u32);
  static bool_t loadVariantDataFromFile_b(const mepl::string& i_FileName_ro);

  // JobBase implementation
  virtual bool_t onInit_b() ME_OVERRIDE;
  virtual void   onVariantChanged_v(bool_t i_FirstTime_b) ME_OVERRIDE;
  virtual bool_t onRun_b() ME_OVERRIDE;
  virtual void onCleanup_v() ME_OVERRIDE;

private:

};
}
#endif // JOB_VARM_H

