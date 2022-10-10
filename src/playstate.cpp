#include "playstate.h"
#include <iostream>

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
  for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); it++)
    {
      (*it)->update();
    }
}

void PlayState::render()
{
  for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); it++)
    {
      (*it)->draw();
    }
}

bool PlayState::onEnter()
{

  if (!TheTextureManager::Instance()->load(DATADIR "/helicopter.png",
					   "helicopter",
					   TheGame::Instance()->getRenderer()))
    {
      std::cerr << "unable to load helicopter.png" << std::endl;
      return false;
    }

  GameObject* player = new Player(new LoaderParams(100, 100, 128, 55,
						   "helicopter"));
  m_gameObjects.push_back(player);
  
  std::cout << "entering playstate" << std::endl;
						   
  return true;
}

bool PlayState::onExit()
{
  for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); it++)
    {
      std::cout << "cleaning player object" << std::endl;
      (*it)->clean();
    }
  m_gameObjects.clear();
  TheTextureManager::Instance()->clearFromTextureMap("helicopter");
  
  std::cout << "exiting PlayState" << std::endl;
  return true;
}
