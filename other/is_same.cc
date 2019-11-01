
#include <cstdint>
#include <iostream>
#include <type_traits>

void print_separator() {
	std::cout << "----------------" << std::endl;
}


void test() {
	std::cout << std::boolalpha;

	std::cout << std::is_same<int, std::int32_t>::value << std::endl;
	std::cout << std::is_same<int, std::int64_t>::value << std::endl;

	print_separator();

	std::cout << std::is_same<float, std::int32_t>::value << std::endl;
	std::cout << std::is_same<int, int>::value << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
