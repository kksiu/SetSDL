//
//  GameObject.h
//  SDLDemo
//
//  Created by Kenneth Siu on 5/19/14.
//
//

#ifndef __GameObject__
#define __GameObject__

#include <iostream>
#include "TextureManager.h"
#include "LoaderParams.h"

class GameObject {
    
public:
    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;
    
protected:
    GameObject(const LoaderParams *object) {}
    virtual ~GameObject(){}
    
};

#endif
