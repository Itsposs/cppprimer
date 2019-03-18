#include <iostream>
#include <chrono>
#include <vector>
#include <list>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	std::vector<int> ivec;
	std::list<int> lvec;

	ivec.assign(ia,ia + 11);
	lvec.assign(ia,ia + 11);

	auto iter1 = ivec.begin();
	auto iter2 = lvec.begin();
	
	int flag = 1;
	while(iter1 != ivec.end())
	{
		if(*iter1 & flag)
		{
			iter1 = ivec.erase(iter1);
		}
		else
		{
			++iter1;
		}
	}

	while(iter2 != lvec.end())
	{
		if(*iter2 & flag)
		{
			++iter2;
		}
		else
		{
			iter2 = lvec.erase(iter2);
		}
	}

	for(const auto val1 : ivec)
	{
		std::cout << val1 << " ";
	}
	std::cout << std::endl;
	
	for(const auto val2 : lvec)
	{
		std::cout << val2 << " ";
	}
	std::cout << std::endl;
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
