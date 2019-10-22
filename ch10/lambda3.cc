

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


void biggies(std::vector<std::string> &words,
		std::vector<std::string>::size_type sz, 
		std::ostream &os = std::cout, char c = ' ') {

	std::for_each(words.begin(), words.end(), 
			[&, c](const std::string &s){ os << s << c; });
	std::cout << std::endl;
	
	std::for_each(words.begin(), words.end(), 
			[=, &os](const std::string &s){ os << s << c; });
	std::cout << std::endl;
}

void test() {
	std::vector<std::string> text{"the", "quick", "red", "fox", "jumps",
		"over", "the", "slow", "red", "turtle"};
	constexpr std::vector<std::string>::size_type size = 5;
	biggies(text, size);
}


int main(int argc, char *argv[]) {
	test();
	// TODO
	return 0;
}
