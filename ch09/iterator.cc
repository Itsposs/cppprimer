#include <iostream>
#include <vector>
#include <typeinfo>

int main(int argc,char *argv[])
{
	std::vector<int> ivec = {1,3,5,7,9};
	auto beg = ivec.crbegin();
	auto end = ivec.crend();
	
	std::cout << typeid(end).name() << std::endl;
	
	while(beg != end)
	{
		std::cout << *beg++ << std::endl;
	}
	//TODO
	return 0;
}
