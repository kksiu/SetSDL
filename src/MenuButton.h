#ifndef __MenuButton__
#define __MenuButton__

#include "SDLGameObject.h"

class MenuButton : public SDLGameObject {
public:
	MenuButton(const LoaderParams *pParams, void (*callback)());
	virtual void draw();
	virtual void update();
	virtual void clean();

private:

	void(*m_callback) ();
	bool m_bReleased;
};

#endif