#include "strvec.h"
#include <iostream>


int main(int argc, char *argv[])
{	
	StrVec str1;
	StrVec str2({"hello","world"});
	str1 = str2;

	str1.push_back("nice");
	str1.push_back("to");

	std::cout << "size():" << std::endl;
	std::cout << "str1:" << str1.size() << std::endl;
	std::cout << "str2:" << str2.size() << std::endl;
	
	

	return 0;
}
