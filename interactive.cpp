#include "interactive.h"


Interactive::Interactive()
{
	pos = st_pos++;
}

Interactive::~Interactive()
{

}

void Interactive::cleanScreen()
{
	_getch();
	system("cls");  // 清屏
}

void Interactive::creatBlockGroup()
{
	bG = new BlockGroup(rG.blockCreatRandom()); // 生成1个方块组
	bG->printBlockGroup();                       // 打印
}



void Interactive::controlMove()
{

	clock_t start, end;
	while (true)
	{
		start = clock();
		end = clock();
		while (end - start < 750) //时间若大于0.75s，则自动下落
		{
			bG->blockMove('t'); // t仅为判断用，无特殊含义
			end = clock();
		}
		if(bG->checkBlockBottom(true, 0, 1)) // true表示会顺便对地图做出修改，而false则仅用于判断
		{
			break;
		}
		bG->blockMove('s');      // 强制下落

	}


	bG->checkRowFull(); // 检测行
	// 当出while，则代表抵达底部，若未死亡，则新建1个方块组继续

	/* if(...) */
	delete bG;
	startBlock();

}
void Interactive::startBlock()
{

	creatBlockGroup();
	controlMove();
}
