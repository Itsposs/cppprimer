

#include <iostream>

void f(int v1, int& v2) {
	std::cout << v1 << " " << ++v2 << std::endl;
}

template <typename F, typename T1, typename T2>
void filp1(F f, T1 t1, T2 t2) {
	f(t2, t1);
}


void Test() {
	int i = 6;
	f(42, i);
	std::cout << "after: " << i << std::endl; 
	int j = 36;
	filp1(f, j, 42);
	std::cout << "after: " << j << std::endl; 
}

int main(int argc, char *argv[]) {
	Test();
	return 0;
}
