
#include <string>
#include <memory>
#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>

struct A {
	public:
		virtual ~A() {}
};

struct B : public A {};
struct C : public A {};

void test() {
	std::unordered_map<std::type_index, std::string> type_names;

	type_names[std::type_index(typeid(int))] = "int";
	type_names[std::type_index(typeid(double))] = "double";
	type_names[std::type_index(typeid(A))] = "A";
	type_names[std::type_index(typeid(B))] = "B";
	type_names[std::type_index(typeid(C))] = "C";

	int i;
	double d;
	A a;

	std::unique_ptr<A> b(new B);
	std::unique_ptr<A> c(new C);

	std::cout << "i is " << type_names[std::type_index(typeid(i))] << std::endl;
	std::cout << "d is " << type_names[std::type_index(typeid(d))] << std::endl;
	std::cout << "a is " << type_names[std::type_index(typeid(a))] << std::endl;
	std::cout << "b is " << type_names[std::type_index(typeid(*b))] << std::endl;
	std::cout << "c is " << type_names[std::type_index(typeid(*c))] << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
