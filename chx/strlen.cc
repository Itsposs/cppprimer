


#include <cstddef>  // size_t

size_t strlen(const char *str)
{
	const char *s;
	//for(s = str; *s; ++s) { }
	s = str;
	while(*s)
		++s;
	return (s - str); // (s - str) type ?

}

#include <iostream>  // test


int main(int argc, char *argv[])
{
	size_t len = strlen("hello world!");
	std::cout << "len:" << len << std::endl;
	return 0;
}
