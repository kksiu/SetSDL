#ifndef __InputHandler__
#define __InputHandler__

//will handle all the input
#include <vector>
#include <iostream>
#include "Game.h"
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

const int m_joystickDeadZone = 10000;

class InputHandler {
public:
	InputHandler() : m_mousePosition(0, 0) {}
	~InputHandler() {}

	//singleton
	static InputHandler* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}

		return s_pInstance;
	}

	//mouse
	bool getMouseButtonState(int buttonNumber) {
		return m_mouseButtonStates[buttonNumber];
	}
	
	Vector2D getMousePosition() {
		return m_mousePosition;
	}

    void initializeMouse();
	void update();
	void clean();

private:
	//instance
	static InputHandler *s_pInstance;

	//control mouse
	std::vector<bool> m_mouseButtonStates;
	Vector2D m_mousePosition;

	Uint8* m_keystates;

	//mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);
};

#endif /* defined(__InputHandler__) */
