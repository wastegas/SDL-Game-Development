#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
//#include "gameobject.h"
#include "sdlgameobject.h"

class Player : public SDLGameObject
{
 public:
  Player(const LoaderParams* pParams);

  virtual void draw();
  virtual void update();
  virtual void clean();

};

#endif // __PLAYER_H__
