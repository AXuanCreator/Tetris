// 界面的一些元素
#ifndef TETRIS_ELEMENT_H
#define TETRIS_ELEMENT_H

#include "consoleset.h" // 控制台信息
#include "blockgroup.h" // 方块组
#include "randomgen.h"  // 随机数生成
#include <iostream>
#include <iomanip>

class Element
{
private:
	ConsoleSet consoleSet;
	RandomGen randomGen;
public:
	Element();

	~Element();

	void countDown();   // 倒计时
	void creatBlockGroup(); // 制造1个方块组
};


#endif //TETRIS_ELEMENT_H
