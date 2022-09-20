#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <string>
#include "gameobject.h"
#include <config.h>

class Enemy : public GameObject
{
 public:
  void load(int, int, int, int, std::string);
  void draw(SDL_Renderer*);
  void update();
  void clean();
};

#endif // __ENEMY_H__
