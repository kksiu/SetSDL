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
#include "Enums.h"

class CardObject : public SDLGameObject {
    
public:
    CardObject(const LoaderParams *pParams, color t_color, shading t_shading, number t_number, shape t_shape);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void setSelected(bool selected);
    
    color getColor() {return color;}
    number getNumber() {return number;}
    shape getShape() {return shape;}
    shading getShading() {return shading;}
    bool getSelected() {return isSelected;}
    
private:
    color color;
    number number;
    shape shape;
    shading shading;
    
    bool isSelected; //the card has been selected
};



#endif /* defined(__CardObject__) */
