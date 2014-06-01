//
//  PlayState.cpp
//  SetSDL
//
//  Created by Kenneth Siu on 5/31/14.
//
//

#include "PlayState.h"

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
    
    std::cout << "Entering Play State\n";
    return true;
}


bool PlayState::onExit() {
    //remove all the cards (using the onExit)
    for(int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    
    m_gameObjects.clear();
    
    removeTextures();
    
    std::cout << "Exiting Play State\n";
    return true;
}

void PlayState::loadCards() {
    //have to load
}

void PlayState::removeTextures() {
    
}