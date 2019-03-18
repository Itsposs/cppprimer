#include <iostream>
#include <string>
#include <list>

int main(int argc,char *argv[])
{
	// equivalent to slist1.clear()
	// followed by slist1.insert(slist1.begin(),10,"Hiya!");
	std::list<std::string> slist1(1);
	slist1.assign(10,"Hiya!");
	
	for(const auto &val : slist1)
	{
		std::cout << val << std::endl;
	}
	//TODO
	return 0;
}
