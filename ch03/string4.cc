
#include <string>
#include <iostream>


int main(int argc, char *argv[])
{
	std::string s("hello world!");

	for(auto c : s)
	{
		std::cout << c  << " ";
	}
	std::cout << std::endl;

	return 0;
}
