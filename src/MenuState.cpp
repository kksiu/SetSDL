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
const int BUTTON_PADDING = 100;

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
    GameObject *singleButton = new MenuButton(new LoaderParams((WIDTH / 2) - (BUTTON_WIDTH / 2), BUTTON_PADDING, BUTTON_WIDTH, BUTTON_HEIGHT, "singlebutton"), playSingleButton);
	GameObject *multiButton = new MenuButton(new LoaderParams((WIDTH / 2) - (BUTTON_WIDTH / 2), (2 * BUTTON_PADDING) + BUTTON_HEIGHT, BUTTON_WIDTH, BUTTON_HEIGHT, "multibutton"), playMultiButton);
	GameObject *settingButton = new MenuButton(new LoaderParams(WIDTH - BUTTON_WIDTH - BUTTON_PADDING, (3 * BUTTON_PADDING) + (2 * BUTTON_HEIGHT), BUTTON_WIDTH, BUTTON_HEIGHT, "settingbutton"), settingsButton);
	GameObject *instrButton = new MenuButton(new LoaderParams(BUTTON_PADDING, (3 * BUTTON_PADDING) + (2 * BUTTON_HEIGHT), BUTTON_WIDTH, BUTTON_HEIGHT, "instrbutton"), instructionButton);
    
    m_gameObjects.push_back(singleButton);
	m_gameObjects.push_back(multiButton);
	m_gameObjects.push_back(settingButton);
	m_gameObjects.push_back(instrButton);
    
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

