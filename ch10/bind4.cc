

#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>


std::ostream& print(std::ostream &os, const std::string &s, char c) {
	return os << s << c;
}

using std::placeholders::_1;

void test() {
	std::vector<std::string> words = {"hello", "world", "nice", 
		"to", "meet", "you"};
	std::for_each(words.begin(), words.end(), std::bind(
				print, std::ref(std::cout), _1, ' '));
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	test();
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
