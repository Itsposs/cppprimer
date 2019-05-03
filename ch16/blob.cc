#include "blob.h"
#include <iostream>


int main(int argc, char *argv[])
{
	Blob<std::string> articles = {"a", "an", "the"};
	std::cout << articles.size() << std::endl;
	articles.push_back("nice");
	std::cout << articles.back() << std::endl;

	return 0;
}
