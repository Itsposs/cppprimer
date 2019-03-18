#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <list>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::list<const char*> slist = {"hello","world","!"};
	std::vector<std::string> svec;
	svec.assign(slist.begin(),slist.end());

	for(const auto &val : svec)
	{
		std::cout << val << std::endl;
	}
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << duration_cast<milliseconds> (end - begin).count()
			  << std::endl;
	return 0;
}
