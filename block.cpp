#include "block.h"

Block::Block()
{
}

Block::~Block()
{
}

void Block::creatBlock(short _x, short _y)
{
	this->point.x = _x; // 方块的坐标X
	this->point.y = _y; // 方块的坐标y
}

void Block::printBlock()
{

	consoleSet.setCursor(point.x, point.y); // 设置光标坐标
	std::cout << "0";                       // 输出
}

void Block::changeBlockX(int m)
{
	if (checkBlock(point.x + m, point.y))
		point.x += m; // 测试：-1
}

void Block::changeBlockY(int m)
{
	if (checkBlock(point.x, point.y + m))
		point.y += m;
}

short Block::getBlockX() const
{
	return point.x;
}

short Block::getBlockY() const
{
	return point.y;
}

void Block::cleanBlock()
{
	consoleSet.setCursor(point.x, point.y);
	std::cout << " ";
}

bool Block::checkBlock(int x, int y)
{
	// 框的移动范围是 : X->[1~37] Y->[1~24]。但会发生改变，因此不能直接使用数字，可以使用两个坐标
	Point tempP = consoleSet.getRange();
	if (x < 1 || x > tempP.x || y < 1 || y > tempP.y)

		return false;
	return true;
}
