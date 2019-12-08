
#include <string>
#include <iostream>
#include <initializer_list>


void error_msg(const std::initializer_list<std::string> &il)
{
	for (auto beg = il.begin(); beg != il.end(); ++beg)
	{
		std::cout << *beg << " ";
	}
	std::cout << std::endl;
}


int main(int argc, char *argv[])
{
	std::string expected{"hello"};
	std::string actual{"world"};

	if (expected != actual)
		error_msg({"functionX", expected, actual});
	else
		error_msg({"functionX", "okay"});
	return 0;
}
