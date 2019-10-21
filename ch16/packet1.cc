

#include <iostream>

template <typename ... Args>
void g(Args ... args) {
	std::cout << sizeof...(Args) << std::endl;
	std::cout << sizeof...(args) << std::endl;
}

void test() {
	int i = 0;
	double d = 3.14;
	std::string s = "how are you ?";
	g(i, d, s);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
