#ifndef _GAME_H
#define _GAME_H

#include "main.h"

#define STATIC_SPACE_SHIP_WIDTH 3
#define STATIC_SPACE_SHIP_HEIGHT 3

unsigned int UserSpaceShip[STATIC_SPACE_SHIP_HEIGHT][STATIC_SPACE_SHIP_WIDTH] = {
    {0, 1, 0},
    {1, 1, 1},
    {1, 0, 1}
};

#endif