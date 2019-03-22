#include <iostream>
#include <chrono>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	/*
	std::vector<int> vec;
	std::istream_iterator<int> in_iter(std::cin);
	std::istream_iterator<int> eof;
	while(in_iter != eof)
	{
		vec.push_back(*in_iter++);
	}
	*/
	
	/*
	std::istream_iterator<int> in_iter(std::cin),eof;
	std::vector<int> vec(in_iter,eof);

	std::for_each(vec.begin(),vec.end(),[](const int &val)
	{ std::cout << val << " ";});
	std::cout << std::endl;
	*/
	std::istream_iterator<int> in(std::cin),eof;
	std::cout << std::accumulate(in,eof,0) << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
