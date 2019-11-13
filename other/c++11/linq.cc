
#include "linq.h"
#include <iostream>

void test() {
	Task<int(int)> task = [](int i) { return i;};
	auto result = task.Then([](int i){ return i; }).Then([](int i){
			return i + 2; }).Then([](int i){ return i + 3; }).Run(1);
	std::cout << "result :" << result << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
