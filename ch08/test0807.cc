#include <iostream>
#include <fstream>
#include "Sales_data.h"


int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		std::cerr << "<input file output file >" 
				  << std::endl;
		return -1;
	}

	std::ifstream in(argv[1],std::ifstream::in);
	if(!in)
	{
		std::cerr << "open input file fail" 
				  << std::endl;
		return -1;
	}
	std::ofstream out(argv[2],std::ofstream::out |
		std::ofstream::trunc);
	if(!out)
	{
		std::cerr << "open output file fail" 
				  << std::endl;
		return -1;
	}

	Sales_data total;
	if(read(in,total))
	{
		Sales_data trans;
		while(read(in,trans))
		{
			if(total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(out,total) << std::endl;
				total = trans;
			}
		}
		print(out,total) << std::endl;
	}
	else
	{
		std::cerr << "no data" << std::endl;
	}




	//TODO
	return 0;
}
