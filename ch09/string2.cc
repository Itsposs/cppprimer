#include <iostream>
#include <chrono>
#include <string>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	const char *cp = "Stately,plump Buck";
	std::string s;
	s.assign(cp,7);
	s.insert(s.size(),cp + 7);
	std::cout << s << std::endl;
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
