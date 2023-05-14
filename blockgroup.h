#pragma once

#ifndef TETRIS_BLOCKGROUP_H
#define TETRIS_BLOCKGROUP_H

#include "block.h"
#include "map.h"
#include <conio.h>
#include <iostream>
#include <ctime>

#define BX1 block[1].getBlockX()
#define BX2 block[2].getBlockX()
#define BX3 block[3].getBlockX()
#define BX0 block[0].getBlockX()
#define BY1 block[1].getBlockY()
#define BY2 block[2].getBlockY()
#define BY3 block[3].getBlockY()
#define BY0 block[0].getBlockY()
#define B1 block[1]
#define B2 block[2]
#define B3 block[3]
#define B0 block[0]

class BlockGroup
{
private:
	Block block[4];         // 四个方块组成一个图形
	Map map;                // 地图
	int sign{};               // 特征值，不同值代表着不同形状，原值有4个

public:
	BlockGroup();
	BlockGroup(int val);    // 用于生成四种不同的形状
	~BlockGroup();

	void blockMove(char ch);                            // 方块运动
	void changeBlockGroup();                            // 更改方块类型
	void blockSign(short x0,
		short y0,
		short x1,
		short y1,
		short x2,
		short y2,
		short x3,
		short y3,
		int _sign);                                     // 方块类型变更
	void printBlockGroup() const;                       // 打印方块组
	void printBlockGroup(short x, short y) const;       // 打印方块组-坐标指定
	bool checkBlockBottom(bool sw, short _x, short _y);                // 检测是否抵达相对底部
	void checkRowFull();                                // 检查行是否已满
	void getAction(char& ch);                           // 方块移动
	void blockClean();                                  // 方块清除
	void blockClean(short x, short y);                  // 方块清除-相对方块坐标

};

#endif //TETRIS_BLOCKGROUP_H
