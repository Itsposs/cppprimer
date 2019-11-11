

#include <iostream>
#include <type_traits>

class A {};

class B : public A {};

class C {};

void test() {
	std::cout << std::boolalpha;
	std::cout << std::is_base_of<A, B>::value << std::endl;
	std::cout << std::is_base_of<B, A>::value << std::endl;
	std::cout << std::is_base_of<C, B>::value << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
