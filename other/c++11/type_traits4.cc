

#include <memory>
#include <iostream>
#include <type_traits>


template <typename T>
class Construct {
	public:
		typedef typename std::remove_reference<T>::type U;
		Construct() : m_ptr(new U) { }
		typename std::add_lvalue_reference<U>::type 
			Get() const { return *m_ptr; }
	private:
		std::unique_ptr<U> m_ptr;
};


void test() {
	Construct<int> c;
	int a = c.Get();
	std::cout << a << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
