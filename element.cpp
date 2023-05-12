#include "element.h"

Element::Element()
{

}

Element::~Element()
= default;

void Element::countDown()
{
	int seconds = 1000;

	for (int i = seconds; i >= 0; --i)
	{
		consoleSet.setCursor(44, 3);
		std::cout << std::setw(4) << std::setfill(' ') << i;
		Sleep(1000);    // 有问题：此函数一旦运行，不能多线程运作，只能等倒计时结束
	}
}

