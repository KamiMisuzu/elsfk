
#include "Solvingarrays.h"
int*** Coordinate_dimensional_array(int wideshape, int longshape,int tempX,int tempY) {
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
	return tempReplace;
}
                                                  

int*** Coordinate_dimensional_array(int wideshape, int longshape, int tempX, int tempY, int MovePosition,Blocks* blocks,Framework* ptrwork) {
	int*** tempReplace = new int** [wideshape];
	int kuan = 0;
	for (int i = 0; i < wideshape; i++)
	{
		int chang = 0;
		tempReplace[i] = new int* [longshape];
		for (int j = 0; j < longshape; j++)
		{			
			tempReplace[i][j] = new int[2];
			switch (MovePosition)
			{		
			case 0:
				tempReplace[i][j][0] = tempX + kuan;
				tempReplace[i][j][1] = tempY + chang;
				break;
			case 75: //左
				if (tempX - 1 == 0) {
					tempReplace[i][j][0] = tempX + kuan;
					tempReplace[i][j][1] = tempY + chang + 1;
					break;
				}	
				tempReplace[i][j][0] = tempX + kuan -1;
				tempReplace[i][j][1] = tempY + chang + 1;
				break;
			case 77: //右
				if (tempX+ 2 == ptrwork->getChessboardsize()[0]+1) {
					tempReplace[i][j][0] = tempX + kuan;
					tempReplace[i][j][1] = tempY + chang + 1;
					break;
				}	
				tempReplace[i][j][0] = tempX + kuan + 1;
				tempReplace[i][j][1] = tempY + chang + 1;
				break;
			case 80: //下
				tempReplace[i][j][0] = tempX + kuan;
				tempReplace[i][j][1] = tempY + chang + 1;
				break;
			default:
				tempReplace[i][j][0] = tempX + kuan;
				tempReplace[i][j][1] = tempY + chang + 1;
			}		
					
			if (i == 0 and j == 0)
			{		
				blocks->setPosition(tempReplace[i][j]);
			}		
			chang++;
		}
		kuan++;
	}
	return tempReplace;
}

char** Updatepatterns(Blocks* blocks,char** chessboard, char pattern)
{

	std::map<std::string, std::string> map = blocks->getpositionMap();
	int** one = new int* [12];
	int** two = new int* [12];
	int** zero = new int* [12];
	int o = 0;
	int t1 = 0;
	int z = 0;
	for (int i = 0; i < 12; i++)
	{
		one[i] = new int[2];
		two[i] = new int[2];
		zero[i] = new int[2];
	}
	std::string token;
	for (const auto& pair : map) {
		std::string zp = pair.first;
		std::istringstream iss(zp);
		std::vector<std::string> tokens;
		std::string token;
		int value = std::stoi(pair.second);
		while (std::getline(iss, token, ',')) {
			tokens.push_back(token);
		}
		int jsd = 0;
		for (const auto& t : tokens) {
			bool pandu = false;
			if (jsd == 0)
			{ //y
				switch (value)
				{
				case 0: //空值
					zero[z][0] = std::stoi(t);
					break;
				case 1: //左有
					one[o][0] = std::stoi(t);
					break;
				case 2: //右有
					two[t1][0] = std::stoi(t);
					break;
				default:
					break;
				}
			}
			else
			{
				switch (value)
				{ //x
				case 0: //空值
					zero[z][1] = std::stoi(t);
					z++;
					break;
				case 1: //左有
					one[o][1] = std::stoi(t);
					o++;
					break;
				case 2: //右有
					two[t1][1] = std::stoi(t);
					t1++;
					break;
				default:
					break;
				}
			}
			jsd++;
		}
	}
	for (int i = 0; i < o; i++)
	{
		int tempx =one[i][0];
		int tempy =one[i][1];
		if (chessboard[tempx][tempy] == '=')
		{
			continue;
		}
		chessboard[tempx][tempy] = pattern;
	}
	for (int i = 0; i < t1; i++)
	{
		int tempx = two[i][0];
		int tempy = two[i][1];
		if (chessboard[tempx][tempy] == '=')
		{
			continue;
		}
		chessboard[tempx][tempy] = pattern;
	}
	// 在使用完后释放内存
	for (int i = 0; i < 12; i++) {
		delete[] one[i];
		delete[] two[i];
		delete[] zero[i];
	}

	delete[] one;
	delete[] two;
	delete[] zero;

	return chessboard;
}

