//
//  CardObject.h
//  SetSDL
//
//  Created by Kenneth Siu on 5/31/14.
//
//

#ifndef __CardObject__
#define __CardObject__

#include <iostream>
#include "SDLGameObject.h"

class CardObject : SDLGameObject {
    
public:
    CardObject(const LoaderParams *pParams, int t_color, int t_shading, int t_number, int t_shape);
    virtual void draw();
    virtual void udpate();
    virtual void clean();
    void setSelected(bool selected);
    
    int getColor() {return color;}
    int getNumber() {return number;}
    int getShape() {return shape;}
    int getShading() {return shading;}
    bool getSelected() {return isSelected;}
    
private:
    enum color {
        BLUE = 0,
        RED = 1,
        GREEN = 2
    };
    
    enum number {
        ONE = 0,
        TWO = 1,
        THREE = 2
    };
    
    enum shape {
        TRIANGLE = 0,
        STAR = 1,
        OCTAGON = 2
    };
    
    enum shading {
        EMPTY = 0,
        MID = 1,
        FULL = 2
    };
    
    int color;
    int number;
    int shape;
    int shading;
    
    bool isSelected; //the card has been selected
};



#endif /* defined(__CardObject__) */
