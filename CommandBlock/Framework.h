#pragma once
#include "Interactive.h"
#include "Blocks.h"
#include <string.h>
#include <iostream>
class Framework
{
private:
	Interactive* ptrInteractive;
	int Chessboardsize[2]; //���̴�СĬ��10x20
	int score; //�÷�
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
	bool init(int flag); //��ʼ��
	char** Startgame(); //������Ϸ
	void Endgame(char** qp, Blocks* blocks); //������Ϸ
	int* getChessboardsize(); //��ȡ���̴�С
	int getScore(); //��ȡ��ǰ�÷�
	int setScore(); //���õ�ǰ�÷�
	void setEndGameFlag(bool flag);
	bool getEndGameFlag();
	std::string getScoreshape();
};

