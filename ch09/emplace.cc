#include <iostream>
#include <chrono>
#include <vector>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<int> ivec = {1,3,4,5};
	ivec.emplace_back(6);
	ivec.emplace(ivec.end(),12);

	for(const auto &val : ivec)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << std::endl;
	return 0;
}
