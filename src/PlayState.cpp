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
    
    
    return true;
}


bool PlayState::onExit() {
    
    
    
    return true;
}

void PlayState::loadCards() {
    
}