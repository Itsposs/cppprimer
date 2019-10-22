

#include <vector>
#include <iostream>
#include <algorithm>


void test() {
	std::vector<int> ivec{1, 3, 5, 7, 9, 2, 0, 2, 4, 5, 6, 2, 5};
	std::replace(ivec.begin(), ivec.end(), 5, 0);
	std::for_each(ivec.begin(), ivec.end(), [] (int val) { std::cout << val << " ";});
	std::cout << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	//TODO
	return 0;
}
