#pragma once

#ifndef TETRIS_CONSOLESET_H
#define TETRIS_CONSOLESET_H

#include <windows.h>
//控制台的相关函数

// 点坐标
struct Point
{
	short x;
	short y;
};

class ConsoleSet
{
private:
	HANDLE hConsole;                        // 句柄
	CONSOLE_FONT_INFOEX fontInfo{};           // 字体信息
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo{};  // 缓冲区信息
	Point windowPoint{};                      // 窗口坐标

public:
	ConsoleSet();

	~ConsoleSet();

	[[nodiscard]] short getX() const;                                       // return x
	[[nodiscard]] short getY() const;                                       // return y
	[[nodiscard]]HANDLE getHandle() const;                                  // return hConsole
	[[nodiscard]]CONSOLE_FONT_INFOEX getFontInfo() const;                   // return fontInfo
	[[nodiscard]]CONSOLE_SCREEN_BUFFER_INFO getBufferInfo() const;          //return bufferInfo;
	void setCursor(short x, short y);                                       // 设置光标位置
};

#endif //TETRIS_CONSOLESET_H
