#pragma once
#include "Blocks.h"
class Ishaped :
    public Blocks
{
public:
    Ishaped() {
        int** tempshep = new int* [4];
        for (int i = 0; i < 4; ++i) {
            tempshep[i] = new int[1];
        }

        tempshep[0][0] = 1;
        tempshep[1][0] = 1;
        tempshep[2][0] = 1;
        tempshep[3][0] = 1;
        
        //020212
        this->shape = tempshep;
        this->wideshape = 1;
        this->longshape = 4;
    }

};

