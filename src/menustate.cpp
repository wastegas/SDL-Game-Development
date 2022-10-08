#include "menustate.h"
#include <iostream>

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
  for (auto it = m_gameObjects.begin();
       it != m_gameObjects.end(); it++)
    {
      (*it)->update();
    }
}

void MenuState::render()
{
  for (auto it = m_gameObjects.begin();
       it != m_gameObjects.end(); it++)
    {
      //      std::cout << "drawing the buttons" << std::endl;
      (*it)->draw();
    }
}

bool MenuState::onEnter()
{
  if (!TheTextureManager::Instance()->load(DATADIR "/button.png",
					   "playbutton",
					   TheGame::Instance()->getRenderer()))
    {
      std::cout << "unable to load " << SDL_GetError() << std::endl;
      return false;
    }
  if (!TheTextureManager::Instance()->load(DATADIR "/exit.png",
					   "exitbutton",
					   TheGame::Instance()->getRenderer()))
    {
      std::cout << "unable to load " << SDL_GetError() << std::endl;
      return false;
    }
  GameObject* button1 = new MenuButton(new LoaderParams(100, 100,
							400, 100,
							"playbutton"),
				       s_menuToPlay);
  GameObject* button2 = new MenuButton(new LoaderParams(100, 300,
							400, 100,
							"exitbutton"),
				       s_exitFromMenu);

  m_gameObjects.push_back(button1);
  m_gameObjects.push_back(button2);
  std::cout << "entering menustate" << std::endl;
  return true;
}

bool MenuState::onExit()
{
  for (auto it = m_gameObjects.begin(); it != m_gameObjects.end();
       it++)
    {
      (*it)->clean();
    }
  m_gameObjects.clear();
  TheTextureManager::Instance()->clearFromTextureMap("playbutton");
  TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
  std::cout << "exiting MenuState" << std::endl;
  return true;
}

void MenuState::s_menuToPlay()
{
  std::cout << "Play button clicked" << std::endl;
}

void MenuState::s_exitFromMenu()
{
  TheGame::Instance()->quit();
}
