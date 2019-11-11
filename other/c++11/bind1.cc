

#include <iostream>
#include <functional>

//using std::placeholders::_1;
//using std::placeholders::_2;

void output(int x, int y) {
	std::cout << x << " " << y << std::endl;
}

void test() {
	std::bind(output, 1, 2)();
	std::bind(output, std::placeholders::_1, 2)(1);
	std::bind(output, 2, std::placeholders_1)(1);

	std::bind(output, 2, std::placeholders_2)(1, 2);
	std::bind(output, std::placeholders_2, std::placeholders_1)(1, 2);

	std::bind(output, std::placeholders_2, std::placeholders_1)(1, 2);
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
