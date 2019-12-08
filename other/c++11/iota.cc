
#include <array>
#include <vector>
#include <numeric>
#include <iostream>

void test() {
	std::vector<int> vec(4);
	for (int i = 1; i != 4; ++i) 
		vec.emplace_back(i);

	std::iota(vec.begin(), vec.end(), 1);
	for (const int val : vec) std::cout << val << " ";
	std::cout << std::endl;

	std::array<int, 4> array;
	std::iota(array.begin(), array.end(), 1);
	for (const int val : array) std::cout << val << " ";
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
