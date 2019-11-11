
#include <vector>
#include <thread>
#include <future>
#include <utility>
#include <iostream>

// a simple task
int func(int x) { return x + 2; }

void test() {
	std::packaged_task<int(int)> tsk(func);
	std::future<int> fut = tsk.get_future();

	std::thread(std::move(tsk), 2).detach();

	int value = fut.get();
	std::cout << "The result is " << value << std::endl;

	std::vector<std::shared_future<int>> v;
	auto f = std::async(std::launch::async, 
			[](int a, int b){ return a + b; }, 2, 3);
	v.push_back(std::move(f));
	std::cout << "The shared_future result is " 
						<< v[0].get() << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
