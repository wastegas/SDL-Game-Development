#ifndef __MENUBUTTON_H__
#define __MENUBUTTON_H__

#include "inputhandler.h"
#include "sdlgameobject.h"

class MenuButton : public SDLGameObject
{
 public:
  MenuButton(const LoaderParams* pParams);

  virtual void draw();
  virtual void update();
  virtual void clean();

 private:
  enum button_state
    {
      MOUSE_OUT = 0,
      MOUSE_OVER = 1,
      CLICKED = 2
    };
};


#endif // __MENUBUTTON_H__
