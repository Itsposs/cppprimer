#include <iostream>
#include <vector>


int main(int argc,char *argv[])
{
	std::vector<int> ivec{1,3,5,7,9};
	
	//std::cout << ivec.data() << std::endl;
	auto iter = ivec.begin();
	ivec.emplace(iter,12);

	for(const auto& val : ivec)
	{
		std::cout << val << std::endl;
	}
	//TODO
	return 0;
}
