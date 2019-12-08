
#include <string>
#include <iostream>
#include "singleton.h"

struct A {
	public:
		A(const std::string &rhs) { std::cout << "lvalue." << std::endl; }
		A(std::string &&rhs) { std::cout << "rvalue." << std::endl; }
	private:
};

struct B {
	public:
		B(const std::string &rhs) { std::cout << "lvalue." << std::endl; }
		B(std::string &&rhs) { std::cout << "rvalue." << std::endl; }
	private:
};

struct C {
	public:
		C(int x, double y) {}
		void func() const { std::cout << "test." << std::endl; }
	private:
};

void test() {
	std::string s{"bb"};
	Singleton<A>::Instance(s);
	Singleton<B>::Instance(std::move(s));
	Singleton<C>::Instance(1, 3.14);
	Singleton<C>::GetInstance() -> func();

	Singleton<A>::DestroyInstance();
	Singleton<B>::DestroyInstance();
	Singleton<C>::DestroyInstance();
	Singleton<A>::GetInstance();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
