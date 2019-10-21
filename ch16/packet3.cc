

#include <iostream>

//void print() { std::cout << "empty" << std::endl; }

//template <typename T>
//void print(T t) { std::cout << t << std::endl; }

template <typename T, typename T1, typename T2>
void print(T t, T1 t1) { std::cout << t << " " << t1 << std::endl;

void print(T t, T1 t1, T2 t1) { std::cout << t << " " << t1 << " " << t1 << std::endl;


template <typename T, typename ...Args>
void print(T head, Args... rest) { 
	std::cout << "parameter " << head << std::endl;
	print(rest...);
}


void test() {
	print(1, 2, 3, 4);
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
