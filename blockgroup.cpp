//
// Created by AXuan on 2023/5/10.
//

#include "blockgroup.h"

BlockGroup::BlockGroup()
{
}

BlockGroup::BlockGroup(int val)
{
	if (val == 1)
	{
		block[0].creatBlock(1, 1);
		block[1].creatBlock(2, 1);
		block[2].creatBlock(3, 1);
		block[3].creatBlock(4, 1);
	}
	else if (val == 2)
	{
		block[0].creatBlock(1, 1);
		block[1].creatBlock(1, 2);
		block[2].creatBlock(2, 1);
		block[3].creatBlock(3, 1);
	}
	else if (val == 3)
	{
		block[0].creatBlock(1, 1);
		block[1].creatBlock(2, 1);
		block[2].creatBlock(2, 2);
		block[3].creatBlock(3, 1);
	}
	else if (val == 4)
	{
		block[0].creatBlock(1, 1);
		block[1].creatBlock(2, 1);
		block[2].creatBlock(2, 2);
		block[3].creatBlock(3, 2);
	}
}

BlockGroup::~BlockGroup()
{
}

void BlockGroup::blockMove()
{
	// 暂时放在这
	moveCheck = checkBlockGroup(); // 获取判定的下标
	while (true)
	{
		char ch = _getch();

		if (ch == 'w')
		{
			continue; // 这里是旋转，但还未实现
		}
		else if (ch == 'a' && block[moveCheck.left].checkBlock(
			block[moveCheck.left].getBlockX() - 1,
			block[moveCheck.left].getBlockY()))
		{
			for (auto& val : block)
			{
				val.cleanBlock();     // 清除方块
				val.changeBlockX(-1); // 方块坐标移动
			}

		}
		else if (ch == 'd' && block[moveCheck.right].checkBlock(
			block[moveCheck.right].getBlockX() + 1,
			block[moveCheck.right].getBlockY()))
		{
			for (auto& val : block)
			{
				val.cleanBlock();
				val.changeBlockX(1);
			}

		}
		else if (ch == 's' && block[moveCheck.down].checkBlock(
			block[moveCheck.down].getBlockX(),
			block[moveCheck.down].getBlockY() + 1))
		{
			for (auto& val : block)
			{
				val.cleanBlock();
				val.changeBlockY(1);
			}
		}

		printBlockGroup(); // 打印方块组
	}
}

void BlockGroup::printBlockGroup() const
{
	for (auto val : block)
	{
		val.printBlock();
	}
}

MoveCheck BlockGroup::checkBlockGroup() const
{
	// 方块最左边的用于判定左移
	// 方块最右边的用于判定右移
	// 方块最下边的用于判定下移
	// 返回1个struct，里面包含三个下标

	short minX = 0; // 取最小值
	short maxX = 0; // 用于右移判定，取最大值
	short maxY = 0; // 用于下移判定
	for (short i = 1; i < 4; ++i)
	{
		// 左移
		if (block[minX].getBlockX() > block[i].getBlockX())
			minX = i;

		// 右移
		if (block[maxX].getBlockX() < block[i].getBlockX())
			maxX = i;

		// 下移
		if (block[maxY].getBlockY() < block[i].getBlockY())
			maxY = i;
	}

	return { minX, maxX, maxY };
}
