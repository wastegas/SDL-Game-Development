#include "player.h"

Player::Player(const LoaderParams* pParams) :
  SDLGameObject(pParams)
{
}

void Player::draw()
{
  SDLGameObject::draw();
}

void Player::update()
{

  //  m_velocity.setX(0);
  m_velocity.setY(0);

  handleInput();
  
  //m_position.setX(m_position.getX() - 1);
  m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
  m_acceleration.setX(1);
  SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput()
{
  // Joystick
  if (TheInputHandler::Instance()->joysticksInitialised())
    {
      if (TheInputHandler::Instance()->xvalue(0, 1) > 0 ||
	  TheInputHandler::Instance()->xvalue(0, 1) < 0)
	{
	  m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0, 1));
	}
      if (TheInputHandler::Instance()->yvalue(0, 1) > 0 ||
	  TheInputHandler::Instance()->yvalue(0, 1) < 0)
	{
	  m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0, 1));
	}
      if (TheInputHandler::Instance()->xvalue(0, 2) > 0 ||
	  TheInputHandler::Instance()->xvalue(0, 2) < 0)
	{
	  m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0, 2));
	}
      if (TheInputHandler::Instance()->yvalue(0, 2) > 0 ||
	  TheInputHandler::Instance()->yvalue(0, 2) < 0)
	{
	  m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0, 2));
	}
    }
  // joystick button
  /* crashes without a joystick
  if (TheInputHandler::Instance()->getButtonState(0, 3))
    {
      m_velocity.setX(1);
    }
  */
  // mouse button
  //  if (TheInputHandler::Instance()->getMouseButtonState(TheInputHandler::LEFT))
  //  {
  //    m_velocity.setX(1);
  //  }
  Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
  m_velocity = (*vec - m_position) / 100;

  // mouse
  if (TheInputHandler::Instance()->getMouseButtonState(TheInputHandler::LEFT))
    {
      m_acceleration.setX(-3);
    }
  if (TheInputHandler::Instance()->getMouseButtonState(TheInputHandler::RIGHT))
    {
      m_acceleration.setX(3);
    }
  

  // keyboard
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
      m_velocity.setX(2);
    }
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
      m_velocity.setX(-2);
    }
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
      m_velocity.setY(-2);
    }
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
      m_velocity.setY(2);
    }
}
