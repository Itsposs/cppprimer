#include <iostream>
#include <chrono>
#include <regex>
#include <string>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	// 查找不在字符c之后的字符串ei
	std::string pattern("[^c]ei");
	// 包含pattern的整个单词
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern); // 构造一个用于查找模式的regex
	std::smatch results; // 定义一个对象保存搜索结果

	// 定义一个string保存与模式匹配和不匹配的文本
	std::string test_str = "receipt friend theif receive";

	// 用r在test_str中查找与pattern匹配的子串
	if(std::regex_search(test_str,results,r))  // 如果有匹配子串打印匹配子串
	{
		std::cout << results.str() << std::endl;
	}
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
