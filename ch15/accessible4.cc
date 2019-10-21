

#include <iostream>

class Base {
	public:
		Base(size_t v = 0) : n(v) { }
		std::size_t size() const { return n; }
	protected:
		std::size_t n;
};


class Derived : private Base {
	public:
		using Base::size;
	protected:
		using Base::n;
};

class Dderived : public Derived {
	public:
		void print() { std::cout << n << std::endl;}
};

void test() {
	Base b1(2);
	Derived d1;
	std::cout << "n:" << d1.size() << std::endl;
	Dderived d2;
	d2.print();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
