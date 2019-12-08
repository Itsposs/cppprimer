
#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <algorithm>


void elimDups(std::vector<std::string> &words) {
	std::sort(words.begin(), words.end());
	auto dunique = std::unique(words.begin(), words.end());

	words.erase(dunique, words.end());
}

void output(std::vector<std::string> &words) {
	std::for_each(words.cbegin(),words.cend(),
		[](const std::string &s){ std::cout << s << " ";});
	std::cout << std::endl;
}

void test() {
	std::vector<std::string> text{"the", "quick", "red", "fox", "jumps",
		"over", "the", "slow", "red", "turtle"};
	elimDups(text);
	output(text);
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
