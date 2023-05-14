#pragma once

// 地图类
#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <iomanip>
#include "consoleset.h"

static int myMap[26][39];   // 地图，0代表墙体，1代表可移动区域
static int rowFull[26];     // 行哨兵，若某一行等于37，则代表此行已满
static int scores = 0;      // 分数

class Map
{
private:
	ConsoleSet consoleSet;  // 控制台对象

public:
	Map();
	~Map();

	void mapInit();                                                 // 地图初始化
	bool checkMap(short x, short y) const;                          // 检测越界
	void mapChange(short x, short y, bool bl);                      // 地图更改
	void refreshMap(short r);                                       // 根据myMap来刷新地图
	void rowAdd(short r);                                           // 当前行+1
	void rowDele(short r);                                          // 删除行
	bool rowDead();                                                 // 死亡判定
	void refreshScore();                                            // 刷新分数


	void printMap() const;                                          // [测试用] 打印地图隐藏值
};
#endif //MAP_H
