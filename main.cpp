#include <iostream>
#include "windowset.h"
#include "element.h"

int main(void)
{
	WindowSet ws;
	ws.setTerminalTittle();
	ws.setSize();
	ws.setFontBig();
	ws.hideCursor();
	ws.setMainTittle();
	ws.drawBoard();      // 倒计时部分存在问题
	Element el;
	el.creatBlockGroup();


	system("pause>nul"); // "pause>nul"可以隐藏[请按任意键继续]
	return 0;
}

