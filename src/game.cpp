#include "game.h"
#include <config.h>

bool Game::init(const char* title, int xpos, int ypos, int height, int width,
	  int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
      m_pWindow = SDL_CreateWindow(title,
				   xpos,
				   ypos,
				   height, width,
				   flags);

      if (m_pWindow != 0)
	{
	  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	  if (m_pRenderer != 0)
	    {
	      if(!TextureManager::Instance()->load(DATADIR "/animate-alpha.png",
						 "animate", m_pRenderer))
		{
		  return false;
		}

	      m_go.load(100, 100, 128, 82, "animate");
	      m_player.load(300, 300, 128, 82, "animate");
	      
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

  m_bRunning = true;
  return true;
}

void Game::render()
{

  SDL_SetRenderDrawColor(m_pRenderer,
		     255, 0, 0, 255);

  // clear the window
  SDL_RenderClear(m_pRenderer);

  m_go.draw(m_pRenderer);
  m_player.draw(m_pRenderer);


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
  //  m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
  m_go.update();
  m_player.update();
}

void Game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}


