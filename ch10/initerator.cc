#include <iostream>
#include <chrono>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	std::vector<int> vec1 = {1,2,3,4,4,6,7,8,9,6,0};
	std::vector<int> vec2;
	std::list<int> lst1 = {1,2,3,4,7,8,9,6,0};
	std::list<int> lst2,lst3,lst4;

	std::copy(lst1.begin(),lst1.end(),front_inserter(lst2));
	std::for_each(lst2.begin(),lst2.end(),[](const int &val)
		{ std::cout << val << " "; });
	std::cout << std::endl;

	std::copy(lst1.cbegin(),lst1.cend(),inserter(lst3,lst3.begin()));
	std::for_each(lst3.begin(),lst3.end(),[](const int &val)
		{ std::cout << val << " "; });
	std::cout << std::endl;

	std::unique_copy(vec1.cbegin(),vec1.cend(),back_inserter(vec2));
	std::for_each(vec2.begin(),vec2.end(),[](const int &val)
		{ std::cout << val << " "; });
	std::cout << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
