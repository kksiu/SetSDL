//
//  CardObject.cpp
//  SetSDL
//
//  Created by Kenneth Siu on 5/31/14.
//
//

#include "CardObject.h"
#include "InputHandler.h"

CardObject::CardObject(const LoaderParams *pParams, ::color t_color, ::shading t_shading, ::number t_number, ::shape t_shape) : SDLGameObject(pParams) {
    color = t_color;
    shading = t_shading;
    shape = t_shape;
    number = t_number;
    isSelected = false;
}

void CardObject::draw() {
    SDLGameObject::draw();
}

void CardObject::update() {
    //update
	if (InputHandler::Instance()->getMouseInitial()) {
		// check mouse potition
        if(isInside(InputHandler::Instance()->getMouseClickPosition())) {
            //change from selected to not selected
            isSelected = !isSelected;
        }
	}
	else {
		// mouse exterior

	}

    SDLGameObject::update();

}

void CardObject::clean() {
    
}

void CardObject::setSelected(bool selected) {
    isSelected = selected;
    
    if(selected) {
        //where the card would show its selected state
    }
}

bool CardObject::isInside(Vector2D pos) {
    
    //check to see if it is inside
    Vector2D currPos = this->getPosition();
    
    //check x
    if((pos.getX() > currPos.getX()) && (pos.getX() < (currPos.getX() + this->getWidth()))) {
        //now check y
        if((pos.getY() > currPos.getY()) && (pos.getY() < (currPos.getY() + this->getHeight()))) {
            return true;
        }
    }
    
    return false;
}
