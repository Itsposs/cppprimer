

#include <utility>
#include <iostream>

void g(int&& i, int& j) {
	std::cout << i << " " << j << std::endl;
}

template <typename F, typename T1, typename T2>
void filp(F f, T1&& t1, T2&& t2) {
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}


void Test() {
	int i = 6;
	g(42, i);
	std::cout << "after: " << i << std::endl; 
	int j = 36;
	filp(g, j, 42);
	std::cout << "after: " << j << std::endl; 
}

int main(int argc, char *argv[]) {
	Test();
	return 0;
}
