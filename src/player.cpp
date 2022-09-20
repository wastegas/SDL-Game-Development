#include "player.h"

void Player::load(int x, int y, int width, int height, std::string textureID)
{
  GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
  GameObject::draw(pRenderer);
  std::cout << "draw player" << std::endl;
}

void Player::update()
{
  std::cout << "update player" << std::endl;
  m_x -= 1;
}

void Player::clean()
{
  GameObject::clean();
  std::cout << "clean player" << std::endl;
}
