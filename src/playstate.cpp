#include "playstate.h"
#include <iostream>

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
  // todo
}

void PlayState::render()
{
  // todo
}

bool PlayState::onEnter()
{
  std::cout << "entering PlayState" << std::endl;
  return true;
}

bool PlayState::onExit()
{
  std::cout << "exiting PlayState" << std::endl;
  return true;
}
