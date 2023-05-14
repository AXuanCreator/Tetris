#include "consoleset.h"

ConsoleSet::ConsoleSet()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 设置句柄
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hConsole, false, &fontInfo); // 获取字体属性
	GetConsoleScreenBufferInfo(hConsole, &bufferInfo);                // 获取缓冲区属性

	windowPoint.x = 55;
	windowPoint.y = 25;
}

ConsoleSet::~ConsoleSet() = default;

short ConsoleSet::getX() const
{
	return windowPoint.x;
}

short ConsoleSet::getY() const
{
	return windowPoint.y;
}

HANDLE ConsoleSet::getHandle() const
{
	return hConsole;
}

CONSOLE_FONT_INFOEX ConsoleSet::getFontInfo() const
{
	return fontInfo;
}

CONSOLE_SCREEN_BUFFER_INFO ConsoleSet::getBufferInfo() const
{
	return bufferInfo;
}

void ConsoleSet::setCursor(short x, short y)
{
	SetConsoleCursorPosition(hConsole, { x, y });
}
