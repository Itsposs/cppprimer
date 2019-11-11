
#include <mutex>
#include <thread>
#include <iostream>

std::once_flag flag;

void do_once() {
	std::call_once(flag, [](){ std::cout << "Called once." << std::endl;});
}

void test() {
	std::thread t1(do_once);
	std::thread t2(do_once);
	std::thread t3(do_once);

	t1.join();
	t2.join();
	t3.join();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
