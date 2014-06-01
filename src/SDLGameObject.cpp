//
//  SDLGameObject.cpp
//  SDLDemo
//
//  Created by Kenneth Siu on 5/23/14.
//
//

#include "SDLGameObject.h"
#include "Game.h"
#include "InputHandler.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) :
GameObject(pParams), m_position(pParams->getX(), pParams->getY()), m_velocity(0, 0), m_acceleration(0, 0)
{
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();

    m_textureID = pParams->getTextureID();
    m_currentRow = 1;
    m_currentFrame = (int)button_state::MOUSE_OUT;
}

void SDLGameObject::draw()
{
    TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer());
}

void SDLGameObject::update() {
}

bool SDLGameObject::isMouseInBounds() {
	Vector2D pMousePos = InputHandler::Instance()->getMousePosition();

	return (pMousePos.getX() > this->m_position.getX() && pMousePos.getX() < this->m_position.getX() + this->getWidth() &&
		pMousePos.getY() > this->m_position.getY() && pMousePos.getY() < this->m_position.getY() + this->getHeight());
}