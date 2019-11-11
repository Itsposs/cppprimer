
#include <typeinfo>
#include <iostream>

template <int...>
struct IndexSeq{};


template <int N, int... Indexes>
struct MakeIndexes : MakeIndexes<N - 1, N - 1, Indexes...> {};


template <int... Indexes>
struct MakeIndexes<0, Indexes...> {
	typedef IndexSeq<Indexes...> type;
};

void test() {
	using T = MakeIndexes<3>::type;
	std::cout << typeid(T).name() << std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
