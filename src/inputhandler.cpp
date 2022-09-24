#include "inputhandler.h"
#include "game.h"

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler()
{
}

void InputHandler::initialiseJoysticks()
{
  if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
    {
      SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }

  if (SDL_NumJoysticks() > 0)
    {
      for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
	  SDL_Joystick* joy = SDL_JoystickOpen(i);

	  if (SDL_JoystickOpen(i))
	    {
	      m_joysticks.push_back(joy);
	      m_joystickValues.push_back(std::make_pair(new
					 Vector2D(0, 0), new
							Vector2D(0, 0)));

	      std::<vector<bool>> tempButtons;

	      for (int j = 0; j < SDL_JoyStickNumButtons(joy); j++)
		{
		  tempButtons.push_back(false);
		}
	      m_buttonStates.push_back(tempButtons);
	      
	    }
	  else
	    {
	      std::cerr << SDL_GetError() << std::endl;
	    }
	}
      SDL_JoystickEventState(SDL_ENABLE);
      m_bJoysticksInitialised = true;

      std::cout << "Initialised " << m_joysticks.size() << "joystick(s)\n";
    }
  else
    {
      m_bJoysticksInitialised = false;
    }
}

void InputHandler::clean()
{
  if (m_bJoysticksInitialised)
    {
      for (unsigned int i = 0; i < SDL_NumJoysticks(); i++)
	{
	  SDL_JoystickClose(m_joysticks[i]);
	}
    }
}

void InputHandler::update()
{
  SDL_Event event;

  while(SDL_PollEvent(&event))
    {
      switch(event.type)
	{
	case SDL_QUIT:
	  TheGame::Instance()->quit();
	  break;
	case SDL_JOYAXISMOTION:
	  {
	    int whichOne = event.jaxis.which;

	    // left stick move left or right
	    if (event.jaxis.axis == 0)
	      {
		if (event.jaxis.value > m_joystickDeadZone)
		  {
		    m_joystickValues[whichOne].first->setX(1);
		  }
		else if (event.jaxis.value < -m_joystickDeadZone)
		  {
		    m_joystickValues[whichOne].first->setX(-1);
		  }
		else
		  {
		    m_joystickValues[whichOne].first->setX(0);
		  }
	      }
	    // left stick move up or down
	    if (event.jaxis.axis == 1)
	      {
		if (event.jaxis.value > m_joystickDeadZone)
		  {
		    m_joystickValues[whichOne].first.setY(1);
		  }
		else if (event.jaxis.value < -m_joystickDeadZone)
		  {
		    m_joystickValues[whichOne].first->setY(-1);
		  }
		else
		  {
		    m_joystickValues[whichOne].first->setY(0);
		  }
	      }
	    // right stick move left or right
	    if (event.jaxis.axis == 3)
	      {
		if (event.axis.value > m_joystickDeadZone)
		  {
		    m_joystickValue[whichOne].second.setX(1);
		  }
		else if (event.jaxis.axis < -m_joystickDeadZone)
		  {
		    m_joystickValue[whichOne].second.setX(-1);
		  }
		else
		  {
		    m_joystickValue[whichOne].second.setX(0);
		  }
		    
	      }
	    // right stick move up or down
	    if (event.jaxis.axis == 4)
	      {
		if (event.axis.value > m_joystickDeadZone)
		  {
		    m_joystickValue[whichOne].second.setY(1);
		  }
		else if (event.axis.value < -m_joystickDeadZone)
		  {
		    m_joystickValue[whichOne].second.setY(-1);
		  }
		else
		  {
		    m_joystickValue[whichOne].second.setY(0);
		  }
	      }
	    break;
	  }
	case SDL_JOYBUTTONDOWN:
	  {
	    int whichOne = event.jaxis.which;

	    m_buttonStates[whichOne][event.jbutton.button] = true;
	    
	    break;
	  }
	case SDL_JOYBUTTONUP:
	  {
	    int whichOne = event.jaxis.which;

	    m_buttonStates[whichOne][event.jbutton.button] = false;
	    
	    break;
	  }
	default:
	  break;
	} //switch

    } // while
}
	  
int InputHandler::xvalue(int joy, int stick)
{
  if (m_joystickValues.size() > 0)
    {
      if (stick == 1)
	{
	  return m_joystickValues[joy].first->getX();
	}
      else if(stick == 2)
	{
	  return m_joystickValues[joy].second->getX();
	}
    }
  return 0;
}

int InputHandler::yvalue(int joy, int stick)
{
  if (m_joystickValues.size() > 0)
    {
      if (stick == 1)
	{
	  return m_joystickValues[joy].first->getY();
	}
      else if(stick == 2)
	{
	  return m_joystickValues[joy].second->getY();
	}
    }
  return 0;
}

bool InputHandler::getButtonState(int joy, int buttonNumber)
{
  return m_buttonStates[joy][buttonNumber];
}
