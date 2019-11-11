
#include <iostream>

class A {
	public:
		A() : m_ptr(new int(0)) {}
		~A() { delete m_ptr; }
	private:
		int *m_ptr;
};

A Get(bool flag) {
	A a;
	A b;
	if (flag)
		return a;
	else
		return b;
}

void test() {
	A a = Get(false);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
