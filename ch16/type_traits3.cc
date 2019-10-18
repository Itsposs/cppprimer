


#include <iostream>
#include <type_traits>


void test() {
	std::cout << std::boolalpha;
	std::cout << std::is_same<const int, std::add_const<int>::type>::value << std::endl;
	std::cout << std::is_same<int, std::remove_const<int>::type>::value << std::endl;
	std::cout << std::is_same<int&, std::add_lvalue_reference<int>::type>::value << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
