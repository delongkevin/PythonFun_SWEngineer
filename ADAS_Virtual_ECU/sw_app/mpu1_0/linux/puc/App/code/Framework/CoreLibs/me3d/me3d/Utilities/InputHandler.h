//--------------------------------------------------------------------------                                                                                                           
/// @file InputHandler.h                                                                         
/// @brief Tracks Keyboard and Mouse state
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "MeclTypeDefs.h"

namespace me3d
{
  enum Keys_e
  {
    e_KeyW,
    e_KeyA,
    e_KeyS,
    e_KeyD,
    e_KeyQ,
    e_KeyE,
    e_Key1,
    e_Key2,
    e_Key3,
    e_Key4,
    e_Key5,
    e_Key6,
    e_Key7,
    e_Key8,
    e_KeyLeft,
    e_KeyRight,
    e_KeyUp,
    e_KeyDown,
    e_KeyCount
  };

  enum Buttons_e
  {
    e_ButtonLeft,
    e_ButtonRight,
    e_ButtonCount
  };

  class InputHandler 
  {
  public:
    InputHandler();

    bool_t isKeyDown_b(Keys_e i_Key_e) const;
    bool_t isButtonDown_b(Buttons_e i_Button_e) const;

    void setKeyDown(Keys_e i_Key_e, bool_t i_Down_b);
    void setButtonDown(Buttons_e i_Button_e, bool_t i_Down_b);
    void setMousePos(uint16_t i_MouseX_u16, uint16_t i_MouseY_u16);
    void resetMouseDelta_v();
    void setMouseWheelDelta_v(float32_t i_Delta_f32);

    float32_t getMouseWheelDelta_f32() const;
    float32_t getMouseDeltaX_f32() const;
    float32_t getMouseDeltaY_f32() const;

    Vector2f getMousePos_o() const;

  private:
    bool_t keyMap_ab[e_KeyCount];
    bool_t btnMap_ab[e_ButtonCount];


    uint16_t mouseX_u16;
    uint16_t mouseY_u16;

    float32_t mouseDeltaX_f32;
    float32_t mouseDeltaY_f32;

    float32_t mouseWheelDelta_f32;
  };

}

#endif