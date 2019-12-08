

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


void test() {
	constexpr int sz = 5;
	std::vector<std::string> words{};
	auto wc = std::find_if(words.begin(), words.end(),
			[=](const std::string &s){ return s.size() >= sz; });
}


int main(int argc, char *argv[]) {
	test();
	//TODO
	return 0;
}
