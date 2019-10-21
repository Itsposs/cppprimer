

#include <cstring>
#include <iostream>
#include <functional>


template <typename T>
inline int compare(const T& v1, const T& v2) {
	if (std::less<T>()(v1, v2)) return -1;
	if (std::less<T>()(v2, v1)) return  1;
	return 0;
}

template <size_t N, size_t M>
inline int compare(const char (&p1)[N], const char (&p2)[M]) {
	return ::strcmp(p1, p2);
}



template <>
inline int compare(const char* const &p1, const char* const &p2) {
	std::cout << "1" << std::endl;
	return ::strcmp(p1, p2);
}


void test() {
	const char *p1 = "hi", *p2 = "mom";
	compare(p1, p2);
	//compare("hi", "mom");
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
