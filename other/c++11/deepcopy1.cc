

#include <iostream>

class A {
	public:
		A() : m_ptr(new int(0)) { 
			std::cout << "construct" << std::endl; 
		}

		A(const A &a) : m_ptr(new int(*a.m_ptr)) {
			std::cout << "copy construct" << std::endl;
		}

		~A() { 
			std::cout << "destruct" << std::endl;
			delete m_ptr;
		}
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
