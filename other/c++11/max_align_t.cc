
#include <cstddef>
#include <iostream>

void test() {
	//std::cout << alignof(std::max_align_t) << std::endl;
	std::cout << alignof(max_align_t) << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
