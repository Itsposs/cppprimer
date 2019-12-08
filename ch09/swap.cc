#include <iostream>
#include <string>
#include <vector>
#include <chrono>

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();

	std::vector<std::string> svec1 = {"Java","C","C++","Python"};
	std::vector<std::string> svec2 = {"nice","to","meet","you","how","are","you"};
	
	std::swap(svec1,svec2);
	for(const auto &val1 : svec1)
	{
		std::cout << val1 << " ";
	}
	std::cout <<  std::endl;

	for(const auto &val2 : svec2)
	{
		std::cout << val2 << " ";
	}
	std::cout << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << duration_cast<milliseconds> (end - begin).count()
			  << std::endl;
	return 0;
}
