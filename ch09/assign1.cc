#include <iostream>
#include <string>
#include <list>
#include <vector>

int main(int argc,char *argv[])
{
	std::list<std::string> names;
	std::vector<const char*> oldstyle = {"hello","world"};
	names.assign(oldstyle.cbegin(),oldstyle.cend());

	for(const auto &val : names)
	{
		std::cout << val << std::endl;
	}
	//TODO
	return 0;
}
