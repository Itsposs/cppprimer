

#include <iostream>
#include <type_traits>

class A {};
class B : public A {};
class C {};

void test() {
	bool b2a = std::is_convertible<B*, A*>::value;
	bool a2b = std::is_convertible<A*, B*>::value;
	bool b2c = std::is_convertible<B*, C*>::value;

	std::cout << std::boolalpha;
	std::cout << b2a << std::endl;
	std::cout << a2b << std::endl;
	std::cout << b2c << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
