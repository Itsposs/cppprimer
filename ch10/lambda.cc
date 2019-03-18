#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<std::string> words = {"hello","world","nice","to"};

	std::stable_sort(words.begin(),words.end(),[](const std::string &a,
		const std::string &b) { return a.size() < b.size();});

	for(const auto &s : words)
	{
		std::cout << s << " ";
	}
	std::cout << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
