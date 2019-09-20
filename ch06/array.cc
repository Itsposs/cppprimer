
#include <cassert>
#include <iostream>

void print(const char *p)
{
	if(p)
	{
		while(*p)
		{
			std::cout << *p++ << " ";
		}
		std::cout << std::endl;
	}
}


void print(const int *beg, const int *end)
{
	assert(!beg && !end);
	while(beg != end)
	{
		std::cout << *beg++ << " ";
	}
	std::cout << std::endl;
}


void print(const int ia[], size_t size)
{
	for(size_t i = 0; i < size; ++i)
	{
		std::cout << ia[i] << " ";
	}
	std::cout << std::endl;
}


void print(int (&array)[10])
{
	for(const auto val : array)
	{
		std::cout << val << " ";
	}
	std::cout <<  std::endl;
}

int main(int argc, char *argv[])
{

	return 0;
}
