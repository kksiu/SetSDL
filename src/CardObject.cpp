//
//  CardObject.cpp
//  SetSDL
//
//  Created by Kenneth Siu on 5/31/14.
//
//

#include "CardObject.h"
#include "InputHandler.h"

CardObject::CardObject(const LoaderParams *pParams, int t_color, int t_shading, int t_number, int t_shape) : SDLGameObject(pParams) {
    
    color = t_color;
    shading = t_shading;
    shape = t_shape;
    number = t_number;
}

void CardObject::draw() {
    SDLGameObject::draw();
}

void CardObject::udpate() {
    //update
    SDLGameObject::update();
}

void CardObject::clean() {
    
}

void CardObject::setSelected(bool selected) {
    isSelected = selected;
    
    if(selected) {
        
    }
}
