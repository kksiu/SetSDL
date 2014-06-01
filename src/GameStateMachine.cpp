#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState *pState) {
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::changeState(GameState *pState) {
	if (!m_gameStates.empty()) {
		//if the state is the same as the one on the end
		if (m_gameStates.back()->getStateID() == pState->getStateID()) {
			return;
		}

		if (m_gameStates.back()->onExit()) {
			m_gameStates.pop_back();
		}
	}

	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState() {
	if (!m_gameStates.empty()) {
		if (m_gameStates.back()->onExit()) {
			m_gameStates.pop_back();
		}
	}
}

void GameStateMachine::update() {
	if (!m_gameStates.empty()) {
		m_gameStates.back()->update();
	}
}

void GameStateMachine::render() {
	if (!m_gameStates.empty()) {
		m_gameStates.back()->render();
	}
}