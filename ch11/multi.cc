
#include <set>
#include <vector>
#include <iostream>

void test() {
	std::vector<int> ivec;
	using size_type = std::vector<int>::size_type;

	for (size_type i = 0; i != 10; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);
	}

	std::set<int> iset(ivec.cbegin(), ivec.cend());
	std::multiset<int> miset(ivec.cbegin(), ivec.cend());
	std::cout << ivec.size() << std::endl;
	std::cout << iset.size() << std::endl;
	std::cout << miset.size() << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
