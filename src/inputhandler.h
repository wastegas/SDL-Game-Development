#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__

#include <SDL.h>
#include <vector>
#include <pair>
#include <iostream>


class InputHandler
{
 public:
  // joystick functions
  void initialiseJoysticks();
  bool joysticksInitialised() { return m_bJoysticksInitialised; }
  int  xvlaue(int joy, int stick);
  int  yvalue(int joy, int stick);
  bool getButtonState(int joy, int buttonNumber);
  // end joystick
  
  
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
  std::vector<std::pair<Vector2D*, Vectror2D*> m_joystickValues;
  const int m_joystickDeadZone = 10000;
  std::vector<std::vector<bool>> m_buttonStates;
  bool m_bJoysticksInitialised;
  // end joystick 

};

typedef InputHandler TheInputHandler;

#endif // __INPUTHANDLER_H__
