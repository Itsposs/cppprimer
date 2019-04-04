#include <iostream>
#include <chrono>
#include <memory>
#include <string>


// 允许拷贝或赋值一个将要被销毁的unqiue_ptr.
std::unique_ptr<int> clone(int p)
{
	return std::unique_ptr<int>(new(std::nothrow) int (p));
	// unique_ptr<int> ret(new(nothrow) int (p));
	// return ret;
}


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::unique_ptr<std::string> p1(new(std::nothrow) std::string("hello world!"));
	// 将所有权从p1(指向string hello world)转移给p2
	std::unique_ptr<std::string> p2(p1.release());

	std::unique_ptr<std::string> p3(new(std::nothrow) std::string("c++ family"));
	// 将所有权从p3转移给p2
	p2.reset(p3.release()); // reset释放了p2原来指向的内存

	auto p = p2.release();
	delete p;
	p = nullptr;

	

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
