#include <iostream>
#include <chrono>
#include <forward_list>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::forward_list<int> ilist;
	for(size_t ix = 0;ix != 4;++ix)
	{
		ilist.push_front(ix);
	}
	
	std::cout << "max_size:" << ilist.max_size() << std::endl;
	for(const auto &val : ilist)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << std::endl;
	return 0;
}
