

#include <iostream>
#include <type_traits>

struct A {
	public:
		A(int a, int b)
			: avg((a + b) / 2) {}
		int avg;
};

typedef std::aligned_storage<sizeof(A), alignof(A)>::type Aligned_A;


void test() {
	Aligned_A a, b;
	new (&a) A (10, 20);
	b = a;
	std::cout << reinterpret_cast<A&>(b).avg << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
