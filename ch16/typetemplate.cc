#include <iostream>
#include <vector>
#include <functional>


template<typename T>
int compare(const T &v1, const T &v2)
{
	if (std::less<T>()(v1, v2)) return -1;
	if (std::less<T>()(v2, v1)) return 1;
	return 0;
}


int main(int argc, char *argv[])
{
	std::cout << compare(1, 0) << std::endl;
	std::vector<int> vec1{1, 3, 5}, vec2{3, 5, 7};
	std::cout << compare(vec1, vec2) << std::endl;

	return 0;
}
