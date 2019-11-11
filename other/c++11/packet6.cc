

template <typename... Args>
struct Sum;

template <typename First, typename... Rest>
struct Sum<First, Rest...> {
	enum { value = Sum<First>::value + Sum<Rest...>::value };
};

template <typename Last>
struct Sum<Last> {
	enum { value = sizeof (Last) };
};

#include <iostream>

void test() {
	auto val = Sum<int, double, short>::value;
	std::cout << "sizeof:" << val << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
