
#include "Screen.h"
#include <iostream>

void test() {

	Screen item1(3, 4, 'c');
	std::cout << item1.get() << std::endl;
	std::cout << item1.get(0, 0) << std::endl;

	Screen item2;
	item2.set(0, 0, 'v');
	item2.set('x');
}


int main(int argc, char *argv[])
{
	test();

	return 0;
}
