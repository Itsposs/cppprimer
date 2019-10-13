
#include <memory>
#include <iostream>

void test() {
	std::unique_ptr<int> up1(new int(6));
	std::unique_ptr<int> up2;
	up2.reset(up1.release());
	//std::cout << *up1 << std::endl;
	std::cout << *up2 << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
