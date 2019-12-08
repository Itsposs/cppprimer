#include <iostream>

/*
 * description: flush output buffer
 */

int main(int argc,char *argv[])
{
	std::cout << "hi!" << std::endl;
	std::cout << "hi!" << std::flush;
	std::cout << "hi!" << std::ends;

	//TODO
	return 0;
}
