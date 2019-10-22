
#include <vector>
#include <iostream>
#include <algorithm>

void test() {
	std::vector<int> ivec{1, 3, 0, 4, 7, 3, 8, 2, 3, 4, 2, 9};
	int times = std::count(ivec.begin(), ivec.end(), 3);
	std::cout << "times:" << times << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
