//--------------------------------------------------------------------------
/// @file FpgaParameters_QNX.cpp
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


// PRQA S 1021 EOF // All defines coming from the xparameters provided by FPGA implementation, cannot be changed
// PRQA S 3604 EOF // All defines coming from the xparameters provided by FPGA implementation, cannot be changed


#ifndef FPGA_PARAMETER_QNX_H_
#define FPGA_PARAMETER_QNX_H_

#include "xparameters.h"

namespace bsp
{

  const  uint32_t c_AxiLiteBase_u32 = XPAR_VIDEO_INPUT_MIPI_RX_MIPI_CSI2_RX_SUBSYST_0_BASEADDR;

  const  uint32_t c_AxiLiteSize_u32 = 0xFFFFFU;

  /// -------------------------------------------------------------------------------
  /// Video In

  // Cam 2 Memory

  const  uint32_t c_VideoInCamera0Buffer0_u32        = 0x10000000U;
  const  uint32_t c_VideoInCamera0Buffer1_u32        = 0x112C0000U;

  const  uint32_t c_VideoInCamera1Buffer0_u32        = 0x10320000U;
  const  uint32_t c_VideoInCamera1Buffer1_u32        = 0x115E0000U;

  const  uint32_t c_VideoInCamera2Buffer0_u32        = 0x10640000U;
  const  uint32_t c_VideoInCamera2Buffer1_u32        = 0x11900000U;

  const  uint32_t c_VideoInCamera3Buffer0_u32        = 0x10960000U;
  const  uint32_t c_VideoInCamera3Buffer1_u32        = 0x11C20000U;

  // VIIF

  // Rx Registers

  const  uint32_t c_VideoInGPIO1Offset_u32           = (XPAR_VIDEO_INPUT_GPIO_CTRL_AXI_GPIO_1_BASEADDR      - c_AxiLiteBase_u32);
  const  uint32_t c_VideoInGPIOSerCEBaseOffset_u32   = (XPAR_VIDEO_INPUT_GPIO_CTRL_AXI_GPIO_SER_CE_BASEADDR - c_AxiLiteBase_u32);

  const  uint32_t c_VideoInCsi2RxBase1_u32           = (XPAR_VIDEO_INPUT_MIPI_RX_MIPI_CSI2_RX_SUBSYST_0_BASEADDR - c_AxiLiteBase_u32);
  const  uint32_t c_VideoInCsi2RxBase2_u32           = (XPAR_VIDEO_INPUT_MIPI_RX_MIPI_CSI2_RX_SUBSYST_1_BASEADDR - c_AxiLiteBase_u32);
  const  uint32_t c_VideoInCsi2RxBase3_u32           = (XPAR_VIDEO_INPUT_MIPI_RX_MIPI_CSI2_RX_SUBSYST_2_BASEADDR - c_AxiLiteBase_u32);
  const  uint32_t c_VideoInCsi2RxBase4_u32           = (XPAR_VIDEO_INPUT_MIPI_RX_MIPI_CSI2_RX_SUBSYST_3_BASEADDR - c_AxiLiteBase_u32);
  const  uint32_t c_VideoInCsi2RxBase5_u32           = (XPAR_VIDEO_INPUT_MIPI_RX_MIPI_CSI2_RX_SUBSYST_4_BASEADDR - c_AxiLiteBase_u32);
  const  uint32_t c_VideoInCsi2RxBase6_u32           = (XPAR_VIDEO_INPUT_MIPI_RX_MIPI_CSI2_RX_SUBSYST_5_BASEADDR - c_AxiLiteBase_u32);

  // IRQs
  const uint32_t c_VideoInSyncCtrlIRQ_u32                    = XPAR_FABRIC_SYNC_CTRL_1_INTERRUPT_OUT_INTR;

  /// -------------------------------------------------------------------------------
  /// Algo View

  const  uint32_t c_VideoInAlgoView1Offset_u32       = (XPAR_ALGOVIEW_AXI_LITE_ALGO_1_BASEADDR - c_AxiLiteBase_u32);
  const  uint32_t c_VideoInAlgoView2Offset_u32       = (XPAR_ALGOVIEW_AXI_LITE_ALGO_2_BASEADDR - c_AxiLiteBase_u32);

  const uint32_t c_AlgoViewBufferCount_u32                   = 2U;

  const uint32_t c_AlgoViewBufferWidth_u32                   = 640U;
  const uint32_t c_AlgoViewBufferHeight_u32                  = 400U;

  const uint32_t c_AlgoViewFullBufferWidth_u32               = 1280U;
  const uint32_t c_AlgoViewFullBufferHeight_u32              = 960U;

  const uint32_t c_AlgoViewBuffer0_u32                       = 0x149C2000;
  const uint32_t c_AlgoViewBuffer1_u32                       = 0x14C1A000;
  const uint32_t c_AlgoViewFullBuffer0_u32                   = 0x14800000;
  const uint32_t c_AlgoViewFullBuffer1_u32                   = 0x14A58000;

  /// -------------------------------------------------------------------------------
  /// Video Out

  const  uint32_t c_VideoOutCsi2TxBase_u32           = (XPAR_CSI2TXSS_0_BASEADDR - c_AxiLiteBase_u32);

  /// -------------------------------------------------------------------------------
  /// Axis Mip Mem

