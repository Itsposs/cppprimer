
#include <iostream>

struct MyStruct {
	char a;
	int b;
	short c;
	long long d;
	char e;
};

void test() {
	MyStruct xx;
	std::cout << alignof(xx) << std::endl;
	std::cout << alignof(MyStruct) << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
