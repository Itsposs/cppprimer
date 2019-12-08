
#include <memory>
#include <iostream>

class A : public std::enable_shared_from_this<A> {
	public:
		std::shared_ptr<A> GetSelf() {
			return shared_from_this();
		}
		~A() { std::cout << "A is deleted." << std::endl; }
};

void test() {
	std::shared_ptr<A> spy(new A);
	std::shared_ptr<A> p = spy -> GetSelf();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
