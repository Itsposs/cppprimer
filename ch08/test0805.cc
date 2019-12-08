#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> 
func(std::ifstream &in,std::string &filename)
{
	std::vector<std::string> vstr;
	std::string line;

	in.open(filename);
	if(!in)
	{
		throw std::runtime_error("IO stream error");
	}
	else
	{
		while(in >> line)
		{
			std::cout << line << std::endl;
			vstr.push_back(line);
		}
	}
	return vstr;
}



int main(int argc,char *argv[])
{

	//TODO
	return 0;
}
