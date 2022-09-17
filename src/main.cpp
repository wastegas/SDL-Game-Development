#include <SDL.h>
#include <iostream>
#include <config.h>

SDL_Window*   g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos, int height, int width,
	  int flags)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
      // Init succeeded create window
      g_pWindow = SDL_CreateWindow(title,
				   xpos,
				   ypos,
				   height, width,
				   flags);
      // Window created, create renderer
      if (g_pWindow != 0)
	{
	  g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
	}
      else
	{
	  return false;
	}
    }
  else
    {
      return false; // something went wrong
    }
  return true;
}


void render()
{
  // set to black
  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

  // clear the window
  SDL_RenderClear(g_pRenderer);

  std::cout << "drawing window" << std::endl;
  // Show the window
  SDL_RenderPresent(g_pRenderer);
}  

int main(int argc, char **argv)
{
  if(init(PACKAGE_STRING, SDL_WINDOWPOS_CENTERED,
	  SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN))
    {
      g_bRunning = true;
    }
  else
    {
      return -1;
    }

  // delay before quitting
  //  SDL_Delay(5000);

  // clean up SDL
  SDL_Quit();

  return 0;
}

	    
