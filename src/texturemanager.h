#ifndef __TEXTUREMANAGER_H__
#define __TEXTUREMANAGER_H__

#include <SDL.h>
#include <SDL_image.h>
#include "loaderparams.h"
#include <string>
#include <iostream>
#include <map>
#include <config.h>

class TextureManager
{
 public:
  bool load(std::string, std::string, SDL_Renderer*);
  void draw(std::string, int, int, int, int,
	    SDL_Renderer*, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void drawFrame(std::string, int, int, int, int, int, int,
		 SDL_Renderer*, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void clearFromTextureMap(std::string id);
  static TextureManager * Instance()
  {
    if (s_pInstance == 0)
      {
	s_pInstance = new TextureManager();
	return s_pInstance;
      }
    return s_pInstance;
  }

 private:
  TextureManager() {}
  static TextureManager* s_pInstance;
  
  std::map<std::string, SDL_Texture*> m_textureMap;
};

typedef TextureManager TheTextureManager;


#endif // __TEXTUREMANAGER_H__
