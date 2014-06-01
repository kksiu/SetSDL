//
//  SDLGameObject.h
//  SDLDemo
//
//  Created by Kenneth Siu on 5/23/14.
//
//

#ifndef __SDLGameObject__
#define __SDLGameObject__

#include <iostream>
#include "Vector2D.h"
#include "GameObject.h"
#include "Enums.h"

class SDLGameObject : public GameObject
{
    
public:
    SDLGameObject(const LoaderParams* pParams);
    virtual void draw();
	virtual void update();
    virtual void clean() {}
	virtual bool isMouseInBounds();

	Vector2D getPosition() { return m_position; }

	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
    
protected:
    int m_width;
    int m_height;
    int m_currentRow;
    button_state m_currentFrame;
    std::string m_textureID;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
};

#endif /* defined(__SDLGameObject__) */
