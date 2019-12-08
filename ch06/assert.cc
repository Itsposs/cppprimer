
#include <iostream>

//#define NDEBUG


void print(const int ia[], size_t size) {
#ifndef NDEBUG
	// __func__
	std::cerr << __func__ << ": array size is " 
			  << size << std::endl; 
#endif
	std::cout << "hello world!" << std::endl;
}


int main(int argc, char *argv[]) {
	int array[] = { 1, 3, 5, 7, 9};
	print(array, 5);

	return 0;
}
