

#include <tuple>
#include <cstdint>
#include <iostream>
#include <type_traits>


//template <std::size_t I = 0, typename Tuple>
//typename std::enable_if<I == std::tuple_size<Tuple>::value>::type
//printtp(Tuple t) { }
//
//
//template <std::size_t I = 0, typename Tuple>
//typename std::enable_if<I < std::tuple_size<Tuple>::value>::type
//printtp(Tuple t) { 
//	std::cout << std::get<I>(t) << std::endl;
//	printtp<I + 1>(t);
//}
//
//template <typename... Args>
//void print(Args... args) { printtp(std::make_tuple(args...)); }



void test() {
	print(1);
	print(1, 2);
	print(1.2, 3.2, "hello world!");
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
