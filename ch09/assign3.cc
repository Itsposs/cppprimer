#include <iostream>
#include <vector>

int main(int argc,char *argv[])
{
	int iarr[] = {1,3,5,7,9};
	std::vector<int> ivec2;
	ivec2.assign(iarr,iarr + 5);

	for(const auto &val : ivec2)
	{
		std::cout << val << std::endl;
	}
	//TODO
	return 0;
}
