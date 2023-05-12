#ifndef TETRIS_INTERACTIVE_H
#define TETRIS_INTERACTIVE_H
#include <conio.h>
#include <cstdlib>
#include <conio.h>

#include "blockgroup.h"
#include "randomgen.h"
#include "map.h"
/*
 * 此头文件用于管理方块组，包括但不限于 方块组的创建，方块组的移动
 */

static int st_pos = 0;
class Interactive
{
private:
	BlockGroup* bG;  // 方块组
	RandomGen rG;        // 随机数生成器
	Map map;         // 地图
	int pos;
public:
    Interactive();
    ~Interactive();
    void cleanScreen();
	void creatBlockGroup();
	void controlMove();
	void startBlock();  // 再次开始程序
};
#endif //TETRIS_INTERACTIVE_H
