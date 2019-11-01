

#include <iostream>
#include <type_traits>

int fn(int) { return int(); }

void test() {
	// 对函数使用std::result_of,要先将函数转换为可调用对象,通过以下方式
	// 获取函数返回类型
	typedef std::result_of<decltype(fn)&(int)>::type A;
	typedef std::result_of<decltype(fn)*(int)>::type B;
	typedef std::result_of<typename std::decay<decltype(fn)>::
		type(int)>::type C;

	static_assert(std::is_same<A, B>::value, "not equal");
	static_assert(std::is_same<A, C>::value, "not equal");
	static_assert(std::is_same<B, C>::value, "not equal");
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
