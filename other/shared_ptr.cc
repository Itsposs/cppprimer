
#include <memory>

template <typename T>
std::shared_ptr<T> make_shared_array(size_t size) {
	return std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
}

void test() {
	std::shared_ptr<int> p1(new int, [](int *p) 
			{ delete p; });
	// array
	std::shared_ptr<int> p2(new int[10], [](int *p)
			{ delete[] p; });

	// make_shared_array
	std::shared_ptr<int> p3 = make_shared_array<int>(10);
	std::shared_ptr<char> p4 = make_shared_array<char>(10);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
