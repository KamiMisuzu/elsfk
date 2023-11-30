#pragma once

#include <thread>
#include <iostream>
#include "Blocks.h"
#include "imageTool.h"
#include "Framework.h"

char** updateChessboard(Blocks* blocks, char** chessboard, int MovePosition, Framework* ptrmework); //¸üÐÂÆåÅÌÎ»ÖÃ
void gameoverFrame(Blocks* blocks, char** chessboard, Framework* ptrframework);
char** Judging_whether_to_score(Blocks* blocks, char** chessboard, Framework* ptrframework);
//void gameover()