
#include <string>
#include <iostream>


int main(int argc, char *argv[])
{
	std::string s1 = "hello";
	std::string s2 = s1 + " world";
	std::cout << "" << s2 << std::endl;
	std::string s3 = (s1 + ",") + "world";
	// std::string  tmp = s1 + ", ";
	// s3 = tmp + "world";
	std::cout << "s3: " << s3 << std::endl;
	return 0;
}
