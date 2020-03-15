
#include "singleton.h"

struct A {
	public:
		A() {}
};

struct B {
	public:
		B(int x) {}
};

struct C {
	public:
		C(int x, double y) {}
};

void test() {
	Singleton<A>::Instance();
	Singleton<B>::Instance(1);
	Singleton<C>::Instance(1, 3.14);

	Singleton<A>::DestroyInstance();
	Singleton<B>::DestroyInstance();
	Singleton<C>::DestroyInstance();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
