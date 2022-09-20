#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>
#include <SDL_image.h>
#include "texturemanager.h"
#include "gameobject.h"
#include "player.h"
#include "enemy.h"
#include <iostream>
#include <vector>
#include <config.h>

class Game
{
 public:
  Game() {}
  ~Game() {}

  bool init(const char* title, int xpos, int ypos, int height, int width,
	    int flag);
  void update();
  void render();
  void handleEvents();
  void clean();
  bool running() { return m_bRunning; }

 private:
  SDL_Window*   m_pWindow;
  SDL_Renderer* m_pRenderer;
  
  bool          m_bRunning;

  int           m_currentFrame;

  GameObject*   m_go;
  GameObject*   m_player;
  GameObject*   m_enemy;
  

  std::vector<GameObject*> m_gameObjects;

};




#endif // __GAME_H__
