//
// Created by AXuan on 2023/5/10.
//

#include "blockgroup.h"

BlockGroup::BlockGroup()
= default;

BlockGroup::BlockGroup(int val)
{
	sign = val;             // 特征值
	if (val == 1)           // 条型 sign == 1 || 衍生->sign == 6
	{
		B0.creatBlock(1, 1);
		B1.creatBlock(1, 2);
		B2.creatBlock(1, 3);
		B3.creatBlock(1, 4);
	}
	else if (val == 2)      // 7型   sign == 2 || 衍生->sign == 7、8、9
	{
		B0.creatBlock(1, 1);
		B1.creatBlock(1, 2);
		B2.creatBlock(2, 1);
		B3.creatBlock(3, 1);
	}
	else if (val == 3)       // z型   sign == 4 || 衍生->sign == 10
	{
		B0.creatBlock(1, 1);
		B1.creatBlock(2, 1);
		B2.creatBlock(2, 2);
		B3.creatBlock(3, 2);
	}
	else if (val == 4)      // 山型   sign == 3 || 衍生->sign == 11、12、13
	{
		B0.creatBlock(1, 1);
		B1.creatBlock(2, 1);
		B2.creatBlock(2, 2);
		B3.creatBlock(3, 1);
	}

	else if (val == 5)       // 正方形  sign == 5  || 无衍生
	{
		B0.creatBlock(1, 1);
		B1.creatBlock(1, 2);
		B2.creatBlock(2, 1);
		B3.creatBlock(2, 2);
	}
}

BlockGroup::~BlockGroup()
= default;

void BlockGroup::blockMove(char ch) // 单次移动
{
	if (ch == 't')                // 若没有这语句，则用户不输入时会导致暂停，且可以限制你的输入时间
		getAction(ch);


	if (ch == 'w')
	{// 这里是旋转，但还未实现
		if (checkBlockBottom(false, 0, 1))
			return;
		changeBlockGroup();
	}
	else if (ch == 'a')
	{
		if (checkBlockBottom(false, -1, 0))
			return;
		for (auto& val : block)
		{
			val.cleanBlock();     // 清除方块
			val.changeBlockX(-1); // 方块坐标移动
		}

	}
	else if (ch == 'd')
	{
		if (checkBlockBottom(false, 1, 0))
			return;
		for (auto& val : block)
		{
			val.cleanBlock();
			val.changeBlockX(1);
		}

	}
	else if (ch == 's')
	{
		if (checkBlockBottom(false, 0, 1))
			return;
		for (auto& val : block)
		{
			val.cleanBlock();
			val.changeBlockY(1);
		}
	}

	if (ch != 't')
		printBlockGroup();      // 打印方块组

}

void BlockGroup::printBlockGroup() const
{
	for (auto val : block)
	{
		val.printBlock();
	}
}

void BlockGroup::printBlockGroup(short x, short y) const
{
	for (auto val : block)
	{
		val.printBlock(x, y);
	}
}

void BlockGroup::getAction(char& ch)
{
	clock_t start, end;
	start = clock();

	while (true)
	{
		if (_kbhit())
		{
			ch = static_cast<char>(_getch());
			break;
		}
		end = clock();
		if (end - start > 550)  //当时间超过这一范围
		{
			break;
		}
	}

}
bool BlockGroup::checkBlockBottom(bool sw, short _x, short _y)
{
	for (auto& bl : block)
	{
		if (!map.checkMap(static_cast<short>(bl.getBlockX() + _x), static_cast<short>(bl.getBlockY() + _y))) // 当有任意1个方块的Y+1坐标触碰到0，则表示抵达底部
		{
			//std::cout << "change";
			if (sw)
				for (auto& b : block)
				{
					map.rowAdd(b.getBlockY());
					map.mapChange(b.getBlockX(), b.getBlockY(), false);   // true变为可移动区域 false变为墙
				}
			//map.printMap();
			//system("pause");
			return true;
		}

	}
	return false;
}

void BlockGroup::changeBlockGroup()
{
	// l
	if (sign == 1)
	{
		blockSign(0, 0, 1, -1, 2, -2, 3, -3, 6);
	}
	else if (sign == 6)
	{
		blockSign(0, 0, -1, 1, -2, 2, -3, 3, 1);
	}
		// 7
	else if (sign == 2)
	{
		blockSign(0, 2, 1, 1, -1, 1, -2, 0, 7);
	}
	else if (sign == 7)
	{
		blockSign(2, 0, 1, -1, 1, 1, 0, 2, 8);
	}
	else if (sign == 8)
	{
		blockSign(0, -2, -1, -1, 1, -1, 2, 0, 9);
	}
	else if (sign == 9)
	{
		blockSign(-2, 0, -1, 1, -1, -1, 0, -2, 2);
	}
		// z
	else if (sign == 3)
	{
		blockSign(1, 2, 0, 1, 1, 0, 0, -1, 10);
	}
	else if (sign == 10)
	{
		blockSign(-1, -2, 0, -1, -1, 0, 0, 1, 3);
	}
		// 山
	else if (sign == 4)
	{
		blockSign(0, 2, -1, 1, 0, 0, -2, 0, 11);
	}
	else if (sign == 11)
	{
		blockSign(2, 0, 1, 1, 0, 0, 0, 2, 12);
	}
	else if (sign == 12)
	{
		blockSign(0, -2, 1, -1, 0, 0, 2, 0, 13);
	}
	else if (sign == 13)
	{
		blockSign(-2, 0, -1, -1, 0, 0, 0, -2, 4);
	}
}

void BlockGroup::blockSign(short x0, short y0, short x1, short y1, short x2, short y2, short x3, short y3, int _sign)
{
	if (B0.checkBlock(BX0 + x0, BY0 + y0) && B1.checkBlock(BX1 + x1, BY1 + y1) && B2.checkBlock(BX2 + x2, BY2 + y2)
		&& B3.checkBlock(BX3 + x3, BY3 + y3))
	{
		sign = _sign;
		blockClean();
		B0.changeBlockXY(BX0 + x0, BY0 + y0);
		B1.changeBlockXY(BX1 + x1, BY1 + y1);
		B2.changeBlockXY(BX2 + x2, BY2 + y2);
		B3.changeBlockXY(BX3 + x3, BY3 + y3);
	}
}
void BlockGroup::checkRowFull()
{
	for (auto& bl : block)
	{
		map.rowDele(bl.getBlockY()); // 检测行是否已满
	}
}

void BlockGroup::blockClean()
{
	for (auto& bl : block)
		bl.cleanBlock();
}
void BlockGroup::blockClean(short x, short y)
{
	for (auto& bl : block)
		bl.cleanBlock(x, y);
}

