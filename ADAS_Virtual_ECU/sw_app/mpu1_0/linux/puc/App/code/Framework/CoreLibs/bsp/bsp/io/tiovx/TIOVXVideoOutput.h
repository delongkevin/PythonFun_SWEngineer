//--------------------------------------------------------------------------
/// @file TIOVXVideoOutput.h
/// @brief Implementation of TIOVX Video Output interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
//  --------------------------------------------------------------------------

#ifndef TIOVX_VIDEO_OUTPUT_H_
#define TIOVX_VIDEO_OUTPUT_H_

#include <platform/PlatformAPI.h>

#include <variants/Enums.h>

//#include <TI/tivx.h>
#include <VX/vx.h>
#include <osal/threading/Thread.h>
#include "osal/threading/Mutex.h"

namespace bsp
{

/// @brief  Number of buffers in a pipeline (tripple buffering? - tbd)
const int32_t   c_MaxDispBuffer_u32 = 3;

class TIOVXVideoOutput
{
public:

  TIOVXVideoOutput();

  ~TIOVXVideoOutput();

  /// @brief	Initialize video output interface
  bool_t    initVideoOutput_b(vx_context i_context_pv);

public:

  void      powerEnable_v() const;

  void      powerDisable_v() const;

  void      setFrameSync_v(bool_t i_Activate_b) const;

  void      switchMode_v(bool_t i_Mode_b) const;

public:

  /// @brief	Get pointer to the frame buffer (writable? not sure)
  uint8_t*  	getVideoOutputBuffer_b(uint32_t i_Index_u32);

  /// @brief  	Wait until output buffer is available (frame triggered)
  bool_t 		waitFrameBuffer_b(uint32_t& o_bufferIdx_u32, uint64_t* o_timestamp_pu64 = NULL);

  /// @brief	Submit current buffer for visualization
  bool_t		submitBuffer_b();

  /// @brief	get current display resolution
  void getResolutionInfo_v(uint32_t& i_width_u32, uint32_t& i_height_u32);

private:
  /// @brief  Display interface creation
  vx_status     createDisplayNode();

  /// @brief  CSI TX output interface creation
  vx_status     createCsiTxNode();

  /// @brief  Create DSS-M2M node
  //vx_status 	tivxHwaDisplayM2M(vx_context context, vx_image in_image, vx_image out_image);
  vx_node tivxHwaDisplayM2M();

private:

  /// -------------------------------------------------------------------------------

  // Conditional variable for various purposes
  Condvar_s             condvar_s;

  // OVX context reference
  vx_context            context_pv;

  // Display graph
  vx_graph              display_pv;

  // Output frames array
  vx_reference          outputImage_apv[c_MaxDispBuffer_u32];
  vx_reference          outputImage_bpv[c_MaxDispBuffer_u32];

  // Display node
  vx_node               displayNode_pv;

  // DSS-M2M graph
  vx_graph               dssm2m_pv;

  // Video buffers descriptors
  uint8_t*				videoBuffer_apv[c_MaxDispBuffer_u32];
  uint8_t*				videoBuffer_bpv[c_MaxDispBuffer_u32];

  // graph initialization completion
  bool_t                initDone_b;

  // Index of last read buffer
  uint32_t				readBufferIdx_u32;

  // Index of last written buffer
  uint32_t				writeBufferIdx_u32;

  // Buffer queue emptiness state
  uint32_t				bufferEmpty_b;

  // Preroll counter
  uint32_t				prerollCount_u32;

  // Module sttate (will probably need that)
  uint32_t				state_t;

  // resolution variant index from table
    uint8_t               resolutionVariant_u8;

    osal::Mutex           mutex_o;
};


} // namespace bsp

#endif // TIOVX_VIDEO_OUTPUT_H_

