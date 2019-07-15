#include <iostream>


int main(int argc, char *argv[])
{
	int i = 6;
	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;

	const auto f = ci;
	return 0;
}
