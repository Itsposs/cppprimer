
#include <iostream> 

class Apple
{
	public:
		Apple() { std::cout << "constructor" << std::endl; }
		~Apple() { std::cout << "desconstructor" << std::endl; }
	private:
		static int i;
};

int Apple::i = 3;

enum class Scope
{
	NORMAL,
	SPECIFIC
};

void test()
{
	Scope normal   = Scope::NORMAL;
	Scope specific = Scope::SPECIFIC;

	if (normal == Scope::NORMAL)
	{
		Apple obj1;
	}

	if (specific == Scope::SPECIFIC)
	{
		static Apple obj2;
	}

	std::cout << ".............." << std::endl;
}

int main(int argc, char *argv[])
{
	test();
	return 0;
}




