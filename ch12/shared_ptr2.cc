
#include <memory>
#include <iostream>

class A
{
	public:
		~A() { std::cout << "~A()" << std::endl; }
	private:
};

class B : public A
{
	public:
		~B() { std::cout << "~B()" << std::endl; }
	private:
};

void test() {
	A *a = new B();
	delete a;
	std::shared_ptr<A> spa = std::make_shared<B>();

}

int main(int argc, char *argv[]) {
	
	test();
	return 0;
}

