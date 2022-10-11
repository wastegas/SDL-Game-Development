#ifndef __PLAYSTATE_H__
#define __PLAYSTATE_H__

#include "game.h"
#include "gamestate.h"
#include "pausestate.h"
#include "gameobject.h"
#include "texturemanager.h"
#include "player.h"
#include <string>
#include <vector>

class GameObject;

class PlayState : public GameState
{
 public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateID() const { return s_playID; }

 private:
  static const std::string s_playID;
  std::vector<GameObject*> m_gameObjects;
};

#endif // __PLAYSTATE_H__
