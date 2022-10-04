#ifndef __GAMESTATEMACHINE_H__
#define __GAMESTATEMACHINE_H__

#include "gamestate.h"
#include <vector>

class GameStateMachine
{
 public:
  void pushState(GameState* pState);
  void changeState(GameState* pState);
  void popState();
  void update();
  void render();

 private:
  std::vector<GameState*> m_gameStates;
};

#endif // __GAMESTATEMACHINE_H__
