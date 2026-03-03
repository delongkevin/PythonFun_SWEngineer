#include "Common/Model/AnimationChannel.h"
#include "Math/Transform.h"
#include "Math/MathLib.h"

namespace me3d
{
  AnimationChannel::AnimationChannel() 
    : name_o("")
    , numPosKeys_u32(0U)
    , numRotKeys_u32(0U)
    , numScaleKeys_u32(0U)
  {
  }

  AnimationChannel::~AnimationChannel()
  {
    // PRQA S 4631 1 // safe here
    name_o            = "";
    numPosKeys_u32    = 0U;
    numRotKeys_u32    = 0U;
    numScaleKeys_u32  = 0U;
  }

  void AnimationChannel::setName_v(const MEString& i_Name_ro)
  {
    name_o = i_Name_ro;
  }

  const MEString& AnimationChannel::getName_ro() const
  {
    return name_o;
  }

  void AnimationChannel::setNumPosKeys_v(uint32_t i_NumPosKeys_u32)
  {
    numPosKeys_u32 = i_NumPosKeys_u32;
  }

  void AnimationChannel::setNumRotKeys_v(uint32_t i_NumRotKeys_u32)
  {
    numRotKeys_u32 = i_NumRotKeys_u32;
  }

  void AnimationChannel::setNumScaleKeys_v(uint32_t i_NumScaleKeys_u32)
  {
    numScaleKeys_u32 = i_NumScaleKeys_u32;
  }

  uint32_t AnimationChannel::getNumPosKeys_u32() const
  {
    return numPosKeys_u32;
  }

  uint32_t AnimationChannel::getNumRotKeys_u32() const
  {
    return numRotKeys_u32;
  }

  uint32_t AnimationChannel::getNumScaleKeys_u32() const
  {
    return numScaleKeys_u32;
  }

  Vector3Key_s& AnimationChannel::getPosKey_rs(uint32_t i_Index_u32)
  {
    Assert(i_Index_u32 < c_MaxChannelKeys_u32);
    return posKeys_ao[i_Index_u32];
  }

  QuaternionKey_s& AnimationChannel::getRotKey_rs(uint32_t i_Index_u32)
  {
    Assert(i_Index_u32 < c_MaxChannelKeys_u32);
    return rotKeys_ao[i_Index_u32];
  }

  Vector3Key_s& AnimationChannel::getScaleKey_rs(uint32_t i_Index_u32)
  {
    Assert(i_Index_u32 < c_MaxChannelKeys_u32);
    return scaleKeys_ao[i_Index_u32];
  }

  void AnimationChannel::getTransformMatrix_v(me3d::Matrix4f& o_Transform_ro, float32_t i_AnimationTime_f32) const
  {
    Transform v_ChannelTransform_o;

    // Interpolate scaling and generate scaling transformation matrix
    me3d::Vector3f v_Scaling_o;
    calcInterpolatedScaling_v(v_Scaling_o, i_AnimationTime_f32);
    v_ChannelTransform_o.setScale_v(v_Scaling_o);

    // Interpolate rotation and generate rotation transformation matrix
    me3d::Quaternionf v_RotationQuat_o;
    calcInterpolatedRotation_v(v_RotationQuat_o, i_AnimationTime_f32);    
    v_ChannelTransform_o.setRotation_v(v_RotationQuat_o);

    // Interpolate translation and generate translation transformation matrix
    me3d::Vector3f v_Translation_o;
    calcInterpolatedPosition_v(v_Translation_o, i_AnimationTime_f32);
    v_ChannelTransform_o.setTranslation_v(v_Translation_o);

    // compute SRT Transformation (scale * rotate * translate)
    o_Transform_ro = v_ChannelTransform_o.getWorldMatrix_ro();
  }

