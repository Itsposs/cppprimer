#include <iostream>



int main(int argc, char *argv[])
{
	const int ci = 0, &cj = ci;
	decltype(ci) x = 0;
	decltype(cj) y = x;
	decltype(cj) z = ci;

	int i = 42, *p = &i, &r = i;
	decltype(r + 0) b;
	decltype(*p) c = i;

	decltype((i)) d = i;
	decltype(i) e;
	
	return 0;
}
