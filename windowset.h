#pragma once

#ifndef _WINDOW_H
#define _WINDOW_H
#include <windows.h>
#include <iostream>

#include "consoleset.h"
#include "interactive.h"

// 设置控制台窗口属性
class WindowSet
{
private:
	ConsoleSet consoleSet;  // 控制台实例
	Interactive iA;         // 交互实例
public:
	WindowSet();
	~WindowSet();
	void setSize();             // 设置大小(120*50)
	void setTerminalTittle();   // 设置终端标题
	void setColor(WORD color);  // 设置颜色
	void setFontBig();          // 设置字体更大
	void setFontSmall();        // 设置字体更小
	void setMainTittle();       // 设置主标题
	void hideCursor();          // 隐藏光标
	void drawBoard();           // 界面
};

#endif