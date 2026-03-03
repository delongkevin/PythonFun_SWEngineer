//--------------------------------------------------------------------------
/// @file FpgaParameters_Rtos.cpp
/// @brief Definitions for FPGA Registers and Offsets
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#ifndef FPGA_PARAMETERS_RTOS_H_
#define FPGA_PARAMETERS_RTOS_H_

namespace bsp
{


const uint32_t c_AxiLiteBase_u32 = 0U;

const uint32_t c_AxiLiteSize_u32 = 0U;

/// -------------------------------------------------------------------------------
/// Video In

const uint32_t c_VideoInGPIO1Offset_u32           = 0U;
const uint32_t c_VideoInGPIOSerCEBaseOffset_u32   = 0U;

const uint32_t c_VideoInVIIFBaseOffset_u32        = 0U;

const uint32_t c_VideoInCsi2RxBase1_u32           = 0U;
const uint32_t c_VideoInCsi2RxBase2_u32           = 0U;
const uint32_t c_VideoInCsi2RxBase3_u32           = 0U;
const uint32_t c_VideoInCsi2RxBase4_u32           = 0U;
const uint32_t c_VideoInCsi2RxBase5_u32           = 0U;
const uint32_t c_VideoInCsi2RxBase6_u32           = 0U;

/// -------------------------------------------------------------------------------
/// Algo View

const uint32_t c_VideoInAlgoView1Offset_u32       = 0U;
const uint32_t c_VideoInAlgoView2Offset_u32       = 0U;

const uint32_t c_AlgoViewBufferCount_u32                   = 0U;

const uint32_t c_AlgoViewBufferWidth_u32                   = 0U;
const uint32_t c_AlgoViewBufferHeight_u32                  = 0U;

const uint32_t c_AlgoViewFullBufferWidth_u32               = 0U;
const uint32_t c_AlgoViewFullBufferHeight_u32              = 0U;

const uint32_t c_AlgoViewBuffer0_u32                       = 0U;
const uint32_t c_AlgoViewBuffer1_u32                       = 0U;
const uint32_t c_AlgoViewFullBuffer0_u32                   = 0U;
const uint32_t c_AlgoViewFullBuffer1_u32                   = 0U;

/// -------------------------------------------------------------------------------
/// Video Out

const uint32_t c_VideoOutCsi2TxBase_u32           = 0U;

/// -------------------------------------------------------------------------------
/// ViewGen

const uint32_t c_ViewGen3Base_u32                 = 0U;
const uint32_t          c_ViewGen3Size_u32                 = 0x40000U;


const uint32_t c_UndistortPrinciplePointsOffset_u32        = 0x40;
const uint32_t c_UndistortPrinciplePointsSize_u32          = 0x4C - c_UndistortPrinciplePointsOffset_u32 + sizeof(uint32_t);

const uint32_t c_DistortPrinciplePointsOffset_u32          = 0x80;
const uint32_t c_DistortPrinciplePointsSize_u32            = 0xAC - c_DistortPrinciplePointsOffset_u32 + sizeof(uint32_t);

const uint32_t c_DistortPixelDensityOffset_u32             = 0x100;
const uint32_t c_DistortPixelDensitySize_u32               = 0x13C - c_DistortPixelDensityOffset_u32 + sizeof(uint32_t);

const uint32_t c_MatMulOffset_u32                          = 0x200;
const uint32_t c_MatMulSize_u32                            = 0x3E0 - c_MatMulOffset_u32 + sizeof(uint32_t);

const uint32_t c_StatisticsOffset_u32                      = 0x800;
const uint32_t c_StatisticsSize_u32                        = 0xB3C - c_StatisticsOffset_u32 + sizeof(uint32_t);

const uint32_t c_HarmonThresholdOffset_u32                 = 0x400U;
const uint32_t c_HarmonApplicationFactorsOffset_u32        = 0x440U;
const uint32_t c_HarmonApplicationOffsetsOffset_u32        = 0x460U;
const uint32_t c_HarmonComputationResultsOffset_u32        = 0x480U;

const uint32_t c_SequencingTableOffset_u32                 = 0x4000;
const uint32_t c_SequencingTableSize_u32                   = 0x7FFC - c_SequencingTableOffset_u32 + sizeof(uint32_t);

const uint32_t c_UndistortLUTOffset_u32                    = 0x10000;
const uint32_t c_UndistortLUTSize_u32                      = 0x1FFFC - c_UndistortLUTOffset_u32 + sizeof(uint32_t);

const uint32_t c_DistortLUTOffset_u32                      = 0x20000;
const uint32_t c_DistortLUTSize_u32                        = 0x2FFFC - c_DistortLUTOffset_u32 + sizeof(uint32_t);

/// -------------------------------------------------------------------------------
/// Layer Engine

const uint8_t c_LayerEngineLayerCount_u8                   = 6U;

const uint8_t c_AlphaLayerCount_u8                         = 3U;
const uint8_t c_AlphaBufferCount_u8                        = 2U;

const uint8_t c_OverlayLayerCount_u8                       = 3U; // 3U
const uint8_t c_OverlayBufferCount_u8                      = 2U;

const uint32_t c_LayerEngineAxiGPIO0Base_u32      = 0U;
const uint32_t c_LayerEngineBase_u32              = 0U;

}; // namespace bsp


#endif // FPGA_PARAMETERS_RTOS_H_