  const  uint32_t c_AxisMipMemBase_u32               = (XPAR_VIDEO_INPUT_AXIS_MIP_MEM_0_BASEADDR);

  /// -------------------------------------------------------------------------------
  /// ViewGen

  const  uint32_t c_ViewGen3Base_u32                 = (XPAR_VIEWGEN3_BASEADDR);
  const uint32_t c_ViewGen3Size_u32                          = (XPAR_VIEWGEN3_HIGHADDR - XPAR_VIEWGEN3_BASEADDR) + sizeof(uint8_t);

  const uint32_t c_UndistortPrinciplePointsOffset_u32        = 0x40U;
  const uint32_t c_UndistortPrinciplePointsSize_u32          = 0x4CU - c_UndistortPrinciplePointsOffset_u32 + sizeof(uint32_t);

  const uint32_t c_DistortPrinciplePointsOffset_u32          = 0x80U;
  const uint32_t c_DistortPrinciplePointsSize_u32            = 0xACU - c_DistortPrinciplePointsOffset_u32 + sizeof(uint32_t);

  const uint32_t c_DistortPixelDensityOffset_u32             = 0x100U;
  const uint32_t c_DistortPixelDensitySize_u32               = 0x13CU - c_DistortPixelDensityOffset_u32 + sizeof(uint32_t);

  const uint32_t c_MatMulOffset_u32                          = 0x200U;
  const uint32_t c_MatMulSize_u32                            = 0x3E0U - c_MatMulOffset_u32 + sizeof(uint32_t);

  const uint32_t c_HarmonThresholdOffset_u32                 = 0x400U;
  const uint32_t c_HarmonThresholdSize_u32                   = sizeof(uint32_t);

  const uint32_t c_HarmonApplicationFactorsOffset_u32        = 0x440U;
  const uint32_t c_HarmonApplicationFactorsSize_u32          = 0x454U - c_HarmonApplicationFactorsOffset_u32 + sizeof(uint32_t);

  const uint32_t c_HarmonApplicationOffsetsOffset_u32        = 0x460U;
  const uint32_t c_HarmonApplicationOffsetsSize_u32          = 0x474U - c_HarmonApplicationOffsetsOffset_u32 + sizeof(uint32_t);

  const uint32_t c_HarmonComputationResultsOffset_u32        = 0x600U;
  const uint32_t c_HarmonComputationResultsSize_u32          = 0x77CU - c_HarmonComputationResultsOffset_u32 + sizeof(uint32_t);

  const uint32_t c_StatisticsOffset_u32                      = 0x1000U;
  const uint32_t c_StatisticsSize_u32                        = 0x163CU - c_StatisticsOffset_u32 + sizeof(uint32_t);

  const uint32_t c_SequencingTableOffset_u32                 = 0x4000U;
  const uint32_t c_SequencingTableSize_u32                   = 0x7FFCU - c_SequencingTableOffset_u32 + sizeof(uint32_t);

  const uint32_t c_UndistortLUTOffset_u32                    = 0x10000U;
  const uint32_t c_UndistortLUTSize_u32                      = 0x1FFFCU - c_UndistortLUTOffset_u32 + sizeof(uint32_t);

  const uint32_t c_DistortLUTOffset_u32                      = 0x20000U;
  const uint32_t c_DistortLUTSize_u32                        = 0x2FFFCU - c_DistortLUTOffset_u32 + sizeof(uint32_t);

  const uint32_t c_ViewGenProcessedIRQ_u32                   = XPAR_FABRIC_VIEWGEN3_INTERRUPT_OUT_INTR;

  const  uint32_t c_ViewGenBuffer0_u32               = 0x15000000U;
  const  uint32_t c_ViewGenBuffer1_u32               = 0x15900000U;

  const  uint32_t c_HistoricBuffer18_u32             = 0x19A40000U;

  /// -------------------------------------------------------------------------------
  /// Layer Engine

  const uint8_t c_AlphaLayerCount_u8                         = 3U;
  const uint8_t c_AlphaBufferCount_u8                        = 2U;

  const uint8_t c_OverlayLayerCount_u8                       = 3U;
  const uint8_t c_OverlayBufferCount_u8                      = 2U;

  const uint8_t c_LayerEngineLayerCount_u8                   = (c_AlphaLayerCount_u8 + c_OverlayLayerCount_u8);

  const  uint32_t c_LayerEngineAxiGPIO0Base_u32      = XPAR_OVERLAY_AXI_GPIO_0_BASEADDR;
  const  uint32_t c_LayerEngineBase_u32              = XPAR_OVERLAY_OVERLAY_ENGINE_0_BASEADDR;

  const  uint32_t c_LayerEngineOverlayLayer0_u32     = 0x1A000000U;
  const  uint32_t c_LayerEngineOverlayLayer1_u32     = c_LayerEngineOverlayLayer0_u32 + (1280*720*4); // Layer 0 is used for 3D View which gens one complete frame
  const  uint32_t c_LayerEngineOverlayLayer2_u32     = c_LayerEngineOverlayLayer1_u32 + (1280*720*4);

  const  uint32_t c_LayerEngineOverlayBufferOffset_u32 = 0x02000000U;
  const  uint32_t c_LayerEngineOverlayLayerSize_u32    = 0x00400000U;

};


#endif // FPGA_PARAMETERS_QNX_H_
