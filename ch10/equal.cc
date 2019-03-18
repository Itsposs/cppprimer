#include <iostream>
#include <chrono>
#include <vector>
#include <string>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<std::string> vs1 = {"hello","world","c++"};
	std::vector<std::string> vs2 = {"nice","to","meet"};
	std::cout << std::equal(vs1.begin(),vs1.end(),vs2.begin()) << std::endl;
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
