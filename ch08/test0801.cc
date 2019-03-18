#include <iostream>

std::istream& func1(std::istream &os)
{
	auto old = os.rdstate();
	std::string line;
	while(getline(os,line))
	{
		std::cout << line << std::endl;
	}
	os.setstate(old);

	return os;
}

std::istream& func2(std::istream &in)
{
	int ival;

	while(in >> ival && !in.eof())
	{
		if(in.bad())
		{
			throw runtime_error("IO stream error");
		}

		if(in.fail())
		{
			std::cerr << "data error,please you try it:" << std::endl;
			in.clear();
			in.ignore(1000,'\n');
			continue;
		}
		std::cout << ival << std::endl;
	}
	return in;
}



int main(int argc,char *argv[])
{
	// TODO
	return 0;
}
