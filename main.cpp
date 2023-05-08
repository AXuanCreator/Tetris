#include <iostream>
#include "windowset.h"
#include "consoleset.h"

int main(void)
{
    WindowSet ws;
    ws.setTerminalTittle();
    ws.setSize();
    ws.setFontBig();
    ws.hideCursor();
    ws.setMainTittle();


    system("pause>nul"); // "pause>nul"可以隐藏[请按任意键继续]
    return 0;
}

