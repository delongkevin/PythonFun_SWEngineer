//--------------------------------------------------------------------------
/// @file SenErrorMgr_ErrorCommPack_QNX_B.h
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
///  *  @author sagar.saste@magna.com
///
//  --------------------------------------------------------------------------

#ifndef SIGM_SENDERS_ERROR_MGR_COMPACK_QNX_B_H_
#define SIGM_SENDERS_ERROR_MGR_COMPACK_QNX_B_H_

#include "BaseSender.h"

namespace sigm
{

class SenErrorMgr_ErrorCommPack_QNX_B : public BaseSender
{
public:
	SenErrorMgr_ErrorCommPack_QNX_B();
  virtual ~SenErrorMgr_ErrorCommPack_QNX_B();

  virtual bool_t handleSpecificSender_b();


private:
  bool_t handle_ErrorMgr_ErrorCommPack_QNX_BSender_b();
};

} // namespace sigm
#endif // SIGM_SENDERS_ERROR_MGR_COMPACK_QNX_B_H_
