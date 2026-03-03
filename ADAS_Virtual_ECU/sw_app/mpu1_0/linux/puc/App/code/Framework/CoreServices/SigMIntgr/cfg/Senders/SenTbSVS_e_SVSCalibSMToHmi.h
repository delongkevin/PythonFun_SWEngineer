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
 *  @author (Author pavan.raut@magna.com)
 *  --------------------------------------------------------------------------*/
#ifndef TBSVS_E_SVSCALIBSMTOHMI_H
#define TBSVS_E_SVSCALIBSMTOHMI_H
#include "BaseSender.h"
namespace sigm
{
class TbSVS_e_SVSCalibSMToHmi : public BaseSender
{
public:
   TbSVS_e_SVSCalibSMToHmi();
   virtual ~TbSVS_e_SVSCalibSMToHmi();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_TbSVS_e_SVSCalibSMToHmi_t_b();
};
} // namespace sigm
#endif //TBSVS_E_SVSCALIBSMTOHMI_H

