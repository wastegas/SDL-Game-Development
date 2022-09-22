#ifndef __SDLGAMEOBJECT_H__
#define __SDLGAMEOBJECT_H__

#include "game.h"
#include "loaderparams.h"
#include "texturemanager.h"
#include "gameobject.h"

class SDLGameObject : public GameObject
{
 public:
  SDLGameObject(const LoaderParams* pParams);

  virtual void draw();
  virtual void update();
  virtual void clean();

 protected:
  int m_x;
  int m_y;
  
  int m_width;
  int m_height;

  int m_currentRow;
  int m_currentFrame;

  std::string m_textureID;
};

#endif // __SDLGAMEOBJECT_H__
