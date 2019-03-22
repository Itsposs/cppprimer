#include <iostream>
#include <chrono>

void fcn3()
{
	size_t v1 = 42;

	// f 可以改变它所捕获的变量的值
	auto f = [v1] () mutable { return ++v1; };
	v1 = 0;
	auto j = f();
	std::cout << j << std::endl;
}

void fcn4()
{
	size_t v1 = 42;

	// v1是一个非const变量的引用
	// 可以通过f2中的引用来改变它
	auto f2 = [&v1] { return ++v1; };
	v1 = 0;
	auto j = f2();
	std::cout << j << std::endl;
}


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	fcn3();
	fcn4();
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
