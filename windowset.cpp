#include "windowset.h"

WindowSet::WindowSet() {
    ConsoleSet consoleSet;
}

WindowSet::~WindowSet() {
}

void WindowSet::setSize() {
    SMALL_RECT size = {0, 0, consoleSet.getX(), consoleSet.getY()};
    COORD bufferSize = {static_cast<short>(consoleSet.getX() + 1), static_cast<short>(consoleSet.getY() + 1)};
    SetConsoleWindowInfo(consoleSet.getHandle(), TRUE, &size);
    SetConsoleScreenBufferSize(consoleSet.getHandle(), bufferSize);
}

void WindowSet::setTerminalTittle() {
    SetConsoleTitle("Tetris");
}

void WindowSet::setColor(WORD color) {
    SetConsoleTextAttribute(consoleSet.getHandle(), color);
}

void WindowSet::setFontBig() {
    // 获取当前控制台字体属性
    CONSOLE_FONT_INFOEX fI = consoleSet.getFontInfo(); // 获取字体属性

    // 字体增大2倍
    fI.dwFontSize.X *= 2;
    fI.dwFontSize.Y *= 2;

    // 设置字体
    SetCurrentConsoleFontEx(consoleSet.getHandle(), false, &fI);
}

void WindowSet::setFontSmall() {
    // 获取当前控制台字体属性
    CONSOLE_FONT_INFOEX fI = consoleSet.getFontInfo();

    // 字体缩小两倍
    fI.dwFontSize.X /= 2;
    fI.dwFontSize.Y /= 2;

    //设置字体
    SetCurrentConsoleFontEx(consoleSet.getHandle(), false, &fI);
}

void WindowSet::setCursor(short x, short y) {
    SetConsoleCursorPosition(consoleSet.getHandle(), {x, y});
}

void WindowSet::hideCursor() {
    //获取并设置光标隐藏
    CONSOLE_CURSOR_INFO consoleCursorInfo;
    consoleCursorInfo.dwSize = 1; // 将光标大小设置为1
    consoleCursorInfo.bVisible = FALSE; // 将光标可见设置为false
    SetConsoleCursorInfo(consoleSet.getHandle(), &consoleCursorInfo);

}

void WindowSet::setMainTittle() {
    // 获取缓冲区信息
    CONSOLE_SCREEN_BUFFER_INFO bI = consoleSet.getBufferInfo();

    short cWidth = bI.srWindow.Right - bI.srWindow.Left + 1;  // 长度
    short cHeight = bI.srWindow.Bottom - bI.srWindow.Top + 1; // 高度
    short x = (cWidth - 65) / 2;
    short y = (cHeight - 10) / 2;

    setCursor(x, y);
    std::cout << "Tetris";

    setCursor(x - 10, y + 2);
    setFontSmall();
    std::cout << "Press Any Key To Start Game!";
}