#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>

void biggies(std::vector<std::string> &words,
	std::vector<std::string>::size_type sz,
	std::ostream &os = std::cout,char c = ' ')
{
	// os隐式捕获,引用捕获方式;c显式捕获,值捕获方式
	std::for_each(words.begin(),words.end(),[&,c]
		(const std::string &s){ os << s << c; });

	// os显式捕获,引用捕获方式;c隐式捕获,值捕获方式
	std::for_each(words.begin(),words.end(),[=,&os]
	(const std::string &s){ os << s << c; });
}


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::vector<std::string> words = {"hello","world","nice","to","meet","you"};
	size_t sz = 5;

	auto wc = std::find_if(words.begin(),words.end(),[=]
		(const std::string &s){ return s.size() >= sz; });
	
	auto count = words.end() - wc;
	std::cout << count << std::endl;

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
