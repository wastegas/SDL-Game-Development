#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include <SDL.h>
#include <iostream>
#include <string>
#include "texturemanager.h"

class GameObject
{
 public:
  virtual void load(int, int, int, int, std::string);
  virtual void draw(SDL_Renderer*);
  virtual void update();
  virtual void clean() { std::cout << "gameobject clean" << std::endl; }

 protected:
  std::string m_textureID;

  int m_currentFrame;
  int m_currentRow;
  
  int m_x;
  int m_y;

  int m_width;
  int m_height;
};

#endif // __GAMEOBECT_H__
