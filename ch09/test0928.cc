#include <iostream>
#include <chrono>
#include <string>
#include <forward_list>

void func(std::forward_list<std::string> &sflst,const std::string &s1,
	std::string &s2)
{
	auto prev = sflst.before_begin();
	auto curr = sflst.begin();
	bool inserted = false;

	while(curr != sflst.end())
	{
		if(*curr == s1)
		{
			curr = sflst.insert_after(curr,s2);
			inserted = true;
		}
		prev = curr;
		curr++;
	}
	if(!inserted)
	{
		sflst.insert_after(prev,s2);
	}
}

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
