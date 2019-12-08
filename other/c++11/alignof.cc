
#include <iostream>

struct MyStruct {
	char a;
	int b;
	short c;
	long long d;
	char e;
};

<<<<<<< HEAD
struct x1 {
	int i;
	char c1;
	char c2;
};

void test() {
	MyStruct xx;
	std::cout << sizeof(x1)  << std::endl;
	std::cout << alignof(xx) << std::endl;
=======
void test() {
	MyStruct xx;
	std::cout << alignof(xx) << std::endl;
	std::cout << alignof(MyStruct) << std::endl;
>>>>>>> e2763e0a43fdee023e83410a284fa63d0cbb0459
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
