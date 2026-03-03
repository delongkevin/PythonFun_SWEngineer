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

#ifndef ANIMATION_CHANNEL_H
#define ANIMATION_CHANNEL_H

#include "RenderEngineCfg.h"
#include "MeclTypeDefs.h"
#include "Utilities/InOut.h"
// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{

struct Vector3Key_s
{
  float32_t time_f32;
  Vector3f  value_o;

  void serialize_v(InOut& b_IO_ro)
  {
    b_IO_ro.serialize_v(time_f32);
    b_IO_ro.serialize_v(value_o);
  }
};

struct QuaternionKey_s
{
  float32_t   time_f32;
  Quaternionf value_o;

  friend bool operator < (const QuaternionKey_s& p1, const QuaternionKey_s& p2)
  {
	bool_t v_RetVal_b = false;  
    if (p1.time_f32 < p2.time_f32)
	{
      v_RetVal_b = true;
	}
	else
	{
	}
	return v_RetVal_b;
  }

  void serialize_v(InOut& b_IO_ro)
  {
    b_IO_ro.serialize_v(time_f32);
    b_IO_ro.serialize_v(value_o);
  }
};

class AnimationChannel
{

public:
  AnimationChannel();
  ~AnimationChannel();

  void setName_v(const MEString& i_Name_ro);
  const MEString& getName_ro() const;

  void setNumPosKeys_v(uint32_t i_NumPosKeys_u32);
  void setNumRotKeys_v(uint32_t i_NumRotKeys_u32);
  void setNumScaleKeys_v(uint32_t i_NumScaleKeys_u32);

  uint32_t getNumPosKeys_u32() const;
  uint32_t getNumRotKeys_u32() const;
  uint32_t getNumScaleKeys_u32() const;

  Vector3Key_s& getPosKey_rs(uint32_t i_Index_u32);
  QuaternionKey_s& getRotKey_rs(uint32_t i_Index_u32);
  Vector3Key_s& getScaleKey_rs(uint32_t i_Index_u32);

  void getTransformMatrix_v(me3d::Matrix4f& o_Transform_ro, float32_t i_AnimationTime_f32) const;
  void calcInterpolatedScaling_v(me3d::Vector3f& o_Scaling_ro, float32_t i_AnimationTime_f32) const;
  void calcInterpolatedRotation_v(me3d::Quaternionf& o_Rotation_ro, float32_t i_AnimationTime_f32) const;
  void calcInterpolatedPosition_v(me3d::Vector3f& o_Position_ro, float32_t i_AnimationTime_f32) const;

  uint32_t findScaling_u32(float32_t i_AnimationTime_f32) const;
  uint32_t findRotation_u32(float32_t i_AnimationTime_f32) const;
  uint32_t findPosition_u32(float32_t i_AnimationTime_f32) const;

  void serialize_v(InOut& b_IO_ro);

private:
  MEString        name_o;
  uint32_t        numPosKeys_u32;
  uint32_t        numRotKeys_u32;
  uint32_t        numScaleKeys_u32;
  Vector3Key_s    posKeys_ao[c_MaxChannelKeys_u32];
  QuaternionKey_s rotKeys_ao[c_MaxChannelKeys_u32];
  Vector3Key_s    scaleKeys_ao[c_MaxChannelKeys_u32];

};


} // namespace me3d

#endif // ANIMATION_H