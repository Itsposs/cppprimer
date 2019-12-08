
#include <vector>
#include <iostream>
#include <algorithm>

void test() {
	std::vector<int> vec1 = {1, 3, 5, 7, 9, 4};
	auto isEven = [](int i) { return i % 2 == 0; };
	auto firstEven = std::find_if(vec1.begin(), vec1.end(), isEven);
	if (firstEven != vec1.end()) 
		std::cout << "the first even is " << *firstEven << std::endl;

	auto firstOdd = std::find_if_not(vec1.begin(), vec1.end(), isEven);
	if (firstEven != vec1.end())
		std::cout << "the first add is " << *firstOdd << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
