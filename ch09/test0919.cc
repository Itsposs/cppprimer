#include <iostream>
#include <chrono>
#include <string>
#include <deque>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::string line;
	std::deque<std::string> words;
	while(std::cin >> line)
	{
		words.push_front(line);
		std::cout << line << " ";
	}
	std::cout << std::endl;
	
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << std::endl;
	return 0;
}
