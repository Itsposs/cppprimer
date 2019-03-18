#include <iostream>

/*
 * description: opening a file in out mode 
 * discards existing data
 */

int main(int argc,char *argv[])
{
	// below expression regard as same
	std::ofstream out1("file1.txt");
	std::ofstream out2("file2.txt",std::ofstream::out);
	std::ofstream out3("file3.txt",std::ofstream::out |
		std::ofstream::truc);

	// to preserve the file's contents,we must explicitily
	// specify app mode
	std::ofstream out4("file4.txt",std::ofstream::app);
	std::ofstream out5("file5.txt",std::ofstream::out |
		std::ofstream::app);


	//TODO
	return 0;
}
