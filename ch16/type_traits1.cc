
#include <iostream>
#include <type_traits>


void test() {
	typedef std::integral_constant<int, 2> two_t;
	typedef std::integral_constant<int, 4> four_t;

	static_assert(two_t::value * 2 == four_t::value, "2 * 2 != 4");

	enum class my_e {
		e1,
		e2
	};
	typedef std::integral_constant<my_e, my_e::e1> my_e_e1;
	typedef std::integral_constant<my_e, my_e::e2> my_e_e2;

	static_assert(std::is_same<my_e_e2, my_e_e2>::value, "my_e_e2 != my_e_e2");
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
