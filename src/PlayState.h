//
//  PlayState.h
//  SetSDL
//
//  Created by Kenneth Siu on 5/31/14.
//
//

#ifndef __PlayState__
#define __PlayState__

#include <iostream>
#include <vector>
#include "GameState.h"
#include "CardObject.h"

class GameObject;

class PlayState : public GameState {
public:
    PlayState() {}
    ~PlayState() {}
    
    //standard state functions
    virtual void update();
    virtual void render();
    
    virtual bool onEnter();
    virtual bool onExit();
    
    //grab the state
    virtual std::string getStateID() const {return s_menuID;}
    
    //function to load all the cards
    bool loadCards();
    void removeTextures();
    
private:
    static const std::string s_menuID;
    std::vector<GameObject*> m_gameObjects;
    void loadRandomInitialCards();
    std::vector<GameObject*> m_leftCards;
    bool checkSet(std::vector<CardObject*>);
};


#endif /* defined(__PlayState__) */
