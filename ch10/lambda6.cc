


#include <vector>
#include <iostream>
#include <algorithm>


void test() {
	std::vector<int> vi{1, -2, -3, 7, -5, 9, 0, -4, 12};
	std::transform(vi.begin(), vi.end(), vi.begin(), 
			[](int i) { return i < 0 ? -i : i; });

	std::transform(vi.begin(), vi.end(), vi.begin(), 
			[](int i) -> int { if (i < 0) return -i;
			else return i; });
	std::for_each(vi.cbegin(), vi.cend(), [](int val)
			{ std::cout << val << " ";});
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	// TODO
	return 0;
}


