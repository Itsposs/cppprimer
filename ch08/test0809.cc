#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

std::istream& func(std::istream &in)
{
	std::string line;
	while(in >> line && !in.eof())
	{
		if(in.bad())
		{
			throw std::runtime_error("IO stream error");
		}
		if(in.fail())
		{
			std::cerr << "data error,try again: " << std::endl;
			in.clear();
			in.ignore(1000,'\n');
			continue;
		}
		std::cout << line << std::endl;
	}
	in.clear();
	return in;
}

int main(int argc,char *argv[])
{
	std::ostringstream msg;
	msg << "C++ Primer 5th" << std::endl;
	std::istringstream in(msg.str());
	func(in);

	//TODO
	return 0;
}



