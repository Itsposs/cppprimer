#include <iostream>



int main(int argc, char *argv[])
{
	//const int ci = 1024;
	//const int &r1 = ci;
	
	int i = 42;
	int &r1 = i;
	const int &r2 = i;
	r1 = 0;
	//r2 = 0;

	return 0;
}
