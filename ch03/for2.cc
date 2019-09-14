
#include <cctype>
#include <string>
#include <iostream>


int main(int argc,char *argv[])
{
	std::string s("Hello World!!!");

	for(auto &c : s)
	{
		c = toupper(c);
	}
	std::cout << s << std::endl;
	// TODO
	return 0;
}
