#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__

#include <SDL.h>
#include <vector>
#include <utility>
#include <iostream>
#include <cstdint>
#include "vector2d.h"

class InputHandler
{
 public:
  enum mouse_buttons
    {
      LEFT = 0,
      MIDDLE = 1,
      RIGHT = 2,
      MOUSE_BUTTON_TOTAL = 3
    };
  
  // joystick functions
  void initialiseJoysticks();
  bool joysticksInitialised() { return m_bJoysticksInitialised; }
  int  xvalue(int joy, int stick);
  int  yvalue(int joy, int stick);
  bool getButtonState(int joy, int buttonNumber);
  // end joystick

  // mouse functions
  bool getMouseButtonState(int buttonNumber);
  Vector2D* getMousePosition();
  // end mouse

  // keyboard functions
  bool isKeyDown(SDL_Scancode key);
  // end keyboard
  
  
  static InputHandler* Instance()
  {
    if (s_pInstance == 0)
      {
	s_pInstance = new InputHandler();
      }
    return s_pInstance;
  }

  void update();
  void clean();

 private:
  InputHandler();
  static InputHandler* s_pInstance;

  // joystick members
  std::vector<SDL_Joystick*> m_joysticks;
  std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
  const int m_joystickDeadZone = 10000;
  std::vector<std::vector<bool>> m_buttonStates;
  bool m_bJoysticksInitialised;
  void onJoystickAxisMove(SDL_Event& event);
  void onJoystickButtonDown(SDL_Event& event);
  void onJoystickButtonUp(SDL_Event& event);
  // end joystick

  // mouse
  std::vector<bool> m_mouseButtonStates;
  Vector2D* m_mousePosition;
  void onMouseMove(SDL_Event& event);
  void onMouseButtonDown(SDL_Event& event);
  void onMouseButtonUp(SDL_Event& event);
  // end mouse

  // keyboard
  const Uint8* m_keystate;
  void onKeyDown();
  void onKeyUp();
  // end keyboard

};

typedef InputHandler TheInputHandler;

#endif // __INPUTHANDLER_H__
