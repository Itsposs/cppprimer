

#include <string>


int main(int argc, char *argv[])
{
	std::string s1;
	std::string s2 = s1;
	std::string s3 = "hiya";
	std::string s4(10, 'c');
	std::string s5 = std::string(6, 'h');
	// std::string temp(6, 'h');
	// std::string s5 = temp;
	
	return 0;
}
