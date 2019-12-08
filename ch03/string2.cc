

#include <string>
#include <iostream>


int main(int argc, char *argv[])
{
	std::string line;

	// input a line each time, until reach file-end
	while(getline(std::cin, line))
	{
		std::cout << line << std::endl;
	}
	return 0;
}

