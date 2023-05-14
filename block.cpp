#include "block.h"

Block::Block()
= default;

Block::~Block()
= default;

void Block::creatBlock(short _x, short _y)
{
	this->point.x = _x; // 方块的坐标X
	this->point.y = _y; // 方块的坐标y
}

void Block::printBlock()
{

	consoleSet.setCursor(point.x, point.y); // 设置光标坐标
	std::cout << "*";                       // 输出
}

void Block::printBlock(short x, short y)
{
	consoleSet.setCursor(static_cast<short>(point.x + x), static_cast<short>(point.y + y));
	std::cout << "*";
}

void Block::changeBlockX(short m)
{
	if (map.checkMap(static_cast<short>(point.x + m), point.y))
		point.x = static_cast<short>(point.x + m);
}

void Block::changeBlockY(short m)
{
	if (map.checkMap(point.x, static_cast<short>(point.y + m)))
		point.y = static_cast<short>(point.y + m);
}

void Block::changeBlockXY(short _x, short _y)
{
	point.x = _x;
	point.y = _y;
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

void Block::cleanBlock(short x, short y)
{
	consoleSet.setCursor(static_cast<short>(point.x + x), static_cast<short>(point.y + y));
	std::cout << " ";
}

bool Block::checkBlock(short _x, short _y)
{
	if (map.checkMap(_x, _y))
		return true;

	return false;
}


