#include <iostream>


int main(int argc,char *argv[])
{
	int ival;
	std::cin >> ival;
	std::cin.clear();

	if(std::cin.good())
	{
		std::cout << "ok" << std::endl;
	}
	else
	{
		std::cout << "error" << std::endl;
	}
	//TODO
	return 0;
}
