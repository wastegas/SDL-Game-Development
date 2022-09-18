#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>
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

  SDL_Texture* m_pTexture;
  SDL_Rect m_sourceRect;
  SDL_Rect m_destRect;

};


#endif // __GAME_H__
