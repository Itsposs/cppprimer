#include <iostream>
#include <chrono>
#include <forward_list>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	
	int flag = 1;
	while(curr != flst.end())
	{
		if(*curr &flag)
		{
			curr = flst.erase_after(prev);
		}
		else
		{
			prev = curr;
			++curr;
		}
	}

	for(const auto &val : flst)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << " ms." << std::endl;
	return 0;
}
