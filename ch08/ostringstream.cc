#include <iostream>
#include <string>
#include <vector>
#include <sstream>
/*
 * description: preserve some people and their
 * associated phone numbers
 */

struct PersonInfo
{
	std::string name;
	std::vector<std::string> phones;
};

bool vaild(const std::string &s)
{
	// TODO
	return true;
}

std::string format(const std::string &s)
{
	return s;
}

int main(int argc,char *argv[])
{
	std::string line,word;
	std::vector<PersonInfo> people;

	while(getline(std::cin,line))   // read a line data
	{
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while(record >> word)
		{
			info.phones.push_back(word);
		}
		people.push_back(info);
	}

	std::ostringstream os;
	for(const auto &entry : people)
	{
		std::ostringstream formatted,badNums;
		for(const auto &nums : entry.phones)
		{
			if(!vaild(nums))
			{
				badNums << " " << nums;
			}
			else
			{
				formatted << " " << format(nums);
			}
		}

		if(badNums.str().empty())
		{
			os << entry.name << " " << formatted.str() << std::endl;
		}
		else
		{
			std::cerr << "input error: " << entry.name
					  << "invalid number(s) " << badNums.str() << std::endl;
		}
	}


	//TODO
	return 0;
}
