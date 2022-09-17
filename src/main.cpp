#include <SDL.h>
#include <iostream>
#include <config.h>

SDL_Window*   g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char **argv)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
      // Init succeeded create window
      g_pWindow = SDL_CreateWindow(PACKAGE_STRING,
				   SDL_WINDOWPOS_CENTERED,
				   SDL_WINDOWPOS_CENTERED,
				   640, 480,
				   SDL_WINDOW_SHOWN);
      // Window created, create renderer
      if (g_pWindow != 0)
	{
	  std::cout << "window created" << std::endl;
	  g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
	}
      else
	{
	  return -1;
	}
      std::cout << "renderer created" << std::endl;
    }
  else
    {
      return -1; // something went wrong
    }

  // everything okay draw window

  // set black background
  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

  // clear the window
  SDL_RenderClear(g_pRenderer);

  std::cout << "drawing window" << std::endl;
  // Show the window
  SDL_RenderPresent(g_pRenderer);

  // delay before quitting
  SDL_Delay(5000);

  // clean up SDL
  SDL_Quit();

  return 0;
}

	    
