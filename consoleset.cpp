#include "consoleset.h"

ConsoleSet::ConsoleSet() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 设置句柄
    fontInfo.cbSize = sizeof(fontInfo);
    GetCurrentConsoleFontEx(hConsole,false,&fontInfo); // 获取字体属性
    GetConsoleScreenBufferInfo(hConsole,&bufferInfo);                // 获取缓冲区属性

    x = 110;
    y = 50;
}

ConsoleSet::~ConsoleSet() {}




short ConsoleSet::getX() {
    return x;
}

short ConsoleSet::getY(){
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