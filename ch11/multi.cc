#include <iostream>
#include <chrono>
#include <string>
#include <map>
#include <set>


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	std::string search_item("Alain de Botton");
	
	std::multimap<std::string,std::string> authors;
	/*
	auto entries = authors.count(search_item);
	auto iter = authors.find(search_item);

	while(entries)
	{
		std::cout << iter -> second << std::endl;
		++iter;
		--entries;
	}
	*/

	for(auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item);
			beg != end; ++beg)
	{
		std::cout << beg -> second << std::endl;
	}

	for(auto pos = authors.equal_range(search_item);
		pos.first != pos.second; ++pos.first)
	{
		std::cout << pos.first -> second << std::endl;
	}

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
