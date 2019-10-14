
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <string>
#include <iostream>


void test() {
	//std::vector<int> ivec = {2,4,6,8,2,4,6,8};
	//std::set<int> set2;
	//set2.insert(ivec.cbegin(),ivec.cend());
	//set2.insert({1,3,5,7,1,3,5,7});

	//for(const auto &val : set2)
	//{
	//	std::cout << val << " ";
	//}
	//std::cout << std::endl;


	//std::map<std::string,size_t> word_count;
	//word_count.insert({"word1",1});
	//word_count.insert(std::make_pair("word2",2));
	//word_count.insert(std::pair<std::string,size_t>("word3",3));
	//word_count.insert(std::map<std::string,size_t>::value_type("word4",4));

	//for(const auto &val : word_count)
	//{
	//	std::cout << val.first << " " << val.second << " ";
	//}
	//std::cout << std::endl;
	
	std::map<std::string,size_t> word_count;
	std::string word;
	while(std::cin >> word)
	{
		// 插入一个元素,关键字等于word,值为1
		// 若word已在word_count中,insert什么也不做
		auto ret = word_count.insert({word,1});
		// 若word已在word_count中,insert什么也不做
		if(!ret.second)
		{
			++((ret.first) -> second); // 递增计数器
		}
	}
}


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	test();

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
