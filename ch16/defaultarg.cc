#include <iostream>
#include <functional>


template<typename T, typename F = std::less<T>>
int compare(const T &v1, const T &v2, F f = F())
{
	if (f(v1, v2)) return -1;
	if (f(v2, v1)) return 1;
	return 0;
}


int main(int argc, char *argv[])
{
	return 0;
}
