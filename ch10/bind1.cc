#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include <functional>


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
	
	auto check6 = std::bind(check_size,_1,6);
	std::string s = "hello world!";
	bool ret = check6(s);
	
	std::cout << ret << std::endl;
	
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
