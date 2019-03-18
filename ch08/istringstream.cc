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


	//TODO
	return 0;
}
