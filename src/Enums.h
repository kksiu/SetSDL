//
//  Enums.h
//  SetSDL
//
//  Created by Kenneth Siu on 5/31/14.
//
//

#ifndef __Enums__
#define __Enums__

//button state
enum class button_state {
    MOUSE_OUT = 0,
    MOUSE_OVER = 1,
    CLICKED = 2
};

enum class color {
    BLUE = 0,
    RED = 1,
    GREEN = 2
};

enum class number {
    ONE = 0,
    TWO = 1,
    THREE = 2
};

enum class shape {
    TRIANGLE = 0,
    STAR = 1,
    OCTAGON = 2
};

enum class shading {
    EMPTY = 0,
    MID = 1,
    FULL = 2
};

#endif
