#include "enemy.h"
#include <config.h>

Enemy::Enemy(const LoaderParams* pParams) :
  SDLGameObject(pParams)
{
  m_velocity.setY(2);
  m_velocity.setX(0.001);
}

void Enemy::draw()
{
  SDLGameObject::draw();
}

void Enemy::update()
{
  /*
  m_position.setX(m_position.getX() + 1);
  m_position.setY(m_position.getY() + 1);
  m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
  */
  m_currentFrame = int (((SDL_GetTicks() / 100) % m_numFrames));

  if (m_position.getY() < 0)
    {
      m_velocity.setY(2);
    }
  else if (m_position.getY() > 400)
    {
      m_velocity.setY(-2);
    }
  SDLGameObject::update();
}

void Enemy::clean()
{
}
