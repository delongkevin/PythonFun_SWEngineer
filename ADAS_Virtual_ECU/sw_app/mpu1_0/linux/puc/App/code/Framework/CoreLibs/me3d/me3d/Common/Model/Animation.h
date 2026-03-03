//--------------------------------------------------------------------------                                                                                                           
/// @file Animation.h                                                                         
/// @brief 
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

// PRQA S 2100 EOF // public members used here by design.

#ifndef ANIMATION_H
#define ANIMATION_H

#include "Common/Model/AnimationChannel.h"

namespace me3d
{

struct KeyFrame_s
{
  uint32_t    key_u32;
  Quaternionf rotation_o;
  Vector3f    translation_o;
  Vector3f    scale_o;
};

struct Track_s
{
  uint32_t    boneIndex_u32;
  uint32_t    keyFrameCount_u32;
  KeyFrame_s* keyFrames_apo;
};

class Animation
{
public:
  Animation();
  ~Animation();

  const MEString& getName_ro() const;
  void setName_v(const MEString& i_Name_ro);

  float64_t getTicksPerSec_f64() const;
  void      setTicksPerSec_f64(float64_t i_TicksPerSec_f64);

  float64_t getDuration_f64() const;
  void      setDuration_f64(float64_t i_Duration_f64);

  uint32_t  getNumChannels_u32() const;
  void      setNumChannels_v(uint32_t i_NumChannels_u32);

  AnimationChannel& getAnimationChannel_rs(uint32_t i_Index_u32);

  const AnimationChannel* findAnimationChannel_ps(const MEString& i_NodeName_ro);

  void serialize_v(InOut& b_IO_ro);

private:
  float64_t           duration_f64;
  float64_t           ticksPerSec_f64;
  uint32_t            numChannels_u32;
  AnimationChannel    channels_ao[c_MaxChannels_u32];

  // FBX stuff
public:
  MEString            name_o;
  uint32_t trackCount_u32;
  Track_s* tracks_aps;
  uint32_t startFrame_u32;
  uint32_t endFrame_u32;
};

} // namespace me3d

#endif // ANIMATION_H