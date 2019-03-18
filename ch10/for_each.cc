#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<std::string> words = {"hello","world","nice","to"};

	std::for_each(words.cbegin(),words.cend(),[](const std::string &s)
		{std::cout << s << " ";});
	std::cout << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
