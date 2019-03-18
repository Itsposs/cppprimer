#include <iostream>
#include <chrono>
#include <iterator>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	int a1[] = {0,1,2,3,4,5,6,7,8,9,0};
	int a2[sizeof(a1)/sizeof(*a1)] = {0};
	auto ret = std::copy(begin(a1),end(a1),a2);
	
	for(size_t i = 0; i < 10; ++i)
	{
		std::cout << a2[i] << std::endl;
	}
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
