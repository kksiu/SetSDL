//
//  Game.h
//  SetSDL
//
//  Created by Kenneth Siu on 5/31/14.
//
//

#ifndef __Game__
#define __Game__

#include <iostream>
#include <vector>
#include "SDL.h"
#include "TextureManager.h"
#include "GameStateMachine.h"
#include "GameObject.h"


class Game {
public:
    
    //constructor
    static Game* Instance() {
        if(s_pInstance == 0) {
            s_pInstance = new Game();
        }
        
        return s_pInstance;
    }
    
    //deconstructor
    ~Game() {}
    
    //simply set running variable to true
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();
    
    //function to access running variable
    bool running() {return isRunning;}
    
    //grabs the renderer
    SDL_Renderer* getRenderer()  const { return m_pRenderer; }
    
    //get state machine
    GameStateMachine *getStateMachine() { return m_pGameStateMachine; }
    
private:
    bool isRunning;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    
    SDL_Texture *m_pTexture;
    SDL_Rect m_sourceRect;
    SDL_Rect m_destinationRect;
    
    TextureManager *m_textureManager;
    
    //create the instance
    static Game* s_pInstance;
    
    //array of game objects
    std::vector<GameObject*> m_gameObjects;
    
    //state machine will go here
    GameStateMachine *m_pGameStateMachine;
};

#endif /* defined(__Game__) */
