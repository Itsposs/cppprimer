

#include <chrono>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


bool isShorter(const std::string &s1, const std::string &s2) {
	return s1.size() < s2.size();
}

void elimDups(std::vector<std::string> &words) {
	// 按字典序排序words,以便查找重复单词
	std::sort(words.begin(),words.end());
	// 返回指向不重复区域之后一个位置的迭代器
	auto dunique = std::unique(words.begin(), words.end());
	// 使用向量操作erase删除重复单词
	words.erase(dunique,words.end());
}

void test() {
	std::string line;
	std::vector<std::string> words{"the", "quick", "red", "fox",
		"jump", "over", "the", "slow", "red", "turtle"};

	elimDups(words);
	// 按长度重新排序,长度相同的单词维持字典序
	std::stable_sort(words.begin(),words.end(),isShorter);
	for (const auto &s : words) {
		std::cout << s << " ";
	}
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
