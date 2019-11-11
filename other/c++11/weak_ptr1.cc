
#include <memory>
#include <iostream>

struct A;
struct B;

struct A {
	public:
		~A() { std::cout << "A is deleted." << std::endl; }
		std::shared_ptr<B> bptr;
};

struct B {
	public:
		~B() { std::cout << "B is deleted." << std::endl; }
		std::weak_ptr<A> aptr;
};

void TestPtr() {
	{
		std::shared_ptr<A> ap(new A);
		std::shared_ptr<B> bp(new B);
		ap -> bptr = bp;
		bp -> aptr = ap;
	}
}

int main(int argc, char *argv[]) {
	TestPtr();
	return 0;
}
