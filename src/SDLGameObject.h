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
    void setPosition(Vector2D pos) { m_position = pos; }

	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
    
    //set visible
    void setVisible(bool vis) { m_isVisible = vis; }
    bool getVisible() { return m_isVisible; }
    
protected:
    int m_width;
    int m_height;
    int m_currentRow;
    int m_currentFrame;
    std::string m_textureID;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
    
    //visible or not
    bool m_isVisible;
};

#endif /* defined(__SDLGameObject__) */
