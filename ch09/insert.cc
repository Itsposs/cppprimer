

#include <chrono>
#include <vector>
#include <string>
#include <iostream>

void test() {
	std::string line;
	std::vector<std::string> vst = {"how","are","you"};
	std::vector<std::string>::const_iterator iter;
	vst.insert(vst.end(),{"nice","to","meet","you"});

	for (const auto &val : vst) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

int main(int argc,char *argv[]) {
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	test();
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			      << std::endl;
	return 0;
}
