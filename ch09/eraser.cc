
#include <list>
#include <chrono>
#include <iostream>

void test() {
	std::list<int> lst;
	for (size_t ix = 0; ix != 9; ++ix)	{
		std::cout << ix << " ";
		lst.push_front(ix);
	}
	std::cout << std::endl;

	int flag = 1;
	auto it = lst.begin();
	while (it != lst.end()) {
		if (*it & flag) {
			it = lst.erase(it);
		} else {
			++it;
		}
	}

	for (const auto &val : lst) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}


int main(int argc,char *argv[]) {
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	test();
	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			      << "ms." << std::endl;
	return 0;
}
