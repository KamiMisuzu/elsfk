#include "Interactive.h"
#include "imageTool.h"
int Interactive::display()
{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // ���û�ɫ

    centerText("��ӭ��������˹����");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    std::cout << std::endl; // ��һ��

    centerText("1] ��ʼ��Ϸ");
    centerText("2] ��ʷ��¼");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // ������ɫ

    centerText("   _______ ");
    centerText("  /       \\");
    centerText(" /         \\");
    centerText(" /           \\");
    centerText("  \\           /");
    centerText(" \\         /");
    centerText("  \\_______/");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return getchar() > 0 ? TRUE : FALSE; 
}


void Interactive::Historicalranking()
{
}

char** Interactive::Start(const int xSize, const int ySize)
{
    char** checkerboard = new char* [ySize + 2];
    for (int i = 0; i < ySize + 2; i++) { 
        checkerboard[i] = new char[xSize + 3];
        for (int j = 0; j < xSize + 3; j++) {
            if (i == 0 || i == ySize+1) {
                if (j == xSize + 2) {
                    checkerboard[i][j] = '\0';
                    continue;
                }
                checkerboard[i][j] = '=';
                continue;
            }
            if (j == 0 || j == xSize + 1) { 
                checkerboard[i][j] = '|';
            }
            else if (j != xSize + 2) {
                checkerboard[i][j] = '+';
            }
            else {
                checkerboard[i][j] = '\0';
            }
            
        }
        
    }
    return checkerboard;
}
