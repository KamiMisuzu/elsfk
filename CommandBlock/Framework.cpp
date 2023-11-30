#include "Framework.h"
#include "imageTool.h"
#include "UpdateTool.h"
bool Framework::init(int flag)
{
	if (flag ==1)
	{
		if (this->ptrInteractive == nullptr) {
			std::cout<< "无法获取UI界面";
			return 0;
		}
		else if (this->getChessboardsize()[0] == NULL) {
			std::cout << "未设置棋盘大小";
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		//
	}
}

char** Framework::Startgame() 
{ 
	int xSize = this -> getChessboardsize()[0];
	int ySize = this->getChessboardsize()[1];
	return this->ptrInteractive->Start(xSize, ySize);
}

void Framework::Endgame(char** qp,Blocks* blocks)
{
	gameoverFrame(blocks,qp,this);
	this->ptrInteractive->display();
}

int* Framework::getChessboardsize() 
{
	return this->Chessboardsize;
}

int Framework::getScore()
{
	return 0;
}

int Framework::setScore()
{
	return 0;
}

void Framework::setEndGameFlag(bool flag)
{
	this->EndGameFlag = flag;
}

bool Framework::getEndGameFlag()
{
	return this->EndGameFlag;
}

std::string Framework::getScoreshape()
{
	return this->Scoreshape;
}
