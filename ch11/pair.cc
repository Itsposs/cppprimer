#include <iostream>
#include <chrono>
#include <utility>
#include <vector>
#include <string>
#include <map>


void add_family(std::map<std::string,std::vector<std::pair<std::string,std::string>>> &families,
	const std::string &family)
{
	families[family];
}

void add_child(std::map<std::string,std::vector<std::pair<std::string,std::string>>> &families,
	const std::string &family,const std::string &child,const std::string &birthday)
{
	families[family].push_back({child,birthday});
}

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::map<std::string,std::vector<std::pair<std::string,std::string>>> families;

	// 添加家庭\孩子\生日等信息
	add_family(families,"Smith");
	add_child(families,"Smith","Jack","2018-03-15");

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
