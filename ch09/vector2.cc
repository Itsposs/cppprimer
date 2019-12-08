#include <iostream>
#include <chrono>
#include <vector>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<int> ivec = {1,3,5,7,9};
	std::cout << "front:" << ivec.front() << std::endl;
	std::cout << "back :" << ivec.back()  << std::endl;
	std::cout << "at(2):" << ivec.at(2)   << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << std::endl;
	return 0;
}
