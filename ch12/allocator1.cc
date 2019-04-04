#include <iostream>
#include <chrono>
#include <memory>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::allocator<std::string> alloc;
	auto const p = alloc.allocate(100);  // 分配100个未初始化的string

	auto q = p;             // q指向最后构造元素之后的位置
	alloc.construct(q++);
	alloc.construct(q++, 10, 'c');
	alloc.construct(q++, "hi");
	std::cout << *p << std::endl;
	std::cout << p[1] << std::endl;
	std::cout << p[2] << std::endl;
	
	while(q != p)
	{
		alloc.destroy(--q);  // q先进行递减操作
	}
	alloc.deallocate(p, 100);


	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
