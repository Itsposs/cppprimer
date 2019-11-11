
#include <vector>
#include <iostream>
#include <algorithm>

void test() {
	std::vector<int> vec = {1, 2, 5, 7, 9, 4};
	auto pos = std::is_sorted_until(vec.begin(), vec.end());

	for (auto it = vec.begin(); it != pos; ++it) std::cout << *it << " ";
	std::cout << std::endl;

	bool ret = std::is_sorted(vec.begin(), vec.end());
	std::cout << std::boolalpha << ret << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
