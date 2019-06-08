#include <iostream>


struct absInt
{
	int operator() (int val) const
	{
		return val < 0 ? -val : val;
	}
};


int main(int argc, char *argv[])
{
	int val = -42;
	absInt abs1;
	int ret = abs1(val);
	std::cout << "ret:" << ret << std::endl;

	return 0;
}
