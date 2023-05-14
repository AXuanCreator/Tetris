#include <iostream>
#include <thread>

#include "windowset.h"
#include "map.h"
#include "interactive.h"

void threadA();
void threadB();

int main(void)
{

	threadA();
	system("pause>nul"); // "pause>nul"可以隐藏[请按任意键继续]
	return 0;
}

void threadA()
{
	WindowSet ws;
	ws.setTerminalTittle();
	ws.setSize();
	ws.setFontBig();
	ws.hideCursor();
	ws.setMainTittle();
	ws.drawBoard();

	Map map;
	map.mapInit();
	map.refreshScore();
	Interactive ia;
	ia.nextCreat();
	ia.startBlock();

}
