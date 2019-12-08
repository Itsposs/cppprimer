

#include <iostream>

class X { };
class Y : public virtual X { };
class Z : public virtual X { };
class A : public Y, public Z { };

void test() {
	X a, b;
	if (&a == &b) std::cerr << "yipes!" << std::endl;
	auto val1 = sizeof(X);
	auto val2 = sizeof(Y);
	auto val3 = sizeof(Z);
	auto val4 = sizeof(A);
	std::cout << "X:" << val1 << std::endl;
	std::cout << "Y:" << val2 << std::endl;
	std::cout << "Z:" << val3 << std::endl;
	std::cout << "A:" << val4 << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
