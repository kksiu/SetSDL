//
//  MenuState.h
//  SetSDL
//
//  Created by Kenneth Siu on 6/1/14.
//
//

#ifndef __MenuState__
#define __MenuState__

#include <iostream>
#include <vector>
#include "GameState.h"
#include "GameObject.h"

class MenuState : public GameState {
public:
    MenuState() {}
    ~MenuState() {}
    
    //standard state functions
    virtual void update();
    virtual void render();
    
    virtual bool onEnter();
    virtual bool onExit();
    
    //grab the state
    virtual std::string getStateID() const {return s_menuID;}
    
private:
    static const std::string s_menuID;
    std::vector<GameObject*> m_gameObjects;
    
    //functions for the button
    static void playSingleButton();
    static void playMultiButton();
    static void settingsButton();
    static void instructionButton();
    static void exitButton();
    
};

#endif /* defined(__MenuState__) */
