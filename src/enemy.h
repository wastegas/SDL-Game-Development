#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <string>
#include "sdlgameobject.h"
#include <config.h>

class Enemy : public SDLGameObject
{
 public:
  Enemy(const LoaderParams* pParams);

  virtual void draw();
  virtual void update();
  virtual void clean();
};

#endif // __ENEMY_H__
