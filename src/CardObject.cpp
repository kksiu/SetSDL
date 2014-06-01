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
}

void CardObject::draw() {
    SDLGameObject::draw();
}

void CardObject::update() {
    //update
	Vector2D pMousePos = InputHandler::Instance()->getMousePosition();

	if (this->isMouseInBounds()) {
		// mouse interior to card

		this->m_position.setX(this->m_position.getX() + 1);
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
        
    }
}
