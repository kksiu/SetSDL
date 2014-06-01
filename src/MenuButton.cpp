#include "MenuButton.h"
#include "Game.h"
#include "InputHandler.h"

MenuButton::MenuButton(const LoaderParams *pParams, void (*callback)()) : SDLGameObject(pParams), m_callback(callback) {
	m_currentFrame = button_state::MOUSE_OUT;
}

void MenuButton::draw() {
	SDLGameObject::draw();
}

void MenuButton::update() {

	Vector2D pMousePos = InputHandler::Instance()->getMousePosition();

	//check to make sure that it is within the bounds of the button
	if (pMousePos.getX() < (m_position.getX() + m_width)
		&& pMousePos.getX() > m_position.getX()
		&& pMousePos.getY() < (m_position.getY() + m_height)
		&& pMousePos.getY() > m_position.getY()) {

		m_currentFrame = button_state::MOUSE_OVER;

		if (InputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased) {
			m_currentFrame = button_state::CLICKED;

			//now callback
			m_callback();
			m_bReleased = false;
		}
		else if (!InputHandler::Instance()->getMouseButtonState(LEFT)) {
			m_bReleased = true;
			m_currentFrame = button_state::MOUSE_OVER;
		}
		else {
			m_currentFrame = button_state::MOUSE_OUT;
		}
	}
	else {
		m_currentFrame = button_state::MOUSE_OUT;
	}
}

void MenuButton::clean() {
	SDLGameObject::clean();
}