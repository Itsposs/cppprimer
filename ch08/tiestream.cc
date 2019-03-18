#include <iostream>
#include <fstream>

/*
 * description: .tie() function
 */

int main(int argc,char *argv[])
{
	/*
	std::cin.tie(&std::cout);
	int ival;
	std::cin >> ival;
	std::cout << ival << std::endl;

	auto old = std::cin.tie(nullptr);
	
	std::cin.tie(&std::cerr);
	std::cin.tie(old);
	*/

	std::ofstream ofs;
	ofs.open("test.txt");

	std::cin.tie(&ofs);
	*(std::cin.tie()) << "hello world!";
	char c;

	while(std::cin >> c && !std::cin.eof())
	{
		ofs << c;
	}

	ofs.close();

	//TODO
	return 0;
}
