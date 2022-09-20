#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>
#include <SDL_image.h>
#include "texturemanager.h"
#include "gameobject.h"
#include "player.h"
#include <iostream>

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

  int m_currentFrame;

  GameObject m_go;
  Player m_player;

};




#endif // __GAME_H__
