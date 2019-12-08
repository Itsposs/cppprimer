#include <string>
#include <cctype>
#include <iostream>


int main(int argc,char *argv[])
{
	std::string s("Hello World!!!");
	decltype(s.size()) punct_cnt = 0;

	for(auto c : s)
	{
		if(ispunct(c))
		{
			++punct_cnt;
		}
	}
	std::cout << punct_cnt << " punctuation characters in "
			  << s << std::endl;
	// TODO
	return 0;
}
