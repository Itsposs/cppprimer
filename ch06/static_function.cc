

#include <iostream>

class Apple
{
	public:
		static void printMsg()
		{
			std::cout << "welcome to Apple!" << std::endl;
		}
	private:
};

void test()
{
	Apple::printMsg();
}


int main(int argc, char *argv[])
{
	test();
	return 0;
}
