

#include <iostream>

int i = 42;   // global scope

int main(int argc, char *argv[])
{
	int i = 100;
	int j = i;

	std::cout << "j:" << j << std::endl;

	return 0;
}
