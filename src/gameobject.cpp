#include "gameobject.h"
#include <config.h>


void GameObject::draw(SDL_Renderer* pRenderer)
{
  TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y,
					m_width, m_height,
					m_currentRow, m_currentFrame,
					pRenderer);
}

void GameObject::update()
{
  m_x += 1;
}
