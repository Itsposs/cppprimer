

#include <utility>
#include <iostream>


struct Default { int foo() const { return 1; }};

struct NonDefault {
	NonDefault(const NonDefault&) { }
	int foo() const { return 1;}
};


void test() {
	decltype(Default().foo()) n1 = 1;
	decltype(std::declval<NonDefault>().foo()) n2 = n1;
	std::cout << "n1 = " << n1 << '\n' << "n2 = "<< n2 << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
