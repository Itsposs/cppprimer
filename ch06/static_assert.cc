
#include <cassert>
#include <iostream>

void func() {
	auto val1 = sizeof(int);
	auto val2 = sizeof(char);

	static_assert(val1 != val2, "type is not same!");
}


int main(int argc, char *argv[]) {
	func();
	return 0;
}
