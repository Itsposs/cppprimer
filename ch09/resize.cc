#include <iostream>
#include <chrono>
#include <list>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::list<int> ilist(10,42);
	ilist.resize(15);
	ilist.resize(25,-1);
	ilist.resize(5);
	for(const auto &val : ilist)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
