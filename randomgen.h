#pragma once

#ifndef TETRIS_RANDOMGEN_H
#define TETRIS_RANDOMGEN_H

#include <random>

//用于生成随机数
class RandomGen
{
private:
	std::random_device rd;  // 随机数种子
	std::mt19937 gen;       // 随机数引擎
public:
	// 使用随机设备生成高熵种子
	RandomGen();
	~RandomGen();

	int blockCreatRandom(); // 生成不同形状的方块
};
#endif //TETRIS_RANDOMGEN_H
