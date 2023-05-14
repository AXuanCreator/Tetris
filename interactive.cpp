#include "interactive.h"


Interactive::Interactive()
= default;

Interactive::~Interactive()
= default;

void Interactive::cleanScreen()
{
	_getch();
	system("cls");  // 清屏
}

void Interactive::creatBlockGroup()
{
	bG = bgNext;
	if (bG != nullptr)
		bG->printBlockGroup();  // 打印
	nextCreat();
}

void Interactive::controlMove()
{
	if (bG == nullptr)
		return;

	clock_t start, end;
	while (true)
	{
		start = clock();
		end = clock();
		while (end - start < 550)   // 时间若大于0.75s，则自动下落
		{
			bG->blockMove('t'); // t仅为判断用，无特殊含义
			end = clock();
		}
		if (bG->checkBlockBottom(true, 0, 1)) // true表示会顺便对地图做出修改，而false则仅用于判断
		{
			break;
		}
		bG->blockMove('s');      // 强制下落

	}

	bG->checkRowFull(); // 检测行是否已满

	// 当出while，则代表抵达底部，若未死亡，则新建1个方块组继续
	delete bG;           //  删除对象
	if (map.rowDead())   // 检测首行是否存在方块
	{
		system("cls");
		consoleSet.setCursor(22, 11);
		std::cout << "Game Over!";
		return;
	}
	else
	{
		startBlock();    // 重新开始
	}

}
void Interactive::startBlock()
{
	creatBlockGroup();  // 新建方块组
	controlMove();      // 控制移动
}

void Interactive::nextCreat()
{
	if (bgNext != nullptr)
		bgNext->blockClean(44, 18); // 清除指定位置的方块组
	bgNext = new BlockGroup(rG.blockCreatRandom()); // 创建一个新的方块组，用于提示下一个方块形状
	bgNext->printBlockGroup(44, 18);               // 在指定位置打印
}
