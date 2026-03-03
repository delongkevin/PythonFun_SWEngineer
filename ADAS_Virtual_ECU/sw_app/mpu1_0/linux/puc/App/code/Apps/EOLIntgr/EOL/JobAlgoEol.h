//--------------------------------------------------------------------------
/// @file JobAlgoEol.h
/// @brief Contains The Eol job definition.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef JOBALGOEOL_H
#define JOBALGOEOL_H

#include <variants/Enums.h>
#include <osal/threading/Thread.h>
#include <container/JobBase.h>
#include <mecl/mecl.h>
#include "IDataProviderEol.h"
#include "EolTypesInternal.h"
#include "EolCalib.h"

// This commented code is uncommented and used when debugging with log_prinfs ON.
// PRQA S 1051 1
//#define EOL_LOG_PRINTF_ON

#ifdef EOL_LOG_PRINTF_ON
//PRQA S 1020 1 //Macro used for debugging
#define EOL_DEBUG_PRINTF(x) log_printf x
#else
//PRQA S 1020 1 //Macro used for debugging
#define EOL_DEBUG_PRINTF(x)
#endif

namespace eol
{

  class EOLThreadRunnable: public osal::IRunnable
  {

  public:
    explicit EOLThreadRunnable(IDataProviderEol &b_DPEol_ro);
    virtual ~EOLThreadRunnable();

    virtual void init_v() ME_OVERRIDE;
    virtual bool_t run_b() ME_OVERRIDE;
    virtual void cleanup_v() ME_OVERRIDE;

  private:
    bool_t hasNext_b( void );
    void start_v( void ) ;
    void execute_v( void ) ;
    void end_v( void ) ;
    void dump_v( void ) ;
    void reset_v( void ) ;

    EolCalib& getEolCalib_ro();
    EolCalib eolcalib_o;
    ME_Hydra3defs_E_EOLAlgoState_t stateAlgo_e;
    EolInitData_s m_EolInitData;

    aParaMgr_E_CalibrationType_t m_CurrAlgoID;
    aParaMgr_E_CalibrationType_t m_PrevAlgoID;

    ME_Hydra3defs_E_AlgoCommand_t m_CurrAlgoCommand;
    ME_Hydra3defs_E_AlgoCommand_t m_PrevAlgoCommand;

    ME_Hydra3defs_E_CameraID_t m_CurrCamID;
    ME_Hydra3defs_E_CameraID_t m_PrevCamID;

    IDataProviderEol &dataProvider_ro;
  };

  class JobAlgoEol : public container::JobBase<IDataProviderEol>
  {
    public:
      JobAlgoEol(container::JobDesc_s& b_JobDesc_rs, IDataProviderEol& b_DPEol_ro);

      virtual ~JobAlgoEol();

      virtual bool_t onInit_b() ME_OVERRIDE;

      virtual void   onVariantChanged_v(bool_t i_FirstTime_b) ME_OVERRIDE;

      virtual bool_t onRun_b() ME_OVERRIDE;

      virtual void   onCleanup_v() ME_OVERRIDE;
    
    private:
      osal::Thread        m_EOLThread_o;
      EOLThreadRunnable   m_EOLThreadRunnable_o;
  };

}//namespace Eol

#endif //JOBALGOEOL_H
