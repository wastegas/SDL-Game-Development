#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include <SDL.h>
#include <iostream>
#include <string>
#include "vector2d.h"
#include "loaderparams.h"

class GameObject
{
 public:
  virtual void draw() = 0;
  virtual void update() = 0;
  virtual void clean() = 0;

 protected:
    GameObject(const LoaderParams* pParams){}
  virtual ~GameObject() {}

};

#endif // __GAMEOBECT_H__
