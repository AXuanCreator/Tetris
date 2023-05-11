#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H
// 一个方块的对象
#include "consoleset.h"
#include "iostream"

class Block {
private:
  ConsoleSet consoleSet; // 控制台信息实例
  Point point; // Point是一个struct类型，位于consoleset.h，用于存储坐标
public:
  Block();
  ~Block();

  void creatBlock(short _x, short _y); // 制造1个方块
  void printBlock();                   // 打印方块
  void cleanBlock();                   // 清除方块
  bool checkBlock(int x , int y);                   // 检查方块是否越界
  void changeBlockX(int m); // 改变坐标
  void changeBlockY(int m); // 改变坐标Y
  short getBlockX() const;  // return point.x
  short getBlockY() const;  // return point.y
};
#endif // TETRIS_BLOCK_H
