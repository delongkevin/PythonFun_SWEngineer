//--------------------------------------------------------------------------
/// @file FpgaViewGen.h
/// @brief Implementation of Fpga ViewGen interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#ifndef FPGA_VIEW_GEN_H_
#define FPGA_VIEW_GEN_H_

#include <platform/PlatformAPI.h>

#include <bsp/io/fpga/FpgaParameters.h>
#include <bsp/io/fpga/FpgaViewGenConfig.h>

#include <osal/system/Time.h>
#include <osal/threading/Mutex.h>
#include <osal/sync/SoftwareInterrupt.h>

namespace bsp
{


class FpgaViewGen
{

  static void* viewGenTrigger_pv(void* i_Arg_pv);

public:

  FpgaViewGen();

  ~FpgaViewGen();

  bool_t                  initViewGen_b();

  bool_t                  enable_b(bool_t i_Lock_b = true);

  bool_t                  disable_b(bool_t i_Lock_b = true);

public:

  bool_t                  configViewGenDone_b();

  bool_t                  update_b();

  bool_t                  updateNonLock_b();

  void                    free_v();

public:

  ViewGenConfig&          getViewGenConfig_rs();

  bool_t                  getViewGenTrigger_b();

  bool_t                  getHarmonComutationResults_b(uint32_t* o_HarmonComputationResults_pu32);

public:

  /// set read buffer (especially for snapshots)
  bool_t                  setReadBuffer_b(uint8_t i_BufferIdx_u8);

  bool_t                  setProcessViewGen_b();

public:

  bool_t                  isEnabled_b();

  bool_t                  isInitialized_b();

  bool_t                  isConfigViewGenDone_b();

  bool_t                  isProcessingViewGen_b();

public:

  bool_t                  lock_b();

  bool_t                  unlock_b();

public:

  bool_t                  updateDistImm_b();

  bool_t                  updateHarmonizationImm_b();

  /// update MatMul table immediately (without sychronization)
  bool_t                  updateMatMulImm_b();
  /// update MatMul table immediately (without sychronization) and set read buffer (especially for snapshots)
  bool_t                  updateMatMulImmSetReadBuffer_b(uint8_t i_BufferIdx_u8);

  bool_t                  updateSequenceTableImm_b();

private:

  bool_t                  updateViewGen_b();

  bool_t                  updateDistortLut_b();

  bool_t                  updateReadBuffer_b() const;

  bool_t                  updateHarmonization_b() const;

  bool_t                  updateSequenceTable_b() const;

  bool_t                  updateUndist_b() const;

  bool_t                  updateMatMul_b() const;

private:

  /// -------------------------------------------------------------------------------

  osal::Time                         time_o;
  osal::Mutex                        mutex_o;
  osal::Mutex                        lockMutex_o;

  osal::SoftwareInterrupt            softwareInterrupt_o;

  bool_t                             isViewGenEnabled_b;
  bool_t                             isViewGenInitialized_b;
  bool_t                             isDistortionInitialized_b;
  bool_t                             isViewGenLocked_b;
  bool_t                             isViewGenProcessed_b;
  bool_t                             isViewGenConfigDone_b;


  void*                              viewGenConfigBase_pv;
  ViewGenConfig                      viewGenConfig_o;

  uint8_t                            imageBufferViewGenConfig_au8[c_ViewGen3Size_u32];
  ViewGenConfig                      imageViewGenConfig_o;

  uint8_t                            cacheBufferViewGenConfig_au8[c_ViewGen3Size_u32];
  ViewGenConfig                      cacheViewGenConfig_o;

  uint32_t                           underfloorReadBuffer_u32;
};


} // namespace bsp



#endif // FPGA_VIEW_GEN_H_
