#ifndef TETRIS_CONSOLESET_H
#define TETRIS_CONSOLESET_H

#include <windows.h>
//控制台的相关函数

class ConsoleSet {
private:
    HANDLE hConsole;    // 句柄
    CONSOLE_FONT_INFOEX fontInfo;  // 字体信息
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo; // 缓冲区信息
    short x;            // 窗口右下角x坐标
    short y;            // 窗口右小角y坐标
public:
    ConsoleSet();

    ~ConsoleSet();

    short getX();       // return x
    short getY();       // return y
    HANDLE getHandle(); // return hConsole
    CONSOLE_FONT_INFOEX getFontInfo(); // return fontInfo
    CONSOLE_SCREEN_BUFFER_INFO getBufferInfo(); //return bufferInfo;
};

#endif //TETRIS_CONSOLESET_H
