

#include <iostream>

int g_constructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;


struct A {
	
	A() { std::cout << "construct: " << ++g_constructCount << std::endl; }
	A(const A &a) { 
		std::cout << "copy construct: " 
							<< ++g_copyConstructCount << std::endl;
	}

	~A() { std::cout << "destruct: " << ++g_destructCount << std::endl; }
};


A GetA() { return A(); }

void test() {
	//A&& a = GetA();
	const A& a = GetA(); // before c++11
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
