

#include "impl.h"
#include <iostream>

template <typename T>
detail_range::impl<T> range(T end) {
	return { {}, end, 1 };
}


template <typename T> 
detail_range::impl<T> range(T begin, T end) {
	return { begin, end, 1 };
}


template <typename T, typename U>
auto range(T begin, T end, U step) 
	-> detail_range::impl<decltype(begin + step)> {
		using r_t = detail_range::impl<decltype(begin + step)>;
		return r_t(begin, end, step);
}

void test_range() {
	std::cout << "range(15):";
	for (int i : range(15)) {
		std::cout << " " << i; 
	}
	std::cout << std::endl;

	std::cout << "range(2, 6):";
	for (auto i : range(2, 6)) {
		std::cout << " " << i;
	}
	std::cout << std::endl;

	const int x = 2, y = 6, z = 3;
	std::cout << "range(2, 6, 3):";
	for (auto i : range(x, y, z)) {
		std::cout << " " << i;
	}
	std::cout << std::endl;

	std::cout << "range(-2, -6, -3):";
	for (auto i : range(-2, -6, -3)) {
		std::cout << " " << i;
	}
	std::cout << std::endl;

	std::cout << "range(10.5, 15.5):";
	for (auto i : range(10.5, 15.5)) {
		std::cout << " " << i;
	}
	std::cout << std::endl;

	std::cout << "range(35, 27, -1):";
	for (int i : range(35, 27, -1)) {
		std::cout << " " << i;
	}
	std::cout << std::endl;

	std::cout << "range(2, 8, 0.5):";
	for (auto i : range(2, 8, 0.5)) {
		std::cout << " " << i;
	}
	std::cout << std::endl;

	std::cout << "range(8, 7, -0.1):";
	for (auto i : range(8, 7, -0.1)) {
		std::cout << " " << i;
	}
	std::cout << std::endl;

	std::cout << "range('a', 'z'):";
	for (auto i : range('a', 'z')) {
		std::cout << " " << i;
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	test_range();
	return 0;
}
