
#include <vector>
#include <iostream>
#include <algorithm>

void test() {
	std::vector<int> vec1 = {1, 3, 5, 7, 9};
	auto isEven = [](int i){ return i % 2 != 0; };
	bool isallOdd = std::all_of(vec1.begin(), vec1.end(), isEven);
	if (isallOdd)
		std::cout << "all is odd." << std::endl;
	bool isnoneEven = std::none_of(vec1.begin(), vec1.end(), isEven);
	if (isnoneEven)
		std::cout << "none is even." <<  std::endl;

	std::vector<int> vec2 = {1, 3, 5, 7, 8, 9};
	bool isanyEven = std::any_of(vec2.begin(), vec2.end(), isEven);
	if (isanyEven)
		std::cout << "at least one is even." << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
