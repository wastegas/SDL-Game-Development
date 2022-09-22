#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__

#include <SDL.h>

class InputHandler
{
 public:
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
  ~InputHandler() {}

  static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;

#endif // __INPUTHANDLER_H__
