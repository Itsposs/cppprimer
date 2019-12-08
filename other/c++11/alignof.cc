
#include <iostream>

struct MyStruct {
	char a;
	int b;
	short c;
	long long d;
	char e;
};

struct x1 {
	int i;
	char c1;
	char c2;
};

void test() {
	MyStruct xx;
	std::cout << sizeof(x1)  << std::endl;
	std::cout << alignof(xx) << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
