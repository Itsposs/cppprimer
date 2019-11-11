

#include <iostream>
#include <functional>


class A {
	public:
		A(const std::function<void()> &f)
			: callback_(f) {}

		void notify() { callback_(); }
	private:
		std::function<void()> callback_;
};

class Foo {
	public:
		void operator()(void) {
			std::cout << __FUNCTION__ << std::endl;
		}
};


void test() {
	Foo foo;
	A aa(foo);
	aa.notify();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
