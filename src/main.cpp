#include "game.h"
#include <cstdint>
#include <config.h>

const int FPS = 60; // frames per sec
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char **argv)
{
  uint32_t frameStart, frameTime;

  
  if(TheGame::Instance()->init(PACKAGE_STRING, SDL_WINDOWPOS_CENTERED,
			       SDL_WINDOWPOS_CENTERED,
			       640, 480, false))
    {  
      while(TheGame::Instance()->running())
	{
	  frameStart = SDL_GetTicks();
	  
	  TheGame::Instance()->handleEvents();
	  TheGame::Instance()->update();
	  TheGame::Instance()->render();

	  frameTime = SDL_GetTicks() - frameStart;

	  if (frameTime < DELAY_TIME)
	    {
	      SDL_Delay((int) (DELAY_TIME - frameTime));
	    }
	}
    }
  else
    {
      return -1;
    }

  TheGame::Instance()->clean();
      

  return 0;
}

	    
