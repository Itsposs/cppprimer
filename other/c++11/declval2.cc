

#include <iostream>
#include <type_traits>

class A {
	public:
		A() = delete;
		int operator()(int i) { return i; }
};

void test() {
	decltype(A()(0)) i = 4;
	std::cout << i << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
