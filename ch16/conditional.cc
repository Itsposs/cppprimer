


#include <typeinfo>
#include <iostream>
#include <type_traits>


void test() {
	typedef std::conditional<true, int, double>::type Type1;
	typedef std::conditional<false, int, double>::type Type2;
	typedef std::conditional<sizeof(int) >= sizeof(double), int, double>::type Type3;

	std::cout << typeid(Type1).name() << std::endl;
	std::cout << typeid(Type2).name() << std::endl;
	std::cout << typeid(Type3).name() << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
