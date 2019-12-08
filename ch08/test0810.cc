#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>


int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		std::cerr << "<usage: inputfile>" << std::endl;
		return -1;
	}
	std::ifstream in(argv[1]);
	if(!in)
	{
		std::cerr << "open file fail" << std::endl;
		return -1;
	}
	std::vector<std::string> vst;
	std::string line;
	while(getline(in,line))
	{
		vst.push_back(line);
	}
	in.close();
	
	std::vector<std::string>::const_iterator it = vst.begin();
	while(it != vst.end())
	{
		std::istringstream record(*it);
		std::string word;
		while(record >> word)
		{
			std::cout << word << " ";
		}
		std::cout << std::endl;
		++it;
	}



	//TODO
	return 0;
}
