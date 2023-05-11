#ifndef TETRIS_BLOCKGROUP_H
#define TETRIS_BLOCKGROUP_H

#include "block.h"
#include <conio.h>
#include <iostream>


struct MoveCheck
{
	short left;
	short right;
	short down;
};
class BlockGroup
{
private:
	Block block[4]; // 四个方块组成一个图形
	MoveCheck moveCheck; // 控制移动时的判定

public:
	BlockGroup();
	BlockGroup(int val); // 用于生成四种不同的形状
	~BlockGroup();

	void blockMove();             // 方块运动
	void printBlockGroup() const; // 打印方块组
	MoveCheck checkBlockGroup() const; // 用于判定哪一个方块是移动时判定的关键
};

#endif //TETRIS_BLOCKGROUP_H
