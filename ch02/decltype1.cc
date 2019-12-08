
#include <iostream>

int main(int argc, char *argv[])
{
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype((b)) d = a;
	++c;
	++d;

	std::cout << " a:" << a
			  << " b:" << b
			  << " c:" << c
			  << " d:" << d << std::endl;
}
