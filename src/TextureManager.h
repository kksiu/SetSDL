//
//  TextureManager.h
//  SDLDemo
//
//  Created by Kenneth Siu on 5/19/14.
//
//

#ifndef __TextureManager__
#define __TextureManager__

#include "SDL.h"
#include "SDL_image.h"
#include "Enums.h"
#include <iostream>
#include <map>

class TextureManager {
    
public:
    TextureManager(){}
    ~TextureManager(){}
    
    
    static TextureManager* Instance() {
        
        if(s_pInstance == 0)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        
        return s_pInstance;
    }
    
    //functions
    bool load(std::string fileName, std::string id, SDL_Renderer *pRenderer);
    
    //Draw
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    //Draw Frame
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, button_state currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void clearFromTextureMap(std::string id);
    
private:
    std::map<std::string, SDL_Texture*> m_textureMap;
    
    static TextureManager *s_pInstance;
    
};

typedef TextureManager TheTextureManager;





#endif /* defined(__TextureManager__) */
