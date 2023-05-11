#include "consoleset.h"

ConsoleSet::ConsoleSet() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 设置句柄
    fontInfo.cbSize = sizeof(fontInfo);
    GetCurrentConsoleFontEx(hConsole,false,&fontInfo); // 获取字体属性
    GetConsoleScreenBufferInfo(hConsole,&bufferInfo);                // 获取缓冲区属性

	moveRange.x = 37;
	moveRange.y = 24;
    x = 55;
    y = 25;
}

ConsoleSet::~ConsoleSet() = default;




short ConsoleSet::getX() const {
    return x;
}

short ConsoleSet::getY() const{
    return y;
}

HANDLE ConsoleSet::getHandle() {
    return hConsole;
}

CONSOLE_FONT_INFOEX ConsoleSet::getFontInfo() {
    return fontInfo;
}

CONSOLE_SCREEN_BUFFER_INFO ConsoleSet::getBufferInfo() {
    return bufferInfo;
}

void ConsoleSet::setCursor(short x, short y) {
    SetConsoleCursorPosition(hConsole, {x, y});
}

void ConsoleSet::changeMoveRange(short x , short y)
{
	moveRange.x +=x;
	moveRange.y +=y;
}
Point ConsoleSet::getRange() const
{
	return moveRange;
}
