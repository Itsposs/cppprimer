
#include <iostream>

extern "C" {
	#include "add.h"
}


void test()
{
	add(2, 3);
}

int main(int argc, char *argv[])
{
	test();
	return 0;
}
