
#include <vector>
#include <string>
#include <iostream>


int main(int argc, char *argv[])
{
	std::vector<std::string> v1{"a", "an", "the"};
	std::vector<std::string> v2(10, "hi!");

	for(auto s : v1)
	{
		std::cout << s << " ";
	}
	std::cout << std::endl;

	return 0;
}
