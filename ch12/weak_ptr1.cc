

#include <memory>
#include <iostream>

void test() {
	std::shared_ptr<int> sp(new int(9));
	std::weak_ptr<int> wp(sp);
	std::cout << wp.use_count() << std::endl;

	if(!wp.expired())
	{
		*(wp.lock()) += 1;
	}
	std::cout << *sp << std::endl;
	wp.reset();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
