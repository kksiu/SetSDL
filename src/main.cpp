//new SDL project
#include <iostream>
#include "SDL.h"
#include "Game.h"

//fixed FPS
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

//main function - initialize the game
int main(int argc, char *argv[]) {
	//get start frame and fame time
	Uint32 frameStart, frameTime;
    
    if(Game::Instance()->init("Multiplayer Set!", 100, 100, 640, 480,
                                 false))
    {
        std::cout << "game init success!\n";
        while(Game::Instance()->running())
        {
			//get initial frame ticks
			frameStart = SDL_GetTicks();
            
            Game::Instance()->handleEvents();
            Game::Instance()->update();
            Game::Instance()->render();
            
			//frame time
			frameTime = SDL_GetTicks() - frameStart;
            
			if (frameTime < DELAY_TIME) {
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
        }
    } else {
        std::cout << "game init failure - " << SDL_GetError() << "\n";
    }
    
	std::cout << "game closing...\n";
    Game::Instance()->clean();
    
	// Body of the program goes here.
	return 0;
}