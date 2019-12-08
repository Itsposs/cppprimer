
#include <vector>
#include <string>
#include <utility>
#include <iostream>

std::pair<std::string, int>
func(std::vector<std::string> &vec) {
	if (!vec.empty())
		// return std::make_pair(vec.back(), vec.back().size());
		return {vec.back(), vec.back().size()};
	else
		return std::pair<std::string, int>();
}


void test() {
	
}


int main(int argc, char *argv[]) {
	return 0;
}
