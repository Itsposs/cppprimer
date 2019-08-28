#include <vector>
#include <iostream>


int main(int argc, char *argv[])
{
	auto addition = [](int lhs, int rhs) -> int { return lhs + rhs; };
	std::vector<int> a = {1, 2, 3, 4, 5};
	std::vector<int> b = {6, 7, 8, 9, 10};

	for(int i = 0, sz = a.size(); i < sz; ++i)
		a[i] = addition(a[i], b[i]);

	for(const auto val : a)
		std::cout << "a[1]: " << val << std::endl;
	//auto f = [] { return 42; };
	//std::cout << "f():" << f() << std::endl;

	return 0;
}
