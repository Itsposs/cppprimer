
#include <chrono>
#include <vector>
#include <iostream>

void test() {
	std::vector<int> ivec;
	std::fill_n(back_inserter(ivec), 10, 7);

	for (const auto &val : ivec) {
		std::cout << val << " ";
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
