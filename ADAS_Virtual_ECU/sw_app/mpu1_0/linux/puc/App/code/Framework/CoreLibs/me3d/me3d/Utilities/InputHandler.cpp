#include "InputHandler.h"

namespace me3d
{

InputHandler::InputHandler()
  : mouseX_u16(0U)
  , mouseY_u16(0U)
  , mouseDeltaX_f32(0.0F)
  , mouseDeltaY_f32(0.0F)
  , mouseWheelDelta_f32(0.0F)
{
}

bool_t InputHandler::isKeyDown_b(Keys_e i_Key_e) const
{
  return keyMap_ab[i_Key_e];
}

bool_t InputHandler::isButtonDown_b(Buttons_e i_Button_e) const
{
  return btnMap_ab[i_Button_e];
}

void InputHandler::setKeyDown(Keys_e i_Key_e, bool_t i_Down_b)
{
  keyMap_ab[i_Key_e] = i_Down_b;
}

void InputHandler::setButtonDown(Buttons_e i_Button_e, bool_t i_Down_b)
{
  btnMap_ab[i_Button_e] = i_Down_b;
}

void InputHandler::setMousePos(uint16_t i_MouseX_u16, uint16_t i_MouseY_u16)
{
  mouseDeltaX_f32 = static_cast<float32_t>(mouseX_u16 - i_MouseX_u16);
  mouseDeltaY_f32 = static_cast<float32_t>(mouseY_u16 - i_MouseY_u16);

  mouseX_u16 = i_MouseX_u16;
  mouseY_u16 = i_MouseY_u16;
}

float32_t InputHandler::getMouseDeltaX_f32() const
{
  return mouseDeltaX_f32;
}

float32_t InputHandler::getMouseDeltaY_f32() const
{
  return mouseDeltaY_f32;
}

me3d::Vector2f InputHandler::getMousePos_o() const
{
  Vector2f v_MousePos_o;
  v_MousePos_o(0) = static_cast<float32_t>(mouseX_u16);
  v_MousePos_o(1) = static_cast<float32_t>(mouseY_u16);
  return v_MousePos_o;
}

void InputHandler::resetMouseDelta_v()
{
  mouseDeltaX_f32 = 0.0F; 
  mouseDeltaY_f32 = 0.0F;
  mouseWheelDelta_f32 = 0.0F;
}

void InputHandler::setMouseWheelDelta_v(float32_t i_Delta_f32)
{
  mouseWheelDelta_f32 = i_Delta_f32;
}

float32_t InputHandler::getMouseWheelDelta_f32() const
{
  return mouseWheelDelta_f32;
}

} // namespace me3d