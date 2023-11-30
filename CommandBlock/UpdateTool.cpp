
#include "UpdateTool.h"
#include "Framework.h"
#include "Solvingarrays.h"
//棋盘X大小xSize
//棋盘Y大小ySize 
//MovePosition 移动的位置
//currentlocation 位置
//chessboard 棋盘
//shape 形状01
//longshape 长
//wideshape 宽

char** updateChessboard(Blocks* blocks, char** chessboard, int MovePosition, Framework * ptrmework)
{
	int tempX = blocks->getPosition()[0];
 	int tempY = blocks->getPosition()[1];
	int postsiond[1][2] = { {tempX,tempY} };
	int wideshape = blocks->getWideshape();
	int longshape = blocks->getLongshape();
	int** shape = blocks->getShape();
	int*** tempReplace = Coordinate_dimensional_array(wideshape, longshape, tempX, tempY);
	
	chessboard = Updatepatterns(blocks, chessboard, '+');
	/*if (chessboard[tempY + longshape][tempX] == '=' or chessboard[tempY + longshape][tempX] == '#' or chessboard[tempY + longshape][tempX + 1] == '=' or chessboard[tempY + longshape][tempX + 1] == '#')*/
	blocks->setpositionMap();
	int boolpost = Is_there_a_judgment_point(blocks, chessboard, MovePosition);
	if(boolpost==1)
	{

		if (chessboard[tempY][tempX] == '=') {
			ptrmework->setEndGameFlag(1);
		}
		blocks->setPositionstatus(0);
		MovePosition = 0;
	}
	else if(boolpost==2)
	{
		MovePosition = 0;
	}


	tempReplace = Coordinate_dimensional_array(wideshape, longshape, tempX, tempY, MovePosition,blocks,ptrmework);
	chessboard = Updatepatterns(blocks, chessboard, '#');
	
	delete[] tempReplace;
	return 	chessboard;
}

void gameoverFrame(Blocks* blocks, char** chessboard,Framework* ptrframework)
{
	int tempX = blocks->getPosition()[0];
	int tempY = blocks->getPosition()[1];
	int wideshape = blocks->getWideshape();
	int longshape = blocks->getLongshape();
	int** shape = blocks->getShape();
	int*** tempReplace = new int** [wideshape];
	int kuan = 0;
	for (int i = 0; i < wideshape; i++)
	{

		int chang = 0;
		tempReplace[i] = new int* [longshape];
		for (int j = 0; j < longshape; j++)
		{
			tempReplace[i][j] = new int[2];
			tempReplace[i][j][0] = tempX + kuan;
			tempReplace[i][j][1] = tempY + chang;
			chang++;
		}
		kuan++;
	}
	for (int i = 0; i < wideshape; i++)
	{
		for (int j = 0; j < longshape; j++)
		{
			if (shape[j][i] == 1)
			{
				int writeX = tempReplace[i][j][0];
				int writeY = tempReplace[i][j][1];
				chessboard[writeY][writeX] = '#';
			}
		}
	}
	for (int i = 0; i <= ptrframework->getChessboardsize()[1]+1; i++)
	{
		centerText(chessboard[i]);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(100000));
}

char** Judging_whether_to_score(Blocks* blocks, char** chessboard, Framework* ptrframework) {
	
    int scoreRows = 0;
    int Record[4] = { 0, 0, 0, 0 };
	int rows = ptrframework->getChessboardsize()[1];
	int cols = ptrframework->getChessboardsize()[0];

    int i;
    for (i = 0; i < rows + 2; i++) {
        if (chessboard[i] == ptrframework->getScoreshape()) {
            Record[scoreRows] = i;
            scoreRows++;
        }
    }
	if (scoreRows != 0) {
		char** tempchessboard;
		tempchessboard = new char* [rows + 2];

		int z;
		for (z = 0; z < rows + 2; z++) {
			tempchessboard[z] = new char[cols + 2];
		}
		for (int k = 0; k < scoreRows; ++k) {
			int row = Record[k];

			for (int j = 0; j < rows + 2; ++j) {
				if (j <= 1) {
					memcpy(tempchessboard[j], chessboard[j], sizeof(char) * (cols + 2));
				}
				else {
					memcpy(tempchessboard[j], chessboard[j - 1], sizeof(char) * (cols + 2));
				}
			}

			for (int i = 1; i < row + 1; ++i) {
				memcpy(chessboard[i], tempchessboard[i], sizeof(char) * (cols + 2));
			}
		}
		for (z = 0; z < rows + 2; z++) {
			delete[] tempchessboard[z];
		}
		delete[] tempchessboard;
		return chessboard;
	}

   
    return chessboard;
}