  void AnimationChannel::calcInterpolatedScaling_v(me3d::Vector3f& o_Scaling_ro, float32_t i_AnimationTime_f32) const
  {
    if (numScaleKeys_u32 == 1) 
    {
      o_Scaling_ro = scaleKeys_ao[0].value_o;
    }
    else
    {
      uint32_t v_ScalingIndex_u32 = findScaling_u32(i_AnimationTime_f32);
      uint32_t v_NextScalingIndex_u32 = (v_ScalingIndex_u32 + 1);
      Assert(v_NextScalingIndex_u32 < numScaleKeys_u32);

      float32_t v_DeltaTime_f32 = static_cast<float32_t>(scaleKeys_ao[v_NextScalingIndex_u32].time_f32 - scaleKeys_ao[v_ScalingIndex_u32].time_f32);
      float32_t v_Factor_f32 = (i_AnimationTime_f32 - static_cast<float32_t>(scaleKeys_ao[v_ScalingIndex_u32].time_f32)) / v_DeltaTime_f32;
      Assert((v_Factor_f32 >= 0.0f) && (v_Factor_f32 <= 1.0f));

      const me3d::Vector3f& c_Start_ro = scaleKeys_ao[v_ScalingIndex_u32].value_o;
      const me3d::Vector3f& c_End_ro   = scaleKeys_ao[v_NextScalingIndex_u32].value_o;
      me3d::Vector3f v_Delta_o = static_cast<me3d::Vector3f>(c_End_ro - c_Start_ro);

      o_Scaling_ro = c_Start_ro + (v_Delta_o * v_Factor_f32);
    }
  }

  void AnimationChannel::calcInterpolatedRotation_v(me3d::Quaternionf& o_Rotation_ro, float32_t i_AnimationTime_f32) const
  {
    // we need at least two values to interpolate...
    if (numRotKeys_u32 == 1) 
    {
      o_Rotation_ro = rotKeys_ao[0].value_o;
    }
    else
    {
      uint32_t v_RotationIndex_u32 = findRotation_u32(i_AnimationTime_f32);
      uint32_t v_NextRotationIndex_u32 = (v_RotationIndex_u32 + 1);
      Assert(v_NextRotationIndex_u32 < numRotKeys_u32);

      float32_t v_DeltaTime_f32 = static_cast<float32_t>(rotKeys_ao[v_NextRotationIndex_u32].time_f32 - rotKeys_ao[v_RotationIndex_u32].time_f32);
      float32_t v_Factor_f32 = (i_AnimationTime_f32 - static_cast<float32_t>(rotKeys_ao[v_RotationIndex_u32].time_f32)) / v_DeltaTime_f32;
      Assert((v_Factor_f32 >= 0.0f) && (v_Factor_f32 <= 1.0f));

      const me3d::Quaternionf& c_StartRotation_ro = rotKeys_ao[v_RotationIndex_u32].value_o;
      const me3d::Quaternionf& c_EndRotation_ro   = rotKeys_ao[v_NextRotationIndex_u32].value_o;  

      o_Rotation_ro = quaternionSlerp(c_StartRotation_ro, c_EndRotation_ro, v_Factor_f32);
      o_Rotation_ro.normalize();
    }
  }

  void AnimationChannel::calcInterpolatedPosition_v(me3d::Vector3f& o_Position_ro, float32_t i_AnimationTime_f32) const
  {
    if (numPosKeys_u32 == 1) 
    {
      o_Position_ro = posKeys_ao[0].value_o;
    }
    else
    {
      uint32_t v_PositionIndex_u32 = findPosition_u32(i_AnimationTime_f32);
      uint32_t v_NextPositionIndex_u32 = (v_PositionIndex_u32 + 1);
      Assert(v_NextPositionIndex_u32 < numPosKeys_u32);

      float32_t v_DeltaTime_f32 = static_cast<float32_t>(posKeys_ao[v_NextPositionIndex_u32].time_f32 - posKeys_ao[v_PositionIndex_u32].time_f32);
      float32_t v_Factor_f32    = (i_AnimationTime_f32 - static_cast<float32_t>(posKeys_ao[v_PositionIndex_u32].time_f32)) / v_DeltaTime_f32;
      Assert((v_Factor_f32 >= 0.0f) && (v_Factor_f32 <= 1.0f));

      const me3d::Vector3f& c_Start_ro = posKeys_ao[v_PositionIndex_u32].value_o;
      const me3d::Vector3f& c_End_ro   = posKeys_ao[v_NextPositionIndex_u32].value_o;
      me3d::Vector3f v_Delta_o = static_cast<me3d::Vector3f>(c_End_ro - c_Start_ro);

      o_Position_ro = c_Start_ro + (v_Delta_o * v_Factor_f32);
    }
  }

