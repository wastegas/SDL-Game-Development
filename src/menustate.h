#ifndef __MENUSTATE_H__
#define __MENUSTATE_H__

#include "game.h"
#include "gamestate.h"
#include "gameobject.h"
#include "texturemanager.h"
#include "menubutton.h"
#include <vector>

class MenuState : public GameState
{
 public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateID() const { return s_menuID; }

 private:
  static const std::string s_menuID;
  std::vector<GameObject*> m_gameObjects;
  // callback functions for menu items
  static void s_menuToPlay();
  static void s_exitFromMenu();
};

#endif // __MENUSTATE_H__