int Is_there_a_judgment_point(Blocks* blocks,char** qp,int moveposition)
{
	int fhz = 0;
	int MaxXo = 0;
	int MaxYo = 0;
	int MaxXt = 0;
	int MaxYt = 0;
	int tempnumberx = NULL;
	int tempnumbery = NULL;
	std::map<std::string, std::string> map = blocks->getpositionMap();
	int** one = new int*[12];
	int** two = new int*[12];
	int** zero = new int*[12];
	int** someof = new int* [12];
	int** downward = new int* [12];
	int o = 0;
	int t1 = 0;
	int z = 0;
	int s = 0;
	int d = 0;

	for (int i = 0; i < 12; i++)
	{
		one[i] = new int[2];
		two[i] = new int[2];
		zero[i] = new int[2];
		someof[i] = new int[2];
		downward[i] = new int[2];
	}

	std::string token;
	for (const auto& pair : map) {
		std::string zp = pair.first;
		std::istringstream iss(zp);
		std::vector<std::string> tokens;
		std::string token;
		int value = std::stoi(pair.second);
		while (std::getline(iss, token, ',')) {
			tokens.push_back(token);
		}
		int jsd = 0;
		for (const auto& t : tokens) {
			bool pandu = false;
			if (jsd==0)
			{ //y
				switch (value)
				{
				case 0: //空值
					zero[z][0] = std::stoi(t);
					break;
				case 1: //左有
					one[o][0] = std::stoi(t);
					break;
				case 2: //右有
					two[t1][0] = std::stoi(t);
					break;
				default:
					break;
				}
			}
			else
			{
				switch (value)
				{ //x
				case 0: //空值
					zero[z][1] = std::stoi(t);
					z++;
					break;
				case 1: //左有
					one[o][1] = std::stoi(t);
					o++;
					break;
				case 2: //右有
					two[t1][1] = std::stoi(t);
					t1++;
					break;
				default:
					break;
				}
			}
			jsd++;
		}	
	}
	switch (moveposition)
	{
	case 75: //左
		for (int i = 0; i < o; i++)
		{
			int tempX = one[i][0];
			int tempY = one[i][1];
			if (qp[tempY][tempX - 1] == '|' or qp[tempY][tempX - 1] == '#') {
				fhz = 2;
				break;
			}
		}
		break;
	case 77: //右
		for (int i = 0; i < z; i++)
		{
			int tempX = two[i][0];
			int tempY = two[i][1];
			if (qp[tempX][tempY+1] == '|' or qp[tempX][tempY +1] == '#') {
				fhz = 2;
				break;
			}
		}
		break;
	case 80: //下
		
		for (int i = 0; i < o; i++)
		{
			MaxXo = one[i][0] > MaxXo ? one[i][0] : MaxXo;
			MaxYo = one[i][0] > MaxYo ? one[i][1] : MaxYo;
		}
		for (int i = 0; i < t1; i++)
		{
			MaxXt = two[i][0] > MaxXt ? two[i][0] : MaxXt;
			MaxYt = two[i][0] > MaxYt ? two[i][1] : MaxYt;
		}
		
		if (qp[MaxXo+1][MaxYo] =='=' or qp[MaxXo + 1][MaxYo] =='#' or qp[MaxXt + 1][MaxYt] == '=' or qp[MaxXt + 1][MaxYt] == '#')
		{
			fhz = 1;
		}
		break;
	default:
		break;
	}

	for (int i = 0; i < 12; i++) {
		delete[] one[i];
		delete[] two[i];
		delete[] zero[i];
		delete[] someof[i];
		delete[] downward[i];
	}

	delete[] one;
	delete[] two;
	delete[] zero;
	delete[] someof;
	delete[] downward;
	return fhz;
}

