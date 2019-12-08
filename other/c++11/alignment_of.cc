
#include <iostream> 

struct MyStruct {
	char a;
	int b;
	double c;
};

void test() {
	int size1 = alignof(MyStruct);
	int size2 = std::alignment_of<MyStruct>::value;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
