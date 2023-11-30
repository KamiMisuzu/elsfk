#pragma once
#include "Blocks.h"
class square :
    public Blocks
{
public:
    square() {
        int** tempshep = new int* [2];
        for (int i = 0; i < 2; ++i) {
            tempshep[i] = new int[2];
        }

        tempshep[0][0] = 1;
        tempshep[0][1] = 2;
        tempshep[1][0] = 1;
        tempshep[1][1] = 2;
        //020212
        this->shape = tempshep;
        this->wideshape = 2;
        this->longshape = 2;
    }
};

