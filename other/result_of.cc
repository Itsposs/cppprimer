

#include <iostream>
#include <type_traits>


int fn(int) { return int(); }
typedef int(&fn_ref)(int);
typedef int(*fn_ptr)(int);
struct fn_class {
	int operator()(int i) { return i; }
};


void test() {
	// result_of获取一个可调用对象的返回类型
	typedef std::result_of<decltype(fn)&(int)>::type A;
	typedef std::result_of<fn_ref(int)>::type B;
	typedef std::result_of<fn_ptr(int)>::type C;
	typedef std::result_of<fn_class(int)>::type D;

	std::cout << std::boolalpha;
	std::cout << "typedefs of int:" << std::endl;

	std::cout << "A: " << std::is_same<int, A>::value << std::endl;
	std::cout << "B: " << std::is_same<int, B>::value << std::endl;
	std::cout << "C: " << std::is_same<int, C>::value << std::endl;
	std::cout << "D: " << std::is_same<int, D>::value << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
