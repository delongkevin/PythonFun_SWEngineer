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
#ifndef QNX_STATE_QNX_H_
#define QNX_STATE_QNX_H_
#include "BaseSender.h"
namespace sigm
{
class QNX_State_QNX : public BaseSender
{
public:
   QNX_State_QNX();
   virtual ~QNX_State_QNX();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_SSM_QNX_CoreStatub();
};
} // namespace sigm
#endif //QNX_STATE_QNX_H_
