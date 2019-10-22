
#include <array>
#include <iostream>
#include <algorithm>

void test() {
	std::array<int, 10> arr1 = {0, 1, 2, 4, 5, 6, 7, 8, 3, 9};
	std::array<int, 10> arr2(arr1);
	// array 不支持
	//std::array<int, 10> arr3(arr1.begin(), arr1.end());

	typedef std::array<int, 10>::size_type stype;
	for(stype i = 0; i < 10; ++i)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;
	std::cout << arr2.size() << std::endl; 
	std::cout << arr2.max_size() << std::endl; 

}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
