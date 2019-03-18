#include <iostream>
#include <chrono>
#include <vector>
#include <string>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<std::string> words;
	std::string line;
	while(std::cin >> line)
	{
		words.push_back(line);
	}
	std::cout << "max_size:" << words.max_size() << std::endl;
	for(const auto &val : words)
	{
		std::cout << val << std::endl;
	}
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << duration_cast<milliseconds> (end - begin).count()
			  << std::endl;
	return 0;
}
