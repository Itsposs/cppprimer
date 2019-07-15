#include <iostream>


class Base
{
	public:
		Base(size_t v = 0) : n(v) { }
		std::size_t size() const { return n; }
	protected:
		std::size_t n;
};


class Derived : private Base
{
	public:
		using Base::size;
	protected:
		using Base::n;
};


int main(int argc, char *argv[])
{
	Base b1(2);
	Derived d1;
	std::cout << "n:" << d1.size() << std::endl;
	return 0;
}
