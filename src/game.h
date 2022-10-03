#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>
#include <SDL_image.h>
#include "gameobject.h"
#include "gamestatemachine.h"
#include "playstate.h"
#include "menustate.h"
#include <iostream>
#include <vector>
#include <config.h>

class Game
{
 public:
  bool init(const char* title, int xpos, int ypos, int height, int width,
	    int flag);
  void update();
  void render();
  void handleEvents();
  void clean();
  void quit();
  bool running() { return m_bRunning; }
  SDL_Renderer* getRenderer() const { return m_pRenderer; }

  static Game* Instance()
  {
    if (s_pInstance == 0)
      {
	s_pInstance = new Game();
        return s_pInstance;
      }
    return s_pInstance;
  }

 private:
  Game() {}
  SDL_Window*   m_pWindow;
  SDL_Renderer* m_pRenderer;
  
  bool          m_bRunning;

  int           m_currentFrame;

  GameObject*   m_go;
  GameObject*   m_player;
  GameObject*   m_enemy;

  static Game* s_pInstance;
  

  std::vector<GameObject*> m_gameObjects;

  GameStateMachine* m_pGameStateMachine;

};

typedef Game TheGame;


#endif // __GAME_H__
