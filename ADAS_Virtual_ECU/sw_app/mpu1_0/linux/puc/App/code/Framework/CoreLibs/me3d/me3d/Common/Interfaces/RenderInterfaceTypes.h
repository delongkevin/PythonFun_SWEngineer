#ifndef RENDER_INTERFACE_TYPES_H
#define RENDER_INTERFACE_TYPES_H

#include "Common/GUI/GuiTypes.h"

namespace me3d
{
  enum ObjectType_e
  {
    e_OtTexture = 0,
    e_OtMaterial,
    e_OtRenderTarget,
    e_OtModel,
    e_OtGui,
    e_OtGuideLine,
    e_OtText,
    e_OtBowlView,
    e_OtSingleView,
    e_OtInvalid
  };


} // namespace me3d

#endif
