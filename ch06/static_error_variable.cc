
#include <iostream>

class Apple
{
	public:
		Apple() {}
		static int i;
	private:
};


void test()
{
	Apple obj1;
	Apple obj2;

	obj1.i = 1;
	obj2.i = 2;

	std::cout << "obj1:" << obj1.i << " "
			  << "obj2:" << obj2.i << std::endl;
}

int main(int argc, char *argv[])
{
	test();
	return 0;
}
