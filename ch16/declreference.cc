

#include <iostream>
#include <type_traits>

template <typename T>
void func(const T &v) {
	//std::cout << std::remove_reference<T>::type << std::endl;
}

void test() {
	int val1 = 6;
	const int val2 = 7;
	func(val1);
	func(val2);
	func(8);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
