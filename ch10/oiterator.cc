#include <iostream>
#include <chrono>
#include <iterator>
#include <vector>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<int> vec = {1,3,5,7,9,0};
	std::ostream_iterator<int> out_iter(std::cout," ");

	for(const auto val : vec)
	{
		*out_iter++ = val;
	}
	std::cout << std::endl;


	// equivalent
	std::copy(vec.begin(),vec.end(),out_iter);
	std::cout << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
