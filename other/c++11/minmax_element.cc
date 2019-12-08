
#include <vector>
#include <iostream>
#include <algorithm>

void test() {
	std::vector<int> vec = {1, 2, 5, 7, 9, 4};
	auto ret = std::minmax_element(vec.begin(), vec.end());

	std::cout << *ret.first << " " << *ret.second << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
