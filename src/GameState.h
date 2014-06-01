//
//  GameState.h
//  SDLDemo
//
//  Created by Kenneth Siu on 5/26/14.
//
//

//FSM
#ifndef __GameState__
#define __GameState__

#include <iostream>

class GameState {
public:
	GameState() {}
	~GameState() {}
    virtual void update() = 0;
    virtual void render() = 0;
    
    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;
    virtual std::string getStateID() const { return s_playID; }
    
private:
    const std::string s_playID;
};

#endif
