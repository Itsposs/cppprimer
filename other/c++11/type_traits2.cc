

#include <vector>
#include <iostream>
#include <type_traits>

class A {};
enum class B {};
void func() {}

void test() {
	std::cout << std::boolalpha;
	std::cout << std::is_void<void>::value << std::endl;
	
	constexpr std::vector<int> vec{1, 3, 5};
	std::cout << std::is_array<vec>::value << std::endl;
	
	constexpr int val = 6;
	constexpr int *p = &val;

	std::cout << std::is_pointer<p>::value << std::endl;
	std::cout << std::is_class<A>::value << std::endl;
	std::cout << std::is_function<func>::value << std::endl;

	constexpr A obj;

	std::cout << std::is_object<obj>::value << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
