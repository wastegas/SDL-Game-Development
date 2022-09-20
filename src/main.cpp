#include "game.h"
#include <config.h>

Game* g_game = 0;

int main(int argc, char **argv)
{
  g_game = new Game();
  
  g_game->init(PACKAGE_STRING, SDL_WINDOWPOS_CENTERED,
	       SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
  
  while(g_game->running())
    {
      g_game->handleEvents();
      g_game->update();
      g_game->render();
      SDL_Delay(10);
    }

  g_game->clean();
      

  return 0;
}

	    
