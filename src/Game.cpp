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

Game *Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
    
    //grab the texture manager
    m_textureManager = TextureManager::Instance();
    
    //init input handler
    InputHandler::Instance()->initializeMouse();
    
    //initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL init success\n";
        
        //init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        
        if(m_pWindow != 0) {
            std::cout << "Window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            
            if(m_pRenderer != 0) {
                std::cout << "renderer creation success\n";
                
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
                
                //State machine
                m_pGameStateMachine = new GameStateMachine();
                
                // TODO ADD MENU STATE MACHINE
                //for now, going to go into play state
                m_pGameStateMachine->changeState(new PlayState());
                
            } else {
                std::cout << "renderer init fail\n";
                return false;
            }
        } else {
            std::cout << "window init fail\n";
            return false;
        }
    } else {
        std::cout << "SDL init fail\n";
        return false;
    }
    
    std::cout << "Initialization successful\n";
    isRunning = true;
    
    return true;
}

void Game::render() {
    
    //clear renderer
    SDL_RenderClear(m_pRenderer);
    
    //loop through the game objects and draw them
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }
    
    m_pGameStateMachine->update();
    
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






