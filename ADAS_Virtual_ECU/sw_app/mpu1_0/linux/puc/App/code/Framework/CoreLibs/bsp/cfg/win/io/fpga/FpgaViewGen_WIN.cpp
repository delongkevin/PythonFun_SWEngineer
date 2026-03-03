//--------------------------------------------------------------------------
/// @file FpgaViewGen_WIN.cpp
/// @brief Implementation of Windows fpga interface
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


#ifdef ME_PLATFORM_WIN


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

  bool_t FpgaViewGen::initViewGen_b()
  {
    bool_t v_Result_b = false;

    v_Result_b = cacheViewGenConfig_o.init_b(cacheBufferViewGenConfig_au8);

    return v_Result_b;
  }


  bool_t FpgaViewGen::enable_b(bool_t i_Lock_b)
  {
    return true;
  }

  bool_t FpgaViewGen::disable_b(bool_t i_Lock_b)
  {
    return true;
  }

  bool_t FpgaViewGen::isEnabled_b()
  {

    bool_t v_Result_b = isViewGenEnabled_b;


    return v_Result_b;
  }

  bool_t FpgaViewGen::isInitialized_b()
  {
    bool_t v_Result_b = isViewGenInitialized_b;

    return v_Result_b;
  }

  bool_t FpgaViewGen::isConfigViewGenDone_b()
  {
    bool_t v_Result_b = isViewGenConfigDone_b;

    return v_Result_b;
  }

  bool_t FpgaViewGen::isProcessingViewGen_b()
  {
    bool_t v_Result_b = isViewGenProcessed_b;

    return v_Result_b;
  }

  ViewGenConfig& FpgaViewGen::getViewGenConfig_rs()
  {
    return cacheViewGenConfig_o;
  }

  bool_t FpgaViewGen::getViewGenTrigger_b()
  {
	  return false;
  }

  bool_t FpgaViewGen::getHarmonComutationResults_b(uint32_t* o_HarmonComputationResults_pu32)
  {
    return true;
  }

  bool_t FpgaViewGen::configViewGenDone_b()
  {
    return (isViewGenConfigDone_b = true);
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

  bool_t FpgaViewGen::lock_b()
  {
    return true;
  }

  bool_t FpgaViewGen::unlock_b()
  {
    return true;
  }

  bool_t FpgaViewGen::update_b()
  {
    return true;
  }

  bool_t FpgaViewGen::updateNonLock_b()
  {
    return true;
  }

  void FpgaViewGen::free_v()
  {

  }

  bool_t FpgaViewGen::updateViewGen_b()
  {
    return true;
  }

  bool_t FpgaViewGen::updateDistImm_b()
  {
    return true;
  }

  bool_t FpgaViewGen::updateHarmonizationImm_b()
  {
    return true;
  }

  bool_t FpgaViewGen::updateSequenceTable_b() const
  {
    return true;
  }

  bool_t FpgaViewGen::updateUndist_b() const
  {
    return true;
  }

  bool_t FpgaViewGen::updateReadBuffer_b() const
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

#endif // ME_PLATFORM_WIN

