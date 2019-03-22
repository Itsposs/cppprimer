#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

bool isShorter(const std::string &s1,const std::string &s2)
{
	return s1.size() < s2.size();
}

using std::placeholders ::_1;
using std::placeholders ::_2;


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<std::string> words = {"hello","world","nice","to","meet","you"};
	// 按单词由短至长排序
	std::sort(words.begin(),words.end(),isShorter);
	std::for_each(words.begin(),words.end(),[](const std::string &s) -> void
		{ std::cout << s << std::endl; });
	// 按单词由长至短排序
	std::sort(words.begin(),words.end(),std::bind(isShorter,_2,_1));
	std::for_each(words.begin(),words.end(),[](const std::string &s) -> void
		{ std::cout << s << std::endl; });

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
