#include <iostream>
#include <fstream>
#include "Sales_data.h"


int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		std::cerr << "input filename:" << std::endl;
		return -1;
	}

	std::ifstream in(argv[1]);
	if(!in)
	{
		std::cerr << "open file fail" << std::endl;
		return -1;
	}

	Sales_data total;
	if(read(in,total))  // read first record to preserver it in total
	{
		Sales_data trans;
		while(read(in,trans)) // read second record to preserver it in trans
		{
			if(total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(std::cout,total) << std::endl;
				total = trans;  // deal with next record
			}
		}
		print(std::cout,total) << std::endl; // print sale record of last book
	}
	else
	{
		std::cerr << "no data" << std::endl;
	}

	//TODO
	return 0;
}
