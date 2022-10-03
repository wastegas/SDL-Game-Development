#include "menustate.h"
#include <iostream>

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
  // todo
}

void MenuState::render()
{
  // todo
}

bool MenuState::onEnter()
{
  std::cout << "entering MenuState" << std::endl;
  return true;
}

bool MenuState::onExit()
{
  std::cout << "exiting MenuState" << std::endl;
  return true;
}
