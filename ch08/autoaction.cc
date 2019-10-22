

#include <fstream>
#include <iostream>

/*
 * description: auto construction and destruction
 */

void process(std::ifstream &in) {
	std::cout << "process" << std::endl;
}

int main(int argc,char *argv[]) {
	for (auto p = argv + 1; p != argv + argc; ++p) {
		std::ifstream input(*p);
		if (input) {
			process(input);
		} else {
			std::cerr << "couldn't open: " + std::string(*p);
		}
	}  // The function of close is automatically invoked,
	   // when a object of fstream is destroied.
	//TODO
	return 0;
}
