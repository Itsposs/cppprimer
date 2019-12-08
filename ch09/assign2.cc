

#include <list>
#include <string>
#include <vector>
#include <iostream>

void test() {
	int iarr[] = {1, 3, 5, 7, 9};
	std::vector<int> ivec2;
	ivec2.assign(iarr, iarr + 5);

	for (const auto &val : ivec2) {
		std::cout << val << " ";
	}	
	std::cout << std::endl;
	// equivalent to slist1.clear()
	// followed by slist1.insert(slist1.begin(),10,"Hiya!");
	std::list<std::string> slist1(1);
	slist1.assign(10, "Hiya!");
	
	for (const auto &val : slist1){
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

int main(int argc,char *argv[]) {
	test();	
	//TODO
	return 0;
}
