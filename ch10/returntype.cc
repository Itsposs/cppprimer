#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<int> ivec = {1,3,-5,-6,-12,6,9,-18};
	std::transform(ivec.begin(),ivec.end(),ivec.begin(),
		[](int i) -> int { if(i < 0) return -i; else return i;});
	
	std::for_each(ivec.begin(),ivec.end(),[](const int &val) -> void
		{ std::cout << val << std::endl;});

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
