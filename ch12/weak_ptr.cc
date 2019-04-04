#include <iostream>
#include <chrono>
#include <memory>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	auto p = std::make_shared<int>(42);
	std::weak_ptr<int> wp(p);  // p弱共享p;p的引用计数未改变

	if(std::shared_ptr<int> np = wp.lock()) // 如果np条件不为空则条件成立
	{
		std::cout << *np << std::endl;
	}

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
