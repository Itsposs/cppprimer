

#include <iostream>
#include <type_traits>


template <typename T, typename U>
struct decay_equiv : std::is_same<typename std::decay<T>::type, U>::type
{};


void test() {
	std::cout << std::boolalpha;
	std::cout << decay_equiv<int, int>::value << std::endl;
	std::cout << decay_equiv<int&, int>::value << std::endl;
	std::cout << decay_equiv<int&&, int>::value << std::endl;
	std::cout << decay_equiv<const int&, int>::value << std::endl;
	std::cout << decay_equiv<int[2], int*>::value << std::endl;
	std::cout << decay_equiv<int(int), int(*)(int)>::value << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
