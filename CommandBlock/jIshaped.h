#pragma once
#include "Blocks.h"
#include <iostream>

class jIshaped :
    public Blocks
{
public:
    jIshaped() {
    int** tempshep = new int* [3];
    for (int i = 0; i < 3; ++i) {
        tempshep[i] = new int[2];
    }

    tempshep[0][0] = 0;
    tempshep[0][1] = 0;
    tempshep[1][0] = 1;
    tempshep[1][1] = 2;
    tempshep[2][0] = 2;
    tempshep[2][1] = 2;
    //020212
    this->shape = tempshep;
    this->wideshape = 2;
    this->longshape = 3;
}

};

