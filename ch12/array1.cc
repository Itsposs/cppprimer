#include <iostream>
#include <chrono>

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	int *pia3 = new int[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string *psa3 = new std::string[10] {"a", "an", "the",
		std::string(3,'x')};
	delete pia3;
	delete [] psa3;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
