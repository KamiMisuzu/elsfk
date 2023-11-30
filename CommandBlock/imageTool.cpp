#pragma

#include "imageTool.h"
void centerText(const std::string& text) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, xPos;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    xPos = (columns - static_cast<int>(text.length())) / 2;
    for (int i = 0; i < xPos; ++i) {
        std::cout << " ";
    }
    std::cout << text << std::endl;
}

void clearScreen() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = false; // Òþ²Ø¹â±ê
    SetConsoleCursorInfo(console, &cursorInfo);
    DWORD written;
    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}