

#include <vector>


//template <typename Container>
//class Foo {
//	//public:
//	typename Container::iterator it_;
//	public:
//		void func(Container &container) { it_ = container.begin(); }
//};
//
//template <typename Container>
//class Foo<const Container> {
//	//public:
//	typename Container::const_iterator it_;
//	public:
//		void func(const Container &container) { it_ = container.begin(); }
//};

template <typename Container>
class Foo {
	//public:
	decltype(Container().begin()) it_;
	public:
		void func(Container &container) { it_ = container.begin(); }
};


void test() {
	typedef const std::vector<int> container_t;
	container_t arry;
	Foo<container_t> foo;
	foo.func(arry);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
