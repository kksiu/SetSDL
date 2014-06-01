//
//  MenuState.cpp
//  SetSDL
//
//  Created by Kenneth Siu on 6/1/14.
//
//

#include "MenuState.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
    // TODO logic to update the buttons
}

void MenuState::render() {
    //render the objects
    for(int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool MenuState::onEnter() {
    //load buttons
    
    
    std::cout << "Entering Menu State" << std::endl;
    return true;
}

bool MenuState::onExit() {
    //remove all buttons
    for(int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    
    m_gameObjects.clear();
    
    std::cout << "Exiting Play State" << std::endl;
    
    return true;
}