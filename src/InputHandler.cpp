#include "InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;

//initialize the joysticks
void InputHandler::initializeMouse() {

	//push three mouse buttons
	for (int i = 0; i < 3; i++) {
		m_mouseButtonStates.push_back(false);
	}
}

void InputHandler::clean() {
}

void InputHandler::update() {
	SDL_Event event;

	m_keystates = (Uint8*)SDL_GetKeyboardState(0);

	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_QUIT:
			Game::Instance()->clean();
			break;
		case SDL_MOUSEMOTION:
			InputHandler::onMouseMove(event);
			break;

		case SDL_MOUSEBUTTONDOWN:
			InputHandler::onMouseButtonDown(event);
			break;

		case SDL_MOUSEBUTTONUP:
			InputHandler::onMouseButtonUp(event);
			break;

		default:
			break;
		};

	}
}

//mouse events
void InputHandler::onMouseMove(SDL_Event& event) {
	m_mousePosition.setX(event.motion.x);
	m_mousePosition.setY(event.motion.y);
}

void InputHandler::onMouseButtonDown(SDL_Event& event) {
	if (event.button.button == SDL_BUTTON_LEFT) {
		m_mouseButtonStates[LEFT] = true;
	}

	if (event.button.button == SDL_BUTTON_MIDDLE) {
		m_mouseButtonStates[MIDDLE] = true;
	}

	if (event.button.button == SDL_BUTTON_RIGHT) {
		m_mouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event& event) {
	if (event.button.button == SDL_BUTTON_LEFT) {
		m_mouseButtonStates[LEFT] = false;
	}

	if (event.button.button == SDL_BUTTON_MIDDLE) {
		m_mouseButtonStates[MIDDLE] = false;
	}

	if (event.button.button == SDL_BUTTON_RIGHT) {
		m_mouseButtonStates[RIGHT] = false;
	}
}