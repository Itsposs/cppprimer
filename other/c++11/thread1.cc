
#include <thread>
#include <string>
#include <iostream>

void func(int i, double d, const std::string &s) {
	std::cout << i << ", " << d << ", " << s << std::endl;
}

void test() {
	std::thread t(func, 1, 2, "test");
	t.join();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
