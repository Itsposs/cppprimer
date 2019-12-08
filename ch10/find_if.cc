
#include <chrono>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


std::string make_plural(size_t ctr, const std::string &word,
	const std::string &ending) {
	return (ctr > 1) ? word + ending : word;
}

void test() {
	std::vector<std::string>::size_type sz = 5;
	std::vector<std::string> words = {"hello", "word", "nice", "to", "meet"};
	
	// 获取一个迭代器,指向第一个满足size() >= sz的元素
	auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string &s)
		{ return s.size() >= sz; });

	// 计算满足size >= sz的元素数目
	auto count = words.end() - wc;
	std::cout << count << " " << make_plural(count,"word","s")
		 << " of length " << sz << " or longer" << std::endl;
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
