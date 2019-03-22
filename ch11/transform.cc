#include <iostream>
#include <chrono>
#include <map>
#include <stdexcept>
#include <string>
#include <fstream>
#include <sstream>

std::map<std::string,std::string> buildMap(std::ifstream &map_file)
{
	std::map<std::string,std::string> trans_map;
	std::string key;
	std::string value;

	while(map_file >> key && getline(map_file,value))
	{
		if(value.size() > 1)
		{
			trans_map[key] = value.substr(1);  // 跳过前导空格
		}
		else
		{
			throw std::runtime_error("no rule for " + key);
		}
	}
	return trans_map;
}

const std::string &
transform(const std::string &s,const std::map<std::string,std::string> &m)
{
	auto map_it = m.find(s);

	// 如果单词在转换规则map中
	if(map_it != m.cend())
	{
		return map_it -> second;   // 使用替换短语		
	}
	else
	{
		return s;
	}
}

void word_transform(std::ifstream &map_file,std::ifstream &input)
{
	auto trans_map = buildMap(map_file);
	std::string text;
	while(getline(input,text))
	{
		std::istringstream stream(text);
		std::string word;
		bool firstword = true;

		while(stream >> word)
		{
			if(firstword)
			{
				firstword = false;
			}
			else
			{
				std::cout << " ";
			}
			std::cout << transform(word,trans_map);
		}
		std::cout << std::endl;
	}
}

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::ifstream ruler("ruler.txt");
	std::ifstream input("input.txt");
	word_transform(ruler,input);

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
