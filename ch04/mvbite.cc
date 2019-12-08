#include <iostream>
#include <bitset>

/*
 * decription: use operation of "<<" and ">>"
 */

int main(int argc,char *argv[])
{
	unsigned char bits = 0233;
	std::bitset<32> b(bits);
	std::cout << "before:" << b << std::endl;

	unsigned int ans1 = bits >> 8;
	std::bitset<32> b1(ans1);
	std::cout << ">> after:" << b1 << std::endl;
	
	unsigned int ans2 = bits << 8;
	std::bitset<32> b2(ans2);
	std::cout << "<< after:" << b2 << std::endl;
	
	// TODO
	return 0;
}
