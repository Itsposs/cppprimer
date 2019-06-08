#include <functional>
#include <iostream>
#include <string>
#include <map>


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
	std::map<std::string, std::function<int(int, int)>> binops = {
		{"+", add},
		{"-", std::minus<int>()},
		{"/", divide()},
		{"*", [](int i, int j) { return i * j; }},
		{"%", mod}
	};

	binops["+"](10, 5);
	binops["-"](10, 5);
	binops["/"](10, 5);
	binops["*"](10, 5);
	binops["%"](10, 5);

	return 0;
}
