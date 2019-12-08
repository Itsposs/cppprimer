

#include <list>
#include <vector>
#include <string>
#include <iostream>

void test() {
	std::list<std::string> names;
	std::vector<const char*> oldstyle = {"hello","world"};
	names.assign(oldstyle.cbegin(),oldstyle.cend());

	for (const auto &val : names) { 
		std::cout << val << std::endl;
	}
}

int main(int argc,char *argv[]) {
	test();
	//TODO
	return 0;
}
