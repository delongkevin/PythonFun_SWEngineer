#ifndef EFFECT_FILE_TYPES_GL_H
#define EFFECT_FILE_TYPES_GL_H

#include "Common/Effect/EffectFileTypes.h"
#include "OpenGL/GLIncludes.h"

namespace me3d
{

static GLenum effectFileStateValueTypesToGLEnums_u32(EffectFileStateValueType_e i_Type_e)
{
  GLenum v_Enm_u32 = 0U;

  switch (i_Type_e)
  {
  case e_EfsvFalse:             { v_Enm_u32 = GL_FALSE;                 } break;
  case e_EfsvTrue:              { v_Enm_u32 = GL_TRUE;                  } break;

    // Alpha Function
  case e_EfsvNever:             { v_Enm_u32 = GL_NEVER;                 } break;
  case e_EfsvLess:              { v_Enm_u32 = GL_LESS;                  } break;
  case e_EfsvEqual:             { v_Enm_u32 = GL_EQUAL;                 } break;
  case e_EfsvLEqual:            { v_Enm_u32 = GL_LEQUAL;                } break;
  case e_EfsvGreater:           { v_Enm_u32 = GL_GREATER;               } break;
  case e_EfsvNotEqual:          { v_Enm_u32 = GL_NOTEQUAL;              } break;
  case e_EfsvGEqual:            { v_Enm_u32 = GL_GEQUAL;                } break;
  case e_EfsvAlways:            { v_Enm_u32 = GL_ALWAYS;                } break;

    // Blending Operations
  case e_EfsvAdd:               { v_Enm_u32 = GL_FUNC_ADD;              } break;
  case e_EfsvSubtract:          { v_Enm_u32 = GL_FUNC_SUBTRACT;         } break;
  case e_EfsvRevSubtract:       { v_Enm_u32 = GL_FUNC_REVERSE_SUBTRACT; } break;
  case e_EfsvMin:               { v_Enm_u32 = GL_MIN;                   } break;
  case e_EfsvMax:               { v_Enm_u32 = GL_MAX;                   } break;

    // Blending Factor
  case e_EfsvZero:              { v_Enm_u32 = GL_ZERO;                  } break;
  case e_EfsvOne:               { v_Enm_u32 = GL_ONE;                   } break;
  case e_EfsvSrcColor:          { v_Enm_u32 = GL_SRC_COLOR;             } break;
  case e_EfsvOneMinusSrcColor:  { v_Enm_u32 = GL_ONE_MINUS_SRC_COLOR;   } break;
  case e_EfsvSrcAlpha:          { v_Enm_u32 = GL_SRC_ALPHA;             } break;
  case e_EfsvOneMinusSrcAlpha:  { v_Enm_u32 = GL_ONE_MINUS_SRC_ALPHA;   } break;
  case e_EfsvDstAlpha:          { v_Enm_u32 = GL_DST_ALPHA;             } break;
  case e_EfsvOneMinusDstAlpha:  { v_Enm_u32 = GL_ONE_MINUS_DST_ALPHA;   } break;
  case e_EfsvDstColor:          { v_Enm_u32 = GL_DST_COLOR;             } break;
  case e_EfsvOneMinusDstColor:  { v_Enm_u32 = GL_ONE_MINUS_DST_COLOR;   } break;
  case e_EfsvSrcAlphaSaturate:  { v_Enm_u32 = GL_SRC_ALPHA_SATURATE;    } break;

    // Cull Face Mode
  case e_EfsvCW:                { v_Enm_u32 = GL_FRONT;                 } break;
  case e_EfsvCCW:               { v_Enm_u32 = GL_BACK;                  } break;
  case e_EfsvNone:              { v_Enm_u32 = 0U;                       } break; // has multiple meanings

    // Stencil Operation
  case e_EfsvKeep:              { v_Enm_u32 = GL_KEEP;                  } break;
  case e_EfsvReplace:           { v_Enm_u32 = GL_REPLACE;               } break;
  case e_EfsvIncr:              { v_Enm_u32 = GL_INCR;                  } break;
  case e_EfsvDecr:              { v_Enm_u32 = GL_DECR;                  } break;
  case e_EfsvInvert:            { v_Enm_u32 = GL_INVERT;                } break;

    // Fill Mode (No GL FILL and LINE in GLES 2.0
  case e_EfsvSolid:             { v_Enm_u32 = 0U; Assert(false);        } break;
  case e_EfsvWireFrame:         { v_Enm_u32 = 0U; Assert(false);        } break;

    // AddressMode
  case e_EfsvWrap:              { v_Enm_u32 = GL_REPEAT;                } break;
  case e_EfsvClamp:             { v_Enm_u32 = GL_CLAMP_TO_EDGE;         } break;
  case e_EfsvMirror:            { v_Enm_u32 = GL_MIRRORED_REPEAT;       } break;
  case e_EfsvBorder:            { v_Enm_u32 = GL_CLAMP_TO_BORDER_OES;   } break;

    // Filter
  case e_EfsvPoint:             { v_Enm_u32 = 0U;                       } break;
  case e_EfsvLinear:            { v_Enm_u32 = 0U;                       } break;
  case e_EfsvAnisotropic:       { v_Enm_u32 = 0U;                       } break;

  case e_EfsvCount:             // fall through
  default:                      { v_Enm_u32 = 0U; Assert(false);        } break;
  }

  return v_Enm_u32;
}


} // namespace me3d

#endif
