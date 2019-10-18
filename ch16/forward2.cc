

#include <utility>
#include <iostream>

void g(int&& i, int& j) {
	std::cout << i << " " << j << std::endl;
}

template <typename F, typename T1, typename T2>
void filp2(F f, T1&& t1, T2&& t2) {
	g(t2, t1);
}


void Test() {
	int i = 6;
	g(42, i);
	std::cout << "after: " << i << std::endl; 
	int j = 36;
	filp2(g, j, 42);  // error: int lvalue convert int&&
	std::cout << "after: " << j << std::endl; 
}

int main(int argc, char *argv[]) {
	Test();
	return 0;
}
