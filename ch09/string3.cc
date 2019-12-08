#include <iostream>
#include <chrono>
#include <string>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::string s1("C++ primer"),s2 = s1;
	s1.insert(s1.size()," 4th Ed.");
	s2.append(" 4th Ed.");
	
	s1.erase(11,3);
	s1.insert(11,"5th");

	// eqivalent to followed by 
	s2.replace(11,3,"5th");

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
