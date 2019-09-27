#include <iostream>


int main(int argcc, char *argv[])
{
	int errNumb = 0;
	int * const curErr = &errNumb;
	const double pi = 3.14159;
	const double * const pip = &pi;
	std::cout << "&errNumb: " << &errNumb << std::endl;
	std::cout << "curErr: "   << curErr   << std::endl;
	std::cout << "*curErr: "  << *curErr  << std::endl;

	return 0;
}
