//--------------------------------------------------------------------------
/// @file ProjectRequests.h
/// @brief Contains project specific request configuration and defines the list that is used big JobSigM
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef SIGM_PROJECT_REQUESTS_H_
#define SIGM_PROJECT_REQUESTS_H_

#include "mecl/core/ArrayList.h"
//#include "cfg/requests/ReqScreen.h"
//#include "cfg/requests/ReqTRA.h"
//#include "cfg/requests/ReqMCU_TRAGateway1.h"
//#include "cfg/requests/ReqMCU_TRAGateway2.h"
//#include "cfg/requests/ReqMCU_TRAGateway3.h"
//#include "cfg/requests/ReqMCU_TRAGateway4.h"
//#include "cfg/requests/ReqControl.h"
//
//#include "cfg/requests/ReqMisc.h"
//#include "cfg/requests/ReqVehicleState.h"
//
//#include "cfg/requests/ReqBootState.h"
//#include "cfg/requests/ReqPerCErrorState.h"
//#include "cfg/requests/ReqInformation.h"
//#include "cfg/requests/ReqApplyConfig.h"
//#include "cfg/requests/ReqAlgoControl.h"
//
//#include "cfg/requests/ReqCamGetEeprom.h"
//#include "cfg/requests/ReqCamGetRegister.h"
//#include "cfg/requests/ReqCamSetRegister.h"
//#include "cfg/requests/ReqCamApplyCalib.h"
//#include "cfg/requests/ReqTestPattern.h"

