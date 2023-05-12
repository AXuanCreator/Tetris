// 地图类
#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "consoleset.h" // 临时

static int myMap[26][39];   // 地图，可以范围是X[1~37] Y[1~24] 算上周围的墙体,共39*26
static int rowFull[26];
class Map
{
private:
	ConsoleSet consoleSet;
public:
	Map();
	~Map();

	void mapInit();      // 地图初始化
	bool checkMap(short x, short y) const;              // 检测越界
	void mapChange(short x , short y ,bool bl);         // 地图更改
	void refreshMap(short r);                                     // 根据myMap来刷新地图
	void rowAdd(short r);                               // 当前行+1
	void rowDele(short r);                              // 删除行


	void printMap() const;              // [测试用] 打印地图隐藏值
};
#endif //MAP_H
