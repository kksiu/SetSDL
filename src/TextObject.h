//
//  TextObject.h
//  SetSDL
//
//  Created by Kenneth Siu on 6/29/14.
//
//

#ifndef __TextObject__
#define __TextObject__

#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "Game.h"

class TextObject {
public:
    
    TextObject(std::string nText, TTF_Font *nFont, SDL_Color nColor, SDL_Rect nPosition)  {
        text = nText;
        font = nFont;
        color = nColor;
        position = nPosition;
        
        //now set the surface
        surface = TTF_RenderText_Solid(font, text.c_str(), color);
        
        mTexture = SDL_CreateTextureFromSurface( Game::Instance()->getRenderer(), surface );

    }
    
    virtual void draw() {
        SDL_RenderCopyEx(Game::Instance()->getRenderer(), mTexture, NULL, &position, 0, 0, SDL_FLIP_NONE);
    }
    
	virtual void update() {
        //now set the surface
        surface = TTF_RenderText_Solid(font, text.c_str(), color);
        
        mTexture = SDL_CreateTextureFromSurface( Game::Instance()->getRenderer(), surface );
    }
    
    virtual void clean() {
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(mTexture);
    }
    
private:
    std::string text;
    TTF_Font *font;
    SDL_Surface *surface;
    SDL_Color color;
    
    SDL_Texture *mTexture;
    
    SDL_Rect position;
};

#endif /* __TextObject__ */
