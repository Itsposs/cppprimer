#include <iostream>
#include <chrono>
#include <initializer_list>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::initializer_list<int> li{1,3,4,5,6,7,8,9};

	std::cout << "size:" << li.size() << std::endl;

	for(auto beg = li.begin(); beg != li.end();
		++beg)
	{
		std::cout << *beg << " ";
	}
	std::cout << std::endl;
	
	// array
	for(const auto &val : li)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
