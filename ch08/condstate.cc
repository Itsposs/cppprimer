#include <iostream>

/*
 * description: how do you manage condition state ?
 */

int main(int argc,char *argv[])
{
	auto old_state = std::cin.rdstate();
	std::cin.clear();
	int ival;
	std::cin >> ival;

	std::cin.setstate(old_state);
	// TODO
	return 0;
}
