#include <iostream>

/*
 * description: unitbuf operator 
 */

int main(int argc,char *argv[])
{
	std::cout << std::unitbuf << "hello world!"
			  << std::nounitbuf;
	// equal to
	std::cout << std::flush << "hello world!"
			  << std::flush;
	//TODO
	return 0;
}
