

#include <iostream>


template <typename T>
void printarg(T t) { std::cout << t << std::endl; }


template <typename ...Args>
void expand(Args... args) {
	//int arr[] = { (printarg(args), 0)...};
	//std::initializer_list<int>{([&]{ std::cout << args << std::endl; }(), 0)...};
	std::initializer_list<int>{(printarg(args), 0)...};
}


void test() { expand(1, 2, 3, 4); }



int main(int argc, char *argv[]) {
	expand(1, 2, 3, 4);
	return 0;
}


