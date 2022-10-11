#ifndef __PAUSESTATE_H__
#define __PAUSESTATE_H__

#include "game.h"
#include "inputhandler.h"
#include "texturemanager.h"
#include "gameobject.h"
#include "gamestatemachine.h"
#include <string>
#include <vector>

class GameObject;

class PauseState : public GameState
{
 public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateID() const { return s_pauseID; }

 private:
  static void s_pauseToMain();
  static void s_resumePlay();

  static const std::string s_pauseID;
  std::vector<GameObject*> m_gameObjects;
  
};

#endif // __PAUSESTATE_H__
