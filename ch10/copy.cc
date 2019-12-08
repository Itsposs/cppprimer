

#include <chrono>
#include <iterator>
#include <iostream>

void test() {
	int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int a2[sizeof(a1)/sizeof(*a1)] = {0};
	auto ret = std::copy(std::begin(a1), std::end(a1), a2);
	
	for (size_t i = 0; i < 10; ++i) {
		std::cout << a2[i] << " ";
	}
	std::cout << std::endl;
}


int main(int argc, char *argv[]) {
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	test();
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
