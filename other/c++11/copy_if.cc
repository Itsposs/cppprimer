
#include <vector>
#include <iostream>
#include <algorithm>

void test() {
	std::vector<int> vec1 = {1, 3, 5, 7, 9, 4};
	std::vector<int> vec2(vec1.size());

	auto ret = std::copy_if(vec1.begin(), vec1.end(), 
			vec2.begin(), [](int i){ return i % 2 != 0; });
	vec2.resize(std::distance(vec1.begin(), ret));

	for (const int val : vec2) std::cout << val << " ";
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
