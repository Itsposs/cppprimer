
#include <typeinfo>
#include <iostream>

class A {
	public:
		virtual void print() { std::cout << "hello world!" << std::endl; }
	private:
};

class B : public A {};

class C : public B {};



void test() {

	// pointer
	A *bp;
	if (B *dp = dynamic_cast<B*>(bp)) {
		dp -> print();
	} else {
		std::cout << "error" << std::endl;
	}
	
	// reference
	try {
		B &b = A
		C &c = dynamic_cast<C&>(b);
		c -> print();
	} catch (const std::bad_cast &e) {
		std::cout << e.what() <<  std::endl;
	}
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
