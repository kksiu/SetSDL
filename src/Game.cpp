//
//  Game.cpp
//  SetSDL
//
//  Created by Kenneth Siu on 5/31/14.
//
//

#include "Game.h"
#include "InputHandler.h"
#include "PlayState.h"
#include "MenuState.h"
#include "SDL_ttf.h"
#include <time.h>

Game *Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
    
    //grab the texture manager
    m_textureManager = TextureManager::Instance();
    
    //init input handler
    InputHandler::Instance()->initializeMouse();
    
    //set seed of random
    srand((unsigned int)time(NULL));
    
    //initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL init success" << std::endl;
        
        //init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        
        if(m_pWindow != 0) {
            std::cout << "Window creation success" << std::endl;
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            
            if(m_pRenderer != 0) {
                std::cout << "renderer creation success" << std::endl;
                
                //initialize true type font
				if(TTF_Init() != 0)
				{
                    std::cout << "TTF_Init creation failed" << std::endl;
					return false;
				}
                
                //set renderer to white
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
                
                //State machine
                m_pGameStateMachine = new GameStateMachine();
                
                //for now, going to go into play state
                m_pGameStateMachine->changeState(new MenuState());
                
            } else {
                std::cout << "renderer init fail" << std::endl;
                return false;
            }
        } else {
            std::cout << "window init fail" << std::endl;
            return false;
        }
    } else {
        std::cout << "SDL init fail" << std::endl;
        return false;
    }
    
    std::cout << "Initialization successful" << std::endl;
    isRunning = true;
    
    return true;
}

void Game::render() {
    
    //clear renderer
    SDL_RenderClear(m_pRenderer);
    
    //loop through the game objects and draw them
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
    
    m_pGameStateMachine->render();
    
    // draw the screen
    SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
    //update the game objects
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }
    
    //update the state machine
	m_pGameStateMachine->update();
}

void Game::handleEvents() {
    //update the input handler
    InputHandler::Instance()->update();
}

void Game::clean() {
    //clean input handler
    InputHandler::Instance()->clean();
    
    //clean game objects
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    
    isRunning = false;
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}






