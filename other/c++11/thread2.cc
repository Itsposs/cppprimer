
#include <thread>
#include <string>
#include <iostream>
#include <functional>

void func(int i, double d, const std::string &s) {
	std::cout << i << ", " << d << ", " << s << std::endl;
}

void test() {
	std::thread t(std::bind(func, 1, 2, "hello world!"));
	// lambda 
	t.join();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
