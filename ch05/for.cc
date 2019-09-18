
#include <vector>
#include <iostream>
#include <algorithm>


int main(int argc, char *argv[])
{
	std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for(auto &r : v)
		r *= 2;

	std::for_each(v.begin(), v.end(), [](int val) { std::cout << val << " "; });
	std::cout << std::endl;
	return 0;
}
