#include <iostream>
#include <fstream>


int main(int argc,char *argv[])
{
	std::string file1("test1.txt");
	std::ifstream infile1(file1);  // C++11
	
	char file2[] = "test2.txt";
	std::ifstream infile2(file2);  // old version

	//TODO
	return 0;
}
