#pragma once

#ifndef TETRIS_INTERACTIVE_H
#define TETRIS_INTERACTIVE_H
#include <conio.h>
#include <cstdlib>
#include <conio.h>

#include "consoleset.h"
#include "blockgroup.h"
#include "randomgen.h"
#include "map.h"

/*
 * 此头文件用于管理方块组，包括但不限于 方块组的创建，方块组的移动
 */


class Interactive
{
private:
	ConsoleSet consoleSet;              // 控制台参数
	BlockGroup* bgNext{};                 // 下一个方块组
	BlockGroup* bG{};                     // 方块组
	RandomGen rG;                       // 随机数生成器
	Map map;                            // 地图
public:
	Interactive();
	~Interactive();
	void cleanScreen();                 // 清屏
	void creatBlockGroup();             // 创建方块组
	void controlMove();                 // 控制移动
	void startBlock();                  // 开始创建、打印、移动方块组
	void nextCreat();                   // 创建下一个方块组
};

#endif //TETRIS_INTERACTIVE_H
