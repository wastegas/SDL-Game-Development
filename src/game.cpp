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

	      SDL_Surface* pTempSurface = SDL_LoadBMP(DATADIR "/animate.bmp");

	      if(pTempSurface == nullptr)
		{
		  std::cerr << "unable to load image:  "
			    << SDL_GetError() << std::endl;
		  return false;
		}
	      m_pTexture = SDL_CreateTextureFromSurface(
							m_pRenderer,
							pTempSurface);
	      SDL_FreeSurface(pTempSurface);
	      
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
		     0, 0, 0, 255);

  m_destRect.w = m_sourceRect.w = 128;
  m_destRect.h = m_sourceRect.h = 82;
  m_destRect.x = 0;
  m_destRect.y = m_sourceRect.y = 0;
  
  

  // clear the window
  SDL_RenderClear(m_pRenderer);


  // Draw our texture
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRect, &m_destRect);

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
  m_sourceRect.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}

void Game::clean()
{
  std::cout << "Cleaning game..." << std::endl;
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}


