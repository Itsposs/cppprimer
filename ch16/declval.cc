

#include <iostream>
#include <type_traits>


struct absInt {
	int operator()(int val) const { 
		return val < 0 ? -val : val;
	}
};



class A {
	public:
		A() = delete;
		int operator() (int i) { return i; }
	private:

};


void test() {
	//decltype(A()(0)) i = 4;  error, A() = delete
	decltype(std::declval<A>()(std::declval<int>())) i = 4;
	std::result_of<A(int)>::type j = 6;
	std::cout << i << std::endl;
	std::cout << j << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
