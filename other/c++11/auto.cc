

#include <iostream>

template <typename T>
struct Bar { };

void test() {
	// func parameter deduction
	void func(auto val = 1) { }
	
	// nonstatic member var
	auto ival = 1;
	
	// ok
	static const auto dval = 6.0;

	// array
	
	auto arry1[10] = {0};
	int arry2[10] = {0};
	auto arry3 = arry2;

	// template parameter
	Bar<int> bar1;
	Bar<auto> bar2 = bar1;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
