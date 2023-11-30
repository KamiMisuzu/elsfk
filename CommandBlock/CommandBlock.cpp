// CommandBlock.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <thread>
#include "Blocks.h"
#include "Framework.h"
//#include "Interactive.h"
#include "imageTool.h"
#include "jIshaped.h"
#include "UpdateTool.h"
#include "Solvingarrays.h"
#include <conio.h>
#include "Ishaped.h"
#include "square.h"
int main()
{
	Interactive* interactive = new Interactive();
	Framework* ptrMework = new Framework(interactive, 10, 20);
	if (ptrMework->init(interactive->display())) {
		int postiton[2] = { 1,2 };
		char** qp = ptrMework->Startgame();
		Blocks* jishaped = new jIshaped(); 
		jishaped->setPosition(postiton);
		int ch = 0;
		while (true)
		{
			
			if (_kbhit()) {
				ch = _getch();
			}
			else if (ch == 224) {
				ch = 80;
			}
			else {
				ch = 80;
			}
			qp = updateChessboard(jishaped, qp, ch, ptrMework);
			
			if (ptrMework->getEndGameFlag()) {
				ptrMework->Endgame(qp, jishaped);
				delete qp;
				break;
			}
			if (jishaped->getPositionstatus() == 0) {
				qp = Judging_whether_to_score(jishaped, qp, ptrMework);
				int postrs = 6;
				delete jishaped;
				std::srand(static_cast<unsigned int>(std::time(nullptr)));
				int randomNumber = std::rand() % 3;
				switch (randomNumber)
				{
				case 0:
					jishaped = new jIshaped();
					break;
				case 1:
					jishaped = new Ishaped();
					break;
				case 2:
					jishaped = new square();
					break;
				}
				int postiton[2] = { postrs,0 };
				jishaped->setPosition(postiton); 
			}
			clearScreen();
			for (size_t i = 0; i <= ptrMework->getChessboardsize()[1]+1; i++)
			{
				centerText(qp[i]);
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}

	}
}
