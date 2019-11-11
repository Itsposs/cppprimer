
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using std::placeholders::_1;

void test() {
	std::vector<int> coll{1, 3, 5, 7, 9, 12, 45, 36, 21, 27};
	auto f = std::bind(std::logical_and<bool>(),
			std::bind(std::greater<int>(), _1, 5),
			std::bind(std::less_equal<int>(), _1, 10));

	int count = std::count_if(coll.begin(), coll.end(), f);
	std::cout << "5 < val <= 10:" << count << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
