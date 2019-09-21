

#include <string>
#include <iostream>


char & get_val(std::string &str, std::string::size_type sz)
{
	return str[sz];
}


int main(int argc, char *argv[])
{
	std::string p{"hello world!"};
	std::cout << p << std::endl;
	get_val(p, 6) = 'A';
	std::cout << p << std::endl;

	return 0;

}
