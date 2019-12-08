
#include <map>
#include <string>
#include <chrono>
#include <iostream>

void test() {
	std::map<std::string, size_t> word_count;
	std::string word;
	while (std::cin >> word) {
		++word_count[word];
	}
	for (const auto &w : word_count) {
		// print result
		std::cout << w.first << " occurs " << w.second
					    << ((w.second > 1) ? " times" : " time") << std::endl;
	}
}


int main(int argc,char *argv[]) {
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	test();

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
