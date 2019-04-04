#include <iostream>
#include <chrono>
#include <memory>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::unique_ptr<int[]> up(new(std::nothrow) int[6]{1, 2, 3, 4, 5, 6});
	for(size_t i = 0; i != 6; ++i)
	{
		std::cout << up[i] << " ";
		up[i] = i;
	}
	up.release(); // 自动调用delete[]销毁其指针
	
	std::shared_ptr<int> sp(new int[10], [](int *p) { delete[] p;});
	for(size_t i = 0; i != 10; ++i)
	{
		*(sp.get() + 1) = i;
		//std::cout << *(sp.get() + i) << " ";
	}
	std::cout << std::endl;
	sp.reset();
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
