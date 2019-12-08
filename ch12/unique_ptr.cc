

#include <memory>
#include <iostream>

void test() {
	std::unique_ptr<int> v1(new int(6));
	std::cout << "v1:" << *v1 << std::endl;
	auto ptr = std::move(v1);
	std::cout << "ptr:" << *ptr << std::endl;
	//std::cout << "v1:" << v1 << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
