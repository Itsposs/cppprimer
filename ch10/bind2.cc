#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>


bool check_size(const std::string &s,
	std::string::size_type sz)
{
	return s.size() >= sz;
}

using std::placeholders::_1;

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<std::string> words = {"hello","world","nice","to","meet","you"};

	size_t sz = 4;
	auto wc = std::find_if(words.begin(),words.end(),std::bind(check_size,_1,sz));
	
	std::for_each(wc,words.end(),[](const std::string &s) -> void {std::cout << s << std::endl;});


	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
