


#include <memory>
#include <iostream>


template <typename T>
void PrintT(T& t) {
	std::cout << "lvalue" << std::endl;
}

template <typename T>
void PrintT(T&& t) {
	std::cout << "rvalue" << std::endl;
}

template <typename T>
void TestForward(T&& v) {
	//PrintT(v);
	//PrintT(std::forward<T>(v));
	//PrintT(std::move(v));
}

void Test() {
	TestForward(1);
	int x = 1;
	TestForward(x);
	TestForward(std::forward<int>(x));
}

int main(int argc, char *argv[]) {
	Test();
	return 0;
}
