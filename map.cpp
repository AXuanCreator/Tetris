#include "map.h"

Map::Map()
{

}

Map::~Map()
{

}

void Map::mapInit()
{
	for (int i = 0; i < 26; ++i)   // Y坐标
	{
		for (int j = 0; j < 39; ++j)   // X坐标
		{
			if (i == 0 || i == 25)
				myMap[i][j] = 0;    // 墙体
			else
				myMap[i][j] = 1;    // 可移动范围
		}
	}

	for (auto& i : myMap)
	{
		i[0] = 0;
		i[38] = 0;
	}

	// 临时放这
	for(auto& i : rowFull)
		i = 0;
	/*for(auto& row : myMap)
	{
		for(auto& col : row)
		{
			std::cout<<col;
		}
		std::cout<<std::endl;
	}*/
}
bool Map::checkMap(short x, short y) const
{
	if (myMap[y][x])  // 空区域
		return true;

	return false;
}
void Map::mapChange(short x, short y,bool bl)
{
	if(bl)
	{
		myMap[y][x] = 1; // 可移动区域
	}
    else
	{
		myMap[y][x] = 0; // 变为墙
	}

}
void Map::printMap() const
{
	for(auto&row : myMap)
	{
		for(auto&col:row)
		{
			std::cout<<col;
		}
		std::cout<<std::endl;
	}

}
void Map::rowAdd(short r)
{
	++rowFull[r];

	// 不可在这里直接检测行是否已满，这样的话会导致部分方块没有被遍历
	//consoleSet.setCursor(45,3);
	//std::cout<<r<<"  "<<rowFull[24];
}
void Map::rowDele(short r)
{
	if(rowFull[r]==37)
	{
		rowFull[r] = 0; // 清空
		for(int i=r;i>1;--i)
		{
			for(int j=1;j<38;++j)
			{
				myMap[i][j]=myMap[i-1][j]; // 不断继承上一层的答案
			}
			rowFull[i] = rowFull[i-1];     // 不断继承上一层
		}

		refreshMap(r);
	}


}
void Map::refreshMap(short r)
{
	for(int i=1;i<=r;++i)
	{
		for(int j=1;j<38;++j)
		{
			if(myMap[i][j]==0)
			{
				consoleSet.setCursor(j,i); //x-y 和 i-j 是相反的
				std::cout << '*';
			}
			else
			{
				consoleSet.setCursor(j,i); //x-y 和 i-j 是相反的
				std::cout << ' ';
			}
		}
	}
}
