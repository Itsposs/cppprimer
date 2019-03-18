#include <iostream>
#include <string>

int main(int argc,char *argv[])
{
	std::string str("some string");
	for(auto c : str)
	{
		std::cout << c << std::endl;
	}
	// TODO
	return 0;
}
