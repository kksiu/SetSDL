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
    m_firstEventMousePress = false;
    
	while (SDL_PollEvent(&event)) {
        
		switch (event.type) {
            case SDL_QUIT:
                Game::Instance()->clean();
                break;
            case SDL_MOUSEMOTION:
                InputHandler::onMouseMove(event);
                break;
                
            case SDL_MOUSEBUTTONDOWN:
                if(!m_initialMousePress) {
                    InputHandler::onMouseButtonDown(event);
                    m_initialMousePress = true;
                    m_firstEventMousePress = true;
                    m_mouseClickPos = m_mousePosition;
                }
                break;
                
            case SDL_MOUSEBUTTONUP:
                InputHandler::onMouseButtonUp(event);
                m_initialMousePress = false;
                break;
                
            default:
                break;
		};
        
	}
}

//mouse events
void InputHandler::onMouseMove(SDL_Event& event) {
	m_mousePosition.setX((float)event.motion.x);
	m_mousePosition.setY((float)event.motion.y);
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