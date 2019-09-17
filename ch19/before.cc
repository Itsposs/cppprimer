
#include <iostream>
#include <typeinfo>


int main(int argc, char *argv[])
{
	if(typeid(int).before(typeid(char)))
		std::cout << "int goes before char in this implementation." << std::endl;
	else
		std::cout << "char goes before int in this implementation." << std::endl;

	return 0;
}
