//
// Created by AXuan on 2023/5/10.
//

#include "blockgroup.h"

BlockGroup::BlockGroup()
{
}

BlockGroup::BlockGroup(int val)
{
	sign = val;
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
{
}

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
		printBlockGroup(); // 打印方块组

}

void BlockGroup::blockRotate(char ch)   // 方块旋转
{

}

void BlockGroup::printBlockGroup() const
{
	for (auto val : block)
	{
		val.printBlock();
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
			ch = _getch();
			break;
		}
		end = clock();
		if (end - start > 750)  //当时间超过这一范围
		{
			break;
		}
	}

}
bool BlockGroup::checkBlockBottom(bool sw, short _x, short _y)
{
	for (auto& bl : block)
	{
		if (!map.checkMap(bl.getBlockX() + _x, bl.getBlockY() + _y)) // 当有任意1个方块的Y+1坐标触碰到0，则表示抵达底部
		{
			//std::cout << "change";
			if (sw)
				for (auto& bl : block)
				{
					map.rowAdd(bl.getBlockY());
					map.mapChange(bl.getBlockX(), bl.getBlockY(), false);   // true变为可移动区域 false变为墙
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
		sign = 6;   // 改变特征值
		blockSign(0, 0, 1, -1, 2, -2, 3, -3);
	}
	else if (sign == 6)
	{
		sign = 1;
		blockSign(0, 0, -1, 1, -2, 2, -3, 3);
	}
		// 7
	else if (sign == 2)
	{
		sign = 7;
		blockSign(0, 2, 1, 1, -1, 1, -2, 0);
	}
	else if (sign == 7)
	{
		sign = 8;
		blockSign(2, 0, 1, -1, 1, 1, 0, 2);
	}
	else if (sign == 8)
	{
		sign = 9;
		blockSign(0, -2, -1, -1, 1, -1, 2, 0);
	}
	else if (sign == 9)
	{
		sign = 2;
		blockSign(-2, 0, -1, 1, -1, -1, 0, -2);
	}
		// z
	else if (sign == 3)
	{
		sign = 10;
		blockSign(1, 2, 0, 1, 1, 0, 0, -1);
	}
	else if (sign == 10)
	{
		sign = 3;
		blockSign(-1, -2, 0, -1, -1, 0, 0, 1);
	}
		// 山
	else if (sign == 4)
	{
		sign = 11;
		blockSign(0, 2, -1, 1, 0, 0, -2, 0);
	}
	else if (sign == 11)
	{
		sign = 12;
		blockSign(2, 0, 1, 1, 0, 0, 0, 2);
	}
	else if (sign == 12)
	{
		sign = 13;
		blockSign(0,-2,1,-1,0,0,2,0);
	}
	else if (sign ==13)
	{
		sign = 4;
		blockSign(-2,0,-1,-1,0,0,0,-2);
	}
}

void BlockGroup::blockSign(short x0, short y0, short x1, short y1, short x2, short y2, short x3, short y3)
{
	if (B0.checkBlock(BX0 + x0, BY0 + y0) && B1.checkBlock(BX1 + x1, BY1 + y1) && B2.checkBlock(BX2 + x2, BY2 + y2)
		&& B3.checkBlock(BX3 + x3, BY3 + y3))
	{
		B0.cleanBlock();
		B1.cleanBlock();
		B2.cleanBlock();
		B3.cleanBlock();
		B0.changeBlockXY(BX0 + x0, BY0 + y0);
		B1.changeBlockXY(BX1 + x1, BY1 + y1);
		B2.changeBlockXY(BX2 + x2, BY2 + y2);
		B3.changeBlockXY(BX3 + x3, BY3 + y3);
	}
}
void BlockGroup::checkRowFull()
{
	for(auto& bl : block)
	{
		map.rowDele(bl.getBlockY()); // 检测行是否已满
	}

}

