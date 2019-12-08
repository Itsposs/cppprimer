
#include <iostream>
#include <functional>


// compare有一个默认模板实参less<T>和一个默认实参F()
template <typename T, typename F = std::less<T>>
int compare(const T &v1, const T &v2, F f = F())
{
	if(f(v1, v2)) return -1;
	if(f(v2, v1)) return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	//bool ret = compare(0, 42);
	bool ret = compare(0, 42);

	std::cout << "ret:" << ret << std::endl;

	return 0;
}
