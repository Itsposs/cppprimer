#include <iostream>
#include <chrono>
#include <vector>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<int> ivec;
	for(size_t ix = 0;ix != 24;++ix)
	{
		ivec.push_back(ix);
	}

	ivec.reserve(48);
	std::cout << "size:" << ivec.size()
			  << "capacity:" << ivec.capacity()
			  << std::endl;
	for(const auto &val : ivec)
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
