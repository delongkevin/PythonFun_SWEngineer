/**
 * -------------------------------------------------------------------------
 *  @file ***.cpp/***.h
 *  @brief Contains
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 *
 *  @author sagar.saste@magna.com
 *  --------------------------------------------------------------------------*/
#ifndef ERRORCOMMPACK_QNX_QM_H_
#define ERRORCOMMPACK_QNX_QM_H_
#include "BaseSender.h"
namespace sigm
{
class ErrorCommPack_QNX_QM : public BaseSender
{
public:
   ErrorCommPack_QNX_QM();
   virtual ~ErrorCommPack_QNX_QM();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_ErrorMgr_ErrorCommPack_QNX_Qb();
};
} // namespace sigm
#endif //ERRORCOMMPACK_QNX_QM_H_
