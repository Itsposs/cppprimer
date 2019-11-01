

#include <iostream>

template <typename T>
std::ostream &print(std::ostream  &os, const T &t) {
	return os << t;  // 包中最后一个元素之后不打印分隔符
}

// 包中除了最后一个元素之外的其他元素都会调用这个版本的print
template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... rest) {
	os << t << ",";  // 打印第一个实参
	return print(os, rest...); // 递归调用,打印其他实参
}


int main(int argc, char *argv[]) {

	return 0;
}
