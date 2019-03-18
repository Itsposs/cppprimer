#include <iostream>
#include <chrono>
#include <string>

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();

	const char *cp = "Hello World!!!";
	std::string s1(cp);
	std::string s2(s1,0);
	std::string s3(s1,6,20);
	std::string s4(cp,6,5);
	std::string s5 = s1.substr(0,5);
	std::cout << s5 << std::endl;
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
