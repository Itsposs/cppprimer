
#include <map>
#include <string>
#include <iostream>


void test() {
	std::map<std::string, size_t> word_count;
	std::set<std::string> exclude = {"The", "But", "And", "Or", "An",
		"A", "the", "but", "and", "or", "an", "a"};
	std::string word;
	while (std::cin >> word) {
		if (exclude.find(word) == exclude.end()) {
			++word_count[word];
		}
	}
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
