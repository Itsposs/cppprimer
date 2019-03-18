#include <iostream>
#include <chrono>
#include <deque>
#include <list>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::list<int> ilist = {1,3,2,5,4,6,9,8,7};
	std::deque<int> queue1,queue2;
	int flag = 1;
	for(auto beg = ilist.begin();beg != ilist.end();++beg)
	{
		if(*beg & flag)
		{
			queue1.push_front(*beg);
		}
		else
		{
			queue2.push_front(*beg);
		}
	}

	for(const auto val1 : queue1)
	{
		std::cout << val1 << " ";
	}
	std::cout << std::endl;
	
	for(const auto val2 : queue2)
	{
		std::cout << val2 << " ";
	}
	std::cout << std::endl;
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << " ms." << std::endl;
	return 0;
}
