#include "game.h"
#include "player.h"
#include "enemy.h"
#include "texturemanager.h"
#include "inputhandler.h"

#include <config.h>

Game* Game::s_pInstance = 0;

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

	      if(!TheTextureManager::Instance()->load(DATADIR "/animate-alpha.png",
						 "animate", m_pRenderer))
		{
		  return false;
		}

	      m_pGameStateMachine = new GameStateMachine();
	      m_pGameStateMachine->changeState(new MenuState());
	      
	      TheInputHandler::Instance()->initialiseJoysticks();
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

  // SDL_SetRenderDrawColor(m_pRenderer,
  //		     255, 0, 0, 255);

  // clear the window
  SDL_RenderClear(m_pRenderer);

  m_pGameStateMachine->render();

  // Show the window
  SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents()
{
  TheInputHandler::Instance()->update();

  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
    {
      m_pGameStateMachine->changeState(new PlayState());
    }
}

void Game::update()
{
  m_pGameStateMachine->update();
}

void Game::clean()
{
  TheInputHandler::Instance()->clean();
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}


void Game::quit()
{
  m_bRunning = false;
}
