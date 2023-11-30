#pragma once
#include "Interactive.h"
#include "Blocks.h"
#include <string.h>
#include <iostream>
class Framework
{
private:
	Interactive* ptrInteractive;
	int Chessboardsize[2]; //棋盘大小默认10x20
	int score; //得分
	bool EndGameFlag =0;
	std::string Scoreshape;
public:
	Framework(Interactive* interactive =nullptr, int xSize =10 , int ySize =20 ) : ptrInteractive(interactive) {
		this->score = 0;
		this->Chessboardsize[0] = xSize;
		this->Chessboardsize[1] = ySize;
		this->Scoreshape = "";
		for (int i = 0; i < this->Chessboardsize[0] + 2; i++)
		{
			if (i == 0 or i == this->Chessboardsize[0] + 1) {
				Scoreshape += "|";
				continue;
			}
			Scoreshape += '#';
		}
	}
	bool init(int flag); //初始化
	char** Startgame(); //启动游戏
	void Endgame(char** qp, Blocks* blocks); //结束游戏
	int* getChessboardsize(); //获取棋盘大小
	int getScore(); //获取当前得分
	int setScore(); //设置当前得分
	void setEndGameFlag(bool flag);
	bool getEndGameFlag();
	std::string getScoreshape();
};

