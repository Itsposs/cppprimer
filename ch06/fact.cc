

#include <iostream>


int fact(int val) { // range of int
	int ret = 1;
	while (val > 1) {
		ret *= val--;
	}
	return ret;
}

int main(int argc, char *argv[]) {
	int j = fact(5);
	std::cout << "5! is " << j << std::endl;

	return 0;
}
