#include <iostream>
#include <chrono>
#include <vector>
#include <string>

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	std::vector<int> ivec = {1,3,5,7,9};
	for(auto beg = ivec.cbegin(); beg != ivec.cend();
			beg++)
	{
		std::cout << *beg << " ";
	}
	std::cout << std::endl;

	std::string s = {"hello world!"};
	std::cout << s << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
