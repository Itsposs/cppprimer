
#include <chrono>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

bool five_or_more(const std::string &s) {
	return s.size() >= 5;
}

typedef std::vector<std::string>::iterator iter;

int main(int argc, char *argv[]) {
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<std::string> words { "the", "quick", "red", "fox", "jumps"
		"over", "the", "slow", "red", "turtle"};

	iter mid = std::partition(words.begin(), words.end(), five_or_more);
	for (iter beg = words.begin(); beg != mid; ++beg) {
		std::cout << *beg << " ";
	}
	std::cout << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			      << "ms." << std::endl;
	return 0;
}
