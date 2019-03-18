#include <iostream>
#include <string>

int main(int argc,char *argv[])
{
	std::string line;

	while(getline(std::cin,line))
	{
		std::cout << "line:" << line << std::endl;
	}
	//TODO
	return 0;
}
