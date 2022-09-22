#include "game.h"
#include <config.h>

int main(int argc, char **argv)
{

  
  if(TheGame::Instance()->init(PACKAGE_STRING, SDL_WINDOWPOS_CENTERED,
			       SDL_WINDOWPOS_CENTERED,
			       640, 480, false))
    {  
      while(TheGame::Instance()->running())
	{
	  TheGame::Instance()->handleEvents();
	  TheGame::Instance()->update();
	  TheGame::Instance()->render();
	  SDL_Delay(10);
	}
    }
  else
    {
      return -1;
    }

  TheGame::Instance()->clean();
      

  return 0;
}

	    
