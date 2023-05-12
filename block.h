#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H
// 一个方块的对象
#include "consoleset.h"
#include "map.h"
#include <iostream>

class Block
{
private:
	ConsoleSet consoleSet; // 控制台信息实例
	Point point; // Point是一个struct类型，位于consoleset.h，用于存储坐标
	Map map;     // 地图
public:
	Block();
	~Block();

	void creatBlock(short _x, short _y); // 制造1个方块
	void printBlock();                   // 打印方块
	void cleanBlock();                   // 清除方块
	bool checkBlock(short _x,short _y);                   // 检查越界
	void changeBlockX(short m);
	void changeBlockY(short m);
	void changeBlockXY(short _x, short _y); // 改变坐标XY
	short getBlockX() const;  // return point.x
	short getBlockY() const;  // return point.y
};
#endif // TETRIS_BLOCK_H
