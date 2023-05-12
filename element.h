// 界面的一些元素
#ifndef TETRIS_ELEMENT_H
#define TETRIS_ELEMENT_H

#include "consoleset.h" // 控制台信息
#include "blockgroup.h" // 方块组
#include <iostream>
#include <iomanip>
#include <conio.h>

class Element
{
private:
	ConsoleSet consoleSet;
public:
	Element();

	~Element();

	void countDown();   // 倒计时

};


#endif //TETRIS_ELEMENT_H
