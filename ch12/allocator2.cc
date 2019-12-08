#include <iostream>
#include <chrono>
#include <memory>
#include <vector>

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<int> vi = {1, 2, 3, 4, 5, 6};
	std::allocator<int> alloc;
	auto p = alloc.allocate(vi.size() * 2);
	// 通过拷贝vi中的元素来构造从p开始的元素
	auto q = std::uninitialized_copy(vi.begin(), vi.end(), p);
	// 将剩余元素初始化为42
	std::uninitialized_fill_n(q, vi.size(), 42);
	
	// 使用数数组
	for(size_t i = 0; i < vi.size() * 2; ++i)
	{
		std::cout << p[i] << " ";
	}
	std::cout << std::endl;

	while(q != p)
	{
		alloc.destroy(--q);
	}
	alloc.deallocate(p, vi.size() * 2);

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
