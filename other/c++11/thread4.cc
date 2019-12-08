
#include <thread>
#include <chrono>
#include <iostream>

void func() {
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "time out." << std::endl;
}

void test() {
	std::thread t(func);
	t.join();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
