#include <iostream>
#include <cstring>


template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
	return strcmp(p1, p2);
}


int main(int argc, char *argv[])
{
	std::cout << compare("hi", "mom") << std::endl;
	return 0;
}
