
#include <iostream>


int main(int argc, char *argv[])
{
	int odd[]  = {1, 3, 5, 7, 9};
	int even[] = {0, 2, 4, 6, 8};

	decltype(odd) * attrPtr(int i)
	{
		return (i % 2) ? &odd : &even;
	}

	return 0;
}
