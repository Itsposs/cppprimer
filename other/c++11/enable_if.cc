

#include <iostream>
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type 
foo(T t) {
	
	return t;
}

template <typename T>
T foo2(T t, typename std::enable_if<std::is_integral<T>::value, int>::type = 0) {
	return t;
}

template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
T foo3(T t) {
	return t;
}

template <typename T, typename Enable = void>
class A { };

template <typename T>
class A<T, typename std::enable_if<std::is_floating_point<T>::value>::type> { };

void test() {
	auto r  = foo(1);
	auto r1 = foo(1.2);
	//auto r2 = foo("test");   // error
	
	std::cout << "-----------------" << std::endl;
	foo2(1, 2);
	// foo2(1, " ");
	
	std::cout << "-----------------" << std::endl;
	foo3(1);
	// foo(1.2);
	
	std::cout << "-----------------" << std::endl;
	A<double> a;
	// A<int> a;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
