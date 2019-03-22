#include <iostream>
#include <chrono>

void fcn1()
{
	size_t v1 = 42;

	// 将v1拷贝到名为f的可调用的对象
	auto f = [v1] { return v1; };
	v1 = 0;
	auto j = f();
	std::cout << j << std::endl;
}

void fcn2()
{
	size_t v1 = 42;  // 局部变量

	// 对象f2包含v1的引用
	auto f2 = [&v1] { return v1; };
	v1 = 0;
	auto j = f2();
	std::cout << j << std::endl;
}

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	fcn1();
	fcn2();

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
