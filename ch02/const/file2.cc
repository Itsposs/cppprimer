
#include <iostream>

extern int ext;

void test()
{
	std::cout << (ext + 10) << std::endl;
}

int main(int argc, char *argv[])
{
	test();
	return 0;
}
