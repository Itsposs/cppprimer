

#include <vector>
#include <typeinfo>
#include <iostream>

void test() {
	std::vector<int> ivec = {1,3,5,7,9};
	auto beg = ivec.crbegin();
	auto end = ivec.crend();
	
	std::cout << typeid(beg).name() << std::endl;
	
	while (beg != end) {
		std::cout << *beg++ << " ";
	}
	std::cout << std::endl;
}

int main(int argc,char *argv[]) {
	test();
	//TODO
	return 0;
}
