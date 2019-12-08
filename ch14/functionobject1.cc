#include <functional>
#include <iostream>


int add(int i, int j) { return i + j; }

auto mod = [](int i, int j) { return i % j; };


struct divide
{
	int operator()(int denominator, int divisor)
	{
		return denominator / divisor;
	}
};


int main(int argc, char *argv[])
{
	std::function<int(int, int)> f1 = add;
	std::function<int(int, int)> f2 = divide();
	std::function<int(int, int)> f3 = [](int i, int j) { return i * j; };
	std::function<int(int, int)> f4 = mod;

	std::cout << f1(4, 2) << std::endl;
	std::cout << f2(4, 2) << std::endl;
	std::cout << f3(4, 2) << std::endl;
	std::cout << f4(4, 2) << std::endl;
	return 0;
}
