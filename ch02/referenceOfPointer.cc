

#include <iostream>


int main(int argc, char *argv[])
{
	int i = 42;
	int *p;
	int *&r = p;
	p = &i;
	*p = 36;

	return 0;
}
