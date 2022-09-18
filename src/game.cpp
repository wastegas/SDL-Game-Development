#include "game.h"
#include <config.h>

bool Game::init(const char* title, int xpos, int ypos, int height, int width,
	  int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
      std::cout << "SDL init success" << std::endl;
      m_pWindow = SDL_CreateWindow(title,
				   xpos,
				   ypos,
				   height, width,
				   flags);

      if (m_pWindow != 0)
	{
	  std::cout << "Window creation success" << std::endl;
	  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	  if (m_pRenderer != 0)
	    {
	      std::cout << "Rendrer creation success" << std::endl;

	      if(!TheTextureManager::Instance()->load(DATADIR "/animate-alpha.png",
					"animate", m_pRenderer))
		{
		  return false;
		}
	      
	    }
	  else
	    {
	      std::cerr << "Renderer init failed " << SDL_GetError()
			<< std::endl;
	      return false;
	    }
	}
      else
	{
	  std::cerr << "Window creation failed " << SDL_GetError()
		    << std::endl;
	  return false;
	}
    }
  else
    {
      std::cerr << "SDL Init failed " << SDL_GetError() << std::endl;
      return false; 
    }

  std::cout << "init success" << std::endl;
  m_bRunning = true;
  return true;
}

void Game::render()
{

  SDL_SetRenderDrawColor(m_pRenderer,
		     255, 0, 0, 255);

  // clear the window
  SDL_RenderClear(m_pRenderer);

  TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82,
			m_pRenderer);
  TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82,
			     1, m_currentFrame, m_pRenderer);


  // Show the window
  SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents()
{
  SDL_Event e;
  if (SDL_PollEvent(&e))
    {
      switch (e.type)
	{
	case SDL_QUIT:
	  m_bRunning = false;
	  break;
	default:
	  break;
	}
    }
}

void Game::update()
{
  m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Game::clean()
{
  std::cout << "Cleaning game..." << std::endl;
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}


