#pragma once
#include "Blocks.h"

#include "Framework.h"
int*** Coordinate_dimensional_array(int wideshape, int longshape, int tempX, int tempY);
int*** Coordinate_dimensional_array(int wideshape, int longshape, int tempX, int tempY, int MovePosition, Blocks* blocks, Framework* ptrwork);
char** Updatepatterns(Blocks* blocks, char** chessboard, char pattern);
int Is_there_a_judgment_point(Blocks* blocks, char** qp, int moveposition);
