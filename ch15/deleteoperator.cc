
#include <iostream>

class B {
	public:
		B() { }
		B(const B&) = delete;
		// other members, without move constructor
	private:
};

class D :  public B {
	public:
	private:
		// without any constructor
};


void test() {
	D d;
	D d2(d); // error
	D d3(std::move(d)); // error
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
