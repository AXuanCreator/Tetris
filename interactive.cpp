#include "interactive.h"


Interactive::Interactive() {

}

Interactive::~Interactive() {

}

void Interactive::cleanScreen() {
    _getch();
    system("cls");  // 清屏
}