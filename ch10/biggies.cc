

#include <string>
#include <vector>
#include <chrono>
#include <iostream>
#include <algorithm>


void elimDups(std::vector<std::string> &words) {
	std::sort(words.begin(), words.end());
	auto dunique = std::unique(words.begin(), words.end());

	words.erase(dunique, words.end());
}

std::string make_plural(size_t ctr, const std::string &word,
	const std::string &ending) {
	return (ctr > 1) ? word + ending : word;
}


void biggies(std::vector<std::string> &words,
	std::vector<std::string>::size_type sz) {
	
	elimDups(words); // 将words按字典排序,删除重复单词

	// 按长度排序,长度相同的单词维持字典序
	std::stable_sort(words.begin(),words.end(),
		[](const std::string &a, const std::string &b)
		{ return a.size() < b.size();});

	// 获取一个迭代器,指向一个满足size() >= sz的元素
	auto wc = std::find_if(words.begin(), words.end(),
		[sz](const std::string &s){ return s.size() >= sz;});
	
	// 使用partition()函数解决问题
	// auto wc = std::partition(words.begin(), words.end(), 
	// [sz](const std::string &s) { s.size() >= sz; });
	
	// 计算满足size >= sz的元素的数目
	auto count = words.end() - wc;

	std::cout << " " << make_plural(count,"word","s")
			  << " of length " << sz << " or longer" 
			  << std::endl;
	
	// 打印长度大于给定的单词,每个单词后面接一个空格
	std::for_each(wc, words.end(), [](const std::string &s)
		{ std::cout << s << " "; });
	std::cout << std::endl;
}

void test() {

}


int main(int argc, char *argv[]) {
	
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			      << "ms." << std::endl;
	return 0;
}
