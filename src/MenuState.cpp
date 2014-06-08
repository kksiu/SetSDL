//
//  MenuState.cpp
//  SetSDL
//
//  Created by Kenneth Siu on 6/1/14.
//
//

#include "MenuState.h"
#include "Constants.h"
#include "Game.h"
#include "MenuButton.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
    //update the game objects
    for(int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }
}

void MenuState::render() {
    //render the objects
    for(int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool MenuState::onEnter() {
	//    for(const std::string *p = &menuButtons[0]; p != &menuButtons[4]; ++p) {
	//        if(!TextureManager::Instance()->load(*p, *p, Game::Instance()->getRenderer())) {
	//            std::cout << "Failed to load menu buttons" << std::endl;
	//            return false;
	//        }
	//    }

	if (!TheTextureManager::Instance()->load("gfx/MButton-MultiPlayer.png", "multibutton", Game::Instance()->getRenderer())) {
		return false;
	}
	;
	if (!TheTextureManager::Instance()->load("gfx/MButton-Instructions.png", "instrbutton", Game::Instance()->getRenderer())) {
		return false;
	}

	if (!TheTextureManager::Instance()->load("gfx/MButton-Quit.png", "quitbutton", Game::Instance()->getRenderer())) {
		return false;
	}

	if (!TheTextureManager::Instance()->load("gfx/MButton-Settings.png", "settingbutton", Game::Instance()->getRenderer())) {
		return false;
	}

	if (!TheTextureManager::Instance()->load("gfx/MButton-SinglePlayer.png", "singlebutton", Game::Instance()->getRenderer())) {
		return false;
	}

    //now load them onto the screen
    GameObject *singleButton = new MenuButton(new LoaderParams(400, 400, 400, 100, "singlebutton"), playSingleButton);
    
    m_gameObjects.push_back(singleButton);
    
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

void MenuState::playSingleButton() {
    
}

void MenuState::playMultiButton() {
    
}

void MenuState::settingsButton() {
    
}

void MenuState::instructionButton() {
    
}

void MenuState::exitButton() {
    
}


