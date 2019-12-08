#include <iostream>
#include <chrono>
#include <string>



int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();

	// TODO
	std::string s1 = "a value", s2 = "another";
	auto n = (s1 + s2).find('a');
	std::cout << "n:" << n << std::endl;

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
