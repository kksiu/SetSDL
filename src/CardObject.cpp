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

void CardObject::udpate() {
    //update
    SDLGameObject::update();

	Vector2D pMousePos = InputHandler::Instance()->getMousePosition();

	this->m_position.setX(pMousePos.getX());
	this->m_position.setY(pMousePos.getY());

}

void CardObject::clean() {
    
}

void CardObject::setSelected(bool selected) {
    isSelected = selected;
    
    if(selected) {
        
    }
}
