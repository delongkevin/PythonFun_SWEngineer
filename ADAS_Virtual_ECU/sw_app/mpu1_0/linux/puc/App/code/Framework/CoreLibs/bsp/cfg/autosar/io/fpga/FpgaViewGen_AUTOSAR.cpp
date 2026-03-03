//--------------------------------------------------------------------------
/// @file FpgaViewGen_AUTOSAR.cpp
/// @brief Implementation of AUTOSAR fpga interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------


#include "bsp/io/fpga/FpgaViewGen.h"


#ifdef ME_PLATFORM_AUTOSAR


namespace bsp
{

  FpgaViewGen::FpgaViewGen()
    : viewGenConfigBase_pv(NULL)
    , viewGenConfig_o()
    , cacheViewGenConfig_o()
  {

  }

  FpgaViewGen::~FpgaViewGen()
  {

  }

  bool_t FpgaViewGen::initViewGen3_b()
  {
    bool_t v_Result_b = false;

    cacheViewGenConfig_o.init_b(cacheBufferViewGenConfig_au8);

    return v_Result_b;
  }


  void FpgaViewGen::enable_v()
  {
  }

  void FpgaViewGen::disable_v()
  {
  }

  ViewGenConfig& FpgaViewGen::getViewGenConfig_rs()
  {
    return cacheViewGenConfig_o;
  }

  void FpgaViewGen::getViewGenTrigger_v()
  {
  }

  bool_t FpgaViewGen::configViewGenDone_b()
  {
    return (isViewGenConfigDone_b = true);
  }

  bool_t FpgaViewGen::isConfigViewGenDone_b()
  {
    return isViewGenConfigDone_b;
  }

  bool_t FpgaViewGen::isProcessingViewGen_b()
  {
    return isViewGenProcessed_b;
  }

  bool_t FpgaViewGen::setProcessViewGen_b()
  {
    return (isViewGenProcessed_b = true);
  }

  bool_t FpgaViewGen::setReadBuffer_b(uint8_t i_BufferIdx_u8)
  {
    bool_t v_Result_b = true;

    return v_Result_b;
  }

  bool_t FpgaViewGen::lockViewGen_b(bool_t i_Lock_b)
  {
    static_cast<void>(i_Lock_b);
    return true;
  }

  bool_t FpgaViewGen::update_b()
  {
    return true;
  }

  bool_t FpgaViewGen::updateViewGen_b()
  {
    return true;
  }

  bool_t FpgaViewGen::updateDist_b()
  {
    return true;
  }

  bool_t FpgaViewGen::updateSequenceTable_b()
  {
    return true;
  }

  bool_t FpgaViewGen::updateUndist_b()
  {
    return true;
  }

  bool_t FpgaViewGen::updateReadBuffer_b()
  {
    return true;
  }

  bool_t FpgaViewGen::updateMatMulImm_b()
  {
    return true;
  }

  bool_t FpgaViewGen::updateMatMulImmSetReadBuffer_b(uint8_t i_BufferIdx_u8)
  {
    return true;
  }

  bool_t FpgaViewGen::updateSequenceTableImm_b()
  {
    return true;
  }

} // namespace bsp

#endif // ME_PLATFORM_AUTOSAR

