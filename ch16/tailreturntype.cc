

#include <list>
#include <string>
#include <vector>
#include <iostream>


template <typename It>
auto fcn(It beg, It end) -> decltype(*beg) {
	
	// 处理序列
	return *beg;
}





void test() {
	std::vector<int> vi = {1, 3, 5, 7};
	std::list<std::string> ca = {"hi", "bye"};
	auto &i = fcn(vi.begin(), vi.end());
	auto &s = fcn(ca.begin(), ca.end());
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
