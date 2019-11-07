
#include <memory>
#include <iostream>

std::weak_ptr<int> gw;
void func() {
	if (gw.expired())
		std::cout << "gw is expired." << std::endl;
	else {
		auto spt = gw.lock();
		std::cout << *spt << std::endl;
	}
}


void test() {
	std::shared_ptr<int> sp(new int(10));
	std::weak_ptr<int> wp(sp);
	std::cout << wp.use_count() << std::endl;

	if (wp.expired()) 
		std::cout << "no effective." << std::endl;
	else
		std::cout << "effective." << std::endl;

	// func
	{
		auto sp = std::make_shared<int>(42);
		gw = sp;
		func();
	}
	func();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}