namespace sigm
{

class BaseRequest;

// Base Request list definition for JobSigm
const uint32_t MaxRequestTypes = 51U;
typedef mecl::core::ArrayList<BaseRequest*,MaxRequestTypes> BaseRequestList_t;

// project specifig quests
struct ProjectRequests_s
{
  void init_v(BaseRequestList_t& b_Items_t)
  {/*
    b_Items_t.pushBack_v(&reqScreen_o);
    b_Items_t.pushBack_v(&reqTRA_o);

	  b_Items_t.pushBack_v(&reqMCU_TRAgateway1_o);
    b_Items_t.pushBack_v(&reqMCU_TRAgateway2_o);
    b_Items_t.pushBack_v(&reqMCU_TRAgateway3_o);
    b_Items_t.pushBack_v(&reqMCU_TRAgateway4_o);
    b_Items_t.pushBack_v(&reqControl_o);
    b_Items_t.pushBack_v(&reqMisc_o);
    b_Items_t.pushBack_v(&reqVehicleState_o);

    b_Items_t.pushBack_v(&reqBootState_o);
    b_Items_t.pushBack_v(&reqErrorState_o);
    b_Items_t.pushBack_v(&reqInformation_o);
    b_Items_t.pushBack_v(&reqApplyConfig_o);

    b_Items_t.pushBack_v(&ReqAlgoEolStart_o);
    b_Items_t.pushBack_v(&ReqAlgoEolStop_o);
    b_Items_t.pushBack_v(&ReqAlgoEolPause_o);
    b_Items_t.pushBack_v(&ReqAlgoEolResume_o);
    b_Items_t.pushBack_v(&ReqAlgoEolStatus_o);
    b_Items_t.pushBack_v(&ReqAlgoEolDebug_o);

    b_Items_t.pushBack_v(&ReqAlgoOCStart_o);
    b_Items_t.pushBack_v(&ReqAlgoOCStop_o);
    b_Items_t.pushBack_v(&ReqAlgoOCPause_o);
    b_Items_t.pushBack_v(&ReqAlgoOCStatus_o);
    b_Items_t.pushBack_v(&ReqAlgoOCResume_o);
    b_Items_t.pushBack_v(&ReqAlgoOCDebug_o);

    b_Items_t.pushBack_v(&ReqAlgoScStart_o);
    b_Items_t.pushBack_v(&ReqAlgoScStop_o);
    b_Items_t.pushBack_v(&ReqAlgoScPause_o);
    b_Items_t.pushBack_v(&ReqAlgoScStatus_o);
    b_Items_t.pushBack_v(&ReqAlgoScResume_o);
    b_Items_t.pushBack_v(&ReqAlgoScDebug_o);

    b_Items_t.pushBack_v(&ReqAlgoTeolStart_o);
    b_Items_t.pushBack_v(&ReqAlgoTeolStop_o);
    b_Items_t.pushBack_v(&ReqAlgoTeolPause_o);
    b_Items_t.pushBack_v(&ReqAlgoTeolStatus_o);
    b_Items_t.pushBack_v(&ReqAlgoTeolDebug_o);

    b_Items_t.pushBack_v(&reqCamGetEeprom_o);
    b_Items_t.pushBack_v(&reqCamGetRegister_o);
    b_Items_t.pushBack_v(&reqCamSetRegister_o);
    b_Items_t.pushBack_v(&reqCamApplyCalib_o);
    b_Items_t.pushBack_v(&reqTestPattern_o);
  */}

private:

/*  ReqScreen          reqScreen_o;                    ///< Handles screen requests and responses (0x110/0x310)
  ReqTRA             reqTRA_o;                    ///< Handles TRA data requests and responses (0x130/0x330)
  ReqMCU_TRAGateway1 reqMCU_TRAgateway1_o;         ///< Handles MCU_TRAGateway requests and responses (0x91/0x291)
  ReqMCU_TRAGateway2 reqMCU_TRAgateway2_o;     ///< Handles MCU_TRAGateway2 data requests and responses (0x92/0x292)
  ReqMCU_TRAGateway3 reqMCU_TRAgateway3_o;     ///< Handles MCU_TRAGateway3 data requests and responses (0x93/0x293)
  ReqMCU_TRAGateway4 reqMCU_TRAgateway4_o;     ///< Handles MCU_TRAGateway4 data requests and responses (0x94/0x294)
  ReqControl         reqControl_o;
  ReqMisc            reqMisc_o;     ///< Handles Misc data requests and responses (0x105/0x3xx)
  ReqVehicleState    reqVehicleState_o;        ///< Handles vehicle state requests and responses (0x120/0x320)

  ReqAlgoEolStart    ReqAlgoEolStart_o;  ///< Handles algo control requests and responses (0x0A10/0x0B10)
  ReqAlgoEolStop     ReqAlgoEolStop_o;   ///< Handles algo control requests and responses (0x0A11/0x0B11)
  ReqAlgoEolPause    ReqAlgoEolPause_o;  ///< Handles algo control requests and responses (0x0A12/0x0B12)
  ReqAlgoEolResume   ReqAlgoEolResume_o;  ///< Handles algo control requests and responses (0x0A12/0x0B12)
  ReqAlgoEolStatus   ReqAlgoEolStatus_o; ///< Handles algo control requests and responses (0x0A13/0x0B13)
  ReqAlgoEolDebug    ReqAlgoEolDebug_o;  ///< Handles algo control requests and responses (0x0A45/0x0B45)

  ReqAlgoOcStart     ReqAlgoOCStart_o;  ///< Handles algo control requests and responses (0x0A10/0x0B10)
  ReqAlgoOcStop      ReqAlgoOCStop_o;   ///< Handles algo control requests and responses (0x0A11/0x0B11)
  ReqAlgoOcPause     ReqAlgoOCPause_o;  ///< Handles algo control requests and responses (0x0A12/0x0B12)
  ReqAlgoOcStatus    ReqAlgoOCStatus_o; ///< Handles algo control requests and responses (0x0A13/0x0B13)
  ReqAlgoOcResume    ReqAlgoOCResume_o; ///< Handles algo control requests and responses (0x0A13/0x0B13)
  ReqAlgoOcDebug     ReqAlgoOCDebug_o;  ///< Handles algo control requests and responses (0x0A45/0x0B45)

  ReqAlgoScStart     ReqAlgoScStart_o;  ///< Handles algo control requests and responses (0x0A10/0x0B10)
  ReqAlgoScStop      ReqAlgoScStop_o;   ///< Handles algo control requests and responses (0x0A11/0x0B11)
  ReqAlgoScPause     ReqAlgoScPause_o;  ///< Handles algo control requests and responses (0x0A12/0x0B12)
  ReqAlgoScResume    ReqAlgoScResume_o;  ///< Handles algo control requests and responses (0x0A12/0x0B12)
  ReqAlgoScStatus    ReqAlgoScStatus_o; ///< Handles algo control requests and responses (0x0A13/0x0B13)
  ReqAlgoScDebug     ReqAlgoScDebug_o;  ///< Handles algo control requests and responses (0x0A45/0x0B45)

  ReqAlgoTeolStart   ReqAlgoTeolStart_o;  ///< Handles algo control requests and responses (0x0A10/0x0B10)
  ReqAlgoTeolStop    ReqAlgoTeolStop_o;   ///< Handles algo control requests and responses (0x0A11/0x0B11)
  ReqAlgoTeolPause   ReqAlgoTeolPause_o;  ///< Handles algo control requests and responses (0x0A12/0x0B12)
  ReqAlgoTeolStatus  ReqAlgoTeolStatus_o; ///< Handles algo control requests and responses (0x0A13/0x0B13)
  ReqAlgoTeolDebug   ReqAlgoTeolDebug_o;  ///< Handles algo control requests and responses (0x0A45/0x0B45)

  ReqBootState       reqBootState_o; ///< Handles boot state requests and responses (0x020/0x220)
  ReqApplyConfig     reqApplyConfig_o; ///< Handles apply config requests and responses (0x30/0x230)
  ReqPerCErrorState  reqErrorState_o; ///< Handles error state requests and responses (0x40/0x240)
  ReqInformation     reqInformation_o; ///< Handles information requests and responses (0x070/0x270)

  ReqCamGetEeprom    reqCamGetEeprom_o; ///< Handles camera requests and responses // TBD
  ReqCamGetRegister  reqCamGetRegister_o; ///< Handles camera requests and responses // TBD
  ReqCamSetRegister  reqCamSetRegister_o; ///< Handles camera requests and responses // TBD
  ReqCamApplyCalib   reqCamApplyCalib_o;
  ReqTestPattern     reqTestPattern_o;     ///< Handles Test Pattern Requests
  */
};

} // namespace SIgM


#endif /* REQUESTLIST_H_ */
