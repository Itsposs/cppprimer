

#include <vector>
#include <iostream>


typedef std::vector<int>::const_iterator citerator;

bool find(citerator beg, citerator end, int target) {
	for ( ; beg != end; ++beg) {
		if (*beg == target) {
			return true;
		}
		
	}
	return false;
}

void test() {
	std::vector<int> ivec = {1, 3, 5, 7, 9, 11, 5};
	citerator iter1 = ivec.begin();
	citerator iter2 = ivec.end();

	std::cout << find(iter1, iter2, 5) << std::endl;
}

int main(int argc,char *argv[]) {
	test();
	//TODO
	return 0;
}
