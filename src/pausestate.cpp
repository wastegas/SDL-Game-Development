#include "pausestate.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
  TheGame::Instance()->getStateMachine()->changeState(new PauseState());
}

void PauseState::s_resumePlay()
{
  TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
  for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); it++)
    {
      (*it)->update();
    }
}

void PauseState::render()
{
  for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); it++)
    {
      (*it)->draw();
    }
}

bool PauseState::onEnter()
{
  if (!TheTextureManager::Instance()->load(DATADIR "/resume.png",
					   "resumebutton",
					   TheGame::Instance()->getRenderer()))
  {
    std::cerr << "Unable to load resume.png" << std::endl;
    return false;
  }

  if (!TheTextureManager::Instance()->load(DATADIR "/main.png",
					    "mainbutton",
					    TheGame::Instance()->getRenderer()))
    {
      std::cerr << "Unable to laod main.png" << std::endl;
      return false;
    }

  GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 200, 80,
							"mainbutton"),
				       s_pauseToMain);
  GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80,
							"resumebutton"),
							s_resumePlay);

  m_gameObjects.push_back(button1);
  m_gameObjects.push_back(button2);

  std::cout << "entering PauseState" << std::endl;
  return true;
}

bool PauseState::onExit()
{
  for (auto it = m_gameObjects.begin(); it != m_gameObjects.end();
       it++)
    {
      (*it)->clean();
    }
  m_gameObjects.clear();
  TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
  TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
  // reset the mosue button states to false
  TheInputHandler::Instance()->reset();

  std::cout << "exiting PauseState" << std::endl;
  return true;
}


