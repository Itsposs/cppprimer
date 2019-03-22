#include <iostream>
#include <chrono>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();

	/*
	std::vector<int> vec = {0,1,2,3,4,5,6,7,8,9,0};

	for(auto r_iter = vec.crbegin();r_iter != vec.crend();
		++r_iter)
	{
		std::cout << *r_iter << " ";
	}
	std::cout << std::endl;
	*/

	std::string word;
	std::vector<std::string> line;
	while(std::cin >> word)
	{
		line.push_back(word);
	}
	auto rcomma = std::find(line.crbegin(),line.crend(),',');
	//std::string ret(rcomma.base(),line.cend()); 
	//std::cout << ret << std::endl;
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
