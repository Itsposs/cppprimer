

#include <string>
#include <iostream>


std::string::size_type find_char(const std::string &s,
	char c, std::string::size_type &occurs)
{
	auto ret = s.size();
	occurs = 0;
	for(decltype(ret) i = 0; i != s.size(); ++i)
	{
		if(s[i] == c)
			ret = i;
		++occurs;
	}
	return ret;
}


int main(int argc, char *argv[])
{
	std::string s{"hello world!"};
	auto index = find_char(s, 'o', ctr);

	return 0;
}
