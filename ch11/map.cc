#include <iostream>
#include <chrono>
#include <map>
#include <vector>
#include <string>

void add_family(std::map<std::string,std::vector<std::string>> &families,
	const std::string &family)
{
	if(families.find(family) == families.end())
	{
		families[family] = std::vector<std::string>();
	}
}

void add_child(std::map<std::string,std::vector<std::string>> &families,
const std::string &family,const std::string &child)
{
	families[family].push_back(child);
}

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::map<std::string,std::vector<std::string>> families;

	// 添加家庭和孩子
	add_family(families,"Smith");
	add_child(families,"Smith","Jack");

	add_family(families,"Huo");
	add_child(families,"Huo","Hvate");

	for(const auto &val : families)
	{
		std::cout << "first:" << val.first << " ";
		for(const auto &c : val.second)
		{
			std::cout << "second:" << c << " ";
		}
		std::cout << std::endl;
	}

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
