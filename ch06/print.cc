
#include <cassert>
#include <iostream>

void print(const char *p) {
	if (p) {
		while (*p) {
			std::cout << *p++ << " ";
		}
		std::cout << std::endl;
	}
}

void print(const int *beg, const int *end) {
	//assert(!beg && !end);
	while (beg != end) {
		std::cout << *beg++ << " ";
	}
	std::cout << std::endl;
}

void print(const int ia[], size_t size) {
	for(size_t i = 0; i < size; ++i) {
		std::cout << ia[i] << " ";
	}
	std::cout << std::endl;
}

void print(int (&array)[10]) {
	for (const auto val : array) {
		std::cout << val << " ";
	}
	std::cout <<  std::endl;
}

// test
#include <array>
#include <string>
#include <iterator>

void test_print() {
	std::cout << " print v1 " << std::endl;
	char s[] = {"hello world"};
	print(s);

	std::cout << " print v2 " << std::endl;
	std::array<int, 6> array1{1, 3, 5, 7, 9, 0};
	print(std::begin(array1), std::end(array1));

	std::cout << " print v3 " << std::endl;
	int array2[] = {2, 4, 6, 8, 0};
	print(array2, 5);

	std::cout << " print v4 " << std::endl;
	int array3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	print(array3);
}

#include <chrono>

int main(int argc, char *argv[]) {
	using namespace std::chrono;
	auto beg = system_clock::now();
	
	test_print();

	auto end = system_clock::now();
	std::cout << "time: " << duration_cast<milliseconds> (end - beg).count()
	          << " ms."   << std::endl;
	return 0;
}