  uint32_t AnimationChannel::findScaling_u32(float32_t i_AnimationTime_f32) const
  {
    Assert(numScaleKeys_u32 > 0);

    uint32_t v_ReturnIndex_u32 = numScaleKeys_u32;

    for (uint32_t v_I_u32 = 0; v_I_u32 < (numScaleKeys_u32 - 1); ++v_I_u32) 
    {
      if (i_AnimationTime_f32 < static_cast<float32_t>(scaleKeys_ao[v_I_u32 + 1].time_f32)) 
      {
        v_ReturnIndex_u32 = v_I_u32;
        break;
      }
    }

    Assert(v_ReturnIndex_u32 < numScaleKeys_u32);
    return v_ReturnIndex_u32;
  }

  uint32_t AnimationChannel::findRotation_u32(float32_t i_AnimationTime_f32) const
  {
    Assert(numRotKeys_u32 > 0);

    uint32_t v_ReturnIndex_u32 = numRotKeys_u32;

    for (uint32_t v_I_u32 = 0; v_I_u32 < (numRotKeys_u32 - 1); ++v_I_u32) 
    {
      if (i_AnimationTime_f32 < static_cast<float32_t>(rotKeys_ao[v_I_u32 + 1].time_f32)) 
      {
        v_ReturnIndex_u32 = v_I_u32;
        break;
      }
    }

    Assert(v_ReturnIndex_u32 < numRotKeys_u32);
    return v_ReturnIndex_u32;
  }

  uint32_t AnimationChannel::findPosition_u32(float32_t i_AnimationTime_f32) const
  {
    Assert(numPosKeys_u32 > 0);

    uint32_t v_ReturnIndex_u32 = numPosKeys_u32;

    for (uint32_t v_I_u32 = 0; v_I_u32 < (numPosKeys_u32 - 1); ++v_I_u32) 
    {
      if (i_AnimationTime_f32 < static_cast<float32_t>(posKeys_ao[v_I_u32 + 1].time_f32)) 
      {
        v_ReturnIndex_u32 = v_I_u32;
        break;
      }
    }

    Assert(v_ReturnIndex_u32 < numPosKeys_u32);
    return v_ReturnIndex_u32;
  }

  void AnimationChannel::serialize_v(InOut& b_IO_ro)
  {
    b_IO_ro.serialize_v(numPosKeys_u32);
    b_IO_ro.serialize_v(numRotKeys_u32);
    b_IO_ro.serialize_v(numScaleKeys_u32);

    for (uint32_t v_I_u32 = 0U; v_I_u32 < numPosKeys_u32; ++v_I_u32)
    {
      posKeys_ao[v_I_u32].serialize_v(b_IO_ro);
    }

    for (uint32_t v_I_u32 = 0U; v_I_u32 < numRotKeys_u32; ++v_I_u32)
    {
      rotKeys_ao[v_I_u32].serialize_v(b_IO_ro);
    }

    for (uint32_t v_I_u32 = 0U; v_I_u32 < numScaleKeys_u32; ++v_I_u32)
    {
      scaleKeys_ao[v_I_u32].serialize_v(b_IO_ro);
    }

    b_IO_ro.serialize_v(name_o);
  }

} // namespace me3d