#include <iostream>
#include <chrono>
#include <vector>

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<int> ivec1 = {1,12,42,32,42,48,72};
	std::vector<int> ivec2 = {1,12,42,32,42,48,72};

	std::fill(ivec1.begin(),ivec1.end(),7);
	std::fill_n(ivec2.begin(),ivec2.size(),7);

	std::cout << (ivec1 == ivec2) << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
