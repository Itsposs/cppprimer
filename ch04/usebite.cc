#include <iostream>
#include <bitset>

/*
 * description: how do students' quiz ?
 */

int main(int argc,char *argv[])
{
	unsigned long quiz = 0;
	unsigned long ans = 1UL << 27;
	//std::bitset<32> b(ans);
	//std::cout << b << std::endl;
	bool status = quiz & ans;

	if(status)
	{
		std::cout << "pass" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}
	// TODO
	return 0;
}
