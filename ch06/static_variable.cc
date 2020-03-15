
#include <iostream>

size_t count_calls()
{
	static size_t ctr = 0;
	return ++ctr;
}


void test()
{
	size_t times = 10;
	for(size_t i = 0; i != times; ++i)
	{
		std::cout << count_calls() << std::endl;
	}

}

int main(int argc, char *argv[])
{
	test();
	return 0;
}
