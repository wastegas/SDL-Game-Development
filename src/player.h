#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "gameobject.h"

class Player : public GameObject
{
 public:
  void load(int, int, int, int, std::string);
  void draw(SDL_Renderer*);
  void update();
  void clean();

};

#endif // __PLAYER_H__
