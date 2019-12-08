#include <iostream>
#include <chrono>
#include <numeric>
#include <vector>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<int> ivec = {1,2,3,4,5,6,7,8,9,0};
	/*
	 * accumulate()
	 * array
	 * type arr[]
	 * point 
	 */
	int sum = std::accumulate(ivec.begin(),ivec.end(),0);
	std::cout << "sum:" << sum << std::endl;
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
