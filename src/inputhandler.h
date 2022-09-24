#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__

#include <SDL.h>
#include <vector>
#include <pair>
#include <iostream>


class InputHandler
{
 public:
  void initialiseJoysticks();
  bool joysticksInitialised() { return m_bJoysticksInitialised; }
  int  xvlaue(int joy, int stick);
  int  yvalue(int joy, int stick);
  
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
  
  std::vector<SDL_Joystick*> m_joysticks;
  std::vector<std::pair<Vector2D*, Vectror2D*> m_joystickValues;
  const int m_joystickDeadZone = 10000;

  bool m_bJoysticksInitialised;


};

typedef InputHandler TheInputHandler;

#endif // __INPUTHANDLER_H__
