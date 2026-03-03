#include "OpenGL/Effect/EffectFileSamplerStateBlockGL.h"

#include "OpenGL/Effect/EffectFileTypesGL.h"


// PRQA S 4243 EOF // this is how stl iterators work

namespace me3d
{

EffectFileSamplerStateBlockGL::EffectFileSamplerStateBlockGL()
  : EffectFileSamplerStateBlock()
{

}

EffectFileSamplerStateBlockGL::~EffectFileSamplerStateBlockGL()
{

}

void EffectFileSamplerStateBlockGL::release_v()
{
  filterState_s = FilterState_s();
}

bool_t EffectFileSamplerStateBlockGL::addState_b(const EffectFileSamplerState_s& i_State_rs)
{
  bool_t v_Added_b = EffectFileSamplerStateBlock::addState_b(i_State_rs);
  if (true == v_Added_b)
  {
    if (i_State_rs.type_e == e_EfstFilter)
    {
      filterState_s.filterTypeWasSet_b = true;
      filterState_s.filterType_s       = i_State_rs.value_s;
    }

    if (i_State_rs.type_e == e_EfstMaxAnisotropy)
    {
      filterState_s.anisotropyLevel_u32 = i_State_rs.value_s.uint_u32;
    }
  }

  return v_Added_b;
}

void EffectFileSamplerStateBlockGL::commitStates_v(GLenum i_TextureType_u32, GLuint i_TextureId_u32)
{
  glBindTexture(i_TextureType_u32, i_TextureId_u32);

  for (SamplerStateList_t::iterator v_It_t = states_o.begin(); v_It_t != states_o.end(); ++v_It_t)
  {
    commitState_v(i_TextureType_u32, v_It_t->type_e, v_It_t->value_s);
  }

  // anisotropic filtering needs 2 information, filtering is handled separately
  filterState_s.commitStatesIfNecessary_v(i_TextureType_u32);
}

void EffectFileSamplerStateBlockGL::restoreChangedStates_v(GLenum i_TextureType_u32, GLuint i_TextureId_u32)
{
  glBindTexture(i_TextureType_u32, i_TextureId_u32);

  for (SamplerStateList_t::iterator v_It_t = states_o.begin(); v_It_t != states_o.end(); ++v_It_t)
  {
    commitState_v(i_TextureType_u32, v_It_t->type_e, getRenderStateDefaultValue_s(v_It_t->type_e));
  }

  // Anisotropic filtering needs 2 information, filtering is handled separately
  if (true == filterState_s.filterTypeWasSet_b)
  {
    FilterState_s v_DefaultValues_s;
    v_DefaultValues_s.filterTypeWasSet_b = true;

    v_DefaultValues_s.commitStatesIfNecessary_v(i_TextureType_u32);
  }
}

void EffectFileSamplerStateBlockGL::commitState_v(GLenum i_TextureType_u32, EffectFileStateType_e i_Type_e, const EffectFileStateValue_s& i_Value_rs)
{
  switch(i_Type_e)
  {
  case e_EfstFilter:            // fall through
  case e_EfstMaxAnisotropy:
    {
      // As this is a compound type, is it set separately outside this method
      break;
    }
  case e_EfstAddress:        // Combines e_EfstAddressU, e_EfstAddressV and e_EfstAddressW
    {
      glTexParameteri(i_TextureType_u32, GL_TEXTURE_WRAP_S, effectFileStateValueTypesToGLEnums_u32(i_Value_rs.enum_e));
      glTexParameteri(i_TextureType_u32, GL_TEXTURE_WRAP_T, effectFileStateValueTypesToGLEnums_u32(i_Value_rs.enum_e));

      Assert(getGLError_b() == false);

      break;
    }
  case e_EfstAddressU:
    {
      glTexParameteri(i_TextureType_u32, GL_TEXTURE_WRAP_S, effectFileStateValueTypesToGLEnums_u32(i_Value_rs.enum_e));
      Assert(getGLError_b() == false);

      break;
    }
  case e_EfstAddressV:
    {
      glTexParameteri(i_TextureType_u32, GL_TEXTURE_WRAP_T, effectFileStateValueTypesToGLEnums_u32(i_Value_rs.enum_e));
      Assert(getGLError_b() == false);

      break;
    }
  case e_EfstAddressW:
    {
      AssertFunction(false, "not supported in OpenGL ES 2.0 only in 3.0"); 

      break;
    }
  case e_EfstComparisonFunc:
    {
      // TODO: check EXT
      if(i_Value_rs.enum_e == e_EfsvAlways)
      {
        // Disable Comparison
        glTexParameteri(i_TextureType_u32, GL_TEXTURE_COMPARE_MODE_EXT, GL_NONE);
      }
      else
      {
        // Enable Comparison
        glTexParameteri(i_TextureType_u32, GL_TEXTURE_COMPARE_MODE_EXT, GL_COMPARE_REF_TO_TEXTURE_EXT);

        // Set Compare Func
        glTexParameteri(i_TextureType_u32, GL_TEXTURE_COMPARE_FUNC_EXT, effectFileStateValueTypesToGLEnums_u32(i_Value_rs.enum_e));
      }

      Assert(getGLError_b() == false);

      break;
    }
  case e_EfstMipLodBias:
    {
      AssertFunction(false, "not supported in OpenGL ES"); 
      break;
    }
  case e_EfstMinLod:
  case e_EfstMaxLod:
    {
      AssertFunction(false, "not supported in OpenGL ES 2.0 only in 3.0"); 
      break;
    }
  default:
    {
      AssertFunction(false, "Unknown Sampler State Type: %i\n", i_Type_e);
      break;
    }
  }
}

// --- Filter State struct --- 
EffectFileSamplerStateBlockGL::FilterState_s::FilterState_s()
  : filterTypeWasSet_b(true)
{
  filterType_s = getRenderStateDefaultValue_s(e_EfstFilter);
  anisotropyLevel_u32 = getRenderStateDefaultValue_s(e_EfstMaxAnisotropy).uint_u32;
}

void EffectFileSamplerStateBlockGL::FilterState_s::commitStatesIfNecessary_v(GLenum i_TextureType_u32)const
{
  if (filterTypeWasSet_b)
  {
    switch (filterType_s.enum_e)
    {
    case e_EfsvLinear:
      {
        glTexParameteri(i_TextureType_u32, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(i_TextureType_u32, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        Assert(getGLError_b() == false);
      }
      break;
    case e_EfsvPoint:
      {
        glTexParameteri(i_TextureType_u32, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(i_TextureType_u32, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        Assert(getGLError_b() == false);
      }
      break;
    case e_EfsvAnisotropic:
      {
        glTexParameteri(i_TextureType_u32, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(i_TextureType_u32, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Theoretically it is possible, that anisotropy is not supported. Technically every GPU supports it.
        //if (TODO: CHECK EXT_texture_filter_anisotropic)
        //{
        glTexParameterf(i_TextureType_u32, GL_TEXTURE_MAX_ANISOTROPY_EXT, static_cast<float32_t>(anisotropyLevel_u32));
        //}


        Assert(getGLError_b() == false);
      }
      break;
    default:
      {
        AssertFunction(false, "Undefined Filter-Mode");
      }
      break;
    }
  }
}

} // namespace me3d