//
//  ScoreText.h
//  SetSDL
//
//  Created by Kenneth Siu on 7/9/14.
//
//

#ifndef __ScoreText__
#define __ScoreText__

#include <iostream>
#include <sstream>
#include <string>
#include "TextObject.h"

class ScoreText : public TextObject {
    
public:
    
    //constructor
    ScoreText(int tScore, std::string tPlayer, TTF_Font *nFont, SDL_Color nColor, SDL_Rect nPosition) : TextObject(tPlayer + ": " + std::to_string(tScore), nFont, nColor, nPosition) {
        score = tScore;
        player = tPlayer;
        
    }
    
    ~ScoreText();
    
    void update() {
        TextObject::setText(player + ": " + std::to_string(score));
        TextObject::update();
    }
    
    //int to hold score
    int score;
    
    //player name
    std::string player;
};

#endif /* defined(__ScoreText__) */
