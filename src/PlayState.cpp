//
//  PlayState.cpp
//  SetSDL
//
//  Created by Kenneth Siu on 5/31/14.
//
//

#include "PlayState.h"
#include "Constants.h"
#include "Game.h"
#include "Enums.h"

const std::string PlayState::s_menuID = "PLAY";


void PlayState::update() {
    // TODO logic to update the cards selected
}

void PlayState::render() {
    //render all the objects
    for(int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool PlayState::onEnter() {
    
    //load all the cards
    PlayState::loadCards();
    
    //make a temporary card
    CardObject *card = new CardObject(new LoaderParams(0, 0, 1400, 900, "gfx/Image-card_1_oct_empty_blue.png"), color::BLUE, shading::EMPTY, number::ONE, shape::OCTAGON);
    
    m_gameObjects.push_back(card);
    
    std::cout << "Entering Play State" << std::endl;
    return true;
}


bool PlayState::onExit() {
    //remove all the cards (using the onExit)
    for(int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    
    m_gameObjects.clear();
    
    removeTextures();
    
    std::cout << "Exiting Play State" << std::endl;
    return true;
}

bool PlayState::loadCards() {
    //have to load all images
    for(std::string* p = &images[0]; p != &images[81]; ++p) {
        if(TextureManager::Instance()->load(*p, *p, Game::Instance()->getRenderer())) {
            std::cout << "FAILED" << std::endl;
            return false;
        }
    }
    
    
    std::cout << "All Images Loaded" << std::endl;
    return true;
}

void PlayState::removeTextures() {
    
